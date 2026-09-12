/*
 * tkPlan9Stubs.c --
 *
 *	Stub implementations of platform-specific Tk functions that are
 *	not meaningful on Plan 9 but must be present for linking.
 *
 *	These include: region operations, busy windows, transparency,
 *	angled text, binding keysym lookup, and test infrastructure.
 */

#include "tkPlan9Int.h"

/*
 * Minimal Plan 9 region implementation.
 *
 * X11 Region is an opaque pointer to struct _XRegion.  We represent it
 * as a simple axis-aligned bounding box.  This is sufficient for all
 * region uses in Tk's generic and unix/ code (scrolling damage, photo
 * images).  Complex multi-rect regions collapse to their union bbox.
 */
struct _XRegion {
    int x, y, w, h;
    int empty;
};

Region
XCreateRegion(void)
{
    Region r = (Region) ckalloc(sizeof(struct _XRegion));
    r->x = r->y = r->w = r->h = 0;
    r->empty = 1;
    return r;
}

int
XDestroyRegion(Region rgn)
{
    if (rgn) ckfree(rgn);
    return 0;
}

int
XClipBox(Region rgn, XRectangle *rect_return)
{
    if (!rgn || rgn->empty) {
        rect_return->x = rect_return->y = 0;
        rect_return->width = rect_return->height = 0;
    } else {
        rect_return->x      = (short)rgn->x;
        rect_return->y      = (short)rgn->y;
        rect_return->width  = (unsigned short)rgn->w;
        rect_return->height = (unsigned short)rgn->h;
    }
    return 0;
}

int
XEmptyRegion(Region rgn)
{
    return !rgn || rgn->empty;
}

int
XUnionRectWithRegion(XRectangle *rect, Region src, Region dst)
{
    int x1, y1, x2, y2;
    if (!rect || !src || !dst) return 0;
    if (src->empty) {
        dst->x = rect->x; dst->y = rect->y;
        dst->w = rect->width; dst->h = rect->height;
        dst->empty = (rect->width == 0 || rect->height == 0);
        return 0;
    }
    x1 = src->x < rect->x ? src->x : rect->x;
    y1 = src->y < rect->y ? src->y : rect->y;
    x2 = (src->x + src->w) > (rect->x + rect->width) ?
         (src->x + src->w) : (rect->x + (int)rect->width);
    y2 = (src->y + src->h) > (rect->y + rect->height) ?
         (src->y + src->h) : (rect->y + (int)rect->height);
    dst->x = x1; dst->y = y1;
    dst->w = x2 - x1; dst->h = y2 - y1;
    dst->empty = 0;
    return 0;
}

int
XIntersectRegion(Region sra, Region srcb, Region dr_return)
{
    int x1, y1, x2, y2;
    if (!sra || !srcb || !dr_return) return 0;
    if (sra->empty || srcb->empty) { dr_return->empty = 1; return 0; }
    x1 = sra->x > srcb->x ? sra->x : srcb->x;
    y1 = sra->y > srcb->y ? sra->y : srcb->y;
    x2 = (sra->x + sra->w) < (srcb->x + srcb->w) ?
         (sra->x + sra->w) : (srcb->x + srcb->w);
    y2 = (sra->y + sra->h) < (srcb->y + srcb->h) ?
         (sra->y + sra->h) : (srcb->y + srcb->h);
    if (x2 <= x1 || y2 <= y1) { dr_return->empty = 1; return 0; }
    dr_return->x = x1; dr_return->y = y1;
    dr_return->w = x2 - x1; dr_return->h = y2 - y1;
    dr_return->empty = 0;
    return 0;
}

int
XSubtractRegion(Region sra, Region srcb, Region dr_return)
{
    /* Approximate: return sra (subtraction of bbox is complex) */
    if (!sra || !dr_return) return 0;
    *dr_return = *sra;
    (void)srcb;
    return 0;
}

int
XRectInRegion(Region rgn, int x, int y, unsigned int w, unsigned int h)
{
    if (!rgn || rgn->empty) return RectangleOut;
    if (x >= rgn->x + rgn->w || y >= rgn->y + rgn->h ||
        (int)(x + w) <= rgn->x || (int)(y + h) <= rgn->y)
        return RectangleOut;
    if (x >= rgn->x && y >= rgn->y &&
        (int)(x + w) <= rgn->x + rgn->w &&
        (int)(y + h) <= rgn->y + rgn->h)
        return RectangleIn;
    return RectanglePart;
}

