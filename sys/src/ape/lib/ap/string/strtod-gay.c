/*
 * strtod-gay.c -- NOT BUILT YET. A candidate replacement for
 * string/strtod.c, and it is not finished: see the STATUS block below
 * before touching it, and do not put it in the mkfile until the
 * cross-check is clean.
 *
 * strtod -- correctly rounded decimal to double, David M. Gay's
 * algorithm, on the Bigint kit this tree already carries.
 *
 * WHAT WAS HERE BEFORE, and what it cost. The old APE strtod
 * accumulated the digits in a double -- `num = num*10 + c-'0'' -- and
 * multiplied by `pow10(exp)'. Two roundings, neither of them the one
 * the standard asks for: the significand is rounded while it is being
 * built (17976931348623157 needs 55 bits and a double has 53), and the
 * scale factor is itself a rounded power of ten. Its own first line
 * said so --
 *
 *	 * bug: should detect overflow, set errno = ERANGE, and
 *	 * return +/- HUGE_VAL
 *
 * -- and nobody had put a number to it. sys/lib/tests/strtod-xcheck.c
 * did, on the build host, against glibc:
 *
 *	round-trip of 199887 random doubles through "%.17g":
 *		148018 came back as a DIFFERENT double  (74%)
 *	the powers of ten, 1e-320..1e308:
 *		445 of 629 wrong, 1e308 off by 2e14 ulp
 *
 * A double printed with %.17g is named uniquely, so a correct strtod
 * must return exactly what was printed. Three times in four this one
 * did not, and every program on the system that reads a number got it.
 *
 * WHY GAY RATHER THAN A REWRITE. `stdio/_fconv.c' and
 * `include/fconv.h' are already Gay's bignum kit -- _Balloc, _multadd,
 * _mult, _pow5mult, _lshift, _cmp, _diff, _d2b, _i2b, and the _tens,
 * _bigtens and _tinytens tables -- and `stdio/_dtoa.c' is Gay's dtoa
 * built on it. strtod is the other half of that same package and the
 * half this tree did not have. The header even says so at the top:
 * "The author of this software (_dtoa, strtod) is David M. Gay". So
 * this is the missing file of a library already here, not a new
 * dependency: prefer the link over the patch.
 *
 * HOW IT WORKS, in one paragraph. Parse at most DBL_DIG+1 significant
 * digits into two 32-bit halves and form a first approximation with
 * floating point, exactly when the value is small enough for that to
 * be exact (Gay's `fast path'). Otherwise scale by powers of ten from
 * the tables, then CORRECT: express both the candidate and the decimal
 * input as exact integers times powers of two and five, take their
 * difference exactly, and step the candidate by ulps until the
 * difference says it is the nearest double. The arithmetic that
 * decides is integer and exact; the floating point only gets it close.
 *
 * IEEE ONLY. fconv.h still carries Gay's VAX and IBM arms; every
 * architecture this tree builds for is IEEE, and an untested
 * non-IEEE path is worse than an absent one, so this file requires
 * IEEE_Arith and says so at compile time rather than pretending.
 *

 * STATUS, measured rather than asserted. Built into
 * sys/lib/tests/strtod-xcheck.c on the build host, beside glibc:
 *
 *	section 1, the seven strings Tcl's expr tests use:
 *		6 of 7 EXACT, including DBL_MAX and the overflow to
 *		infinity one ulp past it. The old file got 0 of 7.
 *		The seventh, -929963218616126365E290 (18 digits), is
 *		off by 128 ulp.
 *	section 2, 200000 round-trips through "%.17g":
 *		140173 still wrong, against 148018 for the old file.
 *		Sixteen inputs also SPIN -- the correction loop does
 *		not converge and is only stopped by a cap.
 *
 * So it is right where the old one was catastrophic and no better
 * where the old one was merely bad. Two transcription bugs have been
 * found and fixed and are worth keeping written down, because both
 * were invisible to reading and took one instrumented run each:
 *
 *   1. THE SCALING. `j' in the correction loop is `P + 1 - bbbits' in
 *	the normal case and `bbe + (P - Emin)' for a denormal; an
 *	earlier version computed `bbe - P + 1' and assigned the normal
 *	case to `i' instead of `j'. Every value that needed correcting
 *	diverged: 1e100 spun with aadj = 8.8e71 and came out -inf.
 *
 *   2. THE SIGN SCAN. Gay writes it as a fall-through switch inside a
 *	`for(s = s00;;s++)'; the '+'/'-' arm advances s past the sign
 *	and then breaks out of the SWITCH, so the loop's own s++
 *	advances again and the first digit is lost. Every negative
 *	number came back at 0.44 of its size -- which is what
 *	"-1.797e308" gives when read as ".797e308". Written out
 *	plainly here instead.
 *
 * WHAT IS STILL WRONG is a third one of the same kind, and the
 * evidence narrows it: for -5.5098193881687261e+58 the floating-point
 * approximation is ALREADY BIT-EXACT before the loop, and the loop
 * then moves it 2048 ulp away. So `bd' -- the decimal digits as an
 * exact Bigint -- or the shifts around it disagree with `bb' by more
 * than half an ulp when they should agree exactly. The next step is to
 * print bd and bb for that input rather than to read s2b again: two
 * readings have already passed it as correct.
 *
 * Checked with sys/lib/tests/strtod-xcheck.c, which links this file
 * into a glibc program beside glibc's own strtod.
 */

