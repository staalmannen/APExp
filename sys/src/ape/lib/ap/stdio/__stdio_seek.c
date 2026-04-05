#include "stdio_impl.h"
#include <unistd.h>

off_t __stdio_seek(FILE *f, off_t off, int whence)
{
	/* Flush write buffer before seeking */
	if (f->wpos > f->wbase) {
		if (write(f->fd, f->wbase, f->wpos - f->wbase) < 0) {
			return -1;
		}
		f->wpos = f->wbase = f->buf;
		f->wend = f->buf + f->buf_size;
	}

	/* Clear read buffer */
	f->rpos = f->rend = 0;

	/* Perform the seek */
	return lseek(f->fd, off, whence);
}