int
XOffsetRegion(Region rgn, int dx, int dy)
{
    if (rgn && !rgn->empty) { rgn->x += dx; rgn->y += dy; }
    return 0;
}

/* ------------------------------------------------------------------ */
/* TkpCopyRegion / TkpBuildRegionFromAlphaData                        */
/* ------------------------------------------------------------------ */

void
TkpCopyRegion(TkRegion dst, TkRegion src)
{
    if (dst && src) *(Region)dst = *(Region)src;
}

/*
 * Mark the non-transparent pixels of a photo block as valid.
 *
 * This is not decorative and it must not be a stub. modelPtr->validRegion
 * is how the photo code records which pixels it has, and Tk_PhotoPutBlock
 * builds it HERE for any block with alpha -- which is every photo, since
 * pix32 always carries an alpha byte. Leave the region empty and
 * TkImgPhotoConfigureInstance's
 *
 *	TkClipBox(modelPtr->validRegion, &validBox);
 *	if ((validBox.width > 0) && (validBox.height > 0))
 *	    TkImgDitherInstance(...);
 *
 * never fires, so the instance pixmap is never written -- TkPutImage is
 * reached from nowhere else -- and every photo drew as whatever was
 * behind it. The same empty region is then set as the gc's clip mask for
 * the XCopyArea that paints it, so it fails twice over.
 *
 * Silent, and it looks like a drawing bug: XPutImage was simply never
 * called, which is what section 3 of sys/lib/tests/tk-image-test.tcl
 * reports and what a $TKP9DEBUG trace on XPutImage's entry proves.
 *
 * Upstream's loop, kept run by run rather than collapsed to one bounding
 * box: the region here is a bbox, so the two agree today, but a real
 * region implementation later would need no change.
 */
void
TkpBuildRegionFromAlphaData(Region region,
    unsigned x, unsigned y,
    unsigned width, unsigned height,
    unsigned char *dataPtr,	/* points at the alpha byte of (x, y) */
    unsigned pixelStride,
    unsigned lineStride)
{
    unsigned char *lineDataPtr;
    unsigned x1, y1, end;
    XRectangle rect;

    if (region == NULL || dataPtr == NULL)
	return;

    for (y1 = 0; y1 < height; y1++) {
	lineDataPtr = dataPtr;
	for (x1 = 0; x1 < width; x1 = end) {
	    /* Skip to the first non-transparent pixel of this run. */
	    while (x1 < width && *lineDataPtr == 0) {
		x1++;
		lineDataPtr += pixelStride;
	    }
	    end = x1;
	    while (end < width && *lineDataPtr != 0) {
		end++;
		lineDataPtr += pixelStride;
	    }
	    if (end > x1) {
		rect.x      = (short)(x + x1);
		rect.y      = (short)(y + y1);
		rect.width  = (unsigned short)(end - x1);
		rect.height = 1;
		XUnionRectWithRegion(&rect, region, region);
	    }
	}
	dataPtr += lineStride;
    }
}

/* ------------------------------------------------------------------ */
/* Busy windows (transparency)                                         */
/* ------------------------------------------------------------------ */

void
TkpShowBusyWindow(TkBusy busy)
{
    (void)busy;
}

void
TkpHideBusyWindow(TkBusy busy)
{
    (void)busy;
}

void
TkpMakeTransparentWindowExist(Tk_Window tkwin, Window parent)
{
    (void)tkwin; (void)parent;
}

void
TkpCreateBusy(Tk_FakeWin *winPtr, Tk_Window tkRef,
              Window *parentPtr, Tk_Window tkParent, TkBusy busy)
{
    (void)winPtr; (void)tkRef; (void)parentPtr;
    (void)tkParent; (void)busy;
}

/* ------------------------------------------------------------------ */
/* Angled text drawing (not yet supported)                            */
/* ------------------------------------------------------------------ */

void
TkpDrawAngledCharsInContext(
    Display *display,
    Drawable d,
    GC gc,
    Tk_Font tkfont,
    const char *source,
    Tcl_Size numBytes,
    Tcl_Size rangeStart,
    Tcl_Size rangeLength,
    double x, double y,
    double angle)
{
    /* Fallback: draw horizontally, ignoring angle */
    Tk_DrawCharsInContext(display, d, gc, tkfont,
                          source, numBytes,
                          rangeStart, rangeLength,
                          (int)x, (int)y);
    (void)angle;
}


