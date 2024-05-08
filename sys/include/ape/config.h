#define PLAN9
#include <_apetypes.h> /* for architecture-specific stuff */

/* Define if the system does not provide POSIX.1 features except
   with this defined.  */
#ifndef _POSIX_1_SOURCE
#define _POSIX_1_SOURCE 2
#endif

/* Activate all extensions because why not?  */
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif

#ifndef _BSD_EXTENSION
#define _BSD_EXTENSION 1
#endif

#ifndef D_SUSV2_SOURCE
#define D_SUSV2_SOURCE 1
#endif

#ifndef _RESEARCH_SOURCE
#define _RESEARCH_SOURCE 1
#endif

#ifndef _PLAN9_SOURCE
#define _PLAN9_SOURCE 1
#endif

#ifndef _LIMITS_EXTENSION
#define _LIMITS_EXTENSION 1
#endif

#ifndef _NET_EXTENSION
#define _NET_EXTENSION 1
#endif

#ifndef _C99_SNPRINTF_EXTENSION
#define _C99_SNPRINTF_EXTENSION 1
#endif

#ifndef _REGEXP_EXTENSION
#define _REGEXP_EXTENSION 1
#endif

#ifndef _REENTRANT_SOURCE
#define _REENTRANT_SOURCE 1
#endif

/* typical config.h stuff stolen from various application-specific generated config.h */

/* Define to 1 if using `alloca.c'. */
#define C_ALLOCA 1

/* Define to 1 if using `getloadavg.c'. */
#define C_GETLOADAVG 1

/* Define if dup2() preserves the close-on-exec flag (ultrix does this) */
//#define DUP2_BROKEN 1

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 0

/* Define to 1 if you have the `alarm' function. */
#define HAVE_ALARM 1

/* Define to 1 if you have 'alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if <alloca.h> works. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the `atexit' function. */
#define HAVE_ATEXIT 1

/* Define to 1 if you have the `bcopy' function. */
#define HAVE_BCOPY 1

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* Define to 1 if you have the `bzero' function. */
#define HAVE_BZERO 1

/* Define to 1 if you have the <bzlib.h> header file. */
#define HAVE_BZLIB_H 1

/* Define if you have the clock_gettime function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the declaration of `__sys_siglist', and to 0 if you
   don't. */
#define HAVE_DECL___SYS_SIGLIST 0

/* Define to 1 if you have the declaration of `clearerr_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_CLEARERR_UNLOCKED 0

/* Define to 1 if you have the declaration of `feof_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_FEOF_UNLOCKED 0

/* Define to 1 if you have the declaration of `ferror_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FERROR_UNLOCKED 0

/* Define to 1 if you have the declaration of `fflush_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FFLUSH_UNLOCKED 0

/* Define to 1 if you have the declaration of `fgets_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FGETS_UNLOCKED 0

/* Define to 1 if you have the declaration of `fputc_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTC_UNLOCKED 0

/* Define to 1 if you have the declaration of `fputs_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTS_UNLOCKED 0

/* Define to 1 if you have the declaration of `fread_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FREAD_UNLOCKED 0

/* Define to 1 if you have the declaration of `fwrite_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FWRITE_UNLOCKED 0

/* Define to 1 if you have the declaration of `getchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_GETCHAR_UNLOCKED 0

/* Define to 1 if you have the declaration of `getc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_GETC_UNLOCKED 0

/* Define to 1 if you have the declaration of `getdelim', and to 0 if you
   don't. */
#define HAVE_DECL_GETDELIM 1

/* Define to 1 if you have the declaration of `getenv', and to 0 if you don't.
   */
#define HAVE_DECL_GETENV 1

/* Define to 1 if you have the declaration of `getline', and to 0 if you
   don't. */
#define HAVE_DECL_GETLINE 1

/* Define to 1 if you have the declaration of `isblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISBLANK 0

/* Define to 1 if you have the declaration of `putchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_PUTCHAR_UNLOCKED 0

/* Define to 1 if you have the declaration of `putc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_PUTC_UNLOCKED 0

/* Define to 1 if you have the declaration of `strerror', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR 1

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 0

/* Define to 1 if you have the declaration of `strndup', and to 0 if you
   don't. */
