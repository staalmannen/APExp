#include <ctype.h>

#undef isalpha

int isalpha(int c) {return _ctype[(unsigned char)(c)]&(_ISupper|_ISlower);}

