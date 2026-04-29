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

void
TkpBuildRegionFromAlphaData(Region region,
    unsigned x, unsigned y,
    unsigned width, unsigned height,
    const unsigned char *dataPtr,
    unsigned pixelStride,
    unsigned lineStride)
{
    (void)region; (void)x; (void)y;
    (void)width; (void)height; (void)dataPtr;
    (void)pixelStride; (void)lineStride;
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
/* Atom name lookup (no real X server; return empty string)           */
/* ------------------------------------------------------------------ */

char *
XGetAtomName(Display *display, Atom atom)
{
    char *s;
    (void)display; (void)atom;
    /* Must return a ckalloc'd string — caller frees with XFree */
    s = (char *) ckalloc(1);
    s[0] = '\0';
    return s;
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

/* TkUnixSetMenubar: no separate menubar on Plan 9 */
void
TkUnixSetMenubar(Tk_Window tkwin, Tk_Window menubar)
{
    (void)tkwin; (void)menubar;
}

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

void
TkpDisplayWarning(const char *msg, const char *title)
{
    if (title && *title)
        fprintf(stderr, "%s: %s\n", title, msg ? msg : "");
    else if (msg)
        fprintf(stderr, "%s\n", msg);
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

void
Tk_SetCaretPos(Tk_Window tkwin, int x, int y, int height)
{
    (void)tkwin; (void)x; (void)y; (void)height;
}

const char *
TkpGetString(TkWindow *winPtr, XEvent *eventPtr, Tcl_DString *dsPtr)
{
    (void)winPtr; (void)eventPtr;
    Tcl_DStringSetLength(dsPtr, 0);
    return Tcl_DStringValue(dsPtr);
}

void
TkpSetKeycodeAndState(Tk_Window tkwin, KeySym keySym, XEvent *eventPtr)
{
    (void)tkwin; (void)keySym; (void)eventPtr;
}

KeySym
TkpGetKeySym(TkDisplay *dispPtr, XEvent *eventPtr)
{
    (void)dispPtr;
    if (eventPtr && eventPtr->type == KeyPress)
        return (KeySym)eventPtr->xkey.keycode;
    return NoSymbol;
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

int
Tk_UseWindow(Tcl_Interp *interp, Tk_Window tkwin, const char *string)
{
    (void)tkwin; (void)string;
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("-use not supported on Plan 9", -1));
    return TCL_ERROR;
}

void
Tk_MakeContainer(Tk_Window tkwin)
{
    (void)tkwin;
}

Tk_Window
Tk_GetOtherWindow(Tk_Window tkwin)
{
    (void)tkwin;
    return NULL;
}

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

