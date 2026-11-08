#include <iconv.h>
#include "_iconv.h"

void
iconv_close(iconv_t ic)
{
	if(ic != nil){
		close(ic->fd);
		free(ic);
	}
}
