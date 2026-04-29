/*
 * tkPlan9Event.c --
 *
 *	Event source implementation for the Plan 9 Tk backend.
 *
 *	Registers a Tcl event source that reads mouse and keyboard events
 *	from the Plan 9 window system (/dev/mouse, /dev/kbd) and converts
 *	them to X11 XEvents pushed into the Tk event queue.
 *
 *	Plan 9 mouse buttons: 1=left 2=middle 4=right (same as X11 bitmask)
 *	Plan 9 keyboard gives UTF-32 runes (Rune type).
 */

#include "tkPlan9Int.h"
#include <sys/select.h>

/* ------------------------------------------------------------------ */
/* Key mapping: Plan 9 Runes -> X11 KeySym                            */
/* ------------------------------------------------------------------ */

/*
 * Plan 9 special keys from keyboard.h use rune values in the private-use
 * area (0xF000+).  We map the most common ones; everything else is
 * passed through as-is (Unicode code point = KeySym for Latin-1 range).
 */

#define Kbs	0x08	/* backspace */
#define Kdel	0x7f
#define Kesc	0x1b
#define Knl	'\n'
#define Ktab	'\t'

/* Plan 9 extended key codes (from <keyboard.h> Kxxx constants) */
#define KUP    0xF00E
#define KDOWN  0xF00F
#define KLEFT  0xF011
#define KRIGHT 0xF012
#define KHOME  0xF013
#define KEND   0xF018
#define KPGUP  0xF019
#define KPGDN  0xF01A
#define KINS   0xF01B
#define KF1    0xF001
#define KF12   0xF00C

static KeySym
RuneToKeySym(int r)
{
    if (r >= 0xF001 && r <= 0xF00C) /* F1–F12 */
        return XK_F1 + (r - 0xF001);
    switch (r) {
    case KUP:    return XK_Up;
    case KDOWN:  return XK_Down;
    case KLEFT:  return XK_Left;
    case KRIGHT: return XK_Right;
    case KHOME:  return XK_Home;
    case KEND:   return XK_End;
    case KPGUP:  return XK_Prior;
    case KPGDN:  return XK_Next;
    case KINS:   return XK_Insert;
    case Kbs:    return XK_BackSpace;
    case Kdel:   return XK_Delete;
    case Kesc:   return XK_Escape;
    case Knl:    return XK_Return;
    case Ktab:   return XK_Tab;
    }
    /* Unicode code points map directly to Latin-1 / Unicode keysyms */
    if (r < 0x100) return (KeySym)r;
    return (KeySym)(r | 0x1000000); /* XK_Unicode range */
}

static unsigned int
ButtonToMask(int buttons)
{
    unsigned m = 0;
    if (buttons & 1) m |= Button1Mask;
    if (buttons & 2) m |= Button2Mask;
    if (buttons & 4) m |= Button3Mask;
    return m;
}

/* ------------------------------------------------------------------ */
/* Find topmost mapped window containing (x, y)                       */
/* ------------------------------------------------------------------ */

static Window
WindowAtPoint(int x, int y)
{
    int i;
    Window best = TKP9_ROOT_XID;
    /* Scan forward; last mapped window wins (topmost in paint order) */
    for (i = 0; i < gP9.nwins; i++) {
        P9Window *w = &gP9.wins[i];
        if (!w->inuse || !w->mapped) continue;
        if (w->xid == TKP9_ROOT_XID) continue;
        if (x >= w->x && x < w->x + w->width &&
            y >= w->y && y < w->y + w->height)
            best = w->xid;
    }
    return best;
}

/* ------------------------------------------------------------------ */
/* Event generation                                                    */
/* ------------------------------------------------------------------ */

