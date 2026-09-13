/*
 * bltInt.h --
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.
 */

#ifndef _BLT_INT_H
#define _BLT_INT_H

#ifdef WIN32
#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef STRICT
#undef WIN32_LEAN_AND_MEAN
#include <windowsx.h>
#endif /* WIN32 */

#include <tcl.h>
#include <tk.h>

#define _VERSION(a,b,c)	    (((a) << 16) + ((b) << 8) + (c))
#define TCL_VERSION_NUMBER _VERSION(TCL_MAJOR_VERSION, TCL_MINOR_VERSION, TCL_RELEASE_SERIAL)
#define TK_VERSION_NUMBER _VERSION(TK_MAJOR_VERSION, TK_MINOR_VERSION, TK_RELEASE_SERIAL)

#include "config.h"
#include "bltTkInt.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
#ifdef WIN32
#include "bltWinConfig.h"
#else
#include "bltConfig.h"
#endif
*/

#include "blt.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif /* HAVE_STDLIB_H */

#ifdef HAVE_STRING_H
#include <string.h>
#endif /* HAVE_STRING_H */

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif /* HAVE_ERRNO_H */

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif /* HAVE_CTYPE_H */

#ifdef HAVE_MEMORY_H
#include <memory.h>
#endif /* HAVE_MEMORY_H */

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif /* HAVE_MALLOC_H */

#ifdef HAVE_FLOAT_H
#include <float.h>
#endif

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef M_PI
#define M_PI    	3.14159265358979323846
#endif /* M_PI */

#ifndef M_PI_2
#define M_PI_2		1.57079632679489661923
#endif

#ifndef M_SQRT2
#define M_SQRT2		1.41421356237309504880
#endif /* M_SQRT2 */

#ifndef M_SQRT1_2
#define M_SQRT1_2	0.70710678118654752440
#endif /* M_SQRT1_2 */

#ifndef SHRT_MAX
#define SHRT_MAX	0x7FFF
#endif /* SHRT_MAX */

#ifndef SHRT_MIN
#define SHRT_MIN	-(SHRT_MAX)
#endif /* SHRT_MAX */

#ifndef USHRT_MAX
#define	USHRT_MAX	0xFFFF
#endif /* USHRT_MAX */

#ifndef INT_MAX
#define INT_MAX		2147483647
#endif /* INT_MAX */

#ifndef HAVE_FLOAT_H
/*
 * ----------------------------------------------------------------------
 *
 * DBL_MIN, DBL_MAX --
 *
 * 	DBL_MAX and DBL_MIN are the largest and smaller double
 * 	precision numbers that can be represented by the floating
 * 	point hardware. If the compiler is ANSI, they can be found in
 * 	float.h.  Otherwise, we use HUGE_VAL or HUGE to determine
 * 	them.
 *
 * ----------------------------------------------------------------------
 */
/*
 * Don't want to include __infinity (definition of HUGE_VAL (SC1.x))
 */
#ifdef sun
#define DBL_MAX		1.7976931348623157E+308
#define DBL_MIN		2.2250738585072014E-308
#define DBL_EPSILON	2.2204460492503131e-16
#else
#ifndef DBL_EPSILON
#define DBL_EPSILON	BLT_DBL_EPSILON
#endif
#ifdef HUGE_VAL
#define DBL_MAX		HUGE_VAL
#define DBL_MIN		(1/HUGE_VAL)
#else
#ifdef HUGE
#define DBL_MAX		HUGE
#define DBL_MIN		(1/HUGE)
#else
/*
 * Punt: Assume values simple and relatively small
 */
#define DBL_MAX		3.40282347E+38
#define DBL_MIN		1.17549435E-38
#endif /*HUGE*/
#endif /*HUGE_VAL*/
#endif /*sun*/
#endif /*!HAVE_FLOAT_H*/

#undef INLINE
#ifdef __GNUC__
#define INLINE inline
#else
#define INLINE
#endif
#undef EXPORT
#define EXPORT

#undef MIN
#define MIN(a,b)	(((a)<(b))?(a):(b))

#undef MAX
#define MAX(a,b)	(((a)>(b))?(a):(b))

/*
 * ----------------------------------------------------------------------
 *
 *  	The following are macros replacing math library functions:
 *  	"fabs", "fmod", "abs", "rint", and "exp10".
 *
 *  	Although many of these routines may be in your math library,
 *  	they aren't used in libtcl.a or libtk.a.  This makes it
 *  	difficult to dynamically load the BLT library as a shared
 *  	object unless the math library is also shared (which isn't
 *  	true on several systems).  We can avoid the problem by
 *  	replacing the "exotic" math routines with macros.
 *
 * ----------------------------------------------------------------------
 */
#undef ABS
#define ABS(x)		(((x)<0)?(-(x)):(x))

#undef EXP10
#define EXP10(x)	(pow(10.0,(x)))

#undef FABS
#define FABS(x) 	(((x)<0.0)?(-(x)):(x))

#undef SIGN
#define SIGN(x)		(((x) < 0.0) ? -1 : 1)

/*
 * Be careful when using the next two macros.  They both assume the floating
 * point number is less than the size of an int.  That means, for example, you
 * can't use these macros with numbers bigger than than 2^31-1.
 */
#undef FMOD
#define FMOD(x,y) 	((x)-(((int)((x)/(y)))*y))

#undef ROUND
#define ROUND(x) 	((int)((x) + (((x)<0.0) ? -0.5 : 0.5)))

