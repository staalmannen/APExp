/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

/* socket extensions */
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>

/* plan 9 */
#include "lib.h"
#include "sys9.h"

#include "priv.h"

/*
 * WHAT THIS USED TO BE, IN ITS ENTIRETY:
 *
 *	int
 *	shutdown(int fd, int how)
 *	{
 *		if(how == 2)
 *			close(fd);
 *		return 0;
 *	}
 *
 * Two separate bugs, and the second is the worse one.
 *
 * IT ANSWERED SUCCESS WITHOUT DOING ANYTHING. That is the "a stub that
 * answers plausibly" family this project has now hit a dozen times --
 * XLoadFont, TkUnixSetMenubar, wm title -- arriving in libap. The cost
 * here is a HANG rather than a wrong answer, because half-close is a
 * protocol step the peer is waiting on: Tcl's chan-io-28.7 does
 *
 *	set s [socket 127.0.0.1 $port]
 *	puts $s Hey
 *	close $s w		<- shutdown(fd, SHUT_WR)
 *	... vwait for the peer's reply ...
 *
 * and the server half reads until EOF before answering. With no FIN
 * sent, EOF never arrives, the server never replies, and the client
 * waits. The test has a 1000ms timer and so merely fails; a program
 * without one waits forever.
 *
 * AND SHUT_RDWR CLOSED THE DESCRIPTOR, WHICH POSIX EXPLICITLY DOES NOT.
 * shutdown() shuts down the connection; the descriptor stays open and
 * the caller still has to close() it -- which every caller does, so
 * every shutdown(fd, SHUT_RDWR) was followed by a close() of a
 * descriptor this library had already released. In between, the fd
 * number is free for any open/socket/accept to take, so the caller's
 * close() then shuts an unrelated file belonging to someone else. That
 * is a descriptor-stealing bug with no diagnostic anywhere, and it is
 * the reason this file could not simply be left alone.
 *
 * WHAT PLAN 9 CAN ACTUALLY DO IS NOT SETTLED, AND IS NOT GUESSED AT
 * HERE. The candidate control messages are listed in halfclose[] below
 * and tried in order; sys/lib/tests/socket-server-test.c section 3
 * opens a real loopback connection and writes each of the same strings
 * to its ctl file, printing errstr() for each, so the next run of that
 * test says which of them this stack accepts -- the same method that
 * settled the announce spelling rather than reasoning from a manual
 * page. If the list turns out to have one right answer, shorten it to
 * that one; if it turns out to have none, see the note on the return
 * value below.
 *
 * WHY A FAILURE IS REPORTED RATHER THAN SWALLOWED. If none of the
 * messages is accepted, this returns -1 rather than the old 0. A
 * caller that ignores the result is no worse off than before, and a
 * caller that checks gets an error instead of a hang -- which is the
 * direction this project has preferred every time the two were in
 * tension. It is also the only way the absence stays visible.
 */

static char *halfclose[] = {
	"close",		/* 9front tcp, if it has it */
	"shutdown",
	"halfclose",
	"fin",
	0,
};

int
shutdown(int fd, int how)
{
	Rock *r;
	int cfd, i, n;

	if(how != SHUT_RD && how != SHUT_WR && how != SHUT_RDWR){
		errno = EINVAL;
		return -1;
	}

	r = _sock_findrock(fd, 0);
	if(r == 0){
		errno = ENOTSOCK;
		return -1;
	}

	/*
	 * SHUT_RD cannot be honoured here and saying so costs nothing.
	 * A socket fd in APE *is* the /net/tcp/n/data file -- read() and
	 * write() go straight to it with no wrapper in this library -- so
	 * there is no point at which a later read could be made to return
	 * 0. The kernel offers no read-side shutdown either. Reporting
	 * success is right: POSIX asks that no more data be delivered to
	 * the application, and an application that has asked to stop
	 * reading and then reads anyway is already outside what it said
	 * it would do. Nothing in the suite depends on it.
	 */
	if(how == SHUT_RD)
		return 0;

	/*
	 * A Unix-domain socket here is a pipe (see _sock_srv.c), and a
	 * Plan 9 pipe has no half-close: closing one end closes the
	 * whole direction. SHUT_RDWR is the one case a pipe can express,
	 * and it is expressed by the caller's own close(), not by us --
	 * see the descriptor note above.
	 */
	if(r->domain != PF_INET && r->domain != PF_INET6){
		if(how == SHUT_WR){
			errno = EOPNOTSUPP;
			return -1;
		}
		return 0;
	}

	if(how == SHUT_RDWR){
		/*
		 * The whole connection, which Plan 9 does have a word for.
		 * The descriptor stays open; only the connection goes.
		 */
		cfd = open(r->ctl, O_RDWR);
		if(cfd < 0){
			_syserrno();
			return -1;
		}
		n = write(cfd, "hangup", 6);
		if(n < 0)
			_syserrno();
		close(cfd);
		return n < 0 ? -1 : 0;
	}

	/*
	 * A fresh ctl file per attempt, for the reason section 2 of
	 * socket-server-test.c gives: a control file that has just
	 * rejected a message is not necessarily still usable, and reusing
	 * one would make the next attempt's answer mean nothing.
	 */
	for(i = 0; halfclose[i] != 0; i++){
		cfd = open(r->ctl, O_RDWR);
		if(cfd < 0){
			_syserrno();
			return -1;
		}
		n = write(cfd, halfclose[i], strlen(halfclose[i]));
		if(n < 0)
			_syserrno();
		close(cfd);
		if(n >= 0)
			return 0;
	}
	return -1;
}
