#include <locale.h>
#include "../include/locale_impl.h"

static const char *dummy(const char *msg, const struct __locale_map *lm)
{
	return msg;
}

#define __lctrans_impl dummy

const char *__lctrans(const char *msg, const struct __locale_map *lm)
{
	return __lctrans_impl(msg, lm);
}

const char *__lctrans_cur(const char *msg)
{
	return __lctrans_impl(msg, (const struct __locale_map *) "UTF8");
}
