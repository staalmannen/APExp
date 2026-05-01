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


