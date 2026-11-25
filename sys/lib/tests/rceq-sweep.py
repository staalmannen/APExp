#!/usr/bin/env python3
#
# rceq-sweep -- which mkfile RECIPE lines hand rc a bare `=' that is not a
# leading assignment, and so cannot parse?
#
#   python3 sys/lib/tests/rceq-sweep.py
#
# IT GATES.  Unlike `ishadow-sweep', every hit here is a real break: mk
# hands a recipe to `rc', `=' is a SYNTAX CHARACTER there, and rc's grammar
# accepts it in exactly one position -- a leading per-command assignment.
# Anywhere else it is `token '=': syntax error' and the command never runs.
#
# **THE MACHINE SETTLED THIS, after this tree had carried it as unmeasured
# for a round.**  `clisp/mkfile.rebuild's `if (test $name = lispbibl)'
# answered `/rc/lib/rcmain:24 *eval*:4: token '=': syntax error' on the VM,
# and `*eval*:4' is that line to the digit.  Before that run the question
# was open, because **there is no rc on the build host** -- which is why
# this is a sweep over text rather than a parse.
#
# AND THE MESSAGE NAMES THE WRONG LINE, which is why one hit costs a round
# if it is not swept for.  mk reported the failure as
# `mk: mkdir -p build-amd64 ...: exit status=rc: syntax error' -- mk names
# a recipe by its FIRST line, and the fault was five lines down in a file
# the message never mentions.  *The message names the victim*, the third
# time in this tree after the `lock.h' shadow and `cmd/mkfile:96'.
#
# WHY EVERY `-DFOO=1' IN THIS TREE IS NONETHELESS FINE, and why the sweep
# must not report them: those arrive through `$CFLAGS', and mk exports its
# variables into rc's ENVIRONMENT, so rc expands them *after* it has
# parsed -- the `=' never reaches the parser as text.  Only a literal one
# typed into a recipe does.  The sweep therefore reads the mkfile's own
# text and ignores what any variable might hold.
#
# THE DISCRIMINATOR IS THE WHOLE INSTRUMENT, as `mkcont-sweep's is.  A
# LEADING assignment is legal and common -- `i=_$i', `ARCHDEF=-D__i386__',
# and notably `if (~ $i seek) j=_seek' in `libc/9syscall/mkfile', which is
# a WORKING PRECEDENT for an assignment after an `if' head.  A naive grep
# for `=' reports 16 lines of which 11 are those.  So a command separator
# is recognised first (`;', `&', `|', `{', `(', `)', `&&', `||', and the
# start of the line), and only an `=' that follows something else is a
# finding.
#
# Single-quoted text is stripped first, since rc quoting is exactly how the
# fix is written: `'objtype='^$objtype' rather than `objtype=$objtype'.
#
# LIMITS, so the next reader does not over-read a clean run.  This does not
# parse rc; it is a lexical approximation of one rule.  It cannot see a `='
# that arrives through a variable this mkfile itself sets to a literal, and
# it NOW ALSO CHECKS rc SCRIPTS, which it did not for two rounds -- this
# sentence used to read "it does not check `rc/bin/*' scripts -- only
# mkfile recipes, which are where mk's own invocation of rc happens".
# ***THAT DOCUMENTED LIMIT COST TWO ROUNDS***: `fdwatch' first, and then
# `sys/lib/tests/archive-roundtrip', where `xz -T0 --block-size=65536'
# answered `token '=': syntax error' AFTER section 1 had run -- in a file
# whose own header quotes this very rule.  *A limit named in a comment is
# still a limit.*  A file is taken for rc by its SHEBANG and nothing else:
# a directory name cannot say it (`sys/lib/tests' holds rc, python, C, tcl
# and bash side by side) and nor can an extension, since this tree's rc
# scripts mostly have none (`apexp-sh', `go-ladder', `archive-roundtrip').
# `sys/src/external' is skipped -- vendored rc is not this tree's to fix.

