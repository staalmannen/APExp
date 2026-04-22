#ifndef __STDDEF_ARCH_H
#define __STDDEF_ARCH_H

typedef long long _ptrdiff_t;
/* On amd64 (LLP64), size_t/ssize_t must be 64-bit to match pointer width.
 * Plan 9 6c has 32-bit 'unsigned long', so define them here before stddef.h
 * can fall back to 'unsigned long'. */
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
