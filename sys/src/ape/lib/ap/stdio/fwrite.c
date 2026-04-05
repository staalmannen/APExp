#include "stdio_impl.h"
#include <string.h>

size_t fwrite(const void *restrict p, size_t recl, size_t nrec, FILE *restrict f){
	const unsigned char *s = (const unsigned char *)p;
	size_t total = recl * nrec;
	size_t bytes = 0;

	FLOCK(f);

	while (bytes < total) {
		size_t avail = f->wend - f->wpos;
		if (avail > 0) {
			/* Space in write buffer */
			size_t n = (total - bytes < avail) ? (total - bytes) : avail;
			memcpy(f->wpos, s + bytes, n);
			f->wpos += n;
			bytes += n;

			/* Check for line buffering trigger */
			if (f->lbf != EOF) {
				for (size_t i = 0; i < n; i++) {
					if (f->wpos[-n+i] == f->lbf) {
						/* Flush on newline */
						if (f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase)
							!= (size_t)(f->wpos - f->wbase)) {
							f->flags |= F_ERR;
							FUNLOCK(f);
							return bytes / recl;
						}
						f->wpos = f->wbase;
						break;
					}
				}
			}
		} else {
			/* Buffer full, flush it */
			if (__towrite(f)) {
				FUNLOCK(f);
				return bytes / recl;
			}

			if (f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase)
				!= (size_t)(f->wpos - f->wbase)) {
				f->flags |= F_ERR;
				FUNLOCK(f);
				return bytes / recl;
			}
			f->wpos = f->wbase;
		}
	}

	FUNLOCK(f);
	return bytes / recl;
}

