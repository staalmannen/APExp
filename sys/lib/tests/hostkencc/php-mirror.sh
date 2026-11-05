#!/bin/sh
#
# php-mirror.sh -- compile php's translation units with the HOST-BUILT
# kencc, so a compile error -- or an undefined symbol -- costs a second
# instead of a VM round trip.
#
#	sh php-mirror.sh --flags      # print the compile flags and exit
#	sh php-mirror.sh --compile    # all of them; GATES on the error count
#	sh php-mirror.sh --compile Zend/zend_lazy_objects.c   # just these
#	sh php-mirror.sh --undefined  # every symbol the LINK will want
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
# ***`--undefined' ASKS THE LINK'S QUESTION WITHOUT A LINKER, AND THIS
# FILE SAID IT COULD NOT.***  The first version's header ended "it
# cannot ask about the LINK, which stays the VM's", because the host
# has no libap and `hostkencc' deliberately does not build `[1-9]l'.
# **Neither is needed.**  `6c -S' prints, for every translation unit,
# each symbol it DEFINES (`TEXT name+0(SB)', `GLOBL name+0(SB)' --
# with `<>' when the definition is file-local) and each symbol it
# REFERENCES (anything else spelled `name+off(SB)').  The program's
# undefined set is then the references minus the global definitions
# minus that unit's own statics, computed over all of them at once --
# which is the question `6l' answers, minus only the part that is
# libap's.
#
# For that last part it hands the list to `apfunc-sweep.py', which
# exists to say whether libap DEFINES a name, only DECLARES it, or has
# neither.  **Read its answer rather than gating on it**, for two
# reasons the first run demonstrated: the sweep looks for FUNCTION
# definitions in `.c' files, so `getcontext' and `swapcontext' come
# back `declared' because they are ASSEMBLY (`arch/amd64/ucontext.s'),
# and `stdin', `stderr', `stdout', `environ', `h_errno', `_ctype' and
# `_errnoloc' come back `absent' because they are DATA.  All ten are
# present; *a sweep over function names, asked about a variable,
# answers `absent' confidently* -- the caveat CLAUDE.md already
# carries, arriving here in its other form.  `signal' is a third
# shape: defined, but spelled
# `(*signal(int sig, void (*func)(int)))(int)', which no
# definition-shaped regex matches.
#
# **ITS POSITIVE CONTROL IS A REAL FAILURE AND COSTS ONE COMMAND**:
#
#	sh php-mirror.sh --undefined ext/lexbor/lexbor/dom/interfaces/node.c
#
# narrows the program to one unit, and the answer names
# `lxb_dom_collection_create', `_init' and `_destroy' among its 37 --
# **the three the VM's `6l' named**, for the reason below.  *A mode
# that reports an empty set is indistinguishable from one that cannot
# see*, which is why this is written down with its number.
#
# ***THOSE THREE ARE WHY `collection.c' IS IN THE MKFILE AND NOT IN
# UPSTREAM'S config.m4.***  `lxb_dom_collection_make' is a `static
# inline' in `lexbor/dom/collection.h', reached by every unit that
# includes `node.h' or `element.h'; **kencc emits an unused static
# function and gcc at -O2 discards it**, so upstream never needs the
# three functions it calls and this build does.  That asymmetry is
# general: a header-only helper calling into a file the port does not
# compile is a link error here and silence there.
#
# WHAT IT FOUND is in `docs/notes/php.md'.

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

mkdir -p "$OUT/shadow" "$OUT/asm"
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

case "${1:-}" in
--compile)	mode=compile; shift;;
--undefined)	mode=undefined; shift;;
*)
	n=$(sources | wc -l)
	echo "php-mirror: staged $OUT; $n sources; now --compile"
	exit 0;;
esac

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
	if [ "$mode" = undefined ]; then
		# `-S' rather than `-o': the assembly carries the symbol
		# table this mode needs, and nothing else does without a
		# reader for Plan 9 object files.
		#
		# ***BUT kencc's `diag()' WRITES TO STDOUT***, which under
		# `-S' is where the assembly goes -- so a failing unit's
		# diagnostics land at the END OF THE .s FILE and `t.log'
		# comes back holding nothing but cpp's `#warning' line.
		# The first version of this arm saved exactly that, and a
		# real error (`sk_X509_new_reserve' undeclared, from
		# LibreSSL) read as *exit 1 with no message*.  **The same
		# trap `hostkencc.sh --probe' already carries**, where ten
		# backends "passed" because `diag' is not on stderr.
		#
		# So on failure, recompile to an OBJECT -- where stdout is
		# the diagnostics and nothing else -- and report that.
		if $CC6 $extra $CFL -S "$src" \
		    > "$OUT/asm/$(echo "$s" | tr / _).s" 2> "$OUT/t.log"; then
			ok=$((ok+1))
		else
			bad=$((bad+1))
			echo "==== $s" >> "$OUT/errors"
			# `|| true' on BOTH: this file runs under `set -e',
			# the recompile is EXPECTED to fail, and a bare
			# failing command kills the script -- which it did,
			# silently, so the run printed nothing at all and
			# exited 1.  *The positive control caught it; the
			# first version of this arm was never exercised
			# because nothing had failed since it was written.*
			$CC6 $extra $CFL -o "$OUT/t.6" "$src" \
				> "$OUT/t.log" 2>&1 || true
			grep -v '#warning directive' "$OUT/t.log" \
				>> "$OUT/errors" || true
		fi
		continue
	fi
	if $CC6 $extra $CFL -o "$OUT/t.6" "$src" > "$OUT/t.log" 2>&1; then
		ok=$((ok+1))
	else
		bad=$((bad+1))
		echo "==== $s" >> "$OUT/errors"
		cat "$OUT/t.log" >> "$OUT/errors"
	fi
