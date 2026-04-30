#include <stdio.h>

#if __has_include(<stdio.h>)
#define HAS_STDIO 1
#else
#define HAS_STDIO 0
#endif

#if __has_include("nonexistent.h")
#define HAS_NONEXISTENT 1
#else
#define HAS_NONEXISTENT 0
#endif

int main() {
    printf("has stdio: %d\n", HAS_STDIO);
    printf("has nonexistent: %d\n", HAS_NONEXISTENT);
    return 0;
}
