#!/bin/sh
# makectx-xcheck.sh -- compile libap's real `makecontext.c' on the build
# host, beside stubs for `_ctxreturn' and `setcontext', and check that
# the frame `makecontext' builds is the one `_ctxfinish' reads back.
#
#	sh makectx-xcheck.sh
#
# ***NOTHING IS EXTRACTED OR TRANSCRIBED HERE.*** The harness
# `#include's the library file itself, which is possible because the
# frame layout lives entirely in C -- the assembly knows only the eight
# register slots and one asserted offset.  So there are no markers to
# rot, and the thing under test is the thing that ships.
#
# The three headers it needs are the tree's own: `<ucontext.h>' from
# `sys/include/ape' and `<ucontext_arch.h>' from `amd64/include/ape'.
# **They cannot simply be put on the include path**, because the APE
# headers reach each other through ABSOLUTE `/sys/include/ape/...'
# paths that resolve only inside `apexp-sh's namespace -- a first
# attempt died on `stddef_arch.h:16'.  So the two are SYMLINKED into a
# scratch directory that is searched first, beside a `<signal.h>' that
# supplies `sigset_t' from glibc's own `<bits/types/sigset_t.h>'.
# *That detail is not cosmetic*: defining `sigset_t' independently made
# `<stdlib.h>' conflict with it two includes later.
#
# It does NOT test the context switch -- that is machine code for a
# machine this is not.  `ucontext-test.c' does, with glibc as a
# reference implementation.

set -e

# This file is three levels below the repository root.
ROOT=$(cd "$(dirname "$0")/../../.." && pwd)
SRC=$ROOT/sys/src/ape/lib/ap/arch/amd64/makecontext.c
HDR=$ROOT/sys/include/ape/ucontext.h
ARCH=$ROOT/amd64/include/ape/ucontext_arch.h
HERE=$(cd "$(dirname "$0")" && pwd)
TMP=$HERE/.makectx-xcheck.d

for f in "$SRC" "$HDR" "$ARCH"; do
	[ -f "$f" ] || { echo "makectx-xcheck: no $f -- is ROOT wrong?" >&2; exit 2; }
done

rm -rf "$TMP"; mkdir -p "$TMP"
ln -s "$HDR"  "$TMP/ucontext.h"
ln -s "$ARCH" "$TMP/ucontext_arch.h"
ln -s "$SRC"  "$TMP/makecontext.c"
: > "$TMP/lib.h"
cat > "$TMP/signal.h" <<'EOF'
#ifndef _MAKECTX_STUB_SIGNAL_H
#define _MAKECTX_STUB_SIGNAL_H
#include <bits/types/sigset_t.h>   /* glibc's own, so <stdlib.h> agrees */
#define SIG_SETMASK 2
extern int sigprocmask(int, sigset_t *, sigset_t *);
#endif
EOF

cc=${CC:-gcc}
$cc -Wall -Wextra -Wno-unused-parameter -I"$TMP" \
	-o "$HERE/makectx-xcheck" "$HERE/makectx-xcheck.c"
"$HERE/makectx-xcheck"
