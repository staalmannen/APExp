/*
 * config.h for bison.
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

#define PACKAGE              "bison"
#define PACKAGE_NAME         "GNU Bison"
#define PACKAGE_STRING       "GNU Bison 3.8"
#define PACKAGE_TARNAME      "bison"
#define PACKAGE_VERSION      "3.8"
#define VERSION              "3.8"
#define PACKAGE_BUGREPORT    "bug-bison@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/bison/"
#define M4					"/bin/m4"

/* bison-specific, with no counterpart in the shared file */
#define PACKAGE_COPYRIGHT_YEAR 2021
