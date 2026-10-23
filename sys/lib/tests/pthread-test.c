/*
 * pthread-test.c -- does a created thread ever RUN, and does
 * pthread_cond_timedwait ever WAIT?
 *
 * WHERE THIS CAME FROM.  `xz -c <sample.txt >/tmp/t.xz' on a file
 * holding the word `sample' took the machine to high load and never
 * returned.  Two rounds were spent on poll(), select() and O_NONBLOCK,
 * because xz does use all three -- and every one of them was the wrong
 * street.  `ps' and two `acid' stacks named it in one run:
 *
 *	79207  Rendez  0:00 0:00
 *	    _RENDEZVOUS <- pthread_create+0x63 <- mythread_create
 *	                <- initialize_new_thread <- get_thread <- main
 *
 *	79206  Ready   0:18 0:34        <- the SYSTEM figure, pinned
 *	    _PREAD <- _NSEC <- nsec <- clock_gettime
 *	           <- pthread_cond_timedwait+0x40 <- wait_for_work <- main
 *
 * **xz is MULTITHREADED** (`liblzma/common/stream_encoder_mt.c'), and
 * libap's pthread layer had three bugs that between them account for
 * both processes exactly:
 *
 *   1. The child half of `pthread_create' did `_RENDEZVOUS(tag, 0)'
 *      and **the parent never answered it** -- that one call was the
 *      only `_RENDEZVOUS' in the whole thread directory.  So every
 *      thread ever created blocked before reaching its start routine,
 *      while its creator was told the call had succeeded.
 *   2. `*t' was never written, so every caller handed rubbish to
 *      `pthread_join'.
 *   3. `pthread_create' returned EINVAL for any non-null `attr', and
 *      **libap's own `pthread_cond_timedwait' always passes one** --
 *      so it returned EAGAIN without waiting, every time, and a caller
 *      that loops on it spins through `clock_gettime'.  On Plan 9 that
 *      is a `_PREAD', which is why the system figure was pinned and
 *      the user figure was not.
 *
 * ***THE TWO FAILURES LOOK LIKE ONE HANG AND ARE TWO BUGS***, which is
 * why sections 0-2 and sections 3-4 are separate: fixing the spin
 * without fixing the handshake gives a program that waits patiently
 * for work nobody will do, and fixing the handshake without the spin
 * gives one that does the work at 100% of a core.
 *
 * **THIS FILE CAN HANG, SO IT ARMS AN ALARM.**  A frozen test and a
 * failing one look identical from the prompt -- that is this tree's own
 * rule -- so `SIGALRM' turns a hang into a named failure: the handler
 * prints which section was running and exits 99.  Every section flushes
 * a marker BEFORE the call it is about to make, in file order, so the
 * last line printed names the statement that did not return.
 *
 * Build:
 *   gcc -o pthread-test pthread-test.c -lpthread && ./pthread-test  # 0
 *   pcc -o pthread-test pthread-test.c && ./pthread-test            # 9front
 *
 * Exit status is the failure count, or 99 for a timeout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

/*
 * Version marker.  `pcc -o x x.c' relinks against the INSTALLED libap,
 * so a test built from a fresh pull can measure days-old library code.
 * This will not LINK against a libap predating the pthread_create fix.
 * Tenth use of the idiom.
 */
#ifndef __linux__
extern int _pthreadmark(void);
#endif

static int fails;
static int section = -1;
static const char *doing = "nothing yet";

static void
eq(const char *what, long got, long want)
{
	if (got == want)
		printf("PASS %-46s %ld\n", what, got);
	else {
		printf("FAIL %-46s %ld   want %ld\n", what, got, want);
		fails++;
	}
}

static void
mark(const char *what)
{
	doing = what;
	printf("     about to: %s\n", what);
	fflush(stdout);
}

static void
onalarm(int sig)
{
	(void)sig;
	printf("\n*** TIMED OUT in section %d, at: %s\n", section, doing);
	printf("*** A hang here is the result, not a harness fault.\n");
	fflush(stdout);
	_exit(99);
}

/* ---- section 0/1: does a thread run at all? ---- */

static volatile int ran;
static pthread_t self_seen;

static void *
setflag(void *arg)
{
	ran = *(int *)arg;
	self_seen = pthread_self();
	return (void *)0x5a5a;
}

/* ---- section 2: with a non-null attr ---- */

static volatile int ran2;

static void *
setflag2(void *arg)
{
	(void)arg;
	ran2 = 1;
	return NULL;
}

