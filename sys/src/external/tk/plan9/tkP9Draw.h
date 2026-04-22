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
 * Drawing — all coordinates are absolute screen pixels.
 * 'rgba' uses Plan 9 convention: 0xRRGGBBFF.
 */
void   tkp9_fillrect(int x, int y, int w, int h, unsigned long rgba);
void   tkp9_drawline(int x1, int y1, int x2, int y2, int width,
		     unsigned long rgba);
void   tkp9_drawrect(int x, int y, int w, int h, int bw,
		     unsigned long rgba);
void   tkp9_copyarea(int sx, int sy, int w, int h, int dx, int dy);
void   tkp9_drawarc(int x, int y, int a, int b, int angle1, int angle2,
		    int lw, unsigned long rgba);
void   tkp9_fillarc(int x, int y, int a, int b, int angle1, int angle2,
		    unsigned long rgba);
void   tkp9_fillpoly(int *xv, int *yv, int n, unsigned long rgba);
void   tkp9_drawpoints(int *xv, int *yv, int n, unsigned long rgba);
void   tkp9_flush(void);

/*
 * Fonts (opaque handle = Plan 9 Font*)
 */
void  *tkp9_openfont(const char *name);	  /* returns Font*, or defont */
void   tkp9_closefont(void *fnt);
int    tkp9_fontascent(void *fnt);
int    tkp9_fontdescent(void *fnt);	  /* height - ascent */
int    tkp9_fontheight(void *fnt);
int    tkp9_measuretext(void *fnt, const char *s, int nbytes);

/*
 * Text drawing
 */
void   tkp9_drawtext(int x, int y, const char *s, int nbytes,
		     void *fnt, unsigned long rgba);

/*
 * Image blending — put a row of RGBA pixels into the screen
 * at (x, y), 'npix' pixels wide.
 */
void   tkp9_putpixels(int x, int y, int w, int h,
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
