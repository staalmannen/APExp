#!/bin/sh
#
# hostkencc.sh -- build kencc's C compilers with gcc, on the build host.
#
#	sh hostkencc.sh            # build every backend, report per backend
#	sh hostkencc.sh 6c 8c      # just these
#	sh hostkencc.sh --clean
#
# Then, for example:
#
#	out/bin/6c -S /tmp/t.c
#	out/bin/6c -c ../regpair-min.c
#
# ***WHAT THIS IS FOR.*** `cpp-xcheck' showed that one third of kencc
# runs on the host; this is the rest of the front end. The compilers are
# the part of this tree where a round trip costs the most -- a `cc/'
# change means a VM build and, by this tree's own rule, ten compiles
# against ten backends -- and `regpair-probe'/`regpair-min' exist
# precisely to ask all ten whether they still compile a construct. **That
# question is local now.**
#
# WHAT IT IS BUILT FROM, and none of it is new code:
#
#   - APExp's own `sys/src/cmd/cc' and `sys/src/cmd/[1-9kqv]c'. *The
#     sources under test are the shipped ones*, which is the whole point;
#     nothing here forks a compiler source file.
#   - go1.4's `lib9', `libbio' and `include', already vendored at
#     `sys/src/external/go1.4'. That is plan9port's Plan 9 API on Unix,
#     in the same lineage as `goken9cc' (which forked the Go repo in
#     October 2010) but newer, and **it compiled with gcc on the first
#     attempt: 89 objects, no diagnostics.** `lib9/main.c' provides the
#     real `main', because `libc.h:366' is `#define main p9main'.
#   - `compat-unix.c' here -- the Unix half of `cc/compat.h', which is
#     `cc/compat' with `systemtype()' and the allocator changed and the
#     other eight hooks VERBATIM, because lib9 implements Plan 9's
#     `create'/`seek'/`dup'/`exec'/`getwd' and even `wait' returning a
#     `Waitmsg*'.
#   - `prelude.h' here, for three name collisions and nothing else.
#   - `mkenam.sh' here, a sed port of `cc/mkenam', which is an `ed'
#     script and there is no `ed' on this host.
#
# ***THE FIDELITY LIMITS, WHICH ARE THE POINT OF READING THIS FILE.***
#
# **kencc is LLP64 and this build is LP64: the host `long' is 64 bits
# where every kencc target's is 32.** So:
#
#   SOUND:   does it compile, does it crash, does it diagnose, what does
#            the parser accept, what does the type machinery do, and
#            -- the big one -- A/B between two builds of the SAME
#            sources (`--regress' below), where both sides share the
#            host's widths and the difference is the change under test.
#   UNSOUND: anything keyed on `long' being 32 bits. `specbits-model.py'
#            exists for exactly this: `TNORET' was `1L<<31' with zero
#            shifts spare on the target, and on the host there are 32
#            spare, so an overflow that is real there cannot appear
#            here. Constant folding of `long' expressions is the other
#            family. **For those, the VM, and the models.**
#
# `-m32' is not the way out and was checked: this host has no 32-bit
# runtime, and in any case gcc -m32 gives a 32-bit POINTER, where kencc
# on amd64 has a 32-bit `long' and a 64-bit pointer. *Neither host model
# matches; the LP64 one at least gets pointers right.*
#
# **One width assumption was already a latent out-of-bounds write** and
# is fixed in the tree rather than worked around here: `cc.h:47`'s NVAR
# was `BITS*sizeof(ulong)*8` while `bits.c' hardcodes 32, so a 64-bit
# `ulong' made `bsetc(319)' write four words past `Bits.b[5]'. It is
# `BITS*32' now, which is the same number on Plan 9.
#
# ***AND THE FIRST THING THAT LOOKED LIKE A HOST ARTIFACT WAS NOT ONE.***
# `6c -S' on `int f(int x){return x;}' answers `MOVL BP,AX', which reads
# as a parameter register-allocated with nothing loading it. It is
# correct: `6c/6.out.h:811' is `REGARG = D_BP', so kencc's amd64
# convention passes the first word-sized argument in BP and
# `cc/pgen.c:57' spills it. *Checked after it had already been called a
# bug*, which is the rule in CLAUDE.md about reading what the code does.
#
# **THE CONTROL THIS HARNESS CANNOT RUN ITSELF.** Nothing here proves a
# host-built `6c' agrees with a VM-built one. The diff is one command on
# each side over the same input:
#
#	( on the VM )   6c -S sys/lib/tests/hostkencc/agree.c > /tmp/vm.s
#	( on the host ) out/bin/6c -S agree.c > /tmp/host.s
#
# ***IT HAS BEEN RUN AND IT FOUND A REAL BUG ON THE FIRST DIFF***: the
# host emitted `CMPQ BP,$4294967296', an immediate x86-64 does not have,
# because `6c/cgen.c's `immconst()' decided "fits in 32 bits" with a
# round trip through `long'. Fixed, and `widecase' now matches the VM
# instruction for instruction.
#
# **What still differs is the ORDER of commutative terms** in two
# functions -- identical instruction multisets, same value -- from
# `cc/scon.c's `acom2', whose sort comparators tie-break on the
# ADDRESSES of the array elements `qsort' is permuting. Not fixed on
# purpose; `agree.c' and `docs/notes/kencc.md' have the reasoning.
#
# **So codegen from this harness is sound with ONE NAMED EXCEPTION.**
# Re-run the diff after any change to `cc/' or `6c/': the two `acom2'
# orderings are expected, and anything beyond them is a finding.

