#include <npe.h>

typedef Rune wchar_t;

#define mblen(r,n) (utfnlen(r, n))
#define mbtowc(r,s,n) (chartorune(r,s))
