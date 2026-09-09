/*
 * sin, cos and tan: exact at zero, and correct after argument reduction.
 *
 *	pcc -o sincos-test sincos-test.c && ./sincos-test
 *
 * libap took these from Plan 9's libc, which is a Hart & Cheney rational
 * approximation from 1980 with a crude argument reduction, and it was
 * wrong in two separate ways.
 *
 * It never returned exactly 1 for cos(0). Plan 9's cos is sinus(x, 1),
 * which shifts the quadrant and evaluates the polynomial at the END of
 * its interval rather than taking a shortcut for a tiny argument, so
 *
 *	cos(0.0) = 0.99999999999999956
 *
 * Two ulp, and invisible in nearly everything -- but Tk's canvas rotates
 * every text item by its -angle with
 *
 *	Tk_PointToChar(layout, (int)(x*cs - y*s), (int)(y*cs + x*s));
 *
 * and for an unrotated item cs is cos(0). (int)(12 * 0.99999999999999956)
 * is 11, so every "canvas index @x,y" was one pixel out and the 13 tests
 * in font-28.* and font-30.* asked which character was at the start of
 * line 2 and were told line 1. An exactness bug is not a rounding bug:
 * truncation turns 2 ulp into a whole pixel.
 *
 * And the argument reduction fell apart entirely away from zero, which
 * is the more serious half. Measured against glibc:
 *
 *	x        cos error (old)   (new)
 *	pi/2     5e15 ulp          0
 *	100      44 ulp            0
 *	1e6      162415 ulp        0
 *	1e15     4e14 ulp          1
 *
 * cos(1e6) had five wrong decimal digits and cos(1e15) no correct ones.
 * Anything doing trigonometry on a large angle -- a plot axis, an
 * accumulated phase, a time in seconds -- was quietly getting noise.
 *
 * Replaced by musl's, which are FreeBSD's fdlibm: sin.c, cos.c and tan.c
 * dispatch to __sin/__cos/__tan after __rem_pio2, all four of which were
 * already in the tree and unused for the double versions.
 *
 * Every case below is required of any conforming libm, so this passes on
 * glibc, which is how it and the replacement were both checked.
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

/*
 * How many ulp apart two values are. Comparing against a decimal
 * literal would test the compiler's parser as much as the library, so
 * the references are hex floats -- exact, and what the value really is.
 */
