#include <ctype.h>

#undef isupper

int isupper(int c) {return _ctype[(unsigned char)(c)]&_ISupper;}

