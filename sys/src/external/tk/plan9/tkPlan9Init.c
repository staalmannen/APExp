/*
 * tkPlan9Init.c --
 *
 *	Display and window management for the Plan 9 Tk backend.
 *
 *	Implements TkpOpenDisplay/TkpCloseDisplay, XkbOpenDisplay, and
 *	all XCreateWindow / XDestroyWindow / XMapWindow / geometry calls.
 *
 *	Plan 9 has one physical window per process.  We emulate X11's
 *	multi-window model by keeping a table of regions (P9Window) within
 *	that single Plan 9 window.
 */

#include "tkPlan9Int.h"

/* ------------------------------------------------------------------ */
/* Global state                                                        */
/* ------------------------------------------------------------------ */

P9DisplayState gP9;

/* Singleton TkDisplay for the Plan 9 display */
static TkDisplay *gTkDisplay = NULL;
static const char *gDisplayName = ":0";

/* ------------------------------------------------------------------ */
/* Window table                                                        */
/* ------------------------------------------------------------------ */

P9Window *
TkP9FindWindow(Window xid)
{
    int i;
    for (i = 0; i < gP9.nwins; i++)
        if (gP9.wins[i].inuse && gP9.wins[i].xid == xid)
            return &gP9.wins[i];
    return NULL;
}

/*
 * The window table is a fixed array, so it can run out -- and the way it
 * used to run out was the worst available: XCreateWindow answered None,
 * which every caller reads as "no window" rather than "no room". A
 * frame would then exist to Tk and not to this port, and the first
 * thing to notice would be something a long way away.
 *
 * Two rules here, both about not being quiet:
 *
 *   - exhaustion PANICS, naming the table and its size. A panic at the
 *     point of failure beats a general protection violation twenty
 *     minutes later, which is what this cost once already.
 *   - occupancy is reported as it climbs, one line per TKP9_WINREPORT
 *     slots, unconditionally rather than under $TKP9DEBUG -- the debug
 *     flag turns on a torrent of drawing traces, so a number that only
 *     appears alongside them is a number nobody will see. Eight lines
 *     over the life of a process is the whole cost, and it turns "did
 *     we get close?" into something the log answers by itself.
 */
#define TKP9_WINREPORT 256

P9Window *
TkP9AllocWindow(void)
{
    int i;
    for (i = 0; i < TKP9_MAX_WINDOWS; i++) {
        if (!gP9.wins[i].inuse) {
            memset(&gP9.wins[i], 0, sizeof(P9Window));
            gP9.wins[i].inuse = 1;
            if (i >= gP9.nwins) gP9.nwins = i + 1;
            gP9.winuse++;
            if (gP9.winuse > gP9.winhigh) {
                int prev = gP9.winhigh;
                gP9.winhigh = gP9.winuse;
                if (gP9.winhigh / TKP9_WINREPORT != prev / TKP9_WINREPORT)
                    fprintf(stderr, "tkp9: window table %d/%d in use\n",
                            gP9.winhigh, TKP9_MAX_WINDOWS);
            }
            return &gP9.wins[i];
        }
    }
    Tcl_Panic("tkp9: window table full (%d entries); "
              "every XCreateWindow from here would answer None",
              TKP9_MAX_WINDOWS);
    return NULL;
}

/*
 * Where a window actually sits on the screen.
 *
 * X window coordinates are relative to the *parent*, so a button inside
 * a frame inside a toplevel is at the sum of the three, not at its own
 * x,y. Every drawing call used one level only, so nested widgets all
 * collapsed toward the origin and piled up in the top-left corner.
 *
 * The walk is bounded by the table size: a corrupt parent chain must
 * not spin here.
 */
void
TkP9WindowOffset(Window xid, int *ox, int *oy)
{
    P9Window *pw;
    int x = 0, y = 0, guard;

    for (pw = TkP9FindWindow(xid), guard = 0;
         pw != NULL && guard < TKP9_MAX_WINDOWS;
         pw = TkP9FindWindow(pw->parent), guard++) {
        x += pw->x;
        y += pw->y;
        /*
         * A pixmap is a drawable in its own right, not a child of the
         * window it was created against, so its position is its own and
         * the walk stops here.
         */
        if (pw->ispixmap || pw->xid == TKP9_ROOT_XID || pw->parent == pw->xid)
            break;
    }
    *ox = x;
    *oy = y;
}

void
TkP9FreeWindow(Window xid)
{
    P9Window *w = TkP9FindWindow(xid);
    if (w) {
        w->inuse = 0;
        gP9.winuse--;
    }
}

/* ------------------------------------------------------------------ */
/* Event queue                                                         */
/* ------------------------------------------------------------------ */

void
TkP9EnqueueEvent(XEvent *ev)
{
    int next = (gP9.evtail + 1) & TKP9_EVQMASK;
    if (next == gP9.evhead) return; /* drop if full */
    gP9.evqueue[gP9.evtail] = *ev;
    gP9.evtail = next;
}

int
TkP9DequeueEvent(XEvent *ev)
{
    if (gP9.evhead == gP9.evtail) return 0;
    *ev = gP9.evqueue[gP9.evhead];
    gP9.evhead = (gP9.evhead + 1) & TKP9_EVQMASK;
    return 1;
}

int
TkP9EventsPending(void)
{
    return gP9.evhead != gP9.evtail;
}

/* ------------------------------------------------------------------ */
/* XID allocator                                                       */
/* ------------------------------------------------------------------ */

static XID
P9AllocXID(Display *display)
{
    (void)display;
    return gP9.next_xid++;
}

/* ------------------------------------------------------------------ */
/* XkbOpenDisplay / TkpOpenDisplay                                     */
/* ------------------------------------------------------------------ */

