#!/usr/bin/env python3
"""
mkcont-sweep -- which mkfile has a COMMENT that silently ends a
continued assignment, leaving the rest of the list as a bare word?

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
"""

import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
if not os.path.isdir(os.path.join(ROOT, "sys/src/ape")):
    sys.exit("mkcont-sweep: %s is not the APExp root -- refusing to "
             "report 0 findings from the wrong tree" % ROOT)


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


def main():
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
    print()
    print("%d broken continuation(s)." % findings)
    if findings:
        print("Add a trailing backslash to the comment line, keeping the "
              "space before it.")
    return findings


if __name__ == "__main__":
    sys.exit(main())
