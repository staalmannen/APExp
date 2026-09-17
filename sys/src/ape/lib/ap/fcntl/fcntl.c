#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include "sys9.h"

/*
 * BUG: advisory locking not implemented
 */

#define OFL (O_ACCMODE|O_NONBLOCK|O_APPEND)

int
fcntl(int fd, int cmd, ...)
{
	int arg, i, ans, err;
	Fdinfo *fi, *fans;
	va_list va;
	unsigned long oflags;

	err = 0;
	ans = 0;
	va_start(va, cmd);
	arg = va_arg(va, int);
	va_end(va);
	fi = &_fdinfo[fd];
	if(fd<0 || fd>=OPEN_MAX || !(fi->flags&FD_ISOPEN))
		err = EBADF;
	else switch(cmd){
		case F_DUPFD_CLOEXEC:
		case F_DUPFD:
			if(fi->flags&(FD_BUFFERED|FD_BUFFEREDX)){
				err = EGREG;	/* dup of buffered fd not implemented */
				break;
			}
			oflags = fi->oflags;
			/*
			 * THE KERNEL PICKS THE DESCRIPTOR, NOT `_fdinfo[]`.
			 *
			 * This used to scan `_fdinfo` for the first slot
			 * without FD_ISOPEN and `_DUP(fd, i)` onto it -- and
			 * `_fdinfo` is libap's own bookkeeping, which knows
			 * only about descriptors opened through APE. Anything
			 * libap opened with the raw `_OPEN` syscall is invisible
			 * to it, so the scan called that slot free and the
			 * `_DUP` SILENTLY CLOSED A LIVE FILE.
			 *
			 * `plan9/9nsec.c` is the one that matters: it opens
			 * `/dev/bintime` with `_OPEN` and caches the descriptor
			 * in a static for the life of the process, because every
			 * `gettimeofday()` reads it. `listen()` opens with
			 * `nfd = dup(fd)`, so one `socket -server` after the
			 * first timestamp could take that descriptor over. The
			 * cached number then names whatever landed there next --
			 * a pipe, a socket -- and `_NSEC`'s `_PREAD` on it never
			 * returns.
			 *
			 * Measured: Tcl's `zlib-9.2` froze with `acid` showing
			 * the test process in `_NSEC` -> `_PREAD(fd=7)` under an
			 * `after 1000`, while its listener process reported
			 * `nfd=0x7` for the socket it had been handed. One
			 * descriptor, two owners.
			 *
			 * `_DUP(fd, -1)` asks the kernel for the lowest free
			 * descriptor, which cannot collide with anything. POSIX
			 * wants the lowest free >= `arg`, so anything below
			 * `arg` is held until we are past it and then released.
			 */
			{
				int held[OPEN_MAX], nheld;

				nheld = 0;
				for(;;){
					ans = _DUP(fd, -1);
					if(ans < 0){
						_syserrno();
						err = errno;
						break;
					}
					if(ans >= arg || nheld >= OPEN_MAX)
						break;
					held[nheld++] = ans;
				}
				for(i = 0; i < nheld; i++)
					_CLOSE(held[i]);
			}
			if(err)
				break;
			if(ans >= OPEN_MAX){
				_CLOSE(ans);
				err = EMFILE;
				break;
			}
			fans = &_fdinfo[ans];
			fans->flags = fi->flags&~FD_CLOEXEC;
			if(cmd == F_DUPFD_CLOEXEC)
				fans->flags |= FD_CLOEXEC;
			fans->oflags = oflags;
			fans->uid = fi->uid;
			fans->gid = fi->gid;
			break;
		case F_GETFD:
			ans = fi->flags&FD_CLOEXEC;
			break;
		case F_SETFD:
			fi->flags = (fi->flags&~FD_CLOEXEC)|(arg&FD_CLOEXEC);
			break;
		case F_GETFL:
			ans = fi->oflags&OFL;
			break;
		case F_SETFL:
			fi->oflags = (fi->oflags&~OFL)|(arg&OFL);
			break;
		case F_GETLK:
		case F_SETLK:
		case F_SETLKW:
			err = EINVAL;
			break;
		}
	if(err){
		errno = err;
		ans = -1;
	}
	return ans;
}
