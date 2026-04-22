#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*
 * vasnprintf - like vasprintf but with a hint buffer.
 * If resultbuf is non-NULL and the result fits in *lengthp bytes,
 * writes into resultbuf and returns it. Otherwise allocates a new
 * buffer. Caller must free the returned pointer only if it != resultbuf.
 */
char *
vasnprintf(char *resultbuf, size_t *lengthp, const char *fmt, va_list ap)
{
	va_list ap2;
	int n;

	va_copy(ap2, ap);
	n = vsnprintf(resultbuf, resultbuf ? *lengthp : 0, fmt, ap2);
	va_end(ap2);

	if(n < 0)
		return NULL;
	if(resultbuf && (size_t)n < *lengthp){
		*lengthp = (size_t)n;
		return resultbuf;
	}

	resultbuf = malloc((size_t)n + 1);
	if(!resultbuf)
		return NULL;
	vsnprintf(resultbuf, (size_t)n + 1, fmt, ap);
	*lengthp = (size_t)n;
	return resultbuf;
}

char *
asnprintf(char *resultbuf, size_t *lengthp, const char *fmt, ...)
{
	va_list ap;
	char *res;
	va_start(ap, fmt);
	res = vasnprintf(resultbuf, lengthp, fmt, ap);
	va_end(ap);
	return res;
}
