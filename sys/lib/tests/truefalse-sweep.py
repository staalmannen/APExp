#!/usr/bin/env python3
#
# truefalse-sweep.py -- which vendored sources use `true' or `false' as
# an IDENTIFIER, in a translation unit that does not define the names
# itself?  Those are the files kencc's C23 keywords break.
#
#	python3 sys/lib/tests/truefalse-sweep.py
#
# **IT DOES NOT GATE.**  Every hit it reports today is a false positive
# and the answer it exists to give is a NUMBER, not a verdict.
#
# WHERE THE QUESTION CAME FROM.  go1.4's stage 2 answered
#
#	go.h:1093 syntax error, last name: true
#
# on `void complexbool(int op, Node *nl, Node *nr, int true, ...)' --
# `true' as a PARAMETER NAME, legal in C89 and a keyword under kencc's
# C23.  The fix was a rename across 11 files and 130 sites, and the
# question that followed was whether a `-std'-style switch to turn the
# keywords off would pay for itself.  **This sweep is the answer and the
# answer is no**: go1.4 is the only package in the tree with the shape,
# and go1.4 is FROZEN -- it is the last C implementation of Go and the
# reason it is the bootstrap at all, so the 130 sites are a cost paid
# once rather than on every import.
#
# ***AND THE CLAIM IN CLAUDE.md WAS TOO STRONG.***  That file said APE's
# `<stdbool.h>' `#define's the names "so an APE build never reaches
# kencc's own C23 keywords".  It only holds for a TU that INCLUDES that
# header -- go's C sources do not, and go's bootstrap is `pcc' (see
# `cmd/go/mkfile.bootstrap:44', `CC=pcc -c'), so an APE build reached
# the keywords on the first file that named one.  *The masking is a
# property of the translation unit, not of the compiler driver*, which
# is why this sweep tests for the mask per file rather than assuming it.
#
# WHAT COUNTS AS MASKED, and all three are real in the tree: a
# `#include <stdbool.h>', a hand `#define true', or an `enum { false,
# true }'.  311 of 20471 files mask the names one of those three ways.
#
# ***THE PATTERN WAS WIDENED TWICE BEFORE ANY NUMBER WAS WRITTEN DOWN,
# and both drafts were wrong in the cry-wolf direction.***  Draft 1 had
# no stopword list, so `return true;' matched -- `return' reads as a
# type name to a regex -- and it reported 8148 hits across 39 packages.
# Draft 2 added the stopwords but only skipped a comment line whose
# FIRST character was `*', so every continuation line inside a block
# comment still matched; 379 hits, and the printed sample was visibly
# all prose.  Draft 3 blanks comments and string literals outright,
# preserving newlines so the line numbers survive, and reports 3.
# *Reporting draft 1's number would have been reporting the regex.*
#
# **ITS POSITIVE CONTROL IS EXTERNAL AND HAS TO BE**, because the fix is
# already committed: running this over the tree finds go1.4 clean, so a
# sweep that could only pass proves nothing.  The control is the
# PRE-RENAME source out of git --
#
#	git show aaf2c2756^:sys/src/external/go1.4/src/cmd/gc/go.h
#
# in a directory of its own, where it fires on `go.h:1093' and
# `go.h:1492'.  `--control' does that for you.  *A check that cannot
# fail is not a check*, and this one could not have failed against the
# tree it was written for.

import os
import re
import subprocess
import sys
import tempfile

# `return true;' is not a declarator.  Every name here is a keyword that
# a regex would otherwise read as the type in `<type> true'.
STOP = {
    'return', 'case', 'goto', 'sizeof', 'while', 'if', 'else', 'do',
    'break', 'continue', 'and', 'or', 'not', 'default', 'typedef',
    'assert', 'true', 'false',
}

# `<something> true' followed by a token that can end a declarator.
DECL = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]*)\s+\**\s*(true|false)\s*(?:[,;)=\[]|$)')

