#!/bin/sh
# edgbaked-xcheck.sh -- which ABI is EDG's generated C baked for?
#
#	cd sys/lib/tests && ./edgbaked-xcheck.sh
#	./edgbaked-xcheck.sh --list		# every row, not just the findings
#	./edgbaked-xcheck.sh --control		# the positive control; MUST fire
#
# A HOST cross-check: it runs gcc and gdb on the build host and never
# goes near the VM.  Nothing here is compiled by pcc.
#
# ------------------------------------------------------------------
# WHAT IT ASKS
#
# EDG's C back end FOLDS `sizeof' and `offsetof' into integer literals.
# `docs/notes/edg.md' records that for the two folded `offsetof' sites
# -- `trans_unit.h''s pair, 400 and 416 -- and `edgtuoff-probe' measures
# exactly those two.  **This asks the same question of every folded
# `sizeof' in the corpus at once**, 91 of them, by the one shape that
# names its own type:
#
#	((T *)(alloc_fe(NULL)))
#
# -- an allocation whose result is cast, so the literal is `sizeof(T)'
# and `T' is written beside it.  Each is compared against what the
# compiling compiler lays `T' out as, read from the DWARF of a real
# `gcc -g -c' object.
#
# ***THE CORPUS IS ABI-LOCKED AND THIS IS HOW YOU FIND OUT TO WHICH
# ABI.***  A baked size that disagrees with the compiler building it is
# an allocation of the wrong length: every member past the short point
# lands in the next object, with no diagnostic from anyone, at run time
# only.  `alloc_fe' hands out bytes from EDG's own sub-allocator, so
# **valgrind cannot see it either** -- the write is inside a malloc'd
# block.  That is measured, not assumed: valgrind over the host-built
# cpfe reports exactly one error, the final null dereference, and
# nothing about the overrun that caused it.
#
# ------------------------------------------------------------------
# THE RECORDED HOST ANSWER, which is what `--control' asserts
#
#	agree 83   array 4   disagree 4
#
# and the four disagreements, every one gcc-larger and every one a
# multiple of 8:
#
#	a_tmpl_decl_state             384 -> 392   (+8)
#	a_decl_parse_state            480 -> 488   (+8)
#	a_translation_unit            440 -> 464   (+24)
#	a_string_literal_table_entry   24 ->  32   (+8)
#
# **One direction and one modulus is the finding, not the four names.**
# It says the corpus was generated for a target whose `long' is 4 bytes
# -- LLP64 -- while gcc on x86-64 Linux is LP64.  kencc amd64 IS LLP64,
# so the corpus is right for the VM and wrong here, which is a fact
# about this host and not a bug in EDG.
# *`a_translation_unit''s +24 is independent corroboration*: it is the
# same 24 as `edgtuoff-probe''s 400 -> 424, the five `unsigned long' in
# `an_il_header', arrived at from the struct's SIZE rather than from a
# member's offset.
#
# **83 agreeing is why the host-built cpfe gets as far as it does.**
# Most of EDG's structs hold no `long' at all, so most allocations are
# the right length and the binary parses its own command line, prints
# EDG's own diagnostics and reaches per-translation-unit init before
# the first short one bites.  *A build that runs is not a build whose
# ABI matches.*
#
# ------------------------------------------------------------------
# THE `array' COLUMN IS A HEURISTIC AND IS REPORTED, NOT COUNTED
#
# `((T *)(alloc_fe(NULL)))' is also how the corpus allocates an ARRAY of
# T -- `a_routine_ptr' 800 is 100 pointers, `a_byte' 65536 is a buffer.
# From the literal alone an array of N is indistinguishable from a
# wrong size, and the only discriminator available is exact
# divisibility.  **So a row whose baked size is an exact multiple of
# the compiler's is reported as `array N' and NOT as agreement** --
# because a genuine disagreement can be divisible by accident, and
# counting those as agreement is the quiet direction to be wrong in.
# Read the array rows; there are four and all four are obvious.
# *`a_string_literal_table_entry' 24 against 32 is why this matters
# less than it looks: 24 is not a multiple of 32, so the heuristic
# cannot hide a short allocation, only a long one.*
#
# ------------------------------------------------------------------
# WHAT IT CANNOT SAY
#
# * **Nothing about the VM.**  There is no gcc and no gdb there, and
#   the whole method is DWARF.  It answers "does the corpus match the
#   compiler in front of it", and the compiler in front of it here is
#   gcc.  For the VM the instrument is `edgtuoff-probe', which asks two
#   of these same questions with pcc and no debugger.
# * **Nothing about folded `offsetof'.**  Those carry no type name, so
#   they cannot be swept this way -- that is the whole reason
#   `edgtuoff-probe' is a hand-written reduction.  `docs/notes/edg.md'
#   has the two sites.
# * **Nothing about a size the corpus never bakes.**  A struct EDG only
#   ever allocates through a variable is invisible here.
#
# ------------------------------------------------------------------
set -u

