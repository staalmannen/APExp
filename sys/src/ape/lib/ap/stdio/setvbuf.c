#include "stdio_impl.h"
#include <stdlib.h>

int setvbuf(FILE *f, char *buf, int mode, size_t size){
	FLOCK(f);

	/* Flush any pending writes (write(f,0,0) is the musl flush-signal) */
	if (f->wpos > f->wbase) {
		f->write(f, 0, 0);
	}

	/* Clear buffers */
	f->rpos = f->rend = 0;
	f->wpos = f->wbase = f->wend = 0;

	if (size == 0) {
		f->buf = NULL;
		f->buf_size = 0;
		f->lbf = EOF;
		FUNLOCK(f);
		return 0;
	}

	if (mode == _IONBF) {
		f->buf = NULL;
		f->buf_size = 0;
		f->lbf = EOF;
		FUNLOCK(f);
		return 0;
	}

	if (buf == NULL) {
		buf = malloc(size);
		if (!buf) {
			FUNLOCK(f);
			return -1;
		}
		f->flags |= F_SVB;
	}

	f->buf = (unsigned char *)buf;
	f->buf_size = size;
	f->wbase = f->wpos = (unsigned char *)buf;
	f->wend = (unsigned char *)buf + size;

	if (mode == _IOLBF) {
		f->lbf = '\n';
	} else {
		f->lbf = EOF;
	}

	FUNLOCK(f);
	return 0;
}

