#!/bin/sh
#
# cxxapp-host.sh -- can APExp's C++ library build a real application?
#
#	sh cxxapp-host.sh unrar      # compile its objects, report the gaps
#	sh cxxapp-host.sh re2c
#	sh cxxapp-host.sh --headers  # just: which <...> does each package
#	                             # want that we do not have?
#	sh cxxapp-host.sh --control  # the harness must still see a known gap
#
# ***REPORTS, DOES NOT GATE.***  These are ports in progress; a gate
# would fail on every run and get switched off.  What it is for is
# turning "build unrar" into a NAMED LIST of missing library pieces,
# on the host, before anyone spends a VM rebuild on it.
#
# It works the way `cxxlib-host.sh' does and for the same reason: with
# the implementation namespace renamed to `std', `sys/include/ape/c++'
# is a REPLACEMENT standard library, so `g++ -nostdinc++' puts it in
# exactly cpfe's position.
#
# ---- WHAT IT IS SOUND FOR -------------------------------------------
#
# **The question "does our C++ library have this name".**  That is a
# NAME question and the two compilers must agree on names, which is
# the same bargain the `extern "C"' A/B struck.
#
# **It is NOT sound for**: cpfe's own acceptance (g++ and cpfe differ,
# and `move_algo.h' was already one case where cpfe is right and g++
# lenient), the C side (these compile against the HOST's `<unistd.h>'
# and friends, not APE's), the link, or anything at run time.
#
# ---- FOUR THINGS THAT MADE EARLIER RUNS OF THIS WRONG ----------------
#
# Each cost a measurement that read like a result:
#
# 1. **The four cpfe predefines.**  Without them every file fails on
#    `__EDG_SIZE_TYPE__ does not name a type' and the run measures the
#    harness.  `cxxlib-host.sh' already knew them; the ad-hoc command
#    did not.
# 2. **The include scan missed `.hpp'.**  A first survey globbed
#    `*.cpp -o *.h -o *.cc' and concluded "unrar needs nothing we do
#    not have" -- while every unrar header is `.hpp' and the real
#    answer was `<deque>'.
# 3. **Not every `.cpp' is a translation unit.**  unrar `#include's
#    `arccmt.cpp', `win32stm.cpp' and others INTO other files, so
#    compiling `*.cpp' reports 38 failures that are all
#    `wchar does not name a type' at line 1.  The object list comes
#    from the package's own makefile.
# 4. **The package's own `-D' set.**  Without `DEFINES' from the
#    makefile the platform arms are wrong and the errors are about
#    Windows code.
#
# ---- WHAT IT FOUND -------------------------------------------------
#
# ***unrar BUILDS CLEAN: 49 objects, 0 failures, no stubbed header.***
# It was **39 of 44** on the first run, then 42, then 43, then 44 --
# four rounds, each one library gap, and the walk is worth more than
# the number:
#
#   39 -> 42  `std::to_wstring' (and six silent miscompiles under it)
#   42 -> 43  `<stdexcept>' was EMPTY and its classes were TEMPLATES
#   43 -> 44  `basic_string(InputIt, InputIt)' copied a BLOCK
#   44        `<deque>' -- unused in unrar, so the include is dropped
#
# *Every one of the four was the library's and not unrar's*, which is
# the result this harness existed to get.
#
# ***AND THEN 44 TURNED OUT TO BE 49.***  The fifth harness fault, and
# the same shape as the other four: it read `OBJECTS=' while the
# makefile's link rule is `unrar: $(OBJECTS) $(UNRAR_OBJ)'.  Five
# files -- `filestr recvol rs scantree qopen' -- had never been
# compiled, and `-DUNRAR' had never been passed either, because that
# arrives as `-D$(WHAT)' in the compile rule and not through
# `DEFINES='.  All five compile and the define changes nothing here,
# so the finding is about the harness; *but a clean 44 was being read
# as "the package builds", and it was not the package.*
#
# ***AND THE GAP IT NAMED WAS NOT THE BUG IT FOUND.***  `to_wstring'
# looked like six wrappers over the generic `to_string2<t_string>'
# already in `string/to_string2.h', and it is -- but that file had
# never been included by anything, so compiling it for the first time
# found `convert.h' using `uint32_t' with nothing declaring it, and
# then running it found **six places in `basic_string' and its storage
# that pass an ELEMENT count where `memcpy' wants BYTES**.  Every one
# is correct for `char' and wrong for `wchar_t', `char16_t' and
# `char32_t', so the whole library was green over it.
# `sys/lib/tests/cxx-wstring-test.cpp' is the test; its control
# against the pre-fix headers gives 21 failures.
#
# *The harness was built to name missing NAMES and what it was worth
# was a silent miscompile two layers underneath one.*
#
# ***AND TWO OF THE FOUR WERE SILENT, WHICH IS WHAT A COMPILE-ONLY
# HARNESS CANNOT SEE BY ITSELF.***  `to_wstring' named a missing NAME
# and what it was worth was six places in `basic_string' passing an
# ELEMENT count where `memcpy' wants BYTES -- every one correct for
# `char', so the whole library was green over it.  The iterator-pair
# constructor `to_address'ed the first element and copied a block,
# which for a `list' iterator read 66 bytes of the wrong memory at
# the right length.  **Neither was found by this harness**: it named
# the loud half and the tests
# (`cxx-wstring-test.cpp', `cxx-striter-test.cpp') found the rest.
# *A package that COMPILES has not been shown to RUN*, which is the
# same rule as "a header that compiles is not a template that
# instantiates", one level up.
#
# `<deque>' was the fourth and is the one fixed in unrar rather than
# in the library: `deque' appears NOWHERE ELSE in the package -- not
# one `std::deque' -- so the include was unused and dropping it is
# cheaper than shipping a `<deque>' that declares nothing, which is
# precisely what EDG's empty `<stdexcept>' did to this port.  A real
# deque is a library decision and is in 0.6's inventory.
#
# **What is NOT measured by any of this**: the link, the C side (these
# compile against the HOST's `<unistd.h>'), cpfe's own acceptance, and
# anything at run time.  unrar's mkfile for Plan 9 does not exist yet.

