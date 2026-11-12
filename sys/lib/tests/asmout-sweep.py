#!/usr/bin/env python3
"""asmout-sweep.py -- which vendored GNU extended asm could kencc reach?

    python3 sys/lib/tests/asmout-sweep.py            # report
    python3 sys/lib/tests/asmout-sweep.py --all      # every site, every class
    python3 sys/lib/tests/asmout-sweep.py --control  # MUST fire; see below

***IT DOES NOT GATE, AND THAT IS DELIBERATE.***  Most hits are in
directories this tree never compiles -- `contrib/', `tests/',
`gnulib-tests/', an OS/2 port, a RISC-V backend -- and nothing here
reads a mkfile, so **only a build settles reachability**.  A gate would
demand changes to code that is never compiled.  Read the list; it is
short.

WHAT IT ASKS.  kencc has no GNU extended asm: `cc/lex.c' swallows the
whole `__asm__ ( ... )' construct.  For a barrier that loses a FENCE.
For an asm with an OUTPUT operand it loses the VALUE -- the named C
object is simply never assigned, and `6c -S' emitted a read of an
uninitialised stack slot, returned as the answer.  `cc/lex.c' now
refuses that shape outright (`asmout-probe.c' / `asmok-probe.c'), so
**this sweep exists to say where the next full build would stop.**

THE CLASSES, and the only one that matters is the third:

  guarded-by-compiler    the enclosing `#if' names `__GNUC__',
                         `_MSC_VER', `__clang__' or similar.  kencc
                         defines none of them, so the arm is not taken.
                         *This is the correct way to write it*, and 278
                         of 403 sites already do.
  other-arch-or-feature  the guard names MIPS, ARM, PowerPC, RISC-V,
                         LoongArch, a BSD, a feature macro... -- not
                         reached on APExp amd64, but not reached for a
                         reason this script cannot check either.
  X86-REACHABLE          **the dangerous class**: the guard asks for
                         `__i386__'/`__x86_64__' and does NOT also ask
                         for a compiler.  ***APExp DEFINES `__x86_64__'
                         ITSELF*** (`amd64/include/ape/_apetypes.h:59'),
                         which is right for every architecture question
                         and is also how a package picks its x86 asm --
                         so one define serves two purposes and only one
                         of them is true here.
  UNGUARDED              no enclosing `#if' at all.

THE MEASURED ANSWER, and the reason this is a report rather than an
alarm: **403 sites, and the X86-REACHABLE + UNGUARDED classes come to
28, of which not one is compiled by this tree.**  Two were checked by
hand and both are already solved, independently of this round:

  * `zstd/lib/common/cpu.h' reads `!defined(Plan9) && defined(__x86_64__)'
    and `lib/zstd/mkfile' passes `-DPlan9'.  **Somebody met this exact
    class before and fixed it the same way**, which is corroboration
    that the shape is real and that a per-package guard is this tree's
    remedy for it.
  * php's `Zend/zend_float.h' needs `HAVE_FPU_INLINE_ASM_X86`, which
    the hand-answered `config.h' leaves `#undef', *and* `!__x86_64__',
    which is false here -- excluded twice.  `php-mirror.sh --compile'
    answering **581 TUs, 0 errors** with the strict compiler is the
    independent confirmation, and it covers the whole package rather
    than the two files anyone read.

***AND THE PREDICTION WAS CONFIRMED BY THE THING THAT SETTLES IT: A
FULL `mk install' COMPLETED.***  This sweep's whole purpose was to
answer "did making the compiler refuse an output-asm stop the tree
building", it answered no, and the next tree-wide rebuild on the VM
finished.  *A sweep that predicts a build outcome is cheap to check
and expensive to skip* -- and this one was written BEFORE the rebuild,
which is what makes the agreement worth anything.

The rest are `contrib/`, `tests/`, `gnulib-tests/`, perl's OS/2 port,
go1.4's `dist` under `#ifndef PLAN9`, sljit's RISC-V and LoongArch
backends, php-fpm (CLI only here) and opcache's darwin JIT TLS.

LIMITS, stated because a sweep that hides them is worse than none:

  * **It reads `#if` TEXT, not `#if` ARITHMETIC.**  A guard naming a
    macro that is `#define`d to 0 reads as present.
  * **It does not know what the build compiles.**  That is the whole
    reason it does not gate.
  * **The `#if` stack is textual**: `#elif' replaces the top of the
    stack and `#else' records `!(prev)' rather than the real negation,
    so a deeply nested site's printed guard is a hint, not a formula.
    *The classification only ever reads the stack for the presence of
    names*, which survives that.

THE CONTROL IS EXTERNAL AND HAS TO BE, since the one real finding is
already fixed: `--control' stages libwebp's PRE-FIX
`endian_inl_utils.h' out of git and must classify it X86-REACHABLE.
*A sweep whose positive control is a shape it can no longer find in the
tree is a sweep nobody has seen fire* -- the `truefalse-sweep` rule.
"""

