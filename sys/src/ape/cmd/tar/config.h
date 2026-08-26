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
