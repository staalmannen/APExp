#include "stdio_impl.h"

/* Returns the number of bytes pending in f's write buffer. */
size_t
_fpending(FILE *f)
{
	if(f->wpos > f->wbase)
		return (size_t)(f->wpos - f->wbase);
	return 0;
}

/* glibc-internal name used by gnulib's close_stream and fpending modules */
size_t
__fpending(FILE *f)
{
	return _fpending(f);
}
