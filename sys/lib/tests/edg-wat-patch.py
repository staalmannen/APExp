#!/usr/bin/env python3
"""edg-wat-patch.py -- instrument EDG's corpus for the allocation record.

    cd sys/src/external/edg/src
    git checkout <clean rev> -- .
    python3 ../../../../lib/tests/edg-wat-patch.py

***THIS FILE EXISTS BECAUSE THE PATCH WAS THREE SEPARATE STEPS AND ONE
OF THEM WAS FORGOTTEN.***  The corpus was reverted and re-patched to
add call-site tags, the arming of `edg_wat_find' in `edg_tok_note' was
a different snippet run by hand, and it did not get re-run -- so the
next VM round came back `edg_wat_found = 0' with every other field
healthy.  *An instrument that is correct in three pieces is not an
instrument.*  All three edits are here and each one GATES.

It makes exactly three changes, and `edg-wat-impl.c' is the body it
inserts:

 1. EVERY definition of `alloc_fe' and `alloc_fe_var_size' records its
    result.  There are **41** and **34** of them, one per TU that uses
    the function, and `cmd/edg/mkfile' passes `-C' so `6l' keeps the
    FIRST and discards the rest -- so patching a subset can patch a
    copy that is not the live one, which is what happened when an
    earlier version keyed on EDG's temp names and missed 14 files.
    **The anchors here carry no temp name**: the definition is found
    by its parameter spelling and the return by the first
    `return (char *)X;' after it, whatever X is called.

 2. EVERY `alloc_fe(32ULL)' call site is TAGGED with a number, written
    to `edg-wat-sites.txt' beside this file.  58 sites, 24 of them
    `struct a_token_cache'.  This is how the object is identified,
    because neither of the other two ways works: the block is
    recycled, so its bytes at death are not its type, and a search of
    every aggregate in all 75 TUs (4812 distinct, 757 of them 32
    bytes) found **zero** with the observed layout.

 3. `edg_tok_note' in `lexical.c' ARMS the search, calling
    `edg_wat_find(elems)' at the first lookup whose token is below the
    text base.  That lookup is the faulting one, reached *before* the
    dereference, so the one moment the victim's address is known is
    also a moment at which code can still run.  **Nothing is
    hardcoded** -- no address (they move with BSS, measured three
    times), no size (248 bytes named 1222 allocations), no ring depth
    (the victim is allocated early and any ring evicts it).
"""

import collections
import glob
import os
import re
import sys

DEF_FE = re.compile(r'char \*_ZN3edg8alloc_feEy\( _ZN3edg8sizeof_tE (__\w+)\)')
DEF_VAR = re.compile(
    r'char \*_ZN3edg17alloc_fe_var_sizeEyPy\( _ZN3edg8sizeof_tE (__\w+),\s*\n?\s*'
    r'_ZN3edg8sizeof_tE \*(__\w+)\)')
RET = re.compile(r'return \(char \*\)(__\w+);')
TAG = '_ZN3edg8alloc_feEy(32ULL)'

DECL = ('extern void edg_wat_note(void *, unsigned long long, long);\n'
        'extern void edg_wat_find(void *);\n'
        'extern long edg_wat_found;\n'
        'extern long edg_wat_site;\n'
        'extern long edg_wat_armed;\n')

HERE = os.path.dirname(os.path.abspath(__file__))
IMPL = open(os.path.join(HERE, 'edg-wat-impl.c')).read()

ARM_OLD = """  i = (edg_tok_calls - 1) & 63;
  edg_tok_ring_val[i] = tok;"""
ARM_NEW = """  /*
   * ***THE SEARCH AIMS ITSELF HERE.***  This runs on every lookup, and
   * the faulting one reaches it BEFORE the dereference that kills the
   * process -- so the one moment at which the victim's address is
   * known is also a moment at which code can still run.  A token below
   * the text base (0x200000) was never an address; that is the whole
   * test, and it needs no constant from any previous run.
   */
  edg_wat_armed = 1;
  if (!edg_wat_found && (unsigned long long)tok < 0x200000ULL
      && edg_tok_elems != (void *)0)
    edg_wat_find(edg_tok_elems);

  i = (edg_tok_calls - 1) & 63;
  edg_tok_ring_val[i] = tok;"""


def fail(msg):
    sys.exit('edg-wat-patch: GATE FAILED: %s' % msg)