#define HAVE_DECL_STRNDUP 0

/* Define to 1 if you have the declaration of `strnlen', and to 0 if you
   don't. */
#define HAVE_DECL_STRNLEN 0

/* Define to 1 if you have the declaration of `tzname', and to 0 if you don't.
   */
#define HAVE_DECL_TZNAME 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define if you have the dup2 function.  */
#define HAVE_DUP2 1

/* Define to 1 if you have the <editline/readline.h> header file. TODO */
/* #undef HAVE_EDITLINE_READLINE_H */

/* Define to 1 if you have the <edit/readline/readline.h> header file. TODO*/
/* #undef HAVE_EDIT_READLINE_READLINE_H */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the `fchmod' function. */
#define HAVE_FCHMOD 1

/* Define to 1 if you have the `fcntl' function. */
#define HAVE_FCNTL 1

/* Define if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fdopen' function. */
#define HAVE_FDOPEN 1

/* Define to 1 if you have the `fmod' function. */
#define HAVE_FMOD 1

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define to 1 if you have the `getgrent' function. */
#define HAVE_GETGRENT 1

/* Define if you have the getgroups function.  */
#define HAVE_GETGROUPS 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* Define if you have the `getopt' function. */
#define HAVE_GETOPT 1

/* Define if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if getopt variables are declared in header */
#define HAVE_GETOPT_HEADER 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `isatty' function. */
#define HAVE_ISATTY 1

/* Define to 1 if you have the <libintl.h> header file. */
#define HAVE_LIBINTL_H 1

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* pthread library */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if the system has the type `long long'. */
#define HAVE_LONG_LONG 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you support file names longer than 14 characters. */
#define HAVE_LONG_FILE_NAMES 1

/* Define to 1 if the system has the type `long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if your system has a GNU libc compatible `malloc' function, and
   to 0 otherwise. */
#define HAVE_MALLOC 1

/* Define if malloc, realloc, and calloc set errno on allocation failure. */
#define HAVE_MALLOC_POSIX 1

/* Define to 1 if you have the `mbrtowc' function. */
#define HAVE_MBRTOWC 1

/* Define to 1 if you have the `mbsinit' function. */
#define HAVE_MBSINIT 1

/* Define to 1 if <wchar.h> declares mbstate_t. */
#define HAVE_MBSTATE_T 1

/* Define to 1 if you have the `memchr' function. */
#define HAVE_MEMCHR 1

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the `mempcpy' function. */
#define HAVE_MEMPCPY 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

#define HAVE_MKDIR 1

/* Define to 1 if you have the `mktemp' function. */
#define HAVE_MKTEMP 1

/* Define to 1 if mkstemp() is available and working. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the `pathconf' function. */
#define HAVE_PATHCONF 1

/* Define to 1 if you have the `pipe' function. */
#define HAVE_PIPE 1

/* Define to 1 if you have the `popen' function. */
#define HAVE_POPEN 1

/* Define to 1 if you have the `pow' function. */
#define HAVE_POW 1

/* Define if C compiler groks function prototypes */
#define HAVE_PROTOTYPES 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
/* #undef HAVE_PTHREAD_PRIO_INHERIT */

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if your system has a GNU libc compatible `realloc' function,
   and to 0 otherwise. */
#define HAVE_REALLOC 1

/* Define if the 'realloc' function is POSIX compliant. */
#define HAVE_REALLOC_POSIX 1

/* Define to 1 if you have the <readline.h> header file. */
/* #undef HAVE_READLINE_H */

/* Define to 1 if you have the <readline/history.h> header file. */
/* #undef HAVE_READLINE_HISTORY_H */

/* Define to 1 if you have the <readline/readline.h> header file. */
/* #undef HAVE_READLINE_READLINE_H */

/* Define to 1 if you have the `readlink' function. */
#define HAVE_READLINK 1

/* Define if <signal.h> defines the SA_RESTART constant. */
#define HAVE_SA_RESTART 1

/* Define to 1 if you have the `setegid' function. */
#define HAVE_SETEGID 1

/* Define to 1 if you have the `seteuid' function. */
#define HAVE_SETEUID 1

