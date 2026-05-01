#include <unistr.h>
#include <utf.h>

size_t u32_strlen(const uint32_t *s) {
    return (size_t)runestrlen((Rune *)s);
}
