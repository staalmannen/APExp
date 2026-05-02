# host system flavor
OS                                      = linux
OS_SEMANTICS                            = elf-posix-linux-ldso

OS_DSO_EXRULES                          = default
OS_DSO_LINKAGE                          = default

OS_APP_PREFIX                           =
OS_APP_SUFFIX                           =

OS_LIB_PREFIX                           = lib
OS_LIB_SUFFIX                           = .so

OS_IMPLIB_EXT                           = .invalid
OS_LIBDEF_EXT                           = .invalid

OS_ARCHIVE_EXT                          = .a
OS_SONAME                               = symlink

OS_LIB_PREFIXED_SUFFIX                  = $(OS_LIB_SUFFIX)
OS_LIB_SUFFIXED_SUFFIX                  =

# host characteristics
CC_HOST                                 = x86_64-chimera-linux-musl
CC_BITS                                 = 64

CC_ARFMT                                = common
CC_SOFMT                                = ELF
CC_BINFMT                               = ELF
CC_UNDERSCORE                           =
CC_ENVIRONMENT                          = hosted

CC_ARCH_BFD                             =
CC_ARCH_LLVM                            =

# incompatible tool variants
AS_ASM                                  = false
AS_LL                                   = llvm-as
AS_MC                                   = llvm-mc

LD_BFD                                  = false
LD_GOLD                                 = false
LD_LLD                                  = lld

OBJDUMP_BFD                             = false
OBJDUMP_LLVM                            = llvm-objdump

READELF_BFD                             = false
READELF_LLVM                            = llvm-readelf

# host primary tools
CC                                      = cc
CPP                                     = cc -E
CXX                                     = c++

AR                                      = ar
NM                                      = nm
OBJDUMP                                 = objdump
RANLIB                                  = ranlib
SIZE                                    = size
STRIP                                   = strip
STRINGS                                 = strings

ADDR2LINE                               = addr2line
COV                                     = llvm-cov
CXXFILT                                 =
OBJCOPY                                 = objcopy

ELFEDIT                                 = false
READELF                                 = readelf
READOBJ                                 = llvm-readobj

PERK                                    = false
MDSO                                    = false
DLLTOOL                                 = dlltool

WINDMC                                  = false
WINDRC                                  = windres

PKGCONF                                 = pkgconf

# host secondary tools
# note: the direct use of $(___ccenv_makevar_prefix___LD) is highly discouraged
AS                                      = $(CC) -c -x assembler
LD                                      = $(CC) -nostdlib -nostartfiles

# host visibility attributes
CFLAGS_ATTR_VISIBILITY_DEFAULT          = -D_ATTR_VISIBILITY_DEFAULT=__attribute__\(\(__visibility__\(\"default\"\)\)\)
CFLAGS_ATTR_VISIBILITY_HIDDEN           = -D_ATTR_VISIBILITY_HIDDEN=__attribute__\(\(__visibility__\(\"hidden\"\)\)\)
CFLAGS_ATTR_VISIBILITY_INTERNAL         = -D_ATTR_VISIBILITY_INTERNAL=__attribute__\(\(__visibility__\(\"internal\"\)\)\)
CFLAGS_ATTR_VISIBILITY_PROTECTED        = -D_ATTR_VISIBILITY_PROTECTED=__attribute__\(\(__visibility__\(\"protected\"\)\)\)

# #ccenv_cfgtype@ compiler attributes
CFLAGS_ATTR_VISIBILITY                  = -D_ATTR_VISIBILITY\(v\)=__attribute__\(\(__visibility__\(v\)\)\)
CFLAGS_ATTR_NONNULL                     = -D_ATTR_NONNULL\(x\)=__attribute__\(\(__nonnull__\(x\)\)\)
CFLAGS_ATTR_FORMAT                      = -D_ATTR_FORMAT\(a,s,c\)=__attribute__\(\(__format__\(a,s,c\)\)\)
CFLAGS_ATTR_MALLOC                      = -D_ATTR_MALLOC=__attribute__\(\(__malloc__\)\)
CFLAGS_ATTR_NORETURN                    = -D_ATTR_NORETURN=__attribute__\(\(__noreturn__\)\)
CFLAGS_ATTR_DEPRECATED                  = -D_ATTR_DEPRECATED=__attribute__\(\(__deprecated__\)\)
CFLAGS_ATTR_UNUSED                      = -D_ATTR_UNUSED=__attribute__\(\(__unused__\)\)
CFLAGS_ATTR_ALWAYS_INLINE               = -D_ATTR_ALWAYS_INLINE=__attribute__\(\(__always_inline__\)\)

# host cflags
CFLAGS_OS                              += -DOS_LIB_SUFFIX=\".so\"
CFLAGS_OS                              +=
CFLAGS_PIC                             += -fPIC

# host cflags: supported compiler switches
_CFLAGS_O0                              = -O0
_CFLAGS_O1                              = -O1
_CFLAGS_O2                              = -O2
_CFLAGS_O3                              = -O3
_CFLAGS_Os                              = -Os
_CFLAGS_Wall                            = -Wall
_CFLAGS_Werror                          = -Werror
_CFLAGS_Wextra                          = -Wextra
_CFLAGS_Wpedantic                       = -Wpedantic
_CFLAGS_Wundef                          = -Wundef
_CFLAGS_dumpmachine                     = -dumpmachine
_CFLAGS_g                               = -g
_CFLAGS_g0                              = -g0
_CFLAGS_g1                              = -g1
_CFLAGS_g2                              = -g2
_CFLAGS_g3                              = -g3
_CFLAGS_print_file_name                 = -print-file-name
_CFLAGS_std_c11                         = -std=c11
_CFLAGS_std_c89                         = -std=c89
_CFLAGS_std_c99                         = -std=c99

# host ldflags: supported compiler switches
_LDFLAGS_Wl___no_undefined              = -Wl,--no-undefined
_LDFLAGS_Wl___print_map                 = -Wl,--print-map
_LDFLAGS_Wl___verbose                   = -Wl,--verbose
