/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>

/* socket extensions */
#include <sys/uio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>

/* plan 9 */
#include "lib.h"
#include "sys9.h"

#include "priv.h"

extern int	_muxsid;
extern void	_killmuxsid(void);

/*
 * replace the fd with a pipe and start a process to
 * accept calls in.  this is all to make select work.
 */
static int
listenproc(Rock *r, int fd)
{
	char listen[Ctlsize], name[Ctlsize], *net, *p;
	int cfd, nfd, dfd, pfd[2], i;
	struct stat d;
	Rock *nr;
	void *v;

	switch(r->stype){
	case SOCK_DGRAM:
		net = "udp";
		break;
	case SOCK_STREAM:
		net = "tcp";
		break;
	case SOCK_RDM:
		net = "il";
		break;
	}

	strcpy(listen, r->ctl);
	p = strrchr(listen, '/');
	if(p == 0)
		return -1;
	strcpy(p+1, "listen");

	if(pipe(pfd) < 0)
		return -1;

	/* replace fd with a pipe */
	nfd = dup(fd);
	dup2(pfd[0], fd);
	close(pfd[0]);
	fstat(fd, &d);
	r->inode = d.st_ino;
	r->dev = d.st_dev;

	/* start listening process */
	switch(fork()){
	case -1:
		close(pfd[1]);
		close(nfd);
		return -1;
	case 0:
		if(_muxsid == -1) {
			_RFORK(RFNOTEG);
			_muxsid = getpgrp();
		} else
			setpgid(getpid(), _muxsid);
		while(_RENDEZVOUS(r, (void*)_muxsid) == (void*)~0)
			;
		break;
	default:
		while((v = _RENDEZVOUS(r, 0)) == (void*)~0)
			;
		_muxsid = (int)v;
		atexit(_killmuxsid);
		close(pfd[1]);
		close(nfd);
		return 0;
	}

	/*
	 * THE CHILD MUST NOT HOLD THE PARENT'S END OF THE PIPE, and until
	 * now it did -- the loop that was here to close it was commented
	 * out, and it is the whole of Tcl's event-11.5 hanging.
	 *
	 * `fd` is pfd[0] (the dup2 above), which is the end accept() and
	 * close() use. A Plan 9 pipe reports end of file to one end only
	 * when EVERY copy of the other end is shut, so while this process
	 * kept a copy the read below could never return 0. Closing the
	 * listening socket therefore did not end this loop: the process
	 * stayed blocked with `dfd` -- a connection it had already opened
	 * and nobody had accepted -- still open, so the peer was never
	 * hung up and the client waited on a conversation that had no
	 * other party left.
	 *
	 * Measured rather than reasoned: sys/lib/tests/select-test.c
	 * section 10 builds exactly that (connect, close the listener,
	 * never accept) and the client is never readable, while sections
	 * 4, 5, 7 and 9 -- every one of which accepts first -- all pass.
	 * Tcl's tcl-fileevent-test.tcl 7b and 7c are the same pair.
	 *
	 * That this matters at all is upstream's doing: event-11.5 closes
	 * its listener with the connection never accepted and still
	 * expects the client to become readable, which on a BSD stack it
	 * does because the kernel resets anything left in the accept
	 * queue. The queue here is this process, so this process has to
	 * do it.
	 *
	 * AND EVERY OTHER INHERITED DESCRIPTOR GOES WITH IT. That was
	 * deferred here once, as "tidier, but a separate change wanting
	 * its own measurement". The measurement arrived: Tcl's suite
	 * froze after `chan-io-73.1` with the whole file passing, and
	 * `acid` on one of the twenty-five leftover processes gave
	 *
	 *	_OPEN ... open(path=...) ... listen.c:135
	 *	listenproc(r=..., fd=0x7) ... listen.c:232
	 *	Tcl_OpenTcpServerEx ... tclUnixSock.c:1818
	 *
	 * -- this function, blocked in the `open(listen, ...)` below,
	 * which is where a Plan 9 listener waits for a call that in those
	 * tests never comes. Closing the socket cannot end that wait: the
	 * read further down is what notices, and this process is not at
	 * it. So each one sat there holding a copy of DESCRIPTOR 1, which
	 * in a tcltest child is the pipe the parent reads results from --
	 * and a Plan 9 pipe reports end of file only when every copy of
	 * the other end is shut, so the parent's `gets` never returned.
	 * The same leak is invisible from a terminal, where nobody is
	 * waiting for end of file on stdout.
	 *
	 * `nfd` and `pfd[1]` are the two this process needs: the announced
	 * socket, whose closing would withdraw the announcement, and the
	 * end of the pipe it talks to accept() over. Everything else goes.
	 *
	 * `_CLOSE`, not `close`: APE's close() calls `_closebuf` for a
	 * buffered descriptor, which SIGKILLs a copy process belonging to
	 * the parent. `_copyproc` closes its inherited descriptors the
	 * same way and for the same reason.
	 */
	for(i = 0; i < OPEN_MAX; i++)
		if(i != nfd && i != pfd[1] && (_fdinfo[i].flags & FD_ISOPEN))
			_CLOSE(i);
	_CLOSE(fd);	/* the dup2'd pipe end, in case _fdinfo disagrees */

	dfd = -1;
	for(;;){
		cfd = open(listen, O_RDWR);
		if(cfd < 0)
			break;

		/* _sock_data closes cfd itself, on success and on failure */
		dfd = _sock_data(cfd, net, r->domain, r->stype, r->protocol, &nr);
		if(dfd < 0)
			break;

		if(write(pfd[1], nr->ctl, strlen(nr->ctl)) < 0)
			break;
		if(read(pfd[1], name, sizeof(name)) <= 0)
			break;

		close(dfd);
		dfd = -1;
	}

	/*
	 * A connection this process opened and nobody accepted has to be
	 * hung up, and explicitly rather than by letting exit() do it:
	 * exit runs atexit handlers first, and the peer should not be left
	 * waiting through them.
	 */
	if(dfd >= 0)
		close(dfd);

	/*
	 * _exit, NOT exit -- A FORKED CHILD MUST NOT RUN THE PARENT'S
	 * atexit HANDLERS, and this one used to.
	 *
	 * It got away with it only because it never reached this line:
	 * before the close(fd) above, the read never returned and the
	 * process never left the loop. Making it exit correctly is what
	 * exposed the second half of the bug.
	 *
	 * The handlers it inherits are _buf.c's. _killmuxsid is guarded --
	 * `_mainpid == getpid()` -- and so does nothing here. **
	 * _killtimerproc is NOT**, and it is `kill(timerpid, SIGKILL)` on
	 * a pid inherited straight from the parent, so this process was
	 * killing the parent's TIMER. After that `timerpid` is still > 0,
	 * so _resettimer() only ever signals a corpse and no timeout ever
	 * fires again: every blocking select() that needs the timer to
	 * wake it waits for ever.
	 *
	 * Measured: tcl-fileevent-test.tcl section 7c stopped reporting
	 * TIMEOUT and began to FREEZE the moment the listener started
	 * exiting, with `at: waitfor` the last line printed and the
	 * handler never reached -- a `vwait` with a 3000ms `after` on it
	 * that never came back, which can only mean the event loop was
	 * never re-entered.
	 *
	 * _copyproc two hundred lines away in _buf.c has always said
	 * _exit(0), for exactly this reason.
	 */
	_exit(0);
	return 0;
}

