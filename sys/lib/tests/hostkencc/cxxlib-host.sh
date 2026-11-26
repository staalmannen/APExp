#!/bin/sh
# cxxlib-host.sh -- compile APExp's C++ library headers with g++ on the
# build host.
#
#	sh cxxlib-host.sh                 # compile cxx-library-test.cpp
#	sh cxxlib-host.sh --portable      # ... forcing the no-builtin arms
#	sh cxxlib-host.sh --headers       # each public header on its own
#	sh cxxlib-host.sh --run           # ... and RUN it
#	sh cxxlib-host.sh --control       # MUST fire
#	sh cxxlib-host.sh --vecsplit      # regenerate cxx-vecsplit.cuts
#
# A HOST instrument: g++ on the build host, never the VM.
#
# ------------------------------------------------------------------
# WHY IT CAN EXIST AT ALL, which is not obvious.
#
# `sys/include/ape/c++' is Paragon Portable STL with its implementation
# namespace renamed to `std'.  That makes it a REPLACEMENT standard
# library rather than an addition -- so `g++ -nostdinc++' pointed at it
# compiles it as the one and only `std', which is exactly the position
# cpfe puts it in.  Nothing about it needs Plan 9: it is header-only
# C++14 over the C library, and glibc serves the C half.
#
# ***THE ONE THING IN THE WAY IS THE FILE NAMES.***  cpfe finds
# `<algorithm>' as `algorithm.stdh' through its own
# `include_file_suffixes', and the plain name is already taken here by a
# DIRECTORY.  gcc has no such mechanism, so this script stages a shim
# directory of extensionless forwarders -- `algorithm' -> `#include
# ".../algorithm.stdh"' -- and puts it first.  *That is the whole of the
# adaptation*, and it is why the headers under test are the repository's
# own files rather than copies.
#
# WHAT IT IS SOUND FOR, stated rather than discovered later:
#
#   * EVERYTHING THAT IS NOT A COMPILER-IDENTITY ARM.  A missing type, a
#     name that does not exist, a using-declaration that collides, a
#     stray `template' keyword -- g++ answers those as well as cpfe and
#     in one second rather than one VM rebuild.
#   * THE PORTABLE ARMS, with `--portable', which defines
#     PSTL_NO_COMPILER_BUILTINS and so makes g++ take the same branches
#     cpfe takes.  **A plain run does NOT exercise them** -- g++ defines
#     `__GNUC__', so it takes the gcc arm of all four selectors.  Run
#     both; they are different questions.
#
# WHAT IT IS NOT SOUND FOR: anything about cpfe itself -- its C output,
# its template model, `--instantiate local', the ABI.  g++ is a second
# front end over one source, so a disagreement is a finding and an
# agreement is not a proof.  Same bargain as `hostkencc'.
# ------------------------------------------------------------------
set -u

HERE=$(cd "$(dirname "$0")" && pwd)
# `sys/lib/tests/hostkencc' is FOUR levels below the root, not three.
# The guard has now fired on seven files in this tree and been wrong in
# the same direction every time.
ROOT=$(cd "$HERE/../../../.." && pwd)
if [ ! -f "$ROOT/CLAUDE.md" ]; then
	echo "cxxlib-host: ROOT=$ROOT is not the repository root" >&2
	exit 2
fi
CXXDIR=$ROOT/sys/include/ape/c++
TEST=$ROOT/sys/lib/tests/cxx-library-test.cpp
[ -f "$CXXDIR/new.stdh" ] || { echo "cxxlib-host: no $CXXDIR/new.stdh" >&2; exit 2; }
[ -f "$TEST" ] || { echo "cxxlib-host: no $TEST" >&2; exit 2; }
command -v g++ >/dev/null 2>&1 || { echo "cxxlib-host: no g++" >&2; exit 2; }

OUT=${TMPDIR:-/tmp}/cxxlib-host
SHIM=$OUT/shim
rm -rf "$SHIM"
mkdir -p "$SHIM" || exit 2

