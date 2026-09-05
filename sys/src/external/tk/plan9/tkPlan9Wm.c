/*
 * tkPlan9Wm.c --
 *
 *	Window manager interface for the Plan 9 Tk backend.
 *
 *	Plan 9 has no separate window manager protocol; the single window
 *	is managed directly via libdraw.  These functions provide the
 *	minimal stubs needed by Tk's generic wm.c.
 */

#include "tkPlan9Int.h"
#include "tkSelect.h"
#include <time.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/* Toplevel geometry                                                   */
/* ------------------------------------------------------------------ */

/*
 * Every toplevel needs a geometry manager, and this port had none.
 *
 * Tk does not size a toplevel itself: it hands the job to the window
 * manager through Tk_ManageGeometry, and when the contents of a
 * toplevel want more room, pack/grid/place call Tk_GeometryRequest,
 * which reaches the wm's requestProc and nowhere else. With
 * TkWmNewWindow an empty stub, no toplevel was ever managed, so no
 * toplevel was ever sized: it stayed 1x1, and pack then refused to map
 * children that could not fit in 1x1.
 *
 * That is the whole of bind.test's
 *
 *	toplevel .t -width 100 -height 50
 *	pack [frame .t.f -width 150 -height 100]
 *	pack [frame .t.g -width 150 -height 100]
 *
 * where .t stayed 1x1 and .t.g and .t.h came back "mapped 0", and it is
 * why widgets in a second toplevel piled into the corner at their
 * minimum size.
 *
 * There is no window manager on Plan 9 -- rio owns the frame and there
 * is one window -- so this is the smallest thing that can stand in for
 * one: honour an explicit "wm geometry", otherwise take the requested
 * size, clamp to minsize/maxsize, and resize. tkUnixWm.c does a great
 * deal more, and all of it is about negotiating with a real window
 * manager.
 */

typedef struct TkWmInfo {
    TkWindow *winPtr;
    int x, y;			/* Requested position. */
    int width, height;		/* Explicit size from "wm geometry", or -1
				 * to follow the requested size. */
    int minWidth, minHeight;
    int maxWidth, maxHeight;	/* 0 means unlimited. */
    int withdrawn;
    int flags;
    struct TkWmInfo *nextPtr;
} WmInfo;

#define WM_UPDATE_PENDING	1
#define WM_NEVER_MAPPED		2

static void WmUpdateGeometry(void *clientData);

/*
 * Ask for a geometry update at idle time, as tkUnixWm.c's TopLevelReqProc
 * does. An explicit "wm geometry" size wins over the requested one, so
 * there is nothing to recompute in that case.
 */
static void
WmReqProc(void *clientData, Tk_Window tkwin)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    WmInfo *wmPtr = winPtr->wmInfoPtr;
    (void)clientData;

    if (wmPtr == NULL)
	return;
    if (wmPtr->width >= 0 && wmPtr->height >= 0)
	return;
    if (!(wmPtr->flags & (WM_UPDATE_PENDING|WM_NEVER_MAPPED))) {
	Tcl_DoWhenIdle(WmUpdateGeometry, winPtr);
	wmPtr->flags |= WM_UPDATE_PENDING;
    }
}

static const Tk_GeomMgr wmMgrType = {
    "wm",			/* name */
    WmReqProc,			/* requestProc */
    NULL			/* lostContentProc */
};

