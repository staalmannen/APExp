#include "str.h"
#include "util.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void str_init(struct Str *b)
{
	b->s = NULL;
	b->len = 0;
	b->cap = 0;
}

void str_free(struct Str *b)
{
	if (b->s)
		b->s[0] = '\0';
	b->len = 0;
	b->cap = 0;
	free(b->s);
	b->s = NULL;
}

static int str_grow(struct Str *b, size_t add)
{
	size_t need;

	need = b->len + add + 1;
	if (need <= b->cap)
		return 0;
	b->cap = need + (need >> 1) + 16;
	b->s = xrealloc(b->s, b->cap);
	return 0;
}

int str_add(struct Str *b, const char *s)
{
	size_t n;

	if (!s || !*s)
		return 0;
	n = strlen(s);
	str_grow(b, n);
	memcpy(b->s + b->len, s, n);
	b->len += n;
	b->s[b->len] = '\0';
	return 0;
}

int str_addc(struct Str *b, char c)
{
	str_grow(b, 1);
	b->s[b->len++] = c;
	b->s[b->len] = '\0';
	return 0;
}

char *str_finish(struct Str *b)
{
	char *s;

	if (!b->s)
		return xstrdup("");
	s = b->s;
	b->s = NULL;
	b->len = 0;
	b->cap = 0;
	return s;
}

char *str_trim(char *s)
{
	char *p, *e;
	size_t n;

	if (!s)
		return NULL;
	p = s;
	while (*p && isspace((unsigned char)*p))
		p++;
	e = p + strlen(p);
	while (e > p && isspace((unsigned char)e[-1]))
		e--;
	*e = '\0';
	if (p != s) {
		n = (size_t)(e - p) + 1;
		memmove(s, p, n);
	}
	return s;
}

char *str_join_space(const char *a, const char *b)
{
	struct Str out;

	str_init(&out);
	if (a && *a)
		str_add(&out, a);
	if (b && *b) {
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, b);
	}
	return str_finish(&out);
}
