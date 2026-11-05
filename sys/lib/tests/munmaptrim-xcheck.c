/* munmaptrim-xcheck.c -- does libap's `p9_munmap' bookkeeping do the
 * right thing for a PARTIAL unmap?  Checked on the build host, against
 * the real function text.
 *
 *	sh munmaptrim-xcheck.sh
 *
 * ***A CROSS-CHECK, NOT A TEST OF THE PLATFORM.*** It links the real
 * `p9_munmap' -- extracted from `sys/src/ape/lib/ap/plan9/__p9_syscall.c'
 * by the shell script beside this file, never transcribed -- into a gcc
 * program with a FAKE `_SEGDETACH'/`free' pair that records what was
 * released.  So it answers "does the entry table end up right", which is
 * pure bookkeeping and so a pure function of its input; it says nothing
 * about segments, pages or Plan 9.  `mmaptrim-probe.c' is the instrument
 * for that half, and the two are deliberately separate.
 *
 * WHY IT EXISTS. The bug this guards against is not a crash in
 * `p9_munmap' itself -- it is `p9_munmap' releasing a segment the caller
 * is still using, or failing to release one at the end.  Both are
 * invisible from inside the function and expensive to see from the VM: a
 * segment freed early faults somewhere else entirely, and one never
 * freed is just a program that grows.  *A table that can be printed is
 * worth more than a fault that has to be chased.*
 *
 * The cases follow php's `zend_mm_chunk_alloc_int' and
 * `zend_mm_chunk_truncate', which are the reason the arm was written:
 *
 *   0  exact unmap            -> released, entry gone
 *   1  head trim then free    -> nothing released by the trim; the
 *                                later free of the NARROWED range
 *                                releases the ORIGINAL base
 *   2  tail trim then free    -> same, from the other end
 *   3  head AND tail trim     -> zend's real sequence
 *   4  interior hole          -> releases nothing, both sides stay live
 *   5  unknown address        -> releases NOTHING. The old code called
 *                                `_SEGDETACH' here, which on Plan 9
 *                                destroys whatever segment that address
 *                                happens to be in.
 *
 * ***SECTION 5 IS THE ONE THAT WOULD HAVE CAUGHT THE WORST OF IT***, and
 * it is a case where the right behaviour is to do NOTHING -- which is
 * exactly the shape this tree keeps getting wrong in the other
 * direction, a stub answering FAILURE where the answer is "nothing to
 * do".  Here it is a stub answering DESTRUCTION where the answer is
 * "not mine".
 *
 * THE CONTROL IS A DELIBERATE BREAK, AND IT HAS BEEN RUN FOUR TIMES --
 * this check has no external oracle, so a clean 0 proves nothing until
 * the instrument has been shown to notice. Each break was made in the
 * real source, measured, and reverted:
 *
 *   `if(len >= mmap_table[i].len)' -> `if(1)', i.e. the old rule that
 *   matched on the start address alone:            **8 failures**, in
 *   sections 1 and 3 -- the head trim releasing the segment the caller
 *   is about to use.
 *
 *   the deliberate no-op at the end -> `_SEGDETACH(addr)', i.e. the old
 *   unknown-address fallback:                      **2 failures**, both
 *   in section 5, one of them for an address ONE PAGE PAST the end of a
 *   live mapping.
 *
 *   the malloc arm's round-up deleted, `p = base':  **1 failure**, in
 *   section 6. Only one, and correctly so: section 7 still passes,
 *   because zend aligns the chunk from whatever address it is given,
 *   so a non-page-aligned mmap breaks POSIX without breaking zend.
 *
 *   `*basep = base' -> `*basep = p':               **3 failures**, in
 *   sections 6 and 7 -- a `free' of a pointer `malloc' never returned.
 *
 * ***AND THAT LAST CONTROL FAILED TO FIRE THE FIRST TIME, 0 FAILURES.***
 * Sections 6 and 7 read `mmap_table[0].base' and then checked that what
 * was released matched it -- which holds however wrong the field is,
 * since both sides come from the same field. *A check that cannot
 * fail.* They compare against the pointer `malloc' actually returned
 * now, which the wrapper below records; the free was already wrapped
 * for exactly this reason and the malloc was not.
 *
 * Exit status is the failure count.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>

/* ---- the fakes the extracted code links against ---------------- */

