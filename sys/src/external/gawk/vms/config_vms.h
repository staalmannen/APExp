#ifndef __CONFIG_VMS_H__
#define __CONFIG_VMS_H__

/* Provide some of our own header files even if the OS version supplies it.
   At last check of VMS 9.2, some of the OS header files were still not
   providing everything that gnu programs expect.
   This must be included first to get definitions provided in the proper
   order to work.
*/
#ifndef HAVE_INTTYPES_H
# define HAVE_INTYPES_H 1
#endif
#include <vms/stdint.h>  /* Includes vms/inttypes.h */
#include <vms/stdio.h>

#ifndef HAVE_STDINT_H
#define HAVE_STDINT_H 1
#endif

/* Printf hacks.  Overiding printf family of functions disables the
   internal defualt compiler optimzaitons to speed them up.
   At some time we may want to do this on a module by module basis
*/
#define NEED_WRAPPED_PRINTF 1 /* for now always wrap printf */

#ifdef NEED_WRAPPED_PRINTF

#ifdef printf
#undef printf
#endif
#define printf vms_printf
int vms_printf(const char * format, ...);

#ifdef sprintf
#undef sprintf
#endif
#define sprintf vms_sprintf
int vms_sprintf(char *str, const char *format, ...);

#ifdef fprintf
#undef fprintf
#endif
#define fprintf vms_fprintf
int vms_fprintf(FILE* stream, const char *format, ...);

#endif /* NEED_WRAPPED_PRINTF */

/* This will eventually go into vms/ctype.h */

#if (__CRTL_VER < 80500000)

#define define isblank(c)  (c == ' ' || c == '\t')

static int isblank(c) { return (c == ' ' || c == '\t'); }

#endif /* (__CRTL_VER < 80500000) */



/* This is previous format supplying omissions from the header files
 * or the compiler.   Most of this will eventually be moved to wrappers
 * for the OS header files that should have been providing the values.
 * nothing new should be added here.
 */
#if __CRTL_VER >= 70000000
#define VMS_V7
#else
#define HAVE_TZNAME 1 /* (faked in vms/vms_misc.c) */
#define HAVE_TZSET 1 /* (faked in vms/vms_misc.c) */
#endif
#if __CRTL_VER >= 70200000
#define DYNAMIC 1
#endif

#define PRINTF_HAS_F_FORMAT 1

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (3 <= __GNUC__ || (__GNUC__ == 2 && 8 <= __GNUC_MINOR__) \
      || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif


#if __DECC_VER >= 60400000 && !defined(DEBUG)
/* disable "new feature in C99" diagnostics (for regex code);
   NEWC99 ought to suffice but doesn't (at least in V6.4) */
#pragma message disable (NEWC99,DESIGNATORUSE)
#pragma message disable (LONGDOUBLENYI)
#pragma message disable (QUESTCOMPARE)
#endif
#if __VMS_VER <= 80200000
#ifdef HAVE_MKSTEMP
#undef HAVE_MKSTEMP
#endif
#endif

/* Standard compliant should only be using __VMS not VMS
   This
#ifndef VMS
#define VMS 1
#endif

/* Need to hide some stuff */
#define getopt hide_getopt
#define optopt hide_optopt
#define optind hide_optind
#define optarg hide_optarg
#define opterr hide_opterr
#define getpgrp hide_getpgrp
#define unsetenv hide_unsetenv
#define read hide_read
#define delete hide_delete
#define getcwd hide_getcwd
#define getgid hide_getgid
#define getegid hide_getegid
#define setgid hide_setgid
#define exit hide_exit
#define _exit hide__exit
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stsdef.h>
#include <string.h>
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 2
#define _XOPEN_SOURCE 1
#define _XOPEN_SOURCE_EXTENDED 1
#include <stat.h>
#undef _POSIX_C_SOURCE
#undef _XOPEN_SOURCE
#undef _XOPEN_SOURCE_EXTENDED
#endif
#define HAVE_STRPTIME 1
#undef getopt
#undef optopt
#undef optind
#undef optarg
#undef opterr
#undef getpgrp
#undef getcwd
#undef unsetenv
#undef read
#undef delete
#undef getgid
#undef getegid
#undef setgid
#undef exit
#undef _exit
#ifdef HAVE_STRNCASECMP
#undef HAVE_STRNCASECMP
#endif
#define IN_CONFIG_H
#include "redirect.h"
#undef IN_CONFIG_H
#define getpgrp gawk_vms_getpgrp
#ifdef HAVE_SETENV
#undef HAVE_SETENV
#endif
#ifdef HAVE_UNSETENV
#undef HAVE_UNSETENV
#endif
#ifdef HAVE_STRFTIME
#undef HAVE_STRFTIME
#define USE_INCLUDED_STRFTIME
#endif /* HAVE_STRFTIME */

/* #include <bitypes.h>
#ifndef INT32_MAX
#define INT32_MAX __INT32_MAX
#endif
#ifndef INT32_MIN
#define INT32_MIN __INT32_MIN
#endif
*/

/*
 * DEFPATH
 *	VMS: "/AWK_LIBRARY" => "AWK_LIBRARY:"
 * The default search path for the -f option of gawk.  It is
 * used if the AWKPATH environment variable is undefined.
 *
 * Note: OK even if no AWK_LIBRARY logical name has been defined.
 */

#define DEFPATH	".,/AWK_LIBRARY"
#define DEFLIBPATH ".,/AWK_LIBRARY"
#define ENVSEP	','

/*
 * Extended source file access.
 */
#define DEFAULT_FILETYPE ".awk"

/*
 * fork/Pipe handling.
 */
#define PIPES_SIMULATED	1

/* Extension for shared libraries */
#define SHLIBEXT	"exe"

#define NO_ALLOCA
#define STACK_DIRECTION (-1)

void decc$exit(int status);
#define _exit(foo) vms_exit(foo)
#define exit(foo) vms_exit(foo)

/* Use POSIX exit codes here */
#ifdef EXIT_FAILURE
#undef EXIT_FAILURE
#endif
#define EXIT_FAILURE (1)

#define EXIT_FATAL (2)

#ifndef C_FACILITY_NO
#define C_FACILITY_NO 0x350000
#endif

/* Build a Posix Exit with VMS severity */
static void vms_exit(int status) {
    int vms_status;
    /* Fake the __posix_exit with severity added */
    /* Undocumented correct way to do this. */
    vms_status = 0;
    if (status != 0) {
        vms_status = C_FACILITY_NO | 0xA000 | STS$M_INHIB_MSG;
        vms_status |= (status << 3);
    }
    if (status == EXIT_FAILURE) {
        vms_status |= STS$K_ERROR;
    } else if (status == EXIT_FATAL) {
        vms_status |= STS$K_SEVERE;
    } else {
        vms_status |= STS$K_SUCCESS;
    }
    decc$exit(vms_status);
}

#define TIME_T_UNSIGNED 1
#include "custom.h"
/* TEMP Fixup for V9.2-2 termios header not compatible */
#ifdef HAVE_TERMIOS_H
#undef HAVE_TERMIOS_H
#endif


#endif /* __CONFIG_VMS_H__ */
