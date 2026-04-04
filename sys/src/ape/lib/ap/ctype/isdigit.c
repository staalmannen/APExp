#include <ctype.h>

#undef isdigit

int isdigit(int c) {return _ctype[(unsigned char)(c)]&_ISdigit;}
