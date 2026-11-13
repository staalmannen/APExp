/*
 * malloc-xcheck -- link libap's REAL allocator into a host program and
 * replay EDG's allocation pattern against it.
 *
 *	./malloc-xcheck.sh		(builds and runs; see that file)
 *
 * ***A CROSS-CHECK, NOT A TEST.***  It compiles
 * `sys/src/ape/lib/ap/malloc/{malloc,free,realloc}.c' -- the real
 * files, not a copy, so nothing can rot -- with the public names
 * renamed to `ap_malloc'/`ap_free'/`ap_realloc' and `sbrk' renamed to
 * a break of our own.  glibc's allocator is then still reachable under
 * its own names, which is what makes the harness itself safe to run.
 *
 * WHY IT EXISTS
 * =============
 *
 * cpfe dies in `free_memory_region' (`mem_manage.c:1208') walking
 * region 0's block chain, with `hdr == 0x3f4a1' -- a value three
 * orders of magnitude below the heap.  Six rounds of narrowing were
 * spent in the front end before `acid' put it in TEARDOWN.
 *
 * ***AND THE ROUND AFTER THAT, "the memory manager is mmap" TURNED
 * OUT TO BE WRONG.***  `mem_manage.c:751' reaches `alloc_new_mem_block'
 * only under `if (precompiled_header_processing_required)'; the else
 * arm is `malloc_with_check', and this port compiles no PCH.  **Every
 * EDG memory block is plain `malloc', and the region table is plain
 * `realloc'** (`realloc_with_check', 16KB and up).  So the mechanism
 * under the crash is libap's allocator -- which THIS RELEASE REWROTE,
 * the 16-aligned break and `_malloc_growtop's grow-in-place.
 *
 * *A rewritten allocator under a program that dies walking its own
 * heap is a suspect that can be examined without the VM*, which is
 * the whole reason for this file.  The VM round it replaces asks
 * `acid' which entry of the chain is bad; this asks whether the
 * allocator can produce a bad entry at all.
 *
 * WHAT IT CAN AND CANNOT SAY
 * ==========================
 *
 * **Sound**: overlap, content preservation, free-list integrity,
 * grow-in-place bookkeeping -- everything that is a function of the
 * allocator's own arithmetic over a break it is given.
 *
 * **Unsound**: anything about Plan 9's `sbrk'.  The fake break here
 * always succeeds, is always contiguous and is never moved by anyone
 * else; the real one is a segment that can refuse, and
 * `_malloc_growtop's whole correctness rests on `sbrk(0)' telling the
 * truth about a break something else may have moved.  **A clean run
 * here does not clear the real `sbrk'** -- it clears the arithmetic
 * above it.  LP64 host against an LLP64 target, so `long' differs;
 * nothing in these three files keys on `long' (`BLKSZ' casts to
 * `size_t' deliberately, and the comment there says why), but that is
 * a thing to re-check rather than assume if a section ever disagrees
 * with the VM.
 *
 * THE SECTIONS
 * ============
 *
 *   0  the invariants in isolation: every live block distinct, no two
 *      overlapping, contents preserved across a free of a neighbour.
 *   1  grow by doubling, which is the path `_malloc_growtop' was
 *      added for, with other blocks live so a wrong grow has
 *      something to tread on.
 *   2  realloc's contract proper: contents preserved, old pointer
 *      reusable afterwards, shrink returns the same pointer.
 *   3  ***EDG's OWN PATTERN***: 48-byte block headers placed at the
 *      base of 65536-byte malloc'd blocks, chained through `next',
 *      a region table grown by `realloc' WHILE blocks are live, then
 *      the chain walked exactly as `free_memory_region' walks it.
 *      This is the section that reproduces the CALL the failing code
 *      makes rather than the outcome it wants.
 *   4  the aligned-allocation back door, because `free' recognises a
 *      second header shape and a block that fails `MAGIC' is an
 *      `abort()' rather than a diagnostic.
 *
 * Section 3 asserts the one thing the crash violates: **every pointer
 * reached by walking the chain is one this program put there.**  A
 * header overwritten by the allocator shows up as a link that is not
 * in the set of blocks we allocated -- which is strictly stronger than
 * "it faulted", and is checkable without faulting.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * libap's allocator, renamed.  Declared here rather than included,
 * because the harness compiles THIS file without the -D renames: a
 * `-D' that moves the unit under test out of the reference's way
 * applies to the checker as well, and this tree has paid for that
 * more than once.
 */
