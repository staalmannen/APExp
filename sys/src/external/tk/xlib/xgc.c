/*
 * xgc.c --
 *
 *	This file contains generic routines for manipulating X graphics
 *	contexts.
 *
 * Copyright © 1995-1996 Sun Microsystems, Inc.
 * Copyright © 2002-2009 Daniel A. Steffen <das@users.sourceforge.net>
 * Copyright © 2008-2009 Apple Inc.
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

#include "tkInt.h"
#include <X11/Xlib.h>
#if defined(MAC_OSX_TK)
#endif


/* The GC functions (XCreateGC ... XSetClipRectangles) moved to libxshim, xs_gc.c. */

#if 0
Cursor
XCreateFontCursor(
    Display *display,
    unsigned int shape)
{
    /*
     * Not reached by the Plan 9 port -- tkUnixCursor.c builds named
     * cursors with XCreateGlyphCursor -- but 0 is None, which Tk reads
     * as failure, and any two callers would collide in
     * dispPtr->cursorIdTable and panic. Answer a unique non-zero id for
     * the same reasons as the cursor stubs in plan9/tkPlan9Draw.c.
     */
    static unsigned long next = 0x40000000;

    (void) display;
    (void) shape;
    return (Cursor) next++;
}

void
XDrawImageString(
    Display *display,
    Drawable d,
    GC gc,
    int x,
    int y,
    _Xconst char *string,
    int length)
{
}
#endif

#ifndef PLAN9
int
XDrawPoint(
    Display *display,
    Drawable d,
    GC gc,
    int x,
    int y)
{
    return XDrawLine(display, d, gc, x, y, x, y);
}

int
XDrawPoints(
    Display *display,
    Drawable d,
    GC gc,
    XPoint *points,
    int npoints,
    TCL_UNUSED(int))
{
    int res = Success;

    while (npoints-- > 0) {
	res = XDrawLine(display, d, gc,
		points[0].x, points[0].y, points[0].x, points[0].y);
	if (res != Success) break;
	++points;
    }
    return res;
}

#if !defined(MAC_OSX_TK)
int
XDrawSegments(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Drawable),
    TCL_UNUSED(GC),
    TCL_UNUSED(XSegment *),
    TCL_UNUSED(int))
{
    return BadDrawable;
}
#endif

char *
XFetchBuffer(
    TCL_UNUSED(Display *),
    TCL_UNUSED(int *),
    TCL_UNUSED(int))
{
    return (char *) 0;
}

Status
XFetchName(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window),
    TCL_UNUSED(char **))
{
    return Success;
}

Atom *
XListProperties(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window),
    TCL_UNUSED(int *))
{
    return (Atom *) 0;
}

int
XMapRaised(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window))
{
    return Success;
}

int
XQueryTextExtents(
    TCL_UNUSED(Display *),
    TCL_UNUSED(XID),
    TCL_UNUSED(_Xconst char *),
    TCL_UNUSED(int),
    TCL_UNUSED(int *),
    TCL_UNUSED(int *),
    TCL_UNUSED(int *),
    TCL_UNUSED(XCharStruct *))
{
    return Success;
}

int
XReparentWindow(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window),
    TCL_UNUSED(Window),
    TCL_UNUSED(int),
    TCL_UNUSED(int))
{
    return BadWindow;
}

int
XUndefineCursor(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window))
{
    return Success;
}

XVaNestedList
XVaCreateNestedList(
    TCL_UNUSED(int), ...)
{
    return NULL;
}

char *
XSetICValues(
    TCL_UNUSED(XIC), ...)
{
    return NULL;
}

char *
XGetICValues(
    TCL_UNUSED(XIC), ...)
{
    return NULL;
}

void
XSetICFocus(
    TCL_UNUSED(XIC))
{
}

Window
XCreateWindow(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Window),
    TCL_UNUSED(int),
    TCL_UNUSED(int),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(int),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(Visual *),
    TCL_UNUSED(unsigned long),
    TCL_UNUSED(XSetWindowAttributes *))
{
	return 0;
}


void
XDestroyIC(
    TCL_UNUSED(XIC))
{
}

Cursor
XCreatePixmapCursor(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Pixmap),
    TCL_UNUSED(Pixmap),
    TCL_UNUSED(XColor *),
    TCL_UNUSED(XColor *),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(unsigned int))
{
    return (Cursor) NULL;
}

Cursor
XCreateGlyphCursor(
    TCL_UNUSED(Display *),
    TCL_UNUSED(Font),
    TCL_UNUSED(Font),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(unsigned int),
    TCL_UNUSED(XColor _Xconst *),
    TCL_UNUSED(XColor _Xconst *))
{
    return (Cursor) NULL;
}

XFontSet
XCreateFontSet(
    TCL_UNUSED(Display *)		/* display */,
    TCL_UNUSED(_Xconst char *)	/* base_font_name_list */,
    TCL_UNUSED(char ***)		/* missing_charset_list */,
    TCL_UNUSED(int *)		/* missing_charset_count */,
    TCL_UNUSED(char **)		/* def_string */
) {
    return (XFontSet)0;
}

void
XFreeFontSet(
    TCL_UNUSED(Display *),		/* display */
    TCL_UNUSED(XFontSet)		/* font_set */
) {
}

void
XFreeStringList(
    TCL_UNUSED(char **)		/* list */
) {
}

Status
XCloseIM(
    TCL_UNUSED(XIM) /* im */
) {
    return Success;
}

Bool
XRegisterIMInstantiateCallback(
    TCL_UNUSED(Display *)			/* dpy */,
    TCL_UNUSED(struct _XrmHashBucketRec *)	/* rdb */,
    TCL_UNUSED(char *)			/* res_name */,
    TCL_UNUSED(char *)			/* res_class */,
    TCL_UNUSED(XIDProc)			/* callback */,
    TCL_UNUSED(XPointer)			/* client_data */
) {
    return False;
}

Bool
XUnregisterIMInstantiateCallback(
    TCL_UNUSED(Display *)		/* dpy */,
    TCL_UNUSED(struct _XrmHashBucketRec *)	/* rdb */,
    TCL_UNUSED(char *)			/* res_name */,
    TCL_UNUSED(char *)			/* res_class */,
    TCL_UNUSED(XIDProc)			/* callback */,
    TCL_UNUSED(XPointer)			/* client_data */
) {
    return False;
}

char *
XSetLocaleModifiers(
    TCL_UNUSED(const char *)		/* modifier_list */
) {
    return NULL;
}

XIM XOpenIM(
    TCL_UNUSED(Display *)			/* dpy */,
    TCL_UNUSED(struct _XrmHashBucketRec *)	/* rdb */,
    TCL_UNUSED(char *)			/* res_name */,
    TCL_UNUSED(char *)			/* res_class */
) {
    return NULL;
}

char *
XGetIMValues(
    TCL_UNUSED(XIM) /* im */, ...
) {
    return NULL;
}

char *
XSetIMValues(
    TCL_UNUSED(XIM) /* im */, ...
) {
    return NULL;
}
#endif /* !PLAN9 */

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
