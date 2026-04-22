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

P9Window *
TkP9AllocWindow(void)
{
    int i;
    for (i = 0; i < TKP9_MAX_WINDOWS; i++) {
        if (!gP9.wins[i].inuse) {
            memset(&gP9.wins[i], 0, sizeof(P9Window));
            gP9.wins[i].inuse = 1;
            if (i >= gP9.nwins) gP9.nwins = i + 1;
            return &gP9.wins[i];
        }
    }
    return NULL;
}

void
TkP9FreeWindow(Window xid)
{
    P9Window *w = TkP9FindWindow(xid);
    if (w) w->inuse = 0;
}

/* ------------------------------------------------------------------ */
/* Event queue                                                         */
/* ------------------------------------------------------------------ */

void
TkP9EnqueueEvent(XEvent *ev)
{
    int next = (gP9.evtail + 1) & 255;
    if (next == gP9.evhead) return; /* drop if full */
    gP9.evqueue[gP9.evtail] = *ev;
    gP9.evtail = next;
}

int
TkP9DequeueEvent(XEvent *ev)
{
    if (gP9.evhead == gP9.evtail) return 0;
    *ev = gP9.evqueue[gP9.evhead];
    gP9.evhead = (gP9.evhead + 1) & 255;
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

int
XDestroyWindow(Display *display, Window w)
{
    (void)display;
    TkP9FreeWindow(w);
    return 0;
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

    /* Send MapNotify */
    memset(&ev, 0, sizeof(ev));
    ev.type                    = MapNotify;
    ev.xmap.display            = display;
    ev.xmap.event              = w;
    ev.xmap.window             = w;
    ev.xmap.override_redirect  = False;
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

    memset(&ev, 0, sizeof(ev));
    ev.type              = UnmapNotify;
    ev.xunmap.display    = display;
    ev.xunmap.event      = w;
    ev.xunmap.window     = w;
    TkP9EnqueueEvent(&ev);
    return 0;
}

int
XMapRaised(Display *display, Window w)
{
    XRaiseWindow(display, w);
    return XMapWindow(display, w);
}

int
XRaiseWindow(Display *display, Window w)
{
    (void)display; (void)w;
    return 0;
}

int
XLowerWindow(Display *display, Window w)
{
    (void)display; (void)w;
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

int
XResizeWindow(Display *display, Window w,
              unsigned int width, unsigned int height)
{
    P9Window *pw = TkP9FindWindow(w);
    XEvent ev;
    (void)display;
    if (!pw) return 0;
    if ((int)width  < 1) width  = 1;
    if ((int)height < 1) height = 1;
    pw->width  = (int)width;
    pw->height = (int)height;

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
    return 0;
}

int
XMoveWindow(Display *display, Window w, int x, int y)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (pw) { pw->x = x; pw->y = y; }
    return 0;
}

int
XMoveResizeWindow(Display *display, Window w,
                  int x, int y, unsigned int width, unsigned int height)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw) return 0;
    pw->x = x; pw->y = y;
    pw->width  = (int)width  > 0 ? (int)width  : 1;
    pw->height = (int)height > 0 ? (int)height : 1;
    return 0;
}

int
XConfigureWindow(Display *display, Window w,
                 unsigned int value_mask, XWindowChanges *values)
{
    P9Window *pw = TkP9FindWindow(w);
    (void)display;
    if (!pw || !values) return 0;
    if (value_mask & CWX)           pw->x            = values->x;
    if (value_mask & CWY)           pw->y            = values->y;
    if (value_mask & CWWidth)       pw->width        = values->width  > 0 ? values->width  : 1;
    if (value_mask & CWHeight)      pw->height       = values->height > 0 ? values->height : 1;
    if (value_mask & CWBorderWidth) pw->border_width = values->border_width;
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
    P9Window *pw = TkP9FindWindow(w);
    int rx = gP9.lastmouse.x;
    int ry = gP9.lastmouse.y;
    (void)display;

    if (root_return)  *root_return  = TKP9_ROOT_XID;
    if (child_return) *child_return = None;
    if (root_x_return) *root_x_return = rx;
    if (root_y_return) *root_y_return = ry;
    if (win_x_return)  *win_x_return  = rx - (pw ? pw->x : 0);
    if (win_y_return)  *win_y_return  = ry - (pw ? pw->y : 0);
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

int
XSetInputFocus(Display *display, Window w, int revert, Time t)
{
    (void)display; (void)w; (void)revert; (void)t;
    return 0;
}

int
XGetInputFocus(Display *display, Window *focus_return, int *revert_return)
{
    (void)display;
    if (focus_return)  *focus_return  = TKP9_ROOT_XID;
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

int
XWarpPointer(Display *d, Window s, Window dw,
             int sx, int sy, unsigned sw, unsigned sh,
             int dx, int dy)
{
    (void)d; (void)s; (void)dw;
    (void)sx; (void)sy; (void)sw; (void)sh;
    (void)dx; (void)dy;
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

int
XGrabPointer(Display *d, Window w, Bool owner, unsigned event_mask,
             int ptr_mode, int kbd_mode, Window confine, Cursor cursor, Time t)
{
    (void)d; (void)w; (void)owner; (void)event_mask;
    (void)ptr_mode; (void)kbd_mode; (void)confine; (void)cursor; (void)t;
    return GrabSuccess;
}

int
XUngrabPointer(Display *d, Time t)
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

