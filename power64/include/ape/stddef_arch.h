#ifndef __STDDEF_ARCH_H
#define __STDDEF_ARCH_H

typedef long long _ptrdiff_t;
/* power64 is LLP64: pointers are 64-bit, 'unsigned long' is 32-bit. */
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long long size_t;
#endif
#ifndef _SSIZE_T
#define _SSIZE_T
typedef long long ssize_t;
#endif
#include "/sys/include/ape/stddef.h"

#endif /* __STDDEF_ARCH_H */
