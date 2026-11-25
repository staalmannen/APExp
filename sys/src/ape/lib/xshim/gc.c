#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/* a 1x1 replicated image of a TrueColor 0xRRGGBB pixel */
static Image*
colour(unsigned long pixel)
{
	return allocimage(xs_dpy, Rect(0, 0, 1, 1), RGBA32, 1, (pixel << 8) | 0xFF);
}

GC
XCreateGC(Display *dpy, Drawable d, unsigned long mask, XGCValues *values)
{
	struct _XGC *gc;

	USED(dpy); USED(d);
	gc = mallocz(sizeof *gc, 1);
	if(gc == nil)
		return nil;
	gc->function = GXcopy;
	gc->line_width = 0;
	gc->fg = colour(0x000000);
	gc->bg = colour(0xFFFFFF);
	if(values != nil){
		if(mask & GCFunction)
			gc->function = values->function;
		if(mask & GCLineWidth)
			gc->line_width = values->line_width > 0 ? values->line_width - 1 : 0;
		if((mask & GCForeground) && gc->fg != nil){
			freeimage(gc->fg);
			gc->fg = colour(values->foreground);
		}
		if((mask & GCBackground) && gc->bg != nil){
			freeimage(gc->bg);
			gc->bg = colour(values->background);
		}
	}
	return gc;
}

int
XFreeGC(Display *dpy, GC gc)
{
	USED(dpy);
	if(gc == nil)
		return 1;
	if(gc->fg != nil)
		freeimage(gc->fg);
	if(gc->bg != nil)
		freeimage(gc->bg);
	free(gc);
	return 1;
}

int
XSetForeground(Display *dpy, GC gc, unsigned long fg)
{
	USED(dpy);
	if(gc->fg != nil)
		freeimage(gc->fg);
	gc->fg = colour(fg);
	return 1;
}

int
XSetBackground(Display *dpy, GC gc, unsigned long bg)
{
	USED(dpy);
	if(gc->bg != nil)
		freeimage(gc->bg);
	gc->bg = colour(bg);
	return 1;
}

/* only the width is used; X's width 1 is a one-pixel line, radius 0 */
int
XSetLineAttributes(Display *dpy, GC gc, unsigned int width,
	int line_style, int cap_style, int join_style)
{
	USED(dpy); USED(line_style); USED(cap_style); USED(join_style);
	gc->line_width = width > 0 ? width - 1 : 0;
	return 1;
}
