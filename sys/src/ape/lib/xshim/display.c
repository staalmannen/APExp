#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "xshim_p.h"

Display	*xs_dpy;

int	xs_expose;

Display*
XOpenDisplay(char *name)
{
	USED(name);
	if(xs_dpy != nil)
		return xs_dpy;
	if(initdraw(nil, nil, "xshim") < 0)
		return nil;
	xs_win_setroot(screen->r.min.x, screen->r.min.y, Dx(screen->r), Dy(screen->r));
	einit(Ekeyboard|Emouse);
	xs_dpy = display;
	return xs_dpy;
}

int
XCloseDisplay(Display *dpy)
{
	USED(dpy);
	if(xs_dpy != nil){
		closedisplay(xs_dpy);
		xs_dpy = nil;
	}
	return 1;
}

/* libdraw calls this when rio resizes the window; the application owns it */
void
eresized(int new)
{
	if(new && getwindow(xs_dpy, Refnone) < 0)
		sysfatal("xshim: getwindow: %r");
	xs_win_setroot(screen->r.min.x, screen->r.min.y, Dx(screen->r), Dy(screen->r));
	xs_expose = 1;
}

int
XDefaultScreen(Display *dpy)
{
	USED(dpy);
	return 0;
}

Window
XDefaultRootWindow(Display *dpy)
{
	USED(dpy);
	return XSHIM_ROOT;
}

int
XDisplayWidth(Display *dpy, int screen)
{
	USED(dpy); USED(screen);
	return Dx(xs_dpy->image->r);
}

int
XDisplayHeight(Display *dpy, int screen)
{
	USED(dpy); USED(screen);
	return Dy(xs_dpy->image->r);
}

unsigned long
XBlackPixel(Display *dpy, int screen)
{
	USED(dpy); USED(screen);
	return 0x000000;
}

unsigned long
XWhitePixel(Display *dpy, int screen)
{
	USED(dpy); USED(screen);
	return 0xFFFFFF;
}

int
XFlush(Display *dpy)
{
	USED(dpy);
	flushimage(xs_dpy, 1);
	return 1;
}

int
XSync(Display *dpy, Bool discard)
{
	USED(dpy); USED(discard);
	flushimage(xs_dpy, 1);
	return 1;
}
