#!/bin/sh
# import.sh — populate sys/src/external/gnulib from the vendored gnulib
# copies that ship inside the individual GNU packages.
#
# APExp builds ONE shared libgnu.a (see sys/src/ape/cmd/gnulib/mkfile).
# Previously each package compiled its own gnulib objects and appended
# them to a shared archive with 'ar vu', so which copy of a module ended
# up in the archive depended on build order. This script instead
# materialises a single coherent source tree, newest-copy-wins.
#
# Priority order is by gnulib vintage, newest first. The first tree that
# supplies a given file wins; later trees only fill in what is missing.
# coreutils is the base: it has the newest gnulib (2026) and by far the
# widest module coverage, so it decides the header set that everything
# else compiles against — including config.h.
#
# Run from this directory:  sh import.sh
# Re-running is safe; it refuses to touch an existing tree unless -f.

set -e

EXT=$(cd "$(dirname "$0")/.." && pwd)
DEST=$EXT/gnulib

# tree:subdir, newest gnulib first
TREES="coreutils/lib m4/lib diffutils/lib ggrep/lib patch/lib gtar/gnu gsed/lib bison/lib"

if [ "$1" != "-f" ] && [ -e "$DEST/config-common.h" ]; then
	echo "$DEST already populated; pass -f to re-import" >&2
	exit 1
fi

copied=0
skipped=0

for t in $TREES; do
	src=$EXT/$t
	[ -d "$src" ] || { echo "skip (absent): $t"; continue; }
	n=0
	# Sources and headers, plus the .def fragments some headers #include
	# textually: timevar.h expands timevar.def to build its enum and its
	# name table. No Makefiles, no .in.h templates that need autoconf.
	for f in $(cd "$src" && find . -name '*.c' -o -name '*.h' -o -name '*.def'); do
		d=$DEST/$(dirname "$f")
		# config.h lands as config-common.h. Each build directory has its
		# own config.h holding package identity, which includes this one;
		# keeping the shared file under that name would shadow them.
		if [ "$f" = "./config.h" ]; then
			[ -e "$DEST/config-common.h" ] && { skipped=$((skipped + 1)); continue; }
			cp "$src/$f" "$DEST/config-common.h"
			n=$((n + 1)); copied=$((copied + 1))
			continue
		fi
		if [ -e "$DEST/$f" ]; then
			skipped=$((skipped + 1))
			continue
		fi
		mkdir -p "$d"
		cp "$src/$f" "$DEST/$f"
		n=$((n + 1))
		copied=$((copied + 1))
	done
	echo "$t: contributed $n files"
done

# Drop gnulib's replacement system headers.
#
# A configured gnulib generates wrappers named stdio.h, unistd.h,
# stddef.h and so on from its *.in.h templates. Each one pulls in the
# real header with #include_next. That works under autoconf, which
# arranges the include path so the wrapper is found first and exactly
# once. Here the build passes -I$GNUSRC, so the wrappers shadow the APE
# headers and the two sets bounce off each other:
#
#   gnulib/stddef.h -> ape/time.h -> gnulib/time.h -> gnulib/sys/stat.h
#     -> ape/unistd.h -> gnulib/unistd.h -> gnulib/stdlib.h -> ...
#
# which cpp reports as "#if too deeply nested". APE's headers are musl
# derived and already provide what these wrappers add, so delete them
# and let every gnulib source compile against APE directly.
#
# obstack.h goes too. libap implements obstack, sys/include/ape/obstack.h
# is the matching full header, and the obstack module is deliberately
# absent from the mkfile's OFILES.
#
# NOT deleted, even though APE ships a file of the same name: error.h,
# sigsegv.h, unicase.h, unictype.h, unistr.h, unitypes.h. The APE copies
# are 8 to 27 line stubs, too thin to declare what gnulib's own error.c,
# sigsegv.c and u8-uctomb-aux.c need. config.h, getopt-cdefs.h, stdbit.h,
# stdckdint.h, uninorm.h and uniwidth.h have no APE counterpart at all.
SHADOWING="ctype.h dirent.h errno.h fcntl.h fnmatch.h getopt.h
	inttypes.h limits.h obstack.h pthread.h sched.h signal.h
	stddef.h stdint.h stdio.h stdlib.h string.h strings.h time.h
	uchar.h unistd.h wchar.h wctype.h"

pruned=0
for h in $SHADOWING; do
	if [ -f "$DEST/$h" ]; then
		rm -f "$DEST/$h"
		pruned=$((pruned + 1))
	fi
