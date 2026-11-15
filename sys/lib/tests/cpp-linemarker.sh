#!/bin/sh
#
# cpp-linemarker.sh -- which `#line' / `# N' forms does kencc's cpp take?
#
#	sh cpp-linemarker.sh            # assert, exits with the failure count
#	sh cpp-linemarker.sh --control  # put the bug back; the flagged forms
#	                                # must then be REFUSED
#
# A HOST cross-check: it builds `sys/src/cmd/cpp' with gcc, exactly as
# `cpp-xcheck/' does and for the same reason -- cpp needs eleven Plan 9
# names and nothing else, so preprocessor questions cost a local run
# instead of a VM round trip.
#
# ***WHY THIS IS NOT A `cpp-xcheck.sh' CASE FILE, WHICH WAS TRIED
# FIRST.*** That harness diffs kencc's output against `gcc -E -P', and
# `-P' is exactly the flag that SUPPRESSES line markers -- while kencc's
# cpp has no `-P' and writes its own.  So a case file made of line
# directives differs by construction, in every line, however correct
# both preprocessors are.  *A comparison whose two sides are asked
# different questions cannot be read*, and the shape to recognise is
# that the diff was 100% noise rather than 1 line of signal.
#
# ***WHERE THE BUG CAME FROM.***  With EDG's short allocation fixed,
# cpfe stopped crashing and `cc -c' reached its OUTPUT for the first
# time -- and answered `Syntax error in #line' once per header switch.
# `c_gen_be.c:782' builds the directive from the literal `"#line "',
# sets `buf[1]' to a SPACE for a gcc-or-clang target so it becomes
# `# N', and appends gcc's system-header flag after the file name.
# kencc's cpp rejected any token after the name.  *A fix that makes a
# process reach code it never reached before can expose anything on
# that path.*
#
# The flags are gcc's -- 1 enter, 2 return, 3 system header, 4
# `extern "C"' -- and **none is acted on**, which is what a compiler
# that is not gcc should do with them.  Section 3 is there because
# skipping them must not also skip the FILE NAME: a run that accepted
# everything and recorded nothing would pass sections 1 and 2.
#
# ***THE NEGATIVES ARE HALF THE TEST.***  A one-line "accept anything
# after the number" would pass every case in section 1 and is wrong;
# section 2 is what separates the fix from that.

set -u

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../.." && pwd)
if [ ! -f "$ROOT/CLAUDE.md" ]; then
	echo "cpp-linemarker: ROOT=$ROOT is not the repository root -- fix the" >&2
	echo "cpp-linemarker: dirname count.  sys/lib/tests is THREE levels" >&2
	echo "cpp-linemarker: below the root; this guard has fired five times." >&2
	exit 2
fi

SRC=$ROOT/sys/src/cmd/cpp
P9=$HERE/cpp-xcheck/p9
[ -d "$P9" ] || { echo "cpp-linemarker: no $P9" >&2; exit 2; }
command -v gcc >/dev/null 2>&1 || { echo "cpp-linemarker: no gcc" >&2; exit 2; }

OUT=${TMPDIR:-/tmp}/cpp-linemarker.$$
mkdir -p "$OUT" || exit 2
trap 'rm -rf "$OUT"' EXIT

CONTROL=""
case "${1:-}" in
"")		;;
--control)	CONTROL=1 ;;
*)		echo "cpp-linemarker: unknown argument $1" >&2; exit 2 ;;
esac

SRCDIR=$SRC
if [ -n "$CONTROL" ]; then
	# THE CONTROL IS A DELIBERATE BREAK.  There is no oracle for "what
	# should this preprocessor accept", so the only way to show the
	# check can fail is to remove the fix: delete the loop that skips
	# the flags and the flagged forms must come back as errors.
	mkdir -p "$OUT/broken"
	cp "$SRC"/*.c "$SRC"/*.h "$OUT/broken/" 2>/dev/null
	sed 's/^\t\t\twhile (ftp+1<trp->lp \&\& ftp->type==NUMBER)$/\t\t\twhile (0)/' \
		"$SRC/cpp.c" > "$OUT/broken/cpp.c"
	if cmp -s "$SRC/cpp.c" "$OUT/broken/cpp.c"; then
		echo "cpp-linemarker: the control's sed matched NOTHING -- the" >&2
		echo "cpp-linemarker: source has moved and the control is void." >&2
		exit 2
	fi
	SRCDIR=$OUT/broken
	echo "cpp-linemarker: CONTROL -- the flag-skipping loop is removed"
fi

gcc -w -O1 -I "$P9" -I "$SRCDIR" -o "$OUT/kcpp" "$SRCDIR"/*.c "$P9/shim.c" || exit 2

objtype=${objtype:-amd64}; export objtype

fails=0
run() {				# run <directive>; prints cpp's diagnostics
	printf '%s\nint x;\n' "$1" > "$OUT/case.c"
	"$OUT/kcpp" "$OUT/case.c" 2>&1 >/dev/null | grep -v 'Unknown \$objtype'
}

echo
echo "-- section 1: forms that MUST be accepted"
for f in \
	'#line 50 "a.cpp"' \
	'#line 50' \
	'# 50 "a.cpp"' \
	'# 50' \
	'#line 50 "a.cpp" 3' \
	'# 50 "a.cpp" 1' \
	'# 50 "a.cpp" 3 4' \
	'# 50 "a.cpp" 1 2 3 4'
do
	if [ -z "$(run "$f")" ]; then
		echo "PASS  accepted   $f"
	else
		echo "FAIL  REFUSED    $f"
		fails=$((fails + 1))
	fi
done

echo
echo "-- section 2: forms that MUST be refused"
for f in \
	'#line' \
	'#line "a.cpp"' \
	'# 50 "a.cpp" x' \
	'# 50 L"a.cpp"'
do
	if [ -n "$(run "$f")" ]; then
		echo "PASS  refused    $f"
	else
		echo "FAIL  ACCEPTED   $f"
		fails=$((fails + 1))
	fi
done

echo
echo "-- section 3: the position is still RECORDED, flags or not"
# `#warning' reports through the same `cursource' the directive sets, so
# it reads back both halves at once.  **Both arms are needed**: a fix
# that skipped the whole tail would leave the file name unset and still
# pass sections 1 and 2.
for f in '# 700 "zz.h" 3' '# 700 "zz.h"' '#line 700 "zz.h" 3'; do
	printf '%s\n#warning here\n' "$f" > "$OUT/case.c"
	got=$("$OUT/kcpp" "$OUT/case.c" 2>&1 >/dev/null \
		| grep -v 'Unknown \$objtype' | sed 's/.*cpp: //;s/ #warning.*//')
	if [ "$got" = "zz.h:700" ]; then
		echo "PASS  zz.h:700   $f"
	else
		echo "FAIL  got '$got', want 'zz.h:700'   $f"
		fails=$((fails + 1))
	fi
done

echo
if [ -n "$CONTROL" ]; then
	if [ "$fails" -eq 0 ]; then
		echo "cpp-linemarker: ***THE CONTROL PASSED, WHICH IS A FAILURE.***"
		echo "cpp-linemarker: with the flag-skipping loop removed the flagged"
		echo "cpp-linemarker: forms must be refused, and this run saw none."
		exit 1
	fi
	echo "cpp-linemarker: control reported $fails failures -- the check can"
	echo "cpp-linemarker: see the bug it was written for."
	exit 0
fi

echo "cpp-linemarker: $fails failures"
exit "$fails"
