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
    char *title;		/* "wm title", or NULL for the default. */
    /*
     * Gridding, as tkUnixWm.c keeps it. When gridWin is non-NULL the
     * width/height above are in GRID UNITS rather than pixels, and a
     * grid unit is widthInc/heightInc pixels; reqGridWidth/Height is the
     * grid size corresponding to the toplevel's own requested size.
     */
    TkWindow *gridWin;
    int reqGridWidth, reqGridHeight;
    int widthInc, heightInc;
    struct TkWmInfo *nextPtr;
} WmInfo;

#define WM_UPDATE_PENDING	1
#define WM_NEVER_MAPPED		2

static void WmUpdateGeometry(void *clientData);
static void WmGridToPixels(WmInfo *wmPtr, int gw, int gh,
			   int *widthPtr, int *heightPtr);
static void WmPixelsToGrid(WmInfo *wmPtr, int w, int h,
			   int *gwPtr, int *ghPtr);
MODULE_SCOPE void   TkP9EmbedGeometryRequest(TkWindow *winPtr, int w, int h);
MODULE_SCOPE Window TkP9EmbedParent(TkWindow *winPtr);

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

    /*
     * An embedded toplevel does not get to choose its own size: it
     * passes the request to the container and takes whatever the
     * container settles on.
     */
    if (winPtr->flags & TK_EMBEDDED) {
	TkP9EmbedGeometryRequest(winPtr,
		Tk_ReqWidth((Tk_Window) winPtr),
		Tk_ReqHeight((Tk_Window) winPtr));
	return;
    }

    /*
     * An explicit size is in grid units while the toplevel is gridded
     * ("-setgrid 1" on a listbox or a text widget), so convert here --
     * this is the one place a size leaves wmPtr for the screen.
     */
    if (wmPtr->width >= 0 && wmPtr->height >= 0) {
	WmGridToPixels(wmPtr, wmPtr->width, wmPtr->height, &width, &height);
    } else {
	width  = (wmPtr->width  >= 0) ? wmPtr->width
				      : Tk_ReqWidth((Tk_Window) winPtr);
	height = (wmPtr->height >= 0) ? wmPtr->height
				      : Tk_ReqHeight((Tk_Window) winPtr);
    }

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
/* Stacking order                                                      */
/* ------------------------------------------------------------------ */

/*
 * Tk keeps the stacking order of a window's children itself, in
 * parentPtr->childList, with later in the list meaning higher
 * (Tk_RestackWindow). Toplevels have no such list -- on X the server
 * stacks them -- so this port keeps them in dispPtr->firstWmPtr, in the
 * same convention: first is bottom, last is top.
 */

static WmInfo *
WmLast(TkDisplay *dispPtr)
{
    WmInfo *p = dispPtr->firstWmPtr;

    if (p == NULL)
	return NULL;
    while (p->nextPtr != NULL)
	p = p->nextPtr;
    return p;
}

static void
WmUnlink(TkDisplay *dispPtr, WmInfo *wmPtr)
{
    WmInfo *p;

    if (dispPtr->firstWmPtr == wmPtr) {
	dispPtr->firstWmPtr = wmPtr->nextPtr;
    } else {
	for (p = dispPtr->firstWmPtr; p != NULL; p = p->nextPtr) {
	    if (p->nextPtr == wmPtr) {
		p->nextPtr = wmPtr->nextPtr;
		break;
	    }
	}
    }
    wmPtr->nextPtr = NULL;
}

