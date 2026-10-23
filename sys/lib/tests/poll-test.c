/*
 * poll-test.c -- does poll() obey the three POSIX rules whose absence
 * can make a caller SPIN rather than merely get an odd answer?
 *
 * WHERE THIS CAME FROM.  `xz -c <sample.txt >/tmp/t.xz' on a file
 * holding the word `sample' took the machine to high load and never
 * returned.  A seven-byte input cannot be a corrupt archive, so the
 * downloaded-sample explanation died there and the fault is ours.
 *
 * `xz/file_io.c's io_wait() is, in full:
 *
 *	while (true) {
 *		const int ret = poll(pfd, 2, timeout);
 *		if (user_abort)       return IO_WAIT_ERROR;
 *		if (ret == -1)        { if EINTR/EAGAIN continue; ... }
 *		if (ret == 0)         return IO_WAIT_TIMEOUT;
 *		if (pfd[0].revents)   return IO_WAIT_MORE;
 *	}
 *
 * **There is nothing in the fall-through path -- no sleep, no
 * progress.**  So any poll() that returns a POSITIVE number without
 * setting `pfd[0].revents' turns that loop into a busy-wait, which is
 * exactly `high load and frozen'.  libap's poll() could do it two ways,
 * and both are fixed:
 *
 *   1. IT RETURNED select()'s VALUE, which counts BITS ACROSS THREE
 *      fd_sets.  POSIX wants the number of pollfd STRUCTURES with
 *      nonzero revents.  One descriptor ready for both reading and
 *      writing counted twice, so the number could exceed the number of
 *      entries actually marked.
 *   2. IT SKIPPED A NEGATIVE fd WHEN BUILDING THE SETS AND NOT WHEN
 *      READING THEM -- `FD_ISSET(-1, &rfds)', out of bounds, and
 *      whatever that found became a revents the caller believed.  xz
 *      passes `user_abort_pipe[0]' as pfd[1], which is -1 whenever that
 *      pipe was not created.
 *   3. And POLLNVAL did not exist: one closed descriptor failed the
 *      WHOLE call with EBADF instead of marking that one entry.
 *
 * ***THIS TEST DOES NOT CLAIM TO BE xz's BUG.***  It asserts the three
 * rules, which are wrong independently of what xz does with them.
 * Whether xz stops hanging is a separate measurement and the only one
 * that settles it -- and `lz4' hangs too while using NEITHER poll nor
 * select nor O_NONBLOCK, so there are at least two faults here and this
 * is at most one of them.
 *
 * THE OLD CODE REPLICATED BESIDE THIS ONE REPORTS 4, and section 1 is
 * the one that matters: `poll returns 1, not 2' answers **2** -- a
 * positive return with a single entry marked, which is precisely the
 * arithmetic io_wait() cannot survive.  *Defect 2 is NOT in that count
 * and cannot be*: `FD_ISSET(-1, ...)' is undefined behaviour, so
 * replicating it on the host risks a crash rather than a failure, and
 * the transcription guards it.  Section 2 therefore asserts the rule
 * without the control being able to prove it fires.
 *
 * SECTION 0 IS THE CONTROL: an ordinary ready descriptor, one entry,
 * one event.  Every implementation gets that right, so if it fails the
 * fault is in the harness and nothing below means anything.
 *
 * Build:
 *   gcc -o poll-test poll-test.c && ./poll-test      # host, 0
 *   pcc -o poll-test poll-test.c && ./poll-test      # 9front
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>

static int fails;

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

int
main(void)
{
	struct pollfd pfd[3];
	int p[2], n, bad;
	char nm[] = "/tmp/polltestXXXXXX";
	int rf;

	printf("poll-test: the three POSIX rules whose absence can make a\n");
	printf("caller SPIN -- the count is of ENTRIES, a negative fd is\n");
	printf("ignored, and a closed one is POLLNVAL on that entry alone.\n\n");

	if (pipe(p) < 0) {
		printf("FAIL could not make a pipe\n");
		return 1;
	}
	write(p[1], "x", 1);

	/* ---- section 0: CONTROL ---- */
	printf("Section 0: CONTROL -- one ready entry, one event\n");
	pfd[0].fd = p[0];
	pfd[0].events = POLLIN;
	pfd[0].revents = 0;
	n = poll(pfd, 1, 1000);
	eq("poll returns 1", n, 1);
	eq("revents has POLLIN", (pfd[0].revents & POLLIN) != 0, 1);

	/* ---- section 1: the count is of ENTRIES, not of bits ---- */
	printf("\nSection 1: ONE fd ready for BOTH reading and writing\n");
	printf("     (a regular file opened read-write is both, so an\n");
	printf("      implementation counting fd_set BITS reports 2 for\n");
	printf("      one entry -- which is the arithmetic that makes a\n");
	printf("      `while(ret>0 && !pfd[0].revents)' loop never sleep.\n");
	printf("      A PIPE will not do here: its read end is readable\n");
	printf("      and not writable, so the defect is unreachable and\n");
	printf("      the check cannot fail.)\n");
	strcpy(nm, "/tmp/polltestXXXXXX");
	rf = mkstemp(nm);
	if (rf < 0)
		printf("     could not make a temporary file -- SKIPPED\n");
	else {
		write(rf, "hello", 5);
		lseek(rf, 0, SEEK_SET);
		pfd[0].fd = rf;
		pfd[0].events = POLLIN | POLLOUT;
		pfd[0].revents = 0;
		n = poll(pfd, 1, 1000);
		/*
		 * Print the bits before asserting on them. Deducing WHICH
		 * one was missing from a bare `0 want 1' cost a round
		 * trip to the other machine once; a failure should name
		 * itself.
		 */
		printf("     revents: POLLIN %d  POLLOUT %d   poll -> %d\n",
		    (pfd[0].revents & POLLIN) != 0,
		    (pfd[0].revents & POLLOUT) != 0, n);
		eq("POLLIN reported on a regular file",
		    (pfd[0].revents & POLLIN) != 0, 1);
		eq("POLLOUT reported on a regular file",
		    (pfd[0].revents & POLLOUT) != 0, 1);
		eq("poll returns 1, not 2", n, 1);
		close(rf);
		unlink(nm);
	}

	/* ---- section 2: a negative fd is IGNORED ---- */
	printf("\nSection 2: a negative fd is ignored, revents 0\n");
	printf("     (this is xz's pfd[1] when its abort pipe is absent)\n");
	pfd[0].fd = -1;
	pfd[0].events = POLLIN;
	pfd[0].revents = 0xff;
	pfd[1].fd = p[0];
	pfd[1].events = POLLIN;
	pfd[1].revents = 0;
	n = poll(pfd, 2, 1000);
	eq("negative entry has revents 0", pfd[0].revents, 0);
	eq("the real entry is reported", (pfd[1].revents & POLLIN) != 0, 1);
	eq("count is 1, not 2", n, 1);

	/*
	 * And the shape that spins: a positive return with the entry the
	 * caller watches unmarked. With only a negative fd beside a ready
	 * one that cannot happen -- but an implementation that counted
	 * the negative entry would report 2 here while marking one, which
	 * is the arithmetic io_wait() cannot survive.
	 */
	eq("entries marked == value returned",
	    ((pfd[0].revents != 0) + (pfd[1].revents != 0)), n);

	/* ---- section 3: all-negative plus a timeout ---- */
	printf("\nSection 3: every fd negative -- a timeout, not an error\n");
	pfd[0].fd = -1;
	pfd[0].events = POLLIN;
	pfd[0].revents = 0xff;
	n = poll(pfd, 1, 10);
	eq("poll returns 0", n, 0);
	eq("revents cleared", pfd[0].revents, 0);

	/* ---- section 4: a closed fd is POLLNVAL on THAT entry ---- */
	printf("\nSection 4: a closed fd marks its own entry, not the call\n");
	strcpy(nm, "/tmp/polltestXXXXXX");
	rf = mkstemp(nm);
	if (rf < 0) {
		printf("     could not make a temporary file -- SKIPPED\n");
	} else {
		bad = dup(rf);
		close(bad);		/* now a closed descriptor number */
		pfd[0].fd = bad;
		pfd[0].events = POLLIN;
		pfd[0].revents = 0;
		pfd[1].fd = p[0];
		pfd[1].events = POLLIN;
		pfd[1].revents = 0;
		n = poll(pfd, 2, 1000);
		eq("the call does not fail", n >= 0, 1);
		eq("closed entry is POLLNVAL",
		    (pfd[0].revents & POLLNVAL) != 0, 1);
		eq("the GOOD entry is still answered",
		    (pfd[1].revents & POLLIN) != 0, 1);
		close(rf);
		unlink(nm);
	}

	/* ---- section 5: a regular file is always ready ---- */
	printf("\nSection 5: a regular file is always ready (POSIX)\n");
	printf("     (xz sets O_NONBLOCK on a redirected stdin and then\n");
	printf("      polls it, so this is the question it asks)\n");
	strcpy(nm, "/tmp/polltestXXXXXX");
	rf = mkstemp(nm);
	if (rf < 0)
		printf("     could not make a temporary file -- SKIPPED\n");
	else {
		write(rf, "hello", 5);
		lseek(rf, 0, SEEK_SET);
		pfd[0].fd = rf;
		pfd[0].events = POLLIN;
		pfd[0].revents = 0;
		n = poll(pfd, 1, 1000);
		eq("a regular file reads as ready", n, 1);
		eq("and says POLLIN", (pfd[0].revents & POLLIN) != 0, 1);
		close(rf);
		unlink(nm);
	}

	close(p[0]);
	close(p[1]);
	printf("\n%d failures\n", fails);
	return fails;
}