# ---- stage the extensionless forwarders --------------------------
n=0
for s in "$CXXDIR"/*.stdh; do
	b=$(basename "$s" .stdh)
	printf '#include "%s"\n' "$s" > "$SHIM/$b"
	n=$((n + 1))
done
# A few names cpfe resolves to a plain `.h' in the same directory.
for h in new exception stdexcept typeinfo; do
	[ -f "$SHIM/$h" ] && continue
	[ -f "$CXXDIR/$h.h" ] || continue
	printf '#include "%s"\n' "$CXXDIR/$h.h" > "$SHIM/$h"
	n=$((n + 1))
done

# `--portable' and `--headers' COMBINE, and they have to: the portable
# arms are the ones cpfe takes, so "every header, portable arms" is the
# run that answers the VM's question.  A `$1'-only parser silently ran
# the first word and dropped the second.
# ---- --iostream: build and run the iostreams test, both arms ------
#
# ***THE REFERENCE ARM IS THE POINT OF THIS MODE.***  Every assertion in
# `cxx-iostream-test.cpp' is a STANDARD rule, so libstdc++ must pass the
# identical file -- which means a failure can be attributed to the
# library rather than argued about.  It earned itself on its first run:
# the test asserted the C++98 rule that a failed extraction leaves the
# caller's value alone, libstdc++ disagreed, and C++11 is why --
# [facet.num.get.virtuals] zeroes it.  *The test was wrong and the
# library had the same bug*, which only a second opinion separates.
#
# A second draft of one case was wrong the OTHER way, asserting that a
# failed `>>' into a string empties it: the erase is real but
# unreachable, because the sentry fails first on empty input.  Both are
# written down in the test.
#
# **The control breaks the library on purpose, twice**, because one
# break exercises one rule and a green run proves nothing by itself:
#
#   * `width()' not consumed      -> 2 failures (`left', `width applies
#                                    once'), and NOT the other sixty,
#                                    which is what says the breakage is
#                                    located rather than general.
#   * no `internal' prefix length -> 1 failure (`internal puts the sign
#                                    first').
#
# Each `sed' is checked for having matched, since a control whose
# pattern silently misses reports the unbroken tree as proof.
# ***AND THE REFERENCE ARM MUST BE BUILT `-DREFERENCE', WHICH BOTH
# MODES FIRST FORGOT.***  Without it libstdc++ compiles the APExp-ONLY
# section too.  For `--iostream' that section happens to hold for
# libstdc++ as well (`cerr' really is unitbuf, `cin' really is tied to
# `cout'), **so the arm passed and was not the arm it claimed to be** --
# a check passing for the wrong reason, invisible for as long as the two
# agreed.  `--deque' is what found it: its APExp-only section calls
# `make_deque' and `clone', which libstdc++ has not got, so the build
# failed outright instead of quietly succeeding.  *The loud case is the
# lucky one.*

# ---- --deque: build and run the container test, both arms --------
#
# Same two-arm shape as `--iostream': every assertion in sections 0 to 7
# of `cxx-deque-test.cpp' is a standard rule, so libstdc++ runs the
# identical file.  The ONE mechanical difference is hidden in the test's
# `PUSH()' macro, because APExp's `push_back' returns
# `expected<void, std_error>' where the standard returns `void' -- so
# both arms run the same statements rather than two sets believed to
# correspond.
#
# ***THE CONTROL READS THE EXIT STATUS AND NOT THE FAILURE COUNT, AND
# THAT IS THE LESSON OF ITS FIRST RUN.***  Two of the three breaks
# corrupt memory, so the test SEGFAULTS before printing a count -- and
# `grep -c FAIL' then answers **0**, which is exactly what a clean run
# prints.  *A control that crashes the thing it is testing reports the
# same number as a control that did not fire.*  So each break records
# what it should do:
#
#   raw() ignores m_start      -> CRASH (139), the index base is wrong
#   grow_map leaves m_start    -> CRASH (139), the map moves and the
#                                 offset does not
#   queue::pop takes the back  -> 1 countable failure, no crash
#
# The third is there so the COUNTING path is exercised too: three
# crashing controls would leave "the test can report a failure at all"
# untested.
deque_mode() {
	T=$ROOT/sys/lib/tests/cxx-deque-test.cpp
	if [ ! -f "$T" ]; then
		echo "cxxlib-host: no $T" >&2
		return 2
	fi
	rc=0
	if ! g++ -std=c++14 -DREFERENCE -o "$OUT/dqref" "$T" > "$OUT/err.dqref" 2>&1; then
		echo "cxxlib-host: deque REFERENCE arm did not build"
		sed -n '1,20p' "$OUT/err.dqref"
		return 1
	fi
	if "$OUT/dqref" > "$OUT/dqref.out" 2>&1; then
		echo "cxxlib-host: deque reference (libstdc++) -- 0 failures"
	else
		echo "cxxlib-host: deque reference (libstdc++) -- FAILURES:"
		grep FAIL "$OUT/dqref.out"
		rc=1
	fi
	if ! g++ $CXXFL -o "$OUT/dqape" "$T" > "$OUT/err.dqape" 2>&1; then
		echo "cxxlib-host: deque APExp arm did not build"
		sed -n '1,20p' "$OUT/err.dqape"
		return 1
	fi
	if "$OUT/dqape" > "$OUT/dqape.out" 2>&1; then
		echo "cxxlib-host: deque APExp headers -- 0 failures"
	else
		echo "cxxlib-host: deque APExp headers -- FAILURES:"
		grep FAIL "$OUT/dqape.out"
		rc=1
	fi
	return $rc
}

deque_control() {
	T=$ROOT/sys/lib/tests/cxx-deque-test.cpp
	DQ=$CXXDIR/containers/deque.h
	QU=$CXXDIR/containers/queue.h
	ok=0

	for which in rawbase mapstart queuepop; do
		case $which in
		rawbase)
			SRC=$DQ
			expr='s|return this->slot(m_start + i);|return this->slot(i);|'
			want=crash
			name='raw() ignores m_start' ;;
		mapstart)
			SRC=$DQ
			expr='s|    m_start += front_blocks \* block_size;||'
			want=crash
			name='grow_map leaves m_start' ;;
		queuepop)
			SRC=$QU
			expr='s|  void pop() { m_c.pop_front(); }|  void pop() { m_c.pop_back(); }|'
			want=1
			name='queue::pop takes the back' ;;
		esac
		cp "$SRC" "$OUT/ctl.orig" || return 2
		sed -i "$expr" "$SRC"
		if cmp -s "$SRC" "$OUT/ctl.orig"; then
			echo "control: the $which sed matched NOTHING -- FAILED"
			cp "$OUT/ctl.orig" "$SRC"
			ok=1
			continue
		fi
		got=build-failed
		if g++ $CXXFL -o "$OUT/dqctl" "$T" > "$OUT/err.dqctl" 2>&1; then
			if "$OUT/dqctl" > "$OUT/dqctl.out" 2>&1; then
				got=0
			else
				st=$?
				if [ "$st" -gt 128 ]; then
					got=crash
				else
					got=$(grep -c FAIL "$OUT/dqctl.out")
				fi
			fi
		fi
		cp "$OUT/ctl.orig" "$SRC"
		if [ "$got" = "$want" ]; then
			echo "control: $name -- $got, as recorded -- ok"
		else
			echo "control: $name -- $got, want $want -- FAILED"
			ok=1
		fi
	done
	return $ok
}

iostream_mode() {
	T=$ROOT/sys/lib/tests/cxx-iostream-test.cpp
	if [ ! -f "$T" ]; then
		echo "cxxlib-host: no $T" >&2
		return 2
	fi
	rc=0

	# the reference arm: the host's own standard library
	if ! g++ -std=c++14 -DREFERENCE -o "$OUT/ioref" "$T" > "$OUT/err.ioref" 2>&1; then
		echo "cxxlib-host: iostream REFERENCE arm did not build"
		sed -n '1,20p' "$OUT/err.ioref"
		return 1
	fi
	if "$OUT/ioref" > "$OUT/ioref.out" 2>&1; then
		echo "cxxlib-host: iostream reference (libstdc++) -- 0 failures"
	else
		echo "cxxlib-host: iostream reference (libstdc++) -- FAILURES:"
		grep FAIL "$OUT/ioref.out"
		rc=1
	fi

	# the subject arm: APExp's headers, cpfe's flags
	if ! g++ $CXXFL -o "$OUT/ioape" "$T" > "$OUT/err.ioape" 2>&1; then
		echo "cxxlib-host: iostream APExp arm did not build"
		sed -n '1,20p' "$OUT/err.ioape"
		return 1
	fi
	if "$OUT/ioape" > "$OUT/ioape.out" 2>&1; then
		echo "cxxlib-host: iostream APExp headers -- 0 failures"
	else
		echo "cxxlib-host: iostream APExp headers -- FAILURES:"
		grep FAIL "$OUT/ioape.out"
		rc=1
	fi
	return $rc
}

iostream_control() {
	T=$ROOT/sys/lib/tests/cxx-iostream-test.cpp
	SRC=$CXXDIR/io/ostream.h
	ok=0

	for which in width internal; do
		cp "$SRC" "$OUT/ostream.h.orig" || return 2
		if [ "$which" = width ]; then
			sed -i 's|^    this->width(0);$|    /* control */|' "$SRC"
			pat='this->width(0);'
			want=2
			name='width not consumed'
		else
			sed -i 's|put_ascii(buf, prefix_len(buf))|put_ascii(buf, 0)|g' "$SRC"
			pat='prefix_len(buf)'
			want=1
			name='no internal prefix'
		fi
		if cmp -s "$SRC" "$OUT/ostream.h.orig"; then
			echo "control: the $which sed matched NOTHING ($pat) -- FAILED"
			cp "$OUT/ostream.h.orig" "$SRC"
			ok=1
			continue
		fi
		if g++ $CXXFL -o "$OUT/ioctl" "$T" > "$OUT/err.ioctl" 2>&1; then
			"$OUT/ioctl" > "$OUT/ioctl.out" 2>&1
			n=$(grep -c FAIL "$OUT/ioctl.out")
		else
			n=-1
		fi
		cp "$OUT/ostream.h.orig" "$SRC"
		if [ "$n" = "$want" ]; then
			echo "control: $name -- $n failure(s), as recorded -- ok"
		else
			echo "control: $name -- $n failure(s), want $want -- FAILED"
			ok=1
		fi
	done
	return $ok
}


