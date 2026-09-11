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
    int iconified;		/* "wm iconify"; distinct from withdrawn */
    /*
     * withdrawnExplicit is upstream's WM_WITHDRAWN flag, and it exists
     * only for transients: a transient follows its container's map
     * state (WmWaitMapProc below), UNLESS the caller withdrew it
     * itself, in which case the container coming back must not map it
     * again (wm-transient-6.2). "withdrawn" alone cannot say which of
     * the two withdrew it.
     */
    int withdrawnExplicit;
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

    /*
     * The rest of the "wm" subcommands. rio owns the frame and there is
     * no window manager, so almost none of these can have an effect on
     * the screen -- but that is not what they are for. Every one of them
     * is a QUERY as well as a set, and portable Tk code reads them back:
     * "wm transient" to find a dialog's master, "wm protocol" to find
     * the WM_DELETE_WINDOW handler, "wm overrideredirect" to decide
     * whether a menu is a real toplevel.
     *
     * Answering the empty string to a value the caller has just set is
     * simply wrong, and it is the same mistake "wm title" made on its
     * own before this (see the "four wm stubs that answered plausibly"
     * section in CLAUDE.md). Twenty-two subcommands fell through to
     * "default: return TCL_OK" here, which is why wm.test and
     * unixWm.test between them reported over three hundred failures of
     * the shape
     *
     *		got   {} {} {}
     *		want  {} {3 4 10 2} {}
     *
     * -- query, set, query back, unset, query again.
     *
     * Stored faithfully, reported faithfully, and acted on only where
     * there is something here to act on. The argument checking and the
     * error messages follow tkUnixWm.c's, because the tests check those
     * too and there is no reason to invent different ones.
     */
    int minAspectX, minAspectY;	/* wm aspect */
    int maxAspectX, maxAspectY;
    int hasAspect;
    char *clientMachine;	/* wm client */
    char *command;		/* wm command, kept as the list string */
    char *cmapWindows;		/* wm colormapwindows, ditto */
    int focusActive;		/* wm focusmodel: 1 active, 0 passive */
    char *leaderName;		/* wm group */
    char *iconName;		/* wm iconname -- NOT the title */
    char *iconBadge;		/* wm iconbadge */
    char *iconBitmap;		/* wm iconbitmap */
    char *iconMask;		/* wm iconmask */
    char *iconWindow;		/* wm iconwindow, as a path name */
    char *iconPhoto;		/* wm iconphoto, as given */
    int iconX, iconY, hasIconPos;
    int positionFrom;		/* 0 unset, 1 user, 2 program */
    int sizeFrom;
    char *transient;		/* wm transient, as a path name */
    struct WmProto *protoPtr;	/* wm protocol handlers */

    /*
     * "wm resizable" was answering a hardcoded "1 1" to every query,
     * which is the "wm title" mistake again: nothing here can stop a
     * user resizing a window, because rio owns the frame, but what the
     * caller set is still what a query has to report.
     * wm-resizable-2.1, unixWm-33.6.
     */
    int widthResizable, heightResizable;

    /*
     * A window named by someone else's "wm iconwindow". On X this is
     * handed to the window manager, which draws it while the toplevel is
     * iconified; rio has no icons, so nothing is drawn -- but the STATE
     * is still real and is what the tests ask about. Such a window
     * reports "icon" from "wm state" and refuses withdraw, deiconify and
     * iconify, because it is no longer its own to show or hide.
     * unixWm-8.*, 16.2, 23.4, 27.*, 38.2.
     */
    TkWindow *iconFor;

    /*
     * The other half of the same relationship: the window THIS toplevel
     * uses as its icon, if any. iconWindow above is the same thing as a
     * path name, kept in step with it because that is what the query
     * reports; this is the pointer, because setting the relationship has
     * to reach into the other window's WmInfo and clearing it has to
     * find the previous holder.
     */
    TkWindow *icon;

    /*
     * "wm transient" as a pointer, kept in step with the path name in
     * transient above for the same reason icon is: the loop check has to
     * walk the chain of containers, and a chain of path names cannot be
     * walked without a lookup at every step.
     */
    TkWindow *container;

    /*
     * The menubar, as "testmenubar window" and "$w configure -menu" set
     * it. On X a toplevel is reparented into a WRAPPER window owned by
     * tkUnixWm.c, and the menubar becomes a second child of that wrapper
     * ABOVE the toplevel: the wrapper keeps the position the toplevel
     * was asked for, the menubar takes the top menuHeight pixels of it,
     * and the toplevel itself is moved down by menuHeight. That is why
     * unixWm-49.2 wants a child placed at y=30 inside a toplevel at +0+0
     * to report rooty 62 once a 30-pixel menubar is set.
     *
     * THERE ARE NO WRAPPER WINDOWS HERE. A toplevel IS its window, and
     * dispPtr->firstWmPtr, Tk_CoordsToWindow and Tk_GetRootCoords are
     * all written that way. So the menubar stays an ordinary child of
     * its toplevel, at the toplevel's own origin, sized to its width:
     * it is created, sized, mapped and destroyed correctly, and it is
     * NOT outside the toplevel's rectangle the way X puts it.
     *
     * WHAT THAT COSTS, so it is not re-derived: the toplevel's contents
     * are not pushed down by menuHeight (unixWm-49.2 reports 32 where X
     * says 62), and a point above the toplevel does not hit the menubar,
     * because Tk_CoordsToWindow only descends into a toplevel whose
     * rectangle already contains the point (unixWm-50.5). Both follow
     * from the missing wrapper and neither can be fixed without one --
     * and a wrapper is not a small change here: every toplevel in the
     * port would gain a window, and the two coordinate conventions in
     * Tk_GetRootCoords (upstream has a whole extra arm for a menubar,
     * subtracting menuHeight and switching to the toplevel) would both
     * have to be honoured. Placing the menubar half-way -- out at the
     * root with screen coordinates in changes.x/y, which was written
     * first -- makes "winfo rootx" DOUBLE-COUNT for it, which is worse
     * than reporting it in the wrong place consistently.
     *
     * menuHeight is 0 exactly when there is no menubar, and every line
     * that acts on these fields is guarded on that, so a toplevel
     * without one follows precisely the path it followed before. That
     * matters more than usual here: this is the first change to
     * WmUpdateGeometry since the one that regressed unixEmbed-10.1.
     */
    TkWindow *menubar;
    int menuHeight;

    struct TkWmInfo *nextPtr;
} WmInfo;

/*
 * One "wm protocol" handler. A list rather than a hash table: there are
 * three of these on a busy toplevel.
 */
typedef struct WmProto {
    struct WmProto *nextPtr;
    char *name;
    char *command;
} WmProto;

/*
 * Replace a stored string, freeing the old one. A NULL or empty s
 * clears the slot, which is how every one of these subcommands spells
 * "unset" -- "wm client .t {}" and so on.
 */
static void
WmSetString(char **slot, const char *s)
{
    if (*slot != NULL) {
	ckfree(*slot);
	*slot = NULL;
    }
    if (s != NULL && *s != '\0') {
	size_t n = strlen(s) + 1;

	*slot = (char *) ckalloc(n);
	memcpy(*slot, s, n);
    }
}

/*
 * Report a stored string, or nothing at all when it is unset. Returning
 * the empty string and returning nothing are the same to Tcl here, but
 * writing it once keeps every query the same shape.
 */
static int
WmReturnString(Tcl_Interp *interp, const char *s)
{
    if (s != NULL)
	Tcl_SetObjResult(interp, Tcl_NewStringObj(s, -1));
    return TCL_OK;
}

#define WM_UPDATE_PENDING	1
#define WM_NEVER_MAPPED		2
/*
 * X's geometry has a SIGN as well as a value: "-10+5" means ten pixels
 * from the RIGHT edge, and "-0-0" is the bottom right corner. wmPtr->x
 * holds the magnitude and these two say which edge it is measured from,
 * as tkUnixWm.c does.
 *
 * Without them a negative offset was parsed by sscanf into a plain
 * integer and the sign was gone: every one of "wm geometry .t -0-0",
 * "+0-0" and "-0+0" was stored as 0,0 and read back as "+0+0", and a
 * window asked for at "-10+5" was placed ten pixels off the left edge
 * instead of ten in from the right. unixWm-2.4..2.9, 3.4..3.9, 44.7,
 * 44.8, 48.13.
 */
#define WM_NEGATIVE_X		4
#define WM_NEGATIVE_Y		8

static void WmScreenPosition(WmInfo *wmPtr, int width, int height,
	int *xPtr, int *yPtr);

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
    int width, height, x, y;

    if (wmPtr == NULL)
	return;
    wmPtr->flags &= ~WM_UPDATE_PENDING;

    /*
     * WORK IN THE UNITS min/max ARE EXPRESSED IN, and convert to pixels
     * at the very end.
     *
     * "wm minsize" and "wm maxsize" speak grid units whenever the
     * toplevel is gridded, exactly as "wm geometry" does -- that is
     * tkUnixWm.c's convention and the one the rest of this file
     * follows. Clamping AFTER the grid-to-pixel conversion compared a
     * grid count against a pixel count, so
     *
     *		wm grid .t 1 1 50 50
     *		wm geom .t 4x4			;# 4 grid units = 200px
     *		wm minsize .t 8 8		;# 8 grid units
     *
     * asked whether 200 < 8 and left the window at 4x4 (wm-minsize-2.2
     * and its neighbours). The note in CLAUDE.md said this was "inert
     * today, since the defaults are 1 and unlimited" -- true until the
     * tests that exercise it could run at all.
     *
     * Both helpers are the identity when gridWin is NULL, so the
     * ungridded case is unchanged and needs no branch of its own.
     */
    if (wmPtr->width >= 0 && wmPtr->height >= 0) {
	width  = wmPtr->width;
	height = wmPtr->height;
    } else {
	WmPixelsToGrid(wmPtr, Tk_ReqWidth((Tk_Window) winPtr),
		Tk_ReqHeight((Tk_Window) winPtr), &width, &height);
    }

    if (width  < wmPtr->minWidth)  width  = wmPtr->minWidth;
    if (height < wmPtr->minHeight) height = wmPtr->minHeight;
    if (wmPtr->maxWidth  > 0 && width  > wmPtr->maxWidth)
	width = wmPtr->maxWidth;
    if (wmPtr->maxHeight > 0 && height > wmPtr->maxHeight)
	height = wmPtr->maxHeight;

    WmGridToPixels(wmPtr, width, height, &width, &height);
    if (width  < 1) width  = 1;
    if (height < 1) height = 1;

    /*
     * An embedded toplevel does not get to choose its own size: it
     * passes the request to the container and takes whatever the
     * container settles on.
     *
     * THIS BRANCH USED TO SIT ABOVE THE BLOCK ABOVE and pass
     * Tk_ReqWidth/Tk_ReqHeight straight through, so an explicit
     *
     *		wm geometry .t1 70x300+10+20
     *
     * on an embedded toplevel was discarded before it could be used and
     * the window kept its -width/-height (unixEmbed-10.2). The request
     * an embedded window makes is its *wanted* size, and an explicit
     * "wm geometry" is exactly what overrides the requested one -- as
     * it does for every other toplevel three lines up. tkUnixWm.c's
     * UpdateGeometryInfo computes width/height first for the same
     * reason and only then asks the container.
     *
     * min/max and the grid conversion apply here too, which is the
     * other thing the early return skipped.
     */
    if (winPtr->flags & TK_EMBEDDED) {
	/*
	 * AN EMBEDDED TOPLEVEL HAS NO POSITION OF ITS OWN. It sits at its
	 * container's origin, so upstream zeroes x/y here -- "embedded
	 * windows are not allowed to move", UpdateGeometryInfo's own
	 * comment -- and clears the negative flags with them.
	 *
	 * This was invisible until "wm geometry" started reporting
	 * wmPtr->x/y rather than winPtr->changes.x/y, which is right for
	 * every other toplevel (a window asked for at "-0-0" must read
	 * back as "-0-0", not as the large positive coordinate it landed
	 * on). For an embedded one it meant "wm geometry .t1 +40+50"
	 * read back as +40+50 where X says +0+0: unixEmbed-10.1 and
	 * 10.2, which had been passing and broke on that change.
	 *
	 * Upstream gates this on TK_EMBEDDED|TK_BOTH_HALVES -- embedded
	 * AND the container in this same process -- because otherwise it
	 * cannot know where the other application put it. Here both
	 * halves always share the process, so TK_EMBEDDED alone is the
	 * same condition.
	 */
	wmPtr->x = wmPtr->y = 0;
	wmPtr->flags &= ~(WM_NEGATIVE_X | WM_NEGATIVE_Y);
	TkP9EmbedGeometryRequest(winPtr, width, height);
	return;
    }

    /*
     * A NEGATIVE OFFSET IS RESOLVED HERE, not when it was parsed: it is
     * measured from the far edge to the far edge of the window, so it
     * depends on the width and height that were just settled. "-10+5" on
     * a 1024-wide screen with a 121-wide window is x = 893, which is
     * what unixWm-44.7 and 44.8 read back through "winfo rootx".
     */
    WmScreenPosition(wmPtr, width, height, &x, &y);

    /*
     * A menubar spans the width of the toplevel it belongs to, so it has
     * to follow every resize. It stays a plain child at the toplevel's
     * own origin -- see the menubar note in WmInfo above for what that
     * costs and why the alternative was not taken.
     *
     * This runs before the no-change guard below on purpose: a menubar
     * can be set on a toplevel whose size is already settled, and the
     * guard would then return before the menubar had ever been placed.
     * Tk_MoveResizeWindow is silent for a move that changes nothing.
     */
    if (wmPtr->menuHeight > 0 && wmPtr->menubar != NULL)
	Tk_MoveResizeWindow((Tk_Window) wmPtr->menubar, 0, 0,
		width, wmPtr->menuHeight);

    if (width == winPtr->changes.width && height == winPtr->changes.height
	    && x == winPtr->changes.x && y == winPtr->changes.y)
	return;

    /*
     * On X the server answers a resize request with a ConfigureNotify and
     * Tk learns the new size from it. There is no server here, so record
     * it directly; XMoveResizeWindow still sends the ConfigureNotify, so
     * <Configure> bindings and the widgets that relayout on them work.
     */
    winPtr->changes.x      = x;
    winPtr->changes.y      = y;
    winPtr->changes.width  = width;
    winPtr->changes.height = height;
    if (winPtr->window != None)
	XMoveResizeWindow(winPtr->display, winPtr->window,
		x, y, (unsigned) width, (unsigned) height);
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

