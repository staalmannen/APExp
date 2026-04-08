#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * reallocarray(ptr, m, n) — realloc(ptr, m*n) with overflow check.
 *
 * The musl version used "-1/n" which relies on unsigned wraparound.
 * Replaced with a portable SIZE_MAX/n check that the Plan9 compiler
 * handles cleanly without warnings.
 */
void *
reallocarray(void *ptr, size_t m, size_t n)
{
	if(n != 0 && m > (size_t)-1 / n) {
		errno = ENOMEM;
		return 0;
	}
	return realloc(ptr, m * n);
}
