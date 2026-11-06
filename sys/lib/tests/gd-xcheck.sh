#!/bin/sh
#
# gd-xcheck.sh -- build libgd from the VENDORED sources with gcc on the
# build host and run `gd-test.c' against it.
#
#	sh gd-xcheck.sh              # build and run; GATES on the failure count
#	sh gd-xcheck.sh --control    # break the library on purpose; must FAIL
#
# ***THERE IS NO REFERENCE IMPLEMENTATION OF libgd TO COMPARE
# AGAINST***, so this is not the usual cross-check shape.  What it
# gives instead is an A/B of the SAME SOURCE through two compilers:
# gcc here, kencc on the VM, one test file, one hand-answered
# `config.h' shared by both.  A failure on the VM that passes here is
# a kencc or libap bug and nothing else; a failure in both is
# `gd-test.c's own bug.
#
# That is the whole reason the library was vendored: all 47 files
# compiled clean under kencc on the first attempt, so **every bug this
# exercise can still find is a RUNTIME bug**, and a runtime bug needs
# a run on each side to localise.
#
# Fidelity limits, which are real and bound what a difference means:
#   - the host is LP64 and kencc is LLP64, so `long' is 64 bits here
#     and 32 there.  That is not a flaw in the instrument, it is the
#     thing most likely to produce a difference, and the difference is
#     the finding.
#   - host libpng is whatever the host ships; APExp's is 1.6.58.  A
#     PNG round trip is checked for its OWN pixels, not against a
#     stored file, so a version difference cannot make it disagree.
#   - gcc's own codegen is not kencc's, so a floating-point result can
#     differ in the last bit.  Nothing here asserts an inexact value:
#     the scaling section uses a FLAT image precisely so that every
#     weighted sum is exact whatever the arithmetic.

set -e

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(dirname "$(dirname "$(dirname "$HERE")")")

# ***ROOT GUARD.***  This has fired four times in this tree, each time
# because a file counted the wrong number of levels, and each time the
# symptom was a sweep confidently reporting nothing.  `sys/lib/tests'
# is THREE directories below the root.
test -d "$ROOT/sys/src/external/libgd" || {
	echo "gd-xcheck: ROOT=$ROOT has no sys/src/external/libgd" >&2
	echo "gd-xcheck: wrong number of dirnames above -- fix, do not guess" >&2
	exit 2; }

GD=$ROOT/sys/src/external/libgd
OUT=$HERE/out/gd
mkdir -p "$OUT"

control=no
[ "${1:-}" = "--control" ] && control=yes

# The source list is `src/Makefile.am's libgd_la_SOURCES, READ rather
# than recalled -- `ls *.c' gives 70, of which 23 are upstream's own
# demo programs with their own `main'.  The same derivation as
# `lib/gd/mkfile', and if the two ever disagree one of them is wrong.
srcs() {
	sed -n '/^libgd_la_SOURCES/,/^$/p' "$GD/src/Makefile.am" |
	grep -oE '[a-z0-9_]+\.c'
}

n=$(srcs | wc -l)
test "$n" -eq 47 || {
	echo "gd-xcheck: expected 47 library sources, Makefile.am gave $n" >&2
	echo "gd-xcheck: upstream moved; re-check lib/gd/mkfile too" >&2
	exit 2; }

CF="-I$GD -I$GD/src -DHAVE_CONFIG_H -w -O1"

rm -f "$OUT"/*.o "$OUT/libgd.a" 2>/dev/null || true
for s in $(srcs); do
	gcc $CF -c "$GD/src/$s" -o "$OUT/${s%.c}.o"
done

if [ "$control" = yes ]; then
	# ***A DELIBERATE BREAK, because there is no external oracle.***
	# `gdImageGetPixel' off by one column makes section 1 and every
	# comparison section wrong while leaving the library linkable --
	# the shape a miscompiled index would have.  If this does NOT
	# fail, the instrument is not reading the library it built.
	echo "gd-xcheck: CONTROL -- breaking gdImageGetPixel on purpose"
	sed 's/return im->pixels\[y\]\[x\];/return im->pixels[y][(x+1) % im->sx];/' \
		"$GD/src/gd.c" > "$OUT/gd_broken.c"
	if cmp -s "$GD/src/gd.c" "$OUT/gd_broken.c"; then
		echo "gd-xcheck: the control's sed matched NOTHING -- gd.c moved" >&2
		echo "gd-xcheck: a control that cannot break is not a control" >&2
		exit 2
	fi
	gcc $CF -c "$OUT/gd_broken.c" -o "$OUT/gd.o"
fi

ar rcs "$OUT/libgd.a" "$OUT"/*.o

# ***`-Werror=implicit-function-declaration' IS NOT TIDINESS.***  The
# first draft of `gd-test.c' called `gdImageRotate90', which is
# INTERNAL to libgd (`gd_intern.h', not installed).  C89 let it
# through as a function returning `int', the returned `gdImagePtr' was
# truncated to 32 bits, and the test SEGFAULTED -- on the host, where
# a pointer does not fit in an int.  That is this tree's own
# undeclared-function invariant, met inside a test written to hunt
# that class of bug, and a warning buried in gcc's output is not how
# it should announce itself.  The library is built `-w' above; the
# TEST is built strictly.
gcc -I"$GD/src" -Werror=implicit-function-declaration \
	-o "$OUT/gd-test" "$HERE/gd-test.c" "$OUT/libgd.a" \
	-lpng -lz -lm

set +e
"$OUT/gd-test"
rc=$?
set -e

echo
if [ "$control" = yes ]; then
	if [ "$rc" -eq 0 ]; then
		echo "gd-xcheck: CONTROL PASSED, which means it is BROKEN --"
		echo "gd-xcheck: the test did not notice a wrong gdImageGetPixel."
		exit 1
	fi
	echo "gd-xcheck: control fired ($rc failures), as it must."
	exit 0
fi

echo "gd-xcheck: $rc failure(s) under gcc"
exit "$rc"
