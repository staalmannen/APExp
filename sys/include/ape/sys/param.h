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

/*
 * Copied from musl -- ***AND THE GUARDS ARE OURS, BECAUSE musl IS THE
 * ODD ONE OUT HERE.***  glibc and the BSDs both wrap these in
 * `#ifndef', and they are right to: `MIN'/`MAX' are not in POSIX, so
 * a program that wants them defines its own, and a header that
 * redefines afterwards is a hard error rather than a nicety.
 *
 * php does exactly that.  `Zend/zend_portability.h:479-482' is
 * `#undef MIN' / `#undef MAX' and then its own spelling with a space
 * after the comma; `main/php.h:215' then includes <sys/param.h> and
 * kencc answered
 *
 *	/sys/include/ape/sys/param.h:36 ... Macro redefinition of MIN
 *
 * -- *a redefinition with a different token sequence*, which is the
 * rule this tree already carries as "a macro's identity includes
 * whether there is white space".
 *
 * The guard can only ever turn an error into a success: it changes
 * nothing unless the name is already defined, and today that case is
 * a diagnostic.
 */
#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif


#ifdef __cplusplus
}
#endif

#endif /* !__PARAM_H__ */
