#include <ctype.h>

#undef isspace

int isspace(int c) {return _ctype[(unsigned char)(c)]&_ISspace;}

