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
/* Choosing a Plan 9 font file                                         */
/* ------------------------------------------------------------------ */

/*
 * Plan 9 bitmap fonts come in discrete sizes, one file each, so a font
 * request is answered by picking the nearest available file rather than
 * by scaling. The size in the table is the nominal pixel height, which
 * is what the file names encode.
 *
 * Any of these may be absent -- what a 9front install ships varies --
 * so a candidate that will not open is skipped and the next-nearest
 * tried. If none opens we fall back to libdraw's default font, which is
 * the behaviour this port had for every request.
 */

typedef struct {
    const char *path;
    int         pixels;
} P9FontFile;

static const P9FontFile monoFonts[] = {
    {"/lib/font/bit/fixed/unicode.4x6.font",    6},
    {"/lib/font/bit/fixed/unicode.5x7.font",    7},
    {"/lib/font/bit/fixed/unicode.5x8.font",    8},
    {"/lib/font/bit/fixed/unicode.6x9.font",    9},
    {"/lib/font/bit/fixed/unicode.6x10.font",  10},
    {"/lib/font/bit/fixed/unicode.6x12.font",  12},
    {"/lib/font/bit/fixed/unicode.6x13.font",  13},
    {"/lib/font/bit/fixed/unicode.7x14.font",  14},
    {"/lib/font/bit/fixed/unicode.9x15.font",  15},
    {"/lib/font/bit/fixed/unicode.8x16.font",  16},
    {"/lib/font/bit/fixed/unicode.9x18.font",  18},
    {"/lib/font/bit/fixed/unicode.10x20.font", 20},
    {NULL, 0}
};

static const P9FontFile propFonts[] = {
    {"/lib/font/bit/lucsans/unicode.6.font",    6},
    {"/lib/font/bit/lucsans/unicode.7.font",    7},
    {"/lib/font/bit/lucsans/unicode.8.font",    8},
    {"/lib/font/bit/pelm/unicode.9.font",       9},
    {"/lib/font/bit/lucsans/unicode.10.font",  10},
    {"/lib/font/bit/lucsans/unicode.13.font",  13},
    {"/lib/font/bit/lucidasans/unicode.13.font", 13},
    {"/lib/font/bit/lucsans/unicode.16.font",  16},
    {"/lib/font/bit/lucidasans/unicode.16.font", 16},
    {NULL, 0}
};

static const P9FontFile serifFonts[] = {
    {"/lib/font/bit/times/unicode.8.font",      8},
    {"/lib/font/bit/times/unicode.10.font",    10},
    {"/lib/font/bit/times/unicode.12.font",    12},
    {"/lib/font/bit/times/unicode.14.font",    14},
    {"/lib/font/bit/times/unicode.16.font",    16},
    {NULL, 0}
};

static int
IsMonoFamily(const char *f)
{
    return f != NULL && (strstr(f, "ourier") || strstr(f, "ixed")
            || strstr(f, "ono") || strstr(f, "onospace")
            || strstr(f, "erminal"));
}

static int
IsSerifFamily(const char *f)
{
    return f != NULL && (strstr(f, "imes") || strstr(f, "erif")
            || strstr(f, "oman"));
}

/*
 * Open the file whose nominal size is nearest to wantPixels, trying
 * successively worse matches until one opens.
 */
static void *
OpenNearest(const P9FontFile *table, int wantPixels)
{
    int used[32];
    int nused = 0, i, best, bestd, d;
    void *fnt;

    for (;;) {
        best = -1;
        bestd = 0;
        for (i = 0; table[i].path != NULL; i++) {
            int j, skip = 0;
            for (j = 0; j < nused; j++)
                if (used[j] == i) { skip = 1; break; }
            if (skip)
                continue;
            d = table[i].pixels - wantPixels;
            if (d < 0)
                d = -d;
            if (best < 0 || d < bestd) { best = i; bestd = d; }
        }
        if (best < 0)
            return NULL;
        fnt = tkp9_openfontpath(table[best].path);
        if (fnt != NULL)
            return fnt;
        if (nused >= (int)(sizeof used / sizeof used[0]))
            return NULL;
        used[nused++] = best;
    }
}

