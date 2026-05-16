/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if __attribute__((__alias__())) is supported */
/* #undef HAVE_ALIAS_ATTRIBUTE */

/* Define to 1 if you have the <alloca.h> header file. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the 'bsearch' function. */
/* #undef HAVE_BSEARCH */

/* Define to 1 if you have the declaration of 'isblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISBLANK 1

/* Define to 1 if you have the 'faccessat' function. */
/* #undef HAVE_FACCESSAT */

/* Define to 1 if you have the 'fnmatch' function. */
/* #undef HAVE_FNMATCH */

/* Define to 1 your system supports F_DUPFD_CLOEXEC */
#define HAVE_F_DUPFD_CLOEXEC 1

/* Define to 1 if you have the 'getpwnam' function. */
/* #undef HAVE_GETPWNAM */

/* Define to 1 if you have the 'getrlimit' function. */
/* #undef HAVE_GETRLIMIT */

/* Define to 1 if you have the 'glob' function. */
/* #undef HAVE_GLOB */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the 'isalpha' function. */
/* #undef HAVE_ISALPHA */

/* Define to 1 if you have the 'killpg' function. */
/* #undef HAVE_KILLPG */

/* Define to 1 if you have the 'memfd_create' function. */
/* #undef HAVE_MEMFD_CREATE */

/* Define to 1 if you have the 'mempcpy' function. */
/* #undef HAVE_MEMPCPY */

/* Define to 1 if you have the 'memrchr' function. */
/* #undef HAVE_MEMRCHR */

/* Define to 1 if you have the <minix/config.h> header file. */
/* #undef HAVE_MINIX_CONFIG_H */

/* Define to 1 if you have the <paths.h> header file. */
/* #undef HAVE_PATHS_H */

/* Define to 1 if you have the 'sigsetmask' function. */
/* #undef HAVE_SIGSETMASK */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the 'stpcpy' function. */
/* #undef HAVE_STPCPY */

/* Define to 1 if you have the 'strchrnul' function. */
/* #undef HAVE_STRCHRNUL */

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the 'strsignal' function. */
/* #undef HAVE_STRSIGNAL */

/* Define to 1 if you have the 'strtod' function. */
/* #undef HAVE_STRTOD */

/* Define to 1 if you have the 'strtoimax' function. */
/* #undef HAVE_STRTOIMAX */

/* Define to 1 if you have the 'strtoumax' function. */
/* #undef HAVE_STRTOUMAX */

/* Define if your `struct stat' has `st_mtim' */
#define HAVE_ST_MTIM 1

/* Define to 1 if you have the 'sysconf' function. */
/* #undef HAVE_SYSCONF */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the 'tee' function. */
/* #undef HAVE_TEE */

/* Define if your faccessat tells root all files are executable */
/* #undef HAVE_TRADITIONAL_FACCESSAT */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the 'wait3' function. */
/* #undef HAVE_WAIT3 */

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Name of package */
#define PACKAGE "dash"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "dash"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "dash 0.5.13.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "dash"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.5.13.4"

/* Define to printf format string for intmax_t */
/* #undef PRIdMAX */

/* The size of 'intmax_t', as computed by sizeof. */
#define SIZEOF_INTMAX_T 0

/* The size of 'long long int', as computed by sizeof. */
#define SIZEOF_LONG_LONG_INT 0

/* Define if you build with -DSMALL */
#define SMALL 1

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Non-zero if memfd_create(3) should be used */
#define USE_MEMFD_CREATE 1

/* Enable extensions on AIX, Interix, z/OS.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable general extensions on macOS.  */
#ifndef _DARWIN_C_SOURCE
# define _DARWIN_C_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable X/Open compliant socket functions that do not require linking
   with -lxnet on HP-UX 11.11.  */
#ifndef _HPUX_ALT_XOPEN_SOCKET_API
# define _HPUX_ALT_XOPEN_SOCKET_API 1
#endif
/* Identify the host operating system as Minix.
   This macro does not affect the system headers' behavior.
   A future release of Autoconf may stop defining this macro.  */
#ifndef _MINIX
/* # undef _MINIX */
#endif
/* Enable general extensions on NetBSD.
   Enable NetBSD compatibility extensions on Minix.  */
#ifndef _NETBSD_SOURCE
# define _NETBSD_SOURCE 1
#endif
/* Enable OpenBSD compatibility extensions on NetBSD.
   Oddly enough, this does nothing on OpenBSD.  */
#ifndef _OPENBSD_SOURCE
# define _OPENBSD_SOURCE 1
#endif
/* Define to 1 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_SOURCE
/* # undef _POSIX_SOURCE */
#endif
/* Define to 2 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_1_SOURCE
/* # undef _POSIX_1_SOURCE */
#endif
/* Enable POSIX-compatible threading on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-5:2014.  */
#ifndef __STDC_WANT_IEC_60559_ATTRIBS_EXT__
# define __STDC_WANT_IEC_60559_ATTRIBS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-1:2014.  */
#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
# define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-2:2015.  */
#ifndef __STDC_WANT_IEC_60559_DFP_EXT__
# define __STDC_WANT_IEC_60559_DFP_EXT__ 1
#endif
/* Enable extensions specified by C23 Annex F.  */
#ifndef __STDC_WANT_IEC_60559_EXT__
# define __STDC_WANT_IEC_60559_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-4:2015.  */
#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
# define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#endif
/* Enable extensions specified by C23 Annex H and ISO/IEC TS 18661-3:2015.  */
#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
# define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TR 24731-2:2010.  */
#ifndef __STDC_WANT_LIB_EXT2__
# define __STDC_WANT_LIB_EXT2__ 1
#endif
/* Enable extensions specified by ISO/IEC 24747:2009.  */
#ifndef __STDC_WANT_MATH_SPEC_FUNCS__
# define __STDC_WANT_MATH_SPEC_FUNCS__ 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable X/Open extensions.  Define to 500 only if necessary
   to make mbstate_t available.  */
#ifndef _XOPEN_SOURCE
/* # undef _XOPEN_SOURCE */
#endif


/* Non-zero if tee(2) should be used */
#define USE_TEE 0

/* Version number of package */
#define VERSION "0.5.13.4"

/* Define if you build with -DWITH_LINENO */
#define WITH_LINENO 1

/* Define to system shell path */
#define _PATH_BSHELL "/bin/sh"

/* Define to devnull device node path */
#define _PATH_DEVNULL "/dev/null"

/* Define to tty device node path */
#define _PATH_TTY "/dev/tty"

/* 64-bit operations are the same as 32-bit */
#define dirent64 dirent

/* 64-bit operations are the same as 32-bit */
#define fstat64 fstat

/* 64-bit operations are the same as 32-bit */
#define glob64 glob

/* 64-bit operations are the same as 32-bit */
#define glob64_t glob_t

/* 64-bit operations are the same as 32-bit */
#define globfree64 globfree

/* 64-bit operations are the same as 32-bit */
#define lstat64 lstat

/* 64-bit operations are the same as 32-bit */
#define open64 open

/* 64-bit operations are the same as 32-bit */
#define readdir64 readdir

/* klibc has bsd_signal instead of signal */
/* #undef signal */

/* 64-bit operations are the same as 32-bit */
#define stat64 stat
