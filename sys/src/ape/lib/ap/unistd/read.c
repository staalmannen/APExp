#include <errno.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"
#include "sys9.h"

#include <stdio.h>
#include <sys/stat.h>

/*
 * O_NONBLOCK HAS NO EFFECT ON A REGULAR FILE, and read() here behaved as
 * though it did.
 *
 * Any descriptor with O_NONBLOCK set was diverted into the buffered
 * copy-process path below, whatever kind of file it was. For a pipe,
 * socket or terminal that is the whole point -- Plan 9 has no
 * non-blocking read, so a second process does the reading and the
 * caller asks what has arrived. For a REGULAR FILE it is both wrong and
 * expensive: a copy process is forked for something that can never
 * block, and _readbuf(..., noblock) then answers "would block" whenever
 * that process has not caught up yet.
 *
 * POSIX is explicit: O_NONBLOCK affects pipes, FIFOs, terminals and
 * sockets. A read from a regular file transfers what is there and
 * returns 0 at end of file; it never fails with EAGAIN.
 *
 * WHAT IT COST, in Tcl's io.test and chanio.test -- the same six tests
 * through two APIs, so twelve failures from this one line:
 *
 *	io-39.9   empty file, non-blocking: got fblocked 1, eof 0
 *	                                    wanted fblocked 0, eof 1
 *	io-35.4   same, through eof alone
 *	io-32.7   `read $f 20' on a long file returned fewer than 20
 *	io-32.8, io-36.5, io-36.6 and the chan-io twins of all of them
 *
 * A file at end of file reported "try again later" for ever, because
 * later never comes for a file that has already ended.
 */
static int
isregular(int d)
{
	struct stat st;
	Fdinfo *f;

	f = &_fdinfo[d];
	if((f->flags & FD_REGCHECKED) == 0){
		f->flags |= FD_REGCHECKED;
		if(fstat(d, &st) == 0 && S_ISREG(st.st_mode))
			f->flags |= FD_ISREG;
	}
	return (f->flags & FD_ISREG) != 0;
}

ssize_t
pread(int d, void *buf, size_t nbytes, off_t offset)
{
	int n, noblock, isbuf;
	Fdinfo *f;

	/*
	 * The two answers that never reach the kernel, and so are
	 * invisible to anything watching the other side. A reader that
	 * turns any error into EOF -- readline does exactly that -- makes
	 * both of these look like a closed terminal.
	 */
	if(d<0 || d>=OPEN_MAX || !(_fdinfo[d].flags & FD_ISOPEN)){
		if(_apdbgon())
			_apdbg("read: EBADF, no syscall", "fd", d, 0, 0);
		errno = EBADF;
		return -1;
	}
	if(nbytes <= 0){
		if(_apdbgon())
			_apdbg("read: 0 bytes asked, no syscall", "fd", d, 0, 0);
		return 0;
	}
	if(buf == 0){
		errno = EFAULT;
		return -1;
	}
	f = &_fdinfo[d];
	noblock = f->oflags&O_NONBLOCK;
	isbuf = f->flags&(FD_BUFFERED|FD_BUFFEREDX);
	/*
	 * $APEXP_DEBUG: which branch a read took, and what it answered.
	 *
	 * WHY HERE. Under vts, bash printed its prompt and then read EOF
	 * with NO 9P MESSAGE AT ALL -- chatty9p shows every T-message on
	 * the shell's fid, and there is not one Tread in the whole
	 * session. So either read() was never called, or it answered
	 * before reaching the kernel; the two are indistinguishable from
	 * the server's side, and three rounds of reading bash's and
	 * readline's source guessed wrong about which.
	 *
	 * These lines separate them in one run: nothing printed means
	 * bash never called read; `enter' with no `->' means it never
	 * returned; anything else names the branch and the answer.
	 * They go to fd 2 -- which under vts is the terminal, so they
	 * travel back through the server and land in its log.
	 */
	if(_apdbgon()){
		_apdbg("read: enter", "fd", d, "n", (int)nbytes);
		_apdbg("read:  fdinfo", "flags", f->flags, "oflags", f->oflags);
	}
	/*
	 * Even when something else has already buffered it -- select()
	 * does that to anything it is asked to watch -- a regular file
	 * must not report EAGAIN, so the flag is cleared either way and
	 * _readbuf below waits for the copy process rather than giving up
	 * on it. That wait always ends: a file cannot fail to arrive.
	 */
	if(noblock && isregular(d))
		noblock = 0;
	if(noblock || isbuf){
		if(f->flags&FD_BUFFEREDX) {
			errno = EIO;
			return -1;
		}
		if(!isbuf) {
			if(_startbuf(d) != 0) {
				errno = EIO;
				return -1;
			}
		}
		n = _readbuf(d, buf, nbytes, noblock);
		if(_apdbgon())
			_apdbg("read:  -> buffered", "n", n, "errno", errno);
	}else{
		n = _PREAD(d, buf, nbytes, offset);
		if(n < 0)
			_syserrno();
		if(_apdbgon())
			_apdbg("read:  -> direct", "n", n, "errno", errno);
	}
	return n;
}

ssize_t
read(int d, void *buf, size_t nbytes)
{
	return pread(d, buf, nbytes, -1LL);
}

