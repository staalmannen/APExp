/* mmaptrim-probe.c -- can a mapping be PARTIALLY unmapped here, and
 * does a large mmap come back 2MB-aligned?
 *
 *	pcc -o mmaptrim-probe mmaptrim-probe.c && ./mmaptrim-probe
 *	./mmaptrim-probe 3          # the head-trim case, run alone
 *
 * ***A PROBE: REPORT WHAT IT PRINTS, DO NOT ASSERT IT.*** Two of its
 * four sections can KILL THE PROCESS, which is why it takes an argument
 * -- see the ordering note at the bottom.
 *
 * **It calls `_mmapmark()', so it will not LINK against a libap
 * predating `p9_munmap's partial-unmap arm.** That matters more here
 * than for a test: a probe reports what it sees as the PLATFORM's
 * answer, so one built against stale library code tells a lie that
 * reads like a measurement.
 *
 * WHERE IT CAME FROM. PHP's Zend memory manager allocates in 2MB
 * CHUNKS that must be 2MB-ALIGNED (`ZEND_MM_CHUNK_SIZE'), and
 * `Zend/zend_alloc.c's `zend_mm_chunk_alloc_int' gets that alignment
 * the way every POSIX allocator does: map MORE than it needs and
 * unmap the overhang.
 *
 *	ptr = mmap(size + alignment - REAL_PAGE_SIZE);
 *	offset = ALIGNED_OFFSET(ptr, alignment);
 *	if (offset != 0) {
 *		offset = alignment - offset;
 *		munmap(ptr, offset);              <- HEAD trim
 *		ptr = (char*)ptr + offset;
 *		alignment -= offset;
 *	}
 *	if (alignment > REAL_PAGE_SIZE)
 *		munmap((char*)ptr + size, alignment - REAL_PAGE_SIZE);
 *	                                          <- TAIL trim
 *
 * `zend_mm_chunk_truncate' is a third tail trim, on a LIVE chunk.
 *
 * WHY THAT WAS A QUESTION ON THIS MACHINE. libap's mmap is emulated:
 * `plan9/__p9_syscall.c's `p9_mmap_impl' uses `_SEGATTACH' for
 * anything at or above `SEG_THRESHOLD' (1MB) and `malloc' below it, and
 * `p9_munmap' USED TO look the address up in a table keyed on the
 * mapping's START and nothing else. So of the three calls above:
 *
 *   - the HEAD trim passes the start address with a SHORT length, which
 *     MATCHED the entry, so `_SEGDETACH' took the whole segment -- and
 *     the caller then went on using `ptr + offset' inside it;
 *   - the TAIL trims pass an INTERIOR address, which matched nothing,
 *     and the fallback was `_SEGDETACH(addr)' -- and Plan 9's segdetach
 *     takes any address IN a segment and detaches ALL of it.
 *
 * *Both routes to the same silent disaster*, neither of them a failure
 * the caller could see. `p9_munmap' has a partial-unmap arm now: a trim
 * NARROWS the entry and frees nothing, and the segment goes back only
 * when the last of the mapping is unmapped. Sections 2 and 3 are
 * therefore REGRESSION CASES with a predicted answer -- both must
 * survive -- and only section 0 is still an open question.
 *
 * SECTION 0 IS THE ONE THAT MATTERS, because the trimming path is only
 * reached when a mapping comes back MISALIGNED. If `_SEGATTACH' already
 * returns 2MB-aligned addresses -- amd64 9front maps in
 * `PTEPERTAB * BY2PG' units, which is 512 * 4096 = 2MB, so it is at
 * least plausible -- then `zend_mm_chunk_alloc_int' takes its FIRST
 * branch every time, nothing is trimmed, and nothing is leaked either.
 * *A port can be saved by an alignment it did not ask for.* Eight
 * mappings rather than one, because a single aligned answer could be
 * luck.
 *
 *   8 of 8 aligned -> the trims never run; the mmap path costs nothing.
 *   some misaligned -> the trims run and WORK, but each trimmed chunk
 *                      holds its over-sized segment until it is freed,
 *                      so the cost is address space. The fallbacks if
 *                      that bites are a Zend storage handler or
 *                      `USE_ZEND_ALLOC=0'.
 *
 * THE HOST IS THE CONTROL, AND IT HAS BEEN RUN. Built with gcc on
 * Linux: sections 2 and 3 both SURVIVE, so the probe's own mechanics
 * are sound and a fault on the VM is the platform's answer rather than
 * a bug in this file. *And the host run says which section decides.*
 * Section 0 is 8 of 8 aligned there -- which is WHY php works on Linux,
 * since `zend_mm_chunk_alloc_int' then takes its first branch -- while
 * **section 1's over-sized mapping is MISALIGNED on Linux too**. So
 * section 1 is information about the trim SIZE and nothing more: it
 * cannot clear or condemn the port either way, and only section 0 can.
 *
 * ORDERING. Sections 0 and 1 cannot fault and always run. Then exactly
 * ONE destructive section runs: no argument gives section 2 (tail),
 * `3' gives section 3 (head). They are not both in one run because
 * *a section that can kill the process hides every section after it* --
 * the same rule this tree has for cases that can hang, and the reason
 * `cppskip-probe' is a separate file from `cppelif-probe'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define CHUNK	(2*1024*1024)		/* ZEND_MM_CHUNK_SIZE */
