#!/usr/bin/env python3
#
# bfmove-sweep -- which structs in this tree would MOVE if kencc let an
# ordinary member share a bit field's container tail?
#
#   python3 sys/lib/tests/bfmove-sweep.py sys/src/ape/lib/ap sys/src/external
#
# WHY IT EXISTS.  `apeabi-probe' answers this from the compiler itself,
# which is the better evidence -- but only for the structs its own
# translation unit lays out, i.e. the PUBLIC APE headers.  The change
# reaches every APE compile, so libap's own sources and every package
# under `external/' are in scope and no acid dump of one translation
# unit can see them.  *The probe's limit is this sweep's reason.*
#
# THE RULE IT ENCODES.  kencc allocates a bit field in a whole `tfield'
# unit and does NOT let a following ordinary member share what is left
# of it; gcc, clang and EDG do.  **So a bit-field group only moves
# anything when the member AFTER it would fit the container's tail at
# its OWN alignment.**  A following `int' wants 4-byte alignment and
# cannot (measured: `fenv_t's `__data_offset' is at 24 under both
# rules); a following `char' array can (measured: `__res_state's
# `unused[3]' is at 368 here and 365 on gcc).  A group with nothing
# after it moves nothing either.
#
# IT IS A LOWER BOUND, and the limits are named rather than left to be
# found:
#   - It is TEXTUAL.  No preprocessor, no parse: a bit-field group is a
#     run of lines matching a declaration with a width, and the member
#     after it is the next line that is not blank, a comment or a `#'.
#     A group split by an `#if' reads as two groups.
#   - `char', `signed/unsigned char', `int8_t', `uint8_t' and `_Bool'
#     are the only base types counted as able to share.  A `short'
#     could share a 2-byte-aligned tail and is NOT counted, which is
#     the conservative direction.
#   - POINTERS ARE EXCLUDED and that was a real false-positive class:
#     the first version allowed `\**' and reported
#     `perl/regexp.h:198', where `compflags:9' is followed by
#     `char *subbeg' -- a pointer, 8-byte aligned, which can never sit
#     in a 4-byte tail.  *A regex that matches the TYPE NAME is not a
#     regex that matches the TYPE.*
#   - It says nothing about whether the struct is COMPILED.  The one
#     hit under `lib/ap' is `include/meta.h', musl's mallocng header,
#     which nothing in this tree includes.
#
# MEASURED, 2026-10:
#   lib/ap        3 groups, 1 would move (meta.h, dead -- see below)
#   external/ 43093 groups, 268 would move -- and **266 of the 268 are
#                   EDG**, which is the whole point: EDG's explicit
#                   `char __dummy[N]' padding IS this shape, emitted
#                   for a compiler that shares the container.  The
#                   other two are `sqlite3.c's `struct Column'
#                   (`notNull:4' then `char affinity') and curl's
#                   `curl_hstsentry', both internal to one package and
#                   so self-consistent after a rebuild.
#
# AND THE ONE libap HIT IS A LATENT BUG RATHER THAN A COST.
# `meta.h's `struct group' is
#       struct meta *meta;
#       unsigned char active_idx:5;
#       char pad[UNIT - sizeof(struct meta *) - 1];
# -- upstream sized that pad so the struct is exactly UNIT, *which is
# only true if the bit field shares*.  Under kencc the arithmetic is
# wrong by construction.  It costs nothing today because nothing
# includes the file (this tree's allocator is Plan 9's own), so it is
# recorded rather than fixed -- but it would break silently the day
# mallocng were built here.  Its base type is `unsigned char' and
# NOTHING HAS MEASURED what kencc does with a sub-int container, so
# the direction is named and the number is not.

import re, os, sys, signal

# `| head' otherwise ends a 268-line report in a BrokenPipeError
# traceback, and a traceback from the instrument reads like a finding.
try:
    signal.signal(signal.SIGPIPE, signal.SIG_DFL)
except (AttributeError, ValueError):
    pass

bitfield = re.compile(
    r'^\s*(?:(?:unsigned|signed|const|volatile|static)\s+)*'
    r'(?:int|char|short|long|_Bool|bool|unsigned|signed|[A-Za-z_]\w*)'
    r'(?:\s+(?:int|long|char|short))*\s+'
    r'[A-Za-z_]\w*\s*:\s*\d+\s*(?:,\s*[A-Za-z_]\w*\s*:\s*\d+\s*)*;')

# A following member small enough to sit in the tail at its own
# alignment.  No `\*' -- see the note above.
sharer = re.compile(
    r'^\s*(?:unsigned\s+|signed\s+|const\s+|volatile\s+)*'
    r'(?:char|u?int8_t|_Bool|bool)\s+[A-Za-z_]\w*\s*(\[[^\]]*\])?\s*;')

def skippable(l):
    s = l.strip()
    return not s or s.startswith(('/*', '*', '//', '#'))

def sweep(roots):
    groups = 0
    movers = []
    for r in roots:
        for dp, _, fns in os.walk(r):
            for fn in fns:
                if not fn.endswith(('.c', '.h', '.cc', '.cpp')):
                    continue
                p = os.path.join(dp, fn)
                try:
                    L = open(p, errors='replace').read().split('\n')
                except OSError:
                    continue
                i = 0
                while i < len(L):
                    if bitfield.match(L[i]) and '?' not in L[i]:
                        j = i
                        while j < len(L) and bitfield.match(L[j]):
                            j += 1
                        groups += 1
                        k = j
                        while k < len(L) and skippable(L[k]):
                            k += 1
                        if k < len(L) and sharer.match(L[k]):
                            movers.append((p, i + 1, L[i].strip(), L[k].strip()))
                        i = j
                    else:
                        i += 1
    return groups, movers

def main():
    roots = sys.argv[1:]
    if not roots:
        print("usage: bfmove-sweep.py <dir> [dir ...]", file=sys.stderr)
        return 2
    groups, movers = sweep(roots)
    print("bit-field groups found:                        %d" % groups)
    print("groups followed by a shareable member (MOVE):  %d" % len(movers))
    for p, n, a, b in movers:
        print("  %s:%d" % (p, n))
        print("     %s" % a)
        print("     %s" % b)
    # It does NOT gate: EDG's 266 are the change's PURPOSE, not its cost,
    # so a non-zero count is the expected answer and failing on it would
    # make the sweep cry wolf -- the rule `ishadow-sweep' already carries.
    return 0

if __name__ == '__main__':
    sys.exit(main())
