#include "stdio_impl.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

size_t __stdio_write(FILE *f, const unsigned char *buf, size_t len)
{
	ssize_t cnt;
	size_t written = 0;

	/* First, flush any pending data in write buffer */
	if (f->wpos > f->wbase) {
		size_t to_write = f->wpos - f->wbase;
		cnt = write(f->fd, f->wbase, to_write);
		if (cnt < 0) {
			f->flags |= F_ERR;
			f->wpos = f->wbase = f->wend = f->buf;
			return 0;
		}
		/* If partial write, we have a problem - just clear buffer */
		f->wpos = f->wbase = f->buf;
		f->wend = f->buf + f->buf_size;
	}

	/* Now write the new data */
	if (len > 0) {
		cnt = write(f->fd, buf, len);
		if (cnt < 0) {
			f->flags |= F_ERR;
			f->wpos = f->wbase = f->wend = f->buf;
			return 0;
		}
		written = (size_t)cnt;

		/* If partial write, move remainder to buffer */
		if (written < len) {
			size_t remaining = len - written;
			memcpy(f->wpos, buf + written, remaining);
			f->wpos += remaining;
		}
	}

	/* Reset buffer pointers on success */
	if (f->wpos == f->wbase) {
		f->wend = f->buf + f->buf_size;
	}

	return len;
}

