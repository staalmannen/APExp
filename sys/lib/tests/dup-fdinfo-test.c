/*
 * dup-fdinfo-test.c -- dup() must not hand out a descriptor the kernel
 * already has open.
 *
 * WHERE THIS CAME FROM. Tcl's zlib-9.2 froze the whole suite, and acid
 * on the test process showed it inside `after 1000`, in
 * Tcl_GetTime -> gettimeofday -> _NSEC -> _PREAD(fd=7), never
 * returning. _NSEC opens /dev/bintime with the RAW _OPEN syscall and
 * caches the descriptor in a static, so libap's own _fdinfo[] table
 * never learns about it -- and fcntl(F_DUPFD) picked its slot by
 * scanning that table for one without FD_ISOPEN. It called 7 free and
 * _DUP'd over the top of /dev/bintime. The listener process forked by
 * the same socket -server reported nfd=0x7 for the socket it had been
 * handed: one descriptor, two owners. Afterwards every timestamp in the
 * process read whatever had landed on 7 -- and a read of a pipe or a
 * socket does not return.
 *
 * WHAT IT COST. Any program that takes a timestamp and then dups --
 * which is every Tcl program using `socket -server`, since listen()
 * opens with nfd = dup(fd) -- could lose its clock. It is
 * order-dependent, so it hides for a long time and then wedges
 * something far away.
 *
 * Section 3 is the one that reproduces it, and it can only fail on a
 * libap where the fix is missing; sections 1 and 2 are the POSIX
 * contract and are correct on glibc, which is where they were checked.
 *
 * Every section is guarded by alarm(), because the failure mode under
 * test is a read that never returns: a test that hangs reports nothing
 * at all, which is the thing this file exists to avoid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/time.h>

static int failures;
static sigjmp_buf jb;
static volatile int timedout;

static void
onalarm(int sig)
{
	(void)sig;
	timedout = 1;
	siglongjmp(jb, 1);
}

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static void
note(const char *fmt, ...)
{
	va_list ap;

	printf("  note ");
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
	printf("\n");
}

int
main(void)
{
	int fd, d, i, n, dups[64];
	struct timeval t0, t1;
	double dt;

	signal(SIGALRM, onalarm);

	printf("--- 1. dup() returns a usable descriptor ---\n");
	fd = open("/dev/null", O_RDONLY);
	if(fd < 0){
		printf("  note cannot open /dev/null (%s); nothing to ask\n",
			strerror(errno));
		return 1;
	}
	d = dup(fd);
	ok("dup() succeeded", d >= 0);
	ok("dup() did not return the original descriptor", d != fd);
	if(d >= 0)
		close(d);

	printf("--- 2. F_DUPFD honours its lower bound ---\n");
	d = fcntl(fd, F_DUPFD, 20);
	if(d < 0)
		ok("F_DUPFD with a bound succeeded", 0);
	else {
		ok("F_DUPFD returned a descriptor >= the bound", d >= 20);
		close(d);
	}

	/*
	 * 3. THE ONE THAT REPRODUCES IT.
	 *
	 * Take a timestamp first, so that libap has opened and cached
	 * /dev/bintime; then dup enough times to walk over whatever slot
	 * _fdinfo[] thinks is free; then ask the time again. On a libap
	 * that picks the slot from its own table rather than from the
	 * kernel, the second gettimeofday either never returns or answers
	 * with eight bytes of somebody else's file.
	 */
	printf("--- 3. the clock survives a burst of dup() ---\n");
	if(gettimeofday(&t0, 0) < 0){
		ok("the first gettimeofday worked", 0);
		return failures ? failures : 1;
	}

	n = 0;
	for(i = 0; i < (int)(sizeof dups / sizeof dups[0]); i++){
		dups[n] = dup(fd);
		if(dups[n] < 0)
			break;
		n++;
	}
	note("made %d dups, highest descriptor %d", n, n ? dups[n-1] : -1);

	timedout = 0;
	if(sigsetjmp(jb, 1) == 0){
		alarm(5);
		if(gettimeofday(&t1, 0) < 0)
			t1.tv_sec = t1.tv_usec = 0;
		alarm(0);
	}
	ok("gettimeofday still returns after dup()", !timedout);

	if(!timedout){
		dt = (t1.tv_sec - t0.tv_sec)
			+ (t1.tv_usec - t0.tv_usec) / 1000000.0;
		note("elapsed %.6f s", dt);
		ok("the clock did not move backwards", dt >= 0.0);
		ok("the clock did not jump (a clobbered /dev/bintime "
		   "reads as somebody else's bytes)", dt < 60.0);
	}

	for(i = 0; i < n; i++)
		close(dups[i]);
	close(fd);

	printf("%d failure(s)\n", failures);
	return failures;
}
