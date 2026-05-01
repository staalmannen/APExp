#include <unistr.h>
#include <utf.h>

uint32_t *u32_chr(const uint32_t *s, size_t n, uint32_t c) {
    Rune *r = runestrchr((Rune *)s, (Rune)c);
    if (r && (size_t)(r - (Rune *)s) < n)
        return (uint32_t *)r;
    return NULL;
}

uint32_t *u32_cpy(uint32_t *dest, const uint32_t *src, size_t n) {
    Rune *d = (Rune *)dest;
    Rune *s = (Rune *)src;
    while(n-- > 0) *d++ = *s++;
    return dest;
}

uint32_t *u32_pcpy(uint32_t *dest, const uint32_t *src, size_t n) {
    Rune *d = (Rune *)dest;
    Rune *s = (Rune *)src;
    while(n-- > 0) *d++ = *s++;
    return (uint32_t *)d;
}

uint32_t *u32_strcat(uint32_t *dest, const uint32_t *src) {
    return (uint32_t *)runestrcat((Rune *)dest, (Rune *)src);
}
