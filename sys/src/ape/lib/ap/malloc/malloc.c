#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <lock.h>
#include "malloc_impl.h"

Arena __malloc_arena;

/*
 * Take n bytes from the break, 16-aligned. See malloc_impl.h for why
 * the alignment is done on the break rather than inside the block.
 * Called with the arena locked.
 */
void*
_malloc_brk(size_t n)
{
	uintptr_t cur, gap;
	char *p;

	cur = (uintptr_t)sbrk(0);
	if(cur == (uintptr_t)-1)
		return nil;
	gap = (-cur) & 15;

	p = sbrk(gap + n);
	if(p == (void*)-1)
		return nil;
	return p + gap;
}

/*
 * Grow a block in place rather than allocate-copy-free, when it is the
 * last thing on the heap.
 *
 * THIS IS THE WHOLE OF THE INTERPRETER PROBLEM. realloc was
 * malloc-copy-free unconditionally, so growing one buffer by doubling
 * -- which is how every interpreter builds a big string -- walked the
 * size classes and stranded a dead block in each one. Measured on the
 * host: building a 32 MB string that way took 62 MB from the kernel,
 * and 1 KB -> 1 MB took 2005575 bytes for a megabyte of string.
 *
 * The strands are not lost forever; the NEXT identical growth reuses
 * them class for class, which is why a second 32 MB string cost zero.
 * It is the PEAK that kills a small VM, and the peak is twice what it
 * needs to be.
 *
 * MEMORY ALREADY OWNED BEATS MEMORY FROM THE KERNEL, so a free block
 * of the target class is taken first and this returns 0. Without that
 * test the heap got BIGGER, not smaller: extending at the break walks
 * straight past the 32 MB block the previous string left on the free
 * list, and three strings in a row cost 97 MB where the unfixed
 * allocator cost 64. Measured, not reasoned -- it is the one thing in
 * this change that went the wrong way, and only the bench said so.
 *
 * Asking the kernel for the current break rather than remembering it
 * is deliberate. If anything else in the program has called sbrk since
 * -- and sbrk is a public entry point -- a remembered top would be
 * stale and LOWER than the real break, so the address test would pass
 * while the memory sbrk hands back is not contiguous with bp. That is
 * silent heap corruption. The syscall costs less than the memmove it
 * replaces.
 */
int
_malloc_growtop(Bucket *bp, int pow)
{
	size_t have, want;
	int ok;

	have = BLKSZ(bp->size);
	want = BLKSZ(pow);
	ok = 0;

	lock(&__malloc_arena);
	if(__malloc_arena.btab[pow] == nil
	&& (char*)bp + have == (char*)sbrk(0)
	&& sbrk(want - have) != (void*)-1){
		bp->size = pow;
		ok = 1;
	}
	unlock(&__malloc_arena);

	return ok;
}

void*
malloc(size_t size)
{
	uintptr_t next;
	int pow, n;
	size_t bsize;
	Bucket *bp, *nbp;

	for(pow = 1; pow < MAX2SIZE; pow++) {
		if(size <= ((size_t)1<<pow))
			goto good;
	}

	return nil;
good:
	/* Allocate off this list */
	lock(&__malloc_arena);
	bp = __malloc_arena.btab[pow];
	if(bp) {
		__malloc_arena.btab[pow] = bp->next;
		unlock(&__malloc_arena);

		if(bp->magic != 0)
			abort();

		bp->next = nil;
		bp->magic = MAGIC;
		return bp->data;
	}

	bsize = BLKSZ(pow);

	if(pow < CUTOFF) {
		n = (CUTOFF-pow)+2;
		bp = _malloc_brk(bsize*n);
		if(bp == nil){
			unlock(&__malloc_arena);
			return nil;
		}

		next = (uintptr_t)bp+bsize;
		nbp = (Bucket*)next;
		__malloc_arena.btab[pow] = nbp;
		for(n -= 2; n; n--) {
			next = (uintptr_t)nbp+bsize;
			nbp->next = (Bucket*)next;
			nbp->size = pow;
			nbp->magic = 0;
			nbp = nbp->next;
		}
		nbp->size = pow;
		nbp->magic = 0;
		nbp->next = nil;
	}
	else {
		bp = _malloc_brk(bsize);
		if(bp == nil){
			unlock(&__malloc_arena);
			return nil;
		}
	}
	unlock(&__malloc_arena);

	bp->size = pow;
	bp->next = nil;
	bp->magic = MAGIC;

	return bp->data;
}
