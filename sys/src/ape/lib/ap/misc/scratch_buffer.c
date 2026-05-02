#include <stdlib.h>

void __libc_scratch_buffer_dupfree(void *ptr) {
    free(ptr);
}
