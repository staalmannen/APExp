#!/usr/bin/env python3
"""edgsize-sweep.py -- does EDG's baked allocation size match the size
kencc gives the type?

    python3 sys/lib/tests/edgsize-sweep.py            # sweep, GATES
    python3 sys/lib/tests/edgsize-sweep.py --control  # prove it can fire

***IT GATES, AND ON ONE THING ONLY: AN ALLOCATION THAT IS SHORT.***
EDG's C back end folds `sizeof' into integer literals, so every
`((T *)(alloc_fe(N)))' in the corpus is a frozen opinion about how the
generating compiler laid `T' out.  **A short allocation is a write past
the end of a heap block with no diagnostic from anyone**, so it gates.
An allocation LARGER than the type is reported and not counted: it is
either wasteful or an array, and neither is a fault.

---- WHAT IT COST TO LEARN THIS ----------------------------------------

`an_include_file_history' was baked at **32** and kencc lays it out at
**48**.  The 16 bytes are `a_unique_file_id', which is
`{dev_t st_dev; ino_t st_ino;}' -- and *this release widened both from
`unsigned short' to `unsigned long long'*, the same change that took
`struct stat' from 88 to 104 and smashed cpfe's return address on every
input.  **The typedefs were widened in EDG's five files and the baked
allocation sizes were not**, because nothing looks at them.

The second half of that write landed one word past a 32-byte block, on
whatever was allocated next -- a carved block header's `next' in one
crash, a token array's `elems[0]' in another, and in both cases the
value was the top half of a file id, which is why it was stable across
builds and across two inputs while every address around it moved.
*Eleven rounds of narrowing, and the answer was a number in the corpus.*

---- WHAT IT DOES NOT SEE --------------------------------------------

Named rather than left out, because a sweep's limits decide what a
clean run means:

  * **Only `alloc_fe'.**  `alloc_general', `malloc_with_check' and the
    IFC readers bake sizes too and are not swept.
  * **Only a CAST site.**  A size reaching the allocator through a
    variable is invisible, and so is a `memcpy' or `memset' length.
  * **Only types kencc's `-a' emits**, which is per TU; a type whose
    TU is not dumped is reported as unknown rather than silently
    agreeing.
  * `X_ptr' is EDG's own typedef for `X *' and the mangled length
    prefix has to be RECOMPUTED, not just the suffix stripped --
    without that, 52 sites read as "type unknown" and the one real
    finding was among them.
"""

import collections
import glob
import os
import re
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
if not os.path.isfile(os.path.join(ROOT, 'CLAUDE.md')):
    sys.exit('edgsize-sweep: ROOT=%s is not the repository root -- fix the '
             'dirname count (this guard has now fired FIVE times in this\n'
             'tree, and on this file''s own first run -- sys/lib/tests is THREE\n'
             'levels below the root and the first draft said two)' % ROOT)

SRC = os.path.join(ROOT, 'sys', 'src', 'external', 'edg', 'src')
CC = os.path.join(HERE, 'hostkencc', 'out', 'bin', '6c')
MANG = re.compile(r'^_ZN3edg(\d+)([A-Za-z0-9_]+)E$')
SITE = re.compile(r'\(\(?(?:struct )?(_ZN3edg[A-Za-z0-9_]*E) ?\*?\)'
                  r'\(_ZN3edg8alloc_feEy\((\d+)ULL\)\)')
SIZEOF = re.compile(r'^sizeof(\S+) = (\d+);$', re.M)


def deptr(name):
    m = MANG.match(name)
    if not m:
        return None
    n, ident = int(m.group(1)), m.group(2)
    if len(ident) != n or not ident.endswith('_ptr'):
        return None
    base = ident[:-4]
    return '_ZN3edg%d%sE' % (len(base), base)


