/*
 * FD_ZERO, as a function.
 *
 * It was a macro clearing three words BY NAME, and that is the shape
 * that cannot be right: the struct's size is the compiler's business
 * (kencc padded `long fds_bits[3]` to sixteen bytes, measured), so a
 * macro naming its elements leaves whatever the caller's stack held in
 * anything it does not know about. A select would then act on a
 * descriptor nobody asked about -- an INVENTED event rather than a
 * missed one, and the harder of the two to ever attribute.
 *
 * Clearing the whole object bytewise is the only version that stays
 * right when the width changes, and a function is the only thing that
 * can: `sizeof` inside the macro would have worked too, but not as one
 * expression, and FD_ZERO has always been usable as one.
 *
 * sys/lib/tests/select-test.c section 11 asserts it against a struct
 * pre-filled with 0xff, so a word cleared by luck cannot pass.
 */
#include <string.h>
#include <sys/select.h>

void
__fd_zero(fd_set *p)
{
	memset(p, 0, sizeof *p);
}
