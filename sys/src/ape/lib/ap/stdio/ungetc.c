#include "stdio_impl.h"

int ungetc(int c, FILE *f){
	if(c==EOF) return EOF;

	FLOCK(f);

	/* Need an active read buffer with room in the UNGET area.
	 * Do NOT call __toread here — it resets rpos/rend and destroys
	 * any buffered data that hasn't been read yet. */
	if(!f->buf || !f->rpos || f->rpos <= (unsigned char *)f->buf - UNGET){
		FUNLOCK(f);
		return EOF;
	}

	/* If there is a pending (unflushed) write buffer, flush it first */
	if(f->wpos != f->wbase && f->wpos)
		f->write(f, 0, 0);
	f->wpos = f->wbase = f->wend = 0;

	*--f->rpos = (unsigned char)c;
	f->flags &= ~F_EOF;

	FUNLOCK(f);
	return (unsigned char)c;
}
