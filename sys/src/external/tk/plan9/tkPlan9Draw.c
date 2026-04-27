/*
 * tkPlan9Draw.c --
 *
 *	X11 drawing primitives for the Plan 9 Tk backend.
 *
 *	All drawing goes through the tkp9_* API (which routes to libdraw)
 *	so this file never sees Plan 9 types directly.
 *
 *	A "Drawable" in the Plan 9 backend is always either:
 *	  - A window XID (in the P9Window table), or
 *	  - A Pixmap (allocated as an off-screen image region)
 *
 *	We map Drawables to absolute screen coordinates by looking up
 *	the window's (x, y) offset in the P9Window table.
 */

#include "tkPlan9Int.h"

/* ------------------------------------------------------------------ */
/* Colour extraction from GC                                           */
/* ------------------------------------------------------------------ */

static unsigned long
GCForegroundRGBA(GC gc)
{
    unsigned long p = gc->foreground;
    /* p is stored as 0x00RRGGBB by XAllocColor */
    return TkP9XColorStructToRGBA(p);
}

static unsigned long
GCBackgroundRGBA(GC gc)
{
    unsigned long p = gc->background;
    return TkP9XColorStructToRGBA(p);
}

/* ------------------------------------------------------------------ */
/* Window offset lookup                                                */
/* ------------------------------------------------------------------ */

static void
DrawableOffset(Drawable d, int *ox, int *oy)
{
    P9Window *pw = TkP9FindWindow((Window)d);
    if (pw) { *ox = pw->x; *oy = pw->y; }
    else    { *ox = 0;     *oy = 0;     }
}

/* ------------------------------------------------------------------ */
/* Core drawing operations                                             */
/* ------------------------------------------------------------------ */

int
XDrawLines(Display *display, Drawable d, GC gc,
           XPoint *points, int npoints, int mode)
{
    int ox, oy, i;
    unsigned long rgba;
    int lw;
    (void)display;

    if (npoints < 2) return 0;
    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;

    for (i = 0; i < npoints - 1; i++) {
        int x1, y1, x2, y2;
        if (mode == CoordModeOrigin) {
            x1 = points[i].x   + ox;
            y1 = points[i].y   + oy;
            x2 = points[i+1].x + ox;
            y2 = points[i+1].y + oy;
        } else {
            /* CoordModePrevious — each point relative to previous */
            static int cx, cy;
            if (i == 0) { cx = points[0].x + ox; cy = points[0].y + oy; }
            x1 = cx; y1 = cy;
            cx += points[i+1].x; cy += points[i+1].y;
            x2 = cx; y2 = cy;
        }
        tkp9_drawline(x1, y1, x2, y2, lw, rgba);
    }
    return 0;
}

int
XFillRectangles(Display *display, Drawable d, GC gc,
                XRectangle *rects, int nrects)
{
    int ox, oy, i;
    unsigned long rgba;
    (void)display;

    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);

    for (i = 0; i < nrects; i++)
        tkp9_fillrect(rects[i].x + ox, rects[i].y + oy,
                      rects[i].width, rects[i].height, rgba);
    return 0;
}

int
XDrawRectangle(Display *display, Drawable d, GC gc,
               int x, int y, unsigned int w, unsigned int h)
{
    int ox, oy;
    int lw;
    unsigned long rgba;
    (void)display;

    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    tkp9_drawrect(x + ox, y + oy, (int)w, (int)h, lw, rgba);
    return 0;
}

int
XDrawRectangles(Display *display, Drawable d, GC gc,
                XRectangle *rects, int nrects)
{
    int i;
    for (i = 0; i < nrects; i++)
        XDrawRectangle(display, d, gc,
                       rects[i].x, rects[i].y,
                       rects[i].width, rects[i].height);
    return 0;
}

