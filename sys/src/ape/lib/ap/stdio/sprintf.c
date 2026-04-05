#include "stdio_impl.h"

int sprintf(char *buf, const char *fmt, ...){
	int n;
	va_list args;

	va_start(args, fmt);
	n=vsnprintf(buf, 2147483647, fmt, args);
	va_end(args);

	return n;
}


