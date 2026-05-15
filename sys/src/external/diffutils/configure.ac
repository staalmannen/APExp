# Configure template for GNU Diffutils.

# Copyright (C) 1994-1995, 1998, 2001-2002, 2004, 2006, 2009-2013, 2015-2025
# Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.64])

AC_INIT([GNU diffutils],
        m4_esyscmd([build-aux/git-version-gen .tarball-version]),
        [bug-diffutils@gnu.org],
	[diffutils],
	[https://www.gnu.org/software/diffutils/])

AC_CONFIG_SRCDIR([src/diff.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11 dist-xz subdir-objects color-tests parallel-tests])
AM_SILENT_RULES([yes]) # make --enable-silent-rules the default.

AC_CONFIG_HEADERS([lib/config.h:lib/config.hin])

AC_PROG_AWK
AC_PROG_CC
AM_MISSING_PROG([HELP2MAN], [help2man])
AC_PROG_RANLIB
gl_EARLY
gl_USE_SYSTEM_EXTENSIONS
gl_INIT

# Ensure VLAs are not used.
# Note -Wvla is implicitly added by gl_MANYWARN_ALL_GCC
AC_DEFINE([GNULIB_NO_VLA], [1], [Define to 1 to disable use of VLAs])

# diffutils is single-threaded; optimize for this.
AC_DEFINE([GNULIB_EXCLUDE_SINGLE_THREAD], [1],
  ['exclude' code is called only from 1 thread.])
AC_DEFINE([GNULIB_MBRTOWC_SINGLE_THREAD], [1],
  ['mbrtowc', 'mbrtoc32', 'regex' code is called only from 1 thread.])
AC_DEFINE([GNULIB_REGEX_SINGLE_THREAD], [1],
  ['regex' code is called only from 1 thread.])
AC_DEFINE([GNULIB_WCHAR_SINGLE_LOCALE], [1],
  [Locale-sensitive functions are called only after locale is set.])

AC_DEFINE([GNULIB_MBRTOC32_REGULAR], [1],
  [Do not worry about rare encodings like CP864, EBCDIC, Johab, and Shift JIS
   that glibc does not support.])

AC_C_INLINE

AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_HEADER_DIRENT
AC_HEADER_SYS_WAIT
AC_TYPE_PID_T

AC_CHECK_FUNCS_ONCE([sigaction sigprocmask])
if test $ac_cv_func_sigprocmask = no; then
  AC_CHECK_FUNCS([sigblock])
fi
AC_FUNC_FORK

dnl O_PATH exists since Linux 2.6.39, but is supported with fstat() only since
dnl Linux 3.6. Use a configure test rather than testing `uname -sr`.
AC_CACHE_CHECK([whether O_PATH supports fstat],
  [du_cv_O_PATH_fstat],
  [AC_RUN_IFELSE(
     [AC_LANG_PROGRAM([[
        #include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
        ]], [[
        struct stat statbuf;
        int fd = openat (AT_FDCWD, "conftest.c", O_RDONLY|O_PATH);
        return !(fd >= 0 && fstat (fd, &statbuf) == 0);
        ]])
     ],
     [du_cv_O_PATH_fstat=yes],
     [du_cv_O_PATH_fstat=no],
     [du_cv_O_PATH_fstat="guessing no"])
  ])
case "$du_cv_O_PATH_fstat" in
  yes)
    AC_DEFINE([O_PATH_SUPPORTS_FSTAT], [1],
      [Define to 1 if <fcntl.h> defines O_PATH and file descriptors
       created with this flag are supported by fstat().])
    ;;
esac

# gl_GCC_VERSION_IFELSE([major], [minor], [run-if-found], [run-if-not-found])
# ------------------------------------------------
# If $CPP is gcc-MAJOR.MINOR or newer, then run RUN-IF-FOUND.
# Otherwise, run RUN-IF-NOT-FOUND.
AC_DEFUN([gl_GCC_VERSION_IFELSE],
  [AC_PREPROC_IFELSE(
    [AC_LANG_PROGRAM(
      [[
#if ($1) < __GNUC__ || (($1) == __GNUC__ && ($2) <= __GNUC_MINOR__)
/* ok */
#else
# error "your version of gcc is older than $1.$2"
#endif
      ]]),
    ], [$3], [$4])
  ]
)

AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([[--enable-gcc-warnings[=TYPE]]],
    [control generation of GCC warnings.  The TYPE 'no' disables
     warnings (default for non-developer builds); 'yes' generates
     cheap warnings if available (default for developer builds);
     'expensive' in addition generates expensive-to-compute warnings
     if available.])],
  [case $enableval in
     no|yes|expensive) ;;
     *)      AC_MSG_ERROR([bad value $enableval for gcc-warnings option]) ;;
   esac
   gl_gcc_warnings=$enableval],
  [
   # GCC provides fine-grained control over diagnostics which
   # is used in gnulib for example to suppress warnings from
   # certain sections of code.  So if this is available and
   # we're running from a git repo, then auto enable the warnings.
   gl_gcc_warnings=no
   gl_GCC_VERSION_IFELSE([4], [6],
                         [test -d "$srcdir"/.git \
                          && ! test -f "$srcdir"/.tarball-version \
                          && gl_gcc_warnings=yes])]
)

