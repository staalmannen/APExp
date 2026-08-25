/*
 * config.h for bison, layered on the shared gnulib one.
 *
 * The shared libgnu.a is built from sys/src/external/gnulib with
 * coreutils' config.h, so that file carries the platform answers every
 * package needs -- the HAVE_* probes, the type sizes, the APExp
 * additions. What it cannot carry is package identity: it says
 * PACKAGE "coreutils" and VERSION "9.11", and bison's src reads
 * VERSION, PACKAGE_STRING, PACKAGE_URL and PACKAGE_BUGREPORT for its
 * --version and --help output. Left alone, bison would introduce
 * itself as GNU coreutils 9.11.
 *
 * So take the shared file for the platform and override the identity.
 * The include is by relative path rather than <config.h>, which would
 * find this file again through -I. and recurse.
 *
 * bison's own lib/config.h is deliberately not used. It is from 2021,
 * and bison compiles against the 2026 gnulib headers now, so its
 * platform answers would no longer describe the objects being linked.
 */

#include "../../../external/gnulib/config.h"

#undef PACKAGE
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#undef PACKAGE_VERSION
#undef VERSION

#define PACKAGE "bison"
#define PACKAGE_BUGREPORT "bug-bison@gnu.org"
#define PACKAGE_NAME "GNU Bison"
#define PACKAGE_STRING "GNU Bison 3.8"
#define PACKAGE_TARNAME "bison"
#define PACKAGE_URL "https://www.gnu.org/software/bison/"
#define PACKAGE_VERSION "3.8"
#define VERSION "3.8"

/* bison-specific, with no counterpart in coreutils' config.h */
#define PACKAGE_COPYRIGHT_YEAR 2021
