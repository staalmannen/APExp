#include <uchar.h>
#include <utf.h>
#include <wchar.h>

size_t mbrtoc32(char32_t *pwc, const char *s, size_t n, mbstate_t *ps) {
    Rune r;
    int len = chartorune(&r, s);
    if (len == 1 && r == Runeerror) return (size_t)-1;
    if (pwc) *pwc = (char32_t)r;
    return (size_t)len;
}