#define PAGE	4096			/* REAL_PAGE_SIZE on amd64 */
#define OVER	(CHUNK + CHUNK - PAGE)	/* what zend over-maps */

#define ULL(p)	((unsigned long long)(unsigned long)(p))

#ifndef __linux__
extern int _mmapmark(void);	/* see the note at the top */
#endif

static void *
map(size_t len)
{
	void *p = mmap(0, len, PROT_READ|PROT_WRITE,
	               MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED)
		return 0;
	return p;
}

int
main(int argc, char **argv)
{
	void *p[8];
	void *q;
	char *c;
	size_t off;
	int i, aligned, which;

	/* unbuffered: a section that faults must still have printed. */
	setvbuf(stdout, (char*)0, _IONBF, 0);

	which = 2;
	if(argc > 1)
		which = atoi(argv[1]);

	printf("mmaptrim-probe: starting, chunk=%d over=%d\n", CHUNK, OVER);
#ifndef __linux__
	printf("mmaptrim-probe: _mmapmark = %d\n", _mmapmark());
#endif

	/* ---- section 0: what alignment does a 2MB mmap give? ---- */
	printf("\n-- section 0: eight %d-byte mappings\n", CHUNK);
	aligned = 0;
	for(i = 0; i < 8; i++){
		p[i] = map(CHUNK);
		if(p[i] == 0){
			printf("  [%d] mmap failed\n", i);
			continue;
		}
		off = ULL(p[i]) & (CHUNK-1);
		if(off == 0)
			aligned++;
		printf("  [%d] %#llx  offset-in-2MB %#llx  %s\n",
		       i, ULL(p[i]), (unsigned long long)off,
		       off == 0 ? "ALIGNED" : "misaligned");
	}
	printf("  %d of 8 were 2MB-aligned\n", aligned);
	if(aligned == 8)
		printf("  -> zend_mm_chunk_alloc_int would never trim\n");
	else
		printf("  -> zend_mm_chunk_alloc_int WOULD trim; see 2 and 3\n");
	for(i = 0; i < 8; i++)
		if(p[i] != 0)
			munmap(p[i], CHUNK);

	/* ---- section 1: the over-sized mapping zend actually asks for ---- */
	printf("\n-- section 1: one %d-byte mapping\n", OVER);
	q = map(OVER);
	if(q == 0)
		printf("  mmap failed -- %d bytes is more than segattach gives\n",
		       OVER);
	else {
		off = ULL(q) & (CHUNK-1);
		printf("  %#llx  offset-in-2MB %#llx  head trim would be %#llx\n",
		       ULL(q), (unsigned long long)off,
		       (unsigned long long)(off ? CHUNK - off : 0));
		munmap(q, OVER);
	}

	/* ---- the destructive pair ---- */
	if(which == 3){
		printf("\n-- section 3: HEAD trim, munmap(ptr, offset)\n");
		q = map(OVER);
		if(q == 0){
			printf("  mmap failed, nothing to say\n");
			return 0;
		}
		off = ULL(q) & (CHUNK-1);
		if(off == 0)
			off = PAGE;		/* force the case anyway */
		else
			off = CHUNK - off;
		memset(q, 0x5a, OVER);
		printf("  mapped %#llx, trimming %#llx off the front\n",
		       ULL(q), (unsigned long long)off);
		printf("  about to munmap(%#llx, %#llx)\n",
		       ULL(q), (unsigned long long)off);
		munmap(q, off);
		printf("  munmap returned\n");
		c = (char*)q + off;
		printf("  about to read the KEPT range at %#llx\n", ULL(c));
		printf("  [0]=%#x [%d]=%#x [%d]=%#x\n",
		       c[0] & 0xff, CHUNK/2, c[CHUNK/2] & 0xff,
		       CHUNK-1, c[CHUNK-1] & 0xff);
		printf("  the kept range SURVIVED the head trim\n");
		return 0;
	}

	printf("\n-- section 2: TAIL trim, munmap(ptr+size, rest)\n");
	q = map(OVER);
	if(q == 0){
		printf("  mmap failed, nothing to say\n");
		return 0;
	}
	memset(q, 0xa5, OVER);
	printf("  mapped %#llx, trimming %#llx off the end at %#llx\n",
	       ULL(q), (unsigned long long)(OVER - CHUNK),
	       ULL((char*)q + CHUNK));
	printf("  about to munmap(%#llx, %#llx)\n",
	       ULL((char*)q + CHUNK), (unsigned long long)(OVER - CHUNK));
	munmap((char*)q + CHUNK, OVER - CHUNK);
	printf("  munmap returned\n");
	c = (char*)q;
	printf("  about to read the KEPT range at %#llx\n", ULL(c));
	printf("  [0]=%#x [%d]=%#x [%d]=%#x\n",
	       c[0] & 0xff, CHUNK/2, c[CHUNK/2] & 0xff,
	       CHUNK-1, c[CHUNK-1] & 0xff);
	printf("  the kept range SURVIVED the tail trim\n");
	printf("\n  now run `mmaptrim-probe 3' for the head trim\n");
	return 0;
}
