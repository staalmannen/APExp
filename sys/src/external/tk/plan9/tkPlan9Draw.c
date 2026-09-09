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
/* Drawable resolution                                                 */
/* ------------------------------------------------------------------ */

/*
 * Resolve a Drawable to something the draw layer can render into.
 *
 * A pixmap has its own image and its own coordinate space starting at
 * (0,0). A window is drawn straight onto the screen at its position,
 * which is the sum of its offsets up the parent chain.
 *
 * Tk double-buffers nearly every widget through a pixmap, so getting
 * this right is what makes widgets appear where they belong rather than
 * as scratch drawing in the corner of the window.
 */
static void
DrawableTarget(Drawable d, void **img, int *ox, int *oy)
{
    P9Window *pw = TkP9FindWindow((Window)d);

    if (pw != NULL && pw->ispixmap) {
	*img = pw->img;
	*ox = 0;
	*oy = 0;
	return;
    }
    *img = NULL;			/* the window on screen */
    TkP9WindowOffset((Window)d, ox, oy);
}

/*
 * An XImage here is 32 bits per pixel holding the visual's pixel value
 * -- 0x00RRGGBB, per screen->root_visual's masks -- in the HOST's byte
 * order, which is what XCreateImage below declares. Generic Tk reads a
 * pixel with a plain 32-bit load and then decomposes it with those
 * masks (tkCanvas.c's DrawCanvas does exactly that), so the only way to
 * agree with it on both endiannesses is to go through a 32-bit access
 * rather than naming bytes.
 *
 * These two used to store R,G,B,A in memory order, which contradicts
 * the LSBFirst byte_order the same file declares: on a little-endian
 * machine that puts blue where the red mask looks. Nothing had noticed
 * because XPutImage and XGetImage were both stubs, so no pixel ever
 * made the trip.
 */
static unsigned int *
XImagePixel(XImage *image, int x, int y)
{
    return (unsigned int *)(image->data + (size_t)y * image->bytes_per_line
                            + (size_t)x * 4);
}

static int
HostByteOrder(void)
{
    unsigned int one = 1;

    return (*(unsigned char *)&one) ? LSBFirst : MSBFirst;
}

/* ------------------------------------------------------------------ */
/* Core drawing operations                                             */
/* ------------------------------------------------------------------ */

int
XDrawLines(Display *display, Drawable d, GC gc,
           XPoint *points, int npoints, int mode)
{
    void *img;
    int ox, oy, i;
    unsigned long rgba;
    int lw;
    (void)display;

    if (npoints < 2) return 0;
    DrawableTarget(d, &img, &ox, &oy);
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
        tkp9_drawline(img, x1, y1, x2, y2, lw, rgba);
    }
    return 0;
}

int
XFillRectangles(Display *display, Drawable d, GC gc,
                XRectangle *rects, int nrects)
{
    void *img;
    int ox, oy, i;
    unsigned long rgba;
    (void)display;

    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);

    for (i = 0; i < nrects; i++)
        tkp9_fillrect(img, rects[i].x + ox, rects[i].y + oy,
                      rects[i].width, rects[i].height, rgba);
    return 0;
}

int
XDrawRectangle(Display *display, Drawable d, GC gc,
               int x, int y, unsigned int w, unsigned int h)
{
    void *img;
    int ox, oy;
    int lw;
    unsigned long rgba;
    (void)display;

    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    tkp9_drawrect(img, x + ox, y + oy, (int)w, (int)h, lw, rgba);
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
    void *simg, *dimg;
    int sox, soy, dox, doy;
    (void)display; (void)gc;

    DrawableTarget(src, &simg, &sox, &soy);
    DrawableTarget(dst, &dimg, &dox, &doy);
    if (tkp9_debug())
        fprintf(stderr, "XCopyArea: %ux%u from %lu (%s) %d,%d+%d,%d"
                " to %lu (%s) %d,%d+%d,%d\n",
                w, h,
                (unsigned long) src, simg? "pixmap": "screen",
                src_x, src_y, sox, soy,
                (unsigned long) dst, dimg? "pixmap": "screen",
                dst_x, dst_y, dox, doy);
    tkp9_copyarea(simg, src_x + sox, src_y + soy,
                  (int)w, (int)h,
                  dimg, dst_x + dox, dst_y + doy);
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
    void *img;
    int ox, oy;
    (void)display;
    if (!pw) return 0;
    TkP9WindowOffset(w, &ox, &oy);
    tkp9_fillrect(NULL, ox, oy, pw->width, pw->height, pw->bg_pixel);
    return 0;
}

int
XClearArea(Display *display, Window w,
           int x, int y, unsigned int width, unsigned int height,
           Bool exposures)
{
    P9Window *pw = TkP9FindWindow(w);
    void *img;
    int ox, oy;
    (void)display; (void)exposures;
    if (!pw) return 0;
    TkP9WindowOffset(w, &ox, &oy);
    tkp9_fillrect(NULL, ox + x, oy + y, (int)width, (int)height,
                  pw->bg_pixel);
    return 0;
}