extern void *ap_malloc(size_t);
extern void  ap_free(void *);
extern void *ap_realloc(void *, size_t);
extern void *ap_aligned_alloc(size_t, size_t);
extern void  ap_brk_reset(void);
extern size_t ap_brk_used(void);

static int failures;
static int checks;

static void
ok(int cond, const char *what, ...)
{
	checks++;
	if(cond)
		return;
	failures++;
	printf("FAIL  %s\n", what);
}

static void
okf(int cond, const char *fmt, long long a, long long b)
{
	checks++;
	if(cond)
		return;
	failures++;
	printf("FAIL  ");
	printf(fmt, a, b);
	printf("\n");
}

/* ---- block bookkeeping, so "overlap" is checkable ---------------- */

enum { MAXBLK = 4096 };

struct blk {
	char	*p;
	size_t	n;
	unsigned char sig;
};

static struct blk blks[MAXBLK];
static int nblks;

static void
remember(void *p, size_t n, unsigned char sig)
{
	if(nblks >= MAXBLK){
		printf("FAIL  malloc-xcheck: MAXBLK too small, the test is wrong\n");
		failures++;
		return;
	}
	blks[nblks].p = p;
	blks[nblks].n = n;
	blks[nblks].sig = sig;
	nblks++;
	memset(p, sig, n);
}

static void
check_all(const char *where)
{
	int i;
	size_t j;

	for(i = 0; i < nblks; i++){
		unsigned char *p = (unsigned char *)blks[i].p;
		for(j = 0; j < blks[i].n; j++){
			if(p[j] != blks[i].sig){
				printf("FAIL  %s: block %d (%p, %zu bytes) byte %zu is 0x%02x, want 0x%02x\n",
					where, i, blks[i].p, blks[i].n, j, p[j], blks[i].sig);
				failures++;
				checks++;
				return;	/* one report per sweep is enough */
			}
		}
	}
	checks++;
}

static int
overlaps(void)
{
	int i, k;

	for(i = 0; i < nblks; i++)
		for(k = i+1; k < nblks; k++){
			char *a = blks[i].p, *b = blks[k].p;
			if(a < b + blks[k].n && b < a + blks[i].n){
				printf("FAIL  overlap: block %d [%p,%zu) and block %d [%p,%zu)\n",
					i, a, blks[i].n, k, b, blks[k].n);
				return 1;
			}
		}
	return 0;
}

static void
forget_all(void)
{
	nblks = 0;
}

/* ---- 0: the invariants in isolation ----------------------------- */

static void
section0(void)
{
	static const size_t sizes[] = {
		1, 7, 8, 15, 16, 17, 31, 48, 63, 64, 100, 127, 128,
		255, 256, 1000, 1024, 4095, 4096, 4097, 65536, 100000
	};
	int i, r;
	void *p;

	printf("-- section 0: distinctness, overlap, neighbour survival\n");
	forget_all();

	for(r = 0; r < 8; r++)
		for(i = 0; i < (int)(sizeof sizes / sizeof sizes[0]); i++){
			p = ap_malloc(sizes[i]);
			ok(p != NULL, "ap_malloc returned null for a sane size");
			if(p == NULL)
				return;
			okf(((uintptr_t)p & 7) == 0,
				"ap_malloc returned %llx, not 8-aligned (%lld)",
				(long long)(uintptr_t)p, (long long)sizes[i]);
			remember(p, sizes[i], (unsigned char)(0x40 + (r*32 + i) % 0xb0));
		}

	failures += overlaps();
	checks++;
	check_all("section 0 after all allocations");

	/* free every third block and check the survivors */
	for(i = 0; i < nblks; i += 3){
		ap_free(blks[i].p);
		blks[i].n = 0;		/* no longer ours to read */
	}
	check_all("section 0 after freeing every third block");

	/*
	 * And allocate the same shapes again: the freed blocks come back
	 * off the free lists, and a free list that hands out a block
	 * twice shows up as an overlap.
	 */
	for(i = 0; i < (int)(sizeof sizes / sizeof sizes[0]); i++){
		p = ap_malloc(sizes[i]);
		if(p == NULL)
			continue;
		remember(p, sizes[i], (unsigned char)(0x20 + i));
	}
	failures += overlaps();
	checks++;
	check_all("section 0 after reuse");
}

