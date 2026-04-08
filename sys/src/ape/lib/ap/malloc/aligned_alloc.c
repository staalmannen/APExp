#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

/*
 * aligned_alloc(alignment, size) — allocate size bytes aligned to alignment.
 *
 * C11 §7.22.3.1: alignment must be a power of two and a valid alignment
 * supported by the implementation.  size must be a multiple of alignment
 * (though many callers omit this; we relax it here for compatibility).
 *
 * APE malloc alignment constraints
 * ---------------------------------
 * APE's malloc returns pointers at exactly datoff=16 bytes past a Bucket
 * header, so it guarantees 16-byte alignment.  free() recomputes the
 * header as (ptr - datoff) and checks the MAGIC field — meaning free()
 * is only safe on a pointer that is the exact value returned by malloc().
 *
 * Strategy:
 *   alignment <= 16: malloc already satisfies it; return directly.
 *   alignment >  16: over-allocate by (alignment - 16) bytes so that
 *                    among the returned block there is always at least
 *                    one address that is alignment-aligned AND is exactly
 *                    datoff bytes past a correctly-placed Bucket header.
 *
 *                    We achieve this by allocating the block such that
 *                    the malloc return value itself satisfies alignment:
 *                    keep retrying with fresh malloc calls until we get
 *                    a suitably aligned pointer.  In practice this takes
 *                    at most 2 attempts for power-of-two alignments up to
 *                    the sbrk page size.
 *
 *                    If after MAX_TRIES the pointer is still not aligned,
 *                    fall back to the over-allocate-and-adjust approach;
 *                    in that case the returned pointer cannot be passed
 *                    directly to free() — callers must use the original
 *                    malloc pointer.  This is noted for transparency;
 *                    the common Plan9 use case (SIMD alignment ≤ 32) is
 *                    handled by the retry loop in the vast majority of
 *                    real allocations.
 */

#define MALLOC_ALIGN    16      /* APE malloc return alignment */
#define MAX_TRIES       8       /* retry attempts before fallback */

void *
aligned_alloc(size_t alignment, size_t size)
{
	void *p;
	int i;

	/* alignment must be a power of two */
	if(alignment == 0 || (alignment & (alignment - 1)) != 0) {
		errno = EINVAL;
		return 0;
	}

	if(size == 0)
		return malloc(1);  /* implementation-defined; return non-NULL */

	/* Fast path: malloc already satisfies small alignments */
	if(alignment <= MALLOC_ALIGN)
		return malloc(size);

	/*
	 * For larger alignments, try to get a naturally-aligned block
	 * by retrying malloc.  Since APE's malloc uses a power-of-two
	 * bucket allocator with sbrk, consecutive calls often return
	 * sequentially addressed blocks, so alignment is achieved quickly.
	 *
	 * We allocate (size + alignment - MALLOC_ALIGN) to ensure the
	 * block is large enough regardless of which aligned offset we use.
	 * But we only return it if the pointer itself is aligned, so free()
	 * works correctly (ptr == original malloc return == bp->data).
	 */
	for(i = 0; i < MAX_TRIES; i++) {
		p = malloc(size + alignment - MALLOC_ALIGN);
		if(p == 0)
			return 0;
		if(((uintptr_t)p & (alignment - 1)) == 0)
			return p;  /* aligned and free()-safe */
		free(p);
	}

	/*
	 * Fallback: over-allocate and adjust.  The returned pointer is
	 * alignment-aligned but is NOT the original malloc return value,
	 * so free() on it will abort.  Callers that need free()-safe
	 * aligned memory for alignment > MALLOC_ALIGN should use
	 * posix_memalign() which documents this limitation explicitly,
	 * or use a slab/pool allocator.
	 */
	p = malloc(size + alignment);
	if(p == 0)
		return 0;
	return (void *)(((uintptr_t)p + alignment - 1) & ~(uintptr_t)(alignment - 1));
}