mode=""
PORT=""
for a in "$@"; do
	case "$a" in
	--portable) PORT="-DPSTL_NO_COMPILER_BUILTINS=1" ;;
	--headers|--control|--run|--vecsplit|--instantiate|--iostream|--deque) mode=$a ;;
	*) echo "cxxlib-host: unknown argument $a" >&2; exit 2 ;;
	esac
done

# ---- the predefined macros cpfe supplies and gcc does not ---------
# EDG's own `.stdh' files READ these; without them `class exception'
# lands in the GLOBAL namespace (`__EDG_RUNTIME_USES_NAMESPACES' guards
# the `namespace std {'), so every `: public ::std::exception' answers
# `expected class-name', and `<initializer_list>' cannot name `size_t'.
# **These stand in for cpfe's predefined macros and are the only place
# this harness asserts anything about the compiler** -- each is what
# cpfe defines, not a guess at what would make the build pass.
EDGDEF="-D__EDG_RUNTIME_USES_NAMESPACES=1"
EDGDEF="$EDGDEF -D__EDG_STD_NAMESPACE=std"
EDGDEF="$EDGDEF -D__EDG_CONSTEXPR_ENABLED__=1"
EDGDEF="$EDGDEF -D__EDG_SIZE_TYPE__=decltype(sizeof(0))"

