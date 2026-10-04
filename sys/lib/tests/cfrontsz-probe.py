#!/usr/bin/env python3
"""
cfrontsz-probe -- does kencc lay out cfront's structs the way the
TRANSLATOR said it would?

    python3 sys/lib/tests/cfrontsz-probe.py       # from the repo root

It GENERATES two files into sys/src/external/cfront-C4/src and runs
the gcc control itself. **Both generated files are COMMITTED**, which
looks wrong and is not: git is the only channel to the VM, 9front has
no python3, and the whole point of the probe is to be compiled by pcc
there. They were `.gitignore'd at first and the VM answered
`cpp: Can't open input file cfrontsz-probe.c'. Regenerate and
re-commit whenever cfront's `main.c' changes. Nothing in
`cmd/cfront/mkfile' lists either file, so mk never compiles them.

Then, on the VM:

    cd sys/src/external/cfront-C4/src
    pcc -B -D_POSIX_SOURCE -D_BSD_EXTENSION -D__cfront_have_bool \\
        -I. -o /tmp/cfrontsz cfrontsz-probe.c && /tmp/cfrontsz

**The flags are cfront's own, from `sys/src/ape/cmd/cfront/mkfile`,
and they are not decoration**: `tarblock-probe` measured a different
`tar.h` the first time for exactly this reason. A probe built with
different flags from the thing it measures is measuring something
else.

------------------------------------------------------------------
WHY: THE TRANSLATOR WROTE ITS OWN ANSWER INTO THE SOURCE.

cfront's C was produced by cfront itself, and every generated struct
carries a comment with the size the translator computed:

    struct expr { /* sizeof expr == 40 */
    struct name { /* sizeof name == 144 */
    struct node { /* sizeof node == 3 */

**That is an oracle, and this tree has met it before.** GNU tar's
`union block` was 520 under kencc where every other system says 512,
because `6c/swt.c`'s `align()` rounds EVERY struct's size up to 8
(`Asu2`) and aligns a NESTED struct member to 8 as well (`Ael1`).
`tarblock-probe.c` is the same instrument for `tar.h`; this is it for
cfront, and cfront has 132 such comments across its `.c` files
against tar's nine.

**`struct node` is already a guaranteed disagreement**: `TOK` and
`bit` are both `unsigned char` (`typedef.h:19-20`), so it is three
bytes on gcc and **eight** under kencc. Whether that MATTERS depends
on whether anything strides over a `node` -- field offsets stay right,
and what breaks is `sizeof` used as a stride or a length. *The probe
reports the fact; it does not decide the consequence.*

------------------------------------------------------------------
WHAT PUT IT HERE.

cfront crashes on 9front at `table.c:1455`, `while ((*__2p))` --
dereferencing `np[j]->__O2__4expr.string`. `acid`'s `lstk()` on the
Broken process gives

    __2s = 0x6f69736963657270

and those eight bytes little-endian are the ASCII **"precisio"** --
the first eight characters of the identifier `precision`. *A
`const char *` holding the TEXT it should point at.* Third time in
this tree a pointer has contained characters, after bash's
`ifs_value` and `date`'s `tm_zone`.

A wrong field OFFSET would produce exactly that: read eight bytes
from the wrong place in a node and you get whatever is there, which
in a name node is often the identifier. So the first question is
whether the offsets are what the generated code assumes -- and the
sizes are the cheapest proxy for it.

**AND `lstk()` ITSELF HAD TO BE CALIBRATED FIRST, which nearly cost a
round.** Its int locals all looked like garbage:

    __1j    = 0x474c200000001a      __1hash = 0x474c20
    __1i    = 0x2b2cfb00000003      __1sick = 0x2b2cfb
    __2oerror_count = 0x47552000000000   __1n = 0x475520

In every pair the HIGH half of the "garbage" is the NEIGHBOURING
variable: acid reads eight bytes for a four-byte `int`, so the low
half is the real value and the high half is the next slot. `__1mx`
reads `0xa5` = 165, and `(g*3)/2` for `g = 0x6e` is **165** exactly,
which confirms it. *So every int in that dump is correct and only
mis-printed* -- and `__2s` is an eight-byte pointer slot, so it is
the one value that is genuinely wrong. Three independent pairs agree
on the artefact before anything was built on the one that did not.

------------------------------------------------------------------
THE CONTROL IS NOT OPTIONAL AND RUNS AUTOMATICALLY.

The declarations are EXTRACTED from `main.c`'s preamble -- the text
before its first function definition -- so a bad extraction would
produce a probe that measures nothing. gcc must therefore reproduce
**every** recorded size: 47 of 47, 0 disagreements. If the gcc run
reports even one, the extraction is wrong and the pcc number means
nothing. *An instrument that cannot reproduce the known answer has
not earned the right to report an unknown one.*

`main.c` is chosen because its preamble declares the most tagged
types of any file (47); the other `.c` files emit subsets of the same
generated declarations.

Only TAGGED definitions are asked about (`struct X {` / `union X {`
carrying their own size comment), and each is asked with the keyword
it was declared with -- the `__Q2_4expr4__C1` family are UNIONS, and
asking `sizeof(struct ...)` for them is a compile error rather than a
wrong answer, which is the safe direction but still no measurement.
"""

