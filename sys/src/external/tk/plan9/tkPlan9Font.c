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
#include <ctype.h>
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

/*
 * Monospace. fixed/ has the finest spread of sizes on a 9front install,
 * and B and O suffixes are its bold and oblique variants.
 */
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
    {"/lib/font/bit/terminus/unicode.16.font", 16},
    {"/lib/font/bit/fixed/unicode.9x18.font",  18},
    {"/lib/font/bit/fixed/unicode.10x20.font", 20},
    {NULL, 0}
};

static const P9FontFile monoBoldFonts[] = {
    {"/lib/font/bit/fixed/unicode.6x13B.font", 13},
    {"/lib/font/bit/fixed/unicode.7x13B.font", 13},
    {"/lib/font/bit/fixed/unicode.8x13B.font", 13},
    {"/lib/font/bit/fixed/unicode.7x14B.font", 14},
    {"/lib/font/bit/fixed/unicode.9x15B.font", 15},
    {"/lib/font/bit/fixed/unicode.9x18B.font", 18},
    {NULL, 0}
};

static const P9FontFile monoItalicFonts[] = {
    {"/lib/font/bit/fixed/unicode.6x13O.font", 13},
    {"/lib/font/bit/fixed/unicode.7x13O.font", 13},
    {"/lib/font/bit/fixed/unicode.8x13O.font", 13},
    {NULL, 0}
};

/*
 * Proportional. lucida/unicode.* is the only family here with a size
 * for nearly every request, so it carries the range; dejavusans has
 * bold and italic with full Unicode coverage, which lucida's latin1B
 * and latin1I do not.
 */
static const P9FontFile propFonts[] = {
    {"/lib/font/bit/lucida/unicode.5.font",       5},
    {"/lib/font/bit/lucida/unicode.6.font",       6},
    {"/lib/font/bit/lucida/unicode.7.font",       7},
    {"/lib/font/bit/lucida/unicode.8.font",       8},
    {"/lib/font/bit/lucida/unicode.9.font",       9},
    {"/lib/font/bit/lucida/unicode.10.font",     10},
    {"/lib/font/bit/lucida/unicode.12.font",     12},
    {"/lib/font/bit/lucida/unicode.14.font",     14},
    {"/lib/font/bit/lucida/unicode.16.font",     16},
    {"/lib/font/bit/lucida/unicode.18.font",     18},
    {"/lib/font/bit/lucida/unicode.20.font",     20},
    {"/lib/font/bit/lucida/unicode.24.font",     24},
    {"/lib/font/bit/lucida/unicode.28.font",     28},
    {"/lib/font/bit/lucida/unicode.32.font",     32},
    {NULL, 0}
};

static const P9FontFile propBoldFonts[] = {
    {"/lib/font/bit/lucidasans/boldunicode.6.font",   6},
    {"/lib/font/bit/lucidasans/boldunicode.7.font",   7},
    {"/lib/font/bit/lucidasans/boldunicode.8.font",   8},
    {"/lib/font/bit/lucidasans/boldunicode.10.font", 10},
    {"/lib/font/bit/dejavusansbd/unicode.12.font",   12},
    {"/lib/font/bit/lucidasans/boldunicode.13.font", 13},
    {"/lib/font/bit/dejavusansbd/unicode.14.font",   14},
    {"/lib/font/bit/dejavusansbd/unicode.16.font",   16},
    {"/lib/font/bit/dejavusansbd/unicode.18.font",   18},
    {NULL, 0}
};

static const P9FontFile propItalicFonts[] = {
    {"/lib/font/bit/lucidasans/italicunicode.6.font",   6},
    {"/lib/font/bit/lucidasans/italicunicode.7.font",   7},
    {"/lib/font/bit/lucidasans/italicunicode.8.font",   8},
    {"/lib/font/bit/lucidasans/italicunicode.10.font", 10},
    {"/lib/font/bit/dejavusansit/unicode.12.font",     12},
    {"/lib/font/bit/lucidasans/italicunicode.13.font", 13},
    {"/lib/font/bit/dejavusansit/unicode.14.font",     14},
    {"/lib/font/bit/dejavusansit/unicode.16.font",     16},
    {"/lib/font/bit/dejavusansit/unicode.18.font",     18},
    {NULL, 0}
};

/*
 * Serif. times/ is latin1 only, so the Unicode DejaVu serif faces carry
 * this; outside 12..18 there is nothing, and the proportional table
 * takes over.
 */
static const P9FontFile serifFonts[] = {
    {"/lib/font/bit/dejavu/unicode.12.font", 12},
    {"/lib/font/bit/dejavu/unicode.14.font", 14},
    {"/lib/font/bit/dejavu/unicode.16.font", 16},
    {"/lib/font/bit/dejavu/unicode.18.font", 18},
    {NULL, 0}
};

