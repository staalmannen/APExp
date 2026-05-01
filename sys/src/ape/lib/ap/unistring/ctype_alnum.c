#include <unictype.h>
#include <utf.h>

int uc_is_alnum(Rune r) {
    return isalnumrune(r);
}