Display *
XkbOpenDisplay(
    const char *name,
    int *ev_rtrn,
    int *err_rtrn,
    int *major_rtrn,
    int *minor_rtrn,
    int *reason)
{
    _XPrivDisplay d;
    Screen       *screen;

    if (!name || !name[0]) name = gDisplayName;

    if (gP9.xdisplay != NULL) {
        /* Only one display on Plan 9 */
        if (ev_rtrn)    *ev_rtrn    = 0;
        if (err_rtrn)   *err_rtrn   = 0;
        if (major_rtrn) *major_rtrn = 0;
        if (minor_rtrn) *minor_rtrn = 0;
        if (reason)     *reason     = 0;
        return gP9.xdisplay;
    }

    /* Initialise libdraw */
    if (!gP9.initialized) {
        if (tkp9_open("wish") < 0)
            return NULL;
        gP9.screenw    = tkp9_screenwidth();
        gP9.screenh    = tkp9_screenheight();
        gP9.mousefd    = tkp9_mousefd();
        gP9.kbdfd      = tkp9_kbdfd();
        gP9.next_xid   = TKP9_ROOT_XID + 1;
        gP9.initialized = 1;
    }

    d      = (_XPrivDisplay) ckalloc(sizeof(Display));
    screen = (Screen *) ckalloc(sizeof(Screen));
    memset(d,      0, sizeof(Display));
    memset(screen, 0, sizeof(Screen));

    d->resource_alloc        = P9AllocXID;
    d->fd                    = gP9.mousefd;
    d->proto_major_version   = 1;
    d->proto_minor_version   = 0;
    d->vendor                = (char *)"Plan9/APExp";
    d->release               = 1;
    d->display_name          = (char *) name;
    d->default_screen        = 0;
    d->nscreens              = 1;
    d->screens               = screen;
    d->byte_order            = LSBFirst;
    d->bitmap_unit           = 32;
    d->bitmap_pad            = 32;
    d->bitmap_bit_order      = LSBFirst;
    d->qlen                  = 0;
    LastKnownRequestProcessed(d) = 1;

    screen->display          = (Display *)d;
    screen->root             = TKP9_ROOT_XID;
    screen->width            = gP9.screenw;
    screen->height           = gP9.screenh;
    screen->mwidth           = (gP9.screenw * 254 + 360) / 720;
    screen->mheight          = (gP9.screenh * 254 + 360) / 720;
    screen->black_pixel      = 0x000000;
    screen->white_pixel      = 0xFFFFFF;
    screen->root_depth       = 32;
    screen->max_maps         = 1;
    screen->min_maps         = 1;
    screen->cmap             = 1;	/* nonzero: DefaultColormap must not be None */
    screen->backing_store    = NotUseful;
    screen->save_unders      = False;

    screen->root_visual      = (Visual *) ckalloc(sizeof(Visual));
    memset(screen->root_visual, 0, sizeof(Visual));
    screen->root_visual->visualid     = 0;
    screen->root_visual->c_class      = TrueColor;
    screen->root_visual->red_mask     = 0xFF0000;
    screen->root_visual->green_mask   = 0x00FF00;
    screen->root_visual->blue_mask    = 0x0000FF;
    screen->root_visual->bits_per_rgb = 8;
    screen->root_visual->map_entries  = 256;

    /* Fake default GC */
    screen->default_gc       = XCreateGC((Display *)d, screen->root, 0, NULL);

    if (ev_rtrn)    *ev_rtrn    = 0;
    if (err_rtrn)   *err_rtrn   = 0;
    if (major_rtrn) *major_rtrn = 0;
    if (minor_rtrn) *minor_rtrn = 0;
    if (reason)     *reason     = 0;

    gP9.xdisplay = (Display *)d;

    /* Register root window */
    {
        P9Window *rw = TkP9AllocWindow();
        if (rw) {
            rw->xid    = TKP9_ROOT_XID;
            rw->parent = 0;
            rw->x = rw->y = 0;
            rw->width  = gP9.screenw;
            rw->height = gP9.screenh;
            rw->mapped = 1;
        }
    }

    return (Display *)d;
}

/* ------------------------------------------------------------------ */
/* TkpOpenDisplay                                                      */
/* ------------------------------------------------------------------ */

TkDisplay *
TkpOpenDisplay(const char *display_name)
{
    Display *d;

    if (gTkDisplay != NULL) {
        if (strcmp(DisplayString(gTkDisplay->display), display_name) == 0)
            return gTkDisplay;
        return NULL;
    }

    d = XkbOpenDisplay(display_name, NULL, NULL, NULL, NULL, NULL);
    if (!d) return NULL;

    gTkDisplay = (TkDisplay *) ckalloc(sizeof(TkDisplay));
    memset(gTkDisplay, 0, sizeof(TkDisplay));
    gTkDisplay->display = d;

    TkpInitKeymapInfo(gTkDisplay);

    return gTkDisplay;
}

/* ------------------------------------------------------------------ */
/* TkpCloseDisplay                                                     */
/* ------------------------------------------------------------------ */

void
TkpCloseDisplay(TkDisplay *dispPtr)
{
    _XPrivDisplay d;

    if (gTkDisplay != dispPtr) return;

    d = (_XPrivDisplay) dispPtr->display;
    if (d->screens) {
        if (d->screens->root_visual)
            ckfree(d->screens->root_visual);
        if (d->screens->default_gc)
            XFreeGC(dispPtr->display, d->screens->default_gc);
        ckfree(d->screens);
    }
    ckfree(d);
    gTkDisplay = NULL;

    tkp9_close();
    memset(&gP9, 0, sizeof(gP9));
}

/* ------------------------------------------------------------------ */
/* TkpInit / TkpGetAppName                                             */
/* ------------------------------------------------------------------ */

int
TkpInit(Tcl_Interp *interp)
{
    TkCreateXEventSource();
    (void)interp;
    return TCL_OK;
}

void
TkpGetAppName(Tcl_Interp *interp, Tcl_DString *namePtr)
{
    const char *p, *name;

    name = Tcl_GetVar2(interp, "argv0", NULL, TCL_GLOBAL_ONLY);
    if (!name || !*name) {
        name = "tk";
    } else {
        p = strrchr(name, '/');
        if (p) name = p + 1;
    }
    Tcl_DStringAppend(namePtr, name, -1);
}

/* ------------------------------------------------------------------ */
/* Window creation / destruction                                       */
/* ------------------------------------------------------------------ */

