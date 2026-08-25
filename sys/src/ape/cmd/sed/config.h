/*
 * config.h for sed.
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

#define PACKAGE              "sed"
#define PACKAGE_NAME         "GNU sed"
#define PACKAGE_STRING       "GNU sed 4.9"
#define PACKAGE_TARNAME      "sed"
#define PACKAGE_VERSION      "4.9"
#define VERSION              "4.9"
#define PACKAGE_BUGREPORT    "bug-sed@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/sed/"

/* Probes coreutils never ran, so they are absent from the shared file
   rather than answered there. libap implements all three: popen in
   stdio/popen.c, setlocale in locale/locale_stubs.c. HAVE_FOPEN_RT is
   sed's own, for the "rt" mode string. Values as sed's config.h had them.

   HAVE_SELINUX_SELINUX_H is left alone: sed sets it to 0 and the shared
   file already carries it as #undef, which reads the same to gnulib. */
#define HAVE_POPEN 1
#define HAVE_SETLOCALE 1
#define HAVE_FOPEN_RT 1
