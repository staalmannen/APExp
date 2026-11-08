#ifndef __npe_h__
#define __npe_h__

#pragma lib "libnpe.a"

#ifndef nil
#include <u.h>
#endif
#ifndef nelem
#include <libc.h>
#endif

typedef vlong off_t;

#ifndef Nsec
#define Nsec 1000000000ULL
#define Nmsec 1000000ULL
uvlong npe_nanosec(void);
void npe_nsleep(uvlong ns);
int npe_mkdirp(char *s, int perm);
#endif

/* programs quite often do not include these directly */
#ifndef NULL
#include </sys/include/stdio.h>
#endif
#ifndef isalpha
#include </sys/include/ctype.h>
#endif
#include <stddef.h>

/* some programs do not #include <strings.h> */
#ifndef strcasecmp
#define strcasecmp cistrcmp
#define strncasecmp cistrncmp
#define strcasestr cistrstr
#endif

#ifndef __attribute__
#define __attribute__(a)
#endif

/* some programs do not #include <stdlib.h> */
#ifndef getenv
#define getenv npe_getenv
char *npe_getenv(char *s);
#endif

/* to override "main" with our own threadmain */
#ifndef __plan9_keep_main__
#define main npe_main_renamed
#pragma lib "libthread.a"
#endif

extern void (*exit)(int);

#endif