/* ------------------------------------------------------------------ */
/* Font attributes for a character                                    */
/* ------------------------------------------------------------------ */

/* TkpGetFontAttrsForChar is in tkPlan9Font.c */

/* ------------------------------------------------------------------ */
/* ICU (no-op — Plan 9 doesn't have libicu)                          */
/* ------------------------------------------------------------------ */

void
Icu_Init(Tcl_Interp *interp)
{
    (void)interp;
}

/* ------------------------------------------------------------------ */
/* Misc pointer / input stubs                                         */
/* ------------------------------------------------------------------ */

void
TkpSetMainMenubar(Tcl_Interp *interp, Tk_Window tkwin, const char *name)
{
    (void)interp; (void)tkwin; (void)name;
}

void
TkpMenuNotifyToplevelCreate(Tcl_Interp *interp, const char *menuName)
{
    (void)interp; (void)menuName;
}

void
TkpMenuInit(void)
{
}

void
TkpMenuThreadInit(void)
{
}

/* ------------------------------------------------------------------ */
/* Dialog stubs (Plan 9 has no native file/color dialogs)            */
/* ------------------------------------------------------------------ */

int
Tk_ChooseColorObjCmd(void *clientData, Tcl_Interp *interp,
                     int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
    return TCL_OK;
}

int
Tk_ChooseDirectoryObjCmd(void *clientData, Tcl_Interp *interp,
                         int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
    return TCL_OK;
}

int
Tk_GetOpenFileObjCmd(void *clientData, Tcl_Interp *interp,
                     int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
    return TCL_OK;
}

int
Tk_GetSaveFileObjCmd(void *clientData, Tcl_Interp *interp,
                     int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
    return TCL_OK;
}

int
Tk_MessageBoxObjCmd(void *clientData, Tcl_Interp *interp,
                    int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("ok", -1));
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* Print stub (no CUPS on Plan 9)                                     */
/* ------------------------------------------------------------------ */

int
Tk_PrintObjCmd(void *clientData, Tcl_Interp *interp,
               int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("printing not supported on Plan 9", -1));
    return TCL_ERROR;
}

/* ------------------------------------------------------------------ */
/* Atom name lookup                                                    */
/* ------------------------------------------------------------------ */

/*
 * NULL MEANS "NO SUCH ATOM", AND AN EMPTY STRING DOES NOT. This used to
 * return a ckalloc'd "", the XLoadFont mistake again: Tk_GetAtomName
 * (generic/tkAtom.c) turns a NULL into the sentinel "?bad atom?", which
 * is what "winfo atomname 44215" tests for and reports as `no atom
 * exists with id "44215"`. An empty name made every id look valid
 * (winfo-2.5).
 *
 * There is nothing to look up. Atoms here are Tk's own -- xlib/xutil.c
 * XInternAtom is a counter -- and generic Tk caches every one it
 * interns in dispPtr->atomTable, so this is only ever reached for an id
 * Tk has never seen. win/stubs.c and macosx/tkMacOSXXStubs.c, the other
 * two ports with no server, both return NULL unconditionally.
 */
char *
XGetAtomName(Display *display, Atom atom)
{
    (void)display; (void)atom;
    return NULL;
}

/* ------------------------------------------------------------------ */
/* SVG stub (linked optionally)                                       */
/* ------------------------------------------------------------------ */