#define TRUE 	1
#define FALSE 	0
/*
 * The macro below is used to modify a "char" value (e.g. by casting
 * it to an unsigned character) so that it can be used safely with
 * macros such as isspace.
 */
#define UCHAR(c) ((unsigned char) (c))

#define PIXELS_NONNEGATIVE	0
#define PIXELS_POSITIVE		1
#define PIXELS_ANY		2

#define COUNT_NONNEGATIVE	0
#define COUNT_POSITIVE		1
#define COUNT_ANY		2

#define SCROLL_MODE_CANVAS	(1<<0)
#define SCROLL_MODE_LISTBOX	(1<<1)
#define SCROLL_MODE_HIERBOX	(1<<2)

#define RGB_ANTIQUEWHITE1	"#ffefdb"
#define RGB_BISQUE1	"#ffe4c4"
#define RGB_BISQUE2	"#eed5b7"
#define RGB_BISQUE3     "#cdb79e"
#define RGB_BLACK	"#000000"
#define RGB_BLUE	"#0000ff"
#define RGB_GREEN	"#00ff00"
#define RGB_GREY	"#b0b0b0"
#define RGB_GREY15	"#262626"
#define RGB_GREY50	"#7f7f7f"
#define RGB_GREY64	"#a3a3a3"
#define RGB_GREY70	"#b3b3b3"
#define RGB_GREY75	"#bfbfbf"
#define RGB_GREY77	"#c3c3c3"
#define RGB_GREY82	"#d1d1d1"
#define RGB_GREY85	"#d9d9d9"
#define RGB_GREY90	"#e5e5e5"
#define RGB_GREY95	"#f2f2f2"
#define RGB_LIGHTBLUE0	"#e4f7ff"
#define RGB_LIGHTBLUE1	"#bfefff"
#define RGB_LIGHTBLUE2	"#b2dfee"
#define RGB_LIGHTSKYBLUE1	"#b0e2ff"
#define RGB_MAROON	"#b03060"
#define RGB_NAVYBLUE	"#000080"
#define RGB_PINK	"#ffc0cb"
#define RGB_RED		"#ff0000"
#define RGB_WHITE	"#ffffff"
#define RGB_YELLOW	"#ffff00"

#ifdef OLD_TK_COLORS
#define STD_COLOR_NORMAL_BG	RGB_BISQUE1
#define STD_COLOR_ACTIVE_BG	RGB_BISQUE2
#define STD_COLOR_SELECT_BG	RGB_LIGHTBLUE2
#define STD_COLOR_DISABLE_FG	RGB_GREY64
#else
#define STD_COLOR_NORMAL_BG	RGB_GREY85
#define STD_COLOR_ACTIVE_BG	RGB_GREY64
#define STD_COLOR_SELECT_BG	RGB_GREY77
#define STD_COLOR_DISABLE_FG	RGB_GREY64
#endif /* OLD_TK_COLORS */

#define STD_COLOR_INDICATOR	RGB_MAROON

#define STD_COLOR_ACTIVE_FG	RGB_BLACK
#define STD_COLOR_NORMAL_FG	RGB_BLACK
#define STD_COLOR_SELECT_FG	RGB_BLACK
#define STD_COLOR_SHADOW	RGB_GREY64
#define STD_MONO_ACTIVE_BG	RGB_BLACK
#define STD_MONO_ACTIVE_FG	RGB_WHITE
#define STD_MONO_NORMAL_BG	RGB_WHITE
#define STD_MONO_NORMAL_FG	RGB_BLACK
#define STD_MONO_SELECT_BG	RGB_BLACK
#define STD_MONO_SELECT_FG	RGB_WHITE
#define STD_MONO_SHADOW		RGB_BLACK

#define STD_SELECT_BORDERWIDTH	"2"
#define STD_BORDERWIDTH 	"2"

#define STD_FONT_HUGE		"*-Helvetica-Medium-R-Normal-*-18-180-*"
#define STD_FONT_LARGE		"*-Helvetica-Medium-R-Normal-*-14-140-*"
#define STD_FONT		"*-Helvetica-Medium-R-Normal-*-12-120-*"
#define STD_FONT_SMALL		"*-Helvetica-Medium-R-Normal-*-10-100-*"

#ifdef WIN32
#undef STD_FONT
#undef STD_FONT_SMALL
#undef STD_FONT_LARGE
#undef STD_COLOR_NORMAL_BG
#undef STD_COLOR_NORMAL_FG
#undef STD_COLOR_TEXT_FG
#undef STD_COLOR_SELECT_BG

#define STD_FONT		"Arial 8"
#define STD_FONT_SMALL		"Arial 6"
#define STD_FONT_LARGE		"Arial 12"
#define STD_COLOR_NORMAL_BG	"SystemButtonFace"
#define STD_COLOR_NORMAL_FG	"SystemButtonText"
#define STD_COLOR_TEXT_FG	"SystemWindowText"
#define STD_COLOR_SELECT_BG	"SystemHighlight"
#endif /* WIN32 */

#define LineWidth(w)	(((w) > 1) ? (w) : 0)

#undef VARARGS
#ifdef __cplusplus
#define ANYARGS (...)
#define VARARGS(first)  (first, ...)
#define VARARGS2(first, second)  (first, second, ...)
#else
#define ANYARGS ()
#define VARARGS(first) ()
#define VARARGS2(first, second) ()
#endif /* __cplusplus */

