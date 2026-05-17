#include "stdio_impl.h"
#include <string.h>

int fputs(const char *s, FILE *f)
{
	size_t len;

	if (!s) return EOF;

	_FLOCK(f);

	len = strlen(s);
	if (f->write(f, (const unsigned char *)s, len) != len) {
		_FUNLOCK(f);
		return EOF;
	}

	_FUNLOCK(f);
	return 0;
}

