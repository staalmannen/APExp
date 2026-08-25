#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <xalloc.h>

/*
 * xalloc_die is deliberately not here. It is replaceable -- a program
 * may define its own -- so it has to be alone in its object file, or
 * defining one drags this whole object in behind it and the linker
 * reports a redefinition. See xalloc_die.c.
 */

void *
xmalloc(size_t n)
{
	void *p = malloc(n);
	if(!p && n != 0)
		xalloc_die();
	return p;
}

void *
xcalloc(size_t n, size_t s)
{
	void *p = calloc(n, s);
	if(!p && n != 0 && s != 0)
		xalloc_die();
	return p;
}

void *
xrealloc(void *p, size_t n)
{
	p = realloc(p, n);
	if(!p && n != 0)
		xalloc_die();
	return p;
}

/* Reallocate P as an array of N objects of S bytes each, with error checking. */
void *
xreallocarray(void *p, size_t n, size_t s)
{
	void *r = reallocarray(p, n, s);
	if(!r && n != 0 && s != 0)
		xalloc_die();
	return r;
}

/* Allocate an array of N objects of S bytes each, with error checking. */
void *
xnmalloc(size_t n, size_t s)
{
	return xreallocarray(NULL, n, s);
}

/* Resize P to an array of N objects of S bytes each, with error checking.
   Unlike x2nrealloc, this resizes to exactly N — it does not grow. */
void *
xnrealloc(void *p, size_t n, size_t s)
{
	return xreallocarray(p, n, s);
}

void *
xmemdup(const void *src, size_t n)
{
	void *p = xmalloc(n);
	memcpy(p, src, n);
	return p;
}

char *
xcharalloc(size_t n)
{
	return xmalloc(n);
}

void *
xzalloc(size_t s)
{
	return xcalloc(s, 1);
}

char *
xstrdup(const char *s)
{
	char *p = strdup(s);
	if(!p)
		xalloc_die();
	return p;
}

char *
xstrndup(const char *s, size_t n)
{
	char *p = strndup(s, n);
	if(!p)
		xalloc_die();
	return p;
}

/* Grow P (array of *PN objects of S bytes) by ~1.5x, with error checking.
   If P is null, allocate an initial block sized for the default fast path. */
void *
x2nrealloc(void *p, size_t *pn, size_t s)
{
	size_t n = *pn;

	if(!p) {
		enum { DEFAULT_MXFAST = 64 * sizeof(size_t) / 4 };
		if(!n) {
			n = DEFAULT_MXFAST / s;
			n += !n;
		}
	} else {
		/* n = floor(1.5 * n) + 1, checking for overflow */
		size_t incr = (n >> 1) + 1;
		if(n > (size_t)-1 - incr)
			xalloc_die();
		n += incr;
	}
	p = xreallocarray(p, n, s);
	*pn = n;
	return p;
}

void *
x2realloc(void *p, size_t *ps)
{
	return x2nrealloc(p, ps, 1);
}

/* Grow array PA of *PN items (each S bytes) by at least N_INCR_MIN items,
   not exceeding N_MAX total (-1 = unlimited). */
void *
xpalloc(void *pa, ptrdiff_t *pn, ptrdiff_t n_incr_min, ptrdiff_t n_max, ptrdiff_t s)
{
	enum { DEFAULT_MXFAST = 64 * sizeof(size_t) / 4 };
	ptrdiff_t n0 = *pn;
	ptrdiff_t n;
	size_t nbytes;

	/* Grow by ~50%; cap at n_max if set. */
	n = n0 + (n0 >> 1) + 1;
	if(n0 > (ptrdiff_t)((size_t)-1 / 2))
		n = (ptrdiff_t)((size_t)-1 / 2);	/* overflow guard */
	if(0 <= n_max && n_max < n)
		n = n_max;

	nbytes = (size_t)n * (size_t)s;
	/* If tiny, round up to DEFAULT_MXFAST */
	if(nbytes < DEFAULT_MXFAST && s > 0) {
		n = DEFAULT_MXFAST / s;
		nbytes = (size_t)n * (size_t)s;
	}

	if(!pa)
		*pn = 0;
	if(n - n0 < n_incr_min) {
		n = n0 + n_incr_min;
		if(n < 0 || (0 <= n_max && n_max < n))
			xalloc_die();
		nbytes = (size_t)n * (size_t)s;
	}
	pa = xrealloc(pa, nbytes);
	*pn = n;
	return pa;
}

/* idx_t (ptrdiff_t) variants — same semantics, signed-size argument. */

void *
ximalloc(ptrdiff_t s)
{
	return xmalloc((size_t)s);
}

void *
xirealloc(void *p, ptrdiff_t s)
{
	return xrealloc(p, (size_t)s);
}

void *
xicalloc(ptrdiff_t n, ptrdiff_t s)
{
	return xcalloc((size_t)n, (size_t)s);
}

void *
xizalloc(ptrdiff_t s)
{
	return xicalloc(s, 1);
}

void *
ximemdup(void const *p, ptrdiff_t s)
{
	return xmemdup(p, (size_t)s);
}

/* Reallocate P as an array of N objects of S bytes each. */
void *
xireallocarray(void *p, ptrdiff_t n, ptrdiff_t s)
{
	return xreallocarray(p, (size_t)n, (size_t)s);
}

/* Allocate an array of N objects of S bytes each. */
void *
xinmalloc(ptrdiff_t n, ptrdiff_t s)
{
	return xireallocarray(NULL, n, s);
}

char *
ximemdup0(void const *p, ptrdiff_t s)
{
	char *result = ximalloc(s + 1);
	result[s] = '\0';
	return memcpy(result, p, s);
}