int
Tk_SvgImageType_Init(Tcl_Interp *interp)
{
    (void)interp;
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* Unix-specific stubs required by tkStubInit.c for X11 builds        */
/* ------------------------------------------------------------------ */

/* TkpCmapStressed: Plan 9 has no colormap stress */
int
TkpCmapStressed(Tk_Window tkwin, Colormap colormap)
{
    (void)tkwin; (void)colormap;
    return 0;
}

/* TkUnixContainerId: no embedding support */
Window
TkUnixContainerId(TkWindow *winPtr)
{
    (void)winPtr;
    return None;
}

/* TkUnixDoOneXEvent: process one X event with timeout */
int
TkUnixDoOneXEvent(Tcl_Time *timePtr)
{
    (void)timePtr;
    return 0;
}

/*
 * TkUnixSetMenubar lives in tkPlan9Wm.c now, beside the WmInfo it has to
 * write. It used to be an empty stub here, under a comment reading "no
 * separate menubar on Plan 9" -- which was true of the DECORATION and
 * false of everything else the function does: it never mapped the
 * menubar window, so "tkwait visibility" on one waited forever and
 * unixWm-50.5 froze the whole test suite.
 */

/* TkWmCleanup: wm cleanup on display close */
void
TkWmCleanup(TkDisplay *dispPtr)
{
    (void)dispPtr;
}

/* TkSendCleanup: send mechanism cleanup */
void
TkSendCleanup(TkDisplay *dispPtr)
{
    (void)dispPtr;
}

/* TkSetPixmapColormap: not needed on Plan 9.
 * tkPlan9Port.h defines TkSetPixmapColormap(p,c) as a macro to no-op
 * call sites, but we still need the linker symbol for the stubs table.
 * Undef the macro before defining the function. */
#undef TkSetPixmapColormap
void
TkSetPixmapColormap(Pixmap pixmap, Colormap colormap)
{
    (void)pixmap; (void)colormap;
}


/* TkpSetCapture: pointer capture (no-op on Plan 9) */
void
TkpSetCapture(TkWindow *winPtr)
{
    (void)winPtr;
}

/* TkpGetCapture: pointer capture query */
Tk_Window
TkpGetCapture(void)
{
    return NULL;
}

/* ------------------------------------------------------------------ */
/* Display warning (no stderr on Plan 9 GUI — write to /dev/cons)    */
/* ------------------------------------------------------------------ */

/*
 * Write through Tcl's stderr channel, as tkUnixInit.c does, not with
 * fprintf. This is the only path by which a startup-script error is
 * ever reported -- Tk_MainEx calls it and then Tcl_Exit(1) -- so if it
 * goes astray, a failing script exits 1 with nothing said at all, which
 * is exactly what every Tk test file was doing.
 *
 * Mixing C stdio with Tcl channel writes on one descriptor also gives
 * unpredictable interleaving, and bypasses Tcl's own flushing at exit.
 * Falling back to fputs keeps something on the terminal if the channel
 * is not available -- during finalization, say.
 */
void
TkpDisplayWarning(const char *msg, const char *title)
{
    Tcl_Channel errChannel = Tcl_GetStdChannel(TCL_STDERR);

    if (errChannel) {
	if (title && *title) {
	    Tcl_WriteChars(errChannel, title, TCL_INDEX_NONE);
	    Tcl_WriteChars(errChannel, ": ", 2);
	}
	if (msg)
	    Tcl_WriteChars(errChannel, msg, TCL_INDEX_NONE);
	Tcl_WriteChars(errChannel, "\n", 1);
	Tcl_Flush(errChannel);
	return;
    }

    if (title && *title) {
	fputs(title, stderr);
	fputs(": ", stderr);
    }
    if (msg)
	fputs(msg, stderr);
    fputs("\n", stderr);
    fflush(stderr);
}

/* ------------------------------------------------------------------ */
/* Server info / screen name (Plan 9 stubs)                          */
/* ------------------------------------------------------------------ */

void
TkGetServerInfo(Tcl_Interp *interp, Tk_Window tkwin)
{
    (void)tkwin;
    Tcl_SetObjResult(interp, Tcl_NewStringObj("Plan9 0 Plan9 0 x", -1));
}

const char *
TkGetDefaultScreenName(Tcl_Interp *interp, const char *screenName)
{
    (void)interp;
    if (screenName && *screenName)
        return screenName;
    return "plan9";
}

/* ------------------------------------------------------------------ */
/* Key binding stubs (Plan 9 has no XKB)                             */
/* ------------------------------------------------------------------ */

/*
 * THE STORE IS THE POINT, not the XIM adjustment. Plan 9 has no input
 * method, so the half of tkUnixKey.c's Tk_SetCaretPos that talks to one
 * genuinely has nothing to do here -- but "tk caret" is a QUERY as well,
 * and generic Tk answers it out of dispPtr->caret (tkCmds.c's
 * CaretCmd). An empty stub therefore made
 *
 *	tk caret . -x 10 -y 11 -h 12 ; tk caret .
 *
 * answer "-height 0 -x 0 -y 0" (tk-5.5, tk-5.6). Same mistake as
 * "wm title" was: the platform having nothing to display is no reason
 * for the value not to read back.
 *
 * The early return when nothing changed is upstream's and is kept,
 * since on X it is what suppresses a round trip to the input method.
 */
void
Tk_SetCaretPos(Tk_Window tkwin, int x, int y, int height)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    TkDisplay *dispPtr;

    if (winPtr == NULL || (dispPtr = winPtr->dispPtr) == NULL)
	return;
    if (dispPtr->caret.winPtr == winPtr
	    && dispPtr->caret.x == x
	    && dispPtr->caret.y == y
	    && dispPtr->caret.height == height)
	return;

    dispPtr->caret.winPtr = winPtr;
    dispPtr->caret.x = x;
    dispPtr->caret.y = y;
    dispPtr->caret.height = height;
}