/* ---- 1: grow by doubling, the _malloc_growtop path --------------- */

static void
section1(void)
{
	char *buf;
	size_t n, i;
	void *keep[16];
	int k;

	printf("-- section 1: grow by doubling with neighbours live\n");
	forget_all();

	/*
	 * Live blocks around the growing one -- and ***THE ORDER IS THE
	 * WHOLE POINT, WHICH THE CONTROL HAD TO TEACH ME.***
	 *
	 * The first version allocated all sixteen neighbours FIRST and
	 * the growing buffer LAST, which puts the buffer at the top of
	 * the heap -- where growing it in place is CORRECT.  So the
	 * control (grow-in-place with its top-of-heap test removed)
	 * passed this section, because there was nothing above the
	 * buffer to tread on.  *It only failed in the first draft
	 * because section 0 ran before it and left a tangled heap* --
	 * i.e. for a reason outside the section.
	 *
	 * Half the neighbours go ABOVE the buffer now.  A block with
	 * something above it is the configuration a wrong grow-in-place
	 * destroys, and it is also the faithful one: EDG's region table
	 * is realloc'd while newer blocks sit above it.
	 */
	for(k = 0; k < 8; k++){
		keep[k] = ap_malloc(4096);
		if(keep[k] == NULL){
			ok(0, "section 1: ap_malloc(4096) returned null");
			return;
		}
		remember(keep[k], 4096, (unsigned char)(0x80 + k));
	}

	n = 1;
	buf = ap_malloc(n);
	ok(buf != NULL, "section 1: initial ap_malloc(1) returned null");
	if(buf == NULL)
		return;
	buf[0] = 0x5a;

	for(k = 8; k < 16; k++){
		keep[k] = ap_malloc(4096);
		if(keep[k] == NULL){
			ok(0, "section 1: ap_malloc(4096) returned null");
			return;
		}
		remember(keep[k], 4096, (unsigned char)(0x80 + k));
	}

	for(; n < (1u<<22); ){
		size_t was = n;
		n *= 2;
		buf = ap_realloc(buf, n);
		if(buf == NULL){
			ok(0, "section 1: ap_realloc returned null while doubling");
			return;
		}
		for(i = 0; i < was; i++)
			if((unsigned char)buf[i] != 0x5a){
				printf("FAIL  section 1: byte %zu lost at size %zu\n", i, n);
				failures++;
				checks++;
				return;
			}
		checks++;
		memset(buf, 0x5a, n);
		/* and the neighbours must be untouched at every step */
		check_all("section 1 during doubling");
	}

	for(k = 0; k < 16; k++)
		ap_free(keep[k]);
	ap_free(buf);
}

/* ---- 2: realloc's contract -------------------------------------- */

static void
section2(void)
{
	char *p, *q;
	size_t i;

	printf("-- section 2: realloc contract\n");
	forget_all();

	p = ap_malloc(100);
	ok(p != NULL, "section 2: ap_malloc(100) returned null");
	if(p == NULL)
		return;
	for(i = 0; i < 100; i++)
		p[i] = (char)i;

	/* a shrink inside the same class must not move */
	q = ap_realloc(p, 50);
	ok(q == p, "section 2: shrink inside the class moved the block");
	ok(q != NULL, "section 2: shrink returned null");
	if(q == NULL)
		return;
	for(i = 0; i < 50; i++)
		if(q[i] != (char)i){
			printf("FAIL  section 2: shrink lost byte %zu\n", i);
			failures++;
			break;
		}
	checks++;

	/* a grow must preserve what was there */
	q = ap_realloc(q, 100000);
	ok(q != NULL, "section 2: grow returned null");
	if(q == NULL)
		return;
	for(i = 0; i < 50; i++)
		if(q[i] != (char)i){
			printf("FAIL  section 2: grow lost byte %zu\n", i);
			failures++;
			break;
		}
	checks++;

	/* realloc(NULL, n) is malloc(n) */
	p = ap_realloc(NULL, 64);
	ok(p != NULL, "section 2: ap_realloc(NULL, 64) returned null");
	if(p != NULL)
		ap_free(p);
	ap_free(q);
}

/* ---- 3: EDG's own pattern --------------------------------------- */