int
XCopyArea(Display *display, Drawable src, Drawable dst, GC gc,
          int src_x, int src_y,
          unsigned int w, unsigned int h,
          int dst_x, int dst_y)
{
    int sox, soy, dox, doy;
    (void)display; (void)gc;

    DrawableOffset(src, &sox, &soy);
    DrawableOffset(dst, &dox, &doy);
    tkp9_copyarea(src_x + sox, src_y + soy,
                  (int)w, (int)h,
                  dst_x + dox, dst_y + doy);
    return 0;
}

int
XCopyPlane(Display *display, Drawable src, Drawable dst, GC gc,
           int src_x, int src_y,
           unsigned int w, unsigned int h,
           int dst_x, int dst_y,
           unsigned long plane)
{
    (void)plane;
    return XCopyArea(display, src, dst, gc,
                     src_x, src_y, w, h, dst_x, dst_y);
}

int
XClearWindow(Display *display, Window w)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw) return 0;
    tkp9_fillrect(pw->x, pw->y, pw->width, pw->height, pw->bg_pixel);
    return 0;
}

int
XClearArea(Display *display, Window w,
           int x, int y, unsigned int width, unsigned int height,
           Bool exposures)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display; (void)exposures;
    if (!pw) return 0;
    tkp9_fillrect(pw->x + x, pw->y + y, (int)width, (int)height,
                  pw->bg_pixel);
    return 0;
}

int
XDrawArc(Display *display, Drawable d, GC gc,
         int x, int y, unsigned int w, unsigned int h,
         int angle1, int angle2)
{
    int ox, oy, lw;
    unsigned long rgba;
    (void)display;

    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    /* Plan 9 arc: centre, semi-axes a,b, line-width, colour, angle pair */
    tkp9_drawarc(x + ox + (int)w/2, y + oy + (int)h/2,
                 (int)w/2, (int)h/2,
                 angle1/64, angle2/64, lw, rgba);
    return 0;
}

int
XFillArc(Display *display, Drawable d, GC gc,
         int x, int y, unsigned int w, unsigned int h,
         int angle1, int angle2)
{
    int ox, oy;
    unsigned long rgba;
    (void)display;

    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    tkp9_fillarc(x + ox + (int)w/2, y + oy + (int)h/2,
                 (int)w/2, (int)h/2,
                 angle1/64, angle2/64, rgba);
    return 0;
}

int
XDrawArcs(Display *display, Drawable d, GC gc, XArc *arcs, int narcs)
{
    int i;
    for (i = 0; i < narcs; i++)
        XDrawArc(display, d, gc,
                 arcs[i].x, arcs[i].y,
                 arcs[i].width, arcs[i].height,
                 arcs[i].angle1, arcs[i].angle2);
    return 0;
}

int
XFillArcs(Display *display, Drawable d, GC gc, XArc *arcs, int narcs)
{
    int i;
    for (i = 0; i < narcs; i++)
        XFillArc(display, d, gc,
                 arcs[i].x, arcs[i].y,
                 arcs[i].width, arcs[i].height,
                 arcs[i].angle1, arcs[i].angle2);
    return 0;
}

int
XFillPolygon(Display *display, Drawable d, GC gc,
             XPoint *points, int npoints, int shape, int mode)
{
    int ox, oy, i;
    int *xv, *yv;
    unsigned long rgba;
    (void)display; (void)shape; (void)mode;

    if (npoints < 1) return 0;
    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);

    xv = (int *)ckalloc(npoints * sizeof(int));
    yv = (int *)ckalloc(npoints * sizeof(int));
    for (i = 0; i < npoints; i++) {
        xv[i] = points[i].x + ox;
        yv[i] = points[i].y + oy;
    }
    tkp9_fillpoly(xv, yv, npoints, rgba);
    ckfree(xv);
    ckfree(yv);
    return 0;
}

