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
 *
 * ***AND <unistd.h> HAS TO BE PULLED FIRST FOR THE SAME REASON AS
 * <math.h>***: the rename below applies to every later declaration,
 * glibc's included, so without it `getopt' and `kencc_getopt' become
 * two conflicting declarations of one name. *The same mistake twice in
 * one file, caught the second time by the first time's comment.*
 *
 * `getopt' is a fourth collision and is in `cpp/nlist.c:6' only: an
 * `extern int getopt(int, char**, char*)' that NOTHING in cpp calls --
 * it uses ARGBEGIN -- against glibc's `int getopt(int, char *const*,
 * const char*)'. Renamed rather than deleted, because the declaration
 * is upstream's and this file exists so that nothing shipped has to
 * change for a host build.
 *
 * `CPP' is not a collision but the hook that makes the host compilers
 * USABLE: `cc/lex.c:4' is `#ifndef CPP / #define CPP "/bin/cpp"', and
 * `-p' execs it. On the host `myexec' is `execvp', which searches PATH
 * for a name with no slash -- so a bare `cpp' would find GCC's and
 * silently preprocess with the wrong one. `kencc-cpp' is a name only
 * this harness installs, so it cannot be answered by accident.
 */
#ifndef _KENCC_HOST_PRELUDE_H
#define _KENCC_HOST_PRELUDE_H
#include <math.h>
#include <unistd.h>
#define round	cc_round
#define log2	cc_log2
#define IOUNIT	8192
#define getopt	kencc_getopt
#ifndef CPP
#define CPP	"kencc-cpp"
#endif
#endif
