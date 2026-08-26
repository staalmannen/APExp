/*
 * config.h for GNU tar.
 *
 * The platform answers -- HAVE_* probes, type sizes, the APExp
 * additions -- are shared by every package that links libgnu.a and
 * live in config-common.h, found through -I$GNUSRC. Only package
 * identity and package-specific settings belong here.
 *
 * tar's own config.h in its source tree is deliberately unused, as for
 * the sibling packages: it predates the 2026 gnulib this links
 * against, so its platform answers no longer describe the objects.
 */

#include <config-common.h>

#define PACKAGE              "tar"
#define PACKAGE_NAME         "GNU tar"
#define PACKAGE_STRING       "GNU tar 1.35"
#define PACKAGE_TARNAME      "tar"
#define PACKAGE_VERSION      "1.35"
#define VERSION              "1.35"
#define PACKAGE_BUGREPORT    "bug-tar@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/tar/"

/* tar's own defaults, from its configure. No counterpart in
   config-common.h, which began as coreutils'. */
#define DEFAULT_ARCHIVE         "-"
#define DEFAULT_ARCHIVE_FORMAT  GNU_FORMAT
#define DEFAULT_BLOCKING        20
#define DEFAULT_QUOTING_STYLE   escape_quoting_style

/*
 * The compressors tar can hand an archive to. buffer.c and suffix.c
 * name all eight unconditionally, in static initialisers, so these are
 * not optional: config-common.h began as coreutils' and defines none of
 * them, so without this block tar does not compile.
 *
 * Five point at programs APExp builds, under the names their own
 * mkfiles install:
 *
 *   bzip2   sys/src/ape/cmd/bzip2
 *   lzip    sys/src/ape/cmd/clzip     (clzip installs as "lzip")
 *   xz      sys/src/ape/cmd/xz
 *   lzma    sys/src/ape/cmd/xz        (the same package installs both)
 *   zstd    sys/src/ape/cmd/zstd
 *
 * gzip is minigzip, from sys/src/ape/cmd/minigzip. tar runs the program
 * as a filter and passes -d to decompress; minigzip takes -d and, given
 * no file arguments, reads stdin and writes stdout, which is the whole
 * of what tar needs. It is not Plan 9's own /bin/gzip: that one has no
 * -d, so tar could compress with it but never extract.
 *
 * compress and lzop have no counterpart here. They are left at their
 * conventional names rather than removed -- tar looks a program up only
 * when a .Z or .lzo archive is actually handled, so an absent one costs
 * nothing until then, and naming it keeps the failure legible.
 */
#define BZIP2_PROGRAM    "bzip2"
#define GZIP_PROGRAM     "minigzip"
#define LZIP_PROGRAM     "lzip"
#define LZMA_PROGRAM     "lzma"
#define XZ_PROGRAM       "xz"
#define ZSTD_PROGRAM     "zstd"
#define COMPRESS_PROGRAM "compress"
#define LZOP_PROGRAM     "lzop"

/*
 * __getopt_argv_const, for the gnulib getopt sources this package
 * builds locally (see the mkfile).
 *
 *   getopt1.c:28 syntax error, last name: __getopt_argv_const
 *
 * getopt1.c declares
 *
 *   getopt_long (int argc, char *__getopt_argv_const *argv, ...)
 *
 * and upstream that macro reaches it through the generated getopt.h,
 * by way of getopt-pfx-ext.h. That wrapper is one of the headers
 * import.sh prunes for shadowing APE's <getopt.h>, so the name arrives
 * undefined and the declaration will not parse.
 *
 * const, not empty. getopt-pfx-ext.h picks empty only under
 * __GETOPT_PREFIX; otherwise it uses const, giving "char *const *argv",
 * which is exactly how APE's <getopt.h> declares getopt_long. The two
 * have to agree, since APE supplies the declaration and gnulib the
 * definition.
 *
 * Note config-common.h has "#define __GETOPT_PREFIX rpl_", under which
 * getopt-pfx-ext.h would pick empty instead. It does not apply: that
 * prefix only takes effect through the same pruned headers, so nothing
 * renames anything here and the getopt sources define the plain names.
 * The value has to match APE's declaration, not gnulib's intent.
 *
 * Here rather than in config-common.h because tar is the only package
 * that compiles gnulib's getopt. If another one starts, this is worth
 * promoting.
 */
#ifndef __getopt_argv_const
#define __getopt_argv_const const
#endif

/*
 * hash_delete was a deprecated synonym for hash_remove. tar 1.35 was
 * written against a gnulib that still had it; the 2026 hash.c in the
 * shared tree has only hash_remove:
 *
 *   names.c: undefined: hash_delete
 *
 * The two took the same arguments and returned the same thing, so a
 * rename is the whole of it. Defined here rather than patched into
 * tar's sources, so the external tree stays as upstream shipped it.
 */
#define hash_delete hash_remove
