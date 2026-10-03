#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/*
 * This was `(1LL<<63)' -- which is **not the largest unsigned long
 * long**, and `strtoul.c' beside it uses the right thing
 * (`ULONG_MAX'). Two consequences, both real, and the second is not
 * the one it looks like:
 *
 *   - the saturation value on overflow was 0x8000000000000000 where
 *     C says ULLONG_MAX, so `strtoull("18446744073709551615")' --
 *     a legal value -- answered 9223372036854775808 with ERANGE;
 *
 *   - `m = UVLONG_MAX/base' is the threshold the accumulation loop
 *     tests, and the literal is SIGNED: `1LL<<63' is LLONG_MIN, the
 *     division is signed, and the negative quotient converts to an
 *     unsigned value just under ULLONG_MAX. So the threshold was not
 *     halved, it was effectively DISABLED, and overflow detection
 *     fell back on the `nn < n' wrap test alone -- which misses an
 *     overflow that wraps more than once. `strtoull("0777777777
 *     777777777777", 16)' returned 8608480567731124087 and no error.
 *
 * *I wrote "halved" here first, from reading the expression rather
 * than evaluating it.* The control is what corrected it: restoring
 * the exact original line makes `strtoint-xcheck' report 28 wrong,
 * and the named cases are the wrap misses, not a band of false
 * ERANGEs.
 *
 * Found by READING, while chasing something else entirely, so
 * nothing had ever measured it; `strtoint-xcheck.c' sweeps it now.
 */
#define UVLONG_MAX	(~0ULL)

unsigned long long
strtoull(char *nptr, char **endptr, int base)
{
	char *p, *zero;
	unsigned long long n, nn, m;
	int c, ovfl, v, neg, ndig;

	p = nptr;
	zero = 0;
	neg = 0;
	n = 0;
	ndig = 0;
	ovfl = 0;

	/*
	 * White space
	 */
	for(;; p++) {
		switch(*p) {
		case ' ':
		case '\t':
		case '\n':
		case '\f':
		case '\r':
		case '\v':
			continue;
		}
		break;
	}

	/*
	 * Sign
	 */
	if(*p == '-' || *p == '+')
		if(*p++ == '-')
			neg = 1;

	/*
	 * Base
	 */
	if(base == 0) {
		base = 10;
		if(*p == '0') {
			base = 8;
			if(p[1] == 'x' || p[1] == 'X'){
				zero = p;	/* see Return: */
				p += 2;
				base = 16;
			}
		}
	} else
	if(base == 16 && *p == '0') {
		if(p[1] == 'x' || p[1] == 'X'){
			zero = p;
			p += 2;
		}
	} else
	if(base < 0 || 36 < base)
		goto Return;

	/*
	 * Non-empty sequence of digits
	 */
	m = UVLONG_MAX/base;
	for(;; p++,ndig++) {
		c = *p;
		v = base;
		if('0' <= c && c <= '9')
			v = c - '0';
		else
		if('a' <= c && c <= 'z')
			v = c - 'a' + 10;
		else
		if('A' <= c && c <= 'Z')
			v = c - 'A' + 10;
		if(v >= base)
			break;
		if(n > m)
			ovfl = 1;
		nn = n*base + v;
		if(nn < n)
			ovfl = 1;
		n = nn;
	}

Return:
	/*
	 * `ndig == 0' with `zero' set is the "0x" case: C says the
	 * subject sequence is the longest INITIAL subsequence of the
	 * expected form, so `strtoull("0x", &e, 16)' converts the `0'
	 * and leaves `e' on the `x'. This consumed the `0x' and then
	 * reported no conversion at all, so a caller testing
	 * `endptr == nptr' rejected a valid zero. Measured against
	 * glibc by `sys/lib/tests/strtoint-xcheck.c'.
	 */
	if(ndig == 0)
		p = zero ? zero + 1 : nptr;
	if(endptr)
		*endptr = p;
	if(ovfl){
		errno = ERANGE;
		return UVLONG_MAX;
	}
	if(neg)
		return -n;
	return n;
}
