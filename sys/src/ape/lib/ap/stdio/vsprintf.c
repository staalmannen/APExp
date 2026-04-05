#include "stdio_impl.h"

int vsprintf(char *buf, const char *fmt, va_list args){
	return vsnprintf(buf, 2147483647, fmt, args);
}

