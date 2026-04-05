#include "stdio_impl.h"
#include <string.h>

size_t __fwritex(const unsigned char *restrict s, size_t l, FILE *restrict f)
{
	return f->write(f, s, l);
}

