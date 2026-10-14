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
