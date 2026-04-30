#include <stdio.h>

/* Dummy print to satisfy the compiler */
void print(const char *fmt, ...) { (void)fmt; }

#define xprint(a, ...) print(a __VA_OPT__(,) __VA_ARGS__)

int main() {
    xprint("format", 1, 2, 3); // print("format", 1, 2, 3)
    xprint("no args");         // print("no args")
    return 0;
}
