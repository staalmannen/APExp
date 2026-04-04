#include <ctype.h>

#undef ispunct

int ispunct(int c) {return _ctype[(unsigned char)(c)]&_ISpunct;}

