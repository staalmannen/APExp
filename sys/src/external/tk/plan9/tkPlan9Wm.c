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

void
TkSelClearSelection(Tcl_Interp *interp, XEvent *eventPtr)
{
    (void)interp; (void)eventPtr;
}

/* ------------------------------------------------------------------ */
/* Send command (no-op — Plan 9 has no X11 send)                     */
/* ------------------------------------------------------------------ */

int
TkpTestsendCmd(void *clientData, Tcl_Interp *interp,
               int objc, Tcl_Obj *const objv[])
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
