#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include "malloc_align.h"

/*
 * posix_memalign — POSIX aligned allocation, freeable with free().
 *
 * Uses the same retry-then-safe-fallback strategy as aligned_alloc.c.
 * See malloc_align.h for the ALIGN_MAGIC sentinel mechanism that
 * makes the fallback pointer correctly handled by free().
 */

#define MALLOC_ALIGN 16
#define MAX_TRIES    16

int
posix_memalign(void **memptr, size_t alignment, size_t size)
{
	void *raw, *aligned;
	size_t i, total;

	if(memptr == NULL)
		return EINVAL;
	if(alignment < sizeof(void*) || (alignment & (alignment - 1)) != 0)
		return EINVAL;

	if(size == 0) {
		*memptr = NULL;
		return 0;
	}

	if(alignment <= MALLOC_ALIGN) {
		raw = malloc(size);
		if(raw == NULL)
			return ENOMEM;
		*memptr = raw;
		return 0;
	}

	/* retry loop: fast path for common alignments */
	for(i = 0; i < MAX_TRIES; i++) {
		raw = malloc(size + alignment - MALLOC_ALIGN);
		if(raw == NULL)
			return ENOMEM;
		if(((uintptr_t)raw & (alignment - 1)) == 0) {
			*memptr = raw;
			return 0;
		}
		free(raw);
	}

	/* safe fallback via ALIGN_MAGIC sentinel */
	total = size + DATOFF + alignment - 1;
	raw = malloc(total);
	if(raw == NULL)
		return ENOMEM;

	aligned = (void *)(((uintptr_t)raw + DATOFF + alignment - 1)
	                   & ~(uintptr_t)(alignment - 1));
	malign_place(aligned, raw);
	*memptr = aligned;
	return 0;
}
