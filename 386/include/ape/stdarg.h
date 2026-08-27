#ifndef _APEXP_STDARG_H_
#define _APEXP_STDARG_H_

/*
 * <stdarg.h> for 386.
 *
 * This file has to exist, for the reason spelled out in the stdint.h
 * beside it: pcc searches -I/$objtype/include/ape before
 * -I/sys/include/ape (pcc.c:234-235), and stock 9front APE keeps its
 * stdarg.h in the architecture directory. APExp renamed that file to
 * stdarg_arch.h and put a wrapper in /sys/include/ape, so with nothing
 * named stdarg.h here, #include <stdarg.h> found the HOST's copy and
 * the wrapper was never read.
 *
 * Worse, as with stdint.h, the stock header takes the same guard --
 * __STDARG -- that stdarg_arch.h uses, so it did not merely win the
 * search, it disabled APExp's file. va_copy is APExp's addition to
 * these headers; whether any of it reached a compile depended entirely
 * on whether the host had a stdarg.h of its own.
 */
#include <stdarg_arch.h>

#endif /* _APEXP_STDARG_H_ */
