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
#define GCForeground	(1L<<2)
#define GCBackground	(1L<<3)
#define GCLineWidth	(1L<<4)

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

typedef struct { short x, y; } XPoint;
typedef struct { short x, y; unsigned short width, height; } XRectangle;
typedef struct { short x1, y1, x2, y2; } XSegment;

typedef struct {
	int function;
	unsigned long foreground;
	unsigned long background;
	int line_width;
} XGCValues;

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
