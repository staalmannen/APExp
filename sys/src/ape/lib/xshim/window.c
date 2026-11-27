#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/*
 * The window functions, over the window tree in xs_win.c.  Only the rio window
 * exists as a real window; everything else is a rectangle inside it.
 */

Window
XCreateSimpleWindow(Display *dpy, Window parent, int x, int y,
	unsigned int width, unsigned int height, unsigned int border_width,
	unsigned long border, unsigned long background)
{
	xs_win *p, *c;

	USED(dpy);
	USED(border_width);
	USED(border);
	p = xs_win_find(parent);
	if(p == nil)
		return None;
	c = xs_win_create(p, x, y, width, height, background, 0);
	return c != nil ? c->id : None;
}

Window
XCreateWindow(Display *dpy, Window parent, int x, int y, unsigned int width,
	unsigned int height, unsigned int border_width, int depth,
	unsigned int c_class, void *visual, unsigned long valuemask,
	XSetWindowAttributes *attributes)
{
	xs_win *p, *c;
	unsigned long bg;
	long mask;

	USED(dpy);
	USED(border_width);
	USED(depth);
	USED(c_class);
	USED(visual);
	bg = 0xFFFFFF;
	mask = 0;
	if(attributes != nil){
		if(valuemask & CWBackPixel)
			bg = attributes->background_pixel;
		if(valuemask & CWEventMask)
			mask = attributes->event_mask;
	}
	p = xs_win_find(parent);
	if(p == nil)
		return None;
	c = xs_win_create(p, x, y, width, height, bg, mask);
	return c != nil ? c->id : None;
}

int
XMapWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	if(!c->mapped){
		c->mapped = 1;
		xs_event_expose(c);
	}
	return 1;
}

int
XUnmapWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	c->mapped = 0;
	return 1;
}

int
XDestroyWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil || c == xs_win_root())
		return 0;
	xs_win_destroy(c);
	return 1;
}

int
XClearWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	xs_clearwin(c);
	return 1;
}

int
XSelectInput(Display *dpy, Window w, long mask)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	c->mask = mask;
	return 1;
}

int
XMoveWindow(Display *dpy, Window w, int x, int y)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil || c == xs_win_root())
		return 0;
	c->x = x;
	c->y = y;
	return 1;
}

int
XResizeWindow(Display *dpy, Window w, unsigned int width, unsigned int height)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil || c == xs_win_root())
		return 0;
	c->w = width;
	c->h = height;
	if(c->mapped)
		xs_event_expose(c);
	return 1;
}

int
XMoveResizeWindow(Display *dpy, Window w, int x, int y, unsigned int width,
	unsigned int height)
{
	return XMoveWindow(dpy, w, x, y) && XResizeWindow(dpy, w, width, height);
}

int
XRaiseWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	xs_win_raise(c, 1);
	return 1;
}

int
XLowerWindow(Display *dpy, Window w)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	xs_win_raise(c, 0);
	return 1;
}

int
XSetWindowBackground(Display *dpy, Window w, unsigned long pixel)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(w);
	if(c == nil)
		return 0;
	c->bg = pixel;
	return 1;
}

int
XSetInputFocus(Display *dpy, Window w, int revert_to, Time time)
{
	xs_win *c;

	USED(dpy);
	USED(revert_to);
	USED(time);
	c = xs_win_find(w);
	xs_win_setfocus(c);
	return 1;
}

int
XGetGeometry(Display *dpy, Drawable d, Window *root, int *x, int *y,
	unsigned int *width, unsigned int *height, unsigned int *border_width,
	unsigned int *depth)
{
	xs_win *c;

	USED(dpy);
	c = xs_win_find(d);
	if(c == nil)
		return 0;
	if(root != nil)
		*root = XSHIM_ROOT;
	if(x != nil)
		*x = c->x;
	if(y != nil)
		*y = c->y;
	if(width != nil)
		*width = c->w;
	if(height != nil)
		*height = c->h;
	if(border_width != nil)
		*border_width = 0;
	if(depth != nil)
		*depth = 24;
	return 1;
}
