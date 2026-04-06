#include "stdio_impl.h"
#include <string.h>

int fputs(const char *s, FILE *f)
{
	size_t len;

	if (!s) return EOF;

	FLOCK(f);

	len = strlen(s);
	if (f->write(f, (const unsigned char *)s, len) != len) {
		FUNLOCK(f);
		return EOF;
	}

	FUNLOCK(f);
	return 0;
}

