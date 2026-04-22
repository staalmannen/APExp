#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <xalloc.h>

/* Called on allocation failure. Programs may override this. */
void
xalloc_die(void)
{
	fputs("memory exhausted\n", stderr);
	exit(1);
}

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

void *
xmemdup(const void *src, size_t n)
{
	void *p = xmalloc(n);
	memcpy(p, src, n);
	return p;
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

/*
 * xnrealloc - realloc *pp to hold at least *pn elements of size s,
 * doubling *pn each time. Useful for growing arrays.
 */
void *
xnrealloc(void *p, size_t *pn, size_t s)
{
	size_t n = *pn;
	if(n == 0)
		n = 1;
	else if(n > (size_t)-1 / 2 / s)
		xalloc_die();
	else
		n *= 2;
	*pn = n;
	return xrealloc(p, n * s);
}
