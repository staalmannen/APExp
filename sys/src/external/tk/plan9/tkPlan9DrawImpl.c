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
static int  gMouseRW  = 0;	/* was /dev/mouse opened for writing? */
static int  gConsFd   = -1;	/* /dev/cons (keyboard) */
static int  gResized  = 0;

/*
 * $TKP9DEBUG turns on tracing for the paths that have no other way to
 * report themselves. Nothing here can be reached from Tcl -- /dev/mouse
 * can only be opened once, and this process holds it -- so a question
 * like "did the warp write succeed, and what did rio say" is otherwise
 * only answerable by rebuilding with a printf in it. CLAUDE.md records
 * that as the technique that worked for every bug found in this
 * directory; this is the same thing left behind rather than removed.
 *
 * Plan 9's fprint() is used rather than fprintf(): this file includes
 * no stdio (see the header comment), and libc.h declares fprint, so
 * there is no variadic-call-with-no-prototype trap. %r is the errstr.
 */
int
tkp9_debug(void)
{
    static int on = -1;

    if(on < 0)
        on = getenv("TKP9DEBUG") != nil;
    return on;
}

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

    /*
     * Open mouse device directly (avoids libthread dependency).
     *
     * It has to be O_RDWR to warp the pointer: a warp is a write of
     * "m x y" to this same descriptor, which is what libdraw's moveto()
     * does. The read-only fallback keeps events working on a system
     * that will not give write permission, at the cost of warping, so
     * remember which one we got -- silently losing the warp is how
     * bind-34.* and event-9.* fail.
     */
    gMouseFd = open("/dev/mouse", O_RDWR);
    gMouseRW = gMouseFd >= 0;
    if(gMouseFd < 0)
        gMouseFd = open("/dev/mouse", O_RDONLY);
    if(tkp9_debug()){
        if(gMouseFd < 0)
            fprint(2, "tkp9: /dev/mouse will not open: %r\n");
        else
            fprint(2, "tkp9: /dev/mouse fd=%d writable=%d\n",
                gMouseFd, gMouseRW);
    }

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
/* Pixel byte order                                                    */
/* ------------------------------------------------------------------ */

/*
 * Which byte of an RGBA32 pixel holds which component, in memory order.
 *
 * Plan 9 names a channel from the most significant bits of the pixel
 * downwards and stores the pixel little-endian, which makes RGBA32
 * A,B,G,R in memory. That is the documented answer and it is used as
 * the fallback -- but it is not assumed, because **getting it wrong is
 * invisible in a round trip**: tkp9_putpixels and tkp9_getpixels would
 * permute and unpermute by the same amount and cancel out. The error
 * would surface only where these bytes meet Tk's XImage layout, as red
 * and blue exchanged in every photo image, which is a long way from
 * here.
 *
 * So ask rather than assume, once: fill a pixel with four components
 * that are all different and see where each one lands. The colour
 * argument to allocimage is 0xRRGGBBAA, which is documented and stable,
 * and an alpha of 0xFF makes premultiplication the identity so the
 * values arrive unchanged.
 */
static int rgbaidx[4] = { -1, -1, -1, -1 };	/* memory index of R,G,B,A */

