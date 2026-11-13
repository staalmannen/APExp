#!/usr/bin/env python3
"""baketype-sweep.py -- a vendored package declaring APExp's own typedefs.

    python3 sys/lib/tests/baketype-sweep.py            # the dangerous class
    python3 sys/lib/tests/baketype-sweep.py --all      # guarded ones too
    python3 sys/lib/tests/baketype-sweep.py --control  # MUST fire

***IT DOES NOT GATE.*** Most hits sit inside an `#if !HAVE_X' arm that
this platform never takes -- gnulib alone accounts for dozens -- and
nothing here evaluates `#if' arithmetic, so only a build settles which
arm is live. A gate would demand changes to code nobody compiles.

WHAT IT ASKS, AND THE BUG IT COMES FROM
=======================================

A package that declares `typedef unsigned short dev_t;` itself has
taken a COPY of the platform ABI. **Changing APExp's header cannot
reach that copy**, and nothing in the build says so: both sides
compile, and the disagreement shows up as a wrong number or a smashed
stack at run time.

That is not hypothetical. EDG's `cpfe` crashed on every input, with
`fault read addr=0x1 pc=0x1` -- a jump to address 1, which is a
SMASHED RETURN ADDRESS. `cmd/edg/mkfile` passes **NO -I and NO -D** on
purpose ("each file declares everything it uses"), so the 2.9M-line
generated corpus carries its own

    typedef unsigned short ino_t;
    typedef unsigned short dev_t;

and its own `struct stat` built from them. **APExp widened both to
`unsigned long long` this release** (64-bit qids; `struct stat`
88 -> 104). `get_file_modification_time' then put an 88-byte
`struct stat' on the stack and libap's `stat()' wrote 104 bytes into
it -- sixteen past the end, over the return address.

**Measured three ways with the host-built `6c`, not computed**:
EDG's struct with the old typedefs is **88**, with the new ones
**104**, and APExp's real `<sys/stat.h>` is **104**.

And it fits everything `cpfe-ladder` had already bracketed: a
NONEXISTENT file is diagnosed cleanly (the `stat' FAILS, so nothing
is written and nothing is smashed) while any real file crashes,
content-independent, with no output, on both the `-E' and the full
path. *The ladder had the fault between a successful open and the
first emitted token, and this is what lives there.*

THE DISCRIMINATOR IS WHETHER THE TYPEDEF IS GUARDED
===================================================

gnulib, coreutils, diffutils and friends declare these names too, but
inside `#if !HAVE_<T>' arms that a platform with the type never takes.
EDG's are **unconditional**, which is what made them live. So:

  UNGUARDED  no enclosing `#if' at all -- the dangerous class
  guarded    inside some condition; reported only with `--all',
             because this script cannot tell a taken arm from an
             untaken one

LIMITS, stated rather than discovered later
===========================================

  * **It reads `#if' TEXT, not `#if' arithmetic.** Guarded is not the
    same as unreachable.
  * **It compares against EVERY APExp declaration of the name, and
    APExp has arch arms.** `_ptrdiff_t' is `long' in `stddef.h' and
    `long long' in `amd64/include/ape/stddef_arch.h'; a corpus saying
    `long long' agrees with amd64 and would read as divergent against
    the generic arm alone. Both roots are searched for that reason,
    and a corpus type matching ANY APExp arm is not reported. *That
    was a real false positive on this script's first run.*
  * **Spelling is normalised but not canonicalised**: `unsigned' and
    `unsigned int' are the same type and are folded; an alias chain
    (`off64_t = off_t') is not resolved and will read as divergent.
  * It sees `typedef <base> <name>;` only -- not a struct, not a
    `#define`.

THE CONTROL IS EXTERNAL AND HAS TO BE, the one real finding being
fixed: `--control` stages EDG's PRE-FIX `host_envir.c` out of git and
requires it to come back UNGUARDED and divergent, *and* requires the
current file not to. **One half alone would pass for a script that
reports everything** -- the `rceq-sweep` lesson.

***AND IT CANNOT STAGE `HEAD`***, which is what the first draft did
and what would have rotted the moment the fix was committed: after
that commit `HEAD` carries the FIXED file and half one fails, which
reads exactly like a broken sweep. It SEARCHES HISTORY instead, for
the newest revision of that path whose blob still declares the short
form -- so the control keeps working however far the fix recedes, and
says outright when no such revision exists rather than passing.
"""

import collections
import pathlib
import re
import subprocess
import sys

TD = re.compile(r'^[ \t]*typedef\s+([A-Za-z_][\w \t*]*?)\s+(\w+)\s*;', re.M)
COND = re.compile(r'^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$')


def norm(s):
    s = ' '.join(s.replace('*', ' * ').split())
    # `unsigned' alone IS `unsigned int'; same for the signed spellings.
    for a, b in (('unsigned int', 'unsigned'), ('signed int', 'int'),
                 ('long int', 'long'), ('short int', 'short')):
        if s == a:
            s = b
    return s


def condstack(text):
    """line number -> depth of enclosing #if nesting."""
    out, depth = {}, 0
    for n, line in enumerate(text.split('\n'), 1):
        m = COND.match(line)
        out[n] = depth
        if m:
            k = m.group(1)
            if k in ('if', 'ifdef', 'ifndef'):
                depth += 1
            elif k == 'endif' and depth:
                depth -= 1
    return out


