/*
 * binfloat-test.c -- the double-to-float narrowing Tcl's
 * `binary format R' does, replicated line by line.
 *
 * WHERE THIS CAME FROM. binary-53.25 and binary-53.26 have outlived
 * the whole float campaign: strtod, strtof, strtold, _dtoa and scalbn
 * are all correct now and these two still fail.
 *
 *	binary scan [binary format H* 47effffff0000001] Q round_to_inf
 *	binary scan [binary format R $round_to_inf] R inf1
 *	expr {$inf1 eq Inf}		-> 0, wanted 1
 *
 * `Q' is a big-endian DOUBLE, so round_to_inf is the double whose bits
 * are 0x47effffff0000001. That is (2^128 - 2^103) + 2^75: one binade
 * above FLT_MAX and strictly ABOVE the boundary at which a narrowing
 * conversion must produce infinity. `binary format R' must therefore
 * write +Inf, and does not.
 *
 * WHAT TCL ACTUALLY DOES, from tclBinary.c's FormatNumber -- it does
 * NOT simply cast, because some compilers trap on an overflowing cast:
 *
 *	if (fabs(dvalue) > (double) FLT_MAX) {
 *	    if (fabs(dvalue) > (FLT_MAX +
 *		    ldexp(1.0, FLT_MAX_EXP - FLT_MANT_DIG - 1))) {
 *		fvalue = (dvalue >= 0.0) ? INFINITY : -INFINITY;
 *	    } else {
 *		fvalue = (dvalue >= 0.0) ? FLT_MAX : -FLT_MAX;
 *	    }
 *	} else {
 *	    fvalue = (float) dvalue;
 *	}
 *
 * so there are four things that can be wrong and a failing test cannot
 * tell them apart: `fabs', `ldexp(1.0, 103)', the `INFINITY' macro,
 * and the plain cast. **This file prints all four.** That is the point
 * of it -- the last round's lesson was that a probe which names each
 * candidate answers in one run where elimination takes several.
 *
 * REPLICATED, NOT REMEMBERED. The block above is copied from the tree,
 * not written from a recollection of what it does; a probe that skips
 * a call cannot clear that call.
 *
 * Correct on glibc, which is where it was checked. On a system where
 * every part is right, section 3 is the whole answer and the rest is
 * there to say which part is not.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <float.h>

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static double
dbits(uint64_t u)
{
	double d;

	memcpy(&d, &u, sizeof d);
	return d;
}

static uint32_t
fbits(float f)
{
	uint32_t u;

	memcpy(&u, &f, sizeof u);
	return u;
}

int
main(void)
{
	double dvalue, thresh;
	float fvalue;

	/* the exact double binary-53.25 builds */
	dvalue = dbits(0x47effffff0000001ULL);

	printf("--- 1. the pieces Tcl's FormatNumber leans on ---\n");
	printf("  note dvalue          = %.17g\n", dvalue);
	printf("  note FLT_MAX         = %.17g\n", (double) FLT_MAX);
	printf("  note fabs(dvalue)    = %.17g\n", fabs(dvalue));
	printf("  note ldexp(1.0, %d) = %.17g   (want 2^103 = 1.0141204801825835e+31)\n",
		FLT_MAX_EXP - FLT_MANT_DIG - 1,
		ldexp(1.0, FLT_MAX_EXP - FLT_MANT_DIG - 1));
	ok("fabs() leaves a positive value alone", fabs(dvalue) == dvalue);
	ok("ldexp(1.0, 103) is 2^103",
		ldexp(1.0, FLT_MAX_EXP - FLT_MANT_DIG - 1) == 10141204801825835211973625643008.0);

	printf("--- 2. INFINITY has to BE infinity ---\n");
	/*
	 * Not idle: APE's HUGE_VAL is a finite decimal literal, which is
	 * why sys/src/ape/lib/tcl/tclConfig.h redefines both HUGE_VAL and
	 * INFINITY. If that redefinition is not in force wherever
	 * tclBinary.c is compiled, this is where it shows.
	 */
	printf("  note INFINITY        = %.17g, bits %08lx\n",
		(double) INFINITY, (unsigned long) fbits((float) INFINITY));
	ok("INFINITY is an infinity", isinf((double) INFINITY));
	ok("...and it is positive", (double) INFINITY > 0);
	ok("(float)INFINITY has the float infinity bits",
		fbits((float) INFINITY) == 0x7f800000);

	printf("--- 3. the comparison that decides it ---\n");
	thresh = (double) FLT_MAX + ldexp(1.0, FLT_MAX_EXP - FLT_MANT_DIG - 1);
	printf("  note threshold       = %.17g\n", thresh);
	ok("dvalue is above FLT_MAX", fabs(dvalue) > (double) FLT_MAX);
	ok("dvalue is above the overflow threshold TOO", fabs(dvalue) > thresh);

	printf("--- 4. FormatNumber's own code, run here ---\n");
	if(fabs(dvalue) > (double) FLT_MAX){
		if(fabs(dvalue) > thresh)
			fvalue = (dvalue >= 0.0) ? INFINITY : -INFINITY;
		else
			fvalue = (dvalue >= 0.0) ? FLT_MAX : -FLT_MAX;
	} else
		fvalue = (float) dvalue;
	printf("  note fvalue bits     = %08lx  (+Inf is 7f800000)\n",
		(unsigned long) fbits(fvalue));
	ok("binary format R of that double is +Inf", fbits(fvalue) == 0x7f800000);

	printf("--- 5. and what a PLAIN cast does, for comparison ---\n");
	/*
	 * Tcl avoids this path for out-of-range values, so it is not the
	 * bug -- but if the cast disagrees with the branch above, the
	 * compiler's narrowing is worth knowing about on its own.
	 */
	fvalue = (float) dvalue;
	printf("  note (float)dvalue   = %08lx\n", (unsigned long) fbits(fvalue));
	ok("a plain cast of a value past the boundary is +Inf too",
		fbits(fvalue) == 0x7f800000);

	printf("--- 6. THE CONTROL: values that must NOT become infinity ---\n");
	/*
	 * Without this, "everything becomes Inf" would look like a fix.
	 */
	ok("FLT_MAX itself narrows to FLT_MAX",
		fbits((float)(double) FLT_MAX) == 0x7f7fffff);
	ok("a double just below the boundary narrows to FLT_MAX",
		fbits((float) dbits(0x47efffffefffffffULL)) == 0x7f7fffff);
	ok("1.0 narrows to 1.0f", fbits((float) 1.0) == 0x3f800000);

	printf("%d failure(s)\n", failures);
	return failures;
}