/*
 * The characters a key event stands for -- Tk's %A substitution.
 *
 * The keysym is the Unicode code point for anything printable, so the
 * string is just its UTF-8 encoding. Keysyms in the 0xFF00 range are
 * function and cursor keys and stand for no character at all, and
 * neither does a keysym of 0.
 */
const char *
TkpGetString(TkWindow *winPtr, XEvent *eventPtr, Tcl_DString *dsPtr)
{
    KeySym sym;
    char buf[TCL_UTF_MAX + 1];
    int n;

    (void)winPtr;
    Tcl_DStringSetLength(dsPtr, 0);

    if (eventPtr == NULL ||
        (eventPtr->type != KeyPress && eventPtr->type != KeyRelease))
	return Tcl_DStringValue(dsPtr);

    sym = (KeySym) eventPtr->xkey.keycode;
    if (sym == 0 || (sym >= 0xFF00 && sym <= 0xFFFF))
	return Tcl_DStringValue(dsPtr);

    n = Tcl_UniCharToUtf((int) sym, buf);
    Tcl_DStringAppend(dsPtr, buf, n);
    return Tcl_DStringValue(dsPtr);
}

/*
 * Fill in a synthetic key event's keycode from its keysym.
 *
 * "event generate . <Key-a>" goes through here (tkBind.c:4156) and then
 * checks the result:
 *
 *	TkpSetKeycodeAndState(tkwin, keysym, &event.general);
 *	if (event.general.xkey.keycode == 0) {
 *	    ... "no keycode for keysym \"%s\"" ...
 *	}
 *
 * so an empty stub failed every key event in the suite -- 146 of the
 * 196 remaining failures in bind.test were this one function.
 *
 * This port keeps keycode and keysym identical: XKeycodeToKeysym and
 * TkpGetKeySym both hand the value straight back. That works for every
 * keysym rather than only the ASCII ones because KeyCode here is an
 * unsigned int, not X11's 8-bit type, and XKeyEvent.keycode is an
 * unsigned int too. No modifier state is needed either, since the
 * keysym is carried exactly rather than being recovered from a keyboard
 * map -- which is what tkUnixKey.c's loop over shift levels is for.
 */
void
TkpSetKeycodeAndState(Tk_Window tkwin, KeySym keySym, XEvent *eventPtr)
{
    (void)tkwin;

    if (eventPtr == NULL)
	return;
    if (keySym == NoSymbol) {
	eventPtr->xkey.keycode = 0;
	return;
    }
    eventPtr->xkey.keycode = (unsigned int) keySym;

    /*
     * X's version reports which shift level of the keycode produced the
     * keysym and ORs in ShiftMask accordingly; do the same from the
     * keysym alone. Note this is an OR: tkBind.c has already put the
     * pattern's own modifiers in xkey.state before calling us.
     */
    if (TkP9KeysymShifted(keySym))
	eventPtr->xkey.state |= ShiftMask;
}

/*
 * The inverse of TkpSetKeycodeAndState: keycode and keysym are the same
 * value here.
 *
 * This used to answer NoSymbol for anything that was not a KeyPress,
 * which loses the release half of every binding -- Tk matches <KeyRelease>
 * patterns through this same call.
 */
KeySym
TkpGetKeySym(TkDisplay *dispPtr, XEvent *eventPtr)
{
    (void)dispPtr;

    if (eventPtr == NULL)
	return NoSymbol;
    if (eventPtr->type != KeyPress && eventPtr->type != KeyRelease)
	return NoSymbol;
    if (eventPtr->xkey.keycode == 0)
	return NoSymbol;
    return (KeySym) eventPtr->xkey.keycode;
}

