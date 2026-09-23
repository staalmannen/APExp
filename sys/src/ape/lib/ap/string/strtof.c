/*
 * strtof -- decimal to float, correctly rounded.
 *
 * WHAT WAS HERE BEFORE was a second copy of the old APE parser, with
 * the same bug: digits accumulated in a double and multiplied by
 * pow10(exp), two roundings and neither of them the one the standard
 * asks for. strtod-xcheck measured the strtod copy of it at 148018 of
 * 199887 round-trips wrong.
 *
 * AND `(float)strtod(s)' IS NOT ENOUGH, which was measured rather than
 * assumed. Rounding a decimal to 53 bits and then to 24 is not the
 * same operation as rounding it to 24: when the correctly rounded
 * double lands exactly on a midpoint between two floats, the second
 * rounding no longer knows which side of that midpoint the decimal was
 * on and falls back on round-half-to-even. Ordinary inputs never
 * notice -- 200000 float round-trips and 200000 seventeen-digit random
 * decimals were all correct -- but decimals BUILT to sit a hair off a
 * float midpoint fail, and sys/lib/tests/strtof-xcheck.c section 5
 * measured 12709 of 39694 wrong. So the shortcut had to go.
 *
 * WHAT IT DOES INSTEAD. `_strtod_cmp' returns the nearest double AND
 * which side of it the exact decimal lay, because strtod's correction
 * loop has the decimal as an exact Bigint and can simply be asked. If
 * that double is a float midpoint and the decimal was not on it, one
 * step of nextafter in the right direction moves it off the tie before
 * the narrowing, and the narrowing then rounds the way it should. If
 * the decimal WAS the midpoint, the tie is real and round-half-to-even
 * is the right answer, so nothing is done.
 *
 * The nudge is conditional on being exactly on a midpoint, and that is
 * not fussiness: a double one ulp away from a midpoint would be moved
 * ONTO one by an unconditional nudge, turning a decided case into a
 * tie.
 *
 * ERRNO. strtod reports ERANGE for the DOUBLE range; the float range
 * is narrower at both ends, so overflow to infinity and underflow to
 * zero are reported here as well. Landing on a subnormal float is not
 * an error.
 */

/*
 * fconv.h FIRST, and that is load-bearing. It defines _RESEARCH_SOURCE
 * before pulling <float.h>, and amd64's float_arch.h only defines
 * IEEE_8087 under that name. Including <float.h> ahead of it leaves
 * the guard set with IEEE_8087 undefined, and fconv.h then reaches its
 * own deliberate syntax error -- "Exactly one of IEEE_8087,
 * IEEE_MC68k, VAX, or IBM should be defined." -- which is what the
 * first build of this file hit.
 */
#include "fconv.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>

/*
 * Is d exactly halfway between two adjacent floats?
 *
 * Asked by averaging the two floats that bracket d rather than by
 * picking the bits apart: that is exact (both are doubles, and their
 * sum has at most 25 significand bits), and it stays correct in the
 * subnormal range, where a float's step is a fixed 2^-149 and the
 * bit pattern argument for normal floats does not hold.
 */
static int
floatmidpoint(double d)
{
	float a;
	double lo, hi;

	if(d == 0 || !isfinite(d))
		return 0;
	a = (float)d;
	if((double)a == d)		/* d IS a float: not a midpoint */
		return 0;
	if(isinf(a)){
		/*
		 * Above FLT_MAX the neighbour is not a float at all. The
		 * boundary that decides overflow is the midpoint between
		 * FLT_MAX and 2^128, which is where the narrowing switches
		 * to infinity.
		 */
		lo = (double)FLT_MAX;
		hi = ldexp(1.0, 128);
		if(d < 0){
			lo = -lo;
			hi = -hi;
		}
		return d == (lo + hi) / 2;
	}
	lo = (double)a;
	hi = (double)nextafterf(a, d < (double)a ? -INFINITY : INFINITY);
	if(!isfinite(hi))
		return 0;
	return d == (lo + hi) / 2;
}

float
strtof(const char *cp, char **endptr)
{
	double d;
	float f;
	int cmp;

	d = _strtod_cmp(cp, endptr, &cmp);
	if(cmp != 0 && floatmidpoint(d))
		d = nextafter(d, cmp > 0 ? INFINITY : -INFINITY);
	f = (float)d;
	if(isinf(f) && isfinite(d))
		errno = ERANGE;
	else if(f == 0 && d != 0)
		errno = ERANGE;
	return f;
}
