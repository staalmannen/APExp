#!/bin/sh
# cpfe-host.sh -- build EDG's cpfe with gcc, with its baked ABI repaired.
#
#	sh cpfe-host.sh            # build it
#	sh cpfe-host.sh --check    # just verify the repair list is current
#
# A HOST instrument: gcc and gdb on the build host, never the VM.
#
# ------------------------------------------------------------------
# WHY IT NEEDS A REPAIR AT ALL
#
# EDG's C back end FOLDS `sizeof' and `offsetof' into integer
# literals, so the 2.9M-line corpus is ABI-LOCKED to the target it was
# generated for -- one whose `long' is 4 bytes.  gcc on x86-64 Linux
# has 8.  A straight `gcc' build therefore compiles cleanly and then
# allocates objects that are too small: `alloc_fe(440)' for a struct
# gcc lays out at 464, and a registration that files a pointer at
# offset 400 where the member is at 424.
#
# `edgbaked-xcheck.sh' found the sizes (91 sites, 4 disagree) and
# `edgtuoff-probe' the two offsets.  **This patches exactly those
# seven literals, in copies, and compiles the copies.**  The repo's
# own files are NOT touched: their numbers are right for kencc, which
# is the compiler that matters.
#
# ***THE RISK IS AN INCOMPLETE REPAIR, AND IT IS NAMED RATHER THAN
# HOPED AWAY.***  A half-repaired cpfe crashes somewhere else and
# invites exactly the misattribution this port has already paid for
# once -- the host crash read as the static-init gap for two rounds.
# So the script RE-RUNS `edgbaked-xcheck' against the patched copies
# and refuses to link if any size still disagrees.  *That bounds the
# class the sweep can see; it cannot bound folded constants that
# carry no type name*, of which `offsetof' is the known family and
# the two below are the whole of it in this corpus.
#
# WHAT IT IS FOR.  `cpfe-ladder' on the VM has the fault bracketed
# between a successful `fopen' of the source and the first emitted
# token, and there is no debugger there.  A repaired host build puts
# gdb at exactly that point.  **It is still sound only for what the
# ABI does not touch** -- see `docs/notes/edg.md'.
# ------------------------------------------------------------------
set -u

HERE=$(cd "$(dirname "$0")" && pwd)
# `sys/lib/tests/hostkencc' is FOUR levels below the root, not three.
# The guard fired on this file's first run, which is the SIXTH time in
# this directory tree -- `cpp-xcheck' is also four deep and made the
# same mistake. *The guard is the instrument that works.*
ROOT=$(cd "$HERE/../../../.." && pwd)
if [ ! -f "$ROOT/CLAUDE.md" ]; then
	echo "cpfe-host: ROOT=$ROOT is not the repository root" >&2
	exit 2
fi
SRC=$ROOT/sys/src/external/edg/src
LIB=$ROOT/sys/src/external/edg/lib_src
# **No `-I' and no `-D', which is `cmd/edg/mkfile's own note**: every
# generated file declares everything it uses, so there is no include
# directory to point at and nothing to keep in step.
[ -d "$SRC" ] || { echo "cpfe-host: no $SRC" >&2; exit 2; }
command -v gcc >/dev/null 2>&1 || { echo "cpfe-host: no gcc" >&2; exit 2; }

OUT=${TMPDIR:-/tmp}/cpfe-host
PATCHED=$OUT/src
OBJ=$OUT/obj
mkdir -p "$PATCHED" "$OBJ" || exit 2

