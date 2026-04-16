#include <wctype.h>
#undef iswlower

int iswlower(wint_t wc)
{
	return towupper(wc) != wc;
}

int __iswlower_l(wint_t c, locale_t l)
{
	return iswlower(c);
}

int iswlower_l(wint_t c, locale_t l)
{
	return iswlower(c);
}

