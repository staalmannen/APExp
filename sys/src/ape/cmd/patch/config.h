/*
 * config.h for patch.
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

#define PACKAGE              "patch"
#define PACKAGE_NAME         "GNU patch"
#define PACKAGE_STRING       "GNU patch 2.8"
#define PACKAGE_TARNAME      "patch"
#define PACKAGE_VERSION      "2.8"
#define VERSION              "2.8"
#define PACKAGE_BUGREPORT    "bug-patch@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/patch/"

/* patch-specific, absent from coreutils' config.h. EDITOR_PROGRAM is
   what patch execs for an ed-format diff; note this is a different macro
   from the ed_PROGRAM already passed in CFLAGS, and patch/src uses both.
   sigfillset is a probe coreutils does not run; libap implements it in
   signal/sigset.c.

   USE_XATTR is left alone: patch sets it to 0 and the shared file already
   carries it as #undef, which reads the same. */
#define EDITOR_PROGRAM "/bin/ed"
#define HAVE_SIGFILLSET 1
