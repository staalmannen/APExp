/*
 * tkPlan9Font.c --
 *
 *	Font management for the Plan 9 Tk backend.
 *
 *	Tk's generic font layer (tkFont.c) calls:
 *	  TkpFontPkgInit	  -- one-time initialization
 *	  TkpGetNativeFont	  -- look up by native name
 *	  TkpGetFontFromAttributes -- create from TkFontAttributes
 *	  TkpDeleteFont		  -- free a font
 *	  TkpGetFontFamilies	  -- list available families
 *	  Tk_MeasureChars	  -- measure a string
 *	  Tk_DrawChars		  -- draw a string
 *
 *	Plan 9 fonts are identified by their file path, e.g.
 *	  /lib/font/bit/fixed/unicode.6x13.font
 *	We map Tk's logical font names to the closest Plan 9 equivalent.
 */

#include "tkPlan9Int.h"
#include <stdio.h>
#include <stdint.h>
#include "tkFont.h"

/* ------------------------------------------------------------------ */
/* Plan 9 font handle embedded in TkFont                              */
/* ------------------------------------------------------------------ */

typedef struct {
    TkFont   header;		/* Must be first — Tk casts this */
    void    *p9font;		/* TkP9Fnt (opaque Plan 9 Font*) */
    int      ascent;
    int      descent;
    int      height;
} P9Font;

/* ------------------------------------------------------------------ */
/* Name -> Plan 9 path heuristic                                       */
/* ------------------------------------------------------------------ */

static const char *
MapFontName(const char *name)
{
    /* Tk's logical font names */
    if (!name || !*name) goto dflt;
    if (strstr(name, "Fixed") || strstr(name, "fixed") ||
        strstr(name, "Courier") || strstr(name, "courier") ||
        strstr(name, "Mono") || strstr(name, "mono"))
        return "/lib/font/bit/fixed/unicode.6x13.font";
    if (strstr(name, "Helvetica") || strstr(name, "helvetica") ||
        strstr(name, "Arial") || strstr(name, "Sans") || strstr(name, "sans"))
        return "/lib/font/bit/pelm/unicode.9.font";
    if (strstr(name, "Times") || strstr(name, "times") ||
        strstr(name, "Serif") || strstr(name, "serif"))
        return "/lib/font/bit/vga/unicode.8x16.font";
dflt:
    return NULL;  /* use Plan 9's default font */
}

/* ------------------------------------------------------------------ */
/* TkpFontPkgInit                                                     */
/* ------------------------------------------------------------------ */

void
TkpFontPkgInit(TkMainInfo *mainPtr)
{
    (void)mainPtr;
}

/* ------------------------------------------------------------------ */
/* TkpGetNativeFont                                                   */
/* ------------------------------------------------------------------ */

TkFont *
TkpGetNativeFont(Tk_Window tkwin, const char *name)
{
    P9Font *p9f;
    const char *path;
    void *fnt;
    (void)tkwin;

    path = MapFontName(name);
    fnt  = tkp9_openfont(path);  /* returns default if path==NULL */
    if (!fnt) return NULL;

    p9f = (P9Font *) ckalloc(sizeof(P9Font));
    memset(p9f, 0, sizeof(P9Font));
    p9f->p9font  = fnt;
    p9f->ascent  = tkp9_fontascent(fnt);
    p9f->descent = tkp9_fontdescent(fnt);
    p9f->height  = tkp9_fontheight(fnt);

    p9f->header.fa.family     = Tk_GetUid(name);
    p9f->header.fa.size       = p9f->height;
    p9f->header.fa.weight     = TK_FW_NORMAL;
    p9f->header.fa.slant      = TK_FS_ROMAN;
    p9f->header.fa.underline  = 0;
    p9f->header.fa.overstrike = 0;
    p9f->header.fm.ascent     = p9f->ascent;
    p9f->header.fm.descent    = p9f->descent;
    p9f->header.fm.fixed      = 1;
    p9f->header.fm.maxWidth   = tkp9_measuretext(fnt, "W", 1);

    return (TkFont *)p9f;
}

/* ------------------------------------------------------------------ */
/* TkpGetFontFromAttributes                                           */
/* ------------------------------------------------------------------ */