#if defined(ITCL_NAMESPACES) || (TCL_MAJOR_VERSION >= 8)
#define HAVE_NAMESPACES 1
#else
#define HAVE_NAMESPACES 0
#endif

#ifdef TCL_UTF_MAX
#define HAVE_UTF 1
#else
#define HAVE_UTF 0
#endif /* TCL_UTF_MAX */

typedef char *DestroyData;


/*
 * Tcl/Tk Backward compatibility section.
 */

#if (TCL_MAJOR_VERSION > 7)

#define NO_FLAGS			0
#define Blt_FindPhoto(interp, name)	Tk_FindPhoto(interp, name)

#else

#define Tcl_GetStringResult(interp)	((interp)->result)
typedef struct Tcl_Namespace Tcl_Namespace;
typedef struct Tcl_CallFrame *Tcl_CallFrame;
#define Blt_FindPhoto(interp, name)	Tk_FindPhoto(name)

#endif /* TCL_MAJOR_VERSION > 7 */

#undef panic
#define panic(mesg)	Blt_Panic("%s:%d %s", __FILE__, __LINE__, (mesg))

/*
 * Since the Tcl/Tk distribution doesn't perform any asserts, dynamic
 * loading can fail to find the __assert function.  As a workaround,
 * we'll include our own.
 */
#undef	assert
#ifdef	NDEBUG
#define	assert(EX) ((void)0)
#else
extern void Blt_Assert _ANSI_ARGS_((char *testExpr, char *fileName, int lineNum));
#ifdef __STDC__
#define	assert(EX) (void)((EX) || (Blt_Assert(#EX, __FILE__, __LINE__), 0))
#else
#define	assert(EX) (void)((EX) || (Blt_Assert("EX", __FILE__, __LINE__), 0))
#endif /* __STDC__ */

#endif /* NDEBUG */

typedef int *Blt_Tile;		/* Opaque type for tiles */

typedef int (QSortCompareProc) _ANSI_ARGS_((const void *, const void *));


/*
 * ----------------------------------------------------------------------
 *
 * Blt_CmdSpec --
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of command */
    Tcl_CmdProc *cmdProc;
    Tcl_CmdDeleteProc *cmdDeleteProc;
    ClientData clientData;
} Blt_CmdSpec;

/*
 * ----------------------------------------------------------------------
 *
 * Blt_Operation --
 *
 * 	Generic function prototype of CmdOptions.
 *
 * ----------------------------------------------------------------------
 */
typedef int (*Blt_Operation) _ANSI_ARGS_(ANYARGS);

/*
 * ----------------------------------------------------------------------
 *
 * Blt_OpSpec --
 *
 * 	Structure to specify a set of operations for a Tcl command.
 *      This is passed to the Blt_GetOperation procedure to look
 *      for a function pointer associated with the operation name.
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char *name;			/* Name of operation */
    int minChars;		/* Minimum # characters to disambiguate */
    Blt_Operation proc;
    int minArgs;		/* Minimum # args required */
    int maxArgs;		/* Maximum # args required */
    char *usage;		/* Usage message */

} Blt_OpSpec;

typedef enum {
    BLT_OPER_ARG0,		/* Operation is the first argument. */
    BLT_OPER_ARG1,		/* Operation is the second argument. */
    BLT_OPER_ARG2,		/* Operation is the third argument. */
    BLT_OPER_ARG3,		/* Operation is the fourth argument. */
    BLT_OPER_ARG4		/* Operation is the fifth argument. */

} Blt_OpIndex;

extern Blt_Operation Blt_GetOperation _ANSI_ARGS_((Tcl_Interp *interp,
	int nSpecs, Blt_OpSpec *specArr, Blt_OpIndex argIndex,
	int nArgs, char **argArr));

extern int Blt_LookupOperation _ANSI_ARGS_((Blt_OpSpec *specArr, int nSpecs,
	char *string));

/*
 * ----------------------------------------------------------------------
 *
 * Pad --
 *
 * 	Specifies vertical and horizontal padding.
 *
 *	Padding can be specified on a per side basis.  The fields
 *	side1 and side2 refer to the opposite sides, either
 *	horizontally or vertically.
 *
 *		side1	side2
 *          x   left    right
 *	    y   top     bottom
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    short int side1, side2;
} Pad;

#define padLeft  	padX.side1
#define padRight  	padX.side2
#define padTop		padY.side1
#define padBottom	padY.side2
#define PADDING(x)	((x).side1 + (x).side2)

/*
 * ----------------------------------------------------------------------
 *
 * The following enumerated values are used as bit flags.
 *
 *
 * ----------------------------------------------------------------------
 */
typedef enum {
    FILL_NONE,			/* Neither coordinate plane is specified */
    FILL_X,			/* Horizontal plane */
    FILL_Y,			/* Vertical plane */
    FILL_BOTH			/* Both vertical and horizontal planes */
} Fill;

/*
 * ----------------------------------------------------------------------
 *
 * Dashes --
 *
 * 	List of dash values (maximum 11 based upon PostScript limit).
 *
 * ----------------------------------------------------------------------
 */
typedef struct {
    char valueArr[12];
    int nValues;
    int offset;
} Dashes;

extern void Blt_SetDashes _ANSI_ARGS_((Display *display, GC gc,
	Dashes *dashesPtr));
extern Dashes *Blt_GetDashes _ANSI_ARGS_((GC gc));