import os
import re
import sys

# THREE levels: this file is sys/lib/tests/<name>.  `ishadow-sweep' said
# two, reported 0 of everything and looked healthy -- and the guard below
# fired on the first run of THIS file for the same miss, which is the only
# reason it is right now.
ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                    '..', '..', '..')
ROOT = os.path.normpath(ROOT)
TREE = os.path.join(ROOT, 'sys', 'src')
EXTERNAL = os.path.join(ROOT, 'sys', 'src', 'external')

# ***THIS USED TO BE `^[^=#]*:[A-Z]*:' AND SO REQUIRED TWO COLONS.***
# That matches an ATTRIBUTE rule -- `install:V:', `test:QV:' -- and
# nothing else, so an ordinary `target: prereq' header was not a rule
# and its recipe lines were never read.  **A gating sweep reporting 0
# over recipes it cannot see** is the one failure mode its own header
# already warns about, two paragraphs down, about backquotes.
#
# It was found by control rather than by reading: a bare `=' planted
# in `cmd/php/mkfile's `clean:V:' was reported, and the same `=' in
# one of that file's `ext/...$O: $PHPSRC/....c' rules was not.
# *Planting the break in only one place would have passed.*
#
# A rule header is now any non-indented, non-comment line with a colon
# that is not an assignment -- `[^=#\t]*' stops at the `=', so
# `CFLAGS=-I/a:/b' cannot match, and a `#' at column 0 cannot either.
RULE = re.compile(r'^[^=#\t]*:')
ASSIGN = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*\s*=')
# an `=' is legal only at the start of a command; these end one
# `*' is a legal variable name (`rc/bin/ape/install:34's `*=($1 $2)',
# which these notes already call the working precedent for the () form),
# and a `!' can sit between the opener and the assignment, as in
# `rc/bin/ape/ar89:6's `if(! ifs=() eval ...)'.  Both read as findings
# without this, and both are correct rc.
LEADING = re.compile(
    r"(^|[;&|{}()]|\|\||&&)\s*!?\s*[A-Za-z_*][A-Za-z0-9_]*\s*=")


BACKQ = re.compile(r'`\{([^}]*)\}')


def backquote_rc(line):
    """The rc source inside a mk backquote, if any.

    ***A RECIPE IS NOT THE ONLY PLACE mk HANDS TEXT TO rc.***  A
    top-level assignment whose value is `` `{...} `` is rc source too,
    evaluated when mk parses the file -- and this sweep read only
    tab-indented recipe lines until `lib/onig/mkfile' proved that was
    not enough:

        ONIG64=`{if(~ $objtype amd64 arm64 power64) echo -DSIZEOF_VOIDP=8}

    `echo' is handed a bare `=' as an ARGUMENT, rc answered
    `/rc/lib/rcmain:24 *eval*:1: token '=': syntax error' twice, and
    **this sweep reported 0**.  `lib/chicken/mkfile''s identical-looking
    line is safe only because `-DC_SIXTY_FOUR -DC_LLP' contains no `='.
    *The sweep was clean and the tree was broken*, which is the one
    failure mode a gating sweep must not have.
    """
    m = BACKQ.search(line)
    return m.group(1) if m else None


def recipe_lines(path):
    """Yield (lineno, text) for every line rc will be handed.

    A recipe is the tab-indented block after a rule header.  Continuation
    lines of an ASSIGNMENT are also tab-indented and are not recipes --
    that distinction is what kept `mkcont-sweep' honest and it is needed
    here for the same 83-hits-of-noise reason.

    PLUS the rc inside any `` `{...} `` backquote, wherever it appears:
    see `backquote_rc' above for the line that made that necessary.
    """
    try:
        text = open(path, encoding='utf-8', errors='replace').read()
    except OSError:
        return
    inrecipe = False
    cont = False
    for i, line in enumerate(text.split('\n'), 1):
        if not line.strip():
            inrecipe = cont = False
            continue
        if line.startswith('\t'):
            if inrecipe and not cont:
                yield i, line
            cont = cont and line.rstrip().endswith('\\')
            continue
        cont = bool(ASSIGN.match(line)) and line.rstrip().endswith('\\')
        inrecipe = (not cont) and bool(RULE.search(line))


