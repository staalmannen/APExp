/*
 * asyncconnect-test.c -- connect() on a non-blocking socket, and the
 * error it reports afterwards.
 *
 * WHERE THIS CAME FROM. Tcl's socket-14.14 and socket-14.15 do
 *
 *	set s [socket -async localhost [randport]]
 *
 * and they had been PASSING for the wrong reason: `randport' certifies
 * a port free by opening and closing a server socket on it, and the
 * listener leak left a process holding the very port it had just
 * certified, so the connect reached that leftover and succeeded. With
 * the leak fixed the port is genuinely dead, the connect is genuinely
 * refused -- and the error came back from the `socket' command itself
 * instead of arriving later on a fileevent. That is when it became
 * visible that -async had never worked: lib/ap/network/connect.c had no
 * O_NONBLOCK, no EINPROGRESS, and no deferred completion at all.
 *
 * THE TWO HALVES, AND THE SECOND IS THE ONE THAT ROTS QUIETLY.
 * connect() must not do the whole conversation when the descriptor is
 * non-blocking; and getsockopt(SO_ERROR) must report what happened.
 * That second one returned a hard-coded 0 -- "no error" for a
 * connection that was never made -- which is the `XLoadFont' family
 * this tree records as its most common bug. A test that only checked
 * the first half would pass over it.
 *
 * WHY THIS DOES NOT ASSERT EINPROGRESS. On Linux a non-blocking connect
 * to a dead port on the LOOPBACK usually fails immediately with
 * ECONNREFUSED: there is no round trip to wait for, so there is nothing
 * to be in progress. Asserting EINPROGRESS would then fail on glibc and
 * say nothing about either system. What both must agree on is the
 * CONTRACT:
 *
 *	a non-blocking connect either resolves now or reports
 *	EINPROGRESS, and if it reported EINPROGRESS then SO_ERROR
 *	afterwards gives the real answer and never a false 0.
 *
 * Section 3 is the control: the same connect on a BLOCKING socket must
 * still fail with ECONNREFUSED as it always did, so a change that broke
 * ordinary connects could not hide behind the sections above.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef __GNUC__
#define HAVE_ERRSTR 1
#endif

#ifdef HAVE_ERRSTR
extern int errstr(char*, unsigned int);
static const char *
p9err(void)
{
	static char buf[256];

	buf[0] = 0;
	errstr(buf, sizeof buf);
	return buf;
}
#else
static const char *
p9err(void)
{
	return "";
}
#endif

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static void
why(const char *what)
{
	const char *pe;

	pe = p9err();
	printf("  note %s -> errno %d (%s)%s%s\n", what, errno,
		strerror(errno), pe[0] ? "; plan 9 says: " : "", pe);
}

static void
addr(struct sockaddr_in *a, int port)
{
	memset(a, 0, sizeof *a);
	a->sin_family = AF_INET;
	a->sin_port = htons((unsigned short)port);
	a->sin_addr.s_addr = htonl(0x7f000001);		/* 127.0.0.1 */
}

/*
 * A port nothing is listening on, found the way Tcl's randport does:
 * take one from a server socket and give it back. Unlike randport this
 * does NOT then re-verify it, because the verification is what used to
 * leave a listener holding the port -- see the note at the top.
 */
static int
deadport(void)
{
	struct sockaddr_in a;
	socklen_t alen;
	int fd, port;

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;
	addr(&a, 0);
	if(bind(fd, (struct sockaddr*)&a, sizeof a) < 0 || listen(fd, 1) < 0){
		close(fd);
		return -1;
	}
	alen = sizeof a;
	if(getsockname(fd, (struct sockaddr*)&a, &alen) < 0){
		close(fd);
		return -1;
	}
	port = ntohs(a.sin_port);
	close(fd);
	return port;
}

static int
soerror(int fd, int *err)
{
	socklen_t len;
	int e;

	len = sizeof e;
	e = 0;
	if(getsockopt(fd, SOL_SOCKET, SO_ERROR, (void*)&e, &len) < 0){
		why("getsockopt SO_ERROR");
		return -1;
	}
	*err = e;
	return 0;
}

int
main(void)
{
	struct sockaddr_in a;
	int fd, port, e, r, lis;

	printf("--- 1. a non-blocking connect to a dead port ---\n");
	if((port = deadport()) < 0){
		printf("  note could not find a free port; nothing to measure\n");
		printf("1 failure(s)\n");
		return 1;
	}
	printf("  note using port %d, which nothing is listening on\n", port);
	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		why("socket");
		printf("1 failure(s)\n");
		return 1;
	}
	if(fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
		why("fcntl O_NONBLOCK");
	addr(&a, port);
	errno = 0;
	r = connect(fd, (struct sockaddr*)&a, sizeof a);
	if(r == 0){
		printf("  note it connected, so the port was not dead after all;\n");
		printf("  note this section cannot say anything\n");
	} else {
		why("non-blocking connect to a dead port");
		e = errno;
		ok("it reported EINPROGRESS, or resolved at once with ECONNREFUSED",
			e == EINPROGRESS || e == ECONNREFUSED);
		if(e == EINPROGRESS){
			/*
			 * THE HALF THAT USED TO BE A HARD-CODED 0. A
			 * connection that was refused must not read back as
			 * "no error".
			 */
			if(soerror(fd, &e) == 0){
				printf("  note SO_ERROR says %d (%s)\n",
					e, strerror(e));
				ok("...and SO_ERROR then gives the real failure",
					e != 0);
			}
		}
	}
	close(fd);

	printf("--- 2. a non-blocking connect that SUCCEEDS ---\n");
	if((lis = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		why("socket for the listener");
		goto blocking;
	}
	addr(&a, 0);
	if(bind(lis, (struct sockaddr*)&a, sizeof a) < 0 || listen(lis, 1) < 0){
		why("bind/listen");
		close(lis);
		goto blocking;
	}
	{
		socklen_t alen = sizeof a;

		if(getsockname(lis, (struct sockaddr*)&a, &alen) < 0){
			why("getsockname");
			close(lis);
			goto blocking;
		}
		port = ntohs(a.sin_port);
	}
	printf("  note listening on port %d\n", port);
	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		why("socket");
		close(lis);
		goto blocking;
	}
	if(fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
		why("fcntl O_NONBLOCK");
	addr(&a, port);
	errno = 0;
	r = connect(fd, (struct sockaddr*)&a, sizeof a);
	if(r < 0){
		why("non-blocking connect to a live port");
		e = errno;
		ok("a connect that will succeed reports EINPROGRESS, not an error",
			e == EINPROGRESS);
	} else
		printf("  note it connected straight away\n");
	if(soerror(fd, &e) == 0){
		printf("  note SO_ERROR says %d (%s)\n", e, strerror(e));
		ok("SO_ERROR is 0 for a connect that succeeded", e == 0);
	}
	close(fd);
	close(lis);

blocking:
	printf("--- 3. the control: a BLOCKING connect still fails ---\n");
	/*
	 * If this stopped working, everything above could be passing while
	 * ordinary connects were broken.
	 */
	if((port = deadport()) < 0)
		printf("  note could not find a free port; section 3 skipped\n");
	else if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		why("socket");
	else {
		addr(&a, port);
		errno = 0;
		if(connect(fd, (struct sockaddr*)&a, sizeof a) == 0)
			printf("  note it connected; the port was not dead\n");
		else {
			why("blocking connect to a dead port");
			ok("...and it is ECONNREFUSED, as it always was",
				errno == ECONNREFUSED);
		}
		close(fd);
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