TkFont *
TkpGetFontFromAttributes(
    TkFont *tkFontPtr,
    Tk_Window tkwin,
    const TkFontAttributes *faPtr)
{
    P9Font *p9f;
    const char *path;
    void *fnt;
    (void)tkwin;

    path = MapFontName(faPtr->family);
    fnt  = tkp9_openfont(path);
    if (!fnt) return NULL;

    if (tkFontPtr != NULL) {
        /* Reuse existing struct */
        p9f = (P9Font *)tkFontPtr;
        tkp9_closefont(p9f->p9font);
    } else {
        p9f = (P9Font *) ckalloc(sizeof(P9Font));
        memset(p9f, 0, sizeof(P9Font));
    }

    p9f->p9font  = fnt;
    p9f->ascent  = tkp9_fontascent(fnt);
    p9f->descent = tkp9_fontdescent(fnt);
    p9f->height  = tkp9_fontheight(fnt);

    p9f->header.fa             = *faPtr;
    p9f->header.fm.ascent      = p9f->ascent;
    p9f->header.fm.descent     = p9f->descent;
    p9f->header.fm.fixed       = 1;
    p9f->header.fm.maxWidth    = tkp9_measuretext(fnt, "W", 1);

    return (TkFont *)p9f;
}

/* ------------------------------------------------------------------ */
/* TkpDeleteFont                                                      */
/* ------------------------------------------------------------------ */

/*
 * Release the platform resources only. The TkFont struct itself belongs
 * to generic Tk, which frees it in Tk_FreeFont immediately after this
 * returns:
 *
 *	TkpDeleteFont(fontPtr);
 *	if (fontPtr->objRefCount == 0) {
 *	    ckfree(fontPtr);
 *	}
 *
 * This used to ckfree(p9f), so that read of objRefCount was already a
 * read of freed memory and the ckfree a double free. Worse, a font with
 * objRefCount > 0 -- one a Tcl_Obj still refers to -- is deliberately
 * kept by Tk with a stale cacheHashPtr, and the guard that catches such
 * a stale reference is "oldFontPtr->resourceRefCount == 0". Reading
 * that field out of recycled memory gave a nonzero answer, so the guard
 * did not fire and Tk_AllocFontFromObj went on to dereference the null
 * cacheHashPtr:
 *
 *	wish: suicide: sys: trap: fault read addr=0x18
 *
 * (0x18 is clientData in Tcl_HashEntry, what Tcl_GetHashValue reads.)
 * Every Tk test died this way on the first use of TkDefaultFont.
 *
 * tkUnixFont.c and tkWinFont.c both do platform cleanup alone; see
 * their ReleaseFont.
 */
void
TkpDeleteFont(TkFont *tkFontPtr)
{
    P9Font *p9f = (P9Font *)tkFontPtr;

    if (p9f->p9font) {
	tkp9_closefont(p9f->p9font);
	p9f->p9font = NULL;
    }
}

/* ------------------------------------------------------------------ */
/* TkpGetFontFamilies                                                 */
/* ------------------------------------------------------------------ */

void
TkpGetFontFamilies(Tcl_Interp *interp, Tk_Window tkwin)
{
    (void)tkwin;
    /* Return a small set of known Plan 9 font families */
    Tcl_AppendElement(interp, "fixed");
    Tcl_AppendElement(interp, "helvetica");
    Tcl_AppendElement(interp, "times");
}

/* ------------------------------------------------------------------ */
/* Tk_MeasureChars                                                    */
/* ------------------------------------------------------------------ */