static void *released[16];
static int   released_seg[16];
static int   nreleased;

static int nattached;

/*
 * `_SEGATTACH' models what Plan 9's does and no more: it answers a
 * PAGE-ALIGNED, zeroed region that `_SEGDETACH' can later take back
 * whole.  It must return real memory, because the extracted
 * `p9_mmap_impl' memsets what it is given -- a fake answering NULL
 * would make the segment arm crash rather than be tested.
 */
static void *
_SEGATTACH(int attr, char *class, void *va, unsigned long len)
{
	void *p = NULL;
	(void)attr; (void)class; (void)va;
	if(posix_memalign(&p, 4096, len) != 0)
		return (void*)-1;
	nattached++;
	return p;
}

static void *
_SEGDETACH(void *p)
{
	if(nreleased < 16){
		released[nreleased] = p;
		released_seg[nreleased] = 1;
		nreleased++;
	}
	return 0;
}

/* The real code calls free() on the malloc-backed arm.  Rename it so
 * nothing is actually freed and the call is visible. */
#define free my_free
static void
my_free(void *p)
{
	if(nreleased < 16){
		released[nreleased] = p;
		released_seg[nreleased] = 0;
		nreleased++;
	}
}

/*
 * ***AND malloc IS WRAPPED FOR THE SAME REASON THE FREE IS, WHICH THE
 * FIRST VERSION OF SECTIONS 6 AND 7 MISSED.***  Those sections read
 * `mmap_table[0].base' and then checked that what was released matched
 * it -- which is true however wrong `base' is, because both sides come
 * from the same field.  Breaking the real code's `*basep = base' to
 * `*basep = p' on purpose produced **0 failures**: a check that cannot
 * fail.  The harness needs its own handle on the pointer malloc
 * actually returned, and this is it.
 */
static void *last_malloc;
static int   nmalloc;

/* taken before the macro below hides the name */
static void *(*real_malloc)(size_t) = malloc;

#define malloc my_malloc
static void *
my_malloc(size_t n)
{
	last_malloc = real_malloc(n);
	nmalloc++;
	return last_malloc;
}

/* ---- the real code ------------------------------------------- */
#include "munmaptrim-extract.h"

#undef free
#undef malloc

/* ---- the harness ---------------------------------------------- */

static int fails;

static void
reset(void)
{
	mmap_table_n = 0;
	nreleased = 0;
	nattached = 0;
}

static void
track(void *base, size_t len)
{
	if(mmap_table_n >= mmap_table_cap){
		int newcap = mmap_table_cap ? mmap_table_cap * 2 : 64;
		struct MmapEntry *t = realloc(mmap_table,
		                              newcap * sizeof(*mmap_table));
		mmap_table = t;
		mmap_table_cap = newcap;
	}
	mmap_table[mmap_table_n].base   = base;
	mmap_table[mmap_table_n].addr   = base;
	mmap_table[mmap_table_n].len    = len;
	mmap_table[mmap_table_n].is_seg = (len >= SEG_THRESHOLD);
	mmap_table_n++;
}

static void
expect(const char *what, long got, long want)
{
	if(got == want)
		printf("  PASS %-44s %ld\n", what, got);
	else {
		printf("  FAIL %-44s got %ld want %ld\n", what, got, want);
		fails++;
	}
}

#define CHUNK	(2*1024*1024)
#define PAGE	4096
#define OVER	(CHUNK + CHUNK - PAGE)

/* a plausible misaligned segattach result */
#define BASE	((char*)0x20001000UL)