/*
 * -------------------------------------------------------------------
 *
 * Point2D --
 *
 *	Represents a single coordinate in 2D space.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    double x, y;
} Point2D;

/*
 * -------------------------------------------------------------------
 *
 * Point3D --
 *
 *	Represents a single coordinate in 3D space.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    double x, y, z;
} Point3D;

/*
 * -------------------------------------------------------------------
 *
 * Dim2D --
 *
 *	Represents the dimension of something in 2D space.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    short int width, height;
} Dim2D;

/*
 *----------------------------------------------------------------------
 *
 * ImageRegion --
 *
 *      Designates a rectangular region of an image.  Used to copy
 *	parts of images.
 *
 *----------------------------------------------------------------------
 */
typedef struct ImageRegion {
    int x, y;			/* Upper left corner coordinates of
				 * the rectangle defining the
				 * region. */
    int width, height;		/* Dimensions of the rectangular region. */
} ImageRegion;

/*
 * -------------------------------------------------------------------
 *
 * ColorPair --
 *
 *	Holds a pair of foreground, background colors.
 *
 * -------------------------------------------------------------------
 */
typedef struct {
    XColor *fgColor, *bgColor;
} ColorPair;

#define COLOR_NONE		(XColor *)0
#define COLOR_DEFAULT		(XColor *)1
#define COLOR_ALLOW_DEFAULTS	1

extern int Blt_GetColorPair _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *fgColor, char *bgColor, ColorPair *pairPtr, int colorFlag));
extern void Blt_FreeColorPair _ANSI_ARGS_((ColorPair *pairPtr));

#define STATE_NORMAL	0
#define STATE_ACTIVE	(1<<0)
#define STATE_DISABLED	(1<<1)
#define STATE_EMPHASIS	(1<<2)


typedef struct BindTable *BindTable;
typedef ClientData (BindPickProc) _ANSI_ARGS_((ClientData clientData,
	int x, int y));

typedef void (BindTagProc) _ANSI_ARGS_((BindTable bindTable, ClientData object,
	ClientData *tagArr, int *nTagsPtr));

/*
 *  Binding structure information:
 */

struct BindTable {
    int flags;
    Tk_BindingTable bindingTable;
    /* Table of all bindings currently defined.
				 * NULL means that no bindings exist, so the
				 * table hasn't been created.  Each "object"
				 * used for this table is either a Tk_Uid for
				 * a tag or the address of an item named by
				 * id. */

    ClientData currentItem;	/* The item currently containing the mouse
				 * pointer, or NULL if none. */

    ClientData newItem;		/* The item that is about to become the
				 * current one, or NULL.  This field is
				 * used to detect deletions of the new
				 * current item pointer that occur during
				 * Leave processing of the previous current
				 * tab.  */

    ClientData focusItem;

    XEvent pickEvent;		/* The event upon which the current choice
				 * of the current tab is based.  Must be saved
				 * so that if the current item is deleted,
				 * we can pick another. */
    int activePick;		/* The pick event has been initialized so
				 * that we can repick it */

    int state;			/* Last known modifier state.  Used to
				 * defer picking a new current object
				 * while buttons are down. */

    ClientData clientData;
    Tk_Window tkwin;
    BindPickProc *pickProc;	/* Routine to report the item the mouse is
				 * currently over. */
    BindTagProc *tagProc;	/* Routine to report tags picked items. */
};

#include "bltText.h"

extern void Blt_DestroyBindingTable _ANSI_ARGS_((BindTable table));

extern BindTable Blt_CreateBindingTable _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, ClientData clientData, BindPickProc * pickProc,
	BindTagProc * tagProc));

extern int Blt_ConfigureBindings _ANSI_ARGS_((Tcl_Interp *interp,
	BindTable table, ClientData item, int argc, char **argv));

extern void Blt_PickCurrentItem _ANSI_ARGS_((BindTable table));

extern void Blt_DeleteBindings _ANSI_ARGS_((BindTable table,
	ClientData object));

#define Blt_SetFocusItem(bindPtr, object) \
	((bindPtr)->focusItem = (ClientData)(object))

#define Blt_GetCurrentItem(bindPtr)  ((bindPtr)->currentItem)
#define Blt_GetLatestItem(bindPtr)  ((bindPtr)->newItem)

#define Blt_GetBindingData(bindPtr)  ((bindPtr)->clientData)

/*
 * ----------------------------------------------------------------------
 *
 * 	X11/Xosdefs.h requires XNOSTDHDRS be set for some systems.
 *	This is a guess.  If I can't find STDC headers or unistd.h,
 *	assume that this is non-POSIX and non-STDC environment.
 *	(needed for Encore Umax 3.4 ?)
 *
 * ----------------------------------------------------------------------
 */
#if !defined(STDC_HEADERS) && !defined(HAVE_UNISTD_H)
#define XNOSTDHDRS 	1
#endif

/*
 * ----------------------------------------------------------------------
 *
 *	Assume we need to declare free if there's no stdlib.h or malloc.h
 *
 * ----------------------------------------------------------------------
 */
#if !defined(HAVE_STDLIB_H) && !defined(HAVE_MALLOC_H)
extern void free _ANSI_ARGS_((void *));
#endif

/*
 * ----------------------------------------------------------------------
 *
 *	On some systems "strdup" and "strcasecmp" are in the C library,
 *      but have no declarations in the C header files. Make sure we
 *      supply them here.
 *
 * ----------------------------------------------------------------------
 */
#ifdef NO_DECL_STRDUP
extern char *strdup _ANSI_ARGS_((CONST char *s));
#endif

