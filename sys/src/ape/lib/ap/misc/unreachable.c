#include <stdlib.h>
#include <stdio.h>

/*
 * The implementation behind C23's unreachable() in <stddef.h>.
 *
 * A distinct name, rather than that macro expanding to abort()
 * directly: the macro's whole point is to be usable from any
 * translation unit that includes <stddef.h>, and reaching abort() from
 * there would mean either declaring it in <stddef.h> -- which this
 * compiler rejects as a redeclaration of a _Noreturn function once
 * <stdlib.h> declares it too -- or leaving callers with an implicit
 * declaration.
 *
 * Reaching here is undefined behaviour by the standard, so anything is
 * permitted. Saying so and aborting beats returning quietly: it turns a
 * wrong assumption into a diagnosable failure at the point it happens.
 *
 * _Noreturn on the definition as well as the declaration, the way
 * stdlib/abort.c does it. That pairing is fine; it was two competing
 * declarations that the compiler would not take.
 */
_Noreturn void
__ape_unreachable(void)
{
	fputs("unreachable code reached\n", stderr);
	abort();
}