/*
 * `a_mem_block_header' from `sys/src/external/edg/src/mem_manage.c:4790',
 * member for member.  EDG folds `sizeof' into literals, and the one it
 * folded is `adjusted_header_size = 48ULL'; this struct must come out
 * 48 on the host too or the replication is not one, which is why
 * section 3 asserts it before using it.
 */
struct mem_block_header {
	struct mem_block_header *next;
	char	*start_of_block;
	char	*next_avail_in_block;
	char	*after_end_of_block;
	size_t	malloc_size;
	unsigned char trimmed;
	char	__dummy[7];
};

enum {
	HDRSZ	 = 48,			/* EDG's baked adjusted_header_size */
	BLOCKSZ	 = 65536,		/* mem_manage.c:812, default_size */
	NREGION	 = 600,			/* enough to force the table to grow */
	NBLOCK	 = 400
};

static void
section3(void)
{
	struct mem_block_header **table;
	struct mem_block_header *hdr, *h;
	struct mem_block_header *allocated[NBLOCK];
	size_t tablesize, oldsize;
	int region, i, k, n, found;
	char *p;

	printf("-- section 3: EDG's block chain over libap's allocator\n");
	forget_all();

	okf(sizeof(struct mem_block_header) == HDRSZ,
		"section 3: sizeof(a_mem_block_header) is %lld, EDG baked %lld",
		(long long)sizeof(struct mem_block_header), (long long)HDRSZ);

	/* init_memory_region: the table is a malloc'd array of pointers */
	tablesize = 2048;
	table = ap_malloc(tablesize * sizeof *table);
	ok(table != NULL, "section 3: table allocation returned null");
	if(table == NULL)
		return;
	memset(table, 0, tablesize * sizeof *table);

	n = 0;
	for(i = 0; i < NBLOCK; i++){
		region = i % 7;		/* a few regions, region 0 busiest */

		/* alloc_new_mem_block's non-PCH arm, verbatim in shape */
		hdr = ap_malloc(BLOCKSZ);
		if(hdr == NULL){
			ok(0, "section 3: ap_malloc(65536) returned null");
			return;
		}
		hdr->malloc_size = BLOCKSZ;
		hdr->start_of_block = (char *)hdr + HDRSZ;
		hdr->after_end_of_block = (char *)hdr + BLOCKSZ;
		hdr->next_avail_in_block = hdr->start_of_block;
		hdr->trimmed = 0;
		hdr->next = table[region];
		table[region] = hdr;
		allocated[n++] = hdr;

		/*
		 * Carve allocations out of the block with a bump pointer,
		 * which is what every `mem_alloc' in the front end does,
		 * and WRITE to them -- an allocator that hands the same
		 * memory out twice is only visible if someone writes.
		 */
		for(k = 0; k < 64; k++){
			if(hdr->next_avail_in_block + 512 > hdr->after_end_of_block)
				break;
			p = hdr->next_avail_in_block;
			hdr->next_avail_in_block = p + 512;
			memset(p, 0x3c, 512);
		}

		/*
		 * ensure_mem_region_table_space: grow the table WHILE the
		 * blocks are live.  This is the interaction the crash
		 * needs -- a realloc of a block that now has live block
		 * headers ABOVE it -- and it is why the table is not simply
		 * allocated big once.
		 *
		 * ***THE CONDITION WAS `(i+1)*3 > tablesize' AND NEVER
		 * FIRED***: `tablesize' starts at 2048 and `NBLOCK' is 400,
		 * so the table never grew and the section measured a
		 * malloc-only pattern while claiming to measure a realloc
		 * one.  The control is what found it -- a grow-in-place
		 * with no top-of-heap test got through untouched.
		 *
		 * Every 40 blocks is MORE often than cpfe grows it for a
		 * small translation unit, and that is deliberate: EDG grows
		 * the table only when a region number outruns it, so a
		 * faithful rate would exercise `realloc' once or not at
		 * all.  The section is asking whether the allocator can
		 * corrupt a header this way, not how often EDG asks it to.
		 */
		if(i % 40 == 39){
			oldsize = tablesize;
			tablesize = tablesize + 2048;
			table = ap_realloc(table, tablesize * sizeof *table);
			if(table == NULL){
				ok(0, "section 3: table ap_realloc returned null");
				return;
			}
			memset(table + oldsize, 0,
				(tablesize - oldsize) * sizeof *table);
		}
	}

	/*
	 * free_memory_region(0), as `mem_manage.c:1207' walks it -- but
	 * CHECKED rather than trusted.  Every pointer reached must be
	 * one this program put there.  That is the assertion the crash
	 * violates, and it is checkable without faulting.
	 */
	for(region = 0; region < 7; region++){
		int walked = 0;
		for(h = table[region]; h != NULL; ){
			struct mem_block_header *next = h->next;

			found = 0;
			for(k = 0; k < n; k++)
				if(allocated[k] == h){
					found = 1;
					break;
				}
			if(!found){
				printf("FAIL  section 3: region %d entry %d is %p, "
					"which this program never allocated\n",
					region, walked, (void *)h);
				failures++;
				checks++;
				break;
			}
			if(h->malloc_size != BLOCKSZ
			|| h->start_of_block != (char *)h + HDRSZ
			|| h->after_end_of_block != (char *)h + BLOCKSZ){
				printf("FAIL  section 3: region %d entry %d (%p) has a "
					"corrupted header: msize %zu start %p end %p\n",
					region, walked, (void *)h, h->malloc_size,
					(void *)h->start_of_block,
					(void *)h->after_end_of_block);
				failures++;
				checks++;
				break;
			}
			walked++;
			if(walked > NBLOCK + 8){
				printf("FAIL  section 3: region %d chain does not end\n", region);
				failures++;
				checks++;
				break;
			}
			h = next;
		}
		if(region == 0)
			printf("      region 0 chain walked %d entries\n", walked);
	}
	checks++;

	for(k = 0; k < n; k++)
		ap_free(allocated[k]);
	ap_free(table);
}

