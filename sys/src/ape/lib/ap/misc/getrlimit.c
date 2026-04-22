#include <sys/resource.h>
#include <errno.h>
#include <limits.h>

/*
 * getrlimit / setrlimit stubs for Plan9/APExp.
 *
 * Plan9 has no resource limit concept. getrlimit returns RLIM_INFINITY
 * for all limits except RLIMIT_NOFILE, where we report the APE OPEN_MAX.
 * setrlimit silently succeeds (requests are ignored).
 */

#ifndef OPEN_MAX
#define OPEN_MAX 128
#endif

int
getrlimit(int resource, struct rlimit *rlp)
{
	if(rlp == NULL){
		errno = EFAULT;
		return -1;
	}
	rlp->rlim_cur = RLIM_INFINITY;
	rlp->rlim_max = RLIM_INFINITY;
	if(resource == RLIMIT_NOFILE){
		rlp->rlim_cur = OPEN_MAX;
		rlp->rlim_max = OPEN_MAX;
	}
	return 0;
}

int
setrlimit(int resource, const struct rlimit *rlp)
{
	(void)resource;
	(void)rlp;
	return 0;
}