# Root guard.  `sys/lib/tests' is THREE levels below the repository
# root -- a sweep in this directory has got that wrong twice, once
# reporting a confident `absent' for everything and once a confident 0.
HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../.." && pwd)
if [ ! -f "$ROOT/CLAUDE.md" ]; then
	echo "edgbaked-xcheck: ROOT=$ROOT is not the repository root" >&2
	exit 2
fi
SRC=$ROOT/sys/src/external/edg/src
INC=$ROOT/sys/src/external/edg/include
if [ ! -d "$SRC" ]; then
	echo "edgbaked-xcheck: no $SRC" >&2
	exit 2
fi

MODE=report
case "${1-}" in
--list)    MODE=list ;;
--control) MODE=control ;;
"")        ;;
*)         echo "usage: $0 [--list|--control]" >&2; exit 2 ;;
esac

# ***IT MUST REFUSE TO RUN WHERE IT CANNOT WORK, AND THE FIRST VERSION
# DID NOT.***  Run on the VM -- which has no `gcc' and no `gdb' -- it
# printed 25 `WARNING ... did not compile' lines, 91 `UNREADABLE' rows
# and then
#
#	edgbaked-xcheck: agree 0  array 0  disagree 0  unreadable 91
#
# *which is a summary line shaped exactly like a clean result*, with
# the zero that matters sitting in the `disagree' column.  The header
# said HOST cross-check in three places and nothing enforced it: this
# tree's own rule is that **a check whose negative result has two
# explanations is not a check**, and "0 disagreements" there meant
# "no compiler", not "the corpus agrees".
#
# So the tools are a precondition, not a warning.  The WARNING lines
# stay for the case where gcc exists and one file genuinely fails to
# compile, which is a finding; a run with no gcc at all is not.
missing=
for t in gcc gdb; do
	command -v "$t" >/dev/null 2>&1 || missing="$missing $t"
done
if [ -n "$missing" ]; then
	echo "edgbaked-xcheck: REFUSING TO RUN -- no$missing on this machine." >&2
	echo "edgbaked-xcheck: this is a HOST cross-check: it reads struct" >&2
	echo "edgbaked-xcheck: layouts out of DWARF, so it answers only for" >&2
	echo "edgbaked-xcheck: the compiler in front of it.  On the VM the" >&2
	echo "edgbaked-xcheck: instrument for this question is edgtuoff-probe," >&2
	echo "edgbaked-xcheck: which asks it with pcc and no debugger." >&2
	exit 2
fi

TMP=${TMPDIR:-/tmp}/edgbaked.$$
mkdir -p "$TMP/dw" || exit 2
trap 'rm -rf "$TMP"' 0 1 2 15

# ---- extract (type, baked size, a file holding the site) -----------
#
# The file column is a file the SITE occurs in, deliberately -- not the
# file that defines the type.  A translation unit containing the cast
# and the member writes necessarily has the type COMPLETE, so its DWARF
# can answer; picking the smallest file that merely mentions the type
# left 47 of 91 unreadable.
#
# `RE' is the pattern.
RE='\(\(_ZN3edg[0-9]+[A-Za-z_0-9]+E \*\)\(_ZN3edg8alloc_feEy\([0-9]+ULL\)\)\)'

extract() {	# $1 = pattern -> stdout "type baked file"
	( cd "$SRC" && for f in *.c; do
		grep -ohE "$1" "$f" |
		sed -E "s/\(\((.*) \*\)\(_ZN3edg8alloc_feEy\(([0-9]+)ULL\)\)\)/\1 \2 $f/"
	  done ) | sort -u -k1,2
}

