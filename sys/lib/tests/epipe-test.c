/*
 * epipe-test.c -- writing to a pipe nobody is reading.
 *
 * WHERE THIS CAME FROM. Tcl's chan-io-29.27 and io-29.27 run a child
 * that exits at once, write to it, and require exactly this:
 *
 *	1 {error flushing "*": broken pipe} {posix epipe {broken pipe}}
 *
 * Tcl spells the middle word from errno, so an errno that is not EPIPE
 * fails the comparison however sensible it is. libap's _errno.c mapped
 * Plan 9's "i/o on hungup channel" and "write to hungup stream" to
 * ESHUTDOWN, which is a BSD name for a SOCKET whose transport has been
 * shut down. POSIX has one answer for both cases -- a write with no
 * reader left is EPIPE, on a pipe and on a socket alike, and Linux
 * gives EPIPE after shutdown(SHUT_WR) too.
 *
 * SIGPIPE IS PART OF THE CONTRACT AND IS WHY SECTION 0 EXISTS. The
 * default action kills the writer, so a test that did not disarm it
 * would die instead of reporting. Plan 9 raises this as the note
 * "sys: write on closed pipe", which signal/signal.c already maps to
 * SIGPIPE; if that mapping broke, section 0 is where it shows.
 *
 * SECTION 2 IS THE CONTROL. A pipe that still has a reader must take
 * the write normally -- otherwise section 1 could be passing because
 * every write had started failing.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>

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

int
main(void)
{
	int p[2], sv[2], n;
	char buf[64];

	printf("--- 0. SIGPIPE can be disarmed, or nothing below reports ---\n");
	ok("signal(SIGPIPE, SIG_IGN) was accepted",
		signal(SIGPIPE, SIG_IGN) != SIG_ERR);

	printf("--- 1. a write with no reader left is EPIPE ---\n");
	if(pipe(p) < 0){
		why("pipe");
		ok("section 1 could not make a pipe", 0);
	} else {
		close(p[0]);
		errno = 0;
		n = write(p[1], "x", 1);
		if(n < 0)
			why("write to a pipe whose read end is closed");
		else
			printf("  note write returned %d\n", n);
		ok("it failed", n < 0);
		ok("...and the errno is EPIPE", n < 0 && errno == EPIPE);
		close(p[1]);
	}

	printf("--- 2. THE CONTROL: a pipe with a reader still works ---\n");
	/*
	 * Without this, "every write fails" would look exactly like a fix.
	 */
	if(pipe(p) < 0){
		why("pipe");
		ok("section 2 could not make a pipe", 0);
	} else {
		errno = 0;
		n = write(p[1], "hello", 5);
		if(n != 5)
			why("write to a pipe that has a reader");
		ok("a write to a live pipe is not refused", n == 5);
		n = read(p[0], buf, sizeof buf);
		ok("...and the bytes come back", n == 5 &&
			memcmp(buf, "hello", 5) == 0);
		close(p[0]);
		close(p[1]);
	}

	printf("--- 3. the same for a socket whose peer is gone ---\n");
	/*
	 * POSIX gives one answer for both, and libap reached both through
	 * the same two table entries -- so measuring only the pipe would
	 * leave half the change unobserved.
	 */
	if(socketpair(AF_UNIX, SOCK_STREAM, 0, sv) < 0){
		why("socketpair");
		printf("  note no socketpair here; section 3 says nothing\n");
	} else {
		close(sv[0]);
		errno = 0;
		n = write(sv[1], "x", 1);
		if(n < 0)
			why("write to a socket whose peer is closed");
		else
			printf("  note write returned %d\n", n);
		/*
		 * A stream socket may take the first write into its own
		 * buffer and only fail on the second, so a success here is
		 * not a failure of the test -- only a wrong errno is.
		 */
		if(n < 0)
			ok("the errno is EPIPE, not ESHUTDOWN",
				errno == EPIPE);
		else {
			errno = 0;
			n = write(sv[1], "x", 1);
			if(n < 0)
				why("second write");
			ok("the errno is EPIPE, not ESHUTDOWN",
				n < 0 && errno == EPIPE);
		}
		close(sv[1]);
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