int
Tk_MeasureChars(
    Tk_Font tkfont,
    const char *source,
    Tcl_Size numBytes,
    int maxPixels,
    int flags,
    int *lengthPtr)
{
    P9Font *p9f = (P9Font *)tkfont;
    void *fnt;
    int w, i, nbytes;

    fnt = p9f ? p9f->p9font : NULL;

    if (numBytes < 0) numBytes = (Tcl_Size)strlen(source);

    if (maxPixels < 0) {
        /* Measure all bytes */
        w = tkp9_measuretext(fnt, source, (int)numBytes);
        if (lengthPtr) *lengthPtr = w;
        return (int)numBytes;
    }

    /* Find how many bytes fit within maxPixels */
    nbytes = 0;
    w      = 0;
    i      = 0;
    while (i < (int)numBytes) {
        /* Walk UTF-8 characters */
        unsigned char c = (unsigned char)source[i];
        int charlen = 1;
        if      ((c & 0x80) == 0x00) charlen = 1;
        else if ((c & 0xE0) == 0xC0) charlen = 2;
        else if ((c & 0xF0) == 0xE0) charlen = 3;
        else if ((c & 0xF8) == 0xF0) charlen = 4;
        if (i + charlen > (int)numBytes) break;

        int cw = tkp9_measuretext(fnt, source + i, charlen);
        if (w + cw > maxPixels) {
            if (flags & TK_PARTIAL_OK) { nbytes += charlen; w += cw; }
            break;
        }
        w      += cw;
        nbytes += charlen;
        i      += charlen;
    }
    if (lengthPtr) *lengthPtr = w;
    return nbytes;
}

/* ------------------------------------------------------------------ */
/* Tk_MeasureCharsInContext                                           */
/* ------------------------------------------------------------------ */

int
Tk_MeasureCharsInContext(
    Tk_Font tkfont,
    const char *source,
    Tcl_Size numSourceBytes,
    Tcl_Size rangeStart,
    Tcl_Size rangeLength,
    int maxPixels,
    int flags,
    int *lengthPtr)
{
    (void)numSourceBytes;
    return Tk_MeasureChars(tkfont, source + rangeStart, rangeLength,
                           maxPixels, flags, lengthPtr);
}

/* ------------------------------------------------------------------ */
/* Tk_DrawChars                                                       */
/* ------------------------------------------------------------------ */

void
Tk_DrawChars(
    Display *display,
    Drawable d,
    GC gc,
    Tk_Font tkfont,
    const char *source,
    Tcl_Size numBytes,
    int x, int y)
{
    P9Font *p9f = (P9Font *)tkfont;
    void *fnt;
    int ox, oy;
    unsigned long rgba;
    P9Window *pw;
    void *img;
    (void)display;

    fnt  = p9f ? p9f->p9font : NULL;
    rgba = TkP9XColorStructToRGBA(gc->foreground);

    /*
     * Text goes to the same place as everything else: a pixmap's own
     * image in its own coordinates, or the window on screen at its
     * position. Tk draws widget text into a pixmap and blits it, so
     * this has to agree with XCopyArea or the text lands in the corner.
     */
    pw = TkP9FindWindow((Window)d);
    if (pw != NULL && pw->ispixmap) {
        img = pw->img;
        ox = oy = 0;
    } else {
        img = NULL;
        TkP9WindowOffset((Window)d, &ox, &oy);
    }

    /* y in Tk is the baseline; Plan 9 string() also uses baseline */
    tkp9_drawtext(img, x + ox, y + oy - (p9f ? p9f->ascent : 0),
                  source, (int)numBytes, fnt, rgba);
}

/* ------------------------------------------------------------------ */
/* Tk_DrawCharsInContext                                              */
/* ------------------------------------------------------------------ */

void
Tk_DrawCharsInContext(
    Display *display,
    Drawable d,
    GC gc,
    Tk_Font tkfont,
    const char *source,
    Tcl_Size numSourceBytes,
    Tcl_Size rangeStart,
    Tcl_Size rangeLength,
    int x, int y)
{
    (void)numSourceBytes;
    Tk_DrawChars(display, d, gc, tkfont,
                 source + rangeStart, rangeLength, x, y);
}

/* ------------------------------------------------------------------ */
/* Additional font query stubs                                        */
/* ------------------------------------------------------------------ */

void
TkpGetSubFonts(Tcl_Interp *interp, Tk_Font tkfont)
{
    (void)interp; (void)tkfont;
}

void
TkpGetFontAttrsForChar(Tk_Window tkwin, Tk_Font tkfont,
                       int c, TkFontAttributes *faPtr)
{
    P9Font *p9f = (P9Font *)tkfont;
    (void)tkwin; (void)c;
    if (p9f) *faPtr = p9f->header.fa;
}
