#include <wctype.h>
#undef iswgraph

int iswgraph(wint_t wc)
{
	/* ISO C defines this function as: */
	return !iswspace(wc) && iswprint(wc);
}

int __iswgraph_l(wint_t c, locale_t l)
{
	return iswgraph(c);
}

int iswgraph_l(wint_t c, locale_t l)
{
	return iswgraph(c);
}


