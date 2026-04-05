#include "stdio_impl.h"

int ferror(FILE *f){
	return f->flags & F_ERR;
}