static void
rgbacalibrate(void)
{
    Image *img;
    uchar buf[4];
    int i;

    if(rgbaidx[0] >= 0)
        return;
    rgbaidx[0] = 3; rgbaidx[1] = 2; rgbaidx[2] = 1; rgbaidx[3] = 0;
    if(display == nil)
        return;
    img = allocimage(display, Rect(0, 0, 1, 1), RGBA32, 1, 0x4080C0FF);
    if(img == nil)
        return;
    if(unloadimage(img, img->r, buf, sizeof buf) == sizeof buf)
        for(i = 0; i < 4; i++)
            switch(buf[i]){
            case 0x40: rgbaidx[0] = i; break;
            case 0x80: rgbaidx[1] = i; break;
            case 0xC0: rgbaidx[2] = i; break;
            case 0xFF: rgbaidx[3] = i; break;
            }
    freeimage(img);
    if(tkp9_debug())
        fprint(2, "tkp9: RGBA32 memory order R=%d G=%d B=%d A=%d\n",
            rgbaidx[0], rgbaidx[1], rgbaidx[2], rgbaidx[3]);
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
    /*
     * X's rectangle outline is a five-point path through the corners --
     * (x,y) (x+w,y) (x+w,y+h) (x,y+h) (x,y) -- so it covers **w+1 by
     * h+1 pixels**, one more than the width and height it was given.
     * Plan 9's border() draws inside the rectangle it is handed, so it
     * has to be widened by one in each direction to mean the same
     * thing. Note XFillRectangle is not like this: a fill really is w
     * by h, and tkp9_fillrect is right as it stands.
     *
     * That extra pixel is not a rounding detail, it is load-bearing.
     * canvas-23.1 is
     *
     *	.c create rectangle 0 0 0 9 -fill #000080 -outline #000080
     *
     * and tkRectOval.c's DisplayRectOval already widens a degenerate
     * box itself -- for x2 == x1 with a coordinate of 0 it does
     * "x1 -= 1" -- so what arrives here is one pixel wide starting at
     * -1. The fill covers only column -1, off the canvas; column 0 is
     * painted by the outline's extra pixel and by nothing else. Drawing
     * the outline one short therefore lost the whole column, which read
     * back as bare background and looked for all the world like a
     * colour bug, since 23.1, 23.2 and 23.3 differ in colour too.
     */
    border(d, dstrect(d, x, y, w + 1, h + 1), bw, src, ZP);
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
/* Snarf buffer (/dev/snarf)                                           */
/* ------------------------------------------------------------------ */

/*
 * rio serves the whole snarf buffer from offset 0 of a freshly opened
 * /dev/snarf and there is no way to be told when it changes, so both of
 * these open, do their business and close. Holding the descriptor open
 * would read a stale copy.
 *
 * The contents are UTF-8, which is what Tk wants for a UTF8_STRING
 * target and what Plan 9 uses natively, so no conversion is needed.
 */
char *
tkp9_getsnarf(void)
{
    int fd, n;
    long len, cap;
    char *buf, *nbuf;

    fd = open("/dev/snarf", O_RDONLY);
    if (fd < 0)
	return NULL;

    cap = 4096;
    len = 0;
    buf = malloc(cap);
    if (buf == NULL) {
	close(fd);
	return NULL;
    }
    for (;;) {
	if (len + 1 >= cap) {
	    cap *= 2;
	    nbuf = realloc(buf, cap);
	    if (nbuf == NULL) {
		free(buf);
		close(fd);
		return NULL;
	    }
	    buf = nbuf;
	}
	n = read(fd, buf + len, cap - len - 1);
	if (n < 0) {
	    free(buf);
	    close(fd);
	    return NULL;
	}
	if (n == 0)
	    break;
	len += n;
    }
    close(fd);
    buf[len] = '\0';
    return buf;
}

int
tkp9_putsnarf(const char *s, int nbytes)
{
    int fd, n;
    int off = 0;

    if (s == NULL)
	return -1;
    fd = open("/dev/snarf", O_WRONLY|O_TRUNC);
    if (fd < 0)
	return -1;
    while (off < nbytes) {
	n = write(fd, s + off, nbytes - off);
	if (n <= 0) {
	    close(fd);
	    return -1;
	}
	off += n;
    }
    close(fd);
    return 0;
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

/*
 * rio moves the pointer when "m<x> <y>" is written to /dev/mouse, so a
 * warp needs the descriptor to be open for writing -- tkp9_open asks
 * for O_RDWR first and only falls back to O_RDONLY.
 */
/*
 * Formatted by hand rather than with snprint: this file includes no
 * stdio, so a print function here would be called with no prototype in
 * scope, and a variadic call like that is the exact shape that has cost
 * this tree several silent bugs.
 */
static int
putnum(char *p, int v)
{
    char tmp[16];
    int n = 0, i = 0;

    if(v < 0) { p[i++] = '-'; v = -v; }
    do { tmp[n++] = '0' + v % 10; v /= 10; } while(v > 0);
    while(n > 0)
        p[i++] = tmp[--n];
    return i;
}

int
tkp9_warpmouse(int x, int y)
{
    char buf[40];
    int n = 0, w;

    if(gMouseFd < 0){
        if(tkp9_debug())
            fprint(2, "tkp9_warpmouse(%d,%d): no /dev/mouse\n", x, y);
        return -1;
    }
    if(!gMouseRW && tkp9_debug())
        fprint(2, "tkp9_warpmouse(%d,%d): /dev/mouse is read-only\n", x, y);

    buf[n++] = 'm';
    n += putnum(buf + n, x);
    buf[n++] = ' ';
    n += putnum(buf + n, y);

    w = write(gMouseFd, buf, n);
    if(w != n){
        if(tkp9_debug()){
            buf[n] = '\0';		/* n <= 24, buf is 40 */
            fprint(2, "tkp9_warpmouse: write(%d, \"%s\", %d) = %d: %r\n",
                gMouseFd, buf, n, w);
        }
        return -1;
    }
    if(tkp9_debug()){
        buf[n] = '\0';
        fprint(2, "tkp9_warpmouse: wrote \"%s\" ok\n", buf);
    }
    return 0;
}

void *
tkp9_openfontpath(const char *path)
{
    if(!path || !path[0]) return nil;
    return openfont(display, path);
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
    uchar *p;
    int i, n;

    if(!d || !rgba32 || w <= 0 || h <= 0) return;
    rgbacalibrate();
    n = w * h;
    if((p = malloc(n * 4)) == nil)
        return;
    for(i = 0; i < n; i++){
        p[i*4 + rgbaidx[0]] = rgba32[i*4 + 0];
        p[i*4 + rgbaidx[1]] = rgba32[i*4 + 1];
        p[i*4 + rgbaidx[2]] = rgba32[i*4 + 2];
        p[i*4 + rgbaidx[3]] = rgba32[i*4 + 3];
    }
    img = allocimage(display, Rect(0, 0, w, h), RGBA32, 0, DTransparent);
    if(img != nil){
        loadimage(img, img->r, p, n * 4);
        draw(d, dstrect(d, x, y, w, h), img, nil, img->r.min);
        freeimage(img);
    }
    free(p);
}

/*
 * Read w*h pixels back out of a drawable, as R,G,B,A bytes. The inverse
 * of tkp9_putpixels, and the thing XGetImage needs: "canvas image"
 * renders into a pixmap and then has to get the pixels out of it, which
 * is the only way Tk can copy a drawable into a photo.
 *
 * The source is drawn into an RGBA32 temporary first rather than being
 * unloaded directly, because a pixmap is allocated in the screen's own
 * channel (tkp9_allocimage) and that varies by machine; draw() does the
 * conversion for us and unloadimage then has one format to deal with.
 */
int
tkp9_getpixels(void *src, int x, int y, int w, int h, unsigned char *rgba32)
{
    Image *s = dstimage(src), *img;
    uchar *p;
    int i, n, ok;

    if(!s || !rgba32 || w <= 0 || h <= 0) return -1;
    rgbacalibrate();
    n = w * h;
    img = allocimage(display, Rect(0, 0, w, h), RGBA32, 0, DTransparent);
    if(img == nil)
        return -1;
    draw(img, img->r, s, nil, dstrect(s, x, y, w, h).min);
    if((p = malloc(n * 4)) == nil){
        freeimage(img);
        return -1;
    }
    ok = unloadimage(img, img->r, p, n * 4) == n * 4;
    freeimage(img);
    if(ok)
        for(i = 0; i < n; i++){
            rgba32[i*4 + 0] = p[i*4 + rgbaidx[0]];
            rgba32[i*4 + 1] = p[i*4 + rgbaidx[1]];
            rgba32[i*4 + 2] = p[i*4 + rgbaidx[2]];
            rgba32[i*4 + 3] = p[i*4 + rgbaidx[3]];
        }
    free(p);
    if(tkp9_debug() && !ok)
        fprint(2, "tkp9_getpixels: unloadimage %dx%d failed: %r\n", w, h);
    return ok ? 0 : -1;
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
    if(n != 1 + 4*12){
        /*
         * A short record is dropped silently, so if the format is ever
         * not 'm' plus four 12-byte fields, no mouse event is delivered
         * at all and nothing says why.
         */
        if(tkp9_debug())
            fprint(2, "tkp9_readmouse: read = %d, want %d: %r\n", n, 1 + 4*12);
        return -1;
    }

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
