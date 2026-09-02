#include "stdio_impl.h"
#include <errno.h>
#include <limits.h>
#include <string.h>

/*
 * musl's own vsnprintf, restored.
 *
 * This used to be a wrapper over fmemopen(buf, nbuf, "w") plus
 * vfprintf, with a second path through open_memstream for nbuf above
 * 64K.  Two things were wrong with it, and both are the sort that show
 * up a long way from here:
 *
 * 1. An empty result left the buffer untouched.  fmemopen's mwrite
 *    writes the terminating NUL *after* a write, so formatting zero
 *    characters -- snprintf(buf, n, "%s", "") -- wrote nothing at all
 *    and buf kept whatever it held before.  C99 7.19.6.5p2 says the
 *    result is always null-terminated when n is nonzero.
 *
 *    GNU m4's format() builtin is where this surfaced.  It formats each
 *    conversion into a fresh xasprintf buffer and, for a specifier with
 *    no argument left, formats the empty string -- so the buffer came
 *    back holding the previous conversion instead.  bison's skeleton
 *    (data/skeletons/c.m4:557) formats "%s = %s%s%s" with three
 *    arguments, the last being the separating comma or nothing, so
 *    every token of every generated parser came out as
 *
 *	YYEOF = 0,,
 *
 *    The Portable Object Compiler was the first thing in the tree to
 *    parse a y.tab.c rather than compile it, and so the first to say
 *    so: "y.tab.c:138: fatal: syntax error \",\"".
 *
 * 2. The return value was truncated.  C99 7.19.6.5p3 requires the
 *    number of characters that *would* have been written.  fmemopen's
 *    mwrite short-writes at the end of the buffer, which makes vfprintf
 *    both count short and set the error flag -- so the return was
 *    wrong, and could be -1.  That breaks the standard two-pass idiom
 *    (measure with a small buffer, allocate, format again), which
 *    quietly truncates instead of growing.
 *
 * sn_write reports every byte as written and copies only what fits, so
 * the count stays right however small nbuf is.  A zero buf_size means
 * vfprintf hands each piece straight to it rather than buffering.
 *
 * The old INT_MAX comment is still worth keeping in mind: sprintf calls
 * this with nbuf = INT_MAX, so nothing here may compute nbuf-1 as a
 * size in a way that can overflow -- c.n is a size_t and n is bounded
 * by INT_MAX just below, so it cannot.
 */

struct cookie {
	char *s;
	size_t n;
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static size_t sn_write(FILE *f, const unsigned char *s, size_t l)
{
	struct cookie *c = f->cookie;
	size_t k = MIN(c->n, (size_t)(f->wpos - f->wbase));
	if (k) {
		memcpy(c->s, f->wbase, k);
		c->s += k;
		c->n -= k;
	}
	k = MIN(c->n, l);
	if (k) {
		memcpy(c->s, s, k);
		c->s += k;
		c->n -= k;
	}
	*c->s = 0;
	f->wpos = f->wbase = f->buf;
	return l;
}

int vsnprintf(char *buf, size_t nbuf, const char *fmt, va_list args){
	unsigned char b[1];
	char dummy[1];
	struct cookie c;
	FILE f;

	if (nbuf > INT_MAX) {
		errno = EOVERFLOW;
		return -1;
	}

	c.s = nbuf ? buf : dummy;
	c.n = nbuf ? nbuf-1 : 0;

	memset(&f, 0, sizeof f);
	f.lbf = EOF;
	f.write = sn_write;
	f.lock = -1;
	f.buf = b;
	f.buf_size = 0;
	f.cookie = &c;
	f.fd = -1;

	*c.s = 0;
	return vfprintf(&f, fmt, args);
}