# `-fno-exceptions -fno-rtti' because that is what `rc/bin/ape/eccp'
# passes by default and so the only configuration this port has ever
# exercised.  `-fpermissive' is NOT passed: a diagnostic gcc gives here
# is the point of the instrument.
SYN="-fsyntax-only"
# ***`--iostream' BUILDS AND RUNS, SO IT MUST CLEAR THIS TOO.***  With
# `-fsyntax-only' still in `CXXFL' the compile SUCCEEDS and emits no
# file, so the mode then fails to execute a binary that was never
# written -- and reported that as "APExp headers -- FAILURES:" with no
# failure lines under it.  *A missing binary and a failing test are not
# the same result*, and the empty list under the heading is the only
# thing that said so.
case "$mode" in
--run|--iostream|--deque) SYN="" ;;
esac
CXXFL="-std=c++14 -nostdinc++ -fno-exceptions -fno-rtti $SYN"
CXXFL="$CXXFL -I$SHIM -I$CXXDIR $EDGDEF $PORT"

run_one() {	# $1 = source, $2 = label
	if g++ $CXXFL "$1" > "$OUT/err.$2" 2>&1; then
		echo "cxxlib-host: ok    $2"
		return 0
	fi
	echo "cxxlib-host: ERROR $2 -- $(grep -c 'error:' "$OUT/err.$2") errors"
	grep 'error:' "$OUT/err.$2" | head -12 | sed 's/^/    /'
	return 1
}