import collections
import os
import pathlib
import re
import subprocess
import sys

# Compiler macros kencc does not define.  A guard naming one of these
# cannot select its arm here, whatever else it says.
COMPILER_MACROS = (
    '__GNUC__', '_MSC_VER', '__clang__', '__INTEL_COMPILER',
    '__SUNPRO_C', '__IBMC__', '__TINYC__', '__WATCOMC__', '__PGI',
    '__xlc__', '__COMPCERT__', '__CC_ARM',
)
X86_MACROS = re.compile(r'__i386__|__i386\b|__x86_64__|__amd64__|__amd64\b'
                        r'|_M_X64|_M_IX86')

ASM = re.compile(r'(__asm__|__asm\b|\basm)\s*'
                 r'(__volatile__|volatile|__inline__|inline|goto)?\s*\(', re.S)
COND = re.compile(r'^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$')


def outsites(text):
    """Line numbers of asm constructs with an output operand.

    The output section is what lies between the first and second `:'
    at the construct's top level; a constraint there beginning `=' or
    `+' names a C object the asm WRITES.  `:: "r"(x)' has an empty
    output section and is not a hit -- which is the discriminator the
    compiler uses too, so the two agree by construction.
    """
    out = []
    for m in ASM.finditer(text):
        w = text[m.end():m.end() + 2000]
        depth, end = 1, -1
        for i, ch in enumerate(w):
            if ch == '(':
                depth += 1
            elif ch == ')':
                depth -= 1
                if depth == 0:
                    end = i
                    break
        if end < 0:
            continue
        body = w[:end]
        if ':' not in body:
            continue
        sec = body.split(':', 1)[1].split(':', 1)[0]
        if re.search(r'"\s*[=+]', sec):
            out.append(text[:m.start()].count('\n') + 1)
    return out


def condstack(text):
    """line -> list of enclosing #if conditions, as TEXT.

    Continuations matter: a condition ending in `\\' carries on, and
    libwebp's own patched guard spans two lines -- reading only the
    first would drop the `&& defined(__GNUC__)' that makes it safe.
    """
    lines = text.split('\n')
    stack, per = [], {}
    n = 0
    while n < len(lines):
        raw = lines[n]
        start = n + 1
        joined = raw
        while joined.rstrip().endswith('\\') and n + 1 < len(lines):
            n += 1
            joined = joined.rstrip()[:-1] + ' ' + lines[n]
        m = COND.match(joined)
        if m:
            kind, rest = m.group(1), m.group(2).strip()
            if kind == 'if':
                stack.append(rest)
            elif kind == 'ifdef':
                stack.append('defined(%s)' % rest)
            elif kind == 'ifndef':
                stack.append('!defined(%s)' % rest)
            elif kind == 'elif':
                if stack:
                    stack[-1] = rest
            elif kind == 'else':
                if stack:
                    stack[-1] = '!(%s)' % stack[-1]
            elif kind == 'endif':
                if stack:
                    stack.pop()
        for k in range(start, n + 2):
            per[k] = list(stack)
        n += 1
    return per


