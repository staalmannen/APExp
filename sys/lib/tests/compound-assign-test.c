/*
 * compound-assign-test.c -- mixed-signedness compound assignment.
 *
 * C99 6.5.16.2p3: "A compound assignment of the form E1 op= E2 is
 * equivalent to the simple assignment expression E1 = E1 op (E2)",
 * bar evaluating E1 once. So the usual arithmetic conversions apply to
 * "E1 op (E2)" first, and only then is the result converted back to
 * the type of E1. When E1 is vlong and E2 is uvlong, the operation is
 * therefore UNSIGNED.
 *
 * This came out of cpp's #if evaluator, which had
 *
 *   vlong rv1; ... rv1 /= (uvlong)rv2;
 *
 * to divide unsigned. It divided signed, so UINTMAX_MAX / 2 evaluated
 * to 0 rather than INTMAX_MAX, and GNU tar's
 *
 *   #if ! (INTMAX_MAX <= UINTMAX_MAX / 2)
 *   # error "sysinttostr: uintmax_t cannot represent all intmax_t values"
 *
 * fired. cpp no longer relies on the implicit conversion, so tar builds
 * either way; this is here to say whether the compiler itself is right.
 *
 * The last case is the interesting comparison: the same operands via a
 * simple assignment work. If that one passes and the compound ones
 * fail, the fault is specifically in how op= converts its operands --
 * most likely converting E2 to the type of E1 before operating, rather
 * than after.
 *
 * Build and run:  pcc -o compound-assign-test compound-assign-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>

typedef long long vlong;
typedef unsigned long long uvlong;

static int failures;

static void
check(const char *what, uvlong got, uvlong want)
{
	if (got == want)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s: got %llu, want %llu\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

int
main(void)
{
	vlong rv1;
	vlong rv2;
	uvlong u;

	/* -1 as a vlong is UINTMAX_MAX as a uvlong. */
	rv1 = -1;
	rv2 = 2;

	rv1 /= (uvlong)rv2;
	check("vlong /= (uvlong): -1 / 2", (uvlong)rv1, 0x7fffffffffffffffULL);

	rv1 = -1;
	rv2 = 2;
	rv1 %= (uvlong)rv2;
	check("vlong %= (uvlong): -1 % 2", (uvlong)rv1, 1);

	rv1 = -1;
	rv2 = 2;
	rv1 = (vlong)((uvlong)rv1 / (uvlong)rv2);
	check("vlong = (uvlong)/(uvlong) [both cast]",
	      (uvlong)rv1, 0x7fffffffffffffffULL);

	/* Simple assignment, one operand cast: the conversions should make
	   the whole division unsigned here too. This is the case cpp's
	   comparisons rely on, and it was working. */
	rv1 = -1;
	rv2 = 2;
	u = (uvlong)rv1 / rv2;
	check("uvlong = (uvlong)vlong / vlong [simple assign]",
	      u, 0x7fffffffffffffffULL);

	/* The comparison form, for completeness: this one was already
	   right, which is why cpp's <= worked while its / did not. */
	rv1 = -1;
	check("(uvlong)vlong > 0", (uvlong)((uvlong)rv1 > 0), 1);

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
