/*
 * Does select() report a descriptor ready?
 *
 *	pcc -o select-test select-test.c && ./select-test
 *
 * WHERE THIS CAME FROM. Two facts measured on the VM by
 * sys/lib/tests/tcl-fileevent-test.tcl, which are the whole of why
 * Tcl's event.test hangs at event-11.5:
 *
 *	5a  FAIL  a readable pipe is reported to a non-blocking poll
 *	5b  PASS  a readable pipe is reported to a blocking wait
 *	7b  FAIL  a closed peer reports readable
 *	8         x (writable on a file) = 2533503,  y (readable
 *	          on a socket whose peer closed) = 0
 *
 * event-11.5 waits on two sources whose handlers each end the wait only
 * when the OTHER one's counter reaches 3. The writable half ran two and
 * a half million times; the socket half never ran once. So the hang is
 * not a fairness problem -- one source is simply dead.
 *
 * THESE ARE TWO SEPARATE BUGS AND THIS FILE ASKS THEM SEPARATELY,
 * because they want different fixes:
 *
 *   1. A NON-BLOCKING POLL NEVER REPORTS ANYTHING (sections 2 and 3).
 *   2. A CONNECTION WHOSE PEER HAS CLOSED IS NEVER READABLE (4 and 5).
 *
 * WHAT THE FIRST VM RUN ANSWERED, because half of the above is now
 * settled and the other half is refuted:
 *
 *	1  PASS   blocking select on a pipe with data
 *	2  FAIL   the same pipe to a zero-timeout poll
 *	3  FAIL   ten more immediate polls, still nothing
 *	4  PASS   closed peer, data pending, readable; read gave 7
 *	5  PASS   closed peer, nothing written, readable; read gave 0
 *	6  PASS   writable on a plain file
 *
 * BUG 1 IS REAL AND IS IN select(). BUG 2 DOES NOT EXIST AT THIS
 * LEVEL: a closed peer is reported readable both ways round, and the
 * read that follows answers exactly what POSIX asks. So Tcl's 7b is
 * failing somewhere above this call, and sections 7 and 8 were added
 * to find out where -- 7 asks the one state section 4 skipped (the
 * end of file AFTER the data has been drained), and 8 rebuilds
 * event-11.5's mixed read/write set in C.
 *
 * Section 3's original answer was thrown away as well; see the note on
 * it below. It said "NEVER" off ten polls that take microseconds.
 *
 * WHY IT IS WORTH GOING DOWN TO C. Tcl's notifier is select(), and on
 * Plan 9 select() is not a system call: ap/plan9/_buf.c implements it
 * with a COPY PROCESS per descriptor, forked by _startbuf() on the
 * first select that names the fd, reading into a shared Muxbuf. select
 * then answers from `b->n > 0 || b->eof` rather than from the kernel.
 *
 * That design makes bug 1 almost predictable -- with a zero timeout,
 * select returns before the copy process it has just forked can have
 * run -- and section 3 asks the question a fix turns on: whether a
 * LATER poll sees it. "Never" and "not the first time" want completely
 * different repairs, and the Tcl-level test cannot tell them apart
 * because `update` does not say how many times it polled.
 *
 * Bug 2 is NOT explained by reading that file -- the copy process does
 * `if(n <= 0) b->eof = 1;`, which covers a read error as well as a
 * zero read, and select does count eof as readable. So the code says it
 * should work and the machine says it does not. THAT IS EXACTLY WHEN TO
 * PROBE RATHER THAN REASON: the same position as the announce spelling
 * and the missing loopback, both of which were settled by printing what
 * the machine did and neither of which was going to be settled by
 * reading more code.
 *
 * Section 5 splits bug 2 once more, because a peer that closes after
 * writing and a peer that closes having written nothing reach the copy
 * process differently -- the first has a successful read before the
 * failing one, the second does not.
 *
 * EVERY ASSERTION HERE IS CORRECT ON GLIBC and was checked there. No
 * section can hang: every select carries a two-second timeout, which is
 * the one thing the suite's own version of these cases lacks.
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
#include <time.h>

static int fail = 0;

static void
ok(int cond, const char *what)
{
	if(cond)
		printf("  PASS %s\n", what);
	else {
		printf("  FAIL %s\n", what);
		fail++;
	}
}

static void
note(const char *what)
{
	printf("  note %s\n", what);
}

/*
 * Is fd readable? `ms` < 0 means block (bounded at two seconds anyway,
 * so this file always reports); 0 means poll and return at once.
 * Returns 1 ready, 0 not ready, -1 error.
 */
