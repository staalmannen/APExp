#include <ctype.h>

#undef isprint

/*
 * printing characters: the graphic ones plus SPACE, and nothing else.
 *
 * NOT a single mask over _ctype. The old body was
 * `..&(_ISpunct|_ISupper|_ISlower|_ISdigit|_ISblank)', which read
 * _ISblank as "is a space" -- true only while space was the only
 * character that had it. TAB now carries _ISblank as C99 requires, so
 * that mask would answer true for a tab. See ap/ctype/ctype.c for what
 * the missing flag cost.
 */
int
isprint(int c)
{
	if(c == ' ')
		return 1;
	return _ctype[(unsigned char)c]&(_ISpunct|_ISupper|_ISlower|_ISdigit);
}
