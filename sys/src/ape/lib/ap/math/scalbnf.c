/*
 * scalbnf.c -- musl's, with a translation mistake undone.
 *
 * `y *= 2^127' was here, and in C that is `2 XOR 127' -- an INTEGER
 * bitwise exclusive-or, 125 -- not two to the power of anything. musl
 * writes `0x1p127', a C99 hex float literal, and someone read the `p'
 * as "power of" and wrote it out as `^'. It compiles, silently, and
 * multiplies by 125.
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

float scalbnf(float x, int n)
{
	union {float f; uint32_t i;} u;
	float y = x;

	if (n > 127) {
		y *= 0x1p127f;
		n -= 127;
		if (n > 127) {
			y *= 0x1p127f;
			n -= 127;
			if (n > 127)
				n = 127;
		}
	} else if (n < -126) {
		y *= 0x1p-126f * 0x1p24f;
		n += 126 - 24;
		if (n < -126) {
			y *= 0x1p-126f * 0x1p24f;
			n += 126 - 24;
			if (n < -126)
				n = -126;
		}
	}
	u.i = (uint32_t)(0x7f+n)<<23;
	x = y * u.f;
	return x;
}
