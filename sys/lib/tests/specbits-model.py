#!/usr/bin/env python3
#
# specbits-model.py -- after 9front's `a68335214' (cc: untangle class
# and type specifiers), do kencc's declaration-specifier bits still fit
# in a 32-bit `long', and does anything alias anything?
#
#	python3 sys/lib/tests/specbits-model.py
#	python3 sys/lib/tests/specbits-model.py --old   # replay the old numbering
#
# ***A MODEL, NOT A TEST.***  It runs on the BUILD HOST and reads the
# enum out of `sys/src/cmd/cc/cc.h' rather than transcribing it, because
# **kencc cannot be compiled here at all** -- its sources open with
# `#include <u.h>' and `<libc.h>', so the first build of any `cc/'
# change is the VM's.  That is the same reason `sualign-model' and
# `clitzero-model' exist.
#
# WHY THE QUESTION IS WORTH A FILE.  Every `B...' in `cc.h' is
# `1L<<T...', and before this commit the TYPES, the STORAGE CLASSES and
# the QUALIFIERS all drew from one numbering.  `BNORET' had reached
# `1L<<31' -- `cc.y' carries a note saying so -- and `long' is 32 bits
# under kencc, so the next specifier APExp wanted would have shifted
# off the end.  **Shifting off the end of a signed long is not a
# diagnostic, it is a wrong constant**, and the constant is used to
# decide what a declaration means.
#
# The commit gives the classes their own numbering (`CG...', from 0)
# and passes the two halves as a `Spec'.  So:
#
#   - the two groups MAY now overlap in value, and that is the point,
#     because they live in different struct members;
#   - within each group the bits must still be distinct and in range.
#
# ***AND APExp'S MERGE IS NOT UPSTREAM'S PATCH, WHICH IS THE REAL
# REASON TO CHECK ARITHMETIC RATHER THAN READ IT.***  Upstream puts
# `TUNSIGNED' at `NTYPE'.  APExp had already put `TCFLOAT' there for
# C99 `_Complex', so `TCFLOAT' and `TAUTO' were THE SAME NUMBER before
# this commit, and `TCDOUBLE' and `TEXTERN' were too.  That was
# harmless only because the complex codes are `etype' values indexing
# `[NCTYPE]' arrays and never enter the bit space -- there is no
# `BCFLOAT'.  *A collision that is harmless because of how the values
# happen to be used is one the next change can expose.*  The merge puts
# the pseudo-types after `NCTYPE' instead, and this file is what says
# the result has no second accidental overlap.
#
# `--old' replays the pre-commit numbering, so the headroom the change
# bought is a number rather than a claim.  **Without it this model
# could only ever pass**, which is the rule about a check that cannot
# fail.

import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.dirname(os.path.abspath(__file__)))))
CCH = os.path.join(ROOT, 'sys/src/cmd/cc/cc.h')

if not os.path.exists(CCH):
    sys.stderr.write('specbits-model: %s not found -- ROOT is wrong\n' % CCH)
    sys.exit(2)

LONGBITS = 32   # kencc's long, on every target


def read_enum(text):
    """Assign values to the type/class enumerators exactly as C would:
    sequential, restarting at any `NAME = value'."""
    vals, cur = {}, 0
    body = text[text.index('TXXX'):text.index('TRUNE')]
    for line in body.splitlines():
        line = re.sub(r'/\*.*?\*/', '', line).strip().rstrip(',')
        if not line or line.startswith(('*', '/*', '#')):
            continue
        m = re.match(r'^([A-Z][A-Z0-9_]*)\s*=\s*(.+)$', line)
        if m:
            name, expr = m.group(1), m.group(2).strip()
            if re.match(r'^[A-Z][A-Z0-9_]*$', expr) and expr in vals:
                cur = vals[expr]
            elif expr.isdigit():
                cur = int(expr)
            else:
                continue        # a computed one such as TRUNE; not a slot
            vals[name] = cur
            cur += 1
            continue
        m = re.match(r'^([A-Z][A-Z0-9_]*)$', line)
        if m:
            vals[m.group(1)] = cur
            cur += 1
    return vals


# The pre-commit numbering, for --old.  Transcribed from the enum this
# merge replaced; it is the control and nothing reads it otherwise.
OLD = ['TXXX', 'TCHAR', 'TUCHAR', 'TSHORT', 'TUSHORT', 'TINT', 'TUINT',
       'TLONG', 'TULONG', 'TVLONG', 'TUVLONG', 'TFLOAT', 'TDOUBLE', 'TIND',
       'TFUNC', 'TARRAY', 'TVOID', 'TSTRUCT', 'TUNION', 'TENUM', 'TDOT',
       'NTYPE']
OLD_AT_NTYPE = ['TAUTO', 'TEXTERN', 'TSTATIC', 'TTYPEDEF', 'TTYPESTR',
                'TREGISTER', 'TCONSTNT', 'TVOLATILE', 'TUNSIGNED', 'TSIGNED',
                'TNORET', 'TOLD']
OLD_COMPLEX = ['TCFLOAT', 'TCDOUBLE']