int
XDrawArc(Display *display, Drawable d, GC gc,
         int x, int y, unsigned int w, unsigned int h,
         int angle1, int angle2)
{
    void *img;
    int ox, oy, lw;
    unsigned long rgba;
    (void)display;

    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    /* Plan 9 arc: centre, semi-axes a,b, line-width, colour, angle pair */
    tkp9_drawarc(img, x + ox + (int)w/2, y + oy + (int)h/2,
                 (int)w/2, (int)h/2,
                 angle1/64, angle2/64, lw, rgba);
    return 0;
}

int
XFillArc(Display *display, Drawable d, GC gc,
         int x, int y, unsigned int w, unsigned int h,
         int angle1, int angle2)
{
    void *img;
    int ox, oy;
    unsigned long rgba;
    (void)display;

    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    tkp9_fillarc(img, x + ox + (int)w/2, y + oy + (int)h/2,
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
    void *img;
    int ox, oy, i;
    int *xv, *yv;
    unsigned long rgba;
    (void)display; (void)shape; (void)mode;

    if (npoints < 1) return 0;
    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);

    xv = (int *)ckalloc(npoints * sizeof(int));
    yv = (int *)ckalloc(npoints * sizeof(int));
    for (i = 0; i < npoints; i++) {
        xv[i] = points[i].x + ox;
        yv[i] = points[i].y + oy;
    }
    tkp9_fillpoly(img, xv, yv, npoints, rgba);
    ckfree(xv);
    ckfree(yv);
    return 0;
}

int
XDrawSegments(Display *display, Drawable d, GC gc,
              XSegment *segs, int nsegs)
{
    void *img;
    int ox, oy, i, lw;
    unsigned long rgba;
    (void)display;

    DrawableTarget(d, &img, &ox, &oy);
    rgba = GCForegroundRGBA(gc);
    lw   = (gc->line_width > 0) ? (int)gc->line_width : 1;
    for (i = 0; i < nsegs; i++)
        tkp9_drawline(img, segs[i].x1 + ox, segs[i].y1 + oy,
                      segs[i].x2 + ox, segs[i].y2 + oy,
                      lw, rgba);
    return 0;
}

int
XDrawPoint(Display *display, Drawable d, GC gc, int x, int y)
{
    void *img;
    int xv[1], yv[1], ox, oy;
    (void)display;
    DrawableTarget(d, &img, &ox, &oy);
    xv[0] = x + ox; yv[0] = y + oy;
    tkp9_drawpoints(img, xv, yv, 1, GCForegroundRGBA(gc));
    return 0;
}

int
XDrawPoints(Display *display, Drawable d, GC gc,
            XPoint *points, int npoints, int mode)
{
    void *img;
    int ox, oy, i;
    int *xv, *yv;
    (void)display; (void)mode;

    DrawableTarget(d, &img, &ox, &oy);
    xv = (int *)ckalloc(npoints * sizeof(int));
    yv = (int *)ckalloc(npoints * sizeof(int));
    for (i = 0; i < npoints; i++) {
        xv[i] = points[i].x + ox;
        yv[i] = points[i].y + oy;
    }
    tkp9_drawpoints(img, xv, yv, npoints, GCForegroundRGBA(gc));
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
    void *img;
    unsigned char *buf, *q;
    unsigned int x, y, p;
    int ox, oy;
    (void)display; (void)gc;

    if (image == NULL || image->data == NULL || width == 0 || height == 0)
        return 0;
    if (image->bits_per_pixel != 32)
        return 0;			/* nothing here makes any other depth */

    /* Clip the source rectangle to the image rather than reading past it. */
    if (src_x < 0 || src_y < 0)
        return 0;
    if (src_x + (int)width > image->width)
        width = (unsigned)(image->width - src_x);
    if (src_y + (int)height > image->height)
        height = (unsigned)(image->height - src_y);
    if ((int)width <= 0 || (int)height <= 0)
        return 0;

    buf = (unsigned char *)ckalloc((size_t)width * height * 4);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            p = *XImagePixel(image, src_x + (int)x, src_y + (int)y);
            q = buf + ((size_t)y * width + x) * 4;
            q[0] = (unsigned char)(p >> 16);	/* red_mask   0xFF0000 */
            q[1] = (unsigned char)(p >>  8);	/* green_mask 0x00FF00 */
            q[2] = (unsigned char)(p);		/* blue_mask  0x0000FF */
            q[3] = 0xFF;
        }
    }

    DrawableTarget(d, &img, &ox, &oy);
    if (tkp9_debug())
        fprintf(stderr, "XPutImage: %ux%u from (%d,%d) to drawable %lu"
                " (%s) at %d,%d + offset %d,%d\n",
                width, height, src_x, src_y, (unsigned long) d,
                img? "pixmap": "screen", dest_x, dest_y, ox, oy);
    tkp9_putpixels(img, dest_x + ox, dest_y + oy,
                   (int)width, (int)height, buf);
    ckfree(buf);
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
    /*
     * A pixmap is backed by a fake window here, but it is *not* a child
     * window: it is an independent drawable with its own coordinate
     * space starting at (0,0). Marking it keeps TkP9WindowOffset from
     * walking up to the parent it was created against and giving it
     * that window's position on screen.
     */
    Window xid = XCreateWindow(display, (Window)d,
                               0, 0, width, height, 0,
                               (int)depth, InputOutput, CopyFromParent,
                               0, NULL);
    P9Window *pw = TkP9FindWindow(xid);

    if (pw) {
        pw->ispixmap = 1;
        pw->img = tkp9_allocimage((int)width, (int)height);
    }
    return (Pixmap) xid;
}

