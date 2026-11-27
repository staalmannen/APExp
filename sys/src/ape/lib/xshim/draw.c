#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/*
 * Drawing.  A GC holds a TrueColor pixel (0xRRGGBB), and libdraw draws from an
 * image, so each call makes a 1x1 replicated image of the foreground and frees
 * it afterwards.  The GC's clip mask is not applied yet.
 */

/* X rectangle at (x,y) of size w x h, in screen coordinates */
static Rectangle
xrect(int x, int y, int w, int h)
{
	Point p;

	p = addpt(xs_origin(), Pt(x, y));
	return Rpt(p, addpt(p, Pt(w, h)));
}

/* only the window is a drawable; pixmaps are not supported yet */
static int
drawable_ok(Drawable d)
{
	return d == XSHIM_WINDOW || d == XSHIM_ROOT;
}

/* a 1x1 replicated image of a TrueColor pixel */
Image*
xs_colour(unsigned long pixel)
{
	return allocimage(xs_dpy, Rect(0, 0, 1, 1), RGBA32, 1, (pixel << 8) | 0xFF);
}

int
XFillRectangle(Display *dpy, Drawable d, GC gc, int x, int y,
	unsigned int width, unsigned int height)
{
	Image *c;

	USED(dpy);
	if(!drawable_ok(d))
		return 0;
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	draw(screen, xrect(x, y, width, height), c, nil, ZP);
	freeimage(c);
	return 1;
}

int
XFillRectangles(Display *dpy, Drawable d, GC gc, XRectangle *rects, int n)
{
	int i;

	for(i = 0; i < n; i++)
		if(!XFillRectangle(dpy, d, gc, rects[i].x, rects[i].y,
		    rects[i].width, rects[i].height))
			return 0;
	return 1;
}

/* the outline is four one-pixel strips, so it works at any size */
int
XDrawRectangle(Display *dpy, Drawable d, GC gc, int x, int y,
	unsigned int width, unsigned int height)
{
	if(width == 0 || height == 0)
		return 1;
	if(!XFillRectangle(dpy, d, gc, x, y, width, 1)
	|| !XFillRectangle(dpy, d, gc, x, y + height - 1, width, 1)
	|| !XFillRectangle(dpy, d, gc, x, y, 1, height)
	|| !XFillRectangle(dpy, d, gc, x + width - 1, y, 1, height))
		return 0;
	return 1;
}

int
XDrawLine(Display *dpy, Drawable d, GC gc, int x1, int y1, int x2, int y2)
{
	Point p0, p1;
	Image *c;
	int radius;

	USED(dpy);
	if(!drawable_ok(d))
		return 0;
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	/* X's width 1 is a one-pixel line: radius 0 */
	radius = gc->line_width > 0 ? gc->line_width - 1 : 0;
	p0 = addpt(xs_origin(), Pt(x1, y1));
	p1 = addpt(xs_origin(), Pt(x2, y2));
	line(screen, p0, p1, 0, 0, radius, c, ZP);
	freeimage(c);
	return 1;
}