static int
readable(int fd, int ms)
{
	fd_set rs;
	struct timeval tv;
	int r;

	FD_ZERO(&rs);
	FD_SET(fd, &rs);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	if(ms < 0)
		tv.tv_sec = 2;
	else {
		tv.tv_sec = ms / 1000;
		tv.tv_usec = (ms % 1000) * 1000;
	}
	errno = 0;
	r = select(fd + 1, &rs, NULL, NULL, &tv);
	if(r < 0)
		return -1;
	return r > 0 && FD_ISSET(fd, &rs);
}

/*
 * A loopback pair with the server half already closed, which is what
 * event-11.5 and section 7b of the Tcl test both build. `withdata`
 * decides whether the server writes a line before closing -- the two
 * reach the copy process differently and are asked separately.
 * Returns the client descriptor, or -1.
 */
static int
closedpeer(int withdata)
{
	int srv, cli, acc;
	struct sockaddr_in sa;
	socklen_t len;

	srv = socket(AF_INET, SOCK_STREAM, 0);
	if(srv < 0)
		return -1;
	memset(&sa, 0, sizeof sa);
	sa.sin_family = AF_INET;
	sa.sin_port = 0;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(bind(srv, (struct sockaddr *)&sa, sizeof sa) < 0
	|| listen(srv, 5) < 0){
		close(srv);
		return -1;
	}
	len = sizeof sa;
	if(getsockname(srv, (struct sockaddr *)&sa, &len) < 0){
		close(srv);
		return -1;
	}
	cli = socket(AF_INET, SOCK_STREAM, 0);
	if(cli < 0 || connect(cli, (struct sockaddr *)&sa, sizeof sa) < 0){
		if(cli >= 0)
			close(cli);
		close(srv);
		return -1;
	}
	acc = accept(srv, NULL, NULL);
	close(srv);
	if(acc < 0){
		close(cli);
		return -1;
	}
	if(withdata)
		write(acc, "foobar\n", 7);
	close(acc);			/* THE PEER IS NOW GONE */
	return cli;
}

