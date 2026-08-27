#ifndef _STDINT_ARCH_H_
#define _STDINT_ARCH_H_ 1

typedef long long _intptr_t;
typedef unsigned long long _uintptr_t;
#define INTPTR_WIDTH 64
#define UINTPTR_WIDTH 64

/* Not <stdint.h>: that would find the wrapper beside this
   file and stop at its guard. */
#include <stdint_generic.h>

#endif
