#!/usr/bin/env python3
#
# bitinit-model -- which BYTES does `cc/dcl.c's `gbitagg()' write for a
# struct's statically-initialised bit fields, and are they the bytes
# gcc puts there?
#
#   python3 sys/lib/tests/bitinit-model.py
#
# WHY A MODEL.  kencc's own sources need Plan 9's `<u.h>' and
# `<libc.h>', so the first build of any `cc/' change is the VM's --
# and this particular change had already cost one full `mk distclean'
# plus `mk install' when the head-sharing rule stopped the tree in GNU
# make with eighty-odd `_convM2D: multiple initialization'.  The
# arithmetic is twenty lines; arithmetic can be transcribed and
# checked here, and gcc's own object file is the oracle.
#
# WHAT IT CHECKS, and it is a stronger question than the layout model
# next door.  For each shape it
#   1. lays the struct out with `sualign-model.py's `layout()', which
#      already reproduces the acid dump and agrees with gcc;
#   2. accumulates each bit-field GROUP the way `init1' does --
#      `(value & mask) << shift', OR'd, zero constants skipped;
#   3. runs `gbitagg()''s byte loop over the group's own span;
#   4. lays those records plus the ordinary members' into a byte image;
#   5. compiles the SAME struct and initialiser with gcc and reads the
#      object's bytes back, and compares.
#
# **THE COMPARISON IS THE WHOLE INSTRUMENT, AND THE OVERLAP CHECK IS
# HALF OF IT.** Writing a record twice is exactly what `6l' diagnoses,
# so the image is built with a written-mask and any byte written twice
# is reported as `OVERLAP' -- the model reproduces the LINKER's
# complaint rather than only the final bytes.  A version that merely
# compared the finished image would score the old code as correct,
# since its four-byte write happens to leave the right bits where the
# one-byte writes had already put them.
#
# THE CONTROL IS SHAPE `plain': no bit fields at all.  If it
# disagrees, the model's own byte image or its gcc reader is wrong and
# nothing below it means anything.
#
# Re-run after any edit to `gbitagg()' or to the group-boundary test
# in `init1()'.

import os
import re
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import importlib.util
_spec = importlib.util.spec_from_file_location(
    "sualign_model", os.path.join(HERE, "sualign-model.py"))
_sm = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(_sm)
layout = _sm.layout

TFIELD = 4


# ---------------------------------------------------------------- cases
# (name, C struct body, members, initialiser values)
# members: (name, width, align, nbits) exactly as sualign-model takes,
# with the VALUE appended.
CASES = [
    ("plain",                           # the CONTROL -- no bit fields
     "void *p; const char *name; unsigned char a, b, c;",
     [("p", 8, 8, None, 0), ("name", 8, 8, None, 0),
      ("a", 1, 1, None, 11), ("b", 1, 1, None, 22), ("c", 1, 1, None, 33)],
     "{ 0, 0, 11, 22, 33 }"),

    ("ftab",                            # GNU make's function_table_entry
     "void *fptr; const char *name; unsigned char len, mn, mx;"
     " unsigned int expand:1; unsigned int alloc:1; unsigned int adds:1;",
     [("fptr", 8, 8, None, 0), ("name", 8, 8, None, 0),
      ("len", 1, 1, None, 7), ("mn", 1, 1, None, 1), ("mx", 1, 1, None, 1),
      ("expand", 0, 0, 1, 1), ("alloc", 0, 0, 1, 0), ("adds", 0, 0, 1, 0)],
     "{ 0, 0, 7, 1, 1, 1, 0, 0 }"),

    ("ftab_all",                        # all three bits set
     "void *fptr; const char *name; unsigned char len, mn, mx;"
     " unsigned int expand:1; unsigned int alloc:1; unsigned int adds:1;",
     [("fptr", 8, 8, None, 0), ("name", 8, 8, None, 0),
      ("len", 1, 1, None, 5), ("mn", 1, 1, None, 1), ("mx", 1, 1, None, 1),
      ("expand", 0, 0, 1, 1), ("alloc", 0, 0, 1, 1), ("adds", 0, 0, 1, 1)],
     "{ 0, 0, 5, 1, 1, 1, 1, 1 }"),

    ("tailshare",                       # the latent one, tail rule's
     "unsigned int a:1; unsigned int b:1; char c; char d;",
     [("a", 0, 0, 1, 1), ("b", 0, 0, 1, 1),
      ("c", 1, 1, None, ord('z')), ("d", 1, 1, None, ord('q'))],
     "{ 1, 1, 'z', 'q' }"),

    ("twogroup",                        # two groups, one container
     "unsigned int a:1; char c; unsigned int b:1; char d;",
     [("a", 0, 0, 1, 1), ("c", 1, 1, None, ord('c')),
      ("b", 0, 0, 1, 1), ("d", 1, 1, None, ord('d'))],
     "{ 1, 'c', 1, 'd' }"),

    ("span3",                           # a group spanning three bytes
     "char c; unsigned int a:17; char d;",
     [("c", 1, 1, None, ord('c')), ("a", 0, 0, 17, 0x1ABCD),
      ("d", 1, 1, None, ord('d'))],
     "{ 'c', 0x1ABCD, 'd' }"),

    ("withzero",                        # zero bit fields beside live bytes
     "unsigned char before; unsigned int z1:4; unsigned int nz:4;"
     " unsigned int z2:4; unsigned char after;",
     [("before", 1, 1, None, 0x5a), ("z1", 0, 0, 4, 0), ("nz", 0, 0, 4, 9),
      ("z2", 0, 0, 4, 0), ("after", 1, 1, None, 0xa5)],
     "{ 0x5a, 0, 9, 0, 0xa5 }"),
]