def bare_eq(line):
    s = re.sub(r"'[^']*'", "''", line)    # rc single quotes
    s = re.sub(r'#.*$', '', s)            # rc comments; stripped AFTER the
                                          # quotes, or a quoted `#' eats the
                                          # rest of a real command.  The
                                          # first version of this file
                                          # skipped this and reported its
                                          # OWN comments as findings.
    s = LEADING.sub(r'\1 ', s)            # leading assignments are legal
    return '=' in s


CONTROL = """\
OFILES=\\
\ta.$O\\
\tb.$O

install:V: $O.out
\techo attr=rule

%.$O: $SRC/%.c
\techo plain=rule

X=`{echo -DSIZE=8}

ok:V:
\techo '-Dquoted=fine'
\tFOO=bar echo leading is legal
"""


# ***rc's OWN REDIRECTION SYNTAX CONTAINS AN `='.***  `>[1=2]', `>[2=1]'
# and `<[0=1]' are dup-and-redirect.  They are the commonest `=' in this
# tree's scripts by a wide margin -- 30-odd lines of the first script
# sweep -- and they are neither an assignment nor an argument.
REDIR = re.compile(r'\[\s*\d+\s*=\s*\d+\s*\]')

SHEBANG = re.compile(r'^#!\s*\S*/rc\b')


def rc_blank(src):
    """
    Blank rc comments and QUOTED TEXT, keeping the line structure.

    ***A SINGLE QUOTE IN rc SPANS LINES, AND THAT IS WHY THIS EXISTS.***
    `bare_eq' strips `'...'` pairs within ONE line, which is all a mkfile
    recipe line ever needed; a SCRIPT hands multi-line programs to other
    languages inside one quoted word -- `cxx-vecacid' does it with acid,
    `bash-runtests' and `fdwatch' with awk -- and every line after the
    opening quote then reads as rc source.  The first script sweep
    reported 102 lines of which about a hundred were awk's
    `for(i = 1; i <= n; i++)' and acid's `print(..., i\D, ...)'.
    *A sweep that cries wolf a hundred times gets switched off*, which is
    this file's own recorded failure.

    ***AND THE COMMENT MUST BE HANDLED IN THIS LOOP, NOT AFTER IT.***
    The first version blanked quotes and then stripped `#' comments in a
    second pass, which is backwards: rc's lexer drops a comment BEFORE
    any quote can begin, so an apostrophe in prose opens nothing.
    `fdwatch' line 2 is `# fdwatch -- sample a process's open
    descriptors', and that one apostrophe desynchronised the machine for
    the whole file, so every awk line below it read as rc.  *Each pass
    was right and their ORDER was the bug*, which no amount of staring
    at either one on its own would show.

    rc has no double quotes and no backslash escape; `''` inside a
    quoted string is a literal quote, which the state machine gets free.
    """
    out = []
    inq = False
    incomment = False
    for ch in src:
        if ch == '\n':
            out.append(ch)
            incomment = False
            continue
        if incomment:
            out.append(' ')
            continue
        if inq:
            out.append(' ' if ch != "'" else ch)
            if ch == "'":
                inq = False
            continue
        if ch == "'":
            inq = True
            out.append(ch)
            continue
        if ch == '#':
            incomment = True
            out.append(' ')
            continue
        out.append(ch)
    return ''.join(out)


