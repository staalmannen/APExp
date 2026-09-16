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
 *
 * SECTIONS 3 AND 4 ARE THE SAME PAIR ASKED ABOUT HALF-CLOSE, and were
 * added once the loopback fix let the suite reach chan-io-28.7. Section
 * 3 is the POSIX sequence -- write, shutdown(SHUT_WR), and does the
 * peer see EOF -- asserted, and correct on glibc. Section 4 is the
 * Plan 9 probe that says which control message, if any, this stack
 * accepts for it, and skips itself off Plan 9.
 *
 * Read them in that order: section 3 says whether it WORKS, section 4
 * says what to write in ap/network/shutdown.c if it does not. The
 * distinction is the one the announce work had to learn -- a control
 * message the stack accepts is not the same as the effect you wanted,
 * so the assertion is on the EOF and not on the write.
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
#include <sys/select.h>
#include <sys/time.h>

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
	int s, r, bound;
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
	bound = bind(s, (struct sockaddr *)&sa, sizeof sa);
	ok(bound == 0, "bind(127.0.0.1, port 0)");
	if(bound < 0)
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

	/*
	 * LISTEN AFTER A FAILED BIND MEANS NOTHING, AND REPORTING IT AS A
	 * PASS IS WORSE THAN SAYING NOTHING.
	 *
	 * The first run of this file printed
	 *
	 *	FAIL bind(127.0.0.1, port 0)   not a local IP address
	 *	FAIL listen(backlog 5)         connection in use
	 *
	 * and the second, after one entry was added to the errno table,
	 *
	 *	FAIL bind(127.0.0.1, port 0)   Address not available
	 *	PASS listen(backlog 5)
	 *
	 * -- a PASS on a socket with no address and no port, which is not
	 * a working listener by any reading. The sequence is bind THEN
	 * listen; once bind has failed, whatever listen does next is
	 * undefined and its result is not evidence of anything.
	 *
	 * (Why it moved at all is the coupling documented in
	 * ap/network/bind.c: the announce fallback there is gated on
	 * errno == EPLAN9, meaning "an error nothing recognised", so
	 * naming an error in the table stops the fallback from running for
	 * it. One less announce attempt is the whole difference.)
	 *
	 * "A check that cannot fail is not a check" is in CLAUDE.md; this
	 * is its twin -- a check that can PASS for the wrong reason.
	 */
	if(bound < 0)
		printf("  SKIP listen: bind failed, so listen's result would\n"
			"       mean nothing either way\n");
	else {
		errno = 0;
		r = listen(s, 5);
		ok(r == 0, "listen(backlog 5)");
		if(r < 0)
			printf("       plan 9 says: %s\n", p9err());
	}

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

	printf("\n--- 3. half-close: does the peer ever see EOF? ---\n");
	/*
	 * chan-io-28.7, in C. Tcl's test is
	 *
	 *	set s [socket 127.0.0.1 $port]
	 *	puts $s Hey
	 *	close $s w		<- shutdown(fd, SHUT_WR)
	 *	... wait for the server's reply ...
	 *
	 * and the server half reads to EOF before answering, so a
	 * shutdown that sends no FIN is not a wrong answer -- it is a
	 * HANG. It reported
	 *
	 *	Result was:              Failed Hey
	 *	Result should have been: Succeeded {Hey DONE}
	 *
	 * "Failed" there is the test's own 1000ms timer firing. A program
	 * without one waits for ever.
	 *
	 * ap/network/shutdown.c was a four-line stub that returned 0
	 * without doing anything (and closed the descriptor for
	 * SHUT_RDWR, which POSIX does not). This section is the whole
	 * sequence end to end, so it says whether the FIN arrives rather
	 * than whether a control message was accepted -- which is the
	 * distinction the announce work had to learn the hard way: a
	 * write the stack accepts is not the same as the effect you
	 * wanted.
	 *
	 * EVERY ASSERTION HERE IS CORRECT ON GLIBC and was checked there,
	 * per the convention in CLAUDE.md. select() is used rather than a
	 * bare read() so that a stack which never sends the FIN makes
	 * this test FAIL in two seconds instead of hanging the way the
	 * suite did.
	 */
	{
		int srv = -1, cli = -1, acc = -1;
		struct sockaddr_in la;
		socklen_t llen;
		char rbuf[64];
		int got, eof, sawdata;

		srv = socket(AF_INET, SOCK_STREAM, 0);
		memset(&la, 0, sizeof la);
		la.sin_family = AF_INET;
		la.sin_port = 0;
		la.sin_addr.s_addr = inet_addr("127.0.0.1");
		if(srv < 0 || bind(srv, (struct sockaddr *)&la, sizeof la) < 0
		|| listen(srv, 5) < 0){
			printf("  SKIP no loopback listener here (%s); section 1\n",
				strerror(errno));
			printf("       above says why, and half-close cannot be\n");
			printf("       measured until that works\n");
			if(srv >= 0)
				close(srv);
		} else {
			llen = sizeof la;
			r = getsockname(srv, (struct sockaddr *)&la, &llen);
			ok(r == 0, "getsockname on the listener");

			cli = socket(AF_INET, SOCK_STREAM, 0);
			errno = 0;
			r = connect(cli, (struct sockaddr *)&la, sizeof la);
			ok(r == 0, "connect to our own listener");
			if(r < 0)
				printf("       plan 9 says: %s\n", p9err());

			if(r == 0){
				acc = accept(srv, NULL, NULL);
				ok(acc >= 0, "accept");
			}

			if(acc >= 0){
				write(cli, "Hey\n", 4);

				errno = 0;
				r = shutdown(cli, SHUT_WR);
				ok(r == 0, "shutdown(client, SHUT_WR)");
				if(r < 0)
					printf("       plan 9 says: %s\n", p9err());

				/*
				 * Read the server side until it reports end of
				 * file. THE EOF IS THE WHOLE POINT: the data
				 * arrives whatever shutdown does, so a test that
				 * only checked for "Hey" would pass on the stub.
				 */
				sawdata = eof = 0;
				for(;;){
					fd_set rs;
					struct timeval tv;

					FD_ZERO(&rs);
					FD_SET(acc, &rs);
					tv.tv_sec = 2;
					tv.tv_usec = 0;
					r = select(acc + 1, &rs, NULL, NULL, &tv);
					if(r <= 0)
						break;		/* timed out: no FIN */
					got = read(acc, rbuf, sizeof rbuf);
					if(got > 0)
						sawdata = 1;
					else if(got == 0) {
						eof = 1;
						break;
					} else
						break;
				}
				ok(sawdata, "the data written before the shutdown arrived");
				ok(eof, "the peer saw END OF FILE after SHUT_WR");
				if(!eof)
					printf("       -- no FIN. This is chan-io-28.7, and any\n"
						"          program that reads to EOF before replying\n"
						"          hangs here. See section 4.\n");

				/*
				 * And the descriptor must still be ours. The old
				 * shutdown() closed it for SHUT_RDWR, so the
				 * caller's own close() then shut whatever file had
				 * since taken the number.
				 */
				errno = 0;
				r = shutdown(cli, SHUT_RDWR);
				printf("  note shutdown(client, SHUT_RDWR) returned %d\n", r);
				errno = 0;
				r = close(cli);
				ok(r == 0,
					"the descriptor survives SHUT_RDWR, so close() works");
				cli = -1;
			}

			if(acc >= 0)
				close(acc);
			if(cli >= 0)
				close(cli);
			close(srv);
		}
	}

	printf("\n--- 4. what the Plan 9 stack calls a half-close ---\n");
	/*
	 * Section 2's method on a different question, and for the same
	 * reason: ap/network/shutdown.c has to write SOMETHING to the
	 * connection's ctl file, the right word is not knowable from
	 * here, and the machine will say. The list below is the same list
	 * shutdown.c tries, in the same order -- keep them in step.
	 *
	 * A connection is set up the Plan 9 way rather than through the
	 * sockets layer, because what is wanted is the ctl file itself.
	 */
	{
		static const char *tries[] = {
			"close", "shutdown", "halfclose", "fin", NULL,
		};
		int i, lfd, cfd, pfd, any = 0;
		char buf[128], dir[160], path[224], port[64];
		ssize_t n;

		lfd = open("/net/tcp/clone", O_RDWR);
		if(lfd < 0) {
			printf("  SKIP no /net/tcp here (%s) -- section 4 is a\n",
				strerror(errno));
			printf("       Plan 9 probe and has nothing to say on"
				" this system\n");
		} else {
			buf[0] = '\0';
			n = read(lfd, buf, sizeof buf - 1);
			if(n <= 0)
				n = 0;
			buf[n] = '\0';
			/* the clone file's first read is the connection number */
			snprintf(dir, sizeof dir, "/net/tcp/%s", buf);

			if(write(lfd, "announce 127.0.0.1!0", 20) < 0) {
				printf("  could not announce: %s\n", p9err());
				close(lfd);
			} else {
				snprintf(path, sizeof path, "%s/local", dir);
				port[0] = '\0';
				pfd = open(path, O_RDONLY);
				if(pfd >= 0) {
					n = read(pfd, port, sizeof port - 1);
					close(pfd);
					if(n < 0)
						n = 0;
					port[n] = '\0';
				}
				printf("  listener local address: %s", port[0] ? port : "?\n");

				for(i = 0; tries[i] != NULL; i++) {
					char cpath[128];

					cfd = open("/net/tcp/clone", O_RDWR);
					if(cfd < 0) {
						printf("  open clone: %s\n", strerror(errno));
						break;
					}
					buf[0] = '\0';
					n = read(cfd, buf, sizeof buf - 1);
					if(n < 0)
						n = 0;
					buf[n] = '\0';

					/*
					 * Connect to the port the listener got. The
					 * local file reads "127.0.0.1!NNNN"; take it
					 * whole, minus the newline.
					 */
					{
						char addr[64];
						char *nl;

						snprintf(addr, sizeof addr, "%s", port);
						nl = strchr(addr, '\n');
						if(nl != NULL)
							*nl = '\0';
						snprintf(cpath, sizeof cpath, "connect %s", addr);
						if(write(cfd, cpath, strlen(cpath)) < 0) {
							printf("  connect failed: %s\n", p9err());
							close(cfd);
							break;
						}
					}

					errno = 0;
					r = write(cfd, tries[i], strlen(tries[i]));
					if(r < 0)
						printf("  no   ctl \"%s\"\n         -> %s\n",
							tries[i], p9err());
					else {
						printf("  YES  ctl \"%s\" accepted\n", tries[i]);
						any++;
					}
					close(cfd);
				}
				close(lfd);

				if(any == 0)
					printf("\n  Nothing was accepted, so this stack has no\n"
						"  half-close and shutdown(fd, SHUT_WR) cannot do\n"
						"  one. Anything that reads to EOF before replying\n"
						"  -- an HTTP/1.0 client, Tcl's chan-io-28.7 -- is\n"
						"  unfixable in libap until the kernel grows one.\n");
				else
					printf("\n  Put the accepted spelling FIRST in\n"
						"  halfclose[] in ap/network/shutdown.c, and drop\n"
						"  the ones that were refused.\n");
			}
		}
	}

	printf("\n%d failure(s)\n", fail);
	return fail;
}