Window
XCreateWindow(
    Display *display,
    Window parent,
    int x, int y,
    unsigned int width, unsigned int height,
    unsigned int border_width,
    int depth,
    unsigned int class,
    Visual *visual,
    unsigned long valuemask,
    XSetWindowAttributes *attributes)
{
    P9Window *pw;
    XID xid;

    (void)depth; (void)class; (void)visual;

    pw = TkP9AllocWindow();
    if (!pw) return None;

    xid = P9AllocXID(display);
    pw->xid          = xid;
    pw->parent       = parent;
    pw->x            = x;
    pw->y            = y;
    pw->width        = (int)width  > 0 ? (int)width  : 1;
    pw->height       = (int)height > 0 ? (int)height : 1;
    pw->border_width = (int)border_width;
    pw->mapped       = 0;
    pw->bg_pixel     = 0xd9d9d9FF; /* NORMAL_BG */
    pw->colormap     = DefaultColormap(display, DefaultScreen(display));
    pw->event_mask   = 0;

    if (valuemask & CWBackPixel && attributes)
        pw->bg_pixel = TkP9XColorStructToRGBA(attributes->background_pixel);
    if (valuemask & CWBorderPixel && attributes)
        pw->border_pixel = TkP9XColorStructToRGBA(attributes->border_pixel);
    if (valuemask & CWEventMask && attributes)
        pw->event_mask = attributes->event_mask;
    if (valuemask & CWColormap && attributes)
        pw->colormap = attributes->colormap;

    return xid;
}

/* Simplified version (same as CreateWindow without extra args) */
Window
XCreateSimpleWindow(
    Display *display,
    Window parent,
    int x, int y,
    unsigned int width, unsigned int height,
    unsigned int border_width,
    unsigned long border,
    unsigned long background)
{
    XSetWindowAttributes attr;
    attr.background_pixel = background;
    attr.border_pixel     = border;
    attr.event_mask       = 0;
    return XCreateWindow(display, parent, x, y, width, height,
                         border_width, CopyFromParent, CopyFromParent,
                         CopyFromParent, CWBackPixel|CWBorderPixel, &attr);
}

/* Repair what a window was covering; defined with P9ExposeTree below. */
static void P9DamageUnder(Display *display, P9Window *pw);

int
XDestroyWindow(Display *display, Window w)
{
    TkWindow *winPtr;
    P9Window *pw;

    /*
     * tkPointer.c remembers the window the pointer was last in; a dead
     * one must be forgotten before it is freed. The Windows and Mac
     * ports do the same from their destroy paths.
     */
    winPtr = (TkWindow *) Tk_IdToWindow(display, w);
    if (winPtr != NULL)
        TkPointerDeadWindow(winPtr);

    /*
     * Repair the hole BEFORE the slot is freed -- P9DamageUnder needs
     * this window's rectangle and its parent, and both are gone the
     * moment TkP9FreeWindow marks the slot unused.
     */
    pw = TkP9FindWindow(w);
    if (pw != NULL && pw->mapped)
        P9DamageUnder(display, pw);

    TkP9FreeWindow(w);
    gP9.pointerDirty = 1;
    return 0;
}

/*
 * DOES THIS PORT HAVE TO REPORT THE MAP OR UNMAP, or has generic Tk
 * already done it? Getting this wrong doubles every one of those
 * events, which is what it did for the whole life of the port.
 *
 * Generic Tk synthesises these itself for the windows an X server would
 * not report to it, because the server only tells a client about a
 * window it selected StructureNotifyMask on. So the platform's job is
 * exactly the complement, and generic/tkWindow.c states it twice, with
 * two DIFFERENT flags -- which is upstream's, not a slip:
 *
 *	Tk_MapWindow    hands TK_WIN_MANAGED to TkWmMapWindow and
 *			returns; everything else it maps and then
 *			synthesises MapNotify for.
 *	Tk_UnmapWindow  hands TK_WIN_MANAGED to TkWmUnmapWindow, and
 *			synthesises UnmapNotify only when
 *			!TK_TOP_HIERARCHY.
 *
 * So: send MapNotify iff TK_WIN_MANAGED, and UnmapNotify iff
 * TK_TOP_HIERARCHY. The asymmetry is what covers an EMBEDDED toplevel,
 * which has TK_TOP_HIERARCHY without TK_WIN_MANAGED: Tk synthesises its
 * map and not its unmap.
 *
 * textWind-12.1 is what said so -- "created mapped mapped modified"
 * where X gives "created mapped modified" -- so every <Map> and <Unmap>
 * binding on an ordinary widget has been firing twice.
 * win/tkWinWindow.c is the other port with no server and gates the same
 * two calls the same way.
 *
 * An id Tk cannot resolve keeps the old behaviour and sends:
 * Tk_IdToWindow answers NULL during teardown for a window this table
 * still has, and a missing MapNotify is much the more expensive
 * mistake -- it is what hung the suite once (see the menubar note in
 * CLAUDE.md).
 */
static int
P9ReportMapEvent(Display *display, Window w, int flag)
{
    Tk_Window tkwin = Tk_IdToWindow(display, w);

    if (tkwin == NULL)
	return 1;
    return (((TkWindow *) tkwin)->flags & flag) != 0;
}

