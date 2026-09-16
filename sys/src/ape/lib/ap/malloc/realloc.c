#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <lock.h>
#include "malloc_impl.h"

void*
realloc(void *ptr, size_t n)
{
	void *new;
	size_t osize;
	int pow;
	Bucket *bp;

	if(ptr == nil)
		return malloc(n);

	/* Find the start of the structure */
	bp = (Bucket*)((uintptr_t)ptr - datoff);

	if(bp->magic != MAGIC)
		abort();
	if(bp->size <= 0 || bp->size >= MAX2SIZE)
		abort();

	/* enough space in this bucket */
	osize = (size_t)1<<bp->size;
	if(n <= osize)
		return ptr;

	/* the class the new size wants */
	for(pow = bp->size+1; pow < MAX2SIZE; pow++)
		if(n <= ((size_t)1<<pow))
			break;
	if(pow >= MAX2SIZE)
		return nil;

	/*
	 * A buffer grown by doubling is nearly always the most recent
	 * thing on the heap, so try to extend it where it lies before
	 * paying for a new block, a copy, and a dead block stranded on
	 * the old class's free list. See _malloc_growtop.
	 */
	if(_malloc_growtop(bp, pow))
		return ptr;

	new = malloc(n);
	if(new == nil)
		return nil;

	memmove(new, ptr, osize);
	free(ptr);

	return new;
}
