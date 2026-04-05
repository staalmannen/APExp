#include "stdio_impl.h"
#include <unistd.h>
#include <errno.h>

size_t __stdio_read(FILE *f, unsigned char *buf, size_t len)
{
	ssize_t cnt;

	/* Simple approach: just read directly into the provided buffer */
	cnt = read(f->fd, buf, len);

	if (cnt <= 0) {
		if (cnt == 0) {
			f->flags |= F_EOF;
		} else {
			f->flags |= F_ERR;
		}
		return 0;
	}

	return (size_t)cnt;
}

