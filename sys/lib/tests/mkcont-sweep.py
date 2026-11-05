#!/usr/bin/env python3
"""
mkcont-sweep -- which mkfile has a logical line mk cannot parse,
because a continuation ended where nobody meant it to?

Two shapes, and the second was added after the first missed it.

    python3 sys/lib/tests/mkcont-sweep.py

A HOST SWEEP, not a test. Exit status is the number of findings, so it
CAN gate -- unlike `ishadow-sweep.py', every hit here is a real break.

------------------------------------------------------------------
WHAT IT IS FOR, AND IT COST A FULL REBUILD.

`sys/src/ape/cmd/mkfile' documents this hazard in its own header --
*"Every comment line INSIDE these lists has to end in a backslash: the
list is one continued line, and a comment without it ends the
assignment there"* -- and then broke it, in the block that explains why
`c++lib' and `basic' are not enabled. Four comment lines without a
trailing backslash, so `_OPTIONAL_APPS' ENDED there, and everything
from `adeb' to `curl' became a fresh logical line starting with a word:

    mk: mkfile:96: syntax error; expected one of :<=

**The reported line is where the runaway logical line ENDS, not where
it starts.** Line 96 is an ordinary `DIRS=\'; the fault is 26 lines
earlier, in a comment. *A rule written down in a file is not a rule the
file obeys*, and the message points at the victim, which is the same
shape as the shadowed `lock.h' one commit earlier.

------------------------------------------------------------------
THE DISCRIMINATOR, because the naive check is mostly false positives.

A comment ending a continuation is USUALLY deliberate: it is how the
tail of a list gets commented out, and `lib/png/mkfile:42' does exactly
that at the end of its OFILES. What makes it a BUG is what comes next:
if the following logical line starts with a bare word -- no `:', `=' or
`<' -- mk cannot parse it. So the sweep reports only that case.

LIMIT, stated rather than discovered later: a broken continuation whose
next line happens to be a valid assignment or rule is NOT reported,
because mk accepts it. It is still wrong -- the dropped entries are
silently not built -- but it has no symptom this can see, so this is a
LOWER BOUND like every other sweep here.

------------------------------------------------------------------
SHAPE TWO: AN ORPHAN INDENTED LINE, AND THIS SWEEP REPORTED 0 OVER IT.

`cmd/php/mkfile' ended its `OFILES' at the last generated entry and
then had a blank line, five comment lines and a tab-indented
`internal_functions_cli.$O' that was meant to be part of the list. mk
answered `mkfile:612: syntax error; expected one of :<=' -- and **the
check above never fired, because the continuation was ended by an
ordinary entry rather than by a comment.**

The generalisation is the one mk itself uses, and it covers both: a
logical line that starts with a bare word -- no `:', `=' or leading
`<' -- is a syntax error WHEREVER it came from. An INDENTED one is a
syntax error unless it is a recipe, which means the rule above it had
a `:'. So this now also reports an indented logical line that follows
an ASSIGNMENT rather than a rule.

*Recipes are the whole difficulty*: every recipe body line is indented
and has no `:' or `=', so a naive version of this check reports the
entire tree. The discriminator is what the last non-indented logical
line was.
"""

import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
if not os.path.isdir(os.path.join(ROOT, "sys/src/ape")):
    sys.exit("mkcont-sweep: %s is not the APExp root -- refusing to "
             "report 0 findings from the wrong tree" % ROOT)


def logical(lines):
    """yield (start_line_index, joined_text, first_raw) per logical line"""
    i = 0
    while i < len(lines):
        start = i
        parts = [lines[i].rstrip()]
        while parts[-1].endswith("\\") and i + 1 < len(lines):
            i += 1
            parts.append(lines[i].rstrip())
        yield start, "\n".join(parts), lines[start]
        i += 1