static void
GenerateMouseEvent(Display *dpy, TkP9Mouse *cur)
{
    TkP9Mouse *prev = &gP9.lastmouse;
    int changed = cur->buttons ^ prev->buttons;
    XEvent ev;
    Window win;
    P9Window *pw;
    int wx, wy;
    unsigned state;

    win  = WindowAtPoint(cur->x, cur->y);
    pw   = TkP9FindWindow(win);
    wx   = cur->x - (pw ? pw->x : 0);
    wy   = cur->y - (pw ? pw->y : 0);
    state = ButtonToMask(prev->buttons);

    /* Motion */
    if (cur->x != prev->x || cur->y != prev->y) {
        memset(&ev, 0, sizeof(ev));
        ev.type                 = MotionNotify;
        ev.xmotion.display      = dpy;
        ev.xmotion.window       = win;
        ev.xmotion.root         = TKP9_ROOT_XID;
        ev.xmotion.x            = wx;
        ev.xmotion.y            = wy;
        ev.xmotion.x_root       = cur->x;
        ev.xmotion.y_root       = cur->y;
        ev.xmotion.state        = state;
        ev.xmotion.time         = cur->msec;
        ev.xmotion.is_hint      = NotifyNormal;
        TkP9EnqueueEvent(&ev);
    }

    /* Button press/release for each changed button */
    if (changed & 1) {
        int btn = Button1; int mask = Button1Mask;
        int pressed = (cur->buttons & 1) != 0;
        memset(&ev, 0, sizeof(ev));
        ev.type              = pressed ? ButtonPress : ButtonRelease;
        ev.xbutton.display   = dpy;
        ev.xbutton.window    = win;
        ev.xbutton.root      = TKP9_ROOT_XID;
        ev.xbutton.x         = wx;
        ev.xbutton.y         = wy;
        ev.xbutton.x_root    = cur->x;
        ev.xbutton.y_root    = cur->y;
        ev.xbutton.button    = btn;
        ev.xbutton.state     = pressed ? state : state | mask;
        ev.xbutton.time      = cur->msec;
        TkP9EnqueueEvent(&ev);
    }
    if (changed & 2) {
        int btn = Button2; int mask = Button2Mask;
        int pressed = (cur->buttons & 2) != 0;
        memset(&ev, 0, sizeof(ev));
        ev.type              = pressed ? ButtonPress : ButtonRelease;
        ev.xbutton.display   = dpy;
        ev.xbutton.window    = win;
        ev.xbutton.root      = TKP9_ROOT_XID;
        ev.xbutton.x         = wx;
        ev.xbutton.y         = wy;
        ev.xbutton.x_root    = cur->x;
        ev.xbutton.y_root    = cur->y;
        ev.xbutton.button    = btn;
        ev.xbutton.state     = pressed ? state : state | mask;
        ev.xbutton.time      = cur->msec;
        TkP9EnqueueEvent(&ev);
    }
    if (changed & 4) {
        int btn = Button3; int mask = Button3Mask;
        int pressed = (cur->buttons & 4) != 0;
        memset(&ev, 0, sizeof(ev));
        ev.type              = pressed ? ButtonPress : ButtonRelease;
        ev.xbutton.display   = dpy;
        ev.xbutton.window    = win;
        ev.xbutton.root      = TKP9_ROOT_XID;
        ev.xbutton.x         = wx;
        ev.xbutton.y         = wy;
        ev.xbutton.x_root    = cur->x;
        ev.xbutton.y_root    = cur->y;
        ev.xbutton.button    = btn;
        ev.xbutton.state     = pressed ? state : state | mask;
        ev.xbutton.time      = cur->msec;
        TkP9EnqueueEvent(&ev);
    }

    *prev = *cur;
}

