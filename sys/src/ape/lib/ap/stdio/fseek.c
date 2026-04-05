#include "stdio_impl.h"
#include <errno.h>

int fseek(FILE *f, long offs, int type){
	off_t ret;

	FLOCK(f);

	if (f->fd < 0) {
		FUNLOCK(f);
		return -1;
	}

	/* Flush write buffer if needed */
	if (f->wpos > f->wbase) {
		if (f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase)
			!= (size_t)(f->wpos - f->wbase)) {
			f->flags |= F_ERR;
			FUNLOCK(f);
			return -1;
		}
	}

	/* Seek to position */
	ret = lseek(f->fd, offs, type);
	if (ret < 0) {
		f->flags |= F_ERR;
		FUNLOCK(f);
		return -1;
	}

	/* Clear read buffer on successful seek */
	f->rpos = f->rend = 0;
	f->flags &= ~(F_EOF | F_ERR);

	FUNLOCK(f);
	return 0;
}


