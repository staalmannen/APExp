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
/* 
 * Fallback for compilers without native _Static_assert.
 * Support both 1 and 2 argument forms using variadic macros.
 */
#   define _STATIC_ASSERT_3(e, m, ...) extern char (*_static_assert_check(void))[1-2*!(e)]
#   define static_assert(...) _STATIC_ASSERT_3(__VA_ARGS__, "static assertion failed", 0)
#   define _Static_assert(...) static_assert(__VA_ARGS__)
#  endif
# endif
#endif

#endif /* _ASSERT_H */
