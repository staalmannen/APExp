#include "stdio_impl.h"

/* Returns the number of bytes pending in f's write buffer. */
size_t
_fpending(FILE *f)
{
	if(f->wpos > f->wbase)
		return (size_t)(f->wpos - f->wbase);
	return 0;
}
