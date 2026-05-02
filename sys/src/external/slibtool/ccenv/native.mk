# native system flavor
NATIVE_OS                               = linux
NATIVE_OS_SEMANTICS                     = elf-posix-linux-ldso

NATIVE_OS_DSO_EXRULES                   = default
NATIVE_OS_DSO_LINKAGE                   = default

NATIVE_OS_APP_PREFIX                    =
NATIVE_OS_APP_SUFFIX                    =

NATIVE_OS_LIB_PREFIX                    = lib
NATIVE_OS_LIB_SUFFIX                    = .so

NATIVE_OS_IMPLIB_EXT                    = .invalid
NATIVE_OS_LIBDEF_EXT                    = .invalid

NATIVE_OS_ARCHIVE_EXT                   = .a
NATIVE_OS_SONAME                        = symlink

NATIVE_OS_LIB_PREFIXED_SUFFIX           = $(OS_LIB_SUFFIX)
NATIVE_OS_LIB_SUFFIXED_SUFFIX           =

# native characteristics
NATIVE_CC_HOST                          = x86_64-chimera-linux-musl
NATIVE_CC_BITS                          = 64

NATIVE_CC_ARFMT                         = common
NATIVE_CC_SOFMT                         = ELF
NATIVE_CC_BINFMT                        = ELF
NATIVE_CC_UNDERSCORE                    =
NATIVE_CC_ENVIRONMENT                   = hosted

NATIVE_CC_ARCH_BFD                      =
NATIVE_CC_ARCH_LLVM                     =

# incompatible tool variants
NATIVE_AS_ASM                           = false
NATIVE_AS_LL                            = llvm-as
NATIVE_AS_MC                            = llvm-mc

NATIVE_LD_BFD                           = false
NATIVE_LD_GOLD                          = false
NATIVE_LD_LLD                           = lld

NATIVE_OBJDUMP_BFD                      = false
NATIVE_OBJDUMP_LLVM                     = llvm-objdump

NATIVE_READELF_BFD                      = false
NATIVE_READELF_LLVM                     = llvm-readelf

# native primary tools
NATIVE_CC                               = cc
NATIVE_CPP                              = cc -E
NATIVE_CXX                              = c++

NATIVE_AR                               = ar
NATIVE_NM                               = nm
NATIVE_OBJDUMP                          = objdump
NATIVE_RANLIB                           = ranlib
NATIVE_SIZE                             = size
NATIVE_STRIP                            = strip
NATIVE_STRINGS                          = strings

NATIVE_ADDR2LINE                        = addr2line
NATIVE_COV                              = llvm-cov
NATIVE_CXXFILT                          =
NATIVE_OBJCOPY                          = objcopy

NATIVE_ELFEDIT                          = false
NATIVE_READELF                          = readelf
NATIVE_READOBJ                          = llvm-readobj

NATIVE_PERK                             = false
NATIVE_MDSO                             = false
NATIVE_DLLTOOL                          = dlltool

NATIVE_WINDMC                           = false
NATIVE_WINDRC                           = windres

NATIVE_PKGCONF                          = pkgconf

# native secondary tools
# note: the direct use of $(___ccenv_makevar_prefix___LD) is highly discouraged
NATIVE_AS                               = $(NATIVE_CC) -c -x assembler
NATIVE_LD                               = $(NATIVE_CC) -nostdlib -nostartfiles

# native visibility attributes
NATIVE_CFLAGS_ATTR_VISIBILITY_DEFAULT   = -D_ATTR_VISIBILITY_DEFAULT=__attribute__\(\(__visibility__\(\"default\"\)\)\)
NATIVE_CFLAGS_ATTR_VISIBILITY_HIDDEN    = -D_ATTR_VISIBILITY_HIDDEN=__attribute__\(\(__visibility__\(\"hidden\"\)\)\)
NATIVE_CFLAGS_ATTR_VISIBILITY_INTERNAL  = -D_ATTR_VISIBILITY_INTERNAL=__attribute__\(\(__visibility__\(\"internal\"\)\)\)
NATIVE_CFLAGS_ATTR_VISIBILITY_PROTECTED = -D_ATTR_VISIBILITY_PROTECTED=__attribute__\(\(__visibility__\(\"protected\"\)\)\)

# #ccenv_cfgtype@ compiler attributes
NATIVE_CFLAGS_ATTR_VISIBILITY           = -D_ATTR_VISIBILITY\(v\)=__attribute__\(\(__visibility__\(v\)\)\)
NATIVE_CFLAGS_ATTR_NONNULL              = -D_ATTR_NONNULL\(x\)=__attribute__\(\(__nonnull__\(x\)\)\)
NATIVE_CFLAGS_ATTR_FORMAT               = -D_ATTR_FORMAT\(a,s,c\)=__attribute__\(\(__format__\(a,s,c\)\)\)
NATIVE_CFLAGS_ATTR_MALLOC               = -D_ATTR_MALLOC=__attribute__\(\(__malloc__\)\)
NATIVE_CFLAGS_ATTR_NORETURN             = -D_ATTR_NORETURN=__attribute__\(\(__noreturn__\)\)
NATIVE_CFLAGS_ATTR_DEPRECATED           = -D_ATTR_DEPRECATED=__attribute__\(\(__deprecated__\)\)
NATIVE_CFLAGS_ATTR_UNUSED               = -D_ATTR_UNUSED=__attribute__\(\(__unused__\)\)
NATIVE_CFLAGS_ATTR_ALWAYS_INLINE        = -D_ATTR_ALWAYS_INLINE=__attribute__\(\(__always_inline__\)\)

# native cflags
NATIVE_CFLAGS_OS                       += -DOS_LIB_SUFFIX=\".so\"
NATIVE_CFLAGS_OS                       +=
NATIVE_CFLAGS_PIC                      += -fPIC

# native cflags: supported compiler switches
_NATIVE_CFLAGS_O0                       = -O0
_NATIVE_CFLAGS_O1                       = -O1
_NATIVE_CFLAGS_O2                       = -O2
_NATIVE_CFLAGS_O3                       = -O3
_NATIVE_CFLAGS_Os                       = -Os
_NATIVE_CFLAGS_Wall                     = -Wall
_NATIVE_CFLAGS_Werror                   = -Werror
_NATIVE_CFLAGS_Wextra                   = -Wextra
_NATIVE_CFLAGS_Wpedantic                = -Wpedantic
_NATIVE_CFLAGS_Wundef                   = -Wundef
_NATIVE_CFLAGS_dumpmachine              = -dumpmachine
_NATIVE_CFLAGS_g                        = -g
_NATIVE_CFLAGS_g0                       = -g0
_NATIVE_CFLAGS_g1                       = -g1
_NATIVE_CFLAGS_g2                       = -g2
_NATIVE_CFLAGS_g3                       = -g3
_NATIVE_CFLAGS_print_file_name          = -print-file-name
_NATIVE_CFLAGS_std_c11                  = -std=c11
_NATIVE_CFLAGS_std_c89                  = -std=c89
_NATIVE_CFLAGS_std_c99                  = -std=c99

# native ldflags: supported compiler switches
_NATIVE_LDFLAGS_Wl___no_undefined       = -Wl,--no-undefined
_NATIVE_LDFLAGS_Wl___print_map          = -Wl,--print-map
_NATIVE_LDFLAGS_Wl___verbose            = -Wl,--verbose
