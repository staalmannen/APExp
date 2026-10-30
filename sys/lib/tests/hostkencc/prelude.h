/*
 * Host prelude for building kencc with gcc. Included with -include, so it
 * is the first thing in every translation unit.
 *
 * THREE NAME COLLISIONS AND NOTHING ELSE. kencc's `cc' declares
 * `long round(long,int)' and `int log2(uvlong)'; glibc's <math.h>, which
 * go1.4's <u.h> pulls in, declares both as double functions. **The rename
 * cannot be a plain -D**: glibc builds those declarations with macros
 * (`__MATHCALL_VEC (log2,, ...)`) and renaming the name inside the macro
 * invocation breaks the expansion -- measured, `expected ';' before
 * 'extern'` on every file. So <math.h> is pulled FIRST, with its real
 * names, and the renames apply only to what comes after: cc's own
 * declaration and all its uses, consistently across every TU.
 *
 * `IOUNIT' is Plan 9's 9P I/O unit, used by cc.h only to size an output
 * buffer, so any value serves.
 */
#ifndef _KENCC_HOST_PRELUDE_H
#define _KENCC_HOST_PRELUDE_H
#include <math.h>
#define round	cc_round
#define log2	cc_log2
#define IOUNIT	8192
#endif
