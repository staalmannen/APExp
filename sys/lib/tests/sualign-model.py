#!/usr/bin/env python3
#
# sualign-model -- what does `cc/dcl.c's sualign() compute, under each
# bit-field rule, for shapes whose answer gcc and acid already know?
#
#   python3 sys/lib/tests/sualign-model.py
#
# WHY A MODEL AND NOT A TEST.  kencc's own sources need Plan 9's `<u.h>'
# and `<libc.h>', so the gcc sweep this tree uses before shipping cannot
# be run on them and **the first build of any `cc/' change is the VM's**
# -- the weaker position `-J', the `auto' grammar fix and the `-C' flag
# all shipped from.  This closes part of that gap: the TSTRUCT arm is
# arithmetic over a handful of variables, and arithmetic can be
# transcribed and checked here.  *It does not compile a line of kencc
# and says nothing about whether the C is right* -- only whether the
# rule is.
#
# ITS CONTROL IS `__res_state', AND THAT IS WHAT MAKES IT ADMISSIBLE.
# The model must reproduce `tmp/abi-bf-before.acid' -- the real pcc's
# real answer, measured on the VM -- for the one public APE struct that
# the SHARING change moves: `pfcode' 360, `ndots' 364, `unused' **368**,
# `sort_list' 372, `sizeof' **456**.  A transcription that reproduces
# the known answer is faithful; one that does not is modelling a
# different compiler, which is the rule `edgtuoff-probe' already
# carries.  **It refuses to print the predictions unless the control
# passes.**
#
# IT ALREADY PAID, AND FOR A COMMENT RATHER THAN FOR CODE.  The sharing
# patch's own comment claimed kencc does not restart the container when
# an ordinary member sits BETWEEN two bit fields, and built the `nw > w'
# monotone guard on that.  The model disagreed with the comment, and
# `cc.y's `edecor: xdecor' arm settles it: `lastbit = 0; firstbit = 1;'
# for every ordinary declarator, so the container DOES restart and the
# guard cannot fire.  *An almost-true claim presented as verified is
# worse than none* -- the `cmd/edg/mkfile' lesson, caught this time
# before the VM rather than after.
#
# ---------------------------------------------------------------------
# THERE ARE TWO RULES AND THIS MODELS BOTH, IN SEPARATE COLUMNS, BECAUSE
# ONLY A COLUMN PER RULE SAYS WHICH ONE FIXES WHICH CASE.
#
#   `share'  -- a bit-field group no longer reserves the whole `tfield'
#               unit, so the next ordinary member may sit in the unused
#               tail of its container.  Landed, confirmed by the acid
#               after-dump (`__res_state' 456 -> 448).
#   `follow' -- a bit-field group that FOLLOWS an ordinary member starts
#               at the next available BIT and uses the `tfield'-aligned
#               unit CONTAINING that bit (round DOWN), moving to the next
#               unit only where the field would cross a boundary.  kencc
#               rounds the container UP at group start instead, so
#               `struct{char c; unsigned a:1; char d;}' is `d@2 size 4'
#               on gcc and `d@5 size 8' under `share' alone.
#
# THE REFERENCE IS gcc FOR EVERY SHAPE BELOW, and legitimately rather
# than by habit: gcc, clang and EDG agree on both rules, EDG's whole
# 2.9M-line corpus was written against them, and `-J' exists to put APE
# where everything else already is.
#
# WHAT `follow' IS WORTH, MEASURED RATHER THAN ASSERTED -- and the
# honest version is NOT the one this file carried a round ago.
#
#   * `fenv_t' IS THE REAL ONE AND IT IS libap's, not EDG's.
#     `amd64/include/ape/fenv_arch.h' puts `__opcode:11, __unused4:5'
#     after a `unsigned short __cs_selector', which leaves `w' at 18 --
#     NOT `tfield'-aligned, so this is exactly the `follow' shape.  gcc
#     answers `__data_offset' 20 and `__mxcsr' **28**; under `share'
#     alone kencc answers 24 and **32**.  And 28 is not a number of
#     gcc's choosing: `arch/amd64/fenv.s' is literally `FSTENV (DI)'
#     then `STMXCSR 28(DI)', with `fesetenv' reading `LDMXCSR 27(DI)'
#     after its `INCQ' -- **the assembly hardcodes the x87 FSTENV image
#     layout**, which is what the struct is a transcription of.
#     *Latent rather than live*: nothing in the tree reads a member by
#     name (grep: zero hits outside the header), and 36 >= 32 so the
#     32 bytes the assembly writes still fit.  It bites the first time
#     any C reads `env.__mxcsr' or builds a `fenv_t' by hand.
#
#   * `a_scope' is where cpfe's own numbers move: `variant' 32 -> 40 and
#     `ms_attributes' 256 -> 264, measured on the VM by
#     `sys/lib/tests/edgscope-probe.c' (6 disagreements, with its
#     bit-field-first CONTROL clean).
#
# AND WHAT IT IS **NOT** WORTH -- a claim this file made and now
# withdraws, because the arithmetic refutes it.  `exprutil.h:577' is
# `memcpy((char*)this, (char*)src, offsetof(an_operand, variant))',
# folded into `expr.c:64388' as a literal `152ULL', and `an_operand' has
# the `follow' shape (`kind', `state', then 23 bit fields).  That was
# recorded as a port blocker.  **It is not one: the member after the
# group is `a_name_reference name_reference', whose alignment is 8, so
# `round(w, 8)' is 24 under HEAD, under `share' and under `share+follow'
# alike -- and every member after it, `variant' included, is therefore
# at gcc's offset in all three.**  The case is in the table below so the
# withdrawal is a number rather than a paragraph.
#
# *A struct with the broken shape is not a struct with a broken offset*:
# an 8-aligned member after the group absorbs the whole 1-3 byte
# difference.  I asserted the consequence from the shape without
# computing it, which is the almost-true-claim trap for the second time
# in this function's history.
#
# SO `follow' IS CONFORMANCE WORK WITH ONE NAMED libap VICTIM, not the
# fix for cpfe's `fault read addr=0x10'.  The whole corpus holds exactly
# two folded `offsetof' sites -- `trans_unit.h's pair, which `share'
# already put back to 400/416, and this one, which never moved -- so no
# baked constant depends on `follow' at all, and kencc is self-consistent
# everywhere else: pcc lays the struct out and pcc reads it back.

