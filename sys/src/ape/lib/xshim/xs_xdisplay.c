#include <X11/Xlib.h>
#include <stdlib.h>
#include <string.h>

/*
 * The X display and font structures, built with the standard layout so that
 * the public macros (DisplayWidth, DefaultRootWindow, ...) and clients' field
 * accesses are right.  This file includes only the standard header, not libdraw,
 * so its names never meet libdraw's Display or Font.  The root window is id 1,
 * as in xs_win.c.
 */

#define XS_ROOT	1UL

void*
xs_newxdisplay(int width, int height)
{
	_XPrivDisplay d;
	Screen *s;

	/* the display's fields are reached through _XPrivDisplay, as the macros do */
	d = calloc(1, sizeof *d);
	s = calloc(1, sizeof *s);
	if(d == NULL || s == NULL){
		free(d);
		free(s);
		return NULL;
	}
	s->display = (Display*)d;
	s->root = XS_ROOT;
	s->width = width;
	s->height = height;
	s->root_depth = 24;
	s->white_pixel = 0xFFFFFF;
	s->black_pixel = 0;
	s->max_maps = 1;
	s->min_maps = 1;
	d->screens = s;
	d->nscreens = 1;
	d->default_screen = 0;
	d->display_name = ":0";
	d->vendor = "APExp xshim (libdraw)";
	d->proto_major_version = 11;
	d->proto_minor_version = 0;
	d->fd = -1;
	return d;
}

/* rio resized the window: the screen's size follows it */
void
xs_resizexdisplay(void *dpy, int width, int height)
{
	_XPrivDisplay d;

	d = dpy;
	if(d == NULL || d->screens == NULL)
		return;
	d->screens[0].width = width;
	d->screens[0].height = height;
}

/* a font, with the standard layout; the metrics the shim knows are filled in */
void*
xs_newfont(XID fid, int ascent, int descent)
{
	XFontStruct *fs;

	fs = calloc(1, sizeof *fs);
	if(fs == NULL)
		return NULL;
	fs->fid = fid;
	fs->ascent = ascent;
	fs->descent = descent;
	fs->min_char_or_byte2 = 0;
	fs->max_char_or_byte2 = 255;
	return fs;
}

XID
xs_fontfid(void *fs)
{
	return fs != NULL ? ((XFontStruct*)fs)->fid : None;
}

/*
 * The Xlib functions that the standard macros of the same stem stand beside.
 * Each reads the standard display structure, as the macros do.
 */
int
XDefaultScreen(Display *dpy)
{
	return ((_XPrivDisplay)dpy)->default_screen;
}

Window
XDefaultRootWindow(Display *dpy)
{
	return ScreenOfDisplay(dpy, DefaultScreen(dpy))->root;
}

int
XDisplayWidth(Display *dpy, int scr)
{
	return ScreenOfDisplay(dpy, scr)->width;
}

int
XDisplayHeight(Display *dpy, int scr)
{
	return ScreenOfDisplay(dpy, scr)->height;
}

unsigned long
XBlackPixel(Display *dpy, int scr)
{
	return ScreenOfDisplay(dpy, scr)->black_pixel;
}

unsigned long
XWhitePixel(Display *dpy, int scr)
{
	return ScreenOfDisplay(dpy, scr)->white_pixel;
}
