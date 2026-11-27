#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/*
 * Drawing.  A GC holds a TrueColor pixel (0xRRGGBB).  libdraw draws from an
 * image, so each call makes a 1x1 replicated image of the foreground and frees
 * it afterwards.  Each drawing is offset into its window and clipped to the
 * window's visible rectangle.  The GC's own clip mask is not applied yet.
 */

int
xs_target(Drawable d, Point *org, Rectangle *clip)
{
	xs_win *w;
	int ax, ay, x0, y0, x1, y1;

	w = xs_win_find(d);
	if(w == nil)
		return 0;
	xs_win_abs(w, &ax, &ay);
	org->x = ax;
	org->y = ay;
	if(!w->mapped){
		*clip = Rect(0, 0, 0, 0);
		return 1;
	}
	xs_win_visible(w, &x0, &y0, &x1, &y1);
	*clip = Rect(x0, y0, x1, y1);
	return 1;
}

void
xs_clipbegin(Rectangle c)
{
	replclipr(screen, 0, c);
}

void
xs_clipend(void)
{
	replclipr(screen, 0, screen->r);
}

/* a 1x1 replicated image of a TrueColor pixel */
Image*
xs_colour(unsigned long pixel)
{
	return allocimage(xs_dpy, Rect(0, 0, 1, 1), RGBA32, 1, (pixel << 8) | 0xFF);
}

void
xs_clearwin(xs_win *w)
{
	Point org;
	Rectangle clip;
	Image *c;

	if(!xs_target(w->id, &org, &clip))
		return;
	c = xs_colour(w->bg);
	if(c == nil)
		return;
	xs_clipbegin(clip);
	draw(screen, Rect(org.x, org.y, org.x + w->w, org.y + w->h), c, nil, ZP);
	xs_clipend();
	freeimage(c);
}

int
XFillRectangle(Display *dpy, Drawable d, GC gc, int x, int y,
	unsigned int width, unsigned int height)
{
	Point org;
	Rectangle clip;
	Image *c;

	USED(dpy);
	if(!xs_target(d, &org, &clip))
		return 0;
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	xs_clipbegin(clip);
	draw(screen, Rect(org.x + x, org.y + y, org.x + x + width, org.y + y + height),
		c, nil, ZP);
	xs_clipend();
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
	Point org, p0, p1;
	Rectangle clip;
	Image *c;
	int radius;

	USED(dpy);
	if(!xs_target(d, &org, &clip))
		return 0;
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	/* X's width 1 is a one-pixel line: radius 0 */
	radius = gc->line_width > 0 ? gc->line_width - 1 : 0;
	p0 = Pt(org.x + x1, org.y + y1);
	p1 = Pt(org.x + x2, org.y + y2);
	xs_clipbegin(clip);
	line(screen, p0, p1, 0, 0, radius, c, ZP);
	xs_clipend();
	freeimage(c);
	return 1;
}
