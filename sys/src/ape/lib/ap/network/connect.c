/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/* bsd extensions */
#include <sys/uio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>

#include "lib.h"
#include "sys9.h"
#include "priv.h"

/*
 * ASYNCHRONOUS connect(), and why it needs a process.
 *
 * WHERE THIS CAME FROM. Tcl's socket-14.14 and 14.15 do
 *
 *	set s [socket -async localhost [randport]]
 *
 * and they had been PASSING -- because `randport' certifies a port free
 * by opening and closing a server socket on it, and the listener leak
 * left a process holding the very port it had just certified. The
 * async connect reached that leftover and succeeded. Fixing the leak
 * made the port genuinely dead, the connect genuinely refused, and the
 * error came back from the `socket' command itself. That is when it
 * became visible that **-async had never worked here at all**: this
 * file had no O_NONBLOCK, no EINPROGRESS and no deferred completion.
 *
 * WHY A PROCESS. On Plan 9 a connect is `write(ctl, "connect a!p")',
 * and that write does not return until the conversation is made or
 * refused. There is no "start it and tell me later" form of it. So an
 * asynchronous connect is another process doing the write while the
 * caller returns to its event loop -- the same shape as listenproc, for
 * the same reason.
 *
 * WHAT TCL EXPECTS, read from tclUnixSock.c rather than assumed: the
 * socket is put in non-blocking mode, `connect' is expected to return
 * -1 with EINPROGRESS, a WRITABLE|EXCEPTION handler is registered, and
 * when it fires the result is read with getsockopt(SO_ERROR).
 *
 * THE ONE PLACE THIS IS STILL AN APPROXIMATION, said plainly because
 * the alternative would be a confident wrong answer. select() in
 * plan9/_buf.c reports every descriptor in the WRITE set ready
 * immediately -- "for now, we'll say they are all ready", which
 * predates this change by many years. So Tcl is told the socket is
 * writable before the connect has resolved, and asks for SO_ERROR at
 * once. getsockopt() therefore WAITS there for the answer rather than
 * returning 0: an unresolved connect reported as success is the
 * `XLoadFont' family, which this tree records as its most common bug,
 * and a caller that blocks briefly is strictly better off than one that
 * is told the wrong thing. The real fix is select() learning about a
 * pending connect, and that belongs in _buf.c with its own measurement.
 */

/*
 * Do the connect, now, in this process. Returns 0 or an errno; it does
 * NOT leave errno set, because the caller may be a child reporting it
 * down a pipe. close() can clobber errno, so the value is saved first.
 */
static int
doconnect(Rock *r, char *msg)
{
	int cfd, n, e;

	if((cfd = open(r->ctl, O_RDWR)) < 0)
		return errno ? errno : EIO;
	n = write(cfd, msg, strlen(msg));
	e = (n < 0) ? (errno ? errno : EIO) : 0;
	close(cfd);
	return e;
}

/*
 * Start the connect in another process and return -1/EINPROGRESS.
 * Falls back to doing it here if the process cannot be made: a slow
 * answer is better than a false one.
 */
static int
asyncconnect(Rock *r, char *msg)
{
	int p[2], i, e, pid;

	if(pipe(p) < 0)
		goto now;
	/*
	 * RFNOWAIT, as _timerproc uses, so this leaves no wait record for
	 * anyone to reap. Nothing calls wait() for it and a process that
	 * has to be waited for is exactly what this tree has just spent
	 * several rounds cleaning up. RFFDG so the closing below is ours.
	 */
	if((pid = _RFORK(RFFDG|RFPROC|RFNOWAIT)) < 0){
		close(p[0]);
		close(p[1]);
		goto now;
	}
	if(pid == 0){
		/*
		 * EVERY OTHER DESCRIPTOR GOES. listen.c records what an
		 * inherited copy of descriptor 1 costs: a Plan 9 pipe
		 * reports end of file only when every copy of the other
		 * end is shut, so a child holding one wedges whoever is
		 * reading it. The ctl file is opened by name below, so
		 * nothing here is needed but the pipe.
		 */
		for(i = 0; i < OPEN_MAX; i++)
			if(i != p[1] && (_fdinfo[i].flags & FD_ISOPEN))
				_CLOSE(i);
		e = doconnect(r, msg);
		_WRITE(p[1], &e, sizeof e);
		_exit(0);	/* _exit: a child must not run atexit handlers */
	}
	close(p[1]);
	/*
	 * A previous connect on this socket whose result nobody read
	 * leaves its pipe open; shut it before overwriting the record, so
	 * the cost is bounded at one descriptor per socket.
	 */
	if(r->cpid != 0 && r->cfd >= 0)
		close(r->cfd);
	r->cpid = pid;
	r->cfd = p[0];
	r->cerr = -1;
	errno = EINPROGRESS;
	return -1;

now:
	if((e = doconnect(r, msg)) != 0){
		errno = e;
		return -1;
	}
	return 0;
}