set -u

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../../.." && pwd)
if [ ! -f "$ROOT/CLAUDE.md" ]; then
	echo "cxxapp-host: ROOT=$ROOT is not the repository root -- fix the" >&2
	echo "cxxapp-host: dirname count.  This directory is FOUR levels below" >&2
	echo "cxxapp-host: the root; the guard has fired five times in this tree." >&2
	exit 2
fi

CXXDIR=$ROOT/sys/include/ape/c++
APPS=$ROOT/sys/src/external/c++
command -v g++ >/dev/null 2>&1 || { echo "cxxapp-host: no g++" >&2; exit 2; }
[ -d "$CXXDIR" ] || { echo "cxxapp-host: no $CXXDIR" >&2; exit 2; }

OUT=${TMPDIR:-/tmp}/cxxapp-host.$$
mkdir -p "$OUT/shim" || exit 2
trap 'rm -rf "$OUT"' EXIT

# The four predefines cpfe has and gcc has not.  Copied from
# cxxlib-host.sh, which carries the reasoning.
EDGDEF="-D__EDG_RUNTIME_USES_NAMESPACES=1 -D__EDG_STD_NAMESPACE=std"
EDGDEF="$EDGDEF -D__EDG_CONSTEXPR_ENABLED__=1"
EDGDEF="$EDGDEF -D__EDG_SIZE_TYPE__=decltype(sizeof(0))"

# cpfe finds `<algorithm>' as `algorithm.stdh' and the plain name is a
# DIRECTORY, so the extensionless forwarders are staged for g++.
for s in "$CXXDIR"/*.stdh; do
	b=$(basename "$s" .stdh)
	printf '#include "%s"\n' "$s" > "$OUT/shim/$b"
done
for h in new exception stdexcept typeinfo; do
	[ -f "$OUT/shim/$h" ] && continue
	[ -f "$CXXDIR/$h.h" ] && printf '#include "%s"\n' "$CXXDIR/$h.h" > "$OUT/shim/$h"
done

headers_wanted() {		# $1 = package dir
	find "$1" -type f \( -name '*.cpp' -o -name '*.cc' -o -name '*.cxx' \
		-o -name '*.h' -o -name '*.hpp' -o -name '*.hxx' -o -name '*.re' \) \
		-print0 2>/dev/null \
	| xargs -0 grep -ho '#include[ 	]*<[a-z_0-9]*>' 2>/dev/null \
	| sed 's/.*<//;s/>//' | sort -u
}

have_headers() {
	for s in "$CXXDIR"/*.stdh; do basename "$s" .stdh; done | sort
}

if [ "${1:-}" = "--headers" ]; then
	for p in "$APPS"/*/; do
		n=$(basename "$p")
		headers_wanted "$p" > "$OUT/want"
		have_headers > "$OUT/have"
		echo "$n: wants $(wc -l < "$OUT/want"), missing:"
		echo "   $(comm -23 "$OUT/want" "$OUT/have" | tr '\n' ' ')"
	done
	exit 0