#include "fconv.h"

#ifndef IEEE_Arith
#error strtod here is IEEE-only; see the note at the top of this file
#endif

/*
 * THREE PIECES OF GAY'S KIT THAT THIS TREE DID NOT KEEP. `_fconv.c'
 * has _Balloc, _multadd, _mult, _pow5mult, _lshift, _cmp, _diff, _d2b
 * and _i2b, but not ulp, b2d or s2b: `_dtoa.c' here was written not to
 * need the first two, and s2b is used by strtod alone. They are static
 * here rather than added to _fconv.c so that nothing already working
 * is disturbed by this file arriving.
 */

/* one unit in the last place of x */
static double
ulp(double x)
{
	Dul a;
	long L;

	a.d = x;
	L = (word0(a) & Exp_mask) - (P-1)*Exp_msk1;
	if (L > 0) {
		word0(a) = L;
		word1(a) = 0;
	}
	else {
		/* denormal: the ulp is a fixed small power of two */
		L = -L >> Exp_shift;
		if (L < Exp_shift) {
			word0(a) = 0x80000 >> L;
			word1(a) = 0;
		}
		else {
			word0(a) = 0;
			L -= Exp_shift;
			word1(a) = L >= 31 ? 1 : 1 << (31 - L);
		}
	}
	return a.d;
}

/* the top P bits of the Bigint a, as a double, with *e its exponent */
static double
b2d(Bigint *a, int *e)
{
	ULong *xa, *xa0, w, y, z;
	int k;
	Dul d;

	xa0 = a->x;
	xa = xa0 + a->wds;
	y = *--xa;
	k = hi0bits(y);
	*e = 32 - k;
	if (k < Ebits) {
		word0(d) = Exp_1 | y >> (Ebits - k);
		w = xa > xa0 ? *--xa : 0;
		word1(d) = y << ((32-Ebits) + k) | w >> (Ebits - k);
		return d.d;
	}
	z = xa > xa0 ? *--xa : 0;
	if (k -= Ebits) {
		word0(d) = Exp_1 | y << k | z >> (32 - k);
		y = xa > xa0 ? *--xa : 0;
		word1(d) = z << k | y >> (32 - k);
	}
	else {
		word0(d) = Exp_1 | y;
		word1(d) = z;
	}
	return d.d;
}

/*
 * The decimal digits as an exact Bigint. nd0 digits sit before the
 * point and nd-nd0 after it; y9 is the first nine already accumulated
 * by the caller, which is why this starts at digit 9.
 */
static Bigint *
s2b(CONST char *s, int nd0, int nd, ULong y9)
{
	Bigint *b;
	int i, k;
	long x, y;

	x = (nd + 8) / 9;
	for(k = 0, y = 1; x > y; y <<= 1, k++) ;
	b = Balloc(k);
	b->x[0] = y9;
	b->wds = 1;
	i = 9;
	if (9 < nd0) {
		s += 9;
		do
			b = multadd(b, 10, *s++ - '0');
		while(++i < nd0);
		s++;
	}
	else
		s += 10;
	for(; i < nd; i++)
		b = multadd(b, 10, *s++ - '0');
	return b;
}

/*
 * ratio(a, b) = a/b as a double, used to size the correction when the
 * candidate is more than one ulp out. Gay's, unchanged apart from the
 * Dul union this tree's fconv.h uses in place of casting a double.
 */
static double
ratio(Bigint *a, Bigint *b)
{
	Dul da, db;
	int k, ka, kb;

	da.d = b2d(a, &ka);
	db.d = b2d(b, &kb);
#ifdef Pack_32
	k = ka - kb + 32*(a->wds - b->wds);
#else
	k = ka - kb + 16*(a->wds - b->wds);
#endif
	if (k > 0)
		word0(da) += k*Exp_msk1;
	else {
		k = -k;
		word0(db) += k*Exp_msk1;
	}
	return da.d / db.d;
}


