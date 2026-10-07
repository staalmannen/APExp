#include "stdio_impl.h"

int __towrite(FILE *f)
{
	f->mode |= f->mode-1;
	if (f->flags & F_NOWR) {
		f->flags |= F_ERR;
		return EOF;
	}
	/* Clear read buffer (easier than summoning nasal demons) */
	f->rpos = f->rend = 0;

	/* Activate write through the buffer. */
	f->wpos = f->wbase = f->buf;
	f->wend = f->buf + f->buf_size;

	return 0;
}

/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
hidden void __towrite_needs_stdio_exit()
{
	__stdio_exit_needed();
}
