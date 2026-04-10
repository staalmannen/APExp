#include "stdio_impl.h"

size_t fwrite(const void *restrict p, size_t recl, size_t nrec, FILE *restrict f){
	size_t total = recl * nrec;
	size_t written;

	if (!total) return 0;

	FLOCK(f);
	written = __fwritex((const unsigned char *)p, total, f);
	FUNLOCK(f);

	return written / recl;
}
