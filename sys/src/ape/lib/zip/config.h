#ifndef HAD_CONFIG_H
#define HAD_CONFIG_H

/*
 * config.h for APExp -- config.h.in answered by hand.
 *
 * Upstream generates this from config.h.in with CMake. Every
 * #cmakedefine in that template is answered below, checked one at a
 * time against sys/include/ape and sys/src/ape/lib/ap rather than
 * assumed, in the template's own order so the two can be compared.
 *
 * Unlike curl's, this one is short and nothing in it is a guess: the
 * whole template is 67 lines and libzip's requirements are modest.
 *
 * Private to the library and the three tools; it is not installed.
 * zipconf.h is the public one.
 */

#ifndef _HAD_ZIPCONF_H
#include "zipconf.h"
#endif

/* zip_fdopen(). Needs fdopen and dup, both of which APE has. */
#define ENABLE_FDOPEN

/*
 * The HAVE__* block of the template is all Microsoft CRT spellings --
 * _close, _dup, _fdopen, _fileno, _fseeki64, _fstat64, _setmode,
 * _snprintf, _snprintf_s, _snwprintf_s, _stat64, _strdup, _stricmp,
 * _strtoi64, _strtoui64, _unlink -- and none is defined here. Nor are
 * the _s bounds-checked forms: memcpy_s, snprintf_s, strerror_s,
 * strerrorlen_s, strncpy_s, localtime_s. Nor __PROGNAME, which is BSD's
 * variable rather than the getprogname() function APE actually has.
 */

#define HAVE_ARC4RANDOM
#define HAVE_FCHMOD
#define HAVE_FILENO
#define HAVE_FSEEKO
#define HAVE_FTELLO
#define HAVE_GETPROGNAME
#define HAVE_LOCALTIME_R
#define HAVE_MKSTEMP
#define HAVE_SNPRINTF
#define HAVE_STRCASECMP
#define HAVE_STRDUP
#define HAVE_STRTOLL
#define HAVE_STRTOULL
#define HAVE_STRUCT_TM_TM_ZONE

/*
 * Compression backends. All four libraries are built in this tree, so
 * all four are on: without them libzip reads and writes stored and
 * deflated entries only, and refuses bzip2, xz and zstd ones.
 *
 * Each turns on one more source file in the mkfile beside this --
 * zip_algorithm_bzip2.c, zip_algorithm_xz.c, zip_algorithm_zstd.c --
 * and the two must agree, as with libressl's compat sources.
 */
#define HAVE_LIBBZ2
#define HAVE_LIBLZMA
#define HAVE_LIBZSTD

/*
 * Crypto, for Winzip AES entries. libressl is beside us, so the
 * OpenSSL backend is the one to use; CommonCrypto is Apple's, GnuTLS
 * and mbedTLS are not in the tree, and HAVE_WINDOWS_CRYPTO is Windows.
 *
 * HAVE_CRYPTO is not a probe -- CMakeLists.txt:261 sets it whenever any
 * one backend was found. It gates zip_winzip_aes.c and the two
 * winzip_aes source/sink files, so it must be defined here for the same
 * reason: those three are in the mkfile's object list.
 */
#define HAVE_OPENSSL
#define HAVE_CRYPTO

/*
 * clonefile is Apple's and ficlonerange is Linux's; both are
 * copy-on-write reflink calls that Plan 9 has no equivalent for.
 * Without them zip_source_file_stdio copies bytes, which is what it
 * would do on most systems anyway.
 */

#define SIZEOF_OFF_T 8
#define SIZEOF_SIZE_T 8

#define HAVE_STDBOOL_H
#define HAVE_STRINGS_H
#define HAVE_UNISTD_H
#define HAVE_DIRENT_H
#define HAVE_FTS_H

/*
 * ndir.h, sys/dir.h and sys/ndir.h are the pre-POSIX spellings that
 * dirent.h replaced; APE has none of them and does not need them.
 *
 * WORDS_BIGENDIAN is left off: this is amd64. It is the one entry here
 * that would have to change for a big-endian port, and libzip reads it
 * for the byte order of the archive format, so getting it wrong would
 * corrupt every archive rather than fail to build.
 *
 * HAVE_SHARED is the inverse of ZIP_STATIC in zipconf.h; APExp builds
 * static libraries only.
 */

#define PACKAGE "libzip"
#define VERSION "1.11.4"

#endif /* HAD_CONFIG_H */