static const P9FontFile serifBoldFonts[] = {
    {"/lib/font/bit/dejavubd/unicode.12.font", 12},
    {"/lib/font/bit/dejavubd/unicode.14.font", 14},
    {"/lib/font/bit/dejavubd/unicode.16.font", 16},
    {"/lib/font/bit/dejavubd/unicode.18.font", 18},
    {NULL, 0}
};

static const P9FontFile serifItalicFonts[] = {
    {"/lib/font/bit/dejavuit/unicode.12.font", 12},
    {"/lib/font/bit/dejavuit/unicode.14.font", 14},
    {"/lib/font/bit/dejavuit/unicode.16.font", 16},
    {"/lib/font/bit/dejavuit/unicode.18.font", 18},
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
    const P9FontFile *table, *variant = NULL;
    int pixels;
    void *fnt;

    pixels = (int)(TkFontGetPixels(tkwin, faPtr->size) + 0.5);
    if (pixels <= 0)
        pixels = 13;			/* Tk's own fallback size */

    if (IsMonoFamily(faPtr->family)) {
        table = monoFonts;
        if (faPtr->weight == TK_FW_BOLD)      variant = monoBoldFonts;
        else if (faPtr->slant != TK_FS_ROMAN) variant = monoItalicFonts;
    } else if (IsSerifFamily(faPtr->family)) {
        table = serifFonts;
        if (faPtr->weight == TK_FW_BOLD)      variant = serifBoldFonts;
        else if (faPtr->slant != TK_FS_ROMAN) variant = serifItalicFonts;
    } else {
        table = propFonts;
        if (faPtr->weight == TK_FW_BOLD)      variant = propBoldFonts;
        else if (faPtr->slant != TK_FS_ROMAN) variant = propItalicFonts;
    }

    /*
     * A bold or italic face only exists at some sizes. Prefer one, but
     * take the right size in the regular face over the right style in
     * the wrong size -- a bitmap font cannot have both.
     */
    fnt = NULL;
    if (variant != NULL)
        fnt = OpenNearest(variant, pixels);
    if (fnt == NULL)
        fnt = OpenNearest(table, pixels);
    if (fnt == NULL && table != propFonts)
        fnt = OpenNearest(propFonts, pixels);
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

/*
 * How many bytes of source fit in maxPixels, and how wide they are.
 *
 * The flags are the whole difficulty, and this used to ignore two of
 * them. Tk_ComputeTextLayout wraps text by calling this with
 * TK_WHOLE_WORDS|TK_AT_LEAST_ONE, and expects a break at the last word
 * boundary that fits -- or, if no whole word fits, at least one
 * character, so a line can never be empty. Breaking at any character
 * instead, as this did, put line breaks in the middle of words and put
 * them in the wrong place for tabs, which is what font-24.* measured.
 *
 * The structure follows tkUnixFont.c: walk forward accumulating width,
 * remember the last place a run of spaces began after non-space (term),
 * stop at the first character that will not fit, then decide what to
 * report from the flags.
 */
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
    void *fnt = p9f ? p9f->p9font : NULL;
    const char *p, *end, *next, *term;
    int ch, curX, newX, termX, sawNonSpace, cw;
    Tcl_Size curByte;

    if (numBytes < 0)
        numBytes = (Tcl_Size) strlen(source);
    end = source + numBytes;

    if (numBytes == 0) {
        curX = 0;
        curByte = 0;
    } else if (maxPixels < 0) {
        curX = tkp9_measuretext(fnt, source, (int) numBytes);
        curByte = numBytes;
    } else {
        next = source + Tcl_UtfToUniChar(source, &ch);
        newX = curX = termX = 0;
        term = source;
        sawNonSpace = (ch > 255) || !isspace(ch);

        for (p = source; ; ) {
            cw = tkp9_measuretext(fnt, p, (int)(next - p));
            newX += cw;
            if (newX > maxPixels)
                break;
            curX = newX;
            p = next;
            if (p >= end) {
                term = end;
                termX = curX;
                break;
            }
            next += Tcl_UtfToUniChar(next, &ch);
            if ((ch < 256) && isspace(ch)) {
                if (sawNonSpace) {
                    term = p;
                    termX = curX;
                    sawNonSpace = 0;
                }
            } else {
                sawNonSpace = 1;
            }
        }

        /*
         * p points to the first character that did not fit (or end).
         * curX is the width of everything before it.
         */
        if ((flags & TK_PARTIAL_OK) && (p < end) && (curX < maxPixels)) {
            /* The partial character counts, and its whole width. */
            curX = newX;
            p += Tcl_UtfToUniChar(p, &ch);
        }
        if ((flags & TK_AT_LEAST_ONE) && (term == source) && (p < end)) {
            term = p;
            termX = curX;
            if (term == source) {
                term += Tcl_UtfToUniChar(term, &ch);
                termX = newX;
            }
        } else if ((p >= end) || !(flags & TK_WHOLE_WORDS)) {
            term = p;
            termX = curX;
        }

        curX = termX;
        curByte = term - source;
    }

    if (lengthPtr)
        *lengthPtr = curX;
    return (int) curByte;
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
