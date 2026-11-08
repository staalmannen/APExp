#include <string.h>

int
strerror_r(int errnum, char *buf, size_t buflen)
{
	USED(errnum);
	rerrstr(buf, buflen);
	return 0;
}
