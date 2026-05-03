#ifndef __STDDEF_H
#define __STDDEF_H

#include <_apetypes.h>
#include <stddef_arch.h>

#ifndef __STDDEF_ARCH_H
typedef long _ptrdiff_t;
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#define offsetof(ty,mem) ((size_t) &(((ty *)0)->mem))

typedef _ptrdiff_t ptrdiff_t;
typedef long max_align_t;
#ifndef _SIZE_T
#define _SIZE_T
#ifdef _BITS64
typedef unsigned long long size_t;
#else
typedef unsigned long size_t;
#endif
#endif
#ifndef _WCHAR_T
#define _WCHAR_T
typedef unsigned short wchar_t;
#endif

#endif /* __STDDEF_H */
