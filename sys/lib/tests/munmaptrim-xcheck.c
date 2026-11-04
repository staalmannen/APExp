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
 * THE CONTROL IS A DELIBERATE BREAK, AND IT HAS BEEN RUN TWICE -- this
 * check has no external oracle, so a clean 0 proves nothing until the
 * instrument has been shown to notice. Both breaks were made in the real
 * source, measured, and reverted:
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
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define SEG_THRESHOLD (1024*1024)

/* ---- the fakes the extracted code links against ---------------- */

static void *released[16];
static int   released_seg[16];
static int   nreleased;

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

/* `p9_mmap_tracked' is extracted too, but its allocator half is not
 * wanted here; the harness fills the table through this instead, so the
 * cases can name addresses that mean something when printed. */

/* ---- the real code ------------------------------------------- */
#include "munmaptrim-extract.h"

#undef free

/* ---- the harness ---------------------------------------------- */

static int fails;

static void
reset(void)
{
	mmap_table_n = 0;
	nreleased = 0;
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
	expect("released as a segment", released_seg[0], 1);

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

	printf("\nmunmaptrim-xcheck: %d failures\n", fails);
	return fails;
}
