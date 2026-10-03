#include <stdlib.h>
#include <errno.h>
#include <limits.h>

unsigned long
strtoul(const char *nptr, char **endptr, int base)
{
	const char *p, *zero;
	unsigned long n, nn;
	int c, ovfl, neg, v, ndig;

	p = (char*)nptr;
	zero = 0;
	neg = 0;
	n = 0;
	ndig = 0;
	ovfl = 0;

	/*
	 * White space
	 */
	for(;;p++){
		switch(*p){
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
		if(*p != '0')
			base = 10;
		else{
			base = 8;
			if(p[1]=='x' || p[1]=='X'){
				zero = p;	/* see Return: */
				p += 2;
				base = 16;
			}
		}
	}else if(base==16 && *p=='0'){
		if(p[1]=='x' || p[1]=='X'){
			zero = p;
			p += 2;
		}
	}else if(base<0 || 36<base)
		goto Return;

	/*
	 * Non-empty sequence of digits
	 */
	for(;; p++,ndig++){
		c = *p;
		v = base;
		if('0'<=c && c<='9')
			v = c - '0';
		else if('a'<=c && c<='z')
			v = c - 'a' + 10;
		else if('A'<=c && c<='Z')
			v = c - 'A' + 10;
		if(v >= base)
			break;
		nn = n*base + v;
		if(nn < n)
			ovfl = 1;
		n = nn;
	}

    Return:
	/*
	 * "0x" with no hex digit after it: C says the subject
	 * sequence is the longest INITIAL subsequence of the
	 * expected form, so this converts the `0' and leaves
	 * endptr on the `x'. It used to consume the `0x' and then
	 * report no conversion at all, so a caller testing
	 * `endptr == nptr' rejected a valid zero. Same fix in all
	 * four strto* files; swept against glibc for the two that
	 * can be (see strtoint-xcheck.c -- `long' is 32-bit here
	 * and 64 on the host, so these two cannot be).
	 */
	if(ndig == 0)
		p = zero ? zero + 1 : nptr;
	if(endptr)
		*endptr = (char *)p;
	if(ovfl){
		errno = ERANGE;
		return ULONG_MAX;
	}
	if(neg)
		return -n;
	return n;
}
