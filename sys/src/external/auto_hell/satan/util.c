#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xmalloc(size_t n)
{
	void *p;

	p = malloc(n ? n : 1);
	if (!p) {
		fprintf(stderr, "satan: out of memory\n");
		exit(1);
	}
	return p;
}

void *xrealloc(void *p, size_t n)
{
	void *q;

	q = realloc(p, n ? n : 1);
	if (!q) {
		fprintf(stderr, "satan: out of memory\n");
		exit(1);
	}
	return q;
}

char *xstrdup(const char *s)
{
	char *p;

	if (!s)
		return NULL;
	p = xmalloc(strlen(s) + 1);
	memcpy(p, s, strlen(s) + 1);
	return p;
}

char *xstrndup(const char *s, size_t n)
{
	char *p;

	if (!s)
		return NULL;
	p = xmalloc(n + 1);
	memcpy(p, s, n);
	p[n] = '\0';
	return p;
}

int path_is_abs(const char *p)
{
	return p && p[0] == '/';
}

char *path_join(const char *a, const char *b)
{
	size_t alen, blen;
	int need;
	char *out;

	if (!a || !*a)
		return xstrdup(b ? b : "");
	if (!b || !*b)
		return xstrdup(a);
	if (path_is_abs(b))
		return xstrdup(b);

	alen = strlen(a);
	blen = strlen(b);
	need = (a[alen - 1] != '/');
	out = xmalloc(alen + blen + (need ? 2 : 1));
	memcpy(out, a, alen);
	if (need)
		out[alen++] = '/';
	memcpy(out + alen, b, blen);
	out[alen + blen] = '\0';
	return out;
}

char *path_dir(const char *p)
{
	const char *s;
	size_t len;
	char *out;

	if (!p || !*p)
		return xstrdup(".");
	s = strrchr(p, '/');
	if (!s)
		return xstrdup(".");
	len = (size_t)(s - p);
	if (len == 0)
		return xstrdup("/");
	out = xmalloc(len + 1);
	memcpy(out, p, len);
	out[len] = '\0';
	return out;
}

char *path_norm(const char *p)
{
	char *out;
	size_t len;

	if (!p)
		return xstrdup("");
	len = strlen(p);
	while (len > 1 && p[len - 1] == '/')
		len--;
	out = xmalloc(len + 1);
	memcpy(out, p, len);
	out[len] = '\0';
	return out;
}

char *shell_escape(const char *s)
{
	const char *p;
	char *out, *q;
	size_t len;
	int need_quote = 0;

	if (!s || !*s)
		return xstrdup("''");

	for (p = s; *p; p++) {
		if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\'' ||
		    *p == '"' || *p == '\\' || *p == '$' || *p == '`' ||
		    *p == '&' || *p == '|' || *p == ';' || *p == '<' ||
		    *p == '>' || *p == '(' || *p == ')' || *p == '{' ||
		    *p == '}' || *p == '*' || *p == '?' || *p == '[' ||
		    *p == ']' || *p == '!' || *p == '#') {
			need_quote = 1;
			break;
		}
	}

	if (!need_quote)
		return xstrdup(s);

	len = strlen(s);
	out = xmalloc(len * 4 + 3); /* every char could be ' */
	q = out;
	*q++ = '\'';
	for (p = s; *p; p++) {
		if (*p == '\'') {
			*q++ = '\'';
			*q++ = '\\';
			*q++ = '\'';
			*q++ = '\'';
		} else {
			*q++ = *p;
		}
	}
	*q++ = '\'';
	*q = '\0';
	return out;
}