static void
WmUpdateGeometry(void *clientData)
{
    TkWindow *winPtr = (TkWindow *) clientData;
    WmInfo *wmPtr = winPtr->wmInfoPtr;
    int width, height;

    if (wmPtr == NULL)
	return;
    wmPtr->flags &= ~WM_UPDATE_PENDING;

    width  = (wmPtr->width  >= 0) ? wmPtr->width
				  : Tk_ReqWidth((Tk_Window) winPtr);
    height = (wmPtr->height >= 0) ? wmPtr->height
				  : Tk_ReqHeight((Tk_Window) winPtr);

    if (width  < wmPtr->minWidth)  width  = wmPtr->minWidth;
    if (height < wmPtr->minHeight) height = wmPtr->minHeight;
    if (wmPtr->maxWidth  > 0 && width  > wmPtr->maxWidth)
	width = wmPtr->maxWidth;
    if (wmPtr->maxHeight > 0 && height > wmPtr->maxHeight)
	height = wmPtr->maxHeight;
    if (width  < 1) width  = 1;
    if (height < 1) height = 1;

    if (width == winPtr->changes.width && height == winPtr->changes.height
	    && wmPtr->x == winPtr->changes.x
	    && wmPtr->y == winPtr->changes.y)
	return;

    /*
     * On X the server answers a resize request with a ConfigureNotify and
     * Tk learns the new size from it. There is no server here, so record
     * it directly; XMoveResizeWindow still sends the ConfigureNotify, so
     * <Configure> bindings and the widgets that relayout on them work.
     */
    winPtr->changes.x      = wmPtr->x;
    winPtr->changes.y      = wmPtr->y;
    winPtr->changes.width  = width;
    winPtr->changes.height = height;
    if (winPtr->window != None)
	XMoveResizeWindow(winPtr->display, winPtr->window,
		wmPtr->x, wmPtr->y, (unsigned) width, (unsigned) height);
}

/* Force the update now rather than at idle time. */
static void
WmUpdateNow(TkWindow *winPtr)
{
    WmInfo *wmPtr = winPtr->wmInfoPtr;

    if (wmPtr == NULL)
	return;
    if (wmPtr->flags & WM_UPDATE_PENDING) {
	Tcl_CancelIdleCall(WmUpdateGeometry, winPtr);
	wmPtr->flags &= ~WM_UPDATE_PENDING;
    }
    WmUpdateGeometry(winPtr);
}

/* ------------------------------------------------------------------ */
/* TkpGetWrapperWindow / TkpMakeMenuWindow                            */
/* ------------------------------------------------------------------ */

TkWindow *
TkpGetWrapperWindow(TkWindow *winPtr)
{
    /* On Plan 9 there is no separate wrapper; return the toplevel itself */
    TkWindow *w = winPtr;
    while (w && !(w->flags & TK_TOP_LEVEL))
        w = w->parentPtr;
    return w ? w : winPtr;
}

void
TkpMakeMenuWindow(Tk_Window tkwin, int transient)
{
    (void)tkwin; (void)transient;
}

/* ------------------------------------------------------------------ */
/* Wm state: iconify, withdraw, etc.                                  */
/* ------------------------------------------------------------------ */

/*
 * Withdrawn means unmapped, and normal means mapped. There is no icon
 * and no window manager, so IconicState is treated as withdrawn.
 */
int
TkpWmSetState(TkWindow *winPtr, int state)
{
    if (winPtr == NULL || winPtr->window == None)
	return 1;
    if (state == NormalState || state == ZoomState) {
	if (!(winPtr->flags & TK_MAPPED))
	    TkWmMapWindow(winPtr);
    } else {
	if (winPtr->flags & TK_MAPPED)
	    TkWmUnmapWindow(winPtr);
    }
    return 1;
}

/* ------------------------------------------------------------------ */
/* Title / icon name                                                  */
/* ------------------------------------------------------------------ */

void
TkpWmSetTitle(TkWindow *winPtr, const char *title)
{
    (void)winPtr; (void)title;
}

/* ------------------------------------------------------------------ */
/* Wm-level configure                                                 */
/* ------------------------------------------------------------------ */

void
TkpWmConfigure(TkWindow *winPtr, int w, int h)
{
    Tk_Window tkwin = (Tk_Window)winPtr;
    XResizeWindow(Tk_Display(tkwin), Tk_WindowId(tkwin),
                  (unsigned)w, (unsigned)h);
}

/* ------------------------------------------------------------------ */
/* Focus management (trivial — no separate focus server)              */
/* ------------------------------------------------------------------ */

/*
 * Record where keyboard input should go. Returning 0 tells tkFocus.c to
 * generate the FocusIn/FocusOut events itself rather than waiting for
 * ones from a server -- there is no server here to send them. That is
 * also what tkUnixWm.c's TkpChangeFocus returns when it does not call
 * XSetInputFocus.
 */
