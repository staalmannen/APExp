#ifndef __ERROR_H
#define __ERROR_H

#pragma lib "/$M/lib/ape/libap.a"

#ifdef __cplusplus
extern "C" {
#endif

extern char *_progname;		/* program name */
extern void _perror(char *);	/* perror but with _progname */

#ifdef __cplusplus
}
#endif

#endif /* _ERROR_H */
