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

	/* *= shares the OASDIV case in cc/com.c, so it takes the same
	   path. Signed and unsigned multiply agree in the low bits, so
	   this cannot tell them apart -- it is here to catch the block
	   being broken outright. */
	rv1 = -1;
	rv2 = 3;
	rv1 *= (uvlong)rv2;
	check("vlong *= (uvlong): -1 * 3", (uvlong)rv1, (uvlong)(vlong)-3);

	/* Shifts have their own block and were already right: C99
	   6.5.7p3 gives the result the promoted LEFT operand's type, so
	   reading the lvalue's type there is correct. Controls. */
	rv1 = -1;
	rv1 >>= 1;
	check("vlong >>= 1 stays arithmetic", (uvlong)rv1, (uvlong)(vlong)-1);

	u = ~0ULL;
	u >>= 1;
	check("uvlong >>= 1 is logical", u, 0x7fffffffffffffffULL);

	/*
	 * Not counted, and expected to differ: a KNOWN LIMITATION beyond
	 * the signedness fix.
	 *
	 * C99 promotes the long to uvlong, divides in 64 bits unsigned,
	 * then converts back, giving -1. kencc performs a compound
	 * assignment in the lvalue's own width, casting the right operand
	 * down to long first, which divides 0xffffffff by 2 and gives
	 * 2147483647. Making this agree means rewriting E1 op= E2 as
	 * E1 = (T1)(E1 op E2), which is a much larger change than
	 * choosing the right opcode.
	 */
	{
		long lv = -1;
		uvlong d = 2;
		unsigned long got, want;

		/* What C requires: promote lv to uvlong, divide there,
		   convert the result back to long. Computed rather than
		   written out, because long is 64-bit on an LP64 host and
		   32-bit on Plan 9 amd64, and only the narrower case can
		   differ. */
		want = (unsigned long)(long)(((uvlong)(long)-1) / 2);

		lv /= d;
		got = (unsigned long)lv;
		printf("%s  long /= uvlong: got %lu, C requires %lu%s\n",
		       got == want ? "note " : "KNOWN",
		       got, want,
		       got == want ? " (widths equal here, nothing to truncate)"
				   : " -- the width limitation described above");
	}

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