#ifdef NO_DECL_DRAND48
extern double drand48 _ANSI_ARGS_((void));
extern void srand48 _ANSI_ARGS_((long seed));
#endif

#ifdef NO_DECL_STRCASECMP
extern int strcasecmp _ANSI_ARGS_((CONST char *s1, CONST char *s2));
#endif

extern int Blt_StringToFlag _ANSI_ARGS_((ClientData clientData,
	Tcl_Interp *interp, Tk_Window tkwin, char *string, char *widgRec,
	int flags));
extern char *Blt_FlagToString _ANSI_ARGS_((ClientData clientData,
	Tk_Window tkwin, char *string, int offset, Tcl_FreeProc **freeProc));

extern Tk_Uid Blt_GetUid _ANSI_ARGS_((char *string));
extern void Blt_FreeUid _ANSI_ARGS_((Tk_Uid uid));
extern Tk_Uid Blt_FindUid _ANSI_ARGS_((char *string));

extern char *Blt_Itoa _ANSI_ARGS_((int value));
extern char *Blt_Dtoa _ANSI_ARGS_((Tcl_Interp *interp, double value));

extern void Blt_InitHexTable _ANSI_ARGS_((char *table));

extern GC Blt_GetPrivateGC _ANSI_ARGS_((Tk_Window tkwin, unsigned long gcMask,
	XGCValues *valuePtr));

extern GC Blt_GetPrivateGCFromDrawable _ANSI_ARGS_((Tk_Window tkwin,
	Drawable drawable, unsigned long gcMask, XGCValues *valuePtr));

extern void Blt_FreePrivateGC _ANSI_ARGS_((Display *display, GC gc));

extern Tk_Window Blt_FindChild _ANSI_ARGS_((Tk_Window parent, char *name));

extern Tk_Window Blt_FirstChild _ANSI_ARGS_((Tk_Window parent));

extern Tk_Window Blt_NextChild _ANSI_ARGS_((Tk_Window tkwin));

extern void Blt_RelinkWindow _ANSI_ARGS_((Tk_Window tkwin, Tk_Window newParent,
	int x, int y));

extern Tk_Window Blt_Toplevel _ANSI_ARGS_((Tk_Window tkwin));

extern int Blt_GetPixels _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *string, int check, int *valuePtr));
extern int Blt_GetCount _ANSI_ARGS_((Tcl_Interp *interp, char *string,
	int check, int *valuePtr));

extern char *Blt_NameOfFill _ANSI_ARGS_((Fill fill));

extern int Blt_GetXY _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *string, int *x, int *y));

extern Tcl_Command Blt_InitCmd _ANSI_ARGS_((Tcl_Interp *interp,
	char *nameSpace, Blt_CmdSpec *specPtr));

extern int Blt_InitCmds _ANSI_ARGS_((Tcl_Interp *interp, char *nameSpace,
	Blt_CmdSpec *specPtr, int nCmds));

extern int Blt_ConfigModified _ANSI_ARGS_(TCL_VARARGS(Tk_ConfigSpec *, specs));

extern void Blt_DStringAppendElements _ANSI_ARGS_(TCL_VARARGS(Tcl_DString *, args));

extern void Blt_MakeTransparentWindowExist _ANSI_ARGS_((Tk_Window tkwin,
	Window parent, int isBusy));

extern Window Blt_GetParent _ANSI_ARGS_((Display *display, Window tkwin));

extern void Blt_GetBoundingBox _ANSI_ARGS_((int width, int height,
	double theta, int *widthPtr, int *heightPtr, XPoint *pointArr));

extern void Blt_InitEpsCanvasItem _ANSI_ARGS_((Tcl_Interp *interp));

extern Pixmap Blt_RotateBitmap _ANSI_ARGS_((Tk_Window tkwin, Pixmap bitmap,
	int width, int height, double theta, int *widthPtr, int *heightPtr));

extern Pixmap Blt_ScaleBitmap _ANSI_ARGS_((Tk_Window tkwin, Pixmap srcBitmap,
	int srcWidth, int srcHeight, int scaledWidth, int scaledHeight));

extern Pixmap Blt_ScaleBitmapRegion _ANSI_ARGS_((Tk_Window tkwin,
	Pixmap srcBitmap, int srcWidth, int srcHeight,
	int scaledWidth, int scaledHeight, ImageRegion *regionPtr));

extern void Blt_TranslateAnchor _ANSI_ARGS_((int x, int y, int width,
	int height, Tk_Anchor anchor, int *transXPtr, int *transYPtr));

typedef void (Blt_TileChangedProc) _ANSI_ARGS_((ClientData clientData,
	Blt_Tile tile));

extern Blt_Tile Blt_GetTile _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin,
	char *imageName));

extern void Blt_FreeTile _ANSI_ARGS_((Blt_Tile tile));

extern char *Blt_NameOfTile _ANSI_ARGS_((Blt_Tile tile));

extern void Blt_SetTileChangedProc _ANSI_ARGS_((Blt_Tile tile,
	Blt_TileChangedProc *changeProc, ClientData clientData));

extern Pixmap Blt_PixmapOfTile _ANSI_ARGS_((Blt_Tile tile));

extern void Blt_SizeOfTile _ANSI_ARGS_((Blt_Tile tile, int *widthPtr,
	int *heightPtr));

extern void Blt_SetTileOrigin _ANSI_ARGS_((Tk_Window tkwin, GC gc, int x,
	int y));