done

if [ "$mode" = undefined ]; then
	echo "php-mirror: assembled $ok, errors $bad, missing $missing"
	test "$bad" -eq 0 || { echo "php-mirror: fix the compile first" >&2; exit 1; }
	python3 - "$OUT/asm" > "$OUT/undefined" <<'EOF'
import os, re, sys

D = sys.argv[1]
# `TEXT name+0(SB)' and `GLOBL name+0(SB)' define; `name<>+0(SB)'
# defines it FILE-LOCALLY, which satisfies that unit and no other.
DEF = re.compile(r'^\t(?:TEXT|GLOBL)\t([A-Za-z_.][\w.]*)(<>)?\+')
REF = re.compile(r'(?<![\w.<])([A-Za-z_.][\w.]*)\+-?\d+\(SB\)')

gdef, statics, refs = set(), {}, {}
for f in sorted(os.listdir(D)):
    st, rf = set(), set()
    for line in open(os.path.join(D, f), errors='ignore'):
        m = DEF.match(line)
        if m:
            (st if m.group(2) else gdef).add(m.group(1))
            continue
        rf.update(REF.findall(line))
    statics[f], refs[f] = st, rf

und = set()
for f, rf in refs.items():
    und |= rf - gdef - statics[f]
for n in sorted(und):
    print(n)
EOF
	rm -rf "$OUT/asm"
	n=$(wc -l < "$OUT/undefined")
	echo "php-mirror: $n symbol(s) the link must find outside php"
	echo "php-mirror: the list is in $OUT/undefined; asking libap --"
	# ***NINE LIBRARIES NOW, NOT ONE.***  php pulls each of them
	# through `#pragma lib' in its own header, so a sweep that knows
	# only libap answers `absent' for every `xmlParseFile',
	# `deflateInit_', `SSL_new' and `curl_easy_init' -- 241 of the
	# 539 the first run with the dom, simplexml and zlib extensions
	# reported.  `--root' adds their vendored sources; **add one here
	# for every library a new extension links**, or the sweep's
	# `absent' column fills with names that are present and the real
	# findings are lost in it.
	python3 "$ROOT/sys/lib/tests/apfunc-sweep.py" \
		--root sys/src/external/libxml2 \
		--root sys/src/external/zlib \
		--root sys/src/external/libressl \
		--root sys/src/external/curl \
		--root sys/src/external/sqlite \
		--root sys/src/external/libzip \
		--root sys/src/external/readline \
		--root sys/src/external/bzip2 \
		--file "$OUT/undefined" |
		grep -v '	*defined   ' || true
	echo "php-mirror: ^ anything here is READ, not a failure -- the"
	echo "php-mirror:   sweep sees C function definitions only, so"
	echo "php-mirror:   assembly reads as 'declared' and DATA as 'absent'."
	echo "php-mirror:   The known-innocent 'absent' names, all checked"
	echo "php-mirror:   by hand: stdin/stdout/stderr, environ, h_errno,"
	echo "php-mirror:   _ctype, _errnoloc, xmlParserVersion,"
	echo "php-mirror:   xmlStringText (DATA); the 16 rl_* (readline"
	echo "php-mirror:   VARIABLES); and the 15 BZ2_* -- bzlib.c spells"
	echo "php-mirror:   every definition 'int BZ_API(BZ2_bzopen)', so"
	echo "php-mirror:   the NAME IS INSIDE A MACRO and no regex over"
	echo "php-mirror:   definition sites can see it.  **A name here"
	echo "php-mirror:   that is not on that list is the finding.**"
	exit 0
fi
echo "php-mirror: compiled $ok, errors $bad, missing $missing"
echo "php-mirror: diagnostics in $OUT/errors"
test "$bad" -eq 0 && test "$missing" -eq 0
