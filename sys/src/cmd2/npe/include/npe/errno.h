#ifndef _npe_errno_h_
#define _npe_errno_h_

#include <npe.h>

enum {
	ENOENT = 2,
	EACCES = 13,
	EINVAL = 22,
	ERANGE = 34,
	ENAMETOOLONG = 36,
};

extern int errno;

#endif