int
listen(int fd, int backlog)
{
	Rock *r;
	int n, cfd;
	char msg[128];
	struct sockaddr_un *lunix;

	r = _sock_findrock(fd, 0);
	if(r == 0){
		errno = ENOTSOCK;
		return -1;
	}

	switch(r->domain){
	case PF_INET:
	case PF_INET6:
		if(!r->announced){
			cfd = open(r->ctl, O_RDWR);
			if(cfd < 0){
				errno = EBADF;
				return -1;
			}
			strcpy(msg, "announce ");
			_sock_inaddr2string(r, msg + 9, sizeof msg - 9);
			n = write(cfd, msg, strlen(msg));
			if(n < 0){
				_syserrno();
				if(errno == EPLAN9)
					errno = EOPNOTSUPP;
				close(cfd);
				return -1;
			}
			close(cfd);
			if(_sock_inport(&r->addr) == 0)
				_sock_ingetaddr(r, &r->addr, 0, "local");
		}

		return listenproc(r, fd);
	case PF_UNIX:
		if(r->other < 0){
			errno = EGREG;
			return -1;
		}
		lunix = (struct sockaddr_un*)&r->addr;
		if(_sock_srv(lunix->sun_path, r->other) < 0){
			r->other = -1;
			return -1;
		}
		r->other = -1;
		return 0;
	default:
		errno = EAFNOSUPPORT;
		return -1;
	}
}
