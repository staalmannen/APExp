/*
 * tkPlan9DrawImpl.c --
 *
 *	Implementation of the opaque tkp9_* drawing API using Plan 9's libdraw.
 *
 *	THIS IS THE ONLY FILE IN THE TK PLAN 9 BACKEND THAT MAY #include <draw.h>.
 *	All other files communicate with libdraw through the tkP9Draw.h API.
 *
 *	Plan 9's "Display" typedef conflicts with Xlib's "Display" typedef;
 *	keeping them in separate translation units avoids the clash.
 *
 *	We do NOT use initmouse/initkeyboard (which require libthread).
 *	Instead we open /dev/mouse and /dev/cons directly, so the only
 *	library dependency besides libc is libdraw.
 *
 *	Mouse event format from /dev/mouse (49 bytes):
 *	  buf[0]     : 'm' (mouse) or 'r' (resize)
 *	  buf[1..12] : X  (text, 12 bytes, right-justified)
 *	  buf[13..24]: Y  (text, 12 bytes)
 *	  buf[25..36]: buttons (text, 12 bytes; bitmask: 1=L 2=M 4=R)
 *	  buf[37..48]: msec  (text, 12 bytes)
 *
 *	Keyboard from /dev/cons: UTF-8 characters.
 */

/*
 * Use APE's Plan 9 extension headers.
 * u.h defines ulong, uchar, nil, etc.
 * draw.h defines Image, Font, Display (Plan 9 types) etc.
 * _PLAN9_SOURCE is passed via -D in DRAWIMPL_CFLAGS.
 */
#include <u.h>
#include <draw.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "tkP9Draw.h"

/* ------------------------------------------------------------------ */
/* Module state                                                        */
/* ------------------------------------------------------------------ */

static int  gMouseFd  = -1;	/* /dev/mouse */
static int  gConsFd   = -1;	/* /dev/cons (keyboard) */
static int  gResized  = 0;

/* ------------------------------------------------------------------ */
/* Helpers                                                             */
/* ------------------------------------------------------------------ */

static Image *
colorimage(unsigned long rgba)
{
    return allocimage(display, Rect(0,0,1,1), screen->chan, 1, (ulong)rgba);
}

/* ------------------------------------------------------------------ */
/* Lifecycle                                                           */
/* ------------------------------------------------------------------ */

int
tkp9_open(const char *label)
{
    if(initdraw(nil, nil, (char*)label) < 0)
        return -1;

    /* Open mouse device directly (avoids libthread dependency) */
    gMouseFd = open("/dev/mouse", O_RDWR);
    if(gMouseFd < 0)
        gMouseFd = open("/dev/mouse", O_RDONLY);

    /* Open console for keyboard input */
    gConsFd = open("/dev/cons", O_RDONLY);

    return 0;
}

void
tkp9_close(void)
{
    if(gMouseFd >= 0) { close(gMouseFd); gMouseFd = -1; }
    if(gConsFd  >= 0) { close(gConsFd);  gConsFd  = -1; }
    if(display) {
        closedisplay(display);
        display = nil;
    }
}

/* ------------------------------------------------------------------ */
/* Screen geometry                                                     */
/* ------------------------------------------------------------------ */

int
tkp9_screenwidth(void)
{
    return screen ? Dx(screen->r) : 800;
}

int
tkp9_screenheight(void)
{
    return screen ? Dy(screen->r) : 600;
}

/* ------------------------------------------------------------------ */
/* Destinations and drawable-relative coordinates                      */
/* ------------------------------------------------------------------ */

/*
 * Callers work in coordinates relative to a drawable's own top-left and
 * pass NULL for "the window on screen". libdraw works in the
 * destination image's own coordinates, and an image's r.min is wherever
 * it happens to live -- for a rio window, wherever the window sits on
 * the display; for an allocated image, (0,0).
 *
 * Translating by dst->r.min therefore handles both uniformly. Without
 * it every draw call to the screen landed outside screen->r and was
 * clipped away, which is why wish showed a blank window however
 * correctly Tk was drawing.
 */
static Image *
dstimage(void *dst)
{
    return dst ? (Image *) dst : screen;
}

static Point
dstpt(Image *d, int x, int y)
{
    return Pt(d->r.min.x + x, d->r.min.y + y);
}

static Rectangle
dstrect(Image *d, int x, int y, int w, int h)
{
    return Rect(d->r.min.x + x,     d->r.min.y + y,
                d->r.min.x + x + w, d->r.min.y + y + h);
}

