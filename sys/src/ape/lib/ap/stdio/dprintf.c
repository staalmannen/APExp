#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/*
 * dprintf / vdprintf - formatted output to a file descriptor
 *
 * These format into a heap buffer then write() to fd, avoiding
 * any dependency on FILE buffering. This matches the POSIX
 * specification: dprintf writes to a file descriptor, not a FILE*.
 */
int
vdprintf(int fd, const char *fmt, va_list ap)
{
	char *buf;
	int n, written;

	n = vasprintf(&buf, fmt, ap);
	if(n < 0)
		return -1;

	written = (int)write(fd, buf, (size_t)n);
	free(buf);
	return written;
}

int
dprintf(int fd, const char *fmt, ...)
{
	va_list ap;
	int n;

	va_start(ap, fmt);
	n = vdprintf(fd, fmt, ap);
	va_end(ap);
	return n;
}
