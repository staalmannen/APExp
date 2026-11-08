#include <iconv.h>
#include "_iconv.h"

size_t
iconv(iconv_t ic, char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft)
{
	int n;

	if(inbuf == nil || *inbuf == nil){ /* flush */
		write(ic->fd, "", 0);
	}else{
		if((n = write(ic->fd, *inbuf, *inbytesleft)) < 0)
			return -1;
		*inbuf += n;
		*inbytesleft -= n;
		return 0;
	}
	if(outbuf == nil || *outbuf == nil) /* nothing to do */
		return 0;
	if((n = read(ic->fd, *outbuf, *outbytesleft)) < 0)
		return -1;
	*outbuf += n;
	*outbytesleft -= n;

	return n;
}
