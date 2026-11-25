#define PACKAGE	"Equis"

/*
 * The arm list must name every architecture the build can target.
 * amd64 was missing, so every compile on it reached the #else and
 * died: this is the first thing an amd64 build of X11 hits.
 */
#if defined(T386) || defined(Tamd64) || defined(Talpha) || defined(Tarm) || defined(Tarm64)
#undef WORDS_BIGENDIAN
#define BYTE_ORDER	LITTLE_ENDIAN
#elif defined(Tmips) || defined(Tsparc) || defined(Tpower) || defined(Tpower64)
#define WORDS_BIGENDIAN 1
#define BYTE_ORDER	BIG_ENDIAN
#else
#error unknown byte order: add this $objtype to the arms in config.h
#endif

#define EWOULDBLOCK EAGAIN
#define HAVE_INTTYPES_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define RETSIGTYPE void
#define STDC_HEADERS 1


/* libXaw */
extern int _SLEEP(long);
#define usleep(x)	_SLEEP((x)/1000)
#define USE_XWCHAR_STRING 1

/* libX11 */
#define TCPCONN 1
#define UNIXCONN 1
#define NO_XLOCALEDIR 1
#define USE_XCB 0
#define X11_DATADIR "/sys/lib/ape/X11"
#define X11_LIBDIR "/$M/lib/ape/X11"
#define XCMS 1
#define XERRORDB "/sys/lib/ape/X11/XErrorDB"
#define XF86BIGFONT 1
#define XKB 1
#define XKEYSYMDB "/sys/lib/ape/X11/XKeysymDB"
#define XLOCALEDATADIR "/sys/lib/ape/X11/locale"
#define XLOCALEDIR "/sys/lib/ape/X11/locale"
#define XLOCALELIBDIR "/sys/lib/ape/X11/locale"

/* libXfont */
#define FONTCACHE 1
#define LOADABLEFONTS 1
#define XFONT_BDFFORMAT 1
#define XFONT_BITMAP 1
#define XFONT_BUILTINS 1
#define XFONT_FC 1
#define XFONT_FONTFILE 1
#define XFONT_FREETYPE 1
#define XFONT_PCFFORMAT 1
#define XFONT_SNFFORMAT 1
#define XFONT_SPEEDO 1
#define XFONT_TYPE1 1
#define X_GZIP_FONT_COMPRESSION 1

extern double hypot(double, double);
/*
 * INT32_MIN and INT32_MAX used to be defined here as INT_MIN/INT_MAX,
 * for a compiler without <stdint.h>.  APE has <stdint.h>, which defines
 * them, and the two definitions differ (INT_MIN is not even visible at
 * this point), so every pixman and xkbfile TU that reached <inttypes.h>
 * after this file got "Macro redefinition of INT32_MIN".
 */

/* libXmu */
#define HAS_SNPRINTF 1
#define BITMAPDIR	"/sys/lib/ape/X11/bitmaps"

/* libXpm */
#define LOCALEDIR "/sys/lib/ape/X11/locale"
#define STAT_ZFILE 1

/* libXt */
#define USE_SNPRINTF 
#define appdefaultdir "/sys/lib/ape/X11/app-defaults"

#define XFILESEARCHPATHDEFAULT "/sys/lib/ape/X11/%L/%T/%N%C%S:/sys/lib/ape/X11/%l/%T/%N%C%S:/sys/lib/ape/X11/%T/%N%C%S:/sys/lib/ape/X11/%L/%T/%N%S:/sys/lib/ape/X11/%l/%T/%N%S:/sys/lib/ape/X11/%T/%N%S"

/* libfontenc */
#define HAVE_LIBZ 1
