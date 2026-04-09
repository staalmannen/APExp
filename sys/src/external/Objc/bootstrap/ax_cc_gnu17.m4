# ===========================================================================
#       https://www.gnu.org/software/autoconf-archive
# ===========================================================================
#
# SYNOPSIS
#
#   AX_CC_GNU17
#
# DESCRIPTION
#
#   Determine whether the C compiler supports -std=gnu17
#
#   The $ac_cv_gnu17 variable will be either yes or no
#
# LICENSE
#
#   Copyright (c) 2025 David Stes
#
#   This program is free software: you can redistribute it and/or modify it
#   under the terms of the GNU General Public License as published by the
#   Free Software Foundation, either version 3 of the License, or (at your
#   option) any later version.
#
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
#   Public License for more details.
#
#   You should have received a copy of the GNU General Public License along
#   with this program. If not, see <https://www.gnu.org/licenses/>.

#serial 1

AC_ARG_WITH(gnu17,
  [  --with-gnu17            use -std=gnu17 for C compiler and C preprocessor],
  [ac_cv_gnu17=$withval]
)

AC_DEFUN([AX_CC_GNU17],
[
AC_MSG_CHECKING(whether compiler supports -std=gnu17)
AC_CACHE_VAL(ac_cv_gnu17,[
t1="ac$$.c"
o1="ac$$.o"
ac_clean_files="$t1 $o1"
cat >$t1 <<EOF
#ifdef __cplusplus
typedef int (*IMP) (...);        /* pointer in C++/C23 */
#else
typedef int (*IMP) ();           /* pointer in K&R C/C17 */
#endif
EOF
# since gcc 15 gcc defaults to C++ style definitions with ... (ellipsis)
echo "$CC -std=gnu17 -c $t1" >&5
if $CC -std=gnu17 -c $t1 2>&5 1>&5
  then
    echo " (yes)" >&5
    ac_cv_gnu17=yes;
  else
    echo " (no)" >&5
    ac_cv_gnu17=no;
fi
rm -rf $ac_clean_files
],ac_cv_gnu17=yes,ac_cv_gnu17=no)
AC_MSG_RESULT($ac_cv_gnu17)
])