int
XMapWindow(Display *display, Window w)
{
    P9Window *pw;
    XEvent ev;
    (void)display;

    pw = TkP9FindWindow(w);
    if (!pw) return 0;
    if (pw->mapped) return 0;
    pw->mapped = 1;
    gP9.pointerDirty = 1;

    /* MapNotify iff TK_WIN_MANAGED; see P9ReportMapEvent above. */
    if (P9ReportMapEvent(display, w, TK_WIN_MANAGED)) {
	memset(&ev, 0, sizeof(ev));
	ev.type                    = MapNotify;
	ev.xmap.display            = display;
	ev.xmap.event              = w;
	ev.xmap.window             = w;
	ev.xmap.override_redirect  = False;
	TkP9EnqueueEvent(&ev);
    }

    /*
     * Send VisibilityNotify. X sends one when a window becomes viewable,
     * and Tk waits for it in more than one place -- most importantly
     * FocusMapProc (tkFocus.c). "focus -force .w" on a window that is
     * not yet mapped cannot set the focus, so TkSetFocusWin defers:
     *
     *	if (!allMapped) {
     *	    Tk_CreateEventHandler((Tk_Window) winPtr, VisibilityChangeMask,
     *		    FocusMapProc, winPtr);
     *	    displayFocusPtr->focusOnMapPtr = winPtr;
     *	    displayFocusPtr->forceFocus = force;
     *	    return;
     *	}
     *
     * and FocusMapProc finishes the job when the window turns up. With
     * no VisibilityNotify ever sent, that handler never fired and the
     * focus was simply never set.
     *
     * The idiom this breaks is the one every Tk test file opens with:
     *
     *	pack .t.f
     *	focus -force .t.f
     *	update
     *
     * pack maps on the idle queue, so at the moment of the focus command
     * .t.f is still unmapped and the deferred path is the only path. Key
     * events are the only thing that notices, since they alone are
     * redirected through the focus (tkEvent.c InvokeFocusHandlers, which
     * discards the event when there is no focus window) -- which is why
     * a button binding on the very same widget worked while every key
     * binding on it silently did nothing, and why bind.test failed 134
     * cases with empty results and no errors.
     */
    memset(&ev, 0, sizeof(ev));
    ev.type                 = VisibilityNotify;
    ev.xvisibility.display  = display;
    ev.xvisibility.window   = w;
    ev.xvisibility.state    = VisibilityUnobscured;
    TkP9EnqueueEvent(&ev);

    /* Send Expose so the window gets repainted */
    memset(&ev, 0, sizeof(ev));
    ev.type              = Expose;
    ev.xexpose.display   = display;
    ev.xexpose.window    = w;
    ev.xexpose.x         = 0;
    ev.xexpose.y         = 0;
    ev.xexpose.width     = pw->width;
    ev.xexpose.height    = pw->height;
    ev.xexpose.count     = 0;
    TkP9EnqueueEvent(&ev);

    return 0;
}

int
XUnmapWindow(Display *display, Window w)
{
    P9Window *pw;
    XEvent ev;
    (void)display;

    pw = TkP9FindWindow(w);
    if (!pw || !pw->mapped) return 0;
    pw->mapped = 0;
    gP9.pointerDirty = 1;

    /* UnmapNotify iff TK_TOP_HIERARCHY; see P9ReportMapEvent above. */
    if (P9ReportMapEvent(display, w, TK_TOP_HIERARCHY)) {
	memset(&ev, 0, sizeof(ev));
	ev.type              = UnmapNotify;
	ev.xunmap.display    = display;
	ev.xunmap.event      = w;
	ev.xunmap.window     = w;
	TkP9EnqueueEvent(&ev);
    }

    /* Whatever it was covering has to repaint; see P9DamageUnder. */
    P9DamageUnder(display, pw);
    return 0;
}

int
XMapRaised(Display *display, Window w)
{
    XRaiseWindow(display, w);
    return XMapWindow(display, w);
}

/*
 * Restacking is Tk's own bookkeeping -- it reorders parentPtr->childList
 * (later in the list is higher) and firstWmPtr for toplevels -- so there
 * is nothing to record here. What there IS to do is repaint: an X server
 * would expose whatever the change uncovered, and nothing on Plan 9
 * will. Drawing is immediate into the one rio window, so a window that
 * has just been raised stays buried under whatever was drawn over it
 * until it repaints itself.
 *
 * Exposing the whole subtree is what makes "raise" visible at all.
 */
static void
P9ExposeTree(Display *display, Window w)
{
    P9Window *pw = TkP9FindWindow(w);
    XEvent ev;
    int i;

    if (pw == NULL || !pw->mapped || pw->ispixmap)
        return;

    memset(&ev, 0, sizeof(ev));
    ev.type            = Expose;
    ev.xexpose.display = display;
    ev.xexpose.window  = w;
    ev.xexpose.x       = 0;
    ev.xexpose.y       = 0;
    ev.xexpose.width   = pw->width;
    ev.xexpose.height  = pw->height;
    ev.xexpose.count   = 0;
    TkP9EnqueueEvent(&ev);

    for (i = 0; i < gP9.nwins; i++) {
        P9Window *c = &gP9.wins[i];
        if (c->inuse && !c->ispixmap && c->parent == w && c->xid != w)
            P9ExposeTree(display, c->xid);
    }
}

/*
 * The same thing over a RECTANGLE rather than a whole window: expose w
 * and its mapped children, each clipped to the part of the rectangle
 * that falls inside it. x,y,width,height are in w's own coordinates.
 *
 * Children are exposed after their parent so they repaint on top of it:
 * drawing here goes straight into the one rio window with no clipping,
 * so the order of the events IS the stacking, and P9ExposeTree above
 * relies on the same thing.
 */
static void
P9ExposeRect(Display *display, Window w, int x, int y, int width, int height)
{
    P9Window *pw = TkP9FindWindow(w);
    XEvent ev;
    int i;

    if (pw == NULL || !pw->mapped || pw->ispixmap)
        return;

    /* Clip to the window itself; nothing outside it was ever its to paint. */
    if (x < 0)          { width  += x; x = 0; }
    if (y < 0)          { height += y; y = 0; }
    if (x + width  > pw->width)  width  = pw->width  - x;
    if (y + height > pw->height) height = pw->height - y;
    if (width <= 0 || height <= 0)
        return;

    memset(&ev, 0, sizeof(ev));
    ev.type            = Expose;
    ev.xexpose.display = display;
    ev.xexpose.window  = w;
    ev.xexpose.x       = x;
    ev.xexpose.y       = y;
    ev.xexpose.width   = width;
    ev.xexpose.height  = height;
    ev.xexpose.count   = 0;
    TkP9EnqueueEvent(&ev);

    for (i = 0; i < gP9.nwins; i++) {
        P9Window *c = &gP9.wins[i];
        if (c->inuse && !c->ispixmap && c->parent == w && c->xid != w)
            P9ExposeRect(display, c->xid, x - c->x, y - c->y, width, height);
    }
}

