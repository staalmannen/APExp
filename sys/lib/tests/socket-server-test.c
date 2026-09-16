/*
 * Why can't anything listen on a socket?
 *
 *	pcc -o socket-server-test socket-server-test.c && ./socket-server-test
 *
 * WHERE THIS CAME FROM. Tcl's suite, first complete-ish run:
 *
 *	==== http11-1.0.0 normal request for document FAILED
 *	---- Test setup failed:
 *	can't wait for variable(s)/channel(s): would wait forever
 *	    while executing "vwait httpd_output"  (procedure "create_httpd")
 *
 * All 86 of http11.test's failures are that one line, and it is the
 * largest single cause in the whole suite by a factor of three. The
 * proximate error, seen 30 times across the log, is
 *
 *	couldn't open socket: operation not supported
 *
 * which is EOPNOTSUPP out of ap/network/bind.c:87 or listen.c:147 --
 * and it is very likely also behind the two files that HANG
 * (chanio.test, io.test), since a test that starts a server and then
 * waits for a callback that can never fire waits forever.
 *
 * SO THE INTERESTING PART IS NOT THE ERRNO, IT IS WHAT PLAN 9 SAID.
 * bind() tries the "bind" control message, and if the stack refuses it
 * falls back to "announce"; if THAT fails it reports EOPNOTSUPP and
 * throws the real message away:
 *
 *	if(n < 0){
 *		if(errno == EPLAN9)
 *			errno = EOPNOTSUPP;	<- the only survivor
 *		return -1;
 *	}
 *
 * EPLAN9 means "a Plan 9 error with no POSIX equivalent", and the text
 * of it is sitting in errstr() unread. One run of this prints it.
 *
 * Section 2 is therefore the point of the file: it opens
 * /net/tcp/clone itself and tries each spelling of the announce
 * message in turn, printing errstr() for each. Whichever one the stack
 * accepts is the answer -- the address syntax is not something to
 * reason about from a manual page when the machine will say.
 *
 * Section 1 is ordinary POSIX and is correct on glibc, which is how
 * the expectations in it were checked; section 2 cannot be, and skips
 * itself where there is no /net/tcp. THAT ASYMMETRY IS DELIBERATE: the
 * convention in CLAUDE.md is that anything testing a library rule must
 * be right on gcc first, and a probe of one operating system's network
 * stack is not a library rule.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int fail = 0;

static void
ok(int cond, const char *what)
{
	if(cond)
		printf("  PASS %s\n", what);
	else {
		printf("  FAIL %s (errno %d: %s)\n", what, errno, strerror(errno));
		fail++;
	}
}

/*
 * The Plan 9 error string, which is where the real message is.
 * errstr() is in libap (ap/plan9/errstr.c, a wrapper over _ERRSTR) and
 * declared in <lib9.h>; that header does not exist on the build host,
 * so it is declared by hand here rather than included, which keeps
 * section 1 compiling on gcc.
 *
 * THE DISCRIMINATOR IS __GNUC__, AND THE OBVIOUS ONES DO NOT WORK.
 * pcc predefines exactly two things (sys/src/cmd/pcc.c:77) --
 * __STDC__=1 and _POSIX_SOURCE= -- so _PLAN9_SOURCE and __plan9__ are
 * both absent from an ordinary `pcc -o x x.c`, and a guard on either
 * would compile section 2 into a function that prints "no errstr" on
 * every line. That is the "a check that cannot fail" trap from
 * CLAUDE.md, and it would have cost the whole round trip this test
 * exists to save. kencc is not gcc and gcc is, so this way round is
 * the one that cannot silently pick the wrong branch.
 */
#ifndef __GNUC__
#define HAVE_ERRSTR 1
#endif

#ifdef HAVE_ERRSTR
extern int errstr(char*, unsigned int);
static const char *
p9err(void)
{
	static char buf[256];
	buf[0] = '\0';
	errstr(buf, sizeof buf);
	return buf;
}
#else
static const char *
p9err(void)
{
	return "(no errstr on this system)";
}
#endif

