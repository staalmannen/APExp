#!/bin/sh
#
# cpp-xcheck.sh -- build kencc's OWN cpp with gcc, on the build host, and
# diff it against gcc's preprocessor.
#
#	sh cpp-xcheck.sh                 # the hideset cases
#	sh cpp-xcheck.sh file.c -- -Dx   # any file, with cpp flags after --
#	sh cpp-xcheck.sh --regress A B   # diff two builds of cpp over files
#
# ***THIS IS A CROSS-CHECK, AND IT IS THE CHEAPEST INSTRUMENT THIS TREE
# HAS EVER HAD FOR THE PREPROCESSOR.*** Everything about `cc/' needs the
# VM, because kencc's sources want Plan 9's `<u.h>' -- which is why
# `clitzero-model.py' and friends TRANSCRIBE functions instead of
# compiling them. **cpp is the exception**: a survey of every Plan 9-ism
# in `sys/src/cmd/cpp' finds `uchar'/`uvlong'/`vlong'/`uint', `nil',
# `exits', `ARGBEGIN', `chartorune', `create', `getwd', a plan9 `dup',
# plan9's `ctime(long)' and `dirfstat' -- eleven names, all in `p9/'
# here, about sixty lines. So the real preprocessor runs on the host and
# every question about it becomes a local run instead of a round trip.
#
# *It had taken three probes and five refuted mechanisms to not answer
# one cpp question* (`cppaste-probe.c', `cppskip-probe.c',
# `cpplimit-probe.c'). This answered it in one run, and then measured
# the fix, and then measured the fix's cost.
#
# WHAT IT IS NOT. The binary is compiled by gcc, so it is ILP64 where
# kencc is LLP64 and its `long' is twice as wide. cpp's logic is
# pointers and ints, and `eval.c' does `#if' arithmetic in `vlong', so
# this is sound for TOKEN questions and **not** for questions about
# `#if' overflow or about the width of an integer constant. For those,
# the VM. The `uintptr' cast in `hideset.c' exists for exactly this
# reason and is commented there.
#
# THE REFERENCE. gcc, and it has to be: the cases in `hideset-cases.c'
# are either valid C whose result the standard fixes, or the standard's
# own EXAMPLE 3. A case gcc REJECTS cannot discriminate anything -- the
# first R7 was one, and it swallowed the rest of the file.
#
# THE REGRESSION MODE compares two builds of cpp against each other over
# real sources, which is the question `did this change anything else'
# that a case file cannot ask. The corpus that found something was
# clisp's: its 31 translation units, generated locally with
# `utils/comment5|gctrigger|varbrace' (all three build with gcc) and
# preprocessed against APExp's own `sys/include/ape'. **One header has
# to be shadowed**: `$objtype/include/ape/stddef_arch.h' includes
# `"/sys/include/ape/stddef.h"' by absolute path, which does not exist
# on the host, so a copy with that one line made relative goes in a
# directory earlier on `-I'. *Nothing else in APExp's headers needed
# help.*

set -e

ROOT=$(cd "$(dirname "$0")/../../../.." && pwd)
CPPSRC=$ROOT/sys/src/cmd/cpp
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=${TMPDIR:-/tmp}/cpp-xcheck.$$
mkdir -p "$OUT"
trap 'rm -rf "$OUT"' EXIT

# `sys/lib/tests/cpp-xcheck' is FOUR levels below the root, and this
# guard is here because `ishadow-sweep', `rceq-sweep' and `apfunc-sweep'
# each shipped with that count wrong -- and a wrong root makes every
# answer a confident one about nothing. ***IT FIRED ON ITS OWN FIRST
# RUN***, for the fourth time: this file is one level deeper than those
# three and I wrote their count.
test -f "$CPPSRC/macro.c" || {
	echo "cpp-xcheck: no $CPPSRC/macro.c -- ROOT is wrong" >&2
	exit 2
}