int
TkpChangeFocus(TkWindow *winPtr, int claim)
{
    (void)claim;
    if (winPtr != NULL && winPtr->window != None)
	XSetInputFocus(winPtr->display, winPtr->window, RevertToParent,
	               CurrentTime);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Cursor                                                             */
/* ------------------------------------------------------------------ */

void
TkpSetCursor(TkpCursor cursor)
{
    (void)cursor;
}

/* ------------------------------------------------------------------ */
/* Embed (no embedding support)                                       */
/* ------------------------------------------------------------------ */

void
TkpGetOtherWindow(TkWindow *winPtr)
{
    (void)winPtr;
}

int
TkpUseWindow(Tcl_Interp *interp, Tk_Window tkwin, const char *string)
{
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("-use not supported on Plan 9", -1));
    return TCL_ERROR;
}

int
TkpScanWindowId(Tcl_Interp *interp, const char *string, Window *idPtr)
{
    (void)interp;
    *idPtr = (Window)strtoul(string, NULL, 0);
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* Warp pointer                                                       */
/* ------------------------------------------------------------------ */

void
TkpDoWarpWrtWin(TkDisplay *dispPtr)
{
    (void)dispPtr;
}

void
TkpWarpPointer(TkDisplay *dispPtr)
{
    Window w;

    if (dispPtr->warpWindow != NULL)
	w = Tk_WindowId(dispPtr->warpWindow);
    else
	w = TKP9_ROOT_XID;
    XWarpPointer(dispPtr->display, None, w, 0, 0, 0, 0,
	    (int) dispPtr->warpX, (int) dispPtr->warpY);
}

/* ------------------------------------------------------------------ */
/* Session management stubs                                           */
/* ------------------------------------------------------------------ */

void
TkpGetRegistryKey(Tcl_DString *result)
{
    Tcl_DStringAppend(result, "/tmp/tk_registry", -1);
}

/* ------------------------------------------------------------------ */
/* System notification / tray (no-op)                                 */
/* ------------------------------------------------------------------ */

int
Tktray_Init(Tcl_Interp *interp)
{
    (void)interp;
    return TCL_OK;
}

int
SysNotify_Init(Tcl_Interp *interp)
{
    (void)interp;
    return TCL_OK;
}

int
Cups_Init(Tcl_Interp *interp)
{
    (void)interp;
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* Selection / clipboard, backed by /dev/snarf                        */
/* ------------------------------------------------------------------ */

/*
 * Plan 9 has one system-wide cut buffer, /dev/snarf, so PRIMARY and
 * CLIPBOARD both map onto it. That is the behaviour a user wants
 * anyway: snarf in an editor, paste into a Tk entry.
 *
 * This hook is reached only for a selection Tk does *not* own --
 * tkSelect.c serves a locally-owned one from its own handlers and never
 * gets here (see Tk_GetSelection), so "clipboard get" right after
 * "clipboard append" does not depend on any of this.
 */
int
TkSelGetSelection(Tcl_Interp *interp, Tk_Window tkwin,
                  Atom selection, Atom target,
                  Tk_GetSelProc *proc, void *clientData)
{
    const char *targetName;
    char *snarf;
    int result;

    targetName = Tk_GetAtomName(tkwin, target);

    if (strcmp(targetName, "TARGETS") == 0)
	return proc(clientData, interp, "STRING TARGETS TEXT UTF8_STRING");

    if (strcmp(targetName, "STRING") != 0
	    && strcmp(targetName, "UTF8_STRING") != 0
	    && strcmp(targetName, "TEXT") != 0
	    && strcmp(targetName, "COMPOUND_TEXT") != 0)
	goto cantget;

    /* /dev/snarf is UTF-8, which is what every one of those wants. */
    snarf = tkp9_getsnarf();
    if (snarf == NULL)
	goto cantget;
    result = proc(clientData, interp, snarf);
    free(snarf);
    return result;

  cantget:
    Tcl_SetObjResult(interp, Tcl_ObjPrintf(
	"%s selection doesn't exist or form \"%s\" not defined",
	Tk_GetAtomName(tkwin, selection), targetName));
    Tcl_SetErrorCode(interp, "TK", "SELECTION", "EXISTS", (char *)NULL);
    return TCL_ERROR;
}

/*
 * Push Tk's clipboard out to /dev/snarf.
 *
 * Called by tkClipboard.c after every "clipboard clear" and every
 * "clipboard append", and it was an empty macro in tkPlan9Port.h -- so
 * nothing a Tk application copied was ever visible to anything else on
 * the system.
 *
 * Rebuild the whole buffer each time rather than trying to append: on a
 * clear the target list is empty and snarf correctly becomes empty, and
 * on an append the concatenation is what the clipboard now holds. rio
 * gives no way to append to /dev/snarf in any case.
 */
void
TkSelUpdateClipboard(TkWindow *winPtr, clipboardOption option)
{
    TkDisplay *dispPtr;
    TkClipboardTarget *targetPtr, *bestPtr;
    TkClipboardBuffer *cbPtr;
    Atom utf8Atom, stringAtom;
    Tcl_DString ds;

    (void)option;
    if (winPtr == NULL || winPtr->dispPtr == NULL)
	return;
    dispPtr = winPtr->dispPtr;

    utf8Atom   = Tk_InternAtom((Tk_Window) winPtr, "UTF8_STRING");
    stringAtom = Tk_InternAtom((Tk_Window) winPtr, "STRING");

    /* Prefer UTF8_STRING; fall back to STRING. Both are UTF-8 here. */
    bestPtr = NULL;
    for (targetPtr = dispPtr->clipTargetPtr; targetPtr != NULL;
	    targetPtr = targetPtr->nextPtr) {
	if (targetPtr->type == utf8Atom) {
	    bestPtr = targetPtr;
	    break;
	}
	if (targetPtr->type == stringAtom && bestPtr == NULL)
	    bestPtr = targetPtr;
    }

    Tcl_DStringInit(&ds);
    if (bestPtr != NULL) {
	for (cbPtr = bestPtr->firstBufferPtr; cbPtr != NULL;
		cbPtr = cbPtr->nextPtr)
	    Tcl_DStringAppend(&ds, cbPtr->buffer, (Tcl_Size) cbPtr->length);
    }
    tkp9_putsnarf(Tcl_DStringValue(&ds), (int) Tcl_DStringLength(&ds));
    Tcl_DStringFree(&ds);
}

void
TkSelEventProc(Tk_Window tkwin, XEvent *eventPtr)
{
    (void)tkwin; (void)eventPtr;
}

void
TkSelPropProc(XEvent *eventPtr)
{
    (void)eventPtr;
}


/* ------------------------------------------------------------------ */
/* Send command (no-op — Plan 9 has no X11 send)                     */
/* ------------------------------------------------------------------ */

int
TkpTestsendCmd(void *clientData, Tcl_Interp *interp,
               Tcl_Size objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("send not supported on Plan 9", -1));
    return TCL_ERROR;
}

/* ------------------------------------------------------------------ */
/* Clipboard (minimal)                                                */
/* ------------------------------------------------------------------ */

int
TkpClipboardAppend(TkDisplay *dispPtr, Atom target, Atom format,
                   const char *buffer, int length)
{
    (void)dispPtr; (void)target; (void)format; (void)buffer; (void)length;
    return TCL_OK;
}

/* ------------------------------------------------------------------ */
/* Window manager internal functions (TkWm*)                          */
/* Plan 9 has no separate WM; these are no-ops or minimal stubs.      */
/* ------------------------------------------------------------------ */

void
TkWmNewWindow(TkWindow *winPtr)
{
    WmInfo *wmPtr = (WmInfo *) ckalloc(sizeof(WmInfo));

    memset(wmPtr, 0, sizeof(WmInfo));
    wmPtr->winPtr    = winPtr;
    wmPtr->x         = winPtr->changes.x;
    wmPtr->y         = winPtr->changes.y;
    wmPtr->width     = -1;
    wmPtr->height    = -1;
    wmPtr->minWidth  = 1;
    wmPtr->minHeight = 1;
    wmPtr->flags     = WM_NEVER_MAPPED;
    wmPtr->nextPtr   = winPtr->dispPtr->firstWmPtr;
    winPtr->dispPtr->firstWmPtr = wmPtr;
    winPtr->wmInfoPtr = wmPtr;

    /*
     * This is the whole point: without it, a Tk_GeometryRequest from the
     * toplevel's contents reaches nobody and the toplevel never resizes.
     */
    Tk_ManageGeometry((Tk_Window) winPtr, &wmMgrType, NULL);
}

/*
 * Tk_MapWindow hands a toplevel entirely to us and returns:
 *
 *	if (winPtr->flags & TK_TOP_HIERARCHY) {
 *	    TkWmMapWindow(winPtr);
 *	    return;
 *	}
 *	winPtr->flags |= TK_MAPPED;
 *	XMapWindow(winPtr->display, winPtr->window);
 *
 * so a no-op here means the toplevel is never marked mapped and never
 * mapped, and since the geometry managers only map children of a mapped
 * parent, nothing in the whole application is ever mapped. Tk draws only
 * mapped windows, so wish showed a blank white window whatever it was
 * doing, and "winfo ismapped .f" answered 0 after pack and update.
 *
 * There is no window manager here -- rio owns the window and there is
 * exactly one -- so the right behaviour is what Tk_MapWindow does for an
 * ordinary window: mark it mapped and map it. tkUnixWm.c does a great
 * deal more, but all of it concerns wrapper windows, WM hints and
 * icons, none of which exist on Plan 9.
 */
void
TkWmMapWindow(TkWindow *winPtr)
{
    WmInfo *wmPtr = winPtr->wmInfoPtr;

    /*
     * Size it before it appears. Until now the toplevel has been
     * accumulating geometry requests with updates suppressed
     * (WM_NEVER_MAPPED), exactly as tkUnixWm.c does, so that a window
     * is not resized repeatedly while it is still being built.
     */
    if (wmPtr != NULL && (wmPtr->flags & WM_NEVER_MAPPED)) {
	wmPtr->flags &= ~WM_NEVER_MAPPED;
	WmUpdateGeometry(winPtr);
    }
    if (winPtr->flags & TK_MAPPED)
	return;
    winPtr->flags |= TK_MAPPED;
    XMapWindow(winPtr->display, winPtr->window);
}

void
TkWmUnmapWindow(TkWindow *winPtr)
{
    if (!(winPtr->flags & TK_MAPPED))
	return;
    winPtr->flags &= ~TK_MAPPED;
    XUnmapWindow(winPtr->display, winPtr->window);
}

void
TkWmDeadWindow(TkWindow *winPtr)
{
    WmInfo *wmPtr = winPtr->wmInfoPtr, *prevPtr;

    if (wmPtr == NULL)
	return;
    if (winPtr->dispPtr->firstWmPtr == wmPtr) {
	winPtr->dispPtr->firstWmPtr = wmPtr->nextPtr;
    } else {
	for (prevPtr = winPtr->dispPtr->firstWmPtr; prevPtr != NULL;
		prevPtr = prevPtr->nextPtr) {
	    if (prevPtr->nextPtr == wmPtr) {
		prevPtr->nextPtr = wmPtr->nextPtr;
		break;
	    }
	}
    }
    if (wmPtr->flags & WM_UPDATE_PENDING)
	Tcl_CancelIdleCall(WmUpdateGeometry, winPtr);
    winPtr->wmInfoPtr = NULL;
    ckfree(wmPtr);
}

void
TkWmSetClass(TkWindow *winPtr)
{
    (void)winPtr;
}

void
TkWmRestackToplevel(TkWindow *winPtr, int aboveBelow, TkWindow *otherPtr)
{
    (void)winPtr; (void)aboveBelow; (void)otherPtr;
}

TkWindow *
TkWmFocusToplevel(TkWindow *winPtr)
{
    TkWindow *w = winPtr;
    while (w && !(w->flags & TK_TOP_LEVEL))
        w = w->parentPtr;
    return w;
}

void
TkWmAddToColormapWindows(TkWindow *winPtr)
{
    (void)winPtr;
}

void
TkWmRemoveFromColormapWindows(TkWindow *winPtr)
{
    (void)winPtr;
}

TkWindow **
TkWmStackorderToplevel(TkWindow *parentPtr)
{
    (void)parentPtr;
    return NULL;
}

void
TkWmProtocolEventProc(TkWindow *winPtr, XEvent *eventPtr)
{
    (void)winPtr; (void)eventPtr;
}

/* ------------------------------------------------------------------ */
/* Grid geometry hint (wm-level resize grid)                         */
/* ------------------------------------------------------------------ */

void
Tk_SetGrid(Tk_Window tkwin, int reqWidth, int reqHeight,
           int gridWidth, int gridHeight)
{
    (void)tkwin; (void)reqWidth; (void)reqHeight;
    (void)gridWidth; (void)gridHeight;
}

void
Tk_UnsetGrid(Tk_Window tkwin)
{
    (void)tkwin;
}

/* ------------------------------------------------------------------ */
/* Root coordinates                                                   */
/* ------------------------------------------------------------------ */

void
Tk_GetRootCoords(Tk_Window tkwin, int *xPtr, int *yPtr)
{
    TkWindow *winPtr = (TkWindow *)tkwin;
    int x = 0, y = 0;
    while (winPtr) {
        x += winPtr->changes.x + winPtr->changes.border_width;
        y += winPtr->changes.y + winPtr->changes.border_width;
        winPtr = winPtr->parentPtr;
    }
    *xPtr = x;
    *yPtr = y;
}

/* ------------------------------------------------------------------ */
/* Create actual X window (Plan 9: allocate an XID)                  */
/* ------------------------------------------------------------------ */

Window
Tk_MakeWindow(Tk_Window tkwin, Window parent)
{
    TkWindow *winPtr = (TkWindow *)tkwin;
    XSetWindowAttributes atts;
    unsigned long mask = 0;

    if (winPtr->atts.background_pixmap != None) {
        atts.background_pixmap = winPtr->atts.background_pixmap;
        mask |= CWBackPixmap;
    } else {
        atts.background_pixel = winPtr->atts.background_pixel;
        mask |= CWBackPixel;
    }
    atts.border_pixel = winPtr->atts.border_pixel;
    atts.colormap     = winPtr->atts.colormap;
    mask |= CWBorderPixel | CWColormap;

    return XCreateWindow(winPtr->display, parent,
        winPtr->changes.x, winPtr->changes.y,
        (unsigned)winPtr->changes.width, (unsigned)winPtr->changes.height,
        (unsigned)winPtr->changes.border_width,
        winPtr->depth, InputOutput, winPtr->visual, mask, &atts);
}

/* ------------------------------------------------------------------ */
/* Millisecond timer (platform)                                       */
/* ------------------------------------------------------------------ */

unsigned long
TkpGetMS(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (unsigned long)(ts.tv_sec * 1000UL + ts.tv_nsec / 1000000UL);
}

/* ------------------------------------------------------------------ */
/* Focus claim / key redirect (embed stubs — no embedding on Plan 9)  */
/* ------------------------------------------------------------------ */

void
TkpClaimFocus(TkWindow *topLevelPtr, int force)
{
    (void)topLevelPtr; (void)force;
}

void
TkpRedirectKeyEvent(TkWindow *winPtr, XEvent *eventPtr)
{
    (void)winPtr; (void)eventPtr;
}

/* ------------------------------------------------------------------ */
/* User inactivity timer (no idle detection on Plan 9)                */
/* ------------------------------------------------------------------ */

long
Tk_GetUserInactiveTime(Display *dpy)
{
    (void)dpy;
    return -1;
}

void
Tk_ResetUserInactiveTime(Display *dpy)
{
    (void)dpy;
}

/* ------------------------------------------------------------------ */
/* Pointer coords (return last known mouse position)                  */
/* ------------------------------------------------------------------ */

void
Tk_GetPointerCoords(Tk_Window tkwin, int *xPtr, int *yPtr)
{
    (void)tkwin;
    *xPtr = 0;
    *yPtr = 0;
}

void
TkGetPointerCoords(Tk_Window tkwin, int *xPtr, int *yPtr)
{
    (void)tkwin;
    *xPtr = 0;
    *yPtr = 0;
}

/* ------------------------------------------------------------------ */
/* Virtual root geometry (Plan 9 has no virtual root; = screen size)  */
/* ------------------------------------------------------------------ */

void
Tk_GetVRootGeometry(Tk_Window tkwin, int *xPtr, int *yPtr,
                    int *widthPtr, int *heightPtr)
{
    *xPtr      = 0;
    *yPtr      = 0;
    *widthPtr  = WidthOfScreen(Tk_Screen(tkwin));
    *heightPtr = HeightOfScreen(Tk_Screen(tkwin));
}

/* ------------------------------------------------------------------ */
/* Coords → window hit-test                                           */
/* ------------------------------------------------------------------ */

Tk_Window
Tk_CoordsToWindow(int rootX, int rootY, Tk_Window tkwin)
{
    (void)rootX; (void)rootY; (void)tkwin;
    return NULL;
}

/* ------------------------------------------------------------------ */
/* Move toplevel (delegate to XMoveWindow)                            */
/* ------------------------------------------------------------------ */

void
Tk_MoveToplevelWindow(Tk_Window tkwin, int x, int y)
{
    TkWindow *winPtr = (TkWindow *)tkwin;
    XMoveWindow(winPtr->display, winPtr->window, x, y);
}

/* ------------------------------------------------------------------ */
/* Wm command — Plan 9 has no WM protocol, so most sub-commands are   */
/* no-ops.  Queries return sensible defaults.                          */
/* ------------------------------------------------------------------ */

int
Tk_WmObjCmd(void *clientData, Tcl_Interp *interp,
            int objc, Tcl_Obj *const objv[])
{
    static const char *const opts[] = {
        "aspect", "attributes", "client", "colormapwindows",
        "command", "deiconify", "focusmodel", "forget",
        "frame", "geometry", "grid", "group",
        "iconbadge", "iconbitmap", "iconify",
        "iconmask", "iconname", "iconphoto",
        "iconposition", "iconwindow", "manage", "maxsize",
        "minsize", "overrideredirect", "positionfrom",
        "protocol", "resizable", "sizefrom", "stackorder",
        "state", "title", "transient", "withdraw", NULL
    };
    enum {
        OPT_ASPECT, OPT_ATTRIBUTES, OPT_CLIENT, OPT_CMAPWINS,
        OPT_COMMAND, OPT_DEICONIFY, OPT_FOCUSMODEL, OPT_FORGET,
        OPT_FRAME, OPT_GEOMETRY, OPT_GRID, OPT_GROUP,
        OPT_ICONBADGE, OPT_ICONBITMAP, OPT_ICONIFY,
        OPT_ICONMASK, OPT_ICONNAME, OPT_ICONPHOTO,
        OPT_ICONPOS, OPT_ICONWIN, OPT_MANAGE, OPT_MAXSIZE,
        OPT_MINSIZE, OPT_OVERREDIR, OPT_POSFROM,
        OPT_PROTOCOL, OPT_RESIZABLE, OPT_SIZEFROM, OPT_STACKORDER,
        OPT_STATE, OPT_TITLE, OPT_TRANSIENT, OPT_WITHDRAW
    };
    int index;
    Tk_Window tkwin = NULL;
    TkWindow *winPtr = NULL;
    WmInfo *wmPtr = NULL;

    if (objc < 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "option window ?arg ...?");
        return TCL_ERROR;
    }
    if (Tcl_GetIndexFromObjStruct(interp, objv[1], opts,
            sizeof(char *), "option", 0, &index) != TCL_OK)
        return TCL_ERROR;

    /*
     * Resolve the window. This used to be skipped entirely, so every
     * "wm" subcommand that sets something was a silent no-op -- "wm
     * geometry .t 200x100" changed nothing and reported no error.
     */
    if (objc >= 3) {
        tkwin = Tk_NameToWindow(interp, Tcl_GetString(objv[2]),
                (Tk_Window) clientData);
        if (tkwin == NULL)
            return TCL_ERROR;
        winPtr = (TkWindow *) tkwin;
        wmPtr  = winPtr->wmInfoPtr;
    }

    switch (index) {
    case OPT_GEOMETRY:
        if (objc == 3) {
            char buf[TCL_INTEGER_SPACE * 4 + 4];
            snprintf(buf, sizeof buf, "%dx%d+%d+%d",
                    winPtr->changes.width, winPtr->changes.height,
                    winPtr->changes.x, winPtr->changes.y);
            Tcl_SetObjResult(interp, Tcl_NewStringObj(buf, -1));
            return TCL_OK;
        }
        if (objc == 4 && wmPtr != NULL) {
            const char *s = Tcl_GetString(objv[3]);
            int w, h, x, y;

            if (*s == '\0') {		/* revert to the requested size */
                wmPtr->width = wmPtr->height = -1;
                WmUpdateNow(winPtr);
                return TCL_OK;
            }
            /*
             * WxH, +X+Y, or both. A position-only form must leave the
             * size following the requested one, or packing a toplevel
             * after "wm geometry .t +0+0" would freeze it at 1x1.
             */
            if (sscanf(s, "%dx%d%d%d", &w, &h, &x, &y) == 4) {
                /* WxH-X-Y, the negative-offset form. */
                wmPtr->width = w; wmPtr->height = h;
                wmPtr->x = x; wmPtr->y = y;
            } else if (sscanf(s, "%dx%d+%d+%d", &w, &h, &x, &y) == 4) {
                wmPtr->width = w; wmPtr->height = h;
                wmPtr->x = x; wmPtr->y = y;
            } else if (sscanf(s, "%dx%d", &w, &h) == 2) {
                wmPtr->width = w; wmPtr->height = h;
            } else if (sscanf(s, "+%d+%d", &x, &y) == 2
                    || sscanf(s, "%d%d", &x, &y) == 2) {
                wmPtr->x = x; wmPtr->y = y;
            } else {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "bad geometry specifier \"%s\"", s));
                Tcl_SetErrorCode(interp, "TK", "VALUE", "GEOMETRY",
                        (char *)NULL);
                return TCL_ERROR;
            }
            WmUpdateNow(winPtr);
        }
        return TCL_OK;

    case OPT_MINSIZE:
    case OPT_MAXSIZE: {
        int w, h;

        if (objc == 3) {
            if (wmPtr == NULL) {
                Tcl_SetObjResult(interp, Tcl_NewStringObj("0 0", -1));
                return TCL_OK;
            }
            Tcl_SetObjResult(interp, Tcl_ObjPrintf("%d %d",
                    (index == OPT_MINSIZE) ? wmPtr->minWidth : wmPtr->maxWidth,
                    (index == OPT_MINSIZE) ? wmPtr->minHeight : wmPtr->maxHeight));
            return TCL_OK;
        }
        if (objc == 5 && wmPtr != NULL) {
            if (Tcl_GetIntFromObj(interp, objv[3], &w) != TCL_OK
                    || Tcl_GetIntFromObj(interp, objv[4], &h) != TCL_OK)
                return TCL_ERROR;
            if (index == OPT_MINSIZE) {
                wmPtr->minWidth = w; wmPtr->minHeight = h;
            } else {
                wmPtr->maxWidth = w; wmPtr->maxHeight = h;
            }
            WmUpdateNow(winPtr);
        }
        return TCL_OK;
    }

    case OPT_WITHDRAW:
        if (winPtr != NULL) {
            if (wmPtr != NULL)
                wmPtr->withdrawn = 1;
            TkpWmSetState(winPtr, WithdrawnState);
        }
        return TCL_OK;

    case OPT_DEICONIFY:
        if (winPtr != NULL) {
            if (wmPtr != NULL)
                wmPtr->withdrawn = 0;
            TkpWmSetState(winPtr, NormalState);
        }
        return TCL_OK;

    case OPT_STATE:
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    (wmPtr != NULL && wmPtr->withdrawn)
                        ? "withdrawn" : "normal", -1));
        }
        return TCL_OK;

    case OPT_STACKORDER:
        /* return empty list */
        Tcl_SetObjResult(interp, Tcl_NewListObj(0, NULL));
        return TCL_OK;

    case OPT_ICONNAME:
    case OPT_TITLE:
        /* query returns empty string; set is silently accepted */
        if (objc == 3)
            Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
        return TCL_OK;

    case OPT_RESIZABLE:
        /* query returns "1 1" */
        if (objc == 3)
            Tcl_SetObjResult(interp, Tcl_NewStringObj("1 1", -1));
        return TCL_OK;

    case OPT_FRAME:
        /* return "0x0" — Plan 9 has no separate frame window */
        Tcl_SetObjResult(interp, Tcl_NewStringObj("0x0", -1));
        return TCL_OK;

    default:
        /* all other sub-commands silently succeed */
        return TCL_OK;
    }
}