/*
 * Tk uses fm.fixed to skip measuring character by character, so claiming
 * it for a proportional font mislays every string. libdraw does not say,
 * so ask the font.
 */
static int
FontIsFixed(void *fnt)
{
    return tkp9_measuretext(fnt, "i", 1) == tkp9_measuretext(fnt, "W", 1);
}

static void *
ChooseFont(Tk_Window tkwin, const TkFontAttributes *faPtr)
{
    const P9FontFile *table;
    int pixels;
    void *fnt;

    pixels = (int)(TkFontGetPixels(tkwin, faPtr->size) + 0.5);
    if (pixels <= 0)
        pixels = 13;			/* Tk's own fallback size */

    if (IsMonoFamily(faPtr->family))
        table = monoFonts;
    else if (IsSerifFamily(faPtr->family))
        table = serifFonts;
    else
        table = propFonts;

    fnt = OpenNearest(table, pixels);
    if (fnt == NULL && table != monoFonts)
        fnt = OpenNearest(monoFonts, pixels);
    if (fnt == NULL)
        fnt = tkp9_openfont(NULL);	/* libdraw's default */
    return fnt;
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

/*
 * Look up a font by *native* name, and fail if the name is not one.
 *
 * Failing is the whole contract. tkFont.c calls this first and, when it
 * returns NULL, parses the string itself -- as an XLFD, as a
 * "{family} size style" list, or as -family/-size option pairs -- and
 * comes back through TkpGetFontFromAttributes. This used to accept
 * everything, opening the default font for any string whatsoever, so
 * that parsing never happened: sizes and styles were silently ignored,
 *
 *	font actual {Helvetica -12}
 *	  -> -family {Helvetica -12} -size 18
 *
 * an XLFD came back whole as the family name, and an empty font name --
 * which must be an error -- was accepted (button-1.104, canvasText-1.7).
 *
 * The only genuinely native name here is the path of a Plan 9 font
 * file, which is what openfont(2) takes.
 */
TkFont *
TkpGetNativeFont(Tk_Window tkwin, const char *name)
{
    P9Font *p9f;
    void *fnt;
    (void)tkwin;

    if (name == NULL || name[0] != '/')
        return NULL;
    fnt = tkp9_openfontpath(name);
    if (fnt == NULL)
        return NULL;

    p9f = (P9Font *) ckalloc(sizeof(P9Font));
    memset(p9f, 0, sizeof(P9Font));
    p9f->p9font  = fnt;
    p9f->ascent  = tkp9_fontascent(fnt);
    p9f->descent = tkp9_fontdescent(fnt);
    p9f->height  = tkp9_fontheight(fnt);

    p9f->header.fa.family     = Tk_GetUid(name);
    p9f->header.fa.size       = -p9f->height;	/* negative == pixels */
    p9f->header.fa.weight     = TK_FW_NORMAL;
    p9f->header.fa.slant      = TK_FS_ROMAN;
    p9f->header.fa.underline  = 0;
    p9f->header.fa.overstrike = 0;
    p9f->header.fm.ascent     = p9f->ascent;
    p9f->header.fm.descent    = p9f->descent;
    p9f->header.fm.fixed      = FontIsFixed(fnt);
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
    void *fnt;

    fnt = ChooseFont(tkwin, faPtr);
    if (fnt == NULL)
        return NULL;

    if (tkFontPtr != NULL) {
        /* Reuse the existing struct; generic Tk still owns it. */
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

    /*
     * Report back what was asked for, not what was found: Tk caches on
     * these attributes, and answering with the file's own size would
     * make "font actual" disagree with the request for every size that
     * has no exact bitmap.
     */
    p9f->header.fa          = *faPtr;
    p9f->header.fm.ascent   = p9f->ascent;
    p9f->header.fm.descent  = p9f->descent;
    p9f->header.fm.fixed    = FontIsFixed(fnt);
    p9f->header.fm.maxWidth = tkp9_measuretext(fnt, "W", 1);

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
    Tcl_AppendElement(interp, "courier");
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
