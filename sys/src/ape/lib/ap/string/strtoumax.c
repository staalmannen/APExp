#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>	/* strtoull -- see below; this line IS the fix */

/*
 * strtoumax - convert string to uintmax_t
 * Companion to strtoimax() in strtoll.c.
 * Delegates to strtoull() since uintmax_t is unsigned long long.
 *
 * ------------------------------------------------------------------
 * `<stdlib.h>' WAS NOT HERE, AND THAT WAS THE WHOLE BUG.
 *
 * Neither <inttypes.h> nor <stdint.h> reaches a declaration of
 * `strtoull' (inttypes.h includes only stdint.h, which includes only
 * stdint_arch.h and stdint_generic.h), so the call below had **no
 * prototype in scope** -- implicit `int' return, SIGN-EXTENDED into
 * the uintmax_t. Every value with bit 31 set came back with the top
 * 32 bits lit.
 *
 * `bash''s `printf "%08X" 2604292517' is what measured it, and the
 * chain is closed end to end. `printf.def''s x/X arm does
 *
 *	p = pp = getuintmax ();		// unsigned long p, uintmax_t pp
 *	if (p != pp) ... PRIdMAX/"ll" ... else ... "l" ...
 *
 * and `printfmod-test' section 9 on the VM prints exactly that:
 *
 *	strtoumax("2604292517")   -> FFFFFFFF9B3A59A5
 *	assigned to unsigned long -> 9B3A59A5
 *	bash takes the PRIdMAX/ll branch (p != pp)
 *
 * so bash formatted the sign-extended value with %08llX and printed
 * `FFFFFFFF9B3A59A5'. The same section shows %08X, %08lX and %08llX
 * of the right value all answering `9B3A59A5' -- **libap's printf was
 * innocent**, and four mechanisms were refuted by reading before the
 * probe named this one in a single line.
 *
 * *And the probe reproduced the bug by accident before it measured
 * it*: its own first version omitted <inttypes.h>, so `strtoumax' had
 * no prototype either and it printed `FFFFFFFF9B3A59A5' on glibc --
 * the bash output character for character, from the same cause one
 * level up. The invariant is already in CLAUDE.md; this is what it
 * costs when the missing declaration is a RETURN type rather than an
 * argument.
 */
uintmax_t
strtoumax(const char *nptr, char **endptr, int base)
{
	return (uintmax_t)strtoull(nptr, endptr, base);
}
