/*
 * xshim_types.h -- the X types the shim shares between its public header
 * and its implementation.  It names struct _XDisplay only as a tag, so it can be
 * included beside libdraw's own Display type without a clash.
 */
#ifndef _XSHIM_TYPES_H_
#define _XSHIM_TYPES_H_

typedef unsigned long XID;
typedef XID Window;
typedef XID Drawable;
typedef unsigned long Time;
typedef unsigned long Atom;
typedef XID Pixmap;

/* regions: a bounding box, see xs_region.c */
typedef struct _XRegion *Region;
#define RectangleOut	0
#define RectangleIn	1
#define RectanglePart	2

/* the predefined atoms are 1..68, as in X11 */
#define XA_LAST_PREDEFINED	((Atom)68)
typedef int Bool;
typedef int Status;

#define True	1
#define False	0
#define None	0L

/* the ids this library hands out */
#define XSHIM_ROOT	1L
#define XSHIM_WINDOW	2L

/* GC functions: only GXcopy is implemented */
#define GXcopy	3

/* GC value mask bits, as in Xlib */
#define GCFunction	(1L<<0)
#define GCPlaneMask	(1L<<1)
#define GCForeground	(1L<<2)
#define GCBackground	(1L<<3)
#define GCLineWidth	(1L<<4)
#define GCLineStyle	(1L<<5)
#define GCCapStyle	(1L<<6)
#define GCJoinStyle	(1L<<7)
#define GCFillStyle	(1L<<8)
#define GCFillRule	(1L<<9)
#define GCTile	(1L<<10)
#define GCStipple	(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont	(1L<<14)
#define GCSubwindowMode	(1L<<15)
#define GCGraphicsExposures	(1L<<16)
#define GCClipXOrigin	(1L<<17)
#define GCClipYOrigin	(1L<<18)
#define GCClipMask	(1L<<19)
#define GCDashOffset	(1L<<20)
#define GCDashList	(1L<<21)
#define GCArcMode	(1L<<22)

/* event masks, accepted and ignored: the shim delivers every event it has */
#define KeyPressMask		(1L<<0)
#define ButtonPressMask		(1L<<2)
#define ButtonReleaseMask	(1L<<3)
#define PointerMotionMask	(1L<<6)
#define ExposureMask		(1L<<15)

/* event types, with Xlib's numbers */
#define KeyPress		2
#define ButtonPress		4
#define ButtonRelease		5
#define MotionNotify		6
#define Expose			12

/* window attributes for XCreateWindow: the fields and masks this shim uses */
#define CWBackPixel	(1L<<1)
#define CWBorderPixel	(1L<<3)
#define CWOverrideRedirect	(1L<<9)
#define CWEventMask	(1L<<11)
#define InputOutput	1
#define PointerRoot	1
typedef struct {
	unsigned long background_pixel;
	unsigned long border_pixel;
	long event_mask;
	int override_redirect;
} XSetWindowAttributes;

typedef struct { short x, y; } XPoint;
typedef struct { short x, y; unsigned short width, height; } XRectangle;
typedef struct { short x1, y1, x2, y2; } XSegment;
typedef struct { short x, y; unsigned short width, height; short angle1, angle2; } XArc;

/* a font: its resource id and metrics (the id names a libdraw Font) */
typedef struct {
	XID fid;
	int ascent;
	int descent;
} XFontStruct;

/* Tk's layout, copied verbatim: a GC is this record, and Tk reads its fields. */
typedef struct {
	int function;		/* logical operation */
	unsigned long plane_mask;/* plane mask */
	unsigned long foreground;/* foreground pixel */
	unsigned long background;/* background pixel */
	int line_width;		/* line width */
	int line_style;	 	/* LineSolid, LineOnOffDash, LineDoubleDash */
	int cap_style;	  	/* CapNotLast, CapButt,
				   CapRound, CapProjecting */
	int join_style;	 	/* JoinMiter, JoinRound, JoinBevel */
	int fill_style;	 	/* FillSolid, FillTiled,
				   FillStippled, FillOpaqueStippled */
	int fill_rule;	  	/* EvenOddRule, WindingRule */
	int arc_mode;		/* ArcChord, ArcPieSlice */
	Pixmap tile;		/* tile pixmap for tiling operations */
	Pixmap stipple;		/* stipple 1 plane pixmap for stippling */
	int ts_x_origin;	/* offset for tile or stipple operations */
	int ts_y_origin;
        XID font;	/* an X Font; typed XID here because libdraw owns the name Font */        /* default text font for text operations */
	int subwindow_mode;     /* ClipByChildren, IncludeInferiors */
	Bool graphics_exposures;/* boolean, should exposures be generated */
	int clip_x_origin;	/* origin for clipping */
	int clip_y_origin;
	Pixmap clip_mask;	/* bitmap clipping; other calls for rects */
	int dash_offset;	/* patterned/dashed line information */
	char dashes;
} XGCValues;
typedef XGCValues *GC;

#define Success	0
#define LineSolid	0
#define LineOnOffDash	1
#define LineDoubleDash	2
#define CapNotLast	0
#define CapButt	1
#define CapRound	2
#define CapProjecting	3
#define JoinMiter	0
#define JoinRound	1
#define JoinBevel	2
#define FillSolid	0
#define FillTiled	1
#define FillStippled	2
#define FillOpaqueStippled	3
#define EvenOddRule	0
#define WindingRule	1
#define ArcChord	0
#define ArcPieSlice	1
#define ClipByChildren	0
#define IncludeInferiors	1

typedef struct {
	int type;
	unsigned long serial;
	Bool send_event;
	struct _XDisplay *display;
	Window window;
} XAnyEvent;

typedef struct {
	int type;
	unsigned long serial;
	Bool send_event;
	struct _XDisplay *display;
	Window window;
	Window root;
	Window subwindow;
	Time time;
	int x, y;
	int x_root, y_root;
	unsigned int state;
	unsigned int keycode;	/* the rune typed, for now */
	Bool same_screen;
} XKeyEvent;

typedef struct {
	int type;
	unsigned long serial;
	Bool send_event;
	struct _XDisplay *display;
	Window window;
	Window root;
	Window subwindow;
	Time time;
	int x, y;
	int x_root, y_root;
	unsigned int state;
	unsigned int button;
	Bool same_screen;
} XButtonEvent;

typedef struct {
	int type;
	unsigned long serial;
	Bool send_event;
	struct _XDisplay *display;
	Window window;
	Window root;
	Window subwindow;
	Time time;
	int x, y;
	int x_root, y_root;
	unsigned int state;
	unsigned int is_hint;
	Bool same_screen;
} XMotionEvent;

typedef struct {
	int type;
	unsigned long serial;
	Bool send_event;
	struct _XDisplay *display;
	Window window;
	int x, y;
	int width, height;
	int count;
} XExposeEvent;

typedef union {
	int type;
	XAnyEvent xany;
	XKeyEvent xkey;
	XButtonEvent xbutton;
	XMotionEvent xmotion;
	XExposeEvent xexpose;
	long pad[24];
} XEvent;


#endif /* _XSHIM_TYPES_H_ */