case "$mode" in
--iostream)
	# Both arms, then the two deliberate breaks.  See `iostream_mode'
	# and `iostream_control' above for what each one is for.
	iostream_mode
	rc=$?
	iostream_control || rc=1
	exit $rc
	;;
--deque)
	deque_mode
	rc=$?
	deque_control || rc=1
	exit $rc
	;;
--instantiate)
	# ***A HEADER THAT COMPILES IS NOT A TEMPLATE THAT INSTANTIATES,
	# AND THIS MODE EXISTS BECAUSE THAT COST A ROUND.***
	#
	# `vector/split_buffer.h' carried three names from upstream put
	# through the rename with the wrong prefix -- `M_clear',
	# `M_M_alloc' (the prefix applied twice) and `M_end_cap', where
	# the members are `clear', `M_alloc' and `end_cap'.  They sit in
	# a nested class whose uses are on a `split_buffer &', a
	# DEPENDENT type, so both cpfe and g++ defer the lookup to
	# instantiation.
	#
	# **So neither `--headers' nor `--run' could see them**: the
	# first compiles each header alone, the second exercises the
	# public API and never instantiates that nested class.  cpfe
	# found them on the VM, which is the expensive way round.
	#
	# An explicit instantiation DEFINITION instantiates a class
	# template's member functions and member classes, so it reaches
	# code no use of the public API happens to touch.
	#
	# **It REPORTS and does not gate.**  Some of these templates are
	# exception-free by convention and have members that are
	# ill-formed to instantiate for an arbitrary argument; a gate
	# would demand changes that must not be made.  Read the names.
	fail=0
	ctlsrc=""
	for spec in \
		'std::split_buffer<int, std::allocator<int> >' \
		'std::vector<int, std::allocator<int> >' \
		'std::list<int, std::allocator<int> >' \
		'std::forward_list<int, std::allocator<int> >' \
		'std::array<int, 4>' \
	; do
		lbl=$(echo "$spec" | tr -cd 'A-Za-z0-9')
		[ -z "$ctlsrc" ] && ctlsrc="$OUT/inst.$lbl.cpp"
		{
			echo '#include <vector.stdh>'
			echo '#include <list.stdh>'
			echo '#include <forward_list.stdh>'
			echo '#include <array.stdh>'
			echo '#include <memory.stdh>'
			echo "template class $spec;"
			echo 'int main(void) { return 0; }'
		} > "$OUT/inst.$lbl.cpp"
		if g++ $CXXFL "$OUT/inst.$lbl.cpp" > "$OUT/inst.$lbl.err" 2>&1; then
			echo "cxxlib-host: ok    instantiate $spec"
		else
			fail=$((fail + 1))
			echo "cxxlib-host: ERROR instantiate $spec -- $(grep -c 'error:' "$OUT/inst.$lbl.err") errors"
			grep 'error:' "$OUT/inst.$lbl.err" | head -8 | sed 's/^/    /'
		fi
	done
	echo
	echo "cxxlib-host: $fail of 5 explicit instantiations failed (REPORT, not a gate)"

	# ***THE POSITIVE CONTROL, AND IT SEARCHES HISTORY RATHER THAN
	# `HEAD'.***  The three names it fires on are FIXED, so staging
	# `HEAD' would stage the fix and the control would pass for the
	# wrong reason -- `baketype-sweep.py' learnt this the same way.
	# It walks back for the last revision of the file that still
	# carries `M_M_alloc' and instantiates against that.
	rev=$(git -C "$ROOT" rev-list -n 60 HEAD -- sys/include/ape/c++/vector/split_buffer.h 2>/dev/null |
	      while read r; do
		if git -C "$ROOT" show "$r:sys/include/ape/c++/vector/split_buffer.h" 2>/dev/null |
		   grep -q 'M_M_alloc'; then echo "$r"; break; fi
	      done)
	if [ -z "$rev" ]; then
		echo "cxxlib-host: CONTROL VOID -- no revision of split_buffer.h carries M_M_alloc," >&2
		echo "cxxlib-host: so this cannot show that the check would fire." >&2
		exit 2
	fi
	rm -rf "$OUT/ctl"; mkdir -p "$OUT/ctl"
	cp -r "$CXXDIR"/. "$OUT/ctl/" || exit 2
	git -C "$ROOT" show "$rev:sys/include/ape/c++/vector/split_buffer.h" \
		> "$OUT/ctl/vector/split_buffer.h" || exit 2
	if g++ -std=c++14 -nostdinc++ -fno-exceptions -fno-rtti -fsyntax-only \
	       -I"$SHIM" -I"$OUT/ctl" $EDGDEF $PORT \
	       "$ctlsrc" > "$OUT/ctl.err" 2>&1; then
		echo "cxxlib-host: ***CONTROL PASSED, WHICH IS A FAILURE.***"
		echo "cxxlib-host: the pre-fix split_buffer.h from $rev instantiated cleanly,"
		echo "cxxlib-host: so this mode is not asking what it claims."
		exit 1
	fi
	# ***AND IT MUST BE THE RIGHT DIAGNOSTIC.***  The first version
	# of this control named the staged source by a hand-written
	# label that did not match the one the loop builds, so g++
	# answered `No such file or directory' -- a NON-ZERO exit, which
	# the test above reads as "the control fired".  *A control that
	# passes for the wrong reason is the failure this tree writes
	# down most often*, and it was caught by reading the output
	# rather than the status.  So the member name is demanded here.
	if ! grep -q 'M_M_alloc' "$OUT/ctl.err"; then
		echo "cxxlib-host: ***THE CONTROL FAILED FOR THE WRONG REASON.***"
		echo "cxxlib-host: it did not name M_M_alloc, so what it hit is not"
		echo "cxxlib-host: the rename slip this mode exists for:"
		head -4 "$OUT/ctl.err" | sed 's/^/    /'
		exit 1
	fi
	echo "cxxlib-host: control ($rev) reports $(grep -c 'error:' "$OUT/ctl.err") errors -- the mode fires:"
	grep 'error:' "$OUT/ctl.err" | head -4 | sed 's/^/    /'
	exit 0
	;;