set -e

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../../.." && pwd)
CMD=$ROOT/sys/src/cmd
GO14=$ROOT/sys/src/external/go1.4
OUT=$HERE/out

# `sys/lib/tests/hostkencc' is FOUR levels below the root. The guard is
# here because this count has been wrong in four instruments now
# (`ishadow-sweep', `rceq-sweep', `apfunc-sweep', `cpp-xcheck'), and a
# wrong root makes every answer a confident one about nothing.
test -f "$CMD/cc/cc.h" || { echo "hostkencc: no $CMD/cc/cc.h -- ROOT wrong" >&2; exit 2; }
test -d "$GO14/src/lib9" || {
	echo "hostkencc: no $GO14/src/lib9 -- go1.4 is not vendored here" >&2
	exit 2
}

case "${1:-}" in
--clean) rm -rf "$OUT"; echo "hostkencc: removed $OUT"; exit 0;;
--probe)
	# The ten-backend question this tree already asks on the VM after any
	# change to `cc/'s type tables, asked here instead.
	#
	# ***kencc's `diag()' WRITES TO STDOUT, NOT STDERR***, and that is the
	# whole reason this is a mode rather than a one-liner. `Bprint(&diagbuf,
	# ...)' goes to fd 1, so the first version of this sweep -- which
	# captured `2>&1 >/dev/null' -- reported **all ten backends passing
	# `regpair-probe'**, including the two that do not. *A check that
	# passes for the wrong reason*, caught only because the tree's recorded
	# answer is eight of ten and the sweep disagreed with it.
	shift
	probes=$*
	test -n "$probes" || probes="regpair-min regpair-probe"
	rc=0
	for d in 1c 2c 5c 6c 7c 8c 9c kc qc vc; do
		test -x "$OUT/bin/$d" || { echo "hostkencc: $d not built"; rc=1; continue; }
		line="$d"
		for f in $probes; do
			m=$("$OUT/bin/$d" -c -I "$HERE/plan9" -o /dev/null "$HERE/../$f.c" 2>&1 | head -1)
			line="$line  $f:${m:-ok}"
		done
		echo "hostkencc: $line"
	done
	exit $rc
	;;
esac

HOSTCC=${HOSTCC:-gcc}
mkdir -p "$OUT"

