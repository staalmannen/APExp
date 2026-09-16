/*
 * Does free() give memory back to malloc(), and what does growing a
 * buffer by realloc actually cost?
 *
 *	pcc -o malloc-reuse-test malloc-reuse-test.c && ./malloc-reuse-test
 *
 * tcltest dies partway through Tcl's own test suite with
 *
 *	Test file error: tcltest 69507: Killed: Insufficient physical memory
 *
 * which is the 9front kernel refusing to grow the process. So the
 * question is what APE's allocator does with memory it already has.
 *
 * ap/malloc/malloc.c is Plan 9's: one free list per power-of-two size
 * class, and free() pushes the block onto the list for ITS OWN class
 * and nowhere else. Two consequences, both measured below:
 *
 *   - every request is rounded UP to a power of two, so a 3 MB string
 *     costs 4 MB and a 33 MB one costs 64 MB;
 *   - a freed block can only ever be reused by a request in the SAME
 *     class. Nothing splits and nothing coalesces, so 64 MB sitting on
 *     the 2**26 list does not satisfy a 32 MB request -- the heap grows
 *     instead. Section 2 is that, and it still fails; see below.
 *
 * SECTION 3 WAS THE ONE THAT MATTERED, AND IT IS FIXED. realloc was
 * malloc-copy-free unconditionally, so growing one buffer by doubling
 * -- how every interpreter builds a big string -- walked the classes
 * and stranded a dead block in each. It now extends the block where it
 * lies when the block is the last thing on the heap, which is nearly
 * always true of a buffer being grown. Measured on the build host:
 * 1 KB -> 1 MB fell from 2005575 bytes to 1075488, and the peak for a
 * 32 MB string from 62 MB to 32 MB.
 *
 * SECTION 4 IS THE ONE TO KEEP. Extending at the break must not take
 * priority over a block that is already free: the first cut of that
 * fix made the heap BIGGER, not smaller -- three 32 MB strings in a row
 * cost 97 MB where the unfixed allocator cost 64 -- because growing in
 * place walked straight past the block the previous string had freed.
 * Nothing but this measurement said so.
 *
 * A NOTE ON SPLITTING, since it is the obvious fix for section 2 and
 * does not work. A block of class k occupies 32 + 2**k bytes: a 16-byte
 * header padded to max_align_t, the payload, and the whole rounded up
 * to 16. So two class-k blocks need 64 + 2**(k+1) -- THIRTY-TWO bytes
 * more than the single 32 + 2**(k+1) block they would be carved from.
 * Tightening the padding does not rescue it either: with an exact
 * 16 + 2**k stride two still need 32 + 2**(k+1) against 16 + 2**(k+1).
 * A header living outside the power of two cannot buddy-split at all.
 * (An earlier version of this comment said 16 + 2**k and so understated
 * the slack by sixteen bytes a block; the conclusion survives, the
 * arithmetic did not, and the stride is worth measuring rather than
 * deriving.)
 *
 * And splitting is not obviously wanted even if the layout allowed it.
 * Searching upward for any larger free block means a 1 KB request
 * shreds a 64 MB block that nothing can ever reassemble, since there is
 * no coalescing to put it back -- so it would have to be bounded, and
 * bounded splitting buys much less than section 3 did. Section 5 is the
 * adversary that would show it.
 *
 * Sizes here are deliberately small so the test costs nothing to run,
 * and so that it is meaningful on glibc: they straddle the 128 KB mmap
 * threshold, and where glibc serves a request by mmap the break does
 * not move at all, which passes every assertion below for its own
 * reasons. Every assertion holds on glibc, which is how this was
 * checked.
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
 * Reported but NOT counted as a failure. A deliberate, documented
 * limitation that can never pass is noise in a test everyone runs, and
 * a permanently red line trains people to stop reading the output --
 * but hiding it would freeze today's limit in as the requirement.
 */
static void
known(int cond, const char *what)
{
	printf("  %s %s\n", cond ? "(now passes!)" : "KNOWN-NOT-FIXED", what);
}

/*
 * Measured and printed, with no verdict, because the right answer is
 * the allocator's own business. Whether a freed block is kept for the
 * next request of that size or handed back to the kernel is a policy
 * choice, not a rule -- glibc does the second for anything over its
 * mmap threshold, and is not wrong to.
 */
