/*
 * tkPlan9Port.h --
 *
 *	Portability shims for the Plan 9 Tk backend.
 *	Included by all Plan 9 backend C files (via tkInt.h).
 */

#ifndef _TKP9PORT_H
#define _TKP9PORT_H

#define __UNIX__ 1	/* Tk generic code gates on this */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <inttypes.h>
#include <assert.h>

#ifndef _TCL
#   include <tcl.h>
#endif

#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

/*
 * fd_set / SELECT_MASK
 */
#ifndef NO_FD_SET
#   define SELECT_MASK fd_set
#else
	typedef long fd_mask;
#   define SELECT_MASK int
#endif
#ifndef FD_SETSIZE
#   define FD_SETSIZE 256
#endif
#ifndef NBBY
#   define NBBY 8
#endif
#ifndef NFDBITS
#   define NFDBITS (NBBY * sizeof(fd_mask))
#endif
#if !defined(howmany)
#   define howmany(x,y) (((x)+((y)-1))/(y))
#endif
#define MASK_SIZE howmany(FD_SETSIZE, NFDBITS)

#include "tkIntXlibDecls.h"

/* Types used by Win/Mac stubs in generic code */
#define UINT		unsigned int
#define HWND		void *
#define HDC		void *
#define HINSTANCE	void *
#define COLORREF	void *
#define HMENU		void *
#define TkWinDCState	void
#define HPALETTE	void *
#define WNDPROC		void *
#define WPARAM		void *
#define LPARAM		void *
#define LRESULT		void *

/* Seek constants */
#ifndef SEEK_SET
#   define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#   define SEEK_CUR 1
#endif
#ifndef SEEK_END
#   define SEEK_END 2
#endif

/*
 * Macros that eliminate Windows/Mac-only calls in generic code.
 */
#define TkpButtonSetDefaults()		{}
#define TkpDestroyButton(butPtr)	{}
#define TkSelUpdateClipboard(a,b)	{}
#define TkSetPixmapColormap(p,c)	{}

#define TkpPrintWindowId(buf,w) \
	snprintf((buf), TCL_INTEGER_SPACE, "0x%lx", (unsigned long)(w))

#endif /* _TKP9PORT_H */