def kencc_sizes(files):
    """Ask the HOST-built 6c for every aggregate's size.  Sound here
    because this is a compile-time question -- the bargain hostkencc
    strikes, and the one it is actually good for."""
    if not os.path.isfile(CC):
        sys.exit('edgsize-sweep: no host 6c at %s -- build sys/lib/tests/'
                 'hostkencc first' % CC)
    env = dict(os.environ, PATH=os.path.dirname(CC) + os.pathsep + os.environ['PATH'])
    sizes = {}
    for f in files:
        p = subprocess.run([CC, '-J', '-p', '-a', '-o', os.devnull, f],
                           capture_output=True, text=True, env=env)
        for m in SIZEOF.finditer(p.stdout):
            sizes.setdefault(m.group(1), int(m.group(2)))
    return sizes


def sweep(srcdir, sizes, quiet=False):
    short, big, unknown, agree = [], [], collections.Counter(), 0
    for f in sorted(glob.glob(os.path.join(srcdir, '*.c'))):
        s = open(f, errors='replace').read()
        for m in SITE.finditer(s):
            t, n = m.group(1), int(m.group(2))
            real = sizes.get(t)
            if real is None:
                b = deptr(t)
                if b:
                    real, t = sizes.get(b), b
            if real is None:
                unknown[t] += 1
                continue
            where = '%s:%d' % (os.path.basename(f), s.count('\n', 0, m.start()) + 1)
            if real == n:
                agree += 1
            elif real > n:
                short.append((t, n, real, where))
            else:
                big.append((t, n, real, where))
    if not quiet:
        print('alloc_fe cast sites: %d agree, %d SHORT, %d larger than the type, '
              '%d type unknown' % (agree, len(short), len(big), sum(unknown.values())))
        for label, rows in (('SHORT -- a write past the block', short),
                            ('larger (array or waste; reported, not counted)', big)):
            if rows:
                print('\n  %s:' % label)
                for t, n, real, where in rows:
                    print('    %-40s baked %5d  kencc %5d  %+d   %s'
                          % (re.sub(r'^_ZN3edg\d+', '', t).rstrip('E'), n, real,
                             real - n, where))
    return short, big, agree


def main():
    control = '--control' in sys.argv[1:]
    files = sorted(glob.glob(os.path.join(SRC, '*.c')))
    if not files:
        sys.exit('edgsize-sweep: no sources at %s' % SRC)
    sizes = kencc_sizes(files)
    print('types sized by the host 6c: %d' % len(sizes))

    if control:
        # ***THE CONTROL IS A DELIBERATE BREAK, BECAUSE THERE IS NO
        # ORACLE.***  Put the bug back -- the one real finding was a
        # single literal -- and the sweep must name it.  A control that
        # only proves the sweep RUNS would pass for a sweep that reports
        # nothing, which is the shape this tree has been caught by.
        with tempfile.TemporaryDirectory() as d:
            hit = False
            for f in files:
                s = open(f, errors='replace').read()
                b = s.replace('_ZN3edg8alloc_feEy(sizeof(struct '
                              '_ZN3edg23an_include_file_historyE))',
                              '_ZN3edg8alloc_feEy(32ULL)')
                if b != s:
                    hit = True
                open(os.path.join(d, os.path.basename(f)), 'w').write(b)
            if not hit:
                sys.exit('edgsize-sweep: the control patched NOTHING -- the fix '
                         'has moved and the control is void')
            short, _, _ = sweep(d, sizes, quiet=True)
            names = [t for t, _, _, _ in short]
            if not any('an_include_file_history' in n for n in names):
                sys.exit('edgsize-sweep: ***THE CONTROL DID NOT FIRE.***  With the '
                         'baked 32 put back the sweep must report '
                         'an_include_file_history as SHORT, and it reported %r'
                         % names)
            print('control: the break is reported -- %d short site(s), including '
                  'an_include_file_history' % len(short))
            return 0

    short, _, _ = sweep(SRC, sizes)
    if short:
        print('\n*** %d SHORT allocation(s): the corpus bakes a size smaller than '
              'kencc lays the type out, which is a write past the end of a heap '
              'block with no diagnostic. ***' % len(short))
        return 1
    print('\nno short allocations')
    return 0


sys.exit(main())
