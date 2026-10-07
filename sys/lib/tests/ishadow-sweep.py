#!/usr/bin/env python3
"""
ishadow-sweep -- which package `-I' directories SHADOW an APE header
that a system header includes with angle brackets?

    python3 sys/lib/tests/ishadow-sweep.py

A HOST SWEEP, like `apdecl-sweep.py' and `strerror-xcheck.py', not a
test: it reads mkfiles and directory listings and asserts nothing.

------------------------------------------------------------------
WHAT IT IS FOR, AND IT COST A BUILD.

`sys/src/ape/cmd/bash/mkfile' carried `-I$BASHSRC/lib/intl', and that
directory holds **gettext's own `lock.h'**. An -I is searched before
the system path, so APE's <pthread.h>, reaching its own
`#include <lock.h>', got gettext's file -- which never typedefs
`Lock'. <qlock.h> then hit `Lock lock;' with no such type:

    /sys/include/ape/qlock.h:44 syntax error, last name: Lock

**And nothing said `lock.h'.** The message named the victim's line in
a header the package does not mention, in a build whose command line
is four screens wide. *Name the file that is COMPILED, not the file
with the right name* -- the `PATH_MAX' and shadowed-`config.h'
lesson, arriving for a header that a SYSTEM header includes rather
than one the package does.

**It was inert for years** because <qlock.h> carried its own `Lock'
typedef behind an always-true `#ifndef Lock'. Removing that duplicate
was correct and is what made the shadow reachable, which is this
tree's recorded rule in a new place: *a fix that makes a process
reach code it never reached before can expose anything on that path.*

------------------------------------------------------------------
MOST HITS ARE DELIBERATE, SO THIS DOES NOT GATE ANYTHING.

Tcl ships its own `regex.h' and `tcl.h'; libressl's
`include/compat' exists precisely to replace <stdio.h> and friends;
zlib owns `zconf.h'. **A sweep that failed on those would cry wolf**,
which is the rule `apehdr-sweep.py' already carries for its twelve
untriaged together-case errors. It prints and exits 0.

**Read a hit as a question, not a finding**: does the shadowing file
provide what the APE header's CALLER needs? Only two answers matter --
the package means to replace the header (fine), or it merely happens
to own the name (a build waiting to break). gettext's `lock.h` was
the second kind.

LIMITS, stated rather than discovered later:
  - mkfile variables are expanded only when they are assigned on one
    plain line in the SAME mkfile. An -I built from a variable this
    cannot resolve is skipped, so **this is a LOWER BOUND**, like the
    all-char struct sweep and `apdecl-sweep'.
  - it asks only about headers some APE header includes with <>. A
    package header shadowing one that only PROGRAMS include is a real
    hazard too and is not reported, because at that point the package
    almost certainly means it.
"""

import os
import re
import sys

#
# sys/lib/tests -> the repo root is THREE levels up, not two. The
# first version said two, found 0 of everything, and printed a clean
# summary -- *a sweep whose root is wrong reports an empty tree as a
# healthy one*, which is the same shape as an instrument whose include
# path is not the build's. The assertion below is why it was caught in
# one run rather than believed.
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
if not os.path.isdir(os.path.join(ROOT, "sys/include/ape")):
    sys.exit("ishadow-sweep: %s is not the APExp root -- refusing to "
             "report 0 findings from the wrong tree" % ROOT)
APEDIRS = ("sys/include/ape", "amd64/include/ape")


def ape_headers():
    """every .h under the APE include trees, by the name an -I would match"""
    names = set()
    for d in APEDIRS:
        p = os.path.join(ROOT, d)
        if not os.path.isdir(p):
            continue
        for dirpath, _, files in os.walk(p):
            rel = os.path.relpath(dirpath, p)
            for f in files:
                if f.endswith(".h"):
                    names.add(f if rel == "." else os.path.join(rel, f))
    return names


def angle_included():
    """
    names some APE header includes with <>.

    This is the discriminating half: a package owning `hash-string.h'
    can shadow nothing, because no system header asks for it. A
    package owning `lock.h' sits directly in <pthread.h>'s path.
    """
    names = set()
    for d in APEDIRS:
        p = os.path.join(ROOT, d)
        if not os.path.isdir(p):
            continue
        for dirpath, _, files in os.walk(p):
            for f in files:
                if not f.endswith(".h"):
                    continue
                try:
                    text = open(os.path.join(dirpath, f), encoding="latin1").read()
                except OSError:
                    continue
                for m in re.finditer(r"#\s*include\s*<([^>]+)>", text):
                    names.add(m.group(1))
    return names


def includedirs(mkfile):
    """the -I directories of one mkfile, resolved as far as is honest"""
    text = open(mkfile, encoding="latin1").read()
    # single-line `NAME=value' assignments only; anything else is left
    # unexpanded and the -I using it is skipped rather than guessed at
    var = dict(re.findall(r"^(\w+)\s*=\s*(\S+)\s*$", text, re.M))
    here = os.path.dirname(mkfile)
    out = []
    for m in re.finditer(r"-I(\S+)", text):
        d = m.group(1).rstrip("\\")
        for _ in range(4):                      # nested variables
            for k, v in var.items():
                d = d.replace("$" + k, v)
        d = d.replace("$APEXPROOT", ROOT).replace("$objtype", "amd64")
        if "$" in d:
            continue
        if not d.startswith("/"):
            d = os.path.normpath(os.path.join(here, d))
        out.append(d)
    return out


def main():
    apehdrs = ape_headers()
    angle = angle_included()
    apereal = [os.path.realpath(os.path.join(ROOT, d)) for d in APEDIRS]

    hits = {}
    for dirpath, _, files in os.walk(os.path.join(ROOT, "sys/src/ape")):
        if "mkfile" not in files:
            continue
        mk = os.path.join(dirpath, "mkfile")
        for d in includedirs(mk):
            if not os.path.isdir(d):
                continue
            real = os.path.realpath(d)
            if any(real.startswith(a) for a in apereal):
                continue                        # the APE trees are not a shadow
            try:
                entries = os.listdir(d)
            except OSError:
                continue
            for f in entries:
                if f in apehdrs and f in angle:
                    key = (os.path.relpath(mk, ROOT), os.path.relpath(d, ROOT))
                    hits.setdefault(key, set()).add(f)

    for (mk, d) in sorted(hits):
        print("%s" % mk)
        print("    -I %s" % d)
        print("       shadows %s" % " ".join("<%s>" % f for f in sorted(hits[(mk, d)])))
    print()
    print("%d (mkfile, directory) pairs; %d shadowed header names."
          % (len(hits), len({f for s in hits.values() for f in s})))
    print("Most are deliberate -- read the header's description above "
          "before changing one.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