--vecsplit)
	# Regenerate `sys/lib/tests/cxx-vecsplit.cuts': the points in
	# vector/vector.h at which it can be TRUNCATED and still
	# compile, as `LINE DEPTH' -- DEPTH closing braces are appended,
	# then `#endif' and a `main'.
	#
	# ***IT SPANS THE WHOLE FILE, INCLUDING THE INCLUDE BLOCK, AND
	# THE FIRST VERSION DID NOT.***  That one cut only at top-level
	# `template<' boundaries, so its shortest prefix was the ENTIRE
	# include block in one step -- and when that prefix CRASHED on
	# the VM there was nothing shorter to bisect against.  *A ladder
	# whose first rung already fails has no rungs.*
	#
	# **The validation is the point.**  Every candidate is compiled
	# by g++ before it is written down, so a rung that errors on the
	# VM means cpfe disagrees with g++ -- a finding -- instead of
	# meaning the harness cut in the wrong place, which is noise.
	python3 - "$ROOT" "$SHIM" "$CXXDIR" <<'PYEOF'
import pathlib, subprocess, sys
root, shim, cxxdir = (pathlib.Path(a) for a in sys.argv[1:4])
src = cxxdir / 'vector/vector.h'
lines = src.read_text().split('\n')

# Brace depth AND preprocessor-conditional depth, line by line,
# ignoring comments, strings and char literals.
depth = 0; ppdepth = 0; incomment = False
bdepths = []; ppdepths = []; isinc = []
for line in lines:
    st = line.lstrip()
    pp = st.startswith('#')
    bdepths.append(depth); ppdepths.append(ppdepth)
    # ***ANY INDENTATION.***  `vector.h' has two `#  include' lines
    # inside an `#if', and the first derivation of this list matched
    # `#include' at column 0 only -- so it reported 56 includes where
    # the file has 58, and never tested either of the two.
    isinc.append(bool(pp and st[1:].lstrip().startswith('include')))
    if pp:
        k = st[1:].lstrip().split(None, 1)[0] if st[1:].strip() else ''
        if k in ('if', 'ifdef', 'ifndef'): ppdepth += 1
        elif k == 'endif' and ppdepth: ppdepth -= 1
        continue
    s = []; j = 0
    while j < len(line):
        if incomment:
            x = line.find('*/', j)
            if x < 0: j = len(line); break
            incomment = False; j = x + 2; continue
        if line[j:j+2] == '/*': incomment = True; j += 2; continue
        if line[j:j+2] == '//': break
        if line[j] in '"\'':
            q = line[j]; j += 1
            while j < len(line) and line[j] != q:
                j += 2 if line[j] == '\\' else 1
            j += 1; continue
        s.append(line[j]); j += 1
    depth += ''.join(s).count('{') - ''.join(s).count('}')