def ape_types(root):
    """name -> set of normalised base types, over BOTH header roots."""
    d = collections.defaultdict(set)
    for sub in ('sys/include/ape', 'amd64/include/ape'):
        base = root / sub
        if not base.is_dir():
            continue
        for p in base.rglob('*.h'):
            try:
                t = p.read_text(errors='ignore')
            except OSError:
                continue
            for m in TD.finditer(t):
                d[m.group(2)].add(norm(m.group(1)))
    return d


def platform_names(root):
    """The names whose width IS the ABI: what APExp declares in sys/."""
    names = set()
    base = root / 'sys/include/ape/sys'
    for p in base.rglob('*.h'):
        try:
            t = p.read_text(errors='ignore')
        except OSError:
            continue
        for m in TD.finditer(t):
            names.add(m.group(2))
    return names


def scan_text(text, plat, ape):
    """yield (line, name, base, guarded) for divergent declarations."""
    depth = condstack(text)
    for m in TD.finditer(text):
        base, name = norm(m.group(1)), m.group(2)
        if name not in plat or name not in ape:
            continue
        if base in ape[name]:
            continue
        line = text[:m.start()].count('\n') + 1
        yield line, name, base, depth.get(line, 0) > 0


def stage_prefix(root, rel, want='typedef unsigned short ino_t;'):
    """Newest revision of `rel' whose blob still carries `want'.

    NOT `HEAD': the moment the fix is committed `HEAD' is the fixed
    file and the control's first half fails for the wrong reason.
    Walking back costs one `rev-list' and a `show' per revision, and
    the fix is the newest change to this path, so it stops at once.
    """
    try:
        revs = subprocess.run(
            ['git', '-C', str(root), 'rev-list', '-n', '40', 'HEAD', '--', rel],
            capture_output=True, text=True, check=True).stdout.split()
    except Exception:
        return None, None
    for rev in revs:
        try:
            t = subprocess.run(
                ['git', '-C', str(root), 'show', '%s:%s' % (rev, rel)],
                capture_output=True, text=True, check=True).stdout
        except Exception:
            continue
        if want in t:
            return t, rev
    return None, None


def main():
    here = pathlib.Path(__file__).resolve().parent
    # `sys/lib/tests' is THREE levels below the root.  Writing two is
    # the trap this directory has now sprung SEVEN times, every one
    # caught by the guard and never by a reading.  *The guard is the
    # instrument that works.*
    root = here.parent.parent.parent
    if not (root / 'CLAUDE.md').is_file():
        sys.exit('baketype-sweep: ROOT=%s is not the repository root' % root)
    ext = root / 'sys/src/external'
    if not ext.is_dir():
        sys.exit('baketype-sweep: no %s' % ext)

    mode = sys.argv[1] if len(sys.argv) > 1 else ''
    if mode not in ('', '--all', '--control'):
        sys.exit('usage: baketype-sweep.py [--all|--control]')

    plat = platform_names(root)
    ape = ape_types(root)

    if mode == '--control':
        rel = 'sys/src/external/edg/src/host_envir.c'
        old, rev = stage_prefix(root, rel)
        if old is None:
            print('baketype-sweep: CONTROL FAILED -- no revision of %s' % rel)
            print('baketype-sweep: declares the short form; cannot stage it.')
            return 1
        print('baketype-sweep: control staged %s from %s' % (rel, rev[:12]))
        got = [(n, b) for _, n, b, g in scan_text(old, plat, ape) if not g]
        if not any(n in ('ino_t', 'dev_t') for n, _ in got):
            print('baketype-sweep: CONTROL FAILED -- the pre-fix EDG header')
            print('baketype-sweep: did not come back UNGUARDED+divergent: %r' % got)
            return 1
        print('baketype-sweep: control 1/2 OK -- pre-fix EDG fires (%d unguarded)'
              % len(got))
        cur = (root / rel).read_text(errors='ignore')
        bad = [(n, b) for _, n, b, g in scan_text(cur, plat, ape)
               if not g and n in ('ino_t', 'dev_t')]
        if bad:
            print('baketype-sweep: CONTROL FAILED -- the CURRENT file still')
            print('baketype-sweep: diverges on %r; the fix is not in.' % bad)
            return 1
        print('baketype-sweep: control 2/2 OK -- the current file does not')
        return 0

    rows = []
    for p in sorted(ext.rglob('*')):
        if p.suffix not in ('.c', '.h') or not p.is_file():
            continue
        try:
            t = p.read_text(errors='ignore')
        except OSError:
            continue
        for line, name, base, guarded in scan_text(t, plat, ape):
            rows.append((str(p.relative_to(ext)), line, name, base, guarded))

    unguarded = [r for r in rows if not r[4]]
    for rel, line, name, base, guarded in rows:
        if guarded and mode != '--all':
            continue
        tag = 'guarded   ' if guarded else 'UNGUARDED '
        print('  %s %s:%d' % (tag, rel, line))
        print('             %s = %s   (APExp: %s)'
              % (name, base, ' / '.join(sorted(ape[name]))))
    print()
    print('baketype-sweep: %d declarations of an APExp sys/ typedef disagree'
          % len(rows))
    print('baketype-sweep: %d of them UNGUARDED -- READ THESE; this does not gate'
          % len(unguarded))
    return 0


if __name__ == '__main__':
    sys.exit(main())