/*
 * The result of a connect started above. Called from getsockopt(SO_ERROR).
 * WAITS for the answer -- see the note at the top on why that is better
 * than reporting 0 -- and then forgets it, because POSIX says reading
 * SO_ERROR clears the error.
 */
int
_sock_connectdone(Rock *r)
{
	int e, n;

	if(r->cpid == 0)
		return 0;
	if(r->cerr < 0){
		n = _READ(r->cfd, &e, sizeof e);
		r->cerr = (n == sizeof e) ? e : 0;
	}
	if(r->cfd >= 0)
		close(r->cfd);
	r->cfd = -1;
	r->cpid = 0;
	e = r->cerr;
	r->cerr = -1;
	return e;
}

int
connect(int fd, void *a, int alen)
{
	Rock *r;
	int n, nfd;
	char msg[8+256+1], file[8+256+1];
	struct sockaddr *sa;
	struct sockaddr_un *runix;
	static int vers;

	r = _sock_findrock(fd, 0);
	if(r == 0){
		errno = ENOTSOCK;
		return -1;
	}
	sa = (struct sockaddr*)a;
	if(sa->sa_family != r->domain){
		errno = EAFNOSUPPORT;
		return -1;
	}
	if(alen > sizeof(r->raddr)){
		errno = ENAMETOOLONG;
		return -1;
	}
	memmove(&r->raddr, a, alen);

	switch(r->domain){
	case PF_INET:
	case PF_INET6:
		/*
		 * Build the message BEFORE deciding who writes it: the
		 * child below needs the same string, and building it twice
		 * is how the two copies drift apart.
		 */
		if(_sock_inport(&r->addr) > 0) {
			snprintf(msg, sizeof msg, "connect %s!%d%s %d",
				inet_ntop(sa->sa_family, _sock_inip(sa), file, sizeof(file)),
				_sock_inport(sa),
				r->reserved ? "!r" : "",
				_sock_inport(&r->addr));
		} else {
			snprintf(msg, sizeof msg, "connect %s!%d%s",
				inet_ntop(sa->sa_family, _sock_inip(sa), file, sizeof(file)),
				_sock_inport(sa),
				r->reserved ? "!r" : "");
		}
		if(r->cpid != 0){
			/* one is already under way on this socket */
			errno = EALREADY;
			return -1;
		}
		if((_fdinfo[fd].oflags & O_NONBLOCK) != 0)
			return asyncconnect(r, msg);
		if((n = doconnect(r, msg)) != 0){
			errno = n;
			return -1;
		}
		return 0;
	case PF_UNIX:
		/* null terminate the address */
		if(alen == sizeof(r->raddr))
			alen--;
		*(((char*)&r->raddr)+alen) = 0;

		if(r->other < 0){
			errno = EGREG;
			return -1;
		}

		/* put far end of our pipe in /srv */
		snprintf(msg, sizeof msg, "UD.%d.%d", getpid(), vers++);
		if(_sock_srv(msg, r->other) < 0){
			r->other = -1;
			return -1;
		}
		r->other = -1;

		/* tell server the /srv file to open */
		runix = (struct sockaddr_un*)&r->raddr;
		_sock_srvname(file, runix->sun_path);
		nfd = open(file, O_RDWR);
		if(nfd < 0){
			unlink(msg);
			return -1;
		}
		if(write(nfd, msg, strlen(msg)) < 0){
			close(nfd);
			unlink(msg);
			return -1;
		}
		close(nfd);

		/* wait for server to open it and then remove it */
		read(fd, file, sizeof(file));
		_sock_srvname(file, msg);
		unlink(file);
		return 0;
	default:
		errno = EAFNOSUPPORT;
		return -1;
	}
}