def orphans(path):
    """shape two: an indented logical line that is not a recipe"""
    lines = open(path, encoding="latin1").read().split("\n")
    out = []
    in_recipe = False
    for start, text, raw in logical(lines):
        bare = raw.strip()
        if not bare or bare.startswith("#"):
            continue            # blank and comment end nothing, deliberately
        if raw[:1] in (" ", "\t"):
            if not in_recipe:
                out.append((start + 1, bare))
            continue
        # a non-indented logical line: does a recipe follow it?
        in_recipe = ":" in text.split("\n")[0]
    return out


def check(path):
    lines = open(path, encoding="latin1").read().split("\n")
    out = []
    cont = False
    for i, raw in enumerate(lines):
        line = raw.rstrip()
        if cont and line.lstrip().startswith("#") and not line.endswith("\\"):
            # the assignment ends here. what is the next logical line?
            j = i + 1
            while j < len(lines) and (not lines[j].strip()
                                      or lines[j].lstrip().startswith("#")):
                j += 1
            nxt = lines[j] if j < len(lines) else ""
            if nxt.strip() and not re.search(r"[:=]", nxt) \
                            and not nxt.lstrip().startswith("<"):
                out.append((i + 1, line, j + 1, nxt))
        cont = line.endswith("\\")
    return out


CONTROL_ONE = """\
OFILES=\\
\ta.$O\\
# a comment that forgets its backslash
\tb.$O\\
\tc.$O
"""

CONTROL_TWO = """\
OFILES=\\
\ta.$O\\
\tb.$O

# a comment block, and then an entry meant to be part of the list
\tc.$O

install:V:
\techo this recipe must NOT be reported
"""


def control():
    """Both shapes, because a sweep that only proves it can say one
    thing has not been shown to say the other.  CONTROL_TWO carries a
    real recipe as well: the discriminator between an orphan and a
    recipe body is the whole difficulty, so a control that omits the
    recipe would pass for a version that reports every mkfile."""
    import tempfile
    ok = True
    with tempfile.TemporaryDirectory() as d:
        for name, body, fn, want in (
                ("one", CONTROL_ONE, lambda p: check(p), 1),
                ("two", CONTROL_TWO, lambda p: orphans(p), 1)):
            p = os.path.join(d, "mkfile")
            open(p, "w").write(body)
            got = len(fn(p))
            print("control %s: %d finding(s), want %d -- %s"
                  % (name, got, want, "ok" if got == want else "FAILED"))
            if got != want:
                ok = False
        # and the recipe in CONTROL_TWO must not be among them
        p = os.path.join(d, "mkfile")
        open(p, "w").write(CONTROL_TWO)
        for (ln, text) in orphans(p):
            if "echo" in text:
                print("control two: REPORTED A RECIPE BODY -- FAILED")
                ok = False
    return 0 if ok else 1


def main():
    if "--control" in sys.argv:
        return control()
    findings = 0
    for base in ("sys/src/ape", "sys/src/cmd", "sys/src/cmd2"):
        top = os.path.join(ROOT, base)
        if not os.path.isdir(top):
            continue
        for dirpath, _, files in os.walk(top):
            if "mkfile" not in files:
                continue
            p = os.path.join(dirpath, "mkfile")
            for (ln, text, nl, nxt) in check(p):
                findings += 1
                print("%s:%d  comment ends the continuation:" %
                      (os.path.relpath(p, ROOT), ln))
                print("        %s" % text.strip()[:68])
                print("    :%d  is then a bare word mk cannot parse:" % nl)
                print("        %s" % nxt.strip()[:68])
            for (ln, text) in orphans(p):
                findings += 1
                print("%s:%d  indented line that is not a recipe:" %
                      (os.path.relpath(p, ROOT), ln))
                print("        %s" % text[:68])
    print()
    print("%d broken continuation(s)." % findings)
    if findings:
        print("Add a trailing backslash to the comment line, keeping the "
              "space before it.")
    return findings


if __name__ == "__main__":
    sys.exit(main())
