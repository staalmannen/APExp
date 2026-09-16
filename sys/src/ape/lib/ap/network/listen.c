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
	int cfd, nfd, dfd, pfd[2];
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
	 * Only `fd` is closed. Closing every other inherited descriptor
	 * would be tidier -- a forked listener holding the parent's files
	 * open is a real leak -- but the commented-out version did it with
	 * a hardcoded `for(fd = 0; fd < 30; fd++)`, which both reused the
	 * parameter and guessed at OPEN_MAX, and that is a separate change
	 * wanting its own measurement. `nfd` must stay open in any case:
	 * it is the announced socket, and closing it withdraws the
	 * announcement.
	 */
	close(fd);

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
	exit(0);
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
