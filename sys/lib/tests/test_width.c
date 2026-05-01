#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    printf("UINTPTR_WIDTH: %d\n", (int)UINTPTR_WIDTH);
    printf("UCHAR_WIDTH: %d\n", (int)UCHAR_WIDTH);
    printf("sizeof(uintptr_t): %d\n", (int)sizeof(uintptr_t));
    printf("sizeof(unsigned char): %d\n", (int)sizeof(unsigned char));
    return 0;
}
