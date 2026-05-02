#include <string.h>
#include <stdbool.h>

bool streq(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}

bool memeq(const void *a, const void *b, size_t n) {
    return memcmp(a, b, n) == 0;
}
