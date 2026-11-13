#!/usr/bin/env python3
"""cxxbuiltin-sweep.py -- a compiler builtin the C++ library uses with
no way to say "this compiler has not got one".

    python3 sys/lib/tests/cxxbuiltin-sweep.py            # the BARE ones
    python3 sys/lib/tests/cxxbuiltin-sweep.py --all      # guarded too
    python3 sys/lib/tests/cxxbuiltin-sweep.py --control  # MUST fire

***IT GATES.*** Unlike `baketype-sweep', this one has no arms-nobody-
takes problem: a `__builtin_x' reached with no enclosing capability
test is a hard error on any compiler without it, full stop. cpfe is
such a compiler and it is the one this library is for.

WHAT IT COMES FROM
==================

`sys/include/ape/c++' is Paragon Portable STL, written for gcc, clang
and MSVC. Four files chose an implementation by COMPILER IDENTITY, and
fixing those four was treated as the whole class. **It was half.**

The other half is a builtin used with NO test of any kind. Nine of
them sat in `common/numeric_limits.h' -- `__builtin_huge_valf',
`__builtin_nanf', `__builtin_nans' and their double forms -- outside
both `limits_msvc/' and `limits_clang_gcc/', so neither selector
could reach them; one more was `memory/addressof.h', which has no
sibling implementation at all. ***They cost a whole VM round***: the
selectors were fixed, the headers compiled on the host, cpfe went from
16 errors to 7, and all 7 were this.

**The host harness could not have caught them and that is the point.**
`cxxlib-host.sh --portable' defines `PSTL_NO_COMPILER_BUILTINS', which
forces the SELECTORS; a bare `__builtin_x' answers to no macro, and
g++ has the builtin, so the portable run compiled it happily. *A flag
that forces the arms you know about says nothing about the code that
has no arms.* This sweep reads the text instead.

WHAT COUNTS AS GUARDED
======================

  GUARDED  the use sits inside an `#if' mentioning `__has_builtin',
           `PSTL_HAS_', `_MSC_VER', `__GNUC__' or `__clang__' ...
  ... OR   the file sits in a `builtin/' directory whose PARENT picks
           between it and a `generic/' sibling. That indirection is
           upstream's normal arrangement and is correct: the guard is
           at the include, not at the use.
  BARE     neither -- the dangerous class.

LIMITS, stated rather than discovered later

  * **Comments and string literals are blanked first.** Without that
    the sweep reports its own explanatory prose, which is how
    `truefalse-sweep' learned the same lesson; three of this file's
    first 25 hits were comments naming the builtin they had just
    guarded away.
  * It reads `#if' TEXT, not arithmetic.
  * A `builtin/' directory with NO `generic/' sibling is reported,
    because then the parent has nothing to select.

THE CONTROL HAS TWO HALVES, because one alone passes for a sweep that
reports everything: `--control' stages `memory/addressof.h' as it was
before the fix and requires it to come back BARE, *and* requires the
current tree to be clean.
"""

import pathlib
import re
import subprocess
import sys

# Files whose bare builtins are CORRECT, each with the reason, after
# `cfghdr-sweep.py's rule that an exemption list holds only entries
# somebody has actually read.
EXEMPT = {
    # `<source_location>' is C++20 and refuses to compile below it
    # (`#error' at its own line 18, which `eccp --c++14' hits first).
    # `__builtin_FILE/LINE/FUNCTION/COLUMN' are not a shortcut here --
    # they are the ONLY way to implement the header, since the values
    # must come from the CALL SITE's default arguments, and EDG
    # provides them in the mode where the header is usable at all.
    'source_location.stdh',
}

COND = re.compile(r'^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$')
USE = re.compile(r'__builtin_[A-Za-z_0-9]+')
ASKS = re.compile(r'__has_builtin|PSTL_HAS|_MSC_VER|__GNUC__|__clang__')


