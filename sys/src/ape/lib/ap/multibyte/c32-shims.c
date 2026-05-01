#include <uchar.h>
#include <unicase.h>

char32_t c32tolower(char32_t r) {
    return (char32_t)uc_tolower((ucs4_t)r);
}

char32_t c32toupper(char32_t r) {
    return (char32_t)uc_toupper((ucs4_t)r);
}
