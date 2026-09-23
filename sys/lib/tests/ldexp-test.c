/*
 * ldexp-test.c -- scalbn, ldexp and scalbnf over the WHOLE exponent
 * range, which is the part that was broken.
 *
 * WHERE THIS CAME FROM. `math/scalbn.c' said
 *
 *	y *= 2^1023;
 *
 * and in C that is `2 XOR 1023' -- an integer bitwise exclusive-or,
 * 1021 -- not two to the power of anything. musl writes `0x1p1023',
 * and someone read the `p' as "power of". It compiles silently and
 * multiplies by 1021. scalbnf had the same thing with 127, where
 * 2 XOR 127 is 125.
 *
 * Those lines are only reached when |n| is bigger than the exponent
 * range of one multiplication -- n > 1023 for double, n > 127 for
 * float -- which is why nothing had noticed. What did notice, in the
 * end, was six failures in Tcl's expr.test: everything at or above
 * 1.7976931348623155e+308 came back infinite, including values that
 * are perfectly representable, because Tcl reaches DBL_MAX by calling
 * ldexp(fraction, 1024).
 *
 * THE LESSON, AND WHY THIS FILE WALKS THE WHOLE RANGE. scalbn had
 * ALREADY been cross-checked against glibc's, on the build host, over
 * 299876 values -- and reported 0 wrong, because that sweep drew its
 * exponent from rand()%200 - 100 and so never once entered the branch
 * that was wrong. *A check that cannot fail is not a check*, and a
 * sweep that cannot reach a branch has not tested it. Every section
 * here is bounded by the format's own limits rather than by a
 * comfortable-looking window.
 *
 * HOW THE EXPECTED VALUES ARE BUILT. Not with ldexp: a test that asks
 * the unit under test for its own answer cannot fail. 2^e is
 * constructed from the IEEE bit pattern -- exponent field e+1023 for a
 * normal, a single significand bit for a subnormal -- so the reference
 * never goes through any library code at all.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

/* 2^e built from the bit pattern, for -1074 <= e <= 1023 */
static double
twoto(int e)
{
	union { double d; uint64_t u; } v;

	if(e >= -1022){
		v.u = (uint64_t)(e + 1023) << 52;	/* normal */
		return v.d;
	}
	v.u = (uint64_t)1 << (e + 1074);		/* subnormal */
	return v.d;
}

static float
twotof(int e)
{
	union { float f; uint32_t u; } v;

	if(e >= -126){
		v.u = (uint32_t)(e + 127) << 23;
		return v.f;
	}
	v.u = (uint32_t)1 << (e + 149);
	return v.f;
}

static int
same(double a, double b)
{
	return memcmp(&a, &b, sizeof a) == 0;
}

static int
samef(float a, float b)
{
	return memcmp(&a, &b, sizeof a) == 0;
}

int
main(void)
{
	int e, bad, first;
	double d, want;
	float f, wantf;

	printf("--- 1. every power of two a double can hold ---\n");
	/*
	 * -1074 (the smallest subnormal) up to 1023 (the largest power of
	 * two). The old scalbn was right for every e in this loop that a
	 * single multiplication could reach and wrong beyond it, so the
	 * loop has to be the whole range or it proves nothing.
	 */
	bad = 0;
	first = 0;
	for(e = -1074; e <= 1023; e++){
		want = twoto(e);
		d = scalbn(1.0, e);
		if(!same(d, want)){
			if(bad++ == 0){
				first = e;
				printf("  note first wrong at e=%d: got %g want %g\n",
					e, d, want);
			}
		}
	}
	printf("  note %d of 2098 exponents wrong\n", bad);
	ok("scalbn(1.0, e) is 2^e for every representable e", bad == 0);
	(void)first;

	printf("--- 2. ldexp is scalbn, and Tcl reaches DBL_MAX through it ---\n");
	/*
	 * The shape of the call that found the bug. Tcl's SafeLdExp asks
	 * for ldexp(fraction, 1024) on the way to DBL_MAX and was getting
	 * 2041.9999999999993 -- the fraction times 2 XOR 1023 times 2.
	 *
	 * The fraction here is the largest double below 1, built from its
	 * bits rather than written as a decimal: (1 - 2^-53) * 2^1024 is
	 * 2^1024 - 2^971, which is DBL_MAX exactly. Tcl's own intermediate
	 * was a few ulp off that and its RefineApproximation closes the
	 * gap; what matters for this file is the scaling, so it uses the
	 * value that makes the answer exact.
	 */
	{
		union { double d; uint64_t u; } frac;

		frac.u = 0x3fefffffffffffffULL;	/* 1 - 2^-53 */
		d = ldexp(frac.d, 1024);
		printf("  note ldexp(%.17g, 1024) = %.17g\n", frac.d, d);
	}
	ok("...and that is DBL_MAX", d == DBL_MAX);

	printf("--- 3. exponents past what one multiplication can do ---\n");
	/*
	 * n > 1023 and n < -1022 are the two multi-step arms, and they are
	 * the only places the mistyped constants lived.
	 */
	ok("scalbn(1.0, 1024) == 2^1024/2 * 2", same(scalbn(0.5, 1024), twoto(1023)));
	ok("scalbn(1.0, 1023) == 2^1023", same(scalbn(1.0, 1023), twoto(1023)));
	ok("scalbn(2^-1074, 2097) == 2^1023",
		same(scalbn(twoto(-1074), 2097), twoto(1023)));
	ok("scalbn(2^1023, -2097) == 2^-1074",
		same(scalbn(twoto(1023), -2097), twoto(-1074)));
	ok("scalbn(1.0, -1074) == the smallest subnormal",
		same(scalbn(1.0, -1074), twoto(-1074)));
	ok("scalbn(1.0, -1075) underflows to zero", scalbn(1.0, -1075) == 0.0);
	ok("scalbn(1.0, 1024) overflows to infinity", isinf(scalbn(1.0, 1024)));
	ok("scalbn(1.0, 5000) overflows to infinity", isinf(scalbn(1.0, 5000)));
	ok("scalbn(1.0, -5000) underflows to zero", scalbn(1.0, -5000) == 0.0);

	printf("--- 4. the same for float ---\n");
	bad = 0;
	for(e = -149; e <= 127; e++){
		wantf = twotof(e);
		f = scalbnf(1.0f, e);
		if(!samef(f, wantf)){
			if(bad++ == 0)
				printf("  note first wrong at e=%d: got %g want %g\n",
					e, (double)f, (double)wantf);
		}
	}
	printf("  note %d of 277 exponents wrong\n", bad);
	ok("scalbnf(1.0f, e) is 2^e for every representable e", bad == 0);
	ok("scalbnf(2^-149, 276) == 2^127",
		samef(scalbnf(twotof(-149), 276), twotof(127)));
	ok("scalbnf(1.0f, 128) overflows to infinity", isinf(scalbnf(1.0f, 128)));
	ok("scalbnf(1.0f, -150) underflows to zero", scalbnf(1.0f, -150) == 0.0f);

	printf("--- 5. THE CONTROL: a small exponent still works ---\n");
	/*
	 * Everything above would also pass if scalbn were replaced by
	 * something that only handles the extremes. This is the range the
	 * old one got right, and it must stay right.
	 */
	ok("scalbn(3.0, 4) == 48", scalbn(3.0, 4) == 48.0);
	ok("scalbn(3.0, -4) == 0.1875", scalbn(3.0, -4) == 0.1875);
	ok("ldexp(1.0, 0) == 1", ldexp(1.0, 0) == 1.0);

	printf("%d failure(s)\n", failures);
	return failures;
}
