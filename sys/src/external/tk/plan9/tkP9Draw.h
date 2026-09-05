/*
 * tkP9Draw.h --
 *
 *	Opaque bridge API between the Tk Plan 9 backend and libdraw.
 *	This header contains NO Plan 9 or Xlib types — only void* and
 *	primitives — so it can be included by any translation unit.
 *
 *	The implementation lives in tkPlan9DrawImpl.c, which is the only
 *	file that #includes <draw.h> and thereby takes ownership of the
 *	name "Display" from Plan 9's namespace.
 */

#ifndef _TKP9DRAW_H
#define _TKP9DRAW_H

/* Mouse state snapshot (no Plan 9 types) */
typedef struct TkP9Mouse {
    int x, y;
    int buttons;	/* bit mask: 1=left 2=middle 4=right */
    unsigned long msec;
} TkP9Mouse;

/*
 * Lifecycle
 */
int    tkp9_open(const char *label);	/* calls initdraw(); returns 0 on ok */
void   tkp9_close(void);

/*
 * Screen geometry
 */
int    tkp9_screenwidth(void);
int    tkp9_screenheight(void);

/*
 * Off-screen drawables.
 *
 * A pixmap is a real image, not a rectangle borrowed from the screen.
 * Tk double-buffers nearly every widget -- draw into a pixmap, then
 * XCopyArea it into place -- so without these the scratch drawing went
 * straight to the window and the copy was a no-op.
 */
void  *tkp9_allocimage(int w, int h);	/* origin (0,0); nil on failure */
void   tkp9_freeimage(void *img);

/*
 * Drawing.
 *
 * 'dst' is a drawable from tkp9_allocimage, or NULL for the window on
 * screen. Coordinates are relative to that drawable's own top-left, so
 * a caller never has to know where the rio window sits on the display
 * or where an image was allocated.
 *
 * 'rgba' uses Plan 9 convention: 0xRRGGBBFF.
 */
void   tkp9_fillrect(void *dst, int x, int y, int w, int h,
		     unsigned long rgba);
void   tkp9_drawline(void *dst, int x1, int y1, int x2, int y2, int width,
		     unsigned long rgba);
void   tkp9_drawrect(void *dst, int x, int y, int w, int h, int bw,
		     unsigned long rgba);
void   tkp9_copyarea(void *src, int sx, int sy, int w, int h,
		     void *dst, int dx, int dy);
void   tkp9_drawarc(void *dst, int x, int y, int a, int b,
		    int angle1, int angle2, int lw, unsigned long rgba);
void   tkp9_fillarc(void *dst, int x, int y, int a, int b,
		    int angle1, int angle2, unsigned long rgba);
void   tkp9_fillpoly(void *dst, int *xv, int *yv, int n, unsigned long rgba);
void   tkp9_drawpoints(void *dst, int *xv, int *yv, int n, unsigned long rgba);
void   tkp9_flush(void);

/*
 * The snarf buffer -- Plan 9's system-wide cut buffer, /dev/snarf,
 * served by rio. There is exactly one of them, so both PRIMARY and
 * CLIPBOARD map onto it.
 *
 * tkp9_getsnarf returns malloc'd NUL-terminated UTF-8 that the caller
 * frees, or NULL if the buffer could not be read. It is reopened on
 * every call because rio serves the whole contents from offset 0 and a
 * held descriptor would go stale.
 */
char  *tkp9_getsnarf(void);
int    tkp9_putsnarf(const char *s, int nbytes);   /* 0 on success */

/*
 * Fonts (opaque handle = Plan 9 Font*)
 */
void  *tkp9_openfont(const char *name);	  /* returns Font*, or defont */

/*
 * Open exactly this font file, or fail. tkp9_openfont silently falls
 * back to the default font, which is the wrong answer when the caller
 * is walking a list of candidate sizes and needs to know which ones
 * actually exist.
 */
void  *tkp9_openfontpath(const char *path);   /* NULL if it will not open */
void   tkp9_closefont(void *fnt);
int    tkp9_fontascent(void *fnt);
int    tkp9_fontdescent(void *fnt);	  /* height - ascent */
int    tkp9_fontheight(void *fnt);
int    tkp9_measuretext(void *fnt, const char *s, int nbytes);

/*
 * Text drawing
 */
void   tkp9_drawtext(void *dst, int x, int y, const char *s, int nbytes,
		     void *fnt, unsigned long rgba);

/*
 * Image blending — put w*h RGBA pixels into 'dst' at (x, y).
 */
void   tkp9_putpixels(void *dst, int x, int y, int w, int h,
		      const unsigned char *rgba32);

/*
 * Event file descriptors (callers select on these)
 */
int    tkp9_mousefd(void);
int    tkp9_kbdfd(void);

/*
 * Event reading
 */
int    tkp9_readmouse(TkP9Mouse *out);	/* 0=ok, -1=eof/error */
int    tkp9_readkey(void);		/* UTF-32 codepoint, or -1 */
int    tkp9_checkresized(void);		/* 1 if window was resized */

#endif /* _TKP9DRAW_H */