done
if [ -d "$DEST/sys" ]; then
	# sys/stat.h, sys/time.h, sys/types.h, sys/wait.h, sys/random.h are
	# all replacement wrappers; APE provides every one of them.
	pruned=$((pruned + $(ls "$DEST"/sys | wc -l)))
	rm -rf "$DEST/sys"
fi
echo "pruned $pruned replacement system headers"

# Generate fts_.h from the newest fts.in.h.
#
# fts.c includes "fts_.h", but newer gnulib ships only the fts.in.h
# template and generates that header. coreutils supplies fts.c and
# fts.in.h; ggrep still carries a pre-generated fts_.h, so the copy loop
# takes fts.c from coreutils and fts_.h from ggrep -- a 2026 source
# against a 2025 header:
#   fts.c:1023 name not declared: FTS_MOUNT
# @HAVE_SYS_CDEFS_H@ is the only substitution the template needs, and APE
# does have <sys/cdefs.h>. The @(#) left behind is an SCCS id in a
# comment, not a placeholder.
if [ -f "$DEST/fts.in.h" ]; then
	sed 's|@HAVE_SYS_CDEFS_H@|1|g' "$DEST/fts.in.h" > "$DEST/fts_.h"
	echo "generated fts_.h from fts.in.h"
fi

# Generate gmp.h, the wrapper over mini-gmp.
#
# coreutils' src/basenc.c and src/factor.c include <gmp.h> with no
# guard. HAVE_GMP_H and HAVE_LIBGMP are both undefined here, so gnulib's
# libgmp module answers with mini-gmp -- and gmp.h is not a template but
# a file the Makefile writes, so nothing in the tarball carries it:
#
#   basenc.c:23 Could not find include file <gmp.h>
#
# Contents as coreutils' lib/gnulib.mk writes them, under
# GL_GENERATE_MINI_GMP_H. The mini-mpq half is guarded by
# GNULIB_LIBGMP_MPQ, which config-common.h sets.
{
	echo '#include "mini-gmp.h"'
	echo '#if GNULIB_LIBGMP_MPQ'
	echo '# include "mini-mpq.h"'
	echo '#endif'
} > "$DEST/gmp.h"
echo "generated gmp.h as a mini-gmp wrapper"

# Strip package identity from the shared file. It began as coreutils'
# config.h, so it says PACKAGE "coreutils" and VERSION "9.11". bison
# reads VERSION and PACKAGE_STRING for its --version output and would
# introduce itself as GNU coreutils 9.11. Each build directory supplies
# these instead, in a config.h that includes config-common.h.
if [ -f "$DEST/config-common.h" ]; then
	for m in PACKAGE PACKAGE_BUGREPORT PACKAGE_NAME PACKAGE_STRING \
		 PACKAGE_TARNAME PACKAGE_URL PACKAGE_VERSION VERSION MANUAL_URL; do
		sed -i.bak "s|^#define $m \".*\"\$|/* APExp: package-specific, see the config.h in each build dir */\n/* #undef $m */|" \
			"$DEST/config-common.h"
	done
	rm -f "$DEST/config-common.h.bak"
	echo "stripped package identity from config-common.h"
fi

# coreutils sets ARGMATCH_DIE to usage (EXIT_FAILURE) in its config.h,
# since every coreutils program exports a usage function. A shared
# gnulib cannot assume that -- bison declares its usage static -- so
# neutralise both and let argmatch.c use its own default,
# exit (exit_failure).
if [ -f "$DEST/config-common.h" ]; then
	sed -i.bak \
		-e 's|^#define ARGMATCH_DIE usage (EXIT_FAILURE)|/* #undef ARGMATCH_DIE */|' \
		-e 's|^#define ARGMATCH_DIE_DECL void usage (int _e)|/* #undef ARGMATCH_DIE_DECL */|' \
		"$DEST/config-common.h"
	rm -f "$DEST/config-common.h.bak"
	echo "neutralised coreutils ARGMATCH_DIE in config.h"
fi

# libap implements vasnprintf and asnprintf with gnulib's signature, so
# the vasnprintf module is not in OFILES. Left at 1, vasnprintf.h renames
# both to rpl_* and nothing defines them.
if [ -f "$DEST/config-common.h" ]; then
	sed -i.bak 's|^#define REPLACE_VASNPRINTF 1|/* #undef REPLACE_VASNPRINTF */|' \
		"$DEST/config-common.h"
	rm -f "$DEST/config-common.h.bak"
	echo "turned off REPLACE_VASNPRINTF in config-common.h"
