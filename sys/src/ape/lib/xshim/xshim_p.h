/*
 * xshim_p.h -- private to the xshim implementation.  It uses libdraw's
 * Display, so it must not be included together with <xshim.h>.
 */
#include <xshim_types.h>

typedef struct _XGC *GC;

/* the one display, set by XOpenDisplay */
extern Display	*xs_dpy;

/* set by eresized when rio resizes the window; cleared when reported */
extern int	xs_expose;

/* a graphics context: foreground and background are 1x1 replicated images */
struct _XGC {
	Image	*fg;
	Image	*bg;
	int	function;
	int	line_width;
};

/* the window's rectangle on the screen, so X coordinates are relative to it */
#define xs_origin()	(xs_dpy->image->r.min)
