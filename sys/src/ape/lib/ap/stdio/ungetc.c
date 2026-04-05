#include "stdio_impl.h"

int ungetc(int c, FILE *f){
	if(c==EOF) return EOF;

	FLOCK(f);

	/* Ensure we're in read mode */
	if (__toread(f)) {
		FUNLOCK(f);
		return EOF;
	}

	/* ungetc requires a read buffer; ensure one exists */
	if (!f->buf || f->rpos <= f->buf) {
		FUNLOCK(f);
		return EOF;
	}

	/* Decrement read pointer and store character */
	*--f->rpos = (unsigned char)c;
	f->flags &= ~F_EOF; /* Clear EOF flag on ungetc */

	FUNLOCK(f);
	return (unsigned char)c;
}