int
main(void)
{
	int p[2], fd, r, i, polled;

	printf("--- 1. a pipe with data, BLOCKING select (the control) ---\n");
	/*
	 * If this fails nothing below means anything: select cannot
	 * report a descriptor that plainly has bytes waiting on it, and
	 * every other question here is downstream of that.
	 */
	if(pipe(p) < 0) {
		printf("  pipe failed (%s)\n", strerror(errno));
		return 1;
	}
	write(p[1], "hello\n", 6);
	r = readable(p[0], -1);
	ok(r == 1, "a pipe with bytes in it is readable to a blocking select");
	close(p[0]);
	close(p[1]);

	printf("\n--- 2. the same pipe, ZERO-TIMEOUT poll ---\n");
	/*
	 * Tcl's Tcl_DoOneEvent(TCL_DONT_WAIT) -- which is what `update`
	 * and the suite's `testfilehandler oneevent` both are -- reaches
	 * select with a zero timeout. Section 5a of the Tcl test says
	 * this does not work; this says it in C, with no notifier, no
	 * channel layer and no event loop in the way.
	 */
	if(pipe(p) < 0) {
		printf("  pipe failed (%s)\n", strerror(errno));
		return 1;
	}
	write(p[1], "hello\n", 6);
	r = readable(p[0], 0);
	polled = r;
	ok(r == 1, "a pipe with bytes in it is readable to a zero-timeout poll");
	if(r == 0)
		note("this is Tcl's 5a, and every DONT_WAIT poll in every Tcl"
			" program is affected");

	printf("\n--- 3. does a LATER poll see it? ---\n");
	/*
	 * THE QUESTION A FIX TURNS ON, and the one the Tcl test cannot
	 * ask. On Plan 9 select forks a copy process for each descriptor
	 * the first time it is named; with a zero timeout it returns
	 * before that process can have run.
	 *
	 * THE FIRST VERSION OF THIS SECTION OVERCLAIMED AND ITS ANSWER
	 * HAD TO BE THROWN AWAY. It polled ten more times back to back
	 * and printed "NEVER, not merely late" when none of them
	 * reported. Ten zero-timeout selects take MICROSECONDS, and the
	 * polling process never yields, so that measured nothing about
	 * "never" -- a copy process that has only just been forked has
	 * not been scheduled yet either. A check whose negative answer
	 * has a second explanation is not a check.
	 *
	 * So the three cases are asked separately now, and they want
	 * different fixes:
	 *
	 *   3a  ten immediate polls  -- the original, kept for the record
	 *   3b  a poll after SLEEPING a second, so the copy process has
	 *       certainly run
	 *   3c  a poll AFTER A BLOCKING SELECT HAS ALREADY SAID READY on
	 *       this same descriptor. By then b->n > 0 is a fact, the
	 *       copy process demonstrably exists, and the poll reads the
	 *       identical test. IF 3c STILL FAILS, THE COPY PROCESS IS
	 *       NOT THE EXPLANATION AT ALL and no amount of waiting for
	 *       it would help.
	 */
	if(polled == 1)
		note("section 2 already passed, so there is nothing to ask");
	else {
		int firstready = -1;

		for(i = 0; i < 10; i++) {
			r = readable(p[0], 0);
			if(r == 1) {
				firstready = i;
				break;
			}
		}
		if(firstready < 0)
			note("3a. ten more immediate polls: still not ready"
				" (which proves nothing on its own)");
		else
			printf("  note 3a. poll number %d reported it ready\n",
				firstready + 2);

		sleep(1);
		r = readable(p[0], 0);
		ok(r == 1, "3b. a poll one second later is ready");
		if(r == 0)
			note("a whole second is long enough for any copy"
				" process, so lateness is NOT the explanation");

		i = readable(p[0], -1);
		printf("  note 3c. a blocking select says %d\n", i);
		r = readable(p[0], 0);
		ok(r == 1, "3c. a poll straight after a blocking select agrees");
		if(i == 1 && r == 0) {
			note("THE SAME DESCRIPTOR, READY TO A BLOCKING SELECT");
			note("AND NOT TO A POLL. Both read b->n > 0 || b->eof,");
			note("so the difference is in select() itself and not");
			note("in whether the copy process has run.");
		}
	}
	close(p[0]);
	close(p[1]);

	printf("\n--- 4. a socket whose peer WROTE AND CLOSED ---\n");
	/*
	 * event-11.5's second source, and section 7b of the Tcl test.
	 * There are seven bytes waiting AND the connection is finished,
	 * so this is readable twice over on any system.
	 */
	fd = closedpeer(1);
	if(fd < 0)
		note("could not build a loopback pair; run socket-server-test");
	else {
		r = readable(fd, -1);
		ok(r == 1, "a closed peer with data pending is readable");
		if(r == 0)
			note("this is Tcl's 7b, and it is what starves"
				" event-11.5's second source");
		else {
			char buf[32];
			int n = read(fd, buf, sizeof buf);
			printf("  note read after it said ready: %d\n", n);
		}
		close(fd);
	}

	printf("\n--- 5. a socket whose peer closed having written NOTHING ---\n");
	/*
	 * The same thing with the successful read taken away, because the
	 * copy process reaches the two cases differently: with data it
	 * has a good read before the failing one, without data the very
	 * first read is the one that ends the stream. They can fail
	 * separately and a fix for one need not be a fix for the other.
	 */
	fd = closedpeer(0);
	if(fd < 0)
		note("could not build a loopback pair; run socket-server-test");
	else {
		r = readable(fd, -1);
		ok(r == 1, "a closed peer with no data is readable (end of file)");
		if(r == 1) {
			char buf[32];
			int n = read(fd, buf, sizeof buf);
			printf("  note read after it said ready: %d", n);
			if(n < 0)
				printf(" (%s)", strerror(errno));
			printf("\n");
			note("END OF FILE MUST BE READABLE. It is how every");
			note("program learns the other end went away, and a");
			note("read that answers 0 is the POSIX way to say so.");
		}
		close(fd);
	}

	printf("\n--- 6. writable on a plain file (the other control) ---\n");
	/*
	 * Section 7a of the Tcl test passes, so this should too. It is
	 * here so that a run of this file alone still says which half of
	 * event-11.5 is alive -- x climbed to two and a half million,
	 * which is this.
	 */
	{
		char *tmp = "select-test.tmp";
		fd_set ws;
		struct timeval tv;

		fd = open(tmp, O_WRONLY|O_CREAT|O_TRUNC, 0666);
		if(fd < 0)
			note("could not create a temporary file");
		else {
			FD_ZERO(&ws);
			FD_SET(fd, &ws);
			tv.tv_sec = 2;
			tv.tv_usec = 0;
			r = select(fd + 1, NULL, &ws, NULL, &tv);
			ok(r > 0 && FD_ISSET(fd, &ws),
				"a file open for writing is writable");
			close(fd);
			remove(tmp);
		}
	}

	printf("\n--- 7. EOF AFTER THE DATA HAS BEEN DRAINED ---\n");
	/*
	 * SECTION 4 DID NOT ASK THIS AND THE TCL TEST'S 7b DOES. 4 selects
	 * once, finds the connection readable because seven bytes are
	 * waiting, and reads them. 7b then drains the line and asks AGAIN,
	 * and the second answer is the one it wants: with the data gone,
	 * the only thing left to report is the end of file.
	 *
	 * Those are different states of the buffer -- `b->n > 0` for the
	 * first, `b->eof` for the second -- and select tests them with one
	 * `||`, so they can come apart. Reading a section's own passing
	 * result as covering the case after it is the "a pair that looks
	 * like one cause was two" mistake from textDisp-6.5/6.6.
	 */
	fd = closedpeer(1);
	if(fd < 0)
		note("could not build a loopback pair; run socket-server-test");
	else {
		char buf[32];
		int n;

		r = readable(fd, -1);
		if(r != 1)
			note("not readable even with data pending -- that is"
				" section 4, and this section adds nothing");
		else {
			n = read(fd, buf, sizeof buf);
			printf("  note drained %d bytes\n", n);
			r = readable(fd, -1);
			ok(r == 1, "the connection is STILL readable once drained"
				" (the EOF)");
			if(r == 0)
				note("this is Tcl's 7b exactly: data reported,"
					" end of file not");
			else {
				n = read(fd, buf, sizeof buf);
				ok(n == 0, "and the read that follows answers 0");
				if(n != 0)
					printf("  note it answered %d (%s)\n", n,
						n < 0 ? strerror(errno) : "");
			}
		}
		close(fd);
	}

	printf("\n--- 8. event-11.5 IN C: a writable file and a dead socket ---\n");
	/*
	 * THE TCL TEST'S SECTION 8, WITH NOTHING BUT LIBAP IN THE WAY. It
	 * reported x = 2533503 and y = 0 -- the writable source ran two and
	 * a half million times and the socket source never once -- and the
	 * C sections above say each of those descriptors behaves correctly
	 * ON ITS OWN. So the remaining difference is that event-11.5 puts
	 * them in the SAME select, and that is what this asks.
	 *
	 * Two things make the mixed set worth suspecting rather than
	 * assuming, and both are visible in ap/plan9/_buf.c:
	 *
	 *   - the writable count is added to `n` BEFORE the read loop, and
	 *     the function returns as soon as `n` is nonzero, so a select
	 *     carrying any writable descriptor NEVER BLOCKS. It becomes a
	 *     spin, and `mux->selwait` is never set, so the copy process's
	 *     wakeup path is never used either.
	 *   - a descriptor the read loop finds not ready is FD_CLR'd and
	 *     recorded in mux->rwant, which the early return then discards.
	 *
	 * The counters are the verdict, not the pass: `nread` staying at 0
	 * while `nwrite` climbs reproduces the Tcl failure here, and puts
	 * the fault in libap. BOTH CLIMBING EXONERATES libap for this test
	 * and moves the question up to Tcl's notifier -- which would be a
	 * result just as useful, and is the reason to run it either way.
	 * Neither handler reads the socket, exactly as event-11.5's does
	 * not, so a connection once reported stays reported.
	 */
	{
		char *tmp = "select-test.rr";
		fd_set rs, ws;
		struct timeval tv;
		time_t start;
		long nwrite = 0, nread = 0, loops = 0;
		int wfd, sfd;

		sfd = closedpeer(1);
		wfd = open(tmp, O_WRONLY|O_CREAT|O_TRUNC, 0666);
		if(sfd < 0 || wfd < 0)
			note("could not build the pair; run socket-server-test");
		else {
			start = time(0);
			while(time(0) - start < 3 && (nwrite < 3 || nread < 3)) {
				FD_ZERO(&rs);
				FD_ZERO(&ws);
				FD_SET(sfd, &rs);
				FD_SET(wfd, &ws);
				tv.tv_sec = 2;
				tv.tv_usec = 0;
				r = select((sfd > wfd ? sfd : wfd) + 1,
					&rs, &ws, NULL, &tv);
				loops++;
				if(r < 0)
					break;
				if(FD_ISSET(wfd, &ws))
					nwrite++;
				if(FD_ISSET(sfd, &rs))
					nread++;
			}
			printf("  note %ld selects, writable %ld times,"
				" readable %ld times\n", loops, nwrite, nread);
			ok(nread >= 3 && nwrite >= 3,
				"both sources were reported (this is event-11.5)");
			if(nread == 0 && nwrite > 0) {
				note("THE SOCKET WAS NEVER REPORTED while the file");
				note("always was -- event-11.5 reproduced in C, so");
				note("the fault is in select() and not in Tcl.");
			} else if(nread >= 3 && nwrite >= 3) {
				note("libap answers this correctly, so Tcl's x=2533503");
				note("y=0 is NOT this call misbehaving. Look next at");
				note("Tcl's notifier and channel layer, not at _buf.c.");
			}
		}
		if(sfd >= 0)
			close(sfd);
		if(wfd >= 0) {
			close(wfd);
			remove(tmp);
		}
	}

	printf("\n--- 9. a SELECT-DRIVEN accept, then the closed peer ---\n");
	/*
	 * THE LAST STRUCTURAL DIFFERENCE BETWEEN THIS FILE AND THE TCL
	 * TEST, and it is the reason section 9 exists at all. Sections 4,
	 * 5, 7 and 8 all build their loopback pair with a BLOCKING
	 * accept(), so nothing here has ever named a LISTENING descriptor
	 * to select(). Tcl's `socket -server` has no choice but to: its
	 * accept is an event, so the notifier selects on the listener.
	 *
	 * That is not a small difference on Plan 9. ap/network/listen.c
	 * does not leave the socket's own file on the descriptor -- it
	 * REPLACES THE FD WITH A PIPE and forks a listener process, and
	 * its comment says why in so many words: "this is all to make
	 * select work". accept() then reads the new connection's ctl file
	 * name out of that pipe and WRITES "OK" BACK INTO IT, so the fd
	 * carries a two-way handshake.
	 *
	 * Now put select() on it. _startbuf() forks a COPY PROCESS that
	 * sits in _READ() on that same pipe, so a third party is reading
	 * one direction of a handshake between two others. accept()'s own
	 * read goes through _readbuf and so still sees the name, which is
	 * why this can work at all -- and section 3 of the Tcl test, whose
	 * server stays open, does work. Whether it keeps working once the
	 * accepted end is closed straight away is exactly what 7b asks and
	 * what nothing in C has yet reproduced.
	 *
	 * THIS IS A HYPOTHESIS AND IT IS LABELLED AS ONE. The last three
	 * rounds all had a confident mechanism that one printed
	 * intermediate refuted, so what matters here is the measurement:
	 * if this section fails, the fault is in libap after all and the
	 * listener pipe is where to look; if it passes, libap is clear for
	 * every shape event-11.5 uses and the question is Tcl's.
	 */
	{
		int srv, cli, acc, ready;
		struct sockaddr_in sa;
		socklen_t len;
		char buf[32];
		int n;

		srv = socket(AF_INET, SOCK_STREAM, 0);
		memset(&sa, 0, sizeof sa);
		sa.sin_family = AF_INET;
		sa.sin_port = 0;
		sa.sin_addr.s_addr = inet_addr("127.0.0.1");
		if(srv < 0
		|| bind(srv, (struct sockaddr *)&sa, sizeof sa) < 0
		|| listen(srv, 5) < 0)
			note("could not listen; run socket-server-test");
		else {
			len = sizeof sa;
			getsockname(srv, (struct sockaddr *)&sa, &len);
			cli = socket(AF_INET, SOCK_STREAM, 0);
			if(cli < 0
			|| connect(cli, (struct sockaddr *)&sa, sizeof sa) < 0)
				note("could not connect to our own listener");
			else {
				/*
				 * The step Tcl takes and nothing here ever
				 * has: ask select whether the LISTENER is
				 * readable. This is what forks a copy process
				 * onto the pipe listen() put there.
				 */
				ready = readable(srv, -1);
				ok(ready == 1,
					"a listening socket with a pending"
					" connection is readable");
				if(ready != 1)
					note("so a select-driven accept can"
						" never run, which is every"
						" Tcl `socket -server`");

				acc = accept(srv, NULL, NULL);
				ok(acc >= 0, "accept after select returns a"
					" connection");
				if(acc >= 0) {
					write(acc, "foobar\n", 7);
					close(acc);	/* THE PEER GOES */

					ready = readable(cli, -1);
					ok(ready == 1, "the client sees the"
						" data its peer left");
					if(ready == 1) {
						n = read(cli, buf, sizeof buf);
						printf("  note drained %d\n", n);
						ready = readable(cli, -1);
						ok(ready == 1, "and the EOF"
							" after it (this is"
							" 7b end to end)");
						if(ready == 1) {
							n = read(cli, buf,
								sizeof buf);
							ok(n == 0, "the read"
								" answers 0");
						}
					}
				}
				close(cli);
			}
			close(srv);
		}
	}

	printf("\n--- 10. the listener closed with the connection NEVER ACCEPTED ---\n");
	/*
	 * UPSTREAM'S event-11.5, AND THE ONE SHAPE NOTHING HERE HAS
	 * TRIED. Every other section accepts -- blocking in 4, 5 and 7,
	 * through select in 9 -- and all of them pass. Tcl's 7b and 8 do
	 * not accept at all:
	 *
	 *	set s1 [socket -server accept -myaddr 127.0.0.1 0]
	 *	after 1000
	 *	set s2 [socket 127.0.0.1 $port]
	 *	close $s1		<- the accept script never ran
	 *
	 * An accept script only runs inside the event loop and there is
	 * none before that close, so the server side never accepted,
	 * never wrote `foobar` and never closed. The test still expects
	 * `3 3 done`, so it is relying on the CONNECTION ABANDONED IN THE
	 * ACCEPT QUEUE becoming readable when the listener goes -- on X11
	 * the kernel resets it and every read answers at once.
	 *
	 * That is a different question from "is a closed peer readable",
	 * which sections 4, 5 and 7 answer YES to, and it is the only one
	 * left that could explain `y = 0`. Tcl section 7c is its control
	 * on the other side.
	 *
	 * Note what a PASS here would mean: not that the port is fine,
	 * but that libap answers this too and the fault is higher still.
	 */
	{
		int srv, cli;
		struct sockaddr_in sa;
		socklen_t len;
		char buf[32];
		int n;

		srv = socket(AF_INET, SOCK_STREAM, 0);
		memset(&sa, 0, sizeof sa);
		sa.sin_family = AF_INET;
		sa.sin_port = 0;
		sa.sin_addr.s_addr = inet_addr("127.0.0.1");
		if(srv < 0
		|| bind(srv, (struct sockaddr *)&sa, sizeof sa) < 0
		|| listen(srv, 5) < 0)
			note("could not listen; run socket-server-test");
		else {
			len = sizeof sa;
			getsockname(srv, (struct sockaddr *)&sa, &len);
			cli = socket(AF_INET, SOCK_STREAM, 0);
			if(cli < 0
			|| connect(cli, (struct sockaddr *)&sa, sizeof sa) < 0)
				note("could not connect to our own listener");
			else {
				close(srv);	/* NEVER ACCEPTED */
				r = readable(cli, -1);
				ok(r == 1, "a connection abandoned in the accept"
					" queue becomes readable");
				if(r == 1) {
					errno = 0;
					n = read(cli, buf, sizeof buf);
					printf("  note read answered %d", n);
					if(n < 0)
						printf(" (%s)", strerror(errno));
					printf("\n");
				} else {
					note("THIS IS event-11.5's y = 0, in C.");
					note("upstream closes the listener without");
					note("ever accepting, so the client is left");
					note("on a connection nothing will answer.");
				}
				close(cli);
			}
		}
	}

	printf("\n--- 11. A DESCRIPTOR ABOVE FD_SETSIZE ---\n");
	/*
	 * THE SYSTEM HANDS OUT DESCRIPTORS select() CANNOT BE ASKED
	 * ABOUT, and it answers "nothing is ready" rather than saying so.
	 *
	 * <sys/select.h> here is
	 *
	 *	typedef struct fd_set { long fds_bits[3]; } fd_set;
	 *	#define FD_SETSIZE 96
	 *
	 * -- the struct is a hardcoded three words whatever FD_SETSIZE
	 * says -- while <sys/limits.h> sets OPEN_MAX to 256 and _fdinfo[]
	 * is that long. So descriptors 96..255 are ordinary, usable
	 * descriptors that no fd_set in the system can represent.
	 *
	 * Three separate things go wrong once a program reaches one, and
	 * only the first is tested here, because the other two corrupt
	 * memory and a test that provokes them cannot report afterwards:
	 *
	 *   - FD_ANYSET in _buf.c reads words 0..2 only, so a select
	 *     naming ONLY high descriptors takes the "no requested fds"
	 *     arm: it sleeps out the timeout and returns 0. A notifier
	 *     waiting on such a descriptor waits for ever, with no error
	 *     anywhere. That is the shape of a Tcl vwait that never
	 *     returns.
	 *   - a MIXED set does reach the scan, and then
	 *     FD_SET(fd, &mux->rwant) writes past the end of a three-word
	 *     fd_set living INSIDE THE SHARED SEGMENT -- rwant is
	 *     followed by ewant and then bufs[], so it lands on another
	 *     descriptor's buffer state.
	 *   - Muxbuf.fd is a `char` (include/lib.h), so a descriptor is
	 *     truncated to eight signed bits on the way into the slot:
	 *     128 and up read back negative, and 255 reads back as -1,
	 *     which is this file's marker for a FREE SLOT.
	 *
	 * Nothing here says this is what hangs chan-io-44.1. It is a
	 * latent bug found by reading, and what this section measures is
	 * only whether the call answers a high descriptor at all.
	 *
	 * The set below is padded deliberately: FD_SET on a plain fd_set
	 * would smash this program's own stack, which is exactly what any
	 * caller with FD_SETSIZE > 96 in scope already does -- Tcl's
	 * tclUnixPort.h says `#define FD_SETSIZE OPEN_MAX` and then
	 * believes it.
	 */
	{
		union { fd_set s; long pad[64]; } u;
		struct timeval tv;
		int hifd, n;
		char c;

		unsigned char *raw;
		size_t k;
		int dirty;

		printf("  note FD_SETSIZE %d, fd_set holds %d, OPEN_MAX %ld\n",
			(int)FD_SETSIZE, (int)(sizeof(fd_set) * 8),
			(long)sysconf(_SC_OPEN_MAX));

		/*
		 * WHICH HEADER SUPPLIED fd_set, and it is not a
		 * rhetorical question: the first VM run reported
		 * `FD_SETSIZE 96, fd_set holds 128`, which no file in
		 * this tree can produce -- all three copies here are
		 * `long fds_bits[3]` and `long` is 32 bits on amd64, so
		 * 96. The width came from somewhere else.
		 *
		 * THE ANSWER WAS NOT WHAT THIS COMMENT FIRST GUESSED. It
		 * said stock APE's copy in the architecture directory
		 * had won the search; the marker below reported `fd_set
		 * came from THIS TREE`, so it had not. The 128 is
		 * KENCC'S PADDING: it rounds `long fds_bits[3]` -- 12
		 * bytes -- up to an eight-byte multiple, leaving a
		 * fourth word that FD_SETSIZE denied, FD_SET could write
		 * into and FD_ZERO never cleared.
		 *
		 * _APEXP_FD_SET_T is defined beside the typedef in all
		 * three of this tree's copies, so it answers the
		 * question outright rather than by arithmetic --
		 * limits-test.c's technique for float/stdarg/stdint.
		 */
#ifdef _APEXP_FD_SET_T
		note("fd_set came from THIS TREE");
#else
		note("fd_set did NOT come from this tree (no"
			" _APEXP_FD_SET_T)");
		note("-- expected on glibc; on Plan 9 it would mean");
		note("stock APE's copy in the architecture directory"
			" won.");
#endif
		if((long)sysconf(_SC_OPEN_MAX) > (long)FD_SETSIZE)
			note("the system gives out descriptors no fd_set can name");
		ok((int)(sizeof(fd_set) * 8) >= (int)FD_SETSIZE,
			"fd_set is as wide as FD_SETSIZE claims");

		/*
		 * FD_ZERO MUST CLEAR THE WHOLE STRUCT, and with the
		 * width coming from one header and the macros possibly
		 * from another it is exactly what can come apart: this
		 * tree's FD_ZERO is three assignments by name, so on a
		 * four-word struct it leaves the last word holding
		 * whatever the stack held. A select would then act on
		 * descriptors nobody asked about, which is not a
		 * missed event but an invented one.
		 *
		 * Filled with 0xff first, so a zeroed word cannot pass
		 * by luck.
		 */
		memset(&u, 0xff, sizeof u);
		FD_ZERO(&u.s);
		raw = (unsigned char *)&u.s;
		dirty = 0;
		for(k = 0; k < sizeof(fd_set); k++)
			if(raw[k] != 0)
				dirty = 1;
		ok(!dirty, "FD_ZERO clears every byte of an fd_set");
		if(dirty)
			note("so the macros and the struct are from different"
				" headers");

		/*
		 * A HIGH DESCRIPTOR, REACHED THE WAY THE MACHINE ALLOWS.
		 * The first attempt used dup2 to FD_SETSIZE+4 and the VM
		 * answered `could not dup a descriptor up that high`,
		 * while Tcl's own ramp held 104 descriptors without
		 * complaint -- so it is dup2 to a specific high number
		 * that is refused, not high numbers themselves. Opening
		 * the same file until the numbers climb is what works,
		 * and it is also what a real program does.
		 */
		if(pipe(p) < 0)
			note("pipe failed");
		else {
			int held[300], nheld, want, hifd;

			want = (int)(sizeof(fd_set) * 8) + 8;
			if(want > 256)
				want = 256;
			for(nheld = 0; nheld < 300; nheld++){
				held[nheld] = dup(p[0]);
				if(held[nheld] < 0)
					break;
				if(held[nheld] >= want)
					break;
			}
			hifd = (nheld < 300 && held[nheld] >= 0)
				? held[nheld] : -1;
			printf("  note highest descriptor reached: %d"
				" (wanted %d)\n",
				hifd >= 0 ? hifd : (nheld > 0 ? held[nheld-1] : -1),
				want);
			if(hifd < 0)
				note("could not climb that high; nothing to ask");
			else {
				write(p[1], "x", 1);
				memset(&u, 0, sizeof u);
				FD_SET(hifd, &u.s);
				tv.tv_sec = 2;
				tv.tv_usec = 0;
				n = select(hifd + 1, &u.s, 0, 0, &tv);
				ok(n == 1, "a high descriptor with data is"
					" reported readable");
				if(n != 1) {
					printf("  note select answered %d", n);
					if(n < 0)
						printf(" (%s)", strerror(errno));
					printf("\n");
					note("so a program that reaches this");
					note("descriptor number waits for ever");
					note("and is told nothing.");
				}
			}
			while(--nheld >= 0)
				if(held[nheld] >= 0)
					close(held[nheld]);
			close(p[0]);
			close(p[1]);
		}
	}

	printf("\n%d failure(s)\n", fail);
	return fail;
}
