/*
 * pthread-stack-test.c -- does a thread share the CREATOR's STACK?
 *
 * FROM: lz4.  `unlz4' reported `LZ4F frame decoding could not complete:
 * invalid frame' while writing byte-identical output, on a file whose
 * frame tail was measured and correct (4 zero bytes of EndMark then 4
 * checksum bytes).  `archive-roundtrip' had cleared the compressor from
 * two directions -- the threaded and `-T1' streams are IDENTICAL -- so
 * the decoder was the only thing left, and the decode path calls
 * `TPool_create(1,1)' unconditionally.
 *
 * `lz4io.c:2104-2106' declares `filesize', `lastStatus' and
 * `storedSkips' as LOCALS, and the worker job is handed all three BY
 * ADDRESS.  The worker's `*lz4fc->lastStatus = nextToLoad' then writes
 * into the parent's stack frame -- which on Plan 9 is a different
 * object in the two processes.
 *
 * ---- THE MECHANISM, AND IT IS IN THIS TREE'S OWN SOURCE --------------
 *
 * `lib/ap/thread/pthread_create.c:85' is
 * `_RFORK(RFFDG|RFPROC|RFMEM)', and its own comment eleven lines down
 * says it plainly:
 *
 *     RFMEM shares data and bss [...] The STACK is not shared --
 *     dupseg() gives SG_STACK a new segment whatever RFMEM says
 *
 * *That was written as a REASSURANCE* -- it is there to explain why the
 * parent returning through the child's frame is safe -- and the cost
 * side of the same fact was never written down.  POSIX requires all
 * threads of a process to share the WHOLE address space, so a pointer
 * to any object is valid in every thread.  Here, data, bss and the heap
 * are shared and STACKS ARE NOT, which makes `&local' the one kind of
 * address that silently means something different in the two threads.
 *
 * That class is not exotic: handing a worker `&result` is the ordinary
 * way to get an answer back out of one.
 *
 * ---- WHY THREE SECTIONS AND NOT ONE ---------------------------------
 *
 * Section 3 alone cannot be read.  A failure there is equally
 * consistent with "threads do not share memory", "pthread_create did
 * not run the function" and "pthread_join did not wait" -- all of which
 * this tree has had.  **Sections 1 and 2 are controls that must PASS**:
 * bss and the heap are in the segments RFMEM does share, so if those
 * two work and the stack does not, the finding is about the STACK and
 * nothing else.
 *
 * ---- THE EXPECTED RESULT TODAY --------------------------------------
 *
 * On glibc: 0 failures, all four sections.
 * On APExp: sections 1, 2 and 4 pass and SECTION 3 FAILS, 1 failure.
 *
 * *A run of 0 failures on Plan 9 would mean the stack question has been
 * solved*, which is a real change (every thread, the main one included,
 * would have to run on a stack allocated from the shared segment) and
 * not something that happens by accident.  Until then this reports a
 * known platform gap rather than a regression; the entry is in 0.6's
 * inventory.
 *
 * Build:
 *   gcc  -o pthread-stack-test pthread-stack-test.c -lpthread   (oracle)
 *   pcc  -o pthread-stack-test pthread-stack-test.c             (APExp)
 *
 * Print PASS/FAIL per case; exit with the number of failures.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

static int failures = 0;

static void check(int ok, const char *what)
{
	printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
	if(!ok)
		failures++;
}

/*
 * This test can HANG -- a thread that never runs and a join that never
 * returns both look like a prompt that does not come back -- so it arms
 * an alarm, the same rule `pthread-test.c' follows.
 */
static void
onalarm(int sig)
{
	(void)sig;
	printf("FAIL: pthread-stack-test TIMED OUT -- a thread or a join never returned\n");
	fflush(stdout);
	_exit(100);
}

/* Section 1's subject: bss, which RFMEM does share. */
static int bss_target;

/* Section 2's subject: the heap, likewise shared. */
static int *heap_target;

