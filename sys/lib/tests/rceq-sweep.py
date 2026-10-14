#!/usr/bin/env python3
#
# rceq-sweep -- which mkfile RECIPE lines hand rc a bare `=' that is not a
# leading assignment, and so cannot parse?
#
#   python3 sys/lib/tests/rceq-sweep.py
#
# IT GATES.  Unlike `ishadow-sweep', every hit here is a real break: mk
# hands a recipe to `rc', `=' is a SYNTAX CHARACTER there, and rc's grammar
# accepts it in exactly one position -- a leading per-command assignment.
# Anywhere else it is `token '=': syntax error' and the command never runs.
#
# **THE MACHINE SETTLED THIS, after this tree had carried it as unmeasured
# for a round.**  `clisp/mkfile.rebuild's `if (test $name = lispbibl)'
# answered `/rc/lib/rcmain:24 *eval*:4: token '=': syntax error' on the VM,
# and `*eval*:4' is that line to the digit.  Before that run the question
# was open, because **there is no rc on the build host** -- which is why
# this is a sweep over text rather than a parse.
#
# AND THE MESSAGE NAMES THE WRONG LINE, which is why one hit costs a round
# if it is not swept for.  mk reported the failure as
# `mk: mkdir -p build-amd64 ...: exit status=rc: syntax error' -- mk names
# a recipe by its FIRST line, and the fault was five lines down in a file
# the message never mentions.  *The message names the victim*, the third
# time in this tree after the `lock.h' shadow and `cmd/mkfile:96'.
#
# WHY EVERY `-DFOO=1' IN THIS TREE IS NONETHELESS FINE, and why the sweep
# must not report them: those arrive through `$CFLAGS', and mk exports its
# variables into rc's ENVIRONMENT, so rc expands them *after* it has
# parsed -- the `=' never reaches the parser as text.  Only a literal one
# typed into a recipe does.  The sweep therefore reads the mkfile's own
# text and ignores what any variable might hold.
#
# THE DISCRIMINATOR IS THE WHOLE INSTRUMENT, as `mkcont-sweep's is.  A
# LEADING assignment is legal and common -- `i=_$i', `ARCHDEF=-D__i386__',
# and notably `if (~ $i seek) j=_seek' in `libc/9syscall/mkfile', which is
# a WORKING PRECEDENT for an assignment after an `if' head.  A naive grep
# for `=' reports 16 lines of which 11 are those.  So a command separator
# is recognised first (`;', `&', `|', `{', `(', `)', `&&', `||', and the
# start of the line), and only an `=' that follows something else is a
# finding.
#
# Single-quoted text is stripped first, since rc quoting is exactly how the
# fix is written: `'objtype='^$objtype' rather than `objtype=$objtype'.
#
# LIMITS, so the next reader does not over-read a clean run.  This does not
# parse rc; it is a lexical approximation of one rule.  It cannot see a `='
# that arrives through a variable this mkfile itself sets to a literal, and
# it does not check `rc/bin/*' scripts -- only mkfile recipes, which are
# where mk's own invocation of rc happens.

import os
import re
import sys

# THREE levels: this file is sys/lib/tests/<name>.  `ishadow-sweep' said
# two, reported 0 of everything and looked healthy -- and the guard below
# fired on the first run of THIS file for the same miss, which is the only
# reason it is right now.
ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                    '..', '..', '..')
ROOT = os.path.normpath(ROOT)
TREE = os.path.join(ROOT, 'sys', 'src')

RULE = re.compile(r'^[^=#]*:[A-Z]*:')
ASSIGN = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*\s*=')
# an `=' is legal only at the start of a command; these end one
LEADING = re.compile(r"(^|[;&|{}()]|\|\||&&)\s*[A-Za-z_][A-Za-z0-9_]*\s*=")


def recipe_lines(path):
    """Yield (lineno, text) for every line rc will be handed.

    A recipe is the tab-indented block after a rule header.  Continuation
    lines of an ASSIGNMENT are also tab-indented and are not recipes --
    that distinction is what kept `mkcont-sweep' honest and it is needed
    here for the same 83-hits-of-noise reason.
    """
    try:
        text = open(path, encoding='utf-8', errors='replace').read()
    except OSError:
        return
    inrecipe = False
    cont = False
    for i, line in enumerate(text.split('\n'), 1):
        if not line.strip():
            inrecipe = cont = False
            continue
        if line.startswith('\t'):
            if inrecipe and not cont:
                yield i, line
            cont = cont and line.rstrip().endswith('\\')
            continue
        cont = bool(ASSIGN.match(line)) and line.rstrip().endswith('\\')
        inrecipe = (not cont) and bool(RULE.search(line))


def bare_eq(line):
    s = re.sub(r"'[^']*'", "''", line)    # rc single quotes
    s = re.sub(r'#.*$', '', s)            # rc comments; stripped AFTER the
                                          # quotes, or a quoted `#' eats the
                                          # rest of a real command.  The
                                          # first version of this file
                                          # skipped this and reported its
                                          # OWN comments as findings.
    s = LEADING.sub(r'\1 ', s)            # leading assignments are legal
    return '=' in s


def main():
    if not os.path.isdir(os.path.join(ROOT, 'sys', 'include', 'ape')):
        print('rceq-sweep: %s is not an APExp root -- refusing to report' % ROOT)
        print('(a sweep rooted in the wrong tree reports an empty one as a')
        print(' clean one; ishadow-sweep paid a round for exactly that)')
        return 2

    nlines = 0
    hits = []
    for dirpath, _, names in os.walk(TREE):
        for name in names:
            if name != 'mkfile' and not name.startswith('mkfile.'):
                continue
            path = os.path.join(dirpath, name)
            rel = os.path.relpath(path, ROOT)
            for lineno, line in recipe_lines(path):
                nlines += 1
                if bare_eq(line):
                    hits.append((rel, lineno, line.strip()))

    for rel, lineno, line in hits:
        print('%s:%d: %s' % (rel, lineno, line))
    print('---- %d recipe lines, %d with a bare `=\' rc cannot parse'
          % (nlines, len(hits)))
    if hits:
        print("fix: write `'name='^$value', or build the word by")
        print("concatenation.  Do NOT leave it: the recipe cannot run at all,")
        print("and if it sits in an untriggered rule nothing will say so.")
    return 1 if hits else 0


if __name__ == '__main__':
    sys.exit(main())
