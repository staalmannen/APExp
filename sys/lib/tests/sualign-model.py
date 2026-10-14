#!/usr/bin/env python3
#
# sualign-model -- what does `cc/dcl.c's sualign() compute, under each
# bit-field rule, for shapes whose answer gcc and acid already know?
#
#   python3 sys/lib/tests/sualign-model.py
#
# WHY A MODEL AND NOT A TEST.  kencc's own sources need Plan 9's `<u.h>`
# and `<libc.h>`, so the gcc sweep this tree uses before shipping cannot
# be run on them and **the first build of any `cc/' change is the VM's**
# -- the weaker position `-J`, the `auto' grammar fix and the `-C' flag
# all shipped from.  This closes part of that gap: the TSTRUCT arm is
# arithmetic over four variables, and arithmetic can be transcribed and
# checked here.  *It does not compile a line of kencc and says nothing
# about whether the C is right* -- only whether the rule is.
#
# ITS CONTROL IS `__res_state', AND THAT IS WHAT MAKES IT ADMISSIBLE.
# The model must reproduce `tmp/abi-bf-before.acid' -- the real pcc's
# real answer, measured on the VM -- for the one public APE struct that
# the change moves: `pfcode' 360, `ndots' 364, `unused' **368**,
# `sort_list' 372, `sizeof' **456**.  A transcription that reproduces
# the known answer is faithful; one that does not is modelling a
# different compiler, which is the rule `edgtuoff-probe' already
# carries.  **It refuses to print the patched prediction unless the
# control passes.**
#
# IT ALREADY PAID, AND FOR A COMMENT RATHER THAN FOR CODE.  The patch's
# own comment claimed kencc does not restart the container when an
# ordinary member sits BETWEEN two bit fields, and built the `nw > w'
# monotone guard on that.  The model disagreed with the comment, and
# `cc.y's `edecor: xdecor' arm settles it: `lastbit = 0; firstbit = 1;'
# for every ordinary declarator, so the container DOES restart and the
# guard cannot fire.  *An almost-true claim presented as verified is
# worse than none* -- the `cmd/edg/mkfile' lesson, caught this time
# before the VM rather than after.
#
# AND IT NAMES THE DIVERGENCE THAT REMAINS, with numbers rather than a
# paragraph.  `after' and `between' are the cases where a bit field
# FOLLOWS a small ordinary member: kencc rounds the container up to a
# `tfield' boundary at group start (`w = round(w, tfield->width)'),
# where gcc puts it at the next free byte.  So `struct{char c;
# unsigned a:1; char d;}' is `d@2 size 4' on gcc and `d@5 size 8' here
# even patched.  **That is a SECOND rule and deliberately out of
# scope**: the change in hand is the sharing of a container's TAIL, and
# EDG's corpus needs only that.  The two are listed so the next reader
# gets the measured gap instead of discovering it.

TFIELD = 4      # tfield->width

