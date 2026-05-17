#include "stdio_impl.h"

long ftell(FILE *f){
	off_t seekp;

	_FLOCK(f);

	if (f->fd < 0) {
		_FUNLOCK(f);
		return -1;
	}

	seekp = lseek(f->fd, 0, SEEK_CUR);
	if (seekp < 0) {
		_FUNLOCK(f);
		return -1;
	}

	/* Adjust for buffered data */
	seekp -= (f->rend - f->rpos);
	seekp += (f->wpos - f->wbase);

	_FUNLOCK(f);
	return seekp;
}