extern int Blt_ConfigureWidgetComponent _ANSI_ARGS_((Tcl_Interp *interp,
	Tk_Window tkwin, char *name, char *class, Tk_ConfigSpec *specs,
	int argc, char **argv, char *widgRec, int flags));

extern void Blt_HSV _ANSI_ARGS_((XColor *colorPtr, double *huePtr,
	double *valPtr, double *satPtr));

extern void Blt_RGB _ANSI_ARGS_((double hue, double sat, double val,
	XColor *colorPtr));

extern int Blt_NaturalSpline _ANSI_ARGS_((double *xCntl, double *yCtrl,
	int nCtrls, double *X, double *Y, int nPoints));

extern int Blt_QuadraticSpline _ANSI_ARGS_((double *xCntl, double *yCtrl,
	int nCtrls, double *X, double *Y, int nPoints, double epsilon));

extern int Blt_ParseFlag _ANSI_ARGS_((ClientData, Tcl_Interp *, Tk_Window,
	char *, char *, int));
extern char *Blt_FlagPrint _ANSI_ARGS_((ClientData, Tk_Window, char *, int,
	Tcl_FreeProc **));

extern Window Blt_GetRealWindowId _ANSI_ARGS_((Tk_Window tkwin));
extern int Blt_RootX _ANSI_ARGS_((Tk_Window tkwin));
extern int Blt_RootY _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_MapTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_UnmapTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_RaiseTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin));
extern void Blt_ResizeTopLevelWindow _ANSI_ARGS_((Tk_Window tkwin, 
	int width, int height));
extern ClientData Blt_GetWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin));

extern void Blt_SetWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin,
	ClientData instanceData));

extern void Blt_DeleteWindowInstanceData _ANSI_ARGS_((Tk_Window tkwin));

extern int Blt_AdjustViewport _ANSI_ARGS_((int offset, int worldSize,
	int windowSize, int scrollUnits, int scrollMode));

extern int Blt_GetScrollInfo _ANSI_ARGS_((Tcl_Interp *interp, int argc,
	char **argv, int *offsetPtr, int worldSize, int windowSize,
	int scrollUnits, int scrollMode));

extern void Blt_UpdateScrollbar _ANSI_ARGS_((Tcl_Interp *interp,
	char *scrollCmd, double firstFract, double lastFract));

extern int Blt_ReparentWindow _ANSI_ARGS_((Display *display, Window window,
	Window newParent, int x, int y));

EXTERN void Blt_Panic _ANSI_ARGS_(TCL_VARARGS(char *, args));

#ifndef TCL_NAMESPACE_ONLY
#define TCL_NAMESPACE_ONLY TCL_GLOBAL_ONLY
#endif

EXTERN Tcl_Namespace *Tcl_GetCurrentNamespace _ANSI_ARGS_((Tcl_Interp *interp));
EXTERN Tcl_Namespace *Tcl_GetGlobalNamespace _ANSI_ARGS_((Tcl_Interp *interp));
EXTERN Tcl_Command Tcl_FindCommand _ANSI_ARGS_((Tcl_Interp *interp,
	char *name, Tcl_Namespace *nsPtr, int flags));

#if (TCL_MAJOR_VERSION >= 8)

EXTERN Tcl_Namespace *Tcl_CreateNamespace _ANSI_ARGS_((Tcl_Interp *interp,
	char *name, ClientData clientData,
	Tcl_NamespaceDeleteProc * nsDelProc));

EXTERN void Tcl_DeleteNamespace _ANSI_ARGS_((Tcl_Namespace *nsPtr));

EXTERN Tcl_Namespace *Tcl_FindNamespace _ANSI_ARGS_((Tcl_Interp *interp,
	char *name, Tcl_Namespace *context, int flags));

EXTERN int Tcl_Export _ANSI_ARGS_((Tcl_Interp *interp, Tcl_Namespace *nsPtr,
	char *name, int resetFlag));

EXTERN Tcl_Var Tcl_FindNamespaceVar _ANSI_ARGS_((Tcl_Interp *interp, char *name,
	Tcl_Namespace *contextNsPtr, int flags));

EXTERN void Tcl_PopCallFrame _ANSI_ARGS_((Tcl_Interp *interp));

EXTERN int Tcl_PushCallFrame _ANSI_ARGS_((Tcl_Interp *interp,
	Tcl_CallFrame * framePtr, Tcl_Namespace *nsPtr, int isProcCallFrame));

extern Tcl_HashTable *Blt_GetArrayVariableTable _ANSI_ARGS_((
	Tcl_Interp *interp, char *varName, int flags));

#endif /* TCL_MAJOR_VERSION >= 8 */

extern Tcl_Namespace *Blt_NamespaceOfVariable _ANSI_ARGS_((Tcl_Interp *interp,
	char *varName));

extern Tcl_CallFrame *Blt_EnterNamespace _ANSI_ARGS_((Tcl_Interp *interp,
	Tcl_Namespace *nsPtr));

extern void Blt_LeaveNamespace _ANSI_ARGS_((Tcl_Interp *interp,
	Tcl_CallFrame * framePtr));

extern int Blt_ParseQualifiedName _ANSI_ARGS_((Tcl_Interp *interp, char *name,
	Tcl_Namespace **nsPtrPtr, char **namePtr));

extern Tcl_Command Blt_CreateCommand _ANSI_ARGS_((Tcl_Interp *interp,
	char *cmdName, Tcl_CmdProc *proc, ClientData clientData,
	Tcl_CmdDeleteProc *deleteProc));

