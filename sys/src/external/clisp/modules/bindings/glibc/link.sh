${MAKE-make} clisp-module \
  CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
  CLISP_LINKKIT="$absolute_linkkitdir" CLISP="${CLISP}"
NEW_FILES="linux.o"
NEW_LIBS="${NEW_FILES} -lm"
NEW_MODULES="linux"
TO_LOAD='linux wrap'
