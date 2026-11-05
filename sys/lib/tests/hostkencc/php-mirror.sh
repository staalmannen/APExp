#!/bin/sh
#
# php-mirror.sh -- compile php's 513 translation units with the
# HOST-BUILT kencc, so a compile error costs a second instead of a VM
# round trip.
#
#	sh php-mirror.sh --flags      # print the compile flags and exit
#	sh php-mirror.sh --compile    # all 513; GATES on the error count
#	sh php-mirror.sh --compile Zend/zend_lazy_objects.c   # just these
#	eval "$(sh php-mirror.sh --flags)"; $CC6 $CFL -S .../zend.c
#
# Depends on `hostkencc.sh' having run.  `clisp-mirror.sh' is the
# precedent and the fidelity limits in `hostkencc.sh' apply unchanged:
# **sound for "does it compile" and "what does it diagnose", unsound
# for anything keyed on `long' being 32 bits**, because this build is
# LP64 and every kencc target is LLP64.
#
# ***UNLIKE clisp's, THERE IS NOTHING TO STAGE.***  clisp needs its
# `.d' files converted, three `configure' probes run and an
# `intparam.h' patched, and that staging is most of its mirror.  php's
# sources compile where they lie: the generated parsers, scanners and
# `zend_vm_execute.h' all ship in the tarball, and the `config.h' is
# hand-kept in `cmd/php/cfg'.  **So this file is the FLAG SET and the
# source list and little else** -- which is exactly what cost the VM
# round trips, one error at a time.
#
# ***THE FLAGS AND THE SOURCE LIST ARE BOTH DERIVED FROM `cmd/php/mkfile',
# NOT TRANSCRIBED.***  The list is its `OFILES', read with sed; the
# per-directory flags for pcre2 and Keccak are its explicit rules, read
# the same way.  *A mirror whose flags have drifted from the mkfile
# reports failures the real build does not have and misses the ones it
# does*, and this tree has paid for that shape twice -- clisp's
# `intparam.h' and the missing `-J'.
#
# ONE SHADOWING HEADER, for the same reason clisp needs one:
# `amd64/include/ape/stddef_arch.h' includes `<stddef.h>'s real body by
# ABSOLUTE path (`"/sys/include/ape/stddef.h"'), which exists on the VM
# and not here.
#
# WHAT IT FOUND ON ITS FIRST RUN is in `docs/notes/php.md'.

set -e

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../../../.." && pwd)
PHP=$ROOT/sys/src/external/php
PORT=$ROOT/sys/src/ape/cmd/php
OUT=$HERE/out/php

# `sys/lib/tests/hostkencc' is FOUR levels below the root; the guard is
# here because that count has been wrong in five instruments now.
test -f "$PHP/Zend/zend.c" || {
	echo "php-mirror: no $PHP/Zend/zend.c -- ROOT wrong" >&2; exit 2; }
test -f "$PORT/mkfile" || {
	echo "php-mirror: no $PORT/mkfile" >&2; exit 2; }

# ---- the flags, read out of the mkfile ----------------------------
#
# `DEFS' and `INCS' are continued over two or three lines each and hold
# `$PHPSRC'; the sed below joins the continuations, drops the variable
# name and substitutes the one variable.  Nothing else in either is
# expanded, which is checked by the `$' test afterwards.
mkvar() {
	sed -n "/^$1=/,/[^\\\\]\$/p" "$PORT/mkfile" |
	tr -d '\\' | tr '\n' ' ' |
	sed -e "s/^$1=//" -e "s#\\\$PHPSRC#$PHP#g" -e 's/  */ /g'
}

DEFS=$(mkvar DEFS)
INCS=$(mkvar INCS)
# `-Icfg' is relative to the port directory in the mkfile.
INCS=$(echo "$INCS" | sed "s#-Icfg#-I$PORT/cfg#")

case "$DEFS$INCS" in
*'$'*)	echo "php-mirror: unexpanded variable in the mkfile's flags:" >&2
	echo "  DEFS=$DEFS" >&2
	echo "  INCS=$INCS" >&2
	exit 2;;
esac

CFL="$DEFS $INCS -I$OUT/shadow -I$ROOT/amd64/include/ape -I$ROOT/sys/include/ape"

# The two directories with flags of their own, from the mkfile's
# explicit rules rather than from memory.
PCRE2FLAGS=$(mkvar PCRE2FLAGS | sed "s#\\\$PHPSRC#$PHP#g")
KECCAKFLAGS=$(mkvar KECCAKFLAGS | sed "s#\\\$PHPSRC#$PHP#g")

