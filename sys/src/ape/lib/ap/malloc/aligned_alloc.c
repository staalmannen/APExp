#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include "malloc_align.h"

/*
 * aligned_alloc(alignment, size) — C11 §7.22.3.1
 *
 * APE malloc guarantees 16-byte alignment (datoff = 16).
 *
 * Strategy for alignment > 16:
 *
 * 1. Retry loop (MAX_TRIES attempts): allocate a block large enough
 *    for size bytes and return it only if malloc happened to return
 *    an alignment-aligned pointer.  Since APE uses power-of-two
 *    bucket sizes, common SIMD alignments (32, 64) succeed within
 *    1-2 tries.
 *
 * 2. Safe fallback: over-allocate, find the aligned address within
 *    the block, and write an ALIGN_MAGIC sentinel at (aligned - DATOFF).
 *    free() in free.c detects ALIGN_MAGIC and redirects to the
 *    original malloc pointer, so free() works correctly on the result.
 *
 * The fallback adds DATOFF (16) + alignment - 1 bytes of overhead.
 */

#define MALLOC_ALIGN  16
#define MAX_TRIES     16

void *
aligned_alloc(size_t alignment, size_t size)
{
	void *raw, *aligned;
	size_t i, total;

	if(alignment == 0 || (alignment & (alignment - 1)) != 0) {
		errno = EINVAL;
		return 0;
	}
	if(size == 0)
		return malloc(1);

	if(alignment <= MALLOC_ALIGN)
		return malloc(size);

	/* retry loop: fast path for common alignments */
	for(i = 0; i < MAX_TRIES; i++) {
		raw = malloc(size + alignment - MALLOC_ALIGN);
		if(raw == 0)
			return 0;
		if(((uintptr_t)raw & (alignment - 1)) == 0)
			return raw;   /* aligned; free() works directly */
		free(raw);
	}

	/*
	 * Safe fallback: allocate DATOFF + alignment - 1 extra bytes so we
	 * can always find an aligned address with room for the sentinel.
	 *
	 * Layout (raw = malloc return):
	 *   raw ... [DATOFF bytes of sentinel] [aligned] ... [size bytes]
	 *
	 * We need: aligned >= raw + DATOFF  (room for sentinel before it)
	 *          aligned % alignment == 0
	 *          aligned + size <= raw + total
	 */
	total = size + DATOFF + alignment - 1;
	raw = malloc(total);
	if(raw == 0)
		return 0;

	/* first alignment-aligned address at or after (raw + DATOFF) */
	aligned = (void *)(((uintptr_t)raw + DATOFF + alignment - 1)
	                   & ~(uintptr_t)(alignment - 1));

	/* write the sentinel so free() can find raw */
	malign_place(aligned, raw);
	return aligned;
}
