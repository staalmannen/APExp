#include <string.h>

size_t
strlcpy(char *dst, char *src, size_t sz)
{
	char *start;

	start = src;
	if(sz == 0)
		return strlen(start);

	while(sz-- > 0 && (*dst++ = *src++) != '\0')
		;
	if(dst[-1] != '\0')
		dst[-1] = '\0';
	while(*src++)
		;
	return src - start - 1;
}
