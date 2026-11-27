#include <u.h>
#include <libc.h>
#include <draw.h>
#include <xshim_types.h>
#include "xshim_p.h"

/*
 * Fonts, backed by libdraw's font support.  An X font id is an index into a
 * table of libdraw Fonts, plus one, so None (0) means "the default font".
 *
 * An X font name is handed to libdraw's openfont, which takes a Plan 9 font
 * file.  X names such as "fixed" or "-misc-fixed-..." are not Plan 9 files, so
 * they fall back to libdraw's default font.  That is the honest mapping for
 * now: the names are not translated, and any X font name gets the native one.
 */

static Font	**fonts;
static ulong	nfonts;

static XID
addfont(Font *f)
{
	ulong n, old;
	Font **t;

	old = nfonts;
	n = old ? old + 16 : 16;
	t = realloc(fonts, n * sizeof *t);
	if(t == nil)
		return None;
	memset(t + old, 0, (n - old) * sizeof *t);
	fonts = t;
	nfonts = n;
	fonts[old] = f;
	return old + 1;
}

/* the libdraw Font for an X font id; the default font for None */
static Font*
fontof(XID id)
{
	if(id == None || id > nfonts || fonts[id - 1] == nil)
		return xs_dpy->defaultfont;
	return fonts[id - 1];
}

XID
XLoadFont(Display *dpy, char *name)
{
	Font *f;

	USED(dpy);
	f = nil;
	if(name != nil && strcmp(name, "fixed") != 0)
		f = openfont(xs_dpy, name);
	if(f == nil)
		return None;
	return addfont(f);
}

XFontStruct*
XLoadQueryFont(Display *dpy, char *name)
{
	XFontStruct *fs;
	Font *f;
	XID id;

	USED(dpy);
	id = XLoadFont(dpy, name);
	f = fontof(id);
	if(f == nil)
		return nil;
	fs = malloc(sizeof *fs);
	if(fs == nil)
		return nil;
	fs->fid = id;
	fs->ascent = f->ascent;
	fs->descent = f->height - f->ascent;
	return fs;
}

int
XFreeFont(Display *dpy, XFontStruct *fs)
{
	USED(dpy);
	if(fs != nil)
		free(fs);
	return 1;
}

/* X's y is the baseline; libdraw's point is the top of the text */
int
XDrawString(Display *dpy, Drawable d, GC gc, int x, int y, char *s, int n)
{
	Font *f;
	Image *c;
	Point org, p;
	Rectangle clip;

	USED(dpy);
	if(!xs_target(d, &org, &clip))
		return 0;
	f = fontof(gc->font);
	if(f == nil)
		return 0;
	c = xs_colour(gc->foreground);
	if(c == nil)
		return 0;
	p = Pt(org.x + x, org.y + y - f->ascent);
	xs_clipbegin(clip);
	stringn(screen, p, c, ZP, f, s, n);
	xs_clipend();
	freeimage(c);
	return 1;
}

int
XTextWidth(XFontStruct *fs, char *s, int n)
{
	Font *f;
	char *buf;
	int w;

	f = fs != nil ? fontof(fs->fid) : xs_dpy->defaultfont;
	if(f == nil || s == nil)
		return 0;
	buf = malloc(n + 1);
	if(buf == nil)
		return 0;
	memmove(buf, s, n);
	buf[n] = 0;
	w = stringwidth(f, buf);
	free(buf);
	return w;
}
