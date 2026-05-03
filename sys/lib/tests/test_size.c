#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned char digest[4];
} XXH32_canonical_t;

typedef struct {
    unsigned char digest[8];
} XXH64_canonical_t;

int main() {
    printf("sizeof(uint32_t): %d\n", (int)sizeof(uint32_t));
    printf("sizeof(XXH32_canonical_t): %d\n", (int)sizeof(XXH32_canonical_t));
    printf("sizeof(uint64_t): %d\n", (int)sizeof(uint64_t));
    printf("sizeof(XXH64_canonical_t): %d\n", (int)sizeof(XXH64_canonical_t));
    return 0;
}