static long long
nowms(void)
{
	struct timespec ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	return (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

int
main(void)
{
	pthread_t t;
	pthread_attr_t attr;
	pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t c = PTHREAD_COND_INITIALIZER;
	struct timespec ts;
	void *ret;
	int r, want, i;
	long long t0, t1;

	setvbuf(stdout, NULL, _IOLBF, 0);
	signal(SIGALRM, onalarm);

	printf("pthread-test: does a created thread RUN, and does\n");
	printf("pthread_cond_timedwait WAIT?  Both questions came from one\n");
	printf("hang (xz), and they are two bugs.\n\n");

#ifndef __linux__
	printf("_pthreadmark = %d\n\n", _pthreadmark());
#endif

	/* ---- section 0: CONTROL ---- */
	section = 0;
	printf("Section 0: CONTROL -- a thread must reach its start routine\n");
	printf("     (if this fails nothing below means anything: it is the\n");
	printf("      bare claim that pthread_create creates a thread.)\n");
	alarm(20);
	ran = 0;
	want = 0x1234;
	t = (pthread_t)-1;
	mark("pthread_create(&t, NULL, setflag, &want)");
	r = pthread_create(&t, NULL, setflag, &want);
	eq("pthread_create returns 0", r, 0);
	if (r != 0) {
		printf("     cannot continue past the control -- stopping\n");
		printf("\n%d failures\n", fails);
		return fails ? fails : 1;
	}
	mark("pthread_join(t, &ret)");
	ret = NULL;
	r = pthread_join(t, &ret);
	alarm(0);
	eq("pthread_join returns 0", r, 0);
	eq("the start routine RAN", ran, want);
	eq("and its return value came back", (long)(size_t)ret, 0x5a5a);

	/* ---- section 1: the out parameter ---- */
	section = 1;
	printf("\nSection 1: pthread_create writes *t\n");
	printf("     (it was simply unused; every caller handed whatever was\n");
	printf("      on its stack to pthread_join.  The thread reports its\n");
	printf("      own pthread_self() so the two can be compared.)\n");
	eq("*t was written", t != (pthread_t)-1, 1);
	eq("*t equals the thread's own pthread_self()",
	    pthread_equal(t, self_seen) != 0, 1);

	/* ---- section 2: a non-null attr ---- */
	section = 2;
	printf("\nSection 2: pthread_create ACCEPTS a non-null attr\n");
	printf("     (libap's own pthread_cond_timedwait passes one, so a\n");
	printf("      rejection here is libap refusing libap.  Every\n");
	printf("      attribute is a no-op; accepting the struct says only\n");
	printf("      that, and detachstate is NOT honoured.)\n");
	alarm(20);
	ran2 = 0;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	mark("pthread_create(&t, &attr, setflag2, NULL)");
	r = pthread_create(&t, &attr, setflag2, NULL);
	eq("pthread_create with an attr returns 0", r, 0);
	if (r == 0) {
		mark("pthread_join after the attr create");
		pthread_join(t, NULL);
		eq("that thread ran too", ran2, 1);
	}
	pthread_attr_destroy(&attr);
	alarm(0);

	/* ---- section 3: timedwait must actually WAIT ---- */
	section = 3;
	printf("\nSection 3: pthread_cond_timedwait WAITS, then ETIMEDOUT\n");
	printf("     (nobody ever signals this cond, so the only correct\n");
	printf("      outcome is ETIMEDOUT after about 300ms.  EAGAIN or\n");
	printf("      EINVAL here is the bug that pinned the system load:\n");
	printf("      an instant return turns xz's wait_for_work loop into\n");
	printf("      a busy-wait made of clock_gettime syscalls.)\n");
	alarm(20);
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_nsec += 300000000L;
	if (ts.tv_nsec >= 1000000000L) {
		ts.tv_nsec -= 1000000000L;
		ts.tv_sec++;
	}
	pthread_mutex_lock(&m);
	t0 = nowms();
	mark("pthread_cond_timedwait(&c, &m, now + 300ms)");
	r = pthread_cond_timedwait(&c, &m, &ts);
	t1 = nowms();
	pthread_mutex_unlock(&m);
	alarm(0);
	printf("     returned %d (%s) after %lld ms\n",
	    r, r == 0 ? "0" : strerror(r), t1 - t0);
	eq("timedwait returns ETIMEDOUT", r, ETIMEDOUT);
	eq("and it actually waited (>= 250ms)", (t1 - t0) >= 250, 1);

	/* ---- section 4: the spin shape, as xz makes it ---- */
	section = 4;
	printf("\nSection 4: the SPIN SHAPE -- xz's wait_for_work, reduced\n");
	printf("     (ten 100ms waits in a loop must take about a second.\n");
	printf("      With timedwait returning instantly they take no time\n");
	printf("      at all, and the loop that contains them is what makes\n");
	printf("      a core's system figure sit at the maximum.  This is\n");
	printf("      the arithmetic the reader would do, done here.)\n");
	alarm(30);
	t0 = nowms();
	pthread_mutex_lock(&m);
	for (i = 0; i < 10; i++) {
		clock_gettime(CLOCK_REALTIME, &ts);
		ts.tv_nsec += 100000000L;
		if (ts.tv_nsec >= 1000000000L) {
			ts.tv_nsec -= 1000000000L;
			ts.tv_sec++;
		}
		mark("one of ten 100ms timedwaits");
		pthread_cond_timedwait(&c, &m, &ts);
	}
	pthread_mutex_unlock(&m);
	t1 = nowms();
	alarm(0);
	printf("     ten 100ms waits took %lld ms\n", t1 - t0);
	eq("ten 100ms waits take at least 800ms", (t1 - t0) >= 800, 1);

	printf("\n%d failures\n", fails);
	return fails;
}
