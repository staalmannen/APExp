#ifndef _limits_h_
#define _limits_h_

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#ifndef CHAR_MAX
#define CHAR_MAX 0x7f
#endif

#ifndef SCHAR_MAX
#define SCHAR_MAX 0x7f
#endif

#ifndef INT8_MAX
#define INT8_MAX 0x7f
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 0xff
#endif

#ifndef SHRT_MAX
#define SHRT_MAX 0x7fff
#endif

#ifndef USHRT_MAX
#define USHRT_MAX 0xffff
#endif

#ifndef SHRT_MIN
#define SHRT_MIN (-SHRT_MAX-1)
#endif

#ifndef SIZE_MAX
#define SIZE_MAX 0xffffffffU
#endif

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#ifndef INT16_MAX
#define INT16_MAX 0x7fff
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 0xffff
#endif

#ifndef INT32_MAX
#define INT32_MAX  0x7fffffff
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 0xffffffffU
#endif

#ifndef INT64_MAX
#define INT64_MAX 0x7fffffffffffffff
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 0xffffffffffffffffULL
#endif

#ifndef INT_MAX
#define INT_MAX INT32_MAX
#endif

#ifndef UINT_MAX
#define UINT_MAX UINT32_MAX
#endif

#ifndef LONG_MAX
#define LONG_MAX	0x7fffffffL
#endif

#ifndef ULONG_MAX
#define ULONG_MAX	0xffffffffUL
#endif

#ifndef LLONG_MAX
#define LLONG_MAX	0x7fffffffffffffffLL
#endif

#ifndef ULLONG_MAX
#define ULLONG_MAX	0xffffffffffffffffULL
#endif

#ifndef INT16_MIN
#define INT16_MIN ((s16int)0x8000)
#endif

#ifndef INT32_MIN
#define INT32_MIN (-INT32_MAX-1)
#endif

#ifndef INT64_MIN
#define INT64_MIN ((s64int)0x8000000000000000ULL)
#endif

#ifndef INT_MIN
#define INT_MIN INT32_MIN
#endif

#ifndef LONG_MIN
#define LONG_MIN	(-LONG_MAX-1)
#endif

#ifndef LLONG_MIN
#define LLONG_MIN	(-LLONG_MAX-1)
#endif

#endif