double
strtod(CONST char *s00, char **se)
{
	int bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign,
		e, e1, esign, i, j, k, nd, nd0, nf, nz, nz0, sign;
	CONST char *s, *s1;
	CONST char *s0;
	double aadj, aadj1, adj;
	Dul rv, rv0;
	long L;
	ULong y, z;
	Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;

	sign = nz0 = nz = 0;
	rv.d = 0.;
	/*
	 * The sign scan, written out rather than as Gay's fall-through
	 * switch inside a for. His spelling advances past the sign and
	 * then leaves the switch, so the loop's own s++ advances AGAIN
	 * and the first digit is skipped. That is exactly what happened
	 * here: every negative number came back 0.44 of its size, which
	 * is what "-1.797...e308" parsed as ".797...e308" gives, and
	 * strtod-xcheck named it in one run by having the positive
	 * values right and the negative ones wrong.
	 */
	for(s = s00; *s == ' ' || *s == '\t'; s++)
		;
	if (*s == '-') {
		sign = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	if (!*s)
		goto ret0;
	if (*s == '0') {
		nz0 = 1;
		while(*++s == '0') ;
		if (!*s)
			goto ret;
	}
	s0 = s;
	y = z = 0;
	for(nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
		if (nd < 9)
			y = 10*y + c - '0';
		else if (nd < 16)
			z = 10*z + c - '0';
	nd0 = nd;
	if (c == '.') {
		c = *++s;
		if (!nd) {
			for(; c == '0'; c = *++s)
				nz++;
			if (c > '0' && c <= '9') {
				s0 = s;
				nf += nz;
				nz = 0;
				goto have_dig;
			}
			goto dig_done;
		}
		for(; c >= '0' && c <= '9'; c = *++s) {
have_dig:
			nz++;
			if (c -= '0') {
				nf += nz;
				for(i = 1; i < nz; i++)
					if (nd++ < 9)
						y *= 10;
					else if (nd <= DBL_DIG + 1)
						z *= 10;
				if (nd++ < 9)
					y = 10*y + c;
				else if (nd <= DBL_DIG + 1)
					z = 10*z + c;
				nz = 0;
			}
		}
	}
dig_done:
	e = 0;
	if (c == 'e' || c == 'E') {
		if (!nd && !nz && !nz0)
			goto ret0;
		s00 = s;
		esign = 0;
		switch(c = *++s) {
		case '-':
			esign = 1;
			/* no break */
		case '+':
			c = *++s;
		}
		if (c >= '0' && c <= '9') {
			while(c == '0')
				c = *++s;
			if (c > '0' && c <= '9') {
				L = c - '0';
				s1 = s;
				while((c = *++s) >= '0' && c <= '9')
					L = 10*L + c - '0';
				if (s - s1 > 8 || L > 19999)
					/*
					 * An exponent big enough to overflow
					 * the int itself: clamp it somewhere
					 * that still means "far too big".
					 */
					e = 19999;
				else
					e = (int)L;
				if (esign)
					e = -e;
			} else
				e = 0;
		} else
			s = s00;
	}
	if (!nd) {
		if (!nz && !nz0)
			goto ret0;
		goto ret;
	}
	e1 = e -= nf;

	/*
	 * Now we have nd0 digits, starting at s0, followed by a
	 * decimal point, followed by nd-nd0 digits.  The number we're
	 * after is the integer represented by those digits times
	 * 10**e
	 */

	if (!nd0)
		nd0 = nd;
	k = nd < DBL_DIG + 1 ? nd : DBL_DIG + 1;
	rv.d = y;
	if (k > 9)
		rv.d = _tens[k - 9] * rv.d + z;
	bd0 = 0;
	if (nd <= DBL_DIG
		&& FLT_ROUNDS == 1
		) {
		if (!e)
			goto ret;
		if (e > 0) {
			if (e <= Ten_pmax) {
				/* exact: one rounding, and it is the right one */
				rv.d *= _tens[e];
				goto ret;
			}
			i = DBL_DIG - nd;
			if (e <= Ten_pmax + i) {
				/*
				 * A fancy test (simplified from Gay's) to
				 * avoid one rounding: scale the significand
				 * up by the slack it has, then by what is
				 * left of the exponent.
				 */
				e -= i;
				rv.d *= _tens[i];
				rv.d *= _tens[e];
				goto ret;
			}
		}
		else if (e >= -Ten_pmax) {
			rv.d /= _tens[-e];
			goto ret;
		}
	}
	e1 += nd - k;

	/* Get starting approximation = rv * 10**e1 */

	if (e1 > 0) {
		if (i = e1 & 15)
			rv.d *= _tens[i];
		if (e1 &= ~15) {
			if (e1 > DBL_MAX_10_EXP) {
ovfl:
				errno = ERANGE;
				word0(rv) = Exp_mask;
				word1(rv) = 0;
				if (bd0)
					goto retfree;
				goto ret;
			}
			if (e1 >>= 4) {
				for(j = 0; e1 > 1; j++, e1 >>= 1)
					if (e1 & 1)
						rv.d *= _bigtens[j];
				/* The last multiplication could overflow. */
				word0(rv) -= P*Exp_msk1;
				rv.d *= _bigtens[j];
				if ((z = word0(rv) & Exp_mask)
				 > Exp_msk1*(DBL_MAX_EXP+Bias-P))
					goto ovfl;
				if (z > Exp_msk1*(DBL_MAX_EXP+Bias-1-P)) {
					/* set to largest number */
					/* (Can't trust DBL_MAX) */
					word0(rv) = Big0;
					word1(rv) = Big1;
				}
				else
					word0(rv) += P*Exp_msk1;
			}
		}
	}
	else if (e1 < 0) {
		e1 = -e1;
		if (i = e1 & 15)
			rv.d /= _tens[i];
		if (e1 &= ~15) {
			e1 >>= 4;
			if (e1 >= 1 << n_bigtens)
				goto undfl;
			for(j = 0; e1 > 1; j++, e1 >>= 1)
				if (e1 & 1)
					rv.d *= _tinytens[j];
			/* The last multiplication could underflow. */
			rv0.d = rv.d;
			rv.d *= _tinytens[j];
			if (!rv.d) {
				rv.d = 2.*rv0.d;
				rv.d *= _tinytens[j];
				if (!rv.d) {
undfl:
					rv.d = 0.;
					errno = ERANGE;
					if (bd0)
						goto retfree;
					goto ret;
				}
				word0(rv) = Tiny0;
				word1(rv) = Tiny1;
				/*
				 * The refinement below can correct the
				 * unlikely case of an under-estimate.
				 */
			}
		}
	}

	/* Now the hard part -- adjusting rv to the correct value.*/

	/* Put digits into bd: true value = bd * 10^e */

	bd0 = s2b(s0, nd0, nd, y);

	for(;;) {
		bd = Balloc(bd0->k);
		Bcopy(bd, bd0);
		bb = _d2b(rv.d, &bbe, &bbbits);	/* rv = bb * 2^bbe */
		bs = i2b(1);

		if (e >= 0) {
			bb2 = bb5 = 0;
			bd2 = bd5 = e;
		}
		else {
			bb2 = bb5 = -e;
			bd2 = bd5 = 0;
		}
		if (bbe >= 0)
			bb2 += bbe;
		else
			bd2 -= bbe;
		bs2 = bb2;
		i = bbe + bbbits - 1;	/* logb(rv) */
		if (i < Emin)		/* denormal */
			j = bbe + (P - Emin);
		else
			j = P + 1 - bbbits;
		bb2 += j;
		bd2 += j;
		i = bb2 < bd2 ? bb2 : bd2;
		if (i > bs2)
			i = bs2;
		if (i > 0) {
			bb2 -= i;
			bd2 -= i;
			bs2 -= i;
		}
		if (bb5 > 0) {
			bs = pow5mult(bs, bb5);
			bb1 = mult(bs, bb);
			Bfree(bb);
			bb = bb1;
		}
		if (bb2 > 0)
			bb = lshift(bb, bb2);
		if (bd5 > 0)
			bd = pow5mult(bd, bd5);
		if (bd2 > 0)
			bd = lshift(bd, bd2);
		if (bs2 > 0)
			bs = lshift(bs, bs2);
		delta = _diff(bb, bd);
		dsign = delta->sign;
		delta->sign = 0;
		i = cmp(delta, bs);
		if (i < 0) {
			/*
			 * Error is less than half an ulp -- check for
			 * special case of mantissa a power of two.
			 */
			if (dsign || word1(rv) || word0(rv) & Bndry_mask)
				break;
			delta = lshift(delta,Log2P);
			if (cmp(delta, bs) > 0)
				goto drop_down;
			break;
		}
		if (i == 0) {
			/* exactly half-way */
			if (dsign) {
				if ((word0(rv) & Bndry_mask1) == Bndry_mask1
				 && word1(rv) == 0xffffffff) {
					/*boundary case -- increment exponent*/
					word0(rv) = (word0(rv) & Exp_mask)
						+ Exp_msk1;
					word1(rv) = 0;
					break;
				}
			}
			else if (!(word0(rv) & Bndry_mask) && !word1(rv)) {
drop_down:
				/* boundary case -- decrement exponent */
				L = word0(rv) & Exp_mask;
				L -= Exp_msk1;
				word0(rv) = L | Bndry_mask1;
				word1(rv) = 0xffffffff;
				break;
			}
			if (!(word1(rv) & LSB))
				break;
			if (dsign)
				rv.d += ulp(rv.d);
			else {
				rv.d -= ulp(rv.d);
				if (!rv.d)
					goto undfl;
			}
			break;
		}
		if ((aadj = ratio(delta, bs)) <= 2.) {
			if (dsign)
				aadj = aadj1 = 1.;
			else if (word1(rv) || word0(rv) & Bndry_mask) {
				if (word1(rv) == Tiny1 && !word0(rv))
					goto undfl;
				aadj = 1.;
				aadj1 = -1.;
			}
			else {
				/*
				 * special case -- power of FLT_RADIX to be
				 * halved
				 */
				if (aadj < 2./FLT_RADIX)
					aadj = 1./FLT_RADIX;
				else
					aadj *= 0.5;
				aadj1 = -aadj;
			}
		}
		else {
			aadj *= 0.5;
			aadj1 = dsign ? aadj : -aadj;
#ifdef Check_FLT_ROUNDS
			switch(FLT_ROUNDS) {
			case 2: /* towards +infinity */
				aadj1 -= 0.5;
				break;
			case 0: /* towards 0 */
			case 3: /* towards -infinity */
				aadj1 += 0.5;
			}
#else
			if (FLT_ROUNDS == 0)
				aadj1 += 0.5;
#endif
		}
		y = word0(rv) & Exp_mask;

		/* Check for overflow */

		if (y == Exp_msk1*(DBL_MAX_EXP+Bias-1)) {
			rv0.d = rv.d;
			word0(rv) -= P*Exp_msk1;
			adj = aadj1 * ulp(rv.d);
			rv.d += adj;
			if ((word0(rv) & Exp_mask) >=
					Exp_msk1*(DBL_MAX_EXP+Bias-P)) {
				if (word0(rv0) == Big0 && word1(rv0) == Big1)
					goto ovfl;
				word0(rv) = Big0;
				word1(rv) = Big1;
				goto cont;
			}
			else
				word0(rv) += P*Exp_msk1;
		}
		else {
			if (y == 0 && rv0.d) {	/* denormal; may underflow */
				rv0.d = rv.d;
				word0(rv) += P*Exp_msk1;
				adj = aadj1 * ulp(rv.d);
				rv.d += adj;
				if ((word0(rv) & Exp_mask) <= P*Exp_msk1) {
					if (word0(rv0) == Tiny0
					 && word1(rv0) == Tiny1)
						goto undfl;
					word0(rv) = Tiny0;
					word1(rv) = Tiny1;
					goto cont;
				}
				else
					word0(rv) -= P*Exp_msk1;
			}
			else {
				adj = aadj1 * ulp(rv.d);
				rv.d += adj;
			}
		}
		z = word0(rv) & Exp_mask;
		if (y == z) {
			/* Can we stop now? */
			L = (long)aadj;
			aadj -= L;
			/*
			 * The tolerances below are conservative.
			 */
			if (dsign || word1(rv) || word0(rv) & Bndry_mask) {
				if (aadj < .4999999 || aadj > .5000001)
					break;
			}
			else if (aadj < .4999999/FLT_RADIX)
				break;
		}
cont:
		Bfree(bb);
		Bfree(bd);
		Bfree(bs);
		Bfree(delta);
	}
	/*
	 * ret0 is "nothing was consumed": it must come BEFORE retfree
	 * and jump over it, or the normal exit falls into it and wipes
	 * the answer it just computed. Nothing is allocated on any path
	 * that reaches it.
	 */
	goto retfree;
ret0:
	s = s00;
	sign = 0;
	goto ret;
retfree:
	Bfree(bb);
	Bfree(bd);
	Bfree(bs);
	Bfree(bd0);
	Bfree(delta);
ret:
	if (se)
		*se = (char *)s;
	return sign ? -rv.d : rv.d;
}