/* ------------------------------------------------------------------ */
/* Off-screen drawables                                                */
/* ------------------------------------------------------------------ */

void *
tkp9_allocimage(int w, int h)
{
    if(!display || w <= 0 || h <= 0)
        return nil;
    /*
     * Allocated at the origin so the caller's coordinates need no
     * adjustment, and in the screen's channel format so blitting to and
     * from the window needs no conversion.
     */
    return allocimage(display, Rect(0, 0, w, h),
                      screen ? screen->chan : RGB24, 0, DWhite);
}

void
tkp9_freeimage(void *img)
{
    if(img && img != screen)
        freeimage((Image *)img);
}

/* ------------------------------------------------------------------ */
/* Drawing                                                             */
/* ------------------------------------------------------------------ */

void
tkp9_fillrect(void *dst, int x, int y, int w, int h, unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    if(!d) return;
    src = colorimage(rgba);
    if(!src) return;
    draw(d, dstrect(d, x, y, w, h), src, nil, ZP);
    freeimage(src);
}

void
tkp9_drawline(void *dst, int x1, int y1, int x2, int y2, int lw,
              unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    if(!d) return;
    src = colorimage(rgba);
    if(!src) return;
    if(lw < 1) lw = 1;
    line(d, dstpt(d, x1, y1), dstpt(d, x2, y2), Endsquare, Endsquare,
         lw/2, src, ZP);
    freeimage(src);
}

void
tkp9_drawrect(void *dst, int x, int y, int w, int h, int bw,
              unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    if(!d || bw < 1) return;
    src = colorimage(rgba);
    if(!src) return;
    border(d, dstrect(d, x, y, w, h), bw, src, ZP);
    freeimage(src);
}

void
tkp9_copyarea(void *src, int sx, int sy, int w, int h,
              void *dst, int dx, int dy)
{
    Image *s = dstimage(src), *d = dstimage(dst);
    if(!s || !d) return;
    draw(d, dstrect(d, dx, dy, w, h), s, nil, dstpt(s, sx, sy));
}

void
tkp9_drawarc(void *dst, int x, int y, int a, int b, int angle1, int angle2,
             int lw, unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    if(!d) return;
    src = colorimage(rgba);
    if(!src) return;
    if(lw < 1) lw = 1;
    arc(d, dstpt(d, x, y), a, b, lw/2, src, ZP, angle1, angle2);
    freeimage(src);
}

void
tkp9_fillarc(void *dst, int x, int y, int a, int b, int angle1, int angle2,
             unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    if(!d) return;
    src = colorimage(rgba);
    if(!src) return;
    fillarc(d, dstpt(d, x, y), a, b, src, ZP, angle1, angle2);
    freeimage(src);
}

void
tkp9_fillpoly(void *dst, int *xv, int *yv, int n, unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    Point *pts;
    int i;
    if(!d || n < 1) return;
    pts = malloc(n * sizeof(Point));
    if(!pts) return;
    for(i = 0; i < n; i++) {
        pts[i] = dstpt(d, xv[i], yv[i]);
    }
    src = colorimage(rgba);
    if(src) {
        fillpoly(d, pts, n, 0, src, ZP);
        freeimage(src);
    }
    free(pts);
}

void
tkp9_drawpoints(void *dst, int *xv, int *yv, int n, unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    int i;
    if(!d || n < 1) return;
    src = colorimage(rgba);
    if(!src) return;
    for(i = 0; i < n; i++)
        draw(d, dstrect(d, xv[i], yv[i], 1, 1), src, nil, ZP);
    freeimage(src);
}

void
tkp9_flush(void)
{
    if(display) flushimage(display, 1);
}

/* ------------------------------------------------------------------ */
/* Fonts                                                               */
/* ------------------------------------------------------------------ */

void *
tkp9_openfont(const char *name)
{
    Font *f;
    if(!name || !name[0]) return font;
    f = openfont(display, name);
    if(!f) f = font;
    return f;
}

void
tkp9_closefont(void *fnt)
{
    if(fnt && fnt != font)
        freefont((Font *)fnt);
}

int
tkp9_fontheight(void *fnt)
{
    Font *f = fnt ? (Font *)fnt : font;
    return f ? (int)f->height : 12;
}

int
tkp9_fontascent(void *fnt)
{
    Font *f = fnt ? (Font *)fnt : font;
    return f ? (int)f->ascent : 10;
}

