#ifndef _FEATURES_H
#define _FEATURES_H

#if defined(_ALL_SOURCE) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE 1
#endif

#if defined(_DEFAULT_SOURCE) && !defined(_BSD_SOURCE)
#define _BSD_SOURCE 1
#endif

#if !defined(_POSIX_SOURCE) && !defined(_POSIX_C_SOURCE) \
 && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) \
 && !defined(_BSD_SOURCE) && !defined(__STRICT_ANSI__)
#define _BSD_SOURCE 1
#define _XOPEN_SOURCE 700
#endif

#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#elif !defined(__GNUC__)
#define __restrict
#endif

#if __STDC_VERSION__ >= 199901L || defined(__cplusplus)
#define __inline inline
#elif !defined(__GNUC__)
#define __inline
#endif

#if __STDC_VERSION__ >= 201112L
#elif defined(__GNUC__)
#define _Noreturn __attribute__((__noreturn__))
#else
#define _Noreturn
#endif

#define __REDIR(x,y) __typeof__(x) x __asm__(#y)

/* Plan9 kencc has no weak symbol support; weak_alias is a no-op here.
 * Explicit strong forwarders are provided in network/res_aliases.c.
 *
 * The parameter names are glibc's, and gnulib's libc-config.h:204 uses
 * the same ones. That matters: libc-config.h defines weak_alias with no
 * guard of its own, so whenever a header pulls this one in first, cpp
 * sees a second definition -- and comparetokens() in cpp/macro.c
 * compares the parameter lists as well as the bodies, so "(old, new)"
 * would be a redefinition error where "(name, aliasname)" is the
 * identical definition C allows. */
#ifndef weak_alias
#define weak_alias(name, aliasname) /* no weak alias on Plan9 */
#endif

#ifndef hidden
#define hidden
#endif

#endif