def layout(members, conformalign, packflg=False):
    """Transcribes the TSTRUCT arm of sualign(), both rules.

    members: (name, width, align, nbits), nbits None for an ordinary one.
    `firstbit'/`lastbit' follow dcl.c's OBIT arm and cc.y's `edecor:
    xdecor' action, which resets both for every ordinary declarator.
    """
    w = 0; bw = 0; a = 1; o = 0
    lastbit = 0; firstbit = True
    out = []
    for (nm, wid, al, nbits) in members:
        if nbits is not None:
            lastbit += nbits
            if lastbit > TFIELD * 8:        # container overflow
                lastbit = nbits
                firstbit = True
            shift = lastbit - nbits
            if firstbit:
                w = ((w + TFIELD - 1) // TFIELD) * TFIELD
                o = w
                if not conformalign:
                    w += TFIELD             # the whole unit, MSVC's rule
                elif o + TFIELD > bw:
                    bw = o + TFIELD         # the cover guard
                firstbit = False
            out.append((nm, o))
            if conformalign:
                nw = o + (shift + nbits + 7) // 8
                if nw > w:
                    w = nw
            ma = 1 if packflg else TFIELD
        else:
            ea = 1 if packflg else al
            w = ((w + ea - 1) // ea) * ea
            out.append((nm, w))
            w += wid
            ma = ea
            firstbit = True                 # cc.y: edecor: xdecor
            lastbit = 0
        if ma > a:
            a = ma
    if conformalign and bw > w:
        w = bw
    talign = a if conformalign else 8       # Asu2: SZ_VLONG when not -J
    size = ((w + talign - 1) // talign) * talign
    return dict(out), size

# ---- the control: the real pcc's real answer, from tmp/abi-bf-before.acid
RES_STATE = [
    ('retrans', 4, 4, None), ('retry', 4, 4, None), ('options', 4, 4, None),
    ('nscount', 4, 4, None), ('nsaddr_list', 48, 4, None), ('id', 2, 2, None),
    ('dnsrch', 32, 8, None), ('defdname', 256, 1, None), ('pfcode', 4, 4, None),
    ('ndots', 0, 0, 4), ('nsort', 0, 0, 4),
    ('unused', 3, 1, None), ('sort_list', 80, 4, None),
]
ACID = {'pfcode': 360, 'ndots': 364, 'nsort': 364, 'unused': 368,
        'sort_list': 372}
ACID_SIZE = 456

# ---- the shapes, with gcc's measured answers
CASES = [
    # name,      members,                                     key, gcc off, gcc size
    ('shares',   [('a',0,0,4),('b',0,0,4),('c',3,1,None)],      'c', 1, 4),
    ('aligned',  [('a',0,0,11),('b',0,0,5),('c',4,4,None)],     'c', 4, 8),
    ('trailing', [('p',8,8,None),('a',0,0,1),('b',0,0,1),('c',0,0,1)],
                                                               None, 0, 16),
    ('split',    [('a',0,0,3),('b',0,0,3),('c',1,1,None)],      'c', 1, 4),
    ('overflow', [('a',0,0,30),('b',0,0,30),('c',1,1,None)],    'c', 8, 12),
    # OUT OF SCOPE: a bit field following a small ordinary member.
    ('after',    [('c',1,1,None),('a',0,0,1),('d',1,1,None)],   'd', 2, 4),
    ('between',  [('a',0,0,1),('x',1,1,None),('b',0,0,1),('y',1,1,None)],
                                                                'y', 3, 4),
]
OUT_OF_SCOPE = ('after', 'between')

def main():
    off, size = layout(RES_STATE, False)
    bad = [k for k, v in ACID.items() if off[k] != v]
    if bad or size != ACID_SIZE:
        print("CONTROL FAILED -- the model does not reproduce the measured")
        print("acid dump of __res_state, so it is modelling some other")
        print("compiler and its predictions mean nothing.")
        for k in sorted(ACID):
            print("   %-12s model %4d   acid %4d%s" %
                  (k, off[k], ACID[k], "   ***" if off[k] != ACID[k] else ""))
        print("   %-12s model %4d   acid %4d%s" %
              ('sizeof', size, ACID_SIZE, "   ***" if size != ACID_SIZE else ""))
        return 1
    print("control: __res_state under HEAD's rule reproduces the acid dump")
    print("         (pfcode 360, ndots 364, unused 368, sort_list 372, 456)\n")

    print("%-9s %-21s %-21s %-21s" % ("case", "HEAD (pcc)", "PATCHED", "gcc"))
    fails = 0
    for nm, mem, key, goff, gsize in CASES:
        oh, sh = layout(mem, False)
        oc, sc = layout(mem, True)
        def f(o, s):
            return ("size %d" % s) if key is None else \
                   ("off(%s)=%d size=%d" % (key, o[key], s))
        g = ("size %d" % gsize) if key is None else \
            ("off(%s)=%d size=%d" % (key, goff, gsize))
        mark = ""
        if f(oc, sc) != g:
            if nm in OUT_OF_SCOPE:
                mark = "  <- out of scope, see header"
            else:
                mark = "  *** PATCHED DISAGREES WITH gcc ***"
                fails += 1
        print("%-9s %-21s %-21s %-21s%s" % (nm, f(oh, sh), f(oc, sc), g, mark))

    offc, sizec = layout(RES_STATE, True)
    print("\n__res_state, the one public APE struct that moves:")
    print("   unused    368 -> %d" % offc['unused'])
    print("   sort_list 372 -> %d" % offc['sort_list'])
    print("   sizeof    456 -> %d   (talign is 8: dnsrch is char *[])" % sizec)
    print("\n%d in-scope disagreement(s) with gcc" % fails)
    return 1 if fails else 0

if __name__ == '__main__':
    raise SystemExit(main())
