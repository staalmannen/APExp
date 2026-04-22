#include <string.h>

void *
rawmemchr(const void *s, int c)
{
	const unsigned char *p = s;
	unsigned char ch = (unsigned char)c;
	while(*p != ch)
		p++;
	return (void *)p;
}
