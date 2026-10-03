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
			/*
			 * A BUFFERED DESCRIPTOR USED TO BE UNDUPLICATABLE,
			 * and the arm that refused it answered `EGREG'.
			 *
			 * Two separate faults. The errno first: EGREG is
			 * APE's own, `_errno.c' maps Plan 9's "ken has left
			 * the building" to it, and `strerror' prints
			 * `Unknown error' -- which is also what an errno out
			 * of range gives, so the two are indistinguishable
			 * from outside. bash's `read7.sub' line 60 is
			 * `read -e -t .001 a <<<abcde': `-e' makes readline
			 * `select()' fd 0, which BUFFERS it, and the
			 * here-string then makes bash save fd 0 with a dup.
			 * It printed `cannot duplicate fd: Unknown error'.
			 *
			 * And the scope is far wider than fcntl, because
			 * `dup()' and `dup2()' are both one line of
			 * `fcntl(.., F_DUPFD, ..)'. So **any APE program that
			 * had ever select()ed a descriptor could no longer
			 * dup it** -- which, since select() is how an event
			 * loop works and dup is how a shell redirects, is a
			 * good deal of ordinary code.
			 *
			 * WHY IT WAS REFUSED, AND WHY CLEARING THE BITS IS
			 * THE ANSWER RATHER THAN AN INVENTION.
			 *
			 * `Muxbuf' is keyed on the descriptor NUMBER
			 * (`_buf.c''s `b->fd'), and `Fdinfo' carries a `buf'
			 * pointer beside the flag. Copy `fi->flags' wholesale
			 * onto a new number and `_readbuf' finds
			 * `b->fd != fd' and answers EBADF on every read --
			 * so simply deleting the arm would trade a refusal
			 * for a descriptor that reads as broken, which is
			 * worse. That is what the arm was protecting against.
			 *
			 * But those two bits are **facts about a descriptor
			 * number in one process image, not about the open
			 * file** -- which is the invariant `_fdinfo.c' already
			 * states for FD_BUFFEREDX, and `sfdinit' already
			 * scrubs exactly this pair on exec for exactly this
			 * reason, in exactly these two lines. The kernel's
			 * `_DUP' gives a real second descriptor on the same
			 * open file; what it does not give is a second
			 * Muxbuf, and the new number must not claim one.
			 * FD_ISTTY and FD_ISREG are facts about the FILE and
			 * are carried over unchanged.
			 *
			 * THE LIMIT, recorded rather than hidden: bytes the
			 * copy process has already drained into the Muxbuf
			 * are not visible through the new descriptor, so the
			 * two do not share a read position the way POSIX says
			 * two dups of one open file description do. There is
			 * nowhere to put them -- a Muxbuf cannot be split --
			 * and a reader of the dup was already competing with
			 * the copy process, which is the keystroke-thief
			 * hazard this tree has measured. Losing that is
			 * strictly better than failing the dup, and the
			 * overwhelming use of dup here (a shell saving a
			 * descriptor to restore later) never reads it at all.
			 */
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
			/*
			 * The two lines from `_fdinfo.c''s exec scrub, and
			 * the SECOND one is the one that would be forgotten:
			 * clearing the flag without clearing the pointer
			 * leaves a stale `Muxbuf *' behind a bit that says
			 * not to look at it, which is one edit away from
			 * being believed again.
			 */
			fans->flags &= ~(FD_BUFFERED|FD_BUFFEREDX);
			fans->buf = 0;
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

/*
 * Version marker for `dupbuf-test.c'. `pcc -o x x.c' relinks against the
 * INSTALLED libap, so a test built from a fresh pull can run days-old
 * library code and report a pass on it; a test that calls this will not
 * LINK against a libap predating the F_DUPFD fix above. The idiom has
 * paid five times already (`_sock_listenmark', `_execmark', `_ttymark',
 * `_getcwdmark', `_printfmark').
 */
int
_dupmark(void)
{
	return 1;
}
