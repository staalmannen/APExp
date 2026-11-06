/*
 * config.h for libgd 2.3.3 under APExp -- HAND-ANSWERED.
 *
 * The template is `src/config.hin' (autoheader's output) and
 * `sys/lib/tests/cfghdr-sweep.py' pairs the two: a `#define' spelled
 * in the template is text copied STRAIGHT THROUGH by autoheader and
 * must appear here, while an unanswered `#undef' is a question we are
 * deliberately silent on.
 *
 * ***THE REASON THIS IS HAND-ANSWERED RATHER THAN CONFIGURED IS THE
 * ONE clisp's `mprotect' ESTABLISHED***: a working `configure' would
 * get this machine wrong.  It probes by compiling and linking, and
 * several things here link and then do nothing -- so a probe that
 * passes is not evidence the capability exists.  Every line below
 * says how it was answered.
 *
 * `lib/png/mkfile' is the precedent for the placement: the answered
 * file sits at the top of the vendored tree and the mkfile reaches it
 * with `-I$GDSOURCE', while the sources' own `#include "config.h"'
 * finds it there.  **It must be in `lib/gd/mkfile's HFILES**, because
 * mk does not scan `#include's and editing this file would otherwise
 * rebuild nothing.
 */

#ifndef APEXP_LIBGD_CONFIG_H
#define APEXP_LIBGD_CONFIG_H

/* Not Win32. */
/* #undef BGDWIN32 */

/*
 * gd's own `.gd' and `.gd2' formats, which need no outside library.
 * On by default upstream (`configure.ac's --disable-gd-formats).
 */
#define ENABLE_GD_FORMATS 1

/* ---- headers, all present in `sys/include/ape' ------------------- */
#define HAVE_DIRENT_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define STDC_HEADERS 1

/*
 * `<dlfcn.h>' EXISTS HERE AND IS ANSWERED NO, for the same reason
 * php's `config.h' answers it no: APE ships the header, and its
 * `dlsym' is `return NULL'.  Plan 9 has no dynamic linking, so a
 * header-presence probe would say yes and be useless.  No libgd
 * source reads this macro -- it is autoconf bookkeeping -- but
 * answering it yes would be a false statement in a file other people
 * read as a capability list.
 */
/* #undef HAVE_DLFCN_H */

/* ---- the two libraries this build actually links ----------------- */
/*
 * Both are built by this tree (`lib/z', `lib/png') and both come in
 * by `#pragma lib' from their own headers, so `lib/gd/mkfile' names
 * no libraries.  **libpng is not optional for us**: it is the only
 * compressed output format this build can write.
 */
#define HAVE_LIBPNG 1
#define HAVE_LIBZ 1

/*
 * ---- iconv: YES, and checked rather than assumed -----------------
 * `apfunc-sweep.py' reports `iconv', `iconv_open' and `iconv_close'
 * all DEFINED in libap (`locale/iconv.c', `locale/iconv_close.c') --
 * not the declared-only middle state that link-fails far from the
 * claim.  Used by `gdkanji.c' for the Shift-JIS conversions.
 */
#define HAVE_ICONV 1
#define HAVE_ICONV_H 1
#define HAVE_ICONV_T_DEF 1
/* APE's iconv() takes a non-const `char **inbuf', as POSIX says. */
#define ICONV_CONST

/*
 * ---- pthread: YES, AND IT IS UNREACHABLE IN THIS BUILD -----------
 * libap has the mutex functions, so yes is the truthful answer. But
 * `gdhelpers.h's `gdMutex*' macros have exactly three call sites and
 * **all three are in `gdft.c'**, whose entire body is inside
 * `#ifdef HAVE_LIBFREETYPE' -- which is answered no below.
 *
 * *So this line changes nothing today*, and that is worth writing
 * down rather than leaving for someone to rediscover: **a working
 * libgd here is NOT evidence that libap's mutexes work**, because no
 * gd code path reaches one. It starts mattering the day FreeType
 * arrives.
 */
#define HAVE_PTHREAD 1
/* #undef HAVE_PTHREAD_PRIO_INHERIT */

/*
 * ---- the optional format and font libraries, none of them here ---
 *
 * Each `#undef' below costs a named capability rather than breaking
 * the build: every one of these files compiles either to nothing or
 * to a function that returns an honest error.
 *
 * **FreeType is the one that is felt**, and it is not a silent loss:
 * `gdft.c:46's no-FreeType arm makes `gdImageStringFT' return the
 * string "libgd was not built with FreeType font support", so a
 * caller is told. What remains is the five BUILT-IN BITMAP FONTS
 * (`gdfontt/s/mb/l/g'), which are fixed-size and adequate for labels
 * and nothing more. Anything wanting scalable text needs a FreeType
 * port first.
 *
 * JPEG, WebP, AVIF, HEIF, TIFF and XPM are absent libraries, so those
 * readers and writers are simply not compiled in. **What this build
 * CAN do is still most of gd**: PNG, GIF, BMP, WBMP, XBM, TGA and
 * gd/gd2 in and out, plus all the drawing, cropping, rotation,
 * scaling, interpolation, palette and filter code, which is the part
 * that is pure arithmetic and the part worth exercising a compiler
 * with.
 */
/* #undef HAVE_FT2BUILD_H */
/* #undef HAVE_LIBFREETYPE */
/* #undef HAVE_LIBFONTCONFIG */
/* #undef HAVE_LIBRAQM */
/* #undef HAVE_LIBJPEG */
/* #undef HAVE_LIBWEBP */
/* #undef HAVE_LIBAVIF */
/* #undef HAVE_LIBHEIF */
/* #undef HAVE_LIBTIFF */
/* #undef HAVE_LIBXPM */
/* #undef HAVE_LIBIMAGEQUANT */

/*
 * `HAVE_LIBM' is autoconf's "-lm exists" and no libgd source reads
 * it; on Plan 9 the math functions are in libap and there is no
 * separate `-lm' to find.
 */
/* #undef HAVE_LIBM */

/* No OpenMP in kencc. */
/* #undef HAVE_OPENMP */

/*
 * kencc has no `__attribute__((visibility("default")))'. No libgd
 * source reads this; `gd.h' guards its own `BGD_EXPORT_DATA_PROT'
 * on `_WIN32' alone, so the default-visible static library is what
 * we get either way.
 */
/* #undef HAVE_VISIBILITY */

/* ---- identification ---------------------------------------------- */
#define PACKAGE "libgd"
#define PACKAGE_NAME "GD"
#define PACKAGE_TARNAME "libgd"
#define PACKAGE_VERSION "2.3.3"
#define PACKAGE_STRING "GD 2.3.3"
#define PACKAGE_BUGREPORT "https://github.com/libgd/libgd/issues"
#define PACKAGE_URL "https://libgd.github.io/"
#define VERSION "2.3.3"

/* libtool's uninstalled-object directory; no libtool here. */
/* #undef LT_OBJDIR */
/* #undef PTHREAD_CREATE_JOINABLE */

#endif /* APEXP_LIBGD_CONFIG_H */
