/*
 * config.h for diff.
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

#define PACKAGE              "diffutils"
#define PACKAGE_NAME         "GNU diffutils"
#define PACKAGE_STRING       "GNU diffutils 3.12"
#define PACKAGE_TARNAME      "diffutils"
#define PACKAGE_VERSION      "3.12"
#define VERSION              "3.12"
#define PACKAGE_BUGREPORT    "bug-diffutils@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/diffutils/"

/* diff-specific, absent from coreutils' config.h. The two program paths
   are what diff execs for --editor and for paginated output; values as
   diffutils' own config.h had them, PR_PROGRAM already pointed at APE's
   pr. HAVE_STRUCT_STAT_ST_RDEV is a probe coreutils does not run, and
   APE's struct stat does have st_rdev. */
#define DEFAULT_EDITOR_PROGRAM "ed"
#define PR_PROGRAM "/bin/pr"
#define HAVE_STRUCT_STAT_ST_RDEV 1