/*
 * Expose w and its children over a rectangle, IN STACKING ORDER.
 *
 * P9ExposeRect above walks gP9.wins in slot order, which is roughly
 * creation order and has nothing to do with what is on top. The events
 * are the stacking here -- drawing is immediate into the one rio window
 * with no clipping, so whoever repaints last wins the pixels -- so slot
 * order is a coin toss. tk-expose-test.tcl section 4 got the right
 * answer by luck:
 *
 *	exposes: {.t 28 14 120 50} {.fb 0 0 72 30} {.fa 0 0 120 50}
 *
 * .fa had just been raised above .fb and happened to sit in a later
 * slot. Create the two frames the other way round and the raise would
 * have repainted .fb last, i.e. done nothing visible.
 *
 * Tk owns the order and always has: parentPtr->childList, lowest
 * first (Tk_RestackWindow). Use it when the window is one Tk knows,
 * and fall back to the slot walk when it is not -- during teardown
 * Tk_IdToWindow can answer NULL for a window this table still has.
 */
static void
P9ExposeRectStacked(Display *display, Window w, int x, int y, int w0, int h0)
{
    TkWindow *winPtr = (TkWindow *) Tk_IdToWindow(display, w);
    P9Window *pw = TkP9FindWindow(w);
    TkWindow *childPtr;

    if (pw == NULL || !pw->mapped || pw->ispixmap)
        return;
    if (winPtr == NULL) {
        P9ExposeRect(display, w, x, y, w0, h0);
        return;
    }

    /* The window itself, clipped, without P9ExposeRect's child walk. */
    {
        int cx = x, cy = y, cw = w0, ch = h0;
        XEvent ev;

        if (cx < 0) { cw += cx; cx = 0; }
        if (cy < 0) { ch += cy; cy = 0; }
        if (cx + cw > pw->width)  cw = pw->width  - cx;
        if (cy + ch > pw->height) ch = pw->height - cy;
        if (cw <= 0 || ch <= 0)
            return;

        memset(&ev, 0, sizeof(ev));
        ev.type            = Expose;
        ev.xexpose.display = display;
        ev.xexpose.window  = w;
        ev.xexpose.x       = cx;
        ev.xexpose.y       = cy;
        ev.xexpose.width   = cw;
        ev.xexpose.height  = ch;
        ev.xexpose.count   = 0;
        TkP9EnqueueEvent(&ev);

        x = cx; y = cy; w0 = cw; h0 = ch;
    }

    for (childPtr = winPtr->childList; childPtr != NULL;
            childPtr = childPtr->nextPtr) {
        P9Window *c;

        if (childPtr->window == None)
            continue;
        c = TkP9FindWindow(childPtr->window);
        if (c == NULL)
            continue;
        P9ExposeRectStacked(display, childPtr->window,
                x - c->x, y - c->y, w0, h0);
    }
}

/*
 * A window is going away, or moving, or being restacked: repair what it
 * was covering.
 *
 * NOTHING DID THIS. Damage was repaired in exactly one place --
 * XMapWindow, which exposes the window that just appeared -- and in
 * XRaiseWindow/XLowerWindow, which generic Tk only calls for TOPLEVELS
 * (Tk_RestackWindow sends a sibling through XConfigureWindow with
 * CWStackMode instead, and that was a pure bookkeeping call here). So
 *
 *	destroy a widget that overlapped another	-> its pixels stayed
 *	place forget a widget				-> same
 *	raise/lower a widget among its siblings		-> no repaint
 *
 * and none of it was visible from Tcl, because Tk believes it asked for
 * the repaint. sys/lib/tests/tk-expose-test.tcl reports the Expose
 * events with their rectangles and found all four cases silent.
 *
 * The rectangle is the departing window's, in its PARENT's coordinates,
 * which is where P9Window.x/y already are -- the recurring trap in this
 * port is confusing those with screen coordinates (see the stacking
 * section in CLAUDE.md), and here the parent is exactly the frame the
 * damage is expressed in.
 *
 * Erring towards MORE damage is the safe direction and is what this
 * does: too much costs a repaint, too little leaves stale pixels that
 * nothing here will ever correct, since there is no backing store and
 * no server to ask.
 */
static void
P9DamageUnder(Display *display, P9Window *pw)
{
    P9Window *parent;

    if (pw == NULL || pw->ispixmap || pw->parent == pw->xid)
        return;
    parent = TkP9FindWindow(pw->parent);
    if (parent == NULL)
        return;
    P9ExposeRectStacked(display, parent->xid,
            pw->x, pw->y, pw->width, pw->height);
}

int
XRaiseWindow(Display *display, Window w)
{
    P9ExposeTree(display, w);
    return 0;
}

int
XLowerWindow(Display *display, Window w)
{
    /*
     * Lowering uncovers the siblings that were beneath, so they are the
     * ones that must repaint -- and the easiest correct answer is to
     * expose everything sharing this parent.
     */
    P9Window *pw = TkP9FindWindow(w);
    int i;

    if (pw == NULL)
        return 0;
    for (i = 0; i < gP9.nwins; i++) {
        P9Window *c = &gP9.wins[i];
        if (c->inuse && !c->ispixmap && c->parent == pw->parent)
            P9ExposeTree(display, c->xid);
    }
    return 0;
}

int
XReparentWindow(Display *display, Window w, Window p, int x, int y)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) { pw->parent = p; pw->x = x; pw->y = y; }
    return 0;
}

/* ------------------------------------------------------------------ */
/* Window geometry                                                     */
/* ------------------------------------------------------------------ */

/*
 * Tell whoever is watching that the window moved or changed size. On X
 * the server does this, and Tk's toplevel geometry code depends on it:
 * <Configure> bindings, and every widget that relays out when its own
 * size changes, arrive through here.
 *
 * XMoveWindow and XMoveResizeWindow used to update the window table
 * silently, so a toplevel resize was invisible to Tk.
 */
static void
P9ReportConfigure(Display *display, Window w, P9Window *pw)
{
    XEvent ev;

    memset(&ev, 0, sizeof(ev));
    ev.type                     = ConfigureNotify;
    ev.xconfigure.display       = display;
    ev.xconfigure.event         = w;
    ev.xconfigure.window        = w;
    ev.xconfigure.x             = pw->x;
    ev.xconfigure.y             = pw->y;
    ev.xconfigure.width         = pw->width;
    ev.xconfigure.height        = pw->height;
    ev.xconfigure.border_width  = pw->border_width;
    TkP9EnqueueEvent(&ev);
}

