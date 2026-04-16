#define _GNU_SOURCE
#include <stdlib.h>
#include <locale.h>

float strtof_l(const char *s, char **p, locale_t l)
{
	return strtof(s, p);
}

double strtod_l(const char *s, char **p, locale_t l)
{
	return strtod(s, p);
}

long double strtold_l(const char *s, char **p, locale_t l)
{
	return strtold(s, p);
}

float __strtof_l(const char *s, char **p, locale_t l)
{
	return strtof(s, p);
}

double __strtod_l(const char *s, char **p, locale_t l)
{
	return strtod(s, p);
}

long double __strtold_l(const char *s, char **p, locale_t l)
{
	return strtold(s, p);
}