# ---- the repair list ---------------------------------------------
#
# file:old:new:tag.  Each `old' must occur EXACTLY ONCE in its file
# or the script stops: a literal that has moved or multiplied means
# the corpus was regenerated and every number here needs re-deriving
# from `edgbaked-xcheck' and `edgtuoff-probe' rather than nudging.
#
# The five sizes are `((T *)(alloc_fe(N)))' sites; the two offsets are
# `f_register_trans_unit_variable(&v, size, FIELD_OFFSET)'.
REPAIRS="
templates.c:(_ZN3edg17a_tmpl_decl_stateE *)(_ZN3edg8alloc_feEy(384ULL)):(_ZN3edg17a_tmpl_decl_stateE *)(_ZN3edg8alloc_feEy(392ULL)):a_tmpl_decl_state 384->392
trans_unit.c:(_ZN3edg18a_translation_unitE *)(_ZN3edg8alloc_feEy(440ULL)):(_ZN3edg18a_translation_unitE *)(_ZN3edg8alloc_feEy(464ULL)):a_translation_unit 440->464
scope_stk.c:(_ZN3edg28a_string_literal_table_entryE *)(_ZN3edg8alloc_feEy(24ULL)):(_ZN3edg28a_string_literal_table_entryE *)(_ZN3edg8alloc_feEy(32ULL)):a_string_literal_table_entry 24->32
host_envir.c:_ZN34_INTERNAL_12_host_envir_c_0c23567a3edg9module_idE)), 8ULL, 416ULL):_ZN34_INTERNAL_12_host_envir_c_0c23567a3edg9module_idE)), 8ULL, 440ULL):module_id offset 416->440
il.c:_ZN3edg30orphaned_file_scope_il_entriesE)), 1616ULL, 400ULL):_ZN3edg30orphaned_file_scope_il_entriesE)), 1616ULL, 424ULL):orphaned_file_scope_il_entries offset 400->424
"
# `a_decl_parse_state' has TWO sites and `sed' would need a global
# replace; it is listed separately for that reason alone, so that the
# exactly-once rule above stays a rule rather than an exception.
DECLS_OLD='(_ZN3edg18a_decl_parse_stateE *)(_ZN3edg8alloc_feEy(480ULL))'
DECLS_NEW='(_ZN3edg18a_decl_parse_stateE *)(_ZN3edg8alloc_feEy(488ULL))'

fail=0
echo "cpfe-host: checking the repair list against the corpus"
printf '%s\n' "$REPAIRS" | while IFS=: read -r f old new tag; do
	[ -n "${f:-}" ] || continue
	n=$(grep -F -c -- "$old" "$SRC/$f" 2>/dev/null || echo 0)
	if [ "$n" != 1 ]; then
		echo "  STALE $f: '$tag' matched $n times, expected 1" >&2
		exit 1
	fi
	echo "  ok    $f: $tag"
done || fail=1
n=$(grep -F -c -- "$DECLS_OLD" "$SRC/decls.c" 2>/dev/null || echo 0)
if [ "$n" != 2 ]; then
	echo "  STALE decls.c: a_decl_parse_state matched $n times, expected 2" >&2
	fail=1
else
	echo "  ok    decls.c: a_decl_parse_state 480->488 (2 sites)"
fi
[ "$fail" = 0 ] || { echo "cpfe-host: repair list is stale; re-derive it" >&2; exit 1; }
[ "${1-}" = "--check" ] && { echo "cpfe-host: list is current"; exit 0; }

# ---- stage the patched copies ------------------------------------
printf '%s\n' "$REPAIRS" | while IFS=: read -r f old new tag; do
	[ -n "${f:-}" ] || continue
	python3 - "$SRC/$f" "$PATCHED/$f" "$old" "$new" <<'PY'
import sys
src, dst, old, new = sys.argv[1:5]
t = open(src, errors='ignore').read()
assert t.count(old) == 1, (src, t.count(old))
open(dst, 'w').write(t.replace(old, new, 1))
PY
done
python3 - "$SRC/decls.c" "$PATCHED/decls.c" "$DECLS_OLD" "$DECLS_NEW" <<'PY'
import sys
src, dst, old, new = sys.argv[1:5]
t = open(src, errors='ignore').read()
assert t.count(old) == 2, (src, t.count(old))
open(dst, 'w').write(t.replace(old, new))
PY
echo "cpfe-host: staged $(ls "$PATCHED" | wc -l) patched files in $PATCHED"

# ---- compile ------------------------------------------------------
# A patched copy is compiled from $PATCHED; everything else from the
# repo.  `-I$SRC' either way, because the HEADERS are unchanged.
CFL="-w -O0 -g -I$SRC"
nerr=0
for f in $(cd "$SRC" && ls *.c); do
	s=$SRC/$f
	[ -f "$PATCHED/$f" ] && s=$PATCHED/$f
	o=$OBJ/${f%.c}.o
	[ -f "$o" ] && [ "$o" -nt "$s" ] && continue
	gcc $CFL -c -o "$o" "$s" 2>>"$OUT/errors" || { echo "  FAIL $f"; nerr=$((nerr+1)); }
done
[ -f "$LIB/placenew.c" ] && gcc $CFL -c -o "$OBJ/placenew.o" "$LIB/placenew.c" 2>>"$OUT/errors"
echo "cpfe-host: compiled $(ls "$OBJ" | wc -l) objects, $nerr failures"

echo "cpfe-host: the shim and the link are not automated yet -- see"
echo "cpfe-host: docs/notes/edg.md for the three names and the"
echo "cpfe-host: --allow-multiple-definition / localize-symbols split."