/* Ask for a geometry update at idle time, as the menubar code does. */
static void
WmScheduleUpdate(WmInfo *wmPtr)
{
    if (!(wmPtr->flags & (WM_UPDATE_PENDING|WM_NEVER_MAPPED))) {
	Tcl_DoWhenIdle(WmUpdateGeometry, wmPtr->winPtr);
	wmPtr->flags |= WM_UPDATE_PENDING;
    }
}

/* ------------------------------------------------------------------ */
/* Menubars                                                            */
/* ------------------------------------------------------------------ */

/*
 * TkUnixSetMenubar WAS AN EMPTY STUB, AND THAT FROZE THE TEST SUITE.
 *
 * It is what "testmenubar window .t .t.menu" and "$w configure -menu"
 * reach (tkUnixMenu.c:268), and the FIRST thing upstream's doc comment
 * promises is that the menubar "will be mapped". Doing nothing therefore
 * left the window unmapped -- and unixWm-50.5 is
 *
 *	testmenubar window .t .t.menu
 *	tkwait visibility .t.menu
 *
 * so it waited for a VisibilityNotify that could not arrive, forever.
 * That stopped unixWm.test dead and with it the last five files of the
 * suite (visual, winfo, winWm, wm, xmfbox), which is why runs 8 and 9
 * were prefixes rather than results.
 *
 * The tell was the shape of the wait, and it is worth keeping: the CPU
 * was loaded CONSTANTLY BUT LIGHTLY, which is this port's notifier
 * sleeping P9_POLL_US and finding nothing -- something waiting for an
 * event that will never come. A loop inside one Tk call pins a core
 * instead; that is what scrollbar-10.1 looked like, and it was a
 * genuinely different bug. THE SUSPECT NAMED FROM THE SCREENSHOT ALONE
 * (unixWm-50.3, the first test to put two Tk main windows in one
 * process) WAS WRONG; one "-verbose t" run named 50.5 in one line,
 * because -verbose t prints each test as it STARTS and 50.2, 50.3 and
 * 50.4 all reported before it. Ask the harness which test, before
 * reasoning about which mechanism.
 *
 * What is done here is upstream's function with the wrapper taken out;
 * see the menubar note in WmInfo above for why a sibling under the root
 * is the same picture as a second child of a wrapper.
 *
 * NOT DONE, deliberately: upstream also gives the menubar its own
 * colormap handling and resizes it from the WRAPPER's width rather than
 * the toplevel's. There is one visual here and the two widths are the
 * same thing, so neither has anything to do.
 */

static void
MenubarDestroyProc(void *clientData, XEvent *eventPtr)
{
    TkWindow *menubarPtr = (TkWindow *) clientData;
    WmInfo *wmPtr;

    if (eventPtr->type != DestroyNotify)
	return;
    wmPtr = menubarPtr->wmInfoPtr;
    if (wmPtr == NULL)
	return;
    wmPtr->menubar = NULL;
    wmPtr->menuHeight = 0;
    WmScheduleUpdate(wmPtr);
}

static void
MenubarReqProc(void *clientData, Tk_Window tkwin)
{
    WmInfo *wmPtr = (WmInfo *) clientData;

    wmPtr->menuHeight = Tk_ReqHeight(tkwin);
    if (wmPtr->menuHeight <= 0)
	wmPtr->menuHeight = 1;
    WmScheduleUpdate(wmPtr);
}

static const Tk_GeomMgr menubarMgrType = {
    "menubar",			/* name */
    MenubarReqProc,		/* requestProc */
    NULL			/* lostContentProc */
};

