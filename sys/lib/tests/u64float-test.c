/*
 * u64float-test.c -- unsigned 64-bit integers converted to floating point.
 *
 * There are two paths and they were both wrong.
 *
 * Constant folding, in cc/scon.c. A cast of a constant is folded through
 * n->vconst, which is a vlong, so an unsigned source with the top bit
 * set came out negative:
 *
 *	(double) (uvlong) ~0	gave  -1.0	should be 1.8446744e19
 *
 * Runtime conversion, in 6c/txt.c. The TUVLONG-to-floating case handles
 * the top bit correctly -- it halves, converts and doubles -- and then
 * never stored the result, because it was missing the gmove(&nod1, t)
 * that the TULONG case beside it has. Harmless when the destination
 * happened to be a register, silent nonsense when it was memory.
 *
 * Neither mattered while SIZE_MAX was 32-bit. Once SIZE_MAX became a
 * 64-bit constant, gnulib's hash.c:
 *
 *	float new_candidate = candidate / tuning->growth_threshold;
 *	if (SIZE_MAX <= new_candidate)
 *	  return 0;
 *
 * folded to "-1.0 <= 128.75", which is true, so compute_bucket_size()
 * returned 0, hash_initialize() returned NULL, and cp printed "memory
 * exhausted" before it had even looked at its operands. mv, ln and du
 * hash too.
 *
 * Build and run:  pcc -o u64float-test u64float-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef unsigned long long uvlong;
typedef long long vlong;

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

/* Compare within a relative tolerance: these values are far larger than
   the mantissa, so exact equality is not the question -- sign and
   magnitude are. */
static int
near(double got, double want)
{
	double d = got - want;

	if (d < 0)
		d = -d;
	return d <= want / 1e12;
}

/* Not static, and taken by pointer below, so the compiler cannot fold
   the conversion and must use the runtime path. */
double
to_double(uvlong u)
{
	return u;
}

float
to_float(uvlong u)
{
	return u;
}

int
main(void)
{
	char d[128];
	volatile uvlong vu;
	double got;

	/* ---- constant folding (cc/scon.c) ---- */

	sprintf(d, "got %.17g", (double)(uvlong)~0ULL);
	check("(double)(uvlong)~0 folds positive",
	      (double)(uvlong)~0ULL > 0.0, d);
	check("(double)(uvlong)~0 is 1.8446744073709552e19",
	      near((double)(uvlong)~0ULL, 18446744073709551616.0), d);

	sprintf(d, "got %.17g", (double)0x8000000000000000ULL);
	check("(double)0x8000000000000000 is 9.223372036854776e18",
	      near((double)0x8000000000000000ULL, 9223372036854775808.0), d);

	/* SIZE_MAX in a float comparison: gnulib's hash.c, verbatim in
	   shape. If this fails, cp cannot start. */
	{
		float new_candidate = 103 / 0.8f;

		sprintf(d, "SIZE_MAX as a float compares <= %.6g",
		        (double)new_candidate);
		check("SIZE_MAX <= 128.75f is false", !(SIZE_MAX <= new_candidate), d);
	}
	check("UINT64_MAX <= 1.0 is false", !(UINT64_MAX <= 1.0), NULL);
	check("(double)UINTMAX_MAX is positive", (double)UINTMAX_MAX > 0.0, NULL);

	/* A value below 2**63 must be unaffected, then and now. */
	check("(double)(uvlong)1000000 is 1e6",
	      near((double)(uvlong)1000000ULL, 1000000.0), NULL);

	/* ---- runtime conversion (6c/txt.c) ---- */

	vu = ~0ULL;
	got = to_double(vu);
	sprintf(d, "got %.17g", got);
	check("runtime (double)uvlong with the top bit set is positive",
	      got > 0.0, d);
	check("runtime (double)~0 is 1.8446744073709552e19",
	      near(got, 18446744073709551616.0), d);

	vu = 0x8000000000000000ULL;
	got = to_double(vu);
	sprintf(d, "got %.17g", got);
	check("runtime (double)0x8000000000000000",
	      near(got, 9223372036854775808.0), d);

	vu = 0x7fffffffffffffffULL;
	got = to_double(vu);
	sprintf(d, "got %.17g", got);
	check("runtime (double)0x7fffffffffffffff",
	      near(got, 9223372036854775808.0), d);

	vu = 1000000ULL;
	got = to_double(vu);
	sprintf(d, "got %.17g", got);
	check("runtime (double)1000000 is exact", got == 1000000.0, d);

	/* The destination is memory rather than a register here -- an
	   element of an array the compiler cannot keep in one. This is
	   the case the missing gmove lost. */
	{
		double a[4];
		int i;
		static const uvlong in[4] = {
			0ULL, 1000000ULL, 0x8000000000000000ULL, ~0ULL
		};
		static const double want[4] = {
			0.0, 1000000.0,
			9223372036854775808.0, 18446744073709551616.0
		};
		int bad = -1;

		for (i = 0; i < 4; i++) {
			vu = in[i];
			a[i] = vu;
		}
		for (i = 0; i < 4; i++)
			if (!(want[i] == 0.0 ? a[i] == 0.0 : near(a[i], want[i]))) {
				bad = i;
				break;
			}
		if (bad >= 0)
			sprintf(d, "element %d is %.17g, want %.17g",
			        bad, a[bad], want[bad]);
		check("uvlong to a double in memory", bad < 0, d);
	}

	/* float, the same conversion with a narrower destination. */
	vu = ~0ULL;
	{
		float f = to_float(vu);

		sprintf(d, "got %.9g", (double)f);
		check("runtime (float)uvlong with the top bit set is positive",
		      f > 0.0f, d);
	}

	/* Signed vlong must keep working: the sign is real there. */
	check("(double)(vlong)-1 is -1", (double)(vlong)-1 == -1.0, NULL);
	{
		volatile vlong vs = -1;
		double sd = vs;

		sprintf(d, "got %.17g", sd);
		check("runtime (double)(vlong)-1 is -1", sd == -1.0, d);
	}

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
