/*
 * xshim_p.h -- private to the xshim implementation.  It uses libdraw's
 * Display, so it must not be included together with <xshim.h>.
 */
#include <xshim_types.h>

/* the one display, set by XOpenDisplay */
extern Display	*xs_dpy;

/* clip all drawing to the window (display.c); call after any change of window */
extern void	xs_clipwindow(void);

/* set by eresized when rio resizes the window; cleared when reported */
extern int	xs_expose;

/* a 1x1 image of a TrueColor pixel, from draw.c; the caller frees it */
extern Image	*xs_colour(unsigned long pixel);

/* the window's rectangle on the screen, so X coordinates are relative to it */
#define xs_origin()	(screen->r.min)

/* the region and clip functions the GC code calls (xs_region.c, xs_gc.c) */
extern Region	XCreateRegion(void);
extern int	XDestroyRegion(Region rgn);
extern int	XUnionRectWithRegion(XRectangle *rect, Region src, Region dst);
extern int	XCopyRegion(Region src, Region dst);
extern int	XSetClipMask(Display *d, GC gc, Pixmap pixmap);

#include "xs_clip.h"
