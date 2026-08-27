#ifndef _APEXP_STDARG_H_
#define _APEXP_STDARG_H_

/*
 * The generic <stdarg.h>, for anything reaching /sys/include/ape without
 * an architecture directory ahead of it. pcc normally does not get here:
 * every architecture now has its own, which is what shadows the host's
 * stock copy. Both chain to stdarg_arch.h.
 *
 * This used to test _STDARG_H and never define it, so it had no include
 * guard at all and leaned on stdarg_arch.h's __STDARG.
 */
#include <stdarg_arch.h>

#endif /* _APEXP_STDARG_H_ */
