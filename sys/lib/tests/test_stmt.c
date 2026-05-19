#include <stdio.h>
int main() {
    int x = ({ int y = 1; y + 1; });
    printf("%d\n", x);
    return 0;
}