/* ---- 4: the aligned back door ----------------------------------- */

static void
section4(void)
{
	void *p;
	int i;
	static const size_t aligns[] = { 16, 32, 64, 256, 4096 };

	printf("-- section 4: aligned_alloc and free's second header shape\n");

	for(i = 0; i < (int)(sizeof aligns / sizeof aligns[0]); i++){
		p = ap_aligned_alloc(aligns[i], aligns[i] * 4);
		if(p == NULL){
			ok(0, "section 4: ap_aligned_alloc returned null");
			continue;
		}
		okf(((uintptr_t)p & (aligns[i]-1)) == 0,
			"section 4: ap_aligned_alloc gave %llx for alignment %lld",
			(long long)(uintptr_t)p, (long long)aligns[i]);
		memset(p, 0xa5, aligns[i] * 4);
		/*
		 * The point of the section: `free' must RECOGNISE this
		 * block rather than abort.  An abort here is the test
		 * dying, not a FAIL line, so the marker below is what says
		 * the section finished.
		 */
		ap_free(p);
	}
	printf("      section 4 completed without abort\n");
	checks++;
}

/*
 * ***IT TAKES A SECTION NUMBER, AND THE CONTROL IS WHY.***
 *
 * The first version ran all five in one process, and the control --
 * `_malloc_growtop' forced to succeed -- made section 1 hand out live
 * memory, which `free' then noticed as a destroyed `MAGIC' and
 * `abort()'ed on.  **So the control never reached section 3**, the one
 * section that replicates EDG's own chain and the only one whose
 * assertion is the one the crash violates.  *A control that proves
 * section 1 can see a break says nothing about section 3*, and this
 * tree's rule about planting the break in one place is exactly that.
 *
 * A section that can abort therefore gets its own process, the same
 * rule this tree already has for a case that can hang and for a case
 * that can kill the preprocessor.
 */
int
main(int argc, char **argv)
{
	int only = -1;

	setvbuf(stdout, NULL, _IOLBF, 0);

	if(argc > 1)
		only = atoi(argv[1]);

	printf("malloc-xcheck: starting%s", only < 0 ? "\n" : "");
	if(only >= 0)
		printf(" section %d\n", only);

	if(only < 0 || only == 0) section0();
	if(only < 0 || only == 1) section1();
	if(only < 0 || only == 2) section2();
	if(only < 0 || only == 3) section3();
	if(only < 0 || only == 4) section4();

	printf("malloc-xcheck: %d checks, %d failures, break used %zu bytes\n",
		checks, failures, ap_brk_used());
	if(failures == 0)
		printf("PASS\n");
	return failures;
}
