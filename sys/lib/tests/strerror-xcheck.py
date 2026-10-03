#!/usr/bin/env python3
# strerror-xcheck -- a HOST cross-check, not a test and not a Plan 9
# program. It asks whether libap's `sys_errlist[]' says what every
# other system says.
#
#       python3 strerror-xcheck.py
#
# It needs gcc and nothing else; no VM round.
#
# ------------------------------------------------------------------
# WHY IT IS A SCRIPT RATHER THAN A C CROSS-CHECK.
#
# The other xchecks in this directory link the unit under test into a
# glibc program. That cannot be done here, and the reason is the whole
# difficulty: **APE's errno NUMBERS are its own**. EBADF is 4 here and
# 9 on glibc, EPERM is 30 here and 1 there. Compiling libap's table
# beside glibc's would line up two tables that index differently, and
# a comparison by index would be nonsense dressed as a measurement.
#
# So the only thing the two systems share is the NAMES, and this
# walks them: parse `sys/include/ape/errno.h' for name -> APE index,
# parse `strerror.c' for the table, then compile a one-shot C program
# that prints glibc's `strerror(NAME)' for each name it has, and
# compare by name.
#
# ------------------------------------------------------------------
# WHAT IT FOUND, AND WHY IT IS CHECKED IN.
#
# **40 of the 76 entries disagreed**, and two of them were worse than
# terse: EACCES read "Access denied" and EPERM read "Permission
# denied", which is glibc's text for **EACCES** -- so the single most
# recognisable message in the table named the wrong errno.
#
# It is checked in because a table of 77 strings indexed by number is
# the easiest thing in this tree to let drift: one inserted row moves
# every entry after it, and nothing would say so. Re-run it after
# touching `errno.h' or `strerror.c'.
#
# ------------------------------------------------------------------
# WHAT IT CANNOT CHECK, so that a clean run is not over-read:
#
#   EGREG     APE's own (`_errno.c' maps Plan 9's "ken has left the
#             building" to it). glibc has no such error, so it is
#             reported as UNCHECKABLE rather than passed over.
#   EDOM      1000 and 1001, outside the table -- `strerror()' spells
#   ERANGE    them in its own arms, which this checks separately.
#   wording   POSIX fixes none of it. The reference is glibc because
#             that is what the GNU test suites in this tree compare
#             against, not because the standard says so.

import os, re, subprocess, sys, tempfile

ROOT = os.path.realpath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
HDR = os.path.join(ROOT, "sys/include/ape/errno.h")
SRC = os.path.join(ROOT, "sys/src/ape/lib/ap/string/strerror.c")

hdr = open(HDR).read()
src = open(SRC).read()

names = {}                                  # APE value -> [names]
for m in re.finditer(r'^#define\s+(E[A-Z0-9_]+)\s+(\d+)\s*$', hdr, re.M):
    v = int(m.group(2))
    names.setdefault(v, []).append(m.group(1))

table = re.findall(r'"((?:\\.|[^"\\])*)"',
                   src.split("char *sys_errlist[] = {", 1)[1].split("\n};", 1)[0])

# the two that live in strerror() itself rather than in the table
infunc = dict(re.findall(r'n == (EDOM|ERANGE)\)\s*\n\s*return "([^"]*)"', src))

prog = ['#include <stdio.h>', '#include <string.h>', '#include <errno.h>',
        'int main(void){']
wanted = [n for v in sorted(names) if v < 1000 for n in names[v]] + ["EDOM", "ERANGE"]
for n in wanted:
    prog += ['#ifdef %s' % n,
             '  printf("%%s\\t%%s\\n", "%s", strerror(%s));' % (n, n),
             '#else', '  printf("%%s\\t\\n", "%s");' % n, '#endif']
prog += ['  return 0;', '}']

with tempfile.TemporaryDirectory() as d:
    c, x = os.path.join(d, "g.c"), os.path.join(d, "g")
    open(c, "w").write("\n".join(prog) + "\n")
    subprocess.run(["gcc", "-w", "-o", x, c], check=True)
    out = subprocess.run([x], capture_output=True, text=True, check=True).stdout

glibc = {}
for line in out.splitlines():
    n, s = line.split("\t", 1)
    glibc[n] = s

print("strerror-xcheck: libap's sys_errlist[] against glibc, by NAME\n")
same = bad = unchecked = 0
for v in sorted(names):
    if v >= 1000:
        continue
    if v >= len(table):
        print("  *** index %d (%s) is past the end of the table"
              % (v, "/".join(names[v])))
        bad += 1
        continue
    ours = table[v]
    want = {glibc.get(n, "") for n in names[v]}
    want.discard("")
    nm = "/".join(names[v])
    if not want:
        unchecked += 1
        print("  UNCHECKABLE  %-16s ours %r  (not an error glibc has)" % (nm, ours))
    elif ours in want:
        same += 1
    else:
        bad += 1
        print("  DIFFERS  %-16s ours %r  glibc %r" % (nm, ours, sorted(want)[0]))

for n in ("EDOM", "ERANGE"):
    ours, want = infunc.get(n), glibc.get(n, "")
    if ours is None:
        print("  *** %s is no longer spelled in strerror() -- read the file" % n)
        bad += 1
    elif ours == want:
        same += 1
    else:
        bad += 1
        print("  DIFFERS  %-16s ours %r  glibc %r" % (n, ours, want))

print("\n%d entries in the table (errno 0 .. %d)" % (len(table), len(table) - 1))
print("%d agree, %d DIFFER, %d uncheckable" % (same, bad, unchecked))
sys.exit(1 if bad else 0)
