#!/usr/bin/env python3
#
# clitzero-model -- which BYTES of a compound literal's hidden auto does
# `cc/dcl.c's clitzero() actually store zero into?
#
#   python3 sys/lib/tests/clitzero-model.py
#
# WHY A MODEL.  kencc's own sources need Plan 9's `<u.h>' and `<libc.h>',
# so the gcc sweep this tree uses before shipping cannot be run on them and
# **the first build of any `cc/' change is the VM's** -- the weaker position
# `-J', the `auto' grammar fix, `-C' and `sualign()' all shipped from.  This
# closes part of that gap the same way `sualign-model.py' does, and with the
# same limit: *it says nothing about whether the compiler is correct, only
# whether this function's arithmetic is.*
#
# IT EXTRACTS THE REAL FUNCTION rather than restating it.  The body is
# lifted out of `dcl.c' verbatim and compiled against stub `Type'/`Node'
# and a stub `initz()' that marks bytes instead of building nodes -- so
# editing `dcl.c' and re-running this measures the edit.  *Replicate the
# code in the tree, not the code you remember.*
#
# WHAT IT CAN CATCH, which is exactly what a hand-written offset loop gets
# wrong: a gap left unzeroed, and a store that lands OUTSIDE the object.
# The second matters more than it looks -- `v' is a FRAME offset and is
# NEGATIVE, so every `%' in that function is a negative modulo, and one
# sign error writes zeros over a neighbouring local.
#
# WHAT IT CANNOT.  **It has no external oracle.** `sualign-model.py' must
# reproduce `tmp/abi-bf-before.acid' -- the real pcc's real answer -- or it
# refuses to print; there is no acid dump of "which bytes a store touches",
# so this has nothing of that kind to check itself against.  **Its CONTROL
# is therefore a deliberate break**: it compiles a second copy with the
# tail loop removed and requires that copy to FAIL, because a model that
# cannot report a bug it was built for is reporting nothing.
#
# Zeroing a byte that the initialiser also writes is CORRECT and is printed
# rather than flagged: `initz()' skips a word only when it is ENTIRELY
# covered, and every store clitzero() builds is prepended, so all of them
# run before the member assignments.  The map below shows it as `0' over
# what would otherwise be `i'.

import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                     '..', '..', '..'))
DCL = os.path.join(ROOT, 'sys', 'src', 'cmd', 'cc', 'dcl.c')

HARNESS = r'''
#include <stdio.h>
#include <string.h>
typedef struct Type Type;
typedef struct Node Node;
struct Type { long width; };
struct Node { int dummy; };
enum { TCHAR, TLONG, TVLONG, TIND, NTYPE };
static Type tc = {1}, tl = {4}, tv = {8}, ti = {8};
Type *types[NTYPE];
long ewidth[NTYPE];

#define SZ %(size)d
static int cov[SZ], zer[SZ];
static long BASE;
static int outside;

static int
covered(long o, long w)
{
	while(w > 0){
		long i = o - BASE;
		if(i < 0 || i >= SZ || !cov[i])
			return 0;
		o++; w--;
	}
	return 1;
}

static Node *
initz(Node *q, Type *t, long o, Node *n)
{
	long k;
	(void)q;
	if(covered(o, t->width))
		return n;
	for(k = 0; k < t->width; k++){
		long i = o + k - BASE;
		if(i >= 0 && i < SZ)
			zer[i] = 1;
		else
			outside++;
	}
	return n;
}

%(clitzero)s

int
main(void)
{
	long bases[] = { -%(size)d, -32, -40, -28, -8, -4088, -%(size)d-1 };
	unsigned b;
	Type t;
	int rc = 0;

	t.width = SZ;
	types[TCHAR]=&tc; types[TLONG]=&tl; types[TVLONG]=&tv; types[TIND]=&ti;
	ewidth[TCHAR]=1; ewidth[TLONG]=4; ewidth[TVLONG]=8; ewidth[TIND]=8;

	for(b = 0; b < sizeof bases/sizeof bases[0]; b++){
		int i, gap = 0;
		BASE = bases[b];
		outside = 0;
		memset(cov, 0, sizeof cov);
		memset(zer, 0, sizeof zer);
%(cover)s
		clitzero((Node*)0, &t, BASE, (Node*)0);
		for(i = 0; i < SZ; i++)
			if(!cov[i] && !zer[i])
				gap = 1;
		printf("  base %%6ld  ", BASE);
		for(i = 0; i < SZ; i++)
			putchar(zer[i] ? '0' : (cov[i] ? 'i' : '.'));
		if(gap){ printf("  *** GAP LEFT UNZEROED"); rc = 1; }
		if(outside){ printf("  *** %%d BYTES OUTSIDE THE OBJECT", outside); rc = 1; }
		if(!gap && !outside) printf("  ok");
		putchar('\n');
	}
	return rc;
}
'''