fi


# coreutils' configure recorded the locale path of whatever host it ran
# on. Point it at APE's.
if [ -f "$DEST/config-common.h" ]; then
	sed -i.bak 's|^#define GNULIB_LOCALEDIR ".*"|#define GNULIB_LOCALEDIR "/sys/lib/ape/locale"|' \
		"$DEST/config-common.h"
	rm -f "$DEST/config-common.h.bak"
fi

# APE has <stdio_ext.h>, so let fwriting.h include it rather than calling
# __fwriting with no declaration in scope.
if [ -f "$DEST/config-common.h" ]; then
	sed -i.bak 's|^/\* #undef HAVE_STDIO_EXT_H \*/|#define HAVE_STDIO_EXT_H 1|' \
		"$DEST/config-common.h"
	rm -f "$DEST/config-common.h.bak"
fi

# libap implements __fpurge in stdio/stdio_ext.c. Without this, fpurge.c
# takes neither the musl nor the BSD branch and falls through to poking
# at FILE internals it does not recognise.
if [ -f "$DEST/config-common.h" ]; then
	sed -i.bak 's|^/\* #undef HAVE___FPURGE \*/|#define HAVE___FPURGE 1|' \
		"$DEST/config-common.h"
	rm -f "$DEST/config-common.h.bak"
fi

# Guard config.h's copy of _UC_RESTRICT, the way unitypes.h guards its own.
#
# config.h carries a deliberate duplicate of the unitypes.h definition,
# for hosts whose pre-installed unitypes.h predates it. unitypes.h wraps
# its copy in #ifndef _UC_RESTRICT; the config.h copy is bare, because a
# config.h is meant to be read once per translation unit.
#
# grep's src/search.h includes <config.h> a second time, and under pcc
# the branch is not stable across the two visits. None of the
# __GNUC__/__clang_major__ arms apply, so the choice comes down to
# whether __restrict is defined yet -- not at grep.c's own <config.h>,
# but yes by the time <features.h> has been read:
#
#   config-common.h:5536 ... search.h:20 ... grep.c:47
#     Macro redefinition of _UC_RESTRICT
#
# Under gcc the first arm wins on both visits, so upstream never sees it.
if [ -f "$DEST/config-common.h" ] &&
   ! grep -q '^#ifndef _UC_RESTRICT' "$DEST/config-common.h"; then
	awk '
		/^# if defined __restrict/ && !seen {
			print "#ifndef _UC_RESTRICT"
			inblock = 1
			seen = 1
		}
		{ print }
		inblock && /^# endif/ {
			print "#endif"
			inblock = 0
		}
	' "$DEST/config-common.h" >"$DEST/config-common.h.new" &&
		mv "$DEST/config-common.h.new" "$DEST/config-common.h"
	echo "guarded _UC_RESTRICT in config-common.h"
fi

# Make the snippet macros reachable from config.h.
#
# gnulib keeps _GL_ARG_NONNULL and _GL_WARN_ON_USE in standalone snippet
# files and has autoconf splice their text into each generated
# replacement header. The deleted stdio.h alone carried 91 uses of
# _GL_ARG_NONNULL along with the definition. With those headers gone the
# macros vanish, and a module header such as stdio-safer.h that says
#
#   FILE *fopen_safer (char const *, char const *) _GL_ARG_NONNULL ((1, 2))
#
# reaches the compiler with _GL_ARG_NONNULL still an unknown identifier,
# which is a syntax error rather than a missing-header one.
#
# Both snippets are self-guarded and free of unsubstituted @PLACEHOLDER@
# text, so they can simply be included. Every gnulib source includes
# config.h first, so pulling them in from there covers all of them.
#
# c++defs.h is deliberately not included: it still has @PLACEHOLDER@ text
# and only matters for the C++ aliasing that this build does not use.
if [ -f "$DEST/config-common.h" ] && ! grep -q 'APExp: snippet macros' "$DEST/config-common.h"; then
	cat >> "$DEST/config-common.h" <<'EOF'

/* APExp: snippet macros.
   gnulib normally splices arg-nonnull.h and warn-on-use.h into its
   generated replacement headers. Those headers are removed here because
   they shadow APE's, so include the snippets directly instead. */
