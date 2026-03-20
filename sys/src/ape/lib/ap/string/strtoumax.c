#include <inttypes.h>
#include <stdint.h>

/*
 * strtoumax - convert string to uintmax_t
 * Companion to strtoimax() in strtoll.c.
 * Delegates to strtoull() since uintmax_t is unsigned long long.
 */
uintmax_t
strtoumax(const char *nptr, char **endptr, int base)
{
	return (uintmax_t)strtoull(nptr, endptr, base);
}