def emit(members, offsets, shifts, size):
    """Transcribes init1()'s bit-field accumulation and gbitagg()'s byte
    loop, and lays the records into an image.  Returns (image, overlaps)."""
    img = bytearray(size)
    written = bytearray(size)
    overlaps = []

    def put(off, nbytes, value):
        for i in range(nbytes):
            if written[off + i]:
                overlaps.append(off + i)
            written[off + i] = 1
            img[off + i] = (value >> (i * 8)) & 0xff

    # gbitagg(): the group's OWN bytes, one at a time, zeros skipped
    def flush(agg, ct_off, first, end):
        if agg is None:
            return
        b0 = first // 8
        b1 = (end + 7) // 8
        for b in range(b0, b1):
            byte = (agg >> ((b - ct_off) * 8)) & 0xff
            if byte:
                put(b, 1, byte)

    agg = None          # bitagg
    ct_off = 0          # bitaggt->offset
    first = 0           # bitfirst
    end = -1            # bitend

    for (nm, wid, al, nbits, val) in members:
        if nbits is None:
            if end != -1:
                flush(agg, ct_off, first, end)
                agg = None
                end = -1
            if val:                     # a zero constant needs no DATA
                put(offsets[nm], wid, val)
            continue
        fb = offsets[nm] * 8 + shifts[nm]
        if end != fb or agg is None:
            flush(agg, ct_off, first, end)
            agg = None
            ct_off = offsets[nm]
            first = fb
        end = fb + nbits
        if val:                         # init1 returns before accumulating 0
            v = (val & ((1 << nbits) - 1)) << shifts[nm]
            agg = v if agg is None else (agg | v)
    if end != -1:
        flush(agg, ct_off, first, end)

    return bytes(img), overlaps


def emit_old(members, offsets, shifts, size):
    """THE CONTROL: the code this replaced -- one DATA of `tfield's width
    at the CONTAINER, with a group boundary detected by container
    OFFSET.  `--old' runs it, and it must report an overlap for every
    shape that has a bit field and none for `plain'.

    *A model that cannot reproduce the failure it was written for has
    not earned the right to report the fix as clean*, and this one
    reproduces it to the byte: `ftab' overlaps at 16, 17 and 18, which
    is exactly what `DATA function_table_init<8>+16(SB)/4' wrote over."""
    img = bytearray(size)
    written = bytearray(size)
    overlaps = []

    def put(off, nbytes, value):
        for i in range(nbytes):
            if written[off + i]:
                overlaps.append(off + i)
            written[off + i] = 1
            img[off + i] = (value >> (i * 8)) & 0xff

    agg = None
    ct_off = 0
    bitoff = -1
    for (nm, wid, al, nbits, val) in members:
        if nbits is None:
            if val:
                put(offsets[nm], wid, val)
            continue
        if bitoff != offsets[nm] or agg is None:
            if agg is not None:
                put(ct_off, TFIELD, agg)
            agg = None
            ct_off = offsets[nm]
            bitoff = offsets[nm]
        if val:
            v = (val & ((1 << nbits) - 1)) << shifts[nm]
            agg = v if agg is None else (agg | v)
    if bitoff != -1 and agg is not None:
        put(ct_off, TFIELD, agg)
    return bytes(img), overlaps