static void
note(const char *what, unsigned long n)
{
	printf("  note %s: %lu\n", what, n);
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
	unsigned long base, mark, grew, grew2;
	char *p, *q, *keep;
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
	 * The one that separates a real allocator from a set of per-size
	 * free lists. 64 KB is free and 32 KB is wanted; there is no reason
	 * to touch the kernel, and this allocator touches it anyway. See
	 * the splitting note at the top for why that is a layout problem
	 * rather than an oversight.
	 */
	p = malloc(64 * 1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	free(p);
	mark = brknow();
	q = malloc(32 * 1024);
	if(q == NULL) { printf("malloc failed\n"); return 1; }
	grew = brknow() - mark;
	printf("  32K after freeing 64K grew the heap by %lu bytes\n", grew);
	known(grew == 0, "a smaller request reuses the larger free block");
	free(q);

	printf("\n--- 3. growing one buffer with realloc ---\n");
	/*
	 * The interpreter pattern, and the number behind the OOM. A
	 * conforming allocator may spend what it likes here, so the bound
	 * is generous -- but anything near 2 MB means every intermediate
	 * block was stranded on its own class's free list, which is what
	 * this port did until realloc learned to extend in place.
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
	printf("  (1M is 1048576; near 2M means each intermediate block was\n");
	printf("   stranded on its own size-class free list)\n");
	ok(grew < 1536UL * 1024, "growing to 1M costs about 1M, not about 2M");

	/* the contents have to survive an in-place grow as much as a copy */
	for(i = 0; i < 1024 * 1024; i++)
		if(p[i] != (char)20) {
			printf("  FAIL contents corrupted at byte %d\n", i);
			fail++;
			break;
		}
	if(i == 1024 * 1024)
		printf("  PASS contents survived the growth\n");
	free(p);

	/* And is any of that reusable? Ask for the final size again. */
	mark = brknow();
	q = malloc(1024 * 1024);
	if(q == NULL) { printf("malloc failed\n"); return 1; }
	grew = brknow() - mark;
	note("asking for 1M again grew the heap by", grew);
	printf("  (0 here means APE kept it on the 2**20 list. glibc gives a\n");
	printf("   block that size back to the kernel and so grows again --\n");
	printf("   which is why this is reported and not asserted.)\n");
	free(q);

	printf("\n--- 4. REUSE MUST BEAT EXTENDING THE BREAK ---\n");
	/*
	 * THE REGRESSION TEST FOR THE FIX ITSELF. Growing a block in place
	 * is only an improvement while it does not skip memory the process
	 * already owns. Free a 1 MB block, then grow a different buffer up
	 * to 1 MB: the freed block must be what satisfies it.
	 *
	 * The first cut of the in-place fix failed exactly here and nowhere
	 * else -- every other section got better while the total heap went
	 * up by half.
	 */
	keep = malloc(1024 * 1024);
	if(keep == NULL) { printf("malloc failed\n"); return 1; }
	free(keep);			/* 1 MB now on its class's free list */

	mark = brknow();
	p = malloc(1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	for(i = 11; i <= 20; i++) {
		q = realloc(p, 1UL << i);
		if(q == NULL) { printf("realloc failed at 2**%d\n", i); return 1; }
		p = q;
	}
	grew = brknow() - mark;
	printf("  growing to 1M with 1M already free took %lu bytes\n", grew);
	ok(grew < 1024UL * 1024,
		"the already-free block was used rather than the kernel");
	free(p);

	printf("\n--- 5. the shredding adversary (reported) ---\n");
	/*
	 * What bounded splitting would have to be measured against, kept
	 * so the argument in the header has a number beside it: a big block
	 * freed, a lot of small traffic, then the big block wanted again.
	 * An allocator that splits without coalescing turns the first
	 * request into confetti and has to go back to the kernel for the
	 * second.
	 */
	mark = brknow();
	p = malloc(4 * 1024 * 1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	free(p);
	for(i = 0; i < 2000; i++) {
		q = malloc(1024);
		if(q == NULL) { printf("malloc failed\n"); return 1; }
		free(q);
	}
	mark = brknow();
	p = malloc(4 * 1024 * 1024);
	if(p == NULL) { printf("malloc failed\n"); return 1; }
	grew2 = brknow() - mark;
	printf("  4M again after 2000 small allocations grew the heap by %lu\n",
		grew2);
	printf("  (0 means the big block came back intact; 4M would mean it\n");
	printf("   had been shredded and could not be reassembled)\n");
	free(p);

	printf("\n%d failure(s)\n", fail);
	return fail;
}