/* Put wmPtr immediately above afterPtr; a NULL afterPtr means bottom. */
static void
WmLinkAfter(TkDisplay *dispPtr, WmInfo *wmPtr, WmInfo *afterPtr)
{
    if (afterPtr == NULL) {
	wmPtr->nextPtr = dispPtr->firstWmPtr;
	dispPtr->firstWmPtr = wmPtr;
    } else {
	wmPtr->nextPtr = afterPtr->nextPtr;
	afterPtr->nextPtr = wmPtr;
    }
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
/* Embedding                                                           */
/* ------------------------------------------------------------------ */

/*
 * Embedding on Plan 9 is far simpler than on X, and the reason is that
 * there is only ever one process involved. tkUnixEmbed.c is 1200 lines
 * because the container and the embedded application are usually
 * separate X clients: it needs wrapper windows, a property protocol to
 * pass geometry between them, and an error handler in case the other
 * client dies mid-conversation.
 *
 * Here the "other application" is a child interpreter in this same
 * process, sharing this window table, so the whole thing reduces to:
 * create the embedded toplevel as a child of the container window, and
 * keep the two sizes in step.
 *
 * This was refused outright -- "-use not supported on Plan 9" -- which
 * is every test in safe.test and safePrimarySelection.test (34 of them),
 * because safe::loadTk always ends in "-use": with no -use argument it
 * builds a decorated toplevel with a "frame $w.c -container 1" and uses
 * that (library/safetk.tcl, tkTopLevel).
 */

typedef struct Container {
    Window    parent;		/* Window id of the container. */
    TkWindow *parentPtr;	/* The container, once it is known. */
    TkWindow *embeddedPtr;	/* The embedded toplevel, once it is known. */
    struct Container *nextPtr;
} Container;

static Container *firstContainerPtr = NULL;

static Container *
FindContainer(Window parent)
{
    Container *c;

    for (c = firstContainerPtr; c != NULL; c = c->nextPtr)
	if (c->parent == parent)
	    return c;
    return NULL;
}

static Container *
FindContainerByEmbedded(TkWindow *winPtr)
{
    Container *c;

    for (c = firstContainerPtr; c != NULL; c = c->nextPtr)
	if (c->embeddedPtr == winPtr)
	    return c;
    return NULL;
}

static Container *
GetContainer(Window parent)
{
    Container *c = FindContainer(parent);

    if (c == NULL) {
	c = (Container *) ckalloc(sizeof(Container));
	memset(c, 0, sizeof(Container));
	c->parent = parent;
	c->nextPtr = firstContainerPtr;
	firstContainerPtr = c;
    }
    return c;
}

static void
EmbedWindowDeleted(TkWindow *winPtr)
{
    Container *c, **prevPtrPtr;

    prevPtrPtr = &firstContainerPtr;
    for (c = firstContainerPtr; c != NULL; c = *prevPtrPtr) {
	if (c->embeddedPtr == winPtr)
	    c->embeddedPtr = NULL;
	if (c->parentPtr == winPtr) {
	    c->parentPtr = NULL;
	    c->parent = None;
	}
	if (c->parentPtr == NULL && c->embeddedPtr == NULL) {
	    *prevPtrPtr = c->nextPtr;
	    ckfree(c);
	} else {
	    prevPtrPtr = &c->nextPtr;
	}
    }
}

/* Give the embedded toplevel exactly the container's size. */
static void
EmbedFitToContainer(Container *containerPtr)
{
    TkWindow *embPtr = containerPtr->embeddedPtr;
    TkWindow *parPtr = containerPtr->parentPtr;
    int w, h;

    if (embPtr == NULL || embPtr->window == None || parPtr == NULL)
	return;
    w = Tk_Width((Tk_Window) parPtr);
    h = Tk_Height((Tk_Window) parPtr);
    if (w < 1) w = 1;
    if (h < 1) h = 1;
    if (embPtr->changes.width == w && embPtr->changes.height == h
	    && embPtr->changes.x == 0 && embPtr->changes.y == 0)
	return;
    embPtr->changes.x = embPtr->changes.y = 0;
    embPtr->changes.width  = w;
    embPtr->changes.height = h;
    XMoveResizeWindow(embPtr->display, embPtr->window, 0, 0,
	    (unsigned) w, (unsigned) h);
}

static void
ContainerEventProc(void *clientData, XEvent *eventPtr)
{
    TkWindow *winPtr = (TkWindow *) clientData;
    Container *containerPtr = FindContainer(winPtr->window);

    if (containerPtr == NULL)
	return;
    if (eventPtr->type == ConfigureNotify)
	EmbedFitToContainer(containerPtr);
    else if (eventPtr->type == DestroyNotify)
	EmbedWindowDeleted(winPtr);
}

static void
EmbeddedEventProc(void *clientData, XEvent *eventPtr)
{
    TkWindow *winPtr = (TkWindow *) clientData;

    if (eventPtr->type == DestroyNotify)
	EmbedWindowDeleted(winPtr);
}

/*
 * The embedded toplevel does not size itself: it asks the container,
 * and then takes whatever the container ends up being. This is what
 * WmUpdateGeometry defers to for a TK_EMBEDDED toplevel.
 */
void
TkP9EmbedGeometryRequest(TkWindow *winPtr, int width, int height)
{
    Container *containerPtr = FindContainerByEmbedded(winPtr);

    if (containerPtr == NULL || containerPtr->parentPtr == NULL)
	return;
    Tk_GeometryRequest((Tk_Window) containerPtr->parentPtr, width, height);
    EmbedFitToContainer(containerPtr);
}

/* The container window an embedded toplevel lives in, or None. */
Window
TkP9EmbedParent(TkWindow *winPtr)
{
    Container *containerPtr = FindContainerByEmbedded(winPtr);

    return (containerPtr != NULL) ? containerPtr->parent : None;
}

int
Tk_UseWindow(Tcl_Interp *interp, Tk_Window tkwin, const char *string)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    TkWindow *usePtr;
    Window parent;
    Container *containerPtr;

    if (winPtr->window != None) {
	Tcl_SetObjResult(interp, Tcl_NewStringObj(
		"can't modify container after widget is created", -1));
	Tcl_SetErrorCode(interp, "TK", "EMBED", "POST_CREATE", (char *)NULL);
	return TCL_ERROR;
    }
    if (TkpScanWindowId(interp, string, &parent) != TCL_OK)
	return TCL_ERROR;

    /*
     * Every window here belongs to this process, so a container we
     * cannot find is one that does not exist.
     */
    usePtr = (TkWindow *) Tk_IdToWindow(winPtr->display, parent);
    if (usePtr == NULL) {
	Tcl_SetObjResult(interp, Tcl_ObjPrintf(
		"couldn't create child of window \"%s\"", string));
	Tcl_SetErrorCode(interp, "TK", "EMBED", "NO_TARGET", (char *)NULL);
	return TCL_ERROR;
    }
    if (!(usePtr->flags & TK_CONTAINER)) {
	Tcl_SetObjResult(interp, Tcl_ObjPrintf(
		"window \"%s\" doesn't have -container option set",
		usePtr->pathName));
	Tcl_SetErrorCode(interp, "TK", "EMBED", "CONTAINER", (char *)NULL);
	return TCL_ERROR;
    }

    Tk_SetWindowVisual(tkwin, usePtr->visual, usePtr->depth,
	    usePtr->atts.colormap);
    Tk_CreateEventHandler(tkwin, StructureNotifyMask, EmbeddedEventProc,
	    winPtr);

    containerPtr = GetContainer(parent);
    containerPtr->embeddedPtr = winPtr;
    winPtr->flags |= TK_EMBEDDED;
    if (containerPtr->parentPtr != NULL) {
	winPtr->flags |= TK_BOTH_HALVES;
	containerPtr->parentPtr->flags |= TK_BOTH_HALVES;
    }
    return TCL_OK;
}

