#!/usr/bin/env python3
"""apexternc-sweep.py -- which APE headers declare C functions with no
`extern "C"' guard?

    python3 sys/lib/tests/apexternc-sweep.py            # GATES
    python3 sys/lib/tests/apexternc-sweep.py --control  # strip one guard

***A HEADER WITHOUT THE GUARD IS A LINK ERROR IN C++ AND NOTHING
ELSE.***  It compiles, it preprocesses, every C program is unaffected
-- and a C++ translation unit that calls one of its functions asks the
linker for a MANGLED name that no C library defines.  cpfe said

    main: undefined: _Z6wcslenPKw
    main: undefined: _Z8iswalphaj

and `<wchar.h>' and `<wctype.h>' had no guard at all, while
`<stdio.h>', `<string.h>' and `<ctype.h>' did.

**Measured on the host, by an A/B over one staged copy of the tree**:
with the guards removed, `g++` asks for `_Z6wcslenPKw` and
`_Z7imaxabsx`; with them in, `wcslen` and `imaxabs`.  *The first of
those is the VM's error to the digit*, which is what makes the host
check sound here -- the question is a NAME, and names are what the two
compilers must agree on.

---- WHAT IT GATES ON, AND WHY NOT EVERYTHING -------------------------

165 headers; **28 declare functions and have no guard**, and most are
third-party or Plan 9 library headers (`lua.h', `libsec.h', `mp.h',
`auth.h', `f2c.h', the `unistring' family) where whether C++ should
ever see them is a separate decision nobody has made.  Gating on all
28 would demand 24 changes nobody has argued for.

So the gate is the set the C++ LIBRARY actually includes -- every
`sys/include/ape/c++/*.stdh' names its C headers -- and the rest are
REPORTED.  *A sweep that gates on a decision nobody has taken is a
sweep that gets switched off.*

---- THE EXEMPTION, WHICH COST AN EDIT --------------------------------

***`stddef.h' WAS GUARDED AND SHOULD NOT HAVE BEEN.***  Its one
declaration sits inside `#ifndef __cplusplus' -- C++ has
`std::unreachable' and no `_Noreturn', and the header's own comment
says so -- so C++ never sees it and a guard around it would have put
`extern "C" {' inside a conditional arm whose `}' was outside.  **An
unbalanced brace in the arm nobody compiles**, which is the worst
version of this to ship.

So a declaration that is unreachable from C++ does not count, and the
scanner tracks `#ifndef __cplusplus' / `#if !defined(__cplusplus)'
arms rather than matching lines.  *It was the edit that taught this,
not the reading*, and the sweep exists so the next one is cheaper.
"""

import glob
import os
import re
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
if not os.path.isfile(os.path.join(ROOT, 'CLAUDE.md')):
    sys.exit('apexternc-sweep: ROOT=%s is not the repository root -- fix the\n'
             'dirname count.  sys/lib/tests is THREE levels below the root;\n'
             'this guard has fired five times in this tree.' % ROOT)

APE = os.path.join(ROOT, 'sys', 'include', 'ape')
CXX = os.path.join(APE, 'c++')

IF = re.compile(r'^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)')
# A function declaration at file scope.  Deliberately conservative: a
# leading type and a `(' on the same line.  It is a LOWER BOUND, which
# is the right direction for a gate.
DECL = re.compile(r'^[A-Za-z_][A-Za-z0-9_ \t\*]*\**\s*[A-Za-z_][A-Za-z0-9_]*\s*\(')
# `#ifndef __cplusplus' and `#if !defined(__cplusplus)'.  ***THE FIRST
# VERSION ANCHORED THIS AT `^ndef' AND SO MATCHED NEITHER***, which made
# the sweep report `stddef.h' -- the one header the edit had already
# proved needs no guard.  A sweep whose first run names a file you have
# just decided about is the cheapest possible chance to catch it.
NOTCXX = re.compile(r'ifndef\s+__cplusplus|!\s*defined\s*\(?\s*__cplusplus')