def rc_script_lines(path):
    """
    Every line of an rc SCRIPT, if the file is one, blanked and with
    rc's redirection brackets removed.

    **There is no recipe/not-recipe question here**: in a mkfile only the
    tab-indented body is rc source, which is why `recipe_lines' exists,
    while in a script every line is.  See the header for the shebang.
    """
    try:
        src = open(path, encoding='utf-8', errors='replace').read()
    except OSError:
        return
    if not src or not SHEBANG.match(src.split('\n', 1)[0]):
        return
    for lineno, line in enumerate(rc_blank(src).split('\n'), 1):
        yield lineno, REDIR.sub(' ', line)


SCRIPT_CONTROL = """\
#!/bin/rc
# a comment holding key=value and an apostrophe in a process's name,
# neither of which rc sees -- the second desynchronised the quote
# machine for a whole file and must NOT be reported.
name = archive
echo 'quoted=fine'
FOO=bar echo leading is legal
if(~ $1 x) j=_seek
echo 'oops' >[1=2]
*=($1 $2)
if(! ifs=() eval `{aux/getflags $*}) exit usage
awk '
\tBEGIN { for(i = 0; i <= 9; i++) n = i }
\t/^x/  { k[j++] = $0 }
'
xz -T0 --block-size=65536 -c
awk -v name=$name
"""


def control():
    """***THREE SHAPES, BECAUSE PLANTING THE BREAK IN ONE PLACE PASSED.***

    This sweep GATES, and for a long time it read recipes only under an
    ATTRIBUTE rule -- `install:V:' -- because `RULE' wanted two colons.
    A bare `=' planted in `cmd/php/mkfile's `clean:V:' was duly
    reported, which looked like proof the sweep worked, and the same
    `=' in one of that file's `target: prereq' rules was not.  989
    recipe lines across the tree were invisible.

    So the control covers an attribute rule, a PLAIN rule, and a
    backquoted assignment -- the three ways mk hands text to rc -- and
    two things that must NOT be reported: a quoted `=' and a LEADING
    assignment, which rc allows.
    """
    import tempfile
    want = {6: 'attribute rule', 9: 'plain rule', 11: 'backquote'}
    ok = True
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, 'mkfile')
        open(p, 'w').write(CONTROL)
        got = set()
        for lineno, line in recipe_lines(p):
            if bare_eq(line):
                got.add(lineno)
        for lineno, line in enumerate(CONTROL.split('\n'), 1):
            rc = backquote_rc(line)
            if rc is not None and bare_eq(rc):
                got.add(lineno)
        for ln, what in sorted(want.items()):
            hit = ln in got
            print('control: %-18s line %2d -- %s'
                  % (what, ln, 'ok' if hit else 'FAILED, not reported'))
            if not hit:
                ok = False
        extra = got - set(want)
        for ln in sorted(extra):
            print('control: line %d reported and must NOT be '
                  '(quoted or leading `=\') -- FAILED' % ln)
            ok = False
        if not extra:
            print('control: quoted and leading `=\' correctly ignored -- ok')

        # ***THE SCRIPT ARM IS A SEPARATE CONTROL AND HAS TO BE.***  The
        # mkfile arm above passes for a sweep that reads no scripts at
        # all, which is the state this file was in for two rounds --
        # *a control that cannot distinguish the bug it is named for is
        # not a control.*  Lines 15 and 16 are the two real shapes: an
        # option spelled `--name=value' (archive-roundtrip) and
        # `awk -v name=$value' (fdwatch).  Everything above them is a
        # legal form that must NOT fire, and each one of those was a
        # false positive in a real run of this sweep.
        sp = os.path.join(d, 'ctl-script')
        open(sp, 'w').write(SCRIPT_CONTROL)
        # ***DERIVED FROM THE CONTROL TEXT, NOT TRANSCRIBED.***  Two
        # edits to the comment above it moved these numbers twice and
        # the control reported its own staleness as a failure both
        # times.  A results table keyed on a LINE rots when the file is
        # edited above it -- this tree's own rule, from the kencc hunt.
        swant = {}
        for ln, txt in enumerate(SCRIPT_CONTROL.split('\n'), 1):
            if '--block-size' in txt:
                swant[ln] = '--opt=value'
            elif txt.startswith('awk -v'):
                swant[ln] = 'awk -v name=$x'
        assert len(swant) == 2, 'control lost one of its two real shapes'
        sgot = set()
        for lineno, line in rc_script_lines(sp):
            if bare_eq(line):
                sgot.add(lineno)
        for ln, what in sorted(swant.items()):
            hit = ln in sgot
            print('control: script %-16s line %2d -- %s'
                  % (what, ln, 'ok' if hit else 'FAILED, not reported'))
            if not hit:
                ok = False
        sextra = sgot - set(swant)
        for ln in sorted(sextra):
            print('control: script line %d reported and must NOT be '
                  '-- FAILED' % ln)
            ok = False
        if not sextra:
            print('control: script comment/apostrophe/quoted/leading/'
                  'redirect/multi-line awk correctly ignored -- ok')

        # A file that is NOT rc must yield nothing, or the sweep reports
        # every Makefile and shell script in the tree.
        np = os.path.join(d, 'not-rc')
        open(np, 'w').write('#!/bin/sh\nxz --block-size=65536\n')
        if list(rc_script_lines(np)):
            print('control: a non-rc shebang was scanned -- FAILED')
            ok = False
        else:
            print('control: non-rc shebang correctly skipped -- ok')
    return 0 if ok else 1


