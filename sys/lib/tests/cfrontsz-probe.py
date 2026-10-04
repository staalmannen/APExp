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
WHAT THE FIRST VM RUN SAID, AND WHY IT IS NOT WHAT IT LOOKED LIKE.

`8 of 47 disagree with the translator' -- and SEVEN of the eight are
nothing to do with kencc's padding:

    __sigset_t          64 here, 128 recorded   Linux's 1024-bit set
    _fpstate           504 here, 512 recorded   x86 FP save area
    _libc_fpstate      504 here, 512 recorded
    _xsave_hdr          32 here,  64 recorded
    __pthread_rwlock_arch_t  48 here, 56        glibc's layout
    __Q3_5__C144__C14__C4    24 here, 32        __clock_t: long
    __Q3_5__C144__C14__C6     8 here, 16        si_band:   long
    node                 8 here,   3 recorded   *** kencc padding ***

**The recorded sizes are the GENERATING machine's**, and cfront's C
was generated on Linux -- so every system type in it carries glibc's
answer, which APE is not obliged to match and mostly should not. Two
more are kencc's 32-bit `long' showing through a `__clock_t'. *The
oracle is only an oracle for the translator's OWN structs.*
**So exactly ONE padding disagreement, and it is the predicted one.**
**And `node' cannot be the crash**: `struct name' INLINES node's
three fields (`base__4node', `permanent__4node', `baseclass__4node')
rather than embedding a `struct node', so node's size never enters
name's layout. cfront's C flattens inheritance.

------------------------------------------------------------------
THE CONTROL IS NOT OPTIONAL AND RUNS AUTOMATICALLY.

The declarations are EXTRACTED from the source file with its function
BODIES removed, so a bad extraction would produce a probe that
measures nothing. gcc must therefore reproduce **every** recorded
size: 97 of 97, 0 disagreements. If the gcc run reports even one, the
extraction is wrong and the pcc number means nothing. *An instrument
that cannot reproduce the known answer has not earned the right to
report an unknown one.*

**AND THAT CONTROL IS NOT ENOUGH ON ITS OWN, which cost the first VM
round.** The first version took main.c's PREAMBLE -- everything above
the first function definition -- and cfront's generated C INTERLEAVES
declarations with definitions, so it got **47 of main.c's 97 tagged
types**. The control reproduced all 47 and reported 0 disagreements,
which was true. *Correctness and completeness are different
properties and only one of them was being checked.* Among the fifty
left out were `name', `expr' and the whole `__Q2_4expr4__C*' family
-- **the exact types the faulting line dereferences**, so the probe
ran, passed its control, and could not have answered the question it
was built for. The extraction skips function bodies now, and the
count assertion is the other half of the control: every tagged type
in the file must survive into the probe. One line.

`main.c` is chosen because it declares the most tagged types of any
file (97); the others emit subsets of the same generated
declarations. Pass a different file name as the one argument to ask
about that one instead.

Only TAGGED definitions are asked about (`struct X {` / `union X {`
carrying their own size comment), and each is asked with the keyword
it was declared with -- the `__Q2_4expr4__C1` family are UNIONS, and
asking `sizeof(struct ...)` for them is a compile error rather than a
wrong answer, which is the safe direction but still no measurement.
"""

import os, re, subprocess, sys

SRC = "sys/src/external/cfront-C4/src"
PCC_FLAGS = "-B -D_POSIX_SOURCE -D_BSD_EXTENSION -D__cfront_have_bool -I."


TAGGED = re.compile(r"^(struct|union)\s+([A-Za-z_]\w*)\s*\{\s*"
                    r"/\*\s*sizeof\s+\2\s*==\s*(\d+)\s*\*/", re.M)
FUNCDEF = re.compile(r"^[A-Za-z_][A-Za-z_0-9 *]*\(.*\{\s*$")


def declarations(path):
    """Every top-level declaration in the file, function BODIES removed.

    The first version of this took the file's PREAMBLE -- everything
    before the first function definition -- and that was wrong in a way
    the gcc control could not see. cfront's generated C INTERLEAVES
    declarations with definitions, so main.c's preamble held 47 of its
    97 tagged types and the other 50 were never asked about. Among the
    missing were `name', `expr' and the whole `__Q2_4expr4__C*' family
    -- *the exact types the crash dereferences*.

    The control reproduced all 47 and reported 0 disagreements, which
    is true and was read as "the extraction is right". **Correctness
    and completeness are different properties and only one of them was
    being checked.** The count assertion below is the other one, and it
    is one line.
    """
    lines = open(path, encoding="latin1").read().split("\n")
    out, i, n = [], 0, len(lines)
    while i < n:
        if FUNCDEF.match(lines[i]):
            # skip the body: count braces from this line to depth 0
            depth = 0
            while i < n:
                depth += lines[i].count("{") - lines[i].count("}")
                i += 1
                if depth <= 0:
                    break
            continue
        out.append(lines[i])
        i += 1
    return "\n".join(out) + "\n"


def main():
    if not os.path.isdir(SRC):
        sys.exit("cfrontsz-probe: run me from the repo root")
    srcfile = os.path.join(SRC, sys.argv[1] if len(sys.argv) > 1 else "main.c")
    decls = declarations(srcfile)
    open(os.path.join(SRC, "cfrontsz-decls.h"), "w").write(decls)

    ents = {}
    for m in TAGGED.finditer(decls):
        ents[m.group(2)] = (m.group(1), int(m.group(3)))

    # COMPLETENESS, which the gcc control cannot check: every tagged
    # type in the file must survive into the extraction. The preamble
    # version silently dropped 50 of main.c's 97 and still reported a
    # clean control.
    whole = len(set(m.group(2) for m in
                    TAGGED.finditer(open(srcfile, encoding="latin1").read())))
    if len(ents) != whole:
        print("cfrontsz-probe: INCOMPLETE EXTRACTION -- %d of %d tagged "
              "types in %s. The ones left out are not measured and the "
              "control cannot tell." % (len(ents), whole, srcfile))
        return 2

    out = ['/* GENERATED by sys/lib/tests/cfrontsz-probe.py -- do not edit. */',
           '#include "cfrontsz-decls.h"',
           "extern int printf(const char*, ...);",
           "int main(void){ int bad=0, n=0, same=0;"]
    for name, (kw, sz) in sorted(ents.items()):
        out.append('  n++; if(sizeof(%s %s)!=%d){ printf('
                   '"  %%-26s here %%4d   translator %%4d   *** DIFFERENT ***\\n",'
                   '"%s",(int)sizeof(%s %s),%d); bad++; }'
                   % (kw, name, sz, name, kw, name, sz))
        # The agreements are NOT printed: at 97 types the table no
        # longer fits a screen, and a screenshot that scrolls off the
        # top is how a reading gets lost. The tally below says how many
        # agreed, so "nothing printed" is still distinguishable from
        # "did not run".
        out.append("  else same++;")
    out.append('  printf("\\n%d of %d disagree, %d agree '
               '(agreements not listed)\\n", bad, n, same);')
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