int
XDrawSegments(Display *display, Drawable d, GC gc,
              XSegment *segs, int nsegs)
{
    int ox, oy, i, lw;
    unsigned long rgba;
    (void)display;

    DrawableOffset(d, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    for (i = 0; i < nsegs; i++)
        tkp9_drawline(segs[i].x1 + ox, segs[i].y1 + oy,
                      segs[i].x2 + ox, segs[i].y2 + oy,
                      lw, rgba);
    return 0;
}

int
XDrawPoint(Display *display, Drawable d, GC gc, int x, int y)
{
    int xv[1], yv[1], ox, oy;
    (void)display;
    DrawableOffset(d, &ox, &oy);
    xv[0] = x + ox; yv[0] = y + oy;
    tkp9_drawpoints(xv, yv, 1, GCForegroundRGBA(gc));
    return 0;
}

int
XDrawPoints(Display *display, Drawable d, GC gc,
            XPoint *points, int npoints, int mode)
{
    int ox, oy, i;
    int *xv, *yv;
    (void)display; (void)mode;

    DrawableOffset(d, &ox, &oy);
    xv = (int *)ckalloc(npoints * sizeof(int));
    yv = (int *)ckalloc(npoints * sizeof(int));
    for (i = 0; i < npoints; i++) {
        xv[i] = points[i].x + ox;
        yv[i] = points[i].y + oy;
    }
    tkp9_drawpoints(xv, yv, npoints, GCForegroundRGBA(gc));
    ckfree(xv);
    ckfree(yv);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Image operations                                                    */
/* ------------------------------------------------------------------ */

int
XPutImage(Display *display, Drawable d, GC gc, XImage *image,
          int src_x, int src_y,
          int dest_x, int dest_y,
          unsigned int width, unsigned int height)
{
    (void)display; (void)d; (void)gc; (void)image;
    (void)src_x; (void)src_y; (void)dest_x; (void)dest_y;
    (void)width; (void)height;
    return 0;
}

#undef TkPutImage
int
TkPutImage(unsigned long *colors, int ncolors,
           Display *display, Drawable d, GC gc, XImage *image,
           int src_x, int src_y, int dest_x, int dest_y,
           unsigned int width, unsigned int height)
{
    (void)colors; (void)ncolors;
    return XPutImage(display, d, gc, image,
                     src_x, src_y, dest_x, dest_y, width, height);
}

/* ------------------------------------------------------------------ */
/* Pixmap (off-screen buffer) stubs                                   */
/* ------------------------------------------------------------------ */

Pixmap
XCreatePixmap(Display *display, Drawable d,
              unsigned int width, unsigned int height, unsigned int depth)
{
    /* For now, allocate a fake window as pixmap storage */
    return XCreateWindow(display, (Window)d,
                         0, 0, width, height, 0,
                         (int)depth, InputOutput, CopyFromParent, 0, NULL);
}

int
XFreePixmap(Display *display, Pixmap pixmap)
{
    return XDestroyWindow(display, (Window)pixmap);
}

Pixmap
XCreateBitmapFromData(Display *display, Drawable d,
                      const char *data, unsigned int w, unsigned int h)
{
    (void)data;
    return XCreatePixmap(display, d, w, h, 1);
}

/* ------------------------------------------------------------------ */
/* Flush / sync                                                        */
/* ------------------------------------------------------------------ */

int
XFlush(Display *display)
{
    (void)display;
    tkp9_flush();
    return 0;
}

/* ------------------------------------------------------------------ */
/* Cursor stubs                                                        */
/* ------------------------------------------------------------------ */

Cursor
XCreatePixmapCursor(Display *d, Pixmap p1, Pixmap p2,
                    XColor *c1, XColor *c2,
                    unsigned int x, unsigned int y)
{
    (void)d; (void)p1; (void)p2; (void)c1; (void)c2; (void)x; (void)y;
    return (Cursor)1;
}

Cursor
XCreateGlyphCursor(Display *d, Font f1, Font f2,
                   unsigned int ch1, unsigned int ch2,
                   XColor *c1, XColor *c2)
{
    (void)d; (void)f1; (void)f2; (void)ch1; (void)ch2; (void)c1; (void)c2;
    return (Cursor)1;
}

int
XFreeCursor(Display *d, Cursor c)
{
    (void)d; (void)c;
    return 0;
}

int
XDefineCursor(Display *d, Window w, Cursor c)
{
    (void)d; (void)w; (void)c;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Input methods (stubs — Plan 9 uses /dev/kbd directly)              */
/* ------------------------------------------------------------------ */

XIC
XCreateIC(XIM xim, ...)
{
    (void)xim;
    return NULL;
}

void
XDestroyIC(XIC xic)
{
    (void)xic;
}

Bool
XFilterEvent(XEvent *ev, Window w)
{
    (void)ev; (void)w;
    return False;
}

char *
XSetICValues(XIC xic, ...)
{
    (void)xic;
    return NULL;
}

char *
XGetICValues(XIC xic, ...)
{
    (void)xic;
    return NULL;
}

void
XSetICFocus(XIC xic)
{
    (void)xic;
}

XIM
XOpenIM(Display *dpy, struct _XrmHashBucketRec *rdb,
        char *res_name, char *res_class)
{
    (void)dpy; (void)rdb; (void)res_name; (void)res_class;
    return NULL;
}

int
XCloseIM(XIM im)
{
    (void)im;
    return 0;
}

char *
XGetIMValues(XIM im, ...)
{
    (void)im;
    return NULL;
}

char *
XSetIMValues(XIM im, ...)
{
    (void)im;
    return NULL;
}

Bool
XRegisterIMInstantiateCallback(Display *dpy,
    struct _XrmHashBucketRec *rdb,
    char *res_name, char *res_class,
    XIDProc callback, XPointer client_data)
{
    (void)dpy; (void)rdb; (void)res_name; (void)res_class;
    (void)callback; (void)client_data;
    return False;
}

Bool
XUnregisterIMInstantiateCallback(Display *dpy,
    struct _XrmHashBucketRec *rdb,
    char *res_name, char *res_class,
    XIDProc callback, XPointer client_data)
{
    (void)dpy; (void)rdb; (void)res_name; (void)res_class;
    (void)callback; (void)client_data;
    return False;
}

char *
XSetLocaleModifiers(const char *modifier_list)
{
    (void)modifier_list;
    return "";
}

/* ------------------------------------------------------------------ */
/* Miscellaneous stubs                                                 */
/* ------------------------------------------------------------------ */

XErrorHandler
XSetErrorHandler(XErrorHandler handler)
{
    (void)handler;
    return NULL;
}

GContext
XGContextFromGC(GC gc)
{
    return (GContext)(uintptr_t)gc;
}

VisualID
XVisualIDFromVisual(Visual *visual)
{
    return visual ? visual->visualid : 0;
}

int
XSetDashes(Display *d, GC gc, int offset, const char *dash_list, int n)
{
    (void)d; (void)gc; (void)offset; (void)dash_list; (void)n;
    return 0;
}

XVaNestedList
XVaCreateNestedList(int dummy, ...)
{
    (void)dummy;
    return NULL;
}

XFontSet
XCreateFontSet(Display *display, const char *base_font_list,
               char ***missing_list, int *missing_count, char **def_string)
{
    (void)display; (void)base_font_list;
    if (missing_list)  *missing_list  = NULL;
    if (missing_count) *missing_count = 0;
    if (def_string)    *def_string    = NULL;
    return NULL;
}

void
XFreeFontSet(Display *display, XFontSet fontset)
{
    (void)display; (void)fontset;
}

void
XFreeStringList(char **list)
{
    (void)list;
}

Status
XStringListToTextProperty(char **list, int count, XTextProperty *prop)
{
    (void)list; (void)count; (void)prop;
    return 0;
}

void
XSetWMClientMachine(Display *d, Window w, XTextProperty *prop)
{
    (void)d; (void)w; (void)prop;
}

XHostAddress *
XListHosts(Display *d, int *nhosts_return, Bool *state_return)
{
    (void)d;
    if (nhosts_return) *nhosts_return = 0;
    if (state_return)  *state_return  = False;
    return NULL;
}

/* ------------------------------------------------------------------ */
/* XImage function pointers                                            */
/* ------------------------------------------------------------------ */

static int
P9DestroyImage(XImage *image)
{
    if (image) {
        if (image->data) ckfree(image->data);
        ckfree(image);
    }
    return 0;
}

static unsigned long
P9GetPixel(XImage *image, int x, int y)
{
    unsigned char *data;
    int idx;
    if (!image || !image->data) return 0;
    if (x < 0 || y < 0 || x >= image->width || y >= image->height) return 0;
    data = (unsigned char *)image->data;
    idx  = y * image->bytes_per_line + x * 4;
    return ((unsigned long)data[idx+0] << 16) |
           ((unsigned long)data[idx+1] <<  8) |
            (unsigned long)data[idx+2];
}

static int
P9PutPixel(XImage *image, int x, int y, unsigned long pixel)
{
    unsigned char *data;
    int idx;
    if (!image || !image->data) return 0;
    if (x < 0 || y < 0 || x >= image->width || y >= image->height) return 0;
    data = (unsigned char *)image->data;
    idx  = y * image->bytes_per_line + x * 4;
    data[idx+0] = (pixel >> 16) & 0xFF;
    data[idx+1] = (pixel >>  8) & 0xFF;
    data[idx+2] =  pixel        & 0xFF;
    data[idx+3] = 0xFF;
    return 0;
}

static XImage *
P9SubImage(XImage *image, int x, int y, unsigned int w, unsigned int h)
{
    (void)image; (void)x; (void)y; (void)w; (void)h;
    return NULL;
}

static int
P9AddPixel(XImage *image, long value)
{
    (void)image; (void)value;
    return 0;
}

int
_XInitImageFuncPtrs(XImage *image)
{
    if (!image) return 0;
    image->f.create_image  = NULL;
    image->f.destroy_image = P9DestroyImage;
    image->f.get_pixel     = P9GetPixel;
    image->f.put_pixel     = P9PutPixel;
    image->f.sub_image     = P9SubImage;
    image->f.add_pixel     = P9AddPixel;
    return 0;
}

XImage *
XCreateImage(
    Display *display,
    Visual *visual,
    unsigned int depth,
    int format,
    int offset,
    char *data,
    unsigned int width,
    unsigned int height,
    int bitmap_pad,
    int bytes_per_line)
{
    XImage *image;
    (void)display; (void)visual; (void)offset; (void)bitmap_pad;

    image = (XImage *) ckalloc(sizeof(XImage));
    memset(image, 0, sizeof(XImage));
    image->width          = (int)width;
    image->height         = (int)height;
    image->depth          = (int)depth;
    image->format         = format;
    image->data           = data;
    image->bytes_per_line = bytes_per_line > 0 ? bytes_per_line : (int)width * 4;
    image->bits_per_pixel = 32;
    image->byte_order     = LSBFirst;
    image->bitmap_unit    = 32;
    image->bitmap_bit_order = LSBFirst;
    image->bitmap_pad     = 32;
    _XInitImageFuncPtrs(image);
    return image;
}

XImage *
XGetImage(
    Display *display,
    Drawable d,
    int x, int y,
    unsigned int width,
    unsigned int height,
    unsigned long plane_mask,
    int format)
{
    (void)display; (void)d; (void)x; (void)y;
    (void)width; (void)height; (void)plane_mask; (void)format;
    return NULL;
}

/* Region operations — minimal implementations */
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

int
XSetClipRectangles(Display *d, GC gc, int clip_x_origin, int clip_y_origin,
                   XRectangle *rectangles, int n, int ordering)
{
    (void)d; (void)gc; (void)clip_x_origin; (void)clip_y_origin;
    (void)rectangles; (void)n; (void)ordering;
    return 0;
}

/* Selection (clipboard) stubs */
int
XSetSelectionOwner(Display *d, Atom a, Window w, Time t)
{
    (void)d; (void)a; (void)w; (void)t;
    return 0;
}
