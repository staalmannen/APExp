#include <ctype.h>

#undef iscntrl

int iscntrl(int c) {return _ctype[(unsigned char)(c)]&_IScntrl;}
