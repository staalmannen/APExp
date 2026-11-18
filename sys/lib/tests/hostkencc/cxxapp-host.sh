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
# unrar, 44 objects: **39 compile, 5 fail, and the failures are two
# library gaps rather than anything of unrar's.**
#
#   * `std::to_wstring' -- 10 sites.  **The implementation is already
#     there**: `string/to_string2.h' has a generic
#     `to_string2<t_string>', so this is six inline wrappers over
#     upstream's own machinery and not new code.
#   * `basic_string(InputIt, InputIt)' -- `win32stm.cpp:240' is
#     `std::string Src(v.begin(), v.end())' with `unsigned char*'
#     iterators, and the iterator-pair constructor does not take it
#     (`enable_if_bool_constant<false>', then a cascade onto the
#     `(const char *, size_type, allocator)' overload).
#
# `<deque>' is a third gap and a smaller one than it looks: unrar
# includes it in `os.hpp' and **never names `std::deque' anywhere**.

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
	# The LOGICAL line, continuations and all.  A first version used a
	# plain `sed -n s/^OBJECTS=//p' and took only the first physical
	# line -- 9 objects of 44, reported as a clean "9 failed".
	objs=$(awk '/^OBJECTS=/{o=1} o{print; if ($0 !~ /\\$/) exit}' "$d/makefile" 2>/dev/null \
		| tr -d '\\' | sed 's/^OBJECTS=//' | tr ' \t' '\n' \
		| grep '\.o$' | sed 's/\.o$/.cpp/' | sort -u)
	defs=$(sed -n 's/^DEFINES=//p' "$d/makefile" 2>/dev/null)
	if [ -z "$objs" ]; then
		echo "cxxapp-host: no OBJECTS in $1/makefile -- cannot tell which" >&2
		echo "cxxapp-host: .cpp files are translation units (note 3)." >&2
		exit 2
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
	# ***AN EXTERNAL CONTROL, AND IT WILL NEED RE-POINTING.***  There
	# is no oracle for "which names is the library missing", so the
	# control is that the harness must still see a gap we KNOW is
	# there.  `to_wstring' is that gap today.  **When it is added, this
	# control starts failing and must be aimed at the next known gap**
	# -- which is the honest cost of a control made of a real finding
	# rather than a planted one, and is why it says so here.
	compile_pkg unrar > /dev/null
	if grep -q "'to_wstring' is not a member of 'std'" "$OUT/err"; then
		echo "control: the harness still reports the known to_wstring gap"
		exit 0
	fi
	echo "cxxapp-host: ***THE CONTROL DID NOT FIRE.***  Either to_wstring" >&2
	echo "cxxapp-host: was added -- in which case re-point this control at" >&2
	echo "cxxapp-host: the next known gap -- or the harness stopped" >&2
	echo "cxxapp-host: compiling anything, which looks identical here." >&2
	exit 1
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
