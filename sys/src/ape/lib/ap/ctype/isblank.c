#include <ctype.h>

#undef isblank

int isblank(int c) {return _ctype[(unsigned char)(c)]&_ISblank;}

