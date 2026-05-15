# Copyright 1993-2025 Free Software Foundation, Inc.

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

AC_PREREQ([2.65])

AC_INIT([GNU patch],
	m4_esyscmd([build-aux/git-version-gen .tarball-version]),
	[bug-patch@gnu.org])

AC_CONFIG_SRCDIR([src/patch.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_ARG_ENABLE([merge],
  [AS_HELP_STRING([--disable-merge],
    [disable support for merging])])
AM_CONDITIONAL([ENABLE_MERGE], [test "$enableval" != no])
AM_CONDITIONAL([ALPHA_VERSION],
  [[echo "$PACKAGE_VERSION" | grep -- "-[0-9a-f][0-9a-f]*\\(-dirty\\)\\?$" >/dev/null]])

AM_INIT_AUTOMAKE([1.11.2 -Wall gnu dist-bzip2 dist-xz color-tests parallel-tests subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_HEADERS([config.h:config.hin])

AC_PROG_CC
gl_EARLY
gl_INIT
AM_PROG_AR

AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([--enable-gcc-warnings@<:@=TYPE@:>@],
    [control generation of GCC warnings.  The TYPE 'no' disables
     warnings (default for non-developer builds); 'yes' generates
     cheap warnings if available;
     'expensive' in addition generates expensive-to-compute warnings
     if available.])],
  [case $enableval in
     no|yes|expensive) ;;
     *)      AC_MSG_ERROR([bad value $enableval for gcc-warnings option]) ;;
   esac
   gl_gcc_warnings=$enableval],
  [gl_gcc_warnings=no]
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
  nw="$nw -Winline"                  # It's OK for a compiler to not inline.

  # Using -Wstrict-overflow is a pain, but the alternative is worse.
  # For an example, see the code that provoked this report:
  # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=33498
  # Code like that still infloops with gcc-4.6.0 and -O2.  Scary indeed.

  gl_MANYWARN_ALL_GCC([ws])
  gl_MANYWARN_COMPLEMENT([ws], [$ws], [$nw])
  for w in $ws; do
    gl_WARN_ADD([$w])
  done
  gl_WARN_ADD([-Wno-sign-compare])     # Too many warnings for now

  gl_WARN_ADD([-fdiagnostics-show-option])

  AC_SUBST([WARN_CFLAGS])

  AC_DEFINE([lint], [1], [Define to 1 if the compiler is checking for lint.])
  AH_VERBATIM([FORTIFY_SOURCE],
  [/* Enable compile-time and run-time bounds-checking, and some warnings,
      without upsetting glibc 2.15+. */
   #if !defined _FORTIFY_SOURCE && defined __OPTIMIZE__ && __OPTIMIZE__
   # define _FORTIFY_SOURCE 2
   #endif
  ])
  AC_DEFINE([GNULIB_PORTCHECK], [1], [enable some gnulib portability checks])

  # We also use a smaller set of warning options for lib/.
  # Remove the following and save the result in GNULIB_WARN_CFLAGS.
  nw=$ew
  gl_MANYWARN_COMPLEMENT([GNULIB_WARN_CFLAGS], [$WARN_CFLAGS], [$nw])
  AC_SUBST([GNULIB_WARN_CFLAGS])
fi

# Ensure VLAs are not used.
# Note -Wvla is implicitly added by gl_MANYWARN_ALL_GCC
AC_DEFINE([GNULIB_NO_VLA], [1], [Define to 1 to disable use of VLAs])

AC_TYPE_MODE_T
AC_TYPE_OFF_T

gl_FUNC_XATTR

AC_CHECK_FUNCS_ONCE([geteuid getuid sigaction sigfillset])
AC_FUNC_SETMODE_DOS

AC_PATH_PROG([ED], [ed], [ed])
AC_DEFINE_UNQUOTED([EDITOR_PROGRAM], ["$ED"], [Name of editor program.])

AC_CONFIG_FILES([
  Makefile
  lib/Makefile
  src/Makefile
  tests/Makefile
])
AC_OUTPUT