def blank(text):
    """Replace comment and string-literal bodies with spaces, keeping
    line structure.  A sweep that reads its own prose cries wolf."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        two = text[i:i + 2]
        if two == '/*':
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(''.join(ch if ch == '\n' else ' ' for ch in text[i:j]))
            i = j
        elif two == '//':
            j = text.find('\n', i)
            j = n if j < 0 else j
            out.append(' ' * (j - i))
            i = j
        elif c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            j = min(j + 1, n)
            out.append(''.join(ch if ch == '\n' else ' ' for ch in text[i:j]))
            i = j
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def scan(text, path, has_generic_sibling):
    """yield (builtin, line, guarded)."""
    stack = []
    for n, line in enumerate(blank(text).split('\n'), 1):
        m = COND.match(line)
        if m:
            k, rest = m.group(1), m.group(2).strip()
            if k in ('if', 'ifdef', 'ifndef'):
                stack.append(rest)
            elif k == 'elif' and stack:
                stack[-1] = rest
            elif k == 'else' and stack:
                stack[-1] = 'NOT(%s)' % stack[-1]
            elif k == 'endif' and stack:
                stack.pop()
            continue
        for u in sorted(set(USE.findall(line))):
            guarded = has_generic_sibling or bool(ASKS.search(' '.join(stack)))
            yield u, n, guarded


def sibling(path):
    """True when a header one level up CHOOSES between this file and a
    same-named file in a sister directory.

    ***THE FIRST VERSION HARDCODED `builtin'/`generic' AND SO REPORTED
    TWO FILES THAT ARE PERFECTLY GUARDED.***  Upstream uses that pair
    most often, but also `gcc_clang'/`msvc' (`algorithm/ctz.h') and
    `buildin_realization'/`no_realization'
    (`metaprogramming/constant_evaluation/is_constant_evaluated.h') --
    the same indirection under three different names.  *A rule written
    from the examples in front of you is a rule that fires on the next
    naming convention.*  So the question is asked structurally: does
    some header in the grandparent include this basename from TWO OR
    MORE different subdirectories?
    """
    p = pathlib.Path(path)
    gp = p.parent.parent
    if not gp.is_dir():
        return False
    dirs = set()
    for h in gp.glob('*.h'):
        txt = h.read_text(errors='ignore')
        for d in gp.iterdir():
            if d.is_dir() and ('"%s/%s"' % (d.name, p.name)) in txt:
                dirs.add(d.name)
    return len(dirs) >= 2


def rows_for(root):
    rows = []
    for p in sorted(root.rglob('*.h')) + sorted(root.rglob('*.stdh')):
        try:
            t = p.read_text(errors='ignore')
        except OSError:
            continue
        sib = sibling(p)
        rel = str(p.relative_to(root))
        for u, n, g in scan(t, p, sib):
            rows.append((rel, n, u, g or (rel in EXEMPT)))
    return rows


def main():
    here = pathlib.Path(__file__).resolve().parent
    # `sys/lib/tests' is THREE levels below the root.  The guard in this
    # directory has now fired eight times and always in the same
    # direction.
    root = here.parent.parent.parent
    if not (root / 'CLAUDE.md').is_file():
        sys.exit('cxxbuiltin-sweep: ROOT=%s is not the repository root' % root)
    cxx = root / 'sys/include/ape/c++'
    if not cxx.is_dir():
        sys.exit('cxxbuiltin-sweep: no %s' % cxx)

    mode = sys.argv[1] if len(sys.argv) > 1 else ''
    if mode not in ('', '--all', '--control'):
        sys.exit('usage: cxxbuiltin-sweep.py [--all|--control]')

    if mode == '--control':
        rel = 'sys/include/ape/c++/memory/addressof.h'
        old, rev = None, None
        try:
            revs = subprocess.run(
                ['git', '-C', str(root), 'rev-list', '-n', '40', 'HEAD', '--', rel],
                capture_output=True, text=True, check=True).stdout.split()
        except Exception as e:
            sys.exit('cxxbuiltin-sweep: CONTROL cannot reach git: %s' % e)
        for r in revs:
            t = subprocess.run(['git', '-C', str(root), 'show', '%s:%s' % (r, rel)],
                               capture_output=True, text=True).stdout
            if '__builtin_addressof' in t and 'PSTL_HAS_BUILTIN' not in t:
                old, rev = t, r
                break
        if old is None:
            print('cxxbuiltin-sweep: CONTROL FAILED -- no revision of %s' % rel)
            print('cxxbuiltin-sweep: uses the builtin unguarded; cannot stage it.')
            return 1
        got = [x for x in scan(old, rel, False) if not x[2]]
        if not got:
            print('cxxbuiltin-sweep: CONTROL FAILED -- the pre-fix addressof.h')
            print('cxxbuiltin-sweep: (%s) did not come back BARE' % rev[:12])
            return 1
        print('cxxbuiltin-sweep: control 1/2 OK -- pre-fix addressof.h fires (%s)'
              % rev[:12])
        bare = [r for r in rows_for(cxx) if not r[3]]
        if bare:
            print('cxxbuiltin-sweep: CONTROL FAILED -- the CURRENT tree still has')
            for f, n, u, _ in bare:
                print('cxxbuiltin-sweep:   %s %s:%d' % (u, f, n))
            return 1
        print('cxxbuiltin-sweep: control 2/2 OK -- the current tree is clean')
        return 0

    rows = rows_for(cxx)
    bare = [r for r in rows if not r[3]]
    for f, n, u, g in rows:
        if g and mode != '--all':
            continue
        print('  %s %-32s %s:%d' % ('guarded' if g else 'BARE   ', u, f, n))
    print()
    print('cxxbuiltin-sweep: %d builtin uses, %d BARE' % (len(rows), len(bare)))
    if bare:
        print('cxxbuiltin-sweep: FAILED -- a bare builtin is a hard error on any')
        print('cxxbuiltin-sweep: compiler without it, and cpfe is one.')
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