int
tkp9_fontdescent(void *fnt)
{
    Font *f = fnt ? (Font *)fnt : font;
    if(!f) return 2;
    return (int)f->height - (int)f->ascent;
}

int
tkp9_measuretext(void *fnt, const char *s, int nbytes)
{
    Font *f = fnt ? (Font *)fnt : font;
    if(!f || !s || nbytes <= 0) return 0;
    return (int)stringnwidth(f, s, nbytes);
}

/* ------------------------------------------------------------------ */
/* Text drawing                                                        */
/* ------------------------------------------------------------------ */

void
tkp9_drawtext(void *dst, int x, int y, const char *s, int nbytes,
              void *fnt, unsigned long rgba)
{
    Image *d = dstimage(dst), *src;
    Font *f;
    if(!d || !s || nbytes <= 0) return;
    f   = fnt ? (Font *)fnt : font;
    src = colorimage(rgba);
    if(!src) return;
    stringn(d, dstpt(d, x, y), src, ZP, f, s, nbytes);
    freeimage(src);
}

/* ------------------------------------------------------------------ */
/* Pixel blending                                                      */
/* ------------------------------------------------------------------ */

void
tkp9_putpixels(void *dst, int x, int y, int w, int h,
               const unsigned char *rgba32)
{
    Image *d = dstimage(dst), *img;
    if(!d || !rgba32 || w <= 0 || h <= 0) return;
    img = allocimage(display, Rect(0, 0, w, h), RGBA32, 0, DTransparent);
    if(!img) return;
    loadimage(img, img->r, (uchar*)rgba32, w * h * 4);
    draw(d, dstrect(d, x, y, w, h), img, nil, img->r.min);
    freeimage(img);
}

/* ------------------------------------------------------------------ */
/* Event file descriptors                                              */
/* ------------------------------------------------------------------ */

int
tkp9_mousefd(void)
{
    return gMouseFd;
}

int
tkp9_kbdfd(void)
{
    return gConsFd;
}

/* ------------------------------------------------------------------ */
/* Mouse event reading                                                 */
/* ------------------------------------------------------------------ */

int
tkp9_readmouse(TkP9Mouse *out)
{
    char buf[1 + 4*12];
    int n;

    if(gMouseFd < 0) return -1;

    n = read(gMouseFd, buf, sizeof buf);
    if(n != 1 + 4*12) return -1;

    if(buf[0] == 'r') {
        /* Resize event */
        if(getwindow(display, Refmesg) < 0)
            return -1;
        gResized = 1;
        /* Also fill in current mouse position by re-reading */
        out->x       = atoi(buf + 1 + 0*12);
        out->y       = atoi(buf + 1 + 1*12);
        out->buttons = atoi(buf + 1 + 2*12);
        out->msec    = (unsigned long)atoll(buf + 1 + 3*12);
        return 0;
    }
    if(buf[0] != 'm') return -1;

    out->x       = atoi(buf + 1 + 0*12);
    out->y       = atoi(buf + 1 + 1*12);
    out->buttons = atoi(buf + 1 + 2*12);
    out->msec    = (unsigned long)atoll(buf + 1 + 3*12);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Keyboard event reading                                              */
/* ------------------------------------------------------------------ */

int
tkp9_readkey(void)
{
    unsigned char buf[4];
    int n, rune;
    unsigned char c;

    if(gConsFd < 0) return -1;

    /* Read one UTF-8 character */
    n = read(gConsFd, buf, 1);
    if(n != 1) return -1;

    c = buf[0];
    if(c < 0x80) {
        rune = c;
    } else if((c & 0xE0) == 0xC0) {
        n = read(gConsFd, buf+1, 1);
        rune = ((c & 0x1F) << 6) | (buf[1] & 0x3F);
    } else if((c & 0xF0) == 0xE0) {
        n = read(gConsFd, buf+1, 2);
        rune = ((c & 0x0F) << 12) |
               ((buf[1] & 0x3F) << 6) |
               (buf[2] & 0x3F);
    } else if((c & 0xF8) == 0xF0) {
        n = read(gConsFd, buf+1, 3);
        rune = ((c & 0x07) << 18) |
               ((buf[1] & 0x3F) << 12) |
               ((buf[2] & 0x3F) << 6)  |
               (buf[3] & 0x3F);
    } else {
        rune = c;
    }
    return rune;
}

/* ------------------------------------------------------------------ */
/* Resize check                                                        */
/* ------------------------------------------------------------------ */

int
tkp9_checkresized(void)
{
    int v = gResized;
    gResized = 0;
    return v;
}