TFIELD = 4      # tfield->width


def rup(v, w):
    return ((v + w - 1) // w) * w


def layout(members, conformalign, follow=False, packflg=False):
    """Transcribes the TSTRUCT arm of sualign().

    members: (name, width, align, nbits), nbits None for an ordinary one.
    `firstbit'/`lastbit' follow dcl.c's OBIT arm and cc.y's `edecor:
    xdecor' action, which resets both for every ordinary declarator.
    """
    w = 0; bw = 0; a = 1; o = 0; gbit = 0
    lastbit = 0; firstbit = True
    out = []
    for (nm, wid, al, nbits) in members:
        if nbits is not None:
            lastbit += nbits
            if lastbit > TFIELD * 8:        # container overflow
                lastbit = nbits
                firstbit = True
            shift = lastbit - nbits
            if not conformalign:
                if firstbit:
                    w = rup(w, TFIELD)
                    o = w
                    w += TFIELD             # the whole unit, MSVC's rule
                    firstbit = False
                out.append((nm, o))
            elif not follow:
                if firstbit:
                    w = rup(w, TFIELD)
                    o = w
                    if o + TFIELD > bw:
                        bw = o + TFIELD     # the cover guard
                    firstbit = False
                out.append((nm, o))
                nw = o + (shift + nbits + 7) // 8
                if nw > w:
                    w = nw
            else:
                if firstbit:
                    gbit = w * 8 - shift    # the next available bit
                    firstbit = False
                fbit = gbit + shift
                o = (fbit // 8) // TFIELD * TFIELD      # round DOWN
                if fbit + nbits > (o + TFIELD) * 8:     # would cross
                    o = rup((fbit + 7) // 8, TFIELD)
                    gbit += o * 8 - fbit                # carry the group
                    fbit = o * 8
                out.append((nm, o))
                if o + TFIELD > bw:
                    bw = o + TFIELD
                nw = (fbit + nbits + 7) // 8
                if nw > w:
                    w = nw
            ma = 1 if packflg else TFIELD
        else:
            ea = 1 if packflg else al
            w = rup(w, ea)
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
    return dict(out), rup(w, talign)


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

P = (8, 8, None)        # a pointer

# ---- amd64/include/ape/fenv_arch.h, verbatim
FENV = [
    ('__control_word', 2, 2, None), ('__unused1', 2, 2, None),
    ('__status_word', 2, 2, None), ('__unused2', 2, 2, None),
    ('__tags', 2, 2, None), ('__unused3', 2, 2, None),
    ('__eip', 4, 4, None), ('__cs_selector', 2, 2, None),
    ('__opcode', 0, 0, 11), ('__unused4', 0, 0, 5),
    ('__data_offset', 4, 4, None),
    ('__data_selector', 2, 2, None), ('__unused5', 2, 2, None),
    ('__mxcsr', 4, 4, None),
]

# ---- EDG's own two, from the generated C
SCOPE = [('next',) + P, ('prev',) + P, ('parent',) + P,
         ('number', 4, 4, None), ('kind', 1, 1, None)] + \
        [('b%d' % i, 0, 0, 1) for i in range(7)] + [('variant',) + P]

OPERAND = [('type',) + P, ('orig_routine_type',) + P,
           ('kind', 1, 1, None), ('state', 1, 1, None)] + \
          [('b%d' % i, 0, 0, 1) for i in range(23)] + \
          [('name_reference', 48, 8, None)]

# ---- the shapes, with gcc's measured answers
CASES = [
    # name,      members,                                     key, gcc off, gcc size
    ('shares',   [('a', 0, 0, 4), ('b', 0, 0, 4), ('c', 3, 1, None)], 'c', 1, 4),
    ('aligned',  [('a', 0, 0, 11), ('b', 0, 0, 5), ('c', 4, 4, None)], 'c', 4, 8),
    ('trailing', [('p',) + P, ('a', 0, 0, 1), ('b', 0, 0, 1), ('c', 0, 0, 1)],
                                                              None, 0, 16),
    ('split',    [('a', 0, 0, 3), ('b', 0, 0, 3), ('c', 1, 1, None)], 'c', 1, 4),
    ('overflow', [('a', 0, 0, 30), ('b', 0, 0, 30), ('c', 1, 1, None)], 'c', 8, 12),
    # the `follow' shape: a bit field after a small ordinary member
    ('after',    [('c', 1, 1, None), ('a', 0, 0, 1), ('d', 1, 1, None)], 'd', 2, 4),
    ('between',  [('a', 0, 0, 1), ('x', 1, 1, None), ('b', 0, 0, 1), ('y', 1, 1, None)],
                                                              'y', 3, 4),
    # a group that STRADDLES a unit boundary once it starts mid-byte.
    # The key is a trailing ORDINARY member in both, deliberately: a bit
    # field has no address, so `offsetof' cannot be taken of one and gcc
    # has no answer to compare the container offset against.  *The first
    # version of these two asserted my own guess at the container and
    # reported a disagreement that was the model's reference being made
    # up* -- the shapes are measured now (gcc: 6/8 and 6/8).
    ('straddle', [('c', 3, 1, None), ('a', 0, 0, 16), ('d', 1, 1, None)],
                                                              'd', 6, 8),
    ('straddle2', [('c', 1, 1, None), ('a', 0, 0, 16), ('b', 0, 0, 16),
                   ('d', 1, 1, None)],                        'd', 6, 8),
    # the real ones
    ('fenv_t',   FENV,                                   '__mxcsr', 28, 32),
    ('a_scope',  SCOPE,                                  'variant', 32, 40),
    ('an_operand', OPERAND,                       'name_reference', 24, 72),
]


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

    print("%-11s %-19s %-19s %-19s %-19s" %
          ("case", "HEAD (pcc -9)", "share (in tree)", "share+follow", "gcc"))
    fails = 0
    for nm, mem, key, goff, gsize in CASES:
        def f(pair):
            o, s = pair
            return ("size %d" % s) if key is None else \
                   ("off(%s)=%d sz=%d" % (key, o[key], s))
        g = ("size %d" % gsize) if key is None else \
            ("off(%s)=%d sz=%d" % (key, goff, gsize))
        cols = [layout(mem, False), layout(mem, True),
                layout(mem, True, follow=True)]
        mark = ""
        if f(cols[2]) != g:
            mark = "  *** share+follow DISAGREES WITH gcc ***"
            fails += 1
        print("%-11s %-19s %-19s %-19s %-19s%s" %
              (nm, f(cols[0]), f(cols[1]), f(cols[2]), g, mark))

    print("\n__res_state, the one public APE struct the SHARING rule moves:")
    for lbl, kw in (("share", {}), ("share+follow", {'follow': True})):
        o, s = layout(RES_STATE, True, **kw)
        print("   %-12s unused %d  sort_list %d  sizeof %d" %
              (lbl, o['unused'], o['sort_list'], s))
    print("   -> `follow' moves NOTHING here: pfcode is an int, so `w' is")
    print("      already tfield-aligned where the group starts.")

    print("\n%d disagreement(s) with gcc under share+follow" % fails)
    return 1 if fails else 0


if __name__ == '__main__':
    raise SystemExit(main())
