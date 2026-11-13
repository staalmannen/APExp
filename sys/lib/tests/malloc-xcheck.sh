#!/bin/sh
# malloc-xcheck.sh -- build libap's REAL allocator with gcc and run
# EDG's allocation pattern against it.
#
#	./malloc-xcheck.sh		build and run
#	./malloc-xcheck.sh --control	deliberately break it and check
#					that the cross-check notices
#
# It compiles the real sources -- not a copy and not an extract -- so
# there are no markers to rot:
#
#	sys/src/ape/lib/ap/malloc/{malloc,free,realloc,aligned_alloc}.c
#
# with the public names renamed out of glibc's way.  The renames go to
# THOSE FILES ONLY: `malloc-xcheck.c' is compiled without them and
# declares `ap_malloc' and friends itself, because *a -D that moves the
# unit under test out of the reference's way applies to the checker as
# well*, and this tree has paid for that more than once.
#
# `-fms-extensions' is not optional: `Arena' carries an unnamed `Lock;'
# member and `Bucket' an unnamed `Header;' inside a union, which is
# kencc's unnamed-member-by-type-name extension.
#
# THE CONTROL.  There is no reference implementation of this allocator,
# so the control is a deliberate break: `--control' rebuilds with
# `_malloc_growtop' forced to claim success unconditionally -- the
# grow-in-place this release added, with its "is this block at the top
# of the heap" test removed -- which is the single most plausible way
# the rewrite could hand out memory that belongs to something else.
# **A cross-check whose break is not noticed is reporting on itself.**
#
# ***THE ROOT GUARD IS HERE BECAUSE IT HAS FIRED FOUR TIMES.***
# `sys/lib/tests' is THREE levels below the root, and more than one
# instrument in this tree has shipped with two or four and answered
# confidently about nothing.

set -e

here=$(cd "$(dirname "$0")" && pwd)
root=$(cd "$here/../../.." && pwd)

if [ ! -d "$root/sys/src/ape/lib/ap/malloc" ]; then
	echo "malloc-xcheck: \$root is $root, which has no sys/src/ape/lib/ap/malloc." >&2
	echo "malloc-xcheck: the root guard fired -- fix the dirname count." >&2
	exit 2
fi

M="$root/sys/src/ape/lib/ap/malloc"
STUB="$here/mallocstub"
OUT="${TMPDIR:-/tmp}/malloc-xcheck.$$"
mkdir -p "$OUT"
trap 'rm -rf "$OUT"' EXIT

CONTROL=""
case "${1:-}" in
"")		;;
--control)	CONTROL=1 ;;
*)		echo "malloc-xcheck: unknown argument $1" >&2; exit 2 ;;
esac

# The renames.  `sbrk' goes too, or the allocator grows the HOST's heap.
REN="-Dmalloc=ap_malloc -Dfree=ap_free -Drealloc=ap_realloc"
REN="$REN -Daligned_alloc=ap_aligned_alloc -Dsbrk=ap_sbrk"
REN="$REN -D_malloc_brk=ap__malloc_brk -D_malloc_growtop=ap__malloc_growtop"

# The stub dir must come FIRST: it shadows <unistd.h>, whose own `sbrk'
# declaration would otherwise be renamed into a conflicting one.
INC="-I$STUB -I$M"

WARN="-Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-pointer-to-int-cast"

srcs="malloc.c free.c realloc.c aligned_alloc.c mallocwatch.c"

if [ -n "$CONTROL" ]; then
	echo "malloc-xcheck: CONTROL -- _malloc_growtop forced to succeed"
	mkdir -p "$OUT/broken"
	sed 's/if(__malloc_arena.btab\[pow\] == nil/if(1 || (__malloc_arena.btab[pow] == nil/; s/\&\& sbrk(want - have) != (void\*)-1){/\&\& sbrk(want - have) != (void*)-1)){/' \
		"$M/malloc.c" > "$OUT/broken/malloc.c"
	if cmp -s "$M/malloc.c" "$OUT/broken/malloc.c"; then
		echo "malloc-xcheck: the control's sed matched NOTHING -- the" >&2
		echo "malloc-xcheck: source has moved and the control is void." >&2
		exit 2
	fi
	cp "$M/free.c" "$M/realloc.c" "$M/aligned_alloc.c" "$M/mallocwatch.c" "$OUT/broken/"
	SRCDIR="$OUT/broken"
else
	SRCDIR="$M"
fi

for f in $srcs; do
	gcc -c -O1 -g -fms-extensions $WARN $REN $INC \
		-o "$OUT/$(basename "$f" .c).o" "$SRCDIR/$f"
done

gcc -c -O1 -g $WARN -o "$OUT/brk.o" "$STUB/brk.c"
gcc -c -O1 -g $WARN -o "$OUT/xcheck.o" "$here/malloc-xcheck.c"

gcc -o "$OUT/malloc-xcheck" "$OUT"/*.o

echo

# ***EACH SECTION IN ITS OWN PROCESS, AND THE CONTROL IS WHY.***
# A broken allocator makes `free' abort on a destroyed MAGIC, so the
# first version's control died in section 1 and NEVER REACHED section
# 3 -- the one section that replicates EDG's chain and carries the
# assertion the crash violates.  A control that proves section 1 can
# see a break says nothing about section 3.
set +e
total=0
saw=""
missed=""
for s in 0 1 2 3 4; do
	"$OUT/malloc-xcheck" $s
	st=$?
	echo
	if [ $st -eq 0 ]; then
		missed="$missed $s"
	else
		saw="$saw $s"
		total=$((total + st))
	fi
done
set -e

if [ -n "$CONTROL" ]; then
	echo "malloc-xcheck: control: sections that NOTICED:$saw"
	echo "malloc-xcheck: control: sections that did not:$missed"
	case " $saw " in
	*" 3 "*)
		;;
	*)
		echo "malloc-xcheck: ***SECTION 3 DID NOT NOTICE, WHICH IS A"
		echo "malloc-xcheck: FAILURE OF THE CROSS-CHECK.***  Section 3"
		echo "malloc-xcheck: is the one that replicates EDG's chain and"
		echo "malloc-xcheck: asserts the thing the crash violates; if a"
		echo "malloc-xcheck: grow-in-place with no top-of-heap test gets"
		echo "malloc-xcheck: past it, it is not asserting what it claims."
		exit 1
		;;
	esac
	if [ -z "$saw" ]; then
		echo "malloc-xcheck: ***CONTROL PASSED EVERYWHERE, WHICH IS A FAILURE.***"
		exit 1
	fi
	echo "malloc-xcheck: control reported $total failures -- the"
	echo "malloc-xcheck: cross-check can see a broken allocator."
	exit 0
fi

echo "malloc-xcheck: $total failures over all five sections"
exit $total