static void
GenerateKeyEvent(Display *dpy, int rune, int press)
{
    XEvent ev;
    Window focus = TKP9_ROOT_XID;
    KeySym sym;

    sym = RuneToKeySym(rune);

    memset(&ev, 0, sizeof(ev));
    ev.type               = press ? KeyPress : KeyRelease;
    ev.xkey.display       = dpy;
    ev.xkey.window        = focus;
    ev.xkey.root          = TKP9_ROOT_XID;
    ev.xkey.keycode       = (KeyCode)(rune & 0xFF);
    ev.xkey.state         = ButtonToMask(gP9.lastmouse.buttons);
    ev.xkey.time          = (Time)(gP9.lastmouse.msec);

    /* Store keysym in the upper bits of keycode for TkpGetKeySym */
    ev.xkey.keycode = XKeysymToKeycode(dpy, sym);
    TkP9EnqueueEvent(&ev);

    /* Auto-generate KeyRelease for non-modifier keys */
    if (press) {
        ev.type = KeyRelease;
        TkP9EnqueueEvent(&ev);
    }
}

static void
GenerateResizeEvent(Display *dpy)
{
    int w = tkp9_screenwidth();
    int h = tkp9_screenheight();
    P9Window *root;
    XEvent ev;

    gP9.screenw = w;
    gP9.screenh = h;

    /* Update screen info */
    {
        _XPrivDisplay pd = (_XPrivDisplay)dpy;
        if (pd && pd->screens) {
            pd->screens->width  = w;
            pd->screens->height = h;
        }
    }

    /* Update root window */
    root = TkP9FindWindow(TKP9_ROOT_XID);
    if (root) { root->width = w; root->height = h; }

    /* Send ConfigureNotify to root */
    memset(&ev, 0, sizeof(ev));
    ev.type                    = ConfigureNotify;
    ev.xconfigure.display      = dpy;
    ev.xconfigure.event        = TKP9_ROOT_XID;
    ev.xconfigure.window       = TKP9_ROOT_XID;
    ev.xconfigure.x            = 0;
    ev.xconfigure.y            = 0;
    ev.xconfigure.width        = w;
    ev.xconfigure.height       = h;
    TkP9EnqueueEvent(&ev);
}

/* ------------------------------------------------------------------ */
/* Poll for pending Plan 9 events (non-blocking)                       */
/* ------------------------------------------------------------------ */

static void
PollP9Events(Display *dpy)
{
    TkP9Mouse mouse;
    int rune;
    struct timeval tv = {0, 0};
    fd_set rset;
    int mfd, kfd, maxfd;

    if (!gP9.initialized) return;

    mfd = gP9.mousefd;
    kfd = gP9.kbdfd;
    if (mfd < 0 && kfd < 0) return;

    FD_ZERO(&rset);
    maxfd = 0;
    if (mfd >= 0) { FD_SET(mfd, &rset); if (mfd > maxfd) maxfd = mfd; }
    if (kfd >= 0) { FD_SET(kfd, &rset); if (kfd > maxfd) maxfd = kfd; }

    if (select(maxfd + 1, &rset, NULL, NULL, &tv) <= 0)
        return;

    /* Check resize first */
    if (tkp9_checkresized())
        GenerateResizeEvent(dpy);

    /* Mouse */
    if (mfd >= 0 && FD_ISSET(mfd, &rset)) {
        if (tkp9_readmouse(&mouse) == 0)
            GenerateMouseEvent(dpy, &mouse);
    }

    /* Keyboard */
    if (kfd >= 0 && FD_ISSET(kfd, &rset)) {
        rune = tkp9_readkey();
        if (rune > 0)
            GenerateKeyEvent(dpy, rune, 1);
    }
}

/* ------------------------------------------------------------------ */
/* Tcl event source callbacks                                          */
/* ------------------------------------------------------------------ */

static void
DisplaySetupProc(void *clientData, int flags)
{
    Tcl_Time blockTime = {0, 0};
    (void)clientData;

    if (!(flags & TCL_WINDOW_EVENTS)) return;
    if (gP9.initialized)
        Tcl_SetMaxBlockTime(&blockTime);
}

