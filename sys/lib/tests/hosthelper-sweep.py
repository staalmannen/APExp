#!/usr/bin/env python3
#
# hosthelper-sweep -- which mkfile recipes RUN a binary the same mkfile
# builds, and is that binary built for the machine doing the build?
#
#   python3 sys/lib/tests/hosthelper-sweep.py
#
# IT DOES NOT GATE, and the reason is the whole point of the sweep:
# **two different things look identical here and they cost wildly
# different amounts to fix.**
#
#   * A SINGLE-FILE HELPER.  bash's `mkbuiltins' reads the .def files
#     and writes .c files; muon's `embedder' reads .meson scripts and
#     prints a C header.  Built with a bare `pcc' each comes out for
#     `$objtype' and the next recipe answers `exec header invalid'.
#     `rc/bin/ape/hostcc' is the fix and it is one word.
#   * A HELPER THAT IS THE PORT.  `miniperl' writes `perlmain.c' and
#     `objc1' writes the C that `$thecc' then compiles, so **their
#     output is architecture-independent too** and `hostcc' is the
#     right SHAPE -- but building them for the host means building
#     libperl, or objc's runtime, a second time.  Real work, not one
#     line.
#
# ***An earlier version of this header said the second group CANNOT be
# host-built because "the binary it runs is the product".  That is
# wrong*** -- all four emit architecture-independent text -- **and it
# is what made `embedder' sit in the second group for a round when it
# belongs in the first.**  It was classified from its position in a
# list rather than from reading `tools/embedder.c'.
#
# So this reports.  A `no' in the `hostcc' column is a question --
# which kind is it, and open the tool to find out -- not a defect.
#
# WHY IT EXISTS.  `objtype=386 mk install' found bash's `mkbuiltins' the
# expensive way, four blockers into a cross build, and the comment
# directly above that rule had said "compile it with the HOST cc, not
# with our cross pcc" since the day it was written.  *A file that states
# the rule and then does not follow it* -- the fourth in that walk,
# after LibreSSL's arch names, chicken's word-size flags and bash's own
# `LD'.  **On a native build `$objtype' and `$cputype' are the same
# string, so no build anyone has ever run could have shown any of
# them.**  A sweep is the only instrument that can.
#
# WHAT IT CANNOT SEE, said plainly so the clean run is not misread:
#   * a helper executed through a variable this file fails to resolve,
#   * a helper run from a DIFFERENT mkfile than the one that builds it,
#     which is why `objc' does not appear: its stage 1 is in `mkfile'
#     and the stage that runs it is in `mkfile.rebuild',
#   * anything reached through `$MKSHELL' or a nested `mk'.
# It resolves one level of `NAME=./thing' indirection and no more.
#
# AND A HIT IS NOT AUTOMATICALLY LIVE.  `external/f2c/src/mkfile.plan9'
# builds `xsum' and runs it from an `xsum.out' target, and **nothing in
# this tree includes that mkfile** -- `cmd/f2c/mkfile' compiles f2c
# from `$F2CSRC/src/%.c' with its own rules.  The only occurrences of
# the name `mkfile.plan9' anywhere are inside f2c's own source
# listings.  So it is a vendored file nobody runs, and it is left
# alone: *an untriggered rule gets no diagnostic from anyone*, which
# this tree has recorded twice before, and editing upstream's dead
# makefile would buy nothing.  Checked once, written down here, so the
# next reader does not check it again.
import os
import re
import sys

# Three levels up from sys/lib/tests, and `ishadow-sweep' got this
# wrong by one, so the guard below checks rather than trusts.
ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                    '..', '..', '..')
ROOT = os.path.normpath(ROOT)

# A recipe line that runs `./x', `../x', `../../x' ...  The name must
# not look like a source file: those are arguments, not commands.
RUN = re.compile(r'(?:^|[\s;&|(]|&&|\|\|)((?:\.\./)*\./?|(?:\.\./)+)'
                 r'([A-Za-z_][A-Za-z0-9_.-]*)')
