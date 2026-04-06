#include "stdio_impl.h"

int fputc(int c, FILE *f)
{
	unsigned char ch = (unsigned char)c;
	FLOCK(f);

	if (f->wpos != f->wend && ch != f->lbf) {
		*f->wpos++ = ch;
		FUNLOCK(f);
		return ch;
	}

	if (f->write(f, &ch, 1) != 1) {
		FUNLOCK(f);
		return EOF;
	}

	FUNLOCK(f);
	return ch;
}