# ***THE INCLUDE GUARD IS ITSELF AN OPEN `#if' FOR THE WHOLE FILE***,
# so a rule of "cut only where no conditional is open" rejects every
# line and the generator answers `0 candidates' -- a result-shaped
# non-result.  The BASELINE is the depth at the first `#include', and
# a cut must be at that depth: inside the guard and inside nothing
# else.  The trailer's single `#endif' then closes exactly the guard.
base = next((ppdepths[i] for i, y in enumerate(isinc) if y), 0)

cand = []
for i, l in enumerate(lines, 1):
    # prefix = lines 1..i.  Never inside a real `#if', or the trailer
    # would land in an unterminated conditional.
    if ppdepths[i-1] != base:
        continue
    after_inc = isinc[i-1]
    before_tmpl = (i < len(lines) and lines[i].startswith('template<')
                   and bdepths[i] == 1)
    if after_inc:
        cand.append((i, bdepths[i-1]))
    elif before_tmpl:
        cand.append((i, bdepths[i]))

tmp = pathlib.Path('/tmp/cxxlib-host'); tmp.mkdir(parents=True, exist_ok=True)
CXX = ['g++', '-std=c++14', '-nostdinc++', '-fno-exceptions', '-fno-rtti',
       '-fsyntax-only', '-I' + str(shim), '-I' + str(cxxdir),
       '-I' + str(cxxdir / 'vector'),
       '-D__EDG_RUNTIME_USES_NAMESPACES=1', '-D__EDG_STD_NAMESPACE=std',
       '-D__EDG_CONSTEXPR_ENABLED__=1',
       '-D__EDG_SIZE_TYPE__=decltype(sizeof(0))',
       '-DPSTL_NO_COMPILER_BUILTINS=1']
good = []
for ln, d in cand:
    body = ('\n'.join(lines[:ln]) + '\n' + ('}\n' * d)
            + '#endif\nint main(void){return 0;}\n')
    f = tmp / 'vs.cpp'; f.write_text(body)
    if subprocess.run(CXX + [str(f)], capture_output=True).returncode == 0:
        good.append((ln, d))
