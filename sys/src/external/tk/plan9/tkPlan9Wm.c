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
#include <time.h>

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

int
TkpWmSetState(TkWindow *winPtr, int state)
{
    (void)winPtr; (void)state;
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

int
TkpChangeFocus(TkWindow *winPtr, int claim)
{
    (void)winPtr; (void)claim;
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
    (void)dispPtr;
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
/* Selection / clipboard stubs                                        */
/* ------------------------------------------------------------------ */

int
TkSelGetSelection(Tcl_Interp *interp, Tk_Window tkwin,
                  Atom selection, Atom target,
                  Tk_GetSelProc *proc, void *clientData)
{
    (void)tkwin; (void)selection; (void)target;
    (void)proc; (void)clientData;
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("selection not supported", -1));
    return TCL_ERROR;
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
    (void)winPtr;
}

void
TkWmMapWindow(TkWindow *winPtr)
{
    (void)winPtr;
}

void
TkWmUnmapWindow(TkWindow *winPtr)
{
    (void)winPtr;
}

void
TkWmDeadWindow(TkWindow *winPtr)
{
    (void)winPtr;
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
/* Wm command (stub — returns "not implemented" for all sub-commands) */
/* ------------------------------------------------------------------ */

int
Tk_WmObjCmd(void *clientData, Tcl_Interp *interp,
            int objc, Tcl_Obj *const objv[])
{
    (void)clientData; (void)objc; (void)objv;
    Tcl_SetObjResult(interp,
        Tcl_NewStringObj("wm not fully implemented on Plan 9", -1));
    return TCL_ERROR;
}
