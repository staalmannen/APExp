/*
 * tkPlan9Color.c --
 *
 *	Color management for the Plan 9 Tk backend.
 *
 *	Tk colors are represented as XColor structs with 16-bit per channel.
 *	We convert to Plan 9's 32-bit RGBA (0xRRGGBBAA) when drawing.
 *
 *	XAllocColor reserves a "pixel" value; for Plan 9 we pack
 *	0x00RRGGBB into the pixel field (8 bits per channel).
 */

#include "tkPlan9Int.h"

/* ------------------------------------------------------------------ */
/* Internal: parse X11 colour names via xcolors.c (xlib/)            */
/* ------------------------------------------------------------------ */

/* XParseColor is provided by xlib/xcolors.c — it fills in an XColor. */

/* ------------------------------------------------------------------ */
/* XAllocColor                                                        */
/* ------------------------------------------------------------------ */

Status
XAllocColor(Display *display, Colormap colormap, XColor *screen_in_out)
{
    (void)display; (void)colormap;
    if (!screen_in_out) return 0;
    /* Pack 16-bit per channel into 8-bit per channel pixel */
    screen_in_out->pixel =
        ((screen_in_out->red   >> 8) << 16) |
        ((screen_in_out->green >> 8) <<  8) |
        ((screen_in_out->blue  >> 8));
    return 1;
}

/* ------------------------------------------------------------------ */
/* XFreeColors                                                        */
/* ------------------------------------------------------------------ */

int
XFreeColors(Display *display, Colormap colormap,
            unsigned long *pixels, int npixels, unsigned long planes)
{
    (void)display; (void)colormap; (void)pixels;
    (void)npixels; (void)planes;
    return 0;
}

/* ------------------------------------------------------------------ */
/* XQueryColors                                                       */
/* ------------------------------------------------------------------ */

int
XQueryColors(Display *display, Colormap colormap,
             XColor *defs_in_out, int ncolors)
{
    int i;
    (void)display; (void)colormap;
    for (i = 0; i < ncolors; i++) {
        unsigned long p = defs_in_out[i].pixel;
        defs_in_out[i].red   = ((p >> 16) & 0xFF) * 257;
        defs_in_out[i].green = ((p >>  8) & 0xFF) * 257;
        defs_in_out[i].blue  = ( p        & 0xFF) * 257;
        defs_in_out[i].flags = DoRed | DoGreen | DoBlue;
    }
    return 0;
}

/* ------------------------------------------------------------------ */
/* XFreeColormap / XCreateColormap                                    */
/* ------------------------------------------------------------------ */

int
XFreeColormap(Display *display, Colormap colormap)
{
    (void)display; (void)colormap;
    return 0;
}

Colormap
XCreateColormap(Display *display, Window w, Visual *visual, int alloc)
{
    (void)display; (void)w; (void)visual; (void)alloc;
    return DefaultColormap(display, DefaultScreen(display));
}

/* ------------------------------------------------------------------ */
/* XLookupColor                                                       */
/* ------------------------------------------------------------------ */

Status
XLookupColor(Display *display, Colormap colormap,
             const char *color_name,
             XColor *exact_def_return,
             XColor *screen_def_return)
{
    if (!XParseColor(display, colormap, color_name, exact_def_return))
        return 0;
    if (screen_def_return) *screen_def_return = *exact_def_return;
    XAllocColor(display, colormap, screen_def_return);
    return 1;
}

/* ------------------------------------------------------------------ */
/* TkpGetColor (Tk platform API)                                      */
/* ------------------------------------------------------------------ */

TkColor *
TkpGetColor(Tk_Window tkwin, Tk_Uid name)
{
    Display  *display = Tk_Display(tkwin);
    Colormap  colormap = Tk_Colormap(tkwin);
    TkColor  *tkColPtr;
    XColor    xcolor;

    if (!XParseColor(display, colormap, name, &xcolor))
        return NULL;

    XAllocColor(display, colormap, &xcolor);

    tkColPtr = (TkColor *) ckalloc(sizeof(TkColor));
    tkColPtr->color = xcolor;
    return tkColPtr;
}

/* ------------------------------------------------------------------ */
/* TkpGetColorByValue                                                 */
/* ------------------------------------------------------------------ */

TkColor *
TkpGetColorByValue(Tk_Window tkwin, XColor *colorPtr)
{
    Display  *display = Tk_Display(tkwin);
    Colormap  colormap = Tk_Colormap(tkwin);
    TkColor  *tkColPtr;

    tkColPtr = (TkColor *) ckalloc(sizeof(TkColor));
    tkColPtr->color = *colorPtr;
    XAllocColor(display, colormap, &tkColPtr->color);
    return tkColPtr;
}

/* ------------------------------------------------------------------ */
/* TkpFreeColor                                                       */
/* ------------------------------------------------------------------ */

void
TkpFreeColor(TkColor *tkColPtr)
{
    ckfree(tkColPtr);
}