int
main(void)
{
	int s, r;
	struct sockaddr_in sa;
	socklen_t slen;

	printf("--- 1. the POSIX sequence a server needs ---\n");
	/*
	 * Exactly what Tcl's [socket -server ... -myaddr 127.0.0.1 0]
	 * does, step by step, so the log says which call is the one that
	 * fails rather than only that the whole thing did.
	 */
	s = socket(AF_INET, SOCK_STREAM, 0);
	ok(s >= 0, "socket(AF_INET, SOCK_STREAM)");
	if(s < 0) {
		printf("\n%d failure(s)\n", fail);
		return fail;
	}

	memset(&sa, 0, sizeof sa);
	sa.sin_family = AF_INET;
	sa.sin_port = 0;			/* any port -- what Tcl asks for */
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");

	errno = 0;
	r = bind(s, (struct sockaddr *)&sa, sizeof sa);
	ok(r == 0, "bind(127.0.0.1, port 0)");
	if(r < 0)
		printf("       plan 9 says: %s\n", p9err());

	/*
	 * Tcl calls getsockname between bind and listen when it asked for
	 * port 0, and uses the answer as the port to connect to. A bind
	 * that "succeeds" without assigning a port is therefore just as
	 * fatal as one that fails, and reads as a hang rather than an
	 * error -- which is worth separating.
	 */
	slen = sizeof sa;
	memset(&sa, 0, sizeof sa);
	errno = 0;
	r = getsockname(s, (struct sockaddr *)&sa, &slen);
	ok(r == 0, "getsockname after bind");
	if(r == 0) {
		printf("       assigned port %d\n", (int)ntohs(sa.sin_port));
		ok(ntohs(sa.sin_port) != 0,
			"a real port was assigned, not still 0");
	}

	errno = 0;
	r = listen(s, 5);
	ok(r == 0, "listen(backlog 5)");
	if(r < 0)
		printf("       plan 9 says: %s\n", p9err());

	close(s);

	printf("\n--- 1a. which addresses does this machine call its own? ---\n");
	/*
	 * THE ANSWER TO SECTION 1 TURNED OUT TO BE A CONFIGURATION
	 * QUESTION, NOT A LIBRARY ONE. The first run of this test said
	 *
	 *	FAIL bind(127.0.0.1, port 0)  plan 9 says: not a local IP address
	 *	YES  "announce 0" accepted
	 *	YES  "announce *!0" accepted
	 *
	 * -- binding to ANY address works and binding to the loopback
	 * does not, because the stack does not think 127.0.0.1 belongs to
	 * it. /net/ipselftab is the list it decides that from, so print it
	 * rather than asking for another round trip.
	 *
	 * On 9front the loopback is configured by
	 *
	 *	ip/ipconfig loopback /dev/null 127.1
	 *
	 * which the standard startup normally does. If 127.0.0.1 is
	 * absent below, that line is the whole fix and no C changes are
	 * needed for any of it.
	 */
	{
		int f;
		char buf[1024];
		ssize_t n;

		f = open("/net/ipselftab", O_RDONLY);
		if(f < 0)
			printf("  no /net/ipselftab (%s)\n", strerror(errno));
		else {
			n = read(f, buf, sizeof buf - 1);
			close(f);
			if(n <= 0)
				printf("  /net/ipselftab is empty\n");
			else {
				buf[n] = '\0';
				printf("%s", buf);
				if(strstr(buf, "127.0.0.1") != NULL)
					printf("  -> 127.0.0.1 IS local; a bind to it"
						" should work\n");
				else
					printf("  -> 127.0.0.1 is NOT listed, which is"
						" exactly what\n     \"not a local IP"
						" address\" means. Try:\n"
						"        ip/ipconfig loopback /dev/null 127.1\n");
			}
		}
	}

	printf("\n--- 2. what the Plan 9 stack actually accepts ---\n");
	/*
	 * THE DECISIVE SECTION. ap/network/bind.c writes one of these
	 * strings to /net/tcp/clone and gives up if the stack refuses it.
	 * Rather than reason about which spelling 9front wants, write each
	 * one and print what comes back.
	 *
	 * Each attempt needs its OWN clone: a control file that has
	 * rejected a message is not necessarily still usable, and reusing
	 * one would make a later success or failure mean nothing.
	 */
	{
		static const char *tries[] = {
			"announce 0",
			"announce *!0",
			"announce 127.0.0.1!0",
			"bind 127.0.0.1!0",
			"announce tcp!*!0",
			NULL,
		};
		int i, cfd, any = 0;
		char buf[64];

		cfd = open("/net/tcp/clone", O_RDWR);
		if(cfd < 0) {
			printf("  SKIP no /net/tcp here (%s) -- section 2 is a\n",
				strerror(errno));
			printf("       Plan 9 probe and has nothing to say on"
				" this system\n");
		} else {
			close(cfd);
			for(i = 0; tries[i] != NULL; i++) {
				cfd = open("/net/tcp/clone", O_RDWR);
				if(cfd < 0) {
					printf("  open /net/tcp/clone: %s\n",
						strerror(errno));
					break;
				}
				/* the connection number comes back on first read */
				buf[0] = '\0';
				read(cfd, buf, sizeof buf - 1);

				errno = 0;
				r = write(cfd, tries[i], strlen(tries[i]));
				if(r < 0)
					printf("  no   \"%s\"\n         -> %s\n",
						tries[i], p9err());
				else {
					printf("  YES  \"%s\" accepted\n", tries[i]);
					any++;
				}
				close(cfd);
			}
			if(any == 0) {
				printf("\n  Nothing was accepted. Either this user cannot\n");
				printf("  announce, or the network is not configured --\n");
				printf("  check that /net/tcp exists and `ip/ipconfig` has run.\n");
			} else {
				printf("\n  bind.c should use a spelling from the YES lines\n");
				printf("  above; it currently tries \"bind\" and then\n");
				printf("  \"announce\" with the address from\n");
				printf("  _sock_inaddr2string.\n");
			}
		}
	}

	printf("\n%d failure(s)\n", fail);
	return fail;
}
