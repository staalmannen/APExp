/*
 * __fopen_rb_ca / __fclose_ca -- caller-allocated FILE helpers
 *
 * musl uses these to open files with a pre-allocated FILE struct and buffer
 * to avoid malloc.  In APExp we simply delegate to fopen/fclose; the
 * pre-allocated struct (_f) and buffer (_buf) parameters are unused.
 */

#include "stdio_impl.h"
#include <stdio.h>
#include <errno.h>

/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
hidden struct _IO_FILE *
__fopen_rb_ca(const char *path, struct _IO_FILE *f, unsigned char *buf, size_t buf_sz)
{
	(void)f;
	(void)buf;
	(void)buf_sz;
	return fopen(path, "rb");
}

hidden int
__fclose_ca(struct _IO_FILE *f)
{
	return fclose(f);
}
