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
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>

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

/*
 * SECTION 3 NEEDS A TIMEOUT RATHER THAN A FREEZE. The thing it is
 * asking about hangs when it goes wrong -- that is the whole symptom --
 * and a test that hangs reports nothing at all, while one that times out
 * says which statement it was in. Every blocking call below is behind an
 * alarm and a named stage.
 */
static const char *stage = "nothing yet";

static void
alarmed(int sig)
{
	(void)sig;
	/*
	 * Written with write(2) rather than printf: this is a signal
	 * handler, and the point of it is to be believed.
	 */
	write(1, "  FAIL TIMED OUT at: ", 21);
	write(1, stage, strlen(stage));
	write(1, "\n", 1);
	_exit(1);
}

static int
stalled(const char *what)
{
	stage = what;
	alarm(10);
	return 0;
}

static void
arrived(void)
{
	alarm(0);
}

/*
 * WHICH libap THIS BINARY IS LINKED AGAINST. `pcc -o x x.c' links
 * against the INSTALLED library, so a test rebuilt from a fresh pull can
 * still be running library code from before it -- and nothing in the
 * output would say. Two rounds were lost that way here. If the link
 * fails with an undefined `_sock_listenmark', the installed libap
 * predates the change entirely, and that is the answer.
 */
#ifndef __GNUC__
extern int _sock_listenmark(void);
#define LISTENMARK _sock_listenmark()
#else
#define LISTENMARK (-1)
#endif

