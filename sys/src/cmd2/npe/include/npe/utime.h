#ifndef _npe_utime_h_
#define _npe_utime_h_

#include <time.h>

struct utimbuf{
	time_t actime;
	time_t modtime;
};

int utime(const char *path, const struct utimbuf *times);

#endif