void
Tk_MakeContainer(Tk_Window tkwin)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    Container *containerPtr;

    /*
     * The window has to exist before it can be named as a -use target,
     * which is exactly what "winfo id $w.c" is about to do.
     */
    Tk_MakeWindowExist(tkwin);

    containerPtr = GetContainer(Tk_WindowId(tkwin));
    containerPtr->parentPtr = winPtr;
    winPtr->flags |= TK_CONTAINER;
    if (containerPtr->embeddedPtr != NULL) {
	winPtr->flags |= TK_BOTH_HALVES;
	containerPtr->embeddedPtr->flags |= TK_BOTH_HALVES;
    }

    Tk_CreateEventHandler(tkwin, StructureNotifyMask, ContainerEventProc,
	    winPtr);
    EmbedFitToContainer(containerPtr);
}

Tk_Window
Tk_GetOtherWindow(Tk_Window tkwin)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    Container *c;

    for (c = firstContainerPtr; c != NULL; c = c->nextPtr) {
	if (c->embeddedPtr == winPtr)
	    return (Tk_Window) c->parentPtr;
	if (c->parentPtr == winPtr)
	    return (Tk_Window) c->embeddedPtr;
    }
    return NULL;
}

void
TkpGetOtherWindow(TkWindow *winPtr)
{
    (void)winPtr;
}

