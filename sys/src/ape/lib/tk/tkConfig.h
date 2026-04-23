#ifndef _TKCONFIG
#define _TKCONFIG

#define PACKAGE_NAME tk
#define PACKAGE_VERSION 9.0.3

#define STATIC_BUILD 1

#define TK_PLATFORM "plan9"

/*
 * Tk build configuration for Plan 9 / APExp.
 */

#define HAVE_STDLIB_H	1
#define HAVE_STRING_H	1
#define HAVE_UNISTD_H	1

/* We do NOT have X11 proper; we have our own draw.h backend */
#undef HAVE_LIBX11
#undef HAVE_X11

/* Font support: Plan 9 native fonts */
#undef HAVE_XRENDER
#undef HAVE_XFT
#undef HAVE_FONTCONFIG

/* PNG support via libpng (if available) */
#undef HAVE_LIBPNG

/* No OpenGL */
#undef HAVE_GL

/* TK_LIBRARY: where tk.tcl lives */
#define CFG_INSTALL_LIBDIR	"/sys/lib/tk"
#define CFG_RUNTIME_LIBDIR	CFG_INSTALL_LIBDIR

/* Cursors — we use none */
#undef HAVE_XCURSOR

/* No input methods */
#undef TK_USE_INPUT_METHODS

/* No modules */
#undef HAVE_MODULE_SUPPORT

#endif /* _TKCONFIG */
