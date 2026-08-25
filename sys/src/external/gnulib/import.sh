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

if [ "$1" != "-f" ] && [ -e "$DEST/config.h" ]; then
	echo "$DEST already populated; pass -f to re-import" >&2
	exit 1
fi

copied=0
skipped=0

for t in $TREES; do
	src=$EXT/$t
	[ -d "$src" ] || { echo "skip (absent): $t"; continue; }
	n=0
	# .c and .h only: no Makefiles, no .in.h templates that need autoconf
	for f in $(cd "$src" && find . -name '*.c' -o -name '*.h' -o -name 'config.h'); do
		d=$DEST/$(dirname "$f")
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
if [ -f "$DEST/config.h" ] && ! grep -q 'APExp: snippet macros' "$DEST/config.h"; then
	cat >> "$DEST/config.h" <<'EOF'

/* APExp: snippet macros.
   gnulib normally splices arg-nonnull.h and warn-on-use.h into its
   generated replacement headers. Those headers are removed here because
   they shadow APE's, so include the snippets directly instead. */
#include "arg-nonnull.h"
#include "warn-on-use.h"
EOF
	echo "appended snippet includes to config.h"
fi

echo "---"
echo "imported $copied files into $DEST ($skipped already present, newer copy kept)"
echo
echo "config.h came from the first tree in TREES that had one (coreutils)."
echo "Modules imported from an older tree were written against that tree's"
echo "config.h; if one fails to build, add the HAVE_* it wants to"
echo "$DEST/config.h rather than reintroducing a per-package gnulib."
