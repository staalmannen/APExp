/*
 * xshim -- a thin Xlib-compatible subset backed by libdraw.
 *
 * Single-window design: the whole program is one rio window.  The root window
 * and the one top-level window are the only windows; subwindows are not
 * supported yet.  Colours are X TrueColor 0xRRGGBB pixels.
 *
 * Programs include this header directly.  Xlib's names and field types are
 * kept so that simple X programs compile against it unchanged.  The old X11
 * headers stay in place for the Tk Plan 9 backend, which needs the full
 * multi-window API that the single-window shim does not provide.  The implementation lives in sys/src/ape/lib/xshim
 * and does not include this file, because it uses libdraw's Display type.
 */
#ifndef _XSHIM_H_
#define _XSHIM_H_

#include <xshim_types.h>

#pragma lib "/$M/lib/ape/libxshim.a"
#pragma lib "/$M/lib/ape/libdraw.a"

typedef struct _XDisplay Display;
typedef struct _XGC *GC;

/* display */
extern Display	*XOpenDisplay(char *name);
extern int	XCloseDisplay(Display *dpy);
extern int	XDefaultScreen(Display *dpy);
extern Window	XDefaultRootWindow(Display *dpy);
extern int	XDisplayWidth(Display *dpy, int screen);
extern int	XDisplayHeight(Display *dpy, int screen);
extern unsigned long XBlackPixel(Display *dpy, int screen);
extern unsigned long XWhitePixel(Display *dpy, int screen);
extern int	XFlush(Display *dpy);
extern int	XSync(Display *dpy, Bool discard);

/* windows */
extern Window	XCreateSimpleWindow(Display *dpy, Window parent, int x, int y,
			unsigned int width, unsigned int height,
			unsigned int border_width, unsigned long border,
			unsigned long background);
extern int	XMapWindow(Display *dpy, Window w);
extern int	XUnmapWindow(Display *dpy, Window w);
extern int	XDestroyWindow(Display *dpy, Window w);
extern int	XClearWindow(Display *dpy, Window w);
extern int	XSelectInput(Display *dpy, Window w, long mask);

/* graphics contexts */
extern GC	XCreateGC(Display *dpy, Drawable d, unsigned long mask, XGCValues *values);
extern int	XFreeGC(Display *dpy, GC gc);
extern int	XSetForeground(Display *dpy, GC gc, unsigned long fg);
extern int	XSetBackground(Display *dpy, GC gc, unsigned long bg);
extern int	XSetLineAttributes(Display *dpy, GC gc, unsigned int width,
			int line_style, int cap_style, int join_style);

/* drawing */
extern int	XFillRectangle(Display *dpy, Drawable d, GC gc,
			int x, int y, unsigned int width, unsigned int height);
extern int	XFillRectangles(Display *dpy, Drawable d, GC gc,
			XRectangle *rects, int n);
extern int	XDrawRectangle(Display *dpy, Drawable d, GC gc,
			int x, int y, unsigned int width, unsigned int height);
extern int	XDrawLine(Display *dpy, Drawable d, GC gc,
			int x1, int y1, int x2, int y2);

/* atoms */
extern Atom	XInternAtom(Display *dpy, char *name, Bool only_if_exists);

/* events */
extern int	XPending(Display *dpy);
extern int	XNextEvent(Display *dpy, XEvent *event);

#endif /* _XSHIM_H_ */
