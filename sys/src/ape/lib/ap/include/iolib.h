/*
 * pANS stdio -- legacy definitions (for backwards compatibility)
 * This file is deprecated; use <stdio.h> directly
 */
#ifndef _IOLIB_H_
#define _IOLIB_H_

#include <stdio.h>
#include "stdio_impl.h"

/* Legacy flag definitions - mapped to musl equivalents */
#define	BALLOC	F_SVB	/* allocated buffer */
#define	LINEBUF	F_NORD	/* line buffered (stub for compat) */
#define	STRING	0x80	/* output to string (obsolete with musl) */
#define APPEND	F_APP	/* append mode output */

/* Legacy state definitions - no longer used */
#define	CLOSED	0
#define	OPEN	1
#define	RDWR	2
#define	RD	3
#define	WR	4
#define	ERR	5
#define	END	6

/* Legacy function stubs */
#define _IO_setvbuf(f) setvbuf(f, NULL, _IOFBF, BUFSIZ)
#define _IO_sopenr(s) fmemopen((char*)s, strlen(s), "r")
#define _IO_sopenw() open_memstream(NULL, NULL)
#define _IO_sclose(f) ({ char *buf = f->buf; fclose(f); buf; })
#define _IO_newfile() fopen("/dev/null", "r")  /* stub - should not be used */

#endif

