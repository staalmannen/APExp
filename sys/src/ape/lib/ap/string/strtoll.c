#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>

#define VLONG_MAX	~(1LL<<63)
#define VLONG_MIN	(1LL<<63)

long long
strtoll(char *nptr, char **endptr, int base)
{
	char *p, *zero;
	unsigned long long n, m, cutoff, lastv;
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
	if(*p=='-' || *p=='+')
		if(*p++ == '-')
			neg = 1;

	/*
	 * Base
	 */
	if(base==0){
		base = 10;
		if(*p == '0') {
			base = 8;
			if(p[1]=='x' || p[1]=='X') {
				zero = p;	/* see Return: */
				p += 2;
				base = 16;
			}
		}
	} else
	if(base==16 && *p=='0') {
		if(p[1]=='x' || p[1]=='X') {
			zero = p;
			p += 2;
		}
	} else
	if(base<0 || 36<base)
		goto Return;

	/*
	 * Non-empty sequence of digits
	 */
	/*
	 * Accumulated UNSIGNED, against a limit that depends on the
	 * sign. The magnitude of LLONG_MIN is one MORE than LLONG_MAX,
	 * and the old loop accumulated into a signed `long long'
	 * against `VLONG_MAX/base' either way -- so
	 * `strtoll("-9223372036854775808")' answered ERANGE for a value
	 * that is exactly representable. Measured against glibc by
	 * `sys/lib/tests/strtoint-xcheck.c', which is also what says
	 * the rewrite below did not break the other 1418 cases.
	 */
	cutoff = neg ? (unsigned long long)VLONG_MAX + 1
		     : (unsigned long long)VLONG_MAX;
	m = cutoff/base;
	lastv = cutoff%base;
	for(;; p++,ndig++) {
		c = *p;
		v = base;
		if('0'<=c && c<='9')
			v = c - '0';
		else
		if('a'<=c && c<='z')
			v = c - 'a' + 10;
		else
		if('A'<=c && c<='Z')
			v = c - 'A' + 10;
		if(v >= base)
			break;
		if(n > m || (n == m && (unsigned long long)v > lastv))
			ovfl = 1;
		else
			n = n*base + v;
	}

Return:
	/*
	 * `ndig == 0' with `zero' set is the "0x" case: C says the
	 * subject sequence is the longest INITIAL subsequence of the
	 * expected form, so `strtol("0x", &e, 16)' converts the `0'
	 * and leaves `e' on the `x' -- it is a successful conversion
	 * of zero, not a failure. This consumed the `0x' and then
	 * reported no conversion at all, so a caller testing
	 * `endptr == nptr' rejected a valid number. glibc, musl and
	 * the BSDs all answer 0 with endptr at nptr+1.
	 */
	if(ndig == 0)
		p = zero ? zero + 1 : nptr;
	if(endptr)
		*endptr = p;
	if(ovfl){
		errno = ERANGE;
		if(neg)
			return VLONG_MIN;
		return VLONG_MAX;
	}
	if(neg)
		return (long long)(0ULL - n);
	return (long long)n;
}

intmax_t
strtoimax(char *nptr, char **endptr, int base)
{
	return strtoll(nptr, endptr, base);
}