# (name, size, [(offset, width) the initialiser writes])
CASES = [
    # muon's struct tstr: buf@0, len@8 OMITTED, cap@12, flags@16, s@20 OMITTED
    ('muon struct tstr, .len and .s omitted', 24, [(0, 8), (12, 4), (16, 4)]),
    # a gap in the middle only
    ('gap in the middle', 24, [(0, 8), (16, 8)]),
    # nothing written at all -- (T){} / a literal whose list is empty
    ('nothing written', 24, []),
    # everything written -- must emit no store at all
    ('fully covered', 24, [(0, 24)]),
    # an odd size, so the tail loop is the one that has to finish it
    ('odd size, trailing gap', 13, [(0, 8)]),
    # a big one, where the body loop does the work
    ('large, one hole', 64, [(0, 8), (16, 48)]),
]


def extract():
    src = open(DCL, encoding='utf-8', errors='replace').read()
    m = re.search(r'^static Node\*\nclitzero\(.*?^\}', src, re.S | re.M)
    if m is None:
        print('clitzero-model: cannot find clitzero() in %s' % DCL)
        print('(an extraction that finds nothing reports a clean tree as a')
        print(' missing one -- refusing rather than printing 0 findings)')
        sys.exit(2)
    return m.group(0).replace('static Node*\n', 'static Node *\n', 1)


def build_and_run(clitzero, name, size, writes, tag):
    cover = '\n'.join(
        '\t\t{ int k; for(k = %d; k < %d; k++) cov[k] = 1; }' % (o, o + w)
        for (o, w) in writes) or '\t\t;'
    src = HARNESS % dict(size=size, clitzero=clitzero, cover=cover)
    with tempfile.TemporaryDirectory() as d:
        c = os.path.join(d, 'm.c')
        x = os.path.join(d, 'm')
        open(c, 'w').write(src)
        r = subprocess.run(['gcc', '-O0', '-o', x, c],
                           capture_output=True, text=True)
        if r.returncode != 0:
            print('%s: WILL NOT COMPILE' % tag)
            print(r.stderr.strip()[:2000])
            return None
        r = subprocess.run([x], capture_output=True, text=True)
        return r.returncode, r.stdout


def main():
    if not os.path.isfile(DCL):
        print('clitzero-model: %s is not an APExp root' % ROOT)
        return 2

    clitzero = extract()
    bad = 0
    print('clitzero(), as extracted from cc/dcl.c:\n')
    for (name, size, writes) in CASES:
        print('%s  (%d bytes)' % (name, size))
        out = build_and_run(clitzero, name, size, writes, name)
        if out is None:
            return 2
        rc, text = out
        sys.stdout.write(text)
        if rc:
            bad += 1
        print('')

    # ---- the control.  Break it on purpose and require the model to notice.
    print('control: the same function with its TAIL loop removed --')
    print('         it must report a gap, or this model reports nothing.')
    broken = re.sub(r'/\* and whatever tail is left over \*/\n'
                    r'\twhile\(w > 0\) \{.*?\n\t\}\n', '', clitzero, flags=re.S)
    if broken == clitzero:
        print('  *** the control could not be applied -- the tail loop was')
        print('  *** not found, so this run proves nothing about the model')
        return 2
    out = build_and_run(broken, 'control', 13, [(0, 8)], 'control')
    if out is None:
        return 2
    rc, text = out
    sys.stdout.write(text)
    if rc == 0:
        print('  *** CONTROL DID NOT FIRE: a clitzero() that leaves a')
        print('  *** trailing gap was reported as ok, so a clean run above')
        print('  *** means nothing.')
        return 2
    print('  control fired, so a clean run above is a real one.\n')

    if bad:
        print('%d case(s) FAILED' % bad)
    else:
        print('all cases ok: every uncovered byte is zeroed, nothing is')
        print('stored outside the object, and a fully-covered object costs')
        print('no stores at all.')
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
