CFRONTC="wine $PWD/cfront.exe"
EXEWRAPPER="wine"
EXEEXT=".exe"
CCOMP="i686-w64-mingw32-gcc -D_MSC_VER=1"
CXX='i686-w64-mingw32-g++ -fno-rtti -fno-exceptions'
CFRONTC="$CFRONTC" \
    EXEWRAPPER="$EXEWRAPPER"  \
    EXEEXT="$EXEEXT" \
    CCOMP="$CCOMP" \
    CXX="$CXX" \
    make CCOMP="$CCOMP" CXX="$CXX" $*

