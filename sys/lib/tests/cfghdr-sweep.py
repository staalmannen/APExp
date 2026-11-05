#!/usr/bin/env python3
"""
cfghdr-sweep -- does a hand-answered `config.h' answer the questions
its own TEMPLATE asks, and does it carry the template's verbatim text?

    python3 sys/lib/tests/cfghdr-sweep.py            # every pair it knows
    python3 sys/lib/tests/cfghdr-sweep.py T.h.in A.h # one pair
    python3 sys/lib/tests/cfghdr-sweep.py --control

A HOST SWEEP.  **It GATES on one thing only** -- see "what it gates
on" below -- and reports the rest, because most of what it finds is a
deliberate omission rather than a fault.

------------------------------------------------------------------
WHAT IT IS FOR, AND IT COST A VM ROUND TRIP.

This tree hand-maintains a `config.h' for perl, bash, clisp, chicken
and now php, each against an autoconf template that is vendored
beside it.  php's was written by reading the GENERATED config from a
host `configure' run and answering each capability -- which is the
right method for the `#undef' lines and **blind to everything else**.

`autoheader' emits only `#undef NAME' lines.  Anything spelled
`#define' in a template is text copied STRAIGHT THROUGH, and
`main/php_config.h.in:7-15' copies three:

    #if defined(__GNUC__) && __GNUC__ >= 4
    # define ZEND_API __attribute__ ((visibility("default")))
    ...
    #define ZEND_DLIMPORT

Reading the generated file as a list of capabilities does not show
them, so the hand-written one had none, and `Zend/zend_map_ptr.h:82'
answered

    not a function
    not a parameter: zend_map_ptr_reset
    syntax error, last name: ZEND_API

-- an undefined identifier where a storage class belongs.  *Every
`ZEND_API' in php is that shape*, so the first file to declare
anything would have failed whichever it was.  **21 names were missing
in all**, and the one `grep` that would have shown them is this file.

------------------------------------------------------------------
WHAT IT GATES ON, AND WHY ONLY THAT.

A template `#define` the answered file does not define.  That is the
copied-through text, it is never optional, and there are three of
them in php's.

It does NOT gate on a template `#undef` the answered file is silent
about.  php's template asks about 1100 names, hundreds of them
`COMPILE_DL_<EXT>` for extensions this port does not build, and
silence there is the correct answer.  *A gate that demands an answer
to every question would demand noise*, which is the same reason
`hosthelper-sweep` does not gate.

***AND ITS LIMIT, STATED RATHER THAN DISCOVERED LATER.***  It reads
names, not arms.  A template that `#define's something only inside a
platform arm nobody takes -- clisp's `_Restrict' and `__restrict__'
live under `#if defined __SUNPRO_CC' with no `#else' -- is reported
as missing when the answered file is right to omit it.  Telling those
apart needs real preprocessing, which is more than this should do, so
a finding is READ rather than obeyed and `PAIRS' holds only the pairs
whose findings someone has looked at.

It also reports, without gating, a name the answered file defines
that the template has never heard of.  That is usually a port's own
addition and sometimes a typo; only the author can tell, so it is
printed rather than counted.
"""

import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__),
                                    '..', '..', '..'))
if not os.path.isdir(os.path.join(ROOT, 'sys', 'src', 'ape')):
    sys.exit('cfghdr-sweep: %s is not the APExp root -- refusing to '
             'report 0 findings from the wrong tree' % ROOT)

# (template, answered) -- both relative to the repository root.
PAIRS = [
    ('sys/src/external/php/main/php_config.h.in',
     'sys/src/ape/cmd/php/cfg/main/php_config.h'),
]

DEFINE = re.compile(r'^\s*#\s*define\s+([A-Za-z_][A-Za-z0-9_]*)')
IFNDEF = re.compile(r'^\s*#\s*ifndef\s+([A-Za-z_][A-Za-z0-9_]*)')
UNDEF_C = re.compile(r'^\s*/\*\s*#\s*undef\s+([A-Za-z_][A-Za-z0-9_]*)\s*\*/')
UNDEF_H = re.compile(r'^\s*#\s*undef\s+([A-Za-z_][A-Za-z0-9_]*)')