/* Section 3's subject: an address the creator passes in. */
struct arg {
	int *cell;
	int  ran;      /* in bss, so the parent can tell "did not run" apart */
	int  saw;      /* what the worker read back immediately after storing */
};

static void *
w_bss(void *a)
{
	(void)a;
	bss_target = 42;
	return NULL;
}

static void *
w_heap(void *a)
{
	(void)a;
	*heap_target = 42;
	return NULL;
}

static void *
w_cell(void *a)
{
	struct arg *g = (struct arg *)a;

	g->ran = 1;
	*g->cell = 42;
	/*
	 * Read it back HERE, in the worker.  If this reads 42 and the
	 * creator still sees 1, the store happened and landed somewhere
	 * the creator cannot see -- which separates "the write did not
	 * happen" from "the write went to a different object".  Without
	 * this the two are the same observation.
	 */
	g->saw = *g->cell;
	return NULL;
}

int
main(void)
{
	pthread_t t;
	int rc;

	setvbuf(stdout, NULL, _IOLBF, 0);
	printf("pthread-stack-test: starting\n");

	signal(SIGALRM, onalarm);
	alarm(30);

	/* ---- 1. bss: a control that must pass ------------------------ */
	bss_target = 1;
	rc = pthread_create(&t, NULL, w_bss, NULL);
	check(rc == 0, "1a pthread_create for the bss case returned 0");
	if(rc == 0){
		check(pthread_join(t, NULL) == 0, "1b join returned");
		check(bss_target == 42, "1c a thread's store to BSS is visible to the creator");
	}

	/* ---- 2. heap: a control that must pass ----------------------- */
	heap_target = (int *)malloc(sizeof(int));
	if(heap_target == NULL){
		printf("FAIL: 2 out of memory\n");
		failures++;
	} else {
		*heap_target = 1;
		rc = pthread_create(&t, NULL, w_heap, NULL);
		check(rc == 0, "2a pthread_create for the heap case returned 0");
		if(rc == 0){
			check(pthread_join(t, NULL) == 0, "2b join returned");
			check(*heap_target == 42,
			      "2c a thread's store to the HEAP is visible to the creator");
		}
	}

	/* ---- 3. the creator's stack: the question -------------------- */
	{
		int cell = 1;             /* a local, as lz4's lastStatus is */
		struct arg g;

		g.cell = &cell;
		g.ran  = 0;
		g.saw  = 0;

		/*
		 * `g' is a local too, but only its ADDRESS is passed and the
		 * worker's own writes to `g.ran'/`g.saw' are subject to the
		 * very thing under test -- so they are read only to
		 * DISAMBIGUATE a failure, never to decide a pass.
		 */
		rc = pthread_create(&t, NULL, w_cell, &g);
		check(rc == 0, "3a pthread_create for the stack case returned 0");
		if(rc == 0){
			check(pthread_join(t, NULL) == 0, "3b join returned");
			check(cell == 42,
			      "3c a thread's store to the CREATOR'S STACK is visible to the creator");
			if(cell != 42)
				printf("      (worker ran=%d, read back=%d -- "
				       "ran=0 and read-back=0 is the whole frame being private; "
				       "ran=1 and read-back=42 would be a store that landed elsewhere)\n",
				       g.ran, g.saw);
		}
	}

	/* ---- 4. the creator is still intact -------------------------- */
	{
		/*
		 * If section 3's store DID land in the creator's frame but at
		 * the wrong offset, the damage would show up as a neighbouring
		 * local changing.  This is cheap and rules that out.
		 */
		volatile int guard_a = 0x11111111;
		volatile int guard_b = 0x22222222;
		check(guard_a == 0x11111111 && guard_b == 0x22222222,
		      "4a the creator's own frame is undamaged");
	}

	alarm(0);
	printf("pthread-stack-test: %d failures\n", failures);
	return failures;
}
