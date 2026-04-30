#include <stdio.h>

_Static_assert(1, "message");
_Static_assert(1);
static_assert(1, "message");
static_assert(1);

int main() {
    _Static_assert(1, "in main");
    _Static_assert(1);
    return 0;
}

struct s {
    int a;
    _Static_assert(1, "in struct");
    _Static_assert(1);
};
