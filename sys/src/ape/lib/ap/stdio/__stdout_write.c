#include "stdio_impl.h"
#include <unistd.h>
#include <errno.h>

/* Unbuffered write for stdout - always flushes immediately */
size_t __stdout_write(FILE *f, const unsigned char *buf, size_t len)
{
	ssize_t cnt;

	if (len == 0) return 0;

	cnt = write(f->fd, buf, len);

	if (cnt < 0) {
		f->flags |= F_ERR;
		return 0;
	}

	return (size_t)cnt;
}