/*
 * A configure request that changes nothing reports nothing.
 *
 * X generates a ConfigureNotify when a window is *actually*
 * reconfigured; moving a window to where it already is is silent. That
 * is not a detail -- Tk counts these events, and code that relays out on
 * <Configure> is written expecting one per real change.
 *
 * geometry-4.7 is the case. Tk_MaintainGeometry registers a placed
 * window with EVERY master between it and its parent, so moving .f
 * runs the callback more than once and .b1 is moved to the same place
 * each time after the first. The test wants
 *
 *	init configure |
 *
 * and got "init configure configure |". WmUpdateGeometry in
 * tkPlan9Wm.c already carries this rule, for the same reason and
 * against a worse symptom: without it, resize -> Configure ->
 * re-request loops.
 */
int
XResizeWindow(Display *display, Window w,
              unsigned int width, unsigned int height)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw) return 0;
    if ((int)width  < 1) width  = 1;
    if ((int)height < 1) height = 1;
    if (pw->width == (int)width && pw->height == (int)height)
	return 0;
    pw->width  = (int)width;
    pw->height = (int)height;
    P9ReportConfigure(display, w, pw);
    return 0;
}

int
XMoveWindow(Display *display, Window w, int x, int y)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw) return 0;
    if (pw->x == x && pw->y == y)
	return 0;
    pw->x = x; pw->y = y;
    P9ReportConfigure(display, w, pw);
    return 0;
}

int
XMoveResizeWindow(Display *display, Window w,
                  int x, int y, unsigned int width, unsigned int height)
{
    P9Window *pw = TkP9FindWindow(w);
    int nw, nh;
    (void)display;
    if (!pw) return 0;
    nw = (int)width  > 0 ? (int)width  : 1;
    nh = (int)height > 0 ? (int)height : 1;
    if (pw->x == x && pw->y == y && pw->width == nw && pw->height == nh)
	return 0;
    pw->x = x; pw->y = y;
    pw->width  = nw;
    pw->height = nh;
    P9ReportConfigure(display, w, pw);
    return 0;
}

int
XConfigureWindow(Display *display, Window w,
                 unsigned int value_mask, XWindowChanges *values)
{
    P9Window *pw = TkP9FindWindow(w);

    if (!pw || !values) return 0;
    if (value_mask & CWX)           pw->x            = values->x;
    if (value_mask & CWY)           pw->y            = values->y;
    if (value_mask & CWWidth)       pw->width        = values->width  > 0 ? values->width  : 1;
    if (value_mask & CWHeight)      pw->height       = values->height > 0 ? values->height : 1;
    if (value_mask & CWBorderWidth) pw->border_width = values->border_width;

    /*
     * CWStackMode is how "raise"/"lower" reaches a NON-TOPLEVEL. Tk
     * reorders parentPtr->childList itself and then tells the server
     * with this call (tkWindow.c Tk_RestackWindow); only a toplevel
     * goes through TkWmRestackToplevel and so through XRaiseWindow.
     *
     * That is why raising a widget among its siblings repainted
     * nothing here while raising a toplevel worked -- and why the
     * stacking tests still passed: Tk_CoordsToWindow answers from Tk's
     * own childList, so the HIT TEST was right and only the pixels were
     * stale. Exactly the trap the stacking section in CLAUDE.md warns
     * about, met from the other side.
     *
     * The order changed, so everything this window overlaps has to
     * repaint, itself included -- damage its rectangle in the parent.
     */
    if ((value_mask & CWStackMode) && pw->mapped)
        P9DamageUnder(display, pw);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Window attributes                                                   */
/* ------------------------------------------------------------------ */

int
XChangeWindowAttributes(Display *display, Window w,
                        unsigned long valuemask, XSetWindowAttributes *attr)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw || !attr) return 0;
    if (valuemask & CWBackPixel)
        pw->bg_pixel = TkP9XColorStructToRGBA(attr->background_pixel);
    if (valuemask & CWBorderPixel)
        pw->border_pixel = TkP9XColorStructToRGBA(attr->border_pixel);
    if (valuemask & CWEventMask)
        pw->event_mask = attr->event_mask;
    if (valuemask & CWColormap)
        pw->colormap = attr->colormap;
    return 0;
}

int
XSetWindowBackground(Display *display, Window w, unsigned long bg)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) pw->bg_pixel = TkP9XColorStructToRGBA(bg);
    return 0;
}

int
XSetWindowBackgroundPixmap(Display *display, Window w, Pixmap pixmap)
{
    (void)display; (void)w; (void)pixmap;
    return 0;
}

int
XSetWindowBorder(Display *display, Window w, unsigned long border)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) pw->border_pixel = TkP9XColorStructToRGBA(border);
    return 0;
}

int
XSetWindowBorderPixmap(Display *display, Window w, Pixmap pixmap)
{
    (void)display; (void)w; (void)pixmap;
    return 0;
}

int
XSetWindowBorderWidth(Display *display, Window w, unsigned int bw)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) pw->border_width = (int)bw;
    return 0;
}

int
XSetWindowColormap(Display *display, Window w, Colormap cmap)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) pw->colormap = cmap;
    return 0;
}

int
XSelectInput(Display *display, Window w, long event_mask)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) pw->event_mask = event_mask;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Window information queries                                          */
/* ------------------------------------------------------------------ */

