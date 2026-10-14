# generated automatically by aclocal 1.11.1 -*- Autoconf -*-

# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
# 2005, 2006, 2007, 2008, 2009  Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

m4_ifndef([AC_AUTOCONF_VERSION],
  [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
m4_if(m4_defn([AC_AUTOCONF_VERSION]), [2.65],,
[m4_warning([this file was generated for autoconf 2.65.
You have another version of autoconf.  It may work, but is not guaranteed to.
If you have problems, you may need to regenerate the build system entirely.
To do so, use the procedure documented by the package, typically `autoreconf'.])])

# Copyright (C) 2002, 2003, 2005, 2006, 2007, 2008  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# AM_AUTOMAKE_VERSION(VERSION)
# ----------------------------
# Automake X.Y traces this macro to ensure aclocal.m4 has been
# generated from the m4 files accompanying Automake X.Y.
# (This private macro should not be called outside this file.)
AC_DEFUN([AM_AUTOMAKE_VERSION],
[am__api_version='1.11'
dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
dnl require some minimum version.  Point them to the right macro.
m4_if([$1], [1.11.1], [],
      [AC_FATAL([Do not call $0, use AM_INIT_AUTOMAKE([$1]).])])dnl
])

# _AM_AUTOCONF_VERSION(VERSION)
# -----------------------------
# aclocal traces this macro to find the Autoconf version.
# This is a private macro too.  Using m4_define simplifies
# the logic in aclocal, which can simply ignore this definition.
m4_define([_AM_AUTOCONF_VERSION], [])

# AM_SET_CURRENT_AUTOMAKE_VERSION
# -------------------------------
# Call AM_AUTOMAKE_VERSION and AM_AUTOMAKE_VERSION so they can be traced.
# This function is AC_REQUIREd by AM_INIT_AUTOMAKE.
AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
[AM_AUTOMAKE_VERSION([1.11.1])dnl
m4_ifndef([AC_AUTOCONF_VERSION],
  [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
_AM_AUTOCONF_VERSION(m4_defn([AC_AUTOCONF_VERSION]))])

# AM_AUX_DIR_EXPAND                                         -*- Autoconf -*-

# Copyright (C) 2001, 2003, 2005  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# For projects using AC_CONFIG_AUX_DIR([foo]), Autoconf sets
# $ac_aux_dir to `$srcdir/foo'.  In other projects, it is set to
# `$srcdir', `$srcdir/..', or `$srcdir/../..'.
#
# Of course, Automake must honor this variable whenever it calls a
# tool from the auxiliary directory.  The problem is that $srcdir (and
# therefore $ac_aux_dir as well) can be either absolute or relative,
# depending on how configure is run.  This is pretty annoying, since
# it makes $ac_aux_dir quite unusable in subdirectories: in the top
# source directory, any form will work fine, but in subdirectories a
# relative path needs to be adjusted first.
#
# $ac_aux_dir/missing
#    fails when called from a subdirectory if $ac_aux_dir is relative
# $top_srcdir/$ac_aux_dir/missing
#    fails if $ac_aux_dir is absolute,
#    fails when called from a subdirectory in a VPATH build with
#          a relative $ac_aux_dir
#
# The reason of the latter failure is that $top_srcdir and $ac_aux_dir
# are both prefixed by $srcdir.  In an in-source build this is usually
# harmless because $srcdir is `.', but things will broke when you
# start a VPATH build or use an absolute $srcdir.
#
# So we could use something similar to $top_srcdir/$ac_aux_dir/missing,
# iff we strip the leading $srcdir from $ac_aux_dir.  That would be:
#   am_aux_dir='\$(top_srcdir)/'`expr "$ac_aux_dir" : "$srcdir//*\(.*\)"`
# and then we would define $MISSING as
#   MISSING="\${SHELL} $am_aux_dir/missing"
# This will work as long as MISSING is not called from configure, because
# unfortunately $(top_srcdir) has no meaning in configure.
# However there are other variables, like CC, which are often used in
# configure, and could therefore not use this "fixed" $ac_aux_dir.
#
# Another solution, used here, is to always expand $ac_aux_dir to an
# absolute PATH.  The drawback is that using absolute paths prevent a
# configured tree to be moved without reconfiguration.

AC_DEFUN([AM_AUX_DIR_EXPAND],
[dnl Rely on autoconf to set up CDPATH properly.
AC_PREREQ([2.50])dnl
# expand $ac_aux_dir to an absolute path
am_aux_dir=`cd $ac_aux_dir && pwd`
])

# AM_CONDITIONAL                                            -*- Autoconf -*-

# Copyright (C) 1997, 2000, 2001, 2003, 2004, 2005, 2006, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 9

# AM_CONDITIONAL(NAME, SHELL-CONDITION)
# -------------------------------------
# Define a conditional.
AC_DEFUN([AM_CONDITIONAL],
[AC_PREREQ(2.52)dnl
 ifelse([$1], [TRUE],  [AC_FATAL([$0: invalid condition: $1])],
	[$1], [FALSE], [AC_FATAL([$0: invalid condition: $1])])dnl
AC_SUBST([$1_TRUE])dnl
AC_SUBST([$1_FALSE])dnl
_AM_SUBST_NOTMAKE([$1_TRUE])dnl
_AM_SUBST_NOTMAKE([$1_FALSE])dnl
m4_define([_AM_COND_VALUE_$1], [$2])dnl
if $2; then
  $1_TRUE=
  $1_FALSE='#'
else
  $1_TRUE='#'
  $1_FALSE=
fi
AC_CONFIG_COMMANDS_PRE(
[if test -z "${$1_TRUE}" && test -z "${$1_FALSE}"; then
  AC_MSG_ERROR([[conditional "$1" was never defined.
Usually this means the macro was only invoked conditionally.]])
fi])])

# Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2009
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 10

# There are a few dirty hacks below to avoid letting `AC_PROG_CC' be
# written in clear, in which case automake, when reading aclocal.m4,
# will think it sees a *use*, and therefore will trigger all it's
# C support machinery.  Also note that it means that autoscan, seeing
# CC etc. in the Makefile, will ask for an AC_PROG_CC use...


# _AM_DEPENDENCIES(NAME)
# ----------------------
# See how the compiler implements dependency checking.
# NAME is "CC", "CXX", "GCJ", or "OBJC".
# We try a few techniques and use that to set a single cache variable.
#
# We don't AC_REQUIRE the corresponding AC_PROG_CC since the latter was
# modified to invoke _AM_DEPENDENCIES(CC); we would have a circular
# dependency, and given that the user is not expected to run this macro,
# just rely on AC_PROG_CC.
AC_DEFUN([_AM_DEPENDENCIES],
[AC_REQUIRE([AM_SET_DEPDIR])dnl
AC_REQUIRE([AM_OUTPUT_DEPENDENCY_COMMANDS])dnl
AC_REQUIRE([AM_MAKE_INCLUDE])dnl
AC_REQUIRE([AM_DEP_TRACK])dnl

ifelse([$1], CC,   [depcc="$CC"   am_compiler_list=],
       [$1], CXX,  [depcc="$CXX"  am_compiler_list=],
       [$1], OBJC, [depcc="$OBJC" am_compiler_list='gcc3 gcc'],
       [$1], UPC,  [depcc="$UPC"  am_compiler_list=],
       [$1], GCJ,  [depcc="$GCJ"  am_compiler_list='gcc3 gcc'],
                   [depcc="$$1"   am_compiler_list=])

AC_CACHE_CHECK([dependency style of $depcc],
               [am_cv_$1_dependencies_compiler_type],
[if test -z "$AMDEP_TRUE" && test -f "$am_depcomp"; then
  # We make a subdir and do the tests there.  Otherwise we can end up
  # making bogus files that we don't know about and never remove.  For
  # instance it was reported that on HP-UX the gcc test will end up
  # making a dummy file named `D' -- because `-MD' means `put the output
  # in D'.
  mkdir conftest.dir
  # Copy depcomp to subdir because otherwise we won't find it if we're
  # using a relative directory.
  cp "$am_depcomp" conftest.dir
  cd conftest.dir
  # We will build objects and dependencies in a subdirectory because
  # it helps to detect inapplicable dependency modes.  For instance
  # both Tru64's cc and ICC support -MD to output dependencies as a
  # side effect of compilation, but ICC will put the dependencies in
  # the current directory while Tru64 will put them in the object
  # directory.
  mkdir sub

  am_cv_$1_dependencies_compiler_type=none
  if test "$am_compiler_list" = ""; then
     am_compiler_list=`sed -n ['s/^#*\([a-zA-Z0-9]*\))$/\1/p'] < ./depcomp`
  fi
  am__universal=false
  m4_case([$1], [CC],
    [case " $depcc " in #(
     *\ -arch\ *\ -arch\ *) am__universal=true ;;
     esac],
    [CXX],
    [case " $depcc " in #(
     *\ -arch\ *\ -arch\ *) am__universal=true ;;
     esac])

  for depmode in $am_compiler_list; do
    # Setup a source with many dependencies, because some compilers
    # like to wrap large dependency lists on column 80 (with \), and
    # we should not choose a depcomp mode which is confused by this.
    #
    # We need to recreate these files for each test, as the compiler may
    # overwrite some of them when testing with obscure command lines.
    # This happens at least with the AIX C compiler.
    : > sub/conftest.c
    for i in 1 2 3 4 5 6; do
      echo '#include "conftst'$i'.h"' >> sub/conftest.c
      # Using `: > sub/conftst$i.h' creates only sub/conftst1.h with
      # Solaris 8's {/usr,}/bin/sh.
      touch sub/conftst$i.h
    done
    echo "${am__include} ${am__quote}sub/conftest.Po${am__quote}" > confmf

    # We check with `-c' and `-o' for the sake of the "dashmstdout"
    # mode.  It turns out that the SunPro C++ compiler does not properly
    # handle `-M -o', and we need to detect this.  Also, some Intel
    # versions had trouble with output in subdirs
    am__obj=sub/conftest.${OBJEXT-o}
    am__minus_obj="-o $am__obj"
    case $depmode in
    gcc)
      # This depmode causes a compiler race in universal mode.
      test "$am__universal" = false || continue
      ;;
    nosideeffect)
      # after this tag, mechanisms are not by side-effect, so they'll
      # only be used when explicitly requested
      if test "x$enable_dependency_tracking" = xyes; then
	continue
      else
	break
      fi
      ;;
    msvisualcpp | msvcmsys)
      # This compiler won't grok `-c -o', but also, the minuso test has
      # not run yet.  These depmodes are late enough in the game, and
      # so weak that their functioning should not be impacted.
      am__obj=conftest.${OBJEXT-o}
      am__minus_obj=
      ;;
    none) break ;;
    esac
    if depmode=$depmode \
       source=sub/conftest.c object=$am__obj \
       depfile=sub/conftest.Po tmpdepfile=sub/conftest.TPo \
       $SHELL ./depcomp $depcc -c $am__minus_obj sub/conftest.c \
         >/dev/null 2>conftest.err &&
       grep sub/conftst1.h sub/conftest.Po > /dev/null 2>&1 &&
       grep sub/conftst6.h sub/conftest.Po > /dev/null 2>&1 &&
       grep $am__obj sub/conftest.Po > /dev/null 2>&1 &&
       ${MAKE-make} -s -f confmf > /dev/null 2>&1; then
      # icc doesn't choke on unknown options, it will just issue warnings
      # or remarks (even with -Werror).  So we grep stderr for any message
      # that says an option was ignored or not supported.
      # When given -MP, icc 7.0 and 7.1 complain thusly:
      #   icc: Command line warning: ignoring option '-M'; no argument required
      # The diagnosis changed in icc 8.0:
      #   icc: Command line remark: option '-MP' not supported
      if (grep 'ignoring option' conftest.err ||
          grep 'not supported' conftest.err) >/dev/null 2>&1; then :; else
        am_cv_$1_dependencies_compiler_type=$depmode
        break
      fi
    fi
  done

  cd ..
  rm -rf conftest.dir
else
  am_cv_$1_dependencies_compiler_type=none
fi
])
AC_SUBST([$1DEPMODE], [depmode=$am_cv_$1_dependencies_compiler_type])
AM_CONDITIONAL([am__fastdep$1], [
  test "x$enable_dependency_tracking" != xno \
  && test "$am_cv_$1_dependencies_compiler_type" = gcc3])
])


# AM_SET_DEPDIR
# -------------
# Choose a directory name for dependency files.
# This macro is AC_REQUIREd in _AM_DEPENDENCIES
AC_DEFUN([AM_SET_DEPDIR],
[AC_REQUIRE([AM_SET_LEADING_DOT])dnl
AC_SUBST([DEPDIR], ["${am__leading_dot}deps"])dnl
])


# AM_DEP_TRACK
# ------------
AC_DEFUN([AM_DEP_TRACK],
[AC_ARG_ENABLE(dependency-tracking,
[  --disable-dependency-tracking  speeds up one-time build
  --enable-dependency-tracking   do not reject slow dependency extractors])
if test "x$enable_dependency_tracking" != xno; then
  am_depcomp="$ac_aux_dir/depcomp"
  AMDEPBACKSLASH='\'
fi
AM_CONDITIONAL([AMDEP], [test "x$enable_dependency_tracking" != xno])
AC_SUBST([AMDEPBACKSLASH])dnl
_AM_SUBST_NOTMAKE([AMDEPBACKSLASH])dnl
])

# Generate code to set up dependency tracking.              -*- Autoconf -*-

# Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

#serial 5

# _AM_OUTPUT_DEPENDENCY_COMMANDS
# ------------------------------
AC_DEFUN([_AM_OUTPUT_DEPENDENCY_COMMANDS],
[{
  # Autoconf 2.62 quotes --file arguments for eval, but not when files
  # are listed without --file.  Let's play safe and only enable the eval
  # if we detect the quoting.
  case $CONFIG_FILES in
  *\'*) eval set x "$CONFIG_FILES" ;;
  *)   set x $CONFIG_FILES ;;
  esac
  shift
  for mf
  do
    # Strip MF so we end up with the name of the file.
    mf=`echo "$mf" | sed -e 's/:.*$//'`
    # Check whether this is an Automake generated Makefile or not.
    # We used to match only the files named `Makefile.in', but
    # some people rename them; so instead we look at the file content.
    # Grep'ing the first line is not enough: some people post-process
    # each Makefile.in and add a new line on top of each file to say so.
    # Grep'ing the whole file is not good either: AIX grep has a line
    # limit of 2048, but all sed's we know have understand at least 4000.
    if sed -n 's,^#.*generated by automake.*,X,p' "$mf" | grep X >/dev/null 2>&1; then
      dirpart=`AS_DIRNAME("$mf")`
    else
      continue
    fi
    # Extract the definition of DEPDIR, am__include, and am__quote
    # from the Makefile without running `make'.
    DEPDIR=`sed -n 's/^DEPDIR = //p' < "$mf"`
    test -z "$DEPDIR" && continue
    am__include=`sed -n 's/^am__include = //p' < "$mf"`
    test -z "am__include" && continue
    am__quote=`sed -n 's/^am__quote = //p' < "$mf"`
    # When using ansi2knr, U may be empty or an underscore; expand it
    U=`sed -n 's/^U = //p' < "$mf"`
    # Find all dependency output files, they are included files with
    # $(DEPDIR) in their names.  We invoke sed twice because it is the
    # simplest approach to changing $(DEPDIR) to its actual value in the
    # expansion.
    for file in `sed -n "
      s/^$am__include $am__quote\(.*(DEPDIR).*\)$am__quote"'$/\1/p' <"$mf" | \
	 sed -e 's/\$(DEPDIR)/'"$DEPDIR"'/g' -e 's/\$U/'"$U"'/g'`; do
      # Make sure the directory exists.
      test -f "$dirpart/$file" && continue
      fdir=`AS_DIRNAME(["$file"])`
      AS_MKDIR_P([$dirpart/$fdir])
      # echo "creating $dirpart/$file"
      echo '# dummy' > "$dirpart/$file"
    done
  done
}
])# _AM_OUTPUT_DEPENDENCY_COMMANDS


# AM_OUTPUT_DEPENDENCY_COMMANDS
# -----------------------------
# This macro should only be invoked once -- use via AC_REQUIRE.
#
# This code is only required when automatic dependency tracking
# is enabled.  FIXME.  This creates each `.P' file that we will
# need in order to bootstrap the dependency handling code.
AC_DEFUN([AM_OUTPUT_DEPENDENCY_COMMANDS],
[AC_CONFIG_COMMANDS([depfiles],
     [test x"$AMDEP_TRUE" != x"" || _AM_OUTPUT_DEPENDENCY_COMMANDS],
     [AMDEP_TRUE="$AMDEP_TRUE" ac_aux_dir="$ac_aux_dir"])
])

# Do all the work for Automake.                             -*- Autoconf -*-

# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
# 2005, 2006, 2008, 2009 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 16

# This macro actually does too much.  Some checks are only needed if
# your package does certain things.  But this isn't really a big deal.

# AM_INIT_AUTOMAKE(PACKAGE, VERSION, [NO-DEFINE])
# AM_INIT_AUTOMAKE([OPTIONS])
# -----------------------------------------------
# The call with PACKAGE and VERSION arguments is the old style
# call (pre autoconf-2.50), which is being phased out.  PACKAGE
# and VERSION should now be passed to AC_INIT and removed from
# the call to AM_INIT_AUTOMAKE.
# We support both call styles for the transition.  After
# the next Automake release, Autoconf can make the AC_INIT
# arguments mandatory, and then we can depend on a new Autoconf
# release and drop the old call support.
AC_DEFUN([AM_INIT_AUTOMAKE],
[AC_PREREQ([2.62])dnl
dnl Autoconf wants to disallow AM_ names.  We explicitly allow
dnl the ones we care about.
m4_pattern_allow([^AM_[A-Z]+FLAGS$])dnl
AC_REQUIRE([AM_SET_CURRENT_AUTOMAKE_VERSION])dnl
AC_REQUIRE([AC_PROG_INSTALL])dnl
if test "`cd $srcdir && pwd`" != "`pwd`"; then
  # Use -I$(srcdir) only when $(srcdir) != ., so that make's output
  # is not polluted with repeated "-I."
  AC_SUBST([am__isrc], [' -I$(srcdir)'])_AM_SUBST_NOTMAKE([am__isrc])dnl
  # test to see if srcdir already configured
  if test -f $srcdir/config.status; then
    AC_MSG_ERROR([source directory already configured; run "make distclean" there first])
  fi
fi

# test whether we have cygpath
if test -z "$CYGPATH_W"; then
  if (cygpath --version) >/dev/null 2>/dev/null; then
    CYGPATH_W='cygpath -w'
  else
    CYGPATH_W=echo
  fi
fi
AC_SUBST([CYGPATH_W])

# Define the identity of the package.
dnl Distinguish between old-style and new-style calls.
m4_ifval([$2],
[m4_ifval([$3], [_AM_SET_OPTION([no-define])])dnl
 AC_SUBST([PACKAGE], [$1])dnl
 AC_SUBST([VERSION], [$2])],
[_AM_SET_OPTIONS([$1])dnl
dnl Diagnose old-style AC_INIT with new-style AM_AUTOMAKE_INIT.
m4_if(m4_ifdef([AC_PACKAGE_NAME], 1)m4_ifdef([AC_PACKAGE_VERSION], 1), 11,,
  [m4_fatal([AC_INIT should be called with package and version arguments])])dnl
 AC_SUBST([PACKAGE], ['AC_PACKAGE_TARNAME'])dnl
 AC_SUBST([VERSION], ['AC_PACKAGE_VERSION'])])dnl

_AM_IF_OPTION([no-define],,
[AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE", [Name of package])
 AC_DEFINE_UNQUOTED(VERSION, "$VERSION", [Version number of package])])dnl

# Some tools Automake needs.
AC_REQUIRE([AM_SANITY_CHECK])dnl
AC_REQUIRE([AC_ARG_PROGRAM])dnl
AM_MISSING_PROG(ACLOCAL, aclocal-${am__api_version})
AM_MISSING_PROG(AUTOCONF, autoconf)
AM_MISSING_PROG(AUTOMAKE, automake-${am__api_version})
AM_MISSING_PROG(AUTOHEADER, autoheader)
AM_MISSING_PROG(MAKEINFO, makeinfo)
AC_REQUIRE([AM_PROG_INSTALL_SH])dnl
AC_REQUIRE([AM_PROG_INSTALL_STRIP])dnl
AC_REQUIRE([AM_PROG_MKDIR_P])dnl
# We need awk for the "check" target.  The system "awk" is bad on
# some platforms.
AC_REQUIRE([AC_PROG_AWK])dnl
AC_REQUIRE([AC_PROG_MAKE_SET])dnl
AC_REQUIRE([AM_SET_LEADING_DOT])dnl
_AM_IF_OPTION([tar-ustar], [_AM_PROG_TAR([ustar])],
	      [_AM_IF_OPTION([tar-pax], [_AM_PROG_TAR([pax])],
			     [_AM_PROG_TAR([v7])])])
_AM_IF_OPTION([no-dependencies],,
[AC_PROVIDE_IFELSE([AC_PROG_CC],
		  [_AM_DEPENDENCIES(CC)],
		  [define([AC_PROG_CC],
			  defn([AC_PROG_CC])[_AM_DEPENDENCIES(CC)])])dnl
AC_PROVIDE_IFELSE([AC_PROG_CXX],
		  [_AM_DEPENDENCIES(CXX)],
		  [define([AC_PROG_CXX],
			  defn([AC_PROG_CXX])[_AM_DEPENDENCIES(CXX)])])dnl
AC_PROVIDE_IFELSE([AC_PROG_OBJC],
		  [_AM_DEPENDENCIES(OBJC)],
		  [define([AC_PROG_OBJC],
			  defn([AC_PROG_OBJC])[_AM_DEPENDENCIES(OBJC)])])dnl
])
_AM_IF_OPTION([silent-rules], [AC_REQUIRE([AM_SILENT_RULES])])dnl
dnl The `parallel-tests' driver may need to know about EXEEXT, so add the
dnl `am__EXEEXT' conditional if _AM_COMPILER_EXEEXT was seen.  This macro
dnl is hooked onto _AC_COMPILER_EXEEXT early, see below.
AC_CONFIG_COMMANDS_PRE(dnl
[m4_provide_if([_AM_COMPILER_EXEEXT],
  [AM_CONDITIONAL([am__EXEEXT], [test -n "$EXEEXT"])])])dnl
])

dnl Hook into `_AC_COMPILER_EXEEXT' early to learn its expansion.  Do not
dnl add the conditional right here, as _AC_COMPILER_EXEEXT may be further
dnl mangled by Autoconf and run in a shell conditional statement.
m4_define([_AC_COMPILER_EXEEXT],
m4_defn([_AC_COMPILER_EXEEXT])[m4_provide([_AM_COMPILER_EXEEXT])])


# When config.status generates a header, we must update the stamp-h file.
# This file resides in the same directory as the config header
# that is generated.  The stamp files are numbered to have different names.

# Autoconf calls _AC_AM_CONFIG_HEADER_HOOK (when defined) in the
# loop where config.status creates the headers, so we can generate
# our stamp files there.
AC_DEFUN([_AC_AM_CONFIG_HEADER_HOOK],
[# Compute $1's index in $config_headers.
_am_arg=$1
_am_stamp_count=1
for _am_header in $config_headers :; do
  case $_am_header in
    $_am_arg | $_am_arg:* )
      break ;;
    * )
      _am_stamp_count=`expr $_am_stamp_count + 1` ;;
  esac
done
echo "timestamp for $_am_arg" >`AS_DIRNAME(["$_am_arg"])`/stamp-h[]$_am_stamp_count])

# Copyright (C) 2001, 2003, 2005, 2008  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# AM_PROG_INSTALL_SH
# ------------------
# Define $install_sh.
AC_DEFUN([AM_PROG_INSTALL_SH],
[AC_REQUIRE([AM_AUX_DIR_EXPAND])dnl
if test x"${install_sh}" != xset; then
  case $am_aux_dir in
  *\ * | *\	*)
    install_sh="\${SHELL} '$am_aux_dir/install-sh'" ;;
  *)
    install_sh="\${SHELL} $am_aux_dir/install-sh"
  esac
fi
AC_SUBST(install_sh)])

# Copyright (C) 2003, 2005  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 2

# Check whether the underlying file-system supports filenames
# with a leading dot.  For instance MS-DOS doesn't.
AC_DEFUN([AM_SET_LEADING_DOT],
[rm -rf .tst 2>/dev/null
mkdir .tst 2>/dev/null
if test -d .tst; then
  am__leading_dot=.
else
  am__leading_dot=_
fi
rmdir .tst 2>/dev/null
AC_SUBST([am__leading_dot])])

# Check to see how 'make' treats includes.	            -*- Autoconf -*-

# Copyright (C) 2001, 2002, 2003, 2005, 2009  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 4

# AM_MAKE_INCLUDE()
# -----------------
# Check to see how make treats includes.
AC_DEFUN([AM_MAKE_INCLUDE],
[am_make=${MAKE-make}
cat > confinc << 'END'
am__doit:
	@echo this is the am__doit target
.PHONY: am__doit
END
# If we don't find an include directive, just comment out the code.
AC_MSG_CHECKING([for style of include used by $am_make])
am__include="#"
am__quote=
_am_result=none
# First try GNU make style include.
echo "include confinc" > confmf
# Ignore all kinds of additional output from `make'.
case `$am_make -s -f confmf 2> /dev/null` in #(
*the\ am__doit\ target*)
  am__include=include
  am__quote=
  _am_result=GNU
  ;;
esac
# Now try BSD make style include.
if test "$am__include" = "#"; then
   echo '.include "confinc"' > confmf
   case `$am_make -s -f confmf 2> /dev/null` in #(
   *the\ am__doit\ target*)
     am__include=.include
     am__quote="\""
     _am_result=BSD
     ;;
   esac
fi
AC_SUBST([am__include])
AC_SUBST([am__quote])
AC_MSG_RESULT([$_am_result])
rm -f confinc confmf
])

# Copyright (C) 1999, 2000, 2001, 2003, 2004, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 6

# AM_PROG_CC_C_O
# --------------
# Like AC_PROG_CC_C_O, but changed for automake.
AC_DEFUN([AM_PROG_CC_C_O],
[AC_REQUIRE([AC_PROG_CC_C_O])dnl
AC_REQUIRE([AM_AUX_DIR_EXPAND])dnl
AC_REQUIRE_AUX_FILE([compile])dnl
# FIXME: we rely on the cache variable name because
# there is no other way.
set dummy $CC
am_cc=`echo $[2] | sed ['s/[^a-zA-Z0-9_]/_/g;s/^[0-9]/_/']`
eval am_t=\$ac_cv_prog_cc_${am_cc}_c_o
if test "$am_t" != yes; then
   # Losing compiler, so override with the script.
   # FIXME: It is wrong to rewrite CC.
   # But if we don't then we get into trouble of one sort or another.
   # A longer-term fix would be to have automake use am__CC in this case,
   # and then we could set am__CC="\$(top_srcdir)/compile \$(CC)"
   CC="$am_aux_dir/compile $CC"
fi
dnl Make sure AC_PROG_CC is never called again, or it will override our
dnl setting of CC.
m4_define([AC_PROG_CC],
          [m4_fatal([AC_PROG_CC cannot be called after AM_PROG_CC_C_O])])
])

# Fake the existence of programs that GNU maintainers use.  -*- Autoconf -*-

# Copyright (C) 1997, 1999, 2000, 2001, 2003, 2004, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 6

# AM_MISSING_PROG(NAME, PROGRAM)
# ------------------------------
AC_DEFUN([AM_MISSING_PROG],
[AC_REQUIRE([AM_MISSING_HAS_RUN])
$1=${$1-"${am_missing_run}$2"}
AC_SUBST($1)])


# AM_MISSING_HAS_RUN
# ------------------
# Define MISSING if not defined so far and test if it supports --run.
# If it does, set am_missing_run to use it, otherwise, to nothing.
AC_DEFUN([AM_MISSING_HAS_RUN],
[AC_REQUIRE([AM_AUX_DIR_EXPAND])dnl
AC_REQUIRE_AUX_FILE([missing])dnl
if test x"${MISSING+set}" != xset; then
  case $am_aux_dir in
  *\ * | *\	*)
    MISSING="\${SHELL} \"$am_aux_dir/missing\"" ;;
  *)
    MISSING="\${SHELL} $am_aux_dir/missing" ;;
  esac
fi
# Use eval to expand $SHELL
if eval "$MISSING --run true"; then
  am_missing_run="$MISSING --run "
else
  am_missing_run=
  AC_MSG_WARN([`missing' script is too old or missing])
fi
])

# Copyright (C) 2003, 2004, 2005, 2006  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# AM_PROG_MKDIR_P
# ---------------
# Check for `mkdir -p'.
AC_DEFUN([AM_PROG_MKDIR_P],
[AC_PREREQ([2.60])dnl
AC_REQUIRE([AC_PROG_MKDIR_P])dnl
dnl Automake 1.8 to 1.9.6 used to define mkdir_p.  We now use MKDIR_P,
dnl while keeping a definition of mkdir_p for backward compatibility.
dnl @MKDIR_P@ is magic: AC_OUTPUT adjusts its value for each Makefile.
dnl However we cannot define mkdir_p as $(MKDIR_P) for the sake of
dnl Makefile.ins that do not define MKDIR_P, so we do our own
dnl adjustment using top_builddir (which is defined more often than
dnl MKDIR_P).
AC_SUBST([mkdir_p], ["$MKDIR_P"])dnl
case $mkdir_p in
  [[\\/$]]* | ?:[[\\/]]*) ;;
  */*) mkdir_p="\$(top_builddir)/$mkdir_p" ;;
esac
])

# Helper functions for option handling.                     -*- Autoconf -*-

# Copyright (C) 2001, 2002, 2003, 2005, 2008  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 4

# _AM_MANGLE_OPTION(NAME)
# -----------------------
AC_DEFUN([_AM_MANGLE_OPTION],
[[_AM_OPTION_]m4_bpatsubst($1, [[^a-zA-Z0-9_]], [_])])

# _AM_SET_OPTION(NAME)
# ------------------------------
# Set option NAME.  Presently that only means defining a flag for this option.
AC_DEFUN([_AM_SET_OPTION],
[m4_define(_AM_MANGLE_OPTION([$1]), 1)])

# _AM_SET_OPTIONS(OPTIONS)
# ----------------------------------
# OPTIONS is a space-separated list of Automake options.
AC_DEFUN([_AM_SET_OPTIONS],
[m4_foreach_w([_AM_Option], [$1], [_AM_SET_OPTION(_AM_Option)])])

# _AM_IF_OPTION(OPTION, IF-SET, [IF-NOT-SET])
# -------------------------------------------
# Execute IF-SET if OPTION is set, IF-NOT-SET otherwise.
AC_DEFUN([_AM_IF_OPTION],
[m4_ifset(_AM_MANGLE_OPTION([$1]), [$2], [$3])])

# Check to make sure that the build environment is sane.    -*- Autoconf -*-

# Copyright (C) 1996, 1997, 2000, 2001, 2003, 2005, 2008
# Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 5

# AM_SANITY_CHECK
# ---------------
AC_DEFUN([AM_SANITY_CHECK],
[AC_MSG_CHECKING([whether build environment is sane])
# Just in case
sleep 1
echo timestamp > conftest.file
# Reject unsafe characters in $srcdir or the absolute working directory
# name.  Accept space and tab only in the latter.
am_lf='
'
case `pwd` in
  *[[\\\"\#\$\&\'\`$am_lf]]*)
    AC_MSG_ERROR([unsafe absolute working directory name]);;
esac
case $srcdir in
  *[[\\\"\#\$\&\'\`$am_lf\ \	]]*)
    AC_MSG_ERROR([unsafe srcdir value: `$srcdir']);;
esac

# Do `set' in a subshell so we don't clobber the current shell's
# arguments.  Must try -L first in case configure is actually a
# symlink; some systems play weird games with the mod time of symlinks
# (eg FreeBSD returns the mod time of the symlink's containing
# directory).
if (
   set X `ls -Lt "$srcdir/configure" conftest.file 2> /dev/null`
   if test "$[*]" = "X"; then
      # -L didn't work.
      set X `ls -t "$srcdir/configure" conftest.file`
   fi
   rm -f conftest.file
   if test "$[*]" != "X $srcdir/configure conftest.file" \
      && test "$[*]" != "X conftest.file $srcdir/configure"; then

      # If neither matched, then we have a broken ls.  This can happen
      # if, for instance, CONFIG_SHELL is bash and it inherits a
      # broken ls alias from the environment.  This has actually
      # happened.  Such a system could not be considered "sane".
      AC_MSG_ERROR([ls -t appears to fail.  Make sure there is not a broken
alias in your environment])
   fi

   test "$[2]" = conftest.file
   )
then
   # Ok.
   :
else
   AC_MSG_ERROR([newly created file is older than distributed files!
Check your system clock])
fi
AC_MSG_RESULT(yes)])

# Copyright (C) 2001, 2003, 2005  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# AM_PROG_INSTALL_STRIP
# ---------------------
# One issue with vendor `install' (even GNU) is that you can't
# specify the program used to strip binaries.  This is especially
# annoying in cross-compiling environments, where the build's strip
# is unlikely to handle the host's binaries.
# Fortunately install-sh will honor a STRIPPROG variable, so we
# always use install-sh in `make install-strip', and initialize
# STRIPPROG with the value of the STRIP variable (set by the user).
AC_DEFUN([AM_PROG_INSTALL_STRIP],
[AC_REQUIRE([AM_PROG_INSTALL_SH])dnl
# Installed binaries are usually stripped using `strip' when the user
# run `make install-strip'.  However `strip' might not be the right
# tool to use in cross-compilation environments, therefore Automake
# will honor the `STRIP' environment variable to overrule this program.
dnl Don't test for $cross_compiling = yes, because it might be `maybe'.
if test "$cross_compiling" != no; then
  AC_CHECK_TOOL([STRIP], [strip], :)
fi
INSTALL_STRIP_PROGRAM="\$(install_sh) -c -s"
AC_SUBST([INSTALL_STRIP_PROGRAM])])

# Copyright (C) 2006, 2008  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 2

# _AM_SUBST_NOTMAKE(VARIABLE)
# ---------------------------
# Prevent Automake from outputting VARIABLE = @VARIABLE@ in Makefile.in.
# This macro is traced by Automake.
AC_DEFUN([_AM_SUBST_NOTMAKE])

# AM_SUBST_NOTMAKE(VARIABLE)
# ---------------------------
# Public sister of _AM_SUBST_NOTMAKE.
AC_DEFUN([AM_SUBST_NOTMAKE], [_AM_SUBST_NOTMAKE($@)])

# Check how to create a tarball.                            -*- Autoconf -*-

# Copyright (C) 2004, 2005  Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 2

# _AM_PROG_TAR(FORMAT)
# --------------------
# Check how to create a tarball in format FORMAT.
# FORMAT should be one of `v7', `ustar', or `pax'.
#
# Substitute a variable $(am__tar) that is a command
# writing to stdout a FORMAT-tarball containing the directory
# $tardir.
#     tardir=directory && $(am__tar) > result.tar
#
# Substitute a variable $(am__untar) that extract such
# a tarball read from stdin.
#     $(am__untar) < result.tar
AC_DEFUN([_AM_PROG_TAR],
[# Always define AMTAR for backward compatibility.
AM_MISSING_PROG([AMTAR], [tar])
m4_if([$1], [v7],
     [am__tar='${AMTAR} chof - "$$tardir"'; am__untar='${AMTAR} xf -'],
     [m4_case([$1], [ustar],, [pax],,
              [m4_fatal([Unknown tar format])])
AC_MSG_CHECKING([how to create a $1 tar archive])
# Loop over all known methods to create a tar archive until one works.
_am_tools='gnutar m4_if([$1], [ustar], [plaintar]) pax cpio none'
_am_tools=${am_cv_prog_tar_$1-$_am_tools}
# Do not fold the above two line into one, because Tru64 sh and
# Solaris sh will not grok spaces in the rhs of `-'.
for _am_tool in $_am_tools
do
  case $_am_tool in
  gnutar)
    for _am_tar in tar gnutar gtar;
    do
      AM_RUN_LOG([$_am_tar --version]) && break
    done
    am__tar="$_am_tar --format=m4_if([$1], [pax], [posix], [$1]) -chf - "'"$$tardir"'
    am__tar_="$_am_tar --format=m4_if([$1], [pax], [posix], [$1]) -chf - "'"$tardir"'
    am__untar="$_am_tar -xf -"
    ;;
  plaintar)
    # Must skip GNU tar: if it does not support --format= it doesn't create
    # ustar tarball either.
    (tar --version) >/dev/null 2>&1 && continue
    am__tar='tar chf - "$$tardir"'
    am__tar_='tar chf - "$tardir"'
    am__untar='tar xf -'
    ;;
  pax)
    am__tar='pax -L -x $1 -w "$$tardir"'
    am__tar_='pax -L -x $1 -w "$tardir"'
    am__untar='pax -r'
    ;;
  cpio)
    am__tar='find "$$tardir" -print | cpio -o -H $1 -L'
    am__tar_='find "$tardir" -print | cpio -o -H $1 -L'
    am__untar='cpio -i -H $1 -d'
    ;;
  none)
    am__tar=false
    am__tar_=false
    am__untar=false
    ;;
  esac

  # If the value was cached, stop now.  We just wanted to have am__tar
  # and am__untar set.
  test -n "${am_cv_prog_tar_$1}" && break

  # tar/untar a dummy directory, and stop if the command works
  rm -rf conftest.dir
  mkdir conftest.dir
  echo GrepMe > conftest.dir/file
  AM_RUN_LOG([tardir=conftest.dir && eval $am__tar_ >conftest.tar])
  rm -rf conftest.dir
  if test -s conftest.tar; then
    AM_RUN_LOG([$am__untar <conftest.tar])
    grep GrepMe conftest.dir/file >/dev/null 2>&1 && break
  fi
done
rm -rf conftest.dir

AC_CACHE_VAL([am_cv_prog_tar_$1], [am_cv_prog_tar_$1=$_am_tool])
AC_MSG_RESULT([$am_cv_prog_tar_$1])])
AC_SUBST([am__tar])
AC_SUBST([am__untar])
]) # _AM_PROG_TAR

# Check for fnmatch - serial 4.

# Copyright (C) 2000-2007, 2009-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# Autoconf defines AC_FUNC_FNMATCH, but that is obsolescent.
# New applications should use the macros below instead.

# Request a POSIX compliant fnmatch function.
AC_DEFUN([gl_FUNC_FNMATCH_POSIX],
[
  m4_divert_text([DEFAULTS], [gl_fnmatch_required=POSIX])

  dnl Persuade glibc <fnmatch.h> to declare FNM_CASEFOLD etc.
  dnl This is only needed if gl_fnmatch_required = GNU. It would be possible
  dnl to avoid this dependency for gl_FUNC_FNMATCH_POSIX by putting
  dnl gl_FUNC_FNMATCH_GNU into a separate .m4 file.
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])

  FNMATCH_H=
  gl_fnmatch_required_lowercase=`echo $gl_fnmatch_required | tr 'A-Z' 'a-z'`
  gl_fnmatch_cache_var="gl_cv_func_fnmatch_${gl_fnmatch_required_lowercase}"
  AC_CACHE_CHECK([for working $gl_fnmatch_required fnmatch],
    [$gl_fnmatch_cache_var],
    [dnl Some versions of Solaris, SCO, and the GNU C Library
     dnl have a broken or incompatible fnmatch.
     dnl So we run a test program.  If we are cross-compiling, take no chance.
     dnl Thanks to John Oleynick, François Pinard, and Paul Eggert for this
     dnl test.
     if test $gl_fnmatch_required = GNU; then
       gl_fnmatch_gnu_start=
       gl_fnmatch_gnu_end=
     else
       gl_fnmatch_gnu_start='#if 0'
       gl_fnmatch_gnu_end='#endif'
     fi
     AC_RUN_IFELSE(
       [AC_LANG_PROGRAM(
          [[#include <fnmatch.h>
            static int
            y (char const *pattern, char const *string, int flags)
            {
              return fnmatch (pattern, string, flags) == 0;
            }
            static int
            n (char const *pattern, char const *string, int flags)
            {
              return fnmatch (pattern, string, flags) == FNM_NOMATCH;
            }
          ]],
          [[char const *Apat = 'A' < '\\\\' ? "[A-\\\\\\\\]" : "[\\\\\\\\-A]";
            char const *apat = 'a' < '\\\\' ? "[a-\\\\\\\\]" : "[\\\\\\\\-a]";
            static char const A_1[] = { 'A' - 1, 0 };
            static char const A01[] = { 'A' + 1, 0 };
            static char const a_1[] = { 'a' - 1, 0 };
            static char const a01[] = { 'a' + 1, 0 };
            static char const bs_1[] = { '\\\\' - 1, 0 };
            static char const bs01[] = { '\\\\' + 1, 0 };
            return
             !(n ("a*", "", 0)
               && y ("a*", "abc", 0)
               && n ("d*/*1", "d/s/1", FNM_PATHNAME)
               && y ("a\\\\bc", "abc", 0)
               && n ("a\\\\bc", "abc", FNM_NOESCAPE)
               && y ("*x", ".x", 0)
               && n ("*x", ".x", FNM_PERIOD)
               && y (Apat, "\\\\", 0) && y (Apat, "A", 0)
               && y (apat, "\\\\", 0) && y (apat, "a", 0)
               && n (Apat, A_1, 0) == ('A' < '\\\\')
               && n (apat, a_1, 0) == ('a' < '\\\\')
               && y (Apat, A01, 0) == ('A' < '\\\\')
               && y (apat, a01, 0) == ('a' < '\\\\')
               && y (Apat, bs_1, 0) == ('A' < '\\\\')
               && y (apat, bs_1, 0) == ('a' < '\\\\')
               && n (Apat, bs01, 0) == ('A' < '\\\\')
               && n (apat, bs01, 0) == ('a' < '\\\\')
               $gl_fnmatch_gnu_start
               && y ("xxXX", "xXxX", FNM_CASEFOLD)
               && y ("a++(x|yy)b", "a+xyyyyxb", FNM_EXTMATCH)
               && n ("d*/*1", "d/s/1", FNM_FILE_NAME)
               && y ("*", "x", FNM_FILE_NAME | FNM_LEADING_DIR)
               && y ("x*", "x/y/z", FNM_FILE_NAME | FNM_LEADING_DIR)
               && y ("*c*", "c/x", FNM_FILE_NAME | FNM_LEADING_DIR)
               $gl_fnmatch_gnu_end
              );
          ]])],
       [eval "$gl_fnmatch_cache_var=yes"],
       [eval "$gl_fnmatch_cache_var=no"],
       [eval "$gl_fnmatch_cache_var=\"guessing no\""])
    ])
  eval "gl_fnmatch_result=\"\$$gl_fnmatch_cache_var\""
  if test "$gl_fnmatch_result" = yes; then
    dnl Not strictly necessary. Only to avoid spurious leftover files if people
    dnl don't do "make distclean".
    rm -f "$gl_source_base/fnmatch.h"
  else
    FNMATCH_H=fnmatch.h
    AC_LIBOBJ([fnmatch])
    dnl We must choose a different name for our function, since on ELF systems
    dnl a broken fnmatch() in libc.so would override our fnmatch() if it is
    dnl compiled into a shared library.
    AC_DEFINE_UNQUOTED([fnmatch], [${gl_fnmatch_required_lowercase}_fnmatch],
      [Define to a replacement function name for fnmatch().])
    dnl Prerequisites of lib/fnmatch.c.
    AC_REQUIRE([AC_TYPE_MBSTATE_T])
    AC_CHECK_DECLS([isblank], [], [], [#include <ctype.h>])
    AC_CHECK_FUNCS_ONCE([btowc isblank iswctype mbsrtowcs mempcpy wmemchr wmemcpy wmempcpy])
    AC_CHECK_HEADERS_ONCE([wctype.h])
  fi
  AC_SUBST([FNMATCH_H])
])

# Request a POSIX compliant fnmatch function with GNU extensions.
AC_DEFUN([gl_FUNC_FNMATCH_GNU],
[
  m4_divert_text([INIT_PREPARE], [gl_fnmatch_required=GNU])

  AC_REQUIRE([gl_FUNC_FNMATCH_POSIX])
])

# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2010 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([wc_gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  # Code from module arg-nonnull:
  # Code from module fnmatch:
  # Code from module fnmatch-gnu:
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([wc_gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  gl_m4_base='modules/wildcard/glm4'
  m4_pushdef([AC_LIBOBJ], m4_defn([wc_gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([wc_gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([wc_gl_LIBSOURCES]))
  m4_pushdef([wc_gl_LIBSOURCES_LIST], [])
  m4_pushdef([wc_gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='modules/wildcard/gllib'
  # Code from module arg-nonnull:
  # Code from module fnmatch:
  gl_FUNC_FNMATCH_POSIX
  # Code from module fnmatch-gnu:
  gl_FUNC_FNMATCH_GNU
  # Code from module dummy:
  # End of code from modules
  m4_ifval(wc_gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([wc_gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]wc_gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([wc_gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([wc_gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([wc_gl_LIBSOURCES_DIR])
  m4_popdef([wc_gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    wc_gl_libobjs=
    wc_gl_ltlibobjs=
    if test -n "$wc_gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $wc_gl_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        wc_gl_libobjs="$wc_gl_libobjs $i.$ac_objext"
        wc_gl_ltlibobjs="$wc_gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([wc_gl_LIBOBJS], [$wc_gl_libobjs])
    AC_SUBST([wc_gl_LTLIBOBJS], [$wc_gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([wc_gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([wc_gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([wc_gltests_LIBSOURCES]))
  m4_pushdef([wc_gltests_LIBSOURCES_LIST], [])
  m4_pushdef([wc_gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
changequote(,)dnl
  wc_gltests_WITNESS=IN_`echo "${PACKAGE-$PACKAGE_TARNAME}" | LC_ALL=C tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ | LC_ALL=C sed -e 's/[^A-Z0-9_]/_/g'`_GNULIB_TESTS
changequote([, ])dnl
  AC_SUBST([wc_gltests_WITNESS])
  gl_module_indicator_condition=$wc_gltests_WITNESS
  m4_pushdef([gl_MODULE_INDICATOR_CONDITION], [$gl_module_indicator_condition])
  m4_popdef([gl_MODULE_INDICATOR_CONDITION])
  m4_ifval(wc_gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([wc_gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]wc_gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([wc_gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([wc_gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([wc_gltests_LIBSOURCES_DIR])
  m4_popdef([wc_gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    wc_gltests_libobjs=
    wc_gltests_ltlibobjs=
    if test -n "$wc_gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $wc_gltests_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        wc_gltests_libobjs="$wc_gltests_libobjs $i.$ac_objext"
        wc_gltests_ltlibobjs="$wc_gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([wc_gltests_LIBOBJS], [$wc_gltests_libobjs])
    AC_SUBST([wc_gltests_LTLIBOBJS], [$wc_gltests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into wc_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([wc_gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [wc_gl_LIBSOURCES([$1.c])])dnl
  wc_gl_LIBOBJS="$wc_gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into wc_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([wc_gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [wc_gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([wc_gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([wc_gl_LIBSOURCES_DIR], [modules/wildcard/gllib])
      m4_append([wc_gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into wc_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([wc_gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [wc_gltests_LIBSOURCES([$1.c])])dnl
  wc_gltests_LIBOBJS="$wc_gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into wc_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([wc_gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [wc_gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([wc_gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([wc_gltests_LIBSOURCES_DIR], [tests])
      m4_append([wc_gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([wc_gl_FILE_LIST], [
  build-aux/arg-nonnull.h
  lib/dummy.c
  lib/fnmatch.c
  lib/fnmatch.in.h
  lib/fnmatch_loop.c
  m4/00gnulib.m4
  m4/fnmatch.m4
  m4/gnulib-common.m4
  m4/mbstate_t.m4
])

# errno_h.m4 serial 6
dnl Copyright (C) 2004, 2006, 2008, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN_ONCE([gl_HEADER_ERRNO_H],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_CACHE_CHECK([for complete errno.h], [gl_cv_header_errno_h_complete], [
    AC_EGREP_CPP([booboo],[
#include <errno.h>
#if !defined ENOMSG
booboo
#endif
#if !defined EIDRM
booboo
#endif
#if !defined ENOLINK
booboo
#endif
#if !defined EPROTO
booboo
#endif
#if !defined EMULTIHOP
booboo
#endif
#if !defined EBADMSG
booboo
#endif
#if !defined EOVERFLOW
booboo
#endif
#if !defined ENOTSUP
booboo
#endif
#if !defined ESTALE
booboo
#endif
#if !defined ECANCELED
booboo
#endif
      ],
      [gl_cv_header_errno_h_complete=no],
      [gl_cv_header_errno_h_complete=yes])
  ])
  if test $gl_cv_header_errno_h_complete = yes; then
    ERRNO_H=''
  else
    gl_CHECK_NEXT_HEADERS([errno.h])
    ERRNO_H='errno.h'
  fi
  AC_SUBST([ERRNO_H])
  gl_REPLACE_ERRNO_VALUE([EMULTIHOP])
  gl_REPLACE_ERRNO_VALUE([ENOLINK])
  gl_REPLACE_ERRNO_VALUE([EOVERFLOW])
])

# Assuming $1 = EOVERFLOW.
# The EOVERFLOW errno value ought to be defined in <errno.h>, according to
# POSIX.  But some systems (like OpenBSD 4.0 or AIX 3) don't define it, and
# some systems (like OSF/1) define it when _XOPEN_SOURCE_EXTENDED is defined.
# Check for the value of EOVERFLOW.
# Set the variables EOVERFLOW_HIDDEN and EOVERFLOW_VALUE.
AC_DEFUN([gl_REPLACE_ERRNO_VALUE],
[
  if test -n "$ERRNO_H"; then
    AC_CACHE_CHECK([for ]$1[ value], [gl_cv_header_errno_h_]$1, [
      AC_EGREP_CPP([yes],[
#include <errno.h>
#ifdef ]$1[
yes
#endif
      ],
      [gl_cv_header_errno_h_]$1[=yes],
      [gl_cv_header_errno_h_]$1[=no])
      if test $gl_cv_header_errno_h_]$1[ = no; then
        AC_EGREP_CPP([yes],[
#define _XOPEN_SOURCE_EXTENDED 1
#include <errno.h>
#ifdef ]$1[
yes
#endif
          ], [gl_cv_header_errno_h_]$1[=hidden])
        if test $gl_cv_header_errno_h_]$1[ = hidden; then
          dnl The macro exists but is hidden.
          dnl Define it to the same value.
          AC_COMPUTE_INT([gl_cv_header_errno_h_]$1, $1, [
#define _XOPEN_SOURCE_EXTENDED 1
#include <errno.h>
/* The following two lines are a workaround against an autoconf-2.52 bug.  */
#include <stdio.h>
#include <stdlib.h>
])
        fi
      fi
    ])
    case $gl_cv_header_errno_h_]$1[ in
      yes | no)
        ]$1[_HIDDEN=0; ]$1[_VALUE=
        ;;
      *)
        ]$1[_HIDDEN=1; ]$1[_VALUE="$gl_cv_header_errno_h_]$1["
        ;;
    esac
    AC_SUBST($1[_HIDDEN])
    AC_SUBST($1[_VALUE])
  fi
])

dnl Autoconf >= 2.61 has AC_COMPUTE_INT built-in.
dnl Remove this when we can assume autoconf >= 2.61.
m4_ifdef([AC_COMPUTE_INT], [], [
  AC_DEFUN([AC_COMPUTE_INT], [_AC_COMPUTE_INT([$2],[$1],[$3],[$4])])
])

# gethostname.m4 serial 9
dnl Copyright (C) 2002, 2008, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Ensure
# - the gethostname() function,
# - the HOST_NAME_MAX macro in <limits.h>.
AC_DEFUN([gl_FUNC_GETHOSTNAME],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  gl_PREREQ_SYS_H_WINSOCK2

  dnl Where is gethostname() defined?
  dnl - On native Windows, it is in ws2_32.dll.
  dnl - Otherwise is is in libc.
  GETHOSTNAME_LIB=
  AC_CHECK_FUNCS([gethostname], , [
    AC_CACHE_CHECK([for gethostname in winsock2.h and -lws2_32],
      [gl_cv_w32_gethostname],
      [gl_cv_w32_gethostname=no
       gl_save_LIBS="$LIBS"
       LIBS="$LIBS -lws2_32"
       AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#ifdef HAVE_WINSOCK2_H
#include <winsock2.h>
#endif
#include <stddef.h>
]], [[gethostname(NULL, 0);]])], [gl_cv_w32_gethostname=yes])
       LIBS="$gl_save_LIBS"
      ])
    if test "$gl_cv_w32_gethostname" = "yes"; then
      GETHOSTNAME_LIB="-lws2_32"
    fi
  ])
  AC_SUBST([GETHOSTNAME_LIB])

  if test "$ac_cv_func_gethostname" = no; then
    AC_LIBOBJ([gethostname])
    HAVE_GETHOSTNAME=0
    gl_PREREQ_GETHOSTNAME
  fi

  dnl Also provide HOST_NAME_MAX when <limits.h> lacks it.
  dnl - On most Unix systems, use MAXHOSTNAMELEN from <sys/param.h> instead.
  dnl - On Solaris, Cygwin, BeOS, use MAXHOSTNAMELEN from <netdb.h> instead.
  dnl - On mingw, use 256, because
  dnl   <http://msdn.microsoft.com/en-us/library/ms738527.aspx> says:
  dnl   "if a buffer of 256 bytes is passed in the name parameter and
  dnl    the namelen parameter is set to 256, the buffer size will always
  dnl    be adequate."
  dnl With this, there is no need to use sysconf (_SC_HOST_NAME_MAX), which
  dnl is not a compile-time constant.
  dnl We cannot override <limits.h> using the usual technique, because
  dnl gl_CHECK_NEXT_HEADERS does not work for <limits.h>. Therefore retrieve
  dnl the value of HOST_NAME_MAX at configure time.
  AC_CHECK_HEADERS_ONCE([sys/param.h])
  AC_CHECK_HEADERS_ONCE([sys/socket.h])
  AC_CHECK_HEADERS_ONCE([netdb.h])
  AC_CACHE_CHECK([for HOST_NAME_MAX], [gl_cv_decl_HOST_NAME_MAX], [
    gl_cv_decl_HOST_NAME_MAX=
    AC_EGREP_CPP([lucky], [
#include <limits.h>
#ifdef HOST_NAME_MAX
lucky
#endif
      ], [gl_cv_decl_HOST_NAME_MAX=yes])
    if test -z "$gl_cv_decl_HOST_NAME_MAX"; then
      dnl It's not defined in <limits.h>. Substitute it.
      if test "$gl_cv_w32_gethostname" = yes; then
        dnl mingw.
        gl_cv_decl_HOST_NAME_MAX=256
      else
        _AC_COMPUTE_INT([MAXHOSTNAMELEN], [gl_cv_decl_HOST_NAME_MAX], [
#include <sys/types.h>
#if HAVE_SYS_PARAM_H
# include <sys/param.h>
#endif
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#if HAVE_NETDB_H
# include <netdb.h>
#endif
])
      fi
    fi
  ])
  if test "$gl_cv_decl_HOST_NAME_MAX" != yes; then
    AC_DEFINE_UNQUOTED([HOST_NAME_MAX], [$gl_cv_decl_HOST_NAME_MAX],
      [Define HOST_NAME_MAX when <limits.h> does not define it.])
  fi
])

# Prerequisites of lib/gethostname.c.
AC_DEFUN([gl_PREREQ_GETHOSTNAME], [
  if test "$gl_cv_w32_gethostname" != "yes"; then
    AC_CHECK_FUNCS([uname])
  fi
])

# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2010 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([sc_gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  # Code from module alignof:
  # Code from module arg-nonnull:
  # Code from module c++defs:
  # Code from module close-hook:
  # Code from module errno:
  # Code from module gethostname:
  # Code from module mbrlen:
  # Code from module mktime:
  # Code from module multiarch:
  # Code from module sockets:
  # Code from module stddef:
  # Code from module strcase:
  # Code from module strftime:
  # Code from module strings:
  # Code from module strptime:
  # Code from module strverscmp:
  # Code from module sys_socket:
  # Code from module sys_utsname:
  # Code from module time:
  # Code from module time_r:
  # Code from module uname:
  # Code from module unistd:
  # Code from module warn-on-use:
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([sc_gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  gl_m4_base='modules/syscalls/glm4'
  m4_pushdef([AC_LIBOBJ], m4_defn([sc_gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([sc_gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([sc_gl_LIBSOURCES]))
  m4_pushdef([sc_gl_LIBSOURCES_LIST], [])
  m4_pushdef([sc_gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='modules/syscalls/gllib'
  # Code from module alignof:
  # Code from module arg-nonnull:
  # Code from module c++defs:
  # Code from module close-hook:
  # Code from module errno:
  gl_HEADER_ERRNO_H
  # Code from module gethostname:
  gl_FUNC_GETHOSTNAME
  gl_UNISTD_MODULE_INDICATOR([gethostname])
  # Code from module mbrlen:
  gl_FUNC_MBRLEN
  gl_WCHAR_MODULE_INDICATOR([mbrlen])
  # Code from module mktime:
  gl_FUNC_MKTIME
  gl_TIME_MODULE_INDICATOR([mktime])
  # Code from module multiarch:
  gl_MULTIARCH
  # Code from module sockets:
  gl_SOCKETS
  # Code from module stddef:
  gl_STDDEF_H
  # Code from module strcase:
  gl_STRCASE
  # Code from module strftime:
  gl_FUNC_GNU_STRFTIME
  # Code from module strings:
  gl_HEADER_STRINGS_H
  # Code from module strptime:
  gl_FUNC_STRPTIME
  gl_TIME_MODULE_INDICATOR([strptime])
  # Code from module strverscmp:
  gl_FUNC_STRVERSCMP
  gl_STRING_MODULE_INDICATOR([strverscmp])
  # Code from module sys_socket:
  gl_HEADER_SYS_SOCKET
  AC_PROG_MKDIR_P
  # Code from module sys_utsname:
  gl_SYS_UTSNAME_H
  AC_PROG_MKDIR_P
  # Code from module time:
  gl_HEADER_TIME_H
  # Code from module time_r:
  gl_TIME_R
  gl_TIME_MODULE_INDICATOR([time_r])
  # Code from module uname:
  gl_FUNC_UNAME
  gl_SYS_UTSNAME_MODULE_INDICATOR([uname])
  # Code from module unistd:
  gl_UNISTD_H
  # Code from module warn-on-use:
  # End of code from modules
  m4_ifval(sc_gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([sc_gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]sc_gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([sc_gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([sc_gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([sc_gl_LIBSOURCES_DIR])
  m4_popdef([sc_gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    sc_gl_libobjs=
    sc_gl_ltlibobjs=
    if test -n "$sc_gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $sc_gl_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        sc_gl_libobjs="$sc_gl_libobjs $i.$ac_objext"
        sc_gl_ltlibobjs="$sc_gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([sc_gl_LIBOBJS], [$sc_gl_libobjs])
    AC_SUBST([sc_gl_LTLIBOBJS], [$sc_gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([sc_gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([sc_gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([sc_gltests_LIBSOURCES]))
  m4_pushdef([sc_gltests_LIBSOURCES_LIST], [])
  m4_pushdef([sc_gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
changequote(,)dnl
  sc_gltests_WITNESS=IN_`echo "${PACKAGE-$PACKAGE_TARNAME}" | LC_ALL=C tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ | LC_ALL=C sed -e 's/[^A-Z0-9_]/_/g'`_GNULIB_TESTS
changequote([, ])dnl
  AC_SUBST([sc_gltests_WITNESS])
  gl_module_indicator_condition=$sc_gltests_WITNESS
  m4_pushdef([gl_MODULE_INDICATOR_CONDITION], [$gl_module_indicator_condition])
  m4_popdef([gl_MODULE_INDICATOR_CONDITION])
  m4_ifval(sc_gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([sc_gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]sc_gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([sc_gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([sc_gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([sc_gltests_LIBSOURCES_DIR])
  m4_popdef([sc_gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    sc_gltests_libobjs=
    sc_gltests_ltlibobjs=
    if test -n "$sc_gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $sc_gltests_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        sc_gltests_libobjs="$sc_gltests_libobjs $i.$ac_objext"
        sc_gltests_ltlibobjs="$sc_gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([sc_gltests_LIBOBJS], [$sc_gltests_libobjs])
    AC_SUBST([sc_gltests_LTLIBOBJS], [$sc_gltests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into sc_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([sc_gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [sc_gl_LIBSOURCES([$1.c])])dnl
  sc_gl_LIBOBJS="$sc_gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into sc_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([sc_gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [sc_gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([sc_gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([sc_gl_LIBSOURCES_DIR], [modules/syscalls/gllib])
      m4_append([sc_gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into sc_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([sc_gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [sc_gltests_LIBSOURCES([$1.c])])dnl
  sc_gltests_LIBOBJS="$sc_gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into sc_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([sc_gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [sc_gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([sc_gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([sc_gltests_LIBSOURCES_DIR], [tests])
      m4_append([sc_gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([sc_gl_FILE_LIST], [
  build-aux/arg-nonnull.h
  build-aux/c++defs.h
  build-aux/warn-on-use.h
  lib/alignof.h
  lib/close-hook.c
  lib/close-hook.h
  lib/errno.in.h
  lib/gethostname.c
  lib/mbrlen.c
  lib/mktime-internal.h
  lib/mktime.c
  lib/sockets.c
  lib/sockets.h
  lib/stddef.in.h
  lib/strcasecmp.c
  lib/strftime.c
  lib/strftime.h
  lib/strings.in.h
  lib/strncasecmp.c
  lib/strptime.c
  lib/strverscmp.c
  lib/sys_socket.in.h
  lib/sys_utsname.in.h
  lib/time.in.h
  lib/time_r.c
  lib/uname.c
  lib/unistd.in.h
  lib/w32sock.h
  m4/00gnulib.m4
  m4/errno_h.m4
  m4/gethostname.m4
  m4/gnulib-common.m4
  m4/mbrlen.m4
  m4/mbstate_t.m4
  m4/mktime.m4
  m4/multiarch.m4
  m4/sockets.m4
  m4/sockpfaf.m4
  m4/stddef_h.m4
  m4/strcase.m4
  m4/strftime.m4
  m4/strings_h.m4
  m4/strptime.m4
  m4/strverscmp.m4
  m4/sys_socket_h.m4
  m4/sys_utsname_h.m4
  m4/time_h.m4
  m4/time_r.m4
  m4/tm_gmtoff.m4
  m4/uname.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wchar_t.m4
])

# mbrlen.m4 serial 2
dnl Copyright (C) 2008, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_MBRLEN],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  AC_REQUIRE([gl_FUNC_MBRTOWC])
  AC_CHECK_FUNCS_ONCE([mbrlen])
  if test $ac_cv_func_mbrlen = no; then
    HAVE_MBRLEN=0
  else
    dnl Most bugs affecting the system's mbrtowc function also affect the
    dnl mbrlen function. So override mbrlen whenever mbrtowc is overridden.
    dnl We could also run the individual tests below; the results would be
    dnl the same.
    if test $REPLACE_MBRTOWC = 1; then
      REPLACE_MBRLEN=1
    fi
  fi
  if test $HAVE_MBRLEN = 0 || test $REPLACE_MBRLEN = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([mbrlen])
    gl_PREREQ_MBRLEN
  fi
])

dnl Test whether mbrlen puts the state into non-initial state when parsing an
dnl incomplete multibyte character.
dnl Result is gl_cv_func_mbrlen_incomplete_state.

AC_DEFUN([gl_MBRLEN_INCOMPLETE_STATE],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_JA])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrlen handles incomplete characters],
    [gl_cv_func_mbrlen_incomplete_state],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
              # Guess no on AIX and OSF/1.
        osf*) gl_cv_func_mbrlen_incomplete_state="guessing no" ;;
              # Guess yes otherwise.
        *)    gl_cv_func_mbrlen_incomplete_state="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_JA != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      const char input[] = "B\217\253\344\217\251\316er"; /* "Büßer" */
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrlen (input + 1, 1, &state) == (size_t)(-2))
        if (mbsinit (&state))
          return 1;
    }
  return 0;
}],
          [gl_cv_func_mbrlen_incomplete_state=yes],
          [gl_cv_func_mbrlen_incomplete_state=no],
          [])
      fi
    ])
])

dnl Test whether mbrlen, when parsing the end of a multibyte character,
dnl correctly returns the number of bytes that were needed to complete the
dnl character (not the total number of bytes of the multibyte character).
dnl Result is gl_cv_func_mbrlen_retval.

AC_DEFUN([gl_MBRLEN_RETVAL],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_FR_UTF8])
  AC_REQUIRE([gt_LOCALE_JA])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrlen has a correct return value],
    [gl_cv_func_mbrlen_retval],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                          # Guess no on HP-UX and Solaris.
        hpux* | solaris*) gl_cv_func_mbrlen_retval="guessing no" ;;
                          # Guess yes otherwise.
        *)                gl_cv_func_mbrlen_retval="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_FR_UTF8 != none || test $LOCALE_JA != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* This fails on Solaris.  */
  if (setlocale (LC_ALL, "$LOCALE_FR_UTF8") != NULL)
    {
      char input[] = "B\303\274\303\237er"; /* "Büßer" */
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrlen (input + 1, 1, &state) == (size_t)(-2))
        {
          input[1] = '\0';
          if (mbrlen (input + 2, 5, &state) != 1)
            return 1;
        }
    }
  /* This fails on HP-UX 11.11.  */
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      char input[] = "B\217\253\344\217\251\316er"; /* "Büßer" */
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrlen (input + 1, 1, &state) == (size_t)(-2))
        {
          input[1] = '\0';
          if (mbrlen (input + 2, 5, &state) != 2)
            return 1;
        }
    }
  return 0;
}],
          [gl_cv_func_mbrlen_retval=yes],
          [gl_cv_func_mbrlen_retval=no],
          [])
      fi
    ])
])

dnl Test whether mbrlen, when parsing a NUL character, correctly returns 0.
dnl Result is gl_cv_func_mbrlen_nul_retval.

AC_DEFUN([gl_MBRLEN_NUL_RETVAL],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_ZH_CN])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrlen returns 0 when parsing a NUL character],
    [gl_cv_func_mbrlen_nul_retval],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                    # Guess no on Solaris 9.
        solaris2.9) gl_cv_func_mbrlen_nul_retval="guessing no" ;;
                    # Guess yes otherwise.
        *)          gl_cv_func_mbrlen_nul_retval="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_ZH_CN != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* This crashes on Solaris 9 inside __mbrtowc_dense_gb18030.  */
  if (setlocale (LC_ALL, "$LOCALE_ZH_CN") != NULL)
    {
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrlen ("", 1, &state) != 0)
        return 1;
    }
  return 0;
}],
          [gl_cv_func_mbrlen_nul_retval=yes],
          [gl_cv_func_mbrlen_nul_retval=no],
          [])
      fi
    ])
])

# Prerequisites of lib/mbrlen.c.
AC_DEFUN([gl_PREREQ_MBRLEN], [
  :
])

# serial 15
dnl Copyright (C) 2002-2003, 2005-2007, 2009-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Jim Meyering.

# Redefine AC_FUNC_MKTIME, to fix a bug in Autoconf 2.61a and earlier.
# This redefinition can be removed once a new version of Autoconf is assumed.
# The redefinition is taken from
# <http://cvs.sv.gnu.org/viewcvs/*checkout*/autoconf/autoconf/lib/autoconf/functions.m4?rev=1.119>.
# AC_FUNC_MKTIME
# --------------
AC_DEFUN([AC_FUNC_MKTIME],
[AC_CHECK_HEADERS_ONCE([unistd.h])
AC_CHECK_FUNCS_ONCE([alarm])
AC_REQUIRE([gl_MULTIARCH])
if test $APPLE_UNIVERSAL_BUILD = 1; then
  # A universal build on Apple MacOS X platforms.
  # The test result would be 'yes' in 32-bit mode and 'no' in 64-bit mode.
  # But we need a configuration result that is valid in both modes.
  ac_cv_func_working_mktime=no
fi
AC_CACHE_CHECK([for working mktime], [ac_cv_func_working_mktime],
[AC_RUN_IFELSE([AC_LANG_SOURCE(
[[/* Test program from Paul Eggert and Tony Leneis.  */
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifndef HAVE_ALARM
# define alarm(X) /* empty */
#endif

/* Work around redefinition to rpl_putenv by other config tests.  */
#undef putenv

static time_t time_t_max;
static time_t time_t_min;

/* Values we'll use to set the TZ environment variable.  */
static char *tz_strings[] = {
  (char *) 0, "TZ=GMT0", "TZ=JST-9",
  "TZ=EST+3EDT+2,M10.1.0/00:00:00,M2.3.0/00:00:00"
};
#define N_STRINGS (sizeof (tz_strings) / sizeof (tz_strings[0]))

/* Return 0 if mktime fails to convert a date in the spring-forward gap.
   Based on a problem report from Andreas Jaeger.  */
static int
spring_forward_gap ()
{
  /* glibc (up to about 1998-10-07) failed this test. */
  struct tm tm;

  /* Use the portable POSIX.1 specification "TZ=PST8PDT,M4.1.0,M10.5.0"
     instead of "TZ=America/Vancouver" in order to detect the bug even
     on systems that don't support the Olson extension, or don't have the
     full zoneinfo tables installed.  */
  putenv ("TZ=PST8PDT,M4.1.0,M10.5.0");

  tm.tm_year = 98;
  tm.tm_mon = 3;
  tm.tm_mday = 5;
  tm.tm_hour = 2;
  tm.tm_min = 0;
  tm.tm_sec = 0;
  tm.tm_isdst = -1;
  return mktime (&tm) != (time_t) -1;
}

static int
mktime_test1 (time_t now)
{
  struct tm *lt;
  return ! (lt = localtime (&now)) || mktime (lt) == now;
}

static int
mktime_test (time_t now)
{
  return (mktime_test1 (now)
          && mktime_test1 ((time_t) (time_t_max - now))
          && mktime_test1 ((time_t) (time_t_min + now)));
}

static int
irix_6_4_bug ()
{
  /* Based on code from Ariel Faigon.  */
  struct tm tm;
  tm.tm_year = 96;
  tm.tm_mon = 3;
  tm.tm_mday = 0;
  tm.tm_hour = 0;
  tm.tm_min = 0;
  tm.tm_sec = 0;
  tm.tm_isdst = -1;
  mktime (&tm);
  return tm.tm_mon == 2 && tm.tm_mday == 31;
}

static int
bigtime_test (int j)
{
  struct tm tm;
  time_t now;
  tm.tm_year = tm.tm_mon = tm.tm_mday = tm.tm_hour = tm.tm_min = tm.tm_sec = j;
  now = mktime (&tm);
  if (now != (time_t) -1)
    {
      struct tm *lt = localtime (&now);
      if (! (lt
             && lt->tm_year == tm.tm_year
             && lt->tm_mon == tm.tm_mon
             && lt->tm_mday == tm.tm_mday
             && lt->tm_hour == tm.tm_hour
             && lt->tm_min == tm.tm_min
             && lt->tm_sec == tm.tm_sec
             && lt->tm_yday == tm.tm_yday
             && lt->tm_wday == tm.tm_wday
             && ((lt->tm_isdst < 0 ? -1 : 0 < lt->tm_isdst)
                  == (tm.tm_isdst < 0 ? -1 : 0 < tm.tm_isdst))))
        return 0;
    }
  return 1;
}

static int
year_2050_test ()
{
  /* The correct answer for 2050-02-01 00:00:00 in Pacific time,
     ignoring leap seconds.  */
  unsigned long int answer = 2527315200UL;

  struct tm tm;
  time_t t;
  tm.tm_year = 2050 - 1900;
  tm.tm_mon = 2 - 1;
  tm.tm_mday = 1;
  tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
  tm.tm_isdst = -1;

  /* Use the portable POSIX.1 specification "TZ=PST8PDT,M4.1.0,M10.5.0"
     instead of "TZ=America/Vancouver" in order to detect the bug even
     on systems that don't support the Olson extension, or don't have the
     full zoneinfo tables installed.  */
  putenv ("TZ=PST8PDT,M4.1.0,M10.5.0");

  t = mktime (&tm);

  /* Check that the result is either a failure, or close enough
     to the correct answer that we can assume the discrepancy is
     due to leap seconds.  */
  return (t == (time_t) -1
          || (0 < t && answer - 120 <= t && t <= answer + 120));
}

int
main ()
{
  time_t t, delta;
  int i, j;

  /* This test makes some buggy mktime implementations loop.
     Give up after 60 seconds; a mktime slower than that
     isn't worth using anyway.  */
  alarm (60);

  for (;;)
    {
      t = (time_t_max << 1) + 1;
      if (t <= time_t_max)
        break;
      time_t_max = t;
    }
  time_t_min = - ((time_t) ~ (time_t) 0 == (time_t) -1) - time_t_max;

  delta = time_t_max / 997; /* a suitable prime number */
  for (i = 0; i < N_STRINGS; i++)
    {
      if (tz_strings[i])
        putenv (tz_strings[i]);

      for (t = 0; t <= time_t_max - delta; t += delta)
        if (! mktime_test (t))
          return 1;
      if (! (mktime_test ((time_t) 1)
             && mktime_test ((time_t) (60 * 60))
             && mktime_test ((time_t) (60 * 60 * 24))))
        return 1;

      for (j = 1; ; j <<= 1)
        if (! bigtime_test (j))
          return 1;
        else if (INT_MAX / 2 < j)
          break;
      if (! bigtime_test (INT_MAX))
        return 1;
    }
  return ! (irix_6_4_bug () && spring_forward_gap () && year_2050_test ());
}]])],
               [ac_cv_func_working_mktime=yes],
               [ac_cv_func_working_mktime=no],
               [ac_cv_func_working_mktime=no])])
if test $ac_cv_func_working_mktime = no; then
  AC_LIBOBJ([mktime])
fi
])# AC_FUNC_MKTIME

AC_DEFUN([gl_FUNC_MKTIME],
[
  AC_REQUIRE([gl_HEADER_TIME_H_DEFAULTS])
  AC_FUNC_MKTIME
  dnl Note: AC_FUNC_MKTIME does AC_LIBOBJ([mktime]).
  if test $ac_cv_func_working_mktime = no; then
    REPLACE_MKTIME=1
    gl_PREREQ_MKTIME
  else
    REPLACE_MKTIME=0
  fi
])

# Prerequisites of lib/mktime.c.
AC_DEFUN([gl_PREREQ_MKTIME],
[
  AC_REQUIRE([AC_C_INLINE])
])

# sockets.m4 serial 6
dnl Copyright (C) 2008, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_SOCKETS],
[
  AC_REQUIRE([AC_C_INLINE])

  gl_PREREQ_SYS_H_WINSOCK2 dnl for HAVE_WINSOCK2_H
  LIBSOCKET=
  if test $HAVE_WINSOCK2_H = 1; then
    dnl Native Windows API (not Cygwin).
    AC_CACHE_CHECK([if we need to call WSAStartup in winsock2.h and -lws2_32],
                   [gl_cv_func_wsastartup], [
      gl_save_LIBS="$LIBS"
      LIBS="$LIBS -lws2_32"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#ifdef HAVE_WINSOCK2_H
# include <winsock2.h>
#endif]], [[
          WORD wVersionRequested = MAKEWORD(1, 1);
          WSADATA wsaData;
          int err = WSAStartup(wVersionRequested, &wsaData);
          WSACleanup ();]])],
        gl_cv_func_wsastartup=yes, gl_cv_func_wsastartup=no)
      LIBS="$gl_save_LIBS"
    ])
    if test "$gl_cv_func_wsastartup" = "yes"; then
      AC_DEFINE([WINDOWS_SOCKETS], [1], [Define if WSAStartup is needed.])
      LIBSOCKET='-lws2_32'
    fi
  else
    dnl Unix API.
    dnl Solaris has most socket functions in libsocket.
    dnl Haiku has most socket functions in libnetwork.
    dnl BeOS has most socket functions in libnet.
    AC_CACHE_CHECK([for library containing setsockopt], [gl_cv_lib_socket], [
      gl_cv_lib_socket=
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[extern
#ifdef __cplusplus
"C"
#endif
char setsockopt();]], [[setsockopt();]])],
        [],
        [gl_save_LIBS="$LIBS"
         LIBS="$gl_save_LIBS -lsocket"
         AC_LINK_IFELSE([AC_LANG_PROGRAM([[extern
#ifdef __cplusplus
"C"
#endif
char setsockopt();]], [[setsockopt();]])],
           [gl_cv_lib_socket="-lsocket"])
         if test -z "$gl_cv_lib_socket"; then
           LIBS="$gl_save_LIBS -lnetwork"
           AC_LINK_IFELSE([AC_LANG_PROGRAM([[extern
#ifdef __cplusplus
"C"
#endif
char setsockopt();]], [[setsockopt();]])],
             [gl_cv_lib_socket="-lnetwork"])
           if test -z "$gl_cv_lib_socket"; then
             LIBS="$gl_save_LIBS -lnet"
             AC_LINK_IFELSE([AC_LANG_PROGRAM([[extern
#ifdef __cplusplus
"C"
#endif
char setsockopt();]], [[setsockopt();]])],
               [gl_cv_lib_socket="-lnet"])
           fi
         fi
         LIBS="$gl_save_LIBS"
        ])
      if test -z "$gl_cv_lib_socket"; then
        gl_cv_lib_socket="none needed"
      fi
    ])
    if test "$gl_cv_lib_socket" != "none needed"; then
      LIBSOCKET="$gl_cv_lib_socket"
    fi
  fi
  AC_SUBST([LIBSOCKET])
  gl_PREREQ_SOCKETS
])

# Prerequisites of lib/sockets.c.
AC_DEFUN([gl_PREREQ_SOCKETS], [
  :
])

# strcase.m4 serial 10
dnl Copyright (C) 2002, 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_STRCASE],
[
  gl_FUNC_STRCASECMP
  gl_FUNC_STRNCASECMP
])

AC_DEFUN([gl_FUNC_STRCASECMP],
[
  AC_REQUIRE([gl_HEADER_STRINGS_H_DEFAULTS])
  AC_REPLACE_FUNCS([strcasecmp])
  if test $ac_cv_func_strcasecmp = no; then
    HAVE_STRCASECMP=0
    gl_PREREQ_STRCASECMP
  fi
])

AC_DEFUN([gl_FUNC_STRNCASECMP],
[
  AC_REQUIRE([gl_HEADER_STRINGS_H_DEFAULTS])
  AC_REPLACE_FUNCS([strncasecmp])
  if test $ac_cv_func_strncasecmp = no; then
    gl_PREREQ_STRNCASECMP
  fi
  AC_CHECK_DECLS([strncasecmp])
  if test $ac_cv_have_decl_strncasecmp = no; then
    HAVE_DECL_STRNCASECMP=0
  fi
])

# Prerequisites of lib/strcasecmp.c.
AC_DEFUN([gl_PREREQ_STRCASECMP], [
  :
])

# Prerequisites of lib/strncasecmp.c.
AC_DEFUN([gl_PREREQ_STRNCASECMP], [
  :
])

# serial 32

# Copyright (C) 1996-1997, 1999-2007, 2009-2010 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# Written by Jim Meyering and Paul Eggert.

AC_DEFUN([gl_FUNC_GNU_STRFTIME],
[
  gl_FUNC_STRFTIME
])

# These are the prerequisite macros for GNU's strftime.c replacement.
AC_DEFUN([gl_FUNC_STRFTIME],
[
 AC_LIBOBJ([strftime])

 # This defines (or not) HAVE_TZNAME and HAVE_TM_ZONE.
 AC_REQUIRE([AC_STRUCT_TIMEZONE])

 AC_REQUIRE([AC_TYPE_MBSTATE_T])
 AC_REQUIRE([gl_TM_GMTOFF])

 AC_CHECK_FUNCS_ONCE([tzset])
 AC_CHECK_HEADERS_ONCE([wchar.h])

 AC_DEFINE([my_strftime], [nstrftime],
   [Define to the name of the strftime replacement function.])
])

# Configure a replacement for <string.h>.
# serial 3

# Copyright (C) 2007, 2009-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_HEADER_STRINGS_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_HEADER_STRINGS_H_BODY])
])

AC_DEFUN([gl_HEADER_STRINGS_H_BODY],
[
  AC_REQUIRE([gl_HEADER_STRINGS_H_DEFAULTS])
  gl_CHECK_NEXT_HEADERS([strings.h])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[#include <strings.h>
    ]], [strcasecmp strncasecmp])
])

AC_DEFUN([gl_STRINGS_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_HEADER_STRINGS_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
])

AC_DEFUN([gl_HEADER_STRINGS_H_DEFAULTS],
[
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_STRCASECMP=1;       AC_SUBST([HAVE_STRCASECMP])
  HAVE_DECL_STRNCASECMP=1; AC_SUBST([HAVE_DECL_STRNCASECMP])
])

# strptime.m4 serial 6
dnl Copyright (C) 2007, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_STRPTIME],
[
  AC_REQUIRE([gl_HEADER_TIME_H_DEFAULTS])
  AC_REQUIRE([AC_C_RESTRICT])
  AC_CHECK_FUNCS_ONCE([strptime])
  if test $ac_cv_func_strptime != yes; then
    HAVE_STRPTIME=0
    AC_LIBOBJ([strptime])
    gl_PREREQ_STRPTIME
  fi
])

# Prerequisites of lib/strptime.c.
AC_DEFUN([gl_PREREQ_STRPTIME],
[
  AC_REQUIRE([gl_TM_GMTOFF])
  :
])

# strverscmp.m4 serial 7
dnl Copyright (C) 2002, 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_STRVERSCMP],
[
  dnl Persuade glibc <string.h> to declare strverscmp().
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])

  AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
  AC_REPLACE_FUNCS([strverscmp])
  if test $ac_cv_func_strverscmp = no; then
    gl_PREREQ_STRVERSCMP
    HAVE_STRVERSCMP=0
  fi
])

# Prerequisites of lib/strverscmp.c.
AC_DEFUN([gl_PREREQ_STRVERSCMP], [
  :
])

# sys_socket_h.m4 serial 17
dnl Copyright (C) 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Simon Josefsson.

AC_DEFUN([gl_HEADER_SYS_SOCKET],
[
  AC_REQUIRE([gl_SYS_SOCKET_H_DEFAULTS])
  AC_REQUIRE([AC_C_INLINE])

  AC_CACHE_CHECK([whether <sys/socket.h> is self-contained],
    [gl_cv_header_sys_socket_h_selfcontained],
    [
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/socket.h>]], [[]])],
        [gl_cv_header_sys_socket_h_selfcontained=yes],
        [gl_cv_header_sys_socket_h_selfcontained=no])
    ])
  if test $gl_cv_header_sys_socket_h_selfcontained = yes; then
    dnl If the shutdown function exists, <sys/socket.h> should define
    dnl SHUT_RD, SHUT_WR, SHUT_RDWR.
    AC_CHECK_FUNCS([shutdown])
    if test $ac_cv_func_shutdown = yes; then
      AC_CACHE_CHECK([whether <sys/socket.h> defines the SHUT_* macros],
        [gl_cv_header_sys_socket_h_shut],
        [
          AC_COMPILE_IFELSE(
            [AC_LANG_PROGRAM([[#include <sys/socket.h>]],
               [[int a[] = { SHUT_RD, SHUT_WR, SHUT_RDWR };]])],
            [gl_cv_header_sys_socket_h_shut=yes],
            [gl_cv_header_sys_socket_h_shut=no])
        ])
      if test $gl_cv_header_sys_socket_h_shut = no; then
        SYS_SOCKET_H='sys/socket.h'
      fi
    fi
  fi
  # We need to check for ws2tcpip.h now.
  gl_PREREQ_SYS_H_SOCKET
  AC_CHECK_TYPES([struct sockaddr_storage, sa_family_t],,,[
  /* sys/types.h is not needed according to POSIX, but the
     sys/socket.h in i386-unknown-freebsd4.10 and
     powerpc-apple-darwin5.5 required it. */
#include <sys/types.h>
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_WS2TCPIP_H
#include <ws2tcpip.h>
#endif
])
  if test $ac_cv_type_struct_sockaddr_storage = no; then
    HAVE_STRUCT_SOCKADDR_STORAGE=0
  fi
  if test $ac_cv_type_sa_family_t = no; then
    HAVE_SA_FAMILY_T=0
  fi
  gl_PREREQ_SYS_H_WINSOCK2

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[
/* Some systems require prerequisite headers.  */
#include <sys/types.h>
#if !defined __GLIBC__ && HAVE_SYS_TIME_H
# include <sys/time.h>
#endif
#include <sys/select.h>
    ]], [socket connect accept bind getpeername getsockname getsockopt
    listen recv send recvfrom sendto setsockopt shutdown accept4])
])

AC_DEFUN([gl_PREREQ_SYS_H_SOCKET],
[
  dnl Check prerequisites of the <sys/socket.h> replacement.
  gl_CHECK_NEXT_HEADERS([sys/socket.h])
  if test $ac_cv_header_sys_socket_h = yes; then
    HAVE_SYS_SOCKET_H=1
    HAVE_WS2TCPIP_H=0
  else
    HAVE_SYS_SOCKET_H=0
    dnl We cannot use AC_CHECK_HEADERS_ONCE here, because that would make
    dnl the check for those headers unconditional; yet cygwin reports
    dnl that the headers are present but cannot be compiled (since on
    dnl cygwin, all socket information should come from sys/socket.h).
    AC_CHECK_HEADERS([ws2tcpip.h])
    if test $ac_cv_header_ws2tcpip_h = yes; then
      HAVE_WS2TCPIP_H=1
    else
      HAVE_WS2TCPIP_H=0
    fi
  fi
  AC_SUBST([HAVE_SYS_SOCKET_H])
  AC_SUBST([HAVE_WS2TCPIP_H])
])

# Common prerequisites of the <sys/socket.h> replacement and of the
# <sys/select.h> replacement.
# Sets and substitutes HAVE_WINSOCK2_H.
AC_DEFUN([gl_PREREQ_SYS_H_WINSOCK2],
[
  m4_ifdef([gl_UNISTD_H_DEFAULTS], [AC_REQUIRE([gl_UNISTD_H_DEFAULTS])])
  m4_ifdef([gl_SYS_IOCTL_H_DEFAULTS], [AC_REQUIRE([gl_SYS_IOCTL_H_DEFAULTS])])
  AC_CHECK_HEADERS_ONCE([sys/socket.h])
  if test $ac_cv_header_sys_socket_h != yes; then
    dnl We cannot use AC_CHECK_HEADERS_ONCE here, because that would make
    dnl the check for those headers unconditional; yet cygwin reports
    dnl that the headers are present but cannot be compiled (since on
    dnl cygwin, all socket information should come from sys/socket.h).
    AC_CHECK_HEADERS([winsock2.h])
  fi
  if test "$ac_cv_header_winsock2_h" = yes; then
    HAVE_WINSOCK2_H=1
    UNISTD_H_HAVE_WINSOCK2_H=1
    SYS_IOCTL_H_HAVE_WINSOCK2_H=1
  else
    HAVE_WINSOCK2_H=0
  fi
  AC_SUBST([HAVE_WINSOCK2_H])
])

AC_DEFUN([gl_SYS_SOCKET_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_SYS_SOCKET_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_SYS_SOCKET_H_DEFAULTS],
[
  GNULIB_SOCKET=0;      AC_SUBST([GNULIB_SOCKET])
  GNULIB_CONNECT=0;     AC_SUBST([GNULIB_CONNECT])
  GNULIB_ACCEPT=0;      AC_SUBST([GNULIB_ACCEPT])
  GNULIB_BIND=0;        AC_SUBST([GNULIB_BIND])
  GNULIB_GETPEERNAME=0; AC_SUBST([GNULIB_GETPEERNAME])
  GNULIB_GETSOCKNAME=0; AC_SUBST([GNULIB_GETSOCKNAME])
  GNULIB_GETSOCKOPT=0;  AC_SUBST([GNULIB_GETSOCKOPT])
  GNULIB_LISTEN=0;      AC_SUBST([GNULIB_LISTEN])
  GNULIB_RECV=0;        AC_SUBST([GNULIB_RECV])
  GNULIB_SEND=0;        AC_SUBST([GNULIB_SEND])
  GNULIB_RECVFROM=0;    AC_SUBST([GNULIB_RECVFROM])
  GNULIB_SENDTO=0;      AC_SUBST([GNULIB_SENDTO])
  GNULIB_SETSOCKOPT=0;  AC_SUBST([GNULIB_SETSOCKOPT])
  GNULIB_SHUTDOWN=0;    AC_SUBST([GNULIB_SHUTDOWN])
  GNULIB_ACCEPT4=0;     AC_SUBST([GNULIB_ACCEPT4])
  HAVE_STRUCT_SOCKADDR_STORAGE=1; AC_SUBST([HAVE_STRUCT_SOCKADDR_STORAGE])
  HAVE_SA_FAMILY_T=1;   AC_SUBST([HAVE_SA_FAMILY_T])
  HAVE_ACCEPT4=1;       AC_SUBST([HAVE_ACCEPT4])
])

# sys_utsname_h.m4 serial 6
dnl Copyright (C) 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Bruno Haible.

AC_DEFUN([gl_SYS_UTSNAME_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_SYS_UTSNAME_H_DEFAULTS])

  dnl <sys/utsname.h> is always overridden, because of GNULIB_POSIXCHECK.
  gl_CHECK_NEXT_HEADERS([sys/utsname.h])
  AC_CHECK_HEADERS_ONCE([sys/utsname.h])
  if test $ac_cv_header_sys_utsname_h != yes; then
    HAVE_SYS_UTSNAME_H=0
    HAVE_STRUCT_UTSNAME=0
  else
    HAVE_SYS_UTSNAME_H=1
    AC_CHECK_TYPES([struct utsname], [], [HAVE_STRUCT_UTSNAME=0], [[
#include <sys/utsname.h>
      ]])
  fi
  AC_SUBST([HAVE_SYS_UTSNAME_H])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[#include <sys/utsname.h>
    ]], [uname])
])

AC_DEFUN([gl_SYS_UTSNAME_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_SYS_UTSNAME_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
])

AC_DEFUN([gl_SYS_UTSNAME_H_DEFAULTS],
[
  GNULIB_UNAME=0;         AC_SUBST([GNULIB_UNAME])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_UNAME=1;           AC_SUBST([HAVE_UNAME])
  HAVE_STRUCT_UTSNAME=1;  AC_SUBST([HAVE_STRUCT_UTSNAME])
])

# Configure a more-standard replacement for <time.h>.

# Copyright (C) 2000-2001, 2003-2007, 2009-2010 Free Software Foundation, Inc.

# serial 2

# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# Written by Paul Eggert and Jim Meyering.

AC_DEFUN([gl_HEADER_TIME_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_HEADER_TIME_H_BODY])
])

AC_DEFUN([gl_HEADER_TIME_H_BODY],
[
  AC_REQUIRE([AC_C_RESTRICT])
  AC_REQUIRE([gl_HEADER_TIME_H_DEFAULTS])
  gl_CHECK_NEXT_HEADERS([time.h])
  AC_REQUIRE([gl_CHECK_TYPE_STRUCT_TIMESPEC])
])

dnl Define HAVE_STRUCT_TIMESPEC if `struct timespec' is declared
dnl in time.h, sys/time.h, or pthread.h.

AC_DEFUN([gl_CHECK_TYPE_STRUCT_TIMESPEC],
[
  AC_CHECK_HEADERS_ONCE([sys/time.h])
  AC_CACHE_CHECK([for struct timespec in <time.h>],
    [gl_cv_sys_struct_timespec_in_time_h],
    [AC_COMPILE_IFELSE(
       [AC_LANG_PROGRAM(
          [[#include <time.h>
          ]],
          [[static struct timespec x; x.tv_sec = x.tv_nsec;]])],
       [gl_cv_sys_struct_timespec_in_time_h=yes],
       [gl_cv_sys_struct_timespec_in_time_h=no])])

  TIME_H_DEFINES_STRUCT_TIMESPEC=0
  SYS_TIME_H_DEFINES_STRUCT_TIMESPEC=0
  PTHREAD_H_DEFINES_STRUCT_TIMESPEC=0
  if test $gl_cv_sys_struct_timespec_in_time_h = yes; then
    TIME_H_DEFINES_STRUCT_TIMESPEC=1
  else
    AC_CACHE_CHECK([for struct timespec in <sys/time.h>],
      [gl_cv_sys_struct_timespec_in_sys_time_h],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM(
            [[#include <sys/time.h>
            ]],
            [[static struct timespec x; x.tv_sec = x.tv_nsec;]])],
         [gl_cv_sys_struct_timespec_in_sys_time_h=yes],
         [gl_cv_sys_struct_timespec_in_sys_time_h=no])])
    if test $gl_cv_sys_struct_timespec_in_sys_time_h = yes; then
      SYS_TIME_H_DEFINES_STRUCT_TIMESPEC=1
    else
      AC_CACHE_CHECK([for struct timespec in <pthread.h>],
        [gl_cv_sys_struct_timespec_in_pthread_h],
        [AC_COMPILE_IFELSE(
           [AC_LANG_PROGRAM(
              [[#include <pthread.h>
              ]],
              [[static struct timespec x; x.tv_sec = x.tv_nsec;]])],
           [gl_cv_sys_struct_timespec_in_pthread_h=yes],
           [gl_cv_sys_struct_timespec_in_pthread_h=no])])
      if test $gl_cv_sys_struct_timespec_in_pthread_h = yes; then
        PTHREAD_H_DEFINES_STRUCT_TIMESPEC=1
      fi
    fi
  fi
  AC_SUBST([TIME_H_DEFINES_STRUCT_TIMESPEC])
  AC_SUBST([SYS_TIME_H_DEFINES_STRUCT_TIMESPEC])
  AC_SUBST([PTHREAD_H_DEFINES_STRUCT_TIMESPEC])
])

AC_DEFUN([gl_TIME_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_HEADER_TIME_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_HEADER_TIME_H_DEFAULTS],
[
  GNULIB_MKTIME=0;                       AC_SUBST([GNULIB_MKTIME])
  GNULIB_NANOSLEEP=0;                    AC_SUBST([GNULIB_NANOSLEEP])
  GNULIB_STRPTIME=0;                     AC_SUBST([GNULIB_STRPTIME])
  GNULIB_TIMEGM=0;                       AC_SUBST([GNULIB_TIMEGM])
  GNULIB_TIME_R=0;                       AC_SUBST([GNULIB_TIME_R])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_LOCALTIME_R=1;                    AC_SUBST([HAVE_LOCALTIME_R])
  HAVE_NANOSLEEP=1;                      AC_SUBST([HAVE_NANOSLEEP])
  HAVE_STRPTIME=1;                       AC_SUBST([HAVE_STRPTIME])
  HAVE_TIMEGM=1;                         AC_SUBST([HAVE_TIMEGM])
  dnl If another module says to replace or to not replace, do that.
  dnl Otherwise, replace only if someone compiles with -DGNULIB_PORTCHECK;
  dnl this lets maintainers check for portability.
  REPLACE_LOCALTIME_R=GNULIB_PORTCHECK;  AC_SUBST([REPLACE_LOCALTIME_R])
  REPLACE_MKTIME=GNULIB_PORTCHECK;       AC_SUBST([REPLACE_MKTIME])
  REPLACE_NANOSLEEP=GNULIB_PORTCHECK;    AC_SUBST([REPLACE_NANOSLEEP])
  REPLACE_TIMEGM=GNULIB_PORTCHECK;       AC_SUBST([REPLACE_TIMEGM])
])

dnl Reentrant time functions: localtime_r, gmtime_r.

dnl Copyright (C) 2003, 2006-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Paul Eggert.

AC_DEFUN([gl_TIME_R],
[
  dnl Persuade glibc and Solaris <time.h> to declare localtime_r.
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])

  AC_REQUIRE([gl_HEADER_TIME_H_DEFAULTS])
  AC_REQUIRE([AC_C_RESTRICT])

  AC_CHECK_FUNCS_ONCE([localtime_r])
  if test $ac_cv_func_localtime_r = yes; then
    AC_CACHE_CHECK([whether localtime_r is compatible with its POSIX signature],
      [gl_cv_time_r_posix],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM(
            [[#include <time.h>]],
            [[/* We don't need to append 'restrict's to the argument types,
                 even though the POSIX signature has the 'restrict's,
                 since C99 says they can't affect type compatibility.  */
              struct tm * (*ptr) (time_t const *, struct tm *) = localtime_r;
              if (ptr) return 0;
              /* Check the return type is a pointer.
                 On HP-UX 10 it is 'int'.  */
              *localtime_r (0, 0);]])
         ],
         [gl_cv_time_r_posix=yes],
         [gl_cv_time_r_posix=no])
      ])
    if test $gl_cv_time_r_posix = yes; then
      REPLACE_LOCALTIME_R=0
    else
      REPLACE_LOCALTIME_R=1
    fi
  else
    HAVE_LOCALTIME_R=0
  fi
  if test $HAVE_LOCALTIME_R = 0 || test $REPLACE_LOCALTIME_R = 1; then
    AC_LIBOBJ([time_r])
    gl_PREREQ_TIME_R
  fi
])

# Prerequisites of lib/time_r.c.
AC_DEFUN([gl_PREREQ_TIME_R], [
  :
])

# tm_gmtoff.m4 serial 3
dnl Copyright (C) 2002, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_TM_GMTOFF],
[
 AC_CHECK_MEMBER([struct tm.tm_gmtoff],
                 [AC_DEFINE([HAVE_TM_GMTOFF], [1],
                            [Define if struct tm has the tm_gmtoff member.])],
                 ,
                 [#include <time.h>])
])

# uname.m4 serial 10
dnl Copyright (C) 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_UNAME],
[
  AC_REQUIRE([gl_SYS_UTSNAME_H_DEFAULTS])
  AC_REPLACE_FUNCS([uname])
  if test $ac_cv_func_uname = no; then
    HAVE_UNAME=0
    gl_PREREQ_UNAME
  fi
])

# Prerequisites of lib/uname.c.
AC_DEFUN([gl_PREREQ_UNAME], [
  :
])

# btowc.m4 serial 6
dnl Copyright (C) 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_BTOWC],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  dnl Check whether <wchar.h> is usable at all, first. Otherwise the test
  dnl program below may lead to an endless loop. See
  dnl <http://gcc.gnu.org/bugzilla/show_bug.cgi?id=42440>.
  AC_REQUIRE([gl_WCHAR_H_INLINE_OK])

  AC_CHECK_FUNCS_ONCE([btowc])
  if test $ac_cv_func_btowc = no; then
    HAVE_BTOWC=0
  else

    AC_REQUIRE([AC_PROG_CC])
    AC_REQUIRE([gt_LOCALE_FR])
    AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles

    dnl Cygwin 1.7.2 btowc('\0') is WEOF, not 0.
    AC_CACHE_CHECK([whether btowc(0) is correct],
      [gl_cv_func_btowc_nul],
      [
        AC_TRY_RUN([
#include <stdio.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (btowc ('\0') != 0)
    return 1;
  return 0;
}],
          [gl_cv_func_btowc_nul=yes],
          [gl_cv_func_btowc_nul=no],
          [
changequote(,)dnl
           case "$host_os" in
                      # Guess no on Cygwin.
             cygwin*) gl_cv_func_btowc_nul="guessing no" ;;
                      # Guess yes otherwise.
             *)       gl_cv_func_btowc_nul="guessing yes" ;;
           esac
changequote([,])dnl
          ])
      ])

    dnl IRIX 6.5 btowc(EOF) is 0xFF, not WEOF.
    AC_CACHE_CHECK([whether btowc(EOF) is correct],
      [gl_cv_func_btowc_eof],
      [
        dnl Initial guess, used when cross-compiling or when no suitable locale
        dnl is present.
changequote(,)dnl
        case "$host_os" in
                 # Guess no on IRIX.
          irix*) gl_cv_func_btowc_eof="guessing no" ;;
                 # Guess yes otherwise.
          *)     gl_cv_func_btowc_eof="guessing yes" ;;
        esac
changequote([,])dnl
        if test $LOCALE_FR != none; then
          AC_TRY_RUN([
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (setlocale (LC_ALL, "$LOCALE_FR") != NULL)
    {
      if (btowc (EOF) != WEOF)
        return 1;
    }
  return 0;
}],
            [gl_cv_func_btowc_eof=yes],
            [gl_cv_func_btowc_eof=no],
            [:])
        fi
      ])

    case "$gl_cv_func_btowc_nul" in
      *yes) ;;
      *) REPLACE_BTOWC=1 ;;
    esac
    case "$gl_cv_func_btowc_eof" in
      *yes) ;;
      *) REPLACE_BTOWC=1 ;;
    esac
  fi
  if test $HAVE_BTOWC = 0 || test $REPLACE_BTOWC = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([btowc])
    gl_PREREQ_BTOWC
  fi
])

# Prerequisites of lib/btowc.c.
AC_DEFUN([gl_PREREQ_BTOWC], [
  :
])

# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2010 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([rx_gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  # Code from module arg-nonnull:
  # Code from module btowc:
  # Code from module c++defs:
  # Code from module gettext-h:
  # Code from module malloc:
  # Code from module malloc-posix:
  # Code from module regex:
  # Code from module ssize_t:
  # Code from module stddef:
  # Code from module stdlib:
  # Code from module unistd:
  # Code from module warn-on-use:
  # Code from module wcrtomb:
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([rx_gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  gl_m4_base='modules/regexp/glm4'
  m4_pushdef([AC_LIBOBJ], m4_defn([rx_gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([rx_gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([rx_gl_LIBSOURCES]))
  m4_pushdef([rx_gl_LIBSOURCES_LIST], [])
  m4_pushdef([rx_gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='modules/regexp/gllib'
  # Code from module arg-nonnull:
  # Code from module btowc:
  gl_FUNC_BTOWC
  gl_WCHAR_MODULE_INDICATOR([btowc])
  # Code from module c++defs:
  # Code from module gettext-h:
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  # Code from module malloc:
  AC_FUNC_MALLOC
  AC_DEFINE([GNULIB_MALLOC_GNU], 1, [Define to indicate the 'malloc' module.])
  # Code from module malloc-posix:
  gl_FUNC_MALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([malloc-posix])
  # Code from module regex:
  gl_REGEX
  # Code from module ssize_t:
  gt_TYPE_SSIZE_T
  # Code from module stddef:
  gl_STDDEF_H
  # Code from module stdlib:
  gl_STDLIB_H
  # Code from module unistd:
  gl_UNISTD_H
  # Code from module warn-on-use:
  # Code from module wcrtomb:
  gl_FUNC_WCRTOMB
  gl_WCHAR_MODULE_INDICATOR([wcrtomb])
  # Code from module dummy:
  # End of code from modules
  m4_ifval(rx_gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([rx_gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]rx_gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([rx_gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([rx_gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([rx_gl_LIBSOURCES_DIR])
  m4_popdef([rx_gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    rx_gl_libobjs=
    rx_gl_ltlibobjs=
    if test -n "$rx_gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $rx_gl_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        rx_gl_libobjs="$rx_gl_libobjs $i.$ac_objext"
        rx_gl_ltlibobjs="$rx_gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([rx_gl_LIBOBJS], [$rx_gl_libobjs])
    AC_SUBST([rx_gl_LTLIBOBJS], [$rx_gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([rx_gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([rx_gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([rx_gltests_LIBSOURCES]))
  m4_pushdef([rx_gltests_LIBSOURCES_LIST], [])
  m4_pushdef([rx_gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
changequote(,)dnl
  rx_gltests_WITNESS=IN_`echo "${PACKAGE-$PACKAGE_TARNAME}" | LC_ALL=C tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ | LC_ALL=C sed -e 's/[^A-Z0-9_]/_/g'`_GNULIB_TESTS
changequote([, ])dnl
  AC_SUBST([rx_gltests_WITNESS])
  gl_module_indicator_condition=$rx_gltests_WITNESS
  m4_pushdef([gl_MODULE_INDICATOR_CONDITION], [$gl_module_indicator_condition])
  m4_popdef([gl_MODULE_INDICATOR_CONDITION])
  m4_ifval(rx_gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([rx_gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]rx_gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([rx_gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([rx_gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([rx_gltests_LIBSOURCES_DIR])
  m4_popdef([rx_gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    rx_gltests_libobjs=
    rx_gltests_ltlibobjs=
    if test -n "$rx_gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $rx_gltests_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        rx_gltests_libobjs="$rx_gltests_libobjs $i.$ac_objext"
        rx_gltests_ltlibobjs="$rx_gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([rx_gltests_LIBOBJS], [$rx_gltests_libobjs])
    AC_SUBST([rx_gltests_LTLIBOBJS], [$rx_gltests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into rx_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([rx_gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [rx_gl_LIBSOURCES([$1.c])])dnl
  rx_gl_LIBOBJS="$rx_gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into rx_gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([rx_gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [rx_gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([rx_gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([rx_gl_LIBSOURCES_DIR], [modules/regexp/gllib])
      m4_append([rx_gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into rx_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([rx_gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [rx_gltests_LIBSOURCES([$1.c])])dnl
  rx_gltests_LIBOBJS="$rx_gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into rx_gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([rx_gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [rx_gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([rx_gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([rx_gltests_LIBSOURCES_DIR], [tests])
      m4_append([rx_gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([rx_gl_FILE_LIST], [
  build-aux/arg-nonnull.h
  build-aux/c++defs.h
  build-aux/warn-on-use.h
  lib/btowc.c
  lib/dummy.c
  lib/gettext.h
  lib/malloc.c
  lib/regcomp.c
  lib/regex.c
  lib/regex.h
  lib/regex_internal.c
  lib/regex_internal.h
  lib/regexec.c
  lib/stddef.in.h
  lib/stdlib.in.h
  lib/unistd.in.h
  lib/wcrtomb.c
  m4/00gnulib.m4
  m4/btowc.m4
  m4/codeset.m4
  m4/gnulib-common.m4
  m4/locale-fr.m4
  m4/locale-ja.m4
  m4/locale-zh.m4
  m4/malloc.m4
  m4/mbrtowc.m4
  m4/mbstate_t.m4
  m4/regex.m4
  m4/ssize_t.m4
  m4/stddef_h.m4
  m4/stdlib_h.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wchar_t.m4
  m4/wcrtomb.m4
])

# malloc.m4 serial 9
dnl Copyright (C) 2007, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# gl_FUNC_MALLOC_POSIX
# --------------------
# Test whether 'malloc' is POSIX compliant (sets errno to ENOMEM when it
# fails), and replace malloc if it is not.
AC_DEFUN([gl_FUNC_MALLOC_POSIX],
[
  AC_REQUIRE([gl_CHECK_MALLOC_POSIX])
  if test $gl_cv_func_malloc_posix = yes; then
    HAVE_MALLOC_POSIX=1
    AC_DEFINE([HAVE_MALLOC_POSIX], [1],
      [Define if the 'malloc' function is POSIX compliant.])
  else
    AC_LIBOBJ([malloc])
    HAVE_MALLOC_POSIX=0
  fi
  AC_SUBST([HAVE_MALLOC_POSIX])
])

# Test whether malloc, realloc, calloc are POSIX compliant,
# Set gl_cv_func_malloc_posix to yes or no accordingly.
AC_DEFUN([gl_CHECK_MALLOC_POSIX],
[
  AC_CACHE_CHECK([whether malloc, realloc, calloc are POSIX compliant],
    [gl_cv_func_malloc_posix],
    [
      dnl It is too dangerous to try to allocate a large amount of memory:
      dnl some systems go to their knees when you do that. So assume that
      dnl all Unix implementations of the function are POSIX compliant.
      AC_TRY_COMPILE([],
        [#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
         choke me
         #endif
        ], [gl_cv_func_malloc_posix=yes], [gl_cv_func_malloc_posix=no])
    ])
])

# serial 56

# Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005, 2006,
# 2007, 2008, 2009, 2010 Free Software Foundation, Inc.
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

dnl Initially derived from code in GNU grep.
dnl Mostly written by Jim Meyering.

AC_PREREQ([2.50])

AC_DEFUN([gl_REGEX],
[
  AC_CHECK_HEADERS_ONCE([locale.h])

  AC_ARG_WITH([included-regex],
    [AS_HELP_STRING([--without-included-regex],
                    [don't compile regex; this is the default on systems
                     with recent-enough versions of the GNU C Library
                     (use with caution on other systems).])])

  case $with_included_regex in #(
  yes|no) ac_use_included_regex=$with_included_regex
        ;;
  '')
    # If the system regex support is good enough that it passes the
    # following run test, then default to *not* using the included regex.c.
    # If cross compiling, assume the test would fail and use the included
    # regex.c.
    AC_CACHE_CHECK([for working re_compile_pattern],
                   [gl_cv_func_re_compile_pattern_working],
      [AC_RUN_IFELSE(
        [AC_LANG_PROGRAM(
          [AC_INCLUDES_DEFAULT[
           #if HAVE_LOCALE_H
            #include <locale.h>
           #endif
           #include <limits.h>
           #include <regex.h>
           ]],
          [[static struct re_pattern_buffer regex;
            unsigned char folded_chars[UCHAR_MAX + 1];
            int i;
            const char *s;
            struct re_registers regs;

            #if HAVE_LOCALE_H
              /* http://sourceware.org/ml/libc-hacker/2006-09/msg00008.html
                 This test needs valgrind to catch the bug on Debian
                 GNU/Linux 3.1 x86, but it might catch the bug better
                 on other platforms and it shouldn't hurt to try the
                 test here.  */
              if (setlocale (LC_ALL, "en_US.UTF-8"))
                {
                  static char const pat[] = "insert into";
                  static char const data[] =
                    "\xFF\0\x12\xA2\xAA\xC4\xB1,K\x12\xC4\xB1*\xACK";
                  re_set_syntax (RE_SYNTAX_GREP | RE_HAT_LISTS_NOT_NEWLINE
                                 | RE_ICASE);
                  memset (&regex, 0, sizeof regex);
                  s = re_compile_pattern (pat, sizeof pat - 1, &regex);
                  if (s)
                    return 1;
                  if (re_search (&regex, data, sizeof data - 1,
                                 0, sizeof data - 1, &regs)
                      != -1)
                    return 1;
                  if (! setlocale (LC_ALL, "C"))
                    return 1;
                }
            #endif

            /* This test is from glibc bug 3957, reported by Andrew Mackey.  */
            re_set_syntax (RE_SYNTAX_EGREP | RE_HAT_LISTS_NOT_NEWLINE);
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("a[^x]b", 6, &regex);
            if (s)
              return 1;

            /* This should fail, but succeeds for glibc-2.5.  */
            if (re_search (&regex, "a\nb", 3, 0, 3, &regs) != -1)
              return 1;

            /* This regular expression is from Spencer ere test number 75
               in grep-2.3.  */
            re_set_syntax (RE_SYNTAX_POSIX_EGREP);
            memset (&regex, 0, sizeof regex);
            for (i = 0; i <= UCHAR_MAX; i++)
              folded_chars[i] = i;
            regex.translate = folded_chars;
            s = re_compile_pattern ("a[[:@:>@:]]b\n", 11, &regex);
            /* This should fail with _Invalid character class name_ error.  */
            if (!s)
              return 1;

            /* Ensure that [b-a] is diagnosed as invalid, when
               using RE_NO_EMPTY_RANGES. */
            re_set_syntax (RE_SYNTAX_POSIX_EGREP | RE_NO_EMPTY_RANGES);
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("a[b-a]", 6, &regex);
            if (s == 0)
              return 1;

            /* This should succeed, but does not for glibc-2.1.3.  */
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("{1", 2, &regex);

            if (s)
              return 1;

            /* The following example is derived from a problem report
               against gawk from Jorge Stolfi <stolfi@ic.unicamp.br>.  */
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("[an\371]*n", 7, &regex);
            if (s)
              return 1;

            /* This should match, but does not for glibc-2.2.1.  */
            if (re_match (&regex, "an", 2, 0, &regs) != 2)
              return 1;

            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("x", 1, &regex);
            if (s)
              return 1;

            /* glibc-2.2.93 does not work with a negative RANGE argument.  */
            if (re_search (&regex, "wxy", 3, 2, -2, &regs) != 1)
              return 1;

            /* The version of regex.c in older versions of gnulib
               ignored RE_ICASE.  Detect that problem too.  */
            re_set_syntax (RE_SYNTAX_EMACS | RE_ICASE);
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("x", 1, &regex);
            if (s)
              return 1;

            if (re_search (&regex, "WXY", 3, 0, 3, &regs) < 0)
              return 1;

            /* Catch a bug reported by Vin Shelton in
               http://lists.gnu.org/archive/html/bug-coreutils/2007-06/msg00089.html
               */
            re_set_syntax (RE_SYNTAX_POSIX_BASIC
                           & ~RE_CONTEXT_INVALID_DUP
                           & ~RE_NO_EMPTY_RANGES);
            memset (&regex, 0, sizeof regex);
            s = re_compile_pattern ("[[:alnum:]_-]\\\\+$", 16, &regex);
            if (s)
              return 1;

            /* REG_STARTEND was added to glibc on 2004-01-15.
               Reject older versions.  */
            if (! REG_STARTEND)
              return 1;

            /* Reject hosts whose regoff_t values are too narrow.
               These include glibc 2.3.5 on hosts with 64-bit ptrdiff_t
               and 32-bit int.  */
            if (sizeof (regoff_t) < sizeof (ptrdiff_t)
                || sizeof (regoff_t) < sizeof (ssize_t))
              return 1;

            return 0;]])],
       [gl_cv_func_re_compile_pattern_working=yes],
       [gl_cv_func_re_compile_pattern_working=no],
       dnl When crosscompiling, assume it is not working.
       [gl_cv_func_re_compile_pattern_working=no])])
    case $gl_cv_func_re_compile_pattern_working in #(
    yes) ac_use_included_regex=no;; #(
    no) ac_use_included_regex=yes;;
    esac
    ;;
  *) AC_MSG_ERROR([Invalid value for --with-included-regex: $with_included_regex])
    ;;
  esac

  if test $ac_use_included_regex = yes; then
    AC_DEFINE([_REGEX_LARGE_OFFSETS], [1],
      [Define if you want regoff_t to be at least as wide POSIX requires.])
    AC_DEFINE([re_syntax_options], [rpl_re_syntax_options],
      [Define to rpl_re_syntax_options if the replacement should be used.])
    AC_DEFINE([re_set_syntax], [rpl_re_set_syntax],
      [Define to rpl_re_set_syntax if the replacement should be used.])
    AC_DEFINE([re_compile_pattern], [rpl_re_compile_pattern],
      [Define to rpl_re_compile_pattern if the replacement should be used.])
    AC_DEFINE([re_compile_fastmap], [rpl_re_compile_fastmap],
      [Define to rpl_re_compile_fastmap if the replacement should be used.])
    AC_DEFINE([re_search], [rpl_re_search],
      [Define to rpl_re_search if the replacement should be used.])
    AC_DEFINE([re_search_2], [rpl_re_search_2],
      [Define to rpl_re_search_2 if the replacement should be used.])
    AC_DEFINE([re_match], [rpl_re_match],
      [Define to rpl_re_match if the replacement should be used.])
    AC_DEFINE([re_match_2], [rpl_re_match_2],
      [Define to rpl_re_match_2 if the replacement should be used.])
    AC_DEFINE([re_set_registers], [rpl_re_set_registers],
      [Define to rpl_re_set_registers if the replacement should be used.])
    AC_DEFINE([re_comp], [rpl_re_comp],
      [Define to rpl_re_comp if the replacement should be used.])
    AC_DEFINE([re_exec], [rpl_re_exec],
      [Define to rpl_re_exec if the replacement should be used.])
    AC_DEFINE([regcomp], [rpl_regcomp],
      [Define to rpl_regcomp if the replacement should be used.])
    AC_DEFINE([regexec], [rpl_regexec],
      [Define to rpl_regexec if the replacement should be used.])
    AC_DEFINE([regerror], [rpl_regerror],
      [Define to rpl_regerror if the replacement should be used.])
    AC_DEFINE([regfree], [rpl_regfree],
      [Define to rpl_regfree if the replacement should be used.])
    AC_LIBOBJ([regex])
    gl_PREREQ_REGEX
  fi
])

# Prerequisites of lib/regex.c and lib/regex_internal.c.
AC_DEFUN([gl_PREREQ_REGEX],
[
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])
  AC_REQUIRE([AC_C_INLINE])
  AC_REQUIRE([AC_C_RESTRICT])
  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  AC_CHECK_HEADERS([libintl.h])
  AC_CHECK_FUNCS_ONCE([isblank iswctype wcscoll])
  AC_CHECK_DECLS([isblank], [], [], [#include <ctype.h>])
])

# ssize_t.m4 serial 4 (gettext-0.15)
dnl Copyright (C) 2001-2003, 2006, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.
dnl Test whether ssize_t is defined.

AC_DEFUN([gt_TYPE_SSIZE_T],
[
  AC_CACHE_CHECK([for ssize_t], [gt_cv_ssize_t],
    [AC_TRY_COMPILE([#include <sys/types.h>],
       [int x = sizeof (ssize_t *) + sizeof (ssize_t);
        return !x;],
       [gt_cv_ssize_t=yes], [gt_cv_ssize_t=no])])
  if test $gt_cv_ssize_t = no; then
    AC_DEFINE([ssize_t], [int],
              [Define as a signed type of the same size as size_t.])
  fi
])

# stdlib_h.m4 serial 28
dnl Copyright (C) 2007-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_STDLIB_H],
[
  AC_REQUIRE([gl_STDLIB_H_DEFAULTS])
  gl_CHECK_NEXT_HEADERS([stdlib.h])
  AC_CHECK_HEADERS([random.h], [], [], [AC_INCLUDES_DEFAULT])
  if test $ac_cv_header_random_h = yes; then
    HAVE_RANDOM_H=1
  else
    HAVE_RANDOM_H=0
  fi
  AC_SUBST([HAVE_RANDOM_H])
  AC_CHECK_TYPES([struct random_data],
    [], [HAVE_STRUCT_RANDOM_DATA=0],
    [[#include <stdlib.h>
      #if HAVE_RANDOM_H
      # include <random.h>
      #endif
    ]])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use, and which is not
  dnl guaranteed by C89.
  gl_WARN_ON_USE_PREPARE([[#include <stdlib.h>
#if HAVE_SYS_LOADAVG_H
# include <sys/loadavg.h>
#endif
#if HAVE_RANDOM_H
# include <random.h>
#endif
    ]], [atoll canonicalize_file_name getloadavg getsubopt grantpt mkdtemp
    mkostemp mkostemps mkstemp mkstemps ptsname random_r initstat_r srandom_r
    setstate_r realpath rpmatch setenv strtod strtoll strtoull unlockpt
    unsetenv])
])

AC_DEFUN([gl_STDLIB_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_STDLIB_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_STDLIB_H_DEFAULTS],
[
  GNULIB_ATOLL=0;         AC_SUBST([GNULIB_ATOLL])
  GNULIB_CALLOC_POSIX=0;  AC_SUBST([GNULIB_CALLOC_POSIX])
  GNULIB_CANONICALIZE_FILE_NAME=0;  AC_SUBST([GNULIB_CANONICALIZE_FILE_NAME])
  GNULIB_GETLOADAVG=0;    AC_SUBST([GNULIB_GETLOADAVG])
  GNULIB_GETSUBOPT=0;     AC_SUBST([GNULIB_GETSUBOPT])
  GNULIB_GRANTPT=0;       AC_SUBST([GNULIB_GRANTPT])
  GNULIB_MALLOC_POSIX=0;  AC_SUBST([GNULIB_MALLOC_POSIX])
  GNULIB_MKDTEMP=0;       AC_SUBST([GNULIB_MKDTEMP])
  GNULIB_MKOSTEMP=0;      AC_SUBST([GNULIB_MKOSTEMP])
  GNULIB_MKOSTEMPS=0;     AC_SUBST([GNULIB_MKOSTEMPS])
  GNULIB_MKSTEMP=0;       AC_SUBST([GNULIB_MKSTEMP])
  GNULIB_MKSTEMPS=0;      AC_SUBST([GNULIB_MKSTEMPS])
  GNULIB_PTSNAME=0;       AC_SUBST([GNULIB_PTSNAME])
  GNULIB_PUTENV=0;        AC_SUBST([GNULIB_PUTENV])
  GNULIB_RANDOM_R=0;      AC_SUBST([GNULIB_RANDOM_R])
  GNULIB_REALLOC_POSIX=0; AC_SUBST([GNULIB_REALLOC_POSIX])
  GNULIB_REALPATH=0;      AC_SUBST([GNULIB_REALPATH])
  GNULIB_RPMATCH=0;       AC_SUBST([GNULIB_RPMATCH])
  GNULIB_SETENV=0;        AC_SUBST([GNULIB_SETENV])
  GNULIB_STRTOD=0;        AC_SUBST([GNULIB_STRTOD])
  GNULIB_STRTOLL=0;       AC_SUBST([GNULIB_STRTOLL])
  GNULIB_STRTOULL=0;      AC_SUBST([GNULIB_STRTOULL])
  GNULIB_UNLOCKPT=0;      AC_SUBST([GNULIB_UNLOCKPT])
  GNULIB_UNSETENV=0;      AC_SUBST([GNULIB_UNSETENV])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_ATOLL=1;              AC_SUBST([HAVE_ATOLL])
  HAVE_CALLOC_POSIX=1;       AC_SUBST([HAVE_CALLOC_POSIX])
  HAVE_CANONICALIZE_FILE_NAME=1;  AC_SUBST([HAVE_CANONICALIZE_FILE_NAME])
  HAVE_DECL_GETLOADAVG=1;    AC_SUBST([HAVE_DECL_GETLOADAVG])
  HAVE_GETSUBOPT=1;          AC_SUBST([HAVE_GETSUBOPT])
  HAVE_GRANTPT=1;            AC_SUBST([HAVE_GRANTPT])
  HAVE_MALLOC_POSIX=1;       AC_SUBST([HAVE_MALLOC_POSIX])
  HAVE_MKDTEMP=1;            AC_SUBST([HAVE_MKDTEMP])
  HAVE_MKOSTEMP=1;           AC_SUBST([HAVE_MKOSTEMP])
  HAVE_MKOSTEMPS=1;          AC_SUBST([HAVE_MKOSTEMPS])
  HAVE_MKSTEMP=1;            AC_SUBST([HAVE_MKSTEMP])
  HAVE_MKSTEMPS=1;           AC_SUBST([HAVE_MKSTEMPS])
  HAVE_PTSNAME=1;            AC_SUBST([HAVE_PTSNAME])
  HAVE_RANDOM_R=1;           AC_SUBST([HAVE_RANDOM_R])
  HAVE_REALLOC_POSIX=1;      AC_SUBST([HAVE_REALLOC_POSIX])
  HAVE_REALPATH=1;           AC_SUBST([HAVE_REALPATH])
  HAVE_RPMATCH=1;            AC_SUBST([HAVE_RPMATCH])
  HAVE_SETENV=1;             AC_SUBST([HAVE_SETENV])
  HAVE_STRTOD=1;             AC_SUBST([HAVE_STRTOD])
  HAVE_STRTOLL=1;            AC_SUBST([HAVE_STRTOLL])
  HAVE_STRTOULL=1;           AC_SUBST([HAVE_STRTOULL])
  HAVE_STRUCT_RANDOM_DATA=1; AC_SUBST([HAVE_STRUCT_RANDOM_DATA])
  HAVE_SYS_LOADAVG_H=0;      AC_SUBST([HAVE_SYS_LOADAVG_H])
  HAVE_UNLOCKPT=1;           AC_SUBST([HAVE_UNLOCKPT])
  HAVE_UNSETENV=1;           AC_SUBST([HAVE_UNSETENV])
  REPLACE_CANONICALIZE_FILE_NAME=0;  AC_SUBST([REPLACE_CANONICALIZE_FILE_NAME])
  REPLACE_MKSTEMP=0;         AC_SUBST([REPLACE_MKSTEMP])
  REPLACE_PUTENV=0;          AC_SUBST([REPLACE_PUTENV])
  REPLACE_REALPATH=0;        AC_SUBST([REPLACE_REALPATH])
  REPLACE_SETENV=0;          AC_SUBST([REPLACE_SETENV])
  REPLACE_STRTOD=0;          AC_SUBST([REPLACE_STRTOD])
  REPLACE_UNSETENV=0;        AC_SUBST([REPLACE_UNSETENV])
])

# wcrtomb.m4 serial 5
dnl Copyright (C) 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_WCRTOMB],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  gl_MBSTATE_T_BROKEN

  AC_CHECK_FUNCS_ONCE([wcrtomb])
  if test $ac_cv_func_wcrtomb = no; then
    HAVE_WCRTOMB=0
  else
    if test $REPLACE_MBSTATE_T = 1; then
      REPLACE_WCRTOMB=1
    else
      dnl On AIX 4.3, OSF/1 5.1 and Solaris 10, wcrtomb (NULL, 0, NULL) sometimes
      dnl returns 0 instead of 1.
      AC_REQUIRE([AC_PROG_CC])
      AC_REQUIRE([gt_LOCALE_FR])
      AC_REQUIRE([gt_LOCALE_FR_UTF8])
      AC_REQUIRE([gt_LOCALE_JA])
      AC_REQUIRE([gt_LOCALE_ZH_CN])
      AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
      AC_CACHE_CHECK([whether wcrtomb return value is correct],
        [gl_cv_func_wcrtomb_retval],
        [
          dnl Initial guess, used when cross-compiling or when no suitable locale
          dnl is present.
changequote(,)dnl
          case "$host_os" in
                                     # Guess no on AIX 4, OSF/1 and Solaris.
            aix4* | osf* | solaris*) gl_cv_func_wcrtomb_retval="guessing no" ;;
                                     # Guess yes otherwise.
            *)                       gl_cv_func_wcrtomb_retval="guessing yes" ;;
          esac
changequote([,])dnl
          if test $LOCALE_FR != none || test $LOCALE_FR_UTF8 != none || test $LOCALE_JA != none || test $LOCALE_ZH_CN != none; then
            AC_TRY_RUN([
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (setlocale (LC_ALL, "$LOCALE_FR") != NULL)
    {
      if (wcrtomb (NULL, 0, NULL) != 1)
        return 1;
    }
  if (setlocale (LC_ALL, "$LOCALE_FR_UTF8") != NULL)
    {
      if (wcrtomb (NULL, 0, NULL) != 1)
        return 1;
    }
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      if (wcrtomb (NULL, 0, NULL) != 1)
        return 1;
    }
  if (setlocale (LC_ALL, "$LOCALE_ZH_CN") != NULL)
    {
      if (wcrtomb (NULL, 0, NULL) != 1)
        return 1;
    }
  return 0;
}],
              [gl_cv_func_wcrtomb_retval=yes],
              [gl_cv_func_wcrtomb_retval=no],
              [:])
          fi
        ])
      case "$gl_cv_func_wcrtomb_retval" in
        *yes) ;;
        *) REPLACE_WCRTOMB=1 ;;
      esac
    fi
  fi
  if test $HAVE_WCRTOMB = 0 || test $REPLACE_WCRTOMB = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([wcrtomb])
    gl_PREREQ_WCRTOMB
  fi
])

# Prerequisites of lib/wcrtomb.c.
AC_DEFUN([gl_PREREQ_WCRTOMB], [
  :
])

# 00gnulib.m4 serial 2
dnl Copyright (C) 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This file must be named something that sorts before all other
dnl gnulib-provided .m4 files.  It is needed until such time as we can
dnl assume Autoconf 2.64, with its improved AC_DEFUN_ONCE semantics.

# AC_DEFUN_ONCE([NAME], VALUE)
# ----------------------------
# Define NAME to expand to VALUE on the first use (whether by direct
# expansion, or by AC_REQUIRE), and to nothing on all subsequent uses.
# Avoid bugs in AC_REQUIRE in Autoconf 2.63 and earlier.  This
# definition is slower than the version in Autoconf 2.64, because it
# can only use interfaces that existed since 2.59; but it achieves the
# same effect.  Quoting is necessary to avoid confusing Automake.
m4_version_prereq([2.63.263], [],
[m4_define([AC][_DEFUN_ONCE],
  [AC][_DEFUN([$1],
    [AC_REQUIRE([_gl_DEFUN_ONCE([$1])],
      [m4_indir([_gl_DEFUN_ONCE([$1])])])])]dnl
[AC][_DEFUN([_gl_DEFUN_ONCE([$1])], [$2])])])

# gl_00GNULIB
# -----------
# Witness macro that this file has been included.  Needed to force
# Automake to include this file prior to all other gnulib .m4 files.
AC_DEFUN([gl_00GNULIB])

# alloca.m4 serial 9
dnl Copyright (C) 2002-2004, 2006-2007, 2009-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_ALLOCA],
[
  dnl Work around a bug of AC_EGREP_CPP in autoconf-2.57.
  AC_REQUIRE([AC_PROG_CPP])
  AC_REQUIRE([AC_PROG_EGREP])

  AC_REQUIRE([AC_FUNC_ALLOCA])
  if test $ac_cv_func_alloca_works = no; then
    gl_PREREQ_ALLOCA
  fi

  # Define an additional variable used in the Makefile substitution.
  if test $ac_cv_working_alloca_h = yes; then
    AC_CACHE_CHECK([for alloca as a compiler built-in], [gl_cv_rpl_alloca], [
      AC_EGREP_CPP([Need own alloca], [
#if defined __GNUC__ || defined _AIX || defined _MSC_VER
        Need own alloca
#endif
        ], [gl_cv_rpl_alloca=yes], [gl_cv_rpl_alloca=no])
    ])
    if test $gl_cv_rpl_alloca = yes; then
      dnl OK, alloca can be implemented through a compiler built-in.
      AC_DEFINE([HAVE_ALLOCA], [1],
        [Define to 1 if you have 'alloca' after including <alloca.h>,
         a header that may be supplied by this distribution.])
      ALLOCA_H=alloca.h
    else
      dnl alloca exists as a library function, i.e. it is slow and probably
      dnl a memory leak. Don't define HAVE_ALLOCA in this case.
      ALLOCA_H=
    fi
  else
    ALLOCA_H=alloca.h
  fi
  AC_SUBST([ALLOCA_H])
])

# Prerequisites of lib/alloca.c.
# STACK_DIRECTION is already handled by AC_FUNC_ALLOCA.
AC_DEFUN([gl_PREREQ_ALLOCA], [:])

# codeset.m4 serial 4 (gettext-0.18)
dnl Copyright (C) 2000-2002, 2006, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

AC_DEFUN([AM_LANGINFO_CODESET],
[
  AC_CACHE_CHECK([for nl_langinfo and CODESET], [am_cv_langinfo_codeset],
    [AC_TRY_LINK([#include <langinfo.h>],
      [char* cs = nl_langinfo(CODESET); return !cs;],
      [am_cv_langinfo_codeset=yes],
      [am_cv_langinfo_codeset=no])
    ])
  if test $am_cv_langinfo_codeset = yes; then
    AC_DEFINE([HAVE_LANGINFO_CODESET], [1],
      [Define if you have <langinfo.h> and nl_langinfo(CODESET).])
  fi
])

# serial 9  -*- Autoconf -*-
# Enable extensions on systems that normally disable them.

# Copyright (C) 2003, 2006-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This definition of AC_USE_SYSTEM_EXTENSIONS is stolen from CVS
# Autoconf.  Perhaps we can remove this once we can assume Autoconf
# 2.62 or later everywhere, but since CVS Autoconf mutates rapidly
# enough in this area it's likely we'll need to redefine
# AC_USE_SYSTEM_EXTENSIONS for quite some time.

# If autoconf reports a warning
#     warning: AC_COMPILE_IFELSE was called before AC_USE_SYSTEM_EXTENSIONS
# or  warning: AC_RUN_IFELSE was called before AC_USE_SYSTEM_EXTENSIONS
# the fix is
#   1) to ensure that AC_USE_SYSTEM_EXTENSIONS is never directly invoked
#      but always AC_REQUIREd,
#   2) to ensure that for each occurrence of
#        AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])
#      or
#        AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
#      the corresponding gnulib module description has 'extensions' among
#      its dependencies. This will ensure that the gl_USE_SYSTEM_EXTENSIONS
#      invocation occurs in gl_EARLY, not in gl_INIT.

# AC_USE_SYSTEM_EXTENSIONS
# ------------------------
# Enable extensions on systems that normally disable them,
# typically due to standards-conformance issues.
# Remember that #undef in AH_VERBATIM gets replaced with #define by
# AC_DEFINE.  The goal here is to define all known feature-enabling
# macros, then, if reports of conflicts are made, disable macros that
# cause problems on some platforms (such as __EXTENSIONS__).
AC_DEFUN_ONCE([AC_USE_SYSTEM_EXTENSIONS],
[AC_BEFORE([$0], [AC_COMPILE_IFELSE])dnl
AC_BEFORE([$0], [AC_RUN_IFELSE])dnl

  AC_REQUIRE([AC_CANONICAL_HOST])

  AC_CHECK_HEADER([minix/config.h], [MINIX=yes], [MINIX=])
  if test "$MINIX" = yes; then
    AC_DEFINE([_POSIX_SOURCE], [1],
      [Define to 1 if you need to in order for `stat' and other
       things to work.])
    AC_DEFINE([_POSIX_1_SOURCE], [2],
      [Define to 2 if the system does not provide POSIX.1 features
       except with this defined.])
    AC_DEFINE([_MINIX], [1],
      [Define to 1 if on MINIX.])
  fi

  dnl HP-UX 11.11 defines mbstate_t only if _XOPEN_SOURCE is defined to 500,
  dnl regardless of whether the flags -Ae or _D_HPUX_SOURCE=1 are already
  dnl provided.
  case "$host_os" in
    hpux*)
      AC_DEFINE([_XOPEN_SOURCE], [500],
        [Define to 500 only on HP-UX.])
      ;;
  esac

  AH_VERBATIM([__EXTENSIONS__],
[/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# undef _ALL_SOURCE
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# undef _GNU_SOURCE
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# undef _POSIX_PTHREAD_SEMANTICS
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# undef _TANDEM_SOURCE
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# undef __EXTENSIONS__
#endif
])
  AC_CACHE_CHECK([whether it is safe to define __EXTENSIONS__],
    [ac_cv_safe_to_define___extensions__],
    [AC_COMPILE_IFELSE(
       [AC_LANG_PROGRAM([[
#         define __EXTENSIONS__ 1
          ]AC_INCLUDES_DEFAULT])],
       [ac_cv_safe_to_define___extensions__=yes],
       [ac_cv_safe_to_define___extensions__=no])])
  test $ac_cv_safe_to_define___extensions__ = yes &&
    AC_DEFINE([__EXTENSIONS__])
  AC_DEFINE([_ALL_SOURCE])
  AC_DEFINE([_GNU_SOURCE])
  AC_DEFINE([_POSIX_PTHREAD_SEMANTICS])
  AC_DEFINE([_TANDEM_SOURCE])
])# AC_USE_SYSTEM_EXTENSIONS

# gl_USE_SYSTEM_EXTENSIONS
# ------------------------
# Enable extensions on systems that normally disable them,
# typically due to standards-conformance issues.
AC_DEFUN_ONCE([gl_USE_SYSTEM_EXTENSIONS],
[
  dnl Require this macro before AC_USE_SYSTEM_EXTENSIONS.
  dnl gnulib does not need it. But if it gets required by third-party macros
  dnl after AC_USE_SYSTEM_EXTENSIONS is required, autoconf 2.62..2.63 emit a
  dnl warning: "AC_COMPILE_IFELSE was called before AC_USE_SYSTEM_EXTENSIONS".
  dnl Note: We can do this only for one of the macros AC_AIX, AC_GNU_SOURCE,
  dnl AC_MINIX. If people still use AC_AIX or AC_MINIX, they are out of luck.
  AC_REQUIRE([AC_GNU_SOURCE])

  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])
])

# fcntl-o.m4 serial 1
dnl Copyright (C) 2006, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Paul Eggert.

# Test whether the flags O_NOATIME and O_NOFOLLOW actually work.
# Define HAVE_WORKING_O_NOATIME to 1 if O_NOATIME works, or to 0 otherwise.
# Define HAVE_WORKING_O_NOFOLLOW to 1 if O_NOFOLLOW works, or to 0 otherwise.
AC_DEFUN([gl_FCNTL_O_FLAGS],
[
  dnl Persuade glibc <fcntl.h> to define O_NOATIME and O_NOFOLLOW.
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])
  AC_CACHE_CHECK([for working fcntl.h], [gl_cv_header_working_fcntl_h],
    [AC_RUN_IFELSE(
       [AC_LANG_PROGRAM(
          [[#include <sys/types.h>
           #include <sys/stat.h>
           #include <unistd.h>
           #include <fcntl.h>
           #ifndef O_NOATIME
            #define O_NOATIME 0
           #endif
           #ifndef O_NOFOLLOW
            #define O_NOFOLLOW 0
           #endif
           static int const constants[] =
            {
              O_CREAT, O_EXCL, O_NOCTTY, O_TRUNC, O_APPEND,
              O_NONBLOCK, O_SYNC, O_ACCMODE, O_RDONLY, O_RDWR, O_WRONLY
            };
          ]],
          [[
            int status = !constants;
            {
              static char const sym[] = "conftest.sym";
              if (symlink (".", sym) != 0
                  || close (open (sym, O_RDONLY | O_NOFOLLOW)) == 0)
                status |= 32;
              unlink (sym);
            }
            {
              static char const file[] = "confdefs.h";
              int fd = open (file, O_RDONLY | O_NOATIME);
              char c;
              struct stat st0, st1;
              if (fd < 0
                  || fstat (fd, &st0) != 0
                  || sleep (1) != 0
                  || read (fd, &c, 1) != 1
                  || close (fd) != 0
                  || stat (file, &st1) != 0
                  || st0.st_atime != st1.st_atime)
                status |= 64;
            }
            return status;]])],
       [gl_cv_header_working_fcntl_h=yes],
       [case $? in #(
        32) gl_cv_header_working_fcntl_h='no (bad O_NOFOLLOW)';; #(
        64) gl_cv_header_working_fcntl_h='no (bad O_NOATIME)';; #(
        96) gl_cv_header_working_fcntl_h='no (bad O_NOATIME, O_NOFOLLOW)';; #(
         *) gl_cv_header_working_fcntl_h='no';;
        esac],
       [gl_cv_header_working_fcntl_h=cross-compiling])])

  case $gl_cv_header_working_fcntl_h in #(
  *O_NOATIME* | no | cross-compiling) ac_val=0;; #(
  *) ac_val=1;;
  esac
  AC_DEFINE_UNQUOTED([HAVE_WORKING_O_NOATIME], [$ac_val],
    [Define to 1 if O_NOATIME works.])

  case $gl_cv_header_working_fcntl_h in #(
  *O_NOFOLLOW* | no | cross-compiling) ac_val=0;; #(
  *) ac_val=1;;
  esac
  AC_DEFINE_UNQUOTED([HAVE_WORKING_O_NOFOLLOW], [$ac_val],
    [Define to 1 if O_NOFOLLOW works.])
])

# getpagesize.m4 serial 8
dnl Copyright (C) 2002, 2004-2005, 2007, 2009-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_GETPAGESIZE],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_CHECK_FUNCS([getpagesize])
  if test $ac_cv_func_getpagesize = no; then
    HAVE_GETPAGESIZE=0
    AC_CHECK_HEADERS([OS.h])
    if test $ac_cv_header_OS_h = yes; then
      HAVE_OS_H=1
    fi
    AC_CHECK_HEADERS([sys/param.h])
    if test $ac_cv_header_sys_param_h = yes; then
      HAVE_SYS_PARAM_H=1
    fi
  fi
  case "$host_os" in
    mingw*)
      REPLACE_GETPAGESIZE=1
      AC_LIBOBJ([getpagesize])
      ;;
  esac
  dnl Also check whether it's declared.
  dnl mingw has getpagesize() in libgcc.a but doesn't declare it.
  AC_CHECK_DECL([getpagesize], , [HAVE_DECL_GETPAGESIZE=0])
])

# gettext.m4 serial 63 (gettext-0.18)
dnl Copyright (C) 1995-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Authors:
dnl   Ulrich Drepper <drepper@cygnus.com>, 1995-2000.
dnl   Bruno Haible <haible@clisp.cons.org>, 2000-2006, 2008-2010.

dnl Macro to add for using GNU gettext.

dnl Usage: AM_GNU_GETTEXT([INTLSYMBOL], [NEEDSYMBOL], [INTLDIR]).
dnl INTLSYMBOL can be one of 'external', 'no-libtool', 'use-libtool'. The
dnl    default (if it is not specified or empty) is 'no-libtool'.
dnl    INTLSYMBOL should be 'external' for packages with no intl directory,
dnl    and 'no-libtool' or 'use-libtool' for packages with an intl directory.
dnl    If INTLSYMBOL is 'use-libtool', then a libtool library
dnl    $(top_builddir)/intl/libintl.la will be created (shared and/or static,
dnl    depending on --{enable,disable}-{shared,static} and on the presence of
dnl    AM-DISABLE-SHARED). If INTLSYMBOL is 'no-libtool', a static library
dnl    $(top_builddir)/intl/libintl.a will be created.
dnl If NEEDSYMBOL is specified and is 'need-ngettext', then GNU gettext
dnl    implementations (in libc or libintl) without the ngettext() function
dnl    will be ignored.  If NEEDSYMBOL is specified and is
dnl    'need-formatstring-macros', then GNU gettext implementations that don't
dnl    support the ISO C 99 <inttypes.h> formatstring macros will be ignored.
dnl INTLDIR is used to find the intl libraries.  If empty,
dnl    the value `$(top_builddir)/intl/' is used.
dnl
dnl The result of the configuration is one of three cases:
dnl 1) GNU gettext, as included in the intl subdirectory, will be compiled
dnl    and used.
dnl    Catalog format: GNU --> install in $(datadir)
dnl    Catalog extension: .mo after installation, .gmo in source tree
dnl 2) GNU gettext has been found in the system's C library.
dnl    Catalog format: GNU --> install in $(datadir)
dnl    Catalog extension: .mo after installation, .gmo in source tree
dnl 3) No internationalization, always use English msgid.
dnl    Catalog format: none
dnl    Catalog extension: none
dnl If INTLSYMBOL is 'external', only cases 2 and 3 can occur.
dnl The use of .gmo is historical (it was needed to avoid overwriting the
dnl GNU format catalogs when building on a platform with an X/Open gettext),
dnl but we keep it in order not to force irrelevant filename changes on the
dnl maintainers.
dnl
AC_DEFUN([AM_GNU_GETTEXT],
[
  dnl Argument checking.
  ifelse([$1], [], , [ifelse([$1], [external], , [ifelse([$1], [no-libtool], , [ifelse([$1], [use-libtool], ,
    [errprint([ERROR: invalid first argument to AM_GNU_GETTEXT
])])])])])
  ifelse(ifelse([$1], [], [old])[]ifelse([$1], [no-libtool], [old]), [old],
    [AC_DIAGNOSE([obsolete], [Use of AM_GNU_GETTEXT without [external] argument is deprecated.])])
  ifelse([$2], [], , [ifelse([$2], [need-ngettext], , [ifelse([$2], [need-formatstring-macros], ,
    [errprint([ERROR: invalid second argument to AM_GNU_GETTEXT
])])])])
  define([gt_included_intl],
    ifelse([$1], [external],
      ifdef([AM_GNU_GETTEXT_][INTL_SUBDIR], [yes], [no]),
      [yes]))
  define([gt_libtool_suffix_prefix], ifelse([$1], [use-libtool], [l], []))
  gt_NEEDS_INIT
  AM_GNU_GETTEXT_NEED([$2])

  AC_REQUIRE([AM_PO_SUBDIRS])dnl
  ifelse(gt_included_intl, yes, [
    AC_REQUIRE([AM_INTL_SUBDIR])dnl
  ])

  dnl Prerequisites of AC_LIB_LINKFLAGS_BODY.
  AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
  AC_REQUIRE([AC_LIB_RPATH])

  dnl Sometimes libintl requires libiconv, so first search for libiconv.
  dnl Ideally we would do this search only after the
  dnl      if test "$USE_NLS" = "yes"; then
  dnl        if { eval "gt_val=\$$gt_func_gnugettext_libc"; test "$gt_val" != "yes"; }; then
  dnl tests. But if configure.in invokes AM_ICONV after AM_GNU_GETTEXT
  dnl the configure script would need to contain the same shell code
  dnl again, outside any 'if'. There are two solutions:
  dnl - Invoke AM_ICONV_LINKFLAGS_BODY here, outside any 'if'.
  dnl - Control the expansions in more detail using AC_PROVIDE_IFELSE.
  dnl Since AC_PROVIDE_IFELSE is only in autoconf >= 2.52 and not
  dnl documented, we avoid it.
  ifelse(gt_included_intl, yes, , [
    AC_REQUIRE([AM_ICONV_LINKFLAGS_BODY])
  ])

  dnl Sometimes, on MacOS X, libintl requires linking with CoreFoundation.
  gt_INTL_MACOSX

  dnl Set USE_NLS.
  AC_REQUIRE([AM_NLS])

  ifelse(gt_included_intl, yes, [
    BUILD_INCLUDED_LIBINTL=no
    USE_INCLUDED_LIBINTL=no
  ])
  LIBINTL=
  LTLIBINTL=
  POSUB=

  dnl Add a version number to the cache macros.
  case " $gt_needs " in
    *" need-formatstring-macros "*) gt_api_version=3 ;;
    *" need-ngettext "*) gt_api_version=2 ;;
    *) gt_api_version=1 ;;
  esac
  gt_func_gnugettext_libc="gt_cv_func_gnugettext${gt_api_version}_libc"
  gt_func_gnugettext_libintl="gt_cv_func_gnugettext${gt_api_version}_libintl"

  dnl If we use NLS figure out what method
  if test "$USE_NLS" = "yes"; then
    gt_use_preinstalled_gnugettext=no
    ifelse(gt_included_intl, yes, [
      AC_MSG_CHECKING([whether included gettext is requested])
      AC_ARG_WITH([included-gettext],
        [  --with-included-gettext use the GNU gettext library included here],
        nls_cv_force_use_gnu_gettext=$withval,
        nls_cv_force_use_gnu_gettext=no)
      AC_MSG_RESULT([$nls_cv_force_use_gnu_gettext])

      nls_cv_use_gnu_gettext="$nls_cv_force_use_gnu_gettext"
      if test "$nls_cv_force_use_gnu_gettext" != "yes"; then
    ])
        dnl User does not insist on using GNU NLS library.  Figure out what
        dnl to use.  If GNU gettext is available we use this.  Else we have
        dnl to fall back to GNU NLS library.

        if test $gt_api_version -ge 3; then
          gt_revision_test_code='
#ifndef __GNU_GETTEXT_SUPPORTED_REVISION
#define __GNU_GETTEXT_SUPPORTED_REVISION(major) ((major) == 0 ? 0 : -1)
#endif
changequote(,)dnl
typedef int array [2 * (__GNU_GETTEXT_SUPPORTED_REVISION(0) >= 1) - 1];
changequote([,])dnl
'
        else
          gt_revision_test_code=
        fi
        if test $gt_api_version -ge 2; then
          gt_expression_test_code=' + * ngettext ("", "", 0)'
        else
          gt_expression_test_code=
        fi

        AC_CACHE_CHECK([for GNU gettext in libc], [$gt_func_gnugettext_libc],
         [AC_TRY_LINK([#include <libintl.h>
$gt_revision_test_code
extern int _nl_msg_cat_cntr;
extern int *_nl_domain_bindings;],
            [bindtextdomain ("", "");
return * gettext ("")$gt_expression_test_code + _nl_msg_cat_cntr + *_nl_domain_bindings],
            [eval "$gt_func_gnugettext_libc=yes"],
            [eval "$gt_func_gnugettext_libc=no"])])

        if { eval "gt_val=\$$gt_func_gnugettext_libc"; test "$gt_val" != "yes"; }; then
          dnl Sometimes libintl requires libiconv, so first search for libiconv.
          ifelse(gt_included_intl, yes, , [
            AM_ICONV_LINK
          ])
          dnl Search for libintl and define LIBINTL, LTLIBINTL and INCINTL
          dnl accordingly. Don't use AC_LIB_LINKFLAGS_BODY([intl],[iconv])
          dnl because that would add "-liconv" to LIBINTL and LTLIBINTL
          dnl even if libiconv doesn't exist.
          AC_LIB_LINKFLAGS_BODY([intl])
          AC_CACHE_CHECK([for GNU gettext in libintl],
            [$gt_func_gnugettext_libintl],
           [gt_save_CPPFLAGS="$CPPFLAGS"
            CPPFLAGS="$CPPFLAGS $INCINTL"
            gt_save_LIBS="$LIBS"
            LIBS="$LIBS $LIBINTL"
            dnl Now see whether libintl exists and does not depend on libiconv.
            AC_TRY_LINK([#include <libintl.h>
$gt_revision_test_code
extern int _nl_msg_cat_cntr;
extern
#ifdef __cplusplus
"C"
#endif
const char *_nl_expand_alias (const char *);],
              [bindtextdomain ("", "");
return * gettext ("")$gt_expression_test_code + _nl_msg_cat_cntr + *_nl_expand_alias ("")],
              [eval "$gt_func_gnugettext_libintl=yes"],
              [eval "$gt_func_gnugettext_libintl=no"])
            dnl Now see whether libintl exists and depends on libiconv.
            if { eval "gt_val=\$$gt_func_gnugettext_libintl"; test "$gt_val" != yes; } && test -n "$LIBICONV"; then
              LIBS="$LIBS $LIBICONV"
              AC_TRY_LINK([#include <libintl.h>
$gt_revision_test_code
extern int _nl_msg_cat_cntr;
extern
#ifdef __cplusplus
"C"
#endif
const char *_nl_expand_alias (const char *);],
                [bindtextdomain ("", "");
return * gettext ("")$gt_expression_test_code + _nl_msg_cat_cntr + *_nl_expand_alias ("")],
               [LIBINTL="$LIBINTL $LIBICONV"
                LTLIBINTL="$LTLIBINTL $LTLIBICONV"
                eval "$gt_func_gnugettext_libintl=yes"
               ])
            fi
            CPPFLAGS="$gt_save_CPPFLAGS"
            LIBS="$gt_save_LIBS"])
        fi

        dnl If an already present or preinstalled GNU gettext() is found,
        dnl use it.  But if this macro is used in GNU gettext, and GNU
        dnl gettext is already preinstalled in libintl, we update this
        dnl libintl.  (Cf. the install rule in intl/Makefile.in.)
        if { eval "gt_val=\$$gt_func_gnugettext_libc"; test "$gt_val" = "yes"; } \
           || { { eval "gt_val=\$$gt_func_gnugettext_libintl"; test "$gt_val" = "yes"; } \
                && test "$PACKAGE" != gettext-runtime \
                && test "$PACKAGE" != gettext-tools; }; then
          gt_use_preinstalled_gnugettext=yes
        else
          dnl Reset the values set by searching for libintl.
          LIBINTL=
          LTLIBINTL=
          INCINTL=
        fi

    ifelse(gt_included_intl, yes, [
        if test "$gt_use_preinstalled_gnugettext" != "yes"; then
          dnl GNU gettext is not found in the C library.
          dnl Fall back on included GNU gettext library.
          nls_cv_use_gnu_gettext=yes
        fi
      fi

      if test "$nls_cv_use_gnu_gettext" = "yes"; then
        dnl Mark actions used to generate GNU NLS library.
        BUILD_INCLUDED_LIBINTL=yes
        USE_INCLUDED_LIBINTL=yes
        LIBINTL="ifelse([$3],[],\${top_builddir}/intl,[$3])/libintl.[]gt_libtool_suffix_prefix[]a $LIBICONV $LIBTHREAD"
        LTLIBINTL="ifelse([$3],[],\${top_builddir}/intl,[$3])/libintl.[]gt_libtool_suffix_prefix[]a $LTLIBICONV $LTLIBTHREAD"
        LIBS=`echo " $LIBS " | sed -e 's/ -lintl / /' -e 's/^ //' -e 's/ $//'`
      fi

      CATOBJEXT=
      if test "$gt_use_preinstalled_gnugettext" = "yes" \
         || test "$nls_cv_use_gnu_gettext" = "yes"; then
        dnl Mark actions to use GNU gettext tools.
        CATOBJEXT=.gmo
      fi
    ])

    if test -n "$INTL_MACOSX_LIBS"; then
      if test "$gt_use_preinstalled_gnugettext" = "yes" \
         || test "$nls_cv_use_gnu_gettext" = "yes"; then
        dnl Some extra flags are needed during linking.
        LIBINTL="$LIBINTL $INTL_MACOSX_LIBS"
        LTLIBINTL="$LTLIBINTL $INTL_MACOSX_LIBS"
      fi
    fi

    if test "$gt_use_preinstalled_gnugettext" = "yes" \
       || test "$nls_cv_use_gnu_gettext" = "yes"; then
      AC_DEFINE([ENABLE_NLS], [1],
        [Define to 1 if translation of program messages to the user's native language
   is requested.])
    else
      USE_NLS=no
    fi
  fi

  AC_MSG_CHECKING([whether to use NLS])
  AC_MSG_RESULT([$USE_NLS])
  if test "$USE_NLS" = "yes"; then
    AC_MSG_CHECKING([where the gettext function comes from])
    if test "$gt_use_preinstalled_gnugettext" = "yes"; then
      if { eval "gt_val=\$$gt_func_gnugettext_libintl"; test "$gt_val" = "yes"; }; then
        gt_source="external libintl"
      else
        gt_source="libc"
      fi
    else
      gt_source="included intl directory"
    fi
    AC_MSG_RESULT([$gt_source])
  fi

  if test "$USE_NLS" = "yes"; then

    if test "$gt_use_preinstalled_gnugettext" = "yes"; then
      if { eval "gt_val=\$$gt_func_gnugettext_libintl"; test "$gt_val" = "yes"; }; then
        AC_MSG_CHECKING([how to link with libintl])
        AC_MSG_RESULT([$LIBINTL])
        AC_LIB_APPENDTOVAR([CPPFLAGS], [$INCINTL])
      fi

      dnl For backward compatibility. Some packages may be using this.
      AC_DEFINE([HAVE_GETTEXT], [1],
       [Define if the GNU gettext() function is already present or preinstalled.])
      AC_DEFINE([HAVE_DCGETTEXT], [1],
       [Define if the GNU dcgettext() function is already present or preinstalled.])
    fi

    dnl We need to process the po/ directory.
    POSUB=po
  fi

  ifelse(gt_included_intl, yes, [
    dnl If this is used in GNU gettext we have to set BUILD_INCLUDED_LIBINTL
    dnl to 'yes' because some of the testsuite requires it.
    if test "$PACKAGE" = gettext-runtime || test "$PACKAGE" = gettext-tools; then
      BUILD_INCLUDED_LIBINTL=yes
    fi

    dnl Make all variables we use known to autoconf.
    AC_SUBST([BUILD_INCLUDED_LIBINTL])
    AC_SUBST([USE_INCLUDED_LIBINTL])
    AC_SUBST([CATOBJEXT])

    dnl For backward compatibility. Some configure.ins may be using this.
    nls_cv_header_intl=
    nls_cv_header_libgt=

    dnl For backward compatibility. Some Makefiles may be using this.
    DATADIRNAME=share
    AC_SUBST([DATADIRNAME])

    dnl For backward compatibility. Some Makefiles may be using this.
    INSTOBJEXT=.mo
    AC_SUBST([INSTOBJEXT])

    dnl For backward compatibility. Some Makefiles may be using this.
    GENCAT=gencat
    AC_SUBST([GENCAT])

    dnl For backward compatibility. Some Makefiles may be using this.
    INTLOBJS=
    if test "$USE_INCLUDED_LIBINTL" = yes; then
      INTLOBJS="\$(GETTOBJS)"
    fi
    AC_SUBST([INTLOBJS])

    dnl Enable libtool support if the surrounding package wishes it.
    INTL_LIBTOOL_SUFFIX_PREFIX=gt_libtool_suffix_prefix
    AC_SUBST([INTL_LIBTOOL_SUFFIX_PREFIX])
  ])

  dnl For backward compatibility. Some Makefiles may be using this.
  INTLLIBS="$LIBINTL"
  AC_SUBST([INTLLIBS])

  dnl Make all documented variables known to autoconf.
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  AC_SUBST([POSUB])
])


dnl gt_NEEDS_INIT ensures that the gt_needs variable is initialized.
m4_define([gt_NEEDS_INIT],
[
  m4_divert_text([DEFAULTS], [gt_needs=])
  m4_define([gt_NEEDS_INIT], [])
])


dnl Usage: AM_GNU_GETTEXT_NEED([NEEDSYMBOL])
AC_DEFUN([AM_GNU_GETTEXT_NEED],
[
  m4_divert_text([INIT_PREPARE], [gt_needs="$gt_needs $1"])
])


dnl Usage: AM_GNU_GETTEXT_VERSION([gettext-version])
AC_DEFUN([AM_GNU_GETTEXT_VERSION], [])

# serial 15

# Copyright (C) 2001-2003, 2005, 2007, 2009-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

dnl From Jim Meyering.

AC_DEFUN([gl_FUNC_GETTIMEOFDAY],
[
  AC_REQUIRE([AC_C_RESTRICT])
  AC_REQUIRE([gl_HEADER_SYS_TIME_H])
  AC_REQUIRE([gl_HEADER_SYS_TIME_H_DEFAULTS])
  AC_CHECK_FUNCS_ONCE([gettimeofday])

  gl_gettimeofday_timezone=void
  if test $ac_cv_func_gettimeofday != yes; then
    HAVE_GETTIMEOFDAY=0
    AC_LIBOBJ([gettimeofday])
    gl_PREREQ_GETTIMEOFDAY
  else
    gl_FUNC_GETTIMEOFDAY_CLOBBER
    AC_CACHE_CHECK([for gettimeofday with POSIX signature],
      [gl_cv_func_gettimeofday_posix_signature],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM(
            [[#include <sys/time.h>
              struct timeval c;
              int gettimeofday (struct timeval *restrict, void *restrict);
            ]],
            [[/* glibc uses struct timezone * rather than the POSIX void *
                 if _GNU_SOURCE is defined.  However, since the only portable
                 use of gettimeofday uses NULL as the second parameter, and
                 since the glibc definition is actually more typesafe, it is
                 not worth wrapping this to get a compliant signature.  */
              int (*f) (struct timeval *restrict, void *restrict)
                = gettimeofday;
              int x = f (&c, 0);
              return !(x | c.tv_sec | c.tv_usec);
            ]])],
          [gl_cv_func_gettimeofday_posix_signature=yes],
          [AC_COMPILE_IFELSE(
            [AC_LANG_PROGRAM(
              [[#include <sys/time.h>
int gettimeofday (struct timeval *restrict, struct timezone *restrict);
              ]])],
            [gl_cv_func_gettimeofday_posix_signature=almost],
            [gl_cv_func_gettimeofday_posix_signature=no])])])
    if test $gl_cv_func_gettimeofday_posix_signature = almost; then
      gl_gettimeofday_timezone='struct timezone'
    elif test $gl_cv_func_gettimeofday_posix_signature != yes; then
      REPLACE_GETTIMEOFDAY=1
      AC_LIBOBJ([gettimeofday])
      gl_PREREQ_GETTIMEOFDAY
    fi
  fi
  AC_DEFINE_UNQUOTED([GETTIMEOFDAY_TIMEZONE], [$gl_gettimeofday_timezone],
    [Define this to 'void' or 'struct timezone' to match the system's
     declaration of the second argument to gettimeofday.])
])


dnl See if gettimeofday clobbers the static buffer that localtime uses
dnl for its return value.  The gettimeofday function from Mac OS X 10.0.4
dnl (i.e., Darwin 1.3.7) has this problem.
dnl
dnl If it does, then arrange to use gettimeofday and localtime only via
dnl the wrapper functions that work around the problem.

AC_DEFUN([gl_FUNC_GETTIMEOFDAY_CLOBBER],
[
 AC_REQUIRE([gl_HEADER_SYS_TIME_H])

 AC_CACHE_CHECK([whether gettimeofday clobbers localtime buffer],
  [gl_cv_func_gettimeofday_clobber],
  [AC_RUN_IFELSE(
     [AC_LANG_PROGRAM(
        [[#include <string.h>
          #include <sys/time.h>
          #include <time.h>
          #include <stdlib.h>
        ]],
        [[
          time_t t = 0;
          struct tm *lt;
          struct tm saved_lt;
          struct timeval tv;
          lt = localtime (&t);
          saved_lt = *lt;
          gettimeofday (&tv, NULL);
          return memcmp (lt, &saved_lt, sizeof (struct tm)) != 0;
        ]])],
     [gl_cv_func_gettimeofday_clobber=no],
     [gl_cv_func_gettimeofday_clobber=yes],
     dnl When crosscompiling, assume it is broken.
     [gl_cv_func_gettimeofday_clobber=yes])])

 if test $gl_cv_func_gettimeofday_clobber = yes; then
   REPLACE_GETTIMEOFDAY=1
   gl_GETTIMEOFDAY_REPLACE_LOCALTIME
   AC_DEFINE([GETTIMEOFDAY_CLOBBERS_LOCALTIME], [1],
     [Define if gettimeofday clobbers the localtime buffer.])
 fi
])

AC_DEFUN([gl_GETTIMEOFDAY_REPLACE_LOCALTIME], [
  AC_LIBOBJ([gettimeofday])
  gl_PREREQ_GETTIMEOFDAY
  AC_DEFINE([gmtime], [rpl_gmtime],
    [Define to rpl_gmtime if the replacement function should be used.])
  AC_DEFINE([localtime], [rpl_localtime],
    [Define to rpl_localtime if the replacement function should be used.])
])

# Prerequisites of lib/gettimeofday.c.
AC_DEFUN([gl_PREREQ_GETTIMEOFDAY], [
  AC_CHECK_HEADERS([sys/timeb.h])
  AC_CHECK_FUNCS([_ftime])
])

# glibc21.m4 serial 4
dnl Copyright (C) 2000-2002, 2004, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Test for the GNU C Library, version 2.1 or newer.
# From Bruno Haible.

AC_DEFUN([gl_GLIBC21],
  [
    AC_CACHE_CHECK([whether we are using the GNU C Library 2.1 or newer],
      [ac_cv_gnu_library_2_1],
      [AC_EGREP_CPP([Lucky GNU user],
        [
#include <features.h>
#ifdef __GNU_LIBRARY__
 #if (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1) || (__GLIBC__ > 2)
  Lucky GNU user
 #endif
#endif
        ],
        [ac_cv_gnu_library_2_1=yes],
        [ac_cv_gnu_library_2_1=no])
      ]
    )
    AC_SUBST([GLIBC21])
    GLIBC21="$ac_cv_gnu_library_2_1"
  ]
)

# Determine whether recent-enough GNU Make is being used.

# Copyright (C) 2007, 2009, 2010 Free Software Foundation, Inc.

# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# Written by Paul Eggert.

# Set GNU_MAKE if we are using a recent-enough version of GNU make.

# Use --version AND trailing junk, because SGI Make doesn't fail on --version.

AC_DEFUN([gl_GNU_MAKE],
[
  AM_CONDITIONAL([GNU_MAKE],
    [${MAKE-make} --version /cannot/make/this >/dev/null 2>&1])
])

# gnulib-common.m4 serial 20
dnl Copyright (C) 2007-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# gl_COMMON
# is expanded unconditionally through gnulib-tool magic.
AC_DEFUN([gl_COMMON], [
  dnl Use AC_REQUIRE here, so that the code is expanded once only.
  AC_REQUIRE([gl_00GNULIB])
  AC_REQUIRE([gl_COMMON_BODY])
])
AC_DEFUN([gl_COMMON_BODY], [
  AH_VERBATIM([isoc99_inline],
[/* Work around a bug in Apple GCC 4.0.1 build 5465: In C99 mode, it supports
   the ISO C 99 semantics of 'extern inline' (unlike the GNU C semantics of
   earlier versions), but does not display it by setting __GNUC_STDC_INLINE__.
   __APPLE__ && __MACH__ test for MacOS X.
   __APPLE_CC__ tests for the Apple compiler and its version.
   __STDC_VERSION__ tests for the C99 mode.  */
#if defined __APPLE__ && defined __MACH__ && __APPLE_CC__ >= 5465 && !defined __cplusplus && __STDC_VERSION__ >= 199901L && !defined __GNUC_STDC_INLINE__
# define __GNUC_STDC_INLINE__ 1
#endif])
  AH_VERBATIM([unused_parameter],
[/* Define as a marker that can be attached to declarations that might not
    be used.  This helps to reduce warnings, such as from
    GCC -Wunused-parameter.  */
#if __GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)
# define _GL_UNUSED __attribute__ ((__unused__))
#else
# define _GL_UNUSED
#endif
/* The name _UNUSED_PARAMETER_ is an earlier spelling, although the name
   is a misnomer outside of parameter lists.  */
#define _UNUSED_PARAMETER_ _GL_UNUSED
])
  dnl Preparation for running test programs:
  dnl Tell glibc to write diagnostics from -D_FORTIFY_SOURCE=2 to stderr, not
  dnl to /dev/tty, so they can be redirected to log files.  Such diagnostics
  dnl arise e.g., in the macros gl_PRINTF_DIRECTIVE_N, gl_SNPRINTF_DIRECTIVE_N.
  LIBC_FATAL_STDERR_=1
  export LIBC_FATAL_STDERR_
])

# gl_MODULE_INDICATOR_CONDITION
# expands to a C preprocessor expression that evaluates to 1 or 0, depending
# whether a gnulib module that has been requested shall be considered present
# or not.
AC_DEFUN([gl_MODULE_INDICATOR_CONDITION], [1])

# gl_MODULE_INDICATOR_SET_VARIABLE([modulename])
# sets the shell variable that indicates the presence of the given module to
# a C preprocessor expression that will evaluate to 1.
AC_DEFUN([gl_MODULE_INDICATOR_SET_VARIABLE],
[
  GNULIB_[]m4_translit([[$1]],
    [abcdefghijklmnopqrstuvwxyz./-],
    [ABCDEFGHIJKLMNOPQRSTUVWXYZ___])=gl_MODULE_INDICATOR_CONDITION
])

# gl_MODULE_INDICATOR([modulename])
# defines a C macro indicating the presence of the given module
# in a location where it can be used.
#                                             |  Value  |   Value   |
#                                             | in lib/ | in tests/ |
# --------------------------------------------+---------+-----------+
# Module present among main modules:          |    1    |     1     |
# --------------------------------------------+---------+-----------+
# Module present among tests-related modules: |    0    |     1     |
# --------------------------------------------+---------+-----------+
# Module not present at all:                  |    0    |     0     |
# --------------------------------------------+---------+-----------+
AC_DEFUN([gl_MODULE_INDICATOR],
[
  AC_DEFINE_UNQUOTED([GNULIB_]m4_translit([[$1]],
      [abcdefghijklmnopqrstuvwxyz./-],
      [ABCDEFGHIJKLMNOPQRSTUVWXYZ___]),
    [gl_MODULE_INDICATOR_CONDITION],
    [Define to a C preprocessor expression that evaluates to 1 or 0,
     depending whether the gnulib module $1 shall be considered present.])
])

# gl_MODULE_INDICATOR_FOR_TESTS([modulename])
# defines a C macro indicating the presence of the given module
# in lib or tests. This is useful to determine whether the module
# should be tested.
#                                             |  Value  |   Value   |
#                                             | in lib/ | in tests/ |
# --------------------------------------------+---------+-----------+
# Module present among main modules:          |    1    |     1     |
# --------------------------------------------+---------+-----------+
# Module present among tests-related modules: |    1    |     1     |
# --------------------------------------------+---------+-----------+
# Module not present at all:                  |    0    |     0     |
# --------------------------------------------+---------+-----------+
AC_DEFUN([gl_MODULE_INDICATOR_FOR_TESTS],
[
  AC_DEFINE([GNULIB_TEST_]m4_translit([[$1]],
      [abcdefghijklmnopqrstuvwxyz./-],
      [ABCDEFGHIJKLMNOPQRSTUVWXYZ___]), [1],
    [Define to 1 when the gnulib module $1 should be tested.])
])

# m4_foreach_w
# is a backport of autoconf-2.59c's m4_foreach_w.
# Remove this macro when we can assume autoconf >= 2.60.
m4_ifndef([m4_foreach_w],
  [m4_define([m4_foreach_w],
    [m4_foreach([$1], m4_split(m4_normalize([$2]), [ ]), [$3])])])

# AS_VAR_IF(VAR, VALUE, [IF-MATCH], [IF-NOT-MATCH])
# ----------------------------------------------------
# Backport of autoconf-2.63b's macro.
# Remove this macro when we can assume autoconf >= 2.64.
m4_ifndef([AS_VAR_IF],
[m4_define([AS_VAR_IF],
[AS_IF([test x"AS_VAR_GET([$1])" = x""$2], [$3], [$4])])])

# AC_PROG_MKDIR_P
# is a backport of autoconf-2.60's AC_PROG_MKDIR_P, with a fix
# for interoperability with automake-1.9.6 from autoconf-2.62.
# Remove this macro when we can assume autoconf >= 2.62 or
# autoconf >= 2.60 && automake >= 1.10.
m4_ifdef([AC_PROG_MKDIR_P], [
  dnl For automake-1.9.6 && autoconf < 2.62: Ensure MKDIR_P is AC_SUBSTed.
  m4_define([AC_PROG_MKDIR_P],
    m4_defn([AC_PROG_MKDIR_P])[
    AC_SUBST([MKDIR_P])])], [
  dnl For autoconf < 2.60: Backport of AC_PROG_MKDIR_P.
  AC_DEFUN_ONCE([AC_PROG_MKDIR_P],
    [AC_REQUIRE([AM_PROG_MKDIR_P])dnl defined by automake
     MKDIR_P='$(mkdir_p)'
     AC_SUBST([MKDIR_P])])])

# AC_C_RESTRICT
# This definition overrides the AC_C_RESTRICT macro from autoconf 2.60..2.61,
# so that mixed use of GNU C and GNU C++ and mixed use of Sun C and Sun C++
# works.
# This definition can be removed once autoconf >= 2.62 can be assumed.
m4_if(m4_version_compare(m4_defn([m4_PACKAGE_VERSION]),[2.62]),[-1],[
AC_DEFUN([AC_C_RESTRICT],
[AC_CACHE_CHECK([for C/C++ restrict keyword], [ac_cv_c_restrict],
  [ac_cv_c_restrict=no
   # The order here caters to the fact that C++ does not require restrict.
   for ac_kw in __restrict __restrict__ _Restrict restrict; do
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
      [[typedef int * int_ptr;
        int foo (int_ptr $ac_kw ip) {
        return ip[0];
       }]],
      [[int s[1];
        int * $ac_kw t = s;
        t[0] = 0;
        return foo(t)]])],
      [ac_cv_c_restrict=$ac_kw])
     test "$ac_cv_c_restrict" != no && break
   done
  ])
 AH_VERBATIM([restrict],
[/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#undef restrict
/* Work around a bug in Sun C++: it does not support _Restrict, even
   though the corresponding Sun C compiler does, which causes
   "#define restrict _Restrict" in the previous line.  Perhaps some future
   version of Sun C++ will work with _Restrict; if so, it'll probably
   define __RESTRICT, just as Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
#endif])
 case $ac_cv_c_restrict in
   restrict) ;;
   no) AC_DEFINE([restrict], []) ;;
   *)  AC_DEFINE_UNQUOTED([restrict], [$ac_cv_c_restrict]) ;;
 esac
])
])

# gl_BIGENDIAN
# is like AC_C_BIGENDIAN, except that it can be AC_REQUIREd.
# Note that AC_REQUIRE([AC_C_BIGENDIAN]) does not work reliably because some
# macros invoke AC_C_BIGENDIAN with arguments.
AC_DEFUN([gl_BIGENDIAN],
[
  AC_C_BIGENDIAN
])

# gl_CACHE_VAL_SILENT(cache-id, command-to-set-it)
# is like AC_CACHE_VAL(cache-id, command-to-set-it), except that it does not
# output a spurious "(cached)" mark in the midst of other configure output.
# This macro should be used instead of AC_CACHE_VAL when it is not surrounded
# by an AC_MSG_CHECKING/AC_MSG_RESULT pair.
AC_DEFUN([gl_CACHE_VAL_SILENT],
[
  saved_as_echo_n="$as_echo_n"
  as_echo_n=':'
  AC_CACHE_VAL([$1], [$2])
  as_echo_n="$saved_as_echo_n"
])

# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2010 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  AC_REQUIRE([AM_PROG_CC_C_O])
  # Code from module alloca:
  # Code from module alloca-opt:
  # Code from module arg-nonnull:
  # Code from module c++defs:
  # Code from module configmake:
  # Code from module extensions:
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
  # Code from module getpagesize:
  # Code from module gettext:
  # Code from module gettext-h:
  # Code from module gettimeofday:
  # Code from module gnu-make:
  # Code from module havelib:
  # Code from module include_next:
  # Code from module langinfo:
  # Code from module libsigsegv:
  # Code from module link-follow:
  # Code from module localcharset:
  # Code from module mbrtowc:
  # Code from module mbsinit:
  # Code from module mbsrtowcs:
  # Code from module memchr:
  # Code from module multiarch:
  # Code from module nl_langinfo:
  # Code from module no-c++:
  # Code from module nocrash:
  # Code from module stdbool:
  # Code from module stddef:
  # Code from module stdint:
  # Code from module streq:
  # Code from module string:
  # Code from module strnlen1:
  # Code from module sys_time:
  # Code from module uniname/base:
  # Code from module uniname/uniname:
  # Code from module unistd:
  # Code from module unitypes:
  # Code from module uniwidth/base:
  # Code from module uniwidth/width:
  # Code from module verify:
  # Code from module warn-on-use:
  # Code from module wchar:
  # Code from module wctype:
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  gl_m4_base='src/glm4'
  m4_pushdef([AC_LIBOBJ], m4_defn([gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gl_LIBSOURCES]))
  m4_pushdef([gl_LIBSOURCES_LIST], [])
  m4_pushdef([gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='src/gllib'
  # Code from module alloca:
  # Code from module alloca-opt:
  gl_FUNC_ALLOCA
  # Code from module arg-nonnull:
  # Code from module c++defs:
  # Code from module configmake:
  # Code from module extensions:
  # Code from module getpagesize:
  gl_FUNC_GETPAGESIZE
  gl_UNISTD_MODULE_INDICATOR([getpagesize])
  # Code from module gettext:
  dnl you must add AM_GNU_GETTEXT([external]) or similar to configure.ac.
  AM_GNU_GETTEXT_VERSION([0.18.1])
  # Code from module gettext-h:
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  # Code from module gettimeofday:
  gl_FUNC_GETTIMEOFDAY
  gl_SYS_TIME_MODULE_INDICATOR([gettimeofday])
  # Code from module gnu-make:
  gl_GNU_MAKE
  # Code from module havelib:
  # Code from module include_next:
  # Code from module langinfo:
  gl_LANGINFO_H
  # Code from module libsigsegv:
  gl_LIBSIGSEGV
  # Code from module link-follow:
  gl_FUNC_LINK_FOLLOWS_SYMLINK
  # Code from module localcharset:
  gl_LOCALCHARSET
  LOCALCHARSET_TESTS_ENVIRONMENT="CHARSETALIASDIR=\"\$(top_builddir)/$gl_source_base\""
  AC_SUBST([LOCALCHARSET_TESTS_ENVIRONMENT])
  # Code from module mbrtowc:
  gl_FUNC_MBRTOWC
  gl_WCHAR_MODULE_INDICATOR([mbrtowc])
  # Code from module mbsinit:
  gl_FUNC_MBSINIT
  gl_WCHAR_MODULE_INDICATOR([mbsinit])
  # Code from module mbsrtowcs:
  gl_FUNC_MBSRTOWCS
  gl_WCHAR_MODULE_INDICATOR([mbsrtowcs])
  # Code from module memchr:
  gl_FUNC_MEMCHR
  gl_STRING_MODULE_INDICATOR([memchr])
  # Code from module multiarch:
  gl_MULTIARCH
  # Code from module nl_langinfo:
  gl_FUNC_NL_LANGINFO
  gl_LANGINFO_MODULE_INDICATOR([nl_langinfo])
  # Code from module no-c++:
  gt_NO_CXX
  # Code from module nocrash:
  # Code from module stdbool:
  AM_STDBOOL_H
  # Code from module stddef:
  gl_STDDEF_H
  # Code from module stdint:
  gl_STDINT_H
  # Code from module streq:
  # Code from module string:
  gl_HEADER_STRING_H
  # Code from module strnlen1:
  # Code from module sys_time:
  gl_HEADER_SYS_TIME_H
  AC_PROG_MKDIR_P
  # Code from module uniname/base:
  gl_LIBUNISTRING_LIBHEADER([0.9], [uniname.h])
  # Code from module uniname/uniname:
  gl_LIBUNISTRING_MODULE([0.9], [uniname/uniname])
  # Code from module unistd:
  gl_UNISTD_H
  # Code from module unitypes:
  gl_LIBUNISTRING_LIBHEADER([0.9], [unitypes.h])
  # Code from module uniwidth/base:
  gl_LIBUNISTRING_LIBHEADER([0.9], [uniwidth.h])
  # Code from module uniwidth/width:
  gl_LIBUNISTRING_MODULE([0.9], [uniwidth/width])
  # Code from module verify:
  # Code from module warn-on-use:
  # Code from module wchar:
  gl_WCHAR_H
  # Code from module wctype:
  gl_WCTYPE_H
  # End of code from modules
  m4_ifval(gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gl_LIBSOURCES_DIR])
  m4_popdef([gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gl_libobjs=
    gl_ltlibobjs=
    if test -n "$gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gl_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        gl_libobjs="$gl_libobjs $i.$ac_objext"
        gl_ltlibobjs="$gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gl_LIBOBJS], [$gl_libobjs])
    AC_SUBST([gl_LTLIBOBJS], [$gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gltests_LIBSOURCES]))
  m4_pushdef([gltests_LIBSOURCES_LIST], [])
  m4_pushdef([gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
changequote(,)dnl
  gltests_WITNESS=IN_`echo "${PACKAGE-$PACKAGE_TARNAME}" | LC_ALL=C tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ | LC_ALL=C sed -e 's/[^A-Z0-9_]/_/g'`_GNULIB_TESTS
changequote([, ])dnl
  AC_SUBST([gltests_WITNESS])
  gl_module_indicator_condition=$gltests_WITNESS
  m4_pushdef([gl_MODULE_INDICATOR_CONDITION], [$gl_module_indicator_condition])
  m4_popdef([gl_MODULE_INDICATOR_CONDITION])
  m4_ifval(gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gltests_LIBSOURCES_DIR])
  m4_popdef([gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gltests_libobjs=
    gltests_ltlibobjs=
    if test -n "$gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gltests_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        gltests_libobjs="$gltests_libobjs $i.$ac_objext"
        gltests_ltlibobjs="$gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gltests_LIBOBJS], [$gltests_libobjs])
    AC_SUBST([gltests_LTLIBOBJS], [$gltests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [gl_LIBSOURCES([$1.c])])dnl
  gl_LIBOBJS="$gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gl_LIBSOURCES_DIR], [src/gllib])
      m4_append([gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [gltests_LIBSOURCES([$1.c])])dnl
  gltests_LIBOBJS="$gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gltests_LIBSOURCES_DIR], [tests])
      m4_append([gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([gl_FILE_LIST], [
  build-aux/arg-nonnull.h
  build-aux/c++defs.h
  build-aux/config.rpath
  build-aux/warn-on-use.h
  lib/alloca.c
  lib/alloca.in.h
  lib/config.charset
  lib/getpagesize.c
  lib/gettext.h
  lib/gettimeofday.c
  lib/langinfo.in.h
  lib/localcharset.c
  lib/localcharset.h
  lib/mbrtowc.c
  lib/mbsinit.c
  lib/mbsrtowcs-state.c
  lib/mbsrtowcs.c
  lib/memchr.c
  lib/memchr.valgrind
  lib/nl_langinfo.c
  lib/ref-add.sin
  lib/ref-del.sin
  lib/stdbool.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/streq.h
  lib/string.in.h
  lib/strnlen1.c
  lib/strnlen1.h
  lib/sys_time.in.h
  lib/uniname.in.h
  lib/uniname/gen-uninames.lisp
  lib/uniname/uniname.c
  lib/uniname/uninames.h
  lib/unistd.in.h
  lib/unitypes.in.h
  lib/uniwidth.in.h
  lib/uniwidth/cjk.h
  lib/uniwidth/width.c
  lib/verify.h
  lib/wchar.in.h
  lib/wctype.in.h
  m4/00gnulib.m4
  m4/alloca.m4
  m4/codeset.m4
  m4/extensions.m4
  m4/fcntl-o.m4
  m4/getpagesize.m4
  m4/gettext.m4
  m4/gettimeofday.m4
  m4/glibc2.m4
  m4/glibc21.m4
  m4/gnu-make.m4
  m4/gnulib-common.m4
  m4/iconv.m4
  m4/include_next.m4
  m4/intdiv0.m4
  m4/intl.m4
  m4/intldir.m4
  m4/intlmacosx.m4
  m4/intmax.m4
  m4/inttypes-pri.m4
  m4/inttypes_h.m4
  m4/langinfo_h.m4
  m4/lcmessage.m4
  m4/lib-ld.m4
  m4/lib-link.m4
  m4/lib-prefix.m4
  m4/libsigsegv.m4
  m4/libunistring-base.m4
  m4/link-follow.m4
  m4/localcharset.m4
  m4/locale-fr.m4
  m4/locale-ja.m4
  m4/locale-zh.m4
  m4/lock.m4
  m4/longlong.m4
  m4/mbrtowc.m4
  m4/mbsinit.m4
  m4/mbsrtowcs.m4
  m4/mbstate_t.m4
  m4/memchr.m4
  m4/mmap-anon.m4
  m4/multiarch.m4
  m4/nl_langinfo.m4
  m4/nls.m4
  m4/no-c++.m4
  m4/nocrash.m4
  m4/po.m4
  m4/printf-posix.m4
  m4/progtest.m4
  m4/size_max.m4
  m4/stdbool.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/stdint_h.m4
  m4/string_h.m4
  m4/sys_time_h.m4
  m4/threadlib.m4
  m4/uintmax_t.m4
  m4/unistd_h.m4
  m4/visibility.m4
  m4/warn-on-use.m4
  m4/wchar_h.m4
  m4/wchar_t.m4
  m4/wctype_h.m4
  m4/wint_t.m4
  m4/xsize.m4
])

# iconv.m4 serial 11 (gettext-0.18.1)
dnl Copyright (C) 2000-2002, 2007-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

AC_DEFUN([AM_ICONV_LINKFLAGS_BODY],
[
  dnl Prerequisites of AC_LIB_LINKFLAGS_BODY.
  AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
  AC_REQUIRE([AC_LIB_RPATH])

  dnl Search for libiconv and define LIBICONV, LTLIBICONV and INCICONV
  dnl accordingly.
  AC_LIB_LINKFLAGS_BODY([iconv])
])

AC_DEFUN([AM_ICONV_LINK],
[
  dnl Some systems have iconv in libc, some have it in libiconv (OSF/1 and
  dnl those with the standalone portable GNU libiconv installed).
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles

  dnl Search for libiconv and define LIBICONV, LTLIBICONV and INCICONV
  dnl accordingly.
  AC_REQUIRE([AM_ICONV_LINKFLAGS_BODY])

  dnl Add $INCICONV to CPPFLAGS before performing the following checks,
  dnl because if the user has installed libiconv and not disabled its use
  dnl via --without-libiconv-prefix, he wants to use it. The first
  dnl AC_TRY_LINK will then fail, the second AC_TRY_LINK will succeed.
  am_save_CPPFLAGS="$CPPFLAGS"
  AC_LIB_APPENDTOVAR([CPPFLAGS], [$INCICONV])

  AC_CACHE_CHECK([for iconv], [am_cv_func_iconv], [
    am_cv_func_iconv="no, consider installing GNU libiconv"
    am_cv_lib_iconv=no
    AC_TRY_LINK([#include <stdlib.h>
#include <iconv.h>],
      [iconv_t cd = iconv_open("","");
       iconv(cd,NULL,NULL,NULL,NULL);
       iconv_close(cd);],
      [am_cv_func_iconv=yes])
    if test "$am_cv_func_iconv" != yes; then
      am_save_LIBS="$LIBS"
      LIBS="$LIBS $LIBICONV"
      AC_TRY_LINK([#include <stdlib.h>
#include <iconv.h>],
        [iconv_t cd = iconv_open("","");
         iconv(cd,NULL,NULL,NULL,NULL);
         iconv_close(cd);],
        [am_cv_lib_iconv=yes]
        [am_cv_func_iconv=yes])
      LIBS="$am_save_LIBS"
    fi
  ])
  if test "$am_cv_func_iconv" = yes; then
    AC_CACHE_CHECK([for working iconv], [am_cv_func_iconv_works], [
      dnl This tests against bugs in AIX 5.1, HP-UX 11.11, Solaris 10.
      am_save_LIBS="$LIBS"
      if test $am_cv_lib_iconv = yes; then
        LIBS="$LIBS $LIBICONV"
      fi
      AC_TRY_RUN([
#include <iconv.h>
#include <string.h>
int main ()
{
  /* Test against AIX 5.1 bug: Failures are not distinguishable from successful
     returns.  */
  {
    iconv_t cd_utf8_to_88591 = iconv_open ("ISO8859-1", "UTF-8");
    if (cd_utf8_to_88591 != (iconv_t)(-1))
      {
        static const char input[] = "\342\202\254"; /* EURO SIGN */
        char buf[10];
        const char *inptr = input;
        size_t inbytesleft = strlen (input);
        char *outptr = buf;
        size_t outbytesleft = sizeof (buf);
        size_t res = iconv (cd_utf8_to_88591,
                            (char **) &inptr, &inbytesleft,
                            &outptr, &outbytesleft);
        if (res == 0)
          return 1;
      }
  }
  /* Test against Solaris 10 bug: Failures are not distinguishable from
     successful returns.  */
  {
    iconv_t cd_ascii_to_88591 = iconv_open ("ISO8859-1", "646");
    if (cd_ascii_to_88591 != (iconv_t)(-1))
      {
        static const char input[] = "\263";
        char buf[10];
        const char *inptr = input;
        size_t inbytesleft = strlen (input);
        char *outptr = buf;
        size_t outbytesleft = sizeof (buf);
        size_t res = iconv (cd_ascii_to_88591,
                            (char **) &inptr, &inbytesleft,
                            &outptr, &outbytesleft);
        if (res == 0)
          return 1;
      }
  }
#if 0 /* This bug could be worked around by the caller.  */
  /* Test against HP-UX 11.11 bug: Positive return value instead of 0.  */
  {
    iconv_t cd_88591_to_utf8 = iconv_open ("utf8", "iso88591");
    if (cd_88591_to_utf8 != (iconv_t)(-1))
      {
        static const char input[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
        char buf[50];
        const char *inptr = input;
        size_t inbytesleft = strlen (input);
        char *outptr = buf;
        size_t outbytesleft = sizeof (buf);
        size_t res = iconv (cd_88591_to_utf8,
                            (char **) &inptr, &inbytesleft,
                            &outptr, &outbytesleft);
        if ((int)res > 0)
          return 1;
      }
  }
#endif
  /* Test against HP-UX 11.11 bug: No converter from EUC-JP to UTF-8 is
     provided.  */
  if (/* Try standardized names.  */
      iconv_open ("UTF-8", "EUC-JP") == (iconv_t)(-1)
      /* Try IRIX, OSF/1 names.  */
      && iconv_open ("UTF-8", "eucJP") == (iconv_t)(-1)
      /* Try AIX names.  */
      && iconv_open ("UTF-8", "IBM-eucJP") == (iconv_t)(-1)
      /* Try HP-UX names.  */
      && iconv_open ("utf8", "eucJP") == (iconv_t)(-1))
    return 1;
  return 0;
}], [am_cv_func_iconv_works=yes], [am_cv_func_iconv_works=no],
        [case "$host_os" in
           aix* | hpux*) am_cv_func_iconv_works="guessing no" ;;
           *)            am_cv_func_iconv_works="guessing yes" ;;
         esac])
      LIBS="$am_save_LIBS"
    ])
    case "$am_cv_func_iconv_works" in
      *no) am_func_iconv=no am_cv_lib_iconv=no ;;
      *)   am_func_iconv=yes ;;
    esac
  else
    am_func_iconv=no am_cv_lib_iconv=no
  fi
  if test "$am_func_iconv" = yes; then
    AC_DEFINE([HAVE_ICONV], [1],
      [Define if you have the iconv() function and it works.])
  fi
  if test "$am_cv_lib_iconv" = yes; then
    AC_MSG_CHECKING([how to link with libiconv])
    AC_MSG_RESULT([$LIBICONV])
  else
    dnl If $LIBICONV didn't lead to a usable library, we don't need $INCICONV
    dnl either.
    CPPFLAGS="$am_save_CPPFLAGS"
    LIBICONV=
    LTLIBICONV=
  fi
  AC_SUBST([LIBICONV])
  AC_SUBST([LTLIBICONV])
])

dnl Define AM_ICONV using AC_DEFUN_ONCE for Autoconf >= 2.64, in order to
dnl avoid warnings like
dnl "warning: AC_REQUIRE: `AM_ICONV' was expanded before it was required".
dnl This is tricky because of the way 'aclocal' is implemented:
dnl - It requires defining an auxiliary macro whose name ends in AC_DEFUN.
dnl   Otherwise aclocal's initial scan pass would miss the macro definition.
dnl - It requires a line break inside the AC_DEFUN_ONCE and AC_DEFUN expansions.
dnl   Otherwise aclocal would emit many "Use of uninitialized value $1"
dnl   warnings.
m4_define([gl_iconv_AC_DEFUN],
  m4_version_prereq([2.64],
    [[AC_DEFUN_ONCE(
        [$1], [$2])]],
    [[AC_DEFUN(
        [$1], [$2])]]))
gl_iconv_AC_DEFUN([AM_ICONV],
[
  AM_ICONV_LINK
  if test "$am_cv_func_iconv" = yes; then
    AC_MSG_CHECKING([for iconv declaration])
    AC_CACHE_VAL([am_cv_proto_iconv], [
      AC_TRY_COMPILE([
#include <stdlib.h>
#include <iconv.h>
extern
#ifdef __cplusplus
"C"
#endif
#if defined(__STDC__) || defined(__cplusplus)
size_t iconv (iconv_t cd, char * *inbuf, size_t *inbytesleft, char * *outbuf, size_t *outbytesleft);
#else
size_t iconv();
#endif
], [], [am_cv_proto_iconv_arg1=""], [am_cv_proto_iconv_arg1="const"])
      am_cv_proto_iconv="extern size_t iconv (iconv_t cd, $am_cv_proto_iconv_arg1 char * *inbuf, size_t *inbytesleft, char * *outbuf, size_t *outbytesleft);"])
    am_cv_proto_iconv=`echo "[$]am_cv_proto_iconv" | tr -s ' ' | sed -e 's/( /(/'`
    AC_MSG_RESULT([
         $am_cv_proto_iconv])
    AC_DEFINE_UNQUOTED([ICONV_CONST], [$am_cv_proto_iconv_arg1],
      [Define as const if the declaration of iconv() needs const.])
  fi
])

# include_next.m4 serial 14
dnl Copyright (C) 2006-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Paul Eggert and Derek Price.

dnl Sets INCLUDE_NEXT and PRAGMA_SYSTEM_HEADER.
dnl
dnl INCLUDE_NEXT expands to 'include_next' if the compiler supports it, or to
dnl 'include' otherwise.
dnl
dnl INCLUDE_NEXT_AS_FIRST_DIRECTIVE expands to 'include_next' if the compiler
dnl supports it in the special case that it is the first include directive in
dnl the given file, or to 'include' otherwise.
dnl
dnl PRAGMA_SYSTEM_HEADER can be used in files that contain #include_next,
dnl so as to avoid GCC warnings when the gcc option -pedantic is used.
dnl '#pragma GCC system_header' has the same effect as if the file was found
dnl through the include search path specified with '-isystem' options (as
dnl opposed to the search path specified with '-I' options). Namely, gcc
dnl does not warn about some things, and on some systems (Solaris and Interix)
dnl __STDC__ evaluates to 0 instead of to 1. The latter is an undesired side
dnl effect; we are therefore careful to use 'defined __STDC__' or '1' instead
dnl of plain '__STDC__'.

AC_DEFUN([gl_INCLUDE_NEXT],
[
  AC_LANG_PREPROC_REQUIRE()
  AC_CACHE_CHECK([whether the preprocessor supports include_next],
    [gl_cv_have_include_next],
    [rm -rf conftestd1a conftestd1b conftestd2
     mkdir conftestd1a conftestd1b conftestd2
     dnl IBM C 9.0, 10.1 (original versions, prior to the 2009-01 updates) on
     dnl AIX 6.1 support include_next when used as first preprocessor directive
     dnl in a file, but not when preceded by another include directive. Check
     dnl for this bug by including <stdio.h>.
     dnl Additionally, with this same compiler, include_next is a no-op when
     dnl used in a header file that was included by specifying its absolute
     dnl file name. Despite these two bugs, include_next is used in the
     dnl compiler's <math.h>. By virtue of the second bug, we need to use
     dnl include_next as well in this case.
     cat <<EOF > conftestd1a/conftest.h
#define DEFINED_IN_CONFTESTD1
#include_next <conftest.h>
#ifdef DEFINED_IN_CONFTESTD2
int foo;
#else
#error "include_next doesn't work"
#endif
EOF
     cat <<EOF > conftestd1b/conftest.h
#define DEFINED_IN_CONFTESTD1
#include <stdio.h>
#include_next <conftest.h>
#ifdef DEFINED_IN_CONFTESTD2
int foo;
#else
#error "include_next doesn't work"
#endif
EOF
     cat <<EOF > conftestd2/conftest.h
#ifndef DEFINED_IN_CONFTESTD1
#error "include_next test doesn't work"
#endif
#define DEFINED_IN_CONFTESTD2
EOF
     gl_save_CPPFLAGS="$CPPFLAGS"
     CPPFLAGS="$gl_save_CPPFLAGS -Iconftestd1b -Iconftestd2"
     AC_COMPILE_IFELSE([#include <conftest.h>],
       [gl_cv_have_include_next=yes],
       [CPPFLAGS="$gl_save_CPPFLAGS -Iconftestd1a -Iconftestd2"
        AC_COMPILE_IFELSE([#include <conftest.h>],
          [gl_cv_have_include_next=buggy],
          [gl_cv_have_include_next=no])
       ])
     CPPFLAGS="$gl_save_CPPFLAGS"
     rm -rf conftestd1a conftestd1b conftestd2
    ])
  PRAGMA_SYSTEM_HEADER=
  if test $gl_cv_have_include_next = yes; then
    INCLUDE_NEXT=include_next
    INCLUDE_NEXT_AS_FIRST_DIRECTIVE=include_next
    if test -n "$GCC"; then
      PRAGMA_SYSTEM_HEADER='#pragma GCC system_header'
    fi
  else
    if test $gl_cv_have_include_next = buggy; then
      INCLUDE_NEXT=include
      INCLUDE_NEXT_AS_FIRST_DIRECTIVE=include_next
    else
      INCLUDE_NEXT=include
      INCLUDE_NEXT_AS_FIRST_DIRECTIVE=include
    fi
  fi
  AC_SUBST([INCLUDE_NEXT])
  AC_SUBST([INCLUDE_NEXT_AS_FIRST_DIRECTIVE])
  AC_SUBST([PRAGMA_SYSTEM_HEADER])
])

# gl_CHECK_NEXT_HEADERS(HEADER1 HEADER2 ...)
# ------------------------------------------
# For each arg foo.h, if #include_next works, define NEXT_FOO_H to be
# '<foo.h>'; otherwise define it to be
# '"///usr/include/foo.h"', or whatever other absolute file name is suitable.
# Also, if #include_next works as first preprocessing directive in a file,
# define NEXT_AS_FIRST_DIRECTIVE_FOO_H to be '<foo.h>'; otherwise define it to
# be
# '"///usr/include/foo.h"', or whatever other absolute file name is suitable.
# That way, a header file with the following line:
#       #@INCLUDE_NEXT@ @NEXT_FOO_H@
# or
#       #@INCLUDE_NEXT_AS_FIRST_DIRECTIVE@ @NEXT_AS_FIRST_DIRECTIVE_FOO_H@
# behaves (after sed substitution) as if it contained
#       #include_next <foo.h>
# even if the compiler does not support include_next.
# The three "///" are to pacify Sun C 5.8, which otherwise would say
# "warning: #include of /usr/include/... may be non-portable".
# Use `""', not `<>', so that the /// cannot be confused with a C99 comment.
# Note: This macro assumes that the header file is not empty after
# preprocessing, i.e. it does not only define preprocessor macros but also
# provides some type/enum definitions or function/variable declarations.
AC_DEFUN([gl_CHECK_NEXT_HEADERS],
[
  AC_REQUIRE([gl_INCLUDE_NEXT])
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_CHECK_HEADERS_ONCE([$1])

  m4_foreach_w([gl_HEADER_NAME], [$1],
    [AS_VAR_PUSHDEF([gl_next_header],
                    [gl_cv_next_]m4_defn([gl_HEADER_NAME]))
     if test $gl_cv_have_include_next = yes; then
       AS_VAR_SET([gl_next_header], ['<'gl_HEADER_NAME'>'])
     else
       AC_CACHE_CHECK(
         [absolute name of <]m4_defn([gl_HEADER_NAME])[>],
         m4_defn([gl_next_header]),
         [AS_VAR_PUSHDEF([gl_header_exists],
                         [ac_cv_header_]m4_defn([gl_HEADER_NAME]))
          if test AS_VAR_GET(gl_header_exists) = yes; then
            AC_LANG_CONFTEST(
              [AC_LANG_SOURCE(
                 [[#include <]]m4_dquote(m4_defn([gl_HEADER_NAME]))[[>]]
               )])
            dnl AIX "xlc -E" and "cc -E" omit #line directives for header files
            dnl that contain only a #include of other header files and no
            dnl non-comment tokens of their own. This leads to a failure to
            dnl detect the absolute name of <dirent.h>, <signal.h>, <poll.h>
            dnl and others. The workaround is to force preservation of comments
            dnl through option -C. This ensures all necessary #line directives
            dnl are present. GCC supports option -C as well.
            case "$host_os" in
              aix*) gl_absname_cpp="$ac_cpp -C" ;;
              *)    gl_absname_cpp="$ac_cpp" ;;
            esac
            dnl eval is necessary to expand gl_absname_cpp.
            dnl Ultrix and Pyramid sh refuse to redirect output of eval,
            dnl so use subshell.
            AS_VAR_SET([gl_next_header],
              ['"'`(eval "$gl_absname_cpp conftest.$ac_ext") 2>&AS_MESSAGE_LOG_FD |
               sed -n '\#/]m4_defn([gl_HEADER_NAME])[#{
                 s#.*"\(.*/]m4_defn([gl_HEADER_NAME])[\)".*#\1#
                 s#^/[^/]#//&#
                 p
                 q
               }'`'"'])
          else
            AS_VAR_SET([gl_next_header], ['<'gl_HEADER_NAME'>'])
          fi
          AS_VAR_POPDEF([gl_header_exists])])
     fi
     AC_SUBST(
       AS_TR_CPP([NEXT_]m4_defn([gl_HEADER_NAME])),
       [AS_VAR_GET([gl_next_header])])
     if test $gl_cv_have_include_next = yes || test $gl_cv_have_include_next = buggy; then
       # INCLUDE_NEXT_AS_FIRST_DIRECTIVE='include_next'
       gl_next_as_first_directive='<'gl_HEADER_NAME'>'
     else
       # INCLUDE_NEXT_AS_FIRST_DIRECTIVE='include'
       gl_next_as_first_directive=AS_VAR_GET([gl_next_header])
     fi
     AC_SUBST(
       AS_TR_CPP([NEXT_AS_FIRST_DIRECTIVE_]m4_defn([gl_HEADER_NAME])),
       [$gl_next_as_first_directive])
     AS_VAR_POPDEF([gl_next_header])])
])

# intlmacosx.m4 serial 3 (gettext-0.18)
dnl Copyright (C) 2004-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Checks for special options needed on MacOS X.
dnl Defines INTL_MACOSX_LIBS.
AC_DEFUN([gt_INTL_MACOSX],
[
  dnl Check for API introduced in MacOS X 10.2.
  AC_CACHE_CHECK([for CFPreferencesCopyAppValue],
    [gt_cv_func_CFPreferencesCopyAppValue],
    [gt_save_LIBS="$LIBS"
     LIBS="$LIBS -Wl,-framework -Wl,CoreFoundation"
     AC_TRY_LINK([#include <CoreFoundation/CFPreferences.h>],
       [CFPreferencesCopyAppValue(NULL, NULL)],
       [gt_cv_func_CFPreferencesCopyAppValue=yes],
       [gt_cv_func_CFPreferencesCopyAppValue=no])
     LIBS="$gt_save_LIBS"])
  if test $gt_cv_func_CFPreferencesCopyAppValue = yes; then
    AC_DEFINE([HAVE_CFPREFERENCESCOPYAPPVALUE], [1],
      [Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in the CoreFoundation framework.])
  fi
  dnl Check for API introduced in MacOS X 10.3.
  AC_CACHE_CHECK([for CFLocaleCopyCurrent], [gt_cv_func_CFLocaleCopyCurrent],
    [gt_save_LIBS="$LIBS"
     LIBS="$LIBS -Wl,-framework -Wl,CoreFoundation"
     AC_TRY_LINK([#include <CoreFoundation/CFLocale.h>], [CFLocaleCopyCurrent();],
       [gt_cv_func_CFLocaleCopyCurrent=yes],
       [gt_cv_func_CFLocaleCopyCurrent=no])
     LIBS="$gt_save_LIBS"])
  if test $gt_cv_func_CFLocaleCopyCurrent = yes; then
    AC_DEFINE([HAVE_CFLOCALECOPYCURRENT], [1],
      [Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the CoreFoundation framework.])
  fi
  INTL_MACOSX_LIBS=
  if test $gt_cv_func_CFPreferencesCopyAppValue = yes || test $gt_cv_func_CFLocaleCopyCurrent = yes; then
    INTL_MACOSX_LIBS="-Wl,-framework -Wl,CoreFoundation"
  fi
  AC_SUBST([INTL_MACOSX_LIBS])
])

# langinfo_h.m4 serial 6
dnl Copyright (C) 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_LANGINFO_H],
[
  AC_REQUIRE([gl_LANGINFO_H_DEFAULTS])

  dnl Persuade glibc-2.0.6 <langinfo.h> to define CODESET.
  AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])

  dnl <langinfo.h> is always overridden, because of GNULIB_POSIXCHECK.
  gl_CHECK_NEXT_HEADERS([langinfo.h])

  dnl Determine whether <langinfo.h> exists. It is missing on mingw and BeOS.
  HAVE_LANGINFO_CODESET=0
  HAVE_LANGINFO_ERA=0
  AC_CHECK_HEADERS_ONCE([langinfo.h])
  if test $ac_cv_header_langinfo_h = yes; then
    HAVE_LANGINFO_H=1
    dnl Determine what <langinfo.h> defines. CODESET and ERA etc. are missing
    dnl on OpenBSD 3.8.
    AC_CACHE_CHECK([whether langinfo.h defines CODESET],
      [gl_cv_header_langinfo_codeset],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM([[#include <langinfo.h>
int a = CODESET;
]])],
         [gl_cv_header_langinfo_codeset=yes],
         [gl_cv_header_langinfo_codeset=no])
      ])
    if test $gl_cv_header_langinfo_codeset = yes; then
      HAVE_LANGINFO_CODESET=1
    fi
    AC_CACHE_CHECK([whether langinfo.h defines ERA],
      [gl_cv_header_langinfo_era],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM([[#include <langinfo.h>
int a = ERA;
]])],
         [gl_cv_header_langinfo_era=yes],
         [gl_cv_header_langinfo_era=no])
      ])
    if test $gl_cv_header_langinfo_era = yes; then
      HAVE_LANGINFO_ERA=1
    fi
  else
    HAVE_LANGINFO_H=0
  fi
  AC_SUBST([HAVE_LANGINFO_H])
  AC_SUBST([HAVE_LANGINFO_CODESET])
  AC_SUBST([HAVE_LANGINFO_ERA])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[#include <langinfo.h>
    ]], [nl_langinfo])
])

AC_DEFUN([gl_LANGINFO_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_LANGINFO_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_LANGINFO_H_DEFAULTS],
[
  GNULIB_NL_LANGINFO=0;  AC_SUBST([GNULIB_NL_LANGINFO])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_NL_LANGINFO=1;    AC_SUBST([HAVE_NL_LANGINFO])
  REPLACE_NL_LANGINFO=0; AC_SUBST([REPLACE_NL_LANGINFO])
])

# lcmessage.m4 serial 6 (gettext-0.18)
dnl Copyright (C) 1995-2002, 2004-2005, 2008-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Authors:
dnl   Ulrich Drepper <drepper@cygnus.com>, 1995.

# Check whether LC_MESSAGES is available in <locale.h>.

AC_DEFUN([gt_LC_MESSAGES],
[
  AC_CACHE_CHECK([for LC_MESSAGES], [gt_cv_val_LC_MESSAGES],
    [AC_TRY_LINK([#include <locale.h>], [return LC_MESSAGES],
       [gt_cv_val_LC_MESSAGES=yes], [gt_cv_val_LC_MESSAGES=no])])
  if test $gt_cv_val_LC_MESSAGES = yes; then
    AC_DEFINE([HAVE_LC_MESSAGES], [1],
      [Define if your <locale.h> file defines LC_MESSAGES.])
  fi
])

# lib-ld.m4 serial 4 (gettext-0.18)
dnl Copyright (C) 1996-2003, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Subroutines of libtool.m4,
dnl with replacements s/AC_/AC_LIB/ and s/lt_cv/acl_cv/ to avoid collision
dnl with libtool.m4.

dnl From libtool-1.4. Sets the variable with_gnu_ld to yes or no.
AC_DEFUN([AC_LIB_PROG_LD_GNU],
[AC_CACHE_CHECK([if the linker ($LD) is GNU ld], [acl_cv_prog_gnu_ld],
[# I'd rather use --version here, but apparently some GNU ld's only accept -v.
case `$LD -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  acl_cv_prog_gnu_ld=yes ;;
*)
  acl_cv_prog_gnu_ld=no ;;
esac])
with_gnu_ld=$acl_cv_prog_gnu_ld
])

dnl From libtool-1.4. Sets the variable LD.
AC_DEFUN([AC_LIB_PROG_LD],
[AC_ARG_WITH([gnu-ld],
[  --with-gnu-ld           assume the C compiler uses GNU ld [default=no]],
test "$withval" = no || with_gnu_ld=yes, with_gnu_ld=no)
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_CANONICAL_HOST])dnl
# Prepare PATH_SEPARATOR.
# The user is always right.
if test "${PATH_SEPARATOR+set}" != set; then
  echo "#! /bin/sh" >conf$$.sh
  echo  "exit 0"   >>conf$$.sh
  chmod +x conf$$.sh
  if (PATH="/nonexistent;."; conf$$.sh) >/dev/null 2>&1; then
    PATH_SEPARATOR=';'
  else
    PATH_SEPARATOR=:
  fi
  rm -f conf$$.sh
fi
ac_prog=ld
if test "$GCC" = yes; then
  # Check if gcc -print-prog-name=ld gives a path.
  AC_MSG_CHECKING([for ld used by GCC])
  case $host in
  *-*-mingw*)
    # gcc leaves a trailing carriage return which upsets mingw
    ac_prog=`($CC -print-prog-name=ld) 2>&5 | tr -d '\015'` ;;
  *)
    ac_prog=`($CC -print-prog-name=ld) 2>&5` ;;
  esac
  case $ac_prog in
    # Accept absolute paths.
    [[\\/]* | [A-Za-z]:[\\/]*)]
      [re_direlt='/[^/][^/]*/\.\./']
      # Canonicalize the path of ld
      ac_prog=`echo $ac_prog| sed 's%\\\\%/%g'`
      while echo $ac_prog | grep "$re_direlt" > /dev/null 2>&1; do
        ac_prog=`echo $ac_prog| sed "s%$re_direlt%/%"`
      done
      test -z "$LD" && LD="$ac_prog"
      ;;
  "")
    # If it fails, then pretend we aren't using GCC.
    ac_prog=ld
    ;;
  *)
    # If it is relative, then search for the first ld in PATH.
    with_gnu_ld=unknown
    ;;
  esac
elif test "$with_gnu_ld" = yes; then
  AC_MSG_CHECKING([for GNU ld])
else
  AC_MSG_CHECKING([for non-GNU ld])
fi
AC_CACHE_VAL([acl_cv_path_LD],
[if test -z "$LD"; then
  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS="${IFS}${PATH_SEPARATOR-:}"
  for ac_dir in $PATH; do
    test -z "$ac_dir" && ac_dir=.
    if test -f "$ac_dir/$ac_prog" || test -f "$ac_dir/$ac_prog$ac_exeext"; then
      acl_cv_path_LD="$ac_dir/$ac_prog"
      # Check to see if the program is GNU ld.  I'd rather use --version,
      # but apparently some GNU ld's only accept -v.
      # Break only if it was the GNU/non-GNU ld that we prefer.
      case `"$acl_cv_path_LD" -v 2>&1 < /dev/null` in
      *GNU* | *'with BFD'*)
        test "$with_gnu_ld" != no && break ;;
      *)
        test "$with_gnu_ld" != yes && break ;;
      esac
    fi
  done
  IFS="$ac_save_ifs"
else
  acl_cv_path_LD="$LD" # Let the user override the test with a path.
fi])
LD="$acl_cv_path_LD"
if test -n "$LD"; then
  AC_MSG_RESULT([$LD])
else
  AC_MSG_RESULT([no])
fi
test -z "$LD" && AC_MSG_ERROR([no acceptable ld found in \$PATH])
AC_LIB_PROG_LD_GNU
])

# lib-link.m4 serial 23 (gettext-0.18.2)
dnl Copyright (C) 2001-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

AC_PREREQ([2.54])

dnl AC_LIB_LINKFLAGS(name [, dependencies]) searches for libname and
dnl the libraries corresponding to explicit and implicit dependencies.
dnl Sets and AC_SUBSTs the LIB${NAME} and LTLIB${NAME} variables and
dnl augments the CPPFLAGS variable.
dnl Sets and AC_SUBSTs the LIB${NAME}_PREFIX variable to nonempty if libname
dnl was found in ${LIB${NAME}_PREFIX}/$acl_libdirstem.
AC_DEFUN([AC_LIB_LINKFLAGS],
[
  AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
  AC_REQUIRE([AC_LIB_RPATH])
  pushdef([Name],[m4_translit([$1],[./+-], [____])])
  pushdef([NAME],[m4_translit([$1],[abcdefghijklmnopqrstuvwxyz./+-],
                                   [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])
  AC_CACHE_CHECK([how to link with lib[]$1], [ac_cv_lib[]Name[]_libs], [
    AC_LIB_LINKFLAGS_BODY([$1], [$2])
    ac_cv_lib[]Name[]_libs="$LIB[]NAME"
    ac_cv_lib[]Name[]_ltlibs="$LTLIB[]NAME"
    ac_cv_lib[]Name[]_cppflags="$INC[]NAME"
    ac_cv_lib[]Name[]_prefix="$LIB[]NAME[]_PREFIX"
  ])
  LIB[]NAME="$ac_cv_lib[]Name[]_libs"
  LTLIB[]NAME="$ac_cv_lib[]Name[]_ltlibs"
  INC[]NAME="$ac_cv_lib[]Name[]_cppflags"
  LIB[]NAME[]_PREFIX="$ac_cv_lib[]Name[]_prefix"
  AC_LIB_APPENDTOVAR([CPPFLAGS], [$INC]NAME)
  AC_SUBST([LIB]NAME)
  AC_SUBST([LTLIB]NAME)
  AC_SUBST([LIB]NAME[_PREFIX])
  dnl Also set HAVE_LIB[]NAME so that AC_LIB_HAVE_LINKFLAGS can reuse the
  dnl results of this search when this library appears as a dependency.
  HAVE_LIB[]NAME=yes
  popdef([NAME])
  popdef([Name])
])

dnl AC_LIB_HAVE_LINKFLAGS(name, dependencies, includes, testcode, [missing-message])
dnl searches for libname and the libraries corresponding to explicit and
dnl implicit dependencies, together with the specified include files and
dnl the ability to compile and link the specified testcode. The missing-message
dnl defaults to 'no' and may contain additional hints for the user.
dnl If found, it sets and AC_SUBSTs HAVE_LIB${NAME}=yes and the LIB${NAME}
dnl and LTLIB${NAME} variables and augments the CPPFLAGS variable, and
dnl #defines HAVE_LIB${NAME} to 1. Otherwise, it sets and AC_SUBSTs
dnl HAVE_LIB${NAME}=no and LIB${NAME} and LTLIB${NAME} to empty.
dnl Sets and AC_SUBSTs the LIB${NAME}_PREFIX variable to nonempty if libname
dnl was found in ${LIB${NAME}_PREFIX}/$acl_libdirstem.
AC_DEFUN([AC_LIB_HAVE_LINKFLAGS],
[
  AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
  AC_REQUIRE([AC_LIB_RPATH])
  pushdef([Name],[m4_translit([$1],[./+-], [____])])
  pushdef([NAME],[m4_translit([$1],[abcdefghijklmnopqrstuvwxyz./+-],
                                   [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])

  dnl Search for lib[]Name and define LIB[]NAME, LTLIB[]NAME and INC[]NAME
  dnl accordingly.
  AC_LIB_LINKFLAGS_BODY([$1], [$2])

  dnl Add $INC[]NAME to CPPFLAGS before performing the following checks,
  dnl because if the user has installed lib[]Name and not disabled its use
  dnl via --without-lib[]Name-prefix, he wants to use it.
  ac_save_CPPFLAGS="$CPPFLAGS"
  AC_LIB_APPENDTOVAR([CPPFLAGS], [$INC]NAME)

  AC_CACHE_CHECK([for lib[]$1], [ac_cv_lib[]Name], [
    ac_save_LIBS="$LIBS"
    dnl If $LIB[]NAME contains some -l options, add it to the end of LIBS,
    dnl because these -l options might require -L options that are present in
    dnl LIBS. -l options benefit only from the -L options listed before it.
    dnl Otherwise, add it to the front of LIBS, because it may be a static
    dnl library that depends on another static library that is present in LIBS.
    dnl Static libraries benefit only from the static libraries listed after
    dnl it.
    case " $LIB[]NAME" in
      *" -l"*) LIBS="$LIBS $LIB[]NAME" ;;
      *)       LIBS="$LIB[]NAME $LIBS" ;;
    esac
    AC_TRY_LINK([$3], [$4],
      [ac_cv_lib[]Name=yes],
      [ac_cv_lib[]Name='m4_if([$5], [], [no], [[$5]])'])
    LIBS="$ac_save_LIBS"
  ])
  if test "$ac_cv_lib[]Name" = yes; then
    HAVE_LIB[]NAME=yes
    AC_DEFINE([HAVE_LIB]NAME, 1, [Define if you have the lib][$1 library.])
    AC_MSG_CHECKING([how to link with lib[]$1])
    AC_MSG_RESULT([$LIB[]NAME])
  else
    HAVE_LIB[]NAME=no
    dnl If $LIB[]NAME didn't lead to a usable library, we don't need
    dnl $INC[]NAME either.
    CPPFLAGS="$ac_save_CPPFLAGS"
    LIB[]NAME=
    LTLIB[]NAME=
    LIB[]NAME[]_PREFIX=
  fi
  AC_SUBST([HAVE_LIB]NAME)
  AC_SUBST([LIB]NAME)
  AC_SUBST([LTLIB]NAME)
  AC_SUBST([LIB]NAME[_PREFIX])
  popdef([NAME])
  popdef([Name])
])

dnl Determine the platform dependent parameters needed to use rpath:
dnl   acl_libext,
dnl   acl_shlibext,
dnl   acl_hardcode_libdir_flag_spec,
dnl   acl_hardcode_libdir_separator,
dnl   acl_hardcode_direct,
dnl   acl_hardcode_minus_L.
AC_DEFUN([AC_LIB_RPATH],
[
  dnl Tell automake >= 1.10 to complain if config.rpath is missing.
  m4_ifdef([AC_REQUIRE_AUX_FILE], [AC_REQUIRE_AUX_FILE([config.rpath])])
  AC_REQUIRE([AC_PROG_CC])                dnl we use $CC, $GCC, $LDFLAGS
  AC_REQUIRE([AC_LIB_PROG_LD])            dnl we use $LD, $with_gnu_ld
  AC_REQUIRE([AC_CANONICAL_HOST])         dnl we use $host
  AC_REQUIRE([AC_CONFIG_AUX_DIR_DEFAULT]) dnl we use $ac_aux_dir
  AC_CACHE_CHECK([for shared library run path origin], [acl_cv_rpath], [
    CC="$CC" GCC="$GCC" LDFLAGS="$LDFLAGS" LD="$LD" with_gnu_ld="$with_gnu_ld" \
    ${CONFIG_SHELL-/bin/sh} "$ac_aux_dir/config.rpath" "$host" > conftest.sh
    . ./conftest.sh
    rm -f ./conftest.sh
    acl_cv_rpath=done
  ])
  wl="$acl_cv_wl"
  acl_libext="$acl_cv_libext"
  acl_shlibext="$acl_cv_shlibext"
  acl_libname_spec="$acl_cv_libname_spec"
  acl_library_names_spec="$acl_cv_library_names_spec"
  acl_hardcode_libdir_flag_spec="$acl_cv_hardcode_libdir_flag_spec"
  acl_hardcode_libdir_separator="$acl_cv_hardcode_libdir_separator"
  acl_hardcode_direct="$acl_cv_hardcode_direct"
  acl_hardcode_minus_L="$acl_cv_hardcode_minus_L"
  dnl Determine whether the user wants rpath handling at all.
  AC_ARG_ENABLE([rpath],
    [  --disable-rpath         do not hardcode runtime library paths],
    :, enable_rpath=yes)
])

dnl AC_LIB_FROMPACKAGE(name, package)
dnl declares that libname comes from the given package. The configure file
dnl will then not have a --with-libname-prefix option but a
dnl --with-package-prefix option. Several libraries can come from the same
dnl package. This declaration must occur before an AC_LIB_LINKFLAGS or similar
dnl macro call that searches for libname.
AC_DEFUN([AC_LIB_FROMPACKAGE],
[
  pushdef([NAME],[m4_translit([$1],[abcdefghijklmnopqrstuvwxyz./+-],
                                   [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])
  define([acl_frompackage_]NAME, [$2])
  popdef([NAME])
  pushdef([PACK],[$2])
  pushdef([PACKUP],[m4_translit(PACK,[abcdefghijklmnopqrstuvwxyz./+-],
                                     [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])
  define([acl_libsinpackage_]PACKUP,
    m4_ifdef([acl_libsinpackage_]PACKUP, [acl_libsinpackage_]PACKUP[[, ]],)[lib$1])
  popdef([PACKUP])
  popdef([PACK])
])

dnl AC_LIB_LINKFLAGS_BODY(name [, dependencies]) searches for libname and
dnl the libraries corresponding to explicit and implicit dependencies.
dnl Sets the LIB${NAME}, LTLIB${NAME} and INC${NAME} variables.
dnl Also, sets the LIB${NAME}_PREFIX variable to nonempty if libname was found
dnl in ${LIB${NAME}_PREFIX}/$acl_libdirstem.
AC_DEFUN([AC_LIB_LINKFLAGS_BODY],
[
  AC_REQUIRE([AC_LIB_PREPARE_MULTILIB])
  pushdef([NAME],[m4_translit([$1],[abcdefghijklmnopqrstuvwxyz./+-],
                                   [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])
  pushdef([PACK],[m4_ifdef([acl_frompackage_]NAME, [acl_frompackage_]NAME, lib[$1])])
  pushdef([PACKUP],[m4_translit(PACK,[abcdefghijklmnopqrstuvwxyz./+-],
                                     [ABCDEFGHIJKLMNOPQRSTUVWXYZ____])])
  pushdef([PACKLIBS],[m4_ifdef([acl_frompackage_]NAME, [acl_libsinpackage_]PACKUP, lib[$1])])
  dnl Autoconf >= 2.61 supports dots in --with options.
  pushdef([P_A_C_K],[m4_if(m4_version_compare(m4_defn([m4_PACKAGE_VERSION]),[2.61]),[-1],[m4_translit(PACK,[.],[_])],PACK)])
  dnl By default, look in $includedir and $libdir.
  use_additional=yes
  AC_LIB_WITH_FINAL_PREFIX([
    eval additional_includedir=\"$includedir\"
    eval additional_libdir=\"$libdir\"
  ])
  AC_ARG_WITH(P_A_C_K[-prefix],
[[  --with-]]P_A_C_K[[-prefix[=DIR]  search for ]PACKLIBS[ in DIR/include and DIR/lib
  --without-]]P_A_C_K[[-prefix     don't search for ]PACKLIBS[ in includedir and libdir]],
[
    if test "X$withval" = "Xno"; then
      use_additional=no
    else
      if test "X$withval" = "X"; then
        AC_LIB_WITH_FINAL_PREFIX([
          eval additional_includedir=\"$includedir\"
          eval additional_libdir=\"$libdir\"
        ])
      else
        additional_includedir="$withval/include"
        additional_libdir="$withval/$acl_libdirstem"
        if test "$acl_libdirstem2" != "$acl_libdirstem" \
           && ! test -d "$withval/$acl_libdirstem"; then
          additional_libdir="$withval/$acl_libdirstem2"
        fi
      fi
    fi
])
  dnl Search the library and its dependencies in $additional_libdir and
  dnl $LDFLAGS. Using breadth-first-seach.
  LIB[]NAME=
  LTLIB[]NAME=
  INC[]NAME=
  LIB[]NAME[]_PREFIX=
  dnl HAVE_LIB${NAME} is an indicator that LIB${NAME}, LTLIB${NAME} have been
  dnl computed. So it has to be reset here.
  HAVE_LIB[]NAME=
  rpathdirs=
  ltrpathdirs=
  names_already_handled=
  names_next_round='$1 $2'
  while test -n "$names_next_round"; do
    names_this_round="$names_next_round"
    names_next_round=
    for name in $names_this_round; do
      already_handled=
      for n in $names_already_handled; do
        if test "$n" = "$name"; then
          already_handled=yes
          break
        fi
      done
      if test -z "$already_handled"; then
        names_already_handled="$names_already_handled $name"
        dnl See if it was already located by an earlier AC_LIB_LINKFLAGS
        dnl or AC_LIB_HAVE_LINKFLAGS call.
        uppername=`echo "$name" | sed -e 'y|abcdefghijklmnopqrstuvwxyz./+-|ABCDEFGHIJKLMNOPQRSTUVWXYZ____|'`
        eval value=\"\$HAVE_LIB$uppername\"
        if test -n "$value"; then
          if test "$value" = yes; then
            eval value=\"\$LIB$uppername\"
            test -z "$value" || LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$value"
            eval value=\"\$LTLIB$uppername\"
            test -z "$value" || LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }$value"
          else
            dnl An earlier call to AC_LIB_HAVE_LINKFLAGS has determined
            dnl that this library doesn't exist. So just drop it.
            :
          fi
        else
          dnl Search the library lib$name in $additional_libdir and $LDFLAGS
          dnl and the already constructed $LIBNAME/$LTLIBNAME.
          found_dir=
          found_la=
          found_so=
          found_a=
          eval libname=\"$acl_libname_spec\"    # typically: libname=lib$name
          if test -n "$acl_shlibext"; then
            shrext=".$acl_shlibext"             # typically: shrext=.so
          else
            shrext=
          fi
          if test $use_additional = yes; then
            dir="$additional_libdir"
            dnl The same code as in the loop below:
            dnl First look for a shared library.
            if test -n "$acl_shlibext"; then
              if test -f "$dir/$libname$shrext"; then
                found_dir="$dir"
                found_so="$dir/$libname$shrext"
              else
                if test "$acl_library_names_spec" = '$libname$shrext$versuffix'; then
                  ver=`(cd "$dir" && \
                        for f in "$libname$shrext".*; do echo "$f"; done \
                        | sed -e "s,^$libname$shrext\\\\.,," \
                        | sort -t '.' -n -r -k1,1 -k2,2 -k3,3 -k4,4 -k5,5 \
                        | sed 1q ) 2>/dev/null`
                  if test -n "$ver" && test -f "$dir/$libname$shrext.$ver"; then
                    found_dir="$dir"
                    found_so="$dir/$libname$shrext.$ver"
                  fi
                else
                  eval library_names=\"$acl_library_names_spec\"
                  for f in $library_names; do
                    if test -f "$dir/$f"; then
                      found_dir="$dir"
                      found_so="$dir/$f"
                      break
                    fi
                  done
                fi
              fi
            fi
            dnl Then look for a static library.
            if test "X$found_dir" = "X"; then
              if test -f "$dir/$libname.$acl_libext"; then
                found_dir="$dir"
                found_a="$dir/$libname.$acl_libext"
              fi
            fi
            if test "X$found_dir" != "X"; then
              if test -f "$dir/$libname.la"; then
                found_la="$dir/$libname.la"
              fi
            fi
          fi
          if test "X$found_dir" = "X"; then
            for x in $LDFLAGS $LTLIB[]NAME; do
              AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
              case "$x" in
                -L*)
                  dir=`echo "X$x" | sed -e 's/^X-L//'`
                  dnl First look for a shared library.
                  if test -n "$acl_shlibext"; then
                    if test -f "$dir/$libname$shrext"; then
                      found_dir="$dir"
                      found_so="$dir/$libname$shrext"
                    else
                      if test "$acl_library_names_spec" = '$libname$shrext$versuffix'; then
                        ver=`(cd "$dir" && \
                              for f in "$libname$shrext".*; do echo "$f"; done \
                              | sed -e "s,^$libname$shrext\\\\.,," \
                              | sort -t '.' -n -r -k1,1 -k2,2 -k3,3 -k4,4 -k5,5 \
                              | sed 1q ) 2>/dev/null`
                        if test -n "$ver" && test -f "$dir/$libname$shrext.$ver"; then
                          found_dir="$dir"
                          found_so="$dir/$libname$shrext.$ver"
                        fi
                      else
                        eval library_names=\"$acl_library_names_spec\"
                        for f in $library_names; do
                          if test -f "$dir/$f"; then
                            found_dir="$dir"
                            found_so="$dir/$f"
                            break
                          fi
                        done
                      fi
                    fi
                  fi
                  dnl Then look for a static library.
                  if test "X$found_dir" = "X"; then
                    if test -f "$dir/$libname.$acl_libext"; then
                      found_dir="$dir"
                      found_a="$dir/$libname.$acl_libext"
                    fi
                  fi
                  if test "X$found_dir" != "X"; then
                    if test -f "$dir/$libname.la"; then
                      found_la="$dir/$libname.la"
                    fi
                  fi
                  ;;
              esac
              if test "X$found_dir" != "X"; then
                break
              fi
            done
          fi
          if test "X$found_dir" != "X"; then
            dnl Found the library.
            LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }-L$found_dir -l$name"
            if test "X$found_so" != "X"; then
              dnl Linking with a shared library. We attempt to hardcode its
              dnl directory into the executable's runpath, unless it's the
              dnl standard /usr/lib.
              if test "$enable_rpath" = no \
                 || test "X$found_dir" = "X/usr/$acl_libdirstem" \
                 || test "X$found_dir" = "X/usr/$acl_libdirstem2"; then
                dnl No hardcoding is needed.
                LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$found_so"
              else
                dnl Use an explicit option to hardcode DIR into the resulting
                dnl binary.
                dnl Potentially add DIR to ltrpathdirs.
                dnl The ltrpathdirs will be appended to $LTLIBNAME at the end.
                haveit=
                for x in $ltrpathdirs; do
                  if test "X$x" = "X$found_dir"; then
                    haveit=yes
                    break
                  fi
                done
                if test -z "$haveit"; then
                  ltrpathdirs="$ltrpathdirs $found_dir"
                fi
                dnl The hardcoding into $LIBNAME is system dependent.
                if test "$acl_hardcode_direct" = yes; then
                  dnl Using DIR/libNAME.so during linking hardcodes DIR into the
                  dnl resulting binary.
                  LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$found_so"
                else
                  if test -n "$acl_hardcode_libdir_flag_spec" && test "$acl_hardcode_minus_L" = no; then
                    dnl Use an explicit option to hardcode DIR into the resulting
                    dnl binary.
                    LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$found_so"
                    dnl Potentially add DIR to rpathdirs.
                    dnl The rpathdirs will be appended to $LIBNAME at the end.
                    haveit=
                    for x in $rpathdirs; do
                      if test "X$x" = "X$found_dir"; then
                        haveit=yes
                        break
                      fi
                    done
                    if test -z "$haveit"; then
                      rpathdirs="$rpathdirs $found_dir"
                    fi
                  else
                    dnl Rely on "-L$found_dir".
                    dnl But don't add it if it's already contained in the LDFLAGS
                    dnl or the already constructed $LIBNAME
                    haveit=
                    for x in $LDFLAGS $LIB[]NAME; do
                      AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
                      if test "X$x" = "X-L$found_dir"; then
                        haveit=yes
                        break
                      fi
                    done
                    if test -z "$haveit"; then
                      LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }-L$found_dir"
                    fi
                    if test "$acl_hardcode_minus_L" != no; then
                      dnl FIXME: Not sure whether we should use
                      dnl "-L$found_dir -l$name" or "-L$found_dir $found_so"
                      dnl here.
                      LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$found_so"
                    else
                      dnl We cannot use $acl_hardcode_runpath_var and LD_RUN_PATH
                      dnl here, because this doesn't fit in flags passed to the
                      dnl compiler. So give up. No hardcoding. This affects only
                      dnl very old systems.
                      dnl FIXME: Not sure whether we should use
                      dnl "-L$found_dir -l$name" or "-L$found_dir $found_so"
                      dnl here.
                      LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }-l$name"
                    fi
                  fi
                fi
              fi
            else
              if test "X$found_a" != "X"; then
                dnl Linking with a static library.
                LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$found_a"
              else
                dnl We shouldn't come here, but anyway it's good to have a
                dnl fallback.
                LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }-L$found_dir -l$name"
              fi
            fi
            dnl Assume the include files are nearby.
            additional_includedir=
            case "$found_dir" in
              */$acl_libdirstem | */$acl_libdirstem/)
                basedir=`echo "X$found_dir" | sed -e 's,^X,,' -e "s,/$acl_libdirstem/"'*$,,'`
                if test "$name" = '$1'; then
                  LIB[]NAME[]_PREFIX="$basedir"
                fi
                additional_includedir="$basedir/include"
                ;;
              */$acl_libdirstem2 | */$acl_libdirstem2/)
                basedir=`echo "X$found_dir" | sed -e 's,^X,,' -e "s,/$acl_libdirstem2/"'*$,,'`
                if test "$name" = '$1'; then
                  LIB[]NAME[]_PREFIX="$basedir"
                fi
                additional_includedir="$basedir/include"
                ;;
            esac
            if test "X$additional_includedir" != "X"; then
              dnl Potentially add $additional_includedir to $INCNAME.
              dnl But don't add it
              dnl   1. if it's the standard /usr/include,
              dnl   2. if it's /usr/local/include and we are using GCC on Linux,
              dnl   3. if it's already present in $CPPFLAGS or the already
              dnl      constructed $INCNAME,
              dnl   4. if it doesn't exist as a directory.
              if test "X$additional_includedir" != "X/usr/include"; then
                haveit=
                if test "X$additional_includedir" = "X/usr/local/include"; then
                  if test -n "$GCC"; then
                    case $host_os in
                      linux* | gnu* | k*bsd*-gnu) haveit=yes;;
                    esac
                  fi
                fi
                if test -z "$haveit"; then
                  for x in $CPPFLAGS $INC[]NAME; do
                    AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
                    if test "X$x" = "X-I$additional_includedir"; then
                      haveit=yes
                      break
                    fi
                  done
                  if test -z "$haveit"; then
                    if test -d "$additional_includedir"; then
                      dnl Really add $additional_includedir to $INCNAME.
                      INC[]NAME="${INC[]NAME}${INC[]NAME:+ }-I$additional_includedir"
                    fi
                  fi
                fi
              fi
            fi
            dnl Look for dependencies.
            if test -n "$found_la"; then
              dnl Read the .la file. It defines the variables
              dnl dlname, library_names, old_library, dependency_libs, current,
              dnl age, revision, installed, dlopen, dlpreopen, libdir.
              save_libdir="$libdir"
              case "$found_la" in
                */* | *\\*) . "$found_la" ;;
                *) . "./$found_la" ;;
              esac
              libdir="$save_libdir"
              dnl We use only dependency_libs.
              for dep in $dependency_libs; do
                case "$dep" in
                  -L*)
                    additional_libdir=`echo "X$dep" | sed -e 's/^X-L//'`
                    dnl Potentially add $additional_libdir to $LIBNAME and $LTLIBNAME.
                    dnl But don't add it
                    dnl   1. if it's the standard /usr/lib,
                    dnl   2. if it's /usr/local/lib and we are using GCC on Linux,
                    dnl   3. if it's already present in $LDFLAGS or the already
                    dnl      constructed $LIBNAME,
                    dnl   4. if it doesn't exist as a directory.
                    if test "X$additional_libdir" != "X/usr/$acl_libdirstem" \
                       && test "X$additional_libdir" != "X/usr/$acl_libdirstem2"; then
                      haveit=
                      if test "X$additional_libdir" = "X/usr/local/$acl_libdirstem" \
                         || test "X$additional_libdir" = "X/usr/local/$acl_libdirstem2"; then
                        if test -n "$GCC"; then
                          case $host_os in
                            linux* | gnu* | k*bsd*-gnu) haveit=yes;;
                          esac
                        fi
                      fi
                      if test -z "$haveit"; then
                        haveit=
                        for x in $LDFLAGS $LIB[]NAME; do
                          AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
                          if test "X$x" = "X-L$additional_libdir"; then
                            haveit=yes
                            break
                          fi
                        done
                        if test -z "$haveit"; then
                          if test -d "$additional_libdir"; then
                            dnl Really add $additional_libdir to $LIBNAME.
                            LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }-L$additional_libdir"
                          fi
                        fi
                        haveit=
                        for x in $LDFLAGS $LTLIB[]NAME; do
                          AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
                          if test "X$x" = "X-L$additional_libdir"; then
                            haveit=yes
                            break
                          fi
                        done
                        if test -z "$haveit"; then
                          if test -d "$additional_libdir"; then
                            dnl Really add $additional_libdir to $LTLIBNAME.
                            LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }-L$additional_libdir"
                          fi
                        fi
                      fi
                    fi
                    ;;
                  -R*)
                    dir=`echo "X$dep" | sed -e 's/^X-R//'`
                    if test "$enable_rpath" != no; then
                      dnl Potentially add DIR to rpathdirs.
                      dnl The rpathdirs will be appended to $LIBNAME at the end.
                      haveit=
                      for x in $rpathdirs; do
                        if test "X$x" = "X$dir"; then
                          haveit=yes
                          break
                        fi
                      done
                      if test -z "$haveit"; then
                        rpathdirs="$rpathdirs $dir"
                      fi
                      dnl Potentially add DIR to ltrpathdirs.
                      dnl The ltrpathdirs will be appended to $LTLIBNAME at the end.
                      haveit=
                      for x in $ltrpathdirs; do
                        if test "X$x" = "X$dir"; then
                          haveit=yes
                          break
                        fi
                      done
                      if test -z "$haveit"; then
                        ltrpathdirs="$ltrpathdirs $dir"
                      fi
                    fi
                    ;;
                  -l*)
                    dnl Handle this in the next round.
                    names_next_round="$names_next_round "`echo "X$dep" | sed -e 's/^X-l//'`
                    ;;
                  *.la)
                    dnl Handle this in the next round. Throw away the .la's
                    dnl directory; it is already contained in a preceding -L
                    dnl option.
                    names_next_round="$names_next_round "`echo "X$dep" | sed -e 's,^X.*/,,' -e 's,^lib,,' -e 's,\.la$,,'`
                    ;;
                  *)
                    dnl Most likely an immediate library name.
                    LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$dep"
                    LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }$dep"
                    ;;
                esac
              done
            fi
          else
            dnl Didn't find the library; assume it is in the system directories
            dnl known to the linker and runtime loader. (All the system
            dnl directories known to the linker should also be known to the
            dnl runtime loader, otherwise the system is severely misconfigured.)
            LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }-l$name"
            LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }-l$name"
          fi
        fi
      fi
    done
  done
  if test "X$rpathdirs" != "X"; then
    if test -n "$acl_hardcode_libdir_separator"; then
      dnl Weird platform: only the last -rpath option counts, the user must
      dnl pass all path elements in one option. We can arrange that for a
      dnl single library, but not when more than one $LIBNAMEs are used.
      alldirs=
      for found_dir in $rpathdirs; do
        alldirs="${alldirs}${alldirs:+$acl_hardcode_libdir_separator}$found_dir"
      done
      dnl Note: acl_hardcode_libdir_flag_spec uses $libdir and $wl.
      acl_save_libdir="$libdir"
      libdir="$alldirs"
      eval flag=\"$acl_hardcode_libdir_flag_spec\"
      libdir="$acl_save_libdir"
      LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$flag"
    else
      dnl The -rpath options are cumulative.
      for found_dir in $rpathdirs; do
        acl_save_libdir="$libdir"
        libdir="$found_dir"
        eval flag=\"$acl_hardcode_libdir_flag_spec\"
        libdir="$acl_save_libdir"
        LIB[]NAME="${LIB[]NAME}${LIB[]NAME:+ }$flag"
      done
    fi
  fi
  if test "X$ltrpathdirs" != "X"; then
    dnl When using libtool, the option that works for both libraries and
    dnl executables is -R. The -R options are cumulative.
    for found_dir in $ltrpathdirs; do
      LTLIB[]NAME="${LTLIB[]NAME}${LTLIB[]NAME:+ }-R$found_dir"
    done
  fi
  popdef([P_A_C_K])
  popdef([PACKLIBS])
  popdef([PACKUP])
  popdef([PACK])
  popdef([NAME])
])

dnl AC_LIB_APPENDTOVAR(VAR, CONTENTS) appends the elements of CONTENTS to VAR,
dnl unless already present in VAR.
dnl Works only for CPPFLAGS, not for LIB* variables because that sometimes
dnl contains two or three consecutive elements that belong together.
AC_DEFUN([AC_LIB_APPENDTOVAR],
[
  for element in [$2]; do
    haveit=
    for x in $[$1]; do
      AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
      if test "X$x" = "X$element"; then
        haveit=yes
        break
      fi
    done
    if test -z "$haveit"; then
      [$1]="${[$1]}${[$1]:+ }$element"
    fi
  done
])

dnl For those cases where a variable contains several -L and -l options
dnl referring to unknown libraries and directories, this macro determines the
dnl necessary additional linker options for the runtime path.
dnl AC_LIB_LINKFLAGS_FROM_LIBS([LDADDVAR], [LIBSVALUE], [USE-LIBTOOL])
dnl sets LDADDVAR to linker options needed together with LIBSVALUE.
dnl If USE-LIBTOOL evaluates to non-empty, linking with libtool is assumed,
dnl otherwise linking without libtool is assumed.
AC_DEFUN([AC_LIB_LINKFLAGS_FROM_LIBS],
[
  AC_REQUIRE([AC_LIB_RPATH])
  AC_REQUIRE([AC_LIB_PREPARE_MULTILIB])
  $1=
  if test "$enable_rpath" != no; then
    if test -n "$acl_hardcode_libdir_flag_spec" && test "$acl_hardcode_minus_L" = no; then
      dnl Use an explicit option to hardcode directories into the resulting
      dnl binary.
      rpathdirs=
      next=
      for opt in $2; do
        if test -n "$next"; then
          dir="$next"
          dnl No need to hardcode the standard /usr/lib.
          if test "X$dir" != "X/usr/$acl_libdirstem" \
             && test "X$dir" != "X/usr/$acl_libdirstem2"; then
            rpathdirs="$rpathdirs $dir"
          fi
          next=
        else
          case $opt in
            -L) next=yes ;;
            -L*) dir=`echo "X$opt" | sed -e 's,^X-L,,'`
                 dnl No need to hardcode the standard /usr/lib.
                 if test "X$dir" != "X/usr/$acl_libdirstem" \
                    && test "X$dir" != "X/usr/$acl_libdirstem2"; then
                   rpathdirs="$rpathdirs $dir"
                 fi
                 next= ;;
            *) next= ;;
          esac
        fi
      done
      if test "X$rpathdirs" != "X"; then
        if test -n ""$3""; then
          dnl libtool is used for linking. Use -R options.
          for dir in $rpathdirs; do
            $1="${$1}${$1:+ }-R$dir"
          done
        else
          dnl The linker is used for linking directly.
          if test -n "$acl_hardcode_libdir_separator"; then
            dnl Weird platform: only the last -rpath option counts, the user
            dnl must pass all path elements in one option.
            alldirs=
            for dir in $rpathdirs; do
              alldirs="${alldirs}${alldirs:+$acl_hardcode_libdir_separator}$dir"
            done
            acl_save_libdir="$libdir"
            libdir="$alldirs"
            eval flag=\"$acl_hardcode_libdir_flag_spec\"
            libdir="$acl_save_libdir"
            $1="$flag"
          else
            dnl The -rpath options are cumulative.
            for dir in $rpathdirs; do
              acl_save_libdir="$libdir"
              libdir="$dir"
              eval flag=\"$acl_hardcode_libdir_flag_spec\"
              libdir="$acl_save_libdir"
              $1="${$1}${$1:+ }$flag"
            done
          fi
        fi
      fi
    fi
  fi
  AC_SUBST([$1])
])

# lib-prefix.m4 serial 7 (gettext-0.18)
dnl Copyright (C) 2001-2005, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

dnl AC_LIB_ARG_WITH is synonymous to AC_ARG_WITH in autoconf-2.13, and
dnl similar to AC_ARG_WITH in autoconf 2.52...2.57 except that is doesn't
dnl require excessive bracketing.
ifdef([AC_HELP_STRING],
[AC_DEFUN([AC_LIB_ARG_WITH], [AC_ARG_WITH([$1],[[$2]],[$3],[$4])])],
[AC_DEFUN([AC_][LIB_ARG_WITH], [AC_ARG_WITH([$1],[$2],[$3],[$4])])])

dnl AC_LIB_PREFIX adds to the CPPFLAGS and LDFLAGS the flags that are needed
dnl to access previously installed libraries. The basic assumption is that
dnl a user will want packages to use other packages he previously installed
dnl with the same --prefix option.
dnl This macro is not needed if only AC_LIB_LINKFLAGS is used to locate
dnl libraries, but is otherwise very convenient.
AC_DEFUN([AC_LIB_PREFIX],
[
  AC_BEFORE([$0], [AC_LIB_LINKFLAGS])
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_REQUIRE([AC_LIB_PREPARE_MULTILIB])
  AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
  dnl By default, look in $includedir and $libdir.
  use_additional=yes
  AC_LIB_WITH_FINAL_PREFIX([
    eval additional_includedir=\"$includedir\"
    eval additional_libdir=\"$libdir\"
  ])
  AC_LIB_ARG_WITH([lib-prefix],
[  --with-lib-prefix[=DIR] search for libraries in DIR/include and DIR/lib
  --without-lib-prefix    don't search for libraries in includedir and libdir],
[
    if test "X$withval" = "Xno"; then
      use_additional=no
    else
      if test "X$withval" = "X"; then
        AC_LIB_WITH_FINAL_PREFIX([
          eval additional_includedir=\"$includedir\"
          eval additional_libdir=\"$libdir\"
        ])
      else
        additional_includedir="$withval/include"
        additional_libdir="$withval/$acl_libdirstem"
      fi
    fi
])
  if test $use_additional = yes; then
    dnl Potentially add $additional_includedir to $CPPFLAGS.
    dnl But don't add it
    dnl   1. if it's the standard /usr/include,
    dnl   2. if it's already present in $CPPFLAGS,
    dnl   3. if it's /usr/local/include and we are using GCC on Linux,
    dnl   4. if it doesn't exist as a directory.
    if test "X$additional_includedir" != "X/usr/include"; then
      haveit=
      for x in $CPPFLAGS; do
        AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
        if test "X$x" = "X-I$additional_includedir"; then
          haveit=yes
          break
        fi
      done
      if test -z "$haveit"; then
        if test "X$additional_includedir" = "X/usr/local/include"; then
          if test -n "$GCC"; then
            case $host_os in
              linux* | gnu* | k*bsd*-gnu) haveit=yes;;
            esac
          fi
        fi
        if test -z "$haveit"; then
          if test -d "$additional_includedir"; then
            dnl Really add $additional_includedir to $CPPFLAGS.
            CPPFLAGS="${CPPFLAGS}${CPPFLAGS:+ }-I$additional_includedir"
          fi
        fi
      fi
    fi
    dnl Potentially add $additional_libdir to $LDFLAGS.
    dnl But don't add it
    dnl   1. if it's the standard /usr/lib,
    dnl   2. if it's already present in $LDFLAGS,
    dnl   3. if it's /usr/local/lib and we are using GCC on Linux,
    dnl   4. if it doesn't exist as a directory.
    if test "X$additional_libdir" != "X/usr/$acl_libdirstem"; then
      haveit=
      for x in $LDFLAGS; do
        AC_LIB_WITH_FINAL_PREFIX([eval x=\"$x\"])
        if test "X$x" = "X-L$additional_libdir"; then
          haveit=yes
          break
        fi
      done
      if test -z "$haveit"; then
        if test "X$additional_libdir" = "X/usr/local/$acl_libdirstem"; then
          if test -n "$GCC"; then
            case $host_os in
              linux*) haveit=yes;;
            esac
          fi
        fi
        if test -z "$haveit"; then
          if test -d "$additional_libdir"; then
            dnl Really add $additional_libdir to $LDFLAGS.
            LDFLAGS="${LDFLAGS}${LDFLAGS:+ }-L$additional_libdir"
          fi
        fi
      fi
    fi
  fi
])

dnl AC_LIB_PREPARE_PREFIX creates variables acl_final_prefix,
dnl acl_final_exec_prefix, containing the values to which $prefix and
dnl $exec_prefix will expand at the end of the configure script.
AC_DEFUN([AC_LIB_PREPARE_PREFIX],
[
  dnl Unfortunately, prefix and exec_prefix get only finally determined
  dnl at the end of configure.
  if test "X$prefix" = "XNONE"; then
    acl_final_prefix="$ac_default_prefix"
  else
    acl_final_prefix="$prefix"
  fi
  if test "X$exec_prefix" = "XNONE"; then
    acl_final_exec_prefix='${prefix}'
  else
    acl_final_exec_prefix="$exec_prefix"
  fi
  acl_save_prefix="$prefix"
  prefix="$acl_final_prefix"
  eval acl_final_exec_prefix=\"$acl_final_exec_prefix\"
  prefix="$acl_save_prefix"
])

dnl AC_LIB_WITH_FINAL_PREFIX([statement]) evaluates statement, with the
dnl variables prefix and exec_prefix bound to the values they will have
dnl at the end of the configure script.
AC_DEFUN([AC_LIB_WITH_FINAL_PREFIX],
[
  acl_save_prefix="$prefix"
  prefix="$acl_final_prefix"
  acl_save_exec_prefix="$exec_prefix"
  exec_prefix="$acl_final_exec_prefix"
  $1
  exec_prefix="$acl_save_exec_prefix"
  prefix="$acl_save_prefix"
])

dnl AC_LIB_PREPARE_MULTILIB creates
dnl - a variable acl_libdirstem, containing the basename of the libdir, either
dnl   "lib" or "lib64" or "lib/64",
dnl - a variable acl_libdirstem2, as a secondary possible value for
dnl   acl_libdirstem, either the same as acl_libdirstem or "lib/sparcv9" or
dnl   "lib/amd64".
AC_DEFUN([AC_LIB_PREPARE_MULTILIB],
[
  dnl There is no formal standard regarding lib and lib64.
  dnl On glibc systems, the current practice is that on a system supporting
  dnl 32-bit and 64-bit instruction sets or ABIs, 64-bit libraries go under
  dnl $prefix/lib64 and 32-bit libraries go under $prefix/lib. We determine
  dnl the compiler's default mode by looking at the compiler's library search
  dnl path. If at least one of its elements ends in /lib64 or points to a
  dnl directory whose absolute pathname ends in /lib64, we assume a 64-bit ABI.
  dnl Otherwise we use the default, namely "lib".
  dnl On Solaris systems, the current practice is that on a system supporting
  dnl 32-bit and 64-bit instruction sets or ABIs, 64-bit libraries go under
  dnl $prefix/lib/64 (which is a symlink to either $prefix/lib/sparcv9 or
  dnl $prefix/lib/amd64) and 32-bit libraries go under $prefix/lib.
  AC_REQUIRE([AC_CANONICAL_HOST])
  acl_libdirstem=lib
  acl_libdirstem2=
  case "$host_os" in
    solaris*)
      dnl See Solaris 10 Software Developer Collection > Solaris 64-bit Developer's Guide > The Development Environment
      dnl <http://docs.sun.com/app/docs/doc/816-5138/dev-env?l=en&a=view>.
      dnl "Portable Makefiles should refer to any library directories using the 64 symbolic link."
      dnl But we want to recognize the sparcv9 or amd64 subdirectory also if the
      dnl symlink is missing, so we set acl_libdirstem2 too.
      AC_CACHE_CHECK([for 64-bit host], [gl_cv_solaris_64bit],
        [AC_EGREP_CPP([sixtyfour bits], [
#ifdef _LP64
sixtyfour bits
#endif
           ], [gl_cv_solaris_64bit=yes], [gl_cv_solaris_64bit=no])
        ])
      if test $gl_cv_solaris_64bit = yes; then
        acl_libdirstem=lib/64
        case "$host_cpu" in
          sparc*)        acl_libdirstem2=lib/sparcv9 ;;
          i*86 | x86_64) acl_libdirstem2=lib/amd64 ;;
        esac
      fi
      ;;
    *)
      searchpath=`(LC_ALL=C $CC -print-search-dirs) 2>/dev/null | sed -n -e 's,^libraries: ,,p' | sed -e 's,^=,,'`
      if test -n "$searchpath"; then
        acl_save_IFS="${IFS= 	}"; IFS=":"
        for searchdir in $searchpath; do
          if test -d "$searchdir"; then
            case "$searchdir" in
              */lib64/ | */lib64 ) acl_libdirstem=lib64 ;;
              */../ | */.. )
                # Better ignore directories of this form. They are misleading.
                ;;
              *) searchdir=`cd "$searchdir" && pwd`
                 case "$searchdir" in
                   */lib64 ) acl_libdirstem=lib64 ;;
                 esac ;;
            esac
          fi
        done
        IFS="$acl_save_IFS"
      fi
      ;;
  esac
  test -n "$acl_libdirstem2" || acl_libdirstem2="$acl_libdirstem"
])

# libsigsegv.m4 serial 4
dnl Copyright (C) 2002-2003, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible, Sam Steingold.

AC_DEFUN([gl_LIBSIGSEGV],
[
  AC_LIB_HAVE_LINKFLAGS([sigsegv], [],
    [#include <sigsegv.h>], [sigsegv_deinstall_handler();],
    [no, consider installing GNU libsigsegv])
  dnl Some other autoconf macros and clisp's configure use this variable.
  gl_cv_lib_sigsegv="$ac_cv_libsigsegv"
])

# libunistring-base.m4 serial 5
dnl Copyright (C) 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Paolo Bonzini and Bruno Haible.

dnl gl_LIBUNISTRING_MODULE([VERSION], [Module])
dnl Declares that the source files of Module should be compiled, unless we
dnl are linking with libunistring and its version is >= the given VERSION.
dnl Defines an automake conditional LIBUNISTRING_COMPILE_$MODULE that is
dnl true if the source files of Module should be compiled.
dnl This macro is to be used for public libunistring API, not for
dnl undocumented API.
dnl
dnl You have to bump the VERSION argument to the next projected version
dnl number each time you make a change that affects the behaviour of the
dnl functions defined in Module (even if the sources of Module itself do not
dnl change).

AC_DEFUN([gl_LIBUNISTRING_MODULE],
[
  AC_REQUIRE([gl_LIBUNISTRING_LIB_PREPARE])
  dnl Use the variables HAVE_LIBUNISTRING, LIBUNISTRING_VERSION from
  dnl gl_LIBUNISTRING_CORE if that macro has been run.
  AM_CONDITIONAL(AS_TR_CPP([LIBUNISTRING_COMPILE_$2]),
    [gl_LIBUNISTRING_VERSION_CMP([$1])])
])

dnl gl_LIBUNISTRING_LIBHEADER([VERSION], [HeaderFile])
dnl Declares that HeaderFile should be created, unless we are linking
dnl with libunistring and its version is >= the given VERSION.
dnl HeaderFile should be relative to the lib directory and end in '.h'.
dnl Prepares for substituting LIBUNISTRING_HEADERFILE (to HeaderFile or empty).
dnl
dnl When we are linking with the already installed libunistring and its version
dnl is < VERSION, we create HeaderFile here, because we may compile functions
dnl (via gl_LIBUNISTRING_MODULE above) that are not contained in the installed
dnl version.
dnl When we are linking with the already installed libunistring and its version
dnl is > VERSION, we don't create HeaderFile here: it could cause compilation
dnl errors in other libunistring header files if some types are missing.
dnl
dnl You have to bump the VERSION argument to the next projected version
dnl number each time you make a non-comment change to the HeaderFile.

AC_DEFUN([gl_LIBUNISTRING_LIBHEADER],
[
  AC_REQUIRE([gl_LIBUNISTRING_LIB_PREPARE])
  dnl Use the variables HAVE_LIBUNISTRING, LIBUNISTRING_VERSION from
  dnl gl_LIBUNISTRING_CORE if that macro has been run.
  if gl_LIBUNISTRING_VERSION_CMP([$1]); then
    LIBUNISTRING_[]AS_TR_CPP([$2])='$2'
  else
    LIBUNISTRING_[]AS_TR_CPP([$2])=
  fi
  AC_SUBST([LIBUNISTRING_]AS_TR_CPP([$2]))
])

dnl Miscellaneous preparations/initializations.

AC_DEFUN([gl_LIBUNISTRING_LIB_PREPARE],
[
  dnl Ensure that HAVE_LIBUNISTRING is fully determined at this point.
  m4_ifdef([gl_LIBUNISTRING], [AC_REQUIRE([gl_LIBUNISTRING])])

  AC_REQUIRE([AC_PROG_AWK])

dnl Sed expressions to extract the parts of a version number.
changequote(,)
gl_libunistring_sed_extract_major='/^[0-9]/{s/^\([0-9]*\).*/\1/p;q;}
i\
0
q
'
gl_libunistring_sed_extract_minor='/^[0-9][0-9]*[.][0-9]/{s/^[0-9]*[.]\([0-9]*\).*/\1/p;q;}
i\
0
q
'
gl_libunistring_sed_extract_subminor='/^[0-9][0-9]*[.][0-9][0-9]*[.][0-9]/{s/^[0-9]*[.][0-9]*[.]\([0-9]*\).*/\1/p;q;}
i\
0
q
'
changequote([,])

  if test "$HAVE_LIBUNISTRING" = yes; then
    LIBUNISTRING_VERSION_MAJOR=`echo "$LIBUNISTRING_VERSION" | sed -n -e "$gl_libunistring_sed_extract_major"`
    LIBUNISTRING_VERSION_MINOR=`echo "$LIBUNISTRING_VERSION" | sed -n -e "$gl_libunistring_sed_extract_minor"`
    LIBUNISTRING_VERSION_SUBMINOR=`echo "$LIBUNISTRING_VERSION" | sed -n -e "$gl_libunistring_sed_extract_subminor"`
  fi
])

dnl gl_LIBUNISTRING_VERSION_CMP([VERSION])
dnl Expands to a shell statement that evaluates to true if LIBUNISTRING_VERSION
dnl is less than the VERSION argument.
AC_DEFUN([gl_LIBUNISTRING_VERSION_CMP],
[ { test "$HAVE_LIBUNISTRING" != yes \
    || {
         dnl AS_LITERAL_IF exists and works fine since autoconf-2.59 at least.
         AS_LITERAL_IF([$1],
           [dnl This is the optimized variant, that assumes the argument is a literal:
            m4_pushdef([requested_version_major],
              [gl_LIBUNISTRING_ARG_OR_ZERO(m4_bpatsubst([$1], [^\([0-9]*\).*], [\1]), [])])
            m4_pushdef([requested_version_minor],
              [gl_LIBUNISTRING_ARG_OR_ZERO(m4_bpatsubst([$1], [^[0-9]*[.]\([0-9]*\).*], [\1]), [$1])])
            m4_pushdef([requested_version_subminor],
              [gl_LIBUNISTRING_ARG_OR_ZERO(m4_bpatsubst([$1], [^[0-9]*[.][0-9]*[.]\([0-9]*\).*], [\1]), [$1])])
            test $LIBUNISTRING_VERSION_MAJOR -lt requested_version_major \
            || { test $LIBUNISTRING_VERSION_MAJOR -eq requested_version_major \
                 && { test $LIBUNISTRING_VERSION_MINOR -lt requested_version_minor \
                      || { test $LIBUNISTRING_VERSION_MINOR -eq requested_version_minor \
                           && test $LIBUNISTRING_VERSION_SUBMINOR -lt requested_version_subminor
                         }
                    }
               }
            m4_popdef([requested_version_subminor])
            m4_popdef([requested_version_minor])
            m4_popdef([requested_version_major])
           ],
           [dnl This is the unoptimized variant:
            requested_version_major=`echo '$1' | sed -n -e "$gl_libunistring_sed_extract_major"`
            requested_version_minor=`echo '$1' | sed -n -e "$gl_libunistring_sed_extract_minor"`
            requested_version_subminor=`echo '$1' | sed -n -e "$gl_libunistring_sed_extract_subminor"`
            test $LIBUNISTRING_VERSION_MAJOR -lt $requested_version_major \
            || { test $LIBUNISTRING_VERSION_MAJOR -eq $requested_version_major \
                 && { test $LIBUNISTRING_VERSION_MINOR -lt $requested_version_minor \
                      || { test $LIBUNISTRING_VERSION_MINOR -eq $requested_version_minor \
                           && test $LIBUNISTRING_VERSION_SUBMINOR -lt $requested_version_subminor
                         }
                    }
               }
           ])
       }
  }])

dnl gl_LIBUNISTRING_ARG_OR_ZERO([ARG], [ORIG]) expands to ARG if it is not the
dnl same as ORIG, otherwise to 0.
m4_define([gl_LIBUNISTRING_ARG_OR_ZERO], [m4_if([$1], [$2], [0], [$1])])

# serial 15
dnl Run a program to determine whether link(2) follows symlinks.
dnl Set LINK_FOLLOWS_SYMLINKS accordingly.

# Copyright (C) 1999-2001, 2004-2006, 2009-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

dnl This macro can be used to emulate POSIX linkat.  If
dnl LINK_FOLLOWS_SYMLINKS is 0, link matches linkat(,0), and
dnl linkat(,AT_SYMLINK_FOLLOW) requires a readlink. If it is 1,
dnl link matches linkat(,AT_SYMLINK_FOLLOW), and there is no way
dnl to do linkat(,0) on symlinks (on all other file types,
dnl link() is sufficient).  If it is -1, use a runtime test.
AC_DEFUN([gl_FUNC_LINK_FOLLOWS_SYMLINK],
[dnl
  AC_CHECK_FUNCS_ONCE([readlink])
  dnl Mingw lacks link, although gnulib provides a good replacement.
  dnl However, it also lacks symlink, so there's nothing to test in
  dnl the first place, and no reason to need to distinguish between
  dnl linkat variants.  So, we set LINK_FOLLOWS_SYMLINKS to 0.
  gl_link_follows_symlinks=0 # assume GNU behavior
  if test $ac_cv_func_readlink = yes; then
    AC_CACHE_CHECK([whether link(2) dereferences a symlink],
                    gl_cv_func_link_follows_symlink,
    [
      # Create a regular file.
      echo > conftest.file
      AC_RUN_IFELSE([AC_LANG_SOURCE([[
#       include <sys/types.h>
#       include <sys/stat.h>
#       include <unistd.h>
#       include <stdlib.h>

#       define SAME_INODE(Stat_buf_1, Stat_buf_2) \
          ((Stat_buf_1).st_ino == (Stat_buf_2).st_ino \
           && (Stat_buf_1).st_dev == (Stat_buf_2).st_dev)

        int
        main ()
        {
          const char *file = "conftest.file";
          const char *sym = "conftest.sym";
          const char *hard = "conftest.hard";
          struct stat sb_file, sb_hard;

          /* Create a symlink to the regular file. */
          if (symlink (file, sym))
            return 2;

          /* Create a hard link to that symlink.  */
          if (link (sym, hard))
            return 3;

          if (lstat (hard, &sb_hard))
            return 4;
          if (lstat (file, &sb_file))
            return 5;

          /* If the dev/inode of hard and file are the same, then
             the link call followed the symlink.  */
          return SAME_INODE (sb_hard, sb_file) ? 1 : 0;
        }
      ]])],
        [gl_cv_func_link_follows_symlink=no], dnl GNU behavior
        [gl_cv_func_link_follows_symlink=yes], dnl Followed link/compile failed
        [gl_cv_func_link_follows_symlink=unknown] dnl We're cross compiling.
      )
      rm -f conftest.file conftest.sym conftest.hard
    ])
    case $gl_cv_func_link_follows_symlink in
      yes) gl_link_follows_symlinks=1 ;;
      no) ;; # already defaulted to 0
      *) gl_link_follows_symlinks=-1 ;;
    esac
  fi
  AC_DEFINE_UNQUOTED([LINK_FOLLOWS_SYMLINKS], [$gl_link_follows_symlinks],
    [Define to 1 if `link(2)' dereferences symbolic links, 0 if it
     creates hard links to symlinks, and -1 if unknown.])
])

# localcharset.m4 serial 7
dnl Copyright (C) 2002, 2004, 2006, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_LOCALCHARSET],
[
  dnl Prerequisites of lib/localcharset.c.
  AC_REQUIRE([AM_LANGINFO_CODESET])
  AC_REQUIRE([gl_FCNTL_O_FLAGS])
  AC_CHECK_DECLS_ONCE([getc_unlocked])

  dnl Prerequisites of the lib/Makefile.am snippet.
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_REQUIRE([gl_GLIBC21])
])

# locale-fr.m4 serial 11
dnl Copyright (C) 2003, 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

dnl Determine the name of a french locale with traditional encoding.
AC_DEFUN([gt_LOCALE_FR],
[
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_REQUIRE([AM_LANGINFO_CODESET])
  AC_CACHE_CHECK([for a traditional french locale], [gt_cv_locale_fr], [
    AC_LANG_CONFTEST([AC_LANG_SOURCE([
changequote(,)dnl
#include <locale.h>
#include <time.h>
#if HAVE_LANGINFO_CODESET
# include <langinfo.h>
#endif
#include <stdlib.h>
#include <string.h>
struct tm t;
char buf[16];
int main () {
  /* Check whether the given locale name is recognized by the system.  */
  if (setlocale (LC_ALL, "") == NULL) return 1;
  /* Check whether nl_langinfo(CODESET) is nonempty and not "ASCII" or "646".
     On MacOS X 10.3.5 (Darwin 7.5) in the fr_FR locale, nl_langinfo(CODESET)
     is empty, and the behaviour of Tcl 8.4 in this locale is not useful.
     On OpenBSD 4.0, when an unsupported locale is specified, setlocale()
     succeeds but then nl_langinfo(CODESET) is "646". In this situation,
     some unit tests fail.  */
#if HAVE_LANGINFO_CODESET
  {
    const char *cs = nl_langinfo (CODESET);
    if (cs[0] == '\0' || strcmp (cs, "ASCII") == 0 || strcmp (cs, "646") == 0)
      return 1;
  }
#endif
#ifdef __CYGWIN__
  /* On Cygwin, avoid locale names without encoding suffix, because the
     locale_charset() function relies on the encoding suffix.  Note that
     LC_ALL is set on the command line.  */
  if (strchr (getenv ("LC_ALL"), '.') == NULL) return 1;
#endif
  /* Check whether in the abbreviation of the second month, the second
     character (should be U+00E9: LATIN SMALL LETTER E WITH ACUTE) is only
     one byte long. This excludes the UTF-8 encoding.  */
  t.tm_year = 1975 - 1900; t.tm_mon = 2 - 1; t.tm_mday = 4;
  if (strftime (buf, sizeof (buf), "%b", &t) < 3 || buf[2] != 'v') return 1;
  /* Check whether the decimal separator is a comma.
     On NetBSD 3.0 in the fr_FR.ISO8859-1 locale, localeconv()->decimal_point
     are nl_langinfo(RADIXCHAR) are both ".".  */
  if (localeconv () ->decimal_point[0] != ',') return 1;
  return 0;
}
changequote([,])dnl
      ])])
    if AC_TRY_EVAL([ac_link]) && test -s conftest$ac_exeext; then
      # Setting LC_ALL is not enough. Need to set LC_TIME to empty, because
      # otherwise on MacOS X 10.3.5 the LC_TIME=C from the beginning of the
      # configure script would override the LC_ALL setting. Likewise for
      # LC_CTYPE, which is also set at the beginning of the configure script.
      # Test for the usual locale name.
      if (LC_ALL=fr_FR LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
        gt_cv_locale_fr=fr_FR
      else
        # Test for the locale name with explicit encoding suffix.
        if (LC_ALL=fr_FR.ISO-8859-1 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
          gt_cv_locale_fr=fr_FR.ISO-8859-1
        else
          # Test for the AIX, OSF/1, FreeBSD, NetBSD, OpenBSD locale name.
          if (LC_ALL=fr_FR.ISO8859-1 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
            gt_cv_locale_fr=fr_FR.ISO8859-1
          else
            # Test for the HP-UX locale name.
            if (LC_ALL=fr_FR.iso88591 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
              gt_cv_locale_fr=fr_FR.iso88591
            else
              # Test for the Solaris 7 locale name.
              if (LC_ALL=fr LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
                gt_cv_locale_fr=fr
              else
                # None found.
                gt_cv_locale_fr=none
              fi
            fi
          fi
        fi
      fi
    fi
    rm -fr conftest*
  ])
  LOCALE_FR=$gt_cv_locale_fr
  AC_SUBST([LOCALE_FR])
])

dnl Determine the name of a french locale with UTF-8 encoding.
AC_DEFUN([gt_LOCALE_FR_UTF8],
[
  AC_REQUIRE([AM_LANGINFO_CODESET])
  AC_CACHE_CHECK([for a french Unicode locale], [gt_cv_locale_fr_utf8], [
    AC_LANG_CONFTEST([AC_LANG_SOURCE([
changequote(,)dnl
#include <locale.h>
#include <time.h>
#if HAVE_LANGINFO_CODESET
# include <langinfo.h>
#endif
#include <stdlib.h>
#include <string.h>
struct tm t;
char buf[16];
int main () {
  /* On BeOS and Haiku, locales are not implemented in libc.  Rather, libintl
     imitates locale dependent behaviour by looking at the environment
     variables, and all locales use the UTF-8 encoding.  */
#if !(defined __BEOS__ || defined __HAIKU__)
  /* Check whether the given locale name is recognized by the system.  */
  if (setlocale (LC_ALL, "") == NULL) return 1;
  /* Check whether nl_langinfo(CODESET) is nonempty and not "ASCII" or "646".
     On MacOS X 10.3.5 (Darwin 7.5) in the fr_FR locale, nl_langinfo(CODESET)
     is empty, and the behaviour of Tcl 8.4 in this locale is not useful.
     On OpenBSD 4.0, when an unsupported locale is specified, setlocale()
     succeeds but then nl_langinfo(CODESET) is "646". In this situation,
     some unit tests fail.  */
# if HAVE_LANGINFO_CODESET
  {
    const char *cs = nl_langinfo (CODESET);
    if (cs[0] == '\0' || strcmp (cs, "ASCII") == 0 || strcmp (cs, "646") == 0)
      return 1;
  }
# endif
# ifdef __CYGWIN__
  /* On Cygwin, avoid locale names without encoding suffix, because the
     locale_charset() function relies on the encoding suffix.  Note that
     LC_ALL is set on the command line.  */
  if (strchr (getenv ("LC_ALL"), '.') == NULL) return 1;
# endif
  /* Check whether in the abbreviation of the second month, the second
     character (should be U+00E9: LATIN SMALL LETTER E WITH ACUTE) is
     two bytes long, with UTF-8 encoding.  */
  t.tm_year = 1975 - 1900; t.tm_mon = 2 - 1; t.tm_mday = 4;
  if (strftime (buf, sizeof (buf), "%b", &t) < 4
      || buf[1] != (char) 0xc3 || buf[2] != (char) 0xa9 || buf[3] != 'v')
    return 1;
#endif
  /* Check whether the decimal separator is a comma.
     On NetBSD 3.0 in the fr_FR.ISO8859-1 locale, localeconv()->decimal_point
     are nl_langinfo(RADIXCHAR) are both ".".  */
  if (localeconv () ->decimal_point[0] != ',') return 1;
  return 0;
}
changequote([,])dnl
      ])])
    if AC_TRY_EVAL([ac_link]) && test -s conftest$ac_exeext; then
      # Setting LC_ALL is not enough. Need to set LC_TIME to empty, because
      # otherwise on MacOS X 10.3.5 the LC_TIME=C from the beginning of the
      # configure script would override the LC_ALL setting. Likewise for
      # LC_CTYPE, which is also set at the beginning of the configure script.
      # Test for the usual locale name.
      if (LC_ALL=fr_FR LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
        gt_cv_locale_fr_utf8=fr_FR
      else
        # Test for the locale name with explicit encoding suffix.
        if (LC_ALL=fr_FR.UTF-8 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
          gt_cv_locale_fr_utf8=fr_FR.UTF-8
        else
          # Test for the Solaris 7 locale name.
          if (LC_ALL=fr.UTF-8 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
            gt_cv_locale_fr_utf8=fr.UTF-8
          else
            # None found.
            gt_cv_locale_fr_utf8=none
          fi
        fi
      fi
    fi
    rm -fr conftest*
  ])
  LOCALE_FR_UTF8=$gt_cv_locale_fr_utf8
  AC_SUBST([LOCALE_FR_UTF8])
])

# locale-ja.m4 serial 7
dnl Copyright (C) 2003, 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

dnl Determine the name of a japanese locale with EUC-JP encoding.
AC_DEFUN([gt_LOCALE_JA],
[
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_REQUIRE([AM_LANGINFO_CODESET])
  AC_CACHE_CHECK([for a traditional japanese locale], [gt_cv_locale_ja], [
    AC_LANG_CONFTEST([AC_LANG_SOURCE([
changequote(,)dnl
#include <locale.h>
#include <time.h>
#if HAVE_LANGINFO_CODESET
# include <langinfo.h>
#endif
#include <stdlib.h>
#include <string.h>
struct tm t;
char buf[16];
int main ()
{
  const char *p;
  /* Check whether the given locale name is recognized by the system.  */
  if (setlocale (LC_ALL, "") == NULL) return 1;
  /* Check whether nl_langinfo(CODESET) is nonempty and not "ASCII" or "646".
     On MacOS X 10.3.5 (Darwin 7.5) in the fr_FR locale, nl_langinfo(CODESET)
     is empty, and the behaviour of Tcl 8.4 in this locale is not useful.
     On OpenBSD 4.0, when an unsupported locale is specified, setlocale()
     succeeds but then nl_langinfo(CODESET) is "646". In this situation,
     some unit tests fail.  */
#if HAVE_LANGINFO_CODESET
  {
    const char *cs = nl_langinfo (CODESET);
    if (cs[0] == '\0' || strcmp (cs, "ASCII") == 0 || strcmp (cs, "646") == 0)
      return 1;
  }
#endif
#ifdef __CYGWIN__
  /* On Cygwin, avoid locale names without encoding suffix, because the
     locale_charset() function relies on the encoding suffix.  Note that
     LC_ALL is set on the command line.  */
  if (strchr (getenv ("LC_ALL"), '.') == NULL) return 1;
#endif
  /* Check whether MB_CUR_MAX is > 1.  This excludes the dysfunctional locales
     on Cygwin 1.5.x.  */
  if (MB_CUR_MAX == 1)
    return 1;
  /* Check whether in a month name, no byte in the range 0x80..0x9F occurs.
     This excludes the UTF-8 encoding.  */
  t.tm_year = 1975 - 1900; t.tm_mon = 2 - 1; t.tm_mday = 4;
  if (strftime (buf, sizeof (buf), "%B", &t) < 2) return 1;
  for (p = buf; *p != '\0'; p++)
    if ((unsigned char) *p >= 0x80 && (unsigned char) *p < 0xa0)
      return 1;
  return 0;
}
changequote([,])dnl
      ])])
    if AC_TRY_EVAL([ac_link]) && test -s conftest$ac_exeext; then
      # Setting LC_ALL is not enough. Need to set LC_TIME to empty, because
      # otherwise on MacOS X 10.3.5 the LC_TIME=C from the beginning of the
      # configure script would override the LC_ALL setting. Likewise for
      # LC_CTYPE, which is also set at the beginning of the configure script.
      # Test for the AIX locale name.
      if (LC_ALL=ja_JP LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
        gt_cv_locale_ja=ja_JP
      else
        # Test for the locale name with explicit encoding suffix.
        if (LC_ALL=ja_JP.EUC-JP LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
          gt_cv_locale_ja=ja_JP.EUC-JP
        else
          # Test for the HP-UX, OSF/1, NetBSD locale name.
          if (LC_ALL=ja_JP.eucJP LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
            gt_cv_locale_ja=ja_JP.eucJP
          else
            # Test for the IRIX, FreeBSD locale name.
            if (LC_ALL=ja_JP.EUC LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
              gt_cv_locale_ja=ja_JP.EUC
            else
              # Test for the Solaris 7 locale name.
              if (LC_ALL=ja LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
                gt_cv_locale_ja=ja
              else
                # Special test for NetBSD 1.6.
                if test -f /usr/share/locale/ja_JP.eucJP/LC_CTYPE; then
                  gt_cv_locale_ja=ja_JP.eucJP
                else
                  # None found.
                  gt_cv_locale_ja=none
                fi
              fi
            fi
          fi
        fi
      fi
    fi
    rm -fr conftest*
  ])
  LOCALE_JA=$gt_cv_locale_ja
  AC_SUBST([LOCALE_JA])
])

# locale-zh.m4 serial 6
dnl Copyright (C) 2003, 2005-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.

dnl Determine the name of a chinese locale with GB18030 encoding.
AC_DEFUN([gt_LOCALE_ZH_CN],
[
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_REQUIRE([AM_LANGINFO_CODESET])
  AC_CACHE_CHECK([for a transitional chinese locale], [gt_cv_locale_zh_CN], [
    AC_LANG_CONFTEST([AC_LANG_SOURCE([
changequote(,)dnl
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#if HAVE_LANGINFO_CODESET
# include <langinfo.h>
#endif
#include <stdlib.h>
#include <string.h>
struct tm t;
char buf[16];
int main ()
{
  const char *p;
  /* Check whether the given locale name is recognized by the system.  */
  if (setlocale (LC_ALL, "") == NULL) return 1;
  /* Check whether nl_langinfo(CODESET) is nonempty and not "ASCII" or "646".
     On MacOS X 10.3.5 (Darwin 7.5) in the fr_FR locale, nl_langinfo(CODESET)
     is empty, and the behaviour of Tcl 8.4 in this locale is not useful.
     On OpenBSD 4.0, when an unsupported locale is specified, setlocale()
     succeeds but then nl_langinfo(CODESET) is "646". In this situation,
     some unit tests fail.  */
#if HAVE_LANGINFO_CODESET
  {
    const char *cs = nl_langinfo (CODESET);
    if (cs[0] == '\0' || strcmp (cs, "ASCII") == 0 || strcmp (cs, "646") == 0)
      return 1;
  }
#endif
#ifdef __CYGWIN__
  /* On Cygwin, avoid locale names without encoding suffix, because the
     locale_charset() function relies on the encoding suffix.  Note that
     LC_ALL is set on the command line.  */
  if (strchr (getenv ("LC_ALL"), '.') == NULL) return 1;
#endif
  /* Check whether in a month name, no byte in the range 0x80..0x9F occurs.
     This excludes the UTF-8 encoding.  */
  t.tm_year = 1975 - 1900; t.tm_mon = 2 - 1; t.tm_mday = 4;
  if (strftime (buf, sizeof (buf), "%B", &t) < 2) return 1;
  for (p = buf; *p != '\0'; p++)
    if ((unsigned char) *p >= 0x80 && (unsigned char) *p < 0xa0)
      return 1;
  /* Check whether a typical GB18030 multibyte sequence is recognized as a
     single wide character.  This excludes the GB2312 and GBK encodings.  */
  if (mblen ("\203\062\332\066", 5) != 4)
    return 1;
  return 0;
}
changequote([,])dnl
      ])])
    if AC_TRY_EVAL([ac_link]) && test -s conftest$ac_exeext; then
      # Setting LC_ALL is not enough. Need to set LC_TIME to empty, because
      # otherwise on MacOS X 10.3.5 the LC_TIME=C from the beginning of the
      # configure script would override the LC_ALL setting. Likewise for
      # LC_CTYPE, which is also set at the beginning of the configure script.
      # Test for the locale name without encoding suffix.
      if (LC_ALL=zh_CN LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
        gt_cv_locale_zh_CN=zh_CN
      else
        # Test for the locale name with explicit encoding suffix.
        if (LC_ALL=zh_CN.GB18030 LC_TIME= LC_CTYPE= ./conftest; exit) 2>/dev/null; then
          gt_cv_locale_zh_CN=zh_CN.GB18030
        else
          # None found.
          gt_cv_locale_zh_CN=none
        fi
      fi
    else
      # If there was a link error, due to mblen(), the system is so old that
      # it certainly doesn't have a chinese locale.
      gt_cv_locale_zh_CN=none
    fi
    rm -fr conftest*
  ])
  LOCALE_ZH_CN=$gt_cv_locale_zh_CN
  AC_SUBST([LOCALE_ZH_CN])
])

# longlong.m4 serial 14
dnl Copyright (C) 1999-2007, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Paul Eggert.

# Define HAVE_LONG_LONG_INT if 'long long int' works.
# This fixes a bug in Autoconf 2.61, but can be removed once we
# assume 2.62 everywhere.

# Note: If the type 'long long int' exists but is only 32 bits large
# (as on some very old compilers), HAVE_LONG_LONG_INT will not be
# defined. In this case you can treat 'long long int' like 'long int'.

AC_DEFUN([AC_TYPE_LONG_LONG_INT],
[
  AC_CACHE_CHECK([for long long int], [ac_cv_type_long_long_int],
    [AC_LINK_IFELSE(
       [_AC_TYPE_LONG_LONG_SNIPPET],
       [dnl This catches a bug in Tandem NonStop Kernel (OSS) cc -O circa 2004.
        dnl If cross compiling, assume the bug isn't important, since
        dnl nobody cross compiles for this platform as far as we know.
        AC_RUN_IFELSE(
          [AC_LANG_PROGRAM(
             [[@%:@include <limits.h>
               @%:@ifndef LLONG_MAX
               @%:@ define HALF \
                        (1LL << (sizeof (long long int) * CHAR_BIT - 2))
               @%:@ define LLONG_MAX (HALF - 1 + HALF)
               @%:@endif]],
             [[long long int n = 1;
               int i;
               for (i = 0; ; i++)
                 {
                   long long int m = n << i;
                   if (m >> i != n)
                     return 1;
                   if (LLONG_MAX / 2 < m)
                     break;
                 }
               return 0;]])],
          [ac_cv_type_long_long_int=yes],
          [ac_cv_type_long_long_int=no],
          [ac_cv_type_long_long_int=yes])],
       [ac_cv_type_long_long_int=no])])
  if test $ac_cv_type_long_long_int = yes; then
    AC_DEFINE([HAVE_LONG_LONG_INT], [1],
      [Define to 1 if the system has the type `long long int'.])
  fi
])

# Define HAVE_UNSIGNED_LONG_LONG_INT if 'unsigned long long int' works.
# This fixes a bug in Autoconf 2.61, but can be removed once we
# assume 2.62 everywhere.

# Note: If the type 'unsigned long long int' exists but is only 32 bits
# large (as on some very old compilers), AC_TYPE_UNSIGNED_LONG_LONG_INT
# will not be defined. In this case you can treat 'unsigned long long int'
# like 'unsigned long int'.

AC_DEFUN([AC_TYPE_UNSIGNED_LONG_LONG_INT],
[
  AC_CACHE_CHECK([for unsigned long long int],
    [ac_cv_type_unsigned_long_long_int],
    [AC_LINK_IFELSE(
       [_AC_TYPE_LONG_LONG_SNIPPET],
       [ac_cv_type_unsigned_long_long_int=yes],
       [ac_cv_type_unsigned_long_long_int=no])])
  if test $ac_cv_type_unsigned_long_long_int = yes; then
    AC_DEFINE([HAVE_UNSIGNED_LONG_LONG_INT], [1],
      [Define to 1 if the system has the type `unsigned long long int'.])
  fi
])

# Expands to a C program that can be used to test for simultaneous support
# of 'long long' and 'unsigned long long'. We don't want to say that
# 'long long' is available if 'unsigned long long' is not, or vice versa,
# because too many programs rely on the symmetry between signed and unsigned
# integer types (excluding 'bool').
AC_DEFUN([_AC_TYPE_LONG_LONG_SNIPPET],
[
  AC_LANG_PROGRAM(
    [[/* For now, do not test the preprocessor; as of 2007 there are too many
         implementations with broken preprocessors.  Perhaps this can
         be revisited in 2012.  In the meantime, code should not expect
         #if to work with literals wider than 32 bits.  */
      /* Test literals.  */
      long long int ll = 9223372036854775807ll;
      long long int nll = -9223372036854775807LL;
      unsigned long long int ull = 18446744073709551615ULL;
      /* Test constant expressions.   */
      typedef int a[((-9223372036854775807LL < 0 && 0 < 9223372036854775807ll)
                     ? 1 : -1)];
      typedef int b[(18446744073709551615ULL <= (unsigned long long int) -1
                     ? 1 : -1)];
      int i = 63;]],
    [[/* Test availability of runtime routines for shift and division.  */
      long long int llmax = 9223372036854775807ll;
      unsigned long long int ullmax = 18446744073709551615ull;
      return ((ll << 63) | (ll >> 63) | (ll < i) | (ll > i)
              | (llmax / ll) | (llmax % ll)
              | (ull << 63) | (ull >> 63) | (ull << i) | (ull >> i)
              | (ullmax / ull) | (ullmax % ull));]])
])

# mbrtowc.m4 serial 17
dnl Copyright (C) 2001-2002, 2004-2005, 2008-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_MBRTOWC],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  gl_MBSTATE_T_BROKEN

  AC_CHECK_FUNCS_ONCE([mbrtowc])
  if test $ac_cv_func_mbrtowc = no; then
    HAVE_MBRTOWC=0
  else
    if test $REPLACE_MBSTATE_T = 1; then
      REPLACE_MBRTOWC=1
    else
      gl_MBRTOWC_NULL_ARG
      gl_MBRTOWC_RETVAL
      gl_MBRTOWC_NUL_RETVAL
      case "$gl_cv_func_mbrtowc_null_arg" in
        *yes) ;;
        *) AC_DEFINE([MBRTOWC_NULL_ARG_BUG], [1],
             [Define if the mbrtowc function has the NULL string argument bug.])
           REPLACE_MBRTOWC=1
           ;;
      esac
      case "$gl_cv_func_mbrtowc_retval" in
        *yes) ;;
        *) AC_DEFINE([MBRTOWC_RETVAL_BUG], [1],
             [Define if the mbrtowc function returns a wrong return value.])
           REPLACE_MBRTOWC=1
           ;;
      esac
      case "$gl_cv_func_mbrtowc_nul_retval" in
        *yes) ;;
        *) AC_DEFINE([MBRTOWC_NUL_RETVAL_BUG], [1],
             [Define if the mbrtowc function does not return 0 for a NUL character.])
           REPLACE_MBRTOWC=1
           ;;
      esac
    fi
  fi
  if test $HAVE_MBRTOWC = 0 || test $REPLACE_MBRTOWC = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([mbrtowc])
    gl_PREREQ_MBRTOWC
  fi
])

dnl Test whether mbsinit() and mbrtowc() need to be overridden in a way that
dnl redefines the semantics of the given mbstate_t type.
dnl Result is REPLACE_MBSTATE_T.
dnl When this is set to 1, we replace both mbsinit() and mbrtowc(), in order to
dnl avoid inconsistencies.

AC_DEFUN([gl_MBSTATE_T_BROKEN],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  AC_CHECK_FUNCS_ONCE([mbsinit])
  AC_CHECK_FUNCS_ONCE([mbrtowc])
  if test $ac_cv_func_mbsinit = yes && test $ac_cv_func_mbrtowc = yes; then
    gl_MBRTOWC_INCOMPLETE_STATE
    gl_MBRTOWC_SANITYCHECK
    REPLACE_MBSTATE_T=0
    case "$gl_cv_func_mbrtowc_incomplete_state" in
      *yes) ;;
      *) REPLACE_MBSTATE_T=1 ;;
    esac
    case "$gl_cv_func_mbrtowc_sanitycheck" in
      *yes) ;;
      *) REPLACE_MBSTATE_T=1 ;;
    esac
  else
    REPLACE_MBSTATE_T=1
  fi
  if test $REPLACE_MBSTATE_T = 1; then
    gl_REPLACE_WCHAR_H
  fi
])

dnl Test whether mbrtowc puts the state into non-initial state when parsing an
dnl incomplete multibyte character.
dnl Result is gl_cv_func_mbrtowc_incomplete_state.

AC_DEFUN([gl_MBRTOWC_INCOMPLETE_STATE],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_JA])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrtowc handles incomplete characters],
    [gl_cv_func_mbrtowc_incomplete_state],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
              # Guess no on AIX and OSF/1.
        osf*) gl_cv_func_mbrtowc_incomplete_state="guessing no" ;;
              # Guess yes otherwise.
        *)    gl_cv_func_mbrtowc_incomplete_state="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_JA != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      const char input[] = "B\217\253\344\217\251\316er"; /* "Büßer" */
      mbstate_t state;
      wchar_t wc;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (&wc, input + 1, 1, &state) == (size_t)(-2))
        if (mbsinit (&state))
          return 1;
    }
  return 0;
}],
          [gl_cv_func_mbrtowc_incomplete_state=yes],
          [gl_cv_func_mbrtowc_incomplete_state=no],
          [:])
      fi
    ])
])

dnl Test whether mbrtowc works not worse than mbtowc.
dnl Result is gl_cv_func_mbrtowc_sanitycheck.

AC_DEFUN([gl_MBRTOWC_SANITYCHECK],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_ZH_CN])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrtowc works as well as mbtowc],
    [gl_cv_func_mbrtowc_sanitycheck],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                    # Guess no on Solaris 8.
        solaris2.8) gl_cv_func_mbrtowc_sanitycheck="guessing no" ;;
                    # Guess yes otherwise.
        *)          gl_cv_func_mbrtowc_sanitycheck="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_ZH_CN != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* This fails on Solaris 8:
     mbrtowc returns 2, and sets wc to 0x00F0.
     mbtowc returns 4 (correct) and sets wc to 0x5EDC.  */
  if (setlocale (LC_ALL, "$LOCALE_ZH_CN") != NULL)
    {
      char input[] = "B\250\271\201\060\211\070er"; /* "Büßer" */
      mbstate_t state;
      wchar_t wc;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (&wc, input + 3, 6, &state) != 4
          && mbtowc (&wc, input + 3, 6) == 4)
        return 1;
    }
  return 0;
}],
          [gl_cv_func_mbrtowc_sanitycheck=yes],
          [gl_cv_func_mbrtowc_sanitycheck=no],
          [:])
      fi
    ])
])

dnl Test whether mbrtowc supports a NULL string argument correctly.
dnl Result is gl_cv_func_mbrtowc_null_arg.

AC_DEFUN([gl_MBRTOWC_NULL_ARG],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_FR_UTF8])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrtowc handles a NULL string argument],
    [gl_cv_func_mbrtowc_null_arg],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
              # Guess no on OSF/1.
        osf*) gl_cv_func_mbrtowc_null_arg="guessing no" ;;
              # Guess yes otherwise.
        *)    gl_cv_func_mbrtowc_null_arg="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_FR_UTF8 != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  if (setlocale (LC_ALL, "$LOCALE_FR_UTF8") != NULL)
    {
      mbstate_t state;
      wchar_t wc;
      int ret;

      memset (&state, '\0', sizeof (mbstate_t));
      wc = (wchar_t) 0xBADFACE;
      mbrtowc (&wc, NULL, 5, &state);
      /* Check that wc was not modified.  */
      if (wc != (wchar_t) 0xBADFACE)
        return 1;
    }
  return 0;
}], [gl_cv_func_mbrtowc_null_arg=yes], [gl_cv_func_mbrtowc_null_arg=no], [:])
      fi
    ])
])

dnl Test whether mbrtowc, when parsing the end of a multibyte character,
dnl correctly returns the number of bytes that were needed to complete the
dnl character (not the total number of bytes of the multibyte character).
dnl Result is gl_cv_func_mbrtowc_retval.

AC_DEFUN([gl_MBRTOWC_RETVAL],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_FR_UTF8])
  AC_REQUIRE([gt_LOCALE_JA])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrtowc has a correct return value],
    [gl_cv_func_mbrtowc_retval],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                          # Guess no on HP-UX and Solaris.
        hpux* | solaris*) gl_cv_func_mbrtowc_retval="guessing no" ;;
                          # Guess yes otherwise.
        *)                gl_cv_func_mbrtowc_retval="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_FR_UTF8 != none || test $LOCALE_JA != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* This fails on Solaris.  */
  if (setlocale (LC_ALL, "$LOCALE_FR_UTF8") != NULL)
    {
      char input[] = "B\303\274\303\237er"; /* "Büßer" */
      mbstate_t state;
      wchar_t wc;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (&wc, input + 1, 1, &state) == (size_t)(-2))
        {
          input[1] = '\0';
          if (mbrtowc (&wc, input + 2, 5, &state) != 1)
            return 1;
        }
    }
  /* This fails on HP-UX 11.11.  */
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      char input[] = "B\217\253\344\217\251\316er"; /* "Büßer" */
      mbstate_t state;
      wchar_t wc;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (&wc, input + 1, 1, &state) == (size_t)(-2))
        {
          input[1] = '\0';
          if (mbrtowc (&wc, input + 2, 5, &state) != 2)
            return 1;
        }
    }
  return 0;
}],
          [gl_cv_func_mbrtowc_retval=yes],
          [gl_cv_func_mbrtowc_retval=no],
          [:])
      fi
    ])
])

dnl Test whether mbrtowc, when parsing a NUL character, correctly returns 0.
dnl Result is gl_cv_func_mbrtowc_nul_retval.

AC_DEFUN([gl_MBRTOWC_NUL_RETVAL],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_ZH_CN])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbrtowc returns 0 when parsing a NUL character],
    [gl_cv_func_mbrtowc_nul_retval],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                       # Guess no on Solaris 8 and 9.
        solaris2.[89]) gl_cv_func_mbrtowc_nul_retval="guessing no" ;;
                       # Guess yes otherwise.
        *)             gl_cv_func_mbrtowc_nul_retval="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_ZH_CN != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* This fails on Solaris 8 and 9.  */
  if (setlocale (LC_ALL, "$LOCALE_ZH_CN") != NULL)
    {
      mbstate_t state;
      wchar_t wc;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (&wc, "", 1, &state) != 0)
        return 1;
    }
  return 0;
}],
          [gl_cv_func_mbrtowc_nul_retval=yes],
          [gl_cv_func_mbrtowc_nul_retval=no],
          [:])
      fi
    ])
])

# Prerequisites of lib/mbrtowc.c.
AC_DEFUN([gl_PREREQ_MBRTOWC], [
  :
])


dnl From Paul Eggert

dnl This override of an autoconf macro can be removed when autoconf 2.60 or
dnl newer can be assumed everywhere.

m4_if(m4_version_compare(m4_defn([m4_PACKAGE_VERSION]),[2.60]),[-1],[
AC_DEFUN([AC_FUNC_MBRTOWC],
[
  dnl Same as AC_FUNC_MBRTOWC in autoconf-2.60.
  AC_CACHE_CHECK([whether mbrtowc and mbstate_t are properly declared],
    gl_cv_func_mbrtowc,
    [AC_LINK_IFELSE(
       [AC_LANG_PROGRAM(
            [[#include <wchar.h>]],
            [[wchar_t wc;
              char const s[] = "";
              size_t n = 1;
              mbstate_t state;
              return ! (sizeof state && (mbrtowc) (&wc, s, n, &state));]])],
       gl_cv_func_mbrtowc=yes,
       gl_cv_func_mbrtowc=no)])
  if test $gl_cv_func_mbrtowc = yes; then
    AC_DEFINE([HAVE_MBRTOWC], [1],
      [Define to 1 if mbrtowc and mbstate_t are properly declared.])
  fi
])
])

# mbsinit.m4 serial 4
dnl Copyright (C) 2008, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_MBSINIT],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  gl_MBSTATE_T_BROKEN

  AC_CHECK_FUNCS_ONCE([mbsinit])
  if test $ac_cv_func_mbsinit = no; then
    HAVE_MBSINIT=0
  else
    if test $REPLACE_MBSTATE_T = 1; then
      REPLACE_MBSINIT=1
    fi
  fi
  if test $HAVE_MBSINIT = 0 || test $REPLACE_MBSINIT = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([mbsinit])
    gl_PREREQ_MBSINIT
  fi
])

# Prerequisites of lib/mbsinit.c.
AC_DEFUN([gl_PREREQ_MBSINIT], [
  :
])

# mbsrtowcs.m4 serial 6
dnl Copyright (C) 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_MBSRTOWCS],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])

  AC_REQUIRE([AC_TYPE_MBSTATE_T])
  gl_MBSTATE_T_BROKEN

  AC_CHECK_FUNCS_ONCE([mbsrtowcs])
  if test $ac_cv_func_mbsrtowcs = no; then
    HAVE_MBSRTOWCS=0
  else
    if test $REPLACE_MBSTATE_T = 1; then
      REPLACE_MBSRTOWCS=1
    else
      gl_MBSRTOWCS_WORKS
      case "$gl_cv_func_mbsrtowcs_works" in
        *yes) ;;
        *) REPLACE_MBSRTOWCS=1 ;;
      esac
    fi
  fi
  if test $HAVE_MBSRTOWCS = 0 || test $REPLACE_MBSRTOWCS = 1; then
    gl_REPLACE_WCHAR_H
    AC_LIBOBJ([mbsrtowcs])
    AC_LIBOBJ([mbsrtowcs-state])
    gl_PREREQ_MBSRTOWCS
  fi
])

dnl Test whether mbsrtowcs works.
dnl Result is gl_cv_func_mbsrtowcs_works.

AC_DEFUN([gl_MBSRTOWCS_WORKS],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([gt_LOCALE_FR_UTF8])
  AC_REQUIRE([gt_LOCALE_JA])
  AC_REQUIRE([gt_LOCALE_ZH_CN])
  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
  AC_CACHE_CHECK([whether mbsrtowcs works],
    [gl_cv_func_mbsrtowcs_works],
    [
      dnl Initial guess, used when cross-compiling or when no suitable locale
      dnl is present.
changequote(,)dnl
      case "$host_os" in
                          # Guess no on HP-UX and Solaris.
        hpux* | solaris*) gl_cv_func_mbsrtowcs_works="guessing no" ;;
                          # Guess yes otherwise.
        *)                gl_cv_func_mbsrtowcs_works="guessing yes" ;;
      esac
changequote([,])dnl
      if test $LOCALE_FR_UTF8 != none || test $LOCALE_JA != none || test $LOCALE_ZH_CN != none; then
        AC_TRY_RUN([
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main ()
{
  /* Test whether the function works when started with a conversion state
     in non-initial state.  This fails on HP-UX 11.11 and Solaris 10.  */
  if (setlocale (LC_ALL, "$LOCALE_FR_UTF8") != NULL)
    {
      const char input[] = "B\303\274\303\237er";
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (NULL, input + 1, 1, &state) == (size_t)(-2))
        if (!mbsinit (&state))
          {
            const char *src = input + 2;
            if (mbsrtowcs (NULL, &src, 10, &state) != 4)
              return 1;
          }
    }
  if (setlocale (LC_ALL, "$LOCALE_JA") != NULL)
    {
      const char input[] = "<\306\374\313\334\270\354>";
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (NULL, input + 3, 1, &state) == (size_t)(-2))
        if (!mbsinit (&state))
          {
            const char *src = input + 4;
            if (mbsrtowcs (NULL, &src, 10, &state) != 3)
              return 1;
          }
    }
  if (setlocale (LC_ALL, "$LOCALE_ZH_CN") != NULL)
    {
      const char input[] = "B\250\271\201\060\211\070er";
      mbstate_t state;

      memset (&state, '\0', sizeof (mbstate_t));
      if (mbrtowc (NULL, input + 1, 1, &state) == (size_t)(-2))
        if (!mbsinit (&state))
          {
            const char *src = input + 2;
            if (mbsrtowcs (NULL, &src, 10, &state) != 4)
              return 1;
          }
    }
  return 0;
}],
          [gl_cv_func_mbsrtowcs_works=yes],
          [gl_cv_func_mbsrtowcs_works=no],
          [:])
      fi
    ])
])

# Prerequisites of lib/mbsrtowcs.c.
AC_DEFUN([gl_PREREQ_MBSRTOWCS], [
  :
])

# mbstate_t.m4 serial 12
dnl Copyright (C) 2000-2002, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# From Paul Eggert.

# BeOS 5 has <wchar.h> but does not define mbstate_t,
# so you can't declare an object of that type.
# Check for this incompatibility with Standard C.

# AC_TYPE_MBSTATE_T
# -----------------
AC_DEFUN([AC_TYPE_MBSTATE_T],
[
   AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS]) dnl for HP-UX 11.11

   AC_CACHE_CHECK([for mbstate_t], [ac_cv_type_mbstate_t],
     [AC_COMPILE_IFELSE(
        [AC_LANG_PROGRAM(
           [AC_INCLUDES_DEFAULT[
#           include <wchar.h>]],
           [[mbstate_t x; return sizeof x;]])],
        [ac_cv_type_mbstate_t=yes],
        [ac_cv_type_mbstate_t=no])])
   if test $ac_cv_type_mbstate_t = yes; then
     AC_DEFINE([HAVE_MBSTATE_T], [1],
               [Define to 1 if <wchar.h> declares mbstate_t.])
   else
     AC_DEFINE([mbstate_t], [int],
               [Define to a type if <wchar.h> does not define.])
   fi
])

# memchr.m4 serial 8
dnl Copyright (C) 2002-2004, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN_ONCE([gl_FUNC_MEMCHR],
[
  dnl Check for prerequisites for memory fence checks.
  gl_FUNC_MMAP_ANON
  AC_CHECK_HEADERS_ONCE([sys/mman.h])
  AC_CHECK_FUNCS_ONCE([mprotect])

  dnl These days, we assume memchr is present.  But just in case...
  AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
  AC_CHECK_FUNCS_ONCE([memchr])
  if test $ac_cv_func_memchr = yes; then
    # Detect platform-specific bugs in some versions of glibc:
    # memchr should not dereference anything with length 0
    #   http://bugzilla.redhat.com/499689
    # memchr should not dereference overestimated length after a match
    #   http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=521737
    #   http://sourceware.org/bugzilla/show_bug.cgi?id=10162
    # Assume that memchr works on platforms that lack mprotect.
    AC_CACHE_CHECK([whether memchr works], [gl_cv_func_memchr_works],
      [AC_RUN_IFELSE([AC_LANG_PROGRAM([[
#include <string.h>
#if HAVE_SYS_MMAN_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/mman.h>
# ifndef MAP_FILE
#  define MAP_FILE 0
# endif
#endif
]], [[
  char *fence = NULL;
#if HAVE_SYS_MMAN_H && HAVE_MPROTECT
# if HAVE_MAP_ANONYMOUS
  const int flags = MAP_ANONYMOUS | MAP_PRIVATE;
  const int fd = -1;
# else /* !HAVE_MAP_ANONYMOUS */
  const int flags = MAP_FILE | MAP_PRIVATE;
  int fd = open ("/dev/zero", O_RDONLY, 0666);
  if (fd >= 0)
# endif
    {
      int pagesize = getpagesize ();
      char *two_pages =
        (char *) mmap (NULL, 2 * pagesize, PROT_READ | PROT_WRITE,
                       flags, fd, 0);
      if (two_pages != (char *)(-1)
          && mprotect (two_pages + pagesize, pagesize, PROT_NONE) == 0)
        fence = two_pages + pagesize;
    }
#endif
  if (fence)
    {
      if (memchr (fence, 0, 0))
        return 1;
      strcpy (fence - 9, "12345678");
      if (memchr (fence - 9, 0, 79) != fence - 1)
        return 2;
    }
  return 0;
]])], [gl_cv_func_memchr_works=yes], [gl_cv_func_memchr_works=no],
      [dnl Be pessimistic for now.
       gl_cv_func_memchr_works="guessing no"])])
    if test "$gl_cv_func_memchr_works" != yes; then
      REPLACE_MEMCHR=1
    fi
  else
    HAVE_MEMCHR=0
  fi
  if test $HAVE_MEMCHR = 0 || test $REPLACE_MEMCHR = 1; then
    AC_LIBOBJ([memchr])
    gl_PREREQ_MEMCHR
  fi
])

# Prerequisites of lib/memchr.c.
AC_DEFUN([gl_PREREQ_MEMCHR], [
  AC_CHECK_HEADERS([bp-sym.h])
])

# mmap-anon.m4 serial 8
dnl Copyright (C) 2005, 2007, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Detect how mmap can be used to create anonymous (not file-backed) memory
# mappings.
# - On Linux, AIX, OSF/1, Solaris, Cygwin, Interix, Haiku, both MAP_ANONYMOUS
#   and MAP_ANON exist and have the same value.
# - On HP-UX, only MAP_ANONYMOUS exists.
# - On MacOS X, FreeBSD, NetBSD, OpenBSD, only MAP_ANON exists.
# - On IRIX, neither exists, and a file descriptor opened to /dev/zero must be
#   used.

AC_DEFUN([gl_FUNC_MMAP_ANON],
[
  dnl Work around a bug of AC_EGREP_CPP in autoconf-2.57.
  AC_REQUIRE([AC_PROG_CPP])
  AC_REQUIRE([AC_PROG_EGREP])

  dnl Persuade glibc <sys/mman.h> to define MAP_ANONYMOUS.
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])

  # Check for mmap(). Don't use AC_FUNC_MMAP, because it checks too much: it
  # fails on HP-UX 11, because MAP_FIXED mappings do not work. But this is
  # irrelevant for anonymous mappings.
  AC_CHECK_FUNC([mmap], [gl_have_mmap=yes], [gl_have_mmap=no])

  # Try to allow MAP_ANONYMOUS.
  gl_have_mmap_anonymous=no
  if test $gl_have_mmap = yes; then
    AC_MSG_CHECKING([for MAP_ANONYMOUS])
    AC_EGREP_CPP([I cant identify this map.], [
#include <sys/mman.h>
#ifdef MAP_ANONYMOUS
    I cant identify this map.
#endif
],
      [gl_have_mmap_anonymous=yes])
    if test $gl_have_mmap_anonymous != yes; then
      AC_EGREP_CPP([I cant identify this map.], [
#include <sys/mman.h>
#ifdef MAP_ANON
    I cant identify this map.
#endif
],
        [AC_DEFINE([MAP_ANONYMOUS], [MAP_ANON],
          [Define to a substitute value for mmap()'s MAP_ANONYMOUS flag.])
         gl_have_mmap_anonymous=yes])
    fi
    AC_MSG_RESULT([$gl_have_mmap_anonymous])
    if test $gl_have_mmap_anonymous = yes; then
      AC_DEFINE([HAVE_MAP_ANONYMOUS], [1],
        [Define to 1 if mmap()'s MAP_ANONYMOUS flag is available after including
         config.h and <sys/mman.h>.])
    fi
  fi
])

# multiarch.m4 serial 5
dnl Copyright (C) 2008, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Determine whether the compiler is or may be producing universal binaries.
#
# On MacOS X 10.5 and later systems, the user can create libraries and
# executables that work on multiple system types--known as "fat" or
# "universal" binaries--by specifying multiple '-arch' options to the
# compiler but only a single '-arch' option to the preprocessor.  Like
# this:
#
#     ./configure CC="gcc -arch i386 -arch x86_64 -arch ppc -arch ppc64" \
#                 CXX="g++ -arch i386 -arch x86_64 -arch ppc -arch ppc64" \
#                 CPP="gcc -E" CXXCPP="g++ -E"
#
# Detect this situation and set the macro AA_APPLE_UNIVERSAL_BUILD at the
# beginning of config.h and set APPLE_UNIVERSAL_BUILD accordingly.

AC_DEFUN_ONCE([gl_MULTIARCH],
[
  dnl Code similar to autoconf-2.63 AC_C_BIGENDIAN.
  gl_cv_c_multiarch=no
  AC_COMPILE_IFELSE(
    [AC_LANG_SOURCE(
      [[#ifndef __APPLE_CC__
         not a universal capable compiler
        #endif
        typedef int dummy;
      ]])],
    [
     dnl Check for potential -arch flags.  It is not universal unless
     dnl there are at least two -arch flags with different values.
     arch=
     prev=
     for word in ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}; do
       if test -n "$prev"; then
         case $word in
           i?86 | x86_64 | ppc | ppc64)
             if test -z "$arch" || test "$arch" = "$word"; then
               arch="$word"
             else
               gl_cv_c_multiarch=yes
             fi
             ;;
         esac
         prev=
       else
         if test "x$word" = "x-arch"; then
           prev=arch
         fi
       fi
     done
    ])
  if test $gl_cv_c_multiarch = yes; then
    AC_DEFINE([AA_APPLE_UNIVERSAL_BUILD], [1],
      [Define if the compiler is building for multiple architectures of Apple platforms at once.])
    APPLE_UNIVERSAL_BUILD=1
  else
    APPLE_UNIVERSAL_BUILD=0
  fi
  AC_SUBST([APPLE_UNIVERSAL_BUILD])
])

# nl_langinfo.m4 serial 3
dnl Copyright (C) 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_NL_LANGINFO],
[
  AC_REQUIRE([gl_LANGINFO_H_DEFAULTS])
  AC_REQUIRE([gl_LANGINFO_H])
  AC_CHECK_FUNCS_ONCE([nl_langinfo])
  if test $ac_cv_func_nl_langinfo = yes; then
    if test $HAVE_LANGINFO_CODESET = 1 && test $HAVE_LANGINFO_ERA = 1; then
      :
    else
      REPLACE_NL_LANGINFO=1
      AC_DEFINE([REPLACE_NL_LANGINFO], [1],
        [Define if nl_langinfo exists but is overridden by gnulib.])
      AC_LIBOBJ([nl_langinfo])
    fi
  else
    HAVE_NL_LANGINFO=0
    AC_LIBOBJ([nl_langinfo])
  fi
])

# nls.m4 serial 5 (gettext-0.18)
dnl Copyright (C) 1995-2003, 2005-2006, 2008-2010 Free Software Foundation,
dnl Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Authors:
dnl   Ulrich Drepper <drepper@cygnus.com>, 1995-2000.
dnl   Bruno Haible <haible@clisp.cons.org>, 2000-2003.

AC_PREREQ([2.50])

AC_DEFUN([AM_NLS],
[
  AC_MSG_CHECKING([whether NLS is requested])
  dnl Default is enabled NLS
  AC_ARG_ENABLE([nls],
    [  --disable-nls           do not use Native Language Support],
    USE_NLS=$enableval, USE_NLS=yes)
  AC_MSG_RESULT([$USE_NLS])
  AC_SUBST([USE_NLS])
])

# no-c++.m4 serial 1
dnl Copyright (C) 2006, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Support for C source files that cannot be compiled by a C++ compiler.
# Set NO_CXX to the C++ compiler flags needed to request C mode instead of
# C++ mode.
# So far only g++ is supported.

AC_DEFUN([gt_NO_CXX],
[
  NO_CXX=
  AC_EGREP_CPP([Is g++], [
#if defined __GNUC__ && defined __cplusplus
  Is g++
#endif
    ],
    [NO_CXX="-x c"])
  AC_SUBST([NO_CXX])
])

# nocrash.m4 serial 2
dnl Copyright (C) 2005, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Based on libsigsegv, from Bruno Haible and Paolo Bonzini.

AC_PREREQ([2.13])

dnl Expands to some code for use in .c programs that will cause the configure
dnl test to exit instead of crashing. This is useful to avoid triggering
dnl action from a background debugger and to avoid core dumps.
dnl Usage:   ...
dnl          ]GL_NOCRASH[
dnl          ...
dnl          int main() { nocrash_init(); ... }
AC_DEFUN([GL_NOCRASH],[[
#include <stdlib.h>
#if defined __MACH__ && defined __APPLE__
/* Avoid a crash on MacOS X.  */
#include <mach/mach.h>
#include <mach/mach_error.h>
#include <mach/thread_status.h>
#include <mach/exception.h>
#include <mach/task.h>
#include <pthread.h>
/* The exception port on which our thread listens.  */
static mach_port_t our_exception_port;
/* The main function of the thread listening for exceptions of type
   EXC_BAD_ACCESS.  */
static void *
mach_exception_thread (void *arg)
{
  /* Buffer for a message to be received.  */
  struct {
    mach_msg_header_t head;
    mach_msg_body_t msgh_body;
    char data[1024];
  } msg;
  mach_msg_return_t retval;
  /* Wait for a message on the exception port.  */
  retval = mach_msg (&msg.head, MACH_RCV_MSG | MACH_RCV_LARGE, 0, sizeof (msg),
                     our_exception_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
  if (retval != MACH_MSG_SUCCESS)
    abort ();
  exit (1);
}
static void
nocrash_init (void)
{
  mach_port_t self = mach_task_self ();
  /* Allocate a port on which the thread shall listen for exceptions.  */
  if (mach_port_allocate (self, MACH_PORT_RIGHT_RECEIVE, &our_exception_port)
      == KERN_SUCCESS) {
    /* See http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/mach_port_insert_right.html.  */
    if (mach_port_insert_right (self, our_exception_port, our_exception_port,
                                MACH_MSG_TYPE_MAKE_SEND)
        == KERN_SUCCESS) {
      /* The exceptions we want to catch.  Only EXC_BAD_ACCESS is interesting
         for us.  */
      exception_mask_t mask = EXC_MASK_BAD_ACCESS;
      /* Create the thread listening on the exception port.  */
      pthread_attr_t attr;
      pthread_t thread;
      if (pthread_attr_init (&attr) == 0
          && pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED) == 0
          && pthread_create (&thread, &attr, mach_exception_thread, NULL) == 0) {
        pthread_attr_destroy (&attr);
        /* Replace the exception port info for these exceptions with our own.
           Note that we replace the exception port for the entire task, not only
           for a particular thread.  This has the effect that when our exception
           port gets the message, the thread specific exception port has already
           been asked, and we don't need to bother about it.
           See http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/task_set_exception_ports.html.  */
        task_set_exception_ports (self, mask, our_exception_port,
                                  EXCEPTION_DEFAULT, MACHINE_THREAD_STATE);
      }
    }
  }
}
#else
/* Avoid a crash on POSIX systems.  */
#include <signal.h>
/* A POSIX signal handler.  */
static void
exception_handler (int sig)
{
  exit (1);
}
static void
nocrash_init (void)
{
#ifdef SIGSEGV
  signal (SIGSEGV, exception_handler);
#endif
#ifdef SIGBUS
  signal (SIGBUS, exception_handler);
#endif
}
#endif
]])

# po.m4 serial 17 (gettext-0.18)
dnl Copyright (C) 1995-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Authors:
dnl   Ulrich Drepper <drepper@cygnus.com>, 1995-2000.
dnl   Bruno Haible <haible@clisp.cons.org>, 2000-2003.

AC_PREREQ([2.50])

dnl Checks for all prerequisites of the po subdirectory.
AC_DEFUN([AM_PO_SUBDIRS],
[
  AC_REQUIRE([AC_PROG_MAKE_SET])dnl
  AC_REQUIRE([AC_PROG_INSTALL])dnl
  AC_REQUIRE([AM_PROG_MKDIR_P])dnl defined by automake
  AC_REQUIRE([AM_NLS])dnl

  dnl Release version of the gettext macros. This is used to ensure that
  dnl the gettext macros and po/Makefile.in.in are in sync.
  AC_SUBST([GETTEXT_MACRO_VERSION], [0.18])

  dnl Perform the following tests also if --disable-nls has been given,
  dnl because they are needed for "make dist" to work.

  dnl Search for GNU msgfmt in the PATH.
  dnl The first test excludes Solaris msgfmt and early GNU msgfmt versions.
  dnl The second test excludes FreeBSD msgfmt.
  AM_PATH_PROG_WITH_TEST(MSGFMT, msgfmt,
    [$ac_dir/$ac_word --statistics /dev/null >&]AS_MESSAGE_LOG_FD[ 2>&1 &&
     (if $ac_dir/$ac_word --statistics /dev/null 2>&1 >/dev/null | grep usage >/dev/null; then exit 1; else exit 0; fi)],
    :)
  AC_PATH_PROG([GMSGFMT], [gmsgfmt], [$MSGFMT])

  dnl Test whether it is GNU msgfmt >= 0.15.
changequote(,)dnl
  case `$MSGFMT --version | sed 1q | sed -e 's,^[^0-9]*,,'` in
    '' | 0.[0-9] | 0.[0-9].* | 0.1[0-4] | 0.1[0-4].*) MSGFMT_015=: ;;
    *) MSGFMT_015=$MSGFMT ;;
  esac
changequote([,])dnl
  AC_SUBST([MSGFMT_015])
changequote(,)dnl
  case `$GMSGFMT --version | sed 1q | sed -e 's,^[^0-9]*,,'` in
    '' | 0.[0-9] | 0.[0-9].* | 0.1[0-4] | 0.1[0-4].*) GMSGFMT_015=: ;;
    *) GMSGFMT_015=$GMSGFMT ;;
  esac
changequote([,])dnl
  AC_SUBST([GMSGFMT_015])

  dnl Search for GNU xgettext 0.12 or newer in the PATH.
  dnl The first test excludes Solaris xgettext and early GNU xgettext versions.
  dnl The second test excludes FreeBSD xgettext.
  AM_PATH_PROG_WITH_TEST(XGETTEXT, xgettext,
    [$ac_dir/$ac_word --omit-header --copyright-holder= --msgid-bugs-address= /dev/null >&]AS_MESSAGE_LOG_FD[ 2>&1 &&
     (if $ac_dir/$ac_word --omit-header --copyright-holder= --msgid-bugs-address= /dev/null 2>&1 >/dev/null | grep usage >/dev/null; then exit 1; else exit 0; fi)],
    :)
  dnl Remove leftover from FreeBSD xgettext call.
  rm -f messages.po

  dnl Test whether it is GNU xgettext >= 0.15.
changequote(,)dnl
  case `$XGETTEXT --version | sed 1q | sed -e 's,^[^0-9]*,,'` in
    '' | 0.[0-9] | 0.[0-9].* | 0.1[0-4] | 0.1[0-4].*) XGETTEXT_015=: ;;
    *) XGETTEXT_015=$XGETTEXT ;;
  esac
changequote([,])dnl
  AC_SUBST([XGETTEXT_015])

  dnl Search for GNU msgmerge 0.11 or newer in the PATH.
  AM_PATH_PROG_WITH_TEST(MSGMERGE, msgmerge,
    [$ac_dir/$ac_word --update -q /dev/null /dev/null >&]AS_MESSAGE_LOG_FD[ 2>&1], :)

  dnl Installation directories.
  dnl Autoconf >= 2.60 defines localedir. For older versions of autoconf, we
  dnl have to define it here, so that it can be used in po/Makefile.
  test -n "$localedir" || localedir='${datadir}/locale'
  AC_SUBST([localedir])

  dnl Support for AM_XGETTEXT_OPTION.
  test -n "${XGETTEXT_EXTRA_OPTIONS+set}" || XGETTEXT_EXTRA_OPTIONS=
  AC_SUBST([XGETTEXT_EXTRA_OPTIONS])

  AC_CONFIG_COMMANDS([po-directories], [[
    for ac_file in $CONFIG_FILES; do
      # Support "outfile[:infile[:infile...]]"
      case "$ac_file" in
        *:*) ac_file=`echo "$ac_file"|sed 's%:.*%%'` ;;
      esac
      # PO directories have a Makefile.in generated from Makefile.in.in.
      case "$ac_file" in */Makefile.in)
        # Adjust a relative srcdir.
        ac_dir=`echo "$ac_file"|sed 's%/[^/][^/]*$%%'`
        ac_dir_suffix="/`echo "$ac_dir"|sed 's%^\./%%'`"
        ac_dots=`echo "$ac_dir_suffix"|sed 's%/[^/]*%../%g'`
        # In autoconf-2.13 it is called $ac_given_srcdir.
        # In autoconf-2.50 it is called $srcdir.
        test -n "$ac_given_srcdir" || ac_given_srcdir="$srcdir"
        case "$ac_given_srcdir" in
          .)  top_srcdir=`echo $ac_dots|sed 's%/$%%'` ;;
          /*) top_srcdir="$ac_given_srcdir" ;;
          *)  top_srcdir="$ac_dots$ac_given_srcdir" ;;
        esac
        # Treat a directory as a PO directory if and only if it has a
        # POTFILES.in file. This allows packages to have multiple PO
        # directories under different names or in different locations.
        if test -f "$ac_given_srcdir/$ac_dir/POTFILES.in"; then
          rm -f "$ac_dir/POTFILES"
          test -n "$as_me" && echo "$as_me: creating $ac_dir/POTFILES" || echo "creating $ac_dir/POTFILES"
          cat "$ac_given_srcdir/$ac_dir/POTFILES.in" | sed -e "/^#/d" -e "/^[ 	]*\$/d" -e "s,.*,     $top_srcdir/& \\\\," | sed -e "\$s/\(.*\) \\\\/\1/" > "$ac_dir/POTFILES"
          POMAKEFILEDEPS="POTFILES.in"
          # ALL_LINGUAS, POFILES, UPDATEPOFILES, DUMMYPOFILES, GMOFILES depend
          # on $ac_dir but don't depend on user-specified configuration
          # parameters.
          if test -f "$ac_given_srcdir/$ac_dir/LINGUAS"; then
            # The LINGUAS file contains the set of available languages.
            if test -n "$OBSOLETE_ALL_LINGUAS"; then
              test -n "$as_me" && echo "$as_me: setting ALL_LINGUAS in configure.in is obsolete" || echo "setting ALL_LINGUAS in configure.in is obsolete"
            fi
            ALL_LINGUAS_=`sed -e "/^#/d" -e "s/#.*//" "$ac_given_srcdir/$ac_dir/LINGUAS"`
            # Hide the ALL_LINGUAS assigment from automake < 1.5.
            eval 'ALL_LINGUAS''=$ALL_LINGUAS_'
            POMAKEFILEDEPS="$POMAKEFILEDEPS LINGUAS"
          else
            # The set of available languages was given in configure.in.
            # Hide the ALL_LINGUAS assigment from automake < 1.5.
            eval 'ALL_LINGUAS''=$OBSOLETE_ALL_LINGUAS'
          fi
          # Compute POFILES
          # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(lang).po)
          # Compute UPDATEPOFILES
          # as      $(foreach lang, $(ALL_LINGUAS), $(lang).po-update)
          # Compute DUMMYPOFILES
          # as      $(foreach lang, $(ALL_LINGUAS), $(lang).nop)
          # Compute GMOFILES
          # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(lang).gmo)
          case "$ac_given_srcdir" in
            .) srcdirpre= ;;
            *) srcdirpre='$(srcdir)/' ;;
          esac
          POFILES=
          UPDATEPOFILES=
          DUMMYPOFILES=
          GMOFILES=
          for lang in $ALL_LINGUAS; do
            POFILES="$POFILES $srcdirpre$lang.po"
            UPDATEPOFILES="$UPDATEPOFILES $lang.po-update"
            DUMMYPOFILES="$DUMMYPOFILES $lang.nop"
            GMOFILES="$GMOFILES $srcdirpre$lang.gmo"
          done
          # CATALOGS depends on both $ac_dir and the user's LINGUAS
          # environment variable.
          INST_LINGUAS=
          if test -n "$ALL_LINGUAS"; then
            for presentlang in $ALL_LINGUAS; do
              useit=no
              if test "%UNSET%" != "$LINGUAS"; then
                desiredlanguages="$LINGUAS"
              else
                desiredlanguages="$ALL_LINGUAS"
              fi
              for desiredlang in $desiredlanguages; do
                # Use the presentlang catalog if desiredlang is
                #   a. equal to presentlang, or
                #   b. a variant of presentlang (because in this case,
                #      presentlang can be used as a fallback for messages
                #      which are not translated in the desiredlang catalog).
                case "$desiredlang" in
                  "$presentlang"*) useit=yes;;
                esac
              done
              if test $useit = yes; then
                INST_LINGUAS="$INST_LINGUAS $presentlang"
              fi
            done
          fi
          CATALOGS=
          if test -n "$INST_LINGUAS"; then
            for lang in $INST_LINGUAS; do
              CATALOGS="$CATALOGS $lang.gmo"
            done
          fi
          test -n "$as_me" && echo "$as_me: creating $ac_dir/Makefile" || echo "creating $ac_dir/Makefile"
          sed -e "/^POTFILES =/r $ac_dir/POTFILES" -e "/^# Makevars/r $ac_given_srcdir/$ac_dir/Makevars" -e "s|@POFILES@|$POFILES|g" -e "s|@UPDATEPOFILES@|$UPDATEPOFILES|g" -e "s|@DUMMYPOFILES@|$DUMMYPOFILES|g" -e "s|@GMOFILES@|$GMOFILES|g" -e "s|@CATALOGS@|$CATALOGS|g" -e "s|@POMAKEFILEDEPS@|$POMAKEFILEDEPS|g" "$ac_dir/Makefile.in" > "$ac_dir/Makefile"
          for f in "$ac_given_srcdir/$ac_dir"/Rules-*; do
            if test -f "$f"; then
              case "$f" in
                *.orig | *.bak | *~) ;;
                *) cat "$f" >> "$ac_dir/Makefile" ;;
              esac
            fi
          done
        fi
        ;;
      esac
    done]],
   [# Capture the value of obsolete ALL_LINGUAS because we need it to compute
    # POFILES, UPDATEPOFILES, DUMMYPOFILES, GMOFILES, CATALOGS. But hide it
    # from automake < 1.5.
    eval 'OBSOLETE_ALL_LINGUAS''="$ALL_LINGUAS"'
    # Capture the value of LINGUAS because we need it to compute CATALOGS.
    LINGUAS="${LINGUAS-%UNSET%}"
   ])
])

dnl Postprocesses a Makefile in a directory containing PO files.
AC_DEFUN([AM_POSTPROCESS_PO_MAKEFILE],
[
  # When this code is run, in config.status, two variables have already been
  # set:
  # - OBSOLETE_ALL_LINGUAS is the value of LINGUAS set in configure.in,
  # - LINGUAS is the value of the environment variable LINGUAS at configure
  #   time.

changequote(,)dnl
  # Adjust a relative srcdir.
  ac_dir=`echo "$ac_file"|sed 's%/[^/][^/]*$%%'`
  ac_dir_suffix="/`echo "$ac_dir"|sed 's%^\./%%'`"
  ac_dots=`echo "$ac_dir_suffix"|sed 's%/[^/]*%../%g'`
  # In autoconf-2.13 it is called $ac_given_srcdir.
  # In autoconf-2.50 it is called $srcdir.
  test -n "$ac_given_srcdir" || ac_given_srcdir="$srcdir"
  case "$ac_given_srcdir" in
    .)  top_srcdir=`echo $ac_dots|sed 's%/$%%'` ;;
    /*) top_srcdir="$ac_given_srcdir" ;;
    *)  top_srcdir="$ac_dots$ac_given_srcdir" ;;
  esac

  # Find a way to echo strings without interpreting backslash.
  if test "X`(echo '\t') 2>/dev/null`" = 'X\t'; then
    gt_echo='echo'
  else
    if test "X`(printf '%s\n' '\t') 2>/dev/null`" = 'X\t'; then
      gt_echo='printf %s\n'
    else
      echo_func () {
        cat <<EOT
$*
EOT
      }
      gt_echo='echo_func'
    fi
  fi

  # A sed script that extracts the value of VARIABLE from a Makefile.
  sed_x_variable='
# Test if the hold space is empty.
x
s/P/P/
x
ta
# Yes it was empty. Look if we have the expected variable definition.
/^[	 ]*VARIABLE[	 ]*=/{
  # Seen the first line of the variable definition.
  s/^[	 ]*VARIABLE[	 ]*=//
  ba
}
bd
:a
# Here we are processing a line from the variable definition.
# Remove comment, more precisely replace it with a space.
s/#.*$/ /
# See if the line ends in a backslash.
tb
:b
s/\\$//
# Print the line, without the trailing backslash.
p
tc
# There was no trailing backslash. The end of the variable definition is
# reached. Clear the hold space.
s/^.*$//
x
bd
:c
# A trailing backslash means that the variable definition continues in the
# next line. Put a nonempty string into the hold space to indicate this.
s/^.*$/P/
x
:d
'
changequote([,])dnl

  # Set POTFILES to the value of the Makefile variable POTFILES.
  sed_x_POTFILES=`$gt_echo "$sed_x_variable" | sed -e '/^ *#/d' -e 's/VARIABLE/POTFILES/g'`
  POTFILES=`sed -n -e "$sed_x_POTFILES" < "$ac_file"`
  # Compute POTFILES_DEPS as
  #   $(foreach file, $(POTFILES), $(top_srcdir)/$(file))
  POTFILES_DEPS=
  for file in $POTFILES; do
    POTFILES_DEPS="$POTFILES_DEPS "'$(top_srcdir)/'"$file"
  done
  POMAKEFILEDEPS=""

  if test -n "$OBSOLETE_ALL_LINGUAS"; then
    test -n "$as_me" && echo "$as_me: setting ALL_LINGUAS in configure.in is obsolete" || echo "setting ALL_LINGUAS in configure.in is obsolete"
  fi
  if test -f "$ac_given_srcdir/$ac_dir/LINGUAS"; then
    # The LINGUAS file contains the set of available languages.
    ALL_LINGUAS_=`sed -e "/^#/d" -e "s/#.*//" "$ac_given_srcdir/$ac_dir/LINGUAS"`
    POMAKEFILEDEPS="$POMAKEFILEDEPS LINGUAS"
  else
    # Set ALL_LINGUAS to the value of the Makefile variable LINGUAS.
    sed_x_LINGUAS=`$gt_echo "$sed_x_variable" | sed -e '/^ *#/d' -e 's/VARIABLE/LINGUAS/g'`
    ALL_LINGUAS_=`sed -n -e "$sed_x_LINGUAS" < "$ac_file"`
  fi
  # Hide the ALL_LINGUAS assigment from automake < 1.5.
  eval 'ALL_LINGUAS''=$ALL_LINGUAS_'
  # Compute POFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(lang).po)
  # Compute UPDATEPOFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(lang).po-update)
  # Compute DUMMYPOFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(lang).nop)
  # Compute GMOFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(lang).gmo)
  # Compute PROPERTIESFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(top_srcdir)/$(DOMAIN)_$(lang).properties)
  # Compute CLASSFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(top_srcdir)/$(DOMAIN)_$(lang).class)
  # Compute QMFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(lang).qm)
  # Compute MSGFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(frob $(lang)).msg)
  # Compute RESOURCESDLLFILES
  # as      $(foreach lang, $(ALL_LINGUAS), $(srcdir)/$(frob $(lang))/$(DOMAIN).resources.dll)
  case "$ac_given_srcdir" in
    .) srcdirpre= ;;
    *) srcdirpre='$(srcdir)/' ;;
  esac
  POFILES=
  UPDATEPOFILES=
  DUMMYPOFILES=
  GMOFILES=
  PROPERTIESFILES=
  CLASSFILES=
  QMFILES=
  MSGFILES=
  RESOURCESDLLFILES=
  for lang in $ALL_LINGUAS; do
    POFILES="$POFILES $srcdirpre$lang.po"
    UPDATEPOFILES="$UPDATEPOFILES $lang.po-update"
    DUMMYPOFILES="$DUMMYPOFILES $lang.nop"
    GMOFILES="$GMOFILES $srcdirpre$lang.gmo"
    PROPERTIESFILES="$PROPERTIESFILES \$(top_srcdir)/\$(DOMAIN)_$lang.properties"
    CLASSFILES="$CLASSFILES \$(top_srcdir)/\$(DOMAIN)_$lang.class"
    QMFILES="$QMFILES $srcdirpre$lang.qm"
    frobbedlang=`echo $lang | sed -e 's/\..*$//' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
    MSGFILES="$MSGFILES $srcdirpre$frobbedlang.msg"
    frobbedlang=`echo $lang | sed -e 's/_/-/g' -e 's/^sr-CS/sr-SP/' -e 's/@latin$/-Latn/' -e 's/@cyrillic$/-Cyrl/' -e 's/^sr-SP$/sr-SP-Latn/' -e 's/^uz-UZ$/uz-UZ-Latn/'`
    RESOURCESDLLFILES="$RESOURCESDLLFILES $srcdirpre$frobbedlang/\$(DOMAIN).resources.dll"
  done
  # CATALOGS depends on both $ac_dir and the user's LINGUAS
  # environment variable.
  INST_LINGUAS=
  if test -n "$ALL_LINGUAS"; then
    for presentlang in $ALL_LINGUAS; do
      useit=no
      if test "%UNSET%" != "$LINGUAS"; then
        desiredlanguages="$LINGUAS"
      else
        desiredlanguages="$ALL_LINGUAS"
      fi
      for desiredlang in $desiredlanguages; do
        # Use the presentlang catalog if desiredlang is
        #   a. equal to presentlang, or
        #   b. a variant of presentlang (because in this case,
        #      presentlang can be used as a fallback for messages
        #      which are not translated in the desiredlang catalog).
        case "$desiredlang" in
          "$presentlang"*) useit=yes;;
        esac
      done
      if test $useit = yes; then
        INST_LINGUAS="$INST_LINGUAS $presentlang"
      fi
    done
  fi
  CATALOGS=
  JAVACATALOGS=
  QTCATALOGS=
  TCLCATALOGS=
  CSHARPCATALOGS=
  if test -n "$INST_LINGUAS"; then
    for lang in $INST_LINGUAS; do
      CATALOGS="$CATALOGS $lang.gmo"
      JAVACATALOGS="$JAVACATALOGS \$(DOMAIN)_$lang.properties"
      QTCATALOGS="$QTCATALOGS $lang.qm"
      frobbedlang=`echo $lang | sed -e 's/\..*$//' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
      TCLCATALOGS="$TCLCATALOGS $frobbedlang.msg"
      frobbedlang=`echo $lang | sed -e 's/_/-/g' -e 's/^sr-CS/sr-SP/' -e 's/@latin$/-Latn/' -e 's/@cyrillic$/-Cyrl/' -e 's/^sr-SP$/sr-SP-Latn/' -e 's/^uz-UZ$/uz-UZ-Latn/'`
      CSHARPCATALOGS="$CSHARPCATALOGS $frobbedlang/\$(DOMAIN).resources.dll"
    done
  fi

  sed -e "s|@POTFILES_DEPS@|$POTFILES_DEPS|g" -e "s|@POFILES@|$POFILES|g" -e "s|@UPDATEPOFILES@|$UPDATEPOFILES|g" -e "s|@DUMMYPOFILES@|$DUMMYPOFILES|g" -e "s|@GMOFILES@|$GMOFILES|g" -e "s|@PROPERTIESFILES@|$PROPERTIESFILES|g" -e "s|@CLASSFILES@|$CLASSFILES|g" -e "s|@QMFILES@|$QMFILES|g" -e "s|@MSGFILES@|$MSGFILES|g" -e "s|@RESOURCESDLLFILES@|$RESOURCESDLLFILES|g" -e "s|@CATALOGS@|$CATALOGS|g" -e "s|@JAVACATALOGS@|$JAVACATALOGS|g" -e "s|@QTCATALOGS@|$QTCATALOGS|g" -e "s|@TCLCATALOGS@|$TCLCATALOGS|g" -e "s|@CSHARPCATALOGS@|$CSHARPCATALOGS|g" -e 's,^#distdir:,distdir:,' < "$ac_file" > "$ac_file.tmp"
  if grep -l '@TCLCATALOGS@' "$ac_file" > /dev/null; then
    # Add dependencies that cannot be formulated as a simple suffix rule.
    for lang in $ALL_LINGUAS; do
      frobbedlang=`echo $lang | sed -e 's/\..*$//' -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
      cat >> "$ac_file.tmp" <<EOF
$frobbedlang.msg: $lang.po
	@echo "\$(MSGFMT) -c --tcl -d \$(srcdir) -l $lang $srcdirpre$lang.po"; \
	\$(MSGFMT) -c --tcl -d "\$(srcdir)" -l $lang $srcdirpre$lang.po || { rm -f "\$(srcdir)/$frobbedlang.msg"; exit 1; }
EOF
    done
  fi
  if grep -l '@CSHARPCATALOGS@' "$ac_file" > /dev/null; then
    # Add dependencies that cannot be formulated as a simple suffix rule.
    for lang in $ALL_LINGUAS; do
      frobbedlang=`echo $lang | sed -e 's/_/-/g' -e 's/^sr-CS/sr-SP/' -e 's/@latin$/-Latn/' -e 's/@cyrillic$/-Cyrl/' -e 's/^sr-SP$/sr-SP-Latn/' -e 's/^uz-UZ$/uz-UZ-Latn/'`
      cat >> "$ac_file.tmp" <<EOF
$frobbedlang/\$(DOMAIN).resources.dll: $lang.po
	@echo "\$(MSGFMT) -c --csharp -d \$(srcdir) -l $lang $srcdirpre$lang.po -r \$(DOMAIN)"; \
	\$(MSGFMT) -c --csharp -d "\$(srcdir)" -l $lang $srcdirpre$lang.po -r "\$(DOMAIN)" || { rm -f "\$(srcdir)/$frobbedlang.msg"; exit 1; }
EOF
    done
  fi
  if test -n "$POMAKEFILEDEPS"; then
    cat >> "$ac_file.tmp" <<EOF
Makefile: $POMAKEFILEDEPS
EOF
  fi
  mv "$ac_file.tmp" "$ac_file"
])

dnl Initializes the accumulator used by AM_XGETTEXT_OPTION.
AC_DEFUN([AM_XGETTEXT_OPTION_INIT],
[
  XGETTEXT_EXTRA_OPTIONS=
])

dnl Registers an option to be passed to xgettext in the po subdirectory.
AC_DEFUN([AM_XGETTEXT_OPTION],
[
  AC_REQUIRE([AM_XGETTEXT_OPTION_INIT])
  XGETTEXT_EXTRA_OPTIONS="$XGETTEXT_EXTRA_OPTIONS $1"
])

# progtest.m4 serial 6 (gettext-0.18)
dnl Copyright (C) 1996-2003, 2005, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl
dnl This file can can be used in projects which are not available under
dnl the GNU General Public License or the GNU Library General Public
dnl License but which still want to provide support for the GNU gettext
dnl functionality.
dnl Please note that the actual code of the GNU gettext library is covered
dnl by the GNU Library General Public License, and the rest of the GNU
dnl gettext package package is covered by the GNU General Public License.
dnl They are *not* in the public domain.

dnl Authors:
dnl   Ulrich Drepper <drepper@cygnus.com>, 1996.

AC_PREREQ([2.50])

# Search path for a program which passes the given test.

dnl AM_PATH_PROG_WITH_TEST(VARIABLE, PROG-TO-CHECK-FOR,
dnl   TEST-PERFORMED-ON-FOUND_PROGRAM [, VALUE-IF-NOT-FOUND [, PATH]])
AC_DEFUN([AM_PATH_PROG_WITH_TEST],
[
# Prepare PATH_SEPARATOR.
# The user is always right.
if test "${PATH_SEPARATOR+set}" != set; then
  echo "#! /bin/sh" >conf$$.sh
  echo  "exit 0"   >>conf$$.sh
  chmod +x conf$$.sh
  if (PATH="/nonexistent;."; conf$$.sh) >/dev/null 2>&1; then
    PATH_SEPARATOR=';'
  else
    PATH_SEPARATOR=:
  fi
  rm -f conf$$.sh
fi

# Find out how to test for executable files. Don't use a zero-byte file,
# as systems may use methods other than mode bits to determine executability.
cat >conf$$.file <<_ASEOF
#! /bin/sh
exit 0
_ASEOF
chmod +x conf$$.file
if test -x conf$$.file >/dev/null 2>&1; then
  ac_executable_p="test -x"
else
  ac_executable_p="test -f"
fi
rm -f conf$$.file

# Extract the first word of "$2", so it can be a program name with args.
set dummy $2; ac_word=[$]2
AC_MSG_CHECKING([for $ac_word])
AC_CACHE_VAL([ac_cv_path_$1],
[case "[$]$1" in
  [[\\/]]* | ?:[[\\/]]*)
    ac_cv_path_$1="[$]$1" # Let the user override the test with a path.
    ;;
  *)
    ac_save_IFS="$IFS"; IFS=$PATH_SEPARATOR
    for ac_dir in ifelse([$5], , $PATH, [$5]); do
      IFS="$ac_save_IFS"
      test -z "$ac_dir" && ac_dir=.
      for ac_exec_ext in '' $ac_executable_extensions; do
        if $ac_executable_p "$ac_dir/$ac_word$ac_exec_ext"; then
          echo "$as_me: trying $ac_dir/$ac_word..." >&AS_MESSAGE_LOG_FD
          if [$3]; then
            ac_cv_path_$1="$ac_dir/$ac_word$ac_exec_ext"
            break 2
          fi
        fi
      done
    done
    IFS="$ac_save_IFS"
dnl If no 4th arg is given, leave the cache variable unset,
dnl so AC_PATH_PROGS will keep looking.
ifelse([$4], , , [  test -z "[$]ac_cv_path_$1" && ac_cv_path_$1="$4"
])dnl
    ;;
esac])dnl
$1="$ac_cv_path_$1"
if test ifelse([$4], , [-n "[$]$1"], ["[$]$1" != "$4"]); then
  AC_MSG_RESULT([$][$1])
else
  AC_MSG_RESULT([no])
fi
AC_SUBST([$1])dnl
])

# Check for stdbool.h that conforms to C99.

dnl Copyright (C) 2002-2006, 2009-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# Prepare for substituting <stdbool.h> if it is not supported.

AC_DEFUN([AM_STDBOOL_H],
[
  AC_REQUIRE([AC_HEADER_STDBOOL])

  # Define two additional variables used in the Makefile substitution.

  if test "$ac_cv_header_stdbool_h" = yes; then
    STDBOOL_H=''
  else
    STDBOOL_H='stdbool.h'
  fi
  AC_SUBST([STDBOOL_H])

  if test "$ac_cv_type__Bool" = yes; then
    HAVE__BOOL=1
  else
    HAVE__BOOL=0
  fi
  AC_SUBST([HAVE__BOOL])
])

# AM_STDBOOL_H will be renamed to gl_STDBOOL_H in the future.
AC_DEFUN([gl_STDBOOL_H], [AM_STDBOOL_H])

# This macro is only needed in autoconf <= 2.59.  Newer versions of autoconf
# have this macro built-in.

AC_DEFUN([AC_HEADER_STDBOOL],
  [AC_CACHE_CHECK([for stdbool.h that conforms to C99],
     [ac_cv_header_stdbool_h],
     [AC_TRY_COMPILE(
        [
          #include <stdbool.h>
          #ifndef bool
           "error: bool is not defined"
          #endif
          #ifndef false
           "error: false is not defined"
          #endif
          #if false
           "error: false is not 0"
          #endif
          #ifndef true
           "error: true is not defined"
          #endif
          #if true != 1
           "error: true is not 1"
          #endif
          #ifndef __bool_true_false_are_defined
           "error: __bool_true_false_are_defined is not defined"
          #endif

          struct s { _Bool s: 1; _Bool t; } s;

          char a[true == 1 ? 1 : -1];
          char b[false == 0 ? 1 : -1];
          char c[__bool_true_false_are_defined == 1 ? 1 : -1];
          char d[(bool) 0.5 == true ? 1 : -1];
          bool e = &s;
          char f[(_Bool) 0.0 == false ? 1 : -1];
          char g[true];
          char h[sizeof (_Bool)];
          char i[sizeof s.t];
          enum { j = false, k = true, l = false * true, m = true * 256 };
          _Bool n[m];
          char o[sizeof n == m * sizeof n[0] ? 1 : -1];
          char p[-1 - (_Bool) 0 < 0 && -1 - (bool) 0 < 0 ? 1 : -1];
          #if defined __xlc__ || defined __GNUC__
           /* Catch a bug in IBM AIX xlc compiler version 6.0.0.0
              reported by James Lemley on 2005-10-05; see
              http://lists.gnu.org/archive/html/bug-coreutils/2005-10/msg00086.html
              This test is not quite right, since xlc is allowed to
              reject this program, as the initializer for xlcbug is
              not one of the forms that C requires support for.
              However, doing the test right would require a run-time
              test, and that would make cross-compilation harder.
              Let us hope that IBM fixes the xlc bug, and also adds
              support for this kind of constant expression.  In the
              meantime, this test will reject xlc, which is OK, since
              our stdbool.h substitute should suffice.  We also test
              this with GCC, where it should work, to detect more
              quickly whether someone messes up the test in the
              future.  */
           char digs[] = "0123456789";
           int xlcbug = 1 / (&(digs + 5)[-2 + (bool) 1] == &digs[4] ? 1 : -1);
          #endif
          /* Catch a bug in an HP-UX C compiler.  See
             http://gcc.gnu.org/ml/gcc-patches/2003-12/msg02303.html
             http://lists.gnu.org/archive/html/bug-coreutils/2005-11/msg00161.html
           */
          _Bool q = true;
          _Bool *pq = &q;
        ],
        [
          *pq |= q;
          *pq |= ! q;
          /* Refer to every declared value, to avoid compiler optimizations.  */
          return (!a + !b + !c + !d + !e + !f + !g + !h + !i + !!j + !k + !!l
                  + !m + !n + !o + !p + !q + !pq);
        ],
        [ac_cv_header_stdbool_h=yes],
        [ac_cv_header_stdbool_h=no])])
   AC_CHECK_TYPES([_Bool])
   if test $ac_cv_header_stdbool_h = yes; then
     AC_DEFINE([HAVE_STDBOOL_H], [1], [Define to 1 if stdbool.h conforms to C99.])
   fi])

dnl A placeholder for POSIX 2008 <stddef.h>, for platforms that have issues.
# stddef_h.m4 serial 2
dnl Copyright (C) 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_STDDEF_H],
[
  AC_REQUIRE([gl_STDDEF_H_DEFAULTS])
  AC_REQUIRE([gt_TYPE_WCHAR_T])
  if test $gt_cv_c_wchar_t = no; then
    HAVE_WCHAR_T=0
    STDDEF_H=stddef.h
  fi
  AC_CACHE_CHECK([whether NULL can be used in arbitrary expressions],
    [gl_cv_decl_null_works],
    [AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stddef.h>
      int test[2 * (sizeof NULL == sizeof (void *)) -1];
]])],
      [gl_cv_decl_null_works=yes],
      [gl_cv_decl_null_works=no])])
  if test $gl_cv_decl_null_works = no; then
    REPLACE_NULL=1
    STDDEF_H=stddef.h
  fi
  if test -n "$STDDEF_H"; then
    gl_CHECK_NEXT_HEADERS([stddef.h])
  fi
])

AC_DEFUN([gl_STDDEF_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_STDDEF_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
])

AC_DEFUN([gl_STDDEF_H_DEFAULTS],
[
  dnl Assume proper GNU behavior unless another module says otherwise.
  REPLACE_NULL=0;                AC_SUBST([REPLACE_NULL])
  HAVE_WCHAR_T=1;                AC_SUBST([HAVE_WCHAR_T])
  STDDEF_H='';                   AC_SUBST([STDDEF_H])
])

# stdint.m4 serial 35
dnl Copyright (C) 2001-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Paul Eggert and Bruno Haible.
dnl Test whether <stdint.h> is supported or must be substituted.

AC_DEFUN([gl_STDINT_H],
[
  AC_PREREQ([2.59])dnl

  dnl Check for long long int and unsigned long long int.
  AC_REQUIRE([AC_TYPE_LONG_LONG_INT])
  if test $ac_cv_type_long_long_int = yes; then
    HAVE_LONG_LONG_INT=1
  else
    HAVE_LONG_LONG_INT=0
  fi
  AC_SUBST([HAVE_LONG_LONG_INT])
  AC_REQUIRE([AC_TYPE_UNSIGNED_LONG_LONG_INT])
  if test $ac_cv_type_unsigned_long_long_int = yes; then
    HAVE_UNSIGNED_LONG_LONG_INT=1
  else
    HAVE_UNSIGNED_LONG_LONG_INT=0
  fi
  AC_SUBST([HAVE_UNSIGNED_LONG_LONG_INT])

  dnl Check for <inttypes.h>.
  dnl AC_INCLUDES_DEFAULT defines $ac_cv_header_inttypes_h.
  if test $ac_cv_header_inttypes_h = yes; then
    HAVE_INTTYPES_H=1
  else
    HAVE_INTTYPES_H=0
  fi
  AC_SUBST([HAVE_INTTYPES_H])

  dnl Check for <sys/types.h>.
  dnl AC_INCLUDES_DEFAULT defines $ac_cv_header_sys_types_h.
  if test $ac_cv_header_sys_types_h = yes; then
    HAVE_SYS_TYPES_H=1
  else
    HAVE_SYS_TYPES_H=0
  fi
  AC_SUBST([HAVE_SYS_TYPES_H])

  gl_CHECK_NEXT_HEADERS([stdint.h])
  if test $ac_cv_header_stdint_h = yes; then
    HAVE_STDINT_H=1
  else
    HAVE_STDINT_H=0
  fi
  AC_SUBST([HAVE_STDINT_H])

  dnl Now see whether we need a substitute <stdint.h>.
  if test $ac_cv_header_stdint_h = yes; then
    AC_CACHE_CHECK([whether stdint.h conforms to C99],
      [gl_cv_header_working_stdint_h],
      [gl_cv_header_working_stdint_h=no
       AC_COMPILE_IFELSE([
         AC_LANG_PROGRAM([[
#define __STDC_LIMIT_MACROS 1 /* to make it work also in C++ mode */
#define __STDC_CONSTANT_MACROS 1 /* to make it work also in C++ mode */
#define _GL_JUST_INCLUDE_SYSTEM_STDINT_H 1 /* work if build isn't clean */
#include <stdint.h>
/* Dragonfly defines WCHAR_MIN, WCHAR_MAX only in <wchar.h>.  */
#if !(defined WCHAR_MIN && defined WCHAR_MAX)
#error "WCHAR_MIN, WCHAR_MAX not defined in <stdint.h>"
#endif
]
gl_STDINT_INCLUDES
[
#ifdef INT8_MAX
int8_t a1 = INT8_MAX;
int8_t a1min = INT8_MIN;
#endif
#ifdef INT16_MAX
int16_t a2 = INT16_MAX;
int16_t a2min = INT16_MIN;
#endif
#ifdef INT32_MAX
int32_t a3 = INT32_MAX;
int32_t a3min = INT32_MIN;
#endif
#ifdef INT64_MAX
int64_t a4 = INT64_MAX;
int64_t a4min = INT64_MIN;
#endif
#ifdef UINT8_MAX
uint8_t b1 = UINT8_MAX;
#else
typedef int b1[(unsigned char) -1 != 255 ? 1 : -1];
#endif
#ifdef UINT16_MAX
uint16_t b2 = UINT16_MAX;
#endif
#ifdef UINT32_MAX
uint32_t b3 = UINT32_MAX;
#endif
#ifdef UINT64_MAX
uint64_t b4 = UINT64_MAX;
#endif
int_least8_t c1 = INT8_C (0x7f);
int_least8_t c1max = INT_LEAST8_MAX;
int_least8_t c1min = INT_LEAST8_MIN;
int_least16_t c2 = INT16_C (0x7fff);
int_least16_t c2max = INT_LEAST16_MAX;
int_least16_t c2min = INT_LEAST16_MIN;
int_least32_t c3 = INT32_C (0x7fffffff);
int_least32_t c3max = INT_LEAST32_MAX;
int_least32_t c3min = INT_LEAST32_MIN;
int_least64_t c4 = INT64_C (0x7fffffffffffffff);
int_least64_t c4max = INT_LEAST64_MAX;
int_least64_t c4min = INT_LEAST64_MIN;
uint_least8_t d1 = UINT8_C (0xff);
uint_least8_t d1max = UINT_LEAST8_MAX;
uint_least16_t d2 = UINT16_C (0xffff);
uint_least16_t d2max = UINT_LEAST16_MAX;
uint_least32_t d3 = UINT32_C (0xffffffff);
uint_least32_t d3max = UINT_LEAST32_MAX;
uint_least64_t d4 = UINT64_C (0xffffffffffffffff);
uint_least64_t d4max = UINT_LEAST64_MAX;
int_fast8_t e1 = INT_FAST8_MAX;
int_fast8_t e1min = INT_FAST8_MIN;
int_fast16_t e2 = INT_FAST16_MAX;
int_fast16_t e2min = INT_FAST16_MIN;
int_fast32_t e3 = INT_FAST32_MAX;
int_fast32_t e3min = INT_FAST32_MIN;
int_fast64_t e4 = INT_FAST64_MAX;
int_fast64_t e4min = INT_FAST64_MIN;
uint_fast8_t f1 = UINT_FAST8_MAX;
uint_fast16_t f2 = UINT_FAST16_MAX;
uint_fast32_t f3 = UINT_FAST32_MAX;
uint_fast64_t f4 = UINT_FAST64_MAX;
#ifdef INTPTR_MAX
intptr_t g = INTPTR_MAX;
intptr_t gmin = INTPTR_MIN;
#endif
#ifdef UINTPTR_MAX
uintptr_t h = UINTPTR_MAX;
#endif
intmax_t i = INTMAX_MAX;
uintmax_t j = UINTMAX_MAX;

#include <limits.h> /* for CHAR_BIT */
#define TYPE_MINIMUM(t) \
  ((t) ((t) 0 < (t) -1 ? (t) 0 : ~ (t) 0 << (sizeof (t) * CHAR_BIT - 1)))
#define TYPE_MAXIMUM(t) \
  ((t) ((t) 0 < (t) -1 ? (t) -1 : ~ (~ (t) 0 << (sizeof (t) * CHAR_BIT - 1))))
struct s {
  int check_PTRDIFF:
      PTRDIFF_MIN == TYPE_MINIMUM (ptrdiff_t)
      && PTRDIFF_MAX == TYPE_MAXIMUM (ptrdiff_t)
      ? 1 : -1;
  /* Detect bug in FreeBSD 6.0 / ia64.  */
  int check_SIG_ATOMIC:
      SIG_ATOMIC_MIN == TYPE_MINIMUM (sig_atomic_t)
      && SIG_ATOMIC_MAX == TYPE_MAXIMUM (sig_atomic_t)
      ? 1 : -1;
  int check_SIZE: SIZE_MAX == TYPE_MAXIMUM (size_t) ? 1 : -1;
  int check_WCHAR:
      WCHAR_MIN == TYPE_MINIMUM (wchar_t)
      && WCHAR_MAX == TYPE_MAXIMUM (wchar_t)
      ? 1 : -1;
  /* Detect bug in mingw.  */
  int check_WINT:
      WINT_MIN == TYPE_MINIMUM (wint_t)
      && WINT_MAX == TYPE_MAXIMUM (wint_t)
      ? 1 : -1;

  /* Detect bugs in glibc 2.4 and Solaris 10 stdint.h, among others.  */
  int check_UINT8_C:
        (-1 < UINT8_C (0)) == (-1 < (uint_least8_t) 0) ? 1 : -1;
  int check_UINT16_C:
        (-1 < UINT16_C (0)) == (-1 < (uint_least16_t) 0) ? 1 : -1;

  /* Detect bugs in OpenBSD 3.9 stdint.h.  */
#ifdef UINT8_MAX
  int check_uint8: (uint8_t) -1 == UINT8_MAX ? 1 : -1;
#endif
#ifdef UINT16_MAX
  int check_uint16: (uint16_t) -1 == UINT16_MAX ? 1 : -1;
#endif
#ifdef UINT32_MAX
  int check_uint32: (uint32_t) -1 == UINT32_MAX ? 1 : -1;
#endif
#ifdef UINT64_MAX
  int check_uint64: (uint64_t) -1 == UINT64_MAX ? 1 : -1;
#endif
  int check_uint_least8: (uint_least8_t) -1 == UINT_LEAST8_MAX ? 1 : -1;
  int check_uint_least16: (uint_least16_t) -1 == UINT_LEAST16_MAX ? 1 : -1;
  int check_uint_least32: (uint_least32_t) -1 == UINT_LEAST32_MAX ? 1 : -1;
  int check_uint_least64: (uint_least64_t) -1 == UINT_LEAST64_MAX ? 1 : -1;
  int check_uint_fast8: (uint_fast8_t) -1 == UINT_FAST8_MAX ? 1 : -1;
  int check_uint_fast16: (uint_fast16_t) -1 == UINT_FAST16_MAX ? 1 : -1;
  int check_uint_fast32: (uint_fast32_t) -1 == UINT_FAST32_MAX ? 1 : -1;
  int check_uint_fast64: (uint_fast64_t) -1 == UINT_FAST64_MAX ? 1 : -1;
  int check_uintptr: (uintptr_t) -1 == UINTPTR_MAX ? 1 : -1;
  int check_uintmax: (uintmax_t) -1 == UINTMAX_MAX ? 1 : -1;
  int check_size: (size_t) -1 == SIZE_MAX ? 1 : -1;
};
         ]])],
         [dnl Determine whether the various *_MIN, *_MAX macros are usable
          dnl in preprocessor expression. We could do it by compiling a test
          dnl program for each of these macros. It is faster to run a program
          dnl that inspects the macro expansion.
          dnl This detects a bug on HP-UX 11.23/ia64.
          AC_RUN_IFELSE([
            AC_LANG_PROGRAM([[
#define __STDC_LIMIT_MACROS 1 /* to make it work also in C++ mode */
#define __STDC_CONSTANT_MACROS 1 /* to make it work also in C++ mode */
#define _GL_JUST_INCLUDE_SYSTEM_STDINT_H 1 /* work if build isn't clean */
#include <stdint.h>
]
gl_STDINT_INCLUDES
[
#include <stdio.h>
#include <string.h>
#define MVAL(macro) MVAL1(macro)
#define MVAL1(expression) #expression
static const char *macro_values[] =
  {
#ifdef INT8_MAX
    MVAL (INT8_MAX),
#endif
#ifdef INT16_MAX
    MVAL (INT16_MAX),
#endif
#ifdef INT32_MAX
    MVAL (INT32_MAX),
#endif
#ifdef INT64_MAX
    MVAL (INT64_MAX),
#endif
#ifdef UINT8_MAX
    MVAL (UINT8_MAX),
#endif
#ifdef UINT16_MAX
    MVAL (UINT16_MAX),
#endif
#ifdef UINT32_MAX
    MVAL (UINT32_MAX),
#endif
#ifdef UINT64_MAX
    MVAL (UINT64_MAX),
#endif
    NULL
  };
]], [[
  const char **mv;
  for (mv = macro_values; *mv != NULL; mv++)
    {
      const char *value = *mv;
      /* Test whether it looks like a cast expression.  */
      if (strncmp (value, "((unsigned int)"/*)*/, 15) == 0
          || strncmp (value, "((unsigned short)"/*)*/, 17) == 0
          || strncmp (value, "((unsigned char)"/*)*/, 16) == 0
          || strncmp (value, "((int)"/*)*/, 6) == 0
          || strncmp (value, "((signed short)"/*)*/, 15) == 0
          || strncmp (value, "((signed char)"/*)*/, 14) == 0)
        return 1;
    }
  return 0;
]])],
              [gl_cv_header_working_stdint_h=yes],
              [],
              [dnl When cross-compiling, assume it works.
               gl_cv_header_working_stdint_h=yes
              ])
         ])
      ])
  fi
  if test "$gl_cv_header_working_stdint_h" = yes; then
    STDINT_H=
  else
    dnl Check for <sys/inttypes.h>, and for
    dnl <sys/bitypes.h> (used in Linux libc4 >= 4.6.7 and libc5).
    AC_CHECK_HEADERS([sys/inttypes.h sys/bitypes.h])
    if test $ac_cv_header_sys_inttypes_h = yes; then
      HAVE_SYS_INTTYPES_H=1
    else
      HAVE_SYS_INTTYPES_H=0
    fi
    AC_SUBST([HAVE_SYS_INTTYPES_H])
    if test $ac_cv_header_sys_bitypes_h = yes; then
      HAVE_SYS_BITYPES_H=1
    else
      HAVE_SYS_BITYPES_H=0
    fi
    AC_SUBST([HAVE_SYS_BITYPES_H])

    dnl Check for <wchar.h> (missing in Linux uClibc when built without wide
    dnl character support).
    AC_CHECK_HEADERS_ONCE([wchar.h])

    gl_STDINT_TYPE_PROPERTIES
    STDINT_H=stdint.h
  fi
  AC_SUBST([STDINT_H])
])

dnl gl_STDINT_BITSIZEOF(TYPES, INCLUDES)
dnl Determine the size of each of the given types in bits.
AC_DEFUN([gl_STDINT_BITSIZEOF],
[
  dnl Use a shell loop, to avoid bloating configure, and
  dnl - extra AH_TEMPLATE calls, so that autoheader knows what to put into
  dnl   config.h.in,
  dnl - extra AC_SUBST calls, so that the right substitutions are made.
  m4_foreach_w([gltype], [$1],
    [AH_TEMPLATE([BITSIZEOF_]m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_]),
       [Define to the number of bits in type ']gltype['.])])
  for gltype in $1 ; do
    AC_CACHE_CHECK([for bit size of $gltype], [gl_cv_bitsizeof_${gltype}],
      [AC_COMPUTE_INT([result], [sizeof ($gltype) * CHAR_BIT],
         [$2
#include <limits.h>], [result=unknown])
       eval gl_cv_bitsizeof_${gltype}=\$result
      ])
    eval result=\$gl_cv_bitsizeof_${gltype}
    if test $result = unknown; then
      dnl Use a nonempty default, because some compilers, such as IRIX 5 cc,
      dnl do a syntax check even on unused #if conditions and give an error
      dnl on valid C code like this:
      dnl   #if 0
      dnl   # if  > 32
      dnl   # endif
      dnl   #endif
      result=0
    fi
    GLTYPE=`echo "$gltype" | tr 'abcdefghijklmnopqrstuvwxyz ' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_'`
    AC_DEFINE_UNQUOTED([BITSIZEOF_${GLTYPE}], [$result])
    eval BITSIZEOF_${GLTYPE}=\$result
  done
  m4_foreach_w([gltype], [$1],
    [AC_SUBST([BITSIZEOF_]m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_]))])
])

dnl gl_CHECK_TYPES_SIGNED(TYPES, INCLUDES)
dnl Determine the signedness of each of the given types.
dnl Define HAVE_SIGNED_TYPE if type is signed.
AC_DEFUN([gl_CHECK_TYPES_SIGNED],
[
  dnl Use a shell loop, to avoid bloating configure, and
  dnl - extra AH_TEMPLATE calls, so that autoheader knows what to put into
  dnl   config.h.in,
  dnl - extra AC_SUBST calls, so that the right substitutions are made.
  m4_foreach_w([gltype], [$1],
    [AH_TEMPLATE([HAVE_SIGNED_]m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_]),
       [Define to 1 if ']gltype[' is a signed integer type.])])
  for gltype in $1 ; do
    AC_CACHE_CHECK([whether $gltype is signed], [gl_cv_type_${gltype}_signed],
      [AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM([$2[
            int verify[2 * (($gltype) -1 < ($gltype) 0) - 1];]])],
         result=yes, result=no)
       eval gl_cv_type_${gltype}_signed=\$result
      ])
    eval result=\$gl_cv_type_${gltype}_signed
    GLTYPE=`echo $gltype | tr 'abcdefghijklmnopqrstuvwxyz ' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_'`
    if test "$result" = yes; then
      AC_DEFINE_UNQUOTED([HAVE_SIGNED_${GLTYPE}], [1])
      eval HAVE_SIGNED_${GLTYPE}=1
    else
      eval HAVE_SIGNED_${GLTYPE}=0
    fi
  done
  m4_foreach_w([gltype], [$1],
    [AC_SUBST([HAVE_SIGNED_]m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_]))])
])

dnl gl_INTEGER_TYPE_SUFFIX(TYPES, INCLUDES)
dnl Determine the suffix to use for integer constants of the given types.
dnl Define t_SUFFIX for each such type.
AC_DEFUN([gl_INTEGER_TYPE_SUFFIX],
[
  dnl Use a shell loop, to avoid bloating configure, and
  dnl - extra AH_TEMPLATE calls, so that autoheader knows what to put into
  dnl   config.h.in,
  dnl - extra AC_SUBST calls, so that the right substitutions are made.
  m4_foreach_w([gltype], [$1],
    [AH_TEMPLATE(m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_])[_SUFFIX],
       [Define to l, ll, u, ul, ull, etc., as suitable for
        constants of type ']gltype['.])])
  for gltype in $1 ; do
    AC_CACHE_CHECK([for $gltype integer literal suffix],
      [gl_cv_type_${gltype}_suffix],
      [eval gl_cv_type_${gltype}_suffix=no
       eval result=\$gl_cv_type_${gltype}_signed
       if test "$result" = yes; then
         glsufu=
       else
         glsufu=u
       fi
       for glsuf in "$glsufu" ${glsufu}l ${glsufu}ll ${glsufu}i64; do
         case $glsuf in
           '')  gltype1='int';;
           l)   gltype1='long int';;
           ll)  gltype1='long long int';;
           i64) gltype1='__int64';;
           u)   gltype1='unsigned int';;
           ul)  gltype1='unsigned long int';;
           ull) gltype1='unsigned long long int';;
           ui64)gltype1='unsigned __int64';;
         esac
         AC_COMPILE_IFELSE(
           [AC_LANG_PROGRAM([$2[
              extern $gltype foo;
              extern $gltype1 foo;]])],
           [eval gl_cv_type_${gltype}_suffix=\$glsuf])
         eval result=\$gl_cv_type_${gltype}_suffix
         test "$result" != no && break
       done])
    GLTYPE=`echo $gltype | tr 'abcdefghijklmnopqrstuvwxyz ' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_'`
    eval result=\$gl_cv_type_${gltype}_suffix
    test "$result" = no && result=
    eval ${GLTYPE}_SUFFIX=\$result
    AC_DEFINE_UNQUOTED([${GLTYPE}_SUFFIX], [$result])
  done
  m4_foreach_w([gltype], [$1],
    [AC_SUBST(m4_translit(gltype,[abcdefghijklmnopqrstuvwxyz ],[ABCDEFGHIJKLMNOPQRSTUVWXYZ_])[_SUFFIX])])
])

dnl gl_STDINT_INCLUDES
AC_DEFUN([gl_STDINT_INCLUDES],
[[
  /* BSD/OS 4.0.1 has a bug: <stddef.h>, <stdio.h> and <time.h> must be
     included before <wchar.h>.  */
  #include <stddef.h>
  #include <signal.h>
  #if HAVE_WCHAR_H
  # include <stdio.h>
  # include <time.h>
  # include <wchar.h>
  #endif
]])

dnl gl_STDINT_TYPE_PROPERTIES
dnl Compute HAVE_SIGNED_t, BITSIZEOF_t and t_SUFFIX, for all the types t
dnl of interest to stdint.in.h.
AC_DEFUN([gl_STDINT_TYPE_PROPERTIES],
[
  AC_REQUIRE([gl_MULTIARCH])
  if test $APPLE_UNIVERSAL_BUILD = 0; then
    gl_STDINT_BITSIZEOF([ptrdiff_t size_t],
      [gl_STDINT_INCLUDES])
  fi
  gl_STDINT_BITSIZEOF([sig_atomic_t wchar_t wint_t],
    [gl_STDINT_INCLUDES])
  gl_CHECK_TYPES_SIGNED([sig_atomic_t wchar_t wint_t],
    [gl_STDINT_INCLUDES])
  gl_cv_type_ptrdiff_t_signed=yes
  gl_cv_type_size_t_signed=no
  if test $APPLE_UNIVERSAL_BUILD = 0; then
    gl_INTEGER_TYPE_SUFFIX([ptrdiff_t size_t],
      [gl_STDINT_INCLUDES])
  fi
  gl_INTEGER_TYPE_SUFFIX([sig_atomic_t wchar_t wint_t],
    [gl_STDINT_INCLUDES])
])

dnl Autoconf >= 2.61 has AC_COMPUTE_INT built-in.
dnl Remove this when we can assume autoconf >= 2.61.
m4_ifdef([AC_COMPUTE_INT], [], [
  AC_DEFUN([AC_COMPUTE_INT], [_AC_COMPUTE_INT([$2],[$1],[$3],[$4])])
])

# Hey Emacs!
# Local Variables:
# indent-tabs-mode: nil
# End:

# Configure a GNU-like replacement for <string.h>.

# Copyright (C) 2007-2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# serial 17

# Written by Paul Eggert.

AC_DEFUN([gl_HEADER_STRING_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_HEADER_STRING_H_BODY])
])

AC_DEFUN([gl_HEADER_STRING_H_BODY],
[
  AC_REQUIRE([AC_C_RESTRICT])
  AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
  gl_CHECK_NEXT_HEADERS([string.h])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use, and which is not
  dnl guaranteed by C89.
  gl_WARN_ON_USE_PREPARE([[#include <string.h>
    ]],
    [memmem mempcpy memrchr rawmemchr stpcpy stpncpy strchrnul strdup
     strncat strndup strnlen strpbrk strsep strcasestr strtok_r strsignal
     strverscmp])
])

AC_DEFUN([gl_STRING_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_HEADER_STRING_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_HEADER_STRING_H_DEFAULTS],
[
  GNULIB_MEMCHR=0;      AC_SUBST([GNULIB_MEMCHR])
  GNULIB_MEMMEM=0;      AC_SUBST([GNULIB_MEMMEM])
  GNULIB_MEMPCPY=0;     AC_SUBST([GNULIB_MEMPCPY])
  GNULIB_MEMRCHR=0;     AC_SUBST([GNULIB_MEMRCHR])
  GNULIB_RAWMEMCHR=0;   AC_SUBST([GNULIB_RAWMEMCHR])
  GNULIB_STPCPY=0;      AC_SUBST([GNULIB_STPCPY])
  GNULIB_STPNCPY=0;     AC_SUBST([GNULIB_STPNCPY])
  GNULIB_STRCHRNUL=0;   AC_SUBST([GNULIB_STRCHRNUL])
  GNULIB_STRDUP=0;      AC_SUBST([GNULIB_STRDUP])
  GNULIB_STRNCAT=0;     AC_SUBST([GNULIB_STRNCAT])
  GNULIB_STRNDUP=0;     AC_SUBST([GNULIB_STRNDUP])
  GNULIB_STRNLEN=0;     AC_SUBST([GNULIB_STRNLEN])
  GNULIB_STRPBRK=0;     AC_SUBST([GNULIB_STRPBRK])
  GNULIB_STRSEP=0;      AC_SUBST([GNULIB_STRSEP])
  GNULIB_STRSTR=0;      AC_SUBST([GNULIB_STRSTR])
  GNULIB_STRCASESTR=0;  AC_SUBST([GNULIB_STRCASESTR])
  GNULIB_STRTOK_R=0;    AC_SUBST([GNULIB_STRTOK_R])
  GNULIB_MBSLEN=0;      AC_SUBST([GNULIB_MBSLEN])
  GNULIB_MBSNLEN=0;     AC_SUBST([GNULIB_MBSNLEN])
  GNULIB_MBSCHR=0;      AC_SUBST([GNULIB_MBSCHR])
  GNULIB_MBSRCHR=0;     AC_SUBST([GNULIB_MBSRCHR])
  GNULIB_MBSSTR=0;      AC_SUBST([GNULIB_MBSSTR])
  GNULIB_MBSCASECMP=0;  AC_SUBST([GNULIB_MBSCASECMP])
  GNULIB_MBSNCASECMP=0; AC_SUBST([GNULIB_MBSNCASECMP])
  GNULIB_MBSPCASECMP=0; AC_SUBST([GNULIB_MBSPCASECMP])
  GNULIB_MBSCASESTR=0;  AC_SUBST([GNULIB_MBSCASESTR])
  GNULIB_MBSCSPN=0;     AC_SUBST([GNULIB_MBSCSPN])
  GNULIB_MBSPBRK=0;     AC_SUBST([GNULIB_MBSPBRK])
  GNULIB_MBSSPN=0;      AC_SUBST([GNULIB_MBSSPN])
  GNULIB_MBSSEP=0;      AC_SUBST([GNULIB_MBSSEP])
  GNULIB_MBSTOK_R=0;    AC_SUBST([GNULIB_MBSTOK_R])
  GNULIB_STRERROR=0;    AC_SUBST([GNULIB_STRERROR])
  GNULIB_STRSIGNAL=0;   AC_SUBST([GNULIB_STRSIGNAL])
  GNULIB_STRVERSCMP=0;  AC_SUBST([GNULIB_STRVERSCMP])
  HAVE_MBSLEN=0;        AC_SUBST([HAVE_MBSLEN])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_MEMCHR=1;                AC_SUBST([HAVE_MEMCHR])
  HAVE_DECL_MEMMEM=1;           AC_SUBST([HAVE_DECL_MEMMEM])
  HAVE_MEMPCPY=1;               AC_SUBST([HAVE_MEMPCPY])
  HAVE_DECL_MEMRCHR=1;          AC_SUBST([HAVE_DECL_MEMRCHR])
  HAVE_RAWMEMCHR=1;             AC_SUBST([HAVE_RAWMEMCHR])
  HAVE_STPCPY=1;                AC_SUBST([HAVE_STPCPY])
  HAVE_STPNCPY=1;               AC_SUBST([HAVE_STPNCPY])
  HAVE_STRCHRNUL=1;             AC_SUBST([HAVE_STRCHRNUL])
  HAVE_DECL_STRDUP=1;           AC_SUBST([HAVE_DECL_STRDUP])
  HAVE_DECL_STRNDUP=1;          AC_SUBST([HAVE_DECL_STRNDUP])
  HAVE_DECL_STRNLEN=1;          AC_SUBST([HAVE_DECL_STRNLEN])
  HAVE_STRPBRK=1;               AC_SUBST([HAVE_STRPBRK])
  HAVE_STRSEP=1;                AC_SUBST([HAVE_STRSEP])
  HAVE_STRCASESTR=1;            AC_SUBST([HAVE_STRCASESTR])
  HAVE_DECL_STRTOK_R=1;         AC_SUBST([HAVE_DECL_STRTOK_R])
  HAVE_DECL_STRSIGNAL=1;        AC_SUBST([HAVE_DECL_STRSIGNAL])
  HAVE_STRVERSCMP=1;            AC_SUBST([HAVE_STRVERSCMP])
  REPLACE_MEMCHR=0;             AC_SUBST([REPLACE_MEMCHR])
  REPLACE_MEMMEM=0;             AC_SUBST([REPLACE_MEMMEM])
  REPLACE_STPNCPY=0;            AC_SUBST([REPLACE_STPNCPY])
  REPLACE_STRDUP=0;             AC_SUBST([REPLACE_STRDUP])
  REPLACE_STRSTR=0;             AC_SUBST([REPLACE_STRSTR])
  REPLACE_STRCASESTR=0;         AC_SUBST([REPLACE_STRCASESTR])
  REPLACE_STRERROR=0;           AC_SUBST([REPLACE_STRERROR])
  REPLACE_STRNCAT=0;            AC_SUBST([REPLACE_STRNCAT])
  REPLACE_STRNDUP=0;            AC_SUBST([REPLACE_STRNDUP])
  REPLACE_STRNLEN=0;            AC_SUBST([REPLACE_STRNLEN])
  REPLACE_STRSIGNAL=0;          AC_SUBST([REPLACE_STRSIGNAL])
  REPLACE_STRTOK_R=0;           AC_SUBST([REPLACE_STRTOK_R])
  UNDEFINE_STRTOK_R=0;          AC_SUBST([UNDEFINE_STRTOK_R])
])

# Configure a replacement for <sys/time.h>.
# serial 6

# Copyright (C) 2007, 2009, 2010 Free Software Foundation, Inc.
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# Written by Paul Eggert and Martin Lambers.

AC_DEFUN([gl_HEADER_SYS_TIME_H],
[
  dnl Use AC_REQUIRE here, so that the REPLACE_GETTIMEOFDAY=0 statement
  dnl below is expanded once only, before all REPLACE_GETTIMEOFDAY=1
  dnl statements that occur in other macros.
  AC_REQUIRE([gl_HEADER_SYS_TIME_H_BODY])
])

AC_DEFUN([gl_HEADER_SYS_TIME_H_BODY],
[
  AC_REQUIRE([AC_C_RESTRICT])
  AC_REQUIRE([gl_HEADER_SYS_TIME_H_DEFAULTS])
  AC_CHECK_HEADERS_ONCE([sys/time.h])
  gl_CHECK_NEXT_HEADERS([sys/time.h])

  if test $ac_cv_header_sys_time_h != yes; then
    HAVE_SYS_TIME_H=0
  fi

  AC_CACHE_CHECK([for struct timeval], [gl_cv_sys_struct_timeval],
    [AC_COMPILE_IFELSE(
       [AC_LANG_PROGRAM(
          [[#if HAVE_SYS_TIME_H
             #include <sys/time.h>
            #endif
            #include <time.h>
          ]],
          [[static struct timeval x; x.tv_sec = x.tv_usec;]])],
       [gl_cv_sys_struct_timeval=yes],
       [gl_cv_sys_struct_timeval=no])])
  if test $gl_cv_sys_struct_timeval != yes; then
    HAVE_STRUCT_TIMEVAL=0
  fi

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[
#if HAVE_SYS_TIME_H
# include <sys/time.h>
#endif
#include <time.h>
    ]], [gettimeofday])
])

AC_DEFUN([gl_SYS_TIME_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_HEADER_SYS_TIME_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_HEADER_SYS_TIME_H_DEFAULTS],
[
  GNULIB_GETTIMEOFDAY=0;     AC_SUBST([GNULIB_GETTIMEOFDAY])
  dnl Assume POSIX behavior unless another module says otherwise.
  HAVE_GETTIMEOFDAY=1;       AC_SUBST([HAVE_GETTIMEOFDAY])
  HAVE_STRUCT_TIMEVAL=1;     AC_SUBST([HAVE_STRUCT_TIMEVAL])
  HAVE_SYS_TIME_H=1;         AC_SUBST([HAVE_SYS_TIME_H])
  REPLACE_GETTIMEOFDAY=0;    AC_SUBST([REPLACE_GETTIMEOFDAY])
])

# unistd_h.m4 serial 46
dnl Copyright (C) 2006-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Simon Josefsson, Bruno Haible.

AC_DEFUN([gl_UNISTD_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  AC_REQUIRE([AC_C_INLINE])

  gl_CHECK_NEXT_HEADERS([unistd.h])

  AC_CHECK_HEADERS_ONCE([unistd.h])
  if test $ac_cv_header_unistd_h = yes; then
    HAVE_UNISTD_H=1
  else
    HAVE_UNISTD_H=0
  fi
  AC_SUBST([HAVE_UNISTD_H])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[#include <unistd.h>
/* Some systems declare various items in the wrong headers.  */
#ifndef __GLIBC__
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__
#  include <io.h>
# endif
#endif
    ]], [chown dup2 dup3 environ euidaccess faccessat fchdir fchownat
    fsync ftruncate getcwd getdomainname getdtablesize getgroups
    gethostname getlogin getlogin_r getpagesize getusershell setusershell
    endusershell lchown link linkat lseek pipe2 pread pwrite readlink
    readlinkat rmdir sleep symlink symlinkat ttyname_r unlink unlinkat
    usleep])
])

AC_DEFUN([gl_UNISTD_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_UNISTD_H_DEFAULTS],
[
  GNULIB_CHOWN=0;            AC_SUBST([GNULIB_CHOWN])
  GNULIB_CLOSE=0;            AC_SUBST([GNULIB_CLOSE])
  GNULIB_DUP2=0;             AC_SUBST([GNULIB_DUP2])
  GNULIB_DUP3=0;             AC_SUBST([GNULIB_DUP3])
  GNULIB_ENVIRON=0;          AC_SUBST([GNULIB_ENVIRON])
  GNULIB_EUIDACCESS=0;       AC_SUBST([GNULIB_EUIDACCESS])
  GNULIB_FACCESSAT=0;        AC_SUBST([GNULIB_FACCESSAT])
  GNULIB_FCHDIR=0;           AC_SUBST([GNULIB_FCHDIR])
  GNULIB_FCHOWNAT=0;         AC_SUBST([GNULIB_FCHOWNAT])
  GNULIB_FSYNC=0;            AC_SUBST([GNULIB_FSYNC])
  GNULIB_FTRUNCATE=0;        AC_SUBST([GNULIB_FTRUNCATE])
  GNULIB_GETCWD=0;           AC_SUBST([GNULIB_GETCWD])
  GNULIB_GETDOMAINNAME=0;    AC_SUBST([GNULIB_GETDOMAINNAME])
  GNULIB_GETDTABLESIZE=0;    AC_SUBST([GNULIB_GETDTABLESIZE])
  GNULIB_GETGROUPS=0;        AC_SUBST([GNULIB_GETGROUPS])
  GNULIB_GETHOSTNAME=0;      AC_SUBST([GNULIB_GETHOSTNAME])
  GNULIB_GETLOGIN=0;         AC_SUBST([GNULIB_GETLOGIN])
  GNULIB_GETLOGIN_R=0;       AC_SUBST([GNULIB_GETLOGIN_R])
  GNULIB_GETPAGESIZE=0;      AC_SUBST([GNULIB_GETPAGESIZE])
  GNULIB_GETUSERSHELL=0;     AC_SUBST([GNULIB_GETUSERSHELL])
  GNULIB_LCHOWN=0;           AC_SUBST([GNULIB_LCHOWN])
  GNULIB_LINK=0;             AC_SUBST([GNULIB_LINK])
  GNULIB_LINKAT=0;           AC_SUBST([GNULIB_LINKAT])
  GNULIB_LSEEK=0;            AC_SUBST([GNULIB_LSEEK])
  GNULIB_PIPE2=0;            AC_SUBST([GNULIB_PIPE2])
  GNULIB_PREAD=0;            AC_SUBST([GNULIB_PREAD])
  GNULIB_PWRITE=0;           AC_SUBST([GNULIB_PWRITE])
  GNULIB_READLINK=0;         AC_SUBST([GNULIB_READLINK])
  GNULIB_READLINKAT=0;       AC_SUBST([GNULIB_READLINKAT])
  GNULIB_RMDIR=0;            AC_SUBST([GNULIB_RMDIR])
  GNULIB_SLEEP=0;            AC_SUBST([GNULIB_SLEEP])
  GNULIB_SYMLINK=0;          AC_SUBST([GNULIB_SYMLINK])
  GNULIB_SYMLINKAT=0;        AC_SUBST([GNULIB_SYMLINKAT])
  GNULIB_TTYNAME_R=0;        AC_SUBST([GNULIB_TTYNAME_R])
  GNULIB_UNISTD_H_GETOPT=0;  AC_SUBST([GNULIB_UNISTD_H_GETOPT])
  GNULIB_UNISTD_H_SIGPIPE=0; AC_SUBST([GNULIB_UNISTD_H_SIGPIPE])
  GNULIB_UNLINK=0;           AC_SUBST([GNULIB_UNLINK])
  GNULIB_UNLINKAT=0;         AC_SUBST([GNULIB_UNLINKAT])
  GNULIB_USLEEP=0;           AC_SUBST([GNULIB_USLEEP])
  GNULIB_WRITE=0;            AC_SUBST([GNULIB_WRITE])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_CHOWN=1;           AC_SUBST([HAVE_CHOWN])
  HAVE_DUP2=1;            AC_SUBST([HAVE_DUP2])
  HAVE_DUP3=1;            AC_SUBST([HAVE_DUP3])
  HAVE_EUIDACCESS=1;      AC_SUBST([HAVE_EUIDACCESS])
  HAVE_FACCESSAT=1;       AC_SUBST([HAVE_FACCESSAT])
  HAVE_FCHDIR=1;          AC_SUBST([HAVE_FCHDIR])
  HAVE_FCHOWNAT=1;        AC_SUBST([HAVE_FCHOWNAT])
  HAVE_FSYNC=1;           AC_SUBST([HAVE_FSYNC])
  HAVE_FTRUNCATE=1;       AC_SUBST([HAVE_FTRUNCATE])
  HAVE_GETDOMAINNAME=1;   AC_SUBST([HAVE_GETDOMAINNAME])
  HAVE_GETDTABLESIZE=1;   AC_SUBST([HAVE_GETDTABLESIZE])
  HAVE_GETGROUPS=1;       AC_SUBST([HAVE_GETGROUPS])
  HAVE_GETHOSTNAME=1;     AC_SUBST([HAVE_GETHOSTNAME])
  HAVE_GETLOGIN=1;        AC_SUBST([HAVE_GETLOGIN])
  HAVE_GETPAGESIZE=1;     AC_SUBST([HAVE_GETPAGESIZE])
  HAVE_LCHOWN=1;          AC_SUBST([HAVE_LCHOWN])
  HAVE_LINK=1;            AC_SUBST([HAVE_LINK])
  HAVE_LINKAT=1;          AC_SUBST([HAVE_LINKAT])
  HAVE_PIPE2=1;           AC_SUBST([HAVE_PIPE2])
  HAVE_PREAD=1;           AC_SUBST([HAVE_PREAD])
  HAVE_PWRITE=1;          AC_SUBST([HAVE_PWRITE])
  HAVE_READLINK=1;        AC_SUBST([HAVE_READLINK])
  HAVE_READLINKAT=1;      AC_SUBST([HAVE_READLINKAT])
  HAVE_SLEEP=1;           AC_SUBST([HAVE_SLEEP])
  HAVE_SYMLINK=1;         AC_SUBST([HAVE_SYMLINK])
  HAVE_SYMLINKAT=1;       AC_SUBST([HAVE_SYMLINKAT])
  HAVE_TTYNAME_R=1;       AC_SUBST([HAVE_TTYNAME_R])
  HAVE_UNLINKAT=1;        AC_SUBST([HAVE_UNLINKAT])
  HAVE_USLEEP=1;          AC_SUBST([HAVE_USLEEP])
  HAVE_DECL_ENVIRON=1;    AC_SUBST([HAVE_DECL_ENVIRON])
  HAVE_DECL_GETLOGIN_R=1; AC_SUBST([HAVE_DECL_GETLOGIN_R])
  HAVE_DECL_GETPAGESIZE=1; AC_SUBST([HAVE_DECL_GETPAGESIZE])
  HAVE_DECL_GETUSERSHELL=1; AC_SUBST([HAVE_DECL_GETUSERSHELL])
  HAVE_OS_H=0;            AC_SUBST([HAVE_OS_H])
  HAVE_SYS_PARAM_H=0;     AC_SUBST([HAVE_SYS_PARAM_H])
  REPLACE_CHOWN=0;        AC_SUBST([REPLACE_CHOWN])
  REPLACE_CLOSE=0;        AC_SUBST([REPLACE_CLOSE])
  REPLACE_DUP=0;          AC_SUBST([REPLACE_DUP])
  REPLACE_DUP2=0;         AC_SUBST([REPLACE_DUP2])
  REPLACE_FCHOWNAT=0;     AC_SUBST([REPLACE_FCHOWNAT])
  REPLACE_GETCWD=0;       AC_SUBST([REPLACE_GETCWD])
  REPLACE_GETGROUPS=0;    AC_SUBST([REPLACE_GETGROUPS])
  REPLACE_GETPAGESIZE=0;  AC_SUBST([REPLACE_GETPAGESIZE])
  REPLACE_LCHOWN=0;       AC_SUBST([REPLACE_LCHOWN])
  REPLACE_LINK=0;         AC_SUBST([REPLACE_LINK])
  REPLACE_LINKAT=0;       AC_SUBST([REPLACE_LINKAT])
  REPLACE_LSEEK=0;        AC_SUBST([REPLACE_LSEEK])
  REPLACE_PREAD=0;        AC_SUBST([REPLACE_PREAD])
  REPLACE_PWRITE=0;       AC_SUBST([REPLACE_PWRITE])
  REPLACE_READLINK=0;     AC_SUBST([REPLACE_READLINK])
  REPLACE_RMDIR=0;        AC_SUBST([REPLACE_RMDIR])
  REPLACE_SLEEP=0;        AC_SUBST([REPLACE_SLEEP])
  REPLACE_SYMLINK=0;      AC_SUBST([REPLACE_SYMLINK])
  REPLACE_TTYNAME_R=0;    AC_SUBST([REPLACE_TTYNAME_R])
  REPLACE_UNLINK=0;       AC_SUBST([REPLACE_UNLINK])
  REPLACE_UNLINKAT=0;     AC_SUBST([REPLACE_UNLINKAT])
  REPLACE_USLEEP=0;       AC_SUBST([REPLACE_USLEEP])
  REPLACE_WRITE=0;        AC_SUBST([REPLACE_WRITE])
  UNISTD_H_HAVE_WINSOCK2_H=0; AC_SUBST([UNISTD_H_HAVE_WINSOCK2_H])
  UNISTD_H_HAVE_WINSOCK2_H_AND_USE_SOCKETS=0;
                           AC_SUBST([UNISTD_H_HAVE_WINSOCK2_H_AND_USE_SOCKETS])
])

# warn-on-use.m4 serial 2
dnl Copyright (C) 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

# gl_WARN_ON_USE_PREPARE(INCLUDES, NAMES)
# ---------------------------------------
# For each whitespace-separated element in the list of NAMES, define
# HAVE_RAW_DECL_name if the function has a declaration among INCLUDES
# even after being undefined as a macro.
#
# See warn-on-use.h for some hints on how to poison function names, as
# well as ideas on poisoning global variables and macros.  NAMES may
# include global variables, but remember that only functions work with
# _GL_WARN_ON_USE.  Typically, INCLUDES only needs to list a single
# header, but if the replacement header pulls in other headers because
# some systems declare functions in the wrong header, then INCLUDES
# should do likewise.
#
# If you assume C89, then it is generally safe to assume declarations
# for functions declared in that standard (such as gets) without
# needing gl_WARN_ON_USE_PREPARE.
AC_DEFUN([gl_WARN_ON_USE_PREPARE],
[
  m4_foreach_w([gl_decl], [$2],
    [AH_TEMPLATE([HAVE_RAW_DECL_]AS_TR_CPP(m4_defn([gl_decl])),
      [Define to 1 if ]m4_defn([gl_decl])[ is declared even after
       undefining macros.])])dnl
  for gl_func in m4_flatten([$2]); do
    AS_VAR_PUSHDEF([gl_Symbol], [gl_cv_have_raw_decl_$gl_func])dnl
    AC_CACHE_CHECK([whether $gl_func is declared without a macro],
      gl_Symbol,
      [AC_COMPILE_IFELSE([AC_LANG_PROGRAM([$1],
[@%:@undef $gl_func
  (void) $gl_func;])],
        [AS_VAR_SET(gl_Symbol, [yes])], [AS_VAR_SET(gl_Symbol, [no])])])
     AS_VAR_IF(gl_Symbol, [yes],
       [AC_DEFINE_UNQUOTED(AS_TR_CPP([HAVE_RAW_DECL_$gl_func]), [1])
       dnl shortcut - if the raw declaration exists, then set a cache
       dnl variable to allow skipping any later AC_CHECK_DECL efforts
       eval ac_cv_have_decl_$gl_func=yes])
    AS_VAR_POPDEF([gl_Symbol])dnl
  done
])

dnl A placeholder for ISO C99 <wchar.h>, for platforms that have issues.

dnl Copyright (C) 2007-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Eric Blake.

# wchar_h.m4 serial 33

AC_DEFUN([gl_WCHAR_H],
[
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])
  AC_REQUIRE([gl_WCHAR_H_INLINE_OK])
  dnl Prepare for creating substitute <wchar.h>.
  dnl Check for <wchar.h> (missing in Linux uClibc when built without wide
  dnl character support).
  dnl <wchar.h> is always overridden, because of GNULIB_POSIXCHECK.
  AC_CHECK_HEADERS_ONCE([wchar.h])
  gl_CHECK_NEXT_HEADERS([wchar.h])
  if test $ac_cv_header_wchar_h = yes; then
    HAVE_WCHAR_H=1
  else
    HAVE_WCHAR_H=0
  fi
  AC_SUBST([HAVE_WCHAR_H])

  AC_REQUIRE([gt_TYPE_WINT_T])
  if test $gt_cv_c_wint_t = yes; then
    HAVE_WINT_T=1
  else
    HAVE_WINT_T=0
  fi
  AC_SUBST([HAVE_WINT_T])

  dnl Check for declarations of anything we want to poison if the
  dnl corresponding gnulib module is not in use.
  gl_WARN_ON_USE_PREPARE([[
/* Some systems require additional headers.  */
#ifndef __GLIBC__
# include <stddef.h>
# include <stdio.h>
# include <time.h>
#endif
#include <wchar.h>
    ]], [btowc wctob mbsinit mbrtowc mbrlen mbsrtowcs mbsnrtowcs wcrtomb
    wcsrtombs wcsnrtombs wcwidth])
])

dnl Check whether <wchar.h> is usable at all.
AC_DEFUN([gl_WCHAR_H_INLINE_OK],
[
  dnl Test whether <wchar.h> suffers due to the transition from '__inline' to
  dnl 'gnu_inline'. See <http://sourceware.org/bugzilla/show_bug.cgi?id=4022>
  dnl and <http://gcc.gnu.org/bugzilla/show_bug.cgi?id=42440>. In summary,
  dnl glibc version 2.5 or older, together with gcc version 4.3 or newer and
  dnl the option -std=c99 or -std=gnu99, leads to a broken <wchar.h>.
  AC_CACHE_CHECK([whether <wchar.h> uses 'inline' correctly],
    [gl_cv_header_wchar_h_correct_inline],
    [gl_cv_header_wchar_h_correct_inline=yes
     AC_LANG_CONFTEST([
       AC_LANG_SOURCE([[#define wcstod renamed_wcstod
#include <wchar.h>
extern int zero (void);
int main () { return zero(); }
]])])
     if AC_TRY_EVAL([ac_compile]); then
       mv conftest.$ac_objext conftest1.$ac_objext
       AC_LANG_CONFTEST([
         AC_LANG_SOURCE([[#define wcstod renamed_wcstod
#include <wchar.h>
int zero (void) { return 0; }
]])])
       if AC_TRY_EVAL([ac_compile]); then
         mv conftest.$ac_objext conftest2.$ac_objext
         if $CC -o conftest$ac_exeext $CFLAGS $LDFLAGS conftest1.$ac_objext conftest2.$ac_objext $LIBS >&AS_MESSAGE_LOG_FD 2>&1; then
           :
         else
           gl_cv_header_wchar_h_correct_inline=no
         fi
       fi
     fi
     rm -f conftest1.$ac_objext conftest2.$ac_objext conftest$ac_exeext
    ])
  if test $gl_cv_header_wchar_h_correct_inline = no; then
    AC_MSG_ERROR([<wchar.h> cannot be used with this compiler ($CC $CFLAGS $CPPFLAGS).
This is a known interoperability problem of glibc <= 2.5 with gcc >= 4.3 in
C99 mode. You have four options:
  - Add the flag -fgnu89-inline to CC and reconfigure, or
  - Fix your include files, using parts of
    <http://sourceware.org/git/?p=glibc.git;a=commitdiff;h=b037a293a48718af30d706c2e18c929d0e69a621>, or
  - Use a gcc version older than 4.3, or
  - Don't use the flags -std=c99 or -std=gnu99.
Configuration aborted.])
  fi
])

dnl Unconditionally enables the replacement of <wchar.h>.
AC_DEFUN([gl_REPLACE_WCHAR_H],
[
  dnl This is a no-op, because <wchar.h> is always overridden.
  :
])

AC_DEFUN([gl_WCHAR_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_WCHAR_H_DEFAULTS])
  gl_MODULE_INDICATOR_SET_VARIABLE([$1])
  dnl Define it also as a C macro, for the benefit of the unit tests.
  gl_MODULE_INDICATOR_FOR_TESTS([$1])
])

AC_DEFUN([gl_WCHAR_H_DEFAULTS],
[
  GNULIB_BTOWC=0;      AC_SUBST([GNULIB_BTOWC])
  GNULIB_WCTOB=0;      AC_SUBST([GNULIB_WCTOB])
  GNULIB_MBSINIT=0;    AC_SUBST([GNULIB_MBSINIT])
  GNULIB_MBRTOWC=0;    AC_SUBST([GNULIB_MBRTOWC])
  GNULIB_MBRLEN=0;     AC_SUBST([GNULIB_MBRLEN])
  GNULIB_MBSRTOWCS=0;  AC_SUBST([GNULIB_MBSRTOWCS])
  GNULIB_MBSNRTOWCS=0; AC_SUBST([GNULIB_MBSNRTOWCS])
  GNULIB_WCRTOMB=0;    AC_SUBST([GNULIB_WCRTOMB])
  GNULIB_WCSRTOMBS=0;  AC_SUBST([GNULIB_WCSRTOMBS])
  GNULIB_WCSNRTOMBS=0; AC_SUBST([GNULIB_WCSNRTOMBS])
  GNULIB_WCWIDTH=0;    AC_SUBST([GNULIB_WCWIDTH])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_BTOWC=1;         AC_SUBST([HAVE_BTOWC])
  HAVE_MBSINIT=1;       AC_SUBST([HAVE_MBSINIT])
  HAVE_MBRTOWC=1;       AC_SUBST([HAVE_MBRTOWC])
  HAVE_MBRLEN=1;        AC_SUBST([HAVE_MBRLEN])
  HAVE_MBSRTOWCS=1;     AC_SUBST([HAVE_MBSRTOWCS])
  HAVE_MBSNRTOWCS=1;    AC_SUBST([HAVE_MBSNRTOWCS])
  HAVE_WCRTOMB=1;       AC_SUBST([HAVE_WCRTOMB])
  HAVE_WCSRTOMBS=1;     AC_SUBST([HAVE_WCSRTOMBS])
  HAVE_WCSNRTOMBS=1;    AC_SUBST([HAVE_WCSNRTOMBS])
  HAVE_DECL_WCTOB=1;    AC_SUBST([HAVE_DECL_WCTOB])
  HAVE_DECL_WCWIDTH=1;  AC_SUBST([HAVE_DECL_WCWIDTH])
  REPLACE_MBSTATE_T=0;  AC_SUBST([REPLACE_MBSTATE_T])
  REPLACE_BTOWC=0;      AC_SUBST([REPLACE_BTOWC])
  REPLACE_WCTOB=0;      AC_SUBST([REPLACE_WCTOB])
  REPLACE_MBSINIT=0;    AC_SUBST([REPLACE_MBSINIT])
  REPLACE_MBRTOWC=0;    AC_SUBST([REPLACE_MBRTOWC])
  REPLACE_MBRLEN=0;     AC_SUBST([REPLACE_MBRLEN])
  REPLACE_MBSRTOWCS=0;  AC_SUBST([REPLACE_MBSRTOWCS])
  REPLACE_MBSNRTOWCS=0; AC_SUBST([REPLACE_MBSNRTOWCS])
  REPLACE_WCRTOMB=0;    AC_SUBST([REPLACE_WCRTOMB])
  REPLACE_WCSRTOMBS=0;  AC_SUBST([REPLACE_WCSRTOMBS])
  REPLACE_WCSNRTOMBS=0; AC_SUBST([REPLACE_WCSNRTOMBS])
  REPLACE_WCWIDTH=0;    AC_SUBST([REPLACE_WCWIDTH])
])

# wchar_t.m4 serial 3 (gettext-0.18)
dnl Copyright (C) 2002-2003, 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.
dnl Test whether <stddef.h> has the 'wchar_t' type.
dnl Prerequisite: AC_PROG_CC

AC_DEFUN([gt_TYPE_WCHAR_T],
[
  AC_CACHE_CHECK([for wchar_t], [gt_cv_c_wchar_t],
    [AC_TRY_COMPILE([#include <stddef.h>
       wchar_t foo = (wchar_t)'\0';], ,
       [gt_cv_c_wchar_t=yes], [gt_cv_c_wchar_t=no])])
  if test $gt_cv_c_wchar_t = yes; then
    AC_DEFINE([HAVE_WCHAR_T], [1], [Define if you have the 'wchar_t' type.])
  fi
])

# wctype_h.m4 serial 6

dnl A placeholder for ISO C99 <wctype.h>, for platforms that lack it.

dnl Copyright (C) 2006-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Paul Eggert.

AC_DEFUN([gl_WCTYPE_H],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_REQUIRE([AC_CANONICAL_HOST])
  AC_CHECK_FUNCS_ONCE([iswcntrl])
  if test $ac_cv_func_iswcntrl = yes; then
    HAVE_ISWCNTRL=1
  else
    HAVE_ISWCNTRL=0
  fi
  AC_SUBST([HAVE_ISWCNTRL])
  AC_CHECK_FUNCS_ONCE([iswblank])
  if test $ac_cv_func_iswblank = yes; then
    HAVE_ISWBLANK=1
  else
    HAVE_ISWBLANK=0
  fi
  AC_SUBST([HAVE_ISWBLANK])
  AC_CHECK_HEADERS_ONCE([wctype.h])
  AC_REQUIRE([AC_C_INLINE])

  AC_REQUIRE([gt_TYPE_WINT_T])
  if test $gt_cv_c_wint_t = yes; then
    HAVE_WINT_T=1
  else
    HAVE_WINT_T=0
  fi
  AC_SUBST([HAVE_WINT_T])

  if test $ac_cv_header_wctype_h = yes; then
    if test $ac_cv_func_iswcntrl = yes; then
      dnl Linux libc5 has an iswprint function that returns 0 for all arguments.
      dnl The other functions are likely broken in the same way.
      AC_CACHE_CHECK([whether iswcntrl works], [gl_cv_func_iswcntrl_works],
        [
          AC_RUN_IFELSE([AC_LANG_SOURCE([[
                            #include <stddef.h>
                            #include <stdio.h>
                            #include <time.h>
                            #include <wchar.h>
                            #include <wctype.h>
                            int main () { return iswprint ('x') == 0; }]])],
            [gl_cv_func_iswcntrl_works=yes], [gl_cv_func_iswcntrl_works=no],
            [AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdlib.h>
                          #if __GNU_LIBRARY__ == 1
                          Linux libc5 i18n is broken.
                          #endif]], [])],
              [gl_cv_func_iswcntrl_works=yes], [gl_cv_func_iswcntrl_works=no])
            ])
        ])
    fi
    gl_CHECK_NEXT_HEADERS([wctype.h])
    HAVE_WCTYPE_H=1
  else
    HAVE_WCTYPE_H=0
  fi
  AC_SUBST([HAVE_WCTYPE_H])

  if test "$gl_cv_func_iswcntrl_works" = no; then
    REPLACE_ISWCNTRL=1
  else
    REPLACE_ISWCNTRL=0
  fi
  AC_SUBST([REPLACE_ISWCNTRL])
])

# wint_t.m4 serial 4 (gettext-0.18)
dnl Copyright (C) 2003, 2007-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible.
dnl Test whether <wchar.h> has the 'wint_t' type.
dnl Prerequisite: AC_PROG_CC

AC_DEFUN([gt_TYPE_WINT_T],
[
  AC_CACHE_CHECK([for wint_t], [gt_cv_c_wint_t],
    [AC_TRY_COMPILE([
/* Tru64 with Desktop Toolkit C has a bug: <stdio.h> must be included before
   <wchar.h>.
   BSD/OS 4.0.1 has a bug: <stddef.h>, <stdio.h> and <time.h> must be included
   before <wchar.h>.  */
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>
       wint_t foo = (wchar_t)'\0';], ,
       [gt_cv_c_wint_t=yes], [gt_cv_c_wint_t=no])])
  if test $gt_cv_c_wint_t = yes; then
    AC_DEFINE([HAVE_WINT_T], [1], [Define if you have the 'wint_t' type.])
  fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_ADDRESS_RANGE],
[AC_REQUIRE([AC_PROG_CC])dnl
address_range_prog='
#include <stdio.h>
int printf_address (unsigned long addr) {
  FILE* out = fopen("conftest.h","w");
  if (sizeof(unsigned long) <= 4)
    fprintf(out,"0x%08X\n", (unsigned int)addr);
  else
    fprintf(out,"0x%08X%08X\n",(unsigned int)(addr>>32),(unsigned int)(addr&0xFFFFFFFF));
  return ferror(out) || fclose(out);
}
#define chop_address(addr) ((unsigned long)(char*)(addr) & ~0x00FFFFFFL)
'
AC_CACHE_CHECK(for the code address range, cl_cv_address_code, [dnl
AC_RUN_IFELSE([#include "confdefs.h"
$address_range_prog
dnl printf_address(chop_address(&main)); doesn't work in C++.
int main() { return printf_address(chop_address(&printf_address)); }],
[cl_cv_address_code=`cat conftest.h`],[cl_cv_address_code='guessing 0'],
[cl_cv_address_code='guessing 0'])
rm -f conftest.h
])
x=`echo $cl_cv_address_code | sed -e 's,^guessing ,,'`"UL"
AC_DEFINE_UNQUOTED(CODE_ADDRESS_RANGE,$x,[address range of program code (text+data+bss)])
dnl
AC_CACHE_CHECK(for the malloc address range, cl_cv_address_malloc, [dnl
AC_RUN_IFELSE([#include "confdefs.h"
#include <sys/types.h>
/* declare malloc() */
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
$address_range_prog
int main() { return printf_address(chop_address(malloc(10000))); }],
[cl_cv_address_malloc=`cat conftest.h`],[cl_cv_address_malloc='guessing 0'],
[cl_cv_address_malloc='guessing 0'])
rm -f conftest.h
])
x=`echo $cl_cv_address_malloc | sed -e 's,^guessing ,,'`"UL"
AC_DEFINE_UNQUOTED(MALLOC_ADDRESS_RANGE,$x,[address range of malloc() memory])
dnl
AC_CACHE_CHECK(for the shared library address range, cl_cv_address_shlib, [dnl
AC_RUN_IFELSE([#include "confdefs.h"
$address_range_prog
/* Declare printf(). */
#if defined(sun) /* for SunOS 4, but not for IRIX 6 */
#ifdef __cplusplus
extern "C" int printf (const char *, ...);
#else
extern int printf ();
#endif
#endif
/* Declare tmpnam(). */
#ifdef __cplusplus
extern "C" char* tmpnam (char*);
#else
extern char* tmpnam ();
#endif
/* With normal simple DLLs, &printf is in the shared library. Fine.
   But with ELF, &printf is a trampoline function allocated near the
   program's code range. errno and other global variables - such as
   &stdout - are allocated near the program's code and bss as well.
   However, the return value of tmpnam(NULL) is a pointer to a static
   buffer in the shared library. (This buffer is unlikely to be named
   by a global symbol.) */
int main() {
  char* addr;
  addr = (char*) tmpnam((char*)0);
  if (!addr) addr = (char*) &printf;
  return printf_address(chop_address(addr));
}],[cl_cv_address_shlib=`cat conftest.h`],[cl_cv_address_shlib='guessing 0'],
[cl_cv_address_shlib='guessing 0'])
rm -f conftest.h
])
x=`echo $cl_cv_address_shlib | sed -e 's,^guessing ,,'`"UL"
AC_DEFINE_UNQUOTED(SHLIB_ADDRESS_RANGE,$x,[address range of shared library code])

AC_CACHE_CHECK(for the stack address range, cl_cv_address_stack, [dnl
AC_RUN_IFELSE([#include "confdefs.h"
#include "confdefs.h"
$address_range_prog
int main() { int dummy; return printf_address(chop_address(&dummy)); }],
[cl_cv_address_stack=`cat conftest.h`],[cl_cv_address_stack='guessing ~0'],
[cl_cv_address_stack='guessing ~0'])
rm -f conftest.h
])
x=`echo "$cl_cv_address_stack" | sed -e 's,^guessing ,,'`"UL"
AC_DEFINE_UNQUOTED(STACK_ADDRESS_RANGE,$x,[address range of the C stack])
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_AS_UNDERSCORE],
[AC_BEFORE([$0], [CL_GLOBAL_CONSTRUCTORS])
m4_pattern_allow([^AS_UNDERSCORE$])
AC_CACHE_CHECK(for underscore in external names, cl_cv_prog_as_underscore, [
cat > conftest.c <<EOF
#ifdef __cplusplus
extern "C"
#endif
int foo() { return 0; }
EOF
# look for the assembly language name in the .s file
AC_TRY_COMMAND(${CC-cc} -S conftest.c) >/dev/null 2>&1
if grep _foo conftest.s >/dev/null ; then
  cl_cv_prog_as_underscore=yes
else
  cl_cv_prog_as_underscore=no
fi
rm -f conftest*
])
if test $cl_cv_prog_as_underscore = yes; then
  AS_UNDERSCORE=true
  AC_DEFINE(ASM_UNDERSCORE,,[symbols are prefixed by an underscore in assembly language])
else
  AS_UNDERSCORE=false
fi
AC_SUBST(AS_UNDERSCORE)dnl
])

dnl -*- Autoconf -*-
# bold.m4 serial 2 (clisp)
dnl Copyright (C) 1999-2002 Ralf S. Engelschall <rse@engelschall.com>
dnl Copyright (C) 2002-2008 Bruno Haible <bruno@clisp.org>
dnl Copyright (C) 2006 Sam Steingold <sds@gnu.org>
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

# Determine the escape sequences for switching bold output on and off.
AC_DEFUN([RSE_BOLD],
[
  dnl Not pretty.
  dnl AC_REQUIRE([AC_PROG_AWK])

  case $TERM in
    # for the most important terminal types we directly know the sequences
    xterm*|vt220*)
      term_bold=`${AWK:-awk} 'BEGIN { printf("%c%c%c%c", 27, 91, 49, 109); }' </dev/null 2>/dev/null`
      term_norm=`${AWK:-awk} 'BEGIN { printf("%c%c%c", 27, 91, 109); }' </dev/null 2>/dev/null`
      ;;
    vt100*)
      term_bold=`${AWK:-awk} 'BEGIN { printf("%c%c%c%c%c%c", 27, 91, 49, 109, 0, 0); }' </dev/null 2>/dev/null`
      term_norm=`${AWK:-awk} 'BEGIN { printf("%c%c%c%c%c", 27, 91, 109, 0, 0); }' </dev/null 2>/dev/null`
      ;;
    # for all others, we try to use a possibly existing `tput' or `tcout' utility
    *)
      paths=`echo "$PATH" | sed -e 's/:/ /g'`
      for tool in tput tcout; do
        for dir in $paths; do
          if test -r "$dir/$tool"; then
            for seq in bold md smso; do # 'smso' is last
              bold="`$dir/$tool $seq 2>/dev/null`"
              if test -n "$bold"; then
                term_bold="$bold"
                break
              fi
            done
            if test -n "$term_bold"; then
              for seq in sgr0 me rmso reset; do # 'reset' is last
                norm="`$dir/$tool $seq 2>/dev/null`"
                if test -n "$norm"; then
                  term_norm="$norm"
                  break
                fi
              done
            fi
            break
          fi
        done
        if test -n "$term_bold" && test -n "$term_norm"; then
          break
        fi
      done
      ;;
  esac

])
AC_DEFUN([BOLD_MSG],[AC_MSG_NOTICE([${term_bold}** $1${term_norm}])])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_BUILTIN_STRLEN],
[AC_CACHE_CHECK(for inline __builtin_strlen, cl_cv_builtin_strlen, [
cat > conftest.$ac_ext <<EOF
int foo (char* x)
{ return __builtin_strlen(x); }
EOF
if AC_TRY_COMMAND(${CC-cc} -S $CFLAGS $CPPFLAGS conftest.$ac_ext) >/dev/null 2>&1 ; then
  if grep strlen conftest.s >/dev/null ; then
    cl_cv_builtin_strlen=no
  else
    cl_cv_builtin_strlen=yes
  fi
else
  cl_cv_builtin_strlen=no
fi
rm -f conftest*
])
if test $cl_cv_builtin_strlen = yes; then
  AC_DEFINE(HAVE_BUILTIN_STRLEN,,[__builtin_strlen() is compiled inline (not a call to strlen())])
fi
])

dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.61)

AC_DEFUN([CL_CC_CPLUSPLUS],
[AC_REQUIRE([AC_PROG_CPP])
AC_CACHE_CHECK(whether using C++, cl_cv_prog_cc_cplusplus, [
AC_EGREP_CPP(yes,[#ifdef __cplusplus
  yes
#endif
], cl_cv_prog_cc_cplusplus=yes, cl_cv_prog_cc_cplusplus=no)
])
if test $cl_cv_prog_cc_cplusplus = yes; then
  CC_CPLUSPLUS=true
else
  CC_CPLUSPLUS=false
fi
AC_SUBST(CC_CPLUSPLUS)dnl
])

AC_DEFUN([CL_CXX_WORKS],
[AC_CACHE_CHECK(whether CXX works at all, cl_cv_prog_cxx_works, [
AC_LANG_PUSH(C++)
AC_RUN_IFELSE([AC_LANG_SOURCE([int main() { exit(0); }])],
[cl_cv_prog_cxx_works=yes], [cl_cv_prog_cxx_works=no],
[AC_LINK_IFELSE([AC_LANG_SOURCE([])], [cl_cv_prog_cxx_works=yes],
[cl_cv_prog_cxx_works=no])])
AC_LANG_POP(C++)
])
if test "$cl_cv_prog_cxx_works" = "no"; then
AC_MSG_FAILURE([Installation or configuration problem: C++ compiler cannot create executables.])
fi
])

AC_DEFUN([CL_TEMPLATE_NULL],
[CL_COMPILE_CHECK([working template<>], cl_cv_c_templatenull,
[template <class T> class c {}; template <> class c<int> { int x; };], ,
AC_DEFINE(HAVE_TEMPLATE_NULL))
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_CADDR_T],
[AC_CACHE_CHECK(for caddr_t in sys/types.h, cl_cv_type_caddr_t, [
AC_EGREP_HEADER(caddr_t, sys/types.h,
cl_cv_type_caddr_t=yes, cl_cv_type_caddr_t=no)
])
if test $cl_cv_type_caddr_t = yes; then
  AC_DEFINE(CADDR_T, caddr_t, [what is your caddr_t type?])
else
  AC_DEFINE(CADDR_T, void*)
fi
])

dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.61)

AC_DEFUN([CL_CC_NEED_DEEMA],
[AC_REQUIRE([AC_PROG_CPP])
AC_CACHE_CHECK(whether CPP likes empty macro arguments, cl_cv_prog_cc_ema, [
AC_PREPROC_IFELSE([AC_LANG_SOURCE([#define divide(x,y,q_zuw,r_zuw) (r_zuw(x)-(q_zuw(x)/(y))*(y))
foo(x,y) int x,y; { int q; divide(x,y,q=,); return q; }])],
cl_cv_prog_cc_ema=yes, cl_cv_prog_cc_ema=no)])
if test $cl_cv_prog_cc_ema = yes; then
  CC_NEED_DEEMA=false
else
  CC_NEED_DEEMA=true
fi
AC_SUBST(CC_NEED_DEEMA)dnl
])

dnl Copyright (C) 1993-2002 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels.

AC_PREREQ(2.13)

AC_DEFUN([CL_CC_GCC],
[AC_REQUIRE([AC_PROG_CPP])
AC_CACHE_CHECK(whether using GNU C, cl_cv_prog_cc_gcc, [
AC_EGREP_CPP(yes,[#ifdef __GNUC__
  yes
#endif
], cl_cv_prog_cc_gcc=yes, cl_cv_prog_cc_gcc=no)
])
if test $cl_cv_prog_cc_gcc = yes; then
  CC_GCC=true
  GCC_X_NONE='-x none'
else
  CC_GCC=false
  GCC_X_NONE=''
fi
AC_SUBST(CC_GCC)dnl
AC_SUBST(GCC_X_NONE)dnl
])

dnl Copyright (C) 2008 Sam Steingold (GNU GPLv2+)
dnl -*- Autoconf -*-

AC_PREREQ(2.13)

AC_DEFUN([CL_CC_SUNPRO],
[AC_REQUIRE([AC_PROG_CPP])
AC_CACHE_CHECK(whether using SUNPRO C, cl_cv_prog_cc_sunpro, [
AC_EGREP_CPP(yes,[#ifdef __SUNPRO_C
  yes
#endif
], cl_cv_prog_cc_sunpro=yes, cl_cv_prog_cc_sunpro=no)])
if test $cl_cv_prog_cc_sunpro = yes; then
  CC_SUNPRO=true
else
  CC_SUNPRO=false
fi
AC_SUBST(CC_SUNPRO)dnl
])

dnl -*- Autoconf -*-
dnl Copyright (C) 2008-2010 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Sam Steingold.

AC_PREREQ(2.59)

dnl set variable $1 to the result of evaluating in clisp of $2
AC_DEFUN([CLISP_SET],[$1=`$cl_cv_clisp -q -norc -x '$2' 2>/dev/null | sed -e 's/^"//' -e 's/"$//'`])

dnl for use with autoconf 2.64 which supports m4_map_args_w
dnl <http://article.gmane.org/gmane.comp.sysutils.autoconf.general/12077>
m4_define([_CL_CLISP_REQUIRE_FEATURE_1],
[_CL_CLISP_REQUIRE_FEATURE_2([$1], m4_toupper([$1]))])
m4_define([_CL_CLISP_REQUIRE_FEATURE_2],
[AC_CACHE_CHECK([for $2 in CLISP], [cl_cv_clisp_$1],
 [CLISP_SET([cl_cv_clisp_$1], [[#+$1 "yes" #-$1 "no"]])])
test $cl_cv_clisp_$1 = no && AC_MSG_ERROR([no $2 in CLISP])])
dnl replace m4_foreach_w below with this:
dnl m4_map_args_w([$1], [_CL_CLISP_REQUIRE_FEATURE_1(], [)], [
dnl ])

dnl When running on woe32, we must ensure that cl_cv_clisp_libdir contains
dnl no colons because this will confuse make ("multiple target patterns")
dnl when $(CLISP_LIBDIR) appears in the list of dependencies.
dnl Moreover, if a colon appears in CPPFLAGS (as -Ic:/foo/bar),
dnl then it will creep into the <module>/gllib/.deps/* files.
AC_DEFUN([CL_DECOLONIZE],
[AC_CACHE_CHECK([how to remove colons from paths], [cl_cv_decolonize],
[case $ac_cv_build in
  *-cygwin ) cl_cv_decolonize='cygpath --unix $x' ;;
  *-mingw* ) cl_cv_decolonize="echo \$x | sed -e 's,\\\\,/,g' -e 's,^\\(.\\):,/\1,'" ;;
  * ) cl_cv_decolonize='echo $x'
esac])
CLISP_DECOLONIZE=$cl_cv_decolonize
AC_SUBST(CLISP_DECOLONIZE)])

dnl check for a clisp installation
dnl use --with-clisp=path if your clisp is not in the PATH
dnl if you want to link with the full linking set,
dnl use --with-clisp='clisp -K full'
AC_DEFUN([CL_CLISP],[dnl
AC_REQUIRE([CL_DECOLONIZE])
AC_ARG_WITH([clisp],
AC_HELP_STRING([--with-clisp],[use a specific CLISP installation]),
[cl_use_clisp="$withval"], [cl_use_clisp=default])
cl_have_clisp=no
if test "$cl_use_clisp" != "no"; then
  if test "$cl_use_clisp" = default -o "$cl_use_clisp" = yes;
  then AC_PATH_PROG(cl_cv_clisp, clisp)
  else cl_cv_clisp="$cl_use_clisp"
  fi
  if test "X$cl_cv_clisp" != "X"; then
    AC_CACHE_CHECK([for CLISP version], [cl_cv_clisp_version], [dnl
     dnl head closes its input after the 1st line and clisp (at least on woe32)
     dnl prints [stream.d:5473] *** - Win32 error 232 (ERROR_NO_DATA): The pipe is being closed.
     dnl we avoid this message by redirecting clisp stderr to /dev/null
     if $cl_cv_clisp --version 2>/dev/null | head -n 1 | grep "GNU CLISP" >/dev/null 2>&1;
     then CLISP_SET(cl_cv_clisp_version,[(lisp-implementation-version)])
     else cl_cv_clisp_version='not a CLISP'
     fi])
    AC_CACHE_CHECK([for CLISP libdir], [cl_cv_clisp_libdir], [dnl
     CLISP_SET(cl_cv_clisp_libdir,[(namestring *lib-directory*)])
     x=$cl_cv_clisp_libdir;
     cl_cv_clisp_libdir=`eval $cl_cv_decolonize`
     # cf src/clisp-link.in:linkkitdir
     missing=''
     for f in modules.c clisp.h; do
       test -r "${cl_cv_clisp_libdir}linkkit/$f" || missing=${missing}' '$f
     done
     test -n "${missing}" && cl_cv_clisp_libdir="missing${missing}"])
    AC_CACHE_CHECK([for CLISP linking set], [cl_cv_clisp_linkset], [dnl
     CLISP_SET(cl_cv_clisp_linkset,[(sys::program-name)])
     cl_cv_clisp_linkset=`dirname ${cl_cv_clisp_linkset}`
     missing=''
     # cf. src/clisp-link.in:check_linkset (we do not need to check for
     # lisp.run because cl_cv_clisp_linkset comes from SYS::PROGRAM-NAME)
     for f in lisp.a lispinit.mem modules.h modules.o makevars; do
       test -r "${cl_cv_clisp_linkset}/$f" || missing=${missing}' '$f
     done
     test -n "${missing}" && cl_cv_clisp_linkset="missing${missing}"])
    CLISP=$cl_cv_clisp; AC_SUBST(CLISP)dnl
    CLISP_LIBDIR="${cl_cv_clisp_libdir}"; AC_SUBST(CLISP_LIBDIR)dnl
    CLISP_LINKKIT="${cl_cv_clisp_libdir}linkkit"; AC_SUBST(CLISP_LINKKIT)dnl
    sed 's/^/CLISP_/' ${cl_cv_clisp_linkset}/makevars > conftestvars
    . ./conftestvars
    rm -f conftestvars
    AC_SUBST(CLISP_FILES)dnl
    AC_SUBST(CLISP_LIBS)dnl
    AC_SUBST(CLISP_CFLAGS)dnl
    AC_SUBST(CLISP_CPPFLAGS)dnl
    test -d $cl_cv_clisp_libdir -a -d $cl_cv_clisp_linkset && cl_have_clisp=yes
  fi
fi
AC_CACHE_CHECK([for CLISP], [cl_cv_have_clisp],
[cl_cv_have_clisp=$cl_have_clisp])
required=m4_default([$2], [true])
${required} && test $cl_cv_have_clisp = no && AC_MSG_ERROR([CLISP not found])
m4_foreach_w([cl_feat], m4_toupper([$1]),
[AC_CACHE_CHECK([for cl_feat in CLISP], [cl_cv_clisp_]cl_feat,
[CLISP_SET([cl_cv_clisp_]cl_feat,[[#+]]cl_feat[[ "yes" #-]]cl_feat[[ "no"]])])
${required} && test $cl_cv_clisp_[]cl_feat = no && \
AC_MSG_ERROR([no ]cl_feat[ in CLISP])])])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.13)

AC_DEFUN([CL_CLOSEDIR],
[AC_BEFORE([$0], [CL_FILECHARSET])dnl
# The following test is necessary, because Cygwin32 declares closedir()
# as returning int but the return value is unusable.
AC_CACHE_CHECK(for usable closedir return value, cl_cv_func_closedir_retval,[
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif
/* Declare opendir(), closedir(). */
#include <dirent.h>
int main() { exit(closedir(opendir(".")) != 0); }],
cl_cv_func_closedir_retval=yes, cl_cv_func_closedir_retval=no,
# When cross-compiling, don't assume a return value.
cl_cv_func_closedir_retval="guessing no")])
case "$cl_cv_func_closedir_retval" in
  *no) AC_DEFINE(VOID_CLOSEDIR,,[closedir() return value is void or unusable]) ;;
esac
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2004, 2007-2009 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.13)

AC_DEFUN([CL_CONNECT],
[AC_CHECK_FUNCS(connect)
if test $ac_cv_func_connect = yes; then
CL_PROTO([connect], [
for x in CONST_VARIANTS; do
for y in 'struct sockaddr *' 'void*'; do
for z in SIZE_VARIANTS; do
if test -z "$have_connect_decl"; then
CL_PROTO_TRY([
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/socket.h>
], [int connect (int fd, $x $y name, $z namelen);], [
cl_cv_proto_connect_arg2a="$x"
cl_cv_proto_connect_arg2b="$y"
cl_cv_proto_connect_arg3="$z"
have_connect_decl=1])
fi
done
done
done
if test -z "$have_connect_decl"; then
CL_PROTO_MISSING(connect)
fi
], [extern int connect (int, $cl_cv_proto_connect_arg2a $cl_cv_proto_connect_arg2b, $cl_cv_proto_connect_arg3);])
AC_DEFINE_UNQUOTED(CONNECT_CONST,$cl_cv_proto_connect_arg2a,[does declaration of connect() need const?])
AC_DEFINE_UNQUOTED(CONNECT_NAME_T,$cl_cv_proto_connect_arg2b,[type of `name' in connect() declaration])
AC_DEFINE_UNQUOTED(CONNECT_ADDRLEN_T,$cl_cv_proto_connect_arg3,[type of `addrlen' in connect() declaration])
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_DYNLOAD],
[dnl Some systems have dlopen in libc, some have it in libdl.
AC_CHECK_HEADERS(dlfcn.h)
if test "$ac_cv_header_dlfcn_h" = yes; then
  AC_SEARCH_LIBS(dlopen, dl)
  AC_CHECK_FUNCS(dlopen dlsym dlvsym dlerror dlclose dladdr)
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_ELOOP],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_CACHE_CHECK(for ELOOP, cl_cv_decl_eloop, [dnl
AC_RUN_IFELSE([#include "confdefs.h"
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <errno.h>
#include <stdio.h>
#ifdef ELOOP
int main () {
  if (freopen("conftest.out", "w", stdout) == NULL) return 1;
  printf("ELOOP\n");
  return ferror(stdout) || fclose(stdout);
}
#else
extern int errno;
#define foo "conflink"
#define foobar "conflink/somefile"
int main() {
  /* If a system goes into an endless loop on this, it must be really broken. */
  if (symlink(foo,foo)<0) return 1;
  if (unlink(foobar)>=0) { unlink(foo); return 1; }
  if (freopen("conftest.out", "w", stdout) == NULL) return 1;
  printf("%d\n",errno); unlink(foo);
  return ferror(stdout) || fclose(stdout);
}
#endif],[cl_cv_decl_ELOOP=`cat conftest.out`
if test "$cl_cv_decl_ELOOP" = "ELOOP"; then
  cl_cv_decl_eloop=yes
else
  cl_cv_decl_eloop="$cl_cv_decl_ELOOP"
fi],[cl_cv_decl_eloop=no
cl_cv_decl_ELOOP="ELOOP"],[AC_EGREP_CPP(yes,[
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <errno.h>
#include <stdio.h>
#ifdef ELOOP
yes
#endif
],[cl_cv_decl_eloop=yes],[cl_cv_decl_eloop=no])
cl_cv_decl_ELOOP="ELOOP"])
rm -f conftest.out
])
AC_DEFINE_UNQUOTED(ELOOP_VALUE,$cl_cv_decl_ELOOP,[the real value of ELOOP even if it is hidden in <errno.h>])
])

dnl -*- Autoconf -*-
dnl Copyright (C) 2002-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Sam Steingold.

AC_PREREQ(2.61)

dnl Each of the macros determines a facet of the default floating-point
dnl environment.
dnl   CL_FLOAT_DIV0        CL_DOUBLE_DIV0        CL_LONGDOUBLE_DIV0
dnl   CL_FLOAT_OVERFLOW    CL_DOUBLE_OVERFLOW    CL_LONGDOUBLE_OVERFLOW
dnl   CL_FLOAT_UNDERFLOW   CL_DOUBLE_UNDERFLOW   CL_LONGDOUBLE_UNDERFLOW
dnl   CL_FLOAT_INEXACT     CL_DOUBLE_INEXACT     CL_LONGDOUBLE_INEXACT

m4_define([CL_FENV_SIGNAL_INSTALL],[signal (SIGFPE, sigfpe_handler);
#if (defined (__sgi) || defined (_AIX)) && defined (SIGTRAP)
  signal (SIGTRAP, sigfpe_handler);
#endif])

AC_DEFUN([CL_FENV_CHECK],[dnl
AC_CACHE_CHECK([whether $1],[$2],
[AC_RUN_IFELSE([AC_LANG_SOURCE([#include <stdlib.h>
#include <signal.h>
static void sigfpe_handler (int sig) { exit (1); }
$3])],[$2=no], [$2=yes], [$2="guessing no"])])])

AC_DEFUN([CL_FLOAT_DIV0],
[CL_FENV_CHECK([single-float divbyzero raises an exception],
[cl_cv_cc_float_divbyzero],[dnl
float x = 1;
float y = 0;
float z;
float nan;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y; nan = y / y;
  return 0;
}])
if test "$cl_cv_cc_float_divbyzero" = yes; then
  AC_DEFINE(FLOAT_DIV0_EXCEPTION,1,
    [Define to 1 if 'float' division by zero raises an exception.])
fi
])

AC_DEFUN([CL_DOUBLE_DIV0],
[CL_FENV_CHECK([double-float divbyzero raises an exception],
[cl_cv_cc_double_divbyzero],[dnl
double x = 1;
double y = 0;
double z;
double nan;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y; nan = y / y;
  return 0;
}])
if test "$cl_cv_cc_double_divbyzero" = yes; then
  AC_DEFINE(DOUBLE_DIV0_EXCEPTION,1,
    [Define to 1 if 'double' division by zero raises an exception.])
fi
])

AC_DEFUN([CL_LONGDOUBLE_DIV0],
[CL_FENV_CHECK([long-float divbyzero raises an exception],
[cl_cv_cc_longdouble_divbyzero],[dnl
long double x = 1;
long double y = 0;
long double z;
long double nan;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y; nan = y / y;
  return 0;
}])
if test "$cl_cv_cc_longdouble_divbyzero" = yes; then
  AC_DEFINE(LONGDOUBLE_DIV0_EXCEPTION,1,
    [Define to 1 if 'long double' division by zero raises an exception.])
fi
])


AC_DEFUN([CL_FLOAT_OVERFLOW],
[CL_FENV_CHECK([single-float overflow raises an exception],
[cl_cv_cc_float_overflow],[dnl
#include <float.h>
float x = FLT_MAX;
float y = FLT_MAX;
float z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_float_overflow" = yes; then
  AC_DEFINE(FLOAT_OVERFLOW_EXCEPTION,1,
    [Define to 1 if 'float' overflow raises an exception.])
fi
])

AC_DEFUN([CL_DOUBLE_OVERFLOW],
[CL_FENV_CHECK([double-float overflow raises an exception],
[cl_cv_cc_double_overflow],[dnl
#include <float.h>
double x = DBL_MAX;
double y = DBL_MAX;
double z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_double_overflow" = yes; then
  AC_DEFINE(DOUBLE_OVERFLOW_EXCEPTION,1,
    [Define to 1 if 'double' overflow raises an exception.])
fi
])

AC_DEFUN([CL_LONGDOUBLE_OVERFLOW],
[CL_FENV_CHECK([long-float overflow raises an exception],
[cl_cv_cc_longdouble_overflow],[dnl
#include <float.h>
long double x;
long double y;
long double z;
int main () {
  x = LDBL_MAX;
  y = LDBL_MAX;
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_longdouble_overflow" = yes; then
  AC_DEFINE(LONGDOUBLE_OVERFLOW_EXCEPTION,1,
    [Define to 1 if 'long double' overflow raises an exception.])
fi
])


AC_DEFUN([CL_FLOAT_UNDERFLOW],
[CL_FENV_CHECK([single-float underflow raises an exception],
[cl_cv_cc_float_underflow],[dnl
#include <float.h>
float x = FLT_MIN;
float y = FLT_MIN;
float z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_float_underflow" = yes; then
  AC_DEFINE(FLOAT_UNDERFLOW_EXCEPTION,1,
    [Define to 1 if 'float' underflow raises an exception.])
fi
])

AC_DEFUN([CL_DOUBLE_UNDERFLOW],
[CL_FENV_CHECK([double-float underflow raises an exception],
[cl_cv_cc_double_underflow],[dnl
#include <float.h>
double x = DBL_MIN;
double y = DBL_MIN;
double z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_double_underflow" = yes; then
  AC_DEFINE(DOUBLE_UNDERFLOW_EXCEPTION,1,
    [Define to 1 if 'double' underflow raises an exception.])
fi
])

AC_DEFUN([CL_LONGDOUBLE_UNDERFLOW],
[CL_FENV_CHECK([long-float underflow raises an exception],
[cl_cv_cc_longdouble_underflow],[dnl
#include <float.h>
long double x;
long double y;
long double z;
int main () {
  x = LDBL_MIN;
  y = LDBL_MIN;
  CL_FENV_SIGNAL_INSTALL
  z = x * y;
  return 0;
}])
if test "$cl_cv_cc_longdouble_underflow" = yes; then
  AC_DEFINE(LONGDOUBLE_UNDERFLOW_EXCEPTION,1,
    [Define to 1 if 'long double' underflow raises an exception.])
fi
])


AC_DEFUN([CL_FLOAT_INEXACT],
[CL_FENV_CHECK([single-float inexact raises an exception],
[cl_cv_cc_float_inexact],[dnl
float x = 1;
float y = 3;
float z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y;
  return 0;
}])
if test "$cl_cv_cc_float_inexact" = yes; then
  AC_DEFINE(FLOAT_INEXACT_EXCEPTION,1,
    [Define to 1 if a 'float' inexact operation raises an exception.])
fi
])

AC_DEFUN([CL_DOUBLE_INEXACT],
[CL_FENV_CHECK([double-float inexact raises an exception],
[cl_cv_cc_double_inexact],[dnl
double x = 1;
double y = 3;
double z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y;
  return 0;
}])
if test "$cl_cv_cc_double_inexact" = yes; then
  AC_DEFINE(DOUBLE_INEXACT_EXCEPTION,1,
    [Define to 1 if a 'double' inexact operation raises an exception.])
fi
])

AC_DEFUN([CL_LONGDOUBLE_INEXACT],
[CL_FENV_CHECK([long-float inexact raises an exception],
[cl_cv_cc_longdouble_inexact],[dnl
long double x = 1;
long double y = 3;
long double z;
int main () {
  CL_FENV_SIGNAL_INSTALL
  z = x / y;
  return 0;
}])
if test "$cl_cv_cc_longdouble_inexact" = yes; then
  AC_DEFINE(LONGDOUBLE_INEXACT_EXCEPTION,1,
    [Define to 1 if a 'long double' inexact operation raises an exception.])
fi
])

# -*- Autoconf -*-
# Copyright (C) 2007-2009 Sam Steingold (GNU GPL2+)

AC_PREREQ(2.61)

AC_DEFUN([CL_FFCALL],[dnl
AC_ARG_WITH([ffcall],
[AC_HELP_STRING([--with-ffcall],[use FFCALL (default is YES, if present)])],
[cl_use_ffcall=$withval],[cl_use_ffcall=default])
if test $cl_use_ffcall != no; then
AC_LIB_FROMPACKAGE(avcall,libffcall)
AC_LIB_FROMPACKAGE(callback,libffcall)
AC_LIB_LINKFLAGS([avcall])
AC_LIB_LINKFLAGS([callback])
AC_CHECK_HEADERS(avcall.h callback.h)
if test "$ac_cv_header_avcall_h" = yes \
     -a "$ac_cv_header_callback_h" = yes
then
cl_save_LIBS="$LIBS"
AC_LIB_APPENDTOVAR([LIBS], [$LIBAVCALL])
AC_LIB_APPENDTOVAR([LIBS], [$LIBCALLBACK])
AC_SEARCH_LIBS(__builtin_avcall)
AC_SEARCH_LIBS(trampoline_r_data0)
if test "$ac_cv_search___builtin_avcall" = no \
     -o "$ac_cv_search_trampoline_r_data0" = no
then LIBS=$cl_save_LIBS
fi
fi
AC_CACHE_CHECK([whether libffcall is installed],[cl_cv_have_ffcall],
[if test "$ac_cv_header_avcall_h" = yes \
      -a "$ac_cv_header_callback_h" = yes \
      -a "$ac_cv_search___builtin_avcall" != no \
      -a "$ac_cv_search_trampoline_r_data0" != no
then cl_cv_have_ffcall=yes
else cl_cv_have_ffcall=no
fi])
if test $cl_use_ffcall = yes -a $cl_cv_have_ffcall = no; then
  if [ "$ac_cv_build" = "$ac_cv_host" ]; then host_arg="";
  else host_arg=" --host=$ac_cv_host";
  fi
  AC_MSG_ERROR([despite --with-ffcall, FFCALL was not found
 Either call configure without --with-ffcall or do
  mkdir tools; cd tools; prefix=`pwd`/${ac_cv_host}
  cvs -z3 -d:pserver:anonymous@cvs.savannah.gnu.org:/sources/libffcall co ffcall
  cd ffcall
  ./configure$host_arg --prefix=\${prefix} && make && make check && make install
  cd ../..
  ./configure --with-libffcall-prefix=\${prefix} [$]*])
fi
fi;])])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2009 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.13)

AC_DEFUN([CL_FILECHARSET],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([CL_CLOSEDIR])dnl
AC_CACHE_CHECK(for the valid characters in filenames,
cl_cv_os_valid_filename_char,[dnl
dnl Create the subdirectory the test program will use for its files.
mkdir conftestdir
AC_RUN_IFELSE([[#include "confdefs.h"
#include <sys/types.h>
#include <stdlib.h>
/* Declare chdir(). */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <string.h>
#include <stdio.h>
/* Declare open(). */
#include <fcntl.h>
/* Declare opendir(), readdir(), closedir(). */
#include <dirent.h>
/* A small program which checks for each character whether or not it is
 * valid in filenames.
 * The actual result may depend on OS, its version, and the file system
 * on which the test is run. */
#define N 256
int main ()
{
  if (freopen("conftest.out", "w", stdout) == NULL) return 1;
  char legal[N];
  char filename[4];
  int i;
  if (chdir("conftestdir") < 0) return 1;
  for (i = 0; i < N; i++) legal[i] = 0;
  strcpy(filename,"a_z");
  for (i = 0; i < N; i++)
    if (i != '\0')
      { filename[1] = i;
        /* Determine whether the filename is valid: create a file
         * and check that it is present afterwards, under the same name. */
        { int fd = open(filename, O_CREAT | O_RDWR, 0644);
          if (fd >=0)
            { DIR* dirp = opendir(".");
              if (dirp != (DIR*)0)
                { struct dirent * d;
                  while ((d = readdir(dirp)))
                    { if (!strcmp(d->d_name,".")) continue;
                      if (!strcmp(d->d_name,"..")) continue;
                      if (!strncmp(d->d_name,".nfs",4)) continue;
                      if (!strcmp(d->d_name,filename)) legal[i] = 1;
                      /* Remove the file even if its name is something else. */
                      unlink(d->d_name);
                    }
                  closedir(dirp);
                }
              close(fd);
      } }   }
  /* Output a boolean expression equivalent to legal[ch] (0 <= ch < N). */
  { int need_or = 0;
    int z;
    for (z = 0; z < N; )
      { int x, y;
        if (! legal[z]) { z++; continue; }
        x = z;
        if (need_or) printf(" || ");
        z++;
        if ((z < N) && legal[z])
          { do { do { z++; } while ((z < N) && legal[z]);
                 y = z-1;
                 z++;
               } while ((z < N) && legal[z]);
            { int premises = 0;
              if (x > 0) premises++;
              if (y < N-1) premises++;
              for (i = x; i <= y; i++)
                if (! legal[i])
                  premises++;
              if (premises > 1) printf("(");
              { int need_and = 0;
                if (x > 0) { printf("(ch >= %d)",x); need_and = 1; }
                if (y < N-1)
                  { if (need_and) printf(" && ");
                    printf("(ch <= %d)",y);
                    need_and = 1;
                  }
                for (i = x; i <= y; i++)
                  if (! legal[i])
                    { if (need_and) printf(" && ");
                      printf("(ch != %d)",i);
                      need_and = 1;
                    }
                if (!need_and) printf("1");
              }
              if (premises > 1) printf(")");
            }
            z = y+1;
          }
          else
          { printf("(ch == %d)",x); z++; }
        need_or = 1;
      }
    printf("\n");
  }
  return ferror(stdout) || fclose(stdout);
}]],[cl_cv_os_valid_filename_char=`cat conftest.out`],
[cl_cv_os_valid_filename_char=''],[cl_cv_os_valid_filename_char=''])
dnl clean up
# Workaround a problem with NFS on Solaris 7, where unlink()ed files reappear
# immediately under a different name and disappear only after 1. the process
# doing readdir() has exited and 2. waiting a second or two.
# Even "rm -rf conftestdir" goes into an endless loop, eating CPU time, under
# these conditions.
period=1
while test -n "`ls conftestdir/.nfs* 2>/dev/null`"; do
  echo "waiting for NFS..."
  rm -f conftestdir/.nfs* 2>/dev/null
  sleep $period
  period=`expr 2 '*' $period`
done
# Now it's safe to do "rm -rf conftestdir".
rm -rf conftestdir
rm -f conftest.out
if test -z "$cl_cv_os_valid_filename_char"; then
  cl_cv_os_valid_filename_charset="guessing 7-bit"
else
  if test "$cl_cv_os_valid_filename_char" = '((ch >= 1) && (ch != 47))'; then
    cl_cv_os_valid_filename_charset="8-bit"
  else
    cl_cv_os_valid_filename_charset="7-bit"
  fi
fi
])
if test -n "$cl_cv_os_valid_filename_char"; then
  AC_DEFINE_UNQUOTED(VALID_FILENAME_CHAR,$cl_cv_os_valid_filename_char,[expression in ch which is true if ch is a valid character in filenames])
fi
])

# floatparam.m4 serial 2  -*- Autoconf -*-
dnl Copyright (C) 2005-2008 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible, Sam Steingold.

AC_DEFUN([CL_FLOATPARAM_CROSS],[
  cl_machine_file_h=$1
  {
    echo "/* Rounding modes, for use below */"
    echo "#define rounds_to_nearest        0  /* 0.5 ulp */"
    echo "#define rounds_to_zero           1  /* 1 ulp */"
    echo "#define rounds_to_infinity       2  /* 1 ulp */"
    echo "#define rounds_to_minus_infinity 3  /* 1 ulp */"
    echo
    for type in float double "long double"; do
      if test -n "$type"; then
        epsilon_bits=-1; y="($type)1.0"
        while true; do
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               (($type)(($type)1.0 + ($type)($y)) == ($type)1.0)
               || ($type)(($type)(($type)1.0 + ($type)($y)) - ($type)1.0) != ($type)($y)
             ) - 1];]])],
            [break;])
          epsilon_bits=`expr $epsilon_bits + 1`; y="$y * ($type)0.5"
        done
        negepsilon_bits=-1; y="($type)-1.0"
        while true; do
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               (($type)(($type)1.0 + ($type)($y)) == ($type)1.0)
               || ($type)(($type)(($type)1.0 + ($type)($y)) - ($type)1.0) != ($type)($y)
             ) - 1];]])],
            [break;])
          negepsilon_bits=`expr $negepsilon_bits + 1`; y="$y * ($type)0.5"
        done
        echo "/* Properties of type \`$type': */"
        echo "/* Largest n for which 1+2^(-n) is exactly represented is $epsilon_bits. */"
        echo "/* Largest n for which 1-2^(-n) is exactly represented is $negepsilon_bits. */"
        if test `expr $negepsilon_bits '<=' $epsilon_bits` = 1; then
          echo "#error \"No exponent jump at 1.0 for type $type!\""
        else
          if test `expr $negepsilon_bits '>' $epsilon_bits + 1` = 1; then
            echo "/* Base for type '$type' is 2^"`expr $negepsilon_bits - $epsilon_bits`
          fi
          echo "#define "`echo $type | sed -e 's, ,_,g'`"_mant_bits "`expr $epsilon_bits + 1`
        fi
        x="($type)1.0"
        i=$epsilon_bits
        while test $i != 0; do
          x="$x * ($type)0.5"
          i=`expr $i - 1`
        done
        x="($type)($x)"
        y1="($type)(($type)1.0 + ($type)5.0*$x)"
        y2="($type)(($type)1.0 + ($type)6.0*$x)"
        ys1="($type)(($type)1.0 + ($type)5.4*$x)"
        ys2="($type)(($type)1.0 + ($type)5.6*$x)"
        z1="($type)(($type)-1.0 + ($type)(-5.0)*$x)"
        z2="($type)(($type)-1.0 + ($type)(-6.0)*$x)"
        zs1="($type)(($type)-1.0 + ($type)(-5.4)*$x)"
        zs2="($type)(($type)-1.0 + ($type)(-5.6)*$x)"
        rounds=
        if test -z "$rounds"; then
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               $ys1 == $y1 && $ys2 == $y2 && $zs1 == $z1 && $zs2 == $z2
             ) - 1];]])],
            [rounds=rounds_to_nearest])
        fi
        if test -z "$rounds"; then
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               $ys1 == $y1 && $ys2 == $y1 && $zs1 == $z1 && $zs2 == $z1
             ) - 1];]])],
            [rounds=rounds_to_zero])
        fi
        if test -z "$rounds"; then
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               $ys1 == $y2 && $ys2 == $y2 && $zs1 == $z1 && $zs2 == $z1
             ) - 1];]])],
            [rounds=rounds_to_infinity])
        fi
        if test -z "$rounds"; then
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
            [[typedef int verify[2*(
               $ys1 == $y1 && $ys2 == $y1 && $zs1 == $z2 && $zs2 == $z2
             ) - 1];]])],
            [rounds=rounds_to_minus_infinity])
        fi
        if test -n "$rounds"; then
          echo "#define "`echo $type | sed -e 's, ,_,g'`"_rounds $rounds"
        else
          echo "#error \"Unknown rounding mode for type $type!\""
        fi
        echo
      fi
    done
    dnl Words-in-a-double endianness test. Note that, assuming IEEE 754 format,
    dnl 2.5479915693083957     = { 0x40 0x04 0x62 0x49 0x67 0x65 0x4E 0x64 } ..bIgeNd
    dnl 1.4396527506122064e164 = { 0x62 0x04 0x00 0x00 0x4E 0x65 0x67 0x49 } b...NegI
    dnl 2.5495230282078065     = { 0x40 0x04 0x65 0x6C 0x54 0x54 0x69 0x4C } ..elTTiL
    dnl 1.4139248369879473e214 = { 0x6C 0x65 0x00 0x00 0x4C 0x69 0x54 0x54 } le..LiTT
    double_wordorder_bigendian_p=
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[double a[9] = {
       0, 2.5479915693083957, 0, 1.4396527506122064e164,
       0, 2.5495230282078065, 0, 1.4139248369879473e214,
       0 };]], [])], [dnl
      if grep LiTTle conftest.$ac_objext >/dev/null ; then
        double_wordorder_bigendian_p=0
      else
        if grep bIgeN conftest.$ac_objext >/dev/null ; then
          double_wordorder_bigendian_p=1
        fi
      fi])
    if test -n "$double_wordorder_bigendian_p"; then
      echo "#define double_wordorder_bigendian_p $double_wordorder_bigendian_p"
    else
      echo "/* Dazed and confused!  Better not define anything. */"
    fi
    echo
  } > "$cl_machine_file_h"
])

dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.61)

dnl without AC_MSG_...:   with AC_MSG_... and caching:
dnl   AC_COMPILE_IFELSE      CL_COMPILE_CHECK
dnl   AC_LINK_IFELSE         CL_LINK_CHECK
dnl Usage:
dnl AC_xxx_IFELSE(PROGRAM, ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND])
dnl CL_xxx_CHECK(ECHO-TEXT, CACHE-ID, PROGRAM,
dnl              ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND])

dnl the next macro avoids aclocal warnings about wrong macro order
dnl when making aclocal.m4, see Makefile.devel.
dnl note that this macro cannot call AC_CONFIG_AUX_DIR directly because
dnl the required macros are evaluated BEFORE the macro itself
dnl and some of them require AC_CONFIG_AUX_DIR.
dnl <http://article.gmane.org/gmane.comp.lib.gnulib.bugs/16312>
AC_DEFUN([CL_MODULE_COMMON_CHECKS],[dnl
AC_REQUIRE([CL_CLISP],[CL_CLISP($1)])dnl
AC_REQUIRE([AC_CONFIG_AUX_DIR],
[AC_CONFIG_AUX_DIR([$cl_cv_clisp_libdir/build-aux])])dnl
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_PROG_CPP])dnl
AC_REQUIRE([CL_PROG_LN_S])dnl
AC_REQUIRE([AC_GNU_SOURCE])dnl
AC_REQUIRE([AC_USE_SYSTEM_EXTENSIONS])dnl
AC_CHECK_HEADERS(time.h sys/time.h)dnl
])

AC_DEFUN([CL_CHECK],[dnl
  AC_CACHE_CHECK([for $2],[$3],
    [$1([AC_LANG_PROGRAM([$4],[$5])],[$3=yes],[$3=no])])
  AS_IF([test $$3 = yes], [$6], [$7])
])

AC_DEFUN([CL_COMPILE_CHECK], [CL_CHECK([AC_COMPILE_IFELSE],$@)])
AC_DEFUN([CL_LINK_CHECK], [CL_CHECK([AC_LINK_IFELSE],$@)])

dnl Expands to the "extern ..." prefix used for system declarations.
dnl AC_LANG_EXTERN()
AC_DEFUN([AC_LANG_EXTERN],
[extern
#ifdef __cplusplus
"C"
#endif
])

AC_DEFUN([CL_CC_WORKS],
[AC_CACHE_CHECK(whether CC works at all, cl_cv_prog_cc_works, [
AC_LANG_PUSH(C)
AC_RUN_IFELSE(AC_LANG_PROGRAM([],[]),
[cl_cv_prog_cc_works=yes], [cl_cv_prog_cc_works=no],
AC_LINK_IFELSE(AC_LANG_PROGRAM([],[]),
[cl_cv_prog_cc_works=yes], [cl_cv_prog_cc_works=no]))
AC_LANG_POP(C)
])
if test "$cl_cv_prog_cc_works" = no; then
AC_MSG_FAILURE([Installation or configuration problem: C compiler cannot create executables.])
fi
])

AC_DEFUN([CL_CANONICAL_HOST_CPU],
[AC_REQUIRE([AC_CANONICAL_HOST])AC_REQUIRE([AC_PROG_CC])
case "$host_cpu" in
changequote(,)dnl
  i[4567]86 )
    host_cpu_instructionset=i386
    ;;
  alphaev[4-8] | alphaev56 | alphapca5[67] | alphaev6[78] )
    host_cpu_instructionset=alpha
    ;;
  hppa1.0 | hppa1.1 | hppa2.0* | hppa64 )
    host_cpu_instructionset=hppa
    ;;
  rs6000 )
    host_cpu_instructionset=powerpc
    ;;
  c1 | c2 | c32 | c34 | c38 | c4 )
    host_cpu_instructionset=convex
    ;;
  arm* )
    host_cpu_instructionset=arm
    ;;
changequote([,])dnl
  mips* )
    AC_CACHE_CHECK([for 64-bit MIPS], cl_cv_host_mips64, [
AC_EGREP_CPP(yes,
[#if defined(_MIPS_SZLONG)
#if (_MIPS_SZLONG == 64)
/* We should also check for (_MIPS_SZPTR == 64), but gcc keeps this at 32. */
  yes
#endif
#endif
], cl_cv_host_mips64=yes, cl_cv_host_mips64=no)
])
if test $cl_cv_host_mips64 = yes; then
  host_cpu_instructionset=mips64
else
  host_cpu_instructionset=mips
fi
    ;;
dnl On powerpc64 systems, the C compiler may still be generating 32-bit code.
  powerpc64 )
    AC_CACHE_CHECK([for 64-bit PowerPC], cl_cv_host_powerpc64, [
AC_EGREP_CPP(yes,
[#if defined(__powerpc64__) || defined(_ARCH_PPC64)
  yes
#endif
], cl_cv_host_powerpc64=yes, cl_cv_host_powerpc64=no)
])
if test $cl_cv_host_powerpc64 = yes; then
  host_cpu_instructionset=powerpc64
else
  host_cpu_instructionset=powerpc
fi
    ;;
dnl UltraSPARCs running Linux have `uname -m` = "sparc64", but the C compiler
dnl still generates 32-bit code.
  sparc | sparc64 )
    AC_CACHE_CHECK([for 64-bit SPARC], cl_cv_host_sparc64, [
AC_EGREP_CPP(yes,
[#if defined(__sparcv9) || defined(__arch64__)
  yes
#endif
], cl_cv_host_sparc64=yes, cl_cv_host_sparc64=no)
])
if test $cl_cv_host_sparc64 = yes; then
  host_cpu_instructionset=sparc64
else
  host_cpu_instructionset=sparc
fi
    ;;
dnl On x86_64 systems, the C compiler may still be generating 32-bit code.
  x86_64 )
    AC_CACHE_CHECK([for 64-bit x86_64], cl_cv_host_x86_64, [
AC_EGREP_CPP(yes,
[#if defined(__LP64__) || defined(__x86_64__) || defined(__amd64__)
  yes
#endif
], cl_cv_host_x86_64=yes, cl_cv_host_x86_64=no)
])
if test $cl_cv_host_x86_64 = yes; then
  host_cpu_instructionset=x86_64
else
  host_cpu_instructionset=i386
fi
    ;;
  *)
    host_cpu_instructionset=$host_cpu
    ;;
esac
dnl was AC_DEFINE_UNQUOTED(__${host_cpu}__) but KAI C++ 3.2d doesn't like this
cat >> confdefs.h <<EOF
#ifndef __${host_cpu_instructionset}__
#define __${host_cpu_instructionset}__ 1
#endif
EOF
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_GETHOSTBYNAME],
[AC_CHECK_HEADERS(netdb.h,
[AC_DEFINE(HAVE_GETHOSTBYNAME,,[have gethostbyname()])dnl
break])])

# Configure paths for GTK+
# Owen Taylor     1997-2001

dnl AM_PATH_GTK_2_0([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND [, MODULES]]]])
dnl Test for GTK+, and define GTK_CFLAGS and GTK_LIBS, if gthread is specified in MODULES, 
dnl pass to pkg-config
dnl
AC_DEFUN([AM_PATH_GTK_2_0],
[dnl 
dnl Get the cflags and libraries from pkg-config
dnl
AC_ARG_ENABLE(gtktest, [  --disable-gtktest       do not try to compile and run a test GTK+ program],
		    , enable_gtktest=yes)

  pkg_config_args=gtk+-2.0
  for module in . $4
  do
      case "$module" in
         gthread) 
             pkg_config_args="$pkg_config_args gthread-2.0"
         ;;
      esac
  done

  no_gtk=""

  AC_PATH_PROG(PKG_CONFIG, pkg-config, no)

  if test x$PKG_CONFIG != xno ; then
    if pkg-config --atleast-pkgconfig-version 0.7 ; then
      :
    else
      echo "*** pkg-config too old; version 0.7 or better required."
      no_gtk=yes
      PKG_CONFIG=no
    fi
  else
    no_gtk=yes
  fi

  min_gtk_version=ifelse([$1], ,2.0.0,$1)
  AC_MSG_CHECKING(for GTK+ - version >= $min_gtk_version)

  if test x$PKG_CONFIG != xno ; then
    ## don't try to run the test against uninstalled libtool libs
    if $PKG_CONFIG --uninstalled $pkg_config_args; then
	  echo "Will use uninstalled version of GTK+ found in PKG_CONFIG_PATH"
	  enable_gtktest=no
    fi

    if $PKG_CONFIG --atleast-version $min_gtk_version $pkg_config_args; then
	  :
    else
	  no_gtk=yes
    fi
  fi

  if test x"$no_gtk" = x ; then
    GTK_CFLAGS=`$PKG_CONFIG $pkg_config_args --cflags`
    GTK_LIBS=`$PKG_CONFIG $pkg_config_args --libs`
    gtk_config_major_version=`$PKG_CONFIG --modversion gtk+-2.0 | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    gtk_config_minor_version=`$PKG_CONFIG --modversion gtk+-2.0 | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    gtk_config_micro_version=`$PKG_CONFIG --modversion gtk+-2.0 | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
    if test "x$enable_gtktest" = "xyes" ; then
      ac_save_CFLAGS="$CFLAGS"
      ac_save_LIBS="$LIBS"
      CFLAGS="$CFLAGS $GTK_CFLAGS"
      LIBS="$GTK_LIBS $LIBS"
dnl
dnl Now check if the installed GTK+ is sufficiently new. (Also sanity
dnl checks the results of pkg-config to some extent)
dnl
      rm -f conf.gtktest
      AC_TRY_RUN([
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

int 
main ()
{
  int major, minor, micro;
  char *tmp_version;

  system ("touch conf.gtktest");

  /* HP/UX 9 (%@#!) writes to sscanf strings */
  tmp_version = g_strdup("$min_gtk_version");
  if (sscanf(tmp_version, "%d.%d.%d", &major, &minor, &micro) != 3) {
     printf("%s, bad version string\n", "$min_gtk_version");
     exit(1);
   }

  if ((gtk_major_version != $gtk_config_major_version) ||
      (gtk_minor_version != $gtk_config_minor_version) ||
      (gtk_micro_version != $gtk_config_micro_version))
    {
      printf("\n*** 'pkg-config --modversion gtk+-2.0' returned %d.%d.%d, but GTK+ (%d.%d.%d)\n", 
             $gtk_config_major_version, $gtk_config_minor_version, $gtk_config_micro_version,
             gtk_major_version, gtk_minor_version, gtk_micro_version);
      printf ("*** was found! If pkg-config was correct, then it is best\n");
      printf ("*** to remove the old version of GTK+. You may also be able to fix the error\n");
      printf("*** by modifying your LD_LIBRARY_PATH enviroment variable, or by editing\n");
      printf("*** /etc/ld.so.conf. Make sure you have run ldconfig if that is\n");
      printf("*** required on your system.\n");
      printf("*** If pkg-config was wrong, set the environment variable PKG_CONFIG_PATH\n");
      printf("*** to point to the correct configuration files\n");
    } 
  else if ((gtk_major_version != GTK_MAJOR_VERSION) ||
	   (gtk_minor_version != GTK_MINOR_VERSION) ||
           (gtk_micro_version != GTK_MICRO_VERSION))
    {
      printf("*** GTK+ header files (version %d.%d.%d) do not match\n",
	     GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION);
      printf("*** library (version %d.%d.%d)\n",
	     gtk_major_version, gtk_minor_version, gtk_micro_version);
    }
  else
    {
      if ((gtk_major_version > major) ||
        ((gtk_major_version == major) && (gtk_minor_version > minor)) ||
        ((gtk_major_version == major) && (gtk_minor_version == minor) && (gtk_micro_version >= micro)))
      {
        return 0;
       }
     else
      {
        printf("\n*** An old version of GTK+ (%d.%d.%d) was found.\n",
               gtk_major_version, gtk_minor_version, gtk_micro_version);
        printf("*** You need a version of GTK+ newer than %d.%d.%d. The latest version of\n",
	       major, minor, micro);
        printf("*** GTK+ is always available from ftp://ftp.gtk.org.\n");
        printf("***\n");
        printf("*** If you have already installed a sufficiently new version, this error\n");
        printf("*** probably means that the wrong copy of the pkg-config shell script is\n");
        printf("*** being found. The easiest way to fix this is to remove the old version\n");
        printf("*** of GTK+, but you can also set the PKG_CONFIG environment to point to the\n");
        printf("*** correct copy of pkg-config. (In this case, you will have to\n");
        printf("*** modify your LD_LIBRARY_PATH enviroment variable, or edit /etc/ld.so.conf\n");
        printf("*** so that the correct libraries are found at run-time))\n");
      }
    }
  return 1;
}
],, no_gtk=yes,[echo $ac_n "cross compiling; assumed OK... $ac_c"])
       CFLAGS="$ac_save_CFLAGS"
       LIBS="$ac_save_LIBS"
     fi
  fi
  if test "x$no_gtk" = x ; then
     AC_MSG_RESULT(yes (version $gtk_config_major_version.$gtk_config_minor_version.$gtk_config_micro_version))
     ifelse([$2], , :, [$2])     
  else
     AC_MSG_RESULT(no)
     if test "$PKG_CONFIG" = "no" ; then
       echo "*** A new enough version of pkg-config was not found."
       echo "*** See http://pkgconfig.sourceforge.net"
     else
       if test -f conf.gtktest ; then
        :
       else
          echo "*** Could not run GTK+ test program, checking why..."
	  ac_save_CFLAGS="$CFLAGS"
	  ac_save_LIBS="$LIBS"
          CFLAGS="$CFLAGS $GTK_CFLAGS"
          LIBS="$LIBS $GTK_LIBS"
          AC_TRY_LINK([
#include <gtk/gtk.h>
#include <stdio.h>
],      [ return ((gtk_major_version) || (gtk_minor_version) || (gtk_micro_version)); ],
        [ echo "*** The test program compiled, but did not run. This usually means"
          echo "*** that the run-time linker is not finding GTK+ or finding the wrong"
          echo "*** version of GTK+. If it is not finding GTK+, you'll need to set your"
          echo "*** LD_LIBRARY_PATH environment variable, or edit /etc/ld.so.conf to point"
          echo "*** to the installed location  Also, make sure you have run ldconfig if that"
          echo "*** is required on your system"
	  echo "***"
          echo "*** If you have an old version installed, it is best to remove it, although"
          echo "*** you may also be able to get things to work by modifying LD_LIBRARY_PATH" ],
        [ echo "*** The test program failed to compile or link. See the file config.log for the"
          echo "*** exact error that occured. This usually means GTK+ is incorrectly installed."])
          CFLAGS="$ac_save_CFLAGS"
          LIBS="$ac_save_LIBS"
       fi
     fi
     GTK_CFLAGS=""
     GTK_LIBS=""
     ifelse([$3], , :, [$3])
  fi
  AC_SUBST(GTK_CFLAGS)
  AC_SUBST(GTK_LIBS)
  rm -f conf.gtktest
])

# intparam.m4 serial 3  -*- Autoconf -*-
dnl Copyright (C) 2005-2008 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Bruno Haible, Sam Steingold

AC_DEFUN([CL_INTPARAM_CROSS],
[
  AC_REQUIRE([AC_TYPE_LONG_LONG_INT])
  AC_REQUIRE([AC_C_BIGENDIAN])
  cl_machine_file_h=$1
  {
    CL_INTPARAM_BITSIZE([signed char], [char_bitsize])
    CL_INTPARAM_BITSIZE([short], [short_bitsize])
    CL_INTPARAM_BITSIZE([int], [int_bitsize])
    CL_INTPARAM_BITSIZE([long], [long_bitsize])
    if test $ac_cv_type_long_long_int = yes; then
      CL_INTPARAM_BITSIZE([long long], [longlong_bitsize])
    fi
    CL_INTPARAM_BITSIZE([unsigned char], [uchar_bitsize])
    CL_INTPARAM_BITSIZE([unsigned short], [ushort_bitsize])
    CL_INTPARAM_BITSIZE([unsigned int], [uint_bitsize])
    CL_INTPARAM_BITSIZE([unsigned long], [ulong_bitsize])
    if test $ac_cv_type_long_long_int = yes; then
      CL_INTPARAM_BITSIZE([unsigned long long], [ulonglong_bitsize])
    fi
    if test -n "$char_bitsize"; then
      echo "/* Integers of type char have $char_bitsize bits. */"
      echo "#define char_bitsize $char_bitsize"
      echo
    else
      echo "#error \"Integers of type char have no binary representation!!\""
    fi
    if test -n "$short_bitsize"; then
      echo "/* Integers of type short have $short_bitsize bits. */"
      echo "#define short_bitsize $short_bitsize"
      echo
    else
      echo "#error \"Integers of type short have no binary representation!!\""
    fi
    if test -n "$int_bitsize"; then
      echo "/* Integers of type int have $int_bitsize bits. */"
      echo "#define int_bitsize $int_bitsize"
      echo
    else
      echo "#error \"Integers of type int have no binary representation!!\""
    fi
    if test -n "$long_bitsize"; then
      echo "/* Integers of type long have $long_bitsize bits. */"
      echo "#define long_bitsize $long_bitsize"
      echo
    else
      echo "#error \"Integers of type long have no binary representation!!\""
    fi
    if test $ac_cv_type_long_long_int = yes; then
      if test -n "$longlong_bitsize"; then
        echo "/* Integers of type long long have $longlong_bitsize bits. */"
        echo "#define long_long_bitsize $longlong_bitsize"
        echo
      else
        echo "#error \"Integers of type long long have no binary representation!!\""
      fi
    fi
    if test -n "$uchar_bitsize"; then
      echo "/* Integers of type unsigned char have $uchar_bitsize bits. */"
      echo
    else
      echo "#error \"Integers of type unsigned char have no binary representation!!\""
    fi
    if test -n "$ushort_bitsize"; then
      echo "/* Integers of type unsigned short have $ushort_bitsize bits. */"
      echo
    else
      echo "#error \"Integers of type unsigned short have no binary representation!!\""
    fi
    if test -n "$uint_bitsize"; then
      echo "/* Integers of type unsigned int have $uint_bitsize bits. */"
      echo
    else
      echo "#error \"Integers of type unsigned int have no binary representation!!\""
    fi
    if test -n "$ulong_bitsize"; then
      echo "/* Integers of type unsigned long have $ulong_bitsize bits. */"
      echo
    else
      echo "#error \"Integers of type unsigned long have no binary representation!!\""
    fi
    if test $ac_cv_type_long_long_int = yes; then
      if test -n "$ulonglong_bitsize"; then
        echo "/* Integers of type unsigned long long have $ulonglong_bitsize bits. */"
        echo
      else
        echo "#error \"Integers of type unsigned long long have no binary representation!!\""
      fi
    fi
    if test "$char_bitsize" != "$uchar_bitsize"; then
      echo "#error \"Integer types char and unsigned char have different sizes!!\""
    fi
    if test "$short_bitsize" != "$ushort_bitsize"; then
      echo "#error \"Integer types short and unsigned short have different sizes!!\""
    fi
    if test "$int_bitsize" != "$uint_bitsize"; then
      echo "#error \"Integer types int and unsigned int have different sizes!!\""
    fi
    if test "$long_bitsize" != "$ulong_bitsize"; then
      echo "#error \"Integer types long and unsigned long have different sizes!!\""
    fi
    if test $ac_cv_type_long_long_int = yes; then
      if test "$longlong_bitsize" != "$ulonglong_bitsize"; then
        echo "#error \"Integer types long long and unsigned long long have different sizes!!\""
      fi
    fi
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
      [[typedef int verify[2*(sizeof(char*)<=sizeof (long))-1];]])],
      [], [echo "#error \"Type char * does not fit into a long!!\""])
    _AC_COMPUTE_INT([sizeof (char *)], [pointer_size])
    pointer_bitsize=`expr $pointer_size '*' $char_bitsize`
    echo "/* Pointers of type char * have $pointer_bitsize bits. */"
    echo "#define pointer_bitsize $pointer_bitsize"
    echo
    CL_INTPARAM_SIZEOF([char], [sizeof_char])
    CL_INTPARAM_ALIGNOF([char], [alignment_char])
    echo "/* Type char has sizeof = $sizeof_char and alignment = $alignment_char. */"
    echo "#define sizeof_char $sizeof_char"
    echo "#define alignment_char $alignment_char"
    echo
    CL_INTPARAM_SIZEOF([unsigned char], [sizeof_uchar])
    CL_INTPARAM_ALIGNOF([unsigned char], [alignment_uchar])
    echo "/* Type unsigned char has sizeof = $sizeof_uchar and alignment = $alignment_uchar. */"
    echo
    CL_INTPARAM_SIZEOF([short], [sizeof_short])
    CL_INTPARAM_ALIGNOF([short], [alignment_short])
    echo "/* Type short has sizeof = $sizeof_short and alignment = $alignment_short. */"
    echo "#define sizeof_short $sizeof_short"
    echo "#define alignment_short $alignment_short"
    echo
    CL_INTPARAM_SIZEOF([unsigned short], [sizeof_ushort])
    CL_INTPARAM_ALIGNOF([unsigned short], [alignment_ushort])
    echo "/* Type unsigned short has sizeof = $sizeof_ushort and alignment = $alignment_ushort. */"
    echo
    CL_INTPARAM_SIZEOF([int], [sizeof_int])
    CL_INTPARAM_ALIGNOF([int], [alignment_int])
    echo "/* Type int has sizeof = $sizeof_int and alignment = $alignment_int. */"
    echo "#define sizeof_int $sizeof_int"
    echo "#define alignment_int $alignment_int"
    echo
    CL_INTPARAM_SIZEOF([unsigned int], [sizeof_uint])
    CL_INTPARAM_ALIGNOF([unsigned int], [alignment_uint])
    echo "/* Type unsigned int has sizeof = $sizeof_uint and alignment = $alignment_uint. */"
    echo
    CL_INTPARAM_SIZEOF([long], [sizeof_long])
    CL_INTPARAM_ALIGNOF([long], [alignment_long])
    echo "/* Type long has sizeof = $sizeof_long and alignment = $alignment_long. */"
    echo "#define sizeof_long $sizeof_long"
    echo "#define alignment_long $alignment_long"
    echo
    CL_INTPARAM_SIZEOF([unsigned long], [sizeof_ulong])
    CL_INTPARAM_ALIGNOF([unsigned long], [alignment_ulong])
    echo "/* Type unsigned long has sizeof = $sizeof_ulong and alignment = $alignment_ulong. */"
    echo
    if test $ac_cv_type_long_long_int = yes; then
      CL_INTPARAM_SIZEOF([long long], [sizeof_longlong])
      CL_INTPARAM_ALIGNOF([long long], [alignment_longlong])
      echo "/* Type long long has sizeof = $sizeof_longlong and alignment = $alignment_longlong. */"
      echo "#define sizeof_long_long $sizeof_longlong"
      echo "#define alignment_long_long $alignment_longlong"
      echo
      CL_INTPARAM_SIZEOF([unsigned long long], [sizeof_ulonglong])
      CL_INTPARAM_ALIGNOF([unsigned long long], [alignment_ulonglong])
      echo "/* Type unsigned long long has sizeof = $sizeof_ulonglong and alignment = $alignment_ulonglong. */"
      echo
    fi
    CL_INTPARAM_SIZEOF([float], [sizeof_float])
    CL_INTPARAM_ALIGNOF([float], [alignment_float])
    echo "/* Type float has sizeof = $sizeof_float and alignment = $alignment_float. */"
    echo "#define sizeof_float $sizeof_float"
    echo "#define alignment_float $alignment_float"
    echo
    CL_INTPARAM_SIZEOF([double], [sizeof_double])
    CL_INTPARAM_ALIGNOF([double], [alignment_double])
    echo "/* Type double has sizeof = $sizeof_double and alignment = $alignment_double. */"
    echo "#define sizeof_double $sizeof_double"
    echo "#define alignment_double $alignment_double"
    echo
    CL_INTPARAM_SIZEOF([long double], [sizeof_longdouble])
    CL_INTPARAM_ALIGNOF([long double], [alignment_longdouble])
    echo "/* Type long double has sizeof = $sizeof_longdouble and alignment = $alignment_longdouble. */"
    echo "#define sizeof_long_double $sizeof_longdouble"
    echo "#define alignment_long_double $alignment_longdouble"
    echo
    CL_INTPARAM_SIZEOF([char *], [sizeof_char_ptr])
    CL_INTPARAM_ALIGNOF([char *], [alignment_char_ptr])
    echo "/* Type char * has sizeof = $sizeof_char_ptr and alignment = $alignment_char_ptr. */"
    echo
    CL_INTPARAM_SIZEOF([long *], [sizeof_long_ptr])
    CL_INTPARAM_ALIGNOF([long *], [alignment_long_ptr])
    echo "/* Type long * has sizeof = $sizeof_long_ptr and alignment = $alignment_long_ptr. */"
    echo
    dnl disabled because:
    dnl - the results of these are not used anywhere
    dnl - the results of non-cross are not generated (see src/intparam.h)
    dnl - the C code fails with "expected identifier or '(' before ')' token"
    dnl   on the line "typedef int verify[2*(alignof(void (*)(void)) == 256) - 1];"
    dnl CL_INTPARAM_SIZEOF([void (*)(void)], [sizeof_function_ptr])
    dnl CL_INTPARAM_ALIGNOF([void (*)(void)], [alignment_function_ptr])
    echo "/* Type function * has sizeof = $sizeof_function_ptr and alignment = $alignment_function_ptr. */"
    echo
    case $ac_cv_c_bigendian in
      yes)
        echo "/* Type unsigned short is stored BIG-ENDIAN in memory (i.e. like mc68000 or sparc). */"
        echo "#define short_big_endian"
        echo "/* Type unsigned int is stored BIG-ENDIAN in memory (i.e. like mc68000 or sparc). */"
        echo "#define int_big_endian"
        echo "/* Type unsigned long is stored BIG-ENDIAN in memory (i.e. like mc68000 or sparc). */"
        echo "#define long_big_endian"
        if test $ac_cv_type_long_long_int = yes; then
          echo "/* Type unsigned long long is stored BIG-ENDIAN in memory (i.e. like mc68000 or sparc). */"
          echo "#define long_long_big_endian"
        fi
        ;;
      no)
        echo "/* Type unsigned short is stored LITTLE-ENDIAN in memory (i.e. like Z80 or VAX). */"
        echo "#define short_little_endian"
        echo "/* Type unsigned int is stored LITTLE-ENDIAN in memory (i.e. like Z80 or VAX). */"
        echo "#define int_little_endian"
        echo "/* Type unsigned long is stored LITTLE-ENDIAN in memory (i.e. like Z80 or VAX). */"
        echo "#define long_little_endian"
        if test $ac_cv_type_long_long_int = yes; then
          echo "/* Type unsigned long long is stored LITTLE-ENDIAN in memory (i.e. like Z80 or VAX). */"
          echo "#define long_long_little_endian"
        fi
        ;;
      *)
        echo "#error \"Type short is stored in memory in an obscure manner!!\""
        echo "#error \"Type int is stored in memory in an obscure manner!!\""
        echo "#error \"Type long is stored in memory in an obscure manner!!\""
        if test $ac_cv_type_long_long_int = yes; then
          echo "#error \"Type long long is stored in memory in an obscure manner!!\""
        fi
        ;;
    esac
    echo
    case $host_cpu in
      hppa)
        echo "/* Stack grows up. */"
        echo "#define stack_grows_up"
        ;;
      *)
        echo "/* Stack grows down. */"
        echo "#define stack_grows_down"
        ;;
    esac
  } > "$cl_machine_file_h"
])

dnl CL_INTPARAM_BITSIZE(type, variable)
dnl puts into variable the determined bitsize of the type.
AC_DEFUN([CL_INTPARAM_BITSIZE],
[
  n=1; x="($1)2"
  while true; do
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],
      [[typedef int verify[2*(($1)($x) == 0) - 1];]])],
      [$2=$n; break;],
      [if test $n = 1000; then $2=; break; fi;])
    n=`expr $n + 1`; x="$x * ($1)2"
  done
])

dnl CL_INTPARAM_SIZEOF(type, variable)
dnl puts into variable the determined size of the type.
AC_DEFUN([CL_INTPARAM_SIZEOF],
[
  _AC_COMPUTE_INT([sizeof($1)], [$2])
])

dnl CL_INTPARAM_ALIGNOF(type, variable)
dnl puts into variable the determined alignment of the type.
AC_DEFUN([CL_INTPARAM_ALIGNOF],[
  dnl Simplify the guessing by assuming that the alignment is a power of 2.
  n=1
  while true; do
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stddef.h>
#ifdef __cplusplus
# ifdef __GNUC__
#  define alignof(type)  __alignof__ (type)
# else
   template <class type> struct alignof_helper { char slot1; type slot2; };
#  define alignof(type)  offsetof (alignof_helper<type>, slot2)
# endif
#else
# define alignof(type)  offsetof (struct { char slot1; type slot2; }, slot2)
#endif
]], [[typedef int verify[2*(alignof($1) == $n) - 1];]])],
      [$2=$n; break;]
      [if test $n = 0; then $2=; break; fi])
    n=`expr $n '*' 2`
  done
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2004, 2007-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_IOCTL],
[AC_REQUIRE([CL_TERM])dnl
AC_REQUIRE([CL_CADDR_T])dnl
AC_CHECK_FUNCS(ioctl)
if test $ac_cv_func_ioctl = yes; then
ioctl_decl1='
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif
#ifndef HAVE_TCSAFLUSH
#undef HAVE_TERMIOS_H
#endif
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#else
#ifdef HAVE_SYS_TERMIO_H
#include <sys/termio.h>
#else
#ifdef HAVE_TERMIO_H
#include <termio.h>
#else
#ifdef HAVE_SGTTY_H
#include <sgtty.h>
#include <sys/ioctl.h>
#endif
#endif
#endif
#endif
'
CL_PROTO([ioctl], [
dnl First find out whether this set of includes declares ioctl(), or whether
dnl we shall use <sys/ioctl.h> instead.
dnl Note: we must not include <sys/ioctl.h> deliberately since it is
dnl incompatible to <termios.h> (and doesn't even declare ioctl()) on SunOS 4.
AC_TRY_COMPILE($ioctl_decl1
AC_LANG_EXTERN[char* ioctl();], [], try_sys_ioctl=1, ioctl_decl="$ioctl_decl1")
if test -n "try_sys_ioctl"; then
ioctl_decl2='
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif
#include <sys/ioctl.h>
'
AC_TRY_COMPILE($ioctl_decl2
AC_LANG_EXTERN[char* ioctl();], [],
ioctl_decl="$ioctl_decl1", ioctl_decl="$ioctl_decl2")
fi
dnl Then find out about the correct ioctl declaration:
for y in 'caddr_t arg' 'void* arg' '...'; do
for x in SIZE_VARIANTS; do
if test -z "$have_ioctl"; then
CL_PROTO_TRY($ioctl_decl[
#ifdef INCLUDE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
], [int ioctl (int fd, $x request, $y);], [
cl_cv_proto_ioctl_arg2="$x"
if test "$y" = "..."; then
cl_cv_proto_ioctl_dots=yes
cl_cv_proto_ioctl_args="int, $cl_cv_proto_ioctl_arg2, ..."
else
cl_cv_proto_ioctl_dots=no
cl_cv_proto_ioctl_arg3=`echo "$y" | sed -e 's, arg,,'`
cl_cv_proto_ioctl_args="int, $cl_cv_proto_ioctl_arg2, $cl_cv_proto_ioctl_arg3"
fi
have_ioctl=1])
fi
done
done
if test -z "$have_ioctl"; then
CL_PROTO_MISSING(ioctl)
fi
], [extern int ioctl ($cl_cv_proto_ioctl_args);])
AC_DEFINE_UNQUOTED(IOCTL_REQUEST_T,$cl_cv_proto_ioctl_arg2,[type of `request' in ioctl() declaration])
if test $cl_cv_proto_ioctl_dots = yes; then
AC_DEFINE(IOCTL_DOTS,,[declaration of ioctl() needs dots])
else
AC_DEFINE_UNQUOTED(IOCTL_ARGUMENT_T,$cl_cv_proto_ioctl_arg3,[type of `argument' in ioctl() declaration, if not superseded by dots])
fi
ioctl_decl="$ioctl_decl1"
ioctl_prog='int x = FIONREAD;'
CL_COMPILE_CHECK([FIONREAD], cl_cv_decl_FIONREAD_1,
$ioctl_decl, $ioctl_prog, ioctl_ok=1)dnl
if test -z "$ioctl_ok"; then
CL_COMPILE_CHECK([FIONREAD in sys/filio.h], cl_cv_decl_FIONREAD_1_sys_filio_h,
$ioctl_decl[#include <sys/filio.h>], $ioctl_prog,
AC_DEFINE(NEED_SYS_FILIO_H,,[need <sys/filio.h> for using ioctl() FIONREAD])
ioctl_ok=1)dnl
fi
if test -z "$ioctl_ok"; then
CL_COMPILE_CHECK([FIONREAD in sys/ioctl.h], cl_cv_decl_FIONREAD_1_sys_ioctl_h,
$ioctl_decl[#include <sys/ioctl.h>], $ioctl_prog,
AC_DEFINE(NEED_SYS_IOCTL_H,,[need <sys/ioctl.h> for using ioctl() FIONREAD])
ioctl_ok=1)dnl
fi
if test -n "$ioctl_ok"; then
AC_DEFINE(HAVE_FIONREAD,,[have the FIONREAD ioctl()])
# Now check whether FIONREAD reliably checks for the EOF of a regular file.
# The number of available characters returned by ioctl(fd,FIONREAD,...) should
# be > 0 for a non-empty regular file at least. On Solaris 2, it is 0.
AC_CACHE_CHECK(for reliable FIONREAD, cl_cv_decl_FIONREAD_reliable, [
AC_TRY_RUN([
/* Declare ioctl(). */
]$ioctl_decl[
#ifdef NEED_SYS_FILIO_H
#include <sys/filio.h>
#endif
#ifdef NEED_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
/* Declare open(). */
#include <fcntl.h>
int main ()
{ int fd = open("conftest.c",O_RDONLY,0644);
  unsigned long bytes_ready;
  /* Clear bytes_ready before use. Some kernels (such as Linux-2.4.18 on ia64)
     apparently expect an 'int *', not a 'long *', as argument of this ioctl,
     and thus fill only part of the bytes_ready variable. Fortunately,
     endianness is not a problem here, because we only check whether
     bytes_ready is == 0 or != 0. */
  bytes_ready = 0;
  exit(!((fd >= 0) && (ioctl(fd,FIONREAD,&bytes_ready) >= 0) && (bytes_ready > 0)));
}],
cl_cv_decl_FIONREAD_reliable=yes, cl_cv_decl_FIONREAD_reliable=no,
dnl When cross-compiling, don't assume anything.
cl_cv_decl_FIONREAD_reliable="guessing no")
])
case "$cl_cv_decl_FIONREAD_reliable" in
  *yes) AC_DEFINE(HAVE_RELIABLE_FIONREAD,,[have the FIONREAD ioctl() and it works reliably on files]) ;;
  *no) ;;
esac
fi
fi
])

# libtool.m4 - Configure libtool for the host system. -*-Autoconf-*-
#
#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
#                 2006, 2007, 2008, 2009, 2010 Free Software Foundation,
#                 Inc.
#   Written by Gordon Matzigkeit, 1996
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

m4_define([_LT_COPYING], [dnl
#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
#                 2006, 2007, 2008, 2009, 2010 Free Software Foundation,
#                 Inc.
#   Written by Gordon Matzigkeit, 1996
#
#   This file is part of GNU Libtool.
#
# GNU Libtool is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# As a special exception to the GNU General Public License,
# if you distribute this file as part of a program or library that
# is built using GNU Libtool, you may include this file under the
# same distribution terms that you use for the rest of that program.
#
# GNU Libtool is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Libtool; see the file COPYING.  If not, a copy
# can be downloaded from http://www.gnu.org/licenses/gpl.html, or
# obtained by writing to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
])

# serial 57 LT_INIT


# LT_PREREQ(VERSION)
# ------------------
# Complain and exit if this libtool version is less that VERSION.
m4_defun([LT_PREREQ],
[m4_if(m4_version_compare(m4_defn([LT_PACKAGE_VERSION]), [$1]), -1,
       [m4_default([$3],
		   [m4_fatal([Libtool version $1 or higher is required],
		             63)])],
       [$2])])


# _LT_CHECK_BUILDDIR
# ------------------
# Complain if the absolute build directory name contains unusual characters
m4_defun([_LT_CHECK_BUILDDIR],
[case `pwd` in
  *\ * | *\	*)
    AC_MSG_WARN([Libtool does not cope well with whitespace in `pwd`]) ;;
esac
])


# LT_INIT([OPTIONS])
# ------------------
AC_DEFUN([LT_INIT],
[AC_PREREQ([2.58])dnl We use AC_INCLUDES_DEFAULT
AC_REQUIRE([AC_CONFIG_AUX_DIR_DEFAULT])dnl
AC_BEFORE([$0], [LT_LANG])dnl
AC_BEFORE([$0], [LT_OUTPUT])dnl
AC_BEFORE([$0], [LTDL_INIT])dnl
m4_require([_LT_CHECK_BUILDDIR])dnl

dnl Autoconf doesn't catch unexpanded LT_ macros by default:
m4_pattern_forbid([^_?LT_[A-Z_]+$])dnl
m4_pattern_allow([^(_LT_EOF|LT_DLGLOBAL|LT_DLLAZY_OR_NOW|LT_MULTI_MODULE)$])dnl
dnl aclocal doesn't pull ltoptions.m4, ltsugar.m4, or ltversion.m4
dnl unless we require an AC_DEFUNed macro:
AC_REQUIRE([LTOPTIONS_VERSION])dnl
AC_REQUIRE([LTSUGAR_VERSION])dnl
AC_REQUIRE([LTVERSION_VERSION])dnl
AC_REQUIRE([LTOBSOLETE_VERSION])dnl
m4_require([_LT_PROG_LTMAIN])dnl

_LT_SHELL_INIT([SHELL=${CONFIG_SHELL-/bin/sh}])

dnl Parse OPTIONS
_LT_SET_OPTIONS([$0], [$1])

# This can be used to rebuild libtool when needed
LIBTOOL_DEPS="$ltmain"

# Always use our own libtool.
LIBTOOL='$(SHELL) $(top_builddir)/libtool'
AC_SUBST(LIBTOOL)dnl

_LT_SETUP

# Only expand once:
m4_define([LT_INIT])
])# LT_INIT

# Old names:
AU_ALIAS([AC_PROG_LIBTOOL], [LT_INIT])
AU_ALIAS([AM_PROG_LIBTOOL], [LT_INIT])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_PROG_LIBTOOL], [])
dnl AC_DEFUN([AM_PROG_LIBTOOL], [])


# _LT_CC_BASENAME(CC)
# -------------------
# Calculate cc_basename.  Skip known compiler wrappers and cross-prefix.
m4_defun([_LT_CC_BASENAME],
[for cc_temp in $1""; do
  case $cc_temp in
    compile | *[[\\/]]compile | ccache | *[[\\/]]ccache ) ;;
    distcc | *[[\\/]]distcc | purify | *[[\\/]]purify ) ;;
    \-*) ;;
    *) break;;
  esac
done
cc_basename=`$ECHO "$cc_temp" | $SED "s%.*/%%; s%^$host_alias-%%"`
])


# _LT_FILEUTILS_DEFAULTS
# ----------------------
# It is okay to use these file commands and assume they have been set
# sensibly after `m4_require([_LT_FILEUTILS_DEFAULTS])'.
m4_defun([_LT_FILEUTILS_DEFAULTS],
[: ${CP="cp -f"}
: ${MV="mv -f"}
: ${RM="rm -f"}
])# _LT_FILEUTILS_DEFAULTS


# _LT_SETUP
# ---------
m4_defun([_LT_SETUP],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_CANONICAL_BUILD])dnl
AC_REQUIRE([_LT_PREPARE_SED_QUOTE_VARS])dnl
AC_REQUIRE([_LT_PROG_ECHO_BACKSLASH])dnl

_LT_DECL([], [host_alias], [0], [The host system])dnl
_LT_DECL([], [host], [0])dnl
_LT_DECL([], [host_os], [0])dnl
dnl
_LT_DECL([], [build_alias], [0], [The build system])dnl
_LT_DECL([], [build], [0])dnl
_LT_DECL([], [build_os], [0])dnl
dnl
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([LT_PATH_LD])dnl
AC_REQUIRE([LT_PATH_NM])dnl
dnl
AC_REQUIRE([AC_PROG_LN_S])dnl
test -z "$LN_S" && LN_S="ln -s"
_LT_DECL([], [LN_S], [1], [Whether we need soft or hard links])dnl
dnl
AC_REQUIRE([LT_CMD_MAX_LEN])dnl
_LT_DECL([objext], [ac_objext], [0], [Object file suffix (normally "o")])dnl
_LT_DECL([], [exeext], [0], [Executable file suffix (normally "")])dnl
dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_CHECK_SHELL_FEATURES])dnl
m4_require([_LT_CMD_RELOAD])dnl
m4_require([_LT_CHECK_MAGIC_METHOD])dnl
m4_require([_LT_CMD_OLD_ARCHIVE])dnl
m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl

_LT_CONFIG_LIBTOOL_INIT([
# See if we are running on zsh, and set the options which allow our
# commands through without removal of \ escapes INIT.
if test -n "\${ZSH_VERSION+set}" ; then
   setopt NO_GLOB_SUBST
fi
])
if test -n "${ZSH_VERSION+set}" ; then
   setopt NO_GLOB_SUBST
fi

_LT_CHECK_OBJDIR

m4_require([_LT_TAG_COMPILER])dnl

case $host_os in
aix3*)
  # AIX sometimes has problems with the GCC collect2 program.  For some
  # reason, if we set the COLLECT_NAMES environment variable, the problems
  # vanish in a puff of smoke.
  if test "X${COLLECT_NAMES+set}" != Xset; then
    COLLECT_NAMES=
    export COLLECT_NAMES
  fi
  ;;
esac

# Global variables:
ofile=libtool
can_build_shared=yes

# All known linkers require a `.a' archive for static linking (except MSVC,
# which needs '.lib').
libext=a

with_gnu_ld="$lt_cv_prog_gnu_ld"

old_CC="$CC"
old_CFLAGS="$CFLAGS"

# Set sane defaults for various variables
test -z "$CC" && CC=cc
test -z "$LTCC" && LTCC=$CC
test -z "$LTCFLAGS" && LTCFLAGS=$CFLAGS
test -z "$LD" && LD=ld
test -z "$ac_objext" && ac_objext=o

_LT_CC_BASENAME([$compiler])

# Only perform the check for file, if the check method requires it
test -z "$MAGIC_CMD" && MAGIC_CMD=file
case $deplibs_check_method in
file_magic*)
  if test "$file_magic_cmd" = '$MAGIC_CMD'; then
    _LT_PATH_MAGIC
  fi
  ;;
esac

# Use C for the default configuration in the libtool script
LT_SUPPORTED_TAG([CC])
_LT_LANG_C_CONFIG
_LT_LANG_DEFAULT_CONFIG
_LT_CONFIG_COMMANDS
])# _LT_SETUP


# _LT_PREPARE_SED_QUOTE_VARS
# --------------------------
# Define a few sed substitution that help us do robust quoting.
m4_defun([_LT_PREPARE_SED_QUOTE_VARS],
[# Backslashify metacharacters that are still active within
# double-quoted strings.
sed_quote_subst='s/\([["`$\\]]\)/\\\1/g'

# Same as above, but do not quote variable references.
double_quote_subst='s/\([["`\\]]\)/\\\1/g'

# Sed substitution to delay expansion of an escaped shell variable in a
# double_quote_subst'ed string.
delay_variable_subst='s/\\\\\\\\\\\$/\\\\\\$/g'

# Sed substitution to delay expansion of an escaped single quote.
delay_single_quote_subst='s/'\''/'\'\\\\\\\'\''/g'

# Sed substitution to avoid accidental globbing in evaled expressions
no_glob_subst='s/\*/\\\*/g'
])

# _LT_PROG_LTMAIN
# ---------------
# Note that this code is called both from `configure', and `config.status'
# now that we use AC_CONFIG_COMMANDS to generate libtool.  Notably,
# `config.status' has no value for ac_aux_dir unless we are using Automake,
# so we pass a copy along to make sure it has a sensible value anyway.
m4_defun([_LT_PROG_LTMAIN],
[m4_ifdef([AC_REQUIRE_AUX_FILE], [AC_REQUIRE_AUX_FILE([ltmain.sh])])dnl
_LT_CONFIG_LIBTOOL_INIT([ac_aux_dir='$ac_aux_dir'])
ltmain="$ac_aux_dir/ltmain.sh"
])# _LT_PROG_LTMAIN



# So that we can recreate a full libtool script including additional
# tags, we accumulate the chunks of code to send to AC_CONFIG_COMMANDS
# in macros and then make a single call at the end using the `libtool'
# label.


# _LT_CONFIG_LIBTOOL_INIT([INIT-COMMANDS])
# ----------------------------------------
# Register INIT-COMMANDS to be passed to AC_CONFIG_COMMANDS later.
m4_define([_LT_CONFIG_LIBTOOL_INIT],
[m4_ifval([$1],
          [m4_append([_LT_OUTPUT_LIBTOOL_INIT],
                     [$1
])])])

# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_INIT])


# _LT_CONFIG_LIBTOOL([COMMANDS])
# ------------------------------
# Register COMMANDS to be passed to AC_CONFIG_COMMANDS later.
m4_define([_LT_CONFIG_LIBTOOL],
[m4_ifval([$1],
          [m4_append([_LT_OUTPUT_LIBTOOL_COMMANDS],
                     [$1
])])])

# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS])


# _LT_CONFIG_SAVE_COMMANDS([COMMANDS], [INIT_COMMANDS])
# -----------------------------------------------------
m4_defun([_LT_CONFIG_SAVE_COMMANDS],
[_LT_CONFIG_LIBTOOL([$1])
_LT_CONFIG_LIBTOOL_INIT([$2])
])


# _LT_FORMAT_COMMENT([COMMENT])
# -----------------------------
# Add leading comment marks to the start of each line, and a trailing
# full-stop to the whole comment if one is not present already.
m4_define([_LT_FORMAT_COMMENT],
[m4_ifval([$1], [
m4_bpatsubst([m4_bpatsubst([$1], [^ *], [# ])],
              [['`$\]], [\\\&])]m4_bmatch([$1], [[!?.]$], [], [.])
)])





# _LT_DECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION], [IS-TAGGED?])
# -------------------------------------------------------------------
# CONFIGNAME is the name given to the value in the libtool script.
# VARNAME is the (base) name used in the configure script.
# VALUE may be 0, 1 or 2 for a computed quote escaped value based on
# VARNAME.  Any other value will be used directly.
m4_define([_LT_DECL],
[lt_if_append_uniq([lt_decl_varnames], [$2], [, ],
    [lt_dict_add_subkey([lt_decl_dict], [$2], [libtool_name],
	[m4_ifval([$1], [$1], [$2])])
    lt_dict_add_subkey([lt_decl_dict], [$2], [value], [$3])
    m4_ifval([$4],
	[lt_dict_add_subkey([lt_decl_dict], [$2], [description], [$4])])
    lt_dict_add_subkey([lt_decl_dict], [$2],
	[tagged?], [m4_ifval([$5], [yes], [no])])])
])


# _LT_TAGDECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION])
# --------------------------------------------------------
m4_define([_LT_TAGDECL], [_LT_DECL([$1], [$2], [$3], [$4], [yes])])


# lt_decl_tag_varnames([SEPARATOR], [VARNAME1...])
# ------------------------------------------------
m4_define([lt_decl_tag_varnames],
[_lt_decl_filter([tagged?], [yes], $@)])


# _lt_decl_filter(SUBKEY, VALUE, [SEPARATOR], [VARNAME1..])
# ---------------------------------------------------------
m4_define([_lt_decl_filter],
[m4_case([$#],
  [0], [m4_fatal([$0: too few arguments: $#])],
  [1], [m4_fatal([$0: too few arguments: $#: $1])],
  [2], [lt_dict_filter([lt_decl_dict], [$1], [$2], [], lt_decl_varnames)],
  [3], [lt_dict_filter([lt_decl_dict], [$1], [$2], [$3], lt_decl_varnames)],
  [lt_dict_filter([lt_decl_dict], $@)])[]dnl
])


# lt_decl_quote_varnames([SEPARATOR], [VARNAME1...])
# --------------------------------------------------
m4_define([lt_decl_quote_varnames],
[_lt_decl_filter([value], [1], $@)])


# lt_decl_dquote_varnames([SEPARATOR], [VARNAME1...])
# ---------------------------------------------------
m4_define([lt_decl_dquote_varnames],
[_lt_decl_filter([value], [2], $@)])


# lt_decl_varnames_tagged([SEPARATOR], [VARNAME1...])
# ---------------------------------------------------
m4_define([lt_decl_varnames_tagged],
[m4_assert([$# <= 2])dnl
_$0(m4_quote(m4_default([$1], [[, ]])),
    m4_ifval([$2], [[$2]], [m4_dquote(lt_decl_tag_varnames)]),
    m4_split(m4_normalize(m4_quote(_LT_TAGS)), [ ]))])
m4_define([_lt_decl_varnames_tagged],
[m4_ifval([$3], [lt_combine([$1], [$2], [_], $3)])])


# lt_decl_all_varnames([SEPARATOR], [VARNAME1...])
# ------------------------------------------------
m4_define([lt_decl_all_varnames],
[_$0(m4_quote(m4_default([$1], [[, ]])),
     m4_if([$2], [],
	   m4_quote(lt_decl_varnames),
	m4_quote(m4_shift($@))))[]dnl
])
m4_define([_lt_decl_all_varnames],
[lt_join($@, lt_decl_varnames_tagged([$1],
			lt_decl_tag_varnames([[, ]], m4_shift($@))))dnl
])


# _LT_CONFIG_STATUS_DECLARE([VARNAME])
# ------------------------------------
# Quote a variable value, and forward it to `config.status' so that its
# declaration there will have the same value as in `configure'.  VARNAME
# must have a single quote delimited value for this to work.
m4_define([_LT_CONFIG_STATUS_DECLARE],
[$1='`$ECHO "$][$1" | $SED "$delay_single_quote_subst"`'])


# _LT_CONFIG_STATUS_DECLARATIONS
# ------------------------------
# We delimit libtool config variables with single quotes, so when
# we write them to config.status, we have to be sure to quote all
# embedded single quotes properly.  In configure, this macro expands
# each variable declared with _LT_DECL (and _LT_TAGDECL) into:
#
#    <var>='`$ECHO "$<var>" | $SED "$delay_single_quote_subst"`'
m4_defun([_LT_CONFIG_STATUS_DECLARATIONS],
[m4_foreach([_lt_var], m4_quote(lt_decl_all_varnames),
    [m4_n([_LT_CONFIG_STATUS_DECLARE(_lt_var)])])])


# _LT_LIBTOOL_TAGS
# ----------------
# Output comment and list of tags supported by the script
m4_defun([_LT_LIBTOOL_TAGS],
[_LT_FORMAT_COMMENT([The names of the tagged configurations supported by this script])dnl
available_tags="_LT_TAGS"dnl
])


# _LT_LIBTOOL_DECLARE(VARNAME, [TAG])
# -----------------------------------
# Extract the dictionary values for VARNAME (optionally with TAG) and
# expand to a commented shell variable setting:
#
#    # Some comment about what VAR is for.
#    visible_name=$lt_internal_name
m4_define([_LT_LIBTOOL_DECLARE],
[_LT_FORMAT_COMMENT(m4_quote(lt_dict_fetch([lt_decl_dict], [$1],
					   [description])))[]dnl
m4_pushdef([_libtool_name],
    m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [libtool_name])))[]dnl
m4_case(m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [value])),
    [0], [_libtool_name=[$]$1],
    [1], [_libtool_name=$lt_[]$1],
    [2], [_libtool_name=$lt_[]$1],
    [_libtool_name=lt_dict_fetch([lt_decl_dict], [$1], [value])])[]dnl
m4_ifval([$2], [_$2])[]m4_popdef([_libtool_name])[]dnl
])


# _LT_LIBTOOL_CONFIG_VARS
# -----------------------
# Produce commented declarations of non-tagged libtool config variables
# suitable for insertion in the LIBTOOL CONFIG section of the `libtool'
# script.  Tagged libtool config variables (even for the LIBTOOL CONFIG
# section) are produced by _LT_LIBTOOL_TAG_VARS.
m4_defun([_LT_LIBTOOL_CONFIG_VARS],
[m4_foreach([_lt_var],
    m4_quote(_lt_decl_filter([tagged?], [no], [], lt_decl_varnames)),
    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var)])])])


# _LT_LIBTOOL_TAG_VARS(TAG)
# -------------------------
m4_define([_LT_LIBTOOL_TAG_VARS],
[m4_foreach([_lt_var], m4_quote(lt_decl_tag_varnames),
    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var, [$1])])])])


# _LT_TAGVAR(VARNAME, [TAGNAME])
# ------------------------------
m4_define([_LT_TAGVAR], [m4_ifval([$2], [$1_$2], [$1])])


# _LT_CONFIG_COMMANDS
# -------------------
# Send accumulated output to $CONFIG_STATUS.  Thanks to the lists of
# variables for single and double quote escaping we saved from calls
# to _LT_DECL, we can put quote escaped variables declarations
# into `config.status', and then the shell code to quote escape them in
# for loops in `config.status'.  Finally, any additional code accumulated
# from calls to _LT_CONFIG_LIBTOOL_INIT is expanded.
m4_defun([_LT_CONFIG_COMMANDS],
[AC_PROVIDE_IFELSE([LT_OUTPUT],
	dnl If the libtool generation code has been placed in $CONFIG_LT,
	dnl instead of duplicating it all over again into config.status,
	dnl then we will have config.status run $CONFIG_LT later, so it
	dnl needs to know what name is stored there:
        [AC_CONFIG_COMMANDS([libtool],
            [$SHELL $CONFIG_LT || AS_EXIT(1)], [CONFIG_LT='$CONFIG_LT'])],
    dnl If the libtool generation code is destined for config.status,
    dnl expand the accumulated commands and init code now:
    [AC_CONFIG_COMMANDS([libtool],
        [_LT_OUTPUT_LIBTOOL_COMMANDS], [_LT_OUTPUT_LIBTOOL_COMMANDS_INIT])])
])#_LT_CONFIG_COMMANDS


# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS_INIT],
[

# The HP-UX ksh and POSIX shell print the target directory to stdout
# if CDPATH is set.
(unset CDPATH) >/dev/null 2>&1 && unset CDPATH

sed_quote_subst='$sed_quote_subst'
double_quote_subst='$double_quote_subst'
delay_variable_subst='$delay_variable_subst'
_LT_CONFIG_STATUS_DECLARATIONS
LTCC='$LTCC'
LTCFLAGS='$LTCFLAGS'
compiler='$compiler_DEFAULT'

# A function that is used when there is no print builtin or printf.
func_fallback_echo ()
{
  eval 'cat <<_LTECHO_EOF
\$[]1
_LTECHO_EOF'
}

# Quote evaled strings.
for var in lt_decl_all_varnames([[ \
]], lt_decl_quote_varnames); do
    case \`eval \\\\\$ECHO \\\\""\\\\\$\$var"\\\\"\` in
    *[[\\\\\\\`\\"\\\$]]*)
      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"\\\$\$var\\" | \\\$SED \\"\\\$sed_quote_subst\\"\\\`\\\\\\""
      ;;
    *)
      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
      ;;
    esac
done

# Double-quote double-evaled strings.
for var in lt_decl_all_varnames([[ \
]], lt_decl_dquote_varnames); do
    case \`eval \\\\\$ECHO \\\\""\\\\\$\$var"\\\\"\` in
    *[[\\\\\\\`\\"\\\$]]*)
      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"\\\$\$var\\" | \\\$SED -e \\"\\\$double_quote_subst\\" -e \\"\\\$sed_quote_subst\\" -e \\"\\\$delay_variable_subst\\"\\\`\\\\\\""
      ;;
    *)
      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
      ;;
    esac
done

_LT_OUTPUT_LIBTOOL_INIT
])

# _LT_GENERATED_FILE_INIT(FILE, [COMMENT])
# ------------------------------------
# Generate a child script FILE with all initialization necessary to
# reuse the environment learned by the parent script, and make the
# file executable.  If COMMENT is supplied, it is inserted after the
# `#!' sequence but before initialization text begins.  After this
# macro, additional text can be appended to FILE to form the body of
# the child script.  The macro ends with non-zero status if the
# file could not be fully written (such as if the disk is full).
m4_ifdef([AS_INIT_GENERATED],
[m4_defun([_LT_GENERATED_FILE_INIT],[AS_INIT_GENERATED($@)])],
[m4_defun([_LT_GENERATED_FILE_INIT],
[m4_require([AS_PREPARE])]dnl
[m4_pushdef([AS_MESSAGE_LOG_FD])]dnl
[lt_write_fail=0
cat >$1 <<_ASEOF || lt_write_fail=1
#! $SHELL
# Generated by $as_me.
$2
SHELL=\${CONFIG_SHELL-$SHELL}
export SHELL
_ASEOF
cat >>$1 <<\_ASEOF || lt_write_fail=1
AS_SHELL_SANITIZE
_AS_PREPARE
exec AS_MESSAGE_FD>&1
_ASEOF
test $lt_write_fail = 0 && chmod +x $1[]dnl
m4_popdef([AS_MESSAGE_LOG_FD])])])# _LT_GENERATED_FILE_INIT

# LT_OUTPUT
# ---------
# This macro allows early generation of the libtool script (before
# AC_OUTPUT is called), incase it is used in configure for compilation
# tests.
AC_DEFUN([LT_OUTPUT],
[: ${CONFIG_LT=./config.lt}
AC_MSG_NOTICE([creating $CONFIG_LT])
_LT_GENERATED_FILE_INIT(["$CONFIG_LT"],
[# Run this file to recreate a libtool stub with the current configuration.])

cat >>"$CONFIG_LT" <<\_LTEOF
lt_cl_silent=false
exec AS_MESSAGE_LOG_FD>>config.log
{
  echo
  AS_BOX([Running $as_me.])
} >&AS_MESSAGE_LOG_FD

lt_cl_help="\
\`$as_me' creates a local libtool stub from the current configuration,
for use in further configure time tests before the real libtool is
generated.

Usage: $[0] [[OPTIONS]]

  -h, --help      print this help, then exit
  -V, --version   print version number, then exit
  -q, --quiet     do not print progress messages
  -d, --debug     don't remove temporary files

Report bugs to <bug-libtool@gnu.org>."

lt_cl_version="\
m4_ifset([AC_PACKAGE_NAME], [AC_PACKAGE_NAME ])config.lt[]dnl
m4_ifset([AC_PACKAGE_VERSION], [ AC_PACKAGE_VERSION])
configured by $[0], generated by m4_PACKAGE_STRING.

Copyright (C) 2010 Free Software Foundation, Inc.
This config.lt script is free software; the Free Software Foundation
gives unlimited permision to copy, distribute and modify it."

while test $[#] != 0
do
  case $[1] in
    --version | --v* | -V )
      echo "$lt_cl_version"; exit 0 ;;
    --help | --h* | -h )
      echo "$lt_cl_help"; exit 0 ;;
    --debug | --d* | -d )
      debug=: ;;
    --quiet | --q* | --silent | --s* | -q )
      lt_cl_silent=: ;;

    -*) AC_MSG_ERROR([unrecognized option: $[1]
Try \`$[0] --help' for more information.]) ;;

    *) AC_MSG_ERROR([unrecognized argument: $[1]
Try \`$[0] --help' for more information.]) ;;
  esac
  shift
done

if $lt_cl_silent; then
  exec AS_MESSAGE_FD>/dev/null
fi
_LTEOF

cat >>"$CONFIG_LT" <<_LTEOF
_LT_OUTPUT_LIBTOOL_COMMANDS_INIT
_LTEOF

cat >>"$CONFIG_LT" <<\_LTEOF
AC_MSG_NOTICE([creating $ofile])
_LT_OUTPUT_LIBTOOL_COMMANDS
AS_EXIT(0)
_LTEOF
chmod +x "$CONFIG_LT"

# configure is writing to config.log, but config.lt does its own redirection,
# appending to config.log, which fails on DOS, as config.log is still kept
# open by configure.  Here we exec the FD to /dev/null, effectively closing
# config.log, so it can be properly (re)opened and appended to by config.lt.
lt_cl_success=:
test "$silent" = yes &&
  lt_config_lt_args="$lt_config_lt_args --quiet"
exec AS_MESSAGE_LOG_FD>/dev/null
$SHELL "$CONFIG_LT" $lt_config_lt_args || lt_cl_success=false
exec AS_MESSAGE_LOG_FD>>config.log
$lt_cl_success || AS_EXIT(1)
])# LT_OUTPUT


# _LT_CONFIG(TAG)
# ---------------
# If TAG is the built-in tag, create an initial libtool script with a
# default configuration from the untagged config vars.  Otherwise add code
# to config.status for appending the configuration named by TAG from the
# matching tagged config vars.
m4_defun([_LT_CONFIG],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
_LT_CONFIG_SAVE_COMMANDS([
  m4_define([_LT_TAG], m4_if([$1], [], [C], [$1]))dnl
  m4_if(_LT_TAG, [C], [
    # See if we are running on zsh, and set the options which allow our
    # commands through without removal of \ escapes.
    if test -n "${ZSH_VERSION+set}" ; then
      setopt NO_GLOB_SUBST
    fi

    cfgfile="${ofile}T"
    trap "$RM \"$cfgfile\"; exit 1" 1 2 15
    $RM "$cfgfile"

    cat <<_LT_EOF >> "$cfgfile"
#! $SHELL

# `$ECHO "$ofile" | sed 's%^.*/%%'` - Provide generalized library-building support services.
# Generated automatically by $as_me ($PACKAGE$TIMESTAMP) $VERSION
# Libtool was configured on host `(hostname || uname -n) 2>/dev/null | sed 1q`:
# NOTE: Changes made to this file will be lost: look at ltmain.sh.
#
_LT_COPYING
_LT_LIBTOOL_TAGS

# ### BEGIN LIBTOOL CONFIG
_LT_LIBTOOL_CONFIG_VARS
_LT_LIBTOOL_TAG_VARS
# ### END LIBTOOL CONFIG

_LT_EOF

  case $host_os in
  aix3*)
    cat <<\_LT_EOF >> "$cfgfile"
# AIX sometimes has problems with the GCC collect2 program.  For some
# reason, if we set the COLLECT_NAMES environment variable, the problems
# vanish in a puff of smoke.
if test "X${COLLECT_NAMES+set}" != Xset; then
  COLLECT_NAMES=
  export COLLECT_NAMES
fi
_LT_EOF
    ;;
  esac

  _LT_PROG_LTMAIN

  # We use sed instead of cat because bash on DJGPP gets confused if
  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
  # text mode, it properly converts lines to CR/LF.  This bash problem
  # is reportedly fixed, but why not run on old versions too?
  sed '/^# Generated shell functions inserted here/q' "$ltmain" >> "$cfgfile" \
    || (rm -f "$cfgfile"; exit 1)

  _LT_PROG_XSI_SHELLFNS

  sed -n '/^# Generated shell functions inserted here/,$p' "$ltmain" >> "$cfgfile" \
    || (rm -f "$cfgfile"; exit 1)

  mv -f "$cfgfile" "$ofile" ||
    (rm -f "$ofile" && cp "$cfgfile" "$ofile" && rm -f "$cfgfile")
  chmod +x "$ofile"
],
[cat <<_LT_EOF >> "$ofile"

dnl Unfortunately we have to use $1 here, since _LT_TAG is not expanded
dnl in a comment (ie after a #).
# ### BEGIN LIBTOOL TAG CONFIG: $1
_LT_LIBTOOL_TAG_VARS(_LT_TAG)
# ### END LIBTOOL TAG CONFIG: $1
_LT_EOF
])dnl /m4_if
],
[m4_if([$1], [], [
    PACKAGE='$PACKAGE'
    VERSION='$VERSION'
    TIMESTAMP='$TIMESTAMP'
    RM='$RM'
    ofile='$ofile'], [])
])dnl /_LT_CONFIG_SAVE_COMMANDS
])# _LT_CONFIG


# LT_SUPPORTED_TAG(TAG)
# ---------------------
# Trace this macro to discover what tags are supported by the libtool
# --tag option, using:
#    autoconf --trace 'LT_SUPPORTED_TAG:$1'
AC_DEFUN([LT_SUPPORTED_TAG], [])


# C support is built-in for now
m4_define([_LT_LANG_C_enabled], [])
m4_define([_LT_TAGS], [])


# LT_LANG(LANG)
# -------------
# Enable libtool support for the given language if not already enabled.
AC_DEFUN([LT_LANG],
[AC_BEFORE([$0], [LT_OUTPUT])dnl
m4_case([$1],
  [C],			[_LT_LANG(C)],
  [C++],		[_LT_LANG(CXX)],
  [Java],		[_LT_LANG(GCJ)],
  [Fortran 77],		[_LT_LANG(F77)],
  [Fortran],		[_LT_LANG(FC)],
  [Windows Resource],	[_LT_LANG(RC)],
  [m4_ifdef([_LT_LANG_]$1[_CONFIG],
    [_LT_LANG($1)],
    [m4_fatal([$0: unsupported language: "$1"])])])dnl
])# LT_LANG


# _LT_LANG(LANGNAME)
# ------------------
m4_defun([_LT_LANG],
[m4_ifdef([_LT_LANG_]$1[_enabled], [],
  [LT_SUPPORTED_TAG([$1])dnl
  m4_append([_LT_TAGS], [$1 ])dnl
  m4_define([_LT_LANG_]$1[_enabled], [])dnl
  _LT_LANG_$1_CONFIG($1)])dnl
])# _LT_LANG


# _LT_LANG_DEFAULT_CONFIG
# -----------------------
m4_defun([_LT_LANG_DEFAULT_CONFIG],
[AC_PROVIDE_IFELSE([AC_PROG_CXX],
  [LT_LANG(CXX)],
  [m4_define([AC_PROG_CXX], defn([AC_PROG_CXX])[LT_LANG(CXX)])])

AC_PROVIDE_IFELSE([AC_PROG_F77],
  [LT_LANG(F77)],
  [m4_define([AC_PROG_F77], defn([AC_PROG_F77])[LT_LANG(F77)])])

AC_PROVIDE_IFELSE([AC_PROG_FC],
  [LT_LANG(FC)],
  [m4_define([AC_PROG_FC], defn([AC_PROG_FC])[LT_LANG(FC)])])

dnl The call to [A][M_PROG_GCJ] is quoted like that to stop aclocal
dnl pulling things in needlessly.
AC_PROVIDE_IFELSE([AC_PROG_GCJ],
  [LT_LANG(GCJ)],
  [AC_PROVIDE_IFELSE([A][M_PROG_GCJ],
    [LT_LANG(GCJ)],
    [AC_PROVIDE_IFELSE([LT_PROG_GCJ],
      [LT_LANG(GCJ)],
      [m4_ifdef([AC_PROG_GCJ],
	[m4_define([AC_PROG_GCJ], defn([AC_PROG_GCJ])[LT_LANG(GCJ)])])
       m4_ifdef([A][M_PROG_GCJ],
	[m4_define([A][M_PROG_GCJ], defn([A][M_PROG_GCJ])[LT_LANG(GCJ)])])
       m4_ifdef([LT_PROG_GCJ],
	[m4_define([LT_PROG_GCJ], defn([LT_PROG_GCJ])[LT_LANG(GCJ)])])])])])

AC_PROVIDE_IFELSE([LT_PROG_RC],
  [LT_LANG(RC)],
  [m4_define([LT_PROG_RC], defn([LT_PROG_RC])[LT_LANG(RC)])])
])# _LT_LANG_DEFAULT_CONFIG

# Obsolete macros:
AU_DEFUN([AC_LIBTOOL_CXX], [LT_LANG(C++)])
AU_DEFUN([AC_LIBTOOL_F77], [LT_LANG(Fortran 77)])
AU_DEFUN([AC_LIBTOOL_FC], [LT_LANG(Fortran)])
AU_DEFUN([AC_LIBTOOL_GCJ], [LT_LANG(Java)])
AU_DEFUN([AC_LIBTOOL_RC], [LT_LANG(Windows Resource)])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_CXX], [])
dnl AC_DEFUN([AC_LIBTOOL_F77], [])
dnl AC_DEFUN([AC_LIBTOOL_FC], [])
dnl AC_DEFUN([AC_LIBTOOL_GCJ], [])
dnl AC_DEFUN([AC_LIBTOOL_RC], [])


# _LT_TAG_COMPILER
# ----------------
m4_defun([_LT_TAG_COMPILER],
[AC_REQUIRE([AC_PROG_CC])dnl

_LT_DECL([LTCC], [CC], [1], [A C compiler])dnl
_LT_DECL([LTCFLAGS], [CFLAGS], [1], [LTCC compiler flags])dnl
_LT_TAGDECL([CC], [compiler], [1], [A language specific compiler])dnl
_LT_TAGDECL([with_gcc], [GCC], [0], [Is the compiler the GNU compiler?])dnl

# If no C compiler was specified, use CC.
LTCC=${LTCC-"$CC"}

# If no C compiler flags were specified, use CFLAGS.
LTCFLAGS=${LTCFLAGS-"$CFLAGS"}

# Allow CC to be a program name with arguments.
compiler=$CC
])# _LT_TAG_COMPILER


# _LT_COMPILER_BOILERPLATE
# ------------------------
# Check for compiler boilerplate output or warnings with
# the simple compiler test code.
m4_defun([_LT_COMPILER_BOILERPLATE],
[m4_require([_LT_DECL_SED])dnl
ac_outfile=conftest.$ac_objext
echo "$lt_simple_compile_test_code" >conftest.$ac_ext
eval "$ac_compile" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
_lt_compiler_boilerplate=`cat conftest.err`
$RM conftest*
])# _LT_COMPILER_BOILERPLATE


# _LT_LINKER_BOILERPLATE
# ----------------------
# Check for linker boilerplate output or warnings with
# the simple link test code.
m4_defun([_LT_LINKER_BOILERPLATE],
[m4_require([_LT_DECL_SED])dnl
ac_outfile=conftest.$ac_objext
echo "$lt_simple_link_test_code" >conftest.$ac_ext
eval "$ac_link" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
_lt_linker_boilerplate=`cat conftest.err`
$RM -r conftest*
])# _LT_LINKER_BOILERPLATE

# _LT_REQUIRED_DARWIN_CHECKS
# -------------------------
m4_defun_once([_LT_REQUIRED_DARWIN_CHECKS],[
  case $host_os in
    rhapsody* | darwin*)
    AC_CHECK_TOOL([DSYMUTIL], [dsymutil], [:])
    AC_CHECK_TOOL([NMEDIT], [nmedit], [:])
    AC_CHECK_TOOL([LIPO], [lipo], [:])
    AC_CHECK_TOOL([OTOOL], [otool], [:])
    AC_CHECK_TOOL([OTOOL64], [otool64], [:])
    _LT_DECL([], [DSYMUTIL], [1],
      [Tool to manipulate archived DWARF debug symbol files on Mac OS X])
    _LT_DECL([], [NMEDIT], [1],
      [Tool to change global to local symbols on Mac OS X])
    _LT_DECL([], [LIPO], [1],
      [Tool to manipulate fat objects and archives on Mac OS X])
    _LT_DECL([], [OTOOL], [1],
      [ldd/readelf like tool for Mach-O binaries on Mac OS X])
    _LT_DECL([], [OTOOL64], [1],
      [ldd/readelf like tool for 64 bit Mach-O binaries on Mac OS X 10.4])

    AC_CACHE_CHECK([for -single_module linker flag],[lt_cv_apple_cc_single_mod],
      [lt_cv_apple_cc_single_mod=no
      if test -z "${LT_MULTI_MODULE}"; then
	# By default we will add the -single_module flag. You can override
	# by either setting the environment variable LT_MULTI_MODULE
	# non-empty at configure time, or by adding -multi_module to the
	# link flags.
	rm -rf libconftest.dylib*
	echo "int foo(void){return 1;}" > conftest.c
	echo "$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
-dynamiclib -Wl,-single_module conftest.c" >&AS_MESSAGE_LOG_FD
	$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
	  -dynamiclib -Wl,-single_module conftest.c 2>conftest.err
        _lt_result=$?
	if test -f libconftest.dylib && test ! -s conftest.err && test $_lt_result = 0; then
	  lt_cv_apple_cc_single_mod=yes
	else
	  cat conftest.err >&AS_MESSAGE_LOG_FD
	fi
	rm -rf libconftest.dylib*
	rm -f conftest.*
      fi])
    AC_CACHE_CHECK([for -exported_symbols_list linker flag],
      [lt_cv_ld_exported_symbols_list],
      [lt_cv_ld_exported_symbols_list=no
      save_LDFLAGS=$LDFLAGS
      echo "_main" > conftest.sym
      LDFLAGS="$LDFLAGS -Wl,-exported_symbols_list,conftest.sym"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
	[lt_cv_ld_exported_symbols_list=yes],
	[lt_cv_ld_exported_symbols_list=no])
	LDFLAGS="$save_LDFLAGS"
    ])
    AC_CACHE_CHECK([for -force_load linker flag],[lt_cv_ld_force_load],
      [lt_cv_ld_force_load=no
      cat > conftest.c << _LT_EOF
int forced_loaded() { return 2;}
_LT_EOF
      echo "$LTCC $LTCFLAGS -c -o conftest.o conftest.c" >&AS_MESSAGE_LOG_FD
      $LTCC $LTCFLAGS -c -o conftest.o conftest.c 2>&AS_MESSAGE_LOG_FD
      echo "$AR cru libconftest.a conftest.o" >&AS_MESSAGE_LOG_FD
      $AR cru libconftest.a conftest.o 2>&AS_MESSAGE_LOG_FD
      echo "$RANLIB libconftest.a" >&AS_MESSAGE_LOG_FD
      $RANLIB libconftest.a 2>&AS_MESSAGE_LOG_FD
      cat > conftest.c << _LT_EOF
int main() { return 0;}
_LT_EOF
      echo "$LTCC $LTCFLAGS $LDFLAGS -o conftest conftest.c -Wl,-force_load,./libconftest.a" >&AS_MESSAGE_LOG_FD
      $LTCC $LTCFLAGS $LDFLAGS -o conftest conftest.c -Wl,-force_load,./libconftest.a 2>conftest.err
      _lt_result=$?
      if test -f conftest && test ! -s conftest.err && test $_lt_result = 0 && $GREP forced_load conftest 2>&1 >/dev/null; then
	lt_cv_ld_force_load=yes
      else
	cat conftest.err >&AS_MESSAGE_LOG_FD
      fi
        rm -f conftest.err libconftest.a conftest conftest.c
        rm -rf conftest.dSYM
    ])
    case $host_os in
    rhapsody* | darwin1.[[012]])
      _lt_dar_allow_undefined='${wl}-undefined ${wl}suppress' ;;
    darwin1.*)
      _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
    darwin*) # darwin 5.x on
      # if running on 10.5 or later, the deployment target defaults
      # to the OS version, if on x86, and 10.4, the deployment
      # target defaults to 10.4. Don't you love it?
      case ${MACOSX_DEPLOYMENT_TARGET-10.0},$host in
	10.0,*86*-darwin8*|10.0,*-darwin[[91]]*)
	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
	10.[[012]]*)
	  _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
	10.*)
	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
      esac
    ;;
  esac
    if test "$lt_cv_apple_cc_single_mod" = "yes"; then
      _lt_dar_single_mod='$single_module'
    fi
    if test "$lt_cv_ld_exported_symbols_list" = "yes"; then
      _lt_dar_export_syms=' ${wl}-exported_symbols_list,$output_objdir/${libname}-symbols.expsym'
    else
      _lt_dar_export_syms='~$NMEDIT -s $output_objdir/${libname}-symbols.expsym ${lib}'
    fi
    if test "$DSYMUTIL" != ":" && test "$lt_cv_ld_force_load" = "no"; then
      _lt_dsymutil='~$DSYMUTIL $lib || :'
    else
      _lt_dsymutil=
    fi
    ;;
  esac
])


# _LT_DARWIN_LINKER_FEATURES
# --------------------------
# Checks for linker and compiler features on darwin
m4_defun([_LT_DARWIN_LINKER_FEATURES],
[
  m4_require([_LT_REQUIRED_DARWIN_CHECKS])
  _LT_TAGVAR(archive_cmds_need_lc, $1)=no
  _LT_TAGVAR(hardcode_direct, $1)=no
  _LT_TAGVAR(hardcode_automatic, $1)=yes
  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
  if test "$lt_cv_ld_force_load" = "yes"; then
    _LT_TAGVAR(whole_archive_flag_spec, $1)='`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience ${wl}-force_load,$conv\"; done; func_echo_all \"$new_convenience\"`'
  else
    _LT_TAGVAR(whole_archive_flag_spec, $1)=''
  fi
  _LT_TAGVAR(link_all_deplibs, $1)=yes
  _LT_TAGVAR(allow_undefined_flag, $1)="$_lt_dar_allow_undefined"
  case $cc_basename in
     ifort*) _lt_dar_can_shared=yes ;;
     *) _lt_dar_can_shared=$GCC ;;
  esac
  if test "$_lt_dar_can_shared" = "yes"; then
    output_verbose_link_cmd=func_echo_all
    _LT_TAGVAR(archive_cmds, $1)="\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring $_lt_dar_single_mod${_lt_dsymutil}"
    _LT_TAGVAR(module_cmds, $1)="\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dsymutil}"
    _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring ${_lt_dar_single_mod}${_lt_dar_export_syms}${_lt_dsymutil}"
    _LT_TAGVAR(module_expsym_cmds, $1)="sed -e 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dar_export_syms}${_lt_dsymutil}"
    m4_if([$1], [CXX],
[   if test "$lt_cv_apple_cc_single_mod" != "yes"; then
      _LT_TAGVAR(archive_cmds, $1)="\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dsymutil}"
      _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dar_export_syms}${_lt_dsymutil}"
    fi
],[])
  else
  _LT_TAGVAR(ld_shlibs, $1)=no
  fi
])

# _LT_SYS_MODULE_PATH_AIX
# -----------------------
# Links a minimal program and checks the executable
# for the system default hardcoded library path. In most cases,
# this is /usr/lib:/lib, but when the MPI compilers are used
# the location of the communication and MPI libs are included too.
# If we don't find anything, use the default library path according
# to the aix ld manual.
m4_defun([_LT_SYS_MODULE_PATH_AIX],
[m4_require([_LT_DECL_SED])dnl
AC_LINK_IFELSE(AC_LANG_PROGRAM,[
lt_aix_libpath_sed='
    /Import File Strings/,/^$/ {
	/^0/ {
	    s/^0  *\(.*\)$/\1/
	    p
	}
    }'
aix_libpath=`dump -H conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
# Check for a 64-bit object if we didn't find anything.
if test -z "$aix_libpath"; then
  aix_libpath=`dump -HX64 conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
fi],[])
if test -z "$aix_libpath"; then aix_libpath="/usr/lib:/lib"; fi
])# _LT_SYS_MODULE_PATH_AIX


# _LT_SHELL_INIT(ARG)
# -------------------
m4_define([_LT_SHELL_INIT],
[m4_divert_text([M4SH-INIT], [$1
])])# _LT_SHELL_INIT



# _LT_PROG_ECHO_BACKSLASH
# -----------------------
# Find how we can fake an echo command that does not interpret backslash.
# In particular, with Autoconf 2.60 or later we add some code to the start
# of the generated configure script which will find a shell with a builtin
# printf (which we can use as an echo command).
m4_defun([_LT_PROG_ECHO_BACKSLASH],
[ECHO='\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'
ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO
ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO$ECHO

AC_MSG_CHECKING([how to print strings])
# Test print first, because it will be a builtin if present.
if test "X`print -r -- -n 2>/dev/null`" = X-n && \
   test "X`print -r -- $ECHO 2>/dev/null`" = "X$ECHO"; then
  ECHO='print -r --'
elif test "X`printf %s $ECHO 2>/dev/null`" = "X$ECHO"; then
  ECHO='printf %s\n'
else
  # Use this function as a fallback that always works.
  func_fallback_echo ()
  {
    eval 'cat <<_LTECHO_EOF
$[]1
_LTECHO_EOF'
  }
  ECHO='func_fallback_echo'
fi

# func_echo_all arg...
# Invoke $ECHO with all args, space-separated.
func_echo_all ()
{
    $ECHO "$*" 
}

case "$ECHO" in
  printf*) AC_MSG_RESULT([printf]) ;;
  print*) AC_MSG_RESULT([print -r]) ;;
  *) AC_MSG_RESULT([cat]) ;;
esac

m4_ifdef([_AS_DETECT_SUGGESTED],
[_AS_DETECT_SUGGESTED([
  test -n "${ZSH_VERSION+set}${BASH_VERSION+set}" || (
    ECHO='\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'
    ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO
    ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO$ECHO
    PATH=/empty FPATH=/empty; export PATH FPATH
    test "X`printf %s $ECHO`" = "X$ECHO" \
      || test "X`print -r -- $ECHO`" = "X$ECHO" )])])

_LT_DECL([], [SHELL], [1], [Shell to use when invoking shell scripts])
_LT_DECL([], [ECHO], [1], [An echo program that protects backslashes])
])# _LT_PROG_ECHO_BACKSLASH


# _LT_ENABLE_LOCK
# ---------------
m4_defun([_LT_ENABLE_LOCK],
[AC_ARG_ENABLE([libtool-lock],
  [AS_HELP_STRING([--disable-libtool-lock],
    [avoid locking (might break parallel builds)])])
test "x$enable_libtool_lock" != xno && enable_libtool_lock=yes

# Some flags need to be propagated to the compiler or linker for good
# libtool support.
case $host in
ia64-*-hpux*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.$ac_objext` in
      *ELF-32*)
	HPUX_IA64_MODE="32"
	;;
      *ELF-64*)
	HPUX_IA64_MODE="64"
	;;
    esac
  fi
  rm -rf conftest*
  ;;
*-*-irix6*)
  # Find out which ABI we are using.
  echo '[#]line '$LINENO' "configure"' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    if test "$lt_cv_prog_gnu_ld" = yes; then
      case `/usr/bin/file conftest.$ac_objext` in
	*32-bit*)
	  LD="${LD-ld} -melf32bsmip"
	  ;;
	*N32*)
	  LD="${LD-ld} -melf32bmipn32"
	  ;;
	*64-bit*)
	  LD="${LD-ld} -melf64bmip"
	;;
      esac
    else
      case `/usr/bin/file conftest.$ac_objext` in
	*32-bit*)
	  LD="${LD-ld} -32"
	  ;;
	*N32*)
	  LD="${LD-ld} -n32"
	  ;;
	*64-bit*)
	  LD="${LD-ld} -64"
	  ;;
      esac
    fi
  fi
  rm -rf conftest*
  ;;

x86_64-*kfreebsd*-gnu|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
s390*-*linux*|s390*-*tpf*|sparc*-*linux*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.o` in
      *32-bit*)
	case $host in
	  x86_64-*kfreebsd*-gnu)
	    LD="${LD-ld} -m elf_i386_fbsd"
	    ;;
	  x86_64-*linux*)
	    LD="${LD-ld} -m elf_i386"
	    ;;
	  ppc64-*linux*|powerpc64-*linux*)
	    LD="${LD-ld} -m elf32ppclinux"
	    ;;
	  s390x-*linux*)
	    LD="${LD-ld} -m elf_s390"
	    ;;
	  sparc64-*linux*)
	    LD="${LD-ld} -m elf32_sparc"
	    ;;
	esac
	;;
      *64-bit*)
	case $host in
	  x86_64-*kfreebsd*-gnu)
	    LD="${LD-ld} -m elf_x86_64_fbsd"
	    ;;
	  x86_64-*linux*)
	    LD="${LD-ld} -m elf_x86_64"
	    ;;
	  ppc*-*linux*|powerpc*-*linux*)
	    LD="${LD-ld} -m elf64ppc"
	    ;;
	  s390*-*linux*|s390*-*tpf*)
	    LD="${LD-ld} -m elf64_s390"
	    ;;
	  sparc*-*linux*)
	    LD="${LD-ld} -m elf64_sparc"
	    ;;
	esac
	;;
    esac
  fi
  rm -rf conftest*
  ;;

*-*-sco3.2v5*)
  # On SCO OpenServer 5, we need -belf to get full-featured binaries.
  SAVE_CFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -belf"
  AC_CACHE_CHECK([whether the C compiler needs -belf], lt_cv_cc_needs_belf,
    [AC_LANG_PUSH(C)
     AC_LINK_IFELSE([AC_LANG_PROGRAM([[]],[[]])],[lt_cv_cc_needs_belf=yes],[lt_cv_cc_needs_belf=no])
     AC_LANG_POP])
  if test x"$lt_cv_cc_needs_belf" != x"yes"; then
    # this is probably gcc 2.8.0, egcs 1.0 or newer; no need for -belf
    CFLAGS="$SAVE_CFLAGS"
  fi
  ;;
sparc*-*solaris*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.o` in
    *64-bit*)
      case $lt_cv_prog_gnu_ld in
      yes*) LD="${LD-ld} -m elf64_sparc" ;;
      *)
	if ${LD-ld} -64 -r -o conftest2.o conftest.o >/dev/null 2>&1; then
	  LD="${LD-ld} -64"
	fi
	;;
      esac
      ;;
    esac
  fi
  rm -rf conftest*
  ;;
esac

need_locks="$enable_libtool_lock"
])# _LT_ENABLE_LOCK


# _LT_CMD_OLD_ARCHIVE
# -------------------
m4_defun([_LT_CMD_OLD_ARCHIVE],
[AC_CHECK_TOOL(AR, ar, false)
test -z "$AR" && AR=ar
test -z "$AR_FLAGS" && AR_FLAGS=cru
_LT_DECL([], [AR], [1], [The archiver])
_LT_DECL([], [AR_FLAGS], [1])

AC_CHECK_TOOL(STRIP, strip, :)
test -z "$STRIP" && STRIP=:
_LT_DECL([], [STRIP], [1], [A symbol stripping program])

AC_CHECK_TOOL(RANLIB, ranlib, :)
test -z "$RANLIB" && RANLIB=:
_LT_DECL([], [RANLIB], [1],
    [Commands used to install an old-style archive])

# Determine commands to create old-style static archives.
old_archive_cmds='$AR $AR_FLAGS $oldlib$oldobjs'
old_postinstall_cmds='chmod 644 $oldlib'
old_postuninstall_cmds=

if test -n "$RANLIB"; then
  case $host_os in
  openbsd*)
    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB -t \$oldlib"
    ;;
  *)
    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB \$oldlib"
    ;;
  esac
  old_archive_cmds="$old_archive_cmds~\$RANLIB \$oldlib"
fi

case $host_os in
  darwin*)
    lock_old_archive_extraction=yes ;;
  *)
    lock_old_archive_extraction=no ;;
esac
_LT_DECL([], [old_postinstall_cmds], [2])
_LT_DECL([], [old_postuninstall_cmds], [2])
_LT_TAGDECL([], [old_archive_cmds], [2],
    [Commands used to build an old-style archive])
_LT_DECL([], [lock_old_archive_extraction], [0],
    [Whether to use a lock for old archive extraction])
])# _LT_CMD_OLD_ARCHIVE


# _LT_COMPILER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
#		[OUTPUT-FILE], [ACTION-SUCCESS], [ACTION-FAILURE])
# ----------------------------------------------------------------
# Check whether the given compiler option works
AC_DEFUN([_LT_COMPILER_OPTION],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_SED])dnl
AC_CACHE_CHECK([$1], [$2],
  [$2=no
   m4_if([$4], , [ac_outfile=conftest.$ac_objext], [ac_outfile=$4])
   echo "$lt_simple_compile_test_code" > conftest.$ac_ext
   lt_compiler_flag="$3"
   # Insert the option either (1) after the last *FLAGS variable, or
   # (2) before a word containing "conftest.", or (3) at the end.
   # Note that $ac_compile itself does not contain backslashes and begins
   # with a dollar sign (not a hyphen), so the echo should work correctly.
   # The option is referenced via a variable to avoid confusing sed.
   lt_compile=`echo "$ac_compile" | $SED \
   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
   -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
   -e 's:$: $lt_compiler_flag:'`
   (eval echo "\"\$as_me:$LINENO: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
   (eval "$lt_compile" 2>conftest.err)
   ac_status=$?
   cat conftest.err >&AS_MESSAGE_LOG_FD
   echo "$as_me:$LINENO: \$? = $ac_status" >&AS_MESSAGE_LOG_FD
   if (exit $ac_status) && test -s "$ac_outfile"; then
     # The compiler can only warn and ignore the option if not recognized
     # So say no if there are warnings other than the usual output.
     $ECHO "$_lt_compiler_boilerplate" | $SED '/^$/d' >conftest.exp
     $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
     if test ! -s conftest.er2 || diff conftest.exp conftest.er2 >/dev/null; then
       $2=yes
     fi
   fi
   $RM conftest*
])

if test x"[$]$2" = xyes; then
    m4_if([$5], , :, [$5])
else
    m4_if([$6], , :, [$6])
fi
])# _LT_COMPILER_OPTION

# Old name:
AU_ALIAS([AC_LIBTOOL_COMPILER_OPTION], [_LT_COMPILER_OPTION])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION], [])


# _LT_LINKER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
#                  [ACTION-SUCCESS], [ACTION-FAILURE])
# ----------------------------------------------------
# Check whether the given linker option works
AC_DEFUN([_LT_LINKER_OPTION],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_SED])dnl
AC_CACHE_CHECK([$1], [$2],
  [$2=no
   save_LDFLAGS="$LDFLAGS"
   LDFLAGS="$LDFLAGS $3"
   echo "$lt_simple_link_test_code" > conftest.$ac_ext
   if (eval $ac_link 2>conftest.err) && test -s conftest$ac_exeext; then
     # The linker can only warn and ignore the option if not recognized
     # So say no if there are warnings
     if test -s conftest.err; then
       # Append any errors to the config.log.
       cat conftest.err 1>&AS_MESSAGE_LOG_FD
       $ECHO "$_lt_linker_boilerplate" | $SED '/^$/d' > conftest.exp
       $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
       if diff conftest.exp conftest.er2 >/dev/null; then
         $2=yes
       fi
     else
       $2=yes
     fi
   fi
   $RM -r conftest*
   LDFLAGS="$save_LDFLAGS"
])

if test x"[$]$2" = xyes; then
    m4_if([$4], , :, [$4])
else
    m4_if([$5], , :, [$5])
fi
])# _LT_LINKER_OPTION

# Old name:
AU_ALIAS([AC_LIBTOOL_LINKER_OPTION], [_LT_LINKER_OPTION])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_LINKER_OPTION], [])


# LT_CMD_MAX_LEN
#---------------
AC_DEFUN([LT_CMD_MAX_LEN],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
# find the maximum length of command line arguments
AC_MSG_CHECKING([the maximum length of command line arguments])
AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [dnl
  i=0
  teststring="ABCD"

  case $build_os in
  msdosdjgpp*)
    # On DJGPP, this test can blow up pretty badly due to problems in libc
    # (any single argument exceeding 2000 bytes causes a buffer overrun
    # during glob expansion).  Even if it were fixed, the result of this
    # check would be larger than it should be.
    lt_cv_sys_max_cmd_len=12288;    # 12K is about right
    ;;

  gnu*)
    # Under GNU Hurd, this test is not required because there is
    # no limit to the length of command line arguments.
    # Libtool will interpret -1 as no limit whatsoever
    lt_cv_sys_max_cmd_len=-1;
    ;;

  cygwin* | mingw* | cegcc*)
    # On Win9x/ME, this test blows up -- it succeeds, but takes
    # about 5 minutes as the teststring grows exponentially.
    # Worse, since 9x/ME are not pre-emptively multitasking,
    # you end up with a "frozen" computer, even though with patience
    # the test eventually succeeds (with a max line length of 256k).
    # Instead, let's just punt: use the minimum linelength reported by
    # all of the supported platforms: 8192 (on NT/2K/XP).
    lt_cv_sys_max_cmd_len=8192;
    ;;

  mint*)
    # On MiNT this can take a long time and run out of memory.
    lt_cv_sys_max_cmd_len=8192;
    ;;

  amigaos*)
    # On AmigaOS with pdksh, this test takes hours, literally.
    # So we just punt and use a minimum line length of 8192.
    lt_cv_sys_max_cmd_len=8192;
    ;;

  netbsd* | freebsd* | openbsd* | darwin* | dragonfly*)
    # This has been around since 386BSD, at least.  Likely further.
    if test -x /sbin/sysctl; then
      lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
    elif test -x /usr/sbin/sysctl; then
      lt_cv_sys_max_cmd_len=`/usr/sbin/sysctl -n kern.argmax`
    else
      lt_cv_sys_max_cmd_len=65536	# usable default for all BSDs
    fi
    # And add a safety zone
    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
    ;;

  interix*)
    # We know the value 262144 and hardcode it with a safety zone (like BSD)
    lt_cv_sys_max_cmd_len=196608
    ;;

  osf*)
    # Dr. Hans Ekkehard Plesser reports seeing a kernel panic running configure
    # due to this test when exec_disable_arg_limit is 1 on Tru64. It is not
    # nice to cause kernel panics so lets avoid the loop below.
    # First set a reasonable default.
    lt_cv_sys_max_cmd_len=16384
    #
    if test -x /sbin/sysconfig; then
      case `/sbin/sysconfig -q proc exec_disable_arg_limit` in
        *1*) lt_cv_sys_max_cmd_len=-1 ;;
      esac
    fi
    ;;
  sco3.2v5*)
    lt_cv_sys_max_cmd_len=102400
    ;;
  sysv5* | sco5v6* | sysv4.2uw2*)
    kargmax=`grep ARG_MAX /etc/conf/cf.d/stune 2>/dev/null`
    if test -n "$kargmax"; then
      lt_cv_sys_max_cmd_len=`echo $kargmax | sed 's/.*[[	 ]]//'`
    else
      lt_cv_sys_max_cmd_len=32768
    fi
    ;;
  *)
    lt_cv_sys_max_cmd_len=`(getconf ARG_MAX) 2> /dev/null`
    if test -n "$lt_cv_sys_max_cmd_len"; then
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
    else
      # Make teststring a little bigger before we do anything with it.
      # a 1K string should be a reasonable start.
      for i in 1 2 3 4 5 6 7 8 ; do
        teststring=$teststring$teststring
      done
      SHELL=${SHELL-${CONFIG_SHELL-/bin/sh}}
      # If test is not a shell built-in, we'll probably end up computing a
      # maximum length that is only half of the actual maximum length, but
      # we can't tell.
      while { test "X"`func_fallback_echo "$teststring$teststring" 2>/dev/null` \
	         = "X$teststring$teststring"; } >/dev/null 2>&1 &&
	      test $i != 17 # 1/2 MB should be enough
      do
        i=`expr $i + 1`
        teststring=$teststring$teststring
      done
      # Only check the string length outside the loop.
      lt_cv_sys_max_cmd_len=`expr "X$teststring" : ".*" 2>&1`
      teststring=
      # Add a significant safety factor because C++ compilers can tack on
      # massive amounts of additional arguments before passing them to the
      # linker.  It appears as though 1/2 is a usable value.
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 2`
    fi
    ;;
  esac
])
if test -n $lt_cv_sys_max_cmd_len ; then
  AC_MSG_RESULT($lt_cv_sys_max_cmd_len)
else
  AC_MSG_RESULT(none)
fi
max_cmd_len=$lt_cv_sys_max_cmd_len
_LT_DECL([], [max_cmd_len], [0],
    [What is the maximum length of a command?])
])# LT_CMD_MAX_LEN

# Old name:
AU_ALIAS([AC_LIBTOOL_SYS_MAX_CMD_LEN], [LT_CMD_MAX_LEN])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_SYS_MAX_CMD_LEN], [])


# _LT_HEADER_DLFCN
# ----------------
m4_defun([_LT_HEADER_DLFCN],
[AC_CHECK_HEADERS([dlfcn.h], [], [], [AC_INCLUDES_DEFAULT])dnl
])# _LT_HEADER_DLFCN


# _LT_TRY_DLOPEN_SELF (ACTION-IF-TRUE, ACTION-IF-TRUE-W-USCORE,
#                      ACTION-IF-FALSE, ACTION-IF-CROSS-COMPILING)
# ----------------------------------------------------------------
m4_defun([_LT_TRY_DLOPEN_SELF],
[m4_require([_LT_HEADER_DLFCN])dnl
if test "$cross_compiling" = yes; then :
  [$4]
else
  lt_dlunknown=0; lt_dlno_uscore=1; lt_dlneed_uscore=2
  lt_status=$lt_dlunknown
  cat > conftest.$ac_ext <<_LT_EOF
[#line $LINENO "configure"
#include "confdefs.h"

#if HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#include <stdio.h>

#ifdef RTLD_GLOBAL
#  define LT_DLGLOBAL		RTLD_GLOBAL
#else
#  ifdef DL_GLOBAL
#    define LT_DLGLOBAL		DL_GLOBAL
#  else
#    define LT_DLGLOBAL		0
#  endif
#endif

/* We may have to define LT_DLLAZY_OR_NOW in the command line if we
   find out it does not work in some platform. */
#ifndef LT_DLLAZY_OR_NOW
#  ifdef RTLD_LAZY
#    define LT_DLLAZY_OR_NOW		RTLD_LAZY
#  else
#    ifdef DL_LAZY
#      define LT_DLLAZY_OR_NOW		DL_LAZY
#    else
#      ifdef RTLD_NOW
#        define LT_DLLAZY_OR_NOW	RTLD_NOW
#      else
#        ifdef DL_NOW
#          define LT_DLLAZY_OR_NOW	DL_NOW
#        else
#          define LT_DLLAZY_OR_NOW	0
#        endif
#      endif
#    endif
#  endif
#endif

/* When -fvisbility=hidden is used, assume the code has been annotated
   correspondingly for the symbols needed.  */
#if defined(__GNUC__) && (((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)) || (__GNUC__ > 3))
void fnord () __attribute__((visibility("default")));
#endif

void fnord () { int i=42; }
int main ()
{
  void *self = dlopen (0, LT_DLGLOBAL|LT_DLLAZY_OR_NOW);
  int status = $lt_dlunknown;

  if (self)
    {
      if (dlsym (self,"fnord"))       status = $lt_dlno_uscore;
      else
        {
	  if (dlsym( self,"_fnord"))  status = $lt_dlneed_uscore;
          else puts (dlerror ());
	}
      /* dlclose (self); */
    }
  else
    puts (dlerror ());

  return status;
}]
_LT_EOF
  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext} 2>/dev/null; then
    (./conftest; exit; ) >&AS_MESSAGE_LOG_FD 2>/dev/null
    lt_status=$?
    case x$lt_status in
      x$lt_dlno_uscore) $1 ;;
      x$lt_dlneed_uscore) $2 ;;
      x$lt_dlunknown|x*) $3 ;;
    esac
  else :
    # compilation failed
    $3
  fi
fi
rm -fr conftest*
])# _LT_TRY_DLOPEN_SELF


# LT_SYS_DLOPEN_SELF
# ------------------
AC_DEFUN([LT_SYS_DLOPEN_SELF],
[m4_require([_LT_HEADER_DLFCN])dnl
if test "x$enable_dlopen" != xyes; then
  enable_dlopen=unknown
  enable_dlopen_self=unknown
  enable_dlopen_self_static=unknown
else
  lt_cv_dlopen=no
  lt_cv_dlopen_libs=

  case $host_os in
  beos*)
    lt_cv_dlopen="load_add_on"
    lt_cv_dlopen_libs=
    lt_cv_dlopen_self=yes
    ;;

  mingw* | pw32* | cegcc*)
    lt_cv_dlopen="LoadLibrary"
    lt_cv_dlopen_libs=
    ;;

  cygwin*)
    lt_cv_dlopen="dlopen"
    lt_cv_dlopen_libs=
    ;;

  darwin*)
  # if libdl is installed we need to link against it
    AC_CHECK_LIB([dl], [dlopen],
		[lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-ldl"],[
    lt_cv_dlopen="dyld"
    lt_cv_dlopen_libs=
    lt_cv_dlopen_self=yes
    ])
    ;;

  *)
    AC_CHECK_FUNC([shl_load],
	  [lt_cv_dlopen="shl_load"],
      [AC_CHECK_LIB([dld], [shl_load],
	    [lt_cv_dlopen="shl_load" lt_cv_dlopen_libs="-ldld"],
	[AC_CHECK_FUNC([dlopen],
	      [lt_cv_dlopen="dlopen"],
	  [AC_CHECK_LIB([dl], [dlopen],
		[lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-ldl"],
	    [AC_CHECK_LIB([svld], [dlopen],
		  [lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-lsvld"],
	      [AC_CHECK_LIB([dld], [dld_link],
		    [lt_cv_dlopen="dld_link" lt_cv_dlopen_libs="-ldld"])
	      ])
	    ])
	  ])
	])
      ])
    ;;
  esac

  if test "x$lt_cv_dlopen" != xno; then
    enable_dlopen=yes
  else
    enable_dlopen=no
  fi

  case $lt_cv_dlopen in
  dlopen)
    save_CPPFLAGS="$CPPFLAGS"
    test "x$ac_cv_header_dlfcn_h" = xyes && CPPFLAGS="$CPPFLAGS -DHAVE_DLFCN_H"

    save_LDFLAGS="$LDFLAGS"
    wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $export_dynamic_flag_spec\"

    save_LIBS="$LIBS"
    LIBS="$lt_cv_dlopen_libs $LIBS"

    AC_CACHE_CHECK([whether a program can dlopen itself],
	  lt_cv_dlopen_self, [dnl
	  _LT_TRY_DLOPEN_SELF(
	    lt_cv_dlopen_self=yes, lt_cv_dlopen_self=yes,
	    lt_cv_dlopen_self=no, lt_cv_dlopen_self=cross)
    ])

    if test "x$lt_cv_dlopen_self" = xyes; then
      wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $lt_prog_compiler_static\"
      AC_CACHE_CHECK([whether a statically linked program can dlopen itself],
	  lt_cv_dlopen_self_static, [dnl
	  _LT_TRY_DLOPEN_SELF(
	    lt_cv_dlopen_self_static=yes, lt_cv_dlopen_self_static=yes,
	    lt_cv_dlopen_self_static=no,  lt_cv_dlopen_self_static=cross)
      ])
    fi

    CPPFLAGS="$save_CPPFLAGS"
    LDFLAGS="$save_LDFLAGS"
    LIBS="$save_LIBS"
    ;;
  esac

  case $lt_cv_dlopen_self in
  yes|no) enable_dlopen_self=$lt_cv_dlopen_self ;;
  *) enable_dlopen_self=unknown ;;
  esac

  case $lt_cv_dlopen_self_static in
  yes|no) enable_dlopen_self_static=$lt_cv_dlopen_self_static ;;
  *) enable_dlopen_self_static=unknown ;;
  esac
fi
_LT_DECL([dlopen_support], [enable_dlopen], [0],
	 [Whether dlopen is supported])
_LT_DECL([dlopen_self], [enable_dlopen_self], [0],
	 [Whether dlopen of programs is supported])
_LT_DECL([dlopen_self_static], [enable_dlopen_self_static], [0],
	 [Whether dlopen of statically linked programs is supported])
])# LT_SYS_DLOPEN_SELF

# Old name:
AU_ALIAS([AC_LIBTOOL_DLOPEN_SELF], [LT_SYS_DLOPEN_SELF])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_DLOPEN_SELF], [])


# _LT_COMPILER_C_O([TAGNAME])
# ---------------------------
# Check to see if options -c and -o are simultaneously supported by compiler.
# This macro does not hard code the compiler like AC_PROG_CC_C_O.
m4_defun([_LT_COMPILER_C_O],
[m4_require([_LT_DECL_SED])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_TAG_COMPILER])dnl
AC_CACHE_CHECK([if $compiler supports -c -o file.$ac_objext],
  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)],
  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=no
   $RM -r conftest 2>/dev/null
   mkdir conftest
   cd conftest
   mkdir out
   echo "$lt_simple_compile_test_code" > conftest.$ac_ext

   lt_compiler_flag="-o out/conftest2.$ac_objext"
   # Insert the option either (1) after the last *FLAGS variable, or
   # (2) before a word containing "conftest.", or (3) at the end.
   # Note that $ac_compile itself does not contain backslashes and begins
   # with a dollar sign (not a hyphen), so the echo should work correctly.
   lt_compile=`echo "$ac_compile" | $SED \
   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
   -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
   -e 's:$: $lt_compiler_flag:'`
   (eval echo "\"\$as_me:$LINENO: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
   (eval "$lt_compile" 2>out/conftest.err)
   ac_status=$?
   cat out/conftest.err >&AS_MESSAGE_LOG_FD
   echo "$as_me:$LINENO: \$? = $ac_status" >&AS_MESSAGE_LOG_FD
   if (exit $ac_status) && test -s out/conftest2.$ac_objext
   then
     # The compiler can only warn and ignore the option if not recognized
     # So say no if there are warnings
     $ECHO "$_lt_compiler_boilerplate" | $SED '/^$/d' > out/conftest.exp
     $SED '/^$/d; /^ *+/d' out/conftest.err >out/conftest.er2
     if test ! -s out/conftest.er2 || diff out/conftest.exp out/conftest.er2 >/dev/null; then
       _LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
     fi
   fi
   chmod u+w . 2>&AS_MESSAGE_LOG_FD
   $RM conftest*
   # SGI C++ compiler will create directory out/ii_files/ for
   # template instantiation
   test -d out/ii_files && $RM out/ii_files/* && rmdir out/ii_files
   $RM out/* && rmdir out
   cd ..
   $RM -r conftest
   $RM conftest*
])
_LT_TAGDECL([compiler_c_o], [lt_cv_prog_compiler_c_o], [1],
	[Does compiler simultaneously support -c and -o options?])
])# _LT_COMPILER_C_O


# _LT_COMPILER_FILE_LOCKS([TAGNAME])
# ----------------------------------
# Check to see if we can do hard links to lock some files if needed
m4_defun([_LT_COMPILER_FILE_LOCKS],
[m4_require([_LT_ENABLE_LOCK])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
_LT_COMPILER_C_O([$1])

hard_links="nottested"
if test "$_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)" = no && test "$need_locks" != no; then
  # do not overwrite the value of need_locks provided by the user
  AC_MSG_CHECKING([if we can lock with hard links])
  hard_links=yes
  $RM conftest*
  ln conftest.a conftest.b 2>/dev/null && hard_links=no
  touch conftest.a
  ln conftest.a conftest.b 2>&5 || hard_links=no
  ln conftest.a conftest.b 2>/dev/null && hard_links=no
  AC_MSG_RESULT([$hard_links])
  if test "$hard_links" = no; then
    AC_MSG_WARN([`$CC' does not support `-c -o', so `make -j' may be unsafe])
    need_locks=warn
  fi
else
  need_locks=no
fi
_LT_DECL([], [need_locks], [1], [Must we lock files when doing compilation?])
])# _LT_COMPILER_FILE_LOCKS


# _LT_CHECK_OBJDIR
# ----------------
m4_defun([_LT_CHECK_OBJDIR],
[AC_CACHE_CHECK([for objdir], [lt_cv_objdir],
[rm -f .libs 2>/dev/null
mkdir .libs 2>/dev/null
if test -d .libs; then
  lt_cv_objdir=.libs
else
  # MS-DOS does not allow filenames that begin with a dot.
  lt_cv_objdir=_libs
fi
rmdir .libs 2>/dev/null])
objdir=$lt_cv_objdir
_LT_DECL([], [objdir], [0],
         [The name of the directory that contains temporary libtool files])dnl
m4_pattern_allow([LT_OBJDIR])dnl
AC_DEFINE_UNQUOTED(LT_OBJDIR, "$lt_cv_objdir/",
  [Define to the sub-directory in which libtool stores uninstalled libraries.])
])# _LT_CHECK_OBJDIR


# _LT_LINKER_HARDCODE_LIBPATH([TAGNAME])
# --------------------------------------
# Check hardcoding attributes.
m4_defun([_LT_LINKER_HARDCODE_LIBPATH],
[AC_MSG_CHECKING([how to hardcode library paths into programs])
_LT_TAGVAR(hardcode_action, $1)=
if test -n "$_LT_TAGVAR(hardcode_libdir_flag_spec, $1)" ||
   test -n "$_LT_TAGVAR(runpath_var, $1)" ||
   test "X$_LT_TAGVAR(hardcode_automatic, $1)" = "Xyes" ; then

  # We can hardcode non-existent directories.
  if test "$_LT_TAGVAR(hardcode_direct, $1)" != no &&
     # If the only mechanism to avoid hardcoding is shlibpath_var, we
     # have to relink, otherwise we might link with an installed library
     # when we should be linking with a yet-to-be-installed one
     ## test "$_LT_TAGVAR(hardcode_shlibpath_var, $1)" != no &&
     test "$_LT_TAGVAR(hardcode_minus_L, $1)" != no; then
    # Linking always hardcodes the temporary library directory.
    _LT_TAGVAR(hardcode_action, $1)=relink
  else
    # We can link without hardcoding, and we can hardcode nonexisting dirs.
    _LT_TAGVAR(hardcode_action, $1)=immediate
  fi
else
  # We cannot hardcode anything, or else we can only hardcode existing
  # directories.
  _LT_TAGVAR(hardcode_action, $1)=unsupported
fi
AC_MSG_RESULT([$_LT_TAGVAR(hardcode_action, $1)])

if test "$_LT_TAGVAR(hardcode_action, $1)" = relink ||
   test "$_LT_TAGVAR(inherit_rpath, $1)" = yes; then
  # Fast installation is not supported
  enable_fast_install=no
elif test "$shlibpath_overrides_runpath" = yes ||
     test "$enable_shared" = no; then
  # Fast installation is not necessary
  enable_fast_install=needless
fi
_LT_TAGDECL([], [hardcode_action], [0],
    [How to hardcode a shared library path into an executable])
])# _LT_LINKER_HARDCODE_LIBPATH


# _LT_CMD_STRIPLIB
# ----------------
m4_defun([_LT_CMD_STRIPLIB],
[m4_require([_LT_DECL_EGREP])
striplib=
old_striplib=
AC_MSG_CHECKING([whether stripping libraries is possible])
if test -n "$STRIP" && $STRIP -V 2>&1 | $GREP "GNU strip" >/dev/null; then
  test -z "$old_striplib" && old_striplib="$STRIP --strip-debug"
  test -z "$striplib" && striplib="$STRIP --strip-unneeded"
  AC_MSG_RESULT([yes])
else
# FIXME - insert some real tests, host_os isn't really good enough
  case $host_os in
  darwin*)
    if test -n "$STRIP" ; then
      striplib="$STRIP -x"
      old_striplib="$STRIP -S"
      AC_MSG_RESULT([yes])
    else
      AC_MSG_RESULT([no])
    fi
    ;;
  *)
    AC_MSG_RESULT([no])
    ;;
  esac
fi
_LT_DECL([], [old_striplib], [1], [Commands to strip libraries])
_LT_DECL([], [striplib], [1])
])# _LT_CMD_STRIPLIB


# _LT_SYS_DYNAMIC_LINKER([TAG])
# -----------------------------
# PORTME Fill in your ld.so characteristics
m4_defun([_LT_SYS_DYNAMIC_LINKER],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_OBJDUMP])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_CHECK_SHELL_FEATURES])dnl
AC_MSG_CHECKING([dynamic linker characteristics])
m4_if([$1],
	[], [
if test "$GCC" = yes; then
  case $host_os in
    darwin*) lt_awk_arg="/^libraries:/,/LR/" ;;
    *) lt_awk_arg="/^libraries:/" ;;
  esac
  case $host_os in
    mingw* | cegcc*) lt_sed_strip_eq="s,=\([[A-Za-z]]:\),\1,g" ;;
    *) lt_sed_strip_eq="s,=/,/,g" ;;
  esac
  lt_search_path_spec=`$CC -print-search-dirs | awk $lt_awk_arg | $SED -e "s/^libraries://" -e $lt_sed_strip_eq`
  case $lt_search_path_spec in
  *\;*)
    # if the path contains ";" then we assume it to be the separator
    # otherwise default to the standard path separator (i.e. ":") - it is
    # assumed that no part of a normal pathname contains ";" but that should
    # okay in the real world where ";" in dirpaths is itself problematic.
    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED 's/;/ /g'`
    ;;
  *)
    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED "s/$PATH_SEPARATOR/ /g"`
    ;;
  esac
  # Ok, now we have the path, separated by spaces, we can step through it
  # and add multilib dir if necessary.
  lt_tmp_lt_search_path_spec=
  lt_multi_os_dir=`$CC $CPPFLAGS $CFLAGS $LDFLAGS -print-multi-os-directory 2>/dev/null`
  for lt_sys_path in $lt_search_path_spec; do
    if test -d "$lt_sys_path/$lt_multi_os_dir"; then
      lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path/$lt_multi_os_dir"
    else
      test -d "$lt_sys_path" && \
	lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path"
    fi
  done
  lt_search_path_spec=`$ECHO "$lt_tmp_lt_search_path_spec" | awk '
BEGIN {RS=" "; FS="/|\n";} {
  lt_foo="";
  lt_count=0;
  for (lt_i = NF; lt_i > 0; lt_i--) {
    if ($lt_i != "" && $lt_i != ".") {
      if ($lt_i == "..") {
        lt_count++;
      } else {
        if (lt_count == 0) {
          lt_foo="/" $lt_i lt_foo;
        } else {
          lt_count--;
        }
      }
    }
  }
  if (lt_foo != "") { lt_freq[[lt_foo]]++; }
  if (lt_freq[[lt_foo]] == 1) { print lt_foo; }
}'`
  # AWK program above erroneously prepends '/' to C:/dos/paths
  # for these hosts.
  case $host_os in
    mingw* | cegcc*) lt_search_path_spec=`$ECHO "$lt_search_path_spec" |\
      $SED 's,/\([[A-Za-z]]:\),\1,g'` ;;
  esac
  sys_lib_search_path_spec=`$ECHO "$lt_search_path_spec" | $lt_NL2SP`
else
  sys_lib_search_path_spec="/lib /usr/lib /usr/local/lib"
fi])
library_names_spec=
libname_spec='lib$name'
soname_spec=
shrext_cmds=".so"
postinstall_cmds=
postuninstall_cmds=
finish_cmds=
finish_eval=
shlibpath_var=
shlibpath_overrides_runpath=unknown
version_type=none
dynamic_linker="$host_os ld.so"
sys_lib_dlsearch_path_spec="/lib /usr/lib"
need_lib_prefix=unknown
hardcode_into_libs=no

# when you set need_version to no, make sure it does not cause -set_version
# flags to be left without arguments
need_version=unknown

case $host_os in
aix3*)
  version_type=linux
  library_names_spec='${libname}${release}${shared_ext}$versuffix $libname.a'
  shlibpath_var=LIBPATH

  # AIX 3 has no versioning support, so we append a major version to the name.
  soname_spec='${libname}${release}${shared_ext}$major'
  ;;

aix[[4-9]]*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  hardcode_into_libs=yes
  if test "$host_cpu" = ia64; then
    # AIX 5 supports IA64
    library_names_spec='${libname}${release}${shared_ext}$major ${libname}${release}${shared_ext}$versuffix $libname${shared_ext}'
    shlibpath_var=LD_LIBRARY_PATH
  else
    # With GCC up to 2.95.x, collect2 would create an import file
    # for dependence libraries.  The import file would start with
    # the line `#! .'.  This would cause the generated library to
    # depend on `.', always an invalid library.  This was fixed in
    # development snapshots of GCC prior to 3.0.
    case $host_os in
      aix4 | aix4.[[01]] | aix4.[[01]].*)
      if { echo '#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 97)'
	   echo ' yes '
	   echo '#endif'; } | ${CC} -E - | $GREP yes > /dev/null; then
	:
      else
	can_build_shared=no
      fi
      ;;
    esac
    # AIX (on Power*) has no versioning support, so currently we can not hardcode correct
    # soname into executable. Probably we can add versioning support to
    # collect2, so additional links can be useful in future.
    if test "$aix_use_runtimelinking" = yes; then
      # If using run time linking (on AIX 4.2 or later) use lib<name>.so
      # instead of lib<name>.a to let people know that these are not
      # typical AIX shared libraries.
      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    else
      # We preserve .a as extension for shared libraries through AIX4.2
      # and later when we are not doing run time linking.
      library_names_spec='${libname}${release}.a $libname.a'
      soname_spec='${libname}${release}${shared_ext}$major'
    fi
    shlibpath_var=LIBPATH
  fi
  ;;

amigaos*)
  case $host_cpu in
  powerpc)
    # Since July 2007 AmigaOS4 officially supports .so libraries.
    # When compiling the executable, add -use-dynld -Lsobjs: to the compileline.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    ;;
  m68k)
    library_names_spec='$libname.ixlibrary $libname.a'
    # Create ${libname}_ixlibrary.a entries in /sys/libs.
    finish_eval='for lib in `ls $libdir/*.ixlibrary 2>/dev/null`; do libname=`func_echo_all "$lib" | $SED '\''s%^.*/\([[^/]]*\)\.ixlibrary$%\1%'\''`; test $RM /sys/libs/${libname}_ixlibrary.a; $show "cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a"; cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a || exit 1; done'
    ;;
  esac
  ;;

beos*)
  library_names_spec='${libname}${shared_ext}'
  dynamic_linker="$host_os ld.so"
  shlibpath_var=LIBRARY_PATH
  ;;

bsdi[[45]]*)
  version_type=linux
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  sys_lib_search_path_spec="/shlib /usr/lib /usr/X11/lib /usr/contrib/lib /lib /usr/local/lib"
  sys_lib_dlsearch_path_spec="/shlib /usr/lib /usr/local/lib"
  # the default ld.so.conf also contains /usr/contrib/lib and
  # /usr/X11R6/lib (/usr/X11 is a link to /usr/X11R6), but let us allow
  # libtool to hard-code these into programs
  ;;

cygwin* | mingw* | pw32* | cegcc*)
  version_type=windows
  shrext_cmds=".dll"
  need_version=no
  need_lib_prefix=no

  case $GCC,$host_os in
  yes,cygwin* | yes,mingw* | yes,pw32* | yes,cegcc*)
    library_names_spec='$libname.dll.a'
    # DLL is installed to $(libdir)/../bin by postinstall_cmds
    postinstall_cmds='base_file=`basename \${file}`~
      dlpath=`$SHELL 2>&1 -c '\''. $dir/'\''\${base_file}'\''i; echo \$dlname'\''`~
      dldir=$destdir/`dirname \$dlpath`~
      test -d \$dldir || mkdir -p \$dldir~
      $install_prog $dir/$dlname \$dldir/$dlname~
      chmod a+x \$dldir/$dlname~
      if test -n '\''$stripme'\'' && test -n '\''$striplib'\''; then
        eval '\''$striplib \$dldir/$dlname'\'' || exit \$?;
      fi'
    postuninstall_cmds='dldll=`$SHELL 2>&1 -c '\''. $file; echo \$dlname'\''`~
      dlpath=$dir/\$dldll~
       $RM \$dlpath'
    shlibpath_overrides_runpath=yes

    case $host_os in
    cygwin*)
      # Cygwin DLLs use 'cyg' prefix rather than 'lib'
      soname_spec='`echo ${libname} | sed -e 's/^lib/cyg/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
m4_if([$1], [],[
      sys_lib_search_path_spec="$sys_lib_search_path_spec /usr/lib/w32api"])
      ;;
    mingw* | cegcc*)
      # MinGW DLLs use traditional 'lib' prefix
      soname_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
      ;;
    pw32*)
      # pw32 DLLs use 'pw' prefix rather than 'lib'
      library_names_spec='`echo ${libname} | sed -e 's/^lib/pw/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
      ;;
    esac
    ;;

  *)
    library_names_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext} $libname.lib'
    ;;
  esac
  dynamic_linker='Win32 ld.exe'
  # FIXME: first we should search . and the directory the executable is in
  shlibpath_var=PATH
  ;;

darwin* | rhapsody*)
  dynamic_linker="$host_os dyld"
  version_type=darwin
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${major}$shared_ext ${libname}$shared_ext'
  soname_spec='${libname}${release}${major}$shared_ext'
  shlibpath_overrides_runpath=yes
  shlibpath_var=DYLD_LIBRARY_PATH
  shrext_cmds='`test .$module = .yes && echo .so || echo .dylib`'
m4_if([$1], [],[
  sys_lib_search_path_spec="$sys_lib_search_path_spec /usr/local/lib"])
  sys_lib_dlsearch_path_spec='/usr/local/lib /lib /usr/lib'
  ;;

dgux*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname$shared_ext'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  ;;

freebsd1*)
  dynamic_linker=no
  ;;

freebsd* | dragonfly*)
  # DragonFly does not have aout.  When/if they implement a new
  # versioning mechanism, adjust this.
  if test -x /usr/bin/objformat; then
    objformat=`/usr/bin/objformat`
  else
    case $host_os in
    freebsd[[123]]*) objformat=aout ;;
    *) objformat=elf ;;
    esac
  fi
  version_type=freebsd-$objformat
  case $version_type in
    freebsd-elf*)
      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
      need_version=no
      need_lib_prefix=no
      ;;
    freebsd-*)
      library_names_spec='${libname}${release}${shared_ext}$versuffix $libname${shared_ext}$versuffix'
      need_version=yes
      ;;
  esac
  shlibpath_var=LD_LIBRARY_PATH
  case $host_os in
  freebsd2*)
    shlibpath_overrides_runpath=yes
    ;;
  freebsd3.[[01]]* | freebsdelf3.[[01]]*)
    shlibpath_overrides_runpath=yes
    hardcode_into_libs=yes
    ;;
  freebsd3.[[2-9]]* | freebsdelf3.[[2-9]]* | \
  freebsd4.[[0-5]] | freebsdelf4.[[0-5]] | freebsd4.1.1 | freebsdelf4.1.1)
    shlibpath_overrides_runpath=no
    hardcode_into_libs=yes
    ;;
  *) # from 4.6 on, and DragonFly
    shlibpath_overrides_runpath=yes
    hardcode_into_libs=yes
    ;;
  esac
  ;;

gnu*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}${major} ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  hardcode_into_libs=yes
  ;;

haiku*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  dynamic_linker="$host_os runtime_loader"
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}${major} ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  sys_lib_dlsearch_path_spec='/boot/home/config/lib /boot/common/lib /boot/system/lib'
  hardcode_into_libs=yes
  ;;

hpux9* | hpux10* | hpux11*)
  # Give a soname corresponding to the major version so that dld.sl refuses to
  # link against other versions.
  version_type=sunos
  need_lib_prefix=no
  need_version=no
  case $host_cpu in
  ia64*)
    shrext_cmds='.so'
    hardcode_into_libs=yes
    dynamic_linker="$host_os dld.so"
    shlibpath_var=LD_LIBRARY_PATH
    shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    if test "X$HPUX_IA64_MODE" = X32; then
      sys_lib_search_path_spec="/usr/lib/hpux32 /usr/local/lib/hpux32 /usr/local/lib"
    else
      sys_lib_search_path_spec="/usr/lib/hpux64 /usr/local/lib/hpux64"
    fi
    sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
    ;;
  hppa*64*)
    shrext_cmds='.sl'
    hardcode_into_libs=yes
    dynamic_linker="$host_os dld.sl"
    shlibpath_var=LD_LIBRARY_PATH # How should we handle SHLIB_PATH
    shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    sys_lib_search_path_spec="/usr/lib/pa20_64 /usr/ccs/lib/pa20_64"
    sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
    ;;
  *)
    shrext_cmds='.sl'
    dynamic_linker="$host_os dld.sl"
    shlibpath_var=SHLIB_PATH
    shlibpath_overrides_runpath=no # +s is required to enable SHLIB_PATH
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    ;;
  esac
  # HP-UX runs *really* slowly unless shared libraries are mode 555, ...
  postinstall_cmds='chmod 555 $lib'
  # or fails outright, so override atomically:
  install_override_mode=555
  ;;

interix[[3-9]]*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  dynamic_linker='Interix 3.x ld.so.1 (PE, like ELF)'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  ;;

irix5* | irix6* | nonstopux*)
  case $host_os in
    nonstopux*) version_type=nonstopux ;;
    *)
	if test "$lt_cv_prog_gnu_ld" = yes; then
		version_type=linux
	else
		version_type=irix
	fi ;;
  esac
  need_lib_prefix=no
  need_version=no
  soname_spec='${libname}${release}${shared_ext}$major'
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${release}${shared_ext} $libname${shared_ext}'
  case $host_os in
  irix5* | nonstopux*)
    libsuff= shlibsuff=
    ;;
  *)
    case $LD in # libtool.m4 will add one of these switches to LD
    *-32|*"-32 "|*-melf32bsmip|*"-melf32bsmip ")
      libsuff= shlibsuff= libmagic=32-bit;;
    *-n32|*"-n32 "|*-melf32bmipn32|*"-melf32bmipn32 ")
      libsuff=32 shlibsuff=N32 libmagic=N32;;
    *-64|*"-64 "|*-melf64bmip|*"-melf64bmip ")
      libsuff=64 shlibsuff=64 libmagic=64-bit;;
    *) libsuff= shlibsuff= libmagic=never-match;;
    esac
    ;;
  esac
  shlibpath_var=LD_LIBRARY${shlibsuff}_PATH
  shlibpath_overrides_runpath=no
  sys_lib_search_path_spec="/usr/lib${libsuff} /lib${libsuff} /usr/local/lib${libsuff}"
  sys_lib_dlsearch_path_spec="/usr/lib${libsuff} /lib${libsuff}"
  hardcode_into_libs=yes
  ;;

# No shared lib support for Linux oldld, aout, or coff.
linux*oldld* | linux*aout* | linux*coff*)
  dynamic_linker=no
  ;;

# This must be Linux ELF.
linux* | k*bsd*-gnu | kopensolaris*-gnu)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig -n $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no

  # Some binutils ld are patched to set DT_RUNPATH
  AC_CACHE_VAL([lt_cv_shlibpath_overrides_runpath],
    [lt_cv_shlibpath_overrides_runpath=no
    save_LDFLAGS=$LDFLAGS
    save_libdir=$libdir
    eval "libdir=/foo; wl=\"$_LT_TAGVAR(lt_prog_compiler_wl, $1)\"; \
	 LDFLAGS=\"\$LDFLAGS $_LT_TAGVAR(hardcode_libdir_flag_spec, $1)\""
    AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
      [AS_IF([ ($OBJDUMP -p conftest$ac_exeext) 2>/dev/null | grep "RUNPATH.*$libdir" >/dev/null],
	 [lt_cv_shlibpath_overrides_runpath=yes])])
    LDFLAGS=$save_LDFLAGS
    libdir=$save_libdir
    ])
  shlibpath_overrides_runpath=$lt_cv_shlibpath_overrides_runpath

  # This implies no fast_install, which is unacceptable.
  # Some rework will be needed to allow for fast_install
  # before this can be enabled.
  hardcode_into_libs=yes

  # Append ld.so.conf contents to the search path
  if test -f /etc/ld.so.conf; then
    lt_ld_extra=`awk '/^include / { system(sprintf("cd /etc; cat %s 2>/dev/null", \[$]2)); skip = 1; } { if (!skip) print \[$]0; skip = 0; }' < /etc/ld.so.conf | $SED -e 's/#.*//;/^[	 ]*hwcap[	 ]/d;s/[:,	]/ /g;s/=[^=]*$//;s/=[^= ]* / /g;s/"//g;/^$/d' | tr '\n' ' '`
    sys_lib_dlsearch_path_spec="/lib /usr/lib $lt_ld_extra"
  fi

  # We used to test for /lib/ld.so.1 and disable shared libraries on
  # powerpc, because MkLinux only supported shared libraries with the
  # GNU dynamic linker.  Since this was broken with cross compilers,
  # most powerpc-linux boxes support dynamic linking these days and
  # people can always --disable-shared, the test was removed, and we
  # assume the GNU/Linux dynamic linker is in use.
  dynamic_linker='GNU/Linux ld.so'
  ;;

netbsd*)
  version_type=sunos
  need_lib_prefix=no
  need_version=no
  if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
    finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
    dynamic_linker='NetBSD (a.out) ld.so'
  else
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    dynamic_linker='NetBSD ld.elf_so'
  fi
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  ;;

newsos6)
  version_type=linux
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  ;;

*nto* | *qnx*)
  version_type=qnx
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  dynamic_linker='ldqnx.so'
  ;;

openbsd*)
  version_type=sunos
  sys_lib_dlsearch_path_spec="/usr/lib"
  need_lib_prefix=no
  # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
  case $host_os in
    openbsd3.3 | openbsd3.3.*)	need_version=yes ;;
    *)				need_version=no  ;;
  esac
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
    case $host_os in
      openbsd2.[[89]] | openbsd2.[[89]].*)
	shlibpath_overrides_runpath=no
	;;
      *)
	shlibpath_overrides_runpath=yes
	;;
      esac
  else
    shlibpath_overrides_runpath=yes
  fi
  ;;

os2*)
  libname_spec='$name'
  shrext_cmds=".dll"
  need_lib_prefix=no
  library_names_spec='$libname${shared_ext} $libname.a'
  dynamic_linker='OS/2 ld.exe'
  shlibpath_var=LIBPATH
  ;;

osf3* | osf4* | osf5*)
  version_type=osf
  need_lib_prefix=no
  need_version=no
  soname_spec='${libname}${release}${shared_ext}$major'
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  sys_lib_search_path_spec="/usr/shlib /usr/ccs/lib /usr/lib/cmplrs/cc /usr/lib /usr/local/lib /var/shlib"
  sys_lib_dlsearch_path_spec="$sys_lib_search_path_spec"
  ;;

rdos*)
  dynamic_linker=no
  ;;

solaris*)
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  # ldd complains unless libraries are executable
  postinstall_cmds='chmod +x $lib'
  ;;

sunos4*)
  version_type=sunos
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
  finish_cmds='PATH="\$PATH:/usr/etc" ldconfig $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  if test "$with_gnu_ld" = yes; then
    need_lib_prefix=no
  fi
  need_version=yes
  ;;

sysv4 | sysv4.3*)
  version_type=linux
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  case $host_vendor in
    sni)
      shlibpath_overrides_runpath=no
      need_lib_prefix=no
      runpath_var=LD_RUN_PATH
      ;;
    siemens)
      need_lib_prefix=no
      ;;
    motorola)
      need_lib_prefix=no
      need_version=no
      shlibpath_overrides_runpath=no
      sys_lib_search_path_spec='/lib /usr/lib /usr/ccs/lib'
      ;;
  esac
  ;;

sysv4*MP*)
  if test -d /usr/nec ;then
    version_type=linux
    library_names_spec='$libname${shared_ext}.$versuffix $libname${shared_ext}.$major $libname${shared_ext}'
    soname_spec='$libname${shared_ext}.$major'
    shlibpath_var=LD_LIBRARY_PATH
  fi
  ;;

sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
  version_type=freebsd-elf
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  if test "$with_gnu_ld" = yes; then
    sys_lib_search_path_spec='/usr/local/lib /usr/gnu/lib /usr/ccs/lib /usr/lib /lib'
  else
    sys_lib_search_path_spec='/usr/ccs/lib /usr/lib'
    case $host_os in
      sco3.2v5*)
        sys_lib_search_path_spec="$sys_lib_search_path_spec /lib"
	;;
    esac
  fi
  sys_lib_dlsearch_path_spec='/usr/lib'
  ;;

tpf*)
  # TPF is a cross-target only.  Preferred cross-host = GNU/Linux.
  version_type=linux
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  ;;

uts4*)
  version_type=linux
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  ;;

*)
  dynamic_linker=no
  ;;
esac
AC_MSG_RESULT([$dynamic_linker])
test "$dynamic_linker" = no && can_build_shared=no

variables_saved_for_relink="PATH $shlibpath_var $runpath_var"
if test "$GCC" = yes; then
  variables_saved_for_relink="$variables_saved_for_relink GCC_EXEC_PREFIX COMPILER_PATH LIBRARY_PATH"
fi

if test "${lt_cv_sys_lib_search_path_spec+set}" = set; then
  sys_lib_search_path_spec="$lt_cv_sys_lib_search_path_spec"
fi
if test "${lt_cv_sys_lib_dlsearch_path_spec+set}" = set; then
  sys_lib_dlsearch_path_spec="$lt_cv_sys_lib_dlsearch_path_spec"
fi

_LT_DECL([], [variables_saved_for_relink], [1],
    [Variables whose values should be saved in libtool wrapper scripts and
    restored at link time])
_LT_DECL([], [need_lib_prefix], [0],
    [Do we need the "lib" prefix for modules?])
_LT_DECL([], [need_version], [0], [Do we need a version for libraries?])
_LT_DECL([], [version_type], [0], [Library versioning type])
_LT_DECL([], [runpath_var], [0],  [Shared library runtime path variable])
_LT_DECL([], [shlibpath_var], [0],[Shared library path variable])
_LT_DECL([], [shlibpath_overrides_runpath], [0],
    [Is shlibpath searched before the hard-coded library search path?])
_LT_DECL([], [libname_spec], [1], [Format of library name prefix])
_LT_DECL([], [library_names_spec], [1],
    [[List of archive names.  First name is the real one, the rest are links.
    The last name is the one that the linker finds with -lNAME]])
_LT_DECL([], [soname_spec], [1],
    [[The coded name of the library, if different from the real name]])
_LT_DECL([], [install_override_mode], [1],
    [Permission mode override for installation of shared libraries])
_LT_DECL([], [postinstall_cmds], [2],
    [Command to use after installation of a shared archive])
_LT_DECL([], [postuninstall_cmds], [2],
    [Command to use after uninstallation of a shared archive])
_LT_DECL([], [finish_cmds], [2],
    [Commands used to finish a libtool library installation in a directory])
_LT_DECL([], [finish_eval], [1],
    [[As "finish_cmds", except a single script fragment to be evaled but
    not shown]])
_LT_DECL([], [hardcode_into_libs], [0],
    [Whether we should hardcode library paths into libraries])
_LT_DECL([], [sys_lib_search_path_spec], [2],
    [Compile-time system search path for libraries])
_LT_DECL([], [sys_lib_dlsearch_path_spec], [2],
    [Run-time system search path for libraries])
])# _LT_SYS_DYNAMIC_LINKER


# _LT_PATH_TOOL_PREFIX(TOOL)
# --------------------------
# find a file program which can recognize shared library
AC_DEFUN([_LT_PATH_TOOL_PREFIX],
[m4_require([_LT_DECL_EGREP])dnl
AC_MSG_CHECKING([for $1])
AC_CACHE_VAL(lt_cv_path_MAGIC_CMD,
[case $MAGIC_CMD in
[[\\/*] |  ?:[\\/]*])
  lt_cv_path_MAGIC_CMD="$MAGIC_CMD" # Let the user override the test with a path.
  ;;
*)
  lt_save_MAGIC_CMD="$MAGIC_CMD"
  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
dnl $ac_dummy forces splitting on constant user-supplied paths.
dnl POSIX.2 word splitting is done only on the output of word expansions,
dnl not every word.  This closes a longstanding sh security hole.
  ac_dummy="m4_if([$2], , $PATH, [$2])"
  for ac_dir in $ac_dummy; do
    IFS="$lt_save_ifs"
    test -z "$ac_dir" && ac_dir=.
    if test -f $ac_dir/$1; then
      lt_cv_path_MAGIC_CMD="$ac_dir/$1"
      if test -n "$file_magic_test_file"; then
	case $deplibs_check_method in
	"file_magic "*)
	  file_magic_regex=`expr "$deplibs_check_method" : "file_magic \(.*\)"`
	  MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
	  if eval $file_magic_cmd \$file_magic_test_file 2> /dev/null |
	    $EGREP "$file_magic_regex" > /dev/null; then
	    :
	  else
	    cat <<_LT_EOF 1>&2

*** Warning: the command libtool uses to detect shared libraries,
*** $file_magic_cmd, produces output that libtool cannot recognize.
*** The result is that libtool may fail to recognize shared libraries
*** as such.  This will affect the creation of libtool libraries that
*** depend on shared libraries, but programs linked with such libtool
*** libraries will work regardless of this problem.  Nevertheless, you
*** may want to report the problem to your system manager and/or to
*** bug-libtool@gnu.org

_LT_EOF
	  fi ;;
	esac
      fi
      break
    fi
  done
  IFS="$lt_save_ifs"
  MAGIC_CMD="$lt_save_MAGIC_CMD"
  ;;
esac])
MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
if test -n "$MAGIC_CMD"; then
  AC_MSG_RESULT($MAGIC_CMD)
else
  AC_MSG_RESULT(no)
fi
_LT_DECL([], [MAGIC_CMD], [0],
	 [Used to examine libraries when file_magic_cmd begins with "file"])dnl
])# _LT_PATH_TOOL_PREFIX

# Old name:
AU_ALIAS([AC_PATH_TOOL_PREFIX], [_LT_PATH_TOOL_PREFIX])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_PATH_TOOL_PREFIX], [])


# _LT_PATH_MAGIC
# --------------
# find a file program which can recognize a shared library
m4_defun([_LT_PATH_MAGIC],
[_LT_PATH_TOOL_PREFIX(${ac_tool_prefix}file, /usr/bin$PATH_SEPARATOR$PATH)
if test -z "$lt_cv_path_MAGIC_CMD"; then
  if test -n "$ac_tool_prefix"; then
    _LT_PATH_TOOL_PREFIX(file, /usr/bin$PATH_SEPARATOR$PATH)
  else
    MAGIC_CMD=:
  fi
fi
])# _LT_PATH_MAGIC


# LT_PATH_LD
# ----------
# find the pathname to the GNU or non-GNU linker
AC_DEFUN([LT_PATH_LD],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_CANONICAL_BUILD])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_PROG_ECHO_BACKSLASH])dnl

AC_ARG_WITH([gnu-ld],
    [AS_HELP_STRING([--with-gnu-ld],
	[assume the C compiler uses GNU ld @<:@default=no@:>@])],
    [test "$withval" = no || with_gnu_ld=yes],
    [with_gnu_ld=no])dnl

ac_prog=ld
if test "$GCC" = yes; then
  # Check if gcc -print-prog-name=ld gives a path.
  AC_MSG_CHECKING([for ld used by $CC])
  case $host in
  *-*-mingw*)
    # gcc leaves a trailing carriage return which upsets mingw
    ac_prog=`($CC -print-prog-name=ld) 2>&5 | tr -d '\015'` ;;
  *)
    ac_prog=`($CC -print-prog-name=ld) 2>&5` ;;
  esac
  case $ac_prog in
    # Accept absolute paths.
    [[\\/]]* | ?:[[\\/]]*)
      re_direlt='/[[^/]][[^/]]*/\.\./'
      # Canonicalize the pathname of ld
      ac_prog=`$ECHO "$ac_prog"| $SED 's%\\\\%/%g'`
      while $ECHO "$ac_prog" | $GREP "$re_direlt" > /dev/null 2>&1; do
	ac_prog=`$ECHO $ac_prog| $SED "s%$re_direlt%/%"`
      done
      test -z "$LD" && LD="$ac_prog"
      ;;
  "")
    # If it fails, then pretend we aren't using GCC.
    ac_prog=ld
    ;;
  *)
    # If it is relative, then search for the first ld in PATH.
    with_gnu_ld=unknown
    ;;
  esac
elif test "$with_gnu_ld" = yes; then
  AC_MSG_CHECKING([for GNU ld])
else
  AC_MSG_CHECKING([for non-GNU ld])
fi
AC_CACHE_VAL(lt_cv_path_LD,
[if test -z "$LD"; then
  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
  for ac_dir in $PATH; do
    IFS="$lt_save_ifs"
    test -z "$ac_dir" && ac_dir=.
    if test -f "$ac_dir/$ac_prog" || test -f "$ac_dir/$ac_prog$ac_exeext"; then
      lt_cv_path_LD="$ac_dir/$ac_prog"
      # Check to see if the program is GNU ld.  I'd rather use --version,
      # but apparently some variants of GNU ld only accept -v.
      # Break only if it was the GNU/non-GNU ld that we prefer.
      case `"$lt_cv_path_LD" -v 2>&1 </dev/null` in
      *GNU* | *'with BFD'*)
	test "$with_gnu_ld" != no && break
	;;
      *)
	test "$with_gnu_ld" != yes && break
	;;
      esac
    fi
  done
  IFS="$lt_save_ifs"
else
  lt_cv_path_LD="$LD" # Let the user override the test with a path.
fi])
LD="$lt_cv_path_LD"
if test -n "$LD"; then
  AC_MSG_RESULT($LD)
else
  AC_MSG_RESULT(no)
fi
test -z "$LD" && AC_MSG_ERROR([no acceptable ld found in \$PATH])
_LT_PATH_LD_GNU
AC_SUBST([LD])

_LT_TAGDECL([], [LD], [1], [The linker used to build libraries])
])# LT_PATH_LD

# Old names:
AU_ALIAS([AM_PROG_LD], [LT_PATH_LD])
AU_ALIAS([AC_PROG_LD], [LT_PATH_LD])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_PROG_LD], [])
dnl AC_DEFUN([AC_PROG_LD], [])


# _LT_PATH_LD_GNU
#- --------------
m4_defun([_LT_PATH_LD_GNU],
[AC_CACHE_CHECK([if the linker ($LD) is GNU ld], lt_cv_prog_gnu_ld,
[# I'd rather use --version here, but apparently some GNU lds only accept -v.
case `$LD -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  lt_cv_prog_gnu_ld=yes
  ;;
*)
  lt_cv_prog_gnu_ld=no
  ;;
esac])
with_gnu_ld=$lt_cv_prog_gnu_ld
])# _LT_PATH_LD_GNU


# _LT_CMD_RELOAD
# --------------
# find reload flag for linker
#   -- PORTME Some linkers may need a different reload flag.
m4_defun([_LT_CMD_RELOAD],
[AC_CACHE_CHECK([for $LD option to reload object files],
  lt_cv_ld_reload_flag,
  [lt_cv_ld_reload_flag='-r'])
reload_flag=$lt_cv_ld_reload_flag
case $reload_flag in
"" | " "*) ;;
*) reload_flag=" $reload_flag" ;;
esac
reload_cmds='$LD$reload_flag -o $output$reload_objs'
case $host_os in
  darwin*)
    if test "$GCC" = yes; then
      reload_cmds='$LTCC $LTCFLAGS -nostdlib ${wl}-r -o $output$reload_objs'
    else
      reload_cmds='$LD$reload_flag -o $output$reload_objs'
    fi
    ;;
esac
_LT_TAGDECL([], [reload_flag], [1], [How to create reloadable object files])dnl
_LT_TAGDECL([], [reload_cmds], [2])dnl
])# _LT_CMD_RELOAD


# _LT_CHECK_MAGIC_METHOD
# ----------------------
# how to check for library dependencies
#  -- PORTME fill in with the dynamic library characteristics
m4_defun([_LT_CHECK_MAGIC_METHOD],
[m4_require([_LT_DECL_EGREP])
m4_require([_LT_DECL_OBJDUMP])
AC_CACHE_CHECK([how to recognize dependent libraries],
lt_cv_deplibs_check_method,
[lt_cv_file_magic_cmd='$MAGIC_CMD'
lt_cv_file_magic_test_file=
lt_cv_deplibs_check_method='unknown'
# Need to set the preceding variable on all platforms that support
# interlibrary dependencies.
# 'none' -- dependencies not supported.
# `unknown' -- same as none, but documents that we really don't know.
# 'pass_all' -- all dependencies passed with no checks.
# 'test_compile' -- check by making test program.
# 'file_magic [[regex]]' -- check by looking for files in library path
# which responds to the $file_magic_cmd with a given extended regex.
# If you have `file' or equivalent on your system and you're not sure
# whether `pass_all' will *always* work, you probably want this one.

case $host_os in
aix[[4-9]]*)
  lt_cv_deplibs_check_method=pass_all
  ;;

beos*)
  lt_cv_deplibs_check_method=pass_all
  ;;

bsdi[[45]]*)
  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib)'
  lt_cv_file_magic_cmd='/usr/bin/file -L'
  lt_cv_file_magic_test_file=/shlib/libc.so
  ;;

cygwin*)
  # func_win32_libid is a shell function defined in ltmain.sh
  lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
  lt_cv_file_magic_cmd='func_win32_libid'
  ;;

mingw* | pw32*)
  # Base MSYS/MinGW do not provide the 'file' command needed by
  # func_win32_libid shell function, so use a weaker test based on 'objdump',
  # unless we find 'file', for example because we are cross-compiling.
  # func_win32_libid assumes BSD nm, so disallow it if using MS dumpbin.
  if ( test "$lt_cv_nm_interface" = "BSD nm" && file / ) >/dev/null 2>&1; then
    lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
    lt_cv_file_magic_cmd='func_win32_libid'
  else
    # Keep this pattern in sync with the one in func_win32_libid.
    lt_cv_deplibs_check_method='file_magic file format (pei*-i386(.*architecture: i386)?|pe-arm-wince|pe-x86-64)'
    lt_cv_file_magic_cmd='$OBJDUMP -f'
  fi
  ;;

cegcc*)
  # use the weaker test based on 'objdump'. See mingw*.
  lt_cv_deplibs_check_method='file_magic file format pe-arm-.*little(.*architecture: arm)?'
  lt_cv_file_magic_cmd='$OBJDUMP -f'
  ;;

darwin* | rhapsody*)
  lt_cv_deplibs_check_method=pass_all
  ;;

freebsd* | dragonfly*)
  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
    case $host_cpu in
    i*86 )
      # Not sure whether the presence of OpenBSD here was a mistake.
      # Let's accept both of them until this is cleared up.
      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD|DragonFly)/i[[3-9]]86 (compact )?demand paged shared library'
      lt_cv_file_magic_cmd=/usr/bin/file
      lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
      ;;
    esac
  else
    lt_cv_deplibs_check_method=pass_all
  fi
  ;;

gnu*)
  lt_cv_deplibs_check_method=pass_all
  ;;

haiku*)
  lt_cv_deplibs_check_method=pass_all
  ;;

hpux10.20* | hpux11*)
  lt_cv_file_magic_cmd=/usr/bin/file
  case $host_cpu in
  ia64*)
    lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|ELF-[[0-9]][[0-9]]) shared object file - IA64'
    lt_cv_file_magic_test_file=/usr/lib/hpux32/libc.so
    ;;
  hppa*64*)
    [lt_cv_deplibs_check_method='file_magic (s[0-9][0-9][0-9]|ELF[ -][0-9][0-9])(-bit)?( [LM]SB)? shared object( file)?[, -]* PA-RISC [0-9]\.[0-9]']
    lt_cv_file_magic_test_file=/usr/lib/pa20_64/libc.sl
    ;;
  *)
    lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|PA-RISC[[0-9]]\.[[0-9]]) shared library'
    lt_cv_file_magic_test_file=/usr/lib/libc.sl
    ;;
  esac
  ;;

interix[[3-9]]*)
  # PIC code is broken on Interix 3.x, that's why |\.a not |_pic\.a here
  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
  ;;

irix5* | irix6* | nonstopux*)
  case $LD in
  *-32|*"-32 ") libmagic=32-bit;;
  *-n32|*"-n32 ") libmagic=N32;;
  *-64|*"-64 ") libmagic=64-bit;;
  *) libmagic=never-match;;
  esac
  lt_cv_deplibs_check_method=pass_all
  ;;

# This must be Linux ELF.
linux* | k*bsd*-gnu | kopensolaris*-gnu)
  lt_cv_deplibs_check_method=pass_all
  ;;

netbsd*)
  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
  else
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
  fi
  ;;

newos6*)
  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (executable|dynamic lib)'
  lt_cv_file_magic_cmd=/usr/bin/file
  lt_cv_file_magic_test_file=/usr/lib/libnls.so
  ;;

*nto* | *qnx*)
  lt_cv_deplibs_check_method=pass_all
  ;;

openbsd*)
  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|\.so|_pic\.a)$'
  else
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
  fi
  ;;

osf3* | osf4* | osf5*)
  lt_cv_deplibs_check_method=pass_all
  ;;

rdos*)
  lt_cv_deplibs_check_method=pass_all
  ;;

solaris*)
  lt_cv_deplibs_check_method=pass_all
  ;;

sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
  lt_cv_deplibs_check_method=pass_all
  ;;

sysv4 | sysv4.3*)
  case $host_vendor in
  motorola)
    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib) M[[0-9]][[0-9]]* Version [[0-9]]'
    lt_cv_file_magic_test_file=`echo /usr/lib/libc.so*`
    ;;
  ncr)
    lt_cv_deplibs_check_method=pass_all
    ;;
  sequent)
    lt_cv_file_magic_cmd='/bin/file'
    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB (shared object|dynamic lib )'
    ;;
  sni)
    lt_cv_file_magic_cmd='/bin/file'
    lt_cv_deplibs_check_method="file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB dynamic lib"
    lt_cv_file_magic_test_file=/lib/libc.so
    ;;
  siemens)
    lt_cv_deplibs_check_method=pass_all
    ;;
  pc)
    lt_cv_deplibs_check_method=pass_all
    ;;
  esac
  ;;

tpf*)
  lt_cv_deplibs_check_method=pass_all
  ;;
esac
])
file_magic_cmd=$lt_cv_file_magic_cmd
deplibs_check_method=$lt_cv_deplibs_check_method
test -z "$deplibs_check_method" && deplibs_check_method=unknown

_LT_DECL([], [deplibs_check_method], [1],
    [Method to check whether dependent libraries are shared objects])
_LT_DECL([], [file_magic_cmd], [1],
    [Command to use when deplibs_check_method == "file_magic"])
])# _LT_CHECK_MAGIC_METHOD


# LT_PATH_NM
# ----------
# find the pathname to a BSD- or MS-compatible name lister
AC_DEFUN([LT_PATH_NM],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_CACHE_CHECK([for BSD- or MS-compatible name lister (nm)], lt_cv_path_NM,
[if test -n "$NM"; then
  # Let the user override the test.
  lt_cv_path_NM="$NM"
else
  lt_nm_to_check="${ac_tool_prefix}nm"
  if test -n "$ac_tool_prefix" && test "$build" = "$host"; then
    lt_nm_to_check="$lt_nm_to_check nm"
  fi
  for lt_tmp_nm in $lt_nm_to_check; do
    lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
    for ac_dir in $PATH /usr/ccs/bin/elf /usr/ccs/bin /usr/ucb /bin; do
      IFS="$lt_save_ifs"
      test -z "$ac_dir" && ac_dir=.
      tmp_nm="$ac_dir/$lt_tmp_nm"
      if test -f "$tmp_nm" || test -f "$tmp_nm$ac_exeext" ; then
	# Check to see if the nm accepts a BSD-compat flag.
	# Adding the `sed 1q' prevents false positives on HP-UX, which says:
	#   nm: unknown option "B" ignored
	# Tru64's nm complains that /dev/null is an invalid object file
	case `"$tmp_nm" -B /dev/null 2>&1 | sed '1q'` in
	*/dev/null* | *'Invalid file or object type'*)
	  lt_cv_path_NM="$tmp_nm -B"
	  break
	  ;;
	*)
	  case `"$tmp_nm" -p /dev/null 2>&1 | sed '1q'` in
	  */dev/null*)
	    lt_cv_path_NM="$tmp_nm -p"
	    break
	    ;;
	  *)
	    lt_cv_path_NM=${lt_cv_path_NM="$tmp_nm"} # keep the first match, but
	    continue # so that we can try to find one that supports BSD flags
	    ;;
	  esac
	  ;;
	esac
      fi
    done
    IFS="$lt_save_ifs"
  done
  : ${lt_cv_path_NM=no}
fi])
if test "$lt_cv_path_NM" != "no"; then
  NM="$lt_cv_path_NM"
else
  # Didn't find any BSD compatible name lister, look for dumpbin.
  if test -n "$DUMPBIN"; then :
    # Let the user override the test.
  else
    AC_CHECK_TOOLS(DUMPBIN, [dumpbin "link -dump"], :)
    case `$DUMPBIN -symbols /dev/null 2>&1 | sed '1q'` in
    *COFF*)
      DUMPBIN="$DUMPBIN -symbols"
      ;;
    *)
      DUMPBIN=:
      ;;
    esac
  fi
  AC_SUBST([DUMPBIN])
  if test "$DUMPBIN" != ":"; then
    NM="$DUMPBIN"
  fi
fi
test -z "$NM" && NM=nm
AC_SUBST([NM])
_LT_DECL([], [NM], [1], [A BSD- or MS-compatible name lister])dnl

AC_CACHE_CHECK([the name lister ($NM) interface], [lt_cv_nm_interface],
  [lt_cv_nm_interface="BSD nm"
  echo "int some_variable = 0;" > conftest.$ac_ext
  (eval echo "\"\$as_me:$LINENO: $ac_compile\"" >&AS_MESSAGE_LOG_FD)
  (eval "$ac_compile" 2>conftest.err)
  cat conftest.err >&AS_MESSAGE_LOG_FD
  (eval echo "\"\$as_me:$LINENO: $NM \\\"conftest.$ac_objext\\\"\"" >&AS_MESSAGE_LOG_FD)
  (eval "$NM \"conftest.$ac_objext\"" 2>conftest.err > conftest.out)
  cat conftest.err >&AS_MESSAGE_LOG_FD
  (eval echo "\"\$as_me:$LINENO: output\"" >&AS_MESSAGE_LOG_FD)
  cat conftest.out >&AS_MESSAGE_LOG_FD
  if $GREP 'External.*some_variable' conftest.out > /dev/null; then
    lt_cv_nm_interface="MS dumpbin"
  fi
  rm -f conftest*])
])# LT_PATH_NM

# Old names:
AU_ALIAS([AM_PROG_NM], [LT_PATH_NM])
AU_ALIAS([AC_PROG_NM], [LT_PATH_NM])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_PROG_NM], [])
dnl AC_DEFUN([AC_PROG_NM], [])


# LT_LIB_M
# --------
# check for math library
AC_DEFUN([LT_LIB_M],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
LIBM=
case $host in
*-*-beos* | *-*-cegcc* | *-*-cygwin* | *-*-haiku* | *-*-pw32* | *-*-darwin*)
  # These system don't have libm, or don't need it
  ;;
*-ncr-sysv4.3*)
  AC_CHECK_LIB(mw, _mwvalidcheckl, LIBM="-lmw")
  AC_CHECK_LIB(m, cos, LIBM="$LIBM -lm")
  ;;
*)
  AC_CHECK_LIB(m, cos, LIBM="-lm")
  ;;
esac
AC_SUBST([LIBM])
])# LT_LIB_M

# Old name:
AU_ALIAS([AC_CHECK_LIBM], [LT_LIB_M])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_CHECK_LIBM], [])


# _LT_COMPILER_NO_RTTI([TAGNAME])
# -------------------------------
m4_defun([_LT_COMPILER_NO_RTTI],
[m4_require([_LT_TAG_COMPILER])dnl

_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=

if test "$GCC" = yes; then
  case $cc_basename in
  nvcc*)
    _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -Xcompiler -fno-builtin' ;;
  *)
    _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin' ;;
  esac

  _LT_COMPILER_OPTION([if $compiler supports -fno-rtti -fno-exceptions],
    lt_cv_prog_compiler_rtti_exceptions,
    [-fno-rtti -fno-exceptions], [],
    [_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)="$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) -fno-rtti -fno-exceptions"])
fi
_LT_TAGDECL([no_builtin_flag], [lt_prog_compiler_no_builtin_flag], [1],
	[Compiler flag to turn off builtin functions])
])# _LT_COMPILER_NO_RTTI


# _LT_CMD_GLOBAL_SYMBOLS
# ----------------------
m4_defun([_LT_CMD_GLOBAL_SYMBOLS],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_PROG_AWK])dnl
AC_REQUIRE([LT_PATH_NM])dnl
AC_REQUIRE([LT_PATH_LD])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_TAG_COMPILER])dnl

# Check for command to grab the raw symbol name followed by C symbol from nm.
AC_MSG_CHECKING([command to parse $NM output from $compiler object])
AC_CACHE_VAL([lt_cv_sys_global_symbol_pipe],
[
# These are sane defaults that work on at least a few old systems.
# [They come from Ultrix.  What could be older than Ultrix?!! ;)]

# Character class describing NM global symbol codes.
symcode='[[BCDEGRST]]'

# Regexp to match symbols that can be accessed directly from C.
sympat='\([[_A-Za-z]][[_A-Za-z0-9]]*\)'

# Define system-specific variables.
case $host_os in
aix*)
  symcode='[[BCDT]]'
  ;;
cygwin* | mingw* | pw32* | cegcc*)
  symcode='[[ABCDGISTW]]'
  ;;
hpux*)
  if test "$host_cpu" = ia64; then
    symcode='[[ABCDEGRST]]'
  fi
  ;;
irix* | nonstopux*)
  symcode='[[BCDEGRST]]'
  ;;
osf*)
  symcode='[[BCDEGQRST]]'
  ;;
solaris*)
  symcode='[[BDRT]]'
  ;;
sco3.2v5*)
  symcode='[[DT]]'
  ;;
sysv4.2uw2*)
  symcode='[[DT]]'
  ;;
sysv5* | sco5v6* | unixware* | OpenUNIX*)
  symcode='[[ABDT]]'
  ;;
sysv4)
  symcode='[[DFNSTU]]'
  ;;
esac

# If we're using GNU nm, then use its standard symbol codes.
case `$NM -V 2>&1` in
*GNU* | *'with BFD'*)
  symcode='[[ABCDGIRSTW]]' ;;
esac

# Transform an extracted symbol line into a proper C declaration.
# Some systems (esp. on ia64) link data and code symbols differently,
# so use this general approach.
lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^T .* \(.*\)$/extern int \1();/p' -e 's/^$symcode* .* \(.*\)$/extern char \1;/p'"

# Transform an extracted symbol line into symbol name and symbol address
lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p'"
lt_cv_sys_global_symbol_to_c_name_address_lib_prefix="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \(lib[[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"lib\2\", (void *) \&\2},/p'"

# Handle CRLF in mingw tool chain
opt_cr=
case $build_os in
mingw*)
  opt_cr=`$ECHO 'x\{0,1\}' | tr x '\015'` # option cr in regexp
  ;;
esac

# Try without a prefix underscore, then with it.
for ac_symprfx in "" "_"; do

  # Transform symcode, sympat, and symprfx into a raw symbol and a C symbol.
  symxfrm="\\1 $ac_symprfx\\2 \\2"

  # Write the raw and C identifiers.
  if test "$lt_cv_nm_interface" = "MS dumpbin"; then
    # Fake it for dumpbin and say T for any non-static function
    # and D for any global variable.
    # Also find C++ and __fastcall symbols from MSVC++,
    # which start with @ or ?.
    lt_cv_sys_global_symbol_pipe="$AWK ['"\
"     {last_section=section; section=\$ 3};"\
"     /Section length .*#relocs.*(pick any)/{hide[last_section]=1};"\
"     \$ 0!~/External *\|/{next};"\
"     / 0+ UNDEF /{next}; / UNDEF \([^|]\)*()/{next};"\
"     {if(hide[section]) next};"\
"     {f=0}; \$ 0~/\(\).*\|/{f=1}; {printf f ? \"T \" : \"D \"};"\
"     {split(\$ 0, a, /\||\r/); split(a[2], s)};"\
"     s[1]~/^[@?]/{print s[1], s[1]; next};"\
"     s[1]~prfx {split(s[1],t,\"@\"); print t[1], substr(t[1],length(prfx))}"\
"     ' prfx=^$ac_symprfx]"
  else
    lt_cv_sys_global_symbol_pipe="sed -n -e 's/^.*[[	 ]]\($symcode$symcode*\)[[	 ]][[	 ]]*$ac_symprfx$sympat$opt_cr$/$symxfrm/p'"
  fi

  # Check to see that the pipe works correctly.
  pipe_works=no

  rm -f conftest*
  cat > conftest.$ac_ext <<_LT_EOF
#ifdef __cplusplus
extern "C" {
#endif
char nm_test_var;
void nm_test_func(void);
void nm_test_func(void){}
#ifdef __cplusplus
}
#endif
int main(){nm_test_var='a';nm_test_func();return(0);}
_LT_EOF

  if AC_TRY_EVAL(ac_compile); then
    # Now try to grab the symbols.
    nlist=conftest.nm
    if AC_TRY_EVAL(NM conftest.$ac_objext \| "$lt_cv_sys_global_symbol_pipe" \> $nlist) && test -s "$nlist"; then
      # Try sorting and uniquifying the output.
      if sort "$nlist" | uniq > "$nlist"T; then
	mv -f "$nlist"T "$nlist"
      else
	rm -f "$nlist"T
      fi

      # Make sure that we snagged all the symbols we need.
      if $GREP ' nm_test_var$' "$nlist" >/dev/null; then
	if $GREP ' nm_test_func$' "$nlist" >/dev/null; then
	  cat <<_LT_EOF > conftest.$ac_ext
#ifdef __cplusplus
extern "C" {
#endif

_LT_EOF
	  # Now generate the symbol file.
	  eval "$lt_cv_sys_global_symbol_to_cdecl"' < "$nlist" | $GREP -v main >> conftest.$ac_ext'

	  cat <<_LT_EOF >> conftest.$ac_ext

/* The mapping between symbol names and symbols.  */
const struct {
  const char *name;
  void       *address;
}
lt__PROGRAM__LTX_preloaded_symbols[[]] =
{
  { "@PROGRAM@", (void *) 0 },
_LT_EOF
	  $SED "s/^$symcode$symcode* \(.*\) \(.*\)$/  {\"\2\", (void *) \&\2},/" < "$nlist" | $GREP -v main >> conftest.$ac_ext
	  cat <<\_LT_EOF >> conftest.$ac_ext
  {0, (void *) 0}
};

/* This works around a problem in FreeBSD linker */
#ifdef FREEBSD_WORKAROUND
static const void *lt_preloaded_setup() {
  return lt__PROGRAM__LTX_preloaded_symbols;
}
#endif

#ifdef __cplusplus
}
#endif
_LT_EOF
	  # Now try linking the two files.
	  mv conftest.$ac_objext conftstm.$ac_objext
	  lt_save_LIBS="$LIBS"
	  lt_save_CFLAGS="$CFLAGS"
	  LIBS="conftstm.$ac_objext"
	  CFLAGS="$CFLAGS$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)"
	  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext}; then
	    pipe_works=yes
	  fi
	  LIBS="$lt_save_LIBS"
	  CFLAGS="$lt_save_CFLAGS"
	else
	  echo "cannot find nm_test_func in $nlist" >&AS_MESSAGE_LOG_FD
	fi
      else
	echo "cannot find nm_test_var in $nlist" >&AS_MESSAGE_LOG_FD
      fi
    else
      echo "cannot run $lt_cv_sys_global_symbol_pipe" >&AS_MESSAGE_LOG_FD
    fi
  else
    echo "$progname: failed program was:" >&AS_MESSAGE_LOG_FD
    cat conftest.$ac_ext >&5
  fi
  rm -rf conftest* conftst*

  # Do not use the global_symbol_pipe unless it works.
  if test "$pipe_works" = yes; then
    break
  else
    lt_cv_sys_global_symbol_pipe=
  fi
done
])
if test -z "$lt_cv_sys_global_symbol_pipe"; then
  lt_cv_sys_global_symbol_to_cdecl=
fi
if test -z "$lt_cv_sys_global_symbol_pipe$lt_cv_sys_global_symbol_to_cdecl"; then
  AC_MSG_RESULT(failed)
else
  AC_MSG_RESULT(ok)
fi

_LT_DECL([global_symbol_pipe], [lt_cv_sys_global_symbol_pipe], [1],
    [Take the output of nm and produce a listing of raw symbols and C names])
_LT_DECL([global_symbol_to_cdecl], [lt_cv_sys_global_symbol_to_cdecl], [1],
    [Transform the output of nm in a proper C declaration])
_LT_DECL([global_symbol_to_c_name_address],
    [lt_cv_sys_global_symbol_to_c_name_address], [1],
    [Transform the output of nm in a C name address pair])
_LT_DECL([global_symbol_to_c_name_address_lib_prefix],
    [lt_cv_sys_global_symbol_to_c_name_address_lib_prefix], [1],
    [Transform the output of nm in a C name address pair when lib prefix is needed])
]) # _LT_CMD_GLOBAL_SYMBOLS


# _LT_COMPILER_PIC([TAGNAME])
# ---------------------------
m4_defun([_LT_COMPILER_PIC],
[m4_require([_LT_TAG_COMPILER])dnl
_LT_TAGVAR(lt_prog_compiler_wl, $1)=
_LT_TAGVAR(lt_prog_compiler_pic, $1)=
_LT_TAGVAR(lt_prog_compiler_static, $1)=

AC_MSG_CHECKING([for $compiler option to produce PIC])
m4_if([$1], [CXX], [
  # C++ specific cases for pic, static, wl, etc.
  if test "$GXX" = yes; then
    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'

    case $host_os in
    aix*)
      # All AIX code is PIC.
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
        ;;
      m68k)
            # FIXME: we need at least 68020 code to build shared libraries, but
            # adding the `-m68020' flag to GCC prevents building anything better,
            # like `-m68040'.
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
        ;;
      esac
      ;;

    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
      # PIC is the default for these OSes.
      ;;
    mingw* | cygwin* | os2* | pw32* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      # Although the cygwin gcc ignores -fPIC, still need this for old-style
      # (--disable-auto-import) libraries
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;
    darwin* | rhapsody*)
      # PIC is the default on this platform
      # Common symbols not allowed in MH_DYLIB files
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
      ;;
    *djgpp*)
      # DJGPP does not support shared libraries at all
      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
      ;;
    haiku*)
      # PIC is the default for Haiku.
      # The "-static" flag exists, but is broken.
      _LT_TAGVAR(lt_prog_compiler_static, $1)=
      ;;
    interix[[3-9]]*)
      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
      # Instead, we relocate shared libraries at runtime.
      ;;
    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
      fi
      ;;
    hpux*)
      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
      # sets the default TLS model and affects inlining.
      case $host_cpu in
      hppa*64*)
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	;;
      esac
      ;;
    *qnx* | *nto*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;
    *)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
      ;;
    esac
  else
    case $host_os in
      aix[[4-9]]*)
	# All AIX code is PIC.
	if test "$host_cpu" = ia64; then
	  # AIX 5 now supports IA64 processor
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	else
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
	fi
	;;
      chorus*)
	case $cc_basename in
	cxch68*)
	  # Green Hills C++ Compiler
	  # _LT_TAGVAR(lt_prog_compiler_static, $1)="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
	  ;;
	esac
	;;
      dgux*)
	case $cc_basename in
	  ec++*)
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    ;;
	  ghcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  *)
	    ;;
	esac
	;;
      freebsd* | dragonfly*)
	# FreeBSD uses GNU C++
	;;
      hpux9* | hpux10* | hpux11*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
	    if test "$host_cpu" != ia64; then
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	    fi
	    ;;
	  aCC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
	    case $host_cpu in
	    hppa*64*|ia64*)
	      # +Z the default
	      ;;
	    *)
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	      ;;
	    esac
	    ;;
	  *)
	    ;;
	esac
	;;
      interix*)
	# This is c89, which is MS Visual C++ (no shared libs)
	# Anyone wants to do a port?
	;;
      irix5* | irix6* | nonstopux*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    # CC pic flag -KPIC is the default.
	    ;;
	  *)
	    ;;
	esac
	;;
      linux* | k*bsd*-gnu | kopensolaris*-gnu)
	case $cc_basename in
	  KCC*)
	    # KAI C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	    ;;
	  ecpc* )
	    # old Intel C++ for x86_64 which still supported -KPIC.
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
	    ;;
	  icpc* )
	    # Intel C++, used to be incompatible with GCC.
	    # ICC 10 doesn't accept -KPIC any more.
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
	    ;;
	  pgCC* | pgcpp*)
	    # Portland Group C++ compiler
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	  cxx*)
	    # Compaq C++
	    # Make sure the PIC flag is empty.  It appears that all Alpha
	    # Linux and Compaq Tru64 Unix objects are PIC.
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    ;;
	  xlc* | xlC* | bgxl[[cC]]* | mpixl[[cC]]*)
	    # IBM XL 8.0, 9.0 on PPC and BlueGene
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
	    ;;
	  *)
	    case `$CC -V 2>&1 | sed 5q` in
	    *Sun\ C*)
	      # Sun C++ 5.9
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
	      ;;
	    esac
	    ;;
	esac
	;;
      lynxos*)
	;;
      m88k*)
	;;
      mvs*)
	case $cc_basename in
	  cxx*)
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-W c,exportall'
	    ;;
	  *)
	    ;;
	esac
	;;
      netbsd*)
	;;
      *qnx* | *nto*)
        # QNX uses GNU C++, but need to define -shared option too, otherwise
        # it will coredump.
        _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
        ;;
      osf3* | osf4* | osf5*)
	case $cc_basename in
	  KCC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
	    ;;
	  RCC*)
	    # Rational C++ 2.4.1
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  cxx*)
	    # Digital/Compaq C++
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    # Make sure the PIC flag is empty.  It appears that all Alpha
	    # Linux and Compaq Tru64 Unix objects are PIC.
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    ;;
	  *)
	    ;;
	esac
	;;
      psos*)
	;;
      solaris*)
	case $cc_basename in
	  CC* | sunCC*)
	    # Sun C++ 4.2, 5.x and Centerline C++
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
	    ;;
	  gcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
	    ;;
	  *)
	    ;;
	esac
	;;
      sunos4*)
	case $cc_basename in
	  CC*)
	    # Sun C++ 4.x
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	  lcc*)
	    # Lucid
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  *)
	    ;;
	esac
	;;
      sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	esac
	;;
      tandem*)
	case $cc_basename in
	  NCC*)
	    # NonStop-UX NCC 3.20
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    ;;
	  *)
	    ;;
	esac
	;;
      vxworks*)
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
	;;
    esac
  fi
],
[
  if test "$GCC" = yes; then
    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'

    case $host_os in
      aix*)
      # All AIX code is PIC.
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
        ;;
      m68k)
            # FIXME: we need at least 68020 code to build shared libraries, but
            # adding the `-m68020' flag to GCC prevents building anything better,
            # like `-m68040'.
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
        ;;
      esac
      ;;

    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
      # PIC is the default for these OSes.
      ;;

    mingw* | cygwin* | pw32* | os2* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      # Although the cygwin gcc ignores -fPIC, still need this for old-style
      # (--disable-auto-import) libraries
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;

    darwin* | rhapsody*)
      # PIC is the default on this platform
      # Common symbols not allowed in MH_DYLIB files
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
      ;;

    haiku*)
      # PIC is the default for Haiku.
      # The "-static" flag exists, but is broken.
      _LT_TAGVAR(lt_prog_compiler_static, $1)=
      ;;

    hpux*)
      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
      # sets the default TLS model and affects inlining.
      case $host_cpu in
      hppa*64*)
	# +Z the default
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	;;
      esac
      ;;

    interix[[3-9]]*)
      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
      # Instead, we relocate shared libraries at runtime.
      ;;

    msdosdjgpp*)
      # Just because we use GCC doesn't mean we suddenly get shared libraries
      # on systems that don't support them.
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      enable_shared=no
      ;;

    *nto* | *qnx*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;

    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
      fi
      ;;

    *)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
      ;;
    esac

    case $cc_basename in
    nvcc*) # Cuda Compiler Driver 2.2
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Xlinker '
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-Xcompiler -fPIC'
      ;;
    esac
  else
    # PORTME Check for flag to pass linker flags through the system compiler.
    case $host_os in
    aix*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      else
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
      fi
      ;;

    mingw* | cygwin* | pw32* | os2* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;

    hpux9* | hpux10* | hpux11*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
      # not for PA HP-UX.
      case $host_cpu in
      hppa*64*|ia64*)
	# +Z the default
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	;;
      esac
      # Is there a better lt_prog_compiler_static that works with the bundled CC?
      _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
      ;;

    irix5* | irix6* | nonstopux*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # PIC (with -KPIC) is the default.
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    linux* | k*bsd*-gnu | kopensolaris*-gnu)
      case $cc_basename in
      # old Intel for x86_64 which still supported -KPIC.
      ecc*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
        ;;
      # icc used to be incompatible with GCC.
      # ICC 10 doesn't accept -KPIC any more.
      icc* | ifort*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
        ;;
      # Lahey Fortran 8.1.
      lf95*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='--shared'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='--static'
	;;
      pgcc* | pgf77* | pgf90* | pgf95* | pgfortran*)
        # Portland Group compilers (*not* the Pentium gcc compiler,
	# which looks to be a dead project)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
        ;;
      ccc*)
        _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
        # All Alpha code is PIC.
        _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
        ;;
      xl* | bgxl* | bgf* | mpixl*)
	# IBM XL C 8.0/Fortran 10.1, 11.1 on PPC and BlueGene
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
	;;
      *)
	case `$CC -V 2>&1 | sed 5q` in
	*Sun\ F* | *Sun*Fortran*)
	  # Sun Fortran 8.3 passes all unrecognized flags to the linker
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)=''
	  ;;
	*Sun\ C*)
	  # Sun C 5.9
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	  ;;
	esac
	;;
      esac
      ;;

    newsos6)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    *nto* | *qnx*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;

    osf3* | osf4* | osf5*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # All OSF/1 code is PIC.
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    rdos*)
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    solaris*)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      case $cc_basename in
      f77* | f90* | f95* | sunf77* | sunf90* | sunf95*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld ';;
      *)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,';;
      esac
      ;;

    sunos4*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    sysv4 | sysv4.2uw2* | sysv4.3*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    sysv4*MP*)
      if test -d /usr/nec ;then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-Kconform_pic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    unicos*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      ;;

    uts4*)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    *)
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      ;;
    esac
  fi
])
case $host_os in
  # For platforms which do not support PIC, -DPIC is meaningless:
  *djgpp*)
    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
    ;;
  *)
    _LT_TAGVAR(lt_prog_compiler_pic, $1)="$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])"
    ;;
esac
AC_MSG_RESULT([$_LT_TAGVAR(lt_prog_compiler_pic, $1)])
_LT_TAGDECL([wl], [lt_prog_compiler_wl], [1],
	[How to pass a linker flag through the compiler])

#
# Check to make sure the PIC flag actually works.
#
if test -n "$_LT_TAGVAR(lt_prog_compiler_pic, $1)"; then
  _LT_COMPILER_OPTION([if $compiler PIC flag $_LT_TAGVAR(lt_prog_compiler_pic, $1) works],
    [_LT_TAGVAR(lt_cv_prog_compiler_pic_works, $1)],
    [$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])], [],
    [case $_LT_TAGVAR(lt_prog_compiler_pic, $1) in
     "" | " "*) ;;
     *) _LT_TAGVAR(lt_prog_compiler_pic, $1)=" $_LT_TAGVAR(lt_prog_compiler_pic, $1)" ;;
     esac],
    [_LT_TAGVAR(lt_prog_compiler_pic, $1)=
     _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no])
fi
_LT_TAGDECL([pic_flag], [lt_prog_compiler_pic], [1],
	[Additional compiler flags for building library objects])

#
# Check to make sure the static flag actually works.
#
wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1) eval lt_tmp_static_flag=\"$_LT_TAGVAR(lt_prog_compiler_static, $1)\"
_LT_LINKER_OPTION([if $compiler static flag $lt_tmp_static_flag works],
  _LT_TAGVAR(lt_cv_prog_compiler_static_works, $1),
  $lt_tmp_static_flag,
  [],
  [_LT_TAGVAR(lt_prog_compiler_static, $1)=])
_LT_TAGDECL([link_static_flag], [lt_prog_compiler_static], [1],
	[Compiler flag to prevent dynamic linking])
])# _LT_COMPILER_PIC


# _LT_LINKER_SHLIBS([TAGNAME])
# ----------------------------
# See if the linker supports building shared libraries.
m4_defun([_LT_LINKER_SHLIBS],
[AC_REQUIRE([LT_PATH_LD])dnl
AC_REQUIRE([LT_PATH_NM])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl
m4_require([_LT_TAG_COMPILER])dnl
AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
m4_if([$1], [CXX], [
  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
  case $host_os in
  aix[[4-9]]*)
    # If we're using GNU nm, then we don't want the "-C" option.
    # -C means demangle to AIX nm, but means don't demangle with GNU nm
    # Also, AIX nm treats weak defined symbols like other global defined
    # symbols, whereas GNU nm marks them as "W".
    if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B") || (\$ 2 == "W")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
    else
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
    fi
    ;;
  pw32*)
    _LT_TAGVAR(export_symbols_cmds, $1)="$ltdll_cmds"
  ;;
  cygwin* | mingw* | cegcc*)
    _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/;/^.*[[ ]]__nm__/s/^.*[[ ]]__nm__\([[^ ]]*\)[[ ]][[^ ]]*/\1 DATA/;/^I[[ ]]/d;/^[[AITW]][[ ]]/s/.* //'\'' | sort | uniq > $export_symbols'
  ;;
  *)
    _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
  ;;
  esac
  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
], [
  runpath_var=
  _LT_TAGVAR(allow_undefined_flag, $1)=
  _LT_TAGVAR(always_export_symbols, $1)=no
  _LT_TAGVAR(archive_cmds, $1)=
  _LT_TAGVAR(archive_expsym_cmds, $1)=
  _LT_TAGVAR(compiler_needs_object, $1)=no
  _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
  _LT_TAGVAR(export_dynamic_flag_spec, $1)=
  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
  _LT_TAGVAR(hardcode_automatic, $1)=no
  _LT_TAGVAR(hardcode_direct, $1)=no
  _LT_TAGVAR(hardcode_direct_absolute, $1)=no
  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
  _LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
  _LT_TAGVAR(hardcode_libdir_separator, $1)=
  _LT_TAGVAR(hardcode_minus_L, $1)=no
  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
  _LT_TAGVAR(inherit_rpath, $1)=no
  _LT_TAGVAR(link_all_deplibs, $1)=unknown
  _LT_TAGVAR(module_cmds, $1)=
  _LT_TAGVAR(module_expsym_cmds, $1)=
  _LT_TAGVAR(old_archive_from_new_cmds, $1)=
  _LT_TAGVAR(old_archive_from_expsyms_cmds, $1)=
  _LT_TAGVAR(thread_safe_flag_spec, $1)=
  _LT_TAGVAR(whole_archive_flag_spec, $1)=
  # include_expsyms should be a list of space-separated symbols to be *always*
  # included in the symbol list
  _LT_TAGVAR(include_expsyms, $1)=
  # exclude_expsyms can be an extended regexp of symbols to exclude
  # it will be wrapped by ` (' and `)$', so one must not match beginning or
  # end of line.  Example: `a|bc|.*d.*' will exclude the symbols `a' and `bc',
  # as well as any symbol that contains `d'.
  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
  # Although _GLOBAL_OFFSET_TABLE_ is a valid symbol C name, most a.out
  # platforms (ab)use it in PIC code, but their linkers get confused if
  # the symbol is explicitly referenced.  Since portable code cannot
  # rely on this symbol name, it's probably fine to never include it in
  # preloaded symbol tables.
  # Exclude shared library initialization/finalization symbols.
dnl Note also adjust exclude_expsyms for C++ above.
  extract_expsyms_cmds=

  case $host_os in
  cygwin* | mingw* | pw32* | cegcc*)
    # FIXME: the MSVC++ port hasn't been tested in a loooong time
    # When not using gcc, we currently assume that we are using
    # Microsoft Visual C++.
    if test "$GCC" != yes; then
      with_gnu_ld=no
    fi
    ;;
  interix*)
    # we just hope/assume this is gcc and not c89 (= MSVC++)
    with_gnu_ld=yes
    ;;
  openbsd*)
    with_gnu_ld=no
    ;;
  esac

  _LT_TAGVAR(ld_shlibs, $1)=yes

  # On some targets, GNU ld is compatible enough with the native linker
  # that we're better off using the native interface for both.
  lt_use_gnu_ld_interface=no
  if test "$with_gnu_ld" = yes; then
    case $host_os in
      aix*)
	# The AIX port of GNU ld has always aspired to compatibility
	# with the native linker.  However, as the warning in the GNU ld
	# block says, versions before 2.19.5* couldn't really create working
	# shared libraries, regardless of the interface used.
	case `$LD -v 2>&1` in
	  *\ \(GNU\ Binutils\)\ 2.19.5*) ;;
	  *\ \(GNU\ Binutils\)\ 2.[[2-9]]*) ;;
	  *\ \(GNU\ Binutils\)\ [[3-9]]*) ;;
	  *)
	    lt_use_gnu_ld_interface=yes
	    ;;
	esac
	;;
      *)
	lt_use_gnu_ld_interface=yes
	;;
    esac
  fi

  if test "$lt_use_gnu_ld_interface" = yes; then
    # If archive_cmds runs LD, not CC, wlarc should be empty
    wlarc='${wl}'

    # Set some defaults for GNU ld with shared library support. These
    # are reset later if shared libraries are not supported. Putting them
    # here allows them to be overridden if necessary.
    runpath_var=LD_RUN_PATH
    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
    # ancient GNU ld didn't support --whole-archive et. al.
    if $LD --help 2>&1 | $GREP 'no-whole-archive' > /dev/null; then
      _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
    else
      _LT_TAGVAR(whole_archive_flag_spec, $1)=
    fi
    supports_anon_versioning=no
    case `$LD -v 2>&1` in
      *GNU\ gold*) supports_anon_versioning=yes ;;
      *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.10.*) ;; # catch versions < 2.11
      *\ 2.11.93.0.2\ *) supports_anon_versioning=yes ;; # RH7.3 ...
      *\ 2.11.92.0.12\ *) supports_anon_versioning=yes ;; # Mandrake 8.2 ...
      *\ 2.11.*) ;; # other 2.11 versions
      *) supports_anon_versioning=yes ;;
    esac

    # See if GNU ld supports shared libraries.
    case $host_os in
    aix[[3-9]]*)
      # On AIX/PPC, the GNU linker is very broken
      if test "$host_cpu" != ia64; then
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: the GNU linker, at least up to release 2.19, is reported
*** to be unable to reliably create shared libraries on AIX.
*** Therefore, libtool is disabling shared libraries support.  If you
*** really care for shared libraries, you may want to install binutils
*** 2.20 or above, or modify your PATH so that a non-GNU linker is found.
*** You will then need to restart the configuration process.

_LT_EOF
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
            _LT_TAGVAR(archive_expsym_cmds, $1)=''
        ;;
      m68k)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
            _LT_TAGVAR(hardcode_minus_L, $1)=yes
        ;;
      esac
      ;;

    beos*)
      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	# Joseph Beckenbach <jrb3@best.com> says some releases of gcc
	# support --undefined.  This deserves some investigation.  FIXME
	_LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    cygwin* | mingw* | pw32* | cegcc*)
      # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
      # as there is no search path for DLLs.
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-all-symbols'
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(always_export_symbols, $1)=no
      _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]][[ ]]/s/.*[[ ]]//'\'' | sort | uniq > $export_symbols'

      if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
	# If the export-symbols file already is a .def file (1st line
	# is EXPORTS), use it as is; otherwise, prepend...
	_LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	  cp $export_symbols $output_objdir/$soname.def;
	else
	  echo EXPORTS > $output_objdir/$soname.def;
	  cat $export_symbols >> $output_objdir/$soname.def;
	fi~
	$CC -shared $output_objdir/$soname.def $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    haiku*)
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    interix[[3-9]]*)
      _LT_TAGVAR(hardcode_direct, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
      # Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
      # Instead, shared libraries are loaded at an image base (0x10000000 by
      # default) and relocated if they conflict, which is a slow very memory
      # consuming and fragmenting process.  To avoid this, we pick a random,
      # 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
      # time.  Moving up from 0x10000000 also allows more sbrk(2) space.
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
      _LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
      ;;

    gnu* | linux* | tpf* | k*bsd*-gnu | kopensolaris*-gnu)
      tmp_diet=no
      if test "$host_os" = linux-dietlibc; then
	case $cc_basename in
	  diet\ *) tmp_diet=yes;;	# linux-dietlibc with static linking (!diet-dyn)
	esac
      fi
      if $LD --help 2>&1 | $EGREP ': supported targets:.* elf' > /dev/null \
	 && test "$tmp_diet" = no
      then
	tmp_addflag=
	tmp_sharedflag='-shared'
	case $cc_basename,$host_cpu in
        pgcc*)				# Portland Group C compiler
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  tmp_addflag=' $pic_flag'
	  ;;
	pgf77* | pgf90* | pgf95* | pgfortran*)
					# Portland Group f77 and f90 compilers
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  tmp_addflag=' $pic_flag -Mnomain' ;;
	ecc*,ia64* | icc*,ia64*)	# Intel C compiler on ia64
	  tmp_addflag=' -i_dynamic' ;;
	efc*,ia64* | ifort*,ia64*)	# Intel Fortran compiler on ia64
	  tmp_addflag=' -i_dynamic -nofor_main' ;;
	ifc* | ifort*)			# Intel Fortran compiler
	  tmp_addflag=' -nofor_main' ;;
	lf95*)				# Lahey Fortran 8.1
	  _LT_TAGVAR(whole_archive_flag_spec, $1)=
	  tmp_sharedflag='--shared' ;;
	xl[[cC]]* | bgxl[[cC]]* | mpixl[[cC]]*) # IBM XL C 8.0 on PPC (deal with xlf below)
	  tmp_sharedflag='-qmkshrobj'
	  tmp_addflag= ;;
	nvcc*)	# Cuda Compiler Driver 2.2
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  _LT_TAGVAR(compiler_needs_object, $1)=yes
	  ;;
	esac
	case `$CC -V 2>&1 | sed 5q` in
	*Sun\ C*)			# Sun C 5.9
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  _LT_TAGVAR(compiler_needs_object, $1)=yes
	  tmp_sharedflag='-G' ;;
	*Sun\ F*)			# Sun Fortran 8.3
	  tmp_sharedflag='-G' ;;
	esac
	_LT_TAGVAR(archive_cmds, $1)='$CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'

        if test "x$supports_anon_versioning" = xyes; then
          _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
	    cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
	    echo "local: *; };" >> $output_objdir/$libname.ver~
	    $CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
        fi

	case $cc_basename in
	xlf* | bgf* | bgxlf* | mpixlf*)
	  # IBM XL Fortran 10.1 on PPC cannot create shared libs itself
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='--whole-archive$convenience --no-whole-archive'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
	  _LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='-rpath $libdir'
	  _LT_TAGVAR(archive_cmds, $1)='$LD -shared $libobjs $deplibs $linker_flags -soname $soname -o $lib'
	  if test "x$supports_anon_versioning" = xyes; then
	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
	      cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
	      echo "local: *; };" >> $output_objdir/$libname.ver~
	      $LD -shared $libobjs $deplibs $linker_flags -soname $soname -version-script $output_objdir/$libname.ver -o $lib'
	  fi
	  ;;
	esac
      else
        _LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    netbsd*)
      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
	wlarc=
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      fi
      ;;

    solaris*)
      if $LD -v 2>&1 | $GREP 'BFD 2\.8' > /dev/null; then
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: The releases 2.8.* of the GNU linker cannot reliably
*** create shared libraries on Solaris systems.  Therefore, libtool
*** is disabling shared libraries support.  We urge you to upgrade GNU
*** binutils to release 2.9.1 or newer.  Another option is to modify
*** your PATH or compiler configuration so that the native linker is
*** used, and then restart.

_LT_EOF
      elif $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX*)
      case `$LD -v 2>&1` in
        *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.1[[0-5]].*)
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: Releases of the GNU linker prior to 2.16.91.0.3 can not
*** reliably create shared libraries on SCO systems.  Therefore, libtool
*** is disabling shared libraries support.  We urge you to upgrade GNU
*** binutils to release 2.16.91.0.3 or newer.  Another option is to modify
*** your PATH or compiler configuration so that the native linker is
*** used, and then restart.

_LT_EOF
	;;
	*)
	  # For security reasons, it is highly recommended that you always
	  # use absolute paths for naming shared libraries, and exclude the
	  # DT_RUNPATH tag from executables and libraries.  But doing so
	  # requires that you compile everything twice, which is a pain.
	  if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
	  else
	    _LT_TAGVAR(ld_shlibs, $1)=no
	  fi
	;;
      esac
      ;;

    sunos4*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bshareable -o $lib $libobjs $deplibs $linker_flags'
      wlarc=
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *)
      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;
    esac

    if test "$_LT_TAGVAR(ld_shlibs, $1)" = no; then
      runpath_var=
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
      _LT_TAGVAR(export_dynamic_flag_spec, $1)=
      _LT_TAGVAR(whole_archive_flag_spec, $1)=
    fi
  else
    # PORTME fill in a description of your system's linker (not GNU ld)
    case $host_os in
    aix3*)
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(always_export_symbols, $1)=yes
      _LT_TAGVAR(archive_expsym_cmds, $1)='$LD -o $output_objdir/$soname $libobjs $deplibs $linker_flags -bE:$export_symbols -T512 -H512 -bM:SRE~$AR $AR_FLAGS $lib $output_objdir/$soname'
      # Note: this linker hardcodes the directories in LIBPATH if there
      # are no directories specified by -L.
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      if test "$GCC" = yes && test -z "$lt_prog_compiler_static"; then
	# Neither direct hardcoding nor static linking is supported with a
	# broken collect2.
	_LT_TAGVAR(hardcode_direct, $1)=unsupported
      fi
      ;;

    aix[[4-9]]*)
      if test "$host_cpu" = ia64; then
	# On IA64, the linker does run time linking by default, so we don't
	# have to do anything special.
	aix_use_runtimelinking=no
	exp_sym_flag='-Bexport'
	no_entry_flag=""
      else
	# If we're using GNU nm, then we don't want the "-C" option.
	# -C means demangle to AIX nm, but means don't demangle with GNU nm
	# Also, AIX nm treats weak defined symbols like other global
	# defined symbols, whereas GNU nm marks them as "W".
	if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B") || (\$ 2 == "W")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
	else
	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
	fi
	aix_use_runtimelinking=no

	# Test if we are trying to use run time linking or normal
	# AIX style linking. If -brtl is somewhere in LDFLAGS, we
	# need to do runtime linking.
	case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
	  for ld_flag in $LDFLAGS; do
	  if (test $ld_flag = "-brtl" || test $ld_flag = "-Wl,-brtl"); then
	    aix_use_runtimelinking=yes
	    break
	  fi
	  done
	  ;;
	esac

	exp_sym_flag='-bexport'
	no_entry_flag='-bnoentry'
      fi

      # When large executables or shared objects are built, AIX ld can
      # have problems creating the table of contents.  If linking a library
      # or program results in "error TOC overflow" add -mminimal-toc to
      # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
      # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.

      _LT_TAGVAR(archive_cmds, $1)=''
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'

      if test "$GCC" = yes; then
	case $host_os in aix4.[[012]]|aix4.[[012]].*)
	# We only want to do this on AIX 4.2 and lower, the check
	# below for broken collect2 doesn't work under 4.3+
	  collect2name=`${CC} -print-prog-name=collect2`
	  if test -f "$collect2name" &&
	   strings "$collect2name" | $GREP resolve_lib_name >/dev/null
	  then
	  # We have reworked collect2
	  :
	  else
	  # We have old collect2
	  _LT_TAGVAR(hardcode_direct, $1)=unsupported
	  # It fails to find uninstalled libraries when the uninstalled
	  # path is not listed in the libpath.  Setting hardcode_minus_L
	  # to unsupported forces relinking
	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
	  _LT_TAGVAR(hardcode_libdir_separator, $1)=
	  fi
	  ;;
	esac
	shared_flag='-shared'
	if test "$aix_use_runtimelinking" = yes; then
	  shared_flag="$shared_flag "'${wl}-G'
	fi
      else
	# not using gcc
	if test "$host_cpu" = ia64; then
	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
	# chokes on -Wl,-G. The following line is correct:
	  shared_flag='-G'
	else
	  if test "$aix_use_runtimelinking" = yes; then
	    shared_flag='${wl}-G'
	  else
	    shared_flag='${wl}-bM:SRE'
	  fi
	fi
      fi

      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
      # It seems that -bexpall does not export symbols beginning with
      # underscore (_), so it is better to generate a list of symbols to export.
      _LT_TAGVAR(always_export_symbols, $1)=yes
      if test "$aix_use_runtimelinking" = yes; then
	# Warning - without using the other runtime loading flags (-brtl),
	# -berok will link without error, but may produce a broken library.
	_LT_TAGVAR(allow_undefined_flag, $1)='-berok'
        # Determine the default libpath from the value encoded in an
        # empty executable.
        _LT_SYS_MODULE_PATH_AIX
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then func_echo_all "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
      else
	if test "$host_cpu" = ia64; then
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
	  _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
	else
	 # Determine the default libpath from the value encoded in an
	 # empty executable.
	 _LT_SYS_MODULE_PATH_AIX
	 _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
	  # Warning - without using the other run time loading flags,
	  # -berok will link without error, but may produce a broken library.
	  _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
	  _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
	  if test "$with_gnu_ld" = yes; then
	    # We only use this code for GNU lds that support --whole-archive.
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	  else
	    # Exported symbols can be pulled into shared objects from archives
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
	  fi
	  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	  # This is similar to how AIX traditionally builds its shared libraries.
	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
	fi
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
            _LT_TAGVAR(archive_expsym_cmds, $1)=''
        ;;
      m68k)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
            _LT_TAGVAR(hardcode_minus_L, $1)=yes
        ;;
      esac
      ;;

    bsdi[[45]]*)
      _LT_TAGVAR(export_dynamic_flag_spec, $1)=-rdynamic
      ;;

    cygwin* | mingw* | pw32* | cegcc*)
      # When not using gcc, we currently assume that we are using
      # Microsoft Visual C++.
      # hardcode_libdir_flag_spec is actually meaningless, as there is
      # no search path for DLLs.
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      # Tell ltmain to make .lib files, not .a files.
      libext=lib
      # Tell ltmain to make .dll files, not .so files.
      shrext_cmds=".dll"
      # FIXME: Setting linknames here is a bad hack.
      _LT_TAGVAR(archive_cmds, $1)='$CC -o $lib $libobjs $compiler_flags `func_echo_all "$deplibs" | $SED '\''s/ -lc$//'\''` -link -dll~linknames='
      # The linker will automatically build a .lib file if we build a DLL.
      _LT_TAGVAR(old_archive_from_new_cmds, $1)='true'
      # FIXME: Should let the user specify the lib program.
      _LT_TAGVAR(old_archive_cmds, $1)='lib -OUT:$oldlib$oldobjs$old_deplibs'
      _LT_TAGVAR(fix_srcfile_path, $1)='`cygpath -w "$srcfile"`'
      _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
      ;;

    darwin* | rhapsody*)
      _LT_DARWIN_LINKER_FEATURES($1)
      ;;

    dgux*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    freebsd1*)
      _LT_TAGVAR(ld_shlibs, $1)=no
      ;;

    # FreeBSD 2.2.[012] allows us to include c++rt0.o to get C++ constructor
    # support.  Future versions do this automatically, but an explicit c++rt0.o
    # does not break anything, and helps significantly (at the cost of a little
    # extra space).
    freebsd2.2*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags /usr/lib/c++rt0.o'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    # Unfortunately, older versions of FreeBSD 2 do not have this feature.
    freebsd2*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
    freebsd* | dragonfly*)
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    hpux9*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $libobjs $deplibs $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
      else
	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$LD -b +b $install_libdir -o $output_objdir/$soname $libobjs $deplibs $linker_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(hardcode_direct, $1)=yes

      # hardcode_minus_L: Not really in the search PATH,
      # but as the default location of the library.
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
      ;;

    hpux10*)
      if test "$GCC" = yes && test "$with_gnu_ld" = no; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'
      fi
      if test "$with_gnu_ld" = no; then
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='+b $libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=:
	_LT_TAGVAR(hardcode_direct, $1)=yes
	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	# hardcode_minus_L: Not really in the search PATH,
	# but as the default location of the library.
	_LT_TAGVAR(hardcode_minus_L, $1)=yes
      fi
      ;;

    hpux11*)
      if test "$GCC" = yes && test "$with_gnu_ld" = no; then
	case $host_cpu in
	hppa*64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	ia64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	esac
      else
	case $host_cpu in
	hppa*64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	ia64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	m4_if($1, [], [
	  # Older versions of the 11.00 compiler do not understand -b yet
	  # (HP92453-01 A.11.01.20 doesn't, HP92453-01 B.11.X.35175-35176.GP does)
	  _LT_LINKER_OPTION([if $CC understands -b],
	    _LT_TAGVAR(lt_cv_prog_compiler__b, $1), [-b],
	    [_LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'],
	    [_LT_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'])],
	  [_LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'])
	  ;;
	esac
      fi
      if test "$with_gnu_ld" = no; then
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=:

	case $host_cpu in
	hppa*64*|ia64*)
	  _LT_TAGVAR(hardcode_direct, $1)=no
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	  ;;
	*)
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'

	  # hardcode_minus_L: Not really in the search PATH,
	  # but as the default location of the library.
	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
	  ;;
	esac
      fi
      ;;

    irix5* | irix6* | nonstopux*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	# Try to use the -exported_symbol ld option, if it does not
	# work, assume that -exports_file does not work either and
	# implicitly export all symbols.
        save_LDFLAGS="$LDFLAGS"
        LDFLAGS="$LDFLAGS -shared ${wl}-exported_symbol ${wl}foo ${wl}-update_registry ${wl}/dev/null"
        AC_LINK_IFELSE(int foo(void) {},
          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations ${wl}-exports_file ${wl}$export_symbols -o $lib'
        )
        LDFLAGS="$save_LDFLAGS"
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -exports_file $export_symbols -o $lib'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(inherit_rpath, $1)=yes
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    netbsd*)
      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    newsos6)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *nto* | *qnx*)
      ;;

    openbsd*)
      if test -f /usr/libexec/ld.so; then
	_LT_TAGVAR(hardcode_direct, $1)=yes
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-retain-symbols-file,$export_symbols'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	else
	  case $host_os in
	   openbsd[[01]].* | openbsd2.[[0-7]] | openbsd2.[[0-7]].*)
	     _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	     ;;
	   *)
	     _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	     ;;
	  esac
	fi
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    os2*)
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(archive_cmds, $1)='$ECHO "LIBRARY $libname INITINSTANCE" > $output_objdir/$libname.def~$ECHO "DESCRIPTION \"$libname\"" >> $output_objdir/$libname.def~echo DATA >> $output_objdir/$libname.def~echo " SINGLE NONSHARED" >> $output_objdir/$libname.def~echo EXPORTS >> $output_objdir/$libname.def~emxexp $libobjs >> $output_objdir/$libname.def~$CC -Zdll -Zcrtdll -o $lib $libobjs $deplibs $compiler_flags $output_objdir/$libname.def'
      _LT_TAGVAR(old_archive_from_new_cmds, $1)='emximp -o $output_objdir/$libname.a $output_objdir/$libname.def'
      ;;

    osf3*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
      else
	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      ;;

    osf4* | osf5*)	# as osf3* with the addition of -msym flag
      if test "$GCC" = yes; then
	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      else
	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -msym -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done; printf "%s\\n" "-hidden">> $lib.exp~
	$CC -shared${allow_undefined_flag} ${wl}-input ${wl}$lib.exp $compiler_flags $libobjs $deplibs -soname $soname `test -n "$verstring" && $ECHO "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib~$RM $lib.exp'

	# Both c and cxx compiler support -rpath directly
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      ;;

    solaris*)
      _LT_TAGVAR(no_undefined_flag, $1)=' -z defs'
      if test "$GCC" = yes; then
	wlarc='${wl}'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-z ${wl}text ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $CC -shared ${wl}-z ${wl}text ${wl}-M ${wl}$lib.exp ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
      else
	case `$CC -V 2>&1` in
	*"Compilers 5.0"*)
	  wlarc=''
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$RM $lib.exp'
	  ;;
	*)
	  wlarc='${wl}'
	  _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $CC -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
	  ;;
	esac
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      case $host_os in
      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
      *)
	# The compiler driver will combine and reorder linker options,
	# but understands `-z linker_flag'.  GCC discards it without `$wl',
	# but is careful enough not to reorder.
	# Supported since Solaris 2.6 (maybe 2.5.1?)
	if test "$GCC" = yes; then
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
	else
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
	fi
	;;
      esac
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    sunos4*)
      if test "x$host_vendor" = xsequent; then
	# Use $CC to link under sequent, because it throws in some extra .o
	# files that make .init and .fini sections work.
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h $soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bstatic -o $lib $libobjs $deplibs $linker_flags'
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    sysv4)
      case $host_vendor in
	sni)
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(hardcode_direct, $1)=yes # is this really true???
	;;
	siemens)
	  ## LD is ld it makes a PLAMLIB
	  ## CC just makes a GrossModule.
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(reload_cmds, $1)='$CC -r -o $output$reload_objs'
	  _LT_TAGVAR(hardcode_direct, $1)=no
        ;;
	motorola)
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(hardcode_direct, $1)=no #Motorola manual says yes, but my tests say they lie
	;;
      esac
      runpath_var='LD_RUN_PATH'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    sysv4.3*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='-Bexport'
      ;;

    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	runpath_var=LD_RUN_PATH
	hardcode_runpath_var=yes
	_LT_TAGVAR(ld_shlibs, $1)=yes
      fi
      ;;

    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      runpath_var='LD_RUN_PATH'

      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      fi
      ;;

    sysv5* | sco3.2v5* | sco5v6*)
      # Note: We can NOT use -z defs as we might desire, because we do not
      # link with -lc, and that would cause any symbols used from libc to
      # always be unresolved, which means just about no library would
      # ever link correctly.  If we're not using GNU ld we use -z text
      # though, which does catch some bad symbols but isn't as heavy-handed
      # as -z defs.
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
      runpath_var='LD_RUN_PATH'

      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      fi
      ;;

    uts4*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *)
      _LT_TAGVAR(ld_shlibs, $1)=no
      ;;
    esac

    if test x$host_vendor = xsni; then
      case $host in
      sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Blargedynsym'
	;;
      esac
    fi
  fi
])
AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no

_LT_TAGVAR(with_gnu_ld, $1)=$with_gnu_ld

_LT_DECL([], [libext], [0], [Old archive suffix (normally "a")])dnl
_LT_DECL([], [shrext_cmds], [1], [Shared library suffix (normally ".so")])dnl
_LT_DECL([], [extract_expsyms_cmds], [2],
    [The commands to extract the exported symbol list from a shared archive])

#
# Do we need to explicitly link libc?
#
case "x$_LT_TAGVAR(archive_cmds_need_lc, $1)" in
x|xyes)
  # Assume -lc should be added
  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes

  if test "$enable_shared" = yes && test "$GCC" = yes; then
    case $_LT_TAGVAR(archive_cmds, $1) in
    *'~'*)
      # FIXME: we may have to deal with multi-command sequences.
      ;;
    '$CC '*)
      # Test whether the compiler implicitly links with -lc since on some
      # systems, -lgcc has to come before -lc. If gcc already passes -lc
      # to ld, don't add -lc before -lgcc.
      AC_CACHE_CHECK([whether -lc should be explicitly linked in],
	[lt_cv_]_LT_TAGVAR(archive_cmds_need_lc, $1),
	[$RM conftest*
	echo "$lt_simple_compile_test_code" > conftest.$ac_ext

	if AC_TRY_EVAL(ac_compile) 2>conftest.err; then
	  soname=conftest
	  lib=conftest
	  libobjs=conftest.$ac_objext
	  deplibs=
	  wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1)
	  pic_flag=$_LT_TAGVAR(lt_prog_compiler_pic, $1)
	  compiler_flags=-v
	  linker_flags=-v
	  verstring=
	  output_objdir=.
	  libname=conftest
	  lt_save_allow_undefined_flag=$_LT_TAGVAR(allow_undefined_flag, $1)
	  _LT_TAGVAR(allow_undefined_flag, $1)=
	  if AC_TRY_EVAL(_LT_TAGVAR(archive_cmds, $1) 2\>\&1 \| $GREP \" -lc \" \>/dev/null 2\>\&1)
	  then
	    lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)=no
	  else
	    lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	  fi
	  _LT_TAGVAR(allow_undefined_flag, $1)=$lt_save_allow_undefined_flag
	else
	  cat conftest.err 1>&5
	fi
	$RM conftest*
	])
      _LT_TAGVAR(archive_cmds_need_lc, $1)=$lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)
      ;;
    esac
  fi
  ;;
esac

_LT_TAGDECL([build_libtool_need_lc], [archive_cmds_need_lc], [0],
    [Whether or not to add -lc for building shared libraries])
_LT_TAGDECL([allow_libtool_libs_with_static_runtimes],
    [enable_shared_with_static_runtimes], [0],
    [Whether or not to disallow shared libs when runtime libs are static])
_LT_TAGDECL([], [export_dynamic_flag_spec], [1],
    [Compiler flag to allow reflexive dlopens])
_LT_TAGDECL([], [whole_archive_flag_spec], [1],
    [Compiler flag to generate shared objects directly from archives])
_LT_TAGDECL([], [compiler_needs_object], [1],
    [Whether the compiler copes with passing no objects directly])
_LT_TAGDECL([], [old_archive_from_new_cmds], [2],
    [Create an old-style archive from a shared archive])
_LT_TAGDECL([], [old_archive_from_expsyms_cmds], [2],
    [Create a temporary old-style archive to link instead of a shared archive])
_LT_TAGDECL([], [archive_cmds], [2], [Commands used to build a shared archive])
_LT_TAGDECL([], [archive_expsym_cmds], [2])
_LT_TAGDECL([], [module_cmds], [2],
    [Commands used to build a loadable module if different from building
    a shared archive.])
_LT_TAGDECL([], [module_expsym_cmds], [2])
_LT_TAGDECL([], [with_gnu_ld], [1],
    [Whether we are building with GNU ld or not])
_LT_TAGDECL([], [allow_undefined_flag], [1],
    [Flag that allows shared libraries with undefined symbols to be built])
_LT_TAGDECL([], [no_undefined_flag], [1],
    [Flag that enforces no undefined symbols])
_LT_TAGDECL([], [hardcode_libdir_flag_spec], [1],
    [Flag to hardcode $libdir into a binary during linking.
    This must work even if $libdir does not exist])
_LT_TAGDECL([], [hardcode_libdir_flag_spec_ld], [1],
    [[If ld is used when linking, flag to hardcode $libdir into a binary
    during linking.  This must work even if $libdir does not exist]])
_LT_TAGDECL([], [hardcode_libdir_separator], [1],
    [Whether we need a single "-rpath" flag with a separated argument])
_LT_TAGDECL([], [hardcode_direct], [0],
    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
    DIR into the resulting binary])
_LT_TAGDECL([], [hardcode_direct_absolute], [0],
    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
    DIR into the resulting binary and the resulting library dependency is
    "absolute", i.e impossible to change by setting ${shlibpath_var} if the
    library is relocated])
_LT_TAGDECL([], [hardcode_minus_L], [0],
    [Set to "yes" if using the -LDIR flag during linking hardcodes DIR
    into the resulting binary])
_LT_TAGDECL([], [hardcode_shlibpath_var], [0],
    [Set to "yes" if using SHLIBPATH_VAR=DIR during linking hardcodes DIR
    into the resulting binary])
_LT_TAGDECL([], [hardcode_automatic], [0],
    [Set to "yes" if building a shared library automatically hardcodes DIR
    into the library and all subsequent libraries and executables linked
    against it])
_LT_TAGDECL([], [inherit_rpath], [0],
    [Set to yes if linker adds runtime paths of dependent libraries
    to runtime path list])
_LT_TAGDECL([], [link_all_deplibs], [0],
    [Whether libtool must link a program against all its dependency libraries])
_LT_TAGDECL([], [fix_srcfile_path], [1],
    [Fix the shell variable $srcfile for the compiler])
_LT_TAGDECL([], [always_export_symbols], [0],
    [Set to "yes" if exported symbols are required])
_LT_TAGDECL([], [export_symbols_cmds], [2],
    [The commands to list exported symbols])
_LT_TAGDECL([], [exclude_expsyms], [1],
    [Symbols that should not be listed in the preloaded symbols])
_LT_TAGDECL([], [include_expsyms], [1],
    [Symbols that must always be exported])
_LT_TAGDECL([], [prelink_cmds], [2],
    [Commands necessary for linking programs (against libraries) with templates])
_LT_TAGDECL([], [file_list_spec], [1],
    [Specify filename containing input files])
dnl FIXME: Not yet implemented
dnl _LT_TAGDECL([], [thread_safe_flag_spec], [1],
dnl    [Compiler flag to generate thread safe objects])
])# _LT_LINKER_SHLIBS


# _LT_LANG_C_CONFIG([TAG])
# ------------------------
# Ensure that the configuration variables for a C compiler are suitably
# defined.  These variables are subsequently used by _LT_CONFIG to write
# the compiler configuration to `libtool'.
m4_defun([_LT_LANG_C_CONFIG],
[m4_require([_LT_DECL_EGREP])dnl
lt_save_CC="$CC"
AC_LANG_PUSH(C)

# Source file extension for C test sources.
ac_ext=c

# Object file extension for compiled C test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code="int some_variable = 0;"

# Code to be used in simple link tests
lt_simple_link_test_code='int main(){return(0);}'

_LT_TAG_COMPILER
# Save the default compiler, since it gets overwritten when the other
# tags are being tested, and _LT_TAGVAR(compiler, []) is a NOP.
compiler_DEFAULT=$CC

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

if test -n "$compiler"; then
  _LT_COMPILER_NO_RTTI($1)
  _LT_COMPILER_PIC($1)
  _LT_COMPILER_C_O($1)
  _LT_COMPILER_FILE_LOCKS($1)
  _LT_LINKER_SHLIBS($1)
  _LT_SYS_DYNAMIC_LINKER($1)
  _LT_LINKER_HARDCODE_LIBPATH($1)
  LT_SYS_DLOPEN_SELF
  _LT_CMD_STRIPLIB

  # Report which library types will actually be built
  AC_MSG_CHECKING([if libtool supports shared libraries])
  AC_MSG_RESULT([$can_build_shared])

  AC_MSG_CHECKING([whether to build shared libraries])
  test "$can_build_shared" = "no" && enable_shared=no

  # On AIX, shared libraries and static libraries use the same namespace, and
  # are all built from PIC.
  case $host_os in
  aix3*)
    test "$enable_shared" = yes && enable_static=no
    if test -n "$RANLIB"; then
      archive_cmds="$archive_cmds~\$RANLIB \$lib"
      postinstall_cmds='$RANLIB $lib'
    fi
    ;;

  aix[[4-9]]*)
    if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
      test "$enable_shared" = yes && enable_static=no
    fi
    ;;
  esac
  AC_MSG_RESULT([$enable_shared])

  AC_MSG_CHECKING([whether to build static libraries])
  # Make sure either enable_shared or enable_static is yes.
  test "$enable_shared" = yes || enable_static=yes
  AC_MSG_RESULT([$enable_static])

  _LT_CONFIG($1)
fi
AC_LANG_POP
CC="$lt_save_CC"
])# _LT_LANG_C_CONFIG


# _LT_LANG_CXX_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for a C++ compiler are suitably
# defined.  These variables are subsequently used by _LT_CONFIG to write
# the compiler configuration to `libtool'.
m4_defun([_LT_LANG_CXX_CONFIG],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_EGREP])dnl
if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
    (test "X$CXX" != "Xg++"))) ; then
  AC_PROG_CXXCPP
else
  _lt_caught_CXX_error=yes
fi

AC_LANG_PUSH(C++)
_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(compiler_needs_object, $1)=no
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for C++ test sources.
ac_ext=cpp

# Object file extension for compiled C++ test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the CXX compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_caught_CXX_error" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="int some_variable = 0;"

  # Code to be used in simple link tests
  lt_simple_link_test_code='int main(int, char *[[]]) { return(0); }'

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC=$CC
  lt_save_LD=$LD
  lt_save_GCC=$GCC
  GCC=$GXX
  lt_save_with_gnu_ld=$with_gnu_ld
  lt_save_path_LD=$lt_cv_path_LD
  if test -n "${lt_cv_prog_gnu_ldcxx+set}"; then
    lt_cv_prog_gnu_ld=$lt_cv_prog_gnu_ldcxx
  else
    $as_unset lt_cv_prog_gnu_ld
  fi
  if test -n "${lt_cv_path_LDCXX+set}"; then
    lt_cv_path_LD=$lt_cv_path_LDCXX
  else
    $as_unset lt_cv_path_LD
  fi
  test -z "${LDCXX+set}" || LD=$LDCXX
  CC=${CXX-"c++"}
  compiler=$CC
  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])

  if test -n "$compiler"; then
    # We don't want -fno-exception when compiling C++ code, so set the
    # no_builtin_flag separately
    if test "$GXX" = yes; then
      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
    else
      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
    fi

    if test "$GXX" = yes; then
      # Set up default GNU C++ configuration

      LT_PATH_LD

      # Check if GNU C++ uses GNU ld as the underlying linker, since the
      # archiving commands below assume that GNU ld is being used.
      if test "$with_gnu_ld" = yes; then
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'

        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'

        # If archive_cmds runs LD, not CC, wlarc should be empty
        # XXX I think wlarc can be eliminated in ltcf-cxx, but I need to
        #     investigate it a little bit more. (MM)
        wlarc='${wl}'

        # ancient GNU ld didn't support --whole-archive et. al.
        if eval "`$CC -print-prog-name=ld` --help 2>&1" |
	  $GREP 'no-whole-archive' > /dev/null; then
          _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
        else
          _LT_TAGVAR(whole_archive_flag_spec, $1)=
        fi
      else
        with_gnu_ld=no
        wlarc=

        # A generic and very simple default shared library creation
        # command for GNU C++ for the case where it uses the native
        # linker, instead of GNU ld.  If possible, this setting should
        # overridden to take advantage of the native linker features on
        # the platform it is being used on.
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
      fi

      # Commands to make compiler produce verbose output that lists
      # what "hidden" libraries, object files and flags are used when
      # linking a shared library.
      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'

    else
      GXX=no
      with_gnu_ld=no
      wlarc=
    fi

    # PORTME: fill in a description of your system's C++ link characteristics
    AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
    _LT_TAGVAR(ld_shlibs, $1)=yes
    case $host_os in
      aix3*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;
      aix[[4-9]]*)
        if test "$host_cpu" = ia64; then
          # On IA64, the linker does run time linking by default, so we don't
          # have to do anything special.
          aix_use_runtimelinking=no
          exp_sym_flag='-Bexport'
          no_entry_flag=""
        else
          aix_use_runtimelinking=no

          # Test if we are trying to use run time linking or normal
          # AIX style linking. If -brtl is somewhere in LDFLAGS, we
          # need to do runtime linking.
          case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
	    for ld_flag in $LDFLAGS; do
	      case $ld_flag in
	      *-brtl*)
	        aix_use_runtimelinking=yes
	        break
	        ;;
	      esac
	    done
	    ;;
          esac

          exp_sym_flag='-bexport'
          no_entry_flag='-bnoentry'
        fi

        # When large executables or shared objects are built, AIX ld can
        # have problems creating the table of contents.  If linking a library
        # or program results in "error TOC overflow" add -mminimal-toc to
        # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
        # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.

        _LT_TAGVAR(archive_cmds, $1)=''
        _LT_TAGVAR(hardcode_direct, $1)=yes
        _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
        _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
        _LT_TAGVAR(link_all_deplibs, $1)=yes
        _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'

        if test "$GXX" = yes; then
          case $host_os in aix4.[[012]]|aix4.[[012]].*)
          # We only want to do this on AIX 4.2 and lower, the check
          # below for broken collect2 doesn't work under 4.3+
	  collect2name=`${CC} -print-prog-name=collect2`
	  if test -f "$collect2name" &&
	     strings "$collect2name" | $GREP resolve_lib_name >/dev/null
	  then
	    # We have reworked collect2
	    :
	  else
	    # We have old collect2
	    _LT_TAGVAR(hardcode_direct, $1)=unsupported
	    # It fails to find uninstalled libraries when the uninstalled
	    # path is not listed in the libpath.  Setting hardcode_minus_L
	    # to unsupported forces relinking
	    _LT_TAGVAR(hardcode_minus_L, $1)=yes
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=
	  fi
          esac
          shared_flag='-shared'
	  if test "$aix_use_runtimelinking" = yes; then
	    shared_flag="$shared_flag "'${wl}-G'
	  fi
        else
          # not using gcc
          if test "$host_cpu" = ia64; then
	  # VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
	  # chokes on -Wl,-G. The following line is correct:
	  shared_flag='-G'
          else
	    if test "$aix_use_runtimelinking" = yes; then
	      shared_flag='${wl}-G'
	    else
	      shared_flag='${wl}-bM:SRE'
	    fi
          fi
        fi

        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
        # It seems that -bexpall does not export symbols beginning with
        # underscore (_), so it is better to generate a list of symbols to
	# export.
        _LT_TAGVAR(always_export_symbols, $1)=yes
        if test "$aix_use_runtimelinking" = yes; then
          # Warning - without using the other runtime loading flags (-brtl),
          # -berok will link without error, but may produce a broken library.
          _LT_TAGVAR(allow_undefined_flag, $1)='-berok'
          # Determine the default libpath from the value encoded in an empty
          # executable.
          _LT_SYS_MODULE_PATH_AIX
          _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"

          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then func_echo_all "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
        else
          if test "$host_cpu" = ia64; then
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
	    _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
          else
	    # Determine the default libpath from the value encoded in an
	    # empty executable.
	    _LT_SYS_MODULE_PATH_AIX
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
	    # Warning - without using the other run time loading flags,
	    # -berok will link without error, but may produce a broken library.
	    _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
	    _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
	    if test "$with_gnu_ld" = yes; then
	      # We only use this code for GNU lds that support --whole-archive.
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	    else
	      # Exported symbols can be pulled into shared objects from archives
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
	    fi
	    _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	    # This is similar to how AIX traditionally builds its shared
	    # libraries.
	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
          fi
        fi
        ;;

      beos*)
	if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	  _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	  # Joseph Beckenbach <jrb3@best.com> says some releases of gcc
	  # support --undefined.  This deserves some investigation.  FIXME
	  _LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	else
	  _LT_TAGVAR(ld_shlibs, $1)=no
	fi
	;;

      chorus*)
        case $cc_basename in
          *)
	  # FIXME: insert proper C++ library support
	  _LT_TAGVAR(ld_shlibs, $1)=no
	  ;;
        esac
        ;;

      cygwin* | mingw* | pw32* | cegcc*)
        # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
        # as there is no search path for DLLs.
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-all-symbols'
        _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
        _LT_TAGVAR(always_export_symbols, $1)=no
        _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes

        if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
          # If the export-symbols file already is a .def file (1st line
          # is EXPORTS), use it as is; otherwise, prepend...
          _LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	    cp $export_symbols $output_objdir/$soname.def;
          else
	    echo EXPORTS > $output_objdir/$soname.def;
	    cat $export_symbols >> $output_objdir/$soname.def;
          fi~
          $CC -shared -nostdlib $output_objdir/$soname.def $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
        else
          _LT_TAGVAR(ld_shlibs, $1)=no
        fi
        ;;
      darwin* | rhapsody*)
        _LT_DARWIN_LINKER_FEATURES($1)
	;;

      dgux*)
        case $cc_basename in
          ec++*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          ghcx*)
	    # Green Hills C++ Compiler
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      freebsd[[12]]*)
        # C++ shared libraries reported to be fairly broken before
	# switch to ELF
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      freebsd-elf*)
        _LT_TAGVAR(archive_cmds_need_lc, $1)=no
        ;;

      freebsd* | dragonfly*)
        # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
        # conventions
        _LT_TAGVAR(ld_shlibs, $1)=yes
        ;;

      gnu*)
        ;;

      haiku*)
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
        _LT_TAGVAR(link_all_deplibs, $1)=yes
        ;;

      hpux9*)
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
        _LT_TAGVAR(hardcode_direct, $1)=yes
        _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
				             # but as the default
				             # location of the library.

        case $cc_basename in
          CC*)
            # FIXME: insert proper C++ library support
            _LT_TAGVAR(ld_shlibs, $1)=no
            ;;
          aCC*)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -b ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
            # Commands to make compiler produce verbose output that lists
            # what "hidden" libraries, object files and flags are used when
            # linking a shared library.
            #
            # There doesn't appear to be a way to prevent this compiler from
            # explicitly linking system object files so we need to strip them
            # from the output so that they don't get included in the library
            # dependencies.
            output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $EGREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
            ;;
          *)
            if test "$GXX" = yes; then
              _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared -nostdlib -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
            else
              # FIXME: insert proper C++ library support
              _LT_TAGVAR(ld_shlibs, $1)=no
            fi
            ;;
        esac
        ;;

      hpux10*|hpux11*)
        if test $with_gnu_ld = no; then
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	  _LT_TAGVAR(hardcode_libdir_separator, $1)=:

          case $host_cpu in
            hppa*64*|ia64*)
              ;;
            *)
	      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
              ;;
          esac
        fi
        case $host_cpu in
          hppa*64*|ia64*)
            _LT_TAGVAR(hardcode_direct, $1)=no
            _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
            ;;
          *)
            _LT_TAGVAR(hardcode_direct, $1)=yes
            _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
            _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
					         # but as the default
					         # location of the library.
            ;;
        esac

        case $cc_basename in
          CC*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          aCC*)
	    case $host_cpu in
	      hppa*64*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	      ia64*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	      *)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	    esac
	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $GREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
	    ;;
          *)
	    if test "$GXX" = yes; then
	      if test $with_gnu_ld = no; then
	        case $host_cpu in
	          hppa*64*)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	          ia64*)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	          *)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	        esac
	      fi
	    else
	      # FIXME: insert proper C++ library support
	      _LT_TAGVAR(ld_shlibs, $1)=no
	    fi
	    ;;
        esac
        ;;

      interix[[3-9]]*)
	_LT_TAGVAR(hardcode_direct, $1)=no
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	# Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
	# Instead, shared libraries are loaded at an image base (0x10000000 by
	# default) and relocated if they conflict, which is a slow very memory
	# consuming and fragmenting process.  To avoid this, we pick a random,
	# 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
	# time.  Moving up from 0x10000000 also allows more sbrk(2) space.
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
	;;
      irix5* | irix6*)
        case $cc_basename in
          CC*)
	    # SGI C++
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared -all -multigot $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'

	    # Archives containing C++ object files must be created using
	    # "CC -ar", where "CC" is the IRIX C++ compiler.  This is
	    # necessary to make sure instantiated templates are included
	    # in the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -ar -WR,-u -o $oldlib $oldobjs'
	    ;;
          *)
	    if test "$GXX" = yes; then
	      if test "$with_gnu_ld" = no; then
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	      else
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` -o $lib'
	      fi
	    fi
	    _LT_TAGVAR(link_all_deplibs, $1)=yes
	    ;;
        esac
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
        _LT_TAGVAR(inherit_rpath, $1)=yes
        ;;

      linux* | k*bsd*-gnu | kopensolaris*-gnu)
        case $cc_basename in
          KCC*)
	    # Kuck and Associates, Inc. (KAI) C++ Compiler

	    # KCC will only create a shared library if the output file
	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
	    # to its proper name (with version) after linking.
	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib ${wl}-retain-symbols-file,$export_symbols; mv \$templib $lib'
	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1 | $GREP "ld"`; rm -f libconftest$shared_ext; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'

	    # Archives containing C++ object files must be created using
	    # "CC -Bstatic", where "CC" is the KAI C++ compiler.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs'
	    ;;
	  icpc* | ecpc* )
	    # Intel C++
	    with_gnu_ld=yes
	    # version 8.0 and above of icpc choke on multiply defined symbols
	    # if we add $predep_objects and $postdep_objects, however 7.1 and
	    # earlier do not add the objects themselves.
	    case `$CC -V 2>&1` in
	      *"Version 7."*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
		;;
	      *)  # Version 8.0 or newer
	        tmp_idyn=
	        case $host_cpu in
		  ia64*) tmp_idyn=' -i_dynamic';;
		esac
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
		;;
	    esac
	    _LT_TAGVAR(archive_cmds_need_lc, $1)=no
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	    ;;
          pgCC* | pgcpp*)
            # Portland Group C++ compiler
	    case `$CC -V` in
	    *pgCC\ [[1-5]].* | *pgcpp\ [[1-5]].*)
	      _LT_TAGVAR(prelink_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $objs $libobjs $compile_deplibs~
		compile_command="$compile_command `find $tpldir -name \*.o | sort | $NL2SP`"'
	      _LT_TAGVAR(old_archive_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $oldobjs$old_deplibs~
		$AR $AR_FLAGS $oldlib$oldobjs$old_deplibs `find $tpldir -name \*.o | sort | $NL2SP`~
		$RANLIB $oldlib'
	      _LT_TAGVAR(archive_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | sort | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | sort | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
	      ;;
	    *) # Version 6 and above use weak symbols
	      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
	      ;;
	    esac

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
            ;;
	  cxx*)
	    # Compaq C++
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname  -o $lib ${wl}-retain-symbols-file $wl$export_symbols'

	    runpath_var=LD_RUN_PATH
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld"`; templist=`func_echo_all "$templist" | $SED "s/\(^.*ld.*\)\( .*ld .*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "X$list" | $Xsed'
	    ;;
	  xl* | mpixl* | bgxl*)
	    # IBM XL 8.0 on PPC, with GNU ld
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    if test "x$supports_anon_versioning" = xyes; then
	      _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
		cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
		echo "local: *; };" >> $output_objdir/$libname.ver~
		$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
	    fi
	    ;;
	  *)
	    case `$CC -V 2>&1 | sed 5q` in
	    *Sun\ C*)
	      # Sun C++ 5.9
	      _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
	      _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file ${wl}$export_symbols'
	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	      _LT_TAGVAR(compiler_needs_object, $1)=yes

	      # Not sure whether something based on
	      # $CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1
	      # would be better.
	      output_verbose_link_cmd='func_echo_all'

	      # Archives containing C++ object files must be created using
	      # "CC -xar", where "CC" is the Sun C++ compiler.  This is
	      # necessary to make sure instantiated templates are included
	      # in the archive.
	      _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
	      ;;
	    esac
	    ;;
	esac
	;;

      lynxos*)
        # FIXME: insert proper C++ library support
	_LT_TAGVAR(ld_shlibs, $1)=no
	;;

      m88k*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
	;;

      mvs*)
        case $cc_basename in
          cxx*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
	  *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
	esac
	;;

      netbsd*)
        if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	  _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
	  wlarc=
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	fi
	# Workaround some broken pre-1.5 toolchains
	output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
	;;

      *nto* | *qnx*)
        _LT_TAGVAR(ld_shlibs, $1)=yes
	;;

      openbsd2*)
        # C++ shared libraries are fairly broken
	_LT_TAGVAR(ld_shlibs, $1)=no
	;;

      openbsd*)
	if test -f /usr/libexec/ld.so; then
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file,$export_symbols -o $lib'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
	  fi
	  output_verbose_link_cmd=func_echo_all
	else
	  _LT_TAGVAR(ld_shlibs, $1)=no
	fi
	;;

      osf3* | osf4* | osf5*)
        case $cc_basename in
          KCC*)
	    # Kuck and Associates, Inc. (KAI) C++ Compiler

	    # KCC will only create a shared library if the output file
	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
	    # to its proper name (with version) after linking.
	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo "$lib" | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Archives containing C++ object files must be created using
	    # the KAI C++ compiler.
	    case $host in
	      osf3*) _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs' ;;
	      *) _LT_TAGVAR(old_archive_cmds, $1)='$CC -o $oldlib $oldobjs' ;;
	    esac
	    ;;
          RCC*)
	    # Rational C++ 2.4.1
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          cxx*)
	    case $host in
	      osf3*)
	        _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $soname `test -n "$verstring" && func_echo_all "${wl}-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
		;;
	      *)
	        _LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done~
	          echo "-hidden">> $lib.exp~
	          $CC -shared$allow_undefined_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname ${wl}-input ${wl}$lib.exp  `test -n "$verstring" && $ECHO "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib~
	          $RM $lib.exp'
	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
		;;
	    esac

	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld" | $GREP -v "ld:"`; templist=`func_echo_all "$templist" | $SED "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
	    ;;
	  *)
	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
	      _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	      case $host in
	        osf3*)
	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
		  ;;
	        *)
	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
		  ;;
	      esac

	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	      _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	      # Commands to make compiler produce verbose output that lists
	      # what "hidden" libraries, object files and flags are used when
	      # linking a shared library.
	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'

	    else
	      # FIXME: insert proper C++ library support
	      _LT_TAGVAR(ld_shlibs, $1)=no
	    fi
	    ;;
        esac
        ;;

      psos*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      sunos4*)
        case $cc_basename in
          CC*)
	    # Sun C++ 4.x
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          lcc*)
	    # Lucid
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      solaris*)
        case $cc_basename in
          CC* | sunCC*)
	    # Sun C++ 4.2, 5.x and Centerline C++
            _LT_TAGVAR(archive_cmds_need_lc,$1)=yes
	    _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag}  -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	      $CC -G${allow_undefined_flag} ${wl}-M ${wl}$lib.exp -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	    _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	    case $host_os in
	      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
	      *)
		# The compiler driver will combine and reorder linker options,
		# but understands `-z linker_flag'.
	        # Supported since Solaris 2.6 (maybe 2.5.1?)
		_LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
	        ;;
	    esac
	    _LT_TAGVAR(link_all_deplibs, $1)=yes

	    output_verbose_link_cmd='func_echo_all'

	    # Archives containing C++ object files must be created using
	    # "CC -xar", where "CC" is the Sun C++ compiler.  This is
	    # necessary to make sure instantiated templates are included
	    # in the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
	    ;;
          gcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'

	    # The C++ compiler must be used to create the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC $LDFLAGS -archive -o $oldlib $oldobjs'
	    ;;
          *)
	    # GNU C++ compiler with Solaris linker
	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
	      _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-z ${wl}defs'
	      if $CC --version | $GREP -v '^2\.7' > /dev/null; then
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
		  $CC -shared -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	        # Commands to make compiler produce verbose output that lists
	        # what "hidden" libraries, object files and flags are used when
	        # linking a shared library.
	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
	      else
	        # g++ 2.7 appears to require `-G' NOT `-shared' on this
	        # platform.
	        _LT_TAGVAR(archive_cmds, $1)='$CC -G -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
		  $CC -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	        # Commands to make compiler produce verbose output that lists
	        # what "hidden" libraries, object files and flags are used when
	        # linking a shared library.
	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
	      fi

	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $wl$libdir'
	      case $host_os in
		solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
		*)
		  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
		  ;;
	      esac
	    fi
	    ;;
        esac
        ;;

    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      runpath_var='LD_RUN_PATH'

      case $cc_basename in
        CC*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
      esac
      ;;

      sysv5* | sco3.2v5* | sco5v6*)
	# Note: We can NOT use -z defs as we might desire, because we do not
	# link with -lc, and that would cause any symbols used from libc to
	# always be unresolved, which means just about no library would
	# ever link correctly.  If we're not using GNU ld we use -z text
	# though, which does catch some bad symbols but isn't as heavy-handed
	# as -z defs.
	_LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
	_LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
	_LT_TAGVAR(archive_cmds_need_lc, $1)=no
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=':'
	_LT_TAGVAR(link_all_deplibs, $1)=yes
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
	runpath_var='LD_RUN_PATH'

	case $cc_basename in
          CC*)
	    _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -Tprelink_objects $oldobjs~
	      '"$_LT_TAGVAR(old_archive_cmds, $1)"
	    _LT_TAGVAR(reload_cmds, $1)='$CC -Tprelink_objects $reload_objs~
	      '"$_LT_TAGVAR(reload_cmds, $1)"
	    ;;
	  *)
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    ;;
	esac
      ;;

      tandem*)
        case $cc_basename in
          NCC*)
	    # NonStop-UX NCC 3.20
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      vxworks*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      *)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;
    esac

    AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
    test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no

    _LT_TAGVAR(GCC, $1)="$GXX"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_SYS_HIDDEN_LIBDEPS($1)
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  CC=$lt_save_CC
  LDCXX=$LD
  LD=$lt_save_LD
  GCC=$lt_save_GCC
  with_gnu_ld=$lt_save_with_gnu_ld
  lt_cv_path_LDCXX=$lt_cv_path_LD
  lt_cv_path_LD=$lt_save_path_LD
  lt_cv_prog_gnu_ldcxx=$lt_cv_prog_gnu_ld
  lt_cv_prog_gnu_ld=$lt_save_with_gnu_ld
fi # test "$_lt_caught_CXX_error" != yes

AC_LANG_POP
])# _LT_LANG_CXX_CONFIG


# _LT_SYS_HIDDEN_LIBDEPS([TAGNAME])
# ---------------------------------
# Figure out "hidden" library dependencies from verbose
# compiler output when linking a shared library.
# Parse the compiler output and extract the necessary
# objects, libraries and library flags.
m4_defun([_LT_SYS_HIDDEN_LIBDEPS],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
# Dependencies to place before and after the object being linked:
_LT_TAGVAR(predep_objects, $1)=
_LT_TAGVAR(postdep_objects, $1)=
_LT_TAGVAR(predeps, $1)=
_LT_TAGVAR(postdeps, $1)=
_LT_TAGVAR(compiler_lib_search_path, $1)=

dnl we can't use the lt_simple_compile_test_code here,
dnl because it contains code intended for an executable,
dnl not a library.  It's possible we should let each
dnl tag define a new lt_????_link_test_code variable,
dnl but it's only used here...
m4_if([$1], [], [cat > conftest.$ac_ext <<_LT_EOF
int a;
void foo (void) { a = 0; }
_LT_EOF
], [$1], [CXX], [cat > conftest.$ac_ext <<_LT_EOF
class Foo
{
public:
  Foo (void) { a = 0; }
private:
  int a;
};
_LT_EOF
], [$1], [F77], [cat > conftest.$ac_ext <<_LT_EOF
      subroutine foo
      implicit none
      integer*4 a
      a=0
      return
      end
_LT_EOF
], [$1], [FC], [cat > conftest.$ac_ext <<_LT_EOF
      subroutine foo
      implicit none
      integer a
      a=0
      return
      end
_LT_EOF
], [$1], [GCJ], [cat > conftest.$ac_ext <<_LT_EOF
public class foo {
  private int a;
  public void bar (void) {
    a = 0;
  }
};
_LT_EOF
])
dnl Parse the compiler output and extract the necessary
dnl objects, libraries and library flags.
if AC_TRY_EVAL(ac_compile); then
  # Parse the compiler output and extract the necessary
  # objects, libraries and library flags.

  # Sentinel used to keep track of whether or not we are before
  # the conftest object file.
  pre_test_object_deps_done=no

  for p in `eval "$output_verbose_link_cmd"`; do
    case $p in

    -L* | -R* | -l*)
       # Some compilers place space between "-{L,R}" and the path.
       # Remove the space.
       if test $p = "-L" ||
          test $p = "-R"; then
	 prev=$p
	 continue
       else
	 prev=
       fi

       if test "$pre_test_object_deps_done" = no; then
	 case $p in
	 -L* | -R*)
	   # Internal compiler library paths should come after those
	   # provided the user.  The postdeps already come after the
	   # user supplied libs so there is no need to process them.
	   if test -z "$_LT_TAGVAR(compiler_lib_search_path, $1)"; then
	     _LT_TAGVAR(compiler_lib_search_path, $1)="${prev}${p}"
	   else
	     _LT_TAGVAR(compiler_lib_search_path, $1)="${_LT_TAGVAR(compiler_lib_search_path, $1)} ${prev}${p}"
	   fi
	   ;;
	 # The "-l" case would never come before the object being
	 # linked, so don't bother handling this case.
	 esac
       else
	 if test -z "$_LT_TAGVAR(postdeps, $1)"; then
	   _LT_TAGVAR(postdeps, $1)="${prev}${p}"
	 else
	   _LT_TAGVAR(postdeps, $1)="${_LT_TAGVAR(postdeps, $1)} ${prev}${p}"
	 fi
       fi
       ;;

    *.$objext)
       # This assumes that the test object file only shows up
       # once in the compiler output.
       if test "$p" = "conftest.$objext"; then
	 pre_test_object_deps_done=yes
	 continue
       fi

       if test "$pre_test_object_deps_done" = no; then
	 if test -z "$_LT_TAGVAR(predep_objects, $1)"; then
	   _LT_TAGVAR(predep_objects, $1)="$p"
	 else
	   _LT_TAGVAR(predep_objects, $1)="$_LT_TAGVAR(predep_objects, $1) $p"
	 fi
       else
	 if test -z "$_LT_TAGVAR(postdep_objects, $1)"; then
	   _LT_TAGVAR(postdep_objects, $1)="$p"
	 else
	   _LT_TAGVAR(postdep_objects, $1)="$_LT_TAGVAR(postdep_objects, $1) $p"
	 fi
       fi
       ;;

    *) ;; # Ignore the rest.

    esac
  done

  # Clean up.
  rm -f a.out a.exe
else
  echo "libtool.m4: error: problem compiling $1 test program"
fi

$RM -f confest.$objext

# PORTME: override above test on systems where it is broken
m4_if([$1], [CXX],
[case $host_os in
interix[[3-9]]*)
  # Interix 3.5 installs completely hosed .la files for C++, so rather than
  # hack all around it, let's just trust "g++" to DTRT.
  _LT_TAGVAR(predep_objects,$1)=
  _LT_TAGVAR(postdep_objects,$1)=
  _LT_TAGVAR(postdeps,$1)=
  ;;

linux*)
  case `$CC -V 2>&1 | sed 5q` in
  *Sun\ C*)
    # Sun C++ 5.9

    # The more standards-conforming stlport4 library is
    # incompatible with the Cstd library. Avoid specifying
    # it if it's in CXXFLAGS. Ignore libCrun as
    # -library=stlport4 depends on it.
    case " $CXX $CXXFLAGS " in
    *" -library=stlport4 "*)
      solaris_use_stlport4=yes
      ;;
    esac

    if test "$solaris_use_stlport4" != yes; then
      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
    fi
    ;;
  esac
  ;;

solaris*)
  case $cc_basename in
  CC* | sunCC*)
    # The more standards-conforming stlport4 library is
    # incompatible with the Cstd library. Avoid specifying
    # it if it's in CXXFLAGS. Ignore libCrun as
    # -library=stlport4 depends on it.
    case " $CXX $CXXFLAGS " in
    *" -library=stlport4 "*)
      solaris_use_stlport4=yes
      ;;
    esac

    # Adding this requires a known-good setup of shared libraries for
    # Sun compiler versions before 5.6, else PIC objects from an old
    # archive will be linked into the output, leading to subtle bugs.
    if test "$solaris_use_stlport4" != yes; then
      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
    fi
    ;;
  esac
  ;;
esac
])

case " $_LT_TAGVAR(postdeps, $1) " in
*" -lc "*) _LT_TAGVAR(archive_cmds_need_lc, $1)=no ;;
esac
 _LT_TAGVAR(compiler_lib_search_dirs, $1)=
if test -n "${_LT_TAGVAR(compiler_lib_search_path, $1)}"; then
 _LT_TAGVAR(compiler_lib_search_dirs, $1)=`echo " ${_LT_TAGVAR(compiler_lib_search_path, $1)}" | ${SED} -e 's! -L! !g' -e 's!^ !!'`
fi
_LT_TAGDECL([], [compiler_lib_search_dirs], [1],
    [The directories searched by this compiler when creating a shared library])
_LT_TAGDECL([], [predep_objects], [1],
    [Dependencies to place before and after the objects being linked to
    create a shared library])
_LT_TAGDECL([], [postdep_objects], [1])
_LT_TAGDECL([], [predeps], [1])
_LT_TAGDECL([], [postdeps], [1])
_LT_TAGDECL([], [compiler_lib_search_path], [1],
    [The library search path used internally by the compiler when linking
    a shared library])
])# _LT_SYS_HIDDEN_LIBDEPS


# _LT_LANG_F77_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for a Fortran 77 compiler are
# suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_F77_CONFIG],
[AC_LANG_PUSH(Fortran 77)
if test -z "$F77" || test "X$F77" = "Xno"; then
  _lt_disable_F77=yes
fi

_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for f77 test sources.
ac_ext=f

# Object file extension for compiled f77 test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the F77 compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_disable_F77" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="\
      subroutine t
      return
      end
"

  # Code to be used in simple link tests
  lt_simple_link_test_code="\
      program t
      end
"

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC="$CC"
  lt_save_GCC=$GCC
  CC=${F77-"f77"}
  compiler=$CC
  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])
  GCC=$G77
  if test -n "$compiler"; then
    AC_MSG_CHECKING([if libtool supports shared libraries])
    AC_MSG_RESULT([$can_build_shared])

    AC_MSG_CHECKING([whether to build shared libraries])
    test "$can_build_shared" = "no" && enable_shared=no

    # On AIX, shared libraries and static libraries use the same namespace, and
    # are all built from PIC.
    case $host_os in
      aix3*)
        test "$enable_shared" = yes && enable_static=no
        if test -n "$RANLIB"; then
          archive_cmds="$archive_cmds~\$RANLIB \$lib"
          postinstall_cmds='$RANLIB $lib'
        fi
        ;;
      aix[[4-9]]*)
	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
	  test "$enable_shared" = yes && enable_static=no
	fi
        ;;
    esac
    AC_MSG_RESULT([$enable_shared])

    AC_MSG_CHECKING([whether to build static libraries])
    # Make sure either enable_shared or enable_static is yes.
    test "$enable_shared" = yes || enable_static=yes
    AC_MSG_RESULT([$enable_static])

    _LT_TAGVAR(GCC, $1)="$G77"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  GCC=$lt_save_GCC
  CC="$lt_save_CC"
fi # test "$_lt_disable_F77" != yes

AC_LANG_POP
])# _LT_LANG_F77_CONFIG


# _LT_LANG_FC_CONFIG([TAG])
# -------------------------
# Ensure that the configuration variables for a Fortran compiler are
# suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_FC_CONFIG],
[AC_LANG_PUSH(Fortran)

if test -z "$FC" || test "X$FC" = "Xno"; then
  _lt_disable_FC=yes
fi

_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for fc test sources.
ac_ext=${ac_fc_srcext-f}

# Object file extension for compiled fc test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the FC compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_disable_FC" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="\
      subroutine t
      return
      end
"

  # Code to be used in simple link tests
  lt_simple_link_test_code="\
      program t
      end
"

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC="$CC"
  lt_save_GCC=$GCC
  CC=${FC-"f95"}
  compiler=$CC
  GCC=$ac_cv_fc_compiler_gnu

  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])

  if test -n "$compiler"; then
    AC_MSG_CHECKING([if libtool supports shared libraries])
    AC_MSG_RESULT([$can_build_shared])

    AC_MSG_CHECKING([whether to build shared libraries])
    test "$can_build_shared" = "no" && enable_shared=no

    # On AIX, shared libraries and static libraries use the same namespace, and
    # are all built from PIC.
    case $host_os in
      aix3*)
        test "$enable_shared" = yes && enable_static=no
        if test -n "$RANLIB"; then
          archive_cmds="$archive_cmds~\$RANLIB \$lib"
          postinstall_cmds='$RANLIB $lib'
        fi
        ;;
      aix[[4-9]]*)
	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
	  test "$enable_shared" = yes && enable_static=no
	fi
        ;;
    esac
    AC_MSG_RESULT([$enable_shared])

    AC_MSG_CHECKING([whether to build static libraries])
    # Make sure either enable_shared or enable_static is yes.
    test "$enable_shared" = yes || enable_static=yes
    AC_MSG_RESULT([$enable_static])

    _LT_TAGVAR(GCC, $1)="$ac_cv_fc_compiler_gnu"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_SYS_HIDDEN_LIBDEPS($1)
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  GCC=$lt_save_GCC
  CC="$lt_save_CC"
fi # test "$_lt_disable_FC" != yes

AC_LANG_POP
])# _LT_LANG_FC_CONFIG


# _LT_LANG_GCJ_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for the GNU Java Compiler compiler
# are suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_GCJ_CONFIG],
[AC_REQUIRE([LT_PROG_GCJ])dnl
AC_LANG_SAVE

# Source file extension for Java test sources.
ac_ext=java

# Object file extension for compiled Java test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code="class foo {}"

# Code to be used in simple link tests
lt_simple_link_test_code='public class conftest { public static void main(String[[]] argv) {}; }'

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
_LT_TAG_COMPILER

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

# Allow CC to be a program name with arguments.
lt_save_CC="$CC"
lt_save_GCC=$GCC
GCC=yes
CC=${GCJ-"gcj"}
compiler=$CC
_LT_TAGVAR(compiler, $1)=$CC
_LT_TAGVAR(LD, $1)="$LD"
_LT_CC_BASENAME([$compiler])

# GCJ did not exist at the time GCC didn't implicitly link libc in.
_LT_TAGVAR(archive_cmds_need_lc, $1)=no

_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds

if test -n "$compiler"; then
  _LT_COMPILER_NO_RTTI($1)
  _LT_COMPILER_PIC($1)
  _LT_COMPILER_C_O($1)
  _LT_COMPILER_FILE_LOCKS($1)
  _LT_LINKER_SHLIBS($1)
  _LT_LINKER_HARDCODE_LIBPATH($1)

  _LT_CONFIG($1)
fi

AC_LANG_RESTORE

GCC=$lt_save_GCC
CC="$lt_save_CC"
])# _LT_LANG_GCJ_CONFIG


# _LT_LANG_RC_CONFIG([TAG])
# -------------------------
# Ensure that the configuration variables for the Windows resource compiler
# are suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_RC_CONFIG],
[AC_REQUIRE([LT_PROG_RC])dnl
AC_LANG_SAVE

# Source file extension for RC test sources.
ac_ext=rc

# Object file extension for compiled RC test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code='sample MENU { MENUITEM "&Soup", 100, CHECKED }'

# Code to be used in simple link tests
lt_simple_link_test_code="$lt_simple_compile_test_code"

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
_LT_TAG_COMPILER

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

# Allow CC to be a program name with arguments.
lt_save_CC="$CC"
lt_save_GCC=$GCC
GCC=
CC=${RC-"windres"}
compiler=$CC
_LT_TAGVAR(compiler, $1)=$CC
_LT_CC_BASENAME([$compiler])
_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes

if test -n "$compiler"; then
  :
  _LT_CONFIG($1)
fi

GCC=$lt_save_GCC
AC_LANG_RESTORE
CC="$lt_save_CC"
])# _LT_LANG_RC_CONFIG


# LT_PROG_GCJ
# -----------
AC_DEFUN([LT_PROG_GCJ],
[m4_ifdef([AC_PROG_GCJ], [AC_PROG_GCJ],
  [m4_ifdef([A][M_PROG_GCJ], [A][M_PROG_GCJ],
    [AC_CHECK_TOOL(GCJ, gcj,)
      test "x${GCJFLAGS+set}" = xset || GCJFLAGS="-g -O2"
      AC_SUBST(GCJFLAGS)])])[]dnl
])

# Old name:
AU_ALIAS([LT_AC_PROG_GCJ], [LT_PROG_GCJ])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_GCJ], [])


# LT_PROG_RC
# ----------
AC_DEFUN([LT_PROG_RC],
[AC_CHECK_TOOL(RC, windres,)
])

# Old name:
AU_ALIAS([LT_AC_PROG_RC], [LT_PROG_RC])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_RC], [])


# _LT_DECL_EGREP
# --------------
# If we don't have a new enough Autoconf to choose the best grep
# available, choose the one first in the user's PATH.
m4_defun([_LT_DECL_EGREP],
[AC_REQUIRE([AC_PROG_EGREP])dnl
AC_REQUIRE([AC_PROG_FGREP])dnl
test -z "$GREP" && GREP=grep
_LT_DECL([], [GREP], [1], [A grep program that handles long lines])
_LT_DECL([], [EGREP], [1], [An ERE matcher])
_LT_DECL([], [FGREP], [1], [A literal string matcher])
dnl Non-bleeding-edge autoconf doesn't subst GREP, so do it here too
AC_SUBST([GREP])
])


# _LT_DECL_OBJDUMP
# --------------
# If we don't have a new enough Autoconf to choose the best objdump
# available, choose the one first in the user's PATH.
m4_defun([_LT_DECL_OBJDUMP],
[AC_CHECK_TOOL(OBJDUMP, objdump, false)
test -z "$OBJDUMP" && OBJDUMP=objdump
_LT_DECL([], [OBJDUMP], [1], [An object symbol dumper])
AC_SUBST([OBJDUMP])
])


# _LT_DECL_SED
# ------------
# Check for a fully-functional sed program, that truncates
# as few characters as possible.  Prefer GNU sed if found.
m4_defun([_LT_DECL_SED],
[AC_PROG_SED
test -z "$SED" && SED=sed
Xsed="$SED -e 1s/^X//"
_LT_DECL([], [SED], [1], [A sed program that does not truncate output])
_LT_DECL([], [Xsed], ["\$SED -e 1s/^X//"],
    [Sed that helps us avoid accidentally triggering echo(1) options like -n])
])# _LT_DECL_SED

m4_ifndef([AC_PROG_SED], [
# NOTE: This macro has been submitted for inclusion into   #
#  GNU Autoconf as AC_PROG_SED.  When it is available in   #
#  a released version of Autoconf we should remove this    #
#  macro and use it instead.                               #

m4_defun([AC_PROG_SED],
[AC_MSG_CHECKING([for a sed that does not truncate output])
AC_CACHE_VAL(lt_cv_path_SED,
[# Loop through the user's path and test for sed and gsed.
# Then use that list of sed's as ones to test for truncation.
as_save_IFS=$IFS; IFS=$PATH_SEPARATOR
for as_dir in $PATH
do
  IFS=$as_save_IFS
  test -z "$as_dir" && as_dir=.
  for lt_ac_prog in sed gsed; do
    for ac_exec_ext in '' $ac_executable_extensions; do
      if $as_executable_p "$as_dir/$lt_ac_prog$ac_exec_ext"; then
        lt_ac_sed_list="$lt_ac_sed_list $as_dir/$lt_ac_prog$ac_exec_ext"
      fi
    done
  done
done
IFS=$as_save_IFS
lt_ac_max=0
lt_ac_count=0
# Add /usr/xpg4/bin/sed as it is typically found on Solaris
# along with /bin/sed that truncates output.
for lt_ac_sed in $lt_ac_sed_list /usr/xpg4/bin/sed; do
  test ! -f $lt_ac_sed && continue
  cat /dev/null > conftest.in
  lt_ac_count=0
  echo $ECHO_N "0123456789$ECHO_C" >conftest.in
  # Check for GNU sed and select it if it is found.
  if "$lt_ac_sed" --version 2>&1 < /dev/null | grep 'GNU' > /dev/null; then
    lt_cv_path_SED=$lt_ac_sed
    break
  fi
  while true; do
    cat conftest.in conftest.in >conftest.tmp
    mv conftest.tmp conftest.in
    cp conftest.in conftest.nl
    echo >>conftest.nl
    $lt_ac_sed -e 's/a$//' < conftest.nl >conftest.out || break
    cmp -s conftest.out conftest.nl || break
    # 10000 chars as input seems more than enough
    test $lt_ac_count -gt 10 && break
    lt_ac_count=`expr $lt_ac_count + 1`
    if test $lt_ac_count -gt $lt_ac_max; then
      lt_ac_max=$lt_ac_count
      lt_cv_path_SED=$lt_ac_sed
    fi
  done
done
])
SED=$lt_cv_path_SED
AC_SUBST([SED])
AC_MSG_RESULT([$SED])
])#AC_PROG_SED
])#m4_ifndef

# Old name:
AU_ALIAS([LT_AC_PROG_SED], [AC_PROG_SED])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_SED], [])


# _LT_CHECK_SHELL_FEATURES
# ------------------------
# Find out whether the shell is Bourne or XSI compatible,
# or has some other useful features.
m4_defun([_LT_CHECK_SHELL_FEATURES],
[AC_MSG_CHECKING([whether the shell understands some XSI constructs])
# Try some XSI features
xsi_shell=no
( _lt_dummy="a/b/c"
  test "${_lt_dummy##*/},${_lt_dummy%/*},"${_lt_dummy%"$_lt_dummy"}, \
      = c,a/b,, \
    && eval 'test $(( 1 + 1 )) -eq 2 \
    && test "${#_lt_dummy}" -eq 5' ) >/dev/null 2>&1 \
  && xsi_shell=yes
AC_MSG_RESULT([$xsi_shell])
_LT_CONFIG_LIBTOOL_INIT([xsi_shell='$xsi_shell'])

AC_MSG_CHECKING([whether the shell understands "+="])
lt_shell_append=no
( foo=bar; set foo baz; eval "$[1]+=\$[2]" && test "$foo" = barbaz ) \
    >/dev/null 2>&1 \
  && lt_shell_append=yes
AC_MSG_RESULT([$lt_shell_append])
_LT_CONFIG_LIBTOOL_INIT([lt_shell_append='$lt_shell_append'])

if ( (MAIL=60; unset MAIL) || exit) >/dev/null 2>&1; then
  lt_unset=unset
else
  lt_unset=false
fi
_LT_DECL([], [lt_unset], [0], [whether the shell understands "unset"])dnl

# test EBCDIC or ASCII
case `echo X|tr X '\101'` in
 A) # ASCII based system
    # \n is not interpreted correctly by Solaris 8 /usr/ucb/tr
  lt_SP2NL='tr \040 \012'
  lt_NL2SP='tr \015\012 \040\040'
  ;;
 *) # EBCDIC based system
  lt_SP2NL='tr \100 \n'
  lt_NL2SP='tr \r\n \100\100'
  ;;
esac
_LT_DECL([SP2NL], [lt_SP2NL], [1], [turn spaces into newlines])dnl
_LT_DECL([NL2SP], [lt_NL2SP], [1], [turn newlines into spaces])dnl
])# _LT_CHECK_SHELL_FEATURES


# _LT_PROG_XSI_SHELLFNS
# ---------------------
# Bourne and XSI compatible variants of some useful shell functions.
m4_defun([_LT_PROG_XSI_SHELLFNS],
[case $xsi_shell in
  yes)
    cat << \_LT_EOF >> "$cfgfile"

# func_dirname file append nondir_replacement
# Compute the dirname of FILE.  If nonempty, add APPEND to the result,
# otherwise set result to NONDIR_REPLACEMENT.
func_dirname ()
{
  case ${1} in
    */*) func_dirname_result="${1%/*}${2}" ;;
    *  ) func_dirname_result="${3}" ;;
  esac
}

# func_basename file
func_basename ()
{
  func_basename_result="${1##*/}"
}

# func_dirname_and_basename file append nondir_replacement
# perform func_basename and func_dirname in a single function
# call:
#   dirname:  Compute the dirname of FILE.  If nonempty,
#             add APPEND to the result, otherwise set result
#             to NONDIR_REPLACEMENT.
#             value returned in "$func_dirname_result"
#   basename: Compute filename of FILE.
#             value retuned in "$func_basename_result"
# Implementation must be kept synchronized with func_dirname
# and func_basename. For efficiency, we do not delegate to
# those functions but instead duplicate the functionality here.
func_dirname_and_basename ()
{
  case ${1} in
    */*) func_dirname_result="${1%/*}${2}" ;;
    *  ) func_dirname_result="${3}" ;;
  esac
  func_basename_result="${1##*/}"
}

# func_stripname prefix suffix name
# strip PREFIX and SUFFIX off of NAME.
# PREFIX and SUFFIX must not contain globbing or regex special
# characters, hashes, percent signs, but SUFFIX may contain a leading
# dot (in which case that matches only a dot).
func_stripname ()
{
  # pdksh 5.2.14 does not do ${X%$Y} correctly if both X and Y are
  # positional parameters, so assign one to ordinary parameter first.
  func_stripname_result=${3}
  func_stripname_result=${func_stripname_result#"${1}"}
  func_stripname_result=${func_stripname_result%"${2}"}
}

# func_opt_split
func_opt_split ()
{
  func_opt_split_opt=${1%%=*}
  func_opt_split_arg=${1#*=}
}

# func_lo2o object
func_lo2o ()
{
  case ${1} in
    *.lo) func_lo2o_result=${1%.lo}.${objext} ;;
    *)    func_lo2o_result=${1} ;;
  esac
}

# func_xform libobj-or-source
func_xform ()
{
  func_xform_result=${1%.*}.lo
}

# func_arith arithmetic-term...
func_arith ()
{
  func_arith_result=$(( $[*] ))
}

# func_len string
# STRING may not start with a hyphen.
func_len ()
{
  func_len_result=${#1}
}

_LT_EOF
    ;;
  *) # Bourne compatible functions.
    cat << \_LT_EOF >> "$cfgfile"

# func_dirname file append nondir_replacement
# Compute the dirname of FILE.  If nonempty, add APPEND to the result,
# otherwise set result to NONDIR_REPLACEMENT.
func_dirname ()
{
  # Extract subdirectory from the argument.
  func_dirname_result=`$ECHO "${1}" | $SED "$dirname"`
  if test "X$func_dirname_result" = "X${1}"; then
    func_dirname_result="${3}"
  else
    func_dirname_result="$func_dirname_result${2}"
  fi
}

# func_basename file
func_basename ()
{
  func_basename_result=`$ECHO "${1}" | $SED "$basename"`
}

dnl func_dirname_and_basename
dnl A portable version of this function is already defined in general.m4sh
dnl so there is no need for it here.

# func_stripname prefix suffix name
# strip PREFIX and SUFFIX off of NAME.
# PREFIX and SUFFIX must not contain globbing or regex special
# characters, hashes, percent signs, but SUFFIX may contain a leading
# dot (in which case that matches only a dot).
# func_strip_suffix prefix name
func_stripname ()
{
  case ${2} in
    .*) func_stripname_result=`$ECHO "${3}" | $SED "s%^${1}%%; s%\\\\${2}\$%%"`;;
    *)  func_stripname_result=`$ECHO "${3}" | $SED "s%^${1}%%; s%${2}\$%%"`;;
  esac
}

# sed scripts:
my_sed_long_opt='1s/^\(-[[^=]]*\)=.*/\1/;q'
my_sed_long_arg='1s/^-[[^=]]*=//'

# func_opt_split
func_opt_split ()
{
  func_opt_split_opt=`$ECHO "${1}" | $SED "$my_sed_long_opt"`
  func_opt_split_arg=`$ECHO "${1}" | $SED "$my_sed_long_arg"`
}

# func_lo2o object
func_lo2o ()
{
  func_lo2o_result=`$ECHO "${1}" | $SED "$lo2o"`
}

# func_xform libobj-or-source
func_xform ()
{
  func_xform_result=`$ECHO "${1}" | $SED 's/\.[[^.]]*$/.lo/'`
}

# func_arith arithmetic-term...
func_arith ()
{
  func_arith_result=`expr "$[@]"`
}

# func_len string
# STRING may not start with a hyphen.
func_len ()
{
  func_len_result=`expr "$[1]" : ".*" 2>/dev/null || echo $max_cmd_len`
}

_LT_EOF
esac

case $lt_shell_append in
  yes)
    cat << \_LT_EOF >> "$cfgfile"

# func_append var value
# Append VALUE to the end of shell variable VAR.
func_append ()
{
  eval "$[1]+=\$[2]"
}
_LT_EOF
    ;;
  *)
    cat << \_LT_EOF >> "$cfgfile"

# func_append var value
# Append VALUE to the end of shell variable VAR.
func_append ()
{
  eval "$[1]=\$$[1]\$[2]"
}

_LT_EOF
    ;;
  esac
])

dnl -*- Autoconf -*-
dnl Copyright (C) 2008 Sam Steingold (repleased under GPLv2+)

AC_DEFUN([CL_LIGHTNING], [
AC_ARG_WITH([lightning-prefix],
[AS_HELP_STRING([--with-lightning-prefix],
[additional place to look for the lightning headers])],
[if test -f $withval/include/lightning.h; then
  AC_LIB_APPENDTOVAR([CPPFLAGS],-I$withval/include)
fi],[])
AC_CHECK_HEADERS(lightning.h)])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.13)

AC_DEFUN([CL_PROG_LN],
[AC_CACHE_CHECK(how to make hard links, cl_cv_prog_LN, [
rm -f conftestdata conftestfile
echo data > conftestfile
if ln conftestfile conftestdata 2>/dev/null; then
  cl_cv_prog_LN=ln
else
  cl_cv_prog_LN="cp -p"
fi
rm -f conftestdata conftestfile
])
LN="$cl_cv_prog_LN"
AC_SUBST(LN)dnl
])

AC_DEFUN([CL_PROG_LN_S],
[AC_REQUIRE([CL_PROG_LN])dnl
dnl Make a symlink if possible; otherwise try a hard link. On filesystems
dnl which support neither symlink nor hard link, use a plain copy.
AC_CACHE_CHECK([whether ln -s works], [cl_cv_prog_LN_S_works], [dnl
rm -f conftestdata
if ln -s X conftestdata 2>/dev/null; then
  cl_cv_prog_LN_S_works=yes
else
  cl_cv_prog_LN_S_works=no
fi
rm -f conftestdata
])
if test $cl_cv_prog_LN_S_works = yes; then
  LN_S="ln -s"
else
  LN_S="$cl_cv_prog_LN"
fi
AC_SUBST(LN_S)])

AC_DEFUN([CL_PROG_HLN],
[AC_REQUIRE([CL_PROG_LN_S])dnl
dnl according to the Linux ln(1):
dnl   "making a hard link to a symbolic link is not portable":
dnl SVR4 (Solaris, Linux) create symbolic links
dnl   (breaks when the target is relative)
dnl Cygwin (1.3.12) is even worse: it makes hard links to the symbolic link,
dnl   instead of resolving the symbolic link.
dnl Good behavior means creating a hard link to the symbolic link's target.
dnl To avoid this, use the "hln" program.
dnl cf gl_AC_FUNC_LINK_FOLLOWS_SYMLINK in gnulib/m4/link-follow.m4
AC_CACHE_CHECK(how to make hard links to symlinks, cl_cv_prog_hln, [
cl_cv_prog_hln="ln"
if test "$cl_cv_prog_LN_S_works" = "yes"; then
echo "blabla" > conftest.x
ln -s conftest.x conftest.y
mkdir conftest.d
cd conftest.d
ln ../conftest.y conftest.z 2>&AC_FD_CC
data=`cat conftest.z 2>/dev/null`
if test "$data" = "blabla" ; then
  # conftest.z contains the correct data -- good!
  cl_cv_prog_hln="ln"
else
  # ln cannot link to symbolic links
  cl_cv_prog_hln="hln"
fi
cd ..
rm -fr conftest.*
else
# If there are no symbolic links, the problem cannot occur.
cl_cv_prog_hln="ln"
fi
])
HLN="$cl_cv_prog_hln"
AC_SUBST(HLN)dnl
])

# Helper functions for option handling.                    -*- Autoconf -*-
#
#   Copyright (C) 2004, 2005, 2007, 2008, 2009 Free Software Foundation,
#   Inc.
#   Written by Gary V. Vaughan, 2004
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

# serial 7 ltoptions.m4

# This is to help aclocal find these macros, as it can't see m4_define.
AC_DEFUN([LTOPTIONS_VERSION], [m4_if([1])])


# _LT_MANGLE_OPTION(MACRO-NAME, OPTION-NAME)
# ------------------------------------------
m4_define([_LT_MANGLE_OPTION],
[[_LT_OPTION_]m4_bpatsubst($1__$2, [[^a-zA-Z0-9_]], [_])])


# _LT_SET_OPTION(MACRO-NAME, OPTION-NAME)
# ---------------------------------------
# Set option OPTION-NAME for macro MACRO-NAME, and if there is a
# matching handler defined, dispatch to it.  Other OPTION-NAMEs are
# saved as a flag.
m4_define([_LT_SET_OPTION],
[m4_define(_LT_MANGLE_OPTION([$1], [$2]))dnl
m4_ifdef(_LT_MANGLE_DEFUN([$1], [$2]),
        _LT_MANGLE_DEFUN([$1], [$2]),
    [m4_warning([Unknown $1 option `$2'])])[]dnl
])


# _LT_IF_OPTION(MACRO-NAME, OPTION-NAME, IF-SET, [IF-NOT-SET])
# ------------------------------------------------------------
# Execute IF-SET if OPTION is set, IF-NOT-SET otherwise.
m4_define([_LT_IF_OPTION],
[m4_ifdef(_LT_MANGLE_OPTION([$1], [$2]), [$3], [$4])])


# _LT_UNLESS_OPTIONS(MACRO-NAME, OPTION-LIST, IF-NOT-SET)
# -------------------------------------------------------
# Execute IF-NOT-SET unless all options in OPTION-LIST for MACRO-NAME
# are set.
m4_define([_LT_UNLESS_OPTIONS],
[m4_foreach([_LT_Option], m4_split(m4_normalize([$2])),
	    [m4_ifdef(_LT_MANGLE_OPTION([$1], _LT_Option),
		      [m4_define([$0_found])])])[]dnl
m4_ifdef([$0_found], [m4_undefine([$0_found])], [$3
])[]dnl
])


# _LT_SET_OPTIONS(MACRO-NAME, OPTION-LIST)
# ----------------------------------------
# OPTION-LIST is a space-separated list of Libtool options associated
# with MACRO-NAME.  If any OPTION has a matching handler declared with
# LT_OPTION_DEFINE, dispatch to that macro; otherwise complain about
# the unknown option and exit.
m4_defun([_LT_SET_OPTIONS],
[# Set options
m4_foreach([_LT_Option], m4_split(m4_normalize([$2])),
    [_LT_SET_OPTION([$1], _LT_Option)])

m4_if([$1],[LT_INIT],[
  dnl
  dnl Simply set some default values (i.e off) if boolean options were not
  dnl specified:
  _LT_UNLESS_OPTIONS([LT_INIT], [dlopen], [enable_dlopen=no
  ])
  _LT_UNLESS_OPTIONS([LT_INIT], [win32-dll], [enable_win32_dll=no
  ])
  dnl
  dnl If no reference was made to various pairs of opposing options, then
  dnl we run the default mode handler for the pair.  For example, if neither
  dnl `shared' nor `disable-shared' was passed, we enable building of shared
  dnl archives by default:
  _LT_UNLESS_OPTIONS([LT_INIT], [shared disable-shared], [_LT_ENABLE_SHARED])
  _LT_UNLESS_OPTIONS([LT_INIT], [static disable-static], [_LT_ENABLE_STATIC])
  _LT_UNLESS_OPTIONS([LT_INIT], [pic-only no-pic], [_LT_WITH_PIC])
  _LT_UNLESS_OPTIONS([LT_INIT], [fast-install disable-fast-install],
  		   [_LT_ENABLE_FAST_INSTALL])
  ])
])# _LT_SET_OPTIONS



# _LT_MANGLE_DEFUN(MACRO-NAME, OPTION-NAME)
# -----------------------------------------
m4_define([_LT_MANGLE_DEFUN],
[[_LT_OPTION_DEFUN_]m4_bpatsubst(m4_toupper([$1__$2]), [[^A-Z0-9_]], [_])])


# LT_OPTION_DEFINE(MACRO-NAME, OPTION-NAME, CODE)
# -----------------------------------------------
m4_define([LT_OPTION_DEFINE],
[m4_define(_LT_MANGLE_DEFUN([$1], [$2]), [$3])[]dnl
])# LT_OPTION_DEFINE


# dlopen
# ------
LT_OPTION_DEFINE([LT_INIT], [dlopen], [enable_dlopen=yes
])

AU_DEFUN([AC_LIBTOOL_DLOPEN],
[_LT_SET_OPTION([LT_INIT], [dlopen])
AC_DIAGNOSE([obsolete],
[$0: Remove this warning and the call to _LT_SET_OPTION when you
put the `dlopen' option into LT_INIT's first parameter.])
])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_DLOPEN], [])


# win32-dll
# ---------
# Declare package support for building win32 dll's.
LT_OPTION_DEFINE([LT_INIT], [win32-dll],
[enable_win32_dll=yes

case $host in
*-*-cygwin* | *-*-mingw* | *-*-pw32* | *-*-cegcc*)
  AC_CHECK_TOOL(AS, as, false)
  AC_CHECK_TOOL(DLLTOOL, dlltool, false)
  AC_CHECK_TOOL(OBJDUMP, objdump, false)
  ;;
esac

test -z "$AS" && AS=as
_LT_DECL([], [AS],      [1], [Assembler program])dnl

test -z "$DLLTOOL" && DLLTOOL=dlltool
_LT_DECL([], [DLLTOOL], [1], [DLL creation program])dnl

test -z "$OBJDUMP" && OBJDUMP=objdump
_LT_DECL([], [OBJDUMP], [1], [Object dumper program])dnl
])# win32-dll

AU_DEFUN([AC_LIBTOOL_WIN32_DLL],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
_LT_SET_OPTION([LT_INIT], [win32-dll])
AC_DIAGNOSE([obsolete],
[$0: Remove this warning and the call to _LT_SET_OPTION when you
put the `win32-dll' option into LT_INIT's first parameter.])
])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_WIN32_DLL], [])


# _LT_ENABLE_SHARED([DEFAULT])
# ----------------------------
# implement the --enable-shared flag, and supports the `shared' and
# `disable-shared' LT_INIT options.
# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
m4_define([_LT_ENABLE_SHARED],
[m4_define([_LT_ENABLE_SHARED_DEFAULT], [m4_if($1, no, no, yes)])dnl
AC_ARG_ENABLE([shared],
    [AS_HELP_STRING([--enable-shared@<:@=PKGS@:>@],
	[build shared libraries @<:@default=]_LT_ENABLE_SHARED_DEFAULT[@:>@])],
    [p=${PACKAGE-default}
    case $enableval in
    yes) enable_shared=yes ;;
    no) enable_shared=no ;;
    *)
      enable_shared=no
      # Look at the argument we got.  We use all the common list separators.
      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
      for pkg in $enableval; do
	IFS="$lt_save_ifs"
	if test "X$pkg" = "X$p"; then
	  enable_shared=yes
	fi
      done
      IFS="$lt_save_ifs"
      ;;
    esac],
    [enable_shared=]_LT_ENABLE_SHARED_DEFAULT)

    _LT_DECL([build_libtool_libs], [enable_shared], [0],
	[Whether or not to build shared libraries])
])# _LT_ENABLE_SHARED

LT_OPTION_DEFINE([LT_INIT], [shared], [_LT_ENABLE_SHARED([yes])])
LT_OPTION_DEFINE([LT_INIT], [disable-shared], [_LT_ENABLE_SHARED([no])])

# Old names:
AC_DEFUN([AC_ENABLE_SHARED],
[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[shared])
])

AC_DEFUN([AC_DISABLE_SHARED],
[_LT_SET_OPTION([LT_INIT], [disable-shared])
])

AU_DEFUN([AM_ENABLE_SHARED], [AC_ENABLE_SHARED($@)])
AU_DEFUN([AM_DISABLE_SHARED], [AC_DISABLE_SHARED($@)])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_ENABLE_SHARED], [])
dnl AC_DEFUN([AM_DISABLE_SHARED], [])



# _LT_ENABLE_STATIC([DEFAULT])
# ----------------------------
# implement the --enable-static flag, and support the `static' and
# `disable-static' LT_INIT options.
# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
m4_define([_LT_ENABLE_STATIC],
[m4_define([_LT_ENABLE_STATIC_DEFAULT], [m4_if($1, no, no, yes)])dnl
AC_ARG_ENABLE([static],
    [AS_HELP_STRING([--enable-static@<:@=PKGS@:>@],
	[build static libraries @<:@default=]_LT_ENABLE_STATIC_DEFAULT[@:>@])],
    [p=${PACKAGE-default}
    case $enableval in
    yes) enable_static=yes ;;
    no) enable_static=no ;;
    *)
     enable_static=no
      # Look at the argument we got.  We use all the common list separators.
      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
      for pkg in $enableval; do
	IFS="$lt_save_ifs"
	if test "X$pkg" = "X$p"; then
	  enable_static=yes
	fi
      done
      IFS="$lt_save_ifs"
      ;;
    esac],
    [enable_static=]_LT_ENABLE_STATIC_DEFAULT)

    _LT_DECL([build_old_libs], [enable_static], [0],
	[Whether or not to build static libraries])
])# _LT_ENABLE_STATIC

LT_OPTION_DEFINE([LT_INIT], [static], [_LT_ENABLE_STATIC([yes])])
LT_OPTION_DEFINE([LT_INIT], [disable-static], [_LT_ENABLE_STATIC([no])])

# Old names:
AC_DEFUN([AC_ENABLE_STATIC],
[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[static])
])

AC_DEFUN([AC_DISABLE_STATIC],
[_LT_SET_OPTION([LT_INIT], [disable-static])
])

AU_DEFUN([AM_ENABLE_STATIC], [AC_ENABLE_STATIC($@)])
AU_DEFUN([AM_DISABLE_STATIC], [AC_DISABLE_STATIC($@)])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_ENABLE_STATIC], [])
dnl AC_DEFUN([AM_DISABLE_STATIC], [])



# _LT_ENABLE_FAST_INSTALL([DEFAULT])
# ----------------------------------
# implement the --enable-fast-install flag, and support the `fast-install'
# and `disable-fast-install' LT_INIT options.
# DEFAULT is either `yes' or `no'.  If omitted, it defaults to `yes'.
m4_define([_LT_ENABLE_FAST_INSTALL],
[m4_define([_LT_ENABLE_FAST_INSTALL_DEFAULT], [m4_if($1, no, no, yes)])dnl
AC_ARG_ENABLE([fast-install],
    [AS_HELP_STRING([--enable-fast-install@<:@=PKGS@:>@],
    [optimize for fast installation @<:@default=]_LT_ENABLE_FAST_INSTALL_DEFAULT[@:>@])],
    [p=${PACKAGE-default}
    case $enableval in
    yes) enable_fast_install=yes ;;
    no) enable_fast_install=no ;;
    *)
      enable_fast_install=no
      # Look at the argument we got.  We use all the common list separators.
      lt_save_ifs="$IFS"; IFS="${IFS}$PATH_SEPARATOR,"
      for pkg in $enableval; do
	IFS="$lt_save_ifs"
	if test "X$pkg" = "X$p"; then
	  enable_fast_install=yes
	fi
      done
      IFS="$lt_save_ifs"
      ;;
    esac],
    [enable_fast_install=]_LT_ENABLE_FAST_INSTALL_DEFAULT)

_LT_DECL([fast_install], [enable_fast_install], [0],
	 [Whether or not to optimize for fast installation])dnl
])# _LT_ENABLE_FAST_INSTALL

LT_OPTION_DEFINE([LT_INIT], [fast-install], [_LT_ENABLE_FAST_INSTALL([yes])])
LT_OPTION_DEFINE([LT_INIT], [disable-fast-install], [_LT_ENABLE_FAST_INSTALL([no])])

# Old names:
AU_DEFUN([AC_ENABLE_FAST_INSTALL],
[_LT_SET_OPTION([LT_INIT], m4_if([$1], [no], [disable-])[fast-install])
AC_DIAGNOSE([obsolete],
[$0: Remove this warning and the call to _LT_SET_OPTION when you put
the `fast-install' option into LT_INIT's first parameter.])
])

AU_DEFUN([AC_DISABLE_FAST_INSTALL],
[_LT_SET_OPTION([LT_INIT], [disable-fast-install])
AC_DIAGNOSE([obsolete],
[$0: Remove this warning and the call to _LT_SET_OPTION when you put
the `disable-fast-install' option into LT_INIT's first parameter.])
])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_ENABLE_FAST_INSTALL], [])
dnl AC_DEFUN([AM_DISABLE_FAST_INSTALL], [])


# _LT_WITH_PIC([MODE])
# --------------------
# implement the --with-pic flag, and support the `pic-only' and `no-pic'
# LT_INIT options.
# MODE is either `yes' or `no'.  If omitted, it defaults to `both'.
m4_define([_LT_WITH_PIC],
[AC_ARG_WITH([pic],
    [AS_HELP_STRING([--with-pic],
	[try to use only PIC/non-PIC objects @<:@default=use both@:>@])],
    [pic_mode="$withval"],
    [pic_mode=default])

test -z "$pic_mode" && pic_mode=m4_default([$1], [default])

_LT_DECL([], [pic_mode], [0], [What type of objects to build])dnl
])# _LT_WITH_PIC

LT_OPTION_DEFINE([LT_INIT], [pic-only], [_LT_WITH_PIC([yes])])
LT_OPTION_DEFINE([LT_INIT], [no-pic], [_LT_WITH_PIC([no])])

# Old name:
AU_DEFUN([AC_LIBTOOL_PICMODE],
[_LT_SET_OPTION([LT_INIT], [pic-only])
AC_DIAGNOSE([obsolete],
[$0: Remove this warning and the call to _LT_SET_OPTION when you
put the `pic-only' option into LT_INIT's first parameter.])
])

dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_PICMODE], [])


m4_define([_LTDL_MODE], [])
LT_OPTION_DEFINE([LTDL_INIT], [nonrecursive],
		 [m4_define([_LTDL_MODE], [nonrecursive])])
LT_OPTION_DEFINE([LTDL_INIT], [recursive],
		 [m4_define([_LTDL_MODE], [recursive])])
LT_OPTION_DEFINE([LTDL_INIT], [subproject],
		 [m4_define([_LTDL_MODE], [subproject])])

m4_define([_LTDL_TYPE], [])
LT_OPTION_DEFINE([LTDL_INIT], [installable],
		 [m4_define([_LTDL_TYPE], [installable])])
LT_OPTION_DEFINE([LTDL_INIT], [convenience],
		 [m4_define([_LTDL_TYPE], [convenience])])

# ltsugar.m4 -- libtool m4 base layer.                         -*-Autoconf-*-
#
# Copyright (C) 2004, 2005, 2007, 2008 Free Software Foundation, Inc.
# Written by Gary V. Vaughan, 2004
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

# serial 6 ltsugar.m4

# This is to help aclocal find these macros, as it can't see m4_define.
AC_DEFUN([LTSUGAR_VERSION], [m4_if([0.1])])


# lt_join(SEP, ARG1, [ARG2...])
# -----------------------------
# Produce ARG1SEPARG2...SEPARGn, omitting [] arguments and their
# associated separator.
# Needed until we can rely on m4_join from Autoconf 2.62, since all earlier
# versions in m4sugar had bugs.
m4_define([lt_join],
[m4_if([$#], [1], [],
       [$#], [2], [[$2]],
       [m4_if([$2], [], [], [[$2]_])$0([$1], m4_shift(m4_shift($@)))])])
m4_define([_lt_join],
[m4_if([$#$2], [2], [],
       [m4_if([$2], [], [], [[$1$2]])$0([$1], m4_shift(m4_shift($@)))])])


# lt_car(LIST)
# lt_cdr(LIST)
# ------------
# Manipulate m4 lists.
# These macros are necessary as long as will still need to support
# Autoconf-2.59 which quotes differently.
m4_define([lt_car], [[$1]])
m4_define([lt_cdr],
[m4_if([$#], 0, [m4_fatal([$0: cannot be called without arguments])],
       [$#], 1, [],
       [m4_dquote(m4_shift($@))])])
m4_define([lt_unquote], $1)


# lt_append(MACRO-NAME, STRING, [SEPARATOR])
# ------------------------------------------
# Redefine MACRO-NAME to hold its former content plus `SEPARATOR'`STRING'.
# Note that neither SEPARATOR nor STRING are expanded; they are appended
# to MACRO-NAME as is (leaving the expansion for when MACRO-NAME is invoked).
# No SEPARATOR is output if MACRO-NAME was previously undefined (different
# than defined and empty).
#
# This macro is needed until we can rely on Autoconf 2.62, since earlier
# versions of m4sugar mistakenly expanded SEPARATOR but not STRING.
m4_define([lt_append],
[m4_define([$1],
	   m4_ifdef([$1], [m4_defn([$1])[$3]])[$2])])



# lt_combine(SEP, PREFIX-LIST, INFIX, SUFFIX1, [SUFFIX2...])
# ----------------------------------------------------------
# Produce a SEP delimited list of all paired combinations of elements of
# PREFIX-LIST with SUFFIX1 through SUFFIXn.  Each element of the list
# has the form PREFIXmINFIXSUFFIXn.
# Needed until we can rely on m4_combine added in Autoconf 2.62.
m4_define([lt_combine],
[m4_if(m4_eval([$# > 3]), [1],
       [m4_pushdef([_Lt_sep], [m4_define([_Lt_sep], m4_defn([lt_car]))])]]dnl
[[m4_foreach([_Lt_prefix], [$2],
	     [m4_foreach([_Lt_suffix],
		]m4_dquote(m4_dquote(m4_shift(m4_shift(m4_shift($@)))))[,
	[_Lt_sep([$1])[]m4_defn([_Lt_prefix])[$3]m4_defn([_Lt_suffix])])])])])


# lt_if_append_uniq(MACRO-NAME, VARNAME, [SEPARATOR], [UNIQ], [NOT-UNIQ])
# -----------------------------------------------------------------------
# Iff MACRO-NAME does not yet contain VARNAME, then append it (delimited
# by SEPARATOR if supplied) and expand UNIQ, else NOT-UNIQ.
m4_define([lt_if_append_uniq],
[m4_ifdef([$1],
	  [m4_if(m4_index([$3]m4_defn([$1])[$3], [$3$2$3]), [-1],
		 [lt_append([$1], [$2], [$3])$4],
		 [$5])],
	  [lt_append([$1], [$2], [$3])$4])])


# lt_dict_add(DICT, KEY, VALUE)
# -----------------------------
m4_define([lt_dict_add],
[m4_define([$1($2)], [$3])])


# lt_dict_add_subkey(DICT, KEY, SUBKEY, VALUE)
# --------------------------------------------
m4_define([lt_dict_add_subkey],
[m4_define([$1($2:$3)], [$4])])


# lt_dict_fetch(DICT, KEY, [SUBKEY])
# ----------------------------------
m4_define([lt_dict_fetch],
[m4_ifval([$3],
	m4_ifdef([$1($2:$3)], [m4_defn([$1($2:$3)])]),
    m4_ifdef([$1($2)], [m4_defn([$1($2)])]))])


# lt_if_dict_fetch(DICT, KEY, [SUBKEY], VALUE, IF-TRUE, [IF-FALSE])
# -----------------------------------------------------------------
m4_define([lt_if_dict_fetch],
[m4_if(lt_dict_fetch([$1], [$2], [$3]), [$4],
	[$5],
    [$6])])


# lt_dict_filter(DICT, [SUBKEY], VALUE, [SEPARATOR], KEY, [...])
# --------------------------------------------------------------
m4_define([lt_dict_filter],
[m4_if([$5], [], [],
  [lt_join(m4_quote(m4_default([$4], [[, ]])),
           lt_unquote(m4_split(m4_normalize(m4_foreach(_Lt_key, lt_car([m4_shiftn(4, $@)]),
		      [lt_if_dict_fetch([$1], _Lt_key, [$2], [$3], [_Lt_key ])])))))])[]dnl
])

# ltversion.m4 -- version numbers			-*- Autoconf -*-
#
#   Copyright (C) 2004 Free Software Foundation, Inc.
#   Written by Scott James Remnant, 2004
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

# Generated from ltversion.in.

# serial 3169 ltversion.m4
# This file is part of GNU Libtool

m4_define([LT_PACKAGE_VERSION], [2.2.8])
m4_define([LT_PACKAGE_REVISION], [1.3169])

AC_DEFUN([LTVERSION_VERSION],
[macro_version='2.2.8'
macro_revision='1.3169'
_LT_DECL(, macro_version, 0, [Which release of libtool.m4 was used?])
_LT_DECL(, macro_revision, 0)
])

# lt~obsolete.m4 -- aclocal satisfying obsolete definitions.    -*-Autoconf-*-
#
#   Copyright (C) 2004, 2005, 2007, 2009 Free Software Foundation, Inc.
#   Written by Scott James Remnant, 2004.
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

# serial 5 lt~obsolete.m4

# These exist entirely to fool aclocal when bootstrapping libtool.
#
# In the past libtool.m4 has provided macros via AC_DEFUN (or AU_DEFUN)
# which have later been changed to m4_define as they aren't part of the
# exported API, or moved to Autoconf or Automake where they belong.
#
# The trouble is, aclocal is a bit thick.  It'll see the old AC_DEFUN
# in /usr/share/aclocal/libtool.m4 and remember it, then when it sees us
# using a macro with the same name in our local m4/libtool.m4 it'll
# pull the old libtool.m4 in (it doesn't see our shiny new m4_define
# and doesn't know about Autoconf macros at all.)
#
# So we provide this file, which has a silly filename so it's always
# included after everything else.  This provides aclocal with the
# AC_DEFUNs it wants, but when m4 processes it, it doesn't do anything
# because those macros already exist, or will be overwritten later.
# We use AC_DEFUN over AU_DEFUN for compatibility with aclocal-1.6. 
#
# Anytime we withdraw an AC_DEFUN or AU_DEFUN, remember to add it here.
# Yes, that means every name once taken will need to remain here until
# we give up compatibility with versions before 1.7, at which point
# we need to keep only those names which we still refer to.

# This is to help aclocal find these macros, as it can't see m4_define.
AC_DEFUN([LTOBSOLETE_VERSION], [m4_if([1])])

m4_ifndef([AC_LIBTOOL_LINKER_OPTION],	[AC_DEFUN([AC_LIBTOOL_LINKER_OPTION])])
m4_ifndef([AC_PROG_EGREP],		[AC_DEFUN([AC_PROG_EGREP])])
m4_ifndef([_LT_AC_PROG_ECHO_BACKSLASH],	[AC_DEFUN([_LT_AC_PROG_ECHO_BACKSLASH])])
m4_ifndef([_LT_AC_SHELL_INIT],		[AC_DEFUN([_LT_AC_SHELL_INIT])])
m4_ifndef([_LT_AC_SYS_LIBPATH_AIX],	[AC_DEFUN([_LT_AC_SYS_LIBPATH_AIX])])
m4_ifndef([_LT_PROG_LTMAIN],		[AC_DEFUN([_LT_PROG_LTMAIN])])
m4_ifndef([_LT_AC_TAGVAR],		[AC_DEFUN([_LT_AC_TAGVAR])])
m4_ifndef([AC_LTDL_ENABLE_INSTALL],	[AC_DEFUN([AC_LTDL_ENABLE_INSTALL])])
m4_ifndef([AC_LTDL_PREOPEN],		[AC_DEFUN([AC_LTDL_PREOPEN])])
m4_ifndef([_LT_AC_SYS_COMPILER],	[AC_DEFUN([_LT_AC_SYS_COMPILER])])
m4_ifndef([_LT_AC_LOCK],		[AC_DEFUN([_LT_AC_LOCK])])
m4_ifndef([AC_LIBTOOL_SYS_OLD_ARCHIVE],	[AC_DEFUN([AC_LIBTOOL_SYS_OLD_ARCHIVE])])
m4_ifndef([_LT_AC_TRY_DLOPEN_SELF],	[AC_DEFUN([_LT_AC_TRY_DLOPEN_SELF])])
m4_ifndef([AC_LIBTOOL_PROG_CC_C_O],	[AC_DEFUN([AC_LIBTOOL_PROG_CC_C_O])])
m4_ifndef([AC_LIBTOOL_SYS_HARD_LINK_LOCKS], [AC_DEFUN([AC_LIBTOOL_SYS_HARD_LINK_LOCKS])])
m4_ifndef([AC_LIBTOOL_OBJDIR],		[AC_DEFUN([AC_LIBTOOL_OBJDIR])])
m4_ifndef([AC_LTDL_OBJDIR],		[AC_DEFUN([AC_LTDL_OBJDIR])])
m4_ifndef([AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH], [AC_DEFUN([AC_LIBTOOL_PROG_LD_HARDCODE_LIBPATH])])
m4_ifndef([AC_LIBTOOL_SYS_LIB_STRIP],	[AC_DEFUN([AC_LIBTOOL_SYS_LIB_STRIP])])
m4_ifndef([AC_PATH_MAGIC],		[AC_DEFUN([AC_PATH_MAGIC])])
m4_ifndef([AC_PROG_LD_GNU],		[AC_DEFUN([AC_PROG_LD_GNU])])
m4_ifndef([AC_PROG_LD_RELOAD_FLAG],	[AC_DEFUN([AC_PROG_LD_RELOAD_FLAG])])
m4_ifndef([AC_DEPLIBS_CHECK_METHOD],	[AC_DEFUN([AC_DEPLIBS_CHECK_METHOD])])
m4_ifndef([AC_LIBTOOL_PROG_COMPILER_NO_RTTI], [AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_NO_RTTI])])
m4_ifndef([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE], [AC_DEFUN([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE])])
m4_ifndef([AC_LIBTOOL_PROG_COMPILER_PIC], [AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_PIC])])
m4_ifndef([AC_LIBTOOL_PROG_LD_SHLIBS],	[AC_DEFUN([AC_LIBTOOL_PROG_LD_SHLIBS])])
m4_ifndef([AC_LIBTOOL_POSTDEP_PREDEP],	[AC_DEFUN([AC_LIBTOOL_POSTDEP_PREDEP])])
m4_ifndef([LT_AC_PROG_EGREP],		[AC_DEFUN([LT_AC_PROG_EGREP])])
m4_ifndef([LT_AC_PROG_SED],		[AC_DEFUN([LT_AC_PROG_SED])])
m4_ifndef([_LT_CC_BASENAME],		[AC_DEFUN([_LT_CC_BASENAME])])
m4_ifndef([_LT_COMPILER_BOILERPLATE],	[AC_DEFUN([_LT_COMPILER_BOILERPLATE])])
m4_ifndef([_LT_LINKER_BOILERPLATE],	[AC_DEFUN([_LT_LINKER_BOILERPLATE])])
m4_ifndef([_AC_PROG_LIBTOOL],		[AC_DEFUN([_AC_PROG_LIBTOOL])])
m4_ifndef([AC_LIBTOOL_SETUP],		[AC_DEFUN([AC_LIBTOOL_SETUP])])
m4_ifndef([_LT_AC_CHECK_DLFCN],		[AC_DEFUN([_LT_AC_CHECK_DLFCN])])
m4_ifndef([AC_LIBTOOL_SYS_DYNAMIC_LINKER],	[AC_DEFUN([AC_LIBTOOL_SYS_DYNAMIC_LINKER])])
m4_ifndef([_LT_AC_TAGCONFIG],		[AC_DEFUN([_LT_AC_TAGCONFIG])])
m4_ifndef([AC_DISABLE_FAST_INSTALL],	[AC_DEFUN([AC_DISABLE_FAST_INSTALL])])
m4_ifndef([_LT_AC_LANG_CXX],		[AC_DEFUN([_LT_AC_LANG_CXX])])
m4_ifndef([_LT_AC_LANG_F77],		[AC_DEFUN([_LT_AC_LANG_F77])])
m4_ifndef([_LT_AC_LANG_GCJ],		[AC_DEFUN([_LT_AC_LANG_GCJ])])
m4_ifndef([AC_LIBTOOL_LANG_C_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_C_CONFIG])])
m4_ifndef([_LT_AC_LANG_C_CONFIG],	[AC_DEFUN([_LT_AC_LANG_C_CONFIG])])
m4_ifndef([AC_LIBTOOL_LANG_CXX_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG])])
m4_ifndef([_LT_AC_LANG_CXX_CONFIG],	[AC_DEFUN([_LT_AC_LANG_CXX_CONFIG])])
m4_ifndef([AC_LIBTOOL_LANG_F77_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_F77_CONFIG])])
m4_ifndef([_LT_AC_LANG_F77_CONFIG],	[AC_DEFUN([_LT_AC_LANG_F77_CONFIG])])
m4_ifndef([AC_LIBTOOL_LANG_GCJ_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_GCJ_CONFIG])])
m4_ifndef([_LT_AC_LANG_GCJ_CONFIG],	[AC_DEFUN([_LT_AC_LANG_GCJ_CONFIG])])
m4_ifndef([AC_LIBTOOL_LANG_RC_CONFIG],	[AC_DEFUN([AC_LIBTOOL_LANG_RC_CONFIG])])
m4_ifndef([_LT_AC_LANG_RC_CONFIG],	[AC_DEFUN([_LT_AC_LANG_RC_CONFIG])])
m4_ifndef([AC_LIBTOOL_CONFIG],		[AC_DEFUN([AC_LIBTOOL_CONFIG])])
m4_ifndef([_LT_AC_FILE_LTDLL_C],	[AC_DEFUN([_LT_AC_FILE_LTDLL_C])])
m4_ifndef([_LT_REQUIRED_DARWIN_CHECKS],	[AC_DEFUN([_LT_REQUIRED_DARWIN_CHECKS])])
m4_ifndef([_LT_AC_PROG_CXXCPP],		[AC_DEFUN([_LT_AC_PROG_CXXCPP])])
m4_ifndef([_LT_PREPARE_SED_QUOTE_VARS],	[AC_DEFUN([_LT_PREPARE_SED_QUOTE_VARS])])
m4_ifndef([_LT_PROG_ECHO_BACKSLASH],	[AC_DEFUN([_LT_PROG_ECHO_BACKSLASH])])
m4_ifndef([_LT_PROG_F77],		[AC_DEFUN([_LT_PROG_F77])])
m4_ifndef([_LT_PROG_FC],		[AC_DEFUN([_LT_PROG_FC])])
m4_ifndef([_LT_PROG_CXX],		[AC_DEFUN([_LT_PROG_CXX])])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_MACH_VM],
[CL_LINK_CHECK([vm_allocate], cl_cv_func_vm,
 , [vm_allocate(); task_self();],
AC_DEFINE(HAVE_MACH_VM,,[have vm_allocate() and task_self() functions])dnl
)])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2010 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_MMAP],
[AC_BEFORE([$0], [CL_MUNMAP])AC_BEFORE([$0], [CL_MPROTECT])
AC_CHECK_HEADER(sys/mman.h, , no_mmap=1)dnl
if test -z "$no_mmap"; then
AC_CHECK_FUNC(mmap, , no_mmap=1)dnl
if test -z "$no_mmap"; then
AC_DEFINE(HAVE_MMAP,,[have <sys/mmap.h> and the mmap() function])
AC_CACHE_CHECK(for working mmap, cl_cv_func_mmap_works, [
case "$host" in
  i[34567]86-*-sysv4*)
    # UNIX_SYSV_UHC_1
    avoid=0x08000000 ;;
  mips-sgi-irix* | mips-dec-ultrix*)
    # UNIX_IRIX, UNIX_DEC_ULTRIX
    avoid=0x10000000 ;;
  rs6000-ibm-aix*)
    # UNIX_AIX
    avoid=0x20000000 ;;
  *)
    avoid=0 ;;
esac
mmap_prog_1='
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
int main () {
'
mmap_prog_2="#define bits_to_avoid $avoid"'
#define my_shift 24
#define my_low   1
#ifdef FOR_SUN4_29
#define my_high  31
#define my_size  32768 /* hope that 32768 is a multiple of the page size */
/* i*32 KB for i=1..31 gives a total of 15.5 MB, which is close to what we need */
#else
#define my_high  64
#define my_size  8192 /* hope that 8192 is a multiple of the page size */
/* i*8 KB for i=1..64 gives a total of 16.25 MB, which is close to what we need */
#endif
#if defined(__APPLE__) && defined(__MACH__) && defined(__x86_64__)
/* On MacOS X in 64-bit mode, mmapable addresses start at 2^33. */
#define base_address 0x200000000UL
#else
#define base_address 0
#endif
 {long i;
#define i_ok(i)  ((i) & (bits_to_avoid >> my_shift) == 0)
  for (i=my_low; i<=my_high; i++)
    if (i_ok(i))
      { caddr_t addr = (caddr_t)(base_address + (i << my_shift));
/* Check for 8 MB, not 16 MB. This is more likely to work on Solaris 2. */
#if bits_to_avoid
        long size = i*my_size;
#else
        long size = ((i+1)/2)*my_size;
#endif
        if (mmap(addr,size,PROT_READ|PROT_WRITE,flags|MAP_FIXED,fd,0) == (void*)-1) exit(1);
    }
#define x(i)  *(unsigned char *) (base_address + (i<<my_shift) + (i*i))
#define y(i)  (unsigned char)((3*i-4)*(7*i+3))
  for (i=my_low; i<=my_high; i++) if (i_ok(i)) { x(i) = y(i); }
  for (i=my_high; i>=my_low; i--) if (i_ok(i)) { if (x(i) != y(i)) exit(1); }
  exit(0);
}}
'
AC_TRY_RUN(GL_NOCRASH[$mmap_prog_1
  int flags = MAP_ANON | MAP_PRIVATE;
  int fd = -1;
  nocrash_init();
$mmap_prog_2
], have_mmap_anon=1
cl_cv_func_mmap_anon=yes, ,
: # When cross-compiling, don't assume anything.
)
AC_TRY_RUN(GL_NOCRASH[$mmap_prog_1
  int flags = MAP_ANONYMOUS | MAP_PRIVATE;
  int fd = -1;
  nocrash_init();
$mmap_prog_2
], have_mmap_anon=1
cl_cv_func_mmap_anonymous=yes, ,
: # When cross-compiling, don't assume anything.
)
AC_TRY_RUN(GL_NOCRASH[$mmap_prog_1
#ifndef MAP_FILE
#define MAP_FILE 0
#endif
  int flags = MAP_FILE | MAP_PRIVATE;
  int fd = open("/dev/zero",O_RDONLY,0666);
  if (fd<0) exit(1);
  nocrash_init();
$mmap_prog_2
], have_mmap_devzero=1
cl_cv_func_mmap_devzero=yes, 
retry_mmap=1,
: # When cross-compiling, don't assume anything.
)
if test -n "$retry_mmap"; then
AC_TRY_RUN(GL_NOCRASH[#define FOR_SUN4_29
$mmap_prog_1
#ifndef MAP_FILE
#define MAP_FILE 0
#endif
  int flags = MAP_FILE | MAP_PRIVATE;
  int fd = open("/dev/zero",O_RDONLY,0666);
  if (fd<0) exit(1);
  nocrash_init();
$mmap_prog_2
], have_mmap_devzero=1
cl_cv_func_mmap_devzero_sun4_29=yes, ,
: # When cross-compiling, don't assume anything.
)
fi
if test -n "$have_mmap_anon" -o -n "$have_mmap_devzero"; then
cl_cv_func_mmap_works=yes
else
cl_cv_func_mmap_works=no
fi
])
if test "$cl_cv_func_mmap_anon" = yes; then
AC_DEFINE(HAVE_MMAP_ANON,,[<sys/mman.h> defines MAP_ANON and mmaping with MAP_ANON works])
fi
if test "$cl_cv_func_mmap_anonymous" = yes; then
AC_DEFINE(HAVE_MMAP_ANONYMOUS,,[<sys/mman.h> defines MAP_ANONYMOUS and mmaping with MAP_ANONYMOUS works])
fi
if test "$cl_cv_func_mmap_devzero" = yes; then
AC_DEFINE(HAVE_MMAP_DEVZERO,,[mmaping of the special device /dev/zero works])
fi
if test "$cl_cv_func_mmap_devzero_sun4_29" = yes; then
AC_DEFINE(HAVE_MMAP_DEVZERO_SUN4_29,,[mmaping of the special device /dev/zero works, but only on addresses < 2^29])
fi
fi
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2009 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_MPROTECT],
[AC_REQUIRE([gl_FUNC_GETPAGESIZE])dnl
AC_REQUIRE([CL_MMAP])dnl
AC_CHECK_FUNCS(mprotect)dnl
if test $ac_cv_func_mprotect = yes; then
AC_CACHE_CHECK(for working mprotect, cl_cv_func_mprotect_works, [
mprotect_prog='
#include <sys/types.h>
/* declare malloc() */
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
/* declare getpagesize() and mprotect() */
#include <sys/mman.h>
#ifndef HAVE_GETPAGESIZE
#include <sys/param.h>
#define getpagesize() PAGESIZE
#else
]AC_LANG_EXTERN[
int getpagesize (void);
#endif
char foo;
int main () {
  unsigned long pagesize = getpagesize();
#define page_align(address)  (char*)((unsigned long)(address) & -pagesize)
'
AC_TRY_RUN([$mprotect_prog
  if ((pagesize-1) & pagesize) exit(1);
  exit(0); }], , no_mprotect=1,
# When cross-compiling, don't assume anything.
no_mprotect=1)
mprotect_prog="$mprotect_prog"'
  char* area = (char*) malloc(6*pagesize);
  char* fault_address = area + pagesize*7/2;
'
if test -z "$no_mprotect"; then
AC_TRY_RUN(GL_NOCRASH[$mprotect_prog
  nocrash_init();
  if (mprotect(page_align(fault_address),pagesize,PROT_NONE) < 0) exit(0);
  foo = *fault_address; /* this should cause an exception or signal */
  exit(0); }], no_mprotect=1, ,
: # When cross-compiling, don't assume anything.
)
fi
if test -z "$no_mprotect"; then
AC_TRY_RUN(GL_NOCRASH[$mprotect_prog
  nocrash_init();
  if (mprotect(page_align(fault_address),pagesize,PROT_NONE) < 0) exit(0);
  *fault_address = 'z'; /* this should cause an exception or signal */
  exit(0); }], no_mprotect=1, ,
: # When cross-compiling, don't assume anything.
)
fi
if test -z "$no_mprotect"; then
AC_TRY_RUN(GL_NOCRASH[$mprotect_prog
  nocrash_init();
  if (mprotect(page_align(fault_address),pagesize,PROT_READ) < 0) exit(0);
  *fault_address = 'z'; /* this should cause an exception or signal */
  exit(0); }], no_mprotect=1, ,
: # When cross-compiling, don't assume anything.
)
fi
if test -z "$no_mprotect"; then
AC_TRY_RUN(GL_NOCRASH[$mprotect_prog
  nocrash_init();
  if (mprotect(page_align(fault_address),pagesize,PROT_READ) < 0) exit(1);
  if (mprotect(page_align(fault_address),pagesize,PROT_READ|PROT_WRITE) < 0) exit(1);
  *fault_address = 'z'; /* this should not cause an exception or signal */
  exit(0); }], , no_mprotect=1,
: # When cross-compiling, don't assume anything.
)
fi
if test -z "$no_mprotect"; then
  cl_cv_func_mprotect_works=yes
else
  cl_cv_func_mprotect_works=no
fi
])
if test $cl_cv_func_mprotect_works = yes; then
  AC_DEFINE(HAVE_WORKING_MPROTECT,,[have a working mprotect() function])
fi
fi
])

dnl Copyright (C) 1993-2002 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels.

AC_PREREQ(2.13)

AC_DEFUN([CL_MSYNC],
[AC_REQUIRE([CL_MMAP])dnl
if test -z "$no_mmap"; then
AC_CHECK_FUNCS(msync)dnl
fi
])

dnl Copyright (C) 1993-2002 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels.

AC_PREREQ(2.13)

AC_DEFUN([CL_MUNMAP],
[AC_REQUIRE([CL_MMAP])dnl
if test -z "$no_mmap"; then
AC_CHECK_FUNCS(munmap)dnl
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.61)

dnl CL_MACHINE([MESSAGE], [PROGRAM_TO_RUN], [CROSS_MACRO], [DESTINATION], [CACHE_VAR])
AC_DEFUN([CL_MACHINE],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_C_CHAR_UNSIGNED])dnl
cl_machine_file_c=$2
if test -z "$[$5]"; then
AC_MSG_CHECKING(for [$1])
cl_machine_file_h=$4
ORIGCC="$CC"
if test $ac_cv_prog_gcc = yes; then
# gcc -O (gcc version <= 2.3.2) crashes when compiling long long shifts for
# target 80386. Strip "-O".
CC=`echo "$CC " | sed -e 's/-O //g'`
fi
cl_machine_file_program=`cat "$cl_machine_file_c"`
AC_RUN_IFELSE([#include "confdefs.h"
$cl_machine_file_program],[AC_MSG_RESULT(created $cl_machine_file_h)
if cmp -s "$cl_machine_file_h" conftest.h 2>/dev/null; then
  # The file exists and we would not be changing it
  rm -f conftest.h
else
  rm -f "$cl_machine_file_h"
  mv conftest.h "$cl_machine_file_h"
fi
[$5]=1],[AC_MSG_RESULT(creation of $cl_machine_file_h failed)],
[AC_MSG_RESULT(creating $cl_machine_file_h)
$3([$4])])
rm -f conftest.h
CC="$ORIGCC"
fi
])

# pkg.m4 - Macros to locate and utilise pkg-config.            -*- Autoconf -*-
# 
# Copyright © 2004 Scott James Remnant <scott@netsplit.com>.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
# As a special exception to the GNU General Public License, if you
# distribute this file as part of a program that contains a
# configuration script generated by Autoconf, you may include it under
# the same distribution terms that you use for the rest of that program.

# PKG_PROG_PKG_CONFIG([MIN-VERSION])
# ----------------------------------
AC_DEFUN([PKG_PROG_PKG_CONFIG],
[m4_pattern_forbid([^_?PKG_[A-Z_]+$])
m4_pattern_allow([^PKG_CONFIG(_PATH)?$])
AC_ARG_VAR([PKG_CONFIG], [path to pkg-config utility])dnl
if test "x$ac_cv_env_PKG_CONFIG_set" != "xset"; then
	AC_PATH_TOOL([PKG_CONFIG], [pkg-config])
fi
if test -n "$PKG_CONFIG"; then
	_pkg_min_version=m4_default([$1], [0.9.0])
	AC_MSG_CHECKING([pkg-config is at least version $_pkg_min_version])
	if $PKG_CONFIG --atleast-pkgconfig-version $_pkg_min_version; then
		AC_MSG_RESULT([yes])
	else
		AC_MSG_RESULT([no])
		PKG_CONFIG=""
	fi
		
fi[]dnl
])# PKG_PROG_PKG_CONFIG

# PKG_CHECK_EXISTS(MODULES, [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
#
# Check to see whether a particular set of modules exists.  Similar
# to PKG_CHECK_MODULES(), but does not set variables or print errors.
#
#
# Similar to PKG_CHECK_MODULES, make sure that the first instance of
# this or PKG_CHECK_MODULES is called, or make sure to call
# PKG_CHECK_EXISTS manually
# --------------------------------------------------------------
AC_DEFUN([PKG_CHECK_EXISTS],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
if test -n "$PKG_CONFIG" && \
    AC_RUN_LOG([$PKG_CONFIG --exists --print-errors "$1"]); then
  m4_ifval([$2], [$2], [:])
m4_ifvaln([$3], [else
  $3])dnl
fi])


# _PKG_CONFIG([VARIABLE], [COMMAND], [MODULES])
# ---------------------------------------------
m4_define([_PKG_CONFIG],
[if test -n "$$1"; then
    pkg_cv_[]$1="$$1"
 elif test -n "$PKG_CONFIG"; then
    PKG_CHECK_EXISTS([$3],
                     [pkg_cv_[]$1=`$PKG_CONFIG --[]$2 "$3" 2>/dev/null`],
		     [pkg_failed=yes])
 else
    pkg_failed=untried
fi[]dnl
])# _PKG_CONFIG

# _PKG_SHORT_ERRORS_SUPPORTED
# -----------------------------
AC_DEFUN([_PKG_SHORT_ERRORS_SUPPORTED],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])
if $PKG_CONFIG --atleast-pkgconfig-version 0.20; then
        _pkg_short_errors_supported=yes
else
        _pkg_short_errors_supported=no
fi[]dnl
])# _PKG_SHORT_ERRORS_SUPPORTED


# PKG_CHECK_MODULES(VARIABLE-PREFIX, MODULES, [ACTION-IF-FOUND],
# [ACTION-IF-NOT-FOUND])
#
#
# Note that if there is a possibility the first call to
# PKG_CHECK_MODULES might not happen, you should be sure to include an
# explicit call to PKG_PROG_PKG_CONFIG in your configure.ac
#
#
# --------------------------------------------------------------
AC_DEFUN([PKG_CHECK_MODULES],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
AC_ARG_VAR([$1][_CFLAGS], [C compiler flags for $1, overriding pkg-config])dnl
AC_ARG_VAR([$1][_LIBS], [linker flags for $1, overriding pkg-config])dnl

pkg_failed=no
AC_MSG_CHECKING([for $1])

_PKG_CONFIG([$1][_CFLAGS], [cflags], [$2])
_PKG_CONFIG([$1][_LIBS], [libs], [$2])

m4_define([_PKG_TEXT], [Alternatively, you may set the environment variables $1[]_CFLAGS
and $1[]_LIBS to avoid the need to call pkg-config.
See the pkg-config man page for more details.])

if test $pkg_failed = yes; then
        _PKG_SHORT_ERRORS_SUPPORTED
        if test $_pkg_short_errors_supported = yes; then
	        $1[]_PKG_ERRORS=`$PKG_CONFIG --short-errors --print-errors "$2" 2>&1`
        else 
	        $1[]_PKG_ERRORS=`$PKG_CONFIG --print-errors "$2" 2>&1`
        fi
	# Put the nasty error message in config.log where it belongs
	echo "$$1[]_PKG_ERRORS" >&AS_MESSAGE_LOG_FD

	ifelse([$4], , [AC_MSG_ERROR(dnl
[Package requirements ($2) were not met:

$$1_PKG_ERRORS

Consider adjusting the PKG_CONFIG_PATH environment variable if you
installed software in a non-standard prefix.

_PKG_TEXT
])],
		[AC_MSG_RESULT([no])
                $4])
elif test $pkg_failed = untried; then
	ifelse([$4], , [AC_MSG_FAILURE(dnl
[The pkg-config script could not be found or is too old.  Make sure it
is in your PATH or set the PKG_CONFIG environment variable to the full
path to pkg-config.

_PKG_TEXT

To get pkg-config, see <http://pkg-config.freedesktop.org/>.])],
		[$4])
else
	$1[]_CFLAGS=$pkg_cv_[]$1[]_CFLAGS
	$1[]_LIBS=$pkg_cv_[]$1[]_LIBS
        AC_MSG_RESULT([yes])
	ifelse([$3], , :, [$3])
fi[]dnl
])# PKG_CHECK_MODULES

dnl -*- Autoconf -*-
dnl Copyright (C) 2004-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible.

AC_PREREQ(2.57)

AC_DEFUN([CL_POLL],
[AC_CHECK_FUNC(poll,
  [# Check whether poll() works on special files (like /dev/null)
   # and ttys (like /dev/tty). On MacOS X 10.4.0, it doesn't.
   AC_TRY_RUN([
#include <fcntl.h>
#include <poll.h>
     int main()
     {
       struct pollfd ufd;
       /* Try /dev/null for reading. */
       ufd.fd = open ("/dev/null", O_RDONLY);
       if (ufd.fd < 0) /* If /dev/null does not exist, it's not MacOS X. */
         return 0;
       ufd.events = POLLIN;
       ufd.revents = 0;
       if (!(poll (&ufd, 1, 0) == 1 && ufd.revents == POLLIN))
         return 1;
       /* Try /dev/null for writing. */
       ufd.fd = open ("/dev/null", O_WRONLY);
       if (ufd.fd < 0) /* If /dev/null does not exist, it's not MacOS X. */
         return 0;
       ufd.events = POLLOUT;
       ufd.revents = 0;
       if (!(poll (&ufd, 1, 0) == 1 && ufd.revents == POLLOUT))
         return 1;
       /* Trying /dev/tty may be too environment dependent. */
       return 0;
     }],
     [cl_cv_func_poll=yes],
     [cl_cv_func_poll=no],
     [# When cross-compiling, assume that poll() works everywhere except on
      # MacOS X, regardless of its version.
      AC_EGREP_CPP([MacOSX], [
#if defined(__APPLE__) && defined(__MACH__)
This is MacOSX
#endif
], [cl_cv_func_poll=no], [cl_cv_func_poll=yes])])])
dnl if AC_CHECK_FUNC does not find poll, cl_cv_func_poll will not be set
if test x$cl_cv_func_poll = xyes; then
  AC_DEFINE([HAVE_POLL], 1,
    [Define to 1 if you have the 'poll' function and it works.])
# Now check whether poll() works reliably on regular files, i.e. signals
# immediate readability and writability, both before EOF and at EOF.
# On FreeBSD 4.0, it doesn't.
AC_CACHE_CHECK([for reliable poll()], cl_cv_func_poll_reliable, [
AC_TRY_RUN([
/* Declare poll(). */
#include <poll.h>
/* Declare open(). */
#include <fcntl.h>
/* Declare lseek(). */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
int main ()
{ int fd = open("conftest.c",O_RDWR,0644);
  int correct_readability_nonempty, correct_readability_empty;
  int correct_writability_nonempty, correct_writability_empty;
  struct pollfd pollfd_bag[1];
  {
    pollfd_bag[0].fd = fd;
    pollfd_bag[0].events = POLLIN;
    pollfd_bag[0].revents = 0;
    correct_readability_nonempty =
      (poll(&pollfd_bag[0],1,0) >= 0 && pollfd_bag[0].revents != 0);
  }
  {
    pollfd_bag[0].fd = fd;
    pollfd_bag[0].events = POLLOUT;
    pollfd_bag[0].revents = 0;
    correct_writability_nonempty =
      (poll(&pollfd_bag[0],1,0) >= 0 && pollfd_bag[0].revents != 0);
  }
  lseek(fd,0,SEEK_END);
  {
    pollfd_bag[0].fd = fd;
    pollfd_bag[0].events = POLLIN;
    pollfd_bag[0].revents = 0;
    correct_readability_empty =
      (poll(&pollfd_bag[0],1,0) >= 0 && pollfd_bag[0].revents != 0);
  }
  {
    pollfd_bag[0].fd = fd;
    pollfd_bag[0].events = POLLOUT;
    pollfd_bag[0].revents = 0;
    correct_writability_empty =
      (poll(&pollfd_bag[0],1,0) >= 0 && pollfd_bag[0].revents != 0);
  }
  exit(!(correct_readability_nonempty && correct_readability_empty
         && correct_writability_nonempty && correct_writability_empty));
}],
cl_cv_func_poll_reliable=yes, cl_cv_func_poll_reliable=no,
dnl When cross-compiling, don't assume anything.
cl_cv_func_poll_reliable="guessing no")
])
case "$cl_cv_func_poll_reliable" in
  *yes) AC_DEFINE(HAVE_RELIABLE_POLL,,[have poll() and it works reliably on files]) ;;
  *no) ;;
esac
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2002, 2007-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.13)

dnl CL_PROTO(IDENTIFIER, ACTION-IF-NOT-FOUND, FINAL-PROTOTYPE)
AC_DEFUN([CL_PROTO],
[AC_MSG_CHECKING([for $1 declaration])
AC_CACHE_VAL(cl_cv_proto_[$1], [$2
cl_cv_proto_$1="$3"])
cl_cv_proto_$1=`echo "[$]cl_cv_proto_$1" | tr -s ' ' | sed -e 's/( /(/'`
AC_MSG_RESULT([$]{ac_t:-
         }[$]cl_cv_proto_$1)
])

dnl CL_PROTO_RET(INCLUDES, DECL, CACHE-ID, TYPE-IF-OK, TYPE-IF-FAILS)
AC_DEFUN([CL_PROTO_RET],
[AC_TRY_COMPILE([$1]
AC_LANG_EXTERN
[$2
], [], $3="$4", $3="$5")
])

dnl CL_PROTO_TRY(INCLUDES, DECL, ACTION-IF-OK, ACTION-IF-FAILS)
AC_DEFUN([CL_PROTO_TRY],
[AC_TRY_COMPILE([$1]
AC_LANG_EXTERN
[$2
], [], [$3], [$4])
])

dnl CL_PROTO_CONST(INCLUDES, DECL, CACHE-ID)
AC_DEFUN([CL_PROTO_CONST],
[CL_PROTO_TRY([$1], [$2], $3="", $3="const")]
)

dnl CL_PROTO_MISSING(function_name)
AC_DEFUN([CL_PROTO_MISSING],
[AC_MSG_FAILURE([please report the $1() declaration on your platform to $PACKAGE_NAME developers at $PACKAGE_BUGREPORT])])

m4_define([CONST_VARIANTS],['' 'const' '__const'])
m4_define([SIZE_VARIANTS],['unsigned int' 'int' 'unsigned long' 'long' 'size_t' 'socklen_t'])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_PUTENV],
[AC_REQUIRE([AC_GNU_SOURCE])
dnl Not AC_CHECK_FUNCS(putenv) because it doesn't work when CC=g++.
AC_CACHE_CHECK([for putenv], ac_cv_func_putenv, [
AC_LINK_IFELSE(AC_LANG_PROGRAM([#include <stdlib.h>], [putenv("")]),
ac_cv_func_putenv=yes, ac_cv_func_putenv=no)])
if test $ac_cv_func_putenv = yes; then
  AC_DEFINE(HAVE_PUTENV, 1, [Define if you have the putenv() function.])
fi
AC_CHECK_FUNCS(setenv unsetenv)dnl
AC_CHECK_DECLS(environ,,,[#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif])
if test "$ac_cv_func_unsetenv" = yes; then
  AC_MSG_CHECKING(return value of unsetenv)
  CL_PROTO_RET([#include <stdlib.h>],[int unsetenv(char*);],
cl_cv_proto_unsetenv_ret,int,void)
  AC_MSG_RESULT($cl_cv_proto_unsetenv_ret)
  if test "$cl_cv_proto_unsetenv_ret" = int;
  then cl_cv_proto_unsetenv_posix=1
  else cl_cv_proto_unsetenv_posix=0
  fi
  AC_DEFINE_UNQUOTED(UNSETENV_POSIX,$cl_cv_proto_unsetenv_posix,
  [define to 1 if the return type of unsetenv is int])
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 2002-2008, 2010 Sam Steingold, Bruno Haible
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

AC_PREREQ(2.57)

AC_DEFUN([CL_READLINE],[dnl
AC_ARG_WITH([readline],
AC_HELP_STRING([--with-readline],[use readline (default is YES, if present)]),
[ac_cv_use_readline=$withval], [ac_cv_use_readline=default])
ac_cv_have_readline=no
if test "$ac_cv_use_readline" = "no" ; then
AC_MSG_NOTICE([not checking for readline])
else
AC_REQUIRE([CL_TERMCAP])dnl
if test $ac_cv_search_tgetent != no ; then
 AC_LIB_LINKFLAGS_BODY(readline)
 ac_save_CPPFLAGS="$CPPFLAGS"
 CPPFLAGS="$CPPFLAGS $INCREADLINE"
 AC_CHECK_HEADERS(readline/readline.h)
 if test "$ac_cv_header_readline_readline_h" != yes; then
  CPPFLAGS="$ac_save_CPPFLAGS"
 else # have <readline/readline.h> => check library
  ac_save_LIBS="$LIBS"
  LIBS="$LIBREADLINE $LIBS"
  AC_CHECK_FUNC(readline)dnl do not define HAVE_READLINE
  AC_CHECK_FUNCS(rl_filename_completion_function)
  if test "$ac_cv_func_readline" != yes ; then
    LIBS="$ac_save_LIBS"
    CPPFLAGS="$ac_save_CPPFLAGS"
  else # have readline => check modern features
    if test $ac_cv_func_rl_filename_completion_function = no ;
    then RL_FCF=filename_completion_function
    else RL_FCF=rl_filename_completion_function
    fi
    dnl READLINE_CONST is necessary for C++ compilation of stream.d
    CL_PROTO([filename_completion_function], [
      CL_PROTO_CONST([
#include <stdio.h>
#include <readline/readline.h>
      ],[char* ${RL_FCF} (char *, int);],
      cl_cv_proto_readline_const) ],
      [extern char* ${RL_FCF}($cl_cv_proto_readline_const char*, int);])
    AC_CHECK_DECLS([rl_already_prompted, rl_readline_name, dnl
rl_gnu_readline_p, rl_deprep_term_function],,,
[#include <stdio.h>
#include <readline/readline.h>])
    AC_MSG_CHECKING(for a modern readline)
    if test "$ac_cv_have_decl_rl_already_prompted" = yes \
         -a "$ac_cv_have_decl_rl_gnu_readline_p" = yes; then
      dnl LIBREADLINE has been added to LIBS.
      AC_MSG_RESULT([found a modern GNU readline])
      ac_cv_have_readline=yes
    else
      AC_MSG_RESULT([readline is too old and will not be used])
      LIBS="$ac_save_LIBS"
      CPPFLAGS="$ac_save_CPPFLAGS"
    fi
  fi
 fi
fi
if test "$ac_cv_have_readline" = yes; then
  AC_DEFINE_UNQUOTED(READLINE_FILE_COMPLETE,${RL_FCF},[The readline built-in filename completion function, either rl_filename_completion_function() or filename_completion_function()])
  AC_DEFINE_UNQUOTED(READLINE_CONST,$cl_cv_proto_readline_const,[declaration of filename_completion_function() needs const in the first argument])
  AC_DEFINE(HAVE_READLINE,,[have a working modern GNU readline])
elif test "$ac_cv_use_readline" = yes; then
  AC_MSG_FAILURE([despite --with-readline, GNU readline was not found (try --with-libreadline-prefix)])
fi
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_RLIMIT],
[AC_CHECK_FUNCS(getrlimit setrlimit)dnl
if test $ac_cv_func_setrlimit = yes; then
AC_CHECK_SIZEOF(rlim_t,,[#include <stdio.h>
#include <sys/resource.h>])
CL_PROTO([getrlimit], [
CL_PROTO_TRY([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
],
[int getrlimit (int resource, struct rlimit * rlim);],
[cl_cv_proto_getrlimit_arg1="int"],
[cl_cv_proto_getrlimit_arg1="enum __rlimit_resource"])
], [extern int getrlimit ($cl_cv_proto_getrlimit_arg1, struct rlimit *);])
AC_DEFINE_UNQUOTED(RLIMIT_RESOURCE_T,$cl_cv_proto_getrlimit_arg1,[type of `resource' in setrlimit() declaration])
CL_PROTO([setrlimit], [
CL_PROTO_CONST([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
], [int setrlimit (RLIMIT_RESOURCE_T resource, struct rlimit * rlim);],
cl_cv_proto_setrlimit_arg2)
], [extern int setrlimit ($cl_cv_proto_getrlimit_arg1, $cl_cv_proto_setrlimit_arg2 struct rlimit *);])
AC_DEFINE_UNQUOTED(SETRLIMIT_CONST,$cl_cv_proto_setrlimit_arg2,[declaration of setrlimit() needs const])
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold, Peter Burwood.

AC_PREREQ(2.57)

AC_DEFUN([CL_RUSAGE],
[AC_CHECK_HEADERS(sys/resource.h sys/times.h)dnl
if test $ac_cv_header_sys_resource_h = yes; then
  dnl HAVE_SYS_RESOURCE_H defined
  CL_LINK_CHECK([getrusage], cl_cv_func_getrusage,
[#include <sys/types.h> /* NetBSD 1.0 needs this */
#include <sys/time.h>
#include <sys/resource.h>],
    [struct rusage x; int y = RUSAGE_SELF; getrusage(y,&x); x.ru_utime.tv_sec;])dnl
  if test $cl_cv_func_getrusage = yes; then
    CL_PROTO([getrusage], [CL_PROTO_TRY([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h> /* NetBSD 1.0 needs this */
#include <sys/time.h>
#include <sys/resource.h>
],
[int getrusage (int who, struct rusage * rusage);],
[cl_cv_proto_getrusage_arg1="int"],
[cl_cv_proto_getrusage_arg1="enum __rusage_who"])
], [extern int getrusage ($cl_cv_proto_getrusage_arg1, struct rusage *);])dnl
    AC_CACHE_CHECK(whether getrusage works, cl_cv_func_getrusage_works, [
    AC_RUN_IFELSE([AC_LANG_SOURCE([[#include <stdio.h>
#include <sys/types.h> /* NetBSD 1.0 needs this */
#include <sys/time.h>
#include <time.h> /* for time(2) */
#include <sys/resource.h>
int main ()
{
  struct rusage used, prev;
  time_t end = time(NULL)+2;
  int count = 0;

  if ((count = getrusage(RUSAGE_SELF, &prev))) {
    /* getrusage is defined but does not do anything. */
    /*fprintf(stderr,"getrusage failed: return=%d\n",count);*/
    return 1;
  }
  while (time(NULL) < end) {
    count++;
    getrusage(RUSAGE_SELF, &used);
    if ((used.ru_utime.tv_usec != prev.ru_utime.tv_usec)
        || (used.ru_utime.tv_sec != prev.ru_utime.tv_sec)
        || (used.ru_stime.tv_usec != prev.ru_stime.tv_usec)
        || (used.ru_stime.tv_sec != prev.ru_stime.tv_sec)) {
      /*fprintf(stderr,"success after %d runs\n",count);*/
      return 0;
    }
  }
  /* getrusage is defined but does not work. */
  /*fprintf(stderr,"failure after %d runs\n",count);*/
  return 1;
}]])],[cl_cv_func_getrusage_works=yes],[cl_cv_func_getrusage_works=no],
dnl When cross-compiling, don't assume anything.
[cl_cv_func_getrusage_works="guessing no"])])
  fi
  if test "$cl_cv_func_getrusage_works" = yes; then
    AC_DEFINE(HAVE_GETRUSAGE,,[have <sys/time.h>, the getrusage() function, the struct rusage type, and <sys/resource.h> defines RUSAGE_SELF])
    AC_DEFINE_UNQUOTED(RUSAGE_WHO_T,$cl_cv_proto_getrusage_arg1,[type of `who' in getrusage() declaration])
  fi
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2004, 2007-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SELECT],
[dnl Not AC_CHECK_FUNCS(select) because it doesn't work when CC=g++.
AC_CACHE_CHECK([for select], ac_cv_func_select, [
AC_TRY_LINK([
#ifdef __BEOS__
#include <sys/socket.h>
#endif
#include <sys/time.h>
]AC_LANG_EXTERN[
#ifdef __cplusplus
int select(int, fd_set*, fd_set*, fd_set*, struct timeval *);
#else
int select();
#endif
], [select(0,(fd_set*)0,(fd_set*)0,(fd_set*)0,(struct timeval *)0);],
ac_cv_func_select=yes, ac_cv_func_select=no)])
if test $ac_cv_func_select = yes; then
AC_DEFINE(HAVE_SELECT, 1, [Define if you have the select() function.])
CL_COMPILE_CHECK([sys/select.h], cl_cv_header_sys_select_h,
[#ifdef __BEOS__
#include <sys/socket.h>
#endif
#include <sys/time.h>
#include <sys/select.h>], ,
AC_DEFINE(HAVE_SYS_SELECT_H,,[have <sys/select.h>?]))dnl
CL_PROTO([select], [
for z in CONST_VARIANTS; do
for y in 'fd_set' 'int' 'void' 'struct fd_set'; do
for x in SIZE_VARIANTS; do
if test -z "$have_select"; then
CL_PROTO_TRY([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#ifdef __BEOS__
#include <sys/socket.h>
#endif
#include <sys/time.h>
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
], [int select ($x width, $y * readfds, $y * writefds, $y * exceptfds, $z struct timeval * timeout);],
[cl_cv_proto_select_arg1="$x"
cl_cv_proto_select_arg2="$y"
cl_cv_proto_select_arg5="$z"
have_select=1])
fi
done
done
done
if test -z "$have_select"; then
CL_PROTO_MISSING(select)
fi
], [extern int select ($cl_cv_proto_select_arg1, $cl_cv_proto_select_arg2 *, $cl_cv_proto_select_arg2 *, $cl_cv_proto_select_arg2 *, $cl_cv_proto_select_arg5 struct timeval *);])
AC_DEFINE_UNQUOTED(SELECT_WIDTH_T,$cl_cv_proto_select_arg1,[type of `width' in select() declaration])
AC_DEFINE_UNQUOTED(SELECT_SET_T,$cl_cv_proto_select_arg2,[type of `* readfds', `* writefds', `* exceptfds' in select() declaration])
AC_DEFINE_UNQUOTED(SELECT_CONST,$cl_cv_proto_select_arg5,[declaration of select() needs const in the fifth argument])
# Now check whether select() works reliably on regular files, i.e. signals
# immediate readability and writability, both before EOF and at EOF.
AC_CACHE_CHECK([for reliable select()], cl_cv_func_select_reliable, [
AC_TRY_RUN([
/* Declare select(). */
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#ifdef __BEOS__
#include <sys/socket.h>
#endif
#include <sys/time.h>
#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
]AC_LANG_EXTERN[
int select (SELECT_WIDTH_T, SELECT_SET_T*, SELECT_SET_T*, SELECT_SET_T*, SELECT_CONST struct timeval *);
/* Declare open(). */
#include <fcntl.h>
int main ()
{ int fd = open("conftest.c",O_RDWR,0644);
  int correct_readability_nonempty, correct_readability_empty;
  int correct_writability_nonempty, correct_writability_empty;
  fd_set handle_set;
  struct timeval zero_time;
  {
    FD_ZERO(&handle_set); FD_SET(fd,&handle_set);
    zero_time.tv_sec = 0; zero_time.tv_usec = 0;
    correct_readability_nonempty =
      (select(FD_SETSIZE,&handle_set,NULL,NULL,&zero_time) == 1);
  }
  {
    FD_ZERO(&handle_set); FD_SET(fd,&handle_set);
    zero_time.tv_sec = 0; zero_time.tv_usec = 0;
    correct_writability_nonempty =
      (select(FD_SETSIZE,NULL,&handle_set,NULL,&zero_time) == 1);
  }
  lseek(fd,0,SEEK_END);
  {
    FD_ZERO(&handle_set); FD_SET(fd,&handle_set);
    zero_time.tv_sec = 0; zero_time.tv_usec = 0;
    correct_readability_empty =
      (select(FD_SETSIZE,&handle_set,NULL,NULL,&zero_time) == 1);
  }
  {
    FD_ZERO(&handle_set); FD_SET(fd,&handle_set);
    zero_time.tv_sec = 0; zero_time.tv_usec = 0;
    correct_writability_empty =
      (select(FD_SETSIZE,NULL,&handle_set,NULL,&zero_time) == 1);
  }
  exit(!(correct_readability_nonempty && correct_readability_empty
         && correct_writability_nonempty && correct_writability_empty));
}],
cl_cv_func_select_reliable=yes, cl_cv_func_select_reliable=no,
dnl When cross-compiling, don't assume anything.
cl_cv_func_select_reliable="guessing no")
])
case "$cl_cv_func_select_reliable" in
  *yes) AC_DEFINE(HAVE_RELIABLE_SELECT,,[have select() and it works reliably on files]) ;;
  *no) ;;
esac
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SETJMP],
[AC_CHECK_FUNC(_setjmp, , no__jmp=1)dnl
if test -z "$no__jmp"; then
AC_CHECK_FUNC(_longjmp, , no__jmp=1)dnl
fi
if test -z "$no__jmp"; then
AC_DEFINE(HAVE__JMP,,[have _setjmp() and _longjmp()])
fi
AC_EGREP_HEADER([void.* longjmp], setjmp.h, , AC_DEFINE(LONGJMP_RETURNS,,[longjmp() may return]))
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SHM_RMID],
[AC_REQUIRE([CL_SHM])dnl
if test "$cl_cv_sys_shm_works" = "yes"; then
AC_CACHE_CHECK(for attachability of removed shared memory, cl_cv_func_shmctl_attachable, [
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#ifdef HAVE_SYS_SYSMACROS_H
#include <sys/sysmacros.h>
#endif
int main ()
{ unsigned int pagesize = 8192; /* should be a multiple of SHMLBA */
  unsigned long addr = (unsigned long) malloc(2*pagesize);
  addr += pagesize-1; addr = (addr/pagesize)*pagesize;
 {unsigned long addr1 = addr + 0x100000;
  unsigned long addr2 = addr + 0x200000;
  int id = shmget(IPC_PRIVATE,pagesize,IPC_CREAT|0600);
  if (id<0)
    { exit(1); }
  if (shmat(id,(void*)addr1,0) == (void*)(-1))
    { shmctl(id,IPC_RMID,NULL); exit(1); }
  if (shmctl(id,IPC_RMID,NULL) < 0)
    { exit(1); }
  if (shmat(id,(void*)addr2,0) == (void*)(-1))
    { shmctl(id,IPC_RMID,NULL); exit(1); }
  shmctl(id,IPC_RMID,NULL);
  exit(0);
}}
], cl_cv_func_shmctl_attachable=yes, cl_cv_func_shmctl_attachable=no,
dnl When cross-compiling, don't assume anything.
cl_cv_func_shmctl_attachable="guessing no")
])
case "$cl_cv_func_shmctl_attachable" in
  *yes) AC_DEFINE(SHM_RMID_VALID,,[attaching removed (but alive!) shared memory segments works]) ;;
  *no)  ;;
esac
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SHM_H],
[AC_BEFORE([$0], [CL_SHM])dnl
AC_CHECK_HEADERS(sys/shm.h)
if test $ac_cv_header_sys_shm_h = yes; then
AC_CHECK_HEADERS(sys/ipc.h)
fi
])

AC_DEFUN([CL_SHM],
[AC_BEFORE([$0], [CL_SHM_RMID])dnl
AC_REQUIRE([CL_SHM_H])dnl
if test "$ac_cv_header_sys_shm_h" = yes -a "$ac_cv_header_sys_ipc_h" = yes; then
# This test is from Marcus Daniels
AC_CACHE_CHECK(for working shared memory, cl_cv_sys_shm_works, [
AC_TRY_RUN([#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
/* try attaching a single segment to multiple addresses */
#define segsize 0x10000
#define attaches 128
#define base_addr 0x01000000
int main ()
{ int shmid, i; char* addr; char* result;
  if ((shmid = shmget(IPC_PRIVATE,segsize,0400)) < 0) exit(1);
  for (i=0, addr = (char*)0x01000000; i<attaches; i++, addr += segsize)
    if ((result = (char*)shmat(shmid,addr,SHM_RDONLY)) == (char*)(-1)) break;
  for (i=0, addr = (char*)0x01000000; i<attaches; i++, addr += segsize)
    shmdt(addr);
  shmctl(shmid,IPC_RMID,0);
  exit(result == (char*)(-1));
}], cl_cv_sys_shm_works=yes, cl_cv_sys_shm_works=no,
dnl When cross-compiling, don't assume anything.
cl_cv_sys_shm_works="guessing no")
])
fi
case "$cl_cv_sys_shm_works" in
  *yes) AC_DEFINE(HAVE_SHM,,[have <sys/shm.h> and <sys/ipc.h> and shared memory works])
        AC_CHECK_HEADERS(sys/sysmacros.h)
        ;;
  *) ;;
esac
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SIGINTERRUPT],
[AC_REQUIRE([CL_SIGACTION])dnl
AC_CHECK_FUNCS(siginterrupt)dnl
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SIGNAL_REINSTALL],
[AC_BEFORE([$0], [CL_SIGNAL_UNBLOCK])dnl
AC_BEFORE([$0], [CL_SIGNAL_BLOCK_OTHERS])dnl
AC_CACHE_CHECK(whether signal handlers need to be reinstalled, cl_cv_func_signal_reinstall, [
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <signal.h>
#ifdef __CYGWIN32__
/* On Cygwin32 version 18, this test would hang (SIGALRM not being signalled).
 * Let it fail instead. */
#error "better fail than hang"
#endif
volatile int gotsig=0;
void sigalrm_handler() { gotsig=1; }
int got_sig () { return gotsig; }
typedef void (*signal_handler_t) (int);
int main() { /* returns 0 if they need not to be reinstalled */
  signal(SIGALRM,(signal_handler_t)sigalrm_handler); alarm(1); while (!got_sig());
  exit(!( (signal_handler_t)signal(SIGALRM,(signal_handler_t)sigalrm_handler)
          == (signal_handler_t)sigalrm_handler
      ) );
}], cl_cv_func_signal_reinstall=no, cl_cv_func_signal_reinstall=yes,
dnl When cross-compiling, don't assume anything.
cl_cv_func_signal_reinstall="guessing yes")
])
case "$cl_cv_func_signal_reinstall" in
  *yes) AC_DEFINE(SIGNAL_NEED_REINSTALL,,[signal handlers need to be reinstalled when they are activated]) ;;
  *no) ;;
esac
])

AC_DEFUN([CL_SIGNAL_UNBLOCK],
[AC_REQUIRE([CL_SIGNAL_REINSTALL])dnl
case "$signalblocks" in
  *POSIX* | *BSD*)
AC_CACHE_CHECK(whether signals are blocked when signal handlers are entered, cl_cv_func_signal_blocked, [
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <signal.h>
#ifdef __CYGWIN32__
/* On Cygwin32 version 18, this test would hang (SIGALRM not being signalled).
 * Let it fail instead. */
#error "better fail than hang"
#endif
volatile int gotsig=0;
volatile int wasblocked=0;
typedef void (*signal_handler_t) (int);
void sigalrm_handler()
{ gotsig=1;
#ifdef SIGNAL_NEED_REINSTALL
  signal(SIGALRM,(signal_handler_t)sigalrm_handler);
#endif
  { sigset_t blocked;
    sigprocmask(SIG_BLOCK, (sigset_t *) 0, &blocked);
    wasblocked = sigismember(&blocked,SIGALRM) ? 1 : 0;
  }
}
int got_sig () { return gotsig; }
int main() { /* returns 0 if they need not to be unblocked */
  signal(SIGALRM,(signal_handler_t)sigalrm_handler); alarm(1); while (!got_sig());
  exit(wasblocked);
}], cl_cv_func_signal_blocked=no, cl_cv_func_signal_blocked=yes,
dnl When cross-compiling, assume the worst case.
cl_cv_func_signal_blocked="guessing yes")
])
case "$cl_cv_func_signal_blocked" in
  *yes) AC_DEFINE(SIGNAL_NEED_UNBLOCK,,[SIGNALBLOCK_BSD is defined above and signals need to be unblocked when signal handlers are left]) ;;
  *no) ;;
esac
  ;;
  *) ;;
esac
])

AC_DEFUN([CL_SIGNAL_BLOCK_OTHERS],
[AC_REQUIRE([CL_SIGNAL_REINSTALL])dnl
case "$signalblocks" in
  *POSIX* | *BSD*)
AC_CACHE_CHECK(whether other signals are blocked when signal handlers are entered, cl_cv_func_signal_blocked_others, [
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <signal.h>
#ifdef __CYGWIN32__
/* On Cygwin32 version 18, this test would hang (SIGALRM not being signalled).
 * Let it fail instead. */
#error "better fail than hang"
#endif
volatile int gotsig=0;
volatile int somewereblocked=0;
typedef void (*signal_handler_t) (int);
void sigalrm_handler()
{ gotsig=1;
#ifdef SIGNAL_NEED_REINSTALL
  signal(SIGALRM,(signal_handler_t)sigalrm_handler);
#endif
  { sigset_t blocked;
    int i;
    sigprocmask(SIG_BLOCK, (sigset_t *) 0, &blocked);
    for (i=1; i<32; i++)
      if (i!=SIGALRM && sigismember(&blocked,i))
        somewereblocked = 1;
  }
}
int got_sig () { return gotsig; }
int main() { /* returns 0 if they need not to be unblocked */
  signal(SIGALRM,(signal_handler_t)sigalrm_handler); alarm(1); while (!got_sig());
  exit(somewereblocked);
}], cl_cv_func_signal_blocked_others=no, cl_cv_func_signal_blocked_others=yes,
dnl When cross-compiling, assume the worst case.
cl_cv_func_signal_blocked_others="guessing yes")
])
case "$cl_cv_func_signal_blocked_others" in
  *yes) AC_DEFINE(SIGNAL_NEED_UNBLOCK_OTHERS,,[SIGNALBLOCK_BSD is defined above and other signals need to be unblocked when signal handlers are left]) ;;
  *no) ;;
esac
  ;;
  *) ;;
esac
])

AC_DEFUN([CL_SIGACTION],
[AC_BEFORE([$0], [CL_SIGACTION_REINSTALL])
AC_BEFORE([$0], [CL_SIGINTERRUPT])
AC_CHECK_FUNCS(sigaction)])

AC_DEFUN([CL_SIGACTION_REINSTALL],
[AC_REQUIRE([CL_SIGACTION])dnl
AC_BEFORE([$0], [CL_SIGACTION_UNBLOCK])dnl
if test -n "$have_sigaction"; then
AC_CACHE_CHECK(whether sigaction handlers need to be reinstalled, cl_cv_func_sigaction_reinstall, [
AC_TRY_RUN([
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <signal.h>
#ifdef __CYGWIN32__
/* On Cygwin32 version 18, this test would hang (SIGALRM not being signalled).
 * Let it fail instead. */
#error "better fail than hang"
#endif
typedef void (*signal_handler_t) (int);
signal_handler_t mysignal (int sig, signal_handler_t handler)
{ struct sigaction old_sa;
  struct sigaction new_sa;
  memset(&new_sa,0,sizeof(new_sa));
  new_sa.sa_handler = handler;
  if (sigaction(sig,&new_sa,&old_sa)<0) { return (signal_handler_t)SIG_IGN; }
  return (signal_handler_t)old_sa.sa_handler;
}
volatile int gotsig=0;
void sigalrm_handler() { gotsig=1; }
int got_sig () { return gotsig; }
int main() { /* returns 0 if they need not to be reinstalled */
  mysignal(SIGALRM,(signal_handler_t)sigalrm_handler); alarm(1); while (!got_sig());
  exit(!( mysignal(SIGALRM,(signal_handler_t)sigalrm_handler)
          == (signal_handler_t)sigalrm_handler
      ) );
}], cl_cv_func_sigaction_reinstall=no, cl_cv_func_sigaction_reinstall=yes,
dnl When cross-compiling, don't assume anything.
cl_cv_func_sigaction_reinstall="guessing yes")
])
case "$cl_cv_func_sigaction_reinstall" in
  *yes) AC_DEFINE(SIGACTION_NEED_REINSTALL,,[signal handlers installed via sigaction() need to be reinstalled when they are activated]) ;;
  *no) ;;
esac
fi
])

AC_DEFUN([CL_SIGACTION_UNBLOCK],
[AC_REQUIRE([CL_SIGACTION])dnl
AC_REQUIRE([CL_SIGACTION_REINSTALL])dnl
if test -n "$have_sigaction"; then
case "$signalblocks" in
  *POSIX* | *BSD*)
AC_CACHE_CHECK(whether signals are blocked when sigaction handlers are entered, cl_cv_func_sigaction_blocked, [
AC_TRY_RUN([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <signal.h>
#ifdef __CYGWIN32__
/* On Cygwin32 version 18, this test would hang (SIGALRM not being signalled).
 * Let it fail instead. */
#error "better fail than hang"
#endif
typedef void (*signal_handler_t) (int);
signal_handler_t mysignal (int sig, signal_handler_t handler)
{ struct sigaction old_sa;
  struct sigaction new_sa;
  memset(&new_sa,0,sizeof(new_sa));
  new_sa.sa_handler = handler;
  if (sigaction(sig,&new_sa,&old_sa)<0) { return (signal_handler_t)SIG_IGN; }
  return (signal_handler_t)old_sa.sa_handler;
}
volatile int gotsig=0;
volatile int wasblocked=0;
void sigalrm_handler()
{ gotsig=1;
#ifdef SIGNAL_NEED_REINSTALL
  mysignal(SIGALRM,(signal_handler_t)sigalrm_handler);
#endif
  { sigset_t blocked;
    sigprocmask(SIG_BLOCK, (sigset_t *) 0, &blocked);
    wasblocked = sigismember(&blocked,SIGALRM) ? 1 : 0;
  }
}
int got_sig () { return gotsig; }
int main() { /* returns 0 if they need not to be unblocked */
  mysignal(SIGALRM,(signal_handler_t)sigalrm_handler); alarm(1); while (!got_sig());
  exit(wasblocked);
}], cl_cv_func_sigaction_blocked=no, cl_cv_func_sigaction_blocked=yes,
dnl When cross-compiling, assume the worst case.
cl_cv_func_sigaction_blocked="guessing yes")
])
case "$cl_cv_func_sigaction_blocked" in
  *yes) AC_DEFINE(SIGACTION_NEED_UNBLOCK,,[signals need to be unblocked when signal handlers installed via sigaction() are left]) ;;
  *no) ;;
esac
  ;;
  *) ;;
esac
fi
])

dnl Copyright (C) 1993-2002 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels.

AC_PREREQ(2.13)

AC_DEFUN([CL_SOCKET],
[dnl Check whether -lsocket and maybe -lnsl is needed for the functions
dnl gethostbyname(), connect(), socket(), inet_addr(), setsockopt().
dnl On SVR4 and Solaris 2:
dnl   gethostbyname() and gethostent() in libnsl,
dnl   setsockopt() in libsocket,
dnl   libsocket requires libnsl.
dnl On SINIX-N 5.43:
dnl   gethostent() in libnsl,
dnl   gethostbyname() and setsockopt() in libsocket,
dnl   libsocket requires libnsl.
dnl Hence checking for gethostent() gives a better hint whether libnsl is
dnl needed than gethostbyname(). Once we found that, we check for setsockopt().
AC_CACHE_CHECK(whether gethostent requires -lnsl, cl_cv_lib_nsl, [
cl_cv_lib_nsl=no
AC_TRY_LINK(AC_LANG_EXTERN[char gethostent();], [gethostent();],
have_gethostent=1)
if test -z "$have_gethostent"; then
cl_save_LIBS="$LIBS"
LIBS="$LIBS -lnsl"
AC_TRY_LINK(AC_LANG_EXTERN[char gethostent();], [gethostent();],
cl_cv_lib_nsl=yes)
LIBS="$cl_save_LIBS"
fi
])
if test $cl_cv_lib_nsl = yes; then
  LIBS="$LIBS -lnsl"
fi
AC_CACHE_CHECK(whether setsockopt requires -lsocket, cl_cv_lib_socket, [
cl_cv_lib_socket=no
AC_TRY_LINK(AC_LANG_EXTERN[char setsockopt();], [setsockopt();],
have_setsockopt=1)
if test -z "$have_setsockopt"; then
cl_save_LIBS="$LIBS"
LIBS="$LIBS -lsocket"
AC_TRY_LINK(AC_LANG_EXTERN[char setsockopt();], [setsockopt();],
cl_cv_lib_socket=yes)
LIBS="$cl_save_LIBS"
fi
])
if test $cl_cv_lib_socket = yes; then
  LIBS="$LIBS -lsocket"
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_SOCKLEN_T],
[AC_CACHE_CHECK(for socklen_t in sys/socket.h, cl_cv_type_socklen_t, [
AC_EGREP_HEADER(socklen_t, sys/socket.h,
cl_cv_type_socklen_t=yes, cl_cv_type_socklen_t=no)
])
if test $cl_cv_type_socklen_t = yes; then
  AC_DEFINE(CLISP_SOCKLEN_T, socklen_t,
[socklen_t (if defined in <sys/socket.h>) or int otherwise])
else
  AC_DEFINE(CLISP_SOCKLEN_T, int)
fi
]
)

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_STAT],
[dnl Cannot use AC_CHECK_FUNCS(lstat) because Linux defines lstat() as an
dnl inline function in <sys/stat.h>.
CL_LINK_CHECK([lstat],cl_cv_func_lstat,[
#include <sys/types.h>
#include <sys/stat.h>
], [return lstat("",(struct stat *)0);],
AC_DEFINE(HAVE_LSTAT,,[have lstat()?]))dnl
AC_CHECK_HEADERS(sys/stat.h)
if test "$ac_cv_header_sys_stat_h" = "yes"; then
 AC_CHECK_MEMBERS([struct stat.st_rdev, struct stat.st_blksize, struct stat.st_blocks],,,[#include <sys/stat.h>])
fi
AC_CHECK_SIZEOF(ino_t)
AC_CHECK_SIZEOF(dev_t)
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2004, 2007-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_TCPCONN],
[CL_COMPILE_CHECK([IPv4 sockets], cl_cv_socket_ipv4,
[#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>],
[int x = AF_INET; struct in_addr y; struct sockaddr_in z;],
AC_DEFINE(HAVE_IPV4,,[<sys/socket.h> defines AF_INET]))
CL_COMPILE_CHECK([IPv6 sockets], cl_cv_socket_ipv6,
[#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>],
[int x = AF_INET6; struct in6_addr y; struct sockaddr_in6 z;],
AC_DEFINE(HAVE_IPV6,,[<sys/socket.h> defines AF_INET6]))
if test $cl_cv_socket_ipv6 = no; then
CL_COMPILE_CHECK([IPv6 sockets in linux/in6.h], cl_cv_socket_ipv6_linux,
[#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/in6.h>],
[int x = AF_INET6; struct in6_addr y; struct sockaddr_in6 z;],
AC_DEFINE(IPV6_NEED_LINUX_IN6_H,,[need <linux/in6.h> for the in6_addr and sockaddr_in6 types])
AC_DEFINE(HAVE_IPV6))
fi
AC_CHECK_FUNCS(inet_pton inet_ntop inet_addr setsockopt getsockopt)
AC_CHECK_HEADERS(netinet/in.h arpa/inet.h)dnl
if test $ac_cv_func_inet_addr = yes; then
CL_PROTO([inet_addr], [
for x in CONST_VARIANTS; do
for y in SIZE_VARIANTS; do
if test -z "$have_inet_addr"; then
CL_PROTO_TRY([
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
#include <netinet/in.h>
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef __BEOS__
#include <sys/socket.h>
#include <netdb.h>
#endif
], [$y inet_addr ($x char *);], [
cl_cv_proto_inet_addr_ret="$y"
cl_cv_proto_inet_addr_arg1="$x"
have_inet_addr=1])
fi
done
done
if test -z "$have_inet_addr"; then
CL_PROTO_MISSING(inet_addr)
fi
], [extern $cl_cv_proto_inet_addr_ret inet_addr ($cl_cv_proto_inet_addr_arg1 char*);])
AC_DEFINE_UNQUOTED(RET_INET_ADDR_TYPE,$cl_cv_proto_inet_addr_ret,[return type of inet_addr()])
AC_DEFINE_UNQUOTED(INET_ADDR_CONST,$cl_cv_proto_inet_addr_arg1,[declaration of inet_addr() needs const])
if test "$cl_cv_proto_inet_addr_ret" = "struct in_addr"; then
AC_DEFINE(INET_ADDR_SUFFIX,[.s_addr],[Define as .s_addr if the return type of inet_addr() is a struct type, as empty if it is a scalar type])
else
AC_DEFINE(INET_ADDR_SUFFIX,[])
fi
fi
AC_CHECK_HEADERS(netinet/tcp.h,,,
dnl AIX 4 requires <netinet/in.h> to be included before <netinet/tcp.h>.
[#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
])
if test $ac_cv_func_setsockopt = yes; then
CL_PROTO([setsockopt], [
for z in SIZE_VARIANTS; do
for y in 'char*' 'void*'; do
for x in CONST_VARIANTS; do
if test -z "$have_setsockopt_decl"; then
CL_PROTO_TRY([
#include <sys/types.h>
#include <sys/socket.h>
], [int setsockopt (int, int, int, $x $y, $z);], [
cl_cv_proto_setsockopt_const="$x"
cl_cv_proto_setsockopt_arg_t="$y"
cl_cv_proto_setsockopt_optlen_t="$z"
have_setsockopt_decl=1])
fi
done
done
done
if test -z "$have_setsockopt_decl"; then
CL_PROTO_MISSING(setsockopt)
fi
], [extern int setsockopt (int, int, int, $cl_cv_proto_setsockopt_const $cl_cv_proto_setsockopt_arg_t, $cl_cv_proto_setsockopt_optlen_t);])
AC_DEFINE_UNQUOTED(SETSOCKOPT_CONST,$cl_cv_proto_setsockopt_const,[declaration of setsockopt() needs const])
AC_DEFINE_UNQUOTED(SETSOCKOPT_ARG_T,$cl_cv_proto_setsockopt_arg_t,[type of `optval' in setsockopt() declaration])
AC_DEFINE_UNQUOTED(SETSOCKOPT_OPTLEN_T,$cl_cv_proto_setsockopt_optlen_t,[type of `optlen' in setsockopt() declaration])
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2002, 2005, 2010 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold

AC_PREREQ(2.13)

AC_DEFUN([CL_TERMCAP],[
dnl Some systems have tgetent(), tgetnum(), tgetstr(), tgetflag(), tputs(),
dnl tgoto() in libc, some have it in libtermcap, some have it in libncurses.
dnl When both libtermcap and libncurses exist, we prefer the latter,
dnl because libtermcap is being phased out.
dnl libcurses is useless: all platforms which have libcurses also have
dnl libtermcap, also they were all different on the various Unix systems,
dnl and often buggy
termcap_prefix=""
AC_ARG_WITH([libtermcap-prefix],
[  --with-libtermcap-prefix[=DIR]  search for ncurses and termcap in DIR],
[case "$withval" in
  /*) termcap_prefix=$withval; ;;
esac])
if test x$termcap_prefix != x; then
  LDFLAGS_save=$LDFLAGS
  LDFLAGS=$LDFLAGS" -L$termcap_prefix/lib"
fi
LIBTERMCAP="broken"
INCTERMCAP=""
AC_SEARCH_LIBS(tgetent, ncurses termcap, LIBTERMCAP="")
if test x$termcap_prefix != x; then
  LDFLAGS=$LDFLAGS_save
  if test x$LIBTERMCAP != xbroken; then
    INCTERMCAP=-I$termcap_prefix/include
    LIBTERMCAP=-L$termcap_prefix/lib
  fi
fi
AC_SUBST(LIBTERMCAP)
AC_SUBST(INCTERMCAP)
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_TERM],
[AC_BEFORE([$0], [CL_IOCTL])
AC_CHECK_HEADERS(termios.h termio.h sys/termio.h sgtty.h)dnl
if test $ac_cv_header_termios_h = yes; then
dnl HAVE_TERMIOS_H defined
dnl A/UX has <termios.h> but is lacking tcgetattr etc.
CL_LINK_CHECK([tcgetattr], cl_cv_func_tcgetattr,
[#include <termios.h>], [struct termios t; tcgetattr(0,&t);],
AC_DEFINE(HAVE_TCGETATTR,,[have tcgetattr(), either as a function or as a macro defined by <termios.h>]))dnl
CL_LINK_CHECK([TCSAFLUSH in termios.h], cl_cv_decl_TCSAFLUSH,
[#include <termios.h>], [int x = TCSAFLUSH;],
AC_DEFINE(HAVE_TCSAFLUSH,,[<termios.h> defines TCSAFLUSH]))dnl
dnl Linux libc5 defines struct winsize in <termios.h>, <termio.h>, <sys/ioctl.h>.
dnl Linux libc6 defines struct winsize in <termio.h>, <sys/ioctl.h>.
dnl Since we don't want to include both <termios.h> and <termio.h> (they may
dnl conflict), prefer <sys/ioctl.h> to <termio.h>.
dnl SCO defines struct winsize in <sys/ptem.h>, which itself needs <sys/stream.h>.
CL_COMPILE_CHECK([struct winsize in termios.h], cl_cv_struct_winsize,
[#include <termios.h>], [struct winsize w;], )dnl
if test $cl_cv_struct_winsize = no; then
CL_COMPILE_CHECK([struct winsize in sys/ioctl.h], cl_cv_struct_winsize_ioctl,
[#include <sys/types.h>
#include <sys/ioctl.h>],
[struct winsize w;], AC_DEFINE(WINSIZE_NEED_SYS_IOCTL_H,,[have <termios.h> but need <sys/ioctl.h> for `struct winsize']))dnl
if test $cl_cv_struct_winsize_ioctl = no; then
CL_COMPILE_CHECK([struct winsize in sys/ptem.h], cl_cv_struct_winsize_ptem,
[#include <sys/types.h>
#include <sys/stream.h>
#include <sys/ptem.h>],
[struct winsize w;], AC_DEFINE(WINSIZE_NEED_SYS_PTEM_H,,[have <termios.h> but need <sys/ptem.h> for `struct winsize']))dnl
fi
fi
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 2005-2006 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Sam Steingold.

AC_PREREQ(2.13)

AC_DEFUN([CL_TEST_NT],[dnl check that test(1) can serve as make(1)
AC_CACHE_CHECK(whether test -nt works, cl_cv_test_nt, [
rm -f conftestfile1 conftestfile2
touch conftestfile1
# see makemake.in, rule "anymodule":
if (test -f conftestfile1 -a conftestfile1 -nt conftestfile2) 1>&5 2>&5
then cl_cv_test_nt=yes
else cl_cv_test_nt=no
fi
rm -f conftestfile1
])
TEST_NT=${cl_cv_test_nt-no}
AC_SUBST(TEST_NT)dnl
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_UNIXCONN],
[AC_CHECK_HEADERS(sys/un.h)dnl
if test $ac_cv_header_sys_un_h = yes; then
CL_COMPILE_CHECK([sun_len in struct sockaddr_un], cl_cv_struct_sockaddr_sun_len,
[#include <sys/types.h> /* NetBSD 1.0 needs this */
#include <sys/un.h>],
[struct sockaddr_un unaddr; unaddr.sun_len;], AC_DEFINE(HAVE_SOCKADDR_UN_LEN,,[`struct sockaddr_un' from <sys/un.h> has a `sun_len' field]))dnl
fi
])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_VADVISE],
[CL_LINK_CHECK([vadvise], cl_cv_func_vadvise,
[#include <sys/vadvise.h>], [vadvise(0);],
AC_DEFINE(HAVE_VADVISE,,[have the vadvise() system call])dnl
)])

dnl -*- Autoconf -*-
dnl Copyright (C) 1993-2008 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible, Marcus Daniels, Sam Steingold.

AC_PREREQ(2.57)

AC_DEFUN([CL_WAITPID],
[CL_PROTO([waitpid], [
CL_PROTO_TRY([
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/types.h>
], [pid_t waitpid (pid_t pid, int* statusp, int options);],
cl_cv_proto_waitpid_arg1="pid_t", cl_cv_proto_waitpid_arg1="int")
], [extern pid_t waitpid ($cl_cv_proto_waitpid_arg1, int*, int);])
AC_DEFINE_UNQUOTED(PID_T,$cl_cv_proto_waitpid_arg1,[type of `pid' in waitpid() declaration])
])

