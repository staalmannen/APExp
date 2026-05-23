#!/bin/sh
# gnulib-deps.sh: find gnulib object files needed for undefined symbols
#
# Usage (pipe mk link errors into it):
#   mk 2>&1 | sh gnulib-deps.sh LIBDIR PREFIX
#
# LIBDIR: path to the package's gnulib lib/ directory
# PREFIX: object file prefix used in the mkfile
#
# Examples:
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/bison/lib    libbison_a
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/m4/lib       libm4_a
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/ggrep/lib    libgrep_a
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/diffutils/lib libdiff_a
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/patch/lib    libpatch_a
#   mk 2>&1 | sh gnulib-deps.sh ../../../external/gtar/lib     libtar_a
#
# Output: sorted unique list of "	PREFIX-stem.$O \" lines ready to paste
# into the mkfile's LIB_OBJS section (or to uncomment existing lines).
#
# Note: the script finds where each symbol is DEFINED using grep.
# It may find false positives (callers, not definers) for some symbols.
# Review output before applying, and iterate if new undefined symbols appear.

LIBDIR=$1
PREFIX=$2

if [ -z "$LIBDIR" ] || [ -z "$PREFIX" ]; then
	echo "Usage: $0 LIBDIR PREFIX" >&2
	echo "" >&2
	echo "Examples:" >&2
	echo "  mk 2>&1 | sh gnulib-deps.sh ../../../external/bison/lib libbison_a" >&2
	exit 1
fi

if [ ! -d "$LIBDIR" ]; then
	echo "Error: LIBDIR '$LIBDIR' not found" >&2
	exit 1
fi

# Extract undefined symbol names from Plan9 linker error format:
#   "caller: undefined: SYMBOL in func"
# or standard ld format:
#   "undefined reference to `SYMBOL'"
extract_symbols() {
	grep ': undefined:' | sed 's/.*: undefined: //;s/ in .*//'
	grep "undefined reference to" | sed "s/.*undefined reference to \`//;s/'.*//"
}

# Find the .c file in LIBDIR that most likely DEFINES a given symbol.
# Strategy:
#   1. Direct file name match: foo_bar -> foo-bar.c or foo_bar.c
#   2. Grep for the symbol as a function definition (not extern/typedef)
find_defining_file() {
	sym=$1
	dash=$(echo "$sym" | tr '_' '-')

	# Try direct name match in top-level and one level of subdirs
	for name in "$sym" "$dash"; do
		for f in "$LIBDIR/$name.c" "$LIBDIR"/*/"$name.c"; do
			[ -f "$f" ] && { echo "$f"; return; }
		done
	done

	# Grep: find files containing the symbol as a likely definition.
	# A definition line typically has the symbol followed by '(' not preceded
	# by 'extern', 'typedef', '#define', or inside a comment.
	# We pick the file with the fewest lines (most focused module).
	best=""
	best_lines=9999999
	for f in $(grep -rln "\b${sym}\b *(" "$LIBDIR"/ 2>/dev/null); do
		# Skip if symbol only appears as extern or call — check for definition
		# by looking for the symbol at the start of a line or after a type
		if grep -qE "^[A-Za-z_*][A-Za-z0-9_ *]*[[:space:]]+\b${sym}\b[[:space:]]*(|$)" "$f" 2>/dev/null ||
		   grep -qE "^\b${sym}\b[[:space:]]*\(" "$f" 2>/dev/null; then
			n=$(wc -l < "$f")
			if [ "$n" -lt "$best_lines" ]; then
				best_lines=$n
				best=$f
			fi
		fi
	done

	# Fall back: just take any file containing the symbol
	if [ -z "$best" ]; then
		best=$(grep -rln "\b${sym}\b" "$LIBDIR"/ 2>/dev/null | head -1)
	fi

	echo "$best"
}

# Map a file path to the object stem (PREFIX-stem.$O)
file_to_obj() {
	f=$1
	base=$(basename "$f" .c)
	echo "	${PREFIX}-${base}.\$O \\"
}

# Main: extract symbols, find files, output object names
extract_symbols | sort -u | while read sym; do
	[ -z "$sym" ] && continue

	f=$(find_defining_file "$sym")

	if [ -z "$f" ]; then
		printf "# NOT FOUND: %s\n" "$sym" >&2
		continue
	fi

	file_to_obj "$f"
done | sort -u

echo ""
echo "# Paste the above lines into your mkfile's LIB_OBJS section." >&2
echo "# Then run mk again and repeat until the build succeeds." >&2
