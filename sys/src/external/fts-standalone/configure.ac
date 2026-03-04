AC_PREREQ([2.68])
AC_INIT([fts], [0.2], [http://bug.gentoo.org])
AC_CONFIG_SRCDIR([fts.c])

AM_INIT_AUTOMAKE([foreign 1.11])
AM_SILENT_RULES([yes])
LT_PREREQ(2.2)
LT_INIT

AC_PROG_CC
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h sys/param.h unistd.h])
AC_TYPE_SIZE_T
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([fchdir memmove memset strrchr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
