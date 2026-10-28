#ifndef __PARAM_H__
#define __PARAM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * MAXPATHLEN, and why it arrives through <limits.h>.
 *
 * Every BSD and Linux <sys/param.h> defines MAXPATHLEN, and portable
 * code written against that expectation says
 *
 *	#include <sys/param.h>
 *	char buf[MAXPATHLEN];
 *
 * -- which is exactly `go1.4''s `cmd/dist/unix.c:280', and it answered
 * `name not declared: MAXPATHLEN'.  **This header did not define it and
 * did not reach anything that does.**
 *
 * `limits_generic.h:169' has had `#define MAXPATHLEN PATH_MAX' all
 * along, with a comment about Tcl's `fCmd.test' needing exactly this
 * spelling, so the name was PRESENT in the tree and simply not
 * reachable through the header that conventionally supplies it.  *A
 * capability this library has and does not declare where callers look
 * for it is the same shape as the stub family*, and the fix is an
 * include rather than a new name: nothing here is being invented, and
 * <limits.h> is what every other platform's <sys/param.h> pulls in to
 * answer this.
 */
#include <limits.h>

#define NOFILES_MAX 100

//copied from musl
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


#ifdef __cplusplus
}
#endif

#endif /* !__PARAM_H__ */
