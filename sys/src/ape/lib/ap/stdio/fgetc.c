/*
 * pANS stdio -- fgetc
 * APExp: implements directly via read buffer / __uflow to avoid
 * mutual recursion with getc() (getc calls fgetc, fgetc must not
 * call getc back).
 */
#include "iolib.h"
int fgetc(FILE *f){
	if (f->rpos != f->rend)
		return (unsigned char)*f->rpos++;
	return __uflow(f);
}