TYPE_BITS = ['BCHAR', 'BUCHAR', 'BSHORT', 'BUSHORT', 'BINT', 'BUINT', 'BLONG',
             'BULONG', 'BVLONG', 'BUVLONG', 'BFLOAT', 'BDOUBLE', 'BIND',
             'BFUNC', 'BARRAY', 'BVOID', 'BSTRUCT', 'BUNION', 'BENUM', 'BDOT',
             'BUNSIGNED', 'BSIGNED']
CLASS_BITS = ['BAUTO', 'BEXTERN', 'BSTATIC', 'BTYPEDEF', 'BTYPESTR',
              'BREGISTER', 'BCONSTNT', 'BVOLATILE', 'BNORET']


def bit_shifts(text, names):
    """Read `BNAME = 1L<<SHIFTNAME,' out of cc.h and return the shift
    NAME each uses, so the model reports what the file says rather than
    what it is assumed to say."""
    out = {}
    for n in names:
        m = re.search(r'\b%s\s*=\s*1L<<\s*([A-Z][A-Z0-9_]*)' % n, text)
        if m:
            out[n] = m.group(1)
    return out


def report_old():
    print('--old: the numbering this merge replaced')
    vals, cur = {}, 0
    for n in OLD:
        vals[n] = cur
        cur += 1
    base = vals['NTYPE']
    for i, n in enumerate(OLD_COMPLEX):
        vals[n] = base + i
    for i, n in enumerate(OLD_AT_NTYPE):
        vals[n] = base + i
    print('  NTYPE = %d' % base)
    print('  TCFLOAT = %d and TAUTO = %d  -> %s'
          % (vals['TCFLOAT'], vals['TAUTO'],
             'ALIAS' if vals['TCFLOAT'] == vals['TAUTO'] else 'distinct'))
    print('  TCDOUBLE = %d and TEXTERN = %d -> %s'
          % (vals['TCDOUBLE'], vals['TEXTERN'],
             'ALIAS' if vals['TCDOUBLE'] == vals['TEXTERN'] else 'distinct'))
    hi = max(vals[n] for n in ('TNORET', 'TOLD'))
    print('  highest specifier shift = %d (TNORET=%d, TOLD=%d)'
          % (hi, vals['TNORET'], vals['TOLD']))
    print('  1L<<%d in a %d-bit long -> %s'
          % (vals['TNORET'], LONGBITS,
             'FITS, with %d shift(s) to spare'
             % (LONGBITS - 1 - vals['TNORET'])
             if vals['TNORET'] < LONGBITS else 'OVERFLOWS'))
    return 0


def main():
    if '--old' in sys.argv:
        return report_old()
    text = open(CCH, errors='replace').read()
    vals = read_enum(text)
    shifts = bit_shifts(text, TYPE_BITS + CLASS_BITS)

    missing = [n for n in TYPE_BITS + CLASS_BITS if n not in shifts]
    if missing:
        print('could not find a `1L<<...` for: %s' % ', '.join(missing))
        return 1

    fail = 0
    print('cc.h: NTYPE=%s NCTYPE=%s NALLTYPES=%s NCGTYPE=%s'
          % (vals.get('NTYPE'), vals.get('NCTYPE'),
             vals.get('NALLTYPES'), vals.get('NCGTYPE')))

    for label, names in (('type', TYPE_BITS), ('class', CLASS_BITS)):
        used = {}
        for n in names:
            s = shifts[n]
            v = vals.get(s)
            if v is None:
                print('  %-10s %s: shift %s has no value' % (label, n, s))
                fail += 1
                continue
            if v >= LONGBITS:
                print('  %-10s %-10s = 1L<<%-12s = shift %d -- OVERFLOWS a '
                      '%d-bit long' % (label, n, s, v, LONGBITS))
                fail += 1
            used.setdefault(v, []).append('%s(%s)' % (n, s))
        dup = {v: ns for v, ns in used.items() if len(ns) > 1}
        hi = max(used) if used else -1
        print('  %-5s bits: %2d names, highest shift %2d, %2d spare, '
              'collisions: %s'
              % (label, len(names), hi, LONGBITS - 1 - hi,
                 ('; '.join('%d: %s' % (v, ' '.join(ns))
                            for v, ns in sorted(dup.items()))
                  if dup else 'none')))
        if dup:
            fail += len(dup)

    # The complex codes must be real etypes below NCTYPE, and the
    # pseudo-types must start at or after it.
    for n in ('TCFLOAT', 'TCDOUBLE'):
        v, nc = vals.get(n), vals.get('NCTYPE')
        if v is None or nc is None or not (vals['NTYPE'] <= v < nc):
            print('  %s = %s is not in [NTYPE, NCTYPE) -- complex etypes '
                  'index [NCTYPE] arrays' % (n, v))
            fail += 1
    for n in ('TUNSIGNED', 'TSIGNED', 'TOLD'):
        v, nc = vals.get(n), vals.get('NCTYPE')
        if v is None or nc is None or v < nc:
            print('  %s = %s is below NCTYPE=%s -- it would alias a complex '
                  'etype' % (n, v, nc))
            fail += 1

    print('%d problem(s)' % fail)
    print('run with --old to see the numbering this replaced')
    return 1 if fail else 0


if __name__ == '__main__':
    sys.exit(main())
