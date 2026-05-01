#include <uchar.h>
#include <utf.h>
#include <wchar.h>

size_t c32rtomb(char *s, char32_t wc, mbstate_t *ps) {
    if (s == NULL) return 1;
    return (size_t)runetochar(s, (Rune *)&wc);
}
