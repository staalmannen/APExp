#ifndef _npe_iconv_h_
#define _npe_iconv_h_

#include <npe.h>

typedef struct iconv_s *iconv_t;
#pragma incomplete struct iconv_s

iconv_t iconv_open(char *to, char *from);
void iconv_close(iconv_t);
size_t iconv(iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft);

#endif