#if HAVE_JPEGLIB_H
extern int Blt_JPEGToPhoto _ANSI_ARGS_((Tcl_Interp *interp, char *fileName,
	Tk_PhotoHandle photo));
#endif /* HAVE_JPEGLIB_H */

/*
 * Define this if you want to be able to tile to the main window "."
 * This will cause a conflict with Tk if you try to compile and link
 * statically.
 */
#undef TILE_MAINWINDOW

#ifndef WIN32
#define NO_PRINTER
#endif

#define NO_TED

#ifndef NO_BEEP
extern Tcl_AppInitProc Blt_BeepInit;
#endif
#ifndef NO_BGEXEC
extern Tcl_AppInitProc Blt_BgexecInit;
#endif
#ifndef NO_BITMAP
extern Tcl_AppInitProc Blt_BitmapInit;
#endif
#ifndef NO_BITMAP
extern Tcl_AppInitProc Blt_BitmapInit;
#endif
#ifndef NO_BUSY
extern Tcl_AppInitProc Blt_BusyInit;
#endif
#ifndef NO_CONTAINER
extern Tcl_AppInitProc Blt_ContainerInit;
#endif
#ifndef NO_CUTBUFFER
extern Tcl_AppInitProc Blt_CutbufferInit;
#endif
#ifndef NO_DEBUG
extern Tcl_AppInitProc Blt_DebugInit;
#endif
#ifndef NO_DRAGDROP
extern Tcl_AppInitProc Blt_DragDropInit;
#endif
#ifndef NO_DND
extern Tcl_AppInitProc Blt_DndInit;
#endif
#ifndef NO_GRAPH
extern Tcl_AppInitProc Blt_GraphInit;
#endif
#ifndef NO_HIERBOX
extern Tcl_AppInitProc Blt_HierboxInit;
#endif
#ifndef NO_HTEXT
extern Tcl_AppInitProc Blt_HtextInit;
#endif
#ifdef WIN32
#ifndef NO_PRINTER
extern Tcl_AppInitProc Blt_PrinterInit;
#endif
#endif
#ifndef NO_TABLE
extern Tcl_AppInitProc Blt_TableInit;
#endif
#ifndef NO_VECTOR
extern Tcl_AppInitProc Blt_VectorInit;
#endif
#ifndef NO_WINOP
extern Tcl_AppInitProc Blt_WinopInit;
#endif
#ifndef NO_WATCH
extern Tcl_AppInitProc Blt_WatchInit;
#endif
#ifndef NO_SPLINE
extern Tcl_AppInitProc Blt_SplineInit;
#endif
#ifndef NO_TABSET
extern Tcl_AppInitProc Blt_TabsetInit;
#endif
#ifndef NO_TILEFRAME
extern Tcl_AppInitProc Blt_FrameInit;
#endif
#ifndef NO_TILEBUTTON
extern Tcl_AppInitProc Blt_ButtonInit;
#endif
#ifndef NO_TILESCROLLBAR
extern Tcl_AppInitProc Blt_ScrollbarInit;
#endif

#if (BLT_MAJOR_VERSION == 3)
#ifndef NO_MOUNTAIN
extern Tcl_AppInitProc Blt_MountainInit;
#endif
#endif
#ifndef NO_TED
extern Tcl_AppInitProc Blt_TedInit;
#endif

#ifdef WIN32
#ifdef CHECK_UNICODE_CALLS

#define _UNICODE
#define UNICODE

#define __TCHAR_DEFINED
typedef float *_TCHAR;

#define _TCHAR_DEFINED
typedef float *TCHAR;

#endif /* CHECK_UNICODE_CALLS */


extern double hypot(double x, double y);
extern int Blt_AsyncRead(int fd, char *buffer, unsigned int size);
extern int Blt_AsyncWrite(int fd, char *buffer, unsigned int size);
extern void Blt_CreateFileHandler(int fd, int flags, Tcl_FileProc * proc,
    ClientData clientData);
extern void Blt_DeleteFileHandler(int fd);
extern int Blt_GetPlatformId(void);
extern char *Blt_LastError(void);
extern int Blt_GetOpenPrinter(Tcl_Interp *interp, const char *id,
    Drawable *drawablePtr);
extern int Blt_OpenPrinterDoc(Tcl_Interp *interp, const char *id);
extern int Blt_ClosePrinterDoc(Tcl_Interp *interp, const char *id);
extern void Blt_GetPrinterScale(HDC dc, double *xRatio, double *yRatio);

#ifdef _MSC_VER
#define strncasecmp(s1,s2,n)	_strnicmp(s1,s2,n)
#define strcasecmp(s1,s2)	_stricmp(s1,s2)
#endif

#undef EXPORT
#define EXPORT __declspec(dllexport)

#ifndef _MSC_VER
/*
 * Add missing definitions from windgi.h, windowsx.h, and winspool.h
 */
#include <missing.h>
#endif

#define malloc(s)		Tcl_Alloc(s)
#define realloc(p, s)		Tcl_Realloc((p), (s))
#define free			Tcl_Free

