#ifndef _NETWORK_LOCK_H
#define _NETWORK_LOCK_H

/* Minimal LOCK/UNLOCK for musl-ported resolver (Plan9 APE is single-process) */
#define LOCK(x)		((void)(x))
#define UNLOCK(x)	((void)(x))

#endif