/* Define to 1 if you have the `setlinebuf' function. */
#define HAVE_SETLINEBUF 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the `setvbuf' function. */
#define HAVE_SETVBUF 1

/* Define if you have the sigaction function.  */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigsetmask' function. */
#define HAVE_SIGSETMASK 1

/* Define to 1 if 'sig_atomic_t' is a signed integer type. */
#define HAVE_SIGNED_SIG_ATOMIC_T 1

/* Define if you have the sigsetjmp function.  */
#define HAVE_SIGSETJMP

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* newer systems define this type here */
#define HAVE_SOCKADDR_STORAGE 1

/* we have sockets on this system */
#define HAVE_SOCKETS 1

/* have sock opts */
#define HAVE_SOCK_OPTS 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strcoll' function and it is properly defined.
   */
#define HAVE_STRCOLL 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if cpp supports the ANSI # stringizing operator. */
#define HAVE_STRINGIZE 1

/* Define if you have the strstr function.  */
#define HAVE_STRSTR

/* Define to 1 if you have the `strtod' function. */
#define HAVE_STRTOD 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

#define HAVE_SYS_ERRLIST 1

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/resource.h> header file.  */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the `system' function. */
#define HAVE_SYSTEM 1

/* Define if you have the tcsetpgrp function.  */
#define HAVE_TCSETPGRP 1

/* Define if you have a sane <termios.h> header file */
#define HAVE_TERMIOS_H 1

/* Define if you have the <time.h> header file.  */
#define HAVE_TIME_H 1

/* Define to 1 if you have the `tmpfile' function. */
#define HAVE_TMPFILE 1

/* Define if you have the tmpnam function.  */
#define HAVE_TMPNAM 1

/* Define to 1 if you don't have `tm_zone' but do have the external array
   `tzname'. */
#define HAVE_TZNAME 1

/* Define to 1 if you have the `tzset' function. */
#define HAVE_TZSET 1

/* Define if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `unsigned long long'. */
#define HAVE_UNSIGNED_LONG_LONG 1

/* Define to 1 if the system has the type `unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if the compiler supports simple visibility declarations. */
#define HAVE_VISIBILITY 0

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Define if you have the waitpid function.  */
#define HAVE_WAITPID 1

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define if you have the 'wchar_t' type. */
#define HAVE_WCHAR_T 1

/* Define to 1 if you have the <wctype.h> header file. */
#define HAVE_WCTYPE_H 1

/* Define to 1 if you have the `wcrtomb' function. */
#define HAVE_WCRTOMB 1

/* Define if you have the 'wint_t' type. */
#define HAVE_WINT_T 1

/* Define to 1 if `fork' works. */
#define HAVE_WORKING_FORK 1

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Define to the type of elements in the array set by `getgroups'. Usually
   this is either `int' or `gid_t'. */
#define GETGROUPS_T gid_t

/* Define to 1 if the `getpgrp' function requires zero arguments. */
#define GETPGRP_VOID 1

/* Define if you don't have setpgrp(), setpgid() or getpgrp() routines */
#define NO_PGRP 1

/* Define if you have a POSIX.1 compatiable <sys/wait.h> */
#define POSIX_SYS_WAIT

/* Define to 1 if the C compiler supports function prototypes. */
#define PROTOTYPES 1

/* Define like PROTOTYPES; this can be used by system headers. */
#define __PROTOTYPES 1

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define as the return value of signal handlers (0 or ).  */
#define RETSIGVAL

/* Define to the type of struct rlimit fields if the rlim_t type is missing */
#define rlim_t long

/* Define if struct stat contains a nanoseconds field */
#define ST_MTIM_NSEC tv_nsec

/* Define if sys_errlist[] and sys_nerr are defined in <errno.h> */
#define SYS_ERRLIST_DECLARED

/* Define if time() is declared in <time.h> */
#define TIME_DECLARED

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* some systems define this type here */
#define TIME_T_IN_SYS_TYPES_H 1

/* Define as `fork' if `vfork' does not work. */
#define vfork fork


/* VARIOUS SYSTEM STUFF */

/* Define to nonzero if you want access control list support. */
#define USE_ACL 0

