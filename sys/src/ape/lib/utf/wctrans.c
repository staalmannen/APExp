#include <wctype.h>
#include <string.h>

wctrans_t wctrans(const char *class)
{
	if (!strcmp(class, "toupper")) return (wctrans_t)1;
	if (!strcmp(class, "tolower")) return (wctrans_t)2;
	return 0;
}

Rune towctrans(Rune wc, wctrans_t trans)
{
	if (trans == (wctrans_t)1) return towupper(wc);
	if (trans == (wctrans_t)2) return towlower(wc);
	return wc;
}

wctrans_t __wctrans_l(const char *s, int l)
{
	return wctrans(s);
}

Rune __towctrans_l(Rune c, wctrans_t t, int l)
{
	return towctrans(c, t);
}

weak_alias(__wctrans_l, wctrans_l);
weak_alias(__towctrans_l, towctrans_l);
