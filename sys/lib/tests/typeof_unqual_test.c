#include <stdio.h>

const int ci = 42;
volatile int vi = 43;
const volatile int cvi = 44;

typeof(ci) a;           // should be const int
typeof_unqual(ci) b;    // should be int
typeof_unqual(vi) c;    // should be int
typeof_unqual(cvi) d;   // should be int

int main() {
    b = 1; // ok
    c = 2; // ok
    d = 3; // ok
    // a = 4; // should fail to compile (const)
    
    printf("sizes: %ld %ld\n", (long)sizeof(typeof(ci)), (long)sizeof(typeof_unqual(ci)));
    return 0;
}