# ***THE MKFILE'S `CFLAGS' OPENS WITH `-c' AND THAT FLAG MUST NOT BE
# PASSED ON.***  `-c' to `pcc' means "compile, do not link"; `-c' to
# `6c' means **print `const if'** (`cc/lex.c:40'), and `pcc' does not
# forward it.  The first version of this script handed it to `6c' and
# every run came back with dozens of
#	Zend/zend_hash.h:1667[...] const if false
# lines, which read exactly like diagnostics and are a debug trace of
# constant-folded conditions.  *A flag one letter from another flag is
# checked rather than recalled*, and the two meanings here are in two
# different programs.  So `CFL' above carries `DEFS' and `INCS' only,
# never `CFLAGS'.
if [ "${1:-}" = "--flags" ]; then
	echo "CC6='$HERE/out/bin/6c -J -p'"
	echo "CFL='$CFL'"
	echo "PCRE2FLAGS='$PCRE2FLAGS'"
	echo "KECCAKFLAGS='$KECCAKFLAGS'"
	echo "PATH=\"$HERE/out/bin:\$PATH\"; export PATH"
	echo "export objtype=amd64"
	exit 0
fi

test -x "$HERE/out/bin/6c" || {
	echo "php-mirror: run hostkencc.sh first" >&2; exit 2; }

mkdir -p "$OUT/shadow"
sed 's#"/sys/include/ape/#"#' \
	"$ROOT/amd64/include/ape/stddef_arch.h" > "$OUT/shadow/stddef_arch.h"

# ---- the source list, read out of the mkfile's OFILES -------------
#
# `OFILES' holds object paths with comment lines between the groups;
# each object is the source path with `.$O' for `.c', with one
# exception the mkfile states and this reproduces: `ext/json's parser
# is built from the bison output `json_parser.tab.c'.
sources() {
	sed -n '/^OFILES=/,/^$/p' "$PORT/mkfile" |
	sed -n 's/^	\([^ 	]*\)\.\$O\\*$/\1/p' |
	sed 's#^ext/json/json_parser$#ext/json/json_parser.tab#' |
	sed 's/$/.c/'
}

if [ "${1:-}" != "--compile" ]; then
	n=$(sources | wc -l)
	echo "php-mirror: staged $OUT; $n sources; now --compile"
	exit 0
fi
shift

PATH="$HERE/out/bin:$PATH"; export PATH
export objtype=amd64
CC6="$HERE/out/bin/6c -J -p"

if [ $# -gt 0 ]; then list=$*; else list=$(sources); fi

ok=0; bad=0; missing=0
: > "$OUT/errors"
for s in $list; do
	#
	# Nearly every source is in the vendored tree, and the `%.$O:
	# %.c' rule beside the `%.$O: $PHPSRC/%.c' one is there for the
	# five files the PORT supplies: `internal_functions_cli.c' is
	# configure-generated and kept beside the mkfile so the vendored
	# tree stays untouched.
	if [ -f "$PHP/$s" ]; then src=$PHP/$s
	elif [ -f "$PORT/$s" ]; then src=$PORT/$s
	else
		missing=$((missing+1))
		echo "MISSING $s" >> "$OUT/errors"
		continue
	fi
	extra=
	#
	# ***`ext/hash/hash_sha3.c' TAKES THE KECCAK FLAGS TOO, AND
	# LEAVING IT OUT MANUFACTURED A FAILURE.***  The first version
	# of this script matched on the DIRECTORY, which reads as the
	# rule but is not it: the mkfile has four explicit Keccak rules
	# and one of them is in `ext/hash' itself.  The mirror duly
	# answered `Could not find include file "KeccakHash.h"' -- a
	# finding that was the instrument's, which is the shape
	# `clisp-mirror's `intparam.h' already cost a round for.
	#
	case "$s" in
	ext/pcre/pcre2lib/*)		extra=$PCRE2FLAGS;;
	ext/hash/sha3/generic64lc/*)	extra=$KECCAKFLAGS;;
	ext/hash/hash_sha3.c)		extra=$KECCAKFLAGS;;
	ext/json/*)			extra=-I$PHP/ext/json;;
	esac
	if $CC6 $extra $CFL -o "$OUT/t.6" "$src" > "$OUT/t.log" 2>&1; then
		ok=$((ok+1))
	else
		bad=$((bad+1))
		echo "==== $s" >> "$OUT/errors"
		cat "$OUT/t.log" >> "$OUT/errors"
	fi
done
echo "php-mirror: compiled $ok, errors $bad, missing $missing"
echo "php-mirror: diagnostics in $OUT/errors"
test "$bad" -eq 0 && test "$missing" -eq 0
