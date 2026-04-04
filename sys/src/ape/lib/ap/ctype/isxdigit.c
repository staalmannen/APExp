#include <ctype.h>

#undef isxdigit

int isxdigit(int c) {return _ctype[(unsigned char)(c)]&_ISxdigit;}
