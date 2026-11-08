#ifndef _npe_string_h_
#define _npe_string_h_

#include <npe.h>

char *strerror(int errnum);
int strerror_r(int errnum, char *buf, size_t buflen);
size_t strlcpy(char *dst, char *src, size_t sz);

#endif
