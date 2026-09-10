/*
 * Does free() give memory back to malloc()?
 *
 *	pcc -o malloc-reuse-test malloc-reuse-test.c && ./malloc-reuse-test
 *
 * tcltest dies partway through Tcl's own test suite with
 *
 *	Test file error: tcltest 69507: Killed: Insufficient physical memory
 *
 * which is the 9front kernel refusing to grow the process, and the same
 * thing is expected to stop bash on a configure script. So the question
 * is whether APE's allocator hands memory back.
 *
 * ap/malloc/malloc.c is Plan 9's: one free list per power-of-two size
 * class, and free() pushes the block onto the list for ITS OWN class and
 * nowhere else. Two consequences, both measured below:
 *
 *   - every request is rounded UP to a power of two, so a 3 MB string
 *     costs 4 MB and a 33 MB one costs 64 MB;
 *   - a freed block can only ever be reused by a request in the SAME
 *     class. Nothing splits a large free block for a smaller request and
 *     nothing coalesces, so 64 MB sitting on the 2**26 list does not
 *     satisfy a 32 MB request -- the heap grows instead.
 *
 * The second one is what makes growth by realloc expensive, and growth
 * by realloc is how every interpreter builds a big string. realloc()
 * here is malloc-copy-free, so growing one buffer to N bytes walks the
 * classes and strands one dead block in each: the heap ends up holding
 * about 2N of garbage that only an identically-sized request can ever
 * use again, on top of the up-to-2N rounding.
 *
 * A note on splitting, since it is the obvious fix and does not work as
 * written: a block of class k occupies 16 + 2**k bytes (the header is
 * padded to 16 for max_align_t), so two class-k blocks need 32 + 2**(k+1)
 * -- sixteen bytes MORE than the one class-(k+1) block they would come
 * from. The layout has no room for the split, which is presumably why
 * Plan 9 never did it. Making this allocator return memory means
 * changing the block layout or replacing it.
 *
 * Sizes here are deliberately small (64 KB and below) so the test costs
 * nothing to run, and so that it is meaningful on glibc too: they are
 * under the 128 KB mmap threshold, so glibc serves them from the same
 * heap and its own splitting is what makes section 2 pass there. Every
 * assertion below holds on glibc, which is how this was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

/*
 * How far has the break moved? sbrk(0) is the current break on both
 * systems. This measures what the process took from the kernel, which is
 * the quantity the "Insufficient physical memory" note is about --
 * not what malloc thinks it has handed out.
 */
static unsigned long
brknow(void)
{
	return (unsigned long)(char *)sbrk(0);
}

int
main(void)
{
	unsigned long base, mark, grew;
	char *p, *q;
	int i;

	/*
	 * Warm up first: the first malloc in a program sets up whatever the
	 * allocator needs, and charging that to the measurement below would
	 * report a growth that has nothing to do with reuse.
	 */
	p = malloc(1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	free(p);

	printf("--- 1. free then ask for the SAME size again ---\n");
	base = brknow();
	p = malloc(64 * 1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	memset(p, 1, 64 * 1024);
	free(p);
	mark = brknow();
	q = malloc(64 * 1024);
	if(q == NULL) { printf("malloc failed\n"); return 1; }
	grew = brknow() - mark;
	printf("  first 64K grew the heap by %lu bytes\n", mark - base);
	printf("  second 64K grew it by a further %lu\n", grew);
	ok(grew == 0, "the same size is served from the freed block");
	free(q);

	printf("\n--- 2. free then ask for a SMALLER size ---\n");
	/*
	 * This is the one that separates a real allocator from a set of
	 * per-size free lists. 64 KB is free and 32 KB is wanted; there is
	 * no reason to touch the kernel.
	 */
	p = malloc(64 * 1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	free(p);
	mark = brknow();
	q = malloc(32 * 1024);
	if(q == NULL) { printf("malloc failed\n"); return 1; }
	grew = brknow() - mark;
	printf("  32K after freeing 64K grew the heap by %lu bytes\n", grew);
	ok(grew == 0, "a smaller request reuses the larger free block");
	free(q);

	printf("\n--- 3. growing one buffer with realloc ---\n");
	/*
	 * The interpreter pattern. Reported rather than asserted, because
	 * how much a conforming allocator needs here is its own business --
	 * but the number says what a Tcl or bash script that builds a big
	 * string will cost, and it is the number behind the OOM.
	 */
	mark = brknow();
	p = malloc(1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	for(i = 11; i <= 20; i++) {		/* 2K up to 1M */
		q = realloc(p, 1UL << i);
		if(q == NULL) { printf("realloc failed at 2**%d\n", i); return 1; }
		p = q;
		memset(p, i, 1UL << i);
	}
	grew = brknow() - mark;
	printf("  growing 1K -> 1M by realloc took %lu bytes from the kernel\n",
		grew);
	printf("  (1M is 1048576; anything near 2M means each intermediate\n");
	printf("   block was stranded on its own size-class free list)\n");
	free(p);

	/* And is any of that reusable? Ask for the final size again. */
	mark = brknow();
	q = malloc(1024 * 1024);
	if(q == NULL) { printf("malloc failed\n"); return 1; }
	printf("  asking for 1M again grew it by %lu\n", brknow() - mark);
	free(q);

	printf("\n%d failure(s)\n", fail);
	return fail;
}
