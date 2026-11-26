/*
 * xshim_p.h -- private to the xshim implementation.  It uses libdraw's
 * Display, so it must not be included together with <xshim.h>.
 */
#include <xshim_types.h>

/* the one display, set by XOpenDisplay */
extern Display	*xs_dpy;

/* set by eresized when rio resizes the window; cleared when reported */
extern int	xs_expose;

/* the window's rectangle on the screen, so X coordinates are relative to it */
#define xs_origin()	(xs_dpy->image->r.min)

/* the region and clip functions the GC code calls (xs_region.c, xs_gc.c) */
extern Region	XCreateRegion(void);
extern int	XDestroyRegion(Region rgn);
extern int	XUnionRectWithRegion(XRectangle *rect, Region src, Region dst);
extern int	XCopyRegion(Region src, Region dst);
extern int	XSetClipMask(Display *d, GC gc, Pixmap pixmap);

#include "xs_clip.h"