void
TkUnixSetMenubar(
    Tk_Window tkwin,		/* Toplevel the menubar belongs to. */
    Tk_Window menubar)		/* The menubar, or NULL to cancel one. */
{
    TkWindow *winPtr = (TkWindow *) tkwin;
    TkWindow *menubarPtr = (TkWindow *) menubar;
    WmInfo *wmPtr = winPtr->wmInfoPtr;

    /*
     * Can be called for something that is not a toplevel at all, in
     * which case there is no wm information and nothing to do.
     */
    if (wmPtr == NULL)
	return;

    if (wmPtr->menubar != NULL) {
	if (wmPtr->menubar == menubarPtr)
	    return;

	/*
	 * Put the old one back where it came from: unmap it, return it
	 * to its Tk parent, and stop managing it. Leaving it mapped
	 * where the new menubar is about to go would paint one over the
	 * other, and there is no server here to sort that out.
	 */
	wmPtr->menubar->wmInfoPtr = NULL;
	Tk_UnmapWindow((Tk_Window) wmPtr->menubar);
	Tk_DeleteEventHandler((Tk_Window) wmPtr->menubar,
		StructureNotifyMask, MenubarDestroyProc, wmPtr->menubar);
	Tk_ManageGeometry((Tk_Window) wmPtr->menubar, NULL, NULL);
    }

    wmPtr->menubar = menubarPtr;
    if (menubarPtr == NULL) {
	wmPtr->menuHeight = 0;
    } else {
	if (menubarPtr->flags & TK_TOP_LEVEL)
	    Tcl_Panic("TkUnixSetMenubar got bad menubar");

	/*
	 * A zero height would make the menubar invisible AND make
	 * menuHeight indistinguishable from "no menubar", which is the
	 * condition every guard in WmUpdateGeometry is written on.
	 */
	wmPtr->menuHeight = Tk_ReqHeight((Tk_Window) menubarPtr);
	if (wmPtr->menuHeight <= 0)
	    wmPtr->menuHeight = 1;

	Tk_MakeWindowExist(tkwin);
	Tk_MakeWindowExist((Tk_Window) menubarPtr);
	menubarPtr->wmInfoPtr = wmPtr;
	Tk_MoveResizeWindow((Tk_Window) menubarPtr, 0, 0,
		Tk_Width(tkwin), wmPtr->menuHeight);

	/*
	 * THE MAP IS THE POINT. Upstream's own doc comment leads with it,
	 * and leaving it out is what hung the suite: "tkwait visibility"
	 * waits for the VisibilityNotify that XMapWindow sends here.
	 */
	Tk_MapWindow((Tk_Window) menubarPtr);
	Tk_CreateEventHandler((Tk_Window) menubarPtr, StructureNotifyMask,
		MenubarDestroyProc, menubarPtr);
	Tk_ManageGeometry((Tk_Window) menubarPtr, &menubarMgrType, wmPtr);

	/*
	 * TK_REPARENTED is NOT set, and that is deliberate rather than an
	 * omission: it is upstream's mark for "this window is no longer
	 * under its Tk parent", which is exactly what is not true here.
	 * tkWindow.c:1913 and :2764 read it when deciding whether a
	 * window can be reached from its parent, and claiming a move that
	 * did not happen would make both of them wrong.
	 */
    }

    /*
     * The toplevel has to move down (or back up) by the menubar's
     * height, and WmUpdateGeometry is the one place that knows where it
     * goes. Do it now rather than at idle time: the caller is usually
     * "tkwait visibility" away from asking where things are.
     */
    WmUpdateNow(winPtr);
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

/*
 * "can't <verb> <name>: it is an icon for <other>", which withdraw,
 * deiconify and state share verbatim -- and which "iconify" does NOT,
 * because upstream quotes the two names there and not here. The tests
 * check the text, so the inconsistency is upstream's to keep:
 *
 *	unixWm-38.2  can't withdraw .t2: it is an icon for .t
 *	unixWm-23.4  can't iconify ".t2": it is an icon for ".t"
 *
 * The name reported is the one the CALLER WROTE (objv[2]), not the
 * window's path name; they differ whenever a window is named through
 * "." or a relative form.
 */
static int
WmIconForError(Tcl_Interp *interp, const char *verb, const char *code,
	Tcl_Obj *nameObj, WmInfo *wmPtr)
{
    Tcl_SetObjResult(interp, Tcl_ObjPrintf(
	    "can't %s %s: it is an icon for %s", verb,
	    Tcl_GetString(nameObj), Tk_PathName(wmPtr->iconFor)));
    Tcl_SetErrorCode(interp, "TK", "WM", code, "ICON", (char *) NULL);
    return TCL_ERROR;
}

/*
 * Break the icon relationship this toplevel holds, if it holds one. The
 * released window stays WITHDRAWN rather than reappearing: it was taken
 * off the screen when it became an icon, and upstream leaves it off --
 * a window that was only ever shown as somebody's icon has no position
 * of its own to come back to.
 */
static void
WmReleaseIcon(WmInfo *wmPtr)
{
    if (wmPtr->icon != NULL) {
	wmPtr->icon->wmInfoPtr->iconFor = NULL;
	wmPtr->icon->wmInfoPtr->withdrawn = 1;
	wmPtr->icon = NULL;
    }
    WmSetString(&wmPtr->iconWindow, NULL);
}

/*
 * "=wxh+x+y", with every part optional and the leading "=" optional too.
 * This is tkUnixWm.c's ParseGeometry, character by character, and it
 * replaces four sscanf attempts in a row.
 *
 * sscanf could not do this job. It cannot tell "+0" from "-0" once the
 * value is an int, so the sign was lost; it stops at the first
 * unconvertible character, so "+20+10z" parsed as "+20+10" and the
 * trailing junk was accepted (unixWm-48.10); and "=100x120" matched
 * nothing at all, though the "=" is part of the standard X geometry
 * syntax and optional by definition (unixWm-48.1).
 *
 * Nothing is written into wmPtr until the whole string has parsed, so a
 * bad specifier leaves the window exactly as it was.
 */
static int
WmParseGeometry(Tcl_Interp *interp, const char *string, TkWindow *winPtr)
{
    WmInfo *wmPtr = winPtr->wmInfoPtr;
    int x, y, width, height, flags;
    char *end;
    const char *p = string;

    if (*p == '=')
	p++;

    width  = wmPtr->width;
    height = wmPtr->height;
    x      = wmPtr->x;
    y      = wmPtr->y;
    flags  = wmPtr->flags;

    if (isdigit(UCHAR(*p))) {
	width = (int) strtoul(p, &end, 10);
	p = end;
	if (*p != 'x')
	    goto error;
	p++;
	if (!isdigit(UCHAR(*p)))
	    goto error;
	height = (int) strtoul(p, &end, 10);
	p = end;
    }

    if (*p != '\0') {
	flags &= ~(WM_NEGATIVE_X | WM_NEGATIVE_Y);
	if (*p == '-')
	    flags |= WM_NEGATIVE_X;
	else if (*p != '+')
	    goto error;
	p++;
	if (!isdigit(UCHAR(*p)) && *p != '-')
	    goto error;
	x = (int) strtol(p, &end, 10);
	p = end;
	if (*p == '-')
	    flags |= WM_NEGATIVE_Y;
	else if (*p != '+')
	    goto error;
	p++;
	if (!isdigit(UCHAR(*p)) && *p != '-')
	    goto error;
	y = (int) strtol(p, &end, 10);
	if (*end != '\0')	/* trailing junk */
	    goto error;
    }

    wmPtr->width  = width;
    wmPtr->height = height;
    wmPtr->x      = x;
    wmPtr->y      = y;
    wmPtr->flags  = flags;
    return TCL_OK;

  error:
    Tcl_SetObjResult(interp, Tcl_ObjPrintf(
	    "bad geometry specifier \"%s\"", string));
    Tcl_SetErrorCode(interp, "TK", "VALUE", "GEOMETRY", (char *) NULL);
    return TCL_ERROR;
}

/*
 * Where a window asked for at wmPtr->x/y actually goes, resolving a
 * negative offset against the screen. "-10" is ten pixels from the right
 * edge to the window's right edge, so the left edge is screenwidth minus
 * the width minus ten.
 */
static void
WmScreenPosition(WmInfo *wmPtr, int width, int height, int *xPtr, int *yPtr)
{
    TkWindow *winPtr = wmPtr->winPtr;

    *xPtr = (wmPtr->flags & WM_NEGATIVE_X)
	    ? WidthOfScreen(Tk_Screen((Tk_Window) winPtr)) - width - wmPtr->x
	    : wmPtr->x;
    *yPtr = (wmPtr->flags & WM_NEGATIVE_Y)
	    ? HeightOfScreen(Tk_Screen((Tk_Window) winPtr)) - height - wmPtr->y
	    : wmPtr->y;
}

/*
 * A DESTROYED CONTAINER LEAVES NO TRANSIENTS BEHIND. "wm transient" on
 * a dialog whose master has been destroyed must answer the empty string,
 * not the name of a window that is gone -- wm-transient-5.2, 5.3, 7.2 --
 * and the stored pointer would otherwise dangle. dispPtr->firstWmPtr is
 * every toplevel, so this is the whole search space.
 */
static void	WmUntrackContainer(TkWindow *winPtr, TkWindow *container);

static void
WmForgetTransientsOf(TkWindow *winPtr)
{
    WmInfo *p;

    for (p = winPtr->dispPtr->firstWmPtr; p != NULL; p = p->nextPtr) {
	if (p->container == winPtr) {
	    WmUntrackContainer(p->winPtr, winPtr);
	    p->container = NULL;
	    WmSetString(&p->transient, NULL);
	}
    }
}

/*
 * The container this window is a transient of, or NULL. One step of the
 * chain the loop check walks.
 */
static TkWindow *
WmTransientOf(TkWindow *winPtr)
{
    if (winPtr == NULL || winPtr->wmInfoPtr == NULL)
	return NULL;
    return winPtr->wmInfoPtr->container;
}

/*
 * A TRANSIENT TRACKS ITS CONTAINER'S MAP STATE, not just the state the
 * container happened to be in when "wm transient" was called. Upstream
 * registers this on the CONTAINER with StructureNotifyMask and passes
 * the TRANSIENT as client data (tkUnixWm.c's WmWaitMapProc); withdraw
 * the container and the dialog goes with it, deiconify it and the
 * dialog comes back. wm-transient-3.3, 4.3, 5.1, 6.2 and 8.1.
 *
 * The one exception is a transient the caller withdrew itself: the
 * container reappearing must not undo that (6.2), which is what
 * withdrawnExplicit is for.
 *
 * This port has no wrapper windows, so the events arrive on the
 * container's own window rather than on a wrapper -- which is exactly
 * why registering on the toplevel is right here and would not be on X.
 */
static void
WmWaitMapProc(void *clientData, XEvent *eventPtr)
{
    TkWindow *winPtr = (TkWindow *) clientData;
    WmInfo *wmPtr;

    if (winPtr == NULL || (wmPtr = winPtr->wmInfoPtr) == NULL)
	return;
    if (wmPtr->container == NULL)
	return;

    if (eventPtr->type == MapNotify) {
	if (wmPtr->withdrawnExplicit)
	    return;
	wmPtr->withdrawn = 0;
	wmPtr->iconified = 0;
	TkpWmSetState(winPtr, NormalState);
    } else if (eventPtr->type == UnmapNotify) {
	wmPtr->withdrawn = 1;
	TkpWmSetState(winPtr, WithdrawnState);
    }
}

/*
 * Attach or detach the tracking handler. Every place that changes
 * wmPtr->container goes through these two, so the handler and the
 * pointer cannot get out of step -- a stale handler would run with a
 * freed TkWindow as its client data.
 */
static void
WmTrackContainer(TkWindow *winPtr, TkWindow *container)
{
    Tk_CreateEventHandler((Tk_Window) container, StructureNotifyMask,
	    WmWaitMapProc, winPtr);
}

static void
WmUntrackContainer(TkWindow *winPtr, TkWindow *container)
{
    if (container == NULL)
	return;
    Tk_DeleteEventHandler((Tk_Window) container, StructureNotifyMask,
	    WmWaitMapProc, winPtr);
}

/*
 * Override-redirect lives in Tk_Attributes rather than in WmInfo -- see
 * the "wm overrideredirect" note -- so there is one answer to the
 * question and this is where to ask it.
 */
static int
WmIsOverrideRedirect(WmInfo *p)
{
    return p != NULL && p->winPtr != NULL
	    && Tk_Attributes((Tk_Window) p->winPtr)->override_redirect;
}

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
    if (w == NULL)
	w = winPtr;

    /*
     * A TOPLEVEL WITH NO WINDOW YET HAS NO WRAPPER YET. On X the wrapper
     * is created when the toplevel is first mapped, so testwrapper
     * answers the empty string before that (TestwrapperObjCmd sets no
     * result at all when this returns NULL). Returning the toplevel
     * regardless made it answer "0x0", which is not a window id -- it is
     * None wearing the format of one, the XLoadFont mistake in miniature.
     * unixWm-21.5 and 37.5 ask exactly that: is the wrapper empty before
     * the window exists.
     *
     * Safe for the one caller outside the test command: tkFocus.c:666
     * passes the result straight to TkpChangeFocus, which already
     * returns early for NULL *and* for a window whose id is None -- so
     * the focus path behaves identically either way.
     */
    if (w->window == None)
	return NULL;
    return w;
}

/*
 * A POSTED MENU IS OVERRIDE-REDIRECT, AND THAT IS TK'S OWN STATE HERE.
 *
 * This was an empty stub on the reasoning that rio owns the frame, so
 * there is no window manager to keep its hands off -- true, and beside
 * the point. `override_redirect` lives in Tk_Attributes(tkwin), generic
 * Tk reads it there, and "wm overrideredirect" reports it (see the "four
 * wm stubs that answered plausibly" note above, which records that the
 * port deliberately keeps it in the attributes rather than in WmInfo so
 * there is only one answer to the question).
 *
 * So the flag had a reader all along and nothing set it: unixWm-54.2
 * posts a menu and asks "wm overrideredirect .m", and got 0 where every
 * Tk says 1. The X call upstream makes on top of this -- telling the
 * server not to reparent -- is the part that genuinely has nothing to
 * do here.
 */
