#ifndef _FLOAT_H
#define _FLOAT_H

/*
 * The generic <float.h>, for anything that reaches /sys/include/ape
 * without an architecture directory ahead of it.
 *
 * Note that pcc normally does NOT get here: pcc.c:234-235 passes
 * -I/$objtype/include/ape before -I/sys/include/ape, and every
 * architecture in this tree now has its own float.h, so that one is
 * found first. Both chain to the same two headers.
 */
#include <float_arch.h>
#include <float_ext.h>

#endif /* _FLOAT_H */
