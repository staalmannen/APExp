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

echo "---"
echo "imported $copied files into $DEST ($skipped already present, newer copy kept)"
echo
echo "config.h came from the first tree in TREES that had one (coreutils)."
echo "Modules imported from an older tree were written against that tree's"
echo "config.h; if one fails to build, add the HAVE_* it wants to"
echo "$DEST/config.h rather than reintroducing a per-package gnulib."
