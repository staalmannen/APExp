/*
 * listenleak-test.c -- does closing a listening socket release its port?
 *
 * WHERE THIS CAME FROM. Tcl's socket_inet-5.1 and 5.3 ask that binding a
 * privileged port be REFUSED, and they had been passing. Then they
 * failed, and the obvious suspect was an errno change in the same
 * commit. It was not: both tests return a fixed string whichever way the
 * error goes, so only success versus failure matters, and Tcl's server
 * path tests exactly one errno (EADDRINUSE, twice, both guarded by
 * port == 0). What settled it was one command on the VM, in a fresh
 * tclsh with no suite running:
 *
 *	% socket -server {apply {{c a p} {}}} 1
 *	couldn't open socket: address already in use
 *
 * Port 1 was still announced, left by the previous run's own
 * socket_inet-5.1 -- which had bound it, failed for that reason, and
 * called `close $msg'. So the tests had been passing for the WRONG
 * REASON: a leftover listener was refusing the bind, not the system.
 *
 * WHY close() FREED NOTHING. listen() does not keep the socket in the
 * calling process: ap/network/listen.c replaces the descriptor with a
 * PIPE, so that select() can work on it, and forks a child that holds
 * the real network descriptor and blocks in open("/net/tcp/N/listen").
 * The parent's close() therefore shuts a pipe while the announcement
 * lives in another process. `_killmuxsid` kills that process group at
 * exit, which is no help to a program that closes a listener and keeps
 * running -- and no help at all to a run that ends by interrupt, note or
 * fault, where no atexit handler runs. Hence the hundred-odd leftover
 * processes this tree had already noted without connecting them to
 * anything.
 *
 * WHAT IT ASKS. Bind a listening socket to port 0, ask which port the
 * system chose, close it, and bind that same port again. On any system
 * that frees the port this is unremarkable; here it was impossible.
 *
 * SECTION 2 IS THE ONE THAT WOULD HAVE CAUGHT THE LEAK EARLIER: the same
 * thing five times over. A single iteration can pass by luck -- the
 * ephemeral port the system hands out the second time need not be the
 * one it just took away -- and asking for the SAME port back is what
 * makes the question sharp.
 *
 * Correct on glibc, which is where it was checked. Note that no
 * SO_REUSEADDR appears anywhere: a listening socket that never accepted
 * a connection has nothing in TIME_WAIT, so its port is immediately
 * reusable, and setting SO_REUSEADDR would hide exactly the failure this
 * file exists to find.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
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

/*
 * Make a listening socket on `port' (0 for "any"), and report which port
 * it ended up on. Returns the descriptor, or -1.
 */
static int
listenon(int port, int *got)
{
	struct sockaddr_in a;
	socklen_t alen;
	int fd;

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		why("socket");
		return -1;
	}
	memset(&a, 0, sizeof a);
	a.sin_family = AF_INET;
	a.sin_port = htons((unsigned short)port);
	a.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(fd, (struct sockaddr*)&a, sizeof a) < 0){
		why(port ? "bind to the port just released" : "bind to port 0");
		close(fd);
		return -1;
	}
	if(listen(fd, 5) < 0){
		why("listen");
		close(fd);
		return -1;
	}
	if(got != 0){
		alen = sizeof a;
		memset(&a, 0, sizeof a);
		if(getsockname(fd, (struct sockaddr*)&a, &alen) < 0){
			why("getsockname");
			close(fd);
			return -1;
		}
		*got = ntohs(a.sin_port);
	}
	return fd;
}

int
main(void)
{
	int fd, port, i, again;

	printf("--- 1. close a listener, then take its port back ---\n");
	port = 0;
	if((fd = listenon(0, &port)) < 0){
		printf("  note could not make a listening socket at all;\n");
		printf("  note nothing below can be measured\n");
		printf("1 failure(s)\n");
		return 1;
	}
	printf("  note the system chose port %d\n", port);
	ok("a port was actually assigned", port > 0);
	if(close(fd) < 0)
		why("close the listening socket");

	errno = 0;
	if((fd = listenon(port, 0)) < 0){
		printf("  note the port is still held by SOMETHING after the\n");
		printf("  note socket that announced it was closed\n");
		ok("the port can be bound again once the socket is closed", 0);
	} else {
		ok("the port can be bound again once the socket is closed", 1);
		close(fd);
	}

	printf("--- 2. five times over, which is what makes it sharp ---\n");
	/*
	 * One round can pass by luck; asking for the same port back, five
	 * times, cannot. A leak shows up on the second iteration.
	 */
	again = 0;
	for(i = 0; i < 5; i++){
		port = 0;
		if((fd = listenon(0, &port)) < 0){
			printf("  note iteration %d could not listen\n", i);
			again++;
			break;
		}
		close(fd);
		errno = 0;
		if((fd = listenon(port, 0)) < 0){
			printf("  note iteration %d could not retake port %d\n",
				i, port);
			again++;
			break;
		}
		close(fd);
	}
	ok("five close-and-rebind rounds all succeeded", again == 0);

	printf("%d failure(s)\n", failures);
	return failures;
}