build() {	# build $1=srcdir -> $2=binary
	gcc -w -O1 -I"$HERE/p9" -I"$1" -o "$2" "$1"/*.c "$HERE/p9/shim.c"
}

case "${1:-}" in
--regress)
	# $2 and $3 are cpp source directories (e.g. a git worktree and HEAD)
	shift
	A=$1; B=$2; shift 2
	build "$A" "$OUT/a"
	build "$B" "$OUT/b"
	: "${objtype:=amd64}"; export objtype
	rc=0
	for f in "$@"; do
		"$OUT/a" $CPPXFLAGS "$f" > "$OUT/a.i" 2>/dev/null || true
		"$OUT/b" $CPPXFLAGS "$f" > "$OUT/b.i" 2>/dev/null || true
		if cmp -s "$OUT/a.i" "$OUT/b.i"; then
			echo "same     $f"
		else
			echo "DIFFERS  $f  ($(diff "$OUT/a.i" "$OUT/b.i" | grep -c '^[<>]') lines)"
			rc=1
		fi
	done
	exit $rc
	;;
esac

CASES=${1:-$HERE/hideset-cases.c}
[ $# -gt 0 ] && shift
[ "${1:-}" = "--" ] && shift

build "$CPPSRC" "$OUT/kcpp"
: "${objtype:=amd64}"; export objtype

# **The timeout is not belt and braces.** The failure this harness was
# built for has a sibling whose symptom is a preprocessor that never
# returns: the first version of the hideset intersection made case R2
# (`a(x)->b(x)', `b(x)->a(x)') loop for ever. Without a timeout the
# harness hangs and the operator reads it as a slow build.
#
# ***AND THE COMPARISON IS BY TOKEN, NOT BY LINE.*** The first run of
# this harness reported eight differences and every one was a SPACE:
# `V1((7)+1)' against `V1 ((7)+1)', `{1,23,' against `{ 1, 23,'. The
# standard fixes the token sequence and leaves inter-token white space to
# the implementation, so a line comparison reports faults that are not
# faults -- a check that can FAIL for the wrong reason, which is the twin
# of the rule this tree already carries.
#
# Stripping all white space would be the other error, since it welds
# `int i' into `inti'. `normalise' below keeps exactly one space where
# removing it would merge two identifier characters, and removes it
# everywhere else.
#
normalise() {
	python3 -c '
import sys, re
w = re.compile(r"[A-Za-z0-9_.]")
out = []
for line in sys.stdin:
    if line.startswith("#line"):
        continue
    s = re.sub(r"\s+", " ", line.strip())
    r = []
    for ch in s:
        if ch == " ":
            if r and w.match(r[-1]):
                r.append(" ")
        else:
            if r and r[-1] == " " and not w.match(ch):
                r.pop()
            r.append(ch)
    t = "".join(r).strip()
    if t:
        out.append(t)
sys.stdout.write("\n".join(out) + "\n")
'
}

timeout 60 "$OUT/kcpp" "$@" "$CASES" 2>"$OUT/kcpp.err" | normalise > "$OUT/kcpp.out" || true
gcc -E -P "$@" "$CASES" 2>"$OUT/gcc.err" | normalise > "$OUT/gcc.out" || true

if [ -s "$OUT/gcc.err" ]; then
	echo "cpp-xcheck: GCC COMPLAINED, so the reference is not a reference:"
	sed 's/^/    /' "$OUT/gcc.err"
	echo "cpp-xcheck: fix the case file before reading anything below."
fi

echo "cpp-xcheck: $CASES"
if cmp -s "$OUT/kcpp.out" "$OUT/gcc.out"; then
	echo "PASS  kencc cpp agrees with gcc on every line"
	exit 0
fi
echo "FAIL  kencc cpp differs from gcc:"
diff "$OUT/gcc.out" "$OUT/kcpp.out" | sed 's/^/    /'
echo "    (< is gcc, > is kencc)"
if [ -s "$OUT/kcpp.err" ]; then
	echo "cpp-xcheck: kencc cpp also said:"
	sed 's/^/    /' "$OUT/kcpp.err"
fi
exit 1
