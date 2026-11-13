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
mode=""
PORT=""
for a in "$@"; do
	case "$a" in
	--portable) PORT="-DPSTL_NO_COMPILER_BUILTINS=1" ;;
	--headers|--control|--run|--vecsplit) mode=$a ;;
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
[ "$mode" = "--run" ] && SYN=""
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
--vecsplit)
	# Regenerate `sys/lib/tests/cxx-vecsplit.cuts': the line numbers
	# in vector/vector.h at which it can be TRUNCATED and still
	# compile.  **The validation is the point.**  The rule that
	# produces the candidates -- a `template<' at column 0 at brace
	# depth 1 -- gives 108 and 27 of them do not compile, because a
	# member template is two `template<...>' lines and a cut between
	# them leaves a dangling header.  Teaching the rule about that
	# case would be the wrong fix: the list is the set g++ PROVED
	# compiles, so a rung that errors on the VM means cpfe disagrees
	# with g++, which is a finding, instead of meaning the harness
	# cut in the wrong place, which is noise.
	python3 - "$ROOT" "$SHIM" "$CXXDIR" <<'PYEOF'
import pathlib, subprocess, sys
root, shim, cxxdir = (pathlib.Path(a) for a in sys.argv[1:4])
src = cxxdir / 'vector/vector.h'
lines = src.read_text().split('\n')
depth = 0; incomment = False; depths = []
for line in lines:
    s = []; j = 0
    while j < len(line):
        if incomment:
            k = line.find('*/', j)
            if k < 0: j = len(line); break
            incomment = False; j = k + 2; continue
        if line[j:j+2] == '/*': incomment = True; j += 2; continue
        if line[j:j+2] == '//': break
        if line[j] in '"\'':
            q = line[j]; j += 1
            while j < len(line) and line[j] != q:
                j += 2 if line[j] == '\\' else 1
            j += 1; continue
        s.append(line[j]); j += 1
    depths.append(depth)
    depth += ''.join(s).count('{') - ''.join(s).count('}')
cand = [i for i, l in enumerate(lines, 1)
        if l.startswith('template<') and depths[i-1] == 1]
tmp = pathlib.Path('/tmp/cxxlib-host'); tmp.mkdir(parents=True, exist_ok=True)
CXX = ['g++', '-std=c++14', '-nostdinc++', '-fno-exceptions', '-fno-rtti',
       '-fsyntax-only', '-I' + str(shim), '-I' + str(cxxdir),
       '-I' + str(cxxdir / 'vector'),
       '-D__EDG_RUNTIME_USES_NAMESPACES=1', '-D__EDG_STD_NAMESPACE=std',
       '-D__EDG_CONSTEXPR_ENABLED__=1',
       '-D__EDG_SIZE_TYPE__=decltype(sizeof(0))',
       '-DPSTL_NO_COMPILER_BUILTINS=1']
good = []
for c in cand:
    body = '\n'.join(lines[:c-1]) + '\n} // namespace std\n#endif\nint main(void){return 0;}\n'
    f = tmp / 'vs.cpp'; f.write_text(body)
    if subprocess.run(CXX + [str(f)], capture_output=True).returncode == 0:
        good.append(c)
hdr = ("""# cxx-vecsplit.cuts -- line numbers in sys/include/ape/c++/vector/vector.h
# at which that file can be TRUNCATED and still compile.
#
# GENERATED AND VALIDATED by `hostkencc/cxxlib-host.sh --vecsplit'.
# A cut at line N means "lines 1..N-1, then `} // namespace std',
# `#endif' and a `main'".  Do not edit by hand: regenerate.
#
# ***EVERY LINE HERE WAS COMPILED BY g++ BEFORE IT WAS WRITTEN DOWN.***
# %d candidates, %d validated -- the %d that fail are member templates,
# two `template<...>' lines where a cut between them leaves a dangling
# header.  The list is the PROVEN set, so a rung that errors on the VM
# is cpfe disagreeing with g++ rather than the harness cutting wrongly.
#
# `cxx-vecsplit' BISECTS these, so a run is about seven cpfe
# invocations rather than %d.
""" % (len(cand), len(good), len(cand) - len(good), len(good)))
out = root / 'sys/lib/tests/cxx-vecsplit.cuts'
out.write_text(hdr + '\n'.join(map(str, good)) + '\n')
print('cxxlib-host: %d candidates, %d validated -> %s'
      % (len(cand), len(good), out))
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