void
TkpMakeMenuWindow(Tk_Window tkwin, int transient)
{
    TkWindow *winPtr = (TkWindow *) tkwin;

    (void)transient;
    if (winPtr == NULL)
	return;
    winPtr->atts.override_redirect = True;
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

/*
 *----------------------------------------------------------------------
 *
 * TkpTestembedCmd --
 *
 *	Tk's own "testembed" test command: report the container list, one
 *	sublist per container, as {parent-id parent-path wrapper embedded-
 *	path}. "testembed all" prints the real window ids where the plain
 *	form prints "XXX", because the ids vary from run to run.
 *
 *	IT WAS A STUB THAT RAISED "testembed not supported on Plan 9",
 *	which is the XLoadFont mistake one more time and the third
 *	instance of it in this port: **answering "cannot" where the truth
 *	is "here it is".** Embedding has worked here since Tk_UseWindow
 *	was written, and the list this command exists to print is
 *	firstContainerPtr, ten lines up. The refusal is what made
 *	unixEmbed-1.7 and -2.3 fail -- both build two containers and two
 *	embedded toplevels entirely in this process, do nothing else, and
 *	ask for exactly this.
 *
 *	Three of upstream's four fields are in the Container above. The
 *	fourth is the WRAPPER, and there is none here -- so the empty
 *	string this prints for it is not an approximation: it is the same
 *	thing upstream prints when containerPtr->wrapper is None.
 *
 *	The structure follows unix/tkUnixEmbed.c line for line, including
 *	its one oddity: embeddedInterp and parentInterp are declared
 *	OUTSIDE the loop and assigned only when the pointer is non-NULL,
 *	so a container missing one of them is filtered against whatever
 *	the previous container had. That is upstream's behaviour and the
 *	expected strings were written against it, so it is reproduced
 *	rather than tidied -- a test command's contract is to match the
 *	other implementations, not to be better than them.
 *
 *----------------------------------------------------------------------
 */

int
TkpTestembedCmd(
    void *dummy,
    Tcl_Interp *interp,
    Tcl_Size objc,
    Tcl_Obj *const objv[])
{
    Container *containerPtr;
    Tcl_DString dString;
    Tcl_Interp *embeddedInterp = NULL, *parentInterp = NULL;
    char buffer[50];
    int all;
    (void)dummy;

    all = (objc > 1) && (strcmp(Tcl_GetString(objv[1]), "all") == 0);

    Tcl_DStringInit(&dString);
    for (containerPtr = firstContainerPtr; containerPtr != NULL;
	    containerPtr = containerPtr->nextPtr) {
	if (containerPtr->embeddedPtr != NULL)
	    embeddedInterp = containerPtr->embeddedPtr->mainPtr->interp;
	if (containerPtr->parentPtr != NULL)
	    parentInterp = containerPtr->parentPtr->mainPtr->interp;

	/*
	 * A container belonging to neither this interpreter's embedded
	 * half nor its container half is none of this interpreter's
	 * business -- that is how the child-interpreter tests tell the
	 * two sides apart.
	 */
	if (embeddedInterp != interp && parentInterp != interp)
	    continue;

	Tcl_DStringStartSublist(&dString);

	/* The container's window id. */
	if (containerPtr->parent == None) {
	    Tcl_DStringAppendElement(&dString, "");
	} else if (all) {
	    snprintf(buffer, sizeof(buffer), "0x%lx",
		    (unsigned long) containerPtr->parent);
	    Tcl_DStringAppendElement(&dString, buffer);
	} else {
	    Tcl_DStringAppendElement(&dString, "XXX");
	}

	/* The container's path name, if it belongs to this interpreter. */
	if (containerPtr->parentPtr == NULL || parentInterp != interp)
	    Tcl_DStringAppendElement(&dString, "");
	else
	    Tcl_DStringAppendElement(&dString,
		    containerPtr->parentPtr->pathName);

	/*
	 * The wrapper. Always empty: on X a toplevel is reparented into
	 * a wrapper window owned by tkUnixWm.c, and there are none here
	 * -- a toplevel IS its window. Upstream prints the empty string
	 * for a container whose wrapper is None, so this is its answer
	 * and not a stand-in for one.
	 */
	Tcl_DStringAppendElement(&dString, "");

	/* The embedded window's path name, likewise. */
	if (containerPtr->embeddedPtr == NULL || embeddedInterp != interp)
	    Tcl_DStringAppendElement(&dString, "");
	else
	    Tcl_DStringAppendElement(&dString,
		    containerPtr->embeddedPtr->pathName);

	Tcl_DStringEndSublist(&dString);
    }
    Tcl_DStringResult(interp, &dString);
    return TCL_OK;
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
    wmPtr->widthResizable  = 1;	/* both default to true, as on X */
    wmPtr->heightResizable = 1;
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

	/*
	 * A TRANSIENT IS NOT MAPPED WHILE ITS MASTER IS NOT, AND THE
	 * TEST IS MADE HERE RATHER THAN WHEN "wm transient" WAS CALLED.
	 *
	 * The note under Tk_WmObjCmd says only the state at the moment
	 * of the call is honoured, and that upstream additionally
	 * *tracks* the master afterwards. Both are true, but they
	 * skipped the case in between, which is upstream's own and is
	 * three lines: `toplevel .subject` is created unmapped, made
	 * transient to a withdrawn master, and mapped by the idle queue
	 * afterwards. At the moment of the `wm transient` there was
	 * nothing to unmap -- TK_MAPPED was not set yet, so
	 * TkpWmSetState found nothing to do -- and the map then went
	 * ahead regardless. `wm state` said withdrawn while
	 * `winfo ismapped` said 1 (wm-transient-3.1, 4.1).
	 *
	 * tkUnixWm.c's TkWmMapWindow does it in the same place, guarded
	 * on containerPtr and phrased the same way: "Don't map a
	 * transient if the container is not mapped."
	 */
	if (wmPtr->container != NULL
		&& !Tk_IsMapped((Tk_Window) wmPtr->container))
	    wmPtr->withdrawn = 1;
    }

    /*
     * A withdrawn toplevel is not mapped, whoever asked. Upstream
     * returns here on hints.initial_state == WithdrawnState; this port
     * keeps the same fact in wmPtr->withdrawn, which "wm deiconify"
     * clears before it asks for the map, so the ordinary path is
     * unaffected.
     */
    if (wmPtr != NULL && wmPtr->withdrawn)
	return;

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

    /*
     * THE MENUBAR HOLDS A POINTER TO THIS WmInfo AND MUST NOT OUTLIVE IT.
     * Upstream's TkWmDeadWindow opens with exactly this line, and the
     * reason is not obvious from unixWm.test, where the menubar happens
     * to be a CHILD of its toplevel (.t.menu) and so is already gone by
     * the time this runs -- generic Tk destroys the whole childList
     * before reaching here (tkWindow.c:1485).
     *
     * The case it is for is "$w configure -menu .menubar", which is the
     * ordinary way a program sets one: tkUnixMenu.c hands us the MENU
     * WIDGET, which is usually a sibling rather than a child. Nothing
     * then destroys it with the toplevel, so without this the ckfree
     * below leaves menubarPtr->wmInfoPtr pointing at freed memory, and
     * MenubarDestroyProc later writes wmPtr->menubar through it and
     * reads wmPtr->winPtr back out to schedule an update.
     *
     * Same shape as the icon relationship below, and the same reason it
     * is worth the line: on this allocator a freed WmInfo stays readable
     * and writable, so nothing fails until the garbage read out of it is
     * dereferenced, somewhere else entirely.
     */
    if (wmPtr->menubar != NULL) {
	TkWindow *menubarPtr = wmPtr->menubar;

	wmPtr->menubar = NULL;
	wmPtr->menuHeight = 0;
	menubarPtr->wmInfoPtr = NULL;
	Tk_DestroyWindow((Tk_Window) menubarPtr);
    }

    WmUnlink(winPtr->dispPtr, wmPtr);
    if (wmPtr->flags & WM_UPDATE_PENDING)
	Tcl_CancelIdleCall(WmUpdateGeometry, winPtr);
    if (wmPtr->title != NULL)
	ckfree(wmPtr->title);

    /*
     * BOTH HALVES OF THE ICON RELATIONSHIP POINT AT A WmInfo, so either
     * window going away must clear the other end or the survivor is left
     * holding a freed pointer -- and on this allocator a freed WmInfo
     * stays readable, so the first thing that would actually fail is the
     * pathName chase inside an error message, a long way from here.
     * (See the "wild pointer shows at the first double indirection" note
     * in CLAUDE.md; this is the same shape as TkpDeleteFont was.)
     */
    WmReleaseIcon(wmPtr);
    WmForgetTransientsOf(winPtr);
    WmUntrackContainer(winPtr, wmPtr->container);
    wmPtr->container = NULL;
    if (wmPtr->iconFor != NULL && wmPtr->iconFor->wmInfoPtr != NULL) {
	wmPtr->iconFor->wmInfoPtr->icon = NULL;
	WmSetString(&wmPtr->iconFor->wmInfoPtr->iconWindow, NULL);
	wmPtr->iconFor = NULL;
    }

    /*
     * Everything "wm" stores. Each of these is a ckalloc'd string, so a
     * toplevel created and destroyed in a loop -- which the test suite
     * does constantly -- would otherwise leak one per subcommand used.
     */
    WmSetString(&wmPtr->clientMachine, NULL);
    WmSetString(&wmPtr->command, NULL);
    WmSetString(&wmPtr->cmapWindows, NULL);
    WmSetString(&wmPtr->leaderName, NULL);
    WmSetString(&wmPtr->iconName, NULL);
    WmSetString(&wmPtr->iconBadge, NULL);
    WmSetString(&wmPtr->iconBitmap, NULL);
    WmSetString(&wmPtr->iconMask, NULL);
    WmSetString(&wmPtr->iconWindow, NULL);
    WmSetString(&wmPtr->iconPhoto, NULL);
    WmSetString(&wmPtr->transient, NULL);
    while (wmPtr->protoPtr != NULL) {
	WmProto *p = wmPtr->protoPtr;

	wmPtr->protoPtr = p->nextPtr;
	WmSetString(&p->name, NULL);
	WmSetString(&p->command, NULL);
	ckfree(p);
    }

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
	/*
	 * AN OVERRIDE-REDIRECT TOPLEVEL STAYS ON TOP. On X the window
	 * manager keeps them there and an ordinary "raise" cannot get
	 * above one (wm-stackorder-5.2). There is no window manager
	 * here, so this port has to hold the rule itself -- and it is
	 * not only a test: TkpMakeMenuWindow marks every posted menu
	 * override-redirect, so without this a "raise" on the window a
	 * menu belongs to buries the menu under it.
	 */
	if (afterPtr != NULL && !WmIsOverrideRedirect(wmPtr)) {
	    WmInfo *p, *below = NULL;

	    for (p = dispPtr->firstWmPtr; p != NULL; p = p->nextPtr)
		if (!WmIsOverrideRedirect(p))
		    below = p;
	    afterPtr = below;
	}
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

/*
 * Count, then collect, the toplevels in winPtr's family that would
 * appear in a stacking order: mapped, a toplevel, and not embedded.
 * Upstream's TkWmStackorderToplevelWrapperMap does the same walk into a
 * hash table keyed by the X wrapper window; there are no wrappers here,
 * so an array and a linear scan are enough for the handful of toplevels
 * a program has.
 */
static int
WmStackCount(TkWindow *winPtr)
{
    TkWindow *childPtr;
    int n = 0;

    if (Tk_IsMapped((Tk_Window) winPtr) && Tk_IsTopLevel(winPtr)
            && !Tk_IsEmbedded(winPtr))
	n = 1;
    for (childPtr = winPtr->childList; childPtr != NULL;
	    childPtr = childPtr->nextPtr)
	n += WmStackCount(childPtr);
    return n;
}

static void
WmStackCollect(TkWindow *winPtr, TkWindow **list, int *np)
{
    TkWindow *childPtr;

    if (Tk_IsMapped((Tk_Window) winPtr) && Tk_IsTopLevel(winPtr)
            && !Tk_IsEmbedded(winPtr))
	list[(*np)++] = winPtr;
    for (childPtr = winPtr->childList; childPtr != NULL;
	    childPtr = childPtr->nextPtr)
	WmStackCollect(childPtr, list, np);
}

/*
 * TkWmStackorderToplevel --
 *
 *	The toplevels under parentPtr, bottom of the stacking order first,
 *	NULL-terminated; the caller ckfrees it. NULL means failure, which
 *	is not the same as an empty list and is what "wm stackorder"
 *	reports as an error.
 *
 *	THIS WAS A STUB RETURNING NULL, and the note in CLAUDE.md claiming
 *	it was implemented was wrong -- read from a grep of the name
 *	rather than the body. That mattered: `wm stackorder` was rewritten
 *	to call it, so 31 of wm.test's 32 stackorder tests went from
 *	answering an empty list to raising an error.
 *
 *	On X this needs XQueryTree, because the server owns the order and
 *	a window manager may have reparented every toplevel into a frame.
 *	Here this port owns it: dispPtr->firstWmPtr is the list, bottom
 *	first (see the stacking-order section in CLAUDE.md), which is
 *	already the order this function must return. So the whole job is
 *	to intersect that list with the family under parentPtr.
 */
TkWindow **
TkWmStackorderToplevel(TkWindow *parentPtr)
{
    TkWindow **windows, **found;
    WmInfo *wmPtr;
    int n, i, k = 0, got = 0;

    n = WmStackCount(parentPtr);
    windows = (TkWindow **) ckalloc((n + 1) * sizeof *windows);
    if (n == 0) {
	windows[0] = NULL;
	return windows;
    }
    found = (TkWindow **) ckalloc(n * sizeof *found);
    WmStackCollect(parentPtr, found, &got);

    for (wmPtr = parentPtr->dispPtr->firstWmPtr; wmPtr != NULL;
	    wmPtr = wmPtr->nextPtr)
	for (i = 0; i < got; i++)
	    if (found[i] == wmPtr->winPtr) {
		windows[k++] = found[i];
		found[i] = NULL;		/* once only */
		break;
	    }

    /*
     * Anything mapped but absent from firstWmPtr, in discovery order.
     * There should be none -- every toplevel is linked in by
     * TkWmNewWindow -- but returning a SHORT list would be a silently
     * wrong stacking order, and "wm stackorder ." answering the empty
     * list is one of the cases the tests check by name.
     */
    for (i = 0; i < got; i++)
	if (found[i] != NULL)
	    windows[k++] = found[i];

    windows[k] = NULL;
    ckfree(found);
    return windows;
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
     * AN EXPLICIT "wm geometry" SET BEFORE GRIDDING IS FORGOTTEN, NOT
     * CONVERTED -- and the difference is the whole of unixWm-40.2.
     *
     * The concern is real: a size stored in pixels would otherwise be
     * read back as a character count a few hundred times too large. But
     * converting it, which is what this did, is upstream's *rejected*
     * answer, and tkUnixWm.c says why in its own comment: "there's no
     * easy way to translate them to grid units since the new requested
     * size of the top-level window in pixels may not yet have been
     * registered yet (it may filter up the hierarchy in DoWhenIdle
     * handlers)."
     *
     * That is exactly what 40.2 does -- "wm geometry .t 200x100", then
     * "-setgrid 1" on a 20x20 listbox that has not yet propagated its
     * request. Converting gave 200/widthInc x 100/heightInc = 17x4,
     * a thoroughly plausible wrong answer; discarding it lets
     * WmUpdateGeometry fall back to the requested size, which is the
     * listbox's own 20x20.
     *
     * The WM_NEVER_MAPPED half is upstream's too: a size given before
     * the window was ever mapped is left alone, on the assumption that
     * it was meant as grid units and merely arrived early.
     *
     * **The note this file used to carry -- "Tk_SetGrid must
     * reinterpret a size set in pixels" -- was a fix reasoned out
     * rather than read.** Upstream had already considered it and
     * written down why it does not work.
     */
    if (wmPtr->gridWin == NULL && !(wmPtr->flags & WM_NEVER_MAPPED)) {
	wmPtr->width = -1;
	wmPtr->height = -1;
    }

    wmPtr->gridWin = (TkWindow *) tkwin;
    wmPtr->reqGridWidth = reqWidth;
    wmPtr->reqGridHeight = reqHeight;
    wmPtr->widthInc = gridWidth;
    wmPtr->heightInc = gridHeight;
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
/* Focus claim / key redirect, for embedded toplevels                  */
/* ------------------------------------------------------------------ */

/*
 * Someone focused a window inside an EMBEDDED toplevel while the focus
 * is elsewhere, so the embedded half has to ask the container for it.
 * The comment here used to say "no embedding on Plan 9" and the body
 * was empty -- left over from before Tk_UseWindow was implemented (see
 * the embedding section in CLAUDE.md).
 *
 * unix/tkUnixEmbed.c cannot do this directly, because on X the
 * container is usually a different client: it sends the container a
 * synthetic FocusIn with mode EMBEDDED_APP_WANTS_FOCUS and detail
 * `force`, and generic Tk turns that back into a TkSetFocusWin on the
 * receiving side (tkFocus.c:295). The event is the round trip, not the
 * mechanism.
 *
 * Here the two halves share this process and this window table, so the
 * round trip is the identity: call TkSetFocusWin on the container. That
 * is the same reduction the rest of this port's embedding makes.
 *
 * Found by unixEmbed-8.2, which loads Tk into a child *interpreter* --
 * so it is one of the few embedding tests that does not need a second
 * wish or tktest, and therefore one of the few that can pass here.
 */
void
TkpClaimFocus(TkWindow *topLevelPtr, int force)
{
    TkWindow *containerPtr;

    if (!(topLevelPtr->flags & TK_EMBEDDED))
	return;
    containerPtr = (TkWindow *) Tk_GetOtherWindow((Tk_Window) topLevelPtr);
    if (containerPtr == NULL)
	return;
    TkSetFocusWin(containerPtr, force);
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
     * Every subcommand needs a window, and the message for leaving it
     * out is the GENERIC one -- "wm option window ?arg ...?" -- not the
     * per-subcommand usage. Upstream checks this after resolving the
     * index and before dispatching, and each subcommand's own
     * Tcl_WrongNumArgs is then only ever reached with a window present.
     *
     * Without it every "wm <sub>" with no window answered
     * "wm stackorder window ?isabove|isbelow window?" and so on, which
     * is one failing test per subcommand -- the wm-*-1.1 "usage" cases.
     */
    if (objc < 3) {
        Tcl_WrongNumArgs(interp, 1, objv, "option window ?arg ...?");
        return TCL_ERROR;
    }

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

    /*
     * A NON-TOPLEVEL IS REFUSED ONCE, HERE, for every subcommand but the
     * two whose whole job is to take one. Upstream does exactly this,
     * immediately after resolving the window and before dispatching.
     *
     * This used not to happen at all: wmPtr was simply NULL for such a
     * window and every case below guarded on it and returned TCL_OK, so
     * "wm geometry .b" on a button answered "1x1+0+0" and "wm iconbadge
     * .f 3" on a frame succeeded. A believable answer to a question that
     * should have been refused -- the same family as "wm title" being
     * write-only. wm-1.5, unixWm-11.4, wm-iconbadge-1.2.
     *
     * Having it here is also what lets the cases below stop testing
     * wmPtr for NULL: past this point a resolved window always has one.
     */
    if (winPtr != NULL && !Tk_IsTopLevel(winPtr)
            && index != OPT_MANAGE && index != OPT_FORGET) {
        Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                "window \"%s\" isn't a top-level window", winPtr->pathName));
        Tcl_SetErrorCode(interp, "TK", "LOOKUP", "TOPLEVEL", winPtr->pathName,
                (char *) NULL);
        return TCL_ERROR;
    }

    switch (index) {
    case OPT_GEOMETRY:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?newGeometry?");
            return TCL_ERROR;
        }
        if (objc == 3) {
            char buf[TCL_INTEGER_SPACE * 4 + 4];
            int w = winPtr->changes.width, h = winPtr->changes.height;

            /*
             * A gridded toplevel reports its size in characters, not
             * pixels -- that is the whole point of "-setgrid 1", and the
             * setter above already reads WxH in the same units.
             */
            WmPixelsToGrid(wmPtr, w, h, &w, &h);
            /*
             * THE POSITION IS wmPtr's, WITH ITS SIGN, not changes.x/y.
             * changes.x/y is where the window ended up on the screen; a
             * window asked for at "-0-0" is at some large positive
             * coordinate there, and reporting that would not be
             * something the caller could hand back to "wm geometry".
             */
            snprintf(buf, sizeof buf, "%dx%d%c%d%c%d", w, h,
                    (wmPtr->flags & WM_NEGATIVE_X) ? '-' : '+', wmPtr->x,
                    (wmPtr->flags & WM_NEGATIVE_Y) ? '-' : '+', wmPtr->y);
            Tcl_SetObjResult(interp, Tcl_NewStringObj(buf, -1));
            return TCL_OK;
        }
        {
            const char *s = Tcl_GetString(objv[3]);

            if (*s == '\0') {		/* revert to the requested size */
                wmPtr->width = wmPtr->height = -1;
                WmUpdateNow(winPtr);
                return TCL_OK;
            }
            if (WmParseGeometry(interp, s, winPtr) != TCL_OK)
                return TCL_ERROR;
            WmUpdateNow(winPtr);
        }
        return TCL_OK;

    case OPT_MINSIZE:
    case OPT_MAXSIZE: {
        int w, h;

        if (objc != 3 && objc != 5) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?width height?");
            return TCL_ERROR;
        }
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf("%d %d",
                    (index == OPT_MINSIZE) ? wmPtr->minWidth : wmPtr->maxWidth,
                    (index == OPT_MINSIZE) ? wmPtr->minHeight : wmPtr->maxHeight));
            return TCL_OK;
        }
        /*
         * A SCREEN DISTANCE, not an integer. "wm minsize . 10c" is legal
         * and so is the error message the tests check -- "expected screen
         * distance but got ..." rather than "expected integer but got
         * ...". wm-minsize-1.4/1.5, wm-maxsize-1.4/1.5.
         */
        if (Tk_GetPixelsFromObj(interp, (Tk_Window) winPtr, objv[3], &w)
                    != TCL_OK
                || Tk_GetPixelsFromObj(interp, (Tk_Window) winPtr, objv[4], &h)
                    != TCL_OK)
            return TCL_ERROR;
        if (index == OPT_MINSIZE) {
            wmPtr->minWidth = w; wmPtr->minHeight = h;
        } else {
            wmPtr->maxWidth = w; wmPtr->maxHeight = h;
        }
        WmUpdateNow(winPtr);
        return TCL_OK;
    }

    case OPT_WITHDRAW:
        if (objc != 3) {
            Tcl_WrongNumArgs(interp, 2, objv, "window");
            return TCL_ERROR;
        }
        if (wmPtr->iconFor != NULL)
            return WmIconForError(interp, "withdraw", "WITHDRAW", objv[2],
                    wmPtr);
        wmPtr->withdrawn = 1;
        wmPtr->withdrawnExplicit = 1;
        TkpWmSetState(winPtr, WithdrawnState);
        return TCL_OK;

    case OPT_DEICONIFY:
        if (objc != 3) {
            Tcl_WrongNumArgs(interp, 2, objv, "window");
            return TCL_ERROR;
        }
        if (wmPtr->iconFor != NULL)
            return WmIconForError(interp, "deiconify", "DEICONIFY", objv[2],
                    wmPtr);
        if (winPtr->flags & TK_EMBEDDED) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                    "can't deiconify %s: it is an embedded window",
                    winPtr->pathName));
            Tcl_SetErrorCode(interp, "TK", "WM", "DEICONIFY", "EMBEDDED",
                    (char *) NULL);
            return TCL_ERROR;
        }
        /*
         * DEICONIFY CLEARS ICONIFIED AS WELL AS WITHDRAWN. It used to
         * clear only the latter, so "wm iconify .t; wm deiconify .t;
         * wm state .t" answered "iconic" -- the window was shown again
         * and went on reporting that it was not. unixWm-16.3, 35.3,
         * wm-state-2.15, 2.17.
         */
        wmPtr->withdrawn = 0;
        wmPtr->withdrawnExplicit = 0;
        wmPtr->iconified = 0;
        TkpWmSetState(winPtr, NormalState);
        return TCL_OK;

    case OPT_STATE:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?state?");
            return TCL_ERROR;
        }
        if (objc == 3) {
            const char *s;

            s = wmPtr->iconFor != NULL ? "icon"
              : wmPtr->withdrawn ? "withdrawn"
              : wmPtr->iconified ? "iconic" : "normal";
            Tcl_SetObjResult(interp, Tcl_NewStringObj(s, -1));
            return TCL_OK;
        }
        /*
         * "wm state .t normal|iconic|withdrawn" is the setting form and
         * is the same three operations under another name.
         */
        {
            /*
             * ALPHABETICAL, because Tcl_GetIndexFromObjStruct builds the
             * error message by listing this array in order and the test
             * checks it verbatim: "must be iconic, normal, or withdrawn".
             * unixWm-35.1.1.
             */
            static const char *const states[] = {
                "iconic", "normal", "withdrawn", NULL };
            enum { ST_ICONIC, ST_NORMAL, ST_WITHDRAWN };
            int st;

            if (wmPtr->iconFor != NULL)
                return WmIconForError(interp, "change state of", "STATE",
                        objv[2], wmPtr);
            if (Tcl_GetIndexFromObjStruct(interp, objv[3], states,
                    sizeof(char *), "argument", 0, &st) != TCL_OK)
                return TCL_ERROR;
            wmPtr->withdrawn = (st == ST_WITHDRAWN);
            wmPtr->withdrawnExplicit = (st == ST_WITHDRAWN);
            wmPtr->iconified = (st == ST_ICONIC);
            TkpWmSetState(winPtr, st == ST_NORMAL ? NormalState :
                    st == ST_ICONIC ? IconicState : WithdrawnState);
            return TCL_OK;
        }

    case OPT_ICONIFY:
        /*
         * There are no icons here, but iconified is a state a caller can
         * ask about and pack/place react to (place-8.*, pack-18.*), so
         * it has to be distinct from withdrawn rather than folded into
         * it.
         *
         * A TRANSIENT CANNOT BE ICONIFIED, and that refusal is upstream's
         * -- a dialog is shown and hidden with the window it belongs to,
         * not on its own. wm-transient-1.4..1.9 are exactly this, and
         * they check the message.
         */
        if (objc != 3) {
            Tcl_WrongNumArgs(interp, 2, objv, "window");
            return TCL_ERROR;
        }
        if (wmPtr->transient != NULL) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                    "can't iconify \"%s\": it is a transient",
                    winPtr->pathName));
            Tcl_SetErrorCode(interp, "TK", "WM", "ICONIFY", "TRANSIENT",
                    (char *) NULL);
            return TCL_ERROR;
        }
        /*
         * Three more refusals, all upstream's and all checked by name.
         * An override-redirect window is not the window manager's to
         * iconify; an icon window is already someone else's icon; an
         * embedded toplevel belongs to its container.
         * unixWm-23.2, 23.4, wm-iconify-2.1, 2.3, 2.4.2.
         */
        if (Tk_Attributes((Tk_Window) winPtr)->override_redirect) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                    "can't iconify \"%s\": override-redirect flag is set",
                    winPtr->pathName));
            Tcl_SetErrorCode(interp, "TK", "WM", "ICONIFY", "OVERRIDE_REDIRECT",
                    (char *) NULL);
            return TCL_ERROR;
        }
        if (wmPtr->iconFor != NULL) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                    "can't iconify \"%s\": it is an icon for \"%s\"",
                    winPtr->pathName, wmPtr->iconFor->pathName));
            Tcl_SetErrorCode(interp, "TK", "WM", "ICONIFY", "ICON",
                    (char *) NULL);
            return TCL_ERROR;
        }
        if (winPtr->flags & TK_EMBEDDED) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                    "can't iconify \"%s\": it is an embedded window",
                    winPtr->pathName));
            Tcl_SetErrorCode(interp, "TK", "WM", "ICONIFY", "EMBEDDED",
                    (char *) NULL);
            return TCL_ERROR;
        }
        wmPtr->withdrawn = 0;
        wmPtr->iconified = 1;
        TkpWmSetState(winPtr, IconicState);
        return TCL_OK;

    case OPT_GRID: {
        int w, h, dx, dy;

        /*
         * "wm grid" is the same gridding Tk_SetGrid drives from
         * "-setgrid 1" -- see the gridding note in CLAUDE.md -- reached
         * from Tcl instead of from a widget. While it is in force
         * wmPtr->width/height are in GRID UNITS, so the conversion has
         * to go through the same two helpers.
         */
        if (objc != 3 && objc != 7) {
            Tcl_WrongNumArgs(interp, 2, objv,
                    "window ?baseWidth baseHeight widthInc heightInc?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            if (wmPtr->gridWin != NULL) {
                Tcl_Obj *r[4];

                r[0] = Tcl_NewWideIntObj(wmPtr->reqGridWidth);
                r[1] = Tcl_NewWideIntObj(wmPtr->reqGridHeight);
                r[2] = Tcl_NewWideIntObj(wmPtr->widthInc);
                r[3] = Tcl_NewWideIntObj(wmPtr->heightInc);
                Tcl_SetObjResult(interp, Tcl_NewListObj(4, r));
            }
            return TCL_OK;
        }
        if (*Tcl_GetString(objv[3]) == '\0') {
            Tk_UnsetGrid(tkwin);
            return TCL_OK;
        }
        if (Tcl_GetIntFromObj(interp, objv[3], &w) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[4], &h) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[5], &dx) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[6], &dy) != TCL_OK)
            return TCL_ERROR;
        /*
         * FOUR SEPARATE MESSAGES, one per argument, as upstream has --
         * naming the argument that is wrong is the whole value of the
         * diagnostic, and the tests check each by name (wm-grid-1.9..12,
         * unixWm-20.5/20.7/20.9/20.11). One combined message describing
         * all four conditions passes none of them and helps nobody.
         */
        if (w < 0) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "baseWidth can't be < 0", -1));
            Tcl_SetErrorCode(interp, "TK", "VALUE", "GRID", (char *) NULL);
            return TCL_ERROR;
        }
        if (h < 0) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "baseHeight can't be < 0", -1));
            Tcl_SetErrorCode(interp, "TK", "VALUE", "GRID", (char *) NULL);
            return TCL_ERROR;
        }
        if (dx <= 0) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "widthInc can't be <= 0", -1));
            Tcl_SetErrorCode(interp, "TK", "VALUE", "GRID", (char *) NULL);
            return TCL_ERROR;
        }
        if (dy <= 0) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "heightInc can't be <= 0", -1));
            Tcl_SetErrorCode(interp, "TK", "VALUE", "GRID", (char *) NULL);
            return TCL_ERROR;
        }
        Tk_SetGrid(tkwin, w, h, dx, dy);
        return TCL_OK;
    }

    case OPT_STACKORDER: {
        /*
         * This used to answer an empty list, which is 32 of wm.test's
         * failures on its own -- and needlessly, because
         * TkWmStackorderToplevel is implemented in this file and
         * dispPtr->firstWmPtr has kept the order all along (bottom
         * first, as Tk's own childList convention has it).
         */
        static const char *const rels[] = { "isabove", "isbelow", NULL };
        TkWindow **windows, **wp;
        int rel;

        if (objc != 3 && objc != 5) {
            Tcl_WrongNumArgs(interp, 2, objv,
                    "window ?isabove|isbelow window?");
            return TCL_ERROR;
        }
        /*
         * THE TWO FORMS WALK FROM DIFFERENT ROOTS, AND UPSTREAM MEANS
         * THEM TO. tkUnixWm.c:3307 passes the named window for
         * "wm stackorder .t" -- the answer is that window's own
         * subtree -- and tkUnixWm.c:3359 passes
         * winPtr->mainPtr->winPtr for isabove/isbelow, because the two
         * windows being compared need not be related at all.
         *
         * Passing the named window for both is why
         * "wm stackorder .t isabove ." reported
         * "TkWmStackorderToplevel failed": the walk covered `.t` and
         * its children, `.` is not among them, so the second index came
         * back -1 and the code read that as the collector having
         * failed. wm-stackorder-4.3, 4.4, 5.3.
         */
        windows = TkWmStackorderToplevel(
                (objc == 5) ? winPtr->mainPtr->winPtr : winPtr);
        if (windows == NULL)
            return TCL_ERROR;
        if (objc == 3) {
            Tcl_Obj *l = Tcl_NewObj();

            for (wp = windows; *wp != NULL; wp++)
                Tcl_ListObjAppendElement(NULL, l,
                        Tcl_NewStringObj((*wp)->pathName, -1));
            ckfree(windows);
            Tcl_SetObjResult(interp, l);
            return TCL_OK;
        }
        {
            Tk_Window relWin;
            TkWindow *winPtr2;
            int i1 = -1, i2 = -1, i;

            if (TkGetWindowFromObj(interp, (Tk_Window) clientData, objv[4],
                    &relWin) != TCL_OK) {
                ckfree(windows);
                return TCL_ERROR;
            }
            winPtr2 = (TkWindow *) relWin;
            if (!Tk_IsTopLevel(winPtr2)) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "window \"%s\" isn't a top-level window",
                        winPtr2->pathName));
                Tcl_SetErrorCode(interp, "TK", "WM", "STACK", "TOPLEVEL",
                        (char *) NULL);
                ckfree(windows);
                return TCL_ERROR;
            }
            if (!Tk_IsMapped(winPtr)) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "window \"%s\" isn't mapped", winPtr->pathName));
                Tcl_SetErrorCode(interp, "TK", "WM", "STACK", "MAPPED",
                        (char *) NULL);
                ckfree(windows);
                return TCL_ERROR;
            }
            if (!Tk_IsMapped(winPtr2)) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "window \"%s\" isn't mapped", winPtr2->pathName));
                Tcl_SetErrorCode(interp, "TK", "WM", "STACK", "MAPPED",
                        (char *) NULL);
                ckfree(windows);
                return TCL_ERROR;
            }
            for (i = 0, wp = windows; *wp != NULL; wp++, i++) {
                if (*wp == winPtr)
                    i1 = i;
                if (*wp == winPtr2)
                    i2 = i;
            }
            ckfree(windows);
            if (i1 < 0 || i2 < 0) {
                Tcl_SetObjResult(interp, Tcl_NewStringObj(
                        "TkWmStackorderToplevel failed", -1));
                return TCL_ERROR;
            }
            if (Tcl_GetIndexFromObjStruct(interp, objv[3], rels,
                    sizeof(char *), "argument", 0, &rel) != TCL_OK)
                return TCL_ERROR;
            Tcl_SetObjResult(interp, Tcl_NewBooleanObj(
                    rel == 0 ? (i1 > i2) : (i1 < i2)));
        }
        return TCL_OK;
    }

    case OPT_ICONNAME:
        /*
         * NOT an alias for the title, though it shared this case until
         * now. wm.test sets one and reads the other back, so folding
         * them together answers the wrong string. There is no icon here
         * either way; the name is simply remembered.
         */
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, wmPtr->iconName);
        if (objc == 4) {
            WmSetString(&wmPtr->iconName, Tcl_GetString(objv[3]));
            return TCL_OK;
        }
        Tcl_WrongNumArgs(interp, 2, objv, "window ?newName?");
        return TCL_ERROR;

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

    case OPT_RESIZABLE: {
        int rw, rh;

        if (objc != 3 && objc != 5) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?width height?");
            return TCL_ERROR;
        }
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_ObjPrintf("%d %d",
                    wmPtr->widthResizable, wmPtr->heightResizable));
            return TCL_OK;
        }
        if (Tcl_GetBooleanFromObj(interp, objv[3], &rw) != TCL_OK
                || Tcl_GetBooleanFromObj(interp, objv[4], &rh) != TCL_OK)
            return TCL_ERROR;
        wmPtr->widthResizable  = rw;
        wmPtr->heightResizable = rh;
        WmUpdateNow(winPtr);
        return TCL_OK;
    }

    case OPT_FRAME:
        /* return "0x0" — Plan 9 has no separate frame window */
        if (objc != 3) {
            Tcl_WrongNumArgs(interp, 2, objv, "window");
            return TCL_ERROR;
        }
        Tcl_SetObjResult(interp, Tcl_NewStringObj("0x0", -1));
        return TCL_OK;

    case OPT_ASPECT: {
        int n1, d1, n2, d2;

        if (objc != 3 && objc != 7) {
            Tcl_WrongNumArgs(interp, 2, objv,
                    "window ?minNumer minDenom maxNumer maxDenom?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            if (wmPtr->hasAspect) {
                Tcl_Obj *r[4];

                r[0] = Tcl_NewWideIntObj(wmPtr->minAspectX);
                r[1] = Tcl_NewWideIntObj(wmPtr->minAspectY);
                r[2] = Tcl_NewWideIntObj(wmPtr->maxAspectX);
                r[3] = Tcl_NewWideIntObj(wmPtr->maxAspectY);
                Tcl_SetObjResult(interp, Tcl_NewListObj(4, r));
            }
            return TCL_OK;
        }
        if (*Tcl_GetString(objv[3]) == '\0') {
            wmPtr->hasAspect = 0;
            return TCL_OK;
        }
        if (Tcl_GetIntFromObj(interp, objv[3], &n1) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[4], &d1) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[5], &n2) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[6], &d2) != TCL_OK)
            return TCL_ERROR;
        if (n1 <= 0 || d1 <= 0 || n2 <= 0 || d2 <= 0) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "aspect number can't be <= 0", -1));
            Tcl_SetErrorCode(interp, "TK", "VALUE", "ASPECT", (char *) NULL);
            return TCL_ERROR;
        }
        wmPtr->minAspectX = n1; wmPtr->minAspectY = d1;
        wmPtr->maxAspectX = n2; wmPtr->maxAspectY = d2;
        wmPtr->hasAspect = 1;
        return TCL_OK;
    }

    case OPT_CLIENT:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?name?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, wmPtr->clientMachine);
        WmSetString(&wmPtr->clientMachine, Tcl_GetString(objv[3]));
        return TCL_OK;

    case OPT_COMMAND:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?value?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, wmPtr->command);
        {
            /*
             * The argument must be a proper list -- upstream splits it
             * into argv for WM_COMMAND, and rejects what it cannot
             * split. Keep the check even though nothing here consumes
             * the result, or "wm command .t {\{}" would be accepted
             * where every other Tk says it is not.
             */
            Tcl_Size n;
            Tcl_Obj **el;

            if (Tcl_ListObjGetElements(interp, objv[3], &n, &el) != TCL_OK)
                return TCL_ERROR;
            WmSetString(&wmPtr->command, n == 0 ? NULL :
                    Tcl_GetString(objv[3]));
        }
        return TCL_OK;

    case OPT_CMAPWINS:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?windowList?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            /*
             * A WINDOW THAT HAS BEEN DESTROYED IS NOT IN THE LIST ANY
             * MORE, and this used to report it for ever.
             *
             * The setter above already refuses a name that cannot be
             * resolved, on the rule stated in the wm section: accepting
             * one is the same class of lie as answering the empty
             * string. That invariant breaks the moment a listed window
             * dies, and the list is kept as a string, so nothing
             * noticed -- `wm colormapwindows .t .t.f2; destroy .t.f2`
             * went on naming `.t.f2` (unixWm-53.2).
             *
             * Upstream keeps a TkWindow array and drops the entry from
             * TkWmRemoveFromColormapWindows as the window is destroyed.
             * Filtering on read reaches the same answer with no second
             * copy of the window set to keep in step, and it cannot go
             * stale between a destroy and the next query.
             */
            Tcl_Obj *stored, *out, **el;
            Tcl_Size n, i;

            if (wmPtr->cmapWindows == NULL)
                return TCL_OK;
            stored = Tcl_NewStringObj(wmPtr->cmapWindows, -1);
            Tcl_IncrRefCount(stored);
            if (Tcl_ListObjGetElements(NULL, stored, &n, &el) != TCL_OK) {
                Tcl_DecrRefCount(stored);
                return WmReturnString(interp, wmPtr->cmapWindows);
            }
            out = Tcl_NewObj();
            for (i = 0; i < n; i++)
                if (Tk_NameToWindow(NULL, Tcl_GetString(el[i]),
                        (Tk_Window) clientData) != NULL)
                    Tcl_ListObjAppendElement(NULL, out, el[i]);
            Tcl_DecrRefCount(stored);
            Tcl_SetObjResult(interp, out);
            return TCL_OK;
        }
        {
            Tcl_Size n, i;
            Tcl_Obj **el;

            if (Tcl_ListObjGetElements(interp, objv[3], &n, &el) != TCL_OK)
                return TCL_ERROR;
            /* Every element must name a window, as on X. */
            for (i = 0; i < n; i++)
                if (Tk_NameToWindow(interp, Tcl_GetString(el[i]),
                        (Tk_Window) clientData) == NULL)
                    return TCL_ERROR;
            WmSetString(&wmPtr->cmapWindows, n == 0 ? NULL :
                    Tcl_GetString(objv[3]));
        }
        return TCL_OK;

    case OPT_FOCUSMODEL: {
        static const char *const models[] = { "active", "passive", NULL };
        int m;

        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?active|passive?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp,
                    wmPtr->focusActive ? "active" : "passive");
        if (Tcl_GetIndexFromObjStruct(interp, objv[3], models,
                sizeof(char *), "argument", 0, &m) != TCL_OK)
            return TCL_ERROR;
        wmPtr->focusActive = (m == 0);
        return TCL_OK;
    }

    case OPT_GROUP:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?pathName?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, wmPtr->leaderName);
        {
            const char *s = Tcl_GetString(objv[3]);
            Tk_Window leader;

            if (*s == '\0') {
                WmSetString(&wmPtr->leaderName, NULL);
                return TCL_OK;
            }
            leader = Tk_NameToWindow(interp, s, (Tk_Window) clientData);
            if (leader == NULL)
                return TCL_ERROR;
            /*
             * The leader is resolved to its nearest TOPLEVEL ancestor,
             * as with "wm transient" above and for the same reason.
             */
            while (leader != NULL && !Tk_TopWinHierarchy((TkWindow *) leader))
                leader = (Tk_Window) ((TkWindow *) leader)->parentPtr;
            if (leader == NULL) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "can't find a toplevel for \"%s\"", s));
                Tcl_SetErrorCode(interp, "TK", "WM", "GROUP", (char *) NULL);
                return TCL_ERROR;
            }
            /*
             * THE LEADER'S WINDOW IS CREATED HERE, and that is not
             * bookkeeping. Upstream's WmGroupCmd does Tk_MakeWindowExist
             * on the leader and then CreateWrapper if it has no wrapper
             * yet, because the group hint has to name a window id and a
             * never-mapped toplevel has none. There are no wrappers in
             * this port -- a toplevel IS its window -- so the first half
             * alone is the whole of it, and unixWm-21.5 tests exactly
             * that: testwrapper on the leader is empty before the "wm
             * group" and must be a real id after it.
             */
            Tk_MakeWindowExist(leader);
            WmSetString(&wmPtr->leaderName, s);
        }
        return TCL_OK;

    case OPT_TRANSIENT:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?window?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, wmPtr->transient);
        {
            const char *s = Tcl_GetString(objv[3]);
            Tk_Window master;

            if (*s == '\0') {
                WmSetString(&wmPtr->transient, NULL);
                WmUntrackContainer(winPtr, wmPtr->container);
                wmPtr->container = NULL;
                return TCL_OK;
            }
            master = Tk_NameToWindow(interp, s, (Tk_Window) clientData);
            if (master == NULL)
                return TCL_ERROR;
            /*
             * The master is resolved to its nearest TOPLEVEL ancestor,
             * as upstream does: "wm transient .subject .top.f" records
             * .top, and reading it back must say .top rather than the
             * frame that was named (wm-transient-2.2).
             */
            while (!Tk_TopWinHierarchy((TkWindow *) master)) {
                master = (Tk_Window) ((TkWindow *) master)->parentPtr;
                if (master == NULL)
                    break;
            }
            if (master == NULL) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "can't find a toplevel for \"%s\"", s));
                Tcl_SetErrorCode(interp, "TK", "WM", "TRANSIENT", (char *) NULL);
                return TCL_ERROR;
            }
            /*
             * Neither end may be somebody's icon: an icon is already
             * owned, and a dialog attached to one could never be shown.
             * wm-transient-1.5 and 1.6, and note they are DIFFERENT
             * messages -- "a transient" for this window, "a container"
             * for the one named.
             */
            if (wmPtr->iconFor != NULL) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "can't make \"%s\" a transient: it is an icon for %s",
                        Tcl_GetString(objv[2]),
                        Tk_PathName(wmPtr->iconFor)));
                Tcl_SetErrorCode(interp, "TK", "WM", "TRANSIENT", "ICON",
                        (char *) NULL);
                return TCL_ERROR;
            }
            if (((TkWindow *) master)->wmInfoPtr->iconFor != NULL) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "can't make \"%s\" a container: it is an icon for %s",
                        s,
                        Tk_PathName(((TkWindow *) master)->wmInfoPtr->iconFor)));
                Tcl_SetErrorCode(interp, "TK", "WM", "TRANSIENT", "ICON",
                        (char *) NULL);
                return TCL_ERROR;
            }
            /*
             * A LOOP IS NOT JUST THE SELF CASE. Walking the chain of
             * containers from the proposed one and finding this window
             * catches "a transient of b, b transient of a" as well, which
             * the self test alone does not -- wm-transient-1.8 is exactly
             * that pair. The message names the CONTAINER, and is the same
             * for both lengths, which is why the old "can't make %s its
             * own master" failed 1.7 and 1.9 as well.
             */
            {
                TkWindow *w;

                for (w = (TkWindow *) master;
                        w != NULL && w->wmInfoPtr != NULL;
                        w = WmTransientOf(w)) {
                    if (w == winPtr) {
                        Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                                "can't set \"%s\" as container:"
                                " would cause management loop",
                                Tk_PathName(master)));
                        Tcl_SetErrorCode(interp, "TK", "WM", "TRANSIENT",
                                "SELF", (char *) NULL);
                        return TCL_ERROR;
                    }
                }
            }
            Tk_MakeWindowExist(master);
            WmSetString(&wmPtr->transient, Tk_PathName(master));
            /*
             * The handler moves with the pointer, and only when the
             * container actually changes -- re-registering would give
             * the window two handlers and every state change twice.
             */
            if (wmPtr->container != (TkWindow *) master) {
                WmUntrackContainer(winPtr, wmPtr->container);
                WmTrackContainer(winPtr, (TkWindow *) master);
                wmPtr->container = (TkWindow *) master;
            }

            /*
             * A transient follows its master's state: while the master
             * is iconic or withdrawn the transient is withdrawn too,
             * because a dialog has no business on screen without the
             * window it belongs to. wm-transient-4.* and -8.1 check
             * exactly this, and it is the one part of "transient" that
             * is behaviour rather than bookkeeping.
             *
             * This is the state at the moment of the call; WmWaitMapProc
             * above keeps it in step afterwards.
             */
            {
                WmInfo *mPtr = ((TkWindow *) master)->wmInfoPtr;

                if (mPtr != NULL && (mPtr->withdrawn || mPtr->iconified)) {
                    wmPtr->withdrawn = 1;
                    wmPtr->iconified = 0;
                    TkpWmSetState(winPtr, WithdrawnState);
                }
            }
        }
        return TCL_OK;

    case OPT_ICONBITMAP:
    case OPT_ICONMASK: {
        char **slot = (index == OPT_ICONBITMAP) ? &wmPtr->iconBitmap
                                                : &wmPtr->iconMask;

        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?bitmap?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp, *slot);
        {
            const char *s = Tcl_GetString(objv[3]);

            if (*s == '\0') {
                WmSetString(slot, NULL);
                return TCL_OK;
            }
            /*
             * The bitmap has to exist: "wm iconbitmap .t bad-bitmap" is
             * an error everywhere else, and answering OK to a name that
             * cannot be resolved is the same class of lie this whole
             * change is about.
             */
            if (Tk_GetBitmap(interp, tkwin, s) == None)
                return TCL_ERROR;
            WmSetString(slot, s);
        }
        return TCL_OK;
    }

    case OPT_ICONPHOTO:
        /*
         * "wm iconphoto window ?-default? image1 ?image2 ...?". Nothing
         * displays it, but the images must exist -- that is the half a
         * caller can observe.
         */
        if (objc < 4) {
            Tcl_WrongNumArgs(interp, 2, objv,
                    "window ?-default? image1 ?image2 ...?");
            return TCL_ERROR;
        }
        {
            int i = 3;

            if (strcmp(Tcl_GetString(objv[3]), "-default") == 0) {
                i = 4;
                if (objc < 5) {
                    Tcl_WrongNumArgs(interp, 2, objv,
                            "window ?-default? image1 ?image2 ...?");
                    return TCL_ERROR;
                }
            }
            /*
             * A PHOTO specifically, not any image, and the message says
             * so: "can't use %s as iconphoto: not a photo image". Going
             * through Tk_GetImage accepted a bitmap and reported a
             * missing name as 'image "x" does not exist', which is true
             * and is not what iconphoto is being asked (wm-iconphoto-1.3).
             */
            for (; i < objc; i++) {
                if (Tk_FindPhoto(interp, Tcl_GetString(objv[i])) == NULL) {
                    Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                            "can't use \"%s\" as iconphoto: not a photo image",
                            Tcl_GetString(objv[i])));
                    Tcl_SetErrorCode(interp, "TK", "WM", "ICONPHOTO",
                            "PHOTO", (char *) NULL);
                    return TCL_ERROR;
                }
            }
            WmSetString(&wmPtr->iconPhoto, Tcl_GetString(objv[objc-1]));
        }
        return TCL_OK;

    case OPT_ICONBADGE: {
        /*
         * "wm iconbadge window badge" -- set only, no query form.
         *
         * DELEGATED TO ::tk::icons::IconBadge, exactly as tkUnixWm.c
         * does, rather than stored here. All the validation lives in
         * that proc -- the base icon must have been set and must be a
         * photo, the badge must be a positive integer or one of the
         * permitted words -- and reimplementing it in C would mean
         * reimplementing five error messages the tests check verbatim
         * (wm-iconbadge-1.3..1.7) and keeping them in step with a Tcl
         * file sitting in the same tree.
         */
        char cmd[4096];

        if (objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window badge");
            return TCL_ERROR;
        }
        snprintf(cmd, sizeof(cmd), "::tk::icons::IconBadge {%s} {%s}",
                Tcl_GetString(objv[2]), Tcl_GetString(objv[3]));
        if (Tcl_EvalEx(interp, cmd, TCL_INDEX_NONE, TCL_EVAL_DIRECT) != TCL_OK)
            return TCL_ERROR;
        WmSetString(&wmPtr->iconBadge, Tcl_GetString(objv[3]));
        return TCL_OK;
    }

    case OPT_ICONPOS: {
        int x, y;

        if (objc != 3 && objc != 5) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?x y?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            if (wmPtr->hasIconPos) {
                Tcl_Obj *r[2];

                r[0] = Tcl_NewWideIntObj(wmPtr->iconX);
                r[1] = Tcl_NewWideIntObj(wmPtr->iconY);
                Tcl_SetObjResult(interp, Tcl_NewListObj(2, r));
            }
            return TCL_OK;
        }
        if (*Tcl_GetString(objv[3]) == '\0') {
            wmPtr->hasIconPos = 0;
            return TCL_OK;
        }
        if (Tcl_GetIntFromObj(interp, objv[3], &x) != TCL_OK
         || Tcl_GetIntFromObj(interp, objv[4], &y) != TCL_OK)
            return TCL_ERROR;
        wmPtr->iconX = x;
        wmPtr->iconY = y;
        wmPtr->hasIconPos = 1;
        return TCL_OK;
    }

    case OPT_ICONWIN:
        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?pathName?");
            return TCL_ERROR;
        }
        if (objc == 3)
            return WmReturnString(interp, wmPtr->iconWindow);
        {
            const char *s = Tcl_GetString(objv[3]);
            Tk_Window icon;
            TkWindow *iconPtr;

            if (*s == '\0') {
                WmReleaseIcon(wmPtr);
                return TCL_OK;
            }
            icon = Tk_NameToWindow(interp, s, (Tk_Window) clientData);
            if (icon == NULL)
                return TCL_ERROR;
            if (!Tk_IsTopLevel(icon)) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "can't use %s as icon window: not at top level", s));
                Tcl_SetErrorCode(interp, "TK", "WM", "ICONWINDOW",
                        "INNER", (char *) NULL);
                return TCL_ERROR;
            }
            iconPtr = (TkWindow *) icon;
            if (iconPtr->wmInfoPtr->iconFor != NULL) {
                Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                        "%s is already an icon for %s", s,
                        Tk_PathName(iconPtr->wmInfoPtr->iconFor)));
                Tcl_SetErrorCode(interp, "TK", "WM", "ICONWINDOW",
                        "ICON", (char *) NULL);
                return TCL_ERROR;
            }
            WmReleaseIcon(wmPtr);	/* a previous icon, if any */

            /*
             * BECOMING AN ICON TAKES THE WINDOW OFF THE SCREEN. On X the
             * window manager owns it from here and draws it only while
             * the toplevel is iconified; rio has no icons at all, so it
             * is simply unmapped -- but "wm state" answers "icon" rather
             * than "withdrawn", because iconFor is what it is now for.
             * unixWm-27.6 checks exactly that pair, and 27.7 checks that
             * "winfo ismapped" goes to 0.
             */
            wmPtr->icon = iconPtr;
            iconPtr->wmInfoPtr->iconFor = winPtr;
            iconPtr->wmInfoPtr->withdrawn = 1;
            TkpWmSetState(iconPtr, WithdrawnState);
            WmSetString(&wmPtr->iconWindow, Tk_PathName(icon));
        }
        return TCL_OK;

    case OPT_OVERREDIR: {
        int b;

        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?boolean?");
            return TCL_ERROR;
        }
        /*
         * Kept in the window's own attributes rather than in WmInfo,
         * as upstream does: generic Tk reads override_redirect there
         * (menus and tooltips set it), so a private copy would be a
         * second answer to the same question.
         */
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_NewBooleanObj(
                    Tk_Attributes(tkwin)->override_redirect));
            return TCL_OK;
        }
        if (Tcl_GetBooleanFromObj(interp, objv[3], &b) != TCL_OK)
            return TCL_ERROR;
        if (Tk_Attributes(tkwin)->override_redirect != b) {
            XSetWindowAttributes atts;

            atts.override_redirect = b;
            Tk_ChangeWindowAttributes(tkwin, CWOverrideRedirect, &atts);
        }
        return TCL_OK;
    }

    case OPT_POSFROM:
    case OPT_SIZEFROM: {
        static const char *const froms[] = { "program", "user", NULL };
        int *slot = (index == OPT_POSFROM) ? &wmPtr->positionFrom
                                           : &wmPtr->sizeFrom;
        int f;

        if (objc != 3 && objc != 4) {
            Tcl_WrongNumArgs(interp, 2, objv, index == OPT_POSFROM
                    ? "window ?user/program?" : "window ?user|program?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3)
            return WmReturnString(interp,
                    *slot == 1 ? "user" : *slot == 2 ? "program" : "");
        if (*Tcl_GetString(objv[3]) == '\0') {
            *slot = 0;
            return TCL_OK;
        }
        if (Tcl_GetIndexFromObjStruct(interp, objv[3], froms,
                sizeof(char *), "argument", 0, &f) != TCL_OK)
            return TCL_ERROR;
        *slot = (f == 1) ? 1 : 2;	/* froms[] is program, user */
        return TCL_OK;
    }

    case OPT_PROTOCOL: {
        WmProto *p, **prev;
        const char *name;

        if (objc < 3 || objc > 5) {
            Tcl_WrongNumArgs(interp, 2, objv, "window ?name? ?command?");
            return TCL_ERROR;
        }
        if (wmPtr == NULL)
            return TCL_OK;
        if (objc == 3) {
            /* Every protocol that has a handler. */
            Tcl_Obj *l = Tcl_NewListObj(0, NULL);

            for (p = wmPtr->protoPtr; p != NULL; p = p->nextPtr)
                Tcl_ListObjAppendElement(NULL, l,
                        Tcl_NewStringObj(p->name, -1));
            Tcl_SetObjResult(interp, l);
            return TCL_OK;
        }
        name = Tcl_GetString(objv[3]);
        prev = &wmPtr->protoPtr;
        for (p = wmPtr->protoPtr; p != NULL; prev = &p->nextPtr,
                p = p->nextPtr)
            if (strcmp(p->name, name) == 0)
                break;
        if (objc == 4)
            return WmReturnString(interp, p != NULL ? p->command : NULL);

        /* Setting: an empty command removes the handler. */
        if (p != NULL) {
            *prev = p->nextPtr;
            WmSetString(&p->name, NULL);
            WmSetString(&p->command, NULL);
            ckfree(p);
        }
        if (*Tcl_GetString(objv[4]) != '\0') {
            p = (WmProto *) ckalloc(sizeof *p);
            p->name = p->command = NULL;
            WmSetString(&p->name, name);
            WmSetString(&p->command, Tcl_GetString(objv[4]));
            p->nextPtr = wmPtr->protoPtr;
            wmPtr->protoPtr = p;
        }
        return TCL_OK;
    }

    case OPT_ATTRIBUTES:
        /*
         * X offers -alpha, -topmost, -type, -zoomed and -fullscreen.
         * None of them means anything without a window manager, so they
         * are reported at their defaults rather than refused: a caller
         * asking "wm attributes .t -topmost" wants an answer, and 0 is
         * the true one here.
         */
        /*
         * ALPHABETICAL, because that is the order X reports them in and
         * unixWm-60.1.1 compares the whole string. The old order was the
         * order they came to mind in.
         */
        if (objc == 3) {
            Tcl_SetObjResult(interp, Tcl_NewStringObj(
                    "-alpha 1.0 -fullscreen 0 -topmost 0 -type {}"
                    " -zoomed 0", -1));
            return TCL_OK;
        }
        {
            static const char *const attrs[] = {
                "-alpha", "-fullscreen", "-topmost", "-type",
                "-zoomed", NULL };
            enum { AT_ALPHA, AT_FULLSCREEN, AT_TOPMOST, AT_TYPE, AT_ZOOMED };
            int at;

            /*
             * An UNKNOWN attribute is an error, not silently ignored:
             * "wm attributes .t -foo" must say so (unixWm-60.5,
             * wm-attributes-1.2.5.1). Tcl_GetIndexFromObjStruct builds
             * the "bad attribute ..., must be ..." message itself.
             */
            if (Tcl_GetIndexFromObjStruct(interp, objv[3], attrs,
                    sizeof(char *), "attribute", 0, &at) != TCL_OK)
                return TCL_ERROR;
            /*
             * Setting is accepted and does nothing -- there is no window
             * manager to be topmost or fullscreen with respect to -- but
             * a query has to answer, and 0 is the true answer here.
             */
            if (objc == 4) {
                if (at == AT_ALPHA)
                    Tcl_SetObjResult(interp, Tcl_NewDoubleObj(1.0));
                else if (at == AT_TYPE)
                    Tcl_SetObjResult(interp, Tcl_NewStringObj("", -1));
                else
                    Tcl_SetObjResult(interp, Tcl_NewBooleanObj(0));
            }
            return TCL_OK;
        }

    case OPT_FORGET:
    case OPT_MANAGE:
        /*
         * Turning a toplevel into an ordinary child and back. Both are
         * real generic-Tk operations and neither needs a window manager;
         * they are left alone here because doing them wrongly is worse
         * than not doing them, and wm-forget/wm-manage are seven tests.
         * See the note in CLAUDE.md.
         */
        return TCL_OK;

    default:
        /*
         * Nothing should reach here now. Every subcommand in opts[]
         * above has a case, so a new one added to that list without an
         * implementation is the only way in -- and silently succeeding
         * is exactly what this change exists to stop.
         */
        Tcl_SetObjResult(interp, Tcl_ObjPrintf(
                "wm %s is not implemented on Plan 9",
                Tcl_GetString(objv[1])));
        Tcl_SetErrorCode(interp, "TK", "WM", "UNSUPPORTED", (char *) NULL);
        return TCL_ERROR;
    }
}
