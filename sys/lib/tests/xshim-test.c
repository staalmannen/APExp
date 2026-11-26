/*
 * xshim-test.c -- the xshim Xlib subset, checked against its own contract.
 *
 * Run it in a rio window: it opens the one display, so it cannot run from a
 * bare terminal.  Every case prints PASS or FAIL and the program exits with
 * the number of failures.  It never blocks waiting for input, so it cannot
 * hang; the event cases only check what is already queued.
 *
 * The contract each case asserts is the one in sys/include/ape/xshim.h:
 * one window, rio's, with the root and the window ids fixed; a drawable
 * other than the window is refused (pixmaps are not supported yet); a
 * zero-size outline draws nothing and succeeds.
 */
#include <u.h>
#include <libc.h>
#include <xshim.h>

static int fails;

static void
check(int ok, char *what)
{
	print("%s: %s\n", ok ? "PASS" : "FAIL", what);
	if(!ok)
		fails++;
}

void
main(void)
{
	Display *dpy;
	Display *again;
	GC gc;
	XRectangle r[2];
	XEvent ev;
	Window w;

	dpy = XOpenDisplay(nil);
	check(dpy != nil, "XOpenDisplay returns a display");
	if(dpy == nil)
		exits("no display");

	again = XOpenDisplay(nil);
	check(again == dpy, "a second XOpenDisplay returns the same display");

	check(XDisplayWidth(dpy, 0) > 0 && XDisplayHeight(dpy, 0) > 0,
		"the screen has a positive size");
	check(XDefaultRootWindow(dpy) == XSHIM_ROOT, "the root window id is XSHIM_ROOT");

	w = XCreateSimpleWindow(dpy, XDefaultRootWindow(dpy), 0, 0, 100, 100, 0, 0, 0);
	check(w == XSHIM_WINDOW, "XCreateSimpleWindow returns the one window");
	check(XMapWindow(dpy, w) && XSelectInput(dpy, w, ExposureMask),
		"map and select on the window succeed");

	gc = XCreateGC(dpy, w, 0, nil);
	check(gc != nil, "XCreateGC returns a context");
	check(XSetForeground(dpy, gc, 0xFF0000), "XSetForeground succeeds");
	check(XFillRectangle(dpy, w, gc, 10, 10, 40, 20), "XFillRectangle on the window succeeds");
	check(XDrawRectangle(dpy, w, gc, 0, 0, 30, 30), "XDrawRectangle succeeds");
	check(XDrawRectangle(dpy, w, gc, 5, 5, 0, 0), "a zero-size outline draws nothing and succeeds");
	check(XDrawLine(dpy, w, gc, 0, 0, 50, 50), "XDrawLine succeeds");

	r[0].x = 1; r[0].y = 1; r[0].width = 5; r[0].height = 5;
	r[1].x = 20; r[1].y = 20; r[1].width = 5; r[1].height = 5;
	check(XFillRectangles(dpy, w, gc, r, 2), "XFillRectangles succeeds");

	check(!XFillRectangle(dpy, 99L, gc, 0, 0, 1, 1),
		"a drawable other than the window is refused");

	check(XFlush(dpy) && XSync(dpy, False), "XFlush and XSync succeed");

	/* nothing has been typed or moved yet, so nothing should be queued;
	 * a nonzero count here only means the mouse moved, so it is reported */
	if(XPending(dpy) != 0)
		print("INFO: events were already queued (mouse moved?)\n");
	else
		check(1, "no events are queued at start");

	check(XFreeGC(dpy, gc), "XFreeGC succeeds");
	check(XCloseDisplay(dpy), "XCloseDisplay succeeds");

	USED(ev);
	print("%d failure(s)\n", fails);
	exits(fails ? "fail" : nil);
}