# ---- 1. lib9 + libbio + libfmt + libutf, from go1.4 -------------------
# The unix arms only: `run_plan9.c', `run_windows.c', `tempdir_plan9.c',
# `tempdir_windows.c', `windows.c' and `goos.c' are other platforms' or
# go's own. `main.c' IS included -- it defines the real `main'.
if [ ! -f "$OUT/lib9.a" ]; then
	echo "hostkencc: building lib9.a"
	L=$OUT/lib9; mkdir -p "$L"
	SRC=$(ls "$GO14"/src/lib9/*.c |
		grep -vE '/(windows|run_plan9|run_windows|tempdir_plan9|tempdir_windows|goos)\.c$')
	SRC="$SRC $(ls "$GO14"/src/lib9/fmt/*.c | grep -vE '/test\.c$')"
	SRC="$SRC $(ls "$GO14"/src/lib9/utf/*.c | grep -vE '/mkrunetype\.c$')"
	SRC="$SRC $(ls "$GO14"/src/libbio/*.c)"
	( cd "$L" && $HOSTCC -c -w -O1 -D_GNU_SOURCE \
		-I"$GO14/include" -I"$GO14/src/lib9/fmt" $SRC )
	rm -f "$OUT/lib9.a"
	ar rc "$OUT/lib9.a" "$L"/*.o
	echo "hostkencc: lib9.a = $(ar t "$OUT/lib9.a" | wc -l) objects"
fi

# ---- 2. the parser ----------------------------------------------------
# bison, not Plan 9 yacc. The conflict counts are the recorded baseline
# (22 shift/reduce, 6 reduce/reduce) and are printed so a change to
# `cc.y' that moves them is visible here rather than on the VM.
if [ ! -f "$OUT/y.tab.c" ]; then
	echo "hostkencc: bison cc.y"
	( cd "$OUT" && bison -y -d -o y.tab.c "$CMD/cc/cc.y" 2>&1 |
		sed -n 's/^.*warning: \(.*conflicts.*\)$/hostkencc:   \1/p' )
fi

# ---- 3. one backend ---------------------------------------------------
# **OFILES comes from the backend's own mkfile and is not globbed.** The
# first attempt globbed `$d/*.c' and six of the ten failed to link --
# `1c'/`2c' do not use `cc/pgen.c' at all, `9c' has its own `bits.c',
# and `7c'/`qc' disagree with `cc/pswt.c' about `swcmp'. *Those are
# per-backend build lists, not portability faults*, and reading the
# mkfile is the difference between six failures and the truth.
ofiles() {	# $1 = mkfile
	sed -n '/^OFILES=/,/[^\\]$/p' "$1" |
		tr -d '\\' | tr ' \t' '\n' |
		sed -n 's/^\([A-Za-z0-9_.]*\)\.\$O$/\1/p'
}

build() {	# $1 = backend dir name, e.g. 6c
	d=$1
	# **`T' and the object-header directory come from the backend's own
	# mkfile, not from the directory name.** `1c' sets `T=2' and its
	# HFILES name `../2c/2.out.h': the 68000 and 68020 backends share one
	# object format, so `1c' has no `1.out.h' and deriving the name from
	# `1c' asks for a file that has never existed. `mkfile.port' spells
	# this `D=${T:%=%c}'.
	t=$(sed -n 's/^T=\(.*\)$/\1/p' "$CMD/$d/mkfile" | head -1)
	test -n "$t" || { echo "hostkencc: $d/mkfile has no T=" >&2; return 1; }
	o=$OUT/obj/$d
	rm -rf "$o"; mkdir -p "$o"
	: > "$o/err"

	sh "$HERE/mkenam.sh" "$CMD/${t}c/$t.out.h" > "$o/enam.c"

	# **`-fcommon' is required and is not a style choice.** Each backend's
	# `gc.h' carries bare `int hintabsize;'-style TENTATIVE definitions,
	# which every TU including it defines; Plan 9's linkers merge those,
	# and gcc 10 and later default to `-fno-common' and refuse them
	# (`multiple definition of `hintabsize''). Six of the ten backends
	# fail to link without it. *A host flag, so no shipped source changes
	# for it.*
	F="-w -O1 -fcommon -I$HERE -I$OUT -I$CMD/cc -I$CMD/$d -I$GO14/include -include $HERE/prelude.h"
	nbad=0

	# cc.a. `compat' is ours; `omachcap' must stay in the ARCHIVE so the
	# backend's own `machcap.o' wins, which is the Plan 9 link's own
	# behaviour and the reason this is an `ar' and not a pile of objects.
	for n in $(ofiles "$CMD/cc/mkfile"); do
		case $n in
		y.tab)   s=$OUT/y.tab.c;;
		compat)  s=$HERE/compat-unix.c;;
		*)       s=$CMD/cc/$n.c;;
		esac
		$HOSTCC -c $F -o "$o/cc_$n.o" "$s" 2>>"$o/err" || nbad=$((nbad+1))
	done

	# the backend. A name with no `.c' in the backend directory comes
	# from `cc/', which is `mkfile.port's `%.$O: ../cc/%.c' rule.
	for n in $(ofiles "$CMD/$d/mkfile"); do
		case $n in
		enam) s=$o/enam.c;;
		*)    if [ -f "$CMD/$d/$n.c" ]; then s=$CMD/$d/$n.c; else s=$CMD/cc/$n.c; fi;;
		esac
		$HOSTCC -c $F -o "$o/bk_$n.o" "$s" 2>>"$o/err" || nbad=$((nbad+1))
	done

	# `cc_lex.o' is named explicitly because it defines `main' (as
	# `p9main'): GNU ld does not search archives for the entry point the
	# way Plan 9's linkers do, so pulling it from cc.a leaves `_start'
	# with an undefined `main'.
	rm -f "$o/cc.a"
	ar rc "$o/cc.a" "$o"/cc_*.o 2>>"$o/err"
	mkdir -p "$OUT/bin"
	if [ "$nbad" -eq 0 ] && $HOSTCC -o "$OUT/bin/$d" "$o"/bk_*.o "$o/cc_lex.o" \
			"$o/cc.a" "$OUT/lib9.a" -lm 2>>"$o/err"; then
		printf 'hostkencc: %-3s OK    %s\n' "$d" "$OUT/bin/$d"
		return 0
	fi
	printf 'hostkencc: %-3s FAIL  %d objects failed, %d diagnostic lines in %s\n' \
		"$d" "$nbad" "$(grep -c . "$o/err" 2>/dev/null || echo 0)" "$o/err"
	return 1
}

BACKENDS=${*:-1c 2c 5c 6c 7c 8c 9c kc qc vc}
rc=0
for d in $BACKENDS; do
	case $d in --*) continue;; esac
	build "$d" || rc=1
done
exit $rc