Status
XGetWindowAttributes(Display *display, Window w, XWindowAttributes *attr)
{
    P9Window *pw = TkP9FindWindow(w);
    if (!attr) return 0;
    memset(attr, 0, sizeof(*attr));
    if (!pw) {
        attr->width  = gP9.screenw;
        attr->height = gP9.screenh;
        attr->map_state = IsViewable;
    } else {
        attr->x             = pw->x;
        attr->y             = pw->y;
        attr->width         = pw->width;
        attr->height        = pw->height;
        attr->border_width  = pw->border_width;
        attr->depth         = 32;
        attr->map_state     = pw->mapped ? IsViewable : IsUnmapped;
        attr->colormap      = pw->colormap;
    }
    attr->visual        = DefaultVisual(display, DefaultScreen(display));
    attr->root          = TKP9_ROOT_XID;
    attr->screen        = ScreenOfDisplay(display, DefaultScreen(display));
    attr->class         = InputOutput;
    attr->all_event_masks = 0xFFFFFF;
    attr->do_not_propagate_mask = 0;
    attr->override_redirect = False;
    return 1;
}

Status
XGetGeometry(Display *display, Drawable d,
             Window *root_return, int *x_return, int *y_return,
             unsigned int *width_return, unsigned int *height_return,
             unsigned int *border_width_return, unsigned int *depth_return)
{
    P9Window *pw = TkP9FindWindow((Window)d);
    (void)display;
    if (root_return)        *root_return        = TKP9_ROOT_XID;
    if (pw) {
        if (x_return)           *x_return           = pw->x;
        if (y_return)           *y_return           = pw->y;
        if (width_return)       *width_return        = (unsigned)pw->width;
        if (height_return)      *height_return       = (unsigned)pw->height;
        if (border_width_return)*border_width_return = (unsigned)pw->border_width;
    } else {
        if (x_return)           *x_return           = 0;
        if (y_return)           *y_return           = 0;
        if (width_return)       *width_return        = (unsigned)gP9.screenw;
        if (height_return)      *height_return       = (unsigned)gP9.screenh;
        if (border_width_return)*border_width_return = 0;
    }
    if (depth_return) *depth_return = 32;
    return 1;
}

Status
XQueryTree(Display *display, Window w,
           Window *root_return, Window *parent_return,
           Window **children_return, unsigned int *nchildren_return)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (root_return)     *root_return     = TKP9_ROOT_XID;
    if (parent_return)   *parent_return   = pw ? pw->parent : 0;
    if (children_return) *children_return = NULL;
    if (nchildren_return)*nchildren_return = 0;
    return 1;
}

Bool
XTranslateCoordinates(Display *display,
                      Window src_w, Window dest_w,
                      int src_x, int src_y,
                      int *dest_x_return, int *dest_y_return,
                      Window *child_return)
{
    P9Window *src  = TkP9FindWindow(src_w);
    P9Window *dest = TkP9FindWindow(dest_w);
    int abs_x, abs_y;
    (void)display;

    /* Compute absolute coords of the point in src */
    abs_x = src_x + (src  ? src->x  : 0);
    abs_y = src_y + (src  ? src->y  : 0);

    /* Subtract dest origin */
    if (dest_x_return) *dest_x_return = abs_x - (dest ? dest->x : 0);
    if (dest_y_return) *dest_y_return = abs_y - (dest ? dest->y : 0);
    if (child_return)  *child_return  = None;
    return True;
}

Window
XRootWindow(Display *display, int screen)
{
    (void)display; (void)screen;
    return TKP9_ROOT_XID;
}

Bool
XQueryPointer(Display *display, Window w,
              Window *root_return, Window *child_return,
              int *root_x_return, int *root_y_return,
              int *win_x_return, int *win_y_return,
              unsigned int *mask_return)
{
    int rx = gP9.lastmouse.x;
    int ry = gP9.lastmouse.y;
    int ox = 0, oy = 0;
    (void)display;

    /*
     * The window-relative coordinates need the offset of w from the
     * screen, which is the accumulated offset up the parent chain --
     * P9Window.x/.y are relative to the parent alone. Subtracting
     * pw->x here was the same mistake WindowAtPoint and
     * GenerateMouseEvent made, and it is right only for a child of the
     * root: for anything nested the answer was short by every
     * ancestor's offset.
     */
    TkP9WindowOffset(w, &ox, &oy);

    if (root_return)  *root_return  = TKP9_ROOT_XID;
    if (child_return) *child_return = None;
    if (root_x_return) *root_x_return = rx;
    if (root_y_return) *root_y_return = ry;
    if (win_x_return)  *win_x_return  = rx - ox;
    if (win_y_return)  *win_y_return  = ry - oy;
    if (mask_return) {
        unsigned m = 0;
        if (gP9.lastmouse.buttons & 1) m |= Button1Mask;
        if (gP9.lastmouse.buttons & 2) m |= Button2Mask;
        if (gP9.lastmouse.buttons & 4) m |= Button3Mask;
        *mask_return = m;
    }
    return True;
}

/* ------------------------------------------------------------------ */
/* Misc display ops                                                    */
/* ------------------------------------------------------------------ */

int
XBell(Display *display, int percent)
{
    (void)display; (void)percent;
    return 0;
}

int
XForceScreenSaver(Display *display, int mode)
{
    (void)display; (void)mode;
    return 0;
}

int
XSetCommand(Display *display, Window w, char **argv, int argc)
{
    (void)display; (void)w; (void)argv; (void)argc;
    return 0;
}

int
XSetIconName(Display *display, Window w, const char *name)
{
    (void)display; (void)w; (void)name;
    return 0;
}

Status
XIconifyWindow(Display *display, Window w, int screen)
{
    (void)display; (void)w; (void)screen;
    return 0;
}

Status
XWithdrawWindow(Display *display, Window w, int screen)
{
    return XUnmapWindow(display, w);
}

/*
 * rio owns the keyboard, so there is no focus server to ask and nothing
 * tells us which window a keystroke was meant for. Tk tells us instead:
 * TkpChangeFocus calls XSetInputFocus with the toplevel it wants, and
 * GenerateKeyEvent addresses the event to whatever we last recorded.
 *
 * The event has to name a window Tk knows, not the root: Tk_HandleEvent
 * looks the window up and drops the event when there is no TkWindow for
 * it, and the root is not one -- so with the root hardwired as the
 * destination, as it was, every keystroke was discarded before
 * TkFocusKeyEvent could redirect it to the focus widget. Until Tk sets
 * a focus, fall back to the first mapped child of the root, which is
 * the one toplevel a wish normally has.
 */
