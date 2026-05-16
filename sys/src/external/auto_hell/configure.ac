AC_INIT([hell], [1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_PROG_CC

#check for yacc
AC_CHECK_PROGS([YACC], [byacc yacc], [no])
if test "x$YACC" = "xno"; then
    AC_MSG_ERROR([yacc or byacc is required, no bison allowed, fuck gnu])
fi

#check for lex
AC_CHECK_PROGS([LEX], [reflex flex lex], [no])
if test "x$LEX" = "xno"; then
    AC_MSG_ERROR([reflex or flex is required])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
