
#include "objpak.h"

int
main()
{
    id block;
    int m = 0;

    block = [ { int n = 0;m++;[{n++;} value];printf("n=%i\n",n); } self ];
    [block value];
    [block value];
    printf("m=%i\n",m);
}


