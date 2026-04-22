#ifndef __STDDEF_ARCH_H
#define __STDDEF_ARCH_H

typedef long long _ptrdiff_t;
/* On amd64, size_t must match pointer width (8 bytes); Plan 9 6c has
 * 32-bit 'unsigned long', so use 'unsigned long long' (= uvlong) here. */
typedef unsigned long long _size_t;
typedef long long _ssize_t;
#include "/sys/include/ape/stddef.h"

#endif /* __STDDEF_ARCH_H */
