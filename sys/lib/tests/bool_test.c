#include <stdio.h>

int main() {
    bool b1 = true;
    bool b2 = false;
    
    if (b1) printf("b1 is true\n");
    if (!b2) printf("b2 is false\n");
    
    printf("sizes: %ld %ld %ld\n", (long)sizeof(bool), (long)sizeof(true), (long)sizeof(false));
    return 0;
}