int
main(void)
{
	char *p;
	size_t off;

	printf("munmaptrim-xcheck: p9_munmap bookkeeping, host build\n\n");

	/* ---- 0: exact unmap ---- */
	printf("Section 0: exact unmap releases the base\n");
	reset();
	track(BASE, CHUNK);
	p9_munmap(BASE, CHUNK);
	expect("entries left", mmap_table_n, 0);
	expect("releases", nreleased, 1);
	expect("released the base", released[0] == BASE, 1);
	/*
	 * `track' derives is_seg from the length, as the real code does,
	 * so which release this expects is a FACT ABOUT THE THRESHOLD.
	 * It said `segment' while SEG_THRESHOLD was 1MB and the 2MB
	 * fixture was above it; at 64MB the same fixture is malloc-backed
	 * and it says the other thing.  *Stated as a dependency rather
	 * than a constant*, because the first run after the threshold
	 * moved failed here and the failing line said nothing about
	 * why.  The segment path is section 8's, through the real
	 * `p9_mmap_tracked'.
	 */
	expect("the 2MB fixture is below SEG_THRESHOLD",
	       CHUNK < SEG_THRESHOLD, 1);
	expect("released as malloc, not segment", released_seg[0], 0);

	/* ---- 1: head trim, then free the rest ---- */
	printf("\nSection 1: head trim keeps the tail live\n");
	reset();
	track(BASE, OVER);
	p9_munmap(BASE, PAGE);
	expect("entries left", mmap_table_n, 1);
	expect("releases from the trim", nreleased, 0);
	expect("addr advanced", mmap_table[0].addr == BASE + PAGE, 1);
	expect("len shrank", (long)mmap_table[0].len, OVER - PAGE);
	expect("base unmoved", mmap_table[0].base == BASE, 1);
	p9_munmap(BASE + PAGE, OVER - PAGE);
	expect("entries after the free", mmap_table_n, 0);
	expect("releases after the free", nreleased, 1);
	expect("released the ORIGINAL base", released[0] == BASE, 1);

	/* ---- 2: tail trim, then free the rest ---- */
	printf("\nSection 2: tail trim keeps the head live\n");
	reset();
	track(BASE, OVER);
	p9_munmap(BASE + CHUNK, OVER - CHUNK);
	expect("entries left", mmap_table_n, 1);
	expect("releases from the trim", nreleased, 0);
	expect("addr unmoved", mmap_table[0].addr == BASE, 1);
	expect("len shrank", (long)mmap_table[0].len, CHUNK);
	p9_munmap(BASE, CHUNK);
	expect("entries after the free", mmap_table_n, 0);
	expect("released the base", released[0] == BASE, 1);

	/* ---- 3: zend's real sequence ---- */
	printf("\nSection 3: zend_mm_chunk_alloc_int's own sequence\n");
	reset();
	track(BASE, OVER);
	off = (unsigned long)BASE & (CHUNK-1);
	off = CHUNK - off;			/* what zend computes */
	p9_munmap(BASE, off);			/* head */
	p = BASE + off;
	expect("chunk is 2MB-aligned", ((unsigned long)p & (CHUNK-1)) == 0, 1);
	expect("len left is the chunk", (long)mmap_table[0].len, CHUNK);
	expect("nothing released yet", nreleased, 0);
	/* alignment -= off leaves exactly REAL_PAGE_SIZE, so zend does NOT
	 * tail-trim here; do it anyway, to check the second arm on a
	 * mapping the first arm has already narrowed. */
	p9_munmap(p + CHUNK/2, CHUNK/2);
	expect("tail trim after a head trim", (long)mmap_table[0].len, CHUNK/2);
	expect("still nothing released", nreleased, 0);
	p9_munmap(p, CHUNK/2);
	expect("final free releases the base", released[0] == BASE, 1);
	expect("entries left", mmap_table_n, 0);

	/* ---- 4: interior hole ---- */
	printf("\nSection 4: an interior hole releases nothing\n");
	reset();
	track(BASE, OVER);
	p9_munmap(BASE + CHUNK/2, PAGE);
	expect("entries left", mmap_table_n, 1);
	expect("releases", nreleased, 0);
	expect("addr unmoved", mmap_table[0].addr == BASE, 1);
	expect("len unmoved", (long)mmap_table[0].len, OVER);

	/* ---- 5: the one that mattered ---- */
	printf("\nSection 5: an address in NO mapping releases nothing\n");
	reset();
	track(BASE, CHUNK);
	p9_munmap((char*)0x7fff00000000UL, PAGE);
	expect("releases", nreleased, 0);
	expect("the real entry is untouched", mmap_table_n, 1);
	p9_munmap(BASE + CHUNK, PAGE);		/* just past the end */
	expect("releases, one past the end", nreleased, 0);
	expect("the real entry is still untouched", mmap_table_n, 1);

	/* ---- 6: the malloc arm must answer a PAGE-ALIGNED address ---- */
	printf("\nSection 6: p9_mmap_tracked's malloc arm is page-aligned\n");
	reset();
	expect("the chunk size is below SEG_THRESHOLD",
	       CHUNK < SEG_THRESHOLD, 1);
	{
		void *a[4];
		int k, misaligned = 0, basesame = 0, badbase = 0;

		for(k = 0; k < 4; k++){
			a[k] = p9_mmap_tracked(NULL, CHUNK, 0,
			                       MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
			if(a[k] == MAP_FAILED){
				printf("  FAIL mmap %d failed\n", k);
				fails++;
				continue;
			}
			if((uintptr_t)a[k] & (MMAP_PAGE - 1))
				misaligned++;
			if(mmap_table[k].base == mmap_table[k].addr)
				basesame++;
			if(mmap_table[k].base != last_malloc)
				badbase++;
			/* the whole range must be writable and zeroed */
			if(((char*)a[k])[0] || ((char*)a[k])[CHUNK-1])
				printf("  (not zeroed at %d)\n", k);
			memset(a[k], 0x3c, CHUNK);
		}
		expect("misaligned returns", misaligned, 0);
		expect("base is the pointer malloc returned", badbase, 0);
		expect("one malloc per mapping", nmalloc, 4);
		expect("no segment slot spent", nattached, 0);
		expect("entries recorded", mmap_table_n, 4);
		/* base == addr only when malloc happened to land on a page;
		 * this is information, not a rule, so it is printed. */
		printf("  (base == addr for %d of 4 -- luck, not a rule)\n",
		       basesame);
		for(k = 0; k < 4; k++)
			p9_munmap(a[k], CHUNK);
		expect("all released", nreleased, 4);
		expect("released as malloc, not segment", released_seg[0], 0);
		expect("entries left", mmap_table_n, 0);
	}

	/* ---- 7: head trim on a malloc-backed mapping frees the BASE ---- */
	printf("\nSection 7: zend's sequence over the malloc arm\n");
	reset();
	{
		char *q = p9_mmap_tracked(NULL, OVER, 0,
		                          MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
		size_t o;

		if(q == MAP_FAILED){
			printf("  FAIL mmap failed\n");
			fails++;
		} else {
			void *b = last_malloc;   /* NOT mmap_table[0].base:
			                          * see the malloc wrapper */

			o = (uintptr_t)q & (CHUNK-1);
			o = o ? CHUNK - o : 0;
			p9_munmap(q, o);
			p = q + o;
			expect("chunk is 2MB-aligned",
			       ((uintptr_t)p & (CHUNK-1)) == 0, 1);
			expect("nothing released by the trim", nreleased, 0);
			expect("base is the pointer malloc returned",
			       mmap_table[0].base == b, 1);
			memset(p, 0x7e, CHUNK);   /* the kept range must be live */
			p9_munmap(p, mmap_table[0].len);
			expect("released", nreleased, 1);
			expect("released the MALLOC pointer, not the chunk",
			       released[0] == b, 1);
			expect("entries left", mmap_table_n, 0);
		}
	}

	/* ---- 8: at or above the threshold it is still a segment ---- */
	printf("\nSection 8: >= SEG_THRESHOLD still takes a segment\n");
	reset();
	{
		void *big = p9_mmap_tracked(NULL, SEG_THRESHOLD, 0,
		                            MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
		if(big == MAP_FAILED){
			printf("  FAIL mmap failed\n");
			fails++;
		} else {
			expect("one segment attached", nattached, 1);
			expect("recorded as a segment", mmap_table[0].is_seg, 1);
			expect("base == addr for a segment",
			       mmap_table[0].base == mmap_table[0].addr, 1);
			p9_munmap(big, SEG_THRESHOLD);
			expect("detached", released_seg[0], 1);
		}
	}

	printf("\nmunmaptrim-xcheck: %d failures\n", fails);
	return fails;
}
