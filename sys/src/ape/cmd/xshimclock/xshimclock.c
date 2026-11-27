/*
 * xshimclock -- an analogue clock written against the Xlib subset that
 * libxshim provides, and nothing else.  It is a proof of concept: it shows that
 * an ordinary Xlib program runs on libdraw through the shim, with no Tk and no
 * X server.
 *
 * It draws a face, twelve ticks, numerals in the native font (through the
 * font shim), and three hands from the local time.  It redraws once a second
 * and on Expose, and it quits on the key q.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define W	300
#define H	300

static Display	*dpy;
static Window	win;
static GC	gc;
static XFontStruct *fs;

/* a hand from the centre, deg clockwise from twelve o'clock */
static void
hand(int cx, int cy, double len, double deg, unsigned int width)
{
	double a;
	int x, y;

	a = deg * M_PI / 180.0;
	x = cx + (int)(len * sin(a) + 0.5);
	y = cy - (int)(len * cos(a) + 0.5);
	XSetLineAttributes(dpy, gc, width, LineSolid, CapButt, JoinMiter);
	XDrawLine(dpy, win, gc, cx, cy, x, y);
}

static void
redraw(void)
{
	int cx, cy, r, i, x, y, w;
	double a;
	char buf[4];
	time_t now;
	struct tm *tm;

	cx = W / 2;
	cy = H / 2;
	r = W / 2 - 10;

	XClearWindow(dpy, win);

	/* the face */
	XSetLineAttributes(dpy, gc, 2, LineSolid, CapButt, JoinMiter);
	XDrawArc(dpy, win, gc, cx - r, cy - r, 2 * r, 2 * r, 0, 360 * 64);

	/* the ticks, and the numerals inside them */
	for(i = 0; i < 12; i++){
		a = i * 30 * M_PI / 180.0;
		XDrawLine(dpy, win, gc,
			cx + (int)((r - 10) * sin(a) + 0.5), cy - (int)((r - 10) * cos(a) + 0.5),
			cx + (int)(r * sin(a) + 0.5), cy - (int)(r * cos(a) + 0.5));
		snprintf(buf, sizeof buf, "%d", i == 0 ? 12 : i);
		w = XTextWidth(fs, buf, strlen(buf));
		x = cx + (int)((r - 28) * sin(a) + 0.5);
		y = cy - (int)((r - 28) * cos(a) + 0.5);
		/* the baseline sits half the font's height below the centre */
		XDrawString(dpy, win, gc, x - w / 2, y + (fs->ascent - fs->descent) / 2,
			buf, strlen(buf));
	}

	/* the hands, from the local time */
	now = time(NULL);
	tm = localtime(&now);
	hand(cx, cy, r * 0.5, ((tm->tm_hour % 12) * 60 + tm->tm_min) / 2.0, 4);
	hand(cx, cy, r * 0.8, tm->tm_min * 6 + tm->tm_sec / 10.0, 3);
	hand(cx, cy, r * 0.9, tm->tm_sec * 6, 1);

	XFlush(dpy);
}

int
main(void)
{
	XEvent ev;
	time_t now, last;
	int dirty;

	dpy = XOpenDisplay(NULL);
	if(dpy == NULL){
		fprintf(stderr, "xshimclock: cannot open the display\n");
		return 1;
	}
	/* a white background: X's pixel 0 is black, which would hide the black face */
	win = XCreateSimpleWindow(dpy, XDefaultRootWindow(dpy), 0, 0, W, H, 0, 0, 0xFFFFFF);
	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
	XMapWindow(dpy, win);
	gc = XCreateGC(dpy, win, 0, NULL);
	fs = XLoadQueryFont(dpy, "fixed");
	if(fs == NULL){
		fprintf(stderr, "xshimclock: no font\n");
		return 1;
	}

	last = 0;
	dirty = 1;
	for(;;){
		while(XPending(dpy) > 0){
			XNextEvent(dpy, &ev);
			if(ev.type == Expose)
				dirty = 1;
			if(ev.type == KeyPress && ev.xkey.keycode == 'q')
				goto done;
		}
		now = time(NULL);
		if(now != last){
			last = now;
			dirty = 1;
		}
		if(dirty){
			redraw();
			dirty = 0;
		}
		usleep(200000);
	}
done:
	XFreeFont(dpy, fs);
	XFreeGC(dpy, gc);
	XCloseDisplay(dpy);
	return 0;
}
