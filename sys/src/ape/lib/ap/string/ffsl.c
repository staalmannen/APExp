#include <string.h>

int
ffsl(long i)
{
	unsigned long u = (unsigned long)i;
	int n;
	if(!u) return 0;
	n = 1;
	if(!(u & 0xffffUL))    { n += 16; u >>= 16; }
	if(!(u & 0x00ffUL))    { n +=  8; u >>=  8; }
	if(!(u & 0x000fUL))    { n +=  4; u >>=  4; }
	if(!(u & 0x0003UL))    { n +=  2; u >>=  2; }
	if(!(u & 0x0001UL))    { n +=  1; }
	return n;
}

int
ffsll(long long i)
{
	unsigned long long u = (unsigned long long)i;
	int n;
	if(!u) return 0;
	n = 1;
	if(!(u & 0xffffffffULL)) { n += 32; u >>= 32; }
	if(!(u & 0x0000ffffULL)) { n += 16; u >>= 16; }
	if(!(u & 0x000000ffULL)) { n +=  8; u >>=  8; }
	if(!(u & 0x0000000fULL)) { n +=  4; u >>=  4; }
	if(!(u & 0x00000003ULL)) { n +=  2; u >>=  2; }
	if(!(u & 0x00000001ULL)) { n +=  1; }
	return n;
}
