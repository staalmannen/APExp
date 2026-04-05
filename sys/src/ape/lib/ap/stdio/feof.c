#include "stdio_impl.h"

int feof(FILE *f){
	return f->flags & F_EOF;
}