/* ------------------------------------------------------------------ */
/* Pixmap wrappers (normally from unix/tkUnixXId.c)                  */
/* ------------------------------------------------------------------ */

Pixmap
Tk_GetPixmap(Display *display, Drawable d, int width, int height, int depth)
{
    return XCreatePixmap(display, d, (unsigned)width, (unsigned)height,
        (unsigned)depth);
}

void
Tk_FreePixmap(Display *display, Pixmap pixmap)
{
    XFreePixmap(display, pixmap);
}

/* ------------------------------------------------------------------ */
/* Embed / container (no embedding support on Plan 9)                 */
/* ------------------------------------------------------------------ */

/*
 * Tk_UseWindow, Tk_MakeContainer and Tk_GetOtherWindow are real now and
 * live in tkPlan9Wm.c beside the Container list they share.
 */

/* ------------------------------------------------------------------ */
/* App name (no send/register on Plan 9)                              */
/* ------------------------------------------------------------------ */

const char *
Tk_SetAppName(Tk_Window tkwin, const char *name)
{
    (void)tkwin;
    return name;
}

/* ------------------------------------------------------------------ */
/* Clipboard cleanup (no X11 clipboard server)                        */
/* ------------------------------------------------------------------ */

void
TkClipCleanup(TkDisplay *dispPtr)
{
    (void)dispPtr;
}

/* ------------------------------------------------------------------ */
/* Angled text drawing                                                */
/* ------------------------------------------------------------------ */

void
TkDrawAngledChars(Display *display, Drawable drawable, GC gc,
                  Tk_Font tkfont, const char *source, Tcl_Size numBytes,
                  double x, double y, double angle)
{
    if (angle == 0.0) {
        Tk_DrawChars(display, drawable, gc, tkfont, source, (int)numBytes,
            (int)x, (int)y);
    }
}

/* ------------------------------------------------------------------ */
/* Interp names (send is not supported on Plan 9)                     */
/* ------------------------------------------------------------------ */

/*
 * TkpTestembedCmd lives in tkPlan9Wm.c now, beside the Container list
 * it reports. It used to raise "testembed not supported on Plan 9"
 * from here -- the XLoadFont mistake again, since embedding has worked
 * in this port since Tk_UseWindow was written and the command had an
 * answer to give all along.
 */

int
TkGetInterpNames(Tcl_Interp *interp, Tk_Window tkwin)
{
    (void)interp; (void)tkwin;
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* XLoadFont stub (no X11 font server)                                */
/* ------------------------------------------------------------------ */

/*
 * There is no X font server here, but returning None is not "no font
 * server", it is "that font could not be loaded" -- and Tk treats the
 * difference as fatal. tkUnixCursor.c's TkGetCursorByName loads
 * CURSORFONT to pick glyph shapes out of it:
 *
 *	dispPtr->cursorFont = XLoadFont(display, CURSORFONT);
 *	if (dispPtr->cursorFont == None) {
 *	    ... "couldn't load cursor font" ...
 *	}
 *	cursor = XCreateGlyphCursor(display, dispPtr->cursorFont, ...);
 *
 * so returning None failed every widget that has a -cursor default,
 * which is most of them:
 *
 *	Error in startup script: couldn't load cursor font
 *	    (default value for "-cursor" in widget ".e")
 *
 * The id is only ever handed back to XCreateGlyphCursor, which ignores
 * it here -- rio owns the pointer, so cursors are cosmetic and
 * XCreateGlyphCursor already answers a placeholder. A non-zero id is
 * therefore honest about what we can do: the font is not real, but
 * nothing ever reads it.
 */
Font
XLoadFont(Display *display, const char *name)
{
    (void)display; (void)name;
    return (Font) 1;
}

/* ------------------------------------------------------------------ */
/* TkpGetPixel — pack XColor r/g/b into 0x00RRGGBB pixel value        */
/* ------------------------------------------------------------------ */

unsigned long
TkpGetPixel(XColor *colorPtr)
{
    return ((unsigned long)(colorPtr->red   >> 8) << 16)
         | ((unsigned long)(colorPtr->green >> 8) <<  8)
         |  (unsigned long)(colorPtr->blue  >> 8);
}

