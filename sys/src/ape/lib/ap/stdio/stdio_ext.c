#include "stdio_impl.h"

/*
 * Solaris-derived <stdio_ext.h> accessors, in the form musl implements
 * them. gnulib reaches for these first: freadahead.h, fseterr.h and
 * fwriting.h each start with an
 *
 *	#if HAVE___FREADAHEAD	/ * musl libc * /
 *	# include <stdio_ext.h>
 *	# define freadahead(stream) __freadahead (stream)
 *
 * branch, and fall back to poking at FILE internals per platform only
 * when it is absent. APE's FILE is musl's, so supplying these lets
 * gnulib take the supported path instead of guessing at our layout.
 */

/* Bytes readable from f's buffer without touching the underlying fd.
   ungetc pushes back by moving rpos, so those bytes are counted too. */
size_t
__freadahead(FILE *f)
{
	return f->rend ? (size_t)(f->rend - f->rpos) : 0;
}

/* Set f's error indicator, as if a write had failed. */
void
__fseterr(FILE *f)
{
	f->flags |= F_ERR;
}

/* Nonzero if f is write-oriented: either it can never be read, or it
   has an active write buffer. */
int
__fwriting(FILE *f)
{
	return (f->flags & F_NORD) || f->wend != 0;
}

/* Nonzero if f is read-oriented. The mirror of __fwriting. */
int
__freading(FILE *f)
{
	return (f->flags & F_NOWR) || f->rend != 0;
}
