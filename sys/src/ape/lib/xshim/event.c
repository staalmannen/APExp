#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "xshim_p.h"

/*
 * libdraw hands back one event at a time, and an X event may need several
 * slots, so the events are decoded into a small queue here.  The queue is
 * full only if the program stops reading for 64 events; newer events are
 * then dropped.
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
newevent(XEvent *e, int type)
{
	memset(e, 0, sizeof *e);
	e->type = type;
	e->xany.display = (struct _XDisplay*)xs_dpy;
	e->xany.window = XSHIM_WINDOW;
}

/* read one libdraw event (blocks unless the caller checked first) and queue
 * the X events it implies */
static void
pump(void)
{
	Event ev;
	XEvent xe;
	Point p;
	ulong id;
	int i, changed;

	id = eread(Ekeyboard|Emouse, &ev);
	if(id & Ekeyboard){
		newevent(&xe, KeyPress);
		xe.xkey.keycode = ev.kbdc;
		enqueue(&xe);
	}
	if(id & Emouse){
		p = subpt(ev.mouse.xy, xs_origin());
		changed = ev.mouse.buttons ^ lastmouse.buttons;
		/* Plan 9 button bits 0,1,2 are X buttons 1,2,3; the wheel is not mapped */
		for(i = 0; i < 3; i++)
			if(changed & (1<<i)){
				newevent(&xe, (ev.mouse.buttons & (1<<i)) ? ButtonPress : ButtonRelease);
				xe.xbutton.x = p.x;
				xe.xbutton.y = p.y;
				xe.xbutton.x_root = ev.mouse.xy.x;
				xe.xbutton.y_root = ev.mouse.xy.y;
				xe.xbutton.button = i + 1;
				enqueue(&xe);
			}
		if(!eqpt(ev.mouse.xy, lastmouse.xy)){
			newevent(&xe, MotionNotify);
			xe.xmotion.x = p.x;
			xe.xmotion.y = p.y;
			xe.xmotion.x_root = ev.mouse.xy.x;
			xe.xmotion.y_root = ev.mouse.xy.y;
			enqueue(&xe);
		}
		lastmouse = ev.mouse;
	}
}

int
XPending(Display *dpy)
{
	USED(dpy);
	if(qlen == 0 && !xs_expose && ecanread(Ekeyboard|Emouse))
		pump();
	return qlen + xs_expose;
}

int
XNextEvent(Display *dpy, XEvent *e)
{
	USED(dpy);
	for(;;){
		if(qlen > 0){
			*e = queue[qhead];
			qhead = (qhead + 1) % QLEN;
			qlen--;
			return 1;
		}
		if(xs_expose){
			xs_expose = 0;
			newevent(e, Expose);
			e->xexpose.x = 0;
			e->xexpose.y = 0;
			e->xexpose.width = Dx(xs_dpy->image->r);
			e->xexpose.height = Dy(xs_dpy->image->r);
			e->xexpose.count = 0;
			return 1;
		}
		pump();
	}
}

/* The position the event loop saw last; it is not read from the device here,
 * so it is only as fresh as the last event the program has taken. */
Bool
XQueryPointer(Display *dpy, Window w, Window *root, Window *child,
	int *root_x, int *root_y, int *win_x, int *win_y, unsigned int *mask)
{
	Point p;

	USED(dpy);
	USED(w);
	p = lastmouse.xy;
	if(root != nil) *root = XSHIM_ROOT;
	if(child != nil) *child = None;
	if(root_x != nil) *root_x = p.x;
	if(root_y != nil) *root_y = p.y;
	p = subpt(p, xs_origin());
	if(win_x != nil) *win_x = p.x;
	if(win_y != nil) *win_y = p.y;
	if(mask != nil) *mask = lastmouse.buttons;
	return True;
}