# ***THE CONTROL HAS TWO HALVES AND ONE ALONE PROVES NOTHING.***  A
# pattern that matches nothing must be REPORTED rather than counted as
# a clean sweep -- and a pattern that matches must still find the known
# answer, or the first half passes for a regex that matches everything.
# *This tree has paid for a gating sweep that reported 0 over lines it
# could not see, and for a break planted in only one of the shapes.*
if [ "$MODE" = control ]; then
	bad=$(extract '\(\(_ZN3edg_NO_SUCH_SHAPE_E \*\)\(_ZN3edg8alloc_feEy\([0-9]+ULL\)\)\)' | wc -l)
	if [ "$bad" -ne 0 ]; then
		echo "edgbaked-xcheck: CONTROL FAILED -- a broken pattern matched $bad" >&2
		exit 1
	fi
	echo "edgbaked-xcheck: control 1/2 OK -- a broken pattern reports nothing"

	got=$(extract "$RE" | awk '$1=="_ZN3edg18a_translation_unitE"{print $2}')
	if [ "$got" != 440 ]; then
		echo "edgbaked-xcheck: CONTROL FAILED -- a_translation_unit baked" >&2
		echo "edgbaked-xcheck: size is '$got', recorded 440.  Either the" >&2
		echo "edgbaked-xcheck: corpus was regenerated (re-read the notes" >&2
		echo "edgbaked-xcheck: before trusting any row) or the extraction" >&2
		echo "edgbaked-xcheck: is broken." >&2
		exit 1
	fi
	echo "edgbaked-xcheck: control 2/2 OK -- the real pattern still finds 440"
	exit 0
fi

extract "$RE" > "$TMP/pairs"
n=$(wc -l < "$TMP/pairs")

if [ "$n" -eq 0 ]; then
	# A sweep reporting 0 over lines it cannot see is the failure this
	# tree's own notes warn about.  Zero sites is never a clean result.
	echo "edgbaked-xcheck: 0 sites -- the pattern matched nothing; the" >&2
	echo "edgbaked-xcheck: corpus was regenerated or the regex rotted." >&2
	exit 1
fi

# ---- one gcc -g object per file that holds a site ------------------
built=0
wanted=0
for f in $(awk '{print $3}' "$TMP/pairs" | sort -u); do
	wanted=$((wanted + 1))
	o="$TMP/dw/${f%.c}.o"
	if gcc -w -O0 -g -c -I"$SRC" -I"$INC" -o "$o" "$SRC/$f" 2>/dev/null; then
		built=$((built + 1))
	else
		echo "edgbaked-xcheck: WARNING $f did not compile" >&2
	fi
done

# **A warning per file and then a summary of zeros is the same failure
# in a second costume**, so the count is a gate too: one file that will
# not compile is a finding worth reading beside the rows, all of them
# failing is a machine that cannot answer the question.
if [ "$built" -eq 0 ]; then
	echo "edgbaked-xcheck: REFUSING TO REPORT -- 0 of $wanted files" >&2
	echo "edgbaked-xcheck: compiled, so every row would read UNREADABLE" >&2
	echo "edgbaked-xcheck: and the summary would show 0 disagreements" >&2
	echo "edgbaked-xcheck: for want of a compiler rather than because" >&2
	echo "edgbaked-xcheck: the corpus agrees." >&2
	exit 2
fi

# ---- ask the DWARF ------------------------------------------------
# Two spellings: most of these names are typedefs to class types, a
# minority are plain structs.
: > "$TMP/rows"
while read -r t n f; do
	o="$TMP/dw/${f%.c}.o"
	v=$(gdb -q -batch -ex "print sizeof($t)" "$o" 2>/dev/null |
	    sed -n 's/^\$1 = //p')
	[ -n "$v" ] || v=$(gdb -q -batch -ex "print sizeof(struct $t)" "$o" \
	    2>/dev/null | sed -n 's/^\$1 = //p')
	echo "${v:-?} $n $t" >> "$TMP/rows"
done < "$TMP/pairs"

LIST=$MODE awk '
{
	gcc = $1; baked = $2; type = $3
	if (gcc == "?") { u++; printf "  UNREADABLE  baked=%-7s %s\n", baked, type; next }
	if (gcc == baked) { a++; if (ENVIRON["LIST"] == "list") printf "  agree       %-7s %s\n", baked, type; next }
	if (gcc+0 > 0 && baked % gcc == 0 && baked / gcc > 1) {
		arr++
		printf "  array %-5d baked=%-7s elem=%-5s %s\n", baked/gcc, baked, gcc, type
		next
	}
	d++
	printf "  DISAGREE    baked=%-7s gcc=%-7s (%+d) %s\n", baked, gcc, gcc-baked, type
}
END {
	printf "\nedgbaked-xcheck: agree %d  array %d  disagree %d  unreadable %d\n",
	    a, arr, d, u
}' "$TMP/rows"
