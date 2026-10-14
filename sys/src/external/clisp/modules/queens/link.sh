${MAKE-make} clisp-module \
  CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
  CLISP_LINKKIT="$absolute_linkkitdir" CLISP="${CLISP}"
NEW_FILES='callqueens.o queens.o'
NEW_LIBS="${NEW_FILES}"
NEW_MODULES='queens'
TO_LOAD=''
