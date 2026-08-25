/*
 * wcstol, wcstoll, wcstoul, wcstoull, wcstod, wcstof, wcstold
 *
 * All seven live together because they share one helper and differ only
 * in which narrow function they call.
 *
 * Every character these conversions can accept is ASCII: the sign,
 * digits, the 0x and 0b prefixes, the radix point, the exponent letters,
 * and the spellings of inf and nan. So the leading run of ASCII
 * characters, taken after any leading whitespace, is a superset of what
 * the parser will consume. Copying that run into a narrow buffer and
 * handing it to the narrow function gives the same answer, and since the
 * copy is one character per character, an offset into the buffer maps
 * straight back onto the wide string.
 *
 * C99 7.24.4.1: if no conversion could be performed, nptr itself is
 * stored in *endptr -- the original pointer, ahead of any whitespace.
 * errno is left alone, so ERANGE from the narrow call propagates.
 */
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>

/*
 * Copy the ASCII run into a fresh narrow buffer. *body is set to where
 * that run begins in the wide string, which is where offsets are
 * measured from.
 */
static char *
ascii_prefix(const wchar_t *s, const wchar_t **body)
{
	const wchar_t *p = s;
	size_t n, i;
	char *b;

	while (iswspace(*p))
		p++;
	*body = p;
	for (n = 0; p[n] && p[n] < 128; n++)
		;
	if (!(b = malloc(n + 1)))
		return 0;
	for (i = 0; i < n; i++)
		b[i] = (char)p[i];
	b[n] = 0;
	return b;
}

/* Where *endptr should point, given where the narrow parser stopped. */
static wchar_t *
map_end(const wchar_t *s, const wchar_t *body, const char *b, const char *e)
{
	return (wchar_t *)(e == b ? s : body + (e - b));
}

long
wcstol(const wchar_t *s, wchar_t **end, int base)
{
	const wchar_t *body;
	char *b, *e;
	long r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtol(b, &e, base);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

long long
wcstoll(const wchar_t *s, wchar_t **end, int base)
{
	const wchar_t *body;
	char *b, *e;
	long long r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtoll(b, &e, base);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

unsigned long
wcstoul(const wchar_t *s, wchar_t **end, int base)
{
	const wchar_t *body;
	char *b, *e;
	unsigned long r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtoul(b, &e, base);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

unsigned long long
wcstoull(const wchar_t *s, wchar_t **end, int base)
{
	const wchar_t *body;
	char *b, *e;
	unsigned long long r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtoull(b, &e, base);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

double
wcstod(const wchar_t *s, wchar_t **end)
{
	const wchar_t *body;
	char *b, *e;
	double r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtod(b, &e);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

float
wcstof(const wchar_t *s, wchar_t **end)
{
	const wchar_t *body;
	char *b, *e;
	float r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtof(b, &e);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}

long double
wcstold(const wchar_t *s, wchar_t **end)
{
	const wchar_t *body;
	char *b, *e;
	long double r;

	if (!(b = ascii_prefix(s, &body))) {
		if (end) *end = (wchar_t *)s;
		return 0;
	}
	r = strtold(b, &e);
	if (end) *end = map_end(s, body, b, e);
	free(b);
	return r;
}
