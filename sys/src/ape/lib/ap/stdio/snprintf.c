#include "stdio_impl.h"

int snprintf(char *buf, size_t nbuf, const char *fmt, ...){
	int n;
	va_list args;

	va_start(args, fmt);
	n=vsnprintf(buf, nbuf, fmt, args);
	va_end(args);

	return n;
}

