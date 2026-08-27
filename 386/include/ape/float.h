#ifndef _FLOAT_H
#define _FLOAT_H

/*
 * <float.h> for 386.
 *
 * This file has to exist. pcc passes -I/$objtype/include/ape before
 * -I/sys/include/ape (pcc.c:234-235), and stock 9front APE ships its
 * float.h in the architecture directory. APExp renamed that file to
 * float_arch.h and put a wrapper in /sys/include/ape -- but with
 * nothing named float.h here, #include <float.h> found the HOST's stock
 * copy from the union mount underneath, and the wrapper was never read.
 * Silent, because the stock copy has everything C89 asks for; it
 * surfaced only when something wanted a C99 name:
 *
 *   dtimespec-bound.h:61 name not declared: DBL_TRUE_MIN
 *
 * float_arch.h is the stock content, unchanged. float_ext.h is the
 * C99/C11 additions, which are the same for every architecture.
 */
#include <float_arch.h>
#include <float_ext.h>

#endif /* _FLOAT_H */