#include "arg-nonnull.h"
#include "warn-on-use.h"
EOF
	# The printf and scanf format attributes are spliced into the
	# generated stdio.h too. error.c and the vasnprintf family declare
	# functions with _GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD, so without
	# these the compiler meets an unknown identifier and reports a
	# syntax error on whatever argument follows it. Lift the block out
	# of stdio.in.h between two stable anchors rather than by line
	# number. Everything in it reduces to _GL_ATTRIBUTE_FORMAT, which
	# config.h already defines as empty for non-GCC compilers.
	{
		echo
		echo "/* APExp: printf and scanf format attributes, lifted from"
		echo "   stdio.in.h because the generated stdio.h that normally"
		echo "   carries them is deleted above. */"
		awk '/__gnu_printf__ is supported in GCC/ { p = 1 }
		     p { print }
		     /__scanf__, formatstring_parameter, first_argument/ { if (p) exit }' \
			"$DEST/stdio.in.h"
	} >> "$DEST/config-common.h"
	# libap implements the musl <stdio_ext.h> accessors, so let
	# freadahead.h, fseterr.h and fwriting.h take their "musl libc"
	# branch. Otherwise each falls through to a per-platform #elif chain
	# that selects its Plan 9 case on EPLAN9 and reads fp->state, fp->rp
	# and fp->wp from the old APE FILE. APExp's FILE is musl's, so those
	# members do not exist and the compile fails.
	cat >> "$DEST/config-common.h" <<'EOF'

/* APExp: libap implements the musl <stdio_ext.h> accessors. */
#define HAVE___FREADAHEAD 1
#define HAVE___FSETERR 1
#define HAVE___FWRITING 1
#define HAVE___FREADING 1
/* APE provides <stdio_ext.h>; fwriting.h gates its include on this. */
#define HAVE_STDIO_EXT_H 1

/* APExp: LOCALEDIR, for the packages whose mkfile does not pass -D.
   Guarded so a command-line -D still wins. */
#ifndef LOCALEDIR
# define LOCALEDIR "/sys/lib/ape/locale"
#endif
EOF
	# strnul is declared in the generated string.h as a macro over an
	# inline; strnul.c only emits the out-of-line copy of that inline, so
	# both vanish with the header. time_rz.c is the only compiled module
	# that calls it. gnulib documents it as s + strlen (s).
	cat >> "$DEST/config-common.h" <<'EOF'

/* APExp: strnul, normally declared in the generated string.h. */
#ifndef strnul
# define strnul(s) ((s) + strlen (s))
#endif

/* APExp: streq, likewise an inline in the generated string.h.
   streq.h is a different thing: the streq0..streq9 helpers call this
   one rather than define it. */
#ifndef streq
# define streq(a, b) (strcmp ((a), (b)) == 0)
#endif

/* APExp: platform answers coreutils' configure never recorded, because
   it reaches these through gnulib modules. Absent entirely, not even
   "#undef", so a package testing them directly defaults to 0 -- which
   made tar's lib/system.h define setlocale() away and break
   <locale.h>. All five hold on APE. */
#ifndef HAVE_LOCALE_H
# define HAVE_LOCALE_H 1
#endif
#ifndef HAVE_SETLOCALE
# define HAVE_SETLOCALE 1
#endif
#ifndef HAVE_FCNTL_H
# define HAVE_FCNTL_H 1
#endif
#ifndef HAVE_MEMORY_H
# define HAVE_MEMORY_H 1
#endif
#ifndef HAVE_STRUCT_STAT_ST_BLKSIZE
# define HAVE_STRUCT_STAT_ST_BLKSIZE 1
#endif

/* APExp: no non-Gregorian calendars in strftime. Otherwise strftime.c
   calls gl_locale_name_unsafe, which means gnulib's localename module,
   whose getlocalename_l-unsafe.c ends in "#error Please port ... to
   your platform". Plan 9 has one locale, so a calendar selected by
   locale name cannot trigger. strftime.c documents this override. */
#ifndef SUPPORT_NON_GREG_CALENDARS_IN_STRFTIME
# define SUPPORT_NON_GREG_CALENDARS_IN_STRFTIME 0
#endif

/* APExp: prototypes and off64_t the deleted wrappers carried. */
#include "apexp-decls.h"
EOF
	echo "appended snippet includes and format attributes to config.h"
fi

echo "---"
echo "imported $copied files into $DEST ($skipped already present, newer copy kept)"
echo
echo "config.h came from the first tree in TREES that had one (coreutils)."
echo "Modules imported from an older tree were written against that tree's"
echo "config.h; if one fails to build, add the HAVE_* it wants to"
echo "$DEST/config-common.h rather than reintroducing a per-package gnulib."
