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
 * u.h defines ulong, uchar, etc.
 * draw.h defines Image, Font, Display (Plan 9 types) etc.
 * libc.h provides atoi, atoll, open, read, close, etc.
 * These are the APE versions from sys/include/ape/.
 */
#define _PLAN9_SOURCE
#include <u.h>
#include <libc.h>
#include <draw.h>

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
    gMouseFd = open("/dev/mouse", ORDWR);
    if(gMouseFd < 0)
        gMouseFd = open("/dev/mouse", OREAD);

    /* Open console for keyboard input */
    gConsFd = open("/dev/cons", OREAD);

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
/* Drawing                                                             */
/* ------------------------------------------------------------------ */

void
tkp9_fillrect(int x, int y, int w, int h, unsigned long rgba)
{
    Image *src;
    if(!screen) return;
    src = colorimage(rgba);
    if(!src) return;
    draw(screen, Rect(x, y, x+w, y+h), src, nil, ZP);
    freeimage(src);
}

void
tkp9_drawline(int x1, int y1, int x2, int y2, int lw, unsigned long rgba)
{
    Image *src;
    if(!screen) return;
    src = colorimage(rgba);
    if(!src) return;
    if(lw < 1) lw = 1;
    line(screen, Pt(x1,y1), Pt(x2,y2), Endsquare, Endsquare, lw/2, src, ZP);
    freeimage(src);
}

void
tkp9_drawrect(int x, int y, int w, int h, int bw, unsigned long rgba)
{
    Image *src;
    if(!screen || bw < 1) return;
    src = colorimage(rgba);
    if(!src) return;
    border(screen, Rect(x, y, x+w, y+h), bw, src, ZP);
    freeimage(src);
}

void
tkp9_copyarea(int sx, int sy, int w, int h, int dx, int dy)
{
    if(!screen) return;
    draw(screen, Rect(dx, dy, dx+w, dy+h), screen, nil, Pt(sx, sy));
}

void
tkp9_drawarc(int x, int y, int a, int b, int angle1, int angle2,
             int lw, unsigned long rgba)
{
    Image *src;
    if(!screen) return;
    src = colorimage(rgba);
    if(!src) return;
    if(lw < 1) lw = 1;
    arc(screen, Pt(x,y), a, b, lw/2, src, ZP, angle1, angle2);
    freeimage(src);
}

void
tkp9_fillarc(int x, int y, int a, int b, int angle1, int angle2,
             unsigned long rgba)
{
    Image *src;
    if(!screen) return;
    src = colorimage(rgba);
    if(!src) return;
    fillarc(screen, Pt(x,y), a, b, src, ZP, angle1, angle2);
    freeimage(src);
}

void
tkp9_fillpoly(int *xv, int *yv, int n, unsigned long rgba)
{
    Point *pts;
    Image *src;
    int i;
    if(!screen || n < 1) return;
    pts = malloc(n * sizeof(Point));
    if(!pts) return;
    for(i = 0; i < n; i++) {
        pts[i].x = xv[i];
        pts[i].y = yv[i];
    }
    src = colorimage(rgba);
    if(src) {
        fillpoly(screen, pts, n, 0, src, ZP);
        freeimage(src);
    }
    free(pts);
}

void
tkp9_drawpoints(int *xv, int *yv, int n, unsigned long rgba)
{
    Image *src;
    int i;
    if(!screen || n < 1) return;
    src = colorimage(rgba);
    if(!src) return;
    for(i = 0; i < n; i++)
        draw(screen, Rect(xv[i], yv[i], xv[i]+1, yv[i]+1), src, nil, ZP);
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
tkp9_drawtext(int x, int y, const char *s, int nbytes,
              void *fnt, unsigned long rgba)
{
    Image *src;
    Font *f;
    if(!screen || !s || nbytes <= 0) return;
    f   = fnt ? (Font *)fnt : font;
    src = colorimage(rgba);
    if(!src) return;
    stringn(screen, Pt(x, y), src, ZP, f, s, nbytes);
    freeimage(src);
}

/* ------------------------------------------------------------------ */
/* Pixel blending                                                      */
/* ------------------------------------------------------------------ */

void
tkp9_putpixels(int x, int y, int w, int h, const unsigned char *rgba32)
{
    Image *img;
    if(!screen || !rgba32 || w <= 0 || h <= 0) return;
    img = allocimage(display, Rect(x, y, x+w, y+h), RGBA32, 0, DTransparent);
    if(!img) return;
    loadimage(img, img->r, (uchar*)rgba32, w * h * 4);
    draw(screen, img->r, img, nil, img->r.min);
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
