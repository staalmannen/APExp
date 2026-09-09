/*
 * Floating-point arithmetic rules kencc used to get wrong.
 *
 *	pcc -o fparith-test fparith-test.c && ./fparith-test
 *
 * Three separate bugs, all found by musl's asin() and all silent. They
 * are grouped here because each is a case of an integer rule applied to
 * floating point, which is the shape to look for.
 *
 * 1. "double op float" was computed in FLOAT.
 *
 *    cc/sub.c's promotion table had tab[TDOUBLE][TFLOAT] == TFLOAT, so
 *    the common type of a double and a float was the SMALLER of the two
 *    -- C99 6.3.1.8 says the greater rank wins. The TFLOAT row was right
 *    (tab[TFLOAT][TDOUBLE] == TDOUBLE), so "float op double" always
 *    worked and only this direction was wrong, which is how it survived.
 *
 *    musl's asin(1.0) returns "x*pio2_hi + 0x1p-120f" -- a double plus a
 *    float constant whose only job is to raise inexact -- and the answer
 *    came back as float pi/2, 1.5707963705062866, exactly 4.371e-08
 *    above the double value. Every mixed-precision expression in the
 *    tree was quietly rounded to 24 bits.
 *
 * 2. 0/x was folded to 0 for floating point.
 *
 *    cc/com.c's ccom() ODIV case did "if(vconst(l) == 0 && !side(r))
 *    *n = *l;". True for integers. In floating point 0.0/0.0 is NaN and
 *    0.0/-1.0 is -0.0 -- and *n = *l replaced the node with the integer
 *    constant, so the result was a positive integer zero. The divisor-is-
 *    zero case two lines below already had a typefd guard; this one did
 *    not.
 *
 *    musl's asin(2.0) reports its domain error with "return 0/(x-x);",
 *    which folded away and returned 0.0 instead of NaN.
 *
 * 3. INFINITY was DBL_MAX.
 *
 *    <math.h> had "#define HUGE_VAL 1.79769313486231e+308" and INFINITY
 *    on top of it -- a finite number. C99 7.12p3/p4 require infinity.
 *    So isinf(INFINITY) was false, exp(1000) == INFINITY was false, and
 *    cos(INFINITY) computed the cosine of a very large angle rather than
 *    NaN. It hid well: exp(INFINITY) "passed" because exp(1.8e308)
 *    returns 1.0+x, which compares equal to that same 1.8e308.
 *
 * 4. Negation was 0 - x, so -(+0.0) was +0.0.
 *
 *    x86-64 has no scalar floating-point negate, and cc/com.c rewrites
 *    -x as 0 - x whenever the back end says it cannot do the operation
 *    itself (machcap()). 6c's machcap() answered for the integer types
 *    only, so every floating-point negation went through the rewrite --
 *    and 0.0 - 0.0 is +0.0. Unary plus had the same shape, 0 + x, so
 *    +(-0.0) was +0.0 as well.
 *
 *    Negation is a sign-bit flip and is now generated as one, an XORPS
 *    or XORPD against a mask of -0.0. Three more places dropped the
 *    sign of zero on the way to the object file, each of them a test of
 *    the form "if(x == 0)" where the two zeros differ:
 *
 *	cc/scon.c   evconst folded -0.0 with a runtime negation, so it
 *	            inherited the bug from the compiler compiling it;
 *	cc/pswt.c   ieeedtod tested "native < 0" before "native == 0",
 *	            and -0.0 is not less than 0;
 *	cc/dcl.c    init1 skips a zero static initialiser, since BSS is
 *	            already zero -- and vconst() answers 0 for -0.0,
 *	            because it truncates to an int;
 *	6c/txt.c    gmove materialised any zero constant with XORPD of a
 *	            register against itself, which gives +0.0.
 *
 *    and 6l's ieeedtof took -0.0 for a denormal and diagnosed "double
 *    fp to single fp overflow".
 *
 *    The dcl.c one is the shape that survives every fix upstream of it:
 *    the value was folded correctly and then DISCARDED AS A ZERO rather
 *    than written wrongly. It was the last case still failing when the
 *    others were fixed. A file-scope initialiser never goes through
 *    com.c or cgen.c, so it fails on its own.
 *
 *    The sign of zero is not decorative: it is what makes 1/x tell the
 *    two infinities apart, and it is the sign of the result of every
 *    multiplication and division that underflows.
 *
 * Every case below is required by C99, so this passes on gcc, which is
 * how it was checked.
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

/* Kept out of the expression so nothing can be folded away. */
static double dzero(void) { return 0.0; }
static double done(void)  { return 1.0; }
static float  fzero(void) { return 0.0f; }
static float  fone(void)  { return 1.0f; }

