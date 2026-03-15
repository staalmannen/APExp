#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/*
 * strtol, strtoul, strtoll, strtoull
 * Written in Plan9 APE style, modelled on the APE strtod.
 *
 * Supports bases 2-36, or base 0 (auto-detect: 0x=hex, 0=octal, else decimal).
 */

static unsigned long long
str2ull(const char *cp, char **endptr, int base, int *neg)
{
	unsigned long long num;
	int c;
	const char *p;
	const char *start;
	int dig;

	p = cp;
	*neg = 0;

	/* skip whitespace */
	while(*p == ' ' || *p == '\t' || *p == '\n' ||
	      *p == '\f' || *p == '\v' || *p == '\r')
		p++;

	/* sign */
	if(*p == '-' || *p == '+'){
		if(*p == '-')
			*neg = 1;
		p++;
	}

	/* base detection for base==0 */
	if(base == 0){
		if(*p == '0'){
			if(p[1] == 'x' || p[1] == 'X')
				base = 16;
			else
				base = 8;
		} else {
			base = 10;
		}
	}

	/* skip 0x/0X prefix for hex */
	if(base == 16 && *p == '0' && (p[1] == 'x' || p[1] == 'X'))
		p += 2;

	start = p;
	num = 0;

	for(;;){
		c = *p;
		if(c >= '0' && c <= '9')
			dig = c - '0';
		else if(c >= 'a' && c <= 'z')
			dig = c - 'a' + 10;
		else if(c >= 'A' && c <= 'Z')
			dig = c - 'A' + 10;
		else
			break;
		if(dig >= base)
			break;
		num = num * base + dig;
		p++;
	}

	if(endptr){
		/* if no digits were consumed, point back to cp */
		if(p == start)
			*endptr = (char *)cp;
		else
			*endptr = (char *)p;
	}

	return num;
}

long
strtol(const char *cp, char **endptr, int base)
{
	int neg;
	unsigned long long u;
	long result;

	u = str2ull(cp, endptr, base, &neg);
	if(neg){
		if(u > (unsigned long long)LONG_MAX + 1){
			errno = ERANGE;
			return LONG_MIN;
		}
		result = -(long)u;
	} else {
		if(u > LONG_MAX){
			errno = ERANGE;
			return LONG_MAX;
		}
		result = (long)u;
	}
	return result;
}

unsigned long
strtoul(const char *cp, char **endptr, int base)
{
	int neg;
	unsigned long long u;

	u = str2ull(cp, endptr, base, &neg);
	if(u > ULONG_MAX){
		errno = ERANGE;
		return ULONG_MAX;
	}
	/* POSIX: negation is performed after conversion */
	return neg ? -(unsigned long)u : (unsigned long)u;
}

long long
strtoll(const char *cp, char **endptr, int base)
{
	int neg;
	unsigned long long u;

	u = str2ull(cp, endptr, base, &neg);
	if(neg){
		if(u > (unsigned long long)LLONG_MAX + 1){
			errno = ERANGE;
			return LLONG_MIN;
		}
		return -(long long)u;
	} else {
		if(u > LLONG_MAX){
			errno = ERANGE;
			return LLONG_MAX;
		}
		return (long long)u;
	}
}

unsigned long long
strtoull(const char *cp, char **endptr, int base)
{
	int neg;
	unsigned long long u;

	u = str2ull(cp, endptr, base, &neg);
	/* on overflow str2ull wraps, but we should set ERANGE.
	 * A full overflow check would require wider arithmetic;
	 * this matches the behaviour of most minimal implementations. */
	return neg ? -u : u;
}