fi

compile_pkg() {			# $1 = package name; echoes "ok fail"
	d=$APPS/$1
	[ -d "$d" ] || { echo "cxxapp-host: no package $1" >&2; exit 2; }
	# The object list and the defines come from the package's OWN
	# makefile -- see note 3 and note 4 above.
	#
	# ***THE OBJECT LIST IS IN THE LINK RULE, NOT IN THE VARIABLE THAT
	# LOOKS LIKE IT.***  This read `OBJECTS=' and reported 44 of
	# unrar's files for four rounds; the makefile's rule is
	#
	#	unrar:	$(OBJECTS) $(UNRAR_OBJ)
	#
	# and `UNRAR_OBJ' is five more -- `filestr recvol rs scantree
	# qopen'.  *A variable named OBJECTS in a makefile with a second
	# object variable is a trap the name itself sets*, and the only
	# place that cannot lie is the rule that builds the program.  So
	# the rule is found by the package's own NAME (the directory's),
	# every `$(VAR)' in its prerequisites is expanded, and `OBJECTS'
	# alone is the FALLBACK -- announced when taken, because a silent
	# fallback to the old behaviour is the bug coming back.
	#
	# A logical line, continuations and all: an earlier version used a
	# plain `sed -n s/^OBJECTS=//p' and took only the first PHYSICAL
	# line -- 9 objects of 44, reported as a clean "9 failed".
	expand_var() {		# $1 = makefile, $2 = variable name
		awk -v v="$2" '
			$0 ~ "^"v"=" {o=1}
			o {print; if ($0 !~ /\\$/) exit}
		' "$1" 2>/dev/null | tr -d '\\' | sed "s/^$2=//"
	}
	lrule=$(awk -v t="$1" '$0 ~ "^"t":" {print; exit}' "$d/makefile" 2>/dev/null)
	lvars=$(printf '%s\n' "$lrule" | grep -o '\$([A-Za-z_][A-Za-z_0-9]*)' \
		| tr -d '$()' | sort -u)
	if [ -z "$lvars" ]; then
		echo "  no '$1:' link rule in $1/makefile -- falling back to OBJECTS=" >&2
		lvars=OBJECTS
	fi
	objs=$(for v in $lvars; do expand_var "$d/makefile" "$v"; done \
		| tr ' \t' '\n' | grep '\.o$' | sed 's/\.o$/.cpp/' | sort -u)
	# ***AND `-DUNRAR' IS NOT IN `DEFINES'.***  unrar's compile rule is
	# `$(COMPILE) -D$(WHAT) -c $<' with `WHAT=UNRAR', so the define
	# that selects the whole program arrives through a SECOND variable
	# and a reader looking at `DEFINES=' never sees it.  Every `-D$(V)'
	# anywhere in the makefile is expanded here for that reason.
	defs=$(expand_var "$d/makefile" DEFINES)
	for v in $(grep -o '\-D\$([A-Za-z_][A-Za-z_0-9]*)' "$d/makefile" 2>/dev/null \
			| sed 's/^-D//' | tr -d '$()' | sort -u); do
		dv=$(expand_var "$d/makefile" "$v" | tr -d ' \t')
		[ -n "$dv" ] && defs="$defs -D$dv"
	done
	if [ -z "$objs" ]; then
		echo "cxxapp-host: no object list for $1 -- neither a '$1:' rule" >&2
		echo "cxxapp-host: nor OBJECTS=, so which .cpp files are" >&2
		echo "cxxapp-host: translation units is unknown (note 3)." >&2
		exit 2
	fi
	# ***AND IF THIS TREE HAS AN mkfile FOR THE PACKAGE, THE TWO LISTS
	# MUST AGREE.***  `sys/src/ape/c++/<pkg>/mkfile' writes its
	# `OFILES' out by hand, so it and the list derived here are two
	# readings of the same makefile -- and the whole reason this
	# function changed is that one such reading was wrong for four
	# rounds.  `gd-xcheck.sh' already gates on exactly this shape
	# (`Makefile.am' against `lib/gd/mkfile'), for the same reason:
	# *two derivations of one list that disagree means one of them is
	# wrong, and neither says which.*  Reported here and required by
	# `--control'.
	# A MARKER FILE and not a variable: `compile_pkg' runs inside
	# `$(...)' so every assignment it makes dies with the subshell,
	# which is the same boundary that already cost this harness an
	# `exit 2' nobody saw (see `report').  `$OUT' is shared, so a file
	# crosses it.
	rm -f "$OUT/objdrift"
	mkf=$ROOT/sys/src/ape/c++/$1/mkfile
	if [ -f "$mkf" ]; then
		awk '/^OFILES=/{o=1;next} o{if($0 !~ /\\$/) exit; print}' "$mkf" \
			| tr -d '\\\t ' | grep '\.o$' | sed 's/\.o$/.cpp/' \
			| sort -u > "$OUT/mkobjs"
		printf '%s\n' "$objs" | sort -u > "$OUT/upobjs"
		if ! cmp -s "$OUT/mkobjs" "$OUT/upobjs"; then
			: > "$OUT/objdrift"
			echo "  *** OFILES DRIFT: $mkf and the makefile's link rule" >&2
			echo "  *** disagree.  mkfile only:" \
			     "$(comm -23 "$OUT/mkobjs" "$OUT/upobjs" | tr '\n' ' ')" >&2
			echo "  *** makefile only:" \
			     "$(comm -13 "$OUT/mkobjs" "$OUT/upobjs" | tr '\n' ' ')" >&2
		fi
	fi
	# ***MISSING HEADERS ARE STUBBED, AND THE STUB IS ANNOUNCED.***
	# Without this the first absent header stops every file and the
	# run reports one error forever -- which says nothing about what
	# ELSE is missing, and that is the whole question.  A stub that is
	# not declared would be far worse than no stub: see this tree's
	# standing complaint about things that answer without saying so.
	stubbed=
	for h in $(headers_wanted "$d"); do
		[ -f "$OUT/shim/$h" ] && continue
		[ -f "$CXXDIR/$h.h" ] && continue
		printf '/* cxxapp-host STUB: the library has no <%s> */\n' "$h" \
			> "$OUT/shim/$h"
		stubbed="$stubbed $h"
	done
	# to stderr: this function's stdout is CAPTURED for the counts
	[ -n "$stubbed" ] && echo "  STUBBED (library has no such header):$stubbed" >&2

	ok=0; bad=0; : > "$OUT/err"; : > "$OUT/fails"
	for b in $objs; do
		[ -f "$d/$b" ] || continue
		if g++ -std=c++14 -fsyntax-only -w -nostdinc++ $EDGDEF $defs \
			-I "$OUT/shim" -I "$CXXDIR" -I "$d" "$d/$b" 2>>"$OUT/err"
		then ok=$((ok + 1)); else bad=$((bad + 1)); echo "$b" >> "$OUT/fails"; fi
	done
	echo "$ok $bad"
}