def declares_visible_to_cxx(path):
    """Does this header declare a function on a path C++ can reach?"""
    skip = 0          # depth of enclosing `not C++' arms
    depth = 0
    stack = []
    for line in open(path, errors='replace'):
        m = IF.match(line)
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ('if', 'ifdef', 'ifndef'):
                depth += 1
                hidden = bool(NOTCXX.search(kind + ' ' + rest))
                stack.append(hidden)
                if hidden:
                    skip += 1
            elif kind == 'endif':
                if stack:
                    if stack.pop():
                        skip -= 1
                depth = max(0, depth - 1)
            elif kind == 'else':
                # the `else' of `#ifndef __cplusplus' IS the C++ arm
                if stack:
                    was = stack[-1]
                    stack[-1] = not was
                    skip += (-1 if was else 1)
            continue
        if skip:
            continue
        s = line.strip()
        if not s or s.startswith(('/*', '*', '//', '#')):
            continue
        if s.endswith(';') and DECL.match(s) and '=' not in s.split('(')[0]:
            return True
    return False


def cxx_reachable():
    out = set()
    for f in glob.glob(os.path.join(CXX, '*.stdh')):
        for m in re.finditer(r'#\s*include\s*<([a-z0-9_]+\.h)>', open(f, errors='replace').read()):
            out.add(m.group(1))
    return out


def sweep(apedir, quiet=False):
    reach = cxx_reachable()
    gated, reported = [], []
    for path in sorted(glob.glob(os.path.join(apedir, '*.h'))):
        name = os.path.basename(path)
        text = open(path, errors='replace').read()
        if 'extern "C"' in text:
            continue
        if not declares_visible_to_cxx(path):
            continue
        (gated if name in reach else reported).append(name)
    if not quiet:
        print('headers the C++ library includes, with no extern "C" guard: %d'
              % len(gated))
        for n in gated:
            print('   *** %s' % n)
        print('\nother headers in the same state (reported, not gated): %d'
              % len(reported))
        print('   ' + ' '.join(reported))
        print('\nThese are third-party or Plan 9 library headers; whether C++')
        print('should see them at all is a decision nobody has taken, and a')
        print('gate on them would demand changes nobody has argued for.')
    return gated


def main():
    if not os.path.isdir(APE):
        sys.exit('apexternc-sweep: no %s' % APE)

    if '--control' in sys.argv[1:]:
        # ***A DELIBERATE BREAK.***  There is no oracle for "should this
        # header have a guard", so the control strips one from a header
        # that HAS it and is C++-reachable, and the sweep must name it.
        reach = cxx_reachable()
        victim = None
        for path in sorted(glob.glob(os.path.join(APE, '*.h'))):
            n = os.path.basename(path)
            if n in reach and 'extern "C"' in open(path, errors='replace').read() \
                    and declares_visible_to_cxx(path):
                victim = path
                break
        if victim is None:
            sys.exit('apexternc-sweep: no guarded C++-reachable header to '
                     'strip -- the control is void')
        with tempfile.TemporaryDirectory() as d:
            for path in glob.glob(os.path.join(APE, '*.h')):
                t = open(path, errors='replace').read()
                if path == victim:
                    t = t.replace('extern "C" {', '/* stripped */').replace(
                        'extern "C"', '/* stripped */')
                open(os.path.join(d, os.path.basename(path)), 'w').write(t)
            # the c++/ directory is read from the real tree for the
            # reachable set; only the C headers are staged.
            global APE_SAVED
            got = sweep(d, quiet=True)
            name = os.path.basename(victim)
            if name not in got:
                sys.exit('apexternc-sweep: ***THE CONTROL DID NOT FIRE.***  '
                         '%s was stripped and the sweep reported %r'
                         % (name, got))
            base = sweep(APE, quiet=True)
            if len(got) != len(base) + 1:
                sys.exit('apexternc-sweep: the control changed %d findings, '
                         'want 1 -- the break is not isolated'
                         % (len(got) - len(base)))
            print('control: stripping the guard from %s is reported, and '
                  'nothing else moved' % name)
            return 0

    gated = sweep(APE)
    print()
    if gated:
        print('*** %d C++-reachable header(s) with no extern "C" guard. ***'
              % len(gated))
        print('Every C++ call into one asks the linker for a MANGLED name')
        print('that no C library defines, and nothing else goes wrong.')
        return 1
    print('every C++-reachable header is guarded')
    return 0


sys.exit(main())
