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
 *
 * Not included, having turned out to be dead code under this config.h:
 * timespec_get (gettime.c takes the clock_gettime branch, since
 * HAVE_CLOCK_GETTIME is set), strerrorname_np (xvasprintf.c guards it
 * with HAVE_WORKING_STRERRORNAME_NP, which is undef), and mkstemps and
 * mkostemps (mkstemp-safer.c guards them with GNULIB_MKSTEMPS and
 * GNULIB_MKOSTEMPS, neither of which is defined).
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

/* stdlib.h wrapper */
extern char *secure_getenv(char const *);

/* stdio.h wrapper */
extern ptrdiff_t vaszprintf(char **, const char *, va_list);
extern off64_t vfzprintf(FILE *, const char *, va_list);
extern off64_t vzprintf(const char *, va_list);

#endif /* _APEXP_DECLS_H */
