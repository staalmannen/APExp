# matlab=/usr/local/matlab/extern/lib/
matlab=d:/MATLAB7/extern/lib/win32/microsoft/msvc60

${MAKE-make} clisp-module \
  CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
  CLISP_LINKKIT="$absolute_linkkitdir" CLISP="${CLISP}"
NEW_FILES="matlab.o"
NEW_LIBS="${NEW_FILES}";
for lib in eng mat mex mx; do
  NEW_LIBS=${NEW_LIBS}" ${matlab}/lib${lib}.lib"
done
NEW_MODULES="matlab"
TO_LOAD='matlab wrap'
CLFLAGS="${CLFLAGS}" # -L${matlab}
PATH="${PATH}:/cygdrive/d/MATLAB7/bin/win32/"
