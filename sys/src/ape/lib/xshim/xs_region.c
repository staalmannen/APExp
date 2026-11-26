#include <u.h>
#include <libc.h>
#include <xshim_types.h>

/*
 * The X region functions.  Moved from Tk's Plan 9 port: the region is a
 * bounding box, as Tk's own stub had it.  XPointInRegion, XUnionRegion and
 * XPolygonRegion below are the stubs that were in effect (their objects linked
 * first), moved unchanged; they are not implementations yet.
 */

struct _XRegion {
	int x, y, w, h;
	int empty;
};

/* Copies a region; Tk's TkpCopyRegion uses this. */
int
XCopyRegion(Region src, Region dst)
{
	if (src == NULL || dst == NULL)
		return 0;
	*dst = *src;
	return 0;
}

/*
 * Minimal Plan 9 region implementation.
 *
 * X11 Region is an opaque pointer to struct _XRegion.  We represent it
 * as a simple axis-aligned bounding box.  This is sufficient for all
 * region uses in Tk's generic and unix/ code (scrolling damage, photo
 * images).  Complex multi-rect regions collapse to their union bbox.
 */

Region
XCreateRegion(void)
{
    Region r = (Region) malloc(sizeof(struct _XRegion));
    if (r == NULL)
	return NULL;
    r->x = r->y = r->w = r->h = 0;
    r->empty = 1;
    return r;
}

int
XDestroyRegion(Region rgn)
{
    if (rgn) free(rgn);
    return 0;
}

int
XClipBox(Region rgn, XRectangle *rect_return)
{
    if (!rgn || rgn->empty) {
        rect_return->x = rect_return->y = 0;
        rect_return->width = rect_return->height = 0;
    } else {
        rect_return->x      = (short)rgn->x;
        rect_return->y      = (short)rgn->y;
        rect_return->width  = (unsigned short)rgn->w;
        rect_return->height = (unsigned short)rgn->h;
    }
    return 0;
}

int
XEmptyRegion(Region rgn)
{
    return !rgn || rgn->empty;
}

int
XUnionRectWithRegion(XRectangle *rect, Region src, Region dst)
{
    int x1, y1, x2, y2;
    if (!rect || !src || !dst) return 0;
    if (src->empty) {
        dst->x = rect->x; dst->y = rect->y;
        dst->w = rect->width; dst->h = rect->height;
        dst->empty = (rect->width == 0 || rect->height == 0);
        return 0;
    }
    x1 = src->x < rect->x ? src->x : rect->x;
    y1 = src->y < rect->y ? src->y : rect->y;
    x2 = (src->x + src->w) > (rect->x + rect->width) ?
         (src->x + src->w) : (rect->x + (int)rect->width);
    y2 = (src->y + src->h) > (rect->y + rect->height) ?
         (src->y + src->h) : (rect->y + (int)rect->height);
    dst->x = x1; dst->y = y1;
    dst->w = x2 - x1; dst->h = y2 - y1;
    dst->empty = 0;
    return 0;
}

int
XIntersectRegion(Region sra, Region srcb, Region dr_return)
{
    int x1, y1, x2, y2;
    if (!sra || !srcb || !dr_return) return 0;
    if (sra->empty || srcb->empty) { dr_return->empty = 1; return 0; }
    x1 = sra->x > srcb->x ? sra->x : srcb->x;
    y1 = sra->y > srcb->y ? sra->y : srcb->y;
    x2 = (sra->x + sra->w) < (srcb->x + srcb->w) ?
         (sra->x + sra->w) : (srcb->x + srcb->w);
    y2 = (sra->y + sra->h) < (srcb->y + srcb->h) ?
         (sra->y + sra->h) : (srcb->y + srcb->h);
    if (x2 <= x1 || y2 <= y1) { dr_return->empty = 1; return 0; }
    dr_return->x = x1; dr_return->y = y1;
    dr_return->w = x2 - x1; dr_return->h = y2 - y1;
    dr_return->empty = 0;
    return 0;
}

int
XSubtractRegion(Region sra, Region srcb, Region dr_return)
{
    /* Approximate: return sra (subtraction of bbox is complex) */
    if (!sra || !dr_return) return 0;
    *dr_return = *sra;
    (void)srcb;
    return 0;
}

int
XRectInRegion(Region rgn, int x, int y, unsigned int w, unsigned int h)
{
    if (!rgn || rgn->empty) return RectangleOut;
    if (x >= rgn->x + rgn->w || y >= rgn->y + rgn->h ||
        (int)(x + w) <= rgn->x || (int)(y + h) <= rgn->y)
        return RectangleOut;
    if (x >= rgn->x && y >= rgn->y &&
        (int)(x + w) <= rgn->x + rgn->w &&
        (int)(y + h) <= rgn->y + rgn->h)
        return RectangleIn;
    return RectanglePart;
}

int
XOffsetRegion(Region rgn, int dx, int dy)
{
    if (rgn && !rgn->empty) { rgn->x += dx; rgn->y += dy; }
    return 0;
}

Region
XPolygonRegion(XPoint *pts, int n, int rule)
{
    (void)pts; (void)n; (void)rule;
    return NULL;
}

int
XPointInRegion(Region rgn, int x, int y)
{
    (void)rgn; (void)x; (void)y;
    return 0;
}

/* XOffsetRegion: real implementation in tkPlan9Stubs.c */

int
XUnionRegion(Region srca, Region srcb, Region dst)
{
    (void)srca; (void)srcb; (void)dst;
    return 0;
}