Window
TkP9FocusWindow(void)
{
    P9Window *pw;
    int i;

    if (gP9.focuswin != None && gP9.focuswin != TKP9_ROOT_XID) {
        pw = TkP9FindWindow(gP9.focuswin);
        if (pw != NULL && pw->mapped && !pw->ispixmap)
            return gP9.focuswin;
    }
    for (i = 0; i < gP9.nwins; i++) {
        pw = &gP9.wins[i];
        if (pw->inuse && pw->mapped && !pw->ispixmap &&
            pw->xid != TKP9_ROOT_XID && pw->parent == TKP9_ROOT_XID)
            return pw->xid;
    }
    return TKP9_ROOT_XID;
}

int
XSetInputFocus(Display *display, Window w, int revert, Time t)
{
    (void)display; (void)revert; (void)t;
    gP9.focuswin = w;
    return 0;
}

int
XGetInputFocus(Display *display, Window *focus_return, int *revert_return)
{
    (void)display;
    if (focus_return)  *focus_return  = TkP9FocusWindow();
    if (revert_return) *revert_return = RevertToParent;
    return 0;
}

int
XGrabServer(Display *display)
{
    (void)display;
    return 0;
}

int
XUngrabServer(Display *display)
{
    (void)display;
    return 0;
}

int
XNoOp(Display *display)
{
    (void)display;
    return 0;
}

XAfterFunction
XSynchronize(Display *display, Bool onoff)
{
    (void)display; (void)onoff;
    return NULL;
}

int
XSync(Display *display, Bool discard)
{
    (void)discard;
    tkp9_flush();
    return 0;
}

int
XFree(void *data)
{
    if (data) ckfree(data);
    return 0;
}

/*
 * Move the pointer. dx,dy are relative to dw when it is given, and to
 * the current position when dw is None; the source rectangle is only
 * used to restrict when the warp happens, and Tk always passes an empty
 * one, meaning "always".
 *
 * The event that follows is generated here rather than waited for.
 * /dev/mouse does report the move back, but Tk's own tests read
 * "winfo pointerxy" immediately afterwards, and rio's reply has not
 * arrived by then.
 */
int
XWarpPointer(Display *d, Window s, Window dw,
             int sx, int sy, unsigned sw, unsigned sh,
             int dx, int dy)
{
    int ox, oy, x, y;
    (void)s; (void)sx; (void)sy; (void)sw; (void)sh;

    if (dw == None) {
        x = gP9.lastmouse.x + dx;
        y = gP9.lastmouse.y + dy;
    } else {
        TkP9WindowOffset(dw, &ox, &oy);
        x = ox + dx;
        y = oy + dy;
    }
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= gP9.screenw) x = gP9.screenw - 1;
    if (y >= gP9.screenh) y = gP9.screenh - 1;

    if (tkp9_debug())
        fprintf(stderr, "XWarpPointer: dw=%lu dx=%d dy=%d -> screen %d,%d\n",
                (unsigned long) dw, dx, dy, x, y);

    if (tkp9_warpmouse(x, y) < 0)
        return 0;

    gP9.lastmouse.x = x;
    gP9.lastmouse.y = y;
    TkP9UpdatePointer(x, y, gP9.lastmouse.buttons);
    return 0;
}

/* ------------------------------------------------------------------ */
/* Keyboard / pointer grabs (stubs)                                   */
/* ------------------------------------------------------------------ */

int
XGrabKeyboard(Display *d, Window w, Bool owner,
              int ptr_mode, int kbd_mode, Time t)
{
    (void)d; (void)w; (void)owner;
    (void)ptr_mode; (void)kbd_mode; (void)t;
    return GrabSuccess;
}

int
XUngrabKeyboard(Display *d, Time t)
{
    (void)d; (void)t;
    return 0;
}


/* ------------------------------------------------------------------ */
/* Properties (stubs — Plan 9 has no X properties)                   */
/* ------------------------------------------------------------------ */

int
XGetWindowProperty(Display *d, Window w, Atom prop, long offset,
                   long length, Bool del, Atom req_type,
                   Atom *actual_type, int *actual_format,
                   unsigned long *nitems, unsigned long *bytes_after,
                   unsigned char **prop_return)
{
    (void)d; (void)w; (void)prop; (void)offset; (void)length;
    (void)del; (void)req_type;
    if (actual_type)   *actual_type   = None;
    if (actual_format) *actual_format = 0;
    if (nitems)        *nitems        = 0;
    if (bytes_after)   *bytes_after   = 0;
    if (prop_return)   *prop_return   = NULL;
    return BadAtom;
}

int
XChangeProperty(Display *d, Window w, Atom prop, Atom type,
                int format, int mode, const unsigned char *data, int nelements)
{
    (void)d; (void)w; (void)prop; (void)type; (void)format;
    (void)mode; (void)data; (void)nelements;
    return 0;
}

int
XDeleteProperty(Display *d, Window w, Atom prop)
{
    (void)d; (void)w; (void)prop;
    return 0;
}

Status
XGetWMColormapWindows(Display *d, Window w,
                      Window **windows_return, int *count_return)
{
    (void)d; (void)w;
    if (windows_return) *windows_return = NULL;
    if (count_return)   *count_return   = 0;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Events                                                              */
/* ------------------------------------------------------------------ */

int
XNextEvent(Display *display, XEvent *event_return)
{
    while (!TkP9DequeueEvent(event_return))
        Tcl_DoOneEvent(TCL_ALL_EVENTS);
    return 0;
}

int
XPutBackEvent(Display *display, XEvent *event)
{
    (void)display;
    TkP9EnqueueEvent(event);
    return 0;
}

int
XWindowEvent(Display *display, Window w, long event_mask, XEvent *ev)
{
    for (;;) {
        XNextEvent(display, ev);
        if (ev->xany.window == w && (ev->xany.type & event_mask))
            return 0;
        XPutBackEvent(display, ev);
    }
}

Status
XSendEvent(Display *display, Window w, Bool propagate,
           long event_mask, XEvent *ev)
{
    (void)propagate; (void)event_mask;
    ev->xany.display = display;
    ev->xany.window  = w;
    TkP9EnqueueEvent(ev);
    return True;
}

