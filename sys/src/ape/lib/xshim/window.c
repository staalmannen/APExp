#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/*
 * Single-window design: rio chose the window's size and place, so the
 * geometry and parent here are ignored and the one window is returned.
 */
Window
XCreateSimpleWindow(Display *dpy, Window parent, int x, int y,
	unsigned int width, unsigned int height, unsigned int border_width,
	unsigned long border, unsigned long background)
{
	USED(dpy); USED(parent); USED(x); USED(y); USED(width); USED(height); USED(border_width); USED(border); USED(background);
	return XSHIM_WINDOW;
}

int
XMapWindow(Display *dpy, Window w)
{
	USED(dpy); USED(w);
	return 1;
}

int
XUnmapWindow(Display *dpy, Window w)
{
	USED(dpy); USED(w);
	return 1;
}

int
XDestroyWindow(Display *dpy, Window w)
{
	USED(dpy); USED(w);
	return 1;
}

/* the window background is not kept, so clearing paints white */
int
XClearWindow(Display *dpy, Window w)
{
	USED(dpy); USED(w);
	draw(xs_dpy->image, xs_dpy->image->r, xs_dpy->white, nil, ZP);
	return 1;
}

/* events are delivered whatever the mask says; accepted for compatibility */
int
XSelectInput(Display *dpy, Window w, long mask)
{
	USED(dpy); USED(w); USED(mask);
	return 1;
}
