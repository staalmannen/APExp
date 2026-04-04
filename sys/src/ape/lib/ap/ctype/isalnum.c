#include <ctype.h>

#undef isalnum

int isalnum(int c) {return _ctype[(unsigned char)(c)]&(_ISupper|_ISlower|_ISdigit);}

