#include "stdio_impl.h"
#include <string.h>

size_t fread(void *restrict p, size_t recl, size_t nrec, FILE *restrict f){
	unsigned char *s = (unsigned char *)p;
	size_t total = recl * nrec;
	size_t bytes = 0;

	FLOCK(f);

	while (bytes < total) {
		size_t avail = f->rend - f->rpos;
		if (avail > 0) {
			/* Data in read buffer */
			size_t n = (total - bytes < avail) ? (total - bytes) : avail;
			memcpy(s + bytes, f->rpos, n);
			f->rpos += n;
			bytes += n;
		} else {
			/* Need to refill buffer */
			if (__toread(f)) {
				/* Cannot transition to read mode */
				break;
			}

			/* Read into buffer */
			size_t n = f->read(f, f->buf, f->buf_size);
			if (n == 0) {
				/* EOF */
				f->flags |= F_EOF;
				break;
			}
			if (n == (size_t)-1) {
				/* Error */
				f->flags |= F_ERR;
				break;
			}

			f->rpos = f->buf;
			f->rend = f->buf + n;
		}
	}

	FUNLOCK(f);

	return bytes / recl;
}

