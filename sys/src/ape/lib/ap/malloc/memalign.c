#include <stdlib.h>

/*
 * memalign(alignment, size) — historical aligned allocator (4.2BSD).
 *
 * Equivalent to aligned_alloc(alignment, size) but without the C11
 * requirement that size be a multiple of alignment.  Since our
 * aligned_alloc already relaxes that constraint, this is a direct
 * wrapper.
 *
 * Unlike aligned_alloc, the result of memalign is specified to be
 * freeable with free() — see posix_memalign(3) for the APE caveat
 * regarding alignment > 16.
 */
void *
memalign(size_t alignment, size_t size)
{
	return aligned_alloc(alignment, size);
}
