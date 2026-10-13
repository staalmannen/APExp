${MAKE-make} clisp-module \
  CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
  CLISP_LINKKIT="$absolute_linkkitdir" CLISP="${CLISP}"
NEW_FILES="netica.o"
# netica 3.25 requires g++
NEW_LIBS="${NEW_FILES} -lnetica -L${NETICA_C_API}/lib -lstdc++ -lpthread"
NEW_MODULES="netica"
TO_LOAD='netica wrap'
