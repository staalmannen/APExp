#include "stdio_impl.h"

off_t ftello(FILE *f){
	off_t seekp;

	FLOCK(f);

	if (f->fd < 0) {
		FUNLOCK(f);
		return -1;
	}

	seekp = lseek(f->fd, 0, SEEK_CUR);
	if (seekp < 0) {
		FUNLOCK(f);
		return -1;
	}

	/* Adjust for buffered data */
	seekp -= (f->rend - f->rpos);
	seekp += (f->wpos - f->wbase);

	FUNLOCK(f);
	return seekp;
}

