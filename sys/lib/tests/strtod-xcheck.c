/*
 * strtod-xcheck.c -- libap's strtod beside glibc's, on the build host.
 *
 * NOT A PLAN 9 TEST. Like tz-xcheck.c, this links the unit under test
 * into a glibc program and compares it against the reference
 * implementation, so the answer arrives in a compile rather than a VM
 * round. Build it with the script in the comment at the bottom.
 *
 * WHERE THIS CAME FROM. Six failures in Tcl's expr.test and
 * expr-old.test, which are all one bug:
 *
 *	expr-30.1   convertToDouble 1.7976931348623157e+308
 *	            got 0x7ff0000000000000, wanted 0x7fefffffffffffff
 *	expr-30.2   the same, negative
 *	expr-28.527 -929963218616126365E290 -> -Inf, wanted -0x7fe08d...
 *	expr-39.21, expr-old-37.21  17976931348623157e292. -> Inf
 *	expr-50.1   sqrt(1e616) == 1e308 -> false
 *
 * AND THE FIRST RUN REFUTED THE DIAGNOSIS THAT BUILT IT, which is why
 * this file is worth more than the six tests. libap's strtod does NOT
 * return infinity for 1.7976931348623157e+308 -- it returns
 * 0x7feffffffffffffd, two ulp low -- so whatever produces the Inf that
 * expr-30.1 reports, it is not this function. Tcl parses numbers in
 * its own tclStrToD.c. The Tcl cluster is therefore UNEXPLAINED and
 * this file does not explain it.
 *
 * What it does explain is much larger, and was not what anyone was
 * looking for: **libap's strtod is inaccurate everywhere.** 74% of
 * round-trips through "%.17g" come back as a different double, and
 * 1e308 is off by 2e14 ulp. Every program on this system that reads a
 * floating-point number gets this.
 *
 * `lib/ap/string/strtod.c' is the old APE one, and its own first
 * comment says what it is:
 *
 *	 * bug: should detect overflow, set errno = ERANGE, and
 *	 * return +/- HUGE_VAL
 *
 * It accumulates the digits in a double -- `num = num*10 + c-'0'' --
 * and then multiplies by `pow10(exp)'. Two roundings, neither of them
 * the one the standard asks for: the mantissa is rounded while being
 * built (17976931348623157 needs 55 bits and a double has 53), and the
 * scale factor is itself a rounded power of ten built by repeated
 * multiplication. Near DBL_MAX the product then tips over into
 * infinity. It is inaccurate everywhere and catastrophic at the top.
 *
 * WHAT THIS MEASURES, in four sections, each printed with its own
 * count so that a partial improvement is visible rather than hidden in
 * a total:
 *
 *	1. the exact strings the six Tcl tests use
 *	2. round-trip: a double -> "%.17g" -> back must be bit-exact
 *	3. the powers of ten, 1e-320 to 1e308
 *	4. values that are exactly representable and must be exact
 *
 * Section 2 is the one that says how bad it is in ordinary use, and it
 * is reported as a worst-case ULP distance as well as a count, because
 * "wrong" and "wrong by 400 ulp" are different claims.
 *
 * The reference is glibc's strtod, which is correctly rounded.
 *
 * Build and run (from this directory, on the build host):
 *
 *	gcc -std=c99 -O2 -o strtod-xcheck strtod-xcheck.c -lm && ./strtod-xcheck
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdint.h>

/*
 * The unit under test, renamed so that glibc's own strtod stays
 * reachable as the reference. -std=c99 keeps <math.h> from declaring
 * pow10 itself, which would clash with libap's (int) signature.
 */
#define pow10	ap_pow10
#define strtod	ap_strtod
#include "../../src/ape/lib/ap/stdio/pow10.c"
#include "../../src/ape/lib/ap/string/strtod.c"
#undef pow10
#undef strtod

static int failures;

static uint64_t
bits(double d)
{
	uint64_t u;

	memcpy(&u, &d, sizeof u);
	return u;
}

/*
 * Distance in representable doubles. Only meaningful when both are
 * finite and of the same sign, which is why the caller checks first;
 * a "ulp distance" computed across infinity is a number with no
 * meaning, and printing one would be worse than printing nothing.
 */
static double
ulpdist(double a, double b)
{
	uint64_t ua, ub;

	if(a == b)
		return 0;
	if(!isfinite(a) || !isfinite(b))
		return INFINITY;
	if((a < 0) != (b < 0))
		return INFINITY;
	ua = bits(fabs(a) == a ? a : -a);
	ub = bits(fabs(b) == b ? b : -b);
	return ua > ub ? (double)(ua - ub) : (double)(ub - ua);
}