def classify(cond):
    if any(u in cond for u in COMPILER_MACROS):
        return 'guarded-by-compiler'
    if not cond.strip():
        return 'UNGUARDED'
    if X86_MACROS.search(cond):
        return 'X86-REACHABLE'
    return 'other-arch-or-feature'


def scan(text):
    per = condstack(text)
    for n in outsites(text):
        cond = ' && '.join(per.get(n, []))
        yield n, cond, classify(cond)


def main():
    here = pathlib.Path(__file__).resolve().parent
    # `sys/lib/tests' is THREE levels below the root, and writing two
    # is the trap this directory has now sprung FIVE times -- on
    # `ishadow-sweep', `rceq-sweep', `apfunc-sweep', `cpp-xcheck' (four
    # there) and here, on the first run, with the guard catching it
    # each time.  *The guard is the instrument that works.*
    root = here.parent.parent.parent
    if not (root / 'CLAUDE.md').is_file():
        sys.exit('asmout-sweep: ROOT=%s is not the repository root' % root)
    ext = root / 'sys/src/external'
    if not ext.is_dir():
        sys.exit('asmout-sweep: no %s' % ext)

    mode = sys.argv[1] if len(sys.argv) > 1 else ''
    if mode not in ('', '--all', '--control'):
        sys.exit('usage: asmout-sweep.py [--all|--control]')

    if mode == '--control':
        rel = 'sys/src/external/libwebp/src/utils/endian_inl_utils.h'
        try:
            old = subprocess.run(
                ['git', '-C', str(root), 'show', 'HEAD~1:' + rel],
                capture_output=True, text=True, check=True).stdout
        except Exception as e:
            sys.exit('asmout-sweep: CONTROL could not stage %s: %s' % (rel, e))
        got = [c for _, _, c in scan(old)]
        if 'X86-REACHABLE' not in got:
            print('asmout-sweep: CONTROL FAILED -- the pre-fix libwebp header')
            print('asmout-sweep: classified as %s, not X86-REACHABLE.' % got)
            return 1
        cur = (root / rel).read_text(errors='ignore')
        curc = [c for _, _, c in scan(cur)]
        if 'X86-REACHABLE' in curc:
            print('asmout-sweep: CONTROL FAILED -- the CURRENT libwebp header')
            print('asmout-sweep: is still X86-REACHABLE; the fix is not in.')
            return 1
        print('asmout-sweep: control OK -- pre-fix libwebp fires '
              '(%d sites), current does not' % got.count('X86-REACHABLE'))
        return 0

    rows = []
    for p in sorted(ext.rglob('*')):
        if p.suffix not in ('.c', '.h') or not p.is_file():
            continue
        try:
            t = p.read_text(errors='ignore')
        except OSError:
            continue
        if '"=' not in t and '"+' not in t:
            continue
        for n, cond, cls in scan(t):
            rows.append((str(p.relative_to(ext)), n, cond, cls))

    counts = collections.Counter(r[3] for r in rows)
    want = ('X86-REACHABLE', 'UNGUARDED')
    for rel, n, cond, cls in rows:
        if mode == '--all' or cls in want:
            print('  %-14s %s:%d' % (cls, rel, n))
            if cond:
                print('                 %s' % cond[:110])
    print()
    for k in ('X86-REACHABLE', 'UNGUARDED', 'other-arch-or-feature',
              'guarded-by-compiler'):
        print('asmout-sweep: %-22s %d' % (k, counts.get(k, 0)))
    print('asmout-sweep: %d sites in %d files -- READ, this does not gate'
          % (len(rows), len({r[0] for r in rows})))
    return 0


if __name__ == '__main__':
    sys.exit(main())
