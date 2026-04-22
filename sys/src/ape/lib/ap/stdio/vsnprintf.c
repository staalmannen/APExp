#include "stdio_impl.h"
#include <string.h>
#include <stdlib.h>

int vsnprintf(char *buf, size_t nbuf, const char *fmt, va_list args){
	int n;
	FILE *f;

	if (nbuf > 65536) {
		char *mem = NULL;
		size_t len = 0;
		f = open_memstream(&mem, &len);
		if (!f) return -1;
		n = vfprintf(f, fmt, args);
		fclose(f);
		if (n >= 0 && mem) {
			/* Use actual length, not nbuf-1: nbuf may be INT_MAX
			 * (from sprintf) making strncpy/buf[] index overflow. */
			size_t copy_len = ((size_t)n < nbuf - 1) ? (size_t)n : nbuf - 1;
			memcpy(buf, mem, copy_len);
			buf[copy_len] = '\0';
			free(mem);
		}
		return n;
	}

	f = fmemopen(buf, nbuf, "w");
	if (!f)
		return -1;

	n=vfprintf(f, fmt, args);
	fclose(f);

	return n;
}


