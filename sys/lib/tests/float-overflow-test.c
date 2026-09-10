/*
 * Does a double just past the float range round to infinity?
 *
 *	pcc -o float-overflow-test float-overflow-test.c && ./float-overflow-test
 *
 * From Tcl's own suite, binary-53.25 and binary-53.26:
 *
 *	binary scan [binary format H* 47effffff0000001] Q round_to_inf
 *	binary scan [binary format R $round_to_inf] R inf1
 *	expr {$inf1 eq Inf}		;# answered 0, wants 1
 *
 * "binary format R" is a 32-bit float, so that is a double -> float
 * conversion and a read back. The constant is not arbitrary: FLT_MAX is
 * 2**128 - 2**104, the next float up is infinity, and the midpoint
 * between them is 2**128 - 2**103, which is exactly 0x47EFFFFFF0000000.
 * The test value is that **plus one ulp of a double**, so it is strictly
 * above the midpoint and round-to-nearest must give infinity with no tie
 * to break. 0x47EFFFFFEFFFFFFF, one ulp below, must give FLT_MAX.
 *
 * Three separate things could produce "0" there and they want different
 * fixes, so ask them separately:
 *
 *   1. the double -> float conversion itself (6c's CVTSD2SS, or the
 *      constant-folded path in cc/scon.c -- note the sign-of-zero work
 *      found ieeedtof in every *l/obj.c mishandling the boundary);
 *   2. isinf() and the INFINITY/HUGE_VAL macros, which <math.h> got
 *      wrong once already -- INFINITY used to be DBL_MAX, so
 *      isinf(INFINITY) was false;
 *   3. printing, since Tcl's "eq Inf" is a STRING comparison: it is
 *      really asking whether Tcl's double-to-string gives exactly "Inf",
 *      and Tcl reaches that spelling through TclIsInfinite() -> isinf().
 *
 * Every case here is required of any conforming C implementation, so it
 * passes on gcc -- which is how it was checked.
 */

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>

static int fail = 0;

static void
ok(int cond, const char *what)
{
	if(cond)
		printf("  PASS %s\n", what);
	else {
		printf("  FAIL %s\n", what);
		fail++;
	}
}

/* Read a double out of its bit pattern, and a float's bits back out. */
static double
d_from_bits(unsigned long long b)
{
	union { unsigned long long u; double d; } x;

	x.u = b;
	return x.d;
}

static unsigned long
f_bits(float f)
{
	union { unsigned long u; float f; } x;

	x.f = f;
	return x.u;
}

int
main(void)
{
	double above, below, big;
	float f;
	volatile double vd;
	char buf[64];

	printf("--- 1. double -> float at the overflow boundary ---\n");
	printf("  (FLT_MAX = %.17g, 2**128 = %.17g)\n",
		(double)FLT_MAX, d_from_bits(0x47F0000000000000ULL));

	/* Strictly above the midpoint: must become +Inf. */
	above = d_from_bits(0x47EFFFFFF0000001ULL);
	f = (float)above;
	printf("  (float)%.17g -> bits %08lx\n", above, f_bits(f));
	ok(f_bits(f) == 0x7F800000UL, "just past the midpoint gives +Inf");

	/* And the negative of it. */
	above = d_from_bits(0xC7EFFFFFF0000001ULL);
	f = (float)above;
	printf("  (float)%.17g -> bits %08lx\n", above, f_bits(f));
	ok(f_bits(f) == 0xFF800000UL, "and the negative gives -Inf");

	/*
	 * One ulp the other side of the midpoint must NOT overflow. This is
	 * the case that tells "the conversion rounds correctly" apart from
	 * "the conversion saturates to infinity too eagerly", which would
	 * pass the two above for the wrong reason.
	 */
	below = d_from_bits(0x47EFFFFFEFFFFFFFULL);
	f = (float)below;
	printf("  (float)%.17g -> bits %08lx\n", below, f_bits(f));
	ok(f_bits(f) == 0x7F7FFFFFUL, "just below the midpoint gives FLT_MAX");

	/* Something plainly out of range. */
	big = 1e300;
	f = (float)big;
	ok(f_bits(f) == 0x7F800000UL, "1e300 gives +Inf");

	/* And a value that fits, so the whole conversion is not just Inf. */
	f = (float)0.5;
	ok(f_bits(f) == 0x3F000000UL, "0.5 survives the conversion");

	printf("\n--- 2. isinf, INFINITY and HUGE_VAL ---\n");
	/*
	 * <math.h> defined INFINITY as DBL_MAX once. isinf(INFINITY) was
	 * false, and exp(1000) == INFINITY was false too -- see the
	 * fparith-test.c notes. Kept here because Tcl's Inf spelling goes
	 * through isinf().
	 */
	ok(isinf(INFINITY), "isinf(INFINITY)");
	ok(isinf(HUGE_VAL), "isinf(HUGE_VAL)");
	ok(INFINITY > DBL_MAX, "INFINITY exceeds DBL_MAX");
	ok(!isinf(DBL_MAX), "isinf(DBL_MAX) is false");

	vd = (double)d_from_bits(0x7FF0000000000000ULL);
	ok(isinf(vd), "isinf of a hand-built +Inf");
	ok(vd > 0, "and it is positive");

	vd = (double)d_from_bits(0xFFF0000000000000ULL);
	ok(isinf(vd), "isinf of a hand-built -Inf");
	ok(vd < 0, "and it is negative");

	/*
	 * The float that came out of the conversion above, widened back to
	 * double, is what Tcl's "binary scan R" produces and then prints.
	 */
	f = (float)d_from_bits(0x47EFFFFFF0000001ULL);
	vd = (double)f;
	ok(isinf(vd), "the converted float widens back to an infinite double");

	printf("\n--- 3. what printf makes of it ---\n");
	/*
	 * Reported, not asserted: C leaves the spelling to the
	 * implementation ("inf" and "INF" are both seen), and Tcl does not
	 * use printf for this. It is here because a printf that produces a
	 * FINITE-looking string is evidence the value is not really
	 * infinite, which is the thing under test.
	 */
	snprintf(buf, sizeof buf, "%g", (double)INFINITY);
	printf("  printf %%g of INFINITY: \"%s\"\n", buf);
	ok(strstr(buf, "inf") != NULL || strstr(buf, "INF") != NULL
		|| strstr(buf, "Inf") != NULL,
		"printf spells INFINITY as some form of \"inf\"");

	snprintf(buf, sizeof buf, "%g", (double)-INFINITY);
	printf("  printf %%g of -INFINITY: \"%s\"\n", buf);

	printf("\n%d failure(s)\n", fail);
	return fail;
}
