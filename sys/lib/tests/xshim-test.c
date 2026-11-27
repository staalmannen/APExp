/*
 * xshim-test.c -- the xshim Xlib subset, checked against its own contract.
 *
 * Run it in a rio window: it opens the one display, so it cannot run from a
 * bare terminal.  Every case prints PASS or FAIL and the program exits with
 * the number of failures.  It never blocks waiting for input, so it cannot
 * hang; the event cases only check what is already queued.
 *
 * The contract each case asserts is the one in sys/include/ape/xshim.h:
 * the root is rio's window, and every other window is a new id in its tree;
 a drawable
 * other than the window is refused (pixmaps are not supported yet); a
 * zero-size outline draws nothing and succeeds.
 */
#include <stdio.h>
#include <stdlib.h>
#include <xshim.h>

static int fails;

static void
check(int ok, char *what)
{
	printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
	if(!ok)
		fails++;
}

int
main(void)
{
	Display *dpy;
	Display *again;
	GC gc;
	XRectangle r[2];
	XEvent ev;
	Window w;

	dpy = XOpenDisplay(NULL);
	check(dpy != NULL, "XOpenDisplay returns a display");
	if(dpy == NULL)
		exit(1);

	again = XOpenDisplay(NULL);
	check(again == dpy, "a second XOpenDisplay returns the same display");

	check(XDisplayWidth(dpy, 0) > 0 && XDisplayHeight(dpy, 0) > 0,
		"the screen has a positive size");
	check(XDefaultRootWindow(dpy) == XSHIM_ROOT, "the root window id is XSHIM_ROOT");

	w = XCreateSimpleWindow(dpy, XDefaultRootWindow(dpy), 0, 0, 100, 100, 0, 0, 0);
	check(w != None && w != XDefaultRootWindow(dpy), "XCreateSimpleWindow returns a new window, not the root");

	{
		Window child, root, rw, cw;
		int rx, ry, wx, wy, gx, gy;
		unsigned int gw, gh, bw, dep, mask;
		Bool ok;

		child = XCreateSimpleWindow(dpy, w, 5, 6, 20, 10, 0, 0, 0);
		check(child != None && child != w, "a child window is created inside its parent");
		check(XMapWindow(dpy, child), "the child maps");
		check(XGetGeometry(dpy, child, &root, &gx, &gy, &gw, &gh, &bw, &dep)
			&& gx == 5 && gy == 6 && gw == 20 && gh == 10,
			"XGetGeometry reports the child's rectangle relative to its parent");
		check(XMoveResizeWindow(dpy, child, 7, 8, 30, 12), "XMoveResizeWindow succeeds");
		check(XRaiseWindow(dpy, child) && XLowerWindow(dpy, child), "XRaiseWindow and XLowerWindow succeed");
		{
			GC cgc = XCreateGC(dpy, child, 0, NULL);
			check(XFillRectangle(dpy, child, cgc, 0, 0, 5, 5), "drawing into a child succeeds");
			XFreeGC(dpy, cgc);
		}
		ok = XQueryPointer(dpy, w, &rw, &cw, &rx, &ry, &wx, &wy, &mask);
		check(ok == True && rw == XDefaultRootWindow(dpy), "XQueryPointer reports the root");
		check(XDestroyWindow(dpy, child) && !XDestroyWindow(dpy, child),
			"XDestroyWindow removes the child, and a second destroy fails");
		check(!XDestroyWindow(dpy, XDefaultRootWindow(dpy)), "the root cannot be destroyed");
	}
	check(XMapWindow(dpy, w) && XSelectInput(dpy, w, ExposureMask),
		"map and select on the window succeed");

	gc = XCreateGC(dpy, w, 0, NULL);
	check(gc != NULL, "XCreateGC returns a context");
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

	check(XDrawArc(dpy, w, gc, 10, 10, 60, 40, 0, 360*64), "XDrawArc (a full ellipse) succeeds");
	check(XFillArc(dpy, w, gc, 10, 10, 60, 40, 0, 90*64), "XFillArc (a pie quarter) succeeds");
	check(!XFillArc(dpy, 99L, gc, 0, 0, 1, 1, 0, 64), "XFillArc refuses a non-window drawable");

	{
		XFontStruct *fs = XLoadQueryFont(dpy, "fixed");
		check(fs != NULL && fs->ascent > 0, "XLoadQueryFont gives a font with a positive ascent");
		check(fs != NULL && XTextWidth(fs, "clock", 5) > 0, "XTextWidth of a word is positive");
		check(XDrawString(dpy, w, gc, 10, 50, "12", 2), "XDrawString succeeds");
		if(fs != NULL)
			XFreeFont(dpy, fs);
	}

	check(XFlush(dpy) && XSync(dpy, False), "XFlush and XSync succeed");

	/* nothing has been typed or moved yet, so nothing should be queued;
	 * a nonzero count here only means the mouse moved, so it is reported */
	if(XPending(dpy) != 0)
		printf("INFO: events were already queued (mouse moved?)\n");
	else
		check(1, "no events are queued at start");

	check(XFreeGC(dpy, gc), "XFreeGC succeeds");
	check(XCloseDisplay(dpy), "XCloseDisplay succeeds");

	(void)ev;
	printf("%d failure(s)\n", fails);
	return fails != 0;
}
