#include "stdio_impl.h"

int fclose(FILE *f){
	if(!f) return EOF;

	int error = 0;
	if(fflush(f)==EOF) error=EOF;

	if(f->buf && (f->flags & F_SVB)){
		free(f->buf);
		f->buf = NULL;
	}

	if(f->close && f->close(f) < 0)
		error = EOF;

	if(f->fd >= 0 && close(f->fd) < 0)
		error = EOF;

	f->fd = -1;
	f->flags = 0;
	return error;
}