report() {			# $1 = package name
	# `compile_pkg' runs in a subshell, so its `exit 2' leaves only the
	# subshell and the counts come back EMPTY -- which then read as
	# `$2: parameter not set' several lines later, in a place that has
	# nothing to do with the cause.  Checked here instead.
	name=$1
	set -- $(compile_pkg "$name")
	if [ $# -ne 2 ]; then
		echo
		echo "$name: NOT MEASURED (see the message above)"
		return 0
	fi
	ok=$1; bad=$2
	echo
	echo "$name: $ok objects compiled, $bad failed"
	[ "$bad" -eq 0 ] && return 0
	echo "  failing: $(tr '\n' ' ' < "$OUT/fails")"
	echo "  std names the library does not have:"
	grep -oP "error: '\K[A-Za-z_][A-Za-z_0-9]*(?=' is not a member of 'std')" \
		"$OUT/err" 2>/dev/null | sort | uniq -c | sed 's/^/    /'
	echo "  other distinct errors:"
	grep -oP 'error: .*' "$OUT/err" \
		| grep -v "is not a member of 'std'" \
		| sed 's/[0-9][0-9]*/N/g' | sort -u | cut -c1-96 | head -6 | sed 's/^/    /'
	return 0
}

if [ "${1:-}" = "--control" ]; then
	# ***THE FIRST VERSION OF THIS CONTROL NAMED ONE GAP AND SO HAD TO
	# BE RE-POINTED EVERY TIME ONE WAS FIXED.***  It required the
	# harness to still report `std::to_wstring' as missing; `to_wstring'
	# was then added, the control failed, and what it was reporting was
	# a success.  *A control made of a single real finding expires the
	# moment the finding is fixed* -- and the next reader cannot tell
	# "fixed" from "harness broke", which is exactly what a control is
	# for.
	#
	# It asked STRUCTURALLY instead -- a compile FLOOR plus "a gap is
	# still named" -- and ***THAT SECOND HALF THEN EXPIRED TOO, ONE
	# ROUND LATER AND EXACTLY AS IT SAID IT WOULD.***  unrar reached
	# 44 of 44 with no header stubbed, so there was no gap left to
	# require, and the control printed its own "this may be good news"
	# branch and exited 1.
	#
	# **So it asserts the MEASURED STATE now, which is the strongest
	# form available and the one a clean package allows.**  unrar
	# builds clean: 49 objects, 0 failures, no stubbed header.  A
	# regression in the library fails this; a new unrar object does
	# not, since the floor is `>=' and not `=='.
	#
	# ***THE NUMBER WAS 44 AND THAT WAS THE HARNESS, NOT THE
	# PACKAGE.***  It read `OBJECTS=' while the link rule is
	# `unrar: $(OBJECTS) $(UNRAR_OBJ)', so five files were never
	# compiled -- and the control had been asserting the wrong total
	# as a clean result.  *A floor is only as good as what it counts.*
	#
	# *The lesson is the one the first version already carried and the
	# second only half took*: a control made of a FINDING expires when
	# the finding is fixed, and the honest move each time is to
	# re-point it at what is now true rather than to loosen it.  What
	# changes here is that the thing now true is a RESULT, so the
	# control has become a regression gate on it.
	MINOK=49
	set -- $(compile_pkg unrar 2>"$OUT/ctl.err")
	if [ $# -ne 2 ]; then
		echo "cxxapp-host: ***THE CONTROL DID NOT RUN.***  compile_pkg gave" >&2
		echo "cxxapp-host: no counts; see the message above." >&2
		exit 1
	fi
	ok=$1; bad=$2
	echo "control: unrar $ok compiled, $bad failed"
	if [ "$ok" -lt "$MINOK" ] || [ "$bad" -ne 0 ]; then
		echo "cxxapp-host: ***THE CONTROL FIRED.***  unrar built clean when" >&2
		echo "cxxapp-host: this was written -- $MINOK objects, 0 failures -- and" >&2
		echo "cxxapp-host: now answers $ok/$bad.  Either the library regressed," >&2
		echo "cxxapp-host: or the harness, the staged shim or the cpfe" >&2
		echo "cxxapp-host: predefines broke.  Run without --control: a harness" >&2
		echo "cxxapp-host: fault fails EVERY object, a library regression a few." >&2
		exit 1
	fi
	if grep -q 'STUBBED' "$OUT/ctl.err"; then
		echo "cxxapp-host: ***THE CONTROL FIRED.***  A header was stubbed," >&2
		echo "cxxapp-host: and unrar needed none when this was written.  A" >&2
		echo "cxxapp-host: stub makes every later count optimistic, so the" >&2
		echo "cxxapp-host: 0 failures above cannot be read." >&2
		exit 1
	fi
	if [ -f "$OUT/objdrift" ]; then
		echo "cxxapp-host: ***THE CONTROL FIRED.***  This tree's own" >&2
		echo "cxxapp-host: sys/src/ape/c++/unrar/mkfile and upstream's link" >&2
		echo "cxxapp-host: rule name different object sets; the lines above" >&2
		echo "cxxapp-host: say which.  One of the two readings is wrong and" >&2
		echo "cxxapp-host: neither says which, so the count means nothing." >&2
		exit 1
	fi
	echo "control: unrar still builds clean, $ok objects and no stubbed header"
	exit 0
fi

if [ $# -gt 0 ]; then
	report "$1"
else
	for p in "$APPS"/*/; do
		n=$(basename "$p")
		[ -f "$p/makefile" ] || { echo; echo "$n: no makefile, skipped"; continue; }
		report "$n"
	done
fi
exit 0
