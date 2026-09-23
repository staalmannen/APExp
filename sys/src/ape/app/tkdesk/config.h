/*
 * config.h for TkDesk under APExp -- hand-answered, the way perl's and
 * Tcl's are, because APExp does not run configure.
 *
 * Every value below is a claim about THIS platform and each one is
 * answerable from the tree rather than guessed:
 *   - the headers are the ones sys/include/ape actually ships;
 *   - the functions are the ones libap actually defines;
 *   - the three typedefs are left ALONE (not defined) because APE has
 *     real ones -- defining them here would shadow the real typedef
 *     and is how a config.h breaks a platform that was fine.
 *
 * PACKAGE_VERSION IS DELIBERATELY ABSENT. tclConfig.h defines it as an
 * unquoted 9.0.3 and TkDesk's C would redefine it; itcl hit exactly
 * this and the fix there was to use the package's own macro. Nothing
 * in TkDesk's C needs it, so it is simply not set.
 */
#ifndef TKDESK_CONFIG_H
#define TKDESK_CONFIG_H

/* headers APE ships */
#define HAVE_DIRENT_H 1
#define HAVE_ERRNO_H 1
#define HAVE_FCNTL_H 1
#define HAVE_FLOAT_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_UNISTD_H 1
#define STDC_HEADERS 1

/*
 * NOT shipped, and each absence is a real one rather than caution:
 * malloc.h (stdlib.h has it), memory.h (string.h has it), ndir.h,
 * sys/dir.h, sys/ndir.h (all pre-POSIX dirent spellings),
 * sys/mount.h, sys/vfs.h, statvfs.h, sys/statvfs.h (no statfs family
 * on Plan 9), waitflags.h (glibc's).
 */

/* functions libap defines */
#define HAVE_GETHOSTNAME 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_SOCKET 1
#define HAVE_STRCASECMP 1
#define HAVE_STRDUP 1

/*
 * statfs/statvfs are NOT defined: Plan 9 has no filesystem-statistics
 * call of either shape. TkDesk uses them to show free space, so the
 * code has to have a path that copes -- and if it does not, that is a
 * finding rather than something to paper over with a fake.
 */

/*
 * NO_UNION_WAIT: APE's wait() takes an int*, not the BSD union.
 * TIME_WITH_SYS_TIME: both headers may be included together.
 * RETSIGTYPE: POSIX signal handlers return void.
 * TM_IN_SYS_TIME is NOT set -- struct tm is declared in <time.h>.
 */
#define NO_UNION_WAIT 1
#define TIME_WITH_SYS_TIME 1
#define RETSIGTYPE void

/*
 * mode_t, pid_t and size_t are deliberately NOT defined here. autoconf
 * emits those to SUBSTITUTE for a missing typedef; APE has all three,
 * and defining them would shadow the real ones.
 */

#endif /* TKDESK_CONFIG_H */
