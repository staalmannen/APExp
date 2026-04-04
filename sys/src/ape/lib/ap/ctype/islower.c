#include <ctype.h>

#undef islower

int islower(int c) {return _ctype[(unsigned char)(c)]&_ISlower;}