/*
 * A static initialiser is folded in dcl.c and written straight to the
 * object file, so it never goes through com.c or cgen.c -- a separate
 * path, and it was separately wrong.
 */
static double negzero = -0.0;

int
main(void)
{
	volatile double d;
	volatile float f;
	double r;

	/*
	 * 1. The usual arithmetic conversions. pi/2 in double and in float
	 * differ by 4.371e-08, so a result rounded to float is unmistakable.
	 */
	{
		double pio2 = 1.57079632679489655800e+00;
		double got;

		got = pio2 + 0x1p-120f;
		ok(got == pio2, "double + float constant stays double");

		f = 1.0f;
		d = pio2;
		got = d + f;
		ok(got == pio2 + 1.0, "double + float variable stays double");

		got = d * f;
		ok(got == pio2, "double * float variable stays double");

		/*
		 * The other order was always right; here so that a failure
		 * says which half of the table moved.
		 */
		got = f + d;
		ok(got == pio2 + 1.0, "float + double stays double");

		/* sizeof through a promotion, which is the rule stated plainly. */
		ok(sizeof(1.0 + 1.0f) == sizeof(double),
			"sizeof(double + float) is sizeof(double)");
	}

	/*
	 * 2. Zero numerators. Integer zero over floating zero is NaN, not
	 * zero, and the sign of the result of 0.0/-1.0 is negative.
	 */
	r = 0 / (dzero() - dzero());
	ok(isnan(r), "0/(0.0) is NaN, not 0");

	r = 0.0 / dzero();
	ok(isnan(r), "0.0/0.0 is NaN");

	r = 0 / -done();
	ok(r == 0.0 && signbit(r), "0/-1.0 is -0.0");

	r = 0.0 / done();
	ok(r == 0.0 && !signbit(r), "0.0/1.0 is +0.0");

	/* Integer 0/x really is 0, and must stay that way. */
	{
		volatile int iz = 0, in = 7;
		ok(iz / in == 0, "integer 0/7 is still 0");
	}

	/*
	 * 3. Infinity. HUGE_VAL and INFINITY must be infinite, and the
	 * library must agree with them.
	 */
	ok(isinf(INFINITY),   "INFINITY is infinite");
	ok(isinf(HUGE_VAL),   "HUGE_VAL is infinite");
	ok(INFINITY > 1.7976931348623157e308, "INFINITY exceeds DBL_MAX");
	ok(-INFINITY < -1.7976931348623157e308, "-INFINITY is below -DBL_MAX");
	ok(isinf(exp(1000.0)), "exp(1000) is infinite");
	ok(exp(1000.0) == INFINITY, "exp(1000) equals INFINITY");
	ok(isnan(cos(INFINITY)), "cos(INFINITY) is NaN");
	ok(log(INFINITY) == INFINITY, "log(INFINITY) is INFINITY");
	ok(isinf(1.0 / dzero()), "1.0/0.0 is infinite");

	/*
	 * 4. The sign of zero, through every route to one: a constant, a
	 * runtime negation, a static initialiser, unary plus, and the
	 * library. Each went through a different piece of the compiler and
	 * each failed separately, so they are listed separately.
	 */
	{
		double z;
		float g;

		z = -0.0;
		ok(z == 0.0 && signbit(z), "the constant -0.0 is negative zero");
		ok(negzero == 0.0 && signbit(negzero),
			"a static -0.0 initialiser is negative zero");
		z = -dzero();
		ok(z == 0.0 && signbit(z), "-(0.0) is negative zero");
		z = -(-dzero());
		ok(z == 0.0 && !signbit(z), "-(-(0.0)) is back to +0.0");

		/* Unary plus is the value of its operand, sign and all. */
		z = +(-0.0);
		ok(z == 0.0 && signbit(z), "+(-0.0) is negative zero");

		/* Ordinary negation must still work. */
		ok(-done() == -1.0, "-(1.0) is -1.0");
		ok(-(-done()) == 1.0, "-(-(1.0)) is 1.0");

		/* float has its own sign bit, in its own place. */
		g = fzero();
		ok(-g == 0.0f && signbit(-g), "float -(0.0f) is negative zero");
		ok(-fone() == -1.0f, "float -(1.0f) is -1.0f");

		/* 1/x is how a program notices. */
		ok(1.0 / -dzero() < 0.0, "1/-0.0 is -inf");
		ok(1.0 / dzero() > 0.0, "1/+0.0 is +inf");

		z = sin(-0.0);
		ok(z == 0.0 && signbit(z), "sin(-0.0) is -0.0");
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
