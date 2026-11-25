#!/usr/bin/env python3
"""edgtarg-sweep.py -- does EDG's BAKED target agree with `kencc_targ.h'?

    python3 sys/lib/tests/edgtarg-sweep.py            # sweep, GATES
    python3 sys/lib/tests/edgtarg-sweep.py --control  # plant a disagreement

***THE TARGET DESCRIPTION IS NOT WHAT RUNS.***  `sys/src/external/edg/
kencc_targ.h' is the description a REGENERATION of the corpus would be
given; the corpus in the tree was generated once, with somebody else's
answers, and `src/target.c' carries those as plain assignments.
Nothing reads the header at run time -- `GCC_IS_GENERATED_CODE_TARGET'
appears once in the whole 2.9M-line corpus and not in `target.c' at
all.  So *the file that documents the target and the file that decides
it can disagree indefinitely, and nothing says so.*

**This has cost two rounds in two different places**, which is why it
is a sweep and not a note:

  * `gcc_is_generated_code_target' is baked **1** while the header says
    0, so the C back end appended gcc's system-header flag to its line
    directives -- `# 123 "f.h" 3' -- and `cc -c' answered
    `Syntax error in #line' once per header switch.
  * `use_empty_struct_in_generated_c' was baked **1**, so a captureless
    lambda's closure type came out as `struct X { };' and `6c' answered
    `syntax error, last name: _Z24mainEUliE_'.  EDG's own portable arm
    writes `char __dummy;' -- which is what the corpus's OWN structs
    contain, visible on any line of `c_gen_be.c'.

---- WHAT IT WILL NOT COMPARE, AND WHY THAT MATTERS ------------------

***THE FIRST VERSION OF THIS SWEEP REPORTED TWO ABI DISAGREEMENTS THAT
DO NOT EXIST.***  It said `TARG_ALIGNOF_POINTER' was 8 in the header
and 4 in the baked target, and the same for `TARG_ALIGNOF_LONG_DOUBLE'
-- either of which would mean every struct EDG lays out is wrong.
**Both were the regex taking the FIRST of eight assignments**:
`targ_alignof_pointer' is set once per DATA MODEL, in arms chosen at
run time, and the first in file order belongs to a 32-bit one.

*A rule written from the examples in front of you fires on the next
shape*, and the next shape here was a variable with eight answers.  So
a name assigned more than once anywhere in `target.c' is reported as
NOT COMPARABLE and never counted: it has no single baked value for a
header constant to disagree with.  **That is the half of this file
worth copying** -- the finding it refuses to make is the one that
would have been believed.

---- THE KNOWN LIST --------------------------------------------------

Three disagreements are real, acknowledged and NOT taken this round,
each for a stated reason.  The sweep gates on anything outside that
list, so a new one is a failure and these are not.
"""

import os
import re
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
if not os.path.isfile(os.path.join(ROOT, 'CLAUDE.md')):
    sys.exit('edgtarg-sweep: ROOT=%s is not the repository root -- fix the\n'
             'dirname count.  sys/lib/tests is THREE levels below the root;\n'
             'this guard has fired five times in this tree.' % ROOT)

EDG = os.path.join(ROOT, 'sys', 'src', 'external', 'edg')
HDR = os.path.join(EDG, 'kencc_targ.h')
TARG = os.path.join(EDG, 'src', 'target.c')
ECCP = os.path.join(ROOT, 'rc', 'bin', 'ape', 'eccp')


def active_target():
    """***THE PER-MODEL SETTINGS ARE A FUNCTION, NOT AN ARM.***  The
    first version of this sweep called ten names NOT COMPARABLE because
    each is assigned eight times -- and that was right about the regex
    and wrong about the file.  The eight are
    `set_target_config_win64', `..._linux_i686', `..._linux_aarch64'
    and five more: **one function per target, and exactly one runs.**

    Which one is not a guess either: `rc/bin/ape/eccp' passes
    `--target win64' and says in its own header that the flag is not
    optional.  So the name is READ FROM THE DRIVER rather than written
    here -- a sweep that hardcoded `win64' would go quietly wrong the
    day the driver changed, which is this tree's whole complaint about
    `kencc_targ.h' in the first place.

    **And it is what let `wchar_t' through.**  win64's `wchar_t' is
    `unsigned short'; APE's is `unsigned int'.  cpfe built `L"ape"'
    out of 2-byte elements and libap's `wcslen' walked it 4 bytes at a
    time, so `std::wcslen(L"ape") == 3' was false -- *the one failure
    left in `cxx-library-test'*, and invisible to a sweep that had
    declared the name unreadable."""
    if not os.path.isfile(ECCP):
        return None
    m = re.search(r'--target\s+([a-z0-9_]+)', open(ECCP, errors='replace').read())
    return m.group(1) if m else None