def main():
    if '--control' in sys.argv:
        return control()
    if not os.path.isdir(os.path.join(ROOT, 'sys', 'include', 'ape')):
        print('rceq-sweep: %s is not an APExp root -- refusing to report' % ROOT)
        print('(a sweep rooted in the wrong tree reports an empty one as a')
        print(' clean one; ishadow-sweep paid a round for exactly that)')
        return 2

    nlines = 0
    hits = []
    for dirpath, _, names in os.walk(TREE):
        for name in names:
            if name != 'mkfile' and not name.startswith('mkfile.'):
                continue
            path = os.path.join(dirpath, name)
            rel = os.path.relpath(path, ROOT)
            for lineno, line in recipe_lines(path):
                nlines += 1
                if bare_eq(line):
                    hits.append((rel, lineno, line.strip()))
            # and every backquote, recipe or not
            try:
                src = open(path, encoding='utf-8',
                           errors='replace').read()
            except OSError:
                continue
            for lineno, line in enumerate(src.split('\n'), 1):
                rc = backquote_rc(line)
                if rc is None:
                    continue
                nlines += 1
                if bare_eq(rc):
                    hits.append((rel, lineno, line.strip()))

    # rc SCRIPTS, over the whole repository and not just `sys/src':
    # `apexp-sh' and `mount-include' are at the root, the harnesses in
    # `sys/lib/tests', the drivers in `rc/bin'.
    nscripts = 0
    for dirpath, dirs, names in os.walk(ROOT):
        dirs[:] = [x for x in dirs if x != '.git'
                   and os.path.join(dirpath, x) != EXTERNAL]
        for name in names:
            path = os.path.join(dirpath, name)
            if os.path.islink(path):
                continue
            lines = list(rc_script_lines(path))
            if not lines:
                continue
            nscripts += 1
            rel = os.path.relpath(path, ROOT)
            for lineno, line in lines:
                nlines += 1
                if bare_eq(line):
                    hits.append((rel, lineno, line.strip()))

    for rel, lineno, line in hits:
        print('%s:%d: %s' % (rel, lineno, line))
    print('---- %d lines (mkfile recipes + %d rc scripts), '
          '%d with a bare `=\' rc cannot parse'
          % (nlines, nscripts, len(hits)))
    if hits:
        print("fix: write `'name='^$value', or build the word by")
        print("concatenation.  Do NOT leave it: the recipe cannot run at all,")
        print("and if it sits in an untriggered rule nothing will say so.")
    return 1 if hits else 0


if __name__ == '__main__':
    sys.exit(main())
