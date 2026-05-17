#include "stdio_impl.h"

void clearerr(FILE *f){
	_FLOCK(f);
	f->flags &= ~(F_EOF | F_ERR);
	_FUNLOCK(f);
}