/* Define to the value of ${prefix}, as a string. */
#define INSTALLPREFIX "/"

/* Default PATH (see comments in pdksh/configure.in for more details) */
#define DEFAULT_PATH "/bin:."

/* Define to the system name. */
#define SYSTEM_NAME "plan9"

#define MAKE_HOST "$M-lucent-Plan9"

/* Define to 1 if filesystem supports mixed-case filenames. */
#define MIXEDCASE_FILENAMES 1

/* Define if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* The number of bytes in a int.  */
#define SIZEOF_INT sizeof(int)

/* The number of bytes in a long.  */
#define SIZEOF_LONG sizeof(long)

/* Define to the number of bits in type 'ptrdiff_t'. */
#define BITSIZEOF_PTRDIFF_T 32

/* Define to the number of bits in type 'sig_atomic_t'. */
#define BITSIZEOF_SIG_ATOMIC_T 32

/* Define to the number of bits in type 'size_t'. */
#define BITSIZEOF_SIZE_T 32

/* Define to the number of bits in type 'wchar_t'. */
#define BITSIZEOF_WCHAR_T 32

/* Define to the number of bits in type 'wint_t'. */
//#define BITSIZEOF_WINT_T 0

/* Define on systems for which file names may have a so-called `drive letter'
   prefix, define this to compute the length of that prefix, including the
   colon. */
#define FILE_SYSTEM_ACCEPTS_DRIVE_LETTER_PREFIX 0

/* Define if the backslash character may also serve as a file name component
   separator. */
#define FILE_SYSTEM_BACKSLASH_IS_FILE_NAME_SEPARATOR 0

/* Define if a drive letter prefix denotes a relative path if it is not
   followed by a file name component separator. */
#define FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE 0




/* gnulib, compiler and C compatibility stuff */



/* Define if your compiler conforms to the ANSI C standard. */
#define HAVE_ANSI_COMPILER 1
#define GCC_NORETURN /* nothing */
#undef GCC_PRINTF
#define GCC_PRINTFLIKE(fmt,var) /* nothing */
#undef GCC_SCANF
/* Define if C compiler groks __attribute__((...)) (const, noreturn, format) */
#undef HAVE_GCC_FUNC_ATTR
/* Define to nothing if compiler doesn't like the volatile keyword */
# define GCC_FUNC_ATTR(x) /* nothing */
# define GCC_FUNC_ATTR2(x,y) /* nothing */
#define volatile /* nothing */
#define _Noreturn /* nothing */
#define _GL_ATTRIBUTE_ERROR(msg) /* nothing */
#define _GL_ATTRIBUTE_WARNING(msg) /* nothing */
#define _GL_ATTRIBUTE_EXTERNALLY_VISIBLE /* nothing */
#define _GL_ATTRIBUTE_FALLTHROUGH ((void) 0)
#define _GL_ATTRIBUTE_FORMAT(spec) /* nothing */
#define _GL_ATTRIBUTE_LEAF /* nothing */
#define _GL_ATTRIBUTE_MALLOC /* nothing */
#define _GL_ATTRIBUTE_MAY_ALIAS /* nothing */
#define _GL_ATTRIBUTE_NODISCARD /* nothing */
#define _GL_ATTRIBUTE_NOINLINE /* nothing */
#define _GL_ATTRIBUTE_NONNULL(args) /* nothing */
#define _GL_ATTRIBUTE_NONSTRING /* nothing */
#define _GL_ATTRIBUTE_NOTHROW /* nothing */
#define _GL_ATTRIBUTE_PURE /* nothing */
#define _GL_ATTRIBUTE_PACKED /* nothing */
#define _GL_ATTRIBUTE_RETURNS_NONNULL /* nothing */
#define _GL_ATTRIBUTE_SENTINEL(pos) /* nothing */
#define _GL_ATTRIBUTE_UNUSED /* nothing */
#define _GL_UNUSED_LABEL /* nothing */
#define restrict /* nothing */
#define _Restrict /* nothing */
#define __restrict__ /* nothing */
#define _UC_RESTRICT /* nothing */
#define DLL_VARIABLE /* nothing */
