/*
 * config.h for grep.
 *
 * The platform answers -- HAVE_* probes, type sizes, the APExp
 * additions -- are shared by every package that links libgnu.a and
 * live in config-common.h, found through -I$GNUSRC. Only package
 * identity belongs here: config-common.h began as coreutils'
 * config.h, and left to itself it makes every program report
 * PACKAGE "coreutils" and VERSION "9.11".
 *
 * The package's own config.h in its source tree is deliberately
 * unused. Those predate the 2026 gnulib this links against, so
 * their platform answers no longer describe the objects.
 */

#include <config-common.h>

#define PACKAGE              "grep"
#define PACKAGE_NAME         "GNU grep"
#define PACKAGE_STRING       "GNU grep 3.12"
#define PACKAGE_TARNAME      "grep"
#define PACKAGE_VERSION      "3.12"
#define VERSION              "3.12"
#define PACKAGE_BUGREPORT    "bug-grep@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/grep/"