#define strdup(s)		Blt_EmulateStrdup(s)
#define calloc(s,n)		Blt_EmulateCalloc((s),(n))
#define XCopyArea		Blt_EmulateXCopyArea
#define XCopyPlane		Blt_EmulateXCopyPlane
#define XDrawArcs		Blt_EmulateXDrawArcs
#define XDrawLine		Blt_EmulateXDrawLine
#define XDrawLines		Blt_EmulateXDrawLines
#define XDrawPoints		Blt_EmulateXDrawPoints
#define XDrawRectangle		Blt_EmulateXDrawRectangle
#define XDrawRectangles		Blt_EmulateXDrawRectangles
#define XDrawSegments		Blt_EmulateXDrawSegments
#define XDrawString		Blt_EmulateXDrawString
#define XFillArcs		Blt_EmulateXFillArcs
#define XFillRectangle		Blt_EmulateXFillRectangle
#define XFillRectangles		Blt_EmulateXFillRectangles
#define XFree			Blt_EmulateXFree
#define XGetWindowAttributes	Blt_EmulateXGetWindowAttributes
#define XLowerWindow		Blt_EmulateXLowerWindow
#define XMaxRequestSize		Blt_EmulateXMaxRequestSize
#define XRaiseWindow		Blt_EmulateXRaiseWindow
#define XReparentWindow		Blt_EmulateXReparentWindow
#define XSetDashes		Blt_EmulateXSetDashes
#define XUnmapWindow		Blt_EmulateXUnmapWindow
#define XWarpPointer		Blt_EmulateXWarpPointer

EXTERN char *Blt_EmulateStrdup(const char *string);
EXTERN void *Blt_EmulateCalloc(unsigned int size, unsigned int nElems);
EXTERN GC Blt_EmulateXCreateGC(Display *display, Drawable drawable,
    unsigned long mask, XGCValues *valuesPtr);
EXTERN void Blt_EmulateXCopyArea(Display *display, Drawable src, Drawable dest,
    GC gc, int src_x, int src_y, unsigned int width, unsigned int height,
    int dest_x, int dest_y);
EXTERN void Blt_EmulateXCopyPlane(Display *display, Drawable src,
    Drawable dest, GC gc, int src_x, int src_y, unsigned int width,
    unsigned int height, int dest_x, int dest_y, unsigned long plane);
EXTERN void Blt_EmulateXDrawArcs(Display *display, Drawable drawable, GC gc,
    XArc *arcArr, int nArcs);
EXTERN void Blt_EmulateXDrawLine(Display *display, Drawable drawable, GC gc,
    int x1, int y1, int x2, int y2);
EXTERN void Blt_EmulateXDrawLines(Display *display, Drawable drawable, GC gc,
    XPoint *pointArr, int nPoints, int mode);
EXTERN void Blt_EmulateXDrawPoints(Display *display, Drawable drawable, GC gc,
    XPoint *pointArr, int nPoints, int mode);
EXTERN void Blt_EmulateXDrawRectangle(Display *display, Drawable drawable,
    GC gc, int x, int y, unsigned int width, unsigned int height);
EXTERN void Blt_EmulateXDrawRectangles(Display *display, Drawable drawable,
    GC gc, XRectangle *rectArr, int nRects);
EXTERN void Blt_EmulateXDrawSegments(Display *display, Drawable drawable,
    GC gc, XSegment *segArr, int nSegments);
EXTERN void Blt_EmulateXDrawSegments(Display *display, Drawable drawable,
    GC gc, XSegment *segArr, int nSegments);
EXTERN void Blt_EmulateXDrawString(Display *display, Drawable drawable, GC gc,
    int x, int y, _Xconst char *string, int length);
EXTERN void Blt_EmulateXFillArcs(Display *display, Drawable drawable, GC gc,
    XArc *arcArr, int nArcs);
EXTERN void Blt_EmulateXFillRectangle(Display *display, Drawable drawable,
    GC gc, int x, int y, unsigned int width, unsigned int height);
EXTERN void Blt_EmulateXFillRectangles(Display *display, Drawable drawable,
    GC gc, XRectangle *rectArr, int nRects);
EXTERN void Blt_EmulateXFree(void *ptr);
EXTERN Status Blt_EmulateXGetWindowAttributes(Display *display, Window window,
    XWindowAttributes * attrsPtr);
EXTERN void Blt_EmulateXLowerWindow(Display *display, Window window);
EXTERN void Blt_EmulateXMapWindow(Display *display, Window window);
EXTERN long Blt_EmulateXMaxRequestSize(Display *display);
EXTERN void Blt_EmulateXRaiseWindow(Display *display, Window window);
EXTERN void Blt_EmulateXReparentWindow(Display *display, Window window,
    Window parent, int x, int y);
EXTERN void Blt_EmulateXSetDashes(Display *display, GC gc, int dashOffset,
    _Xconst char *dashList, int n);
EXTERN void Blt_EmulateXUnmapWindow(Display *display, Window window);
EXTERN void Blt_EmulateXWarpPointer(Display *display, Window srcWindow,
    Window destWindow, int srcX, int srcY, unsigned int srcWidth,
    unsigned int srcHeight, int destX, int destY);

extern unsigned char *Blt_GetBitmapData _ANSI_ARGS_((Display *display,
	Pixmap bitmap, int width, int height, int *pitchPtr));

extern HFONT Blt_CreateRotatedFont _ANSI_ARGS_((Tk_Window tkwin,
	unsigned long font, double theta));

extern HPALETTE Blt_GetSystemPalette _ANSI_ARGS_((void));

extern HPEN Blt_GCToPen _ANSI_ARGS_((HDC dc, GC gc));

#endif /* WIN32 */

#endif /*_BLT_INT_H*/