int
TkpUseWindow(Tcl_Interp *interp, Tk_Window tkwin, const char *string)
{
    return Tk_UseWindow(interp, tkwin, string);
}

/*
 * Parse a window id, and *fail* on one that is not a number.
 *
 * strtoul answers 0 for "xyz" without complaint, so "toplevel .t -use
 * xyz" reached the lookup below and came back "couldn't create child of
 * window \"xyz\"" -- a plausible message for the wrong reason, and one
 * that would equally describe a real id naming a window that has gone.
 * tkUnixEmbed.c's version reports the ordinary Tcl integer error, which
 * is what embed-1.1 asks for.
 */
int
TkpScanWindowId(Tcl_Interp *interp, const char *string, Window *idPtr)
{
    Tcl_Obj *obj = Tcl_NewStringObj(string, TCL_INDEX_NONE);
    Tcl_WideInt value;
    int code;

    Tcl_IncrRefCount(obj);
    code = Tcl_GetWideIntFromObj(interp, obj, &value);
    Tcl_DecrRefCount(obj);
    if (code != TCL_OK)
	return TCL_ERROR;
    *idPtr = (Window) value;
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

    if (tkp9_debug())
	fprintf(stderr, "TkpWarpPointer: warpWindow=%s w=%lu warpX=%d warpY=%d\n",
		dispPtr->warpWindow? Tk_PathName(dispPtr->warpWindow): "(screen)",
		(unsigned long) w, (int) dispPtr->warpX, (int) dispPtr->warpY);

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
    wmPtr->widthInc  = 1;
    wmPtr->heightInc = 1;
    wmPtr->flags     = WM_NEVER_MAPPED;
    wmPtr->nextPtr   = NULL;
    /*
     * firstWmPtr is this port's stacking order for toplevels, running
     * bottom to top, so a new toplevel goes on the end -- on top, and in
     * creation order, which is what raise.test's first case checks.
     * (tkUnixWm.c prepends, but there the X server owns the stacking.)
     */
    WmLinkAfter(winPtr->dispPtr, wmPtr, WmLast(winPtr->dispPtr));
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
    WmInfo *wmPtr = winPtr->wmInfoPtr;

    if (wmPtr == NULL)
	return;
    WmUnlink(winPtr->dispPtr, wmPtr);
    if (wmPtr->flags & WM_UPDATE_PENDING)
	Tcl_CancelIdleCall(WmUpdateGeometry, winPtr);
    if (wmPtr->title != NULL)
	ckfree(wmPtr->title);
    winPtr->wmInfoPtr = NULL;
    ckfree(wmPtr);
}

void
TkWmSetClass(TkWindow *winPtr)
{
    (void)winPtr;
}