DEFINE = re.compile(r'^#define\s+([A-Z][A-Z0-9_]*)\s+(\d+)\s*(?:/\*|$)', re.M)
# ***AND THE ONE THAT BIT IS NOT A NUMBER.***  `TARG_WCHAR_T_INT_KIND'
# is `((an_integer_kind)ik_unsigned_int)', and win64's config baked
# `ik_unsigned_short'.  A sweep that reads only integers is a sweep
# that could not see the setting that produced the bug it was extended
# for, so kinds are compared by SYMBOL beside them.
KIND = re.compile(r'^#define\s+([A-Z][A-Z0-9_]*)\s+\(\([a-z_]+\)(ik_[a-z_]+)\)', re.M)

# Accepted disagreements.  Each entry is a REASON, not a shrug: a name
# here is one somebody has read and decided about.
KNOWN = {
    'GCC_IS_GENERATED_CODE_TARGET':
        'baked 1.  Clearing it changes attributes, builtin varargs and the\n'
        '    line-directive form all at once, and the one consequence that\n'
        '    bit -- gcc linemarker flags -- is handled in kencc cpp instead\n'
        '    (sys/lib/tests/cpp-linemarker.sh).  Not taken in the same round\n'
        '    as a second change to the same file.',
    'INSTANTIATE_EXTERN_INLINE':
        'baked 0.  Template/inline instantiation policy; eccp already passes\n'
        '    --instantiate local and the link model is measured around that.\n'
        '    Changing it is a link-model change and needs its own round.',
    'INSTANTIATE_INLINE_VARIABLES':
        'baked 0.  Same family as INSTANTIATE_EXTERN_INLINE.',
}


def config_body(text, target):
    """The body of `set_target_config_<target>', plus
    `target_early_init' -- the two places a setting is decided."""
    out = []
    for name in ('set_target_config_%sEv(void)' % target, 'target_early_initEv(void)'):
        i = text.find(name)
        while i >= 0:
            j = text.find('\nstatic void ', i + 1)
            k = text.find('\nvoid ', i + 1)
            end = min(x for x in (j, k, len(text)) if x > 0)
            body = text[i:end]
            if '=' in body:
                out.append(body)
            i = text.find(name, i + 1)
    return '\n'.join(out)


def baked(text):
    """name -> (value, count).  count > 1 is still reported as not
    comparable, but within ONE config body it should not happen."""
    out = {}
    pat = (r'_ZN3edg(\d+)([a-z0-9_]+)E = (?:\(\([^()]*\)([0-9]+)[UL]*\)'
           r'|_ZN3edg\d+(ik_[a-z_]+)E)\s*;')
    for m in re.finditer(pat, text):
        n, name = int(m.group(1)), m.group(2)
        val = m.group(3) if m.group(3) is not None else m.group(4)
        if len(name) != n:
            continue
        v, c = out.get(name, (val, 0))
        out[name] = (v, c + 1)
    return out


# ***THE OTHER DIRECTION, WHICH IS WHERE THE jmp_buf BUG LIVED.***
#
# This sweep walks the HEADER's names and asks target.c about each, so a
# setting the baked target assigns and `kencc_targ.h' never mentions is
# invisible to it -- it cannot DISAGREE, because only one side has an
# opinion.  `targ_jmp_buf_num_elements' was exactly that: baked 39 on
# the win64 arm, absent from the header, and it is why no C++ exception
# could be caught (see kencc_targ.h's TARG_JMP_BUF note).
#
# **99 of the win64 arm's 126 settings are in that bucket**, so this
# REPORTS and does not gate -- a gate on 99 unexamined names is one
# somebody switches off.  Most are right by luck rather than by
# choice, and the luck is real: win64 is the only stock arm that is
# LLP64 like kencc, which is why `eccp' selects it.  *That is also
# exactly why the bucket is dangerous* -- the arm agrees about `long'
# and about pointers, so the ones it gets WRONG are the ones that have
# nothing to do with the data model, which is what a buffer element
# count is.
#
# `--baked' prints the list.  The ones to read first are those naming a
# LAYOUT or a platform TYPE, since those are the ones a disagreement
# makes silently wrong rather than loudly broken: `reuse_tail_padding'
# (this tree moved to `-J'), the `*_field_alignment' family,
# `bit_field_container_size', `minimum_struct_alignment',
# `sizeof_ptr_to_member_function' and the `*_int_kind' typedefs.
# **There is deliberately no "reviewed" COUNT here.**  The first
# version kept one, and it could only ever print 0: reviewing a
# setting means giving it a `kencc_targ.h' entry, which takes it OUT
# of this list.  *A count that can only be zero is not a count* --
# the list shrinking IS the progress measure, and 83 is the number to
# compare against.


def baked_only(hdr_text, targ_text):
    """Settings the baked target assigns that the header never names.

    These cannot be compared and so cannot gate; the point is that
    `absent' in the other direction is a different and harmless thing
    (a header name target.c does not set), while THIS direction is
    where a win64 default silently survives."""
    have = set()
    for name, _ in DEFINE.findall(hdr_text) + KIND.findall(hdr_text):
        have.add(name.lower())
    out = []
    for name in sorted(baked(targ_text)):
        low = name[len('targ_'):] if name.startswith('targ_') else name
        if low not in have and name not in have:
            out.append(low)
    return out


