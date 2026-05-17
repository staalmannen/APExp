#include "stdio_impl.h"

int fputc(int c, FILE *f)
{
	unsigned char ch = (unsigned char)c;
	_FLOCK(f);

	if (f->wpos != f->wend && ch != f->lbf) {
		*f->wpos++ = ch;
		_FUNLOCK(f);
		return ch;
	}

	if (f->write(f, &ch, 1) != 1) {
		_FUNLOCK(f);
		return EOF;
	}

	_FUNLOCK(f);
	return ch;
}
