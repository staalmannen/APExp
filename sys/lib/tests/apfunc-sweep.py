#!/usr/bin/env python3
#
# apfunc-sweep.py -- does libap DEFINE this function, or only declare it?
#
#	python3 sys/lib/tests/apfunc-sweep.py NAME...
#	python3 sys/lib/tests/apfunc-sweep.py --file names.txt
#	python3 sys/lib/tests/apfunc-sweep.py --control
#
# **IT DOES NOT GATE.**  It answers a question asked while hand-writing
# a `config.h': for each capability a package wants to claim, is there
# an implementation in `sys/src/ape/lib/ap' or only a declaration in
# `sys/include/ape'?  *Claiming one that is only declared is a link
# error; denying one that exists silently drops a feature*, and the two
# failures look nothing alike, which is why this is mechanical.
#
# WHERE IT CAME FROM.  clisp's `configure' cannot run here, so its
# `config.h' is hand-answered as perl's and bash's are, and the first
# draft of this sweep matched a definition as `^name(' -- Plan 9's
# split-line declarator style, a return type on its own line.  **It
# reported `realpath' absent**, and `misc/realpath.c:16' is
# `char *realpath(const char *filename, char *resolved)', the return
# type on the SAME line.  *Every function written in the other style
# was being denied*, and a `config.h' built on that first run would
# have switched off working library calls one at a time with no
# diagnostic from anyone.  Both spellings are matched now.
#
# ***AND THE REPORT SEPARATES THREE STATES, NOT TWO.***  `defined' is an
# implementation; `declared' is a header promise with nothing behind it,
# which is the one that costs a link; `absent' is neither.  A package's
# `config.h' wants `defined' and nothing else, and *the middle state is
# the whole reason the sweep exists* -- a `grep' of the headers alone
# cannot see it, and that is how `realpath' and `nice' came to look the
# same from outside.
#
# **The control is a triple, one of each state**, because a sweep that
# only proves it can say yes has not been shown to say the other two:
# `open' is defined, `nice' is declared by no APE header and implemented
# nowhere, and a made-up name is absent.  *A check that cannot fail is
# not a check*, and a check with three outcomes needs three.

import os
import re
import subprocess
import sys

# `sys/lib/tests' is THREE levels below the repository root, so this is
# four `dirname's and not three.  **The control caught it saying three
# on the first run**, exactly as `ishadow-sweep' and `rceq-sweep' each
# did before it -- `ROOT' came out as `.../APExp/sys', `AP' pointed at
# a directory that does not exist, and every lookup answered `absent'.
# *A sweep whose root is wrong reports a clean, confident, uniform
# answer*, which is the shape that gets believed.  The guard below is
# why this is now three failures that cost one run between them.
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.dirname(os.path.abspath(__file__)))))
AP = os.path.join(ROOT, 'sys/src/ape/lib/ap')
HDR = os.path.join(ROOT, 'sys/include/ape')

if not os.path.isdir(AP) or not os.path.isdir(HDR):
    sys.stderr.write('apfunc-sweep: %s or %s is not a directory -- ROOT is '
                     'wrong, and every answer would be "absent"\n' % (AP, HDR))
    sys.exit(2)

# `nice' is here because no APE header declares it and nothing in libap
# implements it; `open' because both are true of it.  The third is a
# name that cannot exist.
CONTROL = [('open', 'defined'), ('nice', 'absent'),
           ('apexp_no_such_function_', 'absent'),
           # The suffix case, added after the sweep answered `setenv'
           # with `fenv/fenv.c'.  `setenv' is defined, in `env/setenv.c',
           # and a run that names any other file has the `\b' wrong
           # again -- so the control checks WHERE and not just whether.
           ('setenv', 'defined', 'sys/src/ape/lib/ap/env/setenv.c')]


def definition_patterns(name):
    """The two spellings a definition takes in this tree.  Missing the
    second is the bug this sweep was born from.

    **THE `\\b' IS LOAD-BEARING AND ITS ABSENCE COST THE SAME RUN.**
    Without it the second pattern's `[A-Za-z0-9_ \\t]*' prefix happily
    eats the `fe' of `fesetenv(' and reports `setenv' as defined in
    `fenv/fenv.c'.  *It is a hit, so it looks like a measurement*, and
    the name it prints is a real file -- the one shape of wrong answer
    that survives being read.  Every suffix of every libc name is a
    live collision here: `open'/`fopen', `time'/`ctime', `read'/`pread'.
    """
    n = re.escape(name)
    return [
        r'^\b%s[ \t]*\(' % n,                             # type on its own line
        r'^[A-Za-z_][A-Za-z0-9_ \t]*[ \t*]\b%s[ \t]*\(' % n,  # type on this line
    ]


def defined_in(name):
    for pat in definition_patterns(name):
        out = subprocess.run(['grep', '-rlE', pat, AP, '--include=*.c'],
                             capture_output=True, text=True)
        files = out.stdout.strip().splitlines()
        if files:
            return os.path.relpath(files[0], ROOT)
    return None


def declared_in(name):
    out = subprocess.run(['grep', '-rlE', r'\b%s\s*\(' % re.escape(name), HDR],
                         capture_output=True, text=True)
    files = out.stdout.strip().splitlines()
    return os.path.relpath(files[0], ROOT) if files else None


def classify(name):
    where = defined_in(name)
    if where:
        return 'defined', where
    where = declared_in(name)
    if where:
        return 'declared', where
    return 'absent', '-'


def run(names):
    counts = {'defined': 0, 'declared': 0, 'absent': 0}
    for name in names:
        state, where = classify(name)
        counts[state] += 1
        print('%-24s %-9s %s' % (name, state, where))
    print('-- defined %d  declared-only %d  absent %d'
          % (counts['defined'], counts['declared'], counts['absent']))
    return counts


def control():
    ok = True
    for entry in CONTROL:
        name, want = entry[0], entry[1]
        wantwhere = entry[2] if len(entry) > 2 else None
        state, where = classify(name)
        bad = state != want or (wantwhere is not None and where != wantwhere)
        if bad:
            ok = False
        print('%-24s want %-9s got %-9s %-8s %s'
              % (name, want, state, 'MISMATCH' if bad else 'ok', where))
        if bad and wantwhere:
            print('%-24s   expected it in %s' % ('', wantwhere))
    print('control %s' % ('fires on all three states' if ok else 'FAILED'))
    return 0 if ok else 1


def main():
    args = sys.argv[1:]
    if '--control' in args:
        return control()
    if args[:1] == ['--file']:
        names = [l.strip() for l in open(args[1]) if l.strip()]
    elif args:
        names = args
    else:
        print(__doc__ or 'usage: apfunc-sweep.py NAME... | --file f | --control')
        return 1
    run(names)
    return 0


if __name__ == '__main__':
    sys.exit(main())