SRCEXT = ('.c', '.h', '.def', '.y', '.l', '.in', '.sh', '.md', '.txt',
          '.a', '.o', '.out', '.tab', '.am', '.ac', '.m4', '.py')
ASSIGN = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(\S+)\s*$')


def mkfiles():
    for base, dirs, names in os.walk(ROOT):
        if '.git' in dirs:
            dirs.remove('.git')
        for n in names:
            if n == 'mkfile' or n.startswith('mkfile.'):
                yield os.path.join(base, n)


def scan(path):
    """Return [(lineno, name, built_here, uses_hostcc)] for this mkfile."""
    try:
        lines = open(path, errors='replace').read().split('\n')
    except OSError:
        return []

    # one level of `MKBUILTINS=./mkbuiltins'
    alias = {}
    for ln in lines:
        m = ASSIGN.match(ln)
        if m and m.group(2).startswith(('./', '../')):
            alias[m.group(1)] = m.group(2).lstrip('./')

    # rules: target line at column 0 with a `:', recipe lines tabbed
    builds = {}          # basename -> recipe text of the rule building it
    target = None
    recipe = []
    for ln in lines:
        if ln.startswith('\t'):
            if target is not None:
                recipe.append(ln)
            continue
        if target is not None:
            for t in target:
                builds[t] = '\n'.join(recipe)
            target, recipe = None, []
        if ln and not ln.startswith('#') and ':' in ln:
            head = ln.split(':', 1)[0]
            if '=' in head:
                continue
            # A target can be named through a variable -- bash's rule
            # is `$MKBUILTINS: ...'.  **Expanding aliases in recipes
            # and not in targets is what made the first run of this
            # sweep miss its own positive control**, which is the only
            # reason it is right now: the recipe matched, the rule did
            # not, and the pair never met.
            for var, val in alias.items():
                head = head.replace('$' + var, val)
            target = [os.path.basename(t.lstrip('./'))
                      for t in head.split()]
    if target is not None:
        for t in target:
            builds[t] = '\n'.join(recipe)

    hits = []
    seen = set()
    for i, ln in enumerate(lines, 1):
        if not ln.startswith('\t'):
            continue
        text = ln
        for var, val in alias.items():
            text = text.replace('$' + var, './' + val)
        for _, name in RUN.findall(text):
            if name.endswith(SRCEXT) or name in seen:
                continue
            if name not in builds:
                continue
            seen.add(name)
            hits.append((i, name, True, 'hostcc' in builds[name]))
    return hits


def main():
    if not os.path.isdir(os.path.join(ROOT, 'sys', 'include', 'ape')):
        print('hosthelper-sweep: %s is not an APExp root -- refusing '
              'to report' % ROOT)
        return 2

    rows = []
    for path in sorted(mkfiles()):
        for lineno, name, _, hostcc in scan(path):
            rows.append((os.path.relpath(path, ROOT), lineno, name, hostcc))

    if not rows:
        print('hosthelper-sweep: no mkfile runs a binary it builds.')
        print('That is a CLEAN run and not a broken sweep only if you')
        print('expected it; bash/mkfile is the known positive control.')
        return 0

    w = max(len(r[0]) for r in rows)
    print('%-*s  %-6s %-14s %s' % (w, 'mkfile', 'line', 'runs', 'hostcc?'))
    for path, lineno, name, hostcc in rows:
        print('%-*s  %-6d %-14s %s'
              % (w, path, lineno, name, 'yes' if hostcc else 'no'))
    n_no = sum(1 for r in rows if not r[3])
    print()
    print('---- %d executed-in-tree binaries, %d not built with hostcc'
          % (len(rows), n_no))
    print('A `no\' is a QUESTION, not a defect.  Open the tool: if it '
          'is a')
    print('single file it wants hostcc; if it IS the port (miniperl, '
          'objc1)')
    print('that needs the port built twice.  See the header.')
    return 0


if __name__ == '__main__':
    sys.exit(main())
