#ifndef _SYS_RANDOM_H
#define _SYS_RANDOM_H

/* getentropy and getrandom both take a size_t, so that this header stands on its own. */
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#define GRND_NONBLOCK	0x0001
#define GRND_RANDOM	0x0002
#define GRND_INSECURE	0x0004

ssize_t getrandom(void *, size_t, unsigned);

#ifdef __cplusplus
}
#endif
#endif