import os, re, subprocess, sys

SRC = "sys/src/external/cfront-C4/src"
PCC_FLAGS = "-B -D_POSIX_SOURCE -D_BSD_EXTENSION -D__cfront_have_bool -I."


def preamble(path):
    """main.c up to its first function definition: the declarations."""
    lines = open(path, encoding="latin1").read().split("\n")
    for i, l in enumerate(lines):
        if re.match(r"^[A-Za-z_][A-Za-z_0-9 *]*\(.*\{\s*$", l):
            return "\n".join(lines[:i]) + "\n"
    sys.exit("cfrontsz-probe: no function definition found in " + path)


def main():
    if not os.path.isdir(SRC):
        sys.exit("cfrontsz-probe: run me from the repo root")
    decls = preamble(os.path.join(SRC, "main.c"))
    open(os.path.join(SRC, "cfrontsz-decls.h"), "w").write(decls)

    ents = {}
    for m in re.finditer(
            r"\b(struct|union)\s+([A-Za-z_]\w*)\s*\{\s*"
            r"/\*\s*sizeof\s+\2\s*==\s*(\d+)\s*\*/", decls):
        ents[m.group(2)] = (m.group(1), int(m.group(3)))

    out = ['/* GENERATED by sys/lib/tests/cfrontsz-probe.py -- do not edit. */',
           '#include "cfrontsz-decls.h"',
           "extern int printf(const char*, ...);",
           "int main(void){ int bad=0, n=0;"]
    for name, (kw, sz) in sorted(ents.items()):
        out.append('  n++; if(sizeof(%s %s)!=%d){ printf('
                   '"  %%-26s here %%4d   translator %%4d   *** DIFFERENT ***\\n",'
                   '"%s",(int)sizeof(%s %s),%d); bad++; }'
                   % (kw, name, sz, name, kw, name, sz))
        out.append('  else printf("  %%-26s %%4d  same\\n","%s",'
                   "(int)sizeof(%s %s));" % (name, kw, name))
    out.append('  printf("\\n%d of %d disagree with the translator\\n", bad, n);')
    out.append("  return bad; }")
    cfile = os.path.join(SRC, "cfrontsz-probe.c")
    open(cfile, "w").write("\n".join(out) + "\n")
    print("cfrontsz-probe: generated for %d tagged structs/unions" % len(ents))

    # ---- the control: gcc must reproduce every recorded size ----
    exe = "/tmp/cfrontsz-hostprobe"
    c = subprocess.run(["gcc", "-I", SRC, "-w", "-o", exe, cfile],
                       capture_output=True, text=True)
    if c.returncode != 0:
        print("cfrontsz-probe: CONTROL DID NOT BUILD -- the extraction is "
              "wrong, and the probe measures nothing:")
        print("\n".join(c.stderr.splitlines()[:5]))
        return 2
    r = subprocess.run([exe], capture_output=True, text=True)
    tail = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else "(no output)"
    print("cfrontsz-probe: gcc control -> " + tail)
    if r.returncode != 0:
        print("cfrontsz-probe: THE CONTROL FAILED. gcc must reproduce every")
        print("  recorded size; it did not, so the extraction is wrong and a")
        print("  pcc run would mean nothing. Do not take it to the VM.")
        return 2
    print("\nControl passed. On the VM:")
    print("  cd %s" % SRC)
    print("  pcc %s -o /tmp/cfrontsz cfrontsz-probe.c && /tmp/cfrontsz"
          % PCC_FLAGS)
    return 0


if __name__ == "__main__":
    sys.exit(main())
