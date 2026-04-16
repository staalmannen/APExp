#include <wchar.h>
#include <locale.h>
#include "locale_impl.h"

/* FIXME: stub */
int __wcscoll_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscmp(l, r);
}

#undef wcscoll

int wcscoll(const wchar_t *l, const wchar_t *r)
{
	return __wcscoll_l(l, r, (locale_t) "UTF-8");
}

int wcscoll_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscmp(l, r);
}


