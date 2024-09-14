#include "/sys/include/ape/config.h"

/* Define to the copyright year printed by --version. */
#define COPYRIGHT_YEAR 2009

/* Define to 1 if // is a file system root distinct from /. */
#define DOUBLE_SLASH_IS_DISTINCT_ROOT 1

/* Follow symlinks when processing in place */
#undef ENABLE_FOLLOW_SYMLINKS

/* Define to indicate the 'malloc' module. */
#define GNULIB_MALLOC_GNU 1

#if FILE_SYSTEM_BACKSLASH_IS_FILE_NAME_SEPARATOR
# define ISSLASH(C) ((C) == '/' || (C) == '\\')
#else
# define ISSLASH(C) ((C) == '/')
#endif

/* Name of package */
#define PACKAGE "sed"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "bug-gnu-utils@gnu.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "sed"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "sed 4.2.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "sed"

/* Define to the version of this package. */
#define PACKAGE_VERSION "4.2.1"

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'ptrdiff_t'. */
#define PTRDIFF_T_SUFFIX l

/* Define if rename does not work for source file names with a trailing slash,
   like the one from SunOS 4.1.1_U1. */
#define RENAME_TRAILING_SLASH_BUG 1

/* Define to the version of GNU sed whose features are supported by this sed.
   */
#define SED_FEATURE_VERSION "4.2"

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'sig_atomic_t'. */
#define SIG_ATOMIC_T_SUFFIX 

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'size_t'. */
#define SIZE_T_SUFFIX ul

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
#define STACK_DIRECTION -1

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */


/* Define to 1 if you want getc etc. to use unlocked I/O if available.
   Unlocked I/O can improve performance in unithreaded apps, but it is not
   safe for multithreaded apps. */
#define USE_UNLOCKED_IO 1

/* Version number of package */
#define VERSION "4.2.1"

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wchar_t'. */
#define WCHAR_T_SUFFIX u

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wint_t'. */
#define WINT_T_SUFFIX 

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define if you want regoff_t to be at least as wide POSIX requires. */
#define _REGEX_LARGE_OFFSETS 1

/* Include BSD functions in regex, used by the testsuite */
/* #undef _REGEX_RE_COMP */

/* Define to 500 only on HP-UX. */
/* #undef _XOPEN_SOURCE */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to rpl_gmtime if the replacement function should be used. */
/* #undef gmtime */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Work around a bug in Apple GCC 4.0.1 build 5465: In C99 mode, it supports
   the ISO C 99 semantics of 'extern inline' (unlike the GNU C semantics of
   earlier versions), but does not display it by setting __GNUC_STDC_INLINE__.
   __APPLE__ && __MACH__ test for MacOS X.
   __APPLE_CC__ tests for the Apple compiler and its version.
   __STDC_VERSION__ tests for the C99 mode.  */
#if defined __APPLE__ && defined __MACH__ && __APPLE_CC__ >= 5465 && !defined __cplusplus && __STDC_VERSION__ >= 199901L && !defined __GNUC_STDC_INLINE__
# define __GNUC_STDC_INLINE__ 1
#endif

/* Define to rpl_localtime if the replacement function should be used. */
/* #undef localtime */

/* Define to rpl_malloc if the replacement function should be used. */
/* #undef malloc */

/* Define to a type if <wchar.h> does not define. */
//define mbstate_t int

/* Define to the type of st_nlink in struct stat, or a supertype. */
/* #undef nlink_t */

/* Define to rpl_re_comp if the replacement should be used. */
#define re_comp rpl_re_comp

/* Define to rpl_re_compile_fastmap if the replacement should be used. */
#define re_compile_fastmap rpl_re_compile_fastmap

/* Define to rpl_re_compile_pattern if the replacement should be used. */
#define re_compile_pattern rpl_re_compile_pattern

/* Define to rpl_re_exec if the replacement should be used. */
#define re_exec rpl_re_exec

/* Define to rpl_re_match if the replacement should be used. */
#define re_match rpl_re_match

/* Define to rpl_re_match_2 if the replacement should be used. */
#define re_match_2 rpl_re_match_2

/* Define to rpl_re_search if the replacement should be used. */
#define re_search rpl_re_search

/* Define to rpl_re_search_2 if the replacement should be used. */
#define re_search_2 rpl_re_search_2

/* Define to rpl_re_set_registers if the replacement should be used. */
#define re_set_registers rpl_re_set_registers

/* Define to rpl_re_set_syntax if the replacement should be used. */
#define re_set_syntax rpl_re_set_syntax

/* Define to rpl_re_syntax_options if the replacement should be used. */
#define re_syntax_options rpl_re_syntax_options

/* Define to rpl_regcomp if the replacement should be used. */
//define regcomp rpl_regcomp

/* Define to rpl_regerror if the replacement should be used. */
//define regerror rpl_regerror

/* Define to rpl_regexec if the replacement should be used. */
//define regexec rpl_regexec

/* Define to rpl_regfree if the replacement should be used. */
//define regfree rpl_regfree

/* Define to rpl_rename if the replacement function should be used. */
//define rename rpl_rename

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
/* #undef restrict */
/* Work around a bug in Sun C++: it does not support _Restrict, even
   though the corresponding Sun C compiler does, which causes
   "#define restrict _Restrict" in the previous line.  Perhaps some future
   version of Sun C++ will work with _Restrict; if so, it'll probably
   define __RESTRICT, just as Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef ssize_t */

/* Define to rpl_strnlen if the replacement function should be used. */
//define strnlen rpl_strnlen

/* Define as a marker that can be attached to function parameter declarations
   for parameters that are not used.  This helps to reduce warnings, such as
   from GCC -Wunused-parameter.  */
#if __GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)
# define _UNUSED_PARAMETER_ __attribute__ ((__unused__))
#else
# define _UNUSED_PARAMETER_
#endif


/* #define locale_charset "UTF-8 UTF-8" */
