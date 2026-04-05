#include "stdio_impl.h"

int setbuf(FILE *f, char *buf){
	return setvbuf(f, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}