int
main(void)
{
	int fd, port, i, again;
	int ss, cs, as;
	struct sockaddr_in a;
	socklen_t alen;
	char buf[64];
	int n;

	printf("--- 0. which libap is linked in ---\n");
	if(LISTENMARK < 0)
		printf("  note built with gcc; libap is not involved\n");
	else {
		printf("  note libap listen bookkeeping: mark %d"
			" (this tree is 8)\n", LISTENMARK);
		printf("  note if that is not 8, `mk install' has not reached\n");
		printf("  note the installed library and nothing below is\n");
		printf("  note about the code you just pulled\n");
	}

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

	printf("--- 3. close the LISTENER while a connection is in use ---\n");
	/*
	 * Tcl's chan-io-29.34 reduced, and it is where the suite stopped.
	 * That test accepts a connection, writes 2000 lines into it,
	 * closes the client, CLOSES THE LISTENING SOCKET, and only then
	 * waits for the accepted connection to drain and report end of
	 * file. So closing a listener must not disturb a connection that
	 * has already been accepted -- and close() now ends the process
	 * that was listening, which is a new thing for it to do.
	 *
	 * The read before the close is a control: without it, a failure
	 * after the close would not distinguish "the close broke it" from
	 * "it never worked".
	 *
	 * BUT A PASS HERE HAS TWO EXPLANATIONS, and the output says so
	 * rather than leaving the reader to notice. This section passes if
	 * the listener was killed and the accepted connection was
	 * undisturbed -- and equally if the listener was never killed at
	 * all. It can only CONVICT the kill, never clear it. Sections 1
	 * and 2 are what say whether a kill happened, and when they fail
	 * while this passes, the reading is "no kill happened", not "the
	 * kill is harmless".
	 */
	signal(SIGALRM, alarmed);
	port = 0;
	if((ss = listenon(0, &port)) < 0){
		ok("section 3 could not make a listening socket", 0);
		goto done;
	}
	if((cs = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		why("socket for the client");
		ok("section 3 could not make a client", 0);
		goto done;
	}
	memset(&a, 0, sizeof a);
	a.sin_family = AF_INET;
	a.sin_port = htons((unsigned short)port);
	a.sin_addr.s_addr = htonl(0x7f000001);	/* 127.0.0.1 */
	stalled("connect to the listener");
	if(connect(cs, (struct sockaddr*)&a, sizeof a) < 0){
		arrived();
		why("connect");
		printf("  note no loopback? see the note about ip/ipconfig\n");
		ok("section 3 could not connect", 0);
		goto done;
	}
	arrived();
	alen = sizeof a;
	stalled("accept the connection");
	as = accept(ss, (struct sockaddr*)&a, &alen);
	arrived();
	if(as < 0){
		why("accept");
		ok("section 3 could not accept", 0);
		goto done;
	}

	write(cs, "one\n", 4);
	stalled("read the first message, BEFORE the listener is closed");
	n = read(as, buf, sizeof buf);
	arrived();
	ok("a message arrives before the listener is closed", n == 4);

	/* THE CLOSE UNDER TEST */
	if(close(ss) < 0)
		why("close the listening socket");

	write(cs, "two\n", 4);
	stalled("read the second message, AFTER the listener is closed");
	n = read(as, buf, sizeof buf);
	arrived();
	ok("...and one still arrives after it is closed", n == 4);

	close(cs);
	stalled("read end of file once the client has gone");
	n = read(as, buf, sizeof buf);
	arrived();
	ok("the accepted connection reports end of file", n == 0);
	close(as);
	printf("  note a PASS above means the kill did not break this\n");
	printf("  note connection -- OR that no kill happened. Sections 1\n");
	printf("  note and 2 are what tell those apart; if they FAILED,\n");
	printf("  note nothing was killed and this section proves nothing.\n");
	printf("  note APEXP_LISTENDEBUG=1 makes libap say which it was.\n");

	printf("--- 4. a SECOND server, on the descriptor the first freed ---\n");
	/*
	 * Tcl's socket_inet-2.11 reduced, and it is where the suite stops
	 * now. The debug lines put it exactly:
	 *
	 *	listenpid: killing the listener fd=10 pid=12945
	 *	listenpid: ...gone fd=10
	 *	listenpid: recorded a listener fd=10 pid=12950
	 *	---- socket_inet-2.11 start
	 *	<the event loop ticks a few times, then nothing>
	 *
	 * tcltest runs -setup BEFORE printing `start' ("Verbose
	 * notification of $body start"), so the second listener is that
	 * test's own, and the body then blocks at `vwait sock' -- the
	 * connection is never accepted.
	 *
	 * WHAT SECTIONS 1 TO 3 ALL MISS: none of them accepts a connection
	 * on a SECOND server made after a first one was killed. Section 2
	 * rebinds five times and never accepts; section 3 accepts once and
	 * never makes a second server. The descriptor number comes back --
	 * fd=10 both times above -- and with it whatever state the library
	 * keeps per descriptor.
	 *
	 * So: three full rounds of listen/connect/accept/exchange/close. If
	 * the first passes and a later one hangs, the state left behind by
	 * killing a listener is the thing to look at, and *When a struct is
	 * recycled, reset every field that means something* is already a
	 * rule in this tree.
	 */
	for(i = 0; i < 3; i++){
		char what[64];

		port = 0;
		if((ss = listenon(0, &port)) < 0){
			printf("  note round %d could not listen\n", i);
			ok("three rounds of listen/accept/close", 0);
			break;
		}
		if((cs = socket(AF_INET, SOCK_STREAM, 0)) < 0){
			why("socket for the client");
			ok("three rounds of listen/accept/close", 0);
			break;
		}
		memset(&a, 0, sizeof a);
		a.sin_family = AF_INET;
		a.sin_port = htons((unsigned short)port);
		a.sin_addr.s_addr = htonl(0x7f000001);
		sprintf(what, "round %d: connect", i);
		stalled(what);
		if(connect(cs, (struct sockaddr*)&a, sizeof a) < 0){
			arrived();
			why(what);
			ok("three rounds of listen/accept/close", 0);
			break;
		}
		arrived();
		sprintf(what, "round %d: ACCEPT (2.11 blocks here)", i);
		stalled(what);
		alen = sizeof a;
		as = accept(ss, (struct sockaddr*)&a, &alen);
		arrived();
		if(as < 0){
			why(what);
			ok("three rounds of listen/accept/close", 0);
			break;
		}
		write(cs, "one\n", 4);
		sprintf(what, "round %d: read the message", i);
		stalled(what);
		n = read(as, buf, sizeof buf);
		arrived();
		if(n != 4){
			printf("  note round %d read %d bytes, wanted 4\n", i, n);
			ok("three rounds of listen/accept/close", 0);
			break;
		}
		printf("  note round %d: listened on %d, accepted, exchanged\n",
			i, port);
		close(as);
		close(cs);
		close(ss);		/* kills the listener; fd numbers freed */
	}
	if(i == 3)
		ok("three rounds of listen/accept/close", 1);

	printf("--- 5. ...and waited for with select(), as Tcl does ---\n");
	/*
	 * SECTION 4 PASSED, WHICH REFUTED THE REDUCTION RATHER THAN THE
	 * LIBRARY, and the difference is the whole of it.
	 *
	 * socket_inet-2.11 does not call accept() and wait. It uses
	 * `socket -server' with Tcl's event loop, so the listening socket
	 * is handed to SELECT, and `vwait sock' returns only when select
	 * says the socket is readable and the accept callback runs.
	 *
	 * In libap a listening socket is a PIPE and select() on it is a
	 * COPY PROCESS reading that pipe (plan9/_buf.c) -- a whole
	 * mechanism that a blocking accept() never touches, because it
	 * reads the pipe itself. Killing a listener closes the pipe's write
	 * end under that copy process, which is new, and then the
	 * descriptor is reused for the next server.
	 *
	 * So this is section 4 again with one line changed: wait for the
	 * socket with select() before accepting. select's OWN timeout
	 * reports the failure -- "never became readable" is a better
	 * sentence than "the alarm fired", and it distinguishes a socket
	 * that select ignores from a process stuck somewhere else.
	 *
	 * Correct on glibc: three rounds, select returns 1 each time.
	 */
	for(i = 0; i < 3; i++){
		fd_set rd;
		struct timeval tv;
		int r;

		port = 0;
		if((ss = listenon(0, &port)) < 0){
			printf("  note round %d could not listen\n", i);
			ok("three rounds waited for with select()", 0);
			break;
		}
		if((cs = socket(AF_INET, SOCK_STREAM, 0)) < 0){
			why("socket for the client");
			ok("three rounds waited for with select()", 0);
			break;
		}
		memset(&a, 0, sizeof a);
		a.sin_family = AF_INET;
		a.sin_port = htons((unsigned short)port);
		a.sin_addr.s_addr = htonl(0x7f000001);
		if(connect(cs, (struct sockaddr*)&a, sizeof a) < 0){
			why("connect");
			ok("three rounds waited for with select()", 0);
			break;
		}
		FD_ZERO(&rd);
		FD_SET(ss, &rd);
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		r = select(ss+1, &rd, 0, 0, &tv);
		if(r == 0){
			printf("  note round %d: select TIMED OUT -- the listening\n", i);
			printf("  note socket never became readable, which is\n");
			printf("  note precisely what `vwait sock' waits for\n");
			ok("three rounds waited for with select()", 0);
			break;
		}
		if(r < 0){
			why("select on the listening socket");
			ok("three rounds waited for with select()", 0);
			break;
		}
		alen = sizeof a;
		if((as = accept(ss, (struct sockaddr*)&a, &alen)) < 0){
			why("accept after select said readable");
			ok("three rounds waited for with select()", 0);
			break;
		}
		write(cs, "one\n", 4);
		n = read(as, buf, sizeof buf);
		printf("  note round %d: select said readable, accepted, read %d\n",
			i, n);
		close(as);
		close(cs);
		close(ss);
	}
	if(i == 3)
		ok("three rounds waited for with select()", 1);


done:
	printf("%d failure(s)\n", failures);
	return failures;
}
