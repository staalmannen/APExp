#include <u.h>
#include <libc.h>
#include <draw.h>
#include <xshim_types.h>
#include "xshim_p.h"

/*
 * The graphics context functions.  Moved from Tk's Plan 9 port (xlib/xgc.c)
 * with the same behaviour; the GC is the XGCValues record, as Tk had it.
 *
 * Substitutions, each one a library name for a Tk one:
 *	ckalloc, ckfree		malloc, free
 *	TkCreateRegion etc.	XCreateRegion etc. (xs_region.c)
 *	Tcl_Panic		xs_panic, which prints and exits
 *	BlackPixelOfScreen	the constant 0, WhitePixelOfScreen 0xFFFFFF
 * XSetDashes's Windows-only TkWin* calls are dropped: they were under an
 * #ifdef that never holds on Plan 9.
 */

#define XS_CLIP_PIXMAP	0
#define XS_CLIP_REGION	1

#define MAX_DASH_LIST_SIZE 10

/* a GC is allocated with room for its dash list after the record */
typedef struct {
	XGCValues gc;
	char dash[MAX_DASH_LIST_SIZE];
} XGCValuesWithDash;

static void
xs_panic(char *msg)
{
	fprint(2, "xshim: %s\n", msg);
	exits("xshim panic");
}

static xs_clip*
AllocClipMask(GC gc)
{
	xs_clip *clip_mask = xs_clip_get(gc->clip_mask);

	if(clip_mask == nil){
		clip_mask = malloc(sizeof(xs_clip));
		if(clip_mask == nil)
			xs_panic("AllocClipMask: out of memory");
		gc->clip_mask = xs_clip_new(clip_mask);
		if(gc->clip_mask == None)
			xs_panic("AllocClipMask: out of memory");
	} else if(clip_mask->type == XS_CLIP_REGION){
		XDestroyRegion(clip_mask->value.region);
	}
	clip_mask->type = XS_CLIP_PIXMAP;
	clip_mask->value.pixmap = None;
	return clip_mask;
}

static void
FreeClipMask(GC gc)
{
	xs_clip *clip_mask = xs_clip_get(gc->clip_mask);

	if(clip_mask == nil)
		return;
	if(clip_mask->type == XS_CLIP_REGION)
		XDestroyRegion(clip_mask->value.region);
	free(clip_mask);
	xs_clip_release(gc->clip_mask);
	gc->clip_mask = None;
}

GC
XCreateGC(Display *display, Drawable d, unsigned long mask, XGCValues *values)
{
	XGCValuesWithDash *gp;
	GC gc;

	USED(display);
	USED(d);
	gp = malloc(sizeof *gp);
	if(gp == nil)
		return nil;
	memset(gp, 0, sizeof *gp);
	gc = &gp->gc;

#define InitField(name,maskbit,default) \
	(gc->name = (mask & (maskbit)) ? values->name : (default))

	InitField(function,		GCFunction,		GXcopy);
	InitField(plane_mask,		GCPlaneMask,		(unsigned long)(~0));
	InitField(foreground,		GCForeground,		0x000000);
	InitField(background,		GCBackground,		0xFFFFFF);
	InitField(line_width,		GCLineWidth,		1);
	InitField(line_style,		GCLineStyle,		LineSolid);
	InitField(cap_style,		GCCapStyle,		0);
	InitField(join_style,		GCJoinStyle,		0);
	InitField(fill_style,		GCFillStyle,		FillSolid);
	InitField(fill_rule,		GCFillRule,		EvenOddRule);
	InitField(arc_mode,		GCArcMode,		ArcPieSlice);
	InitField(tile,			GCTile,			0);
	InitField(stipple,		GCStipple,		0);
	InitField(ts_x_origin,		GCTileStipXOrigin,	0);
	InitField(ts_y_origin,		GCTileStipYOrigin,	0);
	InitField(font,			GCFont,			0);
	InitField(subwindow_mode,	GCSubwindowMode,	ClipByChildren);
	InitField(graphics_exposures,	GCGraphicsExposures,	True);
	InitField(clip_x_origin,	GCClipXOrigin,		0);
	InitField(clip_y_origin,	GCClipYOrigin,		0);
	InitField(dash_offset,		GCDashOffset,		0);
	InitField(dashes,		GCDashList,		4);
	(&(gc->dashes))[1] = 0;

	gc->clip_mask = None;
	if(mask & GCClipMask){
		xs_clip *clip_mask = AllocClipMask(gc);

		clip_mask->type = XS_CLIP_PIXMAP;
		clip_mask->value.pixmap = values->clip_mask;
	}
	return gc;
}