static double
ulpdiff(double got, double want)
{
	double d, u;

	if(got == want)
		return 0.0;
	if(isnan(got) || isnan(want))
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
	double z;

	/*
	 * The exactness rules. C99 F.9.1.2/F.9.1.4 make these exact, and
	 * they are what callers rely on without knowing it.
	 */
	ok(cos(0.0) == 1.0, "cos(0.0) is exactly 1.0");
	ok(sin(0.0) == 0.0, "sin(0.0) is exactly 0.0");
	ok(tan(0.0) == 0.0, "tan(0.0) is exactly 0.0");

	/* And the sign of a zero survives: sin(-0) is -0, cos(-0) is +1. */
	z = sin(-0.0);
	ok(z == 0.0 && signbit(z), "sin(-0.0) is -0.0");
	ok(cos(-0.0) == 1.0, "cos(-0.0) is exactly 1.0");
	z = tan(-0.0);
	ok(z == 0.0 && signbit(z), "tan(-0.0) is -0.0");

	/* Even and odd, exactly, for a tiny argument. */
	ok(cos(1e-300) == 1.0, "cos(1e-300) is exactly 1.0");
	ok(sin(1e-300) == 1e-300, "sin(1e-300) returns its argument");

	/*
	 * Small arguments, no reduction needed. These were within an ulp
	 * or two even before, so they are not the interesting cases --
	 * they are here so that a failure here says the polynomial is
	 * wrong rather than the reduction.
	 */
	near(cos(0.5),  0x1.c1528065b7d50p-1, 1.0, "cos(0.5)");
	near(sin(0.5),  0x1.eaee8744b05f0p-2, 1.0, "sin(0.5)");
	near(tan(0.5),  0x1.17b4f5bf3474ap-1, 1.0, "tan(0.5)");
	near(cos(1.0),  0x1.14a280fb5068cp-1, 1.0, "cos(1.0)");
	near(sin(1.0),  0x1.aed548f090ceep-1, 1.0, "sin(1.0)");
	near(tan(1.0),  0x1.8eb245cbee3a6p+0, 1.0, "tan(1.0)");

	/*
	 * cos(pi/2) is not zero -- pi/2 is not representable -- but it is
	 * about 6.1e-17, and getting it right needs the extra precision
	 * __rem_pio2 carries in y[1]. The old code answered 1.1e-16, off
	 * by 5e15 ulp, because it reduced in double alone.
	 */
	near(cos(M_PI/2), 0x1.1a62633145c07p-54, 2.0, "cos(pi/2)");
	near(sin(M_PI),   1.2246467991473532e-16, 2.0, "sin(pi)");

	/* Past one reduction step. */
	near(cos(2.0),  -0x1.aa22657537205p-2, 1.0, "cos(2.0)");
	near(sin(2.0),   0x1.d18f6ead1b446p-1, 1.0, "sin(2.0)");
	near(cos(3.0),  -0x1.fae04be85e5d2p-1, 1.0, "cos(3.0)");
	near(sin(3.0),   0x1.210386db6d55bp-3, 1.0, "sin(3.0)");
	near(cos(10.0), -0x1.ad9ac890c6b1fp-1, 1.0, "cos(10.0)");
	near(sin(10.0), -0x1.1689ef5f34f52p-1, 1.0, "sin(10.0)");
	near(tan(10.0),  0x1.4bf5f34be3782p-1, 1.0, "tan(10.0)");

	/*
	 * The cases the old reduction could not do. 100 was 44 ulp out,
	 * 1e6 was 162415, and 1e15 had no correct digits at all -- these
	 * need __rem_pio2_large, which reduces against a many-word pi.
	 */
	near(cos(100.0), 0x1.b981dbf665fdfp-1, 1.0, "cos(100.0)");
	near(sin(100.0), -0x1.03425b78c4db8p-1, 1.0, "sin(100.0)");
	near(cos(1e6),   0x1.df9df9906d32cp-1, 1.0, "cos(1e6)");
	near(sin(1e6),  -0x1.6664b2568d867p-2, 1.0, "sin(1e6)");
	near(tan(1e6),  -0x1.7e9768ab734c0p-2, 1.0, "tan(1e6)");
	near(cos(1e15), -0x1.06c154609d33fp-1, 2.0, "cos(1e15)");
	near(sin(1e15),  0x1.b76f88136cebap-1, 2.0, "sin(1e15)");
	near(tan(1e15), -0x1.ac23600a95be4p+0, 2.0, "tan(1e15)");

	/* sin^2 + cos^2 == 1 wherever it is asked. */
	{
		static const double xs[] = {
			0.0, 0.5, 1.0, 2.0, 3.0, 7.0, 30.0, 1000.0, 1e6, 1e15
		};
		size_t i;
		int good = 1;

		for(i = 0; i < sizeof xs / sizeof xs[0]; i++){
			double s = sin(xs[i]), c = cos(xs[i]);
			if(fabs(s*s + c*c - 1.0) > 4e-16){
				printf("     sin^2+cos^2 at %g is %.17g\n",
					xs[i], s*s + c*c);
				good = 0;
			}
		}
		ok(good, "sin^2 + cos^2 == 1 across the range");
	}

	/* Infinities and NaN are NaN, not a polynomial evaluated on junk. */
	ok(isnan(cos(INFINITY)), "cos(inf) is NaN");
	ok(isnan(sin(INFINITY)), "sin(inf) is NaN");
	ok(isnan(tan(INFINITY)), "tan(inf) is NaN");
	ok(isnan(cos(NAN)), "cos(NaN) is NaN");

	/*
	 * The Tk canvas case that found this: an unrotated item multiplies
	 * by cos(0) and truncates. Anything less than exactly 1.0 loses a
	 * whole pixel.
	 */
	{
		int i, good = 1;

		for(i = 0; i <= 64; i++){
			if((int)(i * cos(0.0)) != i){
				printf("     (int)(%d * cos(0.0)) = %d\n",
					i, (int)(i * cos(0.0)));
				good = 0;
			}
		}
		ok(good, "(int)(n * cos(0.0)) == n for n in 0..64");
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
