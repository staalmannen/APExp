#include <wctype.h>
#include <langinfo.h>
#undef iswalnum

int iswalnum(wint_t wc)
{
	return iswdigit(wc) || iswalpha(wc);
}

int __iswalnum_l(wint_t c, locale_t l)
{
	return iswalnum(c);
}


int iswalnum_l(wint_t c, locale_t l)
{
	return iswalnum(c);
}