/*
 * "raise .a ?.b?" and "lower .a ?.b?" for toplevels. With no other
 * window named, Above means all the way to the top and Below all the way
 * to the bottom.
 */
void
TkWmRestackToplevel(TkWindow *winPtr, int aboveBelow, TkWindow *otherPtr)
{
    TkDisplay *dispPtr = winPtr->dispPtr;
    WmInfo *wmPtr = winPtr->wmInfoPtr, *otherWmPtr, *afterPtr;

    if (wmPtr == NULL)
	return;
    otherWmPtr = (otherPtr != NULL) ? otherPtr->wmInfoPtr : NULL;
    if (otherWmPtr == wmPtr)
	return;

    WmUnlink(dispPtr, wmPtr);
    if (otherWmPtr == NULL) {
	afterPtr = (aboveBelow == Above) ? WmLast(dispPtr) : NULL;
    } else if (aboveBelow == Above) {
	afterPtr = otherWmPtr;
    } else {
	/* Immediately below otherWmPtr: after whatever precedes it. */
	afterPtr = NULL;
	{
	    WmInfo *p;
	    for (p = dispPtr->firstWmPtr; p != NULL && p != otherWmPtr;
		    p = p->nextPtr)
		afterPtr = p;
	}
    }
    WmLinkAfter(dispPtr, wmPtr, afterPtr);

    if (aboveBelow == Above)
	XRaiseWindow(winPtr->display, winPtr->window);
    else
	XLowerWindow(winPtr->display, winPtr->window);
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

/*
 * Both of these were empty stubs, so "-setgrid 1" on a listbox or a text
 * widget did nothing at all. Gridding is not decoration: with it set,
 * "wm geometry" speaks in CHARACTERS rather than pixels, in both
 * directions, which is what listbox-4.7 checks --
 *
 *	listbox .l2 -font $fixed -width 30 -height 20 -setgrid 1
 *	wm geometry .			;# must say 30x20, not 190x308
 *	wm geometry . 26x15		;# 26 characters, not 26 pixels
 *
 * The convention is tkUnixWm.c's and is worth stating once: while
 * gridWin is non-NULL, wmPtr->width and wmPtr->height hold GRID UNITS,
 * and everything that touches them converts. Nothing else in this file
 * needs to know, because the conversion is confined to the three places
 * a size crosses that boundary -- WmUpdateGeometry on the way out to
 * pixels, and the "wm geometry" query and setter.
 */

/*
 * The pixel size may have moved even with an explicit "wm geometry" in
 * force, since that size is now read in different units -- so ask for an
 * update directly rather than through WmReqProc, which deliberately does
 * nothing when the size is explicit.
 */
static void
WmGridChanged(TkWindow *winPtr)
{
    WmInfo *wmPtr = winPtr->wmInfoPtr;

    if (!(wmPtr->flags & (WM_UPDATE_PENDING|WM_NEVER_MAPPED))) {
	Tcl_DoWhenIdle(WmUpdateGeometry, winPtr);
	wmPtr->flags |= WM_UPDATE_PENDING;
    }
}

/* Which toplevel does this window belong to? */
static TkWindow *
WmToplevelOf(TkWindow *winPtr)
{
    while (winPtr != NULL && !(winPtr->flags & TK_TOP_LEVEL))
	winPtr = winPtr->parentPtr;
    return winPtr;
}

/* Grid units -> pixels, for a size held in wmPtr->width/height. */
static void
WmGridToPixels(WmInfo *wmPtr, int gw, int gh, int *widthPtr, int *heightPtr)
{
    TkWindow *winPtr = wmPtr->winPtr;

    if (wmPtr->gridWin == NULL) {
	*widthPtr = gw;
	*heightPtr = gh;
	return;
    }
    *widthPtr  = Tk_ReqWidth((Tk_Window) winPtr)
	    + (gw - wmPtr->reqGridWidth) * wmPtr->widthInc;
    *heightPtr = Tk_ReqHeight((Tk_Window) winPtr)
	    + (gh - wmPtr->reqGridHeight) * wmPtr->heightInc;
}

/* Pixels -> grid units. */
static void
WmPixelsToGrid(WmInfo *wmPtr, int w, int h, int *gwPtr, int *ghPtr)
{
    TkWindow *winPtr = wmPtr->winPtr;

    if (wmPtr->gridWin == NULL) {
	*gwPtr = w;
	*ghPtr = h;
	return;
    }
    *gwPtr = wmPtr->reqGridWidth
	    + (w - Tk_ReqWidth((Tk_Window) winPtr)) / wmPtr->widthInc;
    *ghPtr = wmPtr->reqGridHeight
	    + (h - Tk_ReqHeight((Tk_Window) winPtr)) / wmPtr->heightInc;
}

void
Tk_SetGrid(Tk_Window tkwin, int reqWidth, int reqHeight,
           int gridWidth, int gridHeight)
{
    TkWindow *winPtr = WmToplevelOf((TkWindow *) tkwin);
    WmInfo *wmPtr;

    if (winPtr == NULL || (wmPtr = winPtr->wmInfoPtr) == NULL)
	return;
    if (gridWidth <= 0 || gridHeight <= 0)
	return;
    /*
     * Only one window may grid a toplevel. tkUnixWm.c takes the first and
     * ignores the rest rather than reporting an error -- two gridded
     * widgets in one toplevel is a layout mistake, not a Tcl one.
     */
    if (wmPtr->gridWin != NULL && wmPtr->gridWin != (TkWindow *) tkwin)
	return;

    if (wmPtr->gridWin != NULL
	    && wmPtr->reqGridWidth == reqWidth
	    && wmPtr->reqGridHeight == reqHeight
	    && wmPtr->widthInc == gridWidth
	    && wmPtr->heightInc == gridHeight)
	return;

    /*
     * An explicit "wm geometry" set BEFORE gridding is in pixels and has
     * to be reinterpreted, or it would silently become a character count
     * a few hundred times too large.
     */
    if (wmPtr->gridWin == NULL && wmPtr->width >= 0) {
	int gw, gh;

	wmPtr->gridWin = (TkWindow *) tkwin;
	wmPtr->reqGridWidth = reqWidth;
	wmPtr->reqGridHeight = reqHeight;
	wmPtr->widthInc = gridWidth;
	wmPtr->heightInc = gridHeight;
	WmPixelsToGrid(wmPtr, wmPtr->width, wmPtr->height, &gw, &gh);
	wmPtr->width = gw;
	wmPtr->height = gh;
    } else {
	wmPtr->gridWin = (TkWindow *) tkwin;
	wmPtr->reqGridWidth = reqWidth;
	wmPtr->reqGridHeight = reqHeight;
	wmPtr->widthInc = gridWidth;
	wmPtr->heightInc = gridHeight;
    }
    WmGridChanged(winPtr);
}

void
Tk_UnsetGrid(Tk_Window tkwin)
{
    TkWindow *winPtr = WmToplevelOf((TkWindow *) tkwin);
    WmInfo *wmPtr;
    int w, h;

    if (winPtr == NULL || (wmPtr = winPtr->wmInfoPtr) == NULL)
	return;
    if (wmPtr->gridWin != (TkWindow *) tkwin)
	return;

    if (wmPtr->width >= 0) {
	WmGridToPixels(wmPtr, wmPtr->width, wmPtr->height, &w, &h);
	wmPtr->width = w;
	wmPtr->height = h;
    }
    wmPtr->gridWin = NULL;
    wmPtr->widthInc = 1;
    wmPtr->heightInc = 1;
    wmPtr->reqGridWidth = 0;
    wmPtr->reqGridHeight = 0;
    WmGridChanged(winPtr);
}

/* ------------------------------------------------------------------ */
/* Root coordinates                                                   */
/* ------------------------------------------------------------------ */

/*
 * The walk up the parents STOPS AT A TOPLEVEL. A toplevel's parentPtr
 * is its logical Tk parent -- ".one"'s is "." -- and its changes.x/y
 * are already screen coordinates, so continuing past it adds the
 * parent's position to a window that is not inside it.
 *
 * This walked the whole chain, so every toplevel but "." was reported
 * at its own position plus "."'s. Invisible while "." sits at 0,0, and
 * event.test's setup_win_mousepointer opens with
 *
 *	wm geometry . +700+400; # root window out of our way
 *
 * which is what made it maximal: ".one" at +100+100 was reported at
 * 800,500. Everything that asks where a window is went wrong with it --
 * "winfo rootx/rooty" for any toplevel, "winfo containing", and through
 * Tk_CoordsToWindow the entire pointer machinery, since a hit test that
 * finds nothing hands NULL to Tk_UpdatePointer and no crossing is ever
 * generated. That is the ten event-9.* failures, all of them stuck in
 * that one setup line waiting for an <Enter> that could not come.
 *
 * An EMBEDDED toplevel is the exception and must keep walking, through
 * its container rather than its parent -- the container is where it
 * actually sits. tkUnixWm.c has to consult the X server when the
 * container belongs to another application; here Tk_GetOtherWindow can
 * always answer, because an embedded window and its container share
 * this process.
 */
void
Tk_GetRootCoords(Tk_Window tkwin, int *xPtr, int *yPtr)
{
    TkWindow *winPtr = (TkWindow *)tkwin;
    int x = 0, y = 0;

    while (winPtr != NULL) {
        x += winPtr->changes.x + winPtr->changes.border_width;
        y += winPtr->changes.y + winPtr->changes.border_width;
        if (winPtr->flags & TK_TOP_LEVEL) {
            Tk_Window otherPtr;

            if (!(winPtr->flags & TK_EMBEDDED))
                break;
            otherPtr = Tk_GetOtherWindow((Tk_Window) winPtr);
            if (otherPtr == NULL)
                break;
            winPtr = (TkWindow *) otherPtr;
            continue;
        }
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

    /*
     * An embedded toplevel is created inside its container rather than
     * at the root -- that substitution is the whole of embedding here,
     * since container and embedded window share this process and this
     * window table.
     */
    if (winPtr->flags & TK_EMBEDDED) {
        Window container = TkP9EmbedParent(winPtr);
        if (container != None)
            parent = container;
    }

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

/*
 * Where is the pointer? This is what "winfo pointerxy" answers, and it
 * was a stub returning 0,0 sitting next to an XQueryPointer that works
 * -- so the position was always 0,0 however the pointer got there.
 *
 * That is the whole of bind-34.1 and bind-34.2. Both warp the pointer
 * and then read it back with "winfo pointerxy", and it looked exactly
 * like a warp that had not happened: the warp is fine, the readback was
 * not. The tell was a real <Motion> reporting %X %Y as 397 124 while
 * winfo pointerxy said 0 0 in the next line.
 *
 * Structured as tkUnixWm.c's: ask about the root, and take the
 * coordinates relative to it, which are the screen coordinates.
 * A failed query answers -1,-1 rather than a plausible 0,0.
 */
void
TkGetPointerCoords(Tk_Window tkwin, int *xPtr, int *yPtr)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    Window root, child;
    int rootX, rootY;
    unsigned mask;

    if (XQueryPointer(winPtr->display,
	    RootWindow(winPtr->display, winPtr->screenNum),
	    &root, &child, &rootX, &rootY, xPtr, yPtr, &mask) != True) {
	*xPtr = -1;
	*yPtr = -1;
    }
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

/*
 * Which window is at this point on the screen?
 *
 * The Unix version asks the X server, walking down with
 * XTranslateCoordinates. There is no server here, and there does not
 * need to be one: this port already knows the whole tree and its
 * stacking order, which is what the server would be consulted for.
 *
 * Both loops walk forward and keep the LAST match, because both lists
 * run bottom to top -- childList by Tk's own convention, firstWmPtr by
 * this port's.
 *
 * This was a stub returning NULL, so "winfo containing" answered the
 * empty string for every point. raise.test decides the stacking order
 * entirely by asking what is on top at a given pixel, so all eleven of
 * its cases failed on that one line.
 */
static int
PointInWindow(TkWindow *winPtr, int rootX, int rootY)
{
    int x, y;

    Tk_GetRootCoords((Tk_Window) winPtr, &x, &y);
    return rootX >= x && rootX < x + Tk_Width((Tk_Window) winPtr)
	&& rootY >= y && rootY < y + Tk_Height((Tk_Window) winPtr);
}

Tk_Window
Tk_CoordsToWindow(int rootX, int rootY, Tk_Window tkwin)
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    TkDisplay *dispPtr = winPtr->dispPtr;
    TkWindow *topPtr = NULL, *bestPtr, *childPtr;
    WmInfo *wmPtr;

    for (wmPtr = dispPtr->firstWmPtr; wmPtr != NULL; wmPtr = wmPtr->nextPtr) {
	TkWindow *tl = wmPtr->winPtr;

	if (tl == NULL || tl->mainPtr == NULL || tl->window == None)
	    continue;
	if (!Tk_IsMapped((Tk_Window) tl))
	    continue;
	if (PointInWindow(tl, rootX, rootY))
	    topPtr = tl;
    }
    if (topPtr == NULL)
	return NULL;

    /*
     * Tk_CoordsToWindow reports only windows of this application; a
     * toplevel belonging to another interpreter hides what is under it
     * just as an alien window would.
     */
    if (topPtr->mainPtr != winPtr->mainPtr)
	return NULL;

    for (;;) {
	bestPtr = NULL;
	for (childPtr = topPtr->childList; childPtr != NULL;
		childPtr = childPtr->nextPtr) {
	    if (childPtr->window == None
		    || (childPtr->flags & TK_TOP_HIERARCHY)
		    || !Tk_IsMapped((Tk_Window) childPtr))
		continue;
	    if (PointInWindow(childPtr, rootX, rootY))
		bestPtr = childPtr;
	}
	if (bestPtr == NULL)
	    return (Tk_Window) topPtr;
	topPtr = bestPtr;
    }
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
            int w = winPtr->changes.width, h = winPtr->changes.height;

            /*
             * A gridded toplevel reports its size in characters, not
             * pixels -- that is the whole point of "-setgrid 1", and the
             * setter above already reads WxH in the same units.
             */
            if (wmPtr != NULL)
                WmPixelsToGrid(wmPtr, w, h, &w, &h);
            snprintf(buf, sizeof buf, "%dx%d+%d+%d", w, h,
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
        /*
         * rio owns the window frame, so nothing here displays a title.
         * That is no reason to forget it: "wm title" is a query as well
         * as a set, and answering the empty string to a title the caller
         * has just set is simply wrong. fontchooser-2.0/2.1 read the
         * title back to identify the dialog they raised.
         *
         * The default is the toplevel's own name, as Tk uses on X.
         */
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    wmPtr->title != NULL ? wmPtr->title
                                         : winPtr->nameUid, -1));
            return TCL_OK;
        }
        if (objc == 4) {
            const char *s = Tcl_GetString(objv[3]);
            size_t n = strlen(s) + 1;

            if (wmPtr->title != NULL)
                ckfree(wmPtr->title);
            wmPtr->title = (char *) ckalloc(n);
            memcpy(wmPtr->title, s, n);
            TkpWmSetTitle(winPtr, wmPtr->title);
            return TCL_OK;
        }
        Tcl_WrongNumArgs(interp, 2, objv, "window ?newTitle?");
        return TCL_ERROR;

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