def sweep(hdr_text, targ_text, quiet=False):
    bake = baked(targ_text)
    agree, disagree, absent, ambiguous = [], [], [], []
    for name, want in DEFINE.findall(hdr_text) + KIND.findall(hdr_text):
        low = name.lower()
        if low not in bake:
            absent.append(name)
            continue
        got, count = bake[low]
        if count != 1:
            ambiguous.append((name, count))
        elif got == want:
            agree.append(name)
        else:
            disagree.append((name, want, got))
    if not quiet:
        print('kencc_targ.h numeric settings: %d agree, %d DISAGREE, '
              '%d not comparable, %d not in target.c'
              % (len(agree), len(disagree), len(ambiguous), len(absent)))
        if ambiguous:
            print('\n  not comparable -- set once per data model, so there is '
                  'no single baked value:')
            for name, c in ambiguous:
                print('    %-44s %d assignments' % (name, c))
        if disagree:
            print('\n  DISAGREE:')
            for name, want, got in disagree:
                tag = 'known' if name in KNOWN else '*** NEW ***'
                print('    %-44s header %-4s baked %-4s  %s' % (name, want, got, tag))
                if name in KNOWN:
                    print('      %s' % KNOWN[name])
        only = baked_only(hdr_text, targ_text)
        print('\n  %d settings are baked in the active arm and NOT named in '
              'kencc_targ.h,' % len(only))
        print('  so they cannot disagree and this gate cannot see them.  That '
              'is where')
        print('  targ_jmp_buf_num_elements hid -- giving one a header entry is '
              'what')
        print('  takes it off this list, so the NUMBER falling is the progress.'
              '  `--baked\'.')
    return disagree


def main():
    for f in (HDR, TARG):
        if not os.path.isfile(f):
            sys.exit('edgtarg-sweep: no %s' % f)
    hdr_text, whole = open(HDR).read(), open(TARG, errors='replace').read()
    target = active_target()
    if target is None:
        sys.exit('edgtarg-sweep: cannot read --target from %s, so which of '
                 'the eight target configs runs is unknown' % ECCP)
    body = config_body(whole, target)
    if not body:
        sys.exit('edgtarg-sweep: no set_target_config_%s in target.c -- the '
                 'driver names a target the corpus does not define' % target)
    print('active target, from %s: %s' % (os.path.basename(ECCP), target))
    targ_text = body

    if '--baked' in sys.argv[1:]:
        only = baked_only(hdr_text, targ_text)
        print('\n%d settings baked in the %s arm with no kencc_targ.h entry.\n'
              % (len(only), target))
        for n in only:
            print('  %s' % n)
        print('\nThese cannot disagree, so the gate above cannot see them --\n'
              'which is where targ_jmp_buf_num_elements hid.  Read the ones\n'
              'naming a LAYOUT or a platform TYPE first.')
        return 0

    if '--control' in sys.argv[1:]:
        # ***A DELIBERATE BREAK, BECAUSE THERE IS NO ORACLE.***  Flip one
        # value that currently AGREES and require the sweep to name it.
        # A control that merely proved the sweep runs would pass for a
        # sweep that reports nothing -- which is what the "not comparable"
        # rule above makes a live possibility, since it is allowed to
        # refuse every name.
        base = sweep(hdr_text, targ_text, quiet=True)
        pick = None
        for name, want in DEFINE.findall(hdr_text):
            low = name.lower()
            b = baked(targ_text)
            if low in b and b[low][1] == 1 and b[low][0] == want:
                pick = (name, low, want)
                break
        if pick is None:
            sys.exit('edgtarg-sweep: nothing AGREES, so the control has '
                     'nothing to flip -- the sweep is void')
        name, low, want = pick
        broken = re.sub(r'(_ZN3edg%d%sE = \(\([^()]*\))%s([UL]*\))' % (len(low), low, want),
                        r'\g<1>%d\g<2>' % (int(want) + 7), targ_text, count=1)
        if broken == targ_text:
            sys.exit('edgtarg-sweep: the control patched NOTHING -- the '
                     'assignment spelling has moved and the control is void')
        got = sweep(hdr_text, broken, quiet=True)
        names = [n for n, _, _ in got]
        if name not in names:
            sys.exit('edgtarg-sweep: ***THE CONTROL DID NOT FIRE.***  %s was '
                     'flipped and the sweep reported %r' % (name, names))
        if len(got) != len(base) + 1:
            sys.exit('edgtarg-sweep: the control changed %d findings, want 1 '
                     '-- the break is not isolated' % (len(got) - len(base)))
        print('control: flipping %s is reported, and nothing else moved' % name)
        return 0

    disagree = sweep(hdr_text, targ_text)
    new = [n for n, _, _ in disagree if n not in KNOWN]
    print()
    if new:
        print('*** %d disagreement(s) outside the known list: %s ***'
              % (len(new), ', '.join(new)))
        print('The baked target decides; kencc_targ.h only documents.  Either')
        print('change src/target.c or add the name to KNOWN with a reason.')
        return 1
    print('no disagreement outside the known list')
    return 0


sys.exit(main())
