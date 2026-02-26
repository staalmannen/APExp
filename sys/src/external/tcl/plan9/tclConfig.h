#ifndef _TCLCONFIG
#define _TCLCONFIG

#define	HAVE_SOCK_OPTS	1
#define	_POSIX_SOURCE	1
#define	_BSD_EXTENSION	1
#define	_SUSV2_SOURCE	1
#define	_REENTRANT_SOURCE	1
#define	STDC_HEADERS	1

#define	CFG_INSTALL_BINDIR		"/bin"
#define	CFG_INSTALL_DOCDIR	"/sys/man"
#define	CFG_INSTALL_INCDIR		"/sys/src/cmd/tcl/generic"
#define	CFG_INSTALL_LIBDIR		"/sys/lib/tcl"
#define	CFG_INSTALL_SCRDIR		"/sys/src/cmd/tcl"

#define	CFG_RUNTIME_BINDIR		CFG_INSTALL_BINDIR
#define	CFG_RUNTIME_DOCDIR	CFG_INSTALL_DOCDIR
#define	CFG_RUNTIME_INCDIR		CFG_INSTALL_INCDIR
#define	CFG_RUNTIME_LIBDIR		CFG_INSTALL_LIBDIR
#define	CFG_RUNTIME_SCRDIR	CFG_INSTALL_SCRDIR

#define	HAVE_GETCWD	1
#define	HAVE_GMTIME_R	1
#define	HAVE_INTPTR_T	1
#define	HAVE_INTTYPES_H	1
#define	HAVE_LIMITS_H	1
#define	HAVE_LOCALTIME_R	1
#define	HAVE_MKTIME	1
#define	HAVE_OPENDIR	1
#define	HAVE_PUTENV_THAT_COPIES	1
#define	HAVE_SIGNED_CHAR	1
#define	HAVE_STDLIB_H	1
#define	HAVE_STRING_H	1
#define	HAVE_STRTOL	1
#define	HAVE_SYS_IOCTL_H	1
#define	HAVE_SYS_PARAM_H	1
#define	HAVE_SYS_SELECT_H	1
#define	HAVE_SYS_STAT_H	1
#define	HAVE_SYS_TIME_H	1
#define	HAVE_SYS_TYPES_H	1
#define	HAVE_UINTPTR_T	1
#define	HAVE_UNISTD_H	1
#define	HAVE_WAITPID	1
#define	NO_DLFCN_H	1
#define	NO_FSTATFS	1
#define	NO_REALPATH	1
#define	NO_UNION_WAIT	1
#define	NO_VALUES_H	1

#define	TCL_CFGVAL_ENCODING	"utf-8"
#define	TCL_CFG_DEBUG	1
#define	TCL_CFG_OPTIMIZED	1
#define	TCL_DEFAULT_ENCODING	"utf-8"
#define	TCL_LIBRARY	"/sys/lib/tcl"
#define	TCL_NO_STACK_CHECK	1
#define	TCL_PACKAGE_PATH	"/sys/lib/tcl"
#define	TCL_SHLIB_EXT	""
#define	TCL_TOMMATH	1
#define	TCL_WIDE_INT_TYPE	long long
#define	TIME_WITH_SYS_TIME	1

/* math helper */
#include <math.h>
extern	double	hypot(double, double);
#ifndef isnan
#define	isnan	isNaN
#endif

/* errno helper */
#include <errno.h>

extern	int	mkstemp(char*);
#define	ECONNRESET	(EINPROGRESS+1)
#undef	EPROTOTYPE

#define	socklen_t	int
#define	P_tmpdir		"/tmp"

#endif


