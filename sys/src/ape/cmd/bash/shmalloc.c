#include <stdlib.h>
#include <string.h>

void *sh_malloc(size_t bytes, const char *file, int line) {
    return malloc(bytes);
}

void *sh_realloc(void *ptr, size_t bytes, const char *file, int line) {
    return realloc(ptr, bytes);
}

void sh_free(void *mem, const char *file, int line) {
    free(mem);
}