int
XChangeGC(Display *d, GC gc, unsigned long mask, XGCValues *values)
{
#define ModifyField(name,maskbit) \
	if(mask & (maskbit)) { gc->name = values->name; }

	ModifyField(function, GCFunction);
	ModifyField(plane_mask, GCPlaneMask);
	ModifyField(foreground, GCForeground);
	ModifyField(background, GCBackground);
	ModifyField(line_width, GCLineWidth);
	ModifyField(line_style, GCLineStyle);
	ModifyField(cap_style, GCCapStyle);
	ModifyField(join_style, GCJoinStyle);
	ModifyField(fill_style, GCFillStyle);
	ModifyField(fill_rule, GCFillRule);
	ModifyField(arc_mode, GCArcMode);
	ModifyField(tile, GCTile);
	ModifyField(stipple, GCStipple);
	ModifyField(ts_x_origin, GCTileStipXOrigin);
	ModifyField(ts_y_origin, GCTileStipYOrigin);
	ModifyField(font, GCFont);
	ModifyField(subwindow_mode, GCSubwindowMode);
	ModifyField(graphics_exposures, GCGraphicsExposures);
	ModifyField(clip_x_origin, GCClipXOrigin);
	ModifyField(clip_y_origin, GCClipYOrigin);
	ModifyField(dash_offset, GCDashOffset);
	if(mask & GCClipMask)
		XSetClipMask(d, gc, values->clip_mask);
	if(mask & GCDashList){
		gc->dashes = values->dashes;
		(&(gc->dashes))[1] = 0;
	}
	return Success;
}

int
XFreeGC(Display *d, GC gc)
{
	USED(d);
	if(gc != nil){
		FreeClipMask(gc);
		free(gc);
	}
	return Success;
}

int
XSetForeground(Display *d, GC gc, unsigned long foreground)
{
	USED(d);
	gc->foreground = foreground;
	return Success;
}

int
XSetBackground(Display *d, GC gc, unsigned long background)
{
	USED(d);
	gc->background = background;
	return Success;
}

int
XSetDashes(Display *d, GC gc, int dash_offset, char *dash_list, int n)
{
	char *p = &(gc->dashes);

	USED(d);
	gc->dash_offset = dash_offset;
	if(n > MAX_DASH_LIST_SIZE)
		n = MAX_DASH_LIST_SIZE;
	while(n-- > 0)
		*p++ = *dash_list++;
	*p = 0;
	return Success;
}

int
XSetFunction(Display *d, GC gc, int function)
{
	USED(d);
	gc->function = function;
	return Success;
}

int
XSetFillRule(Display *d, GC gc, int fill_rule)
{
	USED(d);
	gc->fill_rule = fill_rule;
	return Success;
}

int
XSetFillStyle(Display *d, GC gc, int fill_style)
{
	USED(d);
	gc->fill_style = fill_style;
	return Success;
}

int
XSetTSOrigin(Display *d, GC gc, int x, int y)
{
	USED(d);
	gc->ts_x_origin = x;
	gc->ts_y_origin = y;
	return Success;
}

int
XSetFont(Display *d, GC gc, XID font)
{
	USED(d);
	gc->font = font;
	return Success;
}

int
XSetArcMode(Display *d, GC gc, int arc_mode)
{
	USED(d);
	gc->arc_mode = arc_mode;
	return Success;
}

int
XSetStipple(Display *d, GC gc, Pixmap stipple)
{
	USED(d);
	gc->stipple = stipple;
	return Success;
}

int
XSetLineAttributes(Display *d, GC gc, unsigned int line_width, int line_style,
	int cap_style, int join_style)
{
	USED(d);
	gc->line_width = line_width;
	gc->line_style = line_style;
	gc->cap_style = cap_style;
	gc->join_style = join_style;
	return Success;
}

int
XSetClipOrigin(Display *d, GC gc, int clip_x_origin, int clip_y_origin)
{
	USED(d);
	gc->clip_x_origin = clip_x_origin;
	gc->clip_y_origin = clip_y_origin;
	return Success;
}

/*
 * XSetRegion, which Tk calls as TkSetRegion.  The copy below is what Tk had:
 * it stores r and then overwrites the pointer, so the caller's region is not
 * kept.  That is a known fault, kept so that this step is a move.
 */
int
XSetRegion(Display *d, GC gc, Region r)
{
	USED(d);
	if(r == nil){
		xs_panic("must not pass NULL to XSetRegion for compatibility with X11; use XSetClipMask instead");
	} else {
		xs_clip *clip_mask = AllocClipMask(gc);

		clip_mask->type = XS_CLIP_REGION;
		clip_mask->value.region = r;
		clip_mask->value.region = XCreateRegion();
		XCopyRegion(r, clip_mask->value.region);
	}
	return Success;
}

int
XSetClipMask(Display *d, GC gc, Pixmap pixmap)
{
	USED(d);
	if(pixmap == None){
		FreeClipMask(gc);
	} else {
		xs_clip *clip_mask = AllocClipMask(gc);

		clip_mask->type = XS_CLIP_PIXMAP;
		clip_mask->value.pixmap = pixmap;
	}
	return Success;
}

int
XSetClipRectangles(Display *d, GC gc, int clip_x_origin, int clip_y_origin,
	XRectangle *rectangles, int n, int ordering)
{
	Region clipRgn;
	xs_clip *clip_mask;

	USED(d);
	USED(ordering);
	clipRgn = XCreateRegion();
	clip_mask = AllocClipMask(gc);
	clip_mask->type = XS_CLIP_REGION;
	clip_mask->value.region = clipRgn;

	while(n--){
		XRectangle rect = *rectangles;

		rect.x += clip_x_origin;
		rect.y += clip_y_origin;
		XUnionRectWithRegion(&rect, clipRgn, clipRgn);
		rectangles++;
	}
	return 1;
}
