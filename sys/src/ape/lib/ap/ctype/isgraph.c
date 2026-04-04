#include <ctype.h>

#undef isgraph

int isgraph(int c) {return _ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit);}

