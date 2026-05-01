#include <unistr.h>
#include <utf.h>
#include <wchar.h>

/* c32tolower/toupper wrap the unicase shims */
#include <unicase.h>

ucs4_t c32tolower(ucs4_t r) {
    return uc_tolower(r);
}

ucs4_t c32toupper(ucs4_t r) {
    return uc_toupper(r);
}

/* c32rtomb/mbrtoc32 wrap the native Plan 9 utf routines */
size_t c32rtomb(char *s, ucs4_t wc, mbstate_t *ps) {
    if (s == NULL) return 1;
    return (size_t)runetochar(s, (Rune *)&wc);
}

size_t mbrtoc32(ucs4_t *pwc, const char *s, size_t n, mbstate_t *ps) {
    Rune r;
    int len = chartorune(&r, s);
    if (len == 1 && r == Runeerror) return (size_t)-1;
    if (pwc) *pwc = (ucs4_t)r;
    return (size_t)len;
}