def scan(path):
    """(defines, undefs) as name sets.

    ***THE INCLUDE GUARD IS EXCLUDED, AND THE CONTROL IS WHAT SAID
    SO.***  A guard is a `#define' like any other, so the first
    version of this sweep demanded that an answered file carry the
    TEMPLATE's guard name -- which is nonsense: `X_CONFIG_H' came
    back as a gating finding beside the one real one.  php's happens
    to be `PHP_CONFIG_H' in both files, so the live pair could never
    have shown it.  *A fixture is allowed to differ from the real
    case in exactly the way that exposes the bug.*
    """
    d, u = set(), set()
    guarded = set()
    with open(path, encoding='utf-8', errors='replace') as f:
        for line in f:
            m = IFNDEF.match(line)
            if m:
                guarded.add(m.group(1))
            m = UNDEF_C.match(line)       # the answered form, first:
            if m:                         # `/* #undef X */' also matches
                u.add(m.group(1))         # nothing else, but check it
                continue                  # before DEFINE either way
            m = DEFINE.match(line)
            if m:
                if m.group(1) not in guarded:   # not the include guard
                    d.add(m.group(1))
                continue
            m = UNDEF_H.match(line)
            if m:
                u.add(m.group(1))
    return d, u


def check(tmpl, ans):
    """Returns the number of GATING findings."""
    tdef, tundef = scan(tmpl)
    adef, aundef = scan(ans)
    gating = 0

    # 1. the copied-through text.  This is the gate.
    #
    # ***A NAME THE TEMPLATE BOTH `#define's AND `#undef's IS A
    # QUESTION, NOT VERBATIM TEXT***, and subtracting `tundef' is what
    # says so.  clisp's template `#define's WORDS_BIGENDIAN inside an
    # `#if defined AC_APPLE_UNIVERSAL_BUILD' arm and `#undef's it in
    # the `#else' -- the second is the real question, and the answered
    # file answers it.  Without this the sweep reported it as missing
    # verbatim text, which is the cry-wolf failure.
    missing = sorted(tdef - tundef - adef)
    if missing:
        print('  MISSING template #defines -- these are verbatim text,')
        print('  not capability answers, and are never optional:')
        for n in missing:
            print('      %s' % n)
        gating += len(missing)

    # 2. questions left unanswered.  Information only.
    silent = sorted(tundef - adef - aundef)
    print('  %d of the template\'s %d questions are unanswered'
          % (len(silent), len(tundef)))
    if len(silent) <= 12:
        for n in silent:
            print('      %s' % n)
    else:
        print('      (too many to list; most will be deliberate)')

    # 3. names the template never heard of.  Information only.
    unknown = sorted((adef | aundef) - tdef - tundef)
    if unknown:
        print('  %d name(s) answered that the template does not ask about:'
              % len(unknown))
        for n in unknown:
            print('      %s' % n)
    return gating


CONTROL_TMPL = """\
#ifndef X_CONFIG_H
#define X_CONFIG_H

#if defined(__GNUC__)
# define COPIED_THROUGH __attribute__((whatever))
#else
# define COPIED_THROUGH
#endif

/* a capability */
#undef HAVE_ANSWERED

/* another */
#undef HAVE_SILENT
#endif
"""

CONTROL_ANS = """\
#define HAVE_ANSWERED 1
/* #undef HAVE_DENIED */
#define INVENTED_HERE 1
"""


def control():
    """The template `#define' must gate; the unanswered question must
    not; the invented name must be reported and not counted.  *All
    three in one fixture*, because the bug this sweep exists for was a
    missing `#define' sitting beside hundreds of correctly unanswered
    `#undef's -- a control with only the first would pass for a sweep
    that gated on everything."""
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        t = os.path.join(d, 't.h.in'); open(t, 'w').write(CONTROL_TMPL)
        a = os.path.join(d, 'a.h');    open(a, 'w').write(CONTROL_ANS)
        print('control:')
        n = check(t, a)
    ok = (n == 1)
    print('control: %d gating finding(s), want 1 (COPIED_THROUGH) -- %s'
          % (n, 'ok' if ok else 'FAILED'))
    return 0 if ok else 1


def main():
    if '--control' in sys.argv:
        return control()
    args = [a for a in sys.argv[1:] if not a.startswith('-')]
    pairs = [(args[0], args[1])] if len(args) == 2 else \
            [(os.path.join(ROOT, t), os.path.join(ROOT, a))
             for t, a in PAIRS]
    gating = 0
    for tmpl, ans in pairs:
        if not (os.path.exists(tmpl) and os.path.exists(ans)):
            print('cfghdr-sweep: skipping, missing %s or %s'
                  % (tmpl, ans))
            continue
        print('%s' % os.path.relpath(ans, ROOT))
        gating += check(tmpl, ans)
        print()
    print('---- %d template #define(s) not carried through' % gating)
    if gating:
        print('Copy them VERBATIM from the template: they are not')
        print('capability answers and autoheader never generates them.')
    return gating


if __name__ == '__main__':
    sys.exit(main())
