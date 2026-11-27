#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "xshim_p.h"

/*
 * Events.  libdraw hands back one device event at a time; each becomes one or
 * more X events, routed through the window tree as X routes them: a pointer
 * event goes to the window under the pointer and propagates to the nearest
 * ancestor that selected it, and a key goes to the focus window the same way.
 * The queue holds 64; newer events are dropped if the program stops reading.
 */
#define QLEN	64

static XEvent	queue[QLEN];
static int	qhead, qlen;
static Mouse	lastmouse;

static void
enqueue(XEvent *e)
{
	if(qlen == QLEN)
		return;
	queue[(qhead + qlen) % QLEN] = *e;
	qlen++;
}

static void
newevent(XEvent *e, int type, xs_win *w)
{
	memset(e, 0, sizeof *e);
	e->type = type;
	e->xany.display = (struct _XDisplay*)xs_dpy;
	e->xany.window = w->id;
}

/* the pointer fields of a button or motion event, relative to w */
static void
setpointer(XEvent *e, xs_win *w, Point p)
{
	int rx, ry;

	xs_win_rel(w, p.x, p.y, &rx, &ry);
	e->xbutton.x = rx;
	e->xbutton.y = ry;
	e->xbutton.x_root = p.x;
	e->xbutton.y_root = p.y;
}

void
xs_event_expose(xs_win *w)
{
	XEvent xe;

	if(w == nil || !(w->mask & ExposureMask))
		return;
	newevent(&xe, Expose, w);
	xe.xexpose.x = 0;
	xe.xexpose.y = 0;
	xe.xexpose.width = w->w;
	xe.xexpose.height = w->h;
	xe.xexpose.count = 0;
	enqueue(&xe);
}

/* after a resize every mapped window needs an Expose */
static void
flushexpose(void)
{
	xs_win *w;

	if(!xs_expose)
		return;
	xs_expose = 0;
	for(w = xs_win_all(); w != nil; w = w->allnext)
		if(w->mapped && w != xs_win_root())
			xs_event_expose(w);
}

/* read one libdraw event (blocks unless the caller checked first) and queue
 * the X events it implies */
static void
pump(void)
{
	Event ev;
	XEvent xe;
	Point p;
	xs_win *w;
	ulong id;
	int i, changed, press;

	id = eread(Ekeyboard|Emouse, &ev);
	if(id & Ekeyboard){
		w = xs_win_select(xs_win_focus(), KeyPressMask);
		if(w != nil){
			newevent(&xe, KeyPress, w);
			xe.xkey.keycode = ev.kbdc;
			enqueue(&xe);
		}
	}
	if(id & Emouse){
		p = ev.mouse.xy;
		changed = ev.mouse.buttons ^ lastmouse.buttons;
		/* Plan 9 button bits 0,1,2 are X buttons 1,2,3; the wheel is not mapped */
		for(i = 0; i < 3; i++)
			if(changed & (1<<i)){
				press = (ev.mouse.buttons & (1<<i)) != 0;
				w = xs_win_select(xs_win_at(p.x, p.y),
					press ? ButtonPressMask : ButtonReleaseMask);
				if(w != nil){
					newevent(&xe, press ? ButtonPress : ButtonRelease, w);
					setpointer(&xe, w, p);
					xe.xbutton.button = i + 1;
					enqueue(&xe);
				}
			}
		if(!eqpt(p, lastmouse.xy)){
			w = xs_win_select(xs_win_at(p.x, p.y), PointerMotionMask);
			if(w != nil){
				newevent(&xe, MotionNotify, w);
				setpointer(&xe, w, p);
				enqueue(&xe);
			}
		}
		lastmouse = ev.mouse;
	}
}

int
XPending(Display *dpy)
{
	USED(dpy);
	flushexpose();
	if(qlen == 0 && ecanread(Ekeyboard|Emouse))
		pump();
	return qlen;
}

int
XNextEvent(Display *dpy, XEvent *e)
{
	USED(dpy);
	for(;;){
		flushexpose();
		if(qlen > 0){
			*e = queue[qhead];
			qhead = (qhead + 1) % QLEN;
			qlen--;
			return 1;
		}
		pump();
	}
}

/* the pointer: its position from the last event, the window under it, and
 * the child of w that holds it */
Bool
XQueryPointer(Display *dpy, Window w, Window *root, Window *child,
	int *root_x, int *root_y, int *win_x, int *win_y, unsigned int *mask)
{
	xs_win *wn, *target, *c;
	Point p;
	int rx, ry;

	USED(dpy);
	p = lastmouse.xy;
	wn = xs_win_find(w);
	if(root != nil)
		*root = XSHIM_ROOT;
	if(root_x != nil)
		*root_x = p.x;
	if(root_y != nil)
		*root_y = p.y;
	target = xs_win_at(p.x, p.y);
	if(child != nil){
		*child = None;
		if(wn != nil && target != nil){
			for(c = target; c != nil && c->parent != wn; c = c->parent)
				;
			if(c != nil)
				*child = c->id;
		}
	}
	if(wn != nil){
		xs_win_rel(wn, p.x, p.y, &rx, &ry);
		if(win_x != nil)
			*win_x = rx;
		if(win_y != nil)
			*win_y = ry;
	}
	if(mask != nil)
		*mask = lastmouse.buttons;
	return True;
}
