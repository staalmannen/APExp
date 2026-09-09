/*
 * exp, log, log2, log10 and pow: exact where they must be, and correct.
 *
 *	pcc -o explog-test explog-test.c && ./explog-test
 *
 * These were the last of Plan 9's 1980 libm left in ap/math. Measured
 * against glibc by building each on the host:
 *
 *	exp     430 ulp near |x|=700   ->  1
 *	log       1 ulp                ->  0
 *	log2      2 ulp                ->  1
 *	log10     2 ulp                ->  1
 *	pow       6 ulp                ->  1
 *
 * log was already respectable, so the reason to replace it is the pair
 * beside it: log2 and log10 were **not exact on exact powers**.
 *
 *	log2(8)     = 2.9999999999999996
 *	log10(100)  = 1.9999999999999998
 *
 * so (int)log2(8) was 2. That is the same truncation trap as cos(0)
 * being 0.99999999999999956 -- two ulp that a cast turns into a whole
 * integer -- and it is the one bug in this family that silently changes
 * a program's control flow rather than its last digit. Plan 9's log.c
 * defined all three, which is why they move together; log2.c and
 * log10.c are new files.
 *
 * All five are musl's, which are ARM's optimized-routines: table-driven,
 * with the tables in exp_data.c, log_data.c, log2_data.c and pow_data.c.
 * Those four files were **already in the tree and already in the
 * mkfile**, compiled and unreferenced, because only the double entry
 * points had ever been written.
 *
 * They could not have worked before this in any case: the tables are
 * written entirely in hex floating constants, and kencc converted those
 * with Plan 9's strtod, which stops at the 'x' and returns 0. See the
 * hexfloat() note in CLAUDE.md -- 597 constants, every one zero.
 *
 * Every case below is required of any conforming libm, so this passes on
 * glibc, which is how it and the replacements were both checked.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

static int failures;

static void
ok(int cond, const char *what)
{
	printf("%s %s\n", cond ? "PASS" : "FAIL", what);
	if(!cond)
		failures++;
}

static double
ulpdiff(double got, double want)
{
	double d, u;

	if(got == want)
		return 0.0;
	if(isnan(got) || isnan(want))
		return 1e300;
	if(isinf(got) || isinf(want))
		return 1e300;
	d = fabs(got - want);
	u = nextafter(fabs(want), INFINITY) - fabs(want);
	if(u == 0.0)
		return 1e300;
	return d / u;
}

static void
near(double got, double want, double maxulp, const char *what)
{
	double n = ulpdiff(got, want);
	char buf[160];

	snprintf(buf, sizeof buf, "%s (%.1f ulp)", what, n);
	ok(n <= maxulp, buf);
}

int
main(void)
{
	/*
	 * The exactness rules. These are the ones a program can notice
	 * without looking at the last digit, because a cast or a
	 * comparison turns them into a different answer entirely.
	 */
	ok(exp(0.0) == 1.0,   "exp(0.0) is exactly 1.0");
	ok(log(1.0) == 0.0,   "log(1.0) is exactly 0.0");
	ok(log2(1.0) == 0.0,  "log2(1.0) is exactly 0.0");
	ok(log10(1.0) == 0.0, "log10(1.0) is exactly 0.0");

	/* Exact powers must give exact answers. This is what was wrong. */
	ok(log2(2.0) == 1.0,     "log2(2) is exactly 1");
	ok(log2(8.0) == 3.0,     "log2(8) is exactly 3");
	ok(log2(1024.0) == 10.0, "log2(1024) is exactly 10");
	ok(log2(0.5) == -1.0,    "log2(0.5) is exactly -1");
	ok(log10(10.0) == 1.0,   "log10(10) is exactly 1");
	ok(log10(100.0) == 2.0,  "log10(100) is exactly 2");
	ok(log10(1000.0) == 3.0, "log10(1000) is exactly 3");

	/* The cast is the point: (int)log2(8) must be 3, not 2. */
	{
		int i, good = 1;
		double v = 1.0;

		for(i = 0; i <= 40; i++){
			if((int)log2(v) != i){
				printf("     (int)log2(2^%d) = %d\n",
					i, (int)log2(v));
				good = 0;
			}
			v *= 2.0;
		}
		ok(good, "(int)log2(2^n) == n for n in 0..40");
	}

	ok(pow(2.0, 10.0) == 1024.0, "pow(2,10) is exactly 1024");
	ok(pow(10.0, 3.0) == 1000.0, "pow(10,3) is exactly 1000");
	ok(pow(3.0, 4.0) == 81.0,    "pow(3,4) is exactly 81");
	ok(pow(1.0, 0.0) == 1.0,     "pow(1,0) is exactly 1");
	ok(pow(0.0, 0.0) == 1.0,     "pow(0,0) is exactly 1");

	/* Accuracy. References are hex floats: exact, and what the value is. */
	near(exp(0.5),    0x1.a61298e1e069cp+0,    1.0, "exp(0.5)");
	near(exp(1.0),    0x1.5bf0a8b145769p+1,    1.0, "exp(1.0)");
	near(exp(2.0),    0x1.d8e64b8d4ddaep+2,    1.0, "exp(2.0)");
	near(exp(10.0),   0x1.5829dcf950560p+14,   1.0, "exp(10.0)");
	/* Where the old one was 430 ulp out. */
	near(exp(700.0),  0x1.d945df4f8ec8ep+1009, 1.0, "exp(700.0)");
	near(exp(-700.0), 0x1.14f2b0fb9307fp-1010, 1.0, "exp(-700.0)");

	near(log(0.5),   -0x1.62e42fefa39efp-1, 1.0, "log(0.5)");
	near(log(2.0),    0x1.62e42fefa39efp-1, 1.0, "log(2.0)");
	near(log(10.0),   0x1.26bb1bbb55516p+1, 1.0, "log(10.0)");
	near(log(1e100),  0x1.cc845b54b54f2p+7, 1.0, "log(1e100)");
	near(log(1e-100),-0x1.cc845b54b54f2p+7, 1.0, "log(1e-100)");

	near(log2(10.0),   0x1.a934f0979a371p+1, 1.0, "log2(10.0)");
	near(log2(1e100),  0x1.4c315bf6707b1p+8, 1.0, "log2(1e100)");
	near(log10(2.0),   0x1.34413509f79ffp-2, 1.0, "log10(2.0)");
	near(log10(1e100), 0x1.9000000000000p+6, 1.0, "log10(1e100)");

	near(pow(2.0, 0.5),    0x1.6a09e667f3bcdp+0, 1.0, "pow(2,0.5)");
	near(pow(3.7, 2.9),    0x1.63876a27e42d0p+5, 1.0, "pow(3.7,2.9)");
	near(pow(0.01, -9.5),  0x1.158e460913cffp+63, 1.0, "pow(0.01,-9.5)");

	/* The identities, which catch a wrong table more loudly than a ulp. */
	{
		static const double xs[] = {
			0.1, 0.5, 1.5, 2.0, 7.0, 100.0, 1e10, 1e100
		};
		size_t i;
		int goodl = 1, goodp = 1;

		for(i = 0; i < sizeof xs / sizeof xs[0]; i++){
			double x = xs[i];
			/*
			 * The round trip amplifies: an error e in log(x)
			 * becomes a relative error e in exp, and log(1e100)
			 * is 230, so one ulp there is 2.8e-14 relative. That
			 * is inherent -- glibc does the same -- so the bound
			 * has to scale with |log(x)| rather than be a flat
			 * few ulp.
			 */
			if(fabs(exp(log(x)) - x) >
			   x * (fabs(log(x)) + 2.0) * 1.2e-16){
				printf("     exp(log(%g)) = %.17g\n",
					x, exp(log(x)));
				goodl = 0;
			}
			if(fabs(pow(x, 2.0) - x*x) > 4e-16 * x*x){
				printf("     pow(%g,2) = %.17g vs %.17g\n",
					x, pow(x, 2.0), x*x);
				goodp = 0;
			}
		}
		ok(goodl, "exp(log(x)) == x across the range");
		ok(goodp, "pow(x,2) == x*x across the range");
	}

	/* Edges. */
	ok(log(0.0) == -INFINITY,   "log(0) is -inf");
	ok(isnan(log(-1.0)),        "log(-1) is NaN");
	ok(log(INFINITY) == INFINITY, "log(inf) is inf");
	ok(exp(INFINITY) == INFINITY, "exp(inf) is inf");
	ok(exp(-INFINITY) == 0.0,     "exp(-inf) is 0");
	ok(exp(1000.0) == INFINITY,   "exp(1000) overflows to inf");
	ok(exp(-1000.0) == 0.0,       "exp(-1000) underflows to 0");
	ok(pow(-2.0, 3.0) == -8.0,    "pow(-2,3) is -8");
	ok(pow(-2.0, 2.0) == 4.0,     "pow(-2,2) is 4");
	ok(isnan(pow(-2.0, 0.5)),     "pow(-2,0.5) is NaN");
	ok(pow(1.0, INFINITY) == 1.0, "pow(1,inf) is 1");
	ok(pow(INFINITY, 2.0) == INFINITY, "pow(inf,2) is inf");

	printf("%d failure(s)\n", failures);
	return failures;
}