if test $gl_gcc_warnings != no; then
  gl_WARN_ADD([-Werror], [WERROR_CFLAGS])
  AC_SUBST([WERROR_CFLAGS])

  ew=
  AS_IF([test $gl_gcc_warnings != expensive],
    [# -fanalyzer and related options slow GCC considerably.
     ew="$ew -fanalyzer -Wno-analyzer-malloc-leak"])

  # This, $nw, is the list of warnings we disable.
  nw=$ew
  nw="$nw -Winline"                 # not a correctness warning
  nw="$nw -Wstack-protector"        # not a correctness warning

  gl_MANYWARN_ALL_GCC([ws])
  gl_MANYWARN_COMPLEMENT([ws], [$ws], [$nw])
  for w in $ws; do
    gl_WARN_ADD([$w])
  done
  gl_WARN_ADD([-Wno-sign-compare])     # Too many false positives
  gl_WARN_ADD([-Wno-format-nonliteral])

  AC_SUBST([WARN_CFLAGS])

  AH_VERBATIM([FORTIFY_SOURCE],
  [/* Enable compile-time and run-time bounds-checking, and some warnings,
      without upsetting glibc 2.15+. */
   #if !defined _FORTIFY_SOURCE && defined __OPTIMIZE__ && __OPTIMIZE__ \
       && !defined __MINGW32__
   # define _FORTIFY_SOURCE 2
   #endif
  ])
  AC_DEFINE([GNULIB_PORTCHECK], [1], [enable some gnulib portability checks])
fi

AC_DEFINE([DEFAULT_EDITOR_PROGRAM], ["ed"],
  [Name of editor program, unless overridden.])

AC_PATH_PROG([PR_PROGRAM], [pr], [""])
AC_DEFINE_UNQUOTED([PR_PROGRAM], ["$PR_PROGRAM"], [Name of "pr" program.])

# When .tarball-version exists, we're building from a tarball
# and must not make man/*.1 files depend on the generated src/version.c,
# because that would induce a requirement to run the help2man perl script.
# We are not yet prepared to make perl a build-from-tarball requirement.
# Hence, here we detect .tarball-version existence.  When not present,
# we define a variable to be used in man/Makefile.am to induce the
# proper dependency (so that man/*.1 will be rebuilt upon any version change),
# but not when built from a tarball.
AC_SUBST([SRC_VERSION_C])
test -f $srcdir/.tarball-version \
  && SRC_VERSION_C= \
  || SRC_VERSION_C=../src/version.c

AM_GNU_GETTEXT([external], [need-ngettext])
AM_GNU_GETTEXT_VERSION([0.19.2])
XGETTEXT="AWK='$AWK' \$(SHELL) \$(top_srcdir)/exgettext $XGETTEXT"

AC_CONFIG_FILES([
  Makefile doc/Makefile
  lib/Makefile
  src/Makefile
  tests/Makefile
  gnulib-tests/Makefile
  man/Makefile
  po/Makefile.in
])
AC_OUTPUT
