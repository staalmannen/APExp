#include "stdio_impl.h"
#include <string.h>

int sscanf(const char *s, const char *fmt, ...){
	int n;
	va_list args;
	FILE *f;

	f = fmemopen((char *)s, strlen(s), "r");
	if (!f) return EOF;

	va_start(args, fmt);
	n=vfscanf(f, fmt, args);
	va_end(args);
	fclose(f);

	return n;
}

