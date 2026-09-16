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
	 * before that process can have run. If polls 2..10 report ready,
	 * the answer is "not the first time" and a fix is about making
	 * the first call wait for the copy process to be started. If none
	 * of them ever does, it is "never" and the fault is elsewhere.
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
			note("ten more polls, still not ready: NEVER, not"
				" merely late");
		else {
			printf("  note poll number %d reported it ready\n",
				firstready + 2);
			note("so the data arrives and only the FIRST poll"
				" misses it");
		}
		ok(firstready >= 0 || readable(p[0], -1) != 1,
			"a poll eventually agrees with a blocking select");
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

	printf("\n%d failure(s)\n", fail);
	return fail;
}