ninc = sum(1 for ln, d in good if d == 0)
hdr = ("""# cxx-vecsplit.cuts -- points in sys/include/ape/c++/vector/vector.h
# at which it can be TRUNCATED and still compile, as `LINE DEPTH'.
#
# GENERATED AND VALIDATED by `hostkencc/cxxlib-host.sh --vecsplit'.
# A cut `L D' means "lines 1..L, then D closing braces, then `#endif'
# and a `main'".  Do not edit by hand: regenerate.
#
# ***EVERY ONE WAS COMPILED BY g++ BEFORE IT WAS WRITTEN DOWN.***
# %d candidates, %d validated, %d of them inside the include block.
# The ones that fail are member templates -- two `template<...>'
# lines where a cut between them leaves a dangling header.  The list
# is the PROVEN set, so a rung that errors on the VM is cpfe
# disagreeing with g++ rather than the harness cutting wrongly.
#
# ***IT SPANS THE INCLUDE BLOCK, AND THE FIRST VERSION DID NOT.***
# That one cut only at top-level `template<' boundaries, so its
# shortest prefix was the whole include block in one step -- and that
# prefix CRASHED on the VM, leaving nothing shorter to bisect
# against.  A ladder whose first rung already fails has no rungs.
""" % (len(cand), len(good), ninc))
out = root / 'sys/lib/tests/cxx-vecsplit.cuts'
out.write_text(hdr + '\n'.join('%d %d' % g for g in good) + '\n')
print('cxxlib-host: %d candidates, %d validated (%d in the include block) -> %s'
      % (len(cand), len(good), ninc, out))
PYEOF
	exit $?
	;;
--run)
	# **THE SHIM FORWARDS TO ABSOLUTE PATHS**, so `-I' cannot
	# redirect this at a modified copy of the library: a control
	# staged in a temporary tree is simply not read, compiles
	# clean and reports PASS.  That happened on the first attempt
	# at the `make_integer_sequence' control below.  To break
	# something on purpose, edit the file IN THE REPOSITORY and
	# put it back -- there is no safe `-I' shortcut.
	if ! g++ $CXXFL -o "$OUT/cxx-library-test" "$TEST" > "$OUT/err.run" 2>&1; then
		echo "cxxlib-host: ERROR could not build the test"
		grep 'error:' "$OUT/err.run" | head -12 | sed 's/^/    /'
		exit 1
	fi
	"$OUT/cxx-library-test"
	exit $?
	;;
--control)
	# A deliberate break, because there is no external oracle for
	# "this library compiles".  ONE HALF IS NOT ENOUGH: a harness
	# that reported failure for everything would pass a break-only
	# control, so the current tree must also come back clean.
	brk=$OUT/control.cpp
	printf '#include <vector>\nint main(){ ::std::no_such_name_at_all x; return 0; }\n' > "$brk"
	if g++ $CXXFL "$brk" >"$OUT/err.control" 2>&1; then
		echo "cxxlib-host: CONTROL FAILED -- a bogus name compiled"
		exit 1
	fi
	echo "cxxlib-host: control 1/2 OK -- a bogus name is diagnosed"
	ok=$OUT/ok.cpp
	printf '#include <vector>\nint main(){ return 0; }\n' > "$ok"
	if ! g++ $CXXFL "$ok" >"$OUT/err.control2" 2>&1; then
		echo "cxxlib-host: CONTROL FAILED -- <vector> alone does not compile;"
		echo "cxxlib-host: a clean run would mean nothing.  First errors:"
		grep 'error:' "$OUT/err.control2" | head -8 | sed 's/^/    /'
		exit 1
	fi
	echo "cxxlib-host: control 2/2 OK -- <vector> alone compiles"
	exit 0
	;;
--headers)
	# One translation unit per public header, which is what
	# `cxx-bisect' does on the VM.  A combined run stops at the
	# first error limit and hides the rest.
	nerr=0
	for s in "$CXXDIR"/*.stdh; do
		b=$(basename "$s" .stdh)
		case "$b" in edg_internal_defines) continue ;; esac
		tu=$OUT/one.cpp
		printf '#include <%s>\n' "$b" > "$tu"
		run_one "$tu" "$b" || nerr=$((nerr + 1))
	done
	echo "cxxlib-host: $nerr of the public headers failed${PORT:+ (portable arms)}"
	[ "$nerr" = 0 ]
	exit $?
	;;
esac

echo "cxxlib-host: staged $n forwarders in $SHIM${PORT:+; portable arms forced}"
run_one "$TEST" cxx-library-test
