#include <u.h>
#include <libc.h>
#include <draw.h>
#include <math.h>
#include <xshim_types.h>
#include "xshim_p.h"

/*
 * Arcs.  An X arc is sampled into a polyline on its ellipse and drawn with
 * libdraw's poly (outline) or fillpoly (filled).  Angles are in 1/64 degree,
 * counter-clockwise from 3 o'clock, as X has them.
 */

#define FULLCIRCLE	(360*64)

static int
nsegments(int a2)
{
	int deg, n;

	if(a2 < 0)
		a2 = -a2;
	deg = a2 / 64;
	n = deg / 4 + 4;
	if(a2 >= FULLCIRCLE && n < 48)
		n = 48;
	return n;
}

/* the points of an arc with absolute top-left (x,y); pts holds nsegments+3.
 * With pie set, the centre is the first point. */
static int
arcpoints(int x, int y, unsigned int w, unsigned int h, int a1, int a2,
	int pie, Point *pts)
{
	double cx, cy, rx, ry, a, step;
	int i, n, k;

	n = nsegments(a2);
	cx = x + w / 2.0;
	cy = y + h / 2.0;
	rx = w / 2.0;
	ry = h / 2.0;
	k = 0;
	if(pie){
		pts[k].x = (int)(cx + 0.5);
		pts[k].y = (int)(cy + 0.5);
		k++;
	}
	step = (a2 / 64.0) * (M_PI / 180.0) / n;
	a = (a1 / 64.0) * (M_PI / 180.0);
	for(i = 0; i <= n; i++){
		pts[k].x = (int)(cx + rx * cos(a) + 0.5);
		pts[k].y = (int)(cy - ry * sin(a) + 0.5);
		k++;
		a += step;
	}
	return k;
}

int
XDrawArc(Display *dpy, Drawable d, GC gc, int x, int y, unsigned int width,
	unsigned int height, int angle1, int angle2)
{
	Point org, pts[256];
	Rectangle clip;
	Image *c;
	int n, radius;

	USED(dpy);
	if(!xs_target(d, &org, &clip))
		return 0;
	if(width == 0 || height == 0)
		return 1;
	n = arcpoints(org.x + x, org.y + y, width, height, angle1, angle2, 0, pts);
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	radius = gc->line_width > 0 ? gc->line_width - 1 : 0;
	xs_clipbegin(clip);
	poly(screen, pts, n, 0, 0, radius, c, ZP);
	xs_clipend();
	freeimage(c);
	return 1;
}

int
XFillArc(Display *dpy, Drawable d, GC gc, int x, int y, unsigned int width,
	unsigned int height, int angle1, int angle2)
{
	Point org, pts[256];
	Rectangle clip;
	Image *c;
	int n;

	USED(dpy);
	if(!xs_target(d, &org, &clip))
		return 0;
	if(width == 0 || height == 0)
		return 1;
	/* the pie includes the centre; a chord does not */
	n = arcpoints(org.x + x, org.y + y, width, height, angle1, angle2,
		gc->arc_mode == ArcPieSlice, pts);
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	xs_clipbegin(clip);
	fillpoly(screen, pts, n, ~0, c, ZP);
	xs_clipend();
	freeimage(c);
	return 1;
}

int
XDrawArcs(Display *dpy, Drawable d, GC gc, XArc *arcs, int n)
{
	int i;

	for(i = 0; i < n; i++)
		if(!XDrawArc(dpy, d, gc, arcs[i].x, arcs[i].y, arcs[i].width,
		    arcs[i].height, arcs[i].angle1, arcs[i].angle2))
			return 0;
	return 1;
}

int
XFillArcs(Display *dpy, Drawable d, GC gc, XArc *arcs, int n)
{
	int i;

	for(i = 0; i < n; i++)
		if(!XFillArc(dpy, d, gc, arcs[i].x, arcs[i].y, arcs[i].width,
		    arcs[i].height, arcs[i].angle1, arcs[i].angle2))
			return 0;
	return 1;
}
