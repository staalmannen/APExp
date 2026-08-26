#ifndef _APEXP_DECLS_H
#define _APEXP_DECLS_H

/*
 * Declarations that gnulib puts in its generated replacement headers.
 *
 * APExp deletes those wrappers, because they shadow APE's headers and
 * #include_next back into them until cpp reports "#if too deeply
 * nested". The modules themselves are still built, so a caller in
 * another translation unit is left with no prototype and the compiler
 * falls back to the implicit int return:
 *
 *   tmpdir.c:110 incompatible types: "IND CONST CHAR" and "INT" for op "AS"
 *
 * Everything here was found by listing the _GL_FUNCDECL_SYS and
 * _GL_FUNCDECL_RPL names in the deleted *.in.h templates, keeping the
 * ones a module in OFILES actually calls, and dropping the ones APE
 * already declares. Signatures are copied from each defining .c file.
 * Re-run that sweep whenever modules are added to OFILES: the coreutils
 * batch brought in eleven more, and the one that surfaced it was
 * numfmt.c returning mbschr's char * through an implicit int --
 *
 *   numfmt.c:1403 incompatible types: "INT" and "IND CHAR" for op "LIST"
 *
 * which is the loud version. mbsstr and memset_explicit in the same
 * batch also return pointers, and would have truncated silently
 * wherever the result was simply stored.
 *
 * Not included, having turned out to be dead code under this config.h:
 * timespec_get (gettime.c takes the clock_gettime branch, since
 * HAVE_CLOCK_GETTIME is set), and mkstemps and mkostemps
 * (mkstemp-safer.c guards them with GNULIB_MKSTEMPS and
 * GNULIB_MKOSTEMPS, neither of which is defined).
 *
 * strerrorname_np was on that list too, on the grounds that its only
 * caller was xvasprintf.c under HAVE_WORKING_STRERRORNAME_NP. That
 * stopped being true with coreutils: getlimits.c calls it directly and
 * with no guard, so it is declared below.
 */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>

/* off64_t came from the deleted sys/types.h wrapper, where gnulib
   defines it as long long. APE's off_t is already 64 bit, so alias that
   instead and stay consistent with the rest of the system. */
#ifndef _APEXP_HAVE_OFF64_T
#define _APEXP_HAVE_OFF64_T 1
typedef off_t off64_t;
#endif

/* string.h wrapper */
extern size_t mbslen(const char *);
extern const char *strerrorname_np(int);
extern char *mbschr(const char *, int);
extern char *mbsstr(const char *, const char *);
extern void *memset_explicit(void *, int, size_t);

/* sys/stat.h wrapper */
extern int lchmod(const char *, mode_t);
extern int mkfifoat(int, const char *, mode_t);

/* unistd.h wrapper */
extern int euidaccess(const char *, int);
extern int fdatasync(int);
extern int group_member(gid_t);
extern int lchown(const char *, uid_t, gid_t);

/* uchar.h wrapper. wint_t is a macro in APE's <wchar.h> rather than a
   typedef, so that header has to come first. wc.c is the caller. */
#include <wchar.h>
extern wint_t btoc32(int);

/* stdlib.h wrapper */
extern char *secure_getenv(char const *);
extern int rpmatch(const char *);

/* signal.h wrapper.
   sig2str.c is in the archive, but SIG2STR_MAX and the two prototypes
   live in the generated signal.h, not in sig2str.h -- that header kept
   only SIGNUM_BOUND when gnulib moved the rest. env.c, kill.c, split.c
   and operand2sig.c all declare "char signame[SIG2STR_MAX]":

     env.c:621 name not declared: SIG2STR_MAX

   The value is gnulib's own, from signal.in.h:153: "RTMAX", a sign, up
   to ten digits, a NUL, and two spare. */
#ifndef SIG2STR_MAX
#define SIG2STR_MAX (5 + 1 + 10 + 1 + 2)
#endif
extern int sig2str(int, char *);
extern int str2sig(const char *, int *);

/* stdio.h wrapper */
extern ptrdiff_t vaszprintf(char **, const char *, va_list);
extern off64_t vfzprintf(FILE *, const char *, va_list);
extern off64_t vzprintf(const char *, va_list);

/* locale.h wrapper.
   The deleted wrapper pulled this header in under GNULIB_SETLOCALE_NULL
   (locale.in.h:298), which is how hard-locale.c gets SETLOCALE_NULL_MAX
   and setlocale_null_r -- it includes neither itself. Unlike the rest of
   this file the real header exists, so include it rather than restating
   it; it carries its own guard and its own arg-nonnull.h. */
#include "setlocale_null.h"

#endif /* _APEXP_DECLS_H */
