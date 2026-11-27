#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "xshim_p.h"

Display	*xs_dpy;
static void	*xs_xdpy;	/* the standard display the macros read */

int	xs_expose;

/* xs_newxdisplay and xs_resizexdisplay, xs_xdisplay.c */
extern void	*xs_newxdisplay(int width, int height);
extern void	xs_resizexdisplay(void *dpy, int width, int height);

Display*
XOpenDisplay(char *name)
{
	USED(name);
	if(xs_xdpy != nil)
		return (Display*)xs_xdpy;
	if(initdraw(nil, nil, "xshim") < 0)
		return nil;
	xs_win_setroot(screen->r.min.x, screen->r.min.y, Dx(screen->r), Dy(screen->r));
	einit(Ekeyboard|Emouse);
	xs_dpy = display;
	xs_xdpy = xs_newxdisplay(Dx(screen->r), Dy(screen->r));
	return (Display*)xs_xdpy;
}

int
XCloseDisplay(Display *dpy)
{
	USED(dpy);
	if(xs_dpy != nil){
		closedisplay(xs_dpy);
		xs_dpy = nil;
		xs_xdpy = nil;
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
	if(xs_xdpy != nil)
		xs_resizexdisplay(xs_xdpy, Dx(screen->r), Dy(screen->r));
	xs_expose = 1;
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