static const char *
kind(double d)
{
	if(isnan(d))
		return "nan";
	if(isinf(d))
		return d < 0 ? "-inf" : "+inf";
	return "finite";
}

struct sect {
	const char *name;
	long n;
	long bad;
	double worst;		/* worst ulp distance among finite pairs */
	const char *worsts;	/* the string that produced it */
	long inf;		/* mismatches where ours went infinite */
};

static void
check(struct sect *s, const char *str, char *keep)
{
	double got, want;

	errno = 0;
	got = ap_strtod(str, 0);
	want = strtod(str, 0);
	s->n++;
	if(bits(got) == bits(want))
		return;
	s->bad++;
	if(isinf(got) && isfinite(want))
		s->inf++;
	{
		double d = ulpdist(got, want);

		if(!(d <= s->worst)){	/* NaN-safe: takes inf too */
			s->worst = d;
			s->worsts = keep;
		}
	}
}

static void
report(struct sect *s)
{
	printf("  %-38s %6ld checked, %6ld wrong", s->name, s->n, s->bad);
	if(s->bad == 0){
		printf("   PASS\n");
		return;
	}
	failures++;
	printf("   FAIL\n");
	printf("      %ld of them returned infinity for a finite value\n",
		s->inf);
	if(s->worsts != 0){
		if(isinf(s->worst))
			printf("      worst: %s (not a finite distance)\n",
				s->worsts);
		else
			printf("      worst: %s, off by %.0f ulp\n",
				s->worsts, s->worst);
	}
}

/* the six Tcl tests, spelled exactly as they spell them */
static const char *tcl[] = {
	"1.7976931348623155e+308",
	"1.7976931348623157e+308",
	"1.7976931348623159e+308",
	"-1.7976931348623155e+308",
	"-1.7976931348623157e+308",
	"-1.7976931348623159e+308",
	"-929963218616126365E290",
	0
};

int
main(void)
{
	struct sect s1 = {"1. the strings Tcl's expr tests use"};
	struct sect s2 = {"2. round-trip of random doubles"};
	struct sect s3 = {"3. the powers of ten, 1e-320..1e308"};
	struct sect s4 = {"4. values that must be exact"};
	static char buf[64], keep[64];
	int i;
	long j;

	printf("strtod-xcheck: libap's strtod against glibc's\n");

	printf("--- 1. the exact strings the six failing Tcl tests use ---\n");
	for(i = 0; tcl[i] != 0; i++){
		double got = ap_strtod(tcl[i], 0), want = strtod(tcl[i], 0);

		printf("  %-26s ours %016llx (%s)  glibc %016llx (%s)  %s\n",
			tcl[i], (unsigned long long)bits(got), kind(got),
			(unsigned long long)bits(want), kind(want),
			bits(got) == bits(want) ? "same" : "DIFFER");
		check(&s1, tcl[i], (char *)tcl[i]);
	}
	/* the loop above already counted them; report only */
	report(&s1);

	printf("--- 2. round trip: d -> \"%%.17g\" -> d, must be bit exact ---\n");
	/*
	 * %.17g is enough to name any double uniquely, so a correct
	 * strtod must give back exactly what was printed. This is the
	 * section that says what ordinary programs get.
	 */
	/*
	 * rand() rather than mrand48(), which -std=c99 does not declare;
	 * an implicit declaration is the missing-prototype trap this tree
	 * keeps in its invariants, and a warning is not worth ignoring to
	 * save three lines. Fixed seed, so the run is repeatable.
	 */
	srand(12345);
	for(j = 0; j < 200000; j++){
		uint64_t u;
		double d;

		u = ((uint64_t)rand() << 40) ^ ((uint64_t)rand() << 20)
			^ (uint64_t)rand();
		memcpy(&d, &u, sizeof d);
		if(!isfinite(d))
			continue;
		snprintf(buf, sizeof buf, "%.17g", d);
		strcpy(keep, buf);
		check(&s2, buf, keep);
	}
	report(&s2);

	printf("--- 3. the powers of ten ---\n");
	for(i = -320; i <= 308; i++){
		snprintf(buf, sizeof buf, "1e%d", i);
		strcpy(keep, buf);
		check(&s3, buf, keep);
	}
	report(&s3);

	printf("--- 4. values a naive parser still gets right ---\n");
	/*
	 * The control. If these were wrong too the file would be
	 * reporting a build mistake rather than a rounding one.
	 */
	{
		static const char *easy[] = {
			"0", "1", "-1", "0.5", "100", "1e10", "-2.25",
			"3.0", "1024", "0.125", 0
		};

		for(i = 0; easy[i] != 0; i++)
			check(&s4, easy[i], (char *)easy[i]);
	}
	report(&s4);

	printf("%d section(s) failing\n", failures);
	return failures;
}
