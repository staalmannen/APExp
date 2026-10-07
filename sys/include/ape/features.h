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

/*
 * `hidden' AND `weak_alias' USED TO BE DEFINED HERE AND ARE NOT ANY
 * MORE. They are musl's INTERNAL markers, and this is a PUBLIC header
 * -- reached from <byteswap.h>, <endian.h>, <ftw.h>, <glob.h>,
 * <iconv.h> and more -- so every program that included any of those
 * got them whether it wanted them or not.
 *
 * `hidden' HAD A VICTIM, which is why this moved. It expanded to
 * nothing, and `sqlite3.h:10957' declares
 *
 *	unsigned char hidden[48];
 *
 * so wherever this header came first that member was ERASED: a silent
 * struct-layout change in a public API, with no diagnostic anywhere.
 * `apehdr-sweep.py's together-case is what reported it.
 *
 * `weak_alias' had no victim found, and went for a different reason
 * recorded in its own former comment: it had no guard in gnulib's
 * `libc-config.h', so the two definitions had to agree token for
 * token -- cpp/macro.c's comparetokens() compares PARAMETER NAMES as
 * well as bodies -- and this file's parameter names were chosen to
 * match an external package's. *A public macro that is only safe
 * because it was spelled like someone else's is safe by coincidence.*
 *
 * Every private user now carries `#ifndef <name> / #define' itself,
 * which is what `include/libm.h' and `multibyte/internal.c' already
 * did: sixteen files for `hidden', five under `network/' for
 * `weak_alias'. Nothing outside libap needed either -- every external
 * package that uses `weak_alias' ships its own `libc-config.h', and
 * bash's `lib/intl' (the one exception) is not compiled.
 */

#endif
