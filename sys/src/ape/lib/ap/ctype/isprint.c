#include <ctype.h>

#undef isprint

int isprint(int c) {return _ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit|_ISblank);}

