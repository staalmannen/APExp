/*
 * scalbn.c -- musl's, with a translation mistake undone.
 *
 * `y *= 2^1023' was here, and in C that is `2 XOR 1023' -- an INTEGER
 * bitwise exclusive-or, 1021 -- not two to the power of anything. musl
 * writes `0x1p1023', a C99 hex float literal, and someone read the `p'
 * as "power of" and wrote it out as `^'. It compiles, silently, and
 * multiplies by 1021.
 *
 * WHAT IT COST. Tcl's expr-28.527, expr-30.1, expr-30.2, expr-39.21,
 * expr-50.1 and expr-old-37.21 -- everything at or above
 * 1.7976931348623155e+308 came back infinite, including values that
 * are perfectly representable. Tcl's own tclStrToD.c had the right
 * answer in hand and then called SafeLdExp, which calls ldexp, which
 * is scalbn; instrumented, it showed `Pow10TimesFrExp -> 0.99999...
 * machexp=1024' followed by `SafeLdExp -> 2041.9999999999993'. That
 * factor is 2042 = 1021 * 2, and 1021 is 2 XOR 1023 exactly.
 *
 * AND THE HOST CROSS-CHECK MISSED IT, which is the lesson worth
 * keeping. scalbn was swept against glibc's over 299876 values and
 * reported 0 wrong -- with `n' drawn from rand()%200 - 100, so the
 * branch that is wrong was never entered. *A check that cannot fail
 * is not a check*, and a sweep that never reaches a branch has not
 * tested it. sys/lib/tests/ldexp-test.c now walks the whole exponent
 * range.
 *
 * 89 other files under math/ use `0x1p...' literals and are fine, so
 * kencc's hex floats work; these two were mistyped, not miscompiled.
 */
#include <math.h>
#include <stdint.h>

double scalbn(double x, int n)
{
	union {double f; uint64_t i;} u;
	double y = x;

	if (n > 1023) {
		y *= 0x1p1023;
		n -= 1023;
		if (n > 1023) {
			y *= 0x1p1023;
			n -= 1023;
			if (n > 1023)
				n = 1023;
		}
	} else if (n < -1022) {
		/* make sure final n < -53 to avoid double
		   rounding in the subnormal range */
		y *= 0x1p-1022 * 0x1p53;
		n += 1022 - 53;
		if (n < -1022) {
			y *= 0x1p-1022 * 0x1p53;
			n += 1022 - 53;
			if (n < -1022)
				n = -1022;
		}
	}
	u.i = (uint64_t)(0x3ff+n)<<52;
	x = y * u.f;
	return x;
}
