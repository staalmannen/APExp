#ifndef _ASSERT_H
#define _ASSERT_H

#pragma lib "/$M/lib/ape/libap.a"

#undef assert
#ifdef NDEBUG
#define assert(ignore) ((void)0)
#else
#ifdef __cplusplus
extern "C" {
#endif

extern void _assert(char *, unsigned);

#ifdef __cplusplus
}
#endif
#define assert(e) ((e) ? (void)0 : _assert(__FILE__, __LINE__))
#endif /* NDEBUG */

/* C11 / C23 static_assert support */
#ifndef static_assert
# ifndef __cplusplus
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#   define static_assert _Static_assert
#  else
#   define static_assert(e, m) extern char (*_static_assert_check(void))[1-2*!(e)]
#   define _Static_assert(e, m) static_assert(e, m)
#  endif
# endif
#endif

#endif /* _ASSERT_H */
