#include <wctype.h>
#include <ctype.h>
#undef iswblank

int iswblank(wint_t wc)
{
	return isblank(wc);
}

int __iswblank_l(wint_t c, locale_t l)
{
	return iswblank(c);
}

int iswblank_l(wint_t c, locale_t l)
{
	return iswblank(c);
}