def gcc_image(name, body, init, size):
    """gcc's own bytes for the same struct and initialiser."""
    with tempfile.TemporaryDirectory() as d:
        c = os.path.join(d, "x.c")
        o = os.path.join(d, "x.o")
        with open(c, "w") as f:
            f.write("struct %s { %s };\n" % (name, body))
            f.write("struct %s probe = %s;\n" % (name, init))
        subprocess.run(["gcc", "-w", "-c", "-o", o, c], check=True)
        nm = subprocess.run(["nm", "-S", o], capture_output=True, text=True,
                            check=True).stdout
        m = re.search(r"^([0-9a-f]+)\s+([0-9a-f]+)\s+\S\s+probe$", nm,
                      re.M)
        if m is None:
            return None, "probe not found in nm output"
        addr, gsize = int(m.group(1), 16), int(m.group(2), 16)
        if gsize != size:
            return None, "gcc sizeof %d, model %d" % (gsize, size)
        sec = subprocess.run(
            ["readelf", "-sW", o], capture_output=True, text=True,
            check=True).stdout
        m2 = re.search(r"^\s*\d+:\s+[0-9a-f]+\s+\d+\s+OBJECT\s+\S+\s+\S+\s+"
                       r"(\d+)\s+probe$", sec, re.M)
        if m2 is None:
            return None, "probe section not found"
        shn = m2.group(1)
        secs = subprocess.run(["readelf", "-SW", o], capture_output=True,
                              text=True, check=True).stdout
        m3 = re.search(r"^\s*\[\s*%s\]\s+(\S+)" % shn, secs, re.M)
        if m3 is None:
            return None, "section %s not named" % shn
        sname = m3.group(1)
        if sname == ".bss":
            return bytes(size), None
        raw = os.path.join(d, "raw.bin")
        subprocess.run(["objcopy", "-O", "binary", "--only-section=" + sname,
                        o, raw], check=True)
        with open(raw, "rb") as f:
            data = f.read()
        return data[addr:addr + size], None


def main():
    old = "--old" in sys.argv
    if old:
        print("bitinit-model --old: the CODE THIS REPLACED, which must")
        print("report an overlap for every shape but `plain'.\n")
    else:
        print("bitinit-model: the bytes gbitagg() writes, against gcc's own\n")
    bad = 0
    shapes = 0
    for (name, body, members, init) in CASES:
        lay = [(nm, w, a, nb) for (nm, w, a, nb, _v) in members]
        offsets, size, shifts = layout(lay, True, follow=True)
        fn = emit_old if old else emit
        img, overlaps = fn(members, offsets, shifts, size)
        ref, err = gcc_image(name, body, init, size)
        tag = "CONTROL " if name == "plain" else ""
        if err is not None:
            print("  %-10s %sSKIP   %s" % (name, tag, err))
            bad += 1
            continue
        mark = ""
        if overlaps or (ref is not None and img != ref):
            shapes += 1
        if overlaps:
            mark += "  *** OVERLAP at %s -- 6l would diag ***" % (
                sorted(set(overlaps)),)
            bad += 1
        if img != ref:
            mark += "  *** DIFFERS FROM gcc ***"
            bad += 1
        print("  %-10s %ssize %-3d model %s" %
              (name, tag, size, img.hex()))
        if img != ref or overlaps:
            print("  %-10s %sgcc   %s%s" % ("", " " * len(tag), ref.hex(), mark))
        elif mark:
            print("  %-10s %s%s" % ("", " " * len(tag), mark))

    if old:
        print("\n%d shape(s) reported -- 6 is the expected count, and"
              % shapes)
        print("`plain' staying clean is the other half of the control.")
        return 0
    print("\n%d problem(s)" % bad)
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