def patch_return(s, dmatch, sizeexpr, kind):
    r = RET.search(s, dmatch.end())
    if not r:
        fail('no `return (char *)X;\' after a definition')
    body = ('return (char *)(edg_wat_note(%s, (unsigned long long)(%s), %d), %s);'
            % (r.group(1), sizeexpr, kind, r.group(1)))
    return s[:r.start()] + body + s[r.end():]


def main():
    files = sorted(glob.glob('*.c'))
    if not files:
        fail('no *.c here -- run this from sys/src/external/edg/src')
    if any('edg_wat_note' in open(f).read() for f in files):
        fail('already patched -- revert the corpus first')

    fe = [f for f in files if DEF_FE.search(open(f).read())]
    var = [f for f in files if DEF_VAR.search(open(f).read())]
    print('definitions: alloc_fe %d, alloc_fe_var_size %d' % (len(fe), len(var)))

    # ---- 1: every definition of both allocators ----------------------
    for f in sorted(set(fe) | set(var)):
        s = open(f).read()
        d = DEF_VAR.search(s)
        if d:
            s = patch_return(s, d, '*' + d.group(2), 2)
        d = DEF_FE.search(s)
        if d:
            s = patch_return(s, d, d.group(1), 1)
        open(f, 'w').write((IMPL if f == 'mem_manage.c' else DECL) + s)

    # ---- 2: every alloc_fe(32ULL) call site --------------------------
    sites, n = [], 0
    for f in files:
        s = open(f).read()
        if TAG not in s:
            continue
        out, pos = [], 0
        while True:
            i = s.find(TAG, pos)
            if i < 0:
                out.append(s[pos:])
                break
            n += 1
            ctx = s[max(0, i - 110):i]
            m = re.findall(r'\(\(?(?:struct )?(_ZN3edg[A-Za-z0-9_]*E)[ *]*\)?\($', ctx)
            sites.append((n, f, s.count('\n', 0, i) + 1, m[-1] if m else '?'))
            out.append(s[pos:i])
            out.append('(edg_wat_site = %d, %s)' % (n, TAG))
            pos = i + len(TAG)
        open(f, 'w').write(''.join(out))

    # ---- 3: arm the search in edg_tok_note ---------------------------
    s = open('lexical.c').read()
    if s.count(ARM_OLD) != 1:
        fail('edg_tok_note not found in lexical.c, or found twice -- '
             'the ring code it anchors on has moved')
    open('lexical.c', 'w').write(s.replace(ARM_OLD, ARM_NEW, 1))

    with open(os.path.join(HERE, 'edg-wat-sites.txt'), 'w') as fh:
        fh.write('# tag -> file:line -> type, for every alloc_fe(32ULL) site.\n'
                 '# Generated by edg-wat-patch.py; read it beside `nbr_site\'\n'
                 '# from cxx-vecacid.  A site of 0 means the 32 bytes came from\n'
                 '# a call whose size is not the literal 32ULL, which is a\n'
                 '# finding of its own.\n')
        for t, f, l, ty in sites:
            fh.write('%3d  %-22s:%-7d %s\n' % (t, f, l, ty))

    # ---- THE GATES ---------------------------------------------------
    # Phrased against the TEMP-AGNOSTIC definition lists and against the
    # files themselves, never against the anchors the patch used -- an
    # earlier check counted files matching the same temp-name anchor as
    # the patch, so it agreed by construction and reported 27 of 27
    # while 14 copies went unpatched.
    bad = [f for f in fe if ', 1), ' not in open(f).read()]
    if bad:
        fail('alloc_fe unpatched in %r' % bad)
    bad = [f for f in var if ', 2), ' not in open(f).read()]
    if bad:
        fail('alloc_fe_var_size unpatched in %r' % bad)
    if n != 58:
        fail('tagged %d alloc_fe(32ULL) sites, expected 58' % n)
    if 'edg_wat_note(void *p' not in open('mem_manage.c').read():
        fail('the implementation did not land in mem_manage.c')
    lex = open('lexical.c').read()
    if 'edg_wat_find(edg_tok_elems)' not in lex:
        fail('edg_tok_note is not armed -- the search would never run')
    if 'edg_wat_armed = 1;' not in lex:
        fail('the arming marker is missing -- `found = 0\' would be unreadable')

    print('patched: alloc_fe %d/%d, var_size %d/%d, sites %d, armed'
          % (len(fe), len(fe), len(var), len(var), n))
    print(collections.Counter(ty for _, _, _, ty in sites).most_common(4))
    print('all gates ok')


main()
