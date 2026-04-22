/*
 * tkPlan9Int.h --
 *
 *	Internal header for the Plan 9 Tk backend.
 *
 *	Defines struct _XDisplay (the concrete body behind the opaque
 *	X11 Display typedef), the Plan 9 window table (P9Window), and
 *	global state shared among Plan 9 backend source files.
 *
 *	All Plan 9 backend files include this header INSTEAD OF
 *	tkUnixInt.h.  Only tkPlan9DrawImpl.c may include <draw.h>.
 */

#ifndef _TKP9INT_H
#define _TKP9INT_H

/*
 * XLIB_ILLEGAL_ACCESS causes Xlib.h to use the real struct _XDisplay tag
 * for its anonymous struct, giving us access to Display fields directly.
 * Without it _XDisplay would remain an incomplete type.
 */
#define XLIB_ILLEGAL_ACCESS

#ifndef _TKINT
#   include "tkInt.h"
#endif

#include "tkP9Draw.h"

/* ------------------------------------------------------------------ */
/* Maximum number of Tk "windows" (all map onto Plan 9's single window) */
/* ------------------------------------------------------------------ */

#define TKP9_MAX_WINDOWS 2048

/* Root window XID */
#define TKP9_ROOT_XID   10

/* ------------------------------------------------------------------ */
/* Per-window record                                                   */
/* ------------------------------------------------------------------ */

typedef struct P9Window {
    int       inuse;
    Window    xid;
    Window    parent;
    int       x, y, width, height;
    int       mapped;
    int       border_width;
    unsigned long bg_pixel;		/* background fill colour (Plan 9 RGBA) */
    unsigned long border_pixel;
    long      event_mask;
    Colormap  colormap;
} P9Window;

/* ------------------------------------------------------------------ */
/* Global Plan 9 display state (singleton — Plan 9 has one display)   */
/* ------------------------------------------------------------------ */

typedef struct P9DisplayState {
    int          mousefd;
    int          kbdfd;
    int          screenw;
    int          screenh;
    int          initialized;
    /* Next XID to allocate (starts at TKP9_ROOT_XID + 1) */
    XID          next_xid;
    /* Window table */
    P9Window     wins[TKP9_MAX_WINDOWS];
    int          nwins;
    /* Pending X events queue (simple ring buffer) */
    XEvent       evqueue[256];
    int          evhead;
    int          evtail;
    /* Last known mouse state */
    TkP9Mouse    lastmouse;
    int          lastbuttons;
    /* Display/screen pointers (set by XkbOpenDisplay) */
    Display     *xdisplay;
    /* Tcl event source state */
    int          eventSourceAdded;
} P9DisplayState;

extern P9DisplayState gP9;

/* ------------------------------------------------------------------ */
/* Window table helpers                                                */
/* ------------------------------------------------------------------ */

extern P9Window *TkP9FindWindow(Window xid);
extern P9Window *TkP9AllocWindow(void);
extern void      TkP9FreeWindow(Window xid);

/* ------------------------------------------------------------------ */
/* Event queue helpers                                                 */
/* ------------------------------------------------------------------ */

extern void TkP9EnqueueEvent(XEvent *ev);
extern int  TkP9DequeueEvent(XEvent *ev);
extern int  TkP9EventsPending(void);

/* ------------------------------------------------------------------ */
/* Colour conversion                                                   */
/* ------------------------------------------------------------------ */

/* XColor pixel (16-bit per component) -> Plan 9 RGBA (8-bit per component) */
static inline unsigned long
TkP9XColorToRGBA(unsigned long pixel)
{
    return pixel | 0xFF;	/* pixel already in 0xRRGGBBAA, set alpha=0xFF */
}

/* XColor struct -> Plan 9 RGBA */
static inline unsigned long
TkP9XColorStructToRGBA(unsigned long pixel)
{
    /* pixel from XAllocColor is packed 0x00RRGGBB (8-bit each) */
    unsigned r = (pixel >> 16) & 0xFF;
    unsigned g = (pixel >>  8) & 0xFF;
    unsigned b =  pixel        & 0xFF;
    return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

#endif /* _TKP9INT_H */
