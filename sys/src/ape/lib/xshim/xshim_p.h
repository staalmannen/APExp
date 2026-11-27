/*
 * xshim_p.h -- private to the xshim implementation.  It uses libdraw, so the
 * including file must include <draw.h> first.
 */
#include <xshim_types.h>
#include "xs_clip.h"
#include "xs_win.h"

/* the one display, set by XOpenDisplay */
extern Display	*xs_dpy;

/* set by eresized when rio resizes the window; the expose events are made on
 * the next read (event.c) */
extern int	xs_expose;

/* a 1x1 image of a TrueColor pixel, from draw.c; the caller frees it */
extern Image	*xs_colour(unsigned long pixel);

/* where a drawable is: its absolute origin, and the rectangle its drawing may
 * reach (empty when unmapped).  Returns 0 if it is not a window. */
extern int	xs_target(Drawable d, Point *org, Rectangle *clip);

/* clip all drawing on the window to c, and back to the whole window */
extern void	xs_clipbegin(Rectangle c);
extern void	xs_clipend(void);

/* clear w to its background pixel (draw.c) */
extern void	xs_clearwin(xs_win *w);

/* queue an Expose for w if it selects one (event.c) */
extern void	xs_event_expose(xs_win *w);

/* the region and clip functions the GC code calls (xs_region.c, xs_gc.c) */
extern Region	XCreateRegion(void);
extern int	XDestroyRegion(Region rgn);
extern int	XUnionRectWithRegion(XRectangle *rect, Region src, Region dst);
extern int	XCopyRegion(Region src, Region dst);
extern int	XSetClipMask(Display *d, GC gc, Pixmap pixmap);
