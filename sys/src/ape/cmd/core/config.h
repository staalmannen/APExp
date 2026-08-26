/*
 * config.h for GNU coreutils.
 *
 * This is the one package where the two halves are being rejoined.
 * config-common.h *is* coreutils' own config.h -- import.sh took it as
 * the base for the shared tree, because coreutils has the newest gnulib
 * and the widest module coverage -- with the package identity stripped
 * out so that bison would not introduce itself as GNU coreutils 9.11.
 *
 * So all this file has to do is put the identity back. Every platform
 * answer, every HAVE_*, every APExp addition is already in
 * config-common.h, reached through -I$GNUSRC, and is exactly what
 * coreutils' configure produced.
 *
 * Values from the package's own Makefile (PACKAGE = coreutils, and so
 * on) rather than invented.
 */

#include <config-common.h>

#define PACKAGE              "coreutils"
#define PACKAGE_NAME         "GNU coreutils"
#define PACKAGE_STRING       "GNU coreutils 9.11"
#define PACKAGE_TARNAME      "coreutils"
#define PACKAGE_VERSION      "9.11"
#define VERSION              "9.11"
#define PACKAGE_BUGREPORT    "bug-coreutils@gnu.org"
#define PACKAGE_URL          "https://www.gnu.org/software/coreutils/"
