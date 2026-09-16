#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <lock.h>
#include "malloc_impl.h"
#include "malloc_align.h"

void
free(void *ptr)
{
	Bucket *bp, **l;

	if(ptr == nil)
		return;

	/* Find the start of the structure */
	bp = (Bucket*)((uintptr_t)ptr - datoff);

	if(bp->magic != MAGIC) {
		/* aligned-fallback block: header written by aligned_alloc/posix_memalign */
		if(malign_check(bp)) {
			free(malign_orig(bp));
			return;
		}
		abort();
	}
	if(bp->size <= 0 || bp->size >= MAX2SIZE)
		abort();

	bp->magic = 0;
	l = &__malloc_arena.btab[bp->size];
	lock(&__malloc_arena);
	bp->next = *l;
	*l = bp;
	unlock(&__malloc_arena);
}