int
XFreePixmap(Display *display, Pixmap pixmap)
{
    P9Window *pw = TkP9FindWindow((Window)pixmap);

    if (pw != NULL && pw->img != NULL) {
        tkp9_freeimage(pw->img);
        pw->img = NULL;
    }
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

/*
 * Cursors are cosmetic here -- rio owns the pointer, and nothing in this
 * backend draws one -- but their ids still have to be *unique*. Tk
 * registers every cursor in dispPtr->cursorIdTable keyed by the id and
 * panics on a collision (tkCursor.c:283, and again at :388):
 *
 *	cursor already registered in Tk_GetCursor
 *
 * These all used to answer (Cursor)1, so the second distinct cursor a
 * program asked for killed it. The whole Tk test suite got as far as
 * busy.test before hitting it.
 *
 * Zero is not available either: it is None, which Tk reads as failure.
 */
static Cursor
P9NextCursorId(void)
{
    static unsigned long next = 1;

    return (Cursor) next++;
}

Cursor
XCreatePixmapCursor(Display *d, Pixmap p1, Pixmap p2,
                    XColor *c1, XColor *c2,
                    unsigned int x, unsigned int y)
{
    (void)d; (void)p1; (void)p2; (void)c1; (void)c2; (void)x; (void)y;
    return P9NextCursorId();
}

Cursor
XCreateGlyphCursor(Display *d, Font f1, Font f2,
                   unsigned int ch1, unsigned int ch2,
                   const XColor *c1, const XColor *c2)
{
    (void)d; (void)f1; (void)f2; (void)ch1; (void)ch2; (void)c1; (void)c2;
    return P9NextCursorId();
}

int
XFreeCursor(Display *d, Cursor c)
{
    (void)d; (void)c;
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
    if (!image || !image->data) return 0;
    if (x < 0 || y < 0 || x >= image->width || y >= image->height) return 0;
    return *XImagePixel(image, x, y) & 0x00FFFFFFu;
}

static int
P9PutPixel(XImage *image, int x, int y, unsigned long pixel)
{
    if (!image || !image->data) return 0;
    if (x < 0 || y < 0 || x >= image->width || y >= image->height) return 0;
    *XImagePixel(image, x, y) = 0xFF000000u | (unsigned int)(pixel & 0x00FFFFFFu);
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
    /*
     * The pixel is stored as a host-order 32-bit word (see
     * XImagePixel), so say so rather than hardcoding LSBFirst: this
     * tree builds for big-endian architectures too, and generic Tk
     * byte-swaps when byte_order disagrees with the host.
     */
    image->byte_order     = HostByteOrder();
    image->bitmap_unit    = 32;
    image->bitmap_bit_order = image->byte_order;
    image->bitmap_pad     = 32;
    _XInitImageFuncPtrs(image);
    return image;
}

/*
 * Read a rectangle of a drawable back as an XImage. "canvas image"
 * renders the canvas into a pixmap and then has to get the pixels out
 * of it -- tkCanvas.c's comment calls this "the only way to get Pixmap
 * image data out of an image" -- so a stub returning NULL is
 * canvas-23.* failing with "failed to copy Pixmap to XImage".
 */
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
    XImage *image;
    unsigned char *buf, *q;
    char *data;
    void *img;
    int ox, oy;
    unsigned int ix, iy;
    (void)plane_mask;

    if (format != ZPixmap || width == 0 || height == 0)
        return NULL;

    buf = (unsigned char *)ckalloc((size_t)width * height * 4);
    DrawableTarget(d, &img, &ox, &oy);
    if (tkp9_getpixels(img, x + ox, y + oy, (int)width, (int)height, buf) < 0) {
        ckfree(buf);
        return NULL;
    }

    data = (char *)ckalloc((size_t)width * height * 4);
    image = XCreateImage(display, NULL, 32, ZPixmap, 0, data,
                         width, height, 32, (int)width * 4);
    if (image == NULL) {
        ckfree(buf);
        ckfree(data);
        return NULL;
    }

    for (iy = 0; iy < height; iy++) {
        for (ix = 0; ix < width; ix++) {
            q = buf + ((size_t)iy * width + ix) * 4;
            *XImagePixel(image, (int)ix, (int)iy) =
                0xFF000000u | ((unsigned int)q[0] << 16)
                            | ((unsigned int)q[1] <<  8)
                            |  (unsigned int)q[2];
        }
    }
    ckfree(buf);
    return image;
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


/* Selection (clipboard) stubs */
int
XSetSelectionOwner(Display *d, Atom a, Window w, Time t)
{
    (void)d; (void)a; (void)w; (void)t;
    return 0;
}