MASK = re.compile(
    r'#\s*include\s*[<"]stdbool\.h'
    r'|#\s*define\s+(true|false)\b'
    r'|\b(?:enum|typedef\s+enum)\b[^;]{0,200}?\b(?:false|true)\s*(?:=|,|\})',
    re.S)

BLOCK = re.compile(r'/\*.*?\*/|//[^\n]*', re.S)
LITERAL = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'')

# The control is one commit before the rename; see the header.
CONTROL_COMMIT = 'aaf2c2756^'
CONTROL_FILES = [
    'sys/src/external/go1.4/src/cmd/gc/go.h',
    'sys/src/external/go1.4/src/cmd/gc/subr.c',
    'sys/src/external/go1.4/src/cmd/6c/txt.c',
]


def blank(m):
    """Replace a comment or literal with spaces, keeping its newlines so
    that line numbers stay the file's own."""
    return re.sub(r'[^\n]', ' ', m.group(0))


def sweep(root):
    hits = {}
    nfile = nmask = 0
    for dirpath, _, filenames in os.walk(root):
        for name in filenames:
            if not name.endswith(('.c', '.h')):
                continue
            path = os.path.join(dirpath, name)
            try:
                with open(path, errors='replace') as fp:
                    text = fp.read()
            except OSError:
                continue
            nfile += 1
            if MASK.search(text):
                nmask += 1
                continue
            text = LITERAL.sub(blank, BLOCK.sub(blank, text))
            for lineno, line in enumerate(text.splitlines(), 1):
                if line.lstrip().startswith('#'):
                    continue
                m = DECL.search(line)
                if m and m.group(1) not in STOP:
                    pkg = relpkg(path, root)
                    hits.setdefault(pkg, []).append((path, lineno, line.strip()))
    return hits, nfile, nmask


def relpkg(path, root):
    rest = os.path.relpath(path, root).split(os.sep)
    return rest[0] if len(rest) > 1 else os.path.basename(path)


def report(hits, nfile, nmask, root):
    print('%s: %d .c/.h files, %d define true/false themselves'
          % (root, nfile, nmask))
    for pkg in sorted(hits, key=lambda k: (-len(hits[k]), k)):
        print('  %-24s %4d' % (pkg, len(hits[pkg])))
        for path, lineno, line in hits[pkg]:
            print('      %s:%d: %s' % (path, lineno, line[:100]))
    print('candidate declarators: %d' % sum(len(v) for v in hits.values()))


def control():
    """Stage the pre-rename go sources and sweep them.  Fires on go.h's
    two declarations of `complexbool' and `bgen'."""
    with tempfile.TemporaryDirectory() as tmp:
        staged = os.path.join(tmp, 'go1.4')
        os.makedirs(staged)
        for src in CONTROL_FILES:
            try:
                blob = subprocess.check_output(
                    ['git', 'show', '%s:%s' % (CONTROL_COMMIT, src)])
            except subprocess.CalledProcessError:
                print('control: cannot read %s at %s -- has the commit been '
                      'rewritten?' % (src, CONTROL_COMMIT))
                return 1
            with open(os.path.join(staged, src.replace('/', '_')), 'wb') as fp:
                fp.write(blob)
        hits, nfile, nmask = sweep(tmp)
        report(hits, nfile, nmask, 'control (%s)' % CONTROL_COMMIT)
        found = sum(len(v) for v in hits.values())
        if found:
            print('control FIRES (%d) -- the sweep can fail' % found)
            return 0
        print('control is SILENT -- the sweep below means nothing')
        return 1


def main():
    if '--control' in sys.argv:
        return control()
    root = 'sys/src/external'
    if not os.path.isdir(root):
        print('run me from the repository root (%s not found)' % root)
        return 1
    hits, nfile, nmask = sweep(root)
    report(hits, nfile, nmask, root)
    print('this sweep does NOT gate; read the hits, they are prose and '
          'macro pastes, not declarators')
    return 0


if __name__ == '__main__':
    sys.exit(main())