static void
DisplayCheckProc(void *clientData, int flags)
{
    TkDisplay *dispPtr;
    Display   *dpy;

    (void)clientData;
    if (!(flags & TCL_WINDOW_EVENTS)) return;

    dispPtr = TkGetDisplayList();
    if (!dispPtr) return;
    dpy = dispPtr->display;

    PollP9Events(dpy);

    /* Transfer from our queue into Tk's queue */
    while (TkP9EventsPending()) {
        XEvent ev;
        if (TkP9DequeueEvent(&ev)) {
            Tk_QueueWindowEvent(&ev, TCL_QUEUE_TAIL);
        }
    }
}

/* ------------------------------------------------------------------ */
/* TkCreateXEventSource / TkpSync                                      */
/* ------------------------------------------------------------------ */

void
TkCreateXEventSource(void)
{
    if (!gP9.eventSourceAdded) {
        gP9.eventSourceAdded = 1;
        Tcl_CreateEventSource(DisplaySetupProc, DisplayCheckProc, NULL);
    }
}

void
TkpSync(Display *display)
{
    XSync(display, False);
}

/* ------------------------------------------------------------------ */
/* Key mapping stubs (minimal)                                         */
/* ------------------------------------------------------------------ */

void
TkpInitKeymapInfo(TkDisplay *dispPtr)
{
    dispPtr->modeModMask = 0;
    dispPtr->altModMask  = Mod1Mask;
    dispPtr->metaModMask = Mod4Mask;
}

KeyCode
XKeysymToKeycode(Display *display, KeySym sym)
{
    (void)display;
    /* Simple mapping: use low byte of keysym as keycode */
    if (sym < 0x100) return (KeyCode)sym;
    return (KeyCode)(sym & 0xFF);
}

KeySym
XKeycodeToKeysym(Display *display, unsigned int keycode, int index)
{
    (void)display; (void)index;
    return (KeySym)keycode;
}

KeySym
XkbKeycodeToKeysym(Display *display, unsigned int keycode, int group, int level)
{
    (void)display; (void)group; (void)level;
    return (KeySym)keycode;
}

typedef struct { const char *name; KeySym value; } KsEntry;
static const KsEntry ksTable[] = {
#include "../generic/ks_names.h"
    {NULL, 0}
};

KeySym
XStringToKeysym(const char *string)
{
    const KsEntry *p;
    if (!string || !string[0])
        return NoSymbol;
    for (p = ksTable; p->name; p++) {
        if (strcmp(p->name, string) == 0)
            return p->value;
    }
    return NoSymbol;
}

char *
XKeysymToString(KeySym keysym)
{
    static char buf[2];
    const KsEntry *p;
    /* Check named keysyms table first */
    for (p = ksTable; p->name; p++) {
        if (p->value == keysym)
            return (char *)p->name;
    }
    /* Fall back to single printable ASCII */
    if (keysym >= 0x20 && keysym < 0x7f) {
        buf[0] = (char)keysym;
        buf[1] = '\0';
        return buf;
    }
    return (char *)"";
}

XModifierKeymap *
XGetModifierMapping(Display *display)
{
    XModifierKeymap *map;
    (void)display;
    map = (XModifierKeymap *) ckalloc(sizeof(XModifierKeymap));
    map->max_keypermod = 0;
    map->modifiermap   = NULL;
    return map;
}

int
XFreeModifiermap(XModifierKeymap *map)
{
    if (map) {
        if (map->modifiermap) ckfree(map->modifiermap);
        ckfree(map);
    }
    return 0;
}

int
XmbLookupString(XIC xic, XKeyPressedEvent *event,
                char *buf, int nbytes,
                KeySym *sym_return, Status *status_return)
{
    (void)xic;
    if (sym_return)    *sym_return    = (KeySym)event->keycode;
    if (status_return) *status_return = XLookupKeySym;
    return 0;
}

int
XRefreshKeyboardMapping(XMappingEvent *ev)
{
    (void)ev;
    return 0;
}
