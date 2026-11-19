#!/usr/bin/env python3
"""apconst-xcheck.py -- does an APE prototype drop a `const' glibc has?

***A HOST CROSS-CHECK, NOT A SWEEP***, and it REPORTS rather than
gates: glibc is the oracle and glibc is not POSIX, so a disagreement
is a question until someone reads it.

---- WHERE IT CAME FROM ---------------------------------------------

unrar's `find.cpp:122' is

    if (lstat(FindMaskA.c_str(), &st) != 0)

and `c_str()' is `const char *'.  `<sys/stat.h>:193' declared

    extern int lstat(char *, struct stat *);

while `stat', `chmod', `mkdir', `unlink' and `access' in the same two
headers all say `const char *'.  **A single prototype out of step with
its five neighbours**, and POSIX says `const' for all six.

***IT IS A C++ ERROR AND NOTHING ELSE***, which is why it survived.  C
converts `const char *' to `char *' with at most a warning, so every C
caller in the tree compiled and ran; C++ refuses outright.  *The port
that first reaches a header is the one that measures it* -- the same
shape as `<wchar.h>' having no `extern "C"' guard, which was also
invisible until a C++ program linked.

---- WHY A BARE GREP CANNOT ASK THIS --------------------------------

`grep' for a `char *' parameter finds 30 in these headers and **nearly
all are correct**: `fgets', `setvbuf', `getpwuid_r', `strerror_r',
`ctime_r', `mktemp', `mkdtemp' and `putenv' all take a NON-const
`char *' in POSIX itself, because the buffer is an OUTPUT or the
string is retained.  A list that cannot tell those from `lstat' is a
list nobody will read twice.

So the question needs an oracle, and `gcc -aux-info' is one: it dumps
every declaration a translation unit saw, with the real types.  **The
comparison is CONST-NESS ONLY, position by position** -- never the
types themselves -- which sidesteps `mode_t' against `__mode_t',
`size_t' spellings and every typedef difference between the two
libraries at once.

---- LIMITS, AND THEY ARE THE REASON IT DOES NOT GATE ----------------

  * glibc is not POSIX.  Where glibc adds a `const' POSIX does not
    require, APExp is free to differ -- so a hit is a QUESTION.
  * Only names declared by BOTH are compared.  A name APExp has and
    glibc has not is invisible here, which is most of `<libv.h>'.
  * Parameter COUNTS that differ make the prototype not comparable
    and it is skipped and counted, never guessed at.
  * It reads the generic header root only.  An arch header that
    redeclares a name is not seen.

**Both directions are reported** and they are different findings:
APE-missing-const is the one that breaks C++ callers; APE-has-const-
glibc-lacks is stricter than the oracle and is almost always fine.

    python3 apconst-xcheck.py              report
    python3 apconst-xcheck.py --control    stage the pre-fix lstat
"""

import os
import re
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
# `sys/lib/tests' is THREE levels below the root.  This guard has fired
# six times in this tree, every time on a miscount exactly like it.
ROOT = os.path.abspath(os.path.join(HERE, "..", "..", ".."))
if not os.path.isfile(os.path.join(ROOT, "CLAUDE.md")):
    sys.exit("apconst-xcheck: ROOT=%s is not the repository root" % ROOT)

APEINC = os.path.join(ROOT, "sys", "include", "ape")

# The headers to ask glibc about.  Each must exist on the host; one
# that does not is skipped and said so, rather than failing the run.
HEADERS = [
    "sys/stat.h", "sys/types.h", "sys/wait.h", "sys/time.h",
    "unistd.h", "stdio.h", "stdlib.h", "string.h", "strings.h",
    "time.h", "fcntl.h", "dirent.h", "pwd.h", "grp.h", "signal.h",
    "locale.h", "wchar.h", "wctype.h", "ctype.h", "utime.h",
    "libgen.h", "glob.h", "netdb.h", "poll.h", "regex.h", "syslog.h",
    "termios.h", "math.h", "stdarg.h", "errno.h", "limits.h",
]

PROTO = re.compile(r"^/\*.*?\*/\s*extern\s+(.+?)\s*\(([^)]*)\)\s*;\s*$")

# ***EXEMPT, WITH THE REASON, AND THERE IS EXACTLY ONE.***  It is kept
# as a named entry rather than silently dropped because it is the
# PROOF that "glibc is not POSIX" is a real limit and not a hedge.
#
# `basename' exists TWICE on the host: POSIX/XPG's in `<libgen.h>' is
# `char *basename(char *)' -- NON-const, because it may modify the
# string in place -- and GNU's in `<string.h>' is
# `const char *basename(const char *)'.  A translation unit that
# includes both gets whichever the macro dance leaves, and
# `gcc -aux-info' reported the GNU one.  **APExp's non-const
# declaration is the POSIX one and is correct**; the oracle is the
# thing that is wrong here.
#
# *Anything added to this list needs its reason written beside it*,
# because an exemption with no reason is indistinguishable from a bug
# someone got tired of.
EXEMPT = {
    "basename": "glibc has two; <libgen.h>'s POSIX one is non-const"
                " and that is the one APExp declares",
}


def strip_noise(s):
    """Remove the qualifiers that say nothing about const-ness."""
    s = s.replace("__restrict", " ").replace("restrict", " ")
    return " ".join(s.split())


def params_of(text):
    """Split a parameter list, or None when it cannot be split safely.

    A nested `(' means a function-pointer parameter, where a naive
    comma split is wrong -- so the whole prototype is refused rather
    than mis-split.  *A parser that guesses produces findings nobody
    can check.*
    """
    text = strip_noise(text)
    if text in ("", "void"):
        return []
    if "(" in text:
        return None
    return [p.strip() for p in text.split(",")]


def constness(params):
    """Per parameter: True when it is a pointer to const."""
    out = []
    for p in params:
        out.append("const" in p.split() and "*" in p)
    return out


def glibc_prototypes():
    tmp = tempfile.mkdtemp(prefix="apconst.")
    try:
        src = os.path.join(tmp, "a.c")
        info = os.path.join(tmp, "a.info")
        avail, missing = [], []
        for h in HEADERS:
            probe = os.path.join(tmp, "p.c")
            with open(probe, "w") as f:
                f.write("#include <%s>\n" % h)
            r = subprocess.run(["gcc", "-fsyntax-only", probe],
                               capture_output=True)
            (avail if r.returncode == 0 else missing).append(h)
        with open(src, "w") as f:
            f.write("#define _GNU_SOURCE 1\n")
            for h in avail:
                f.write("#include <%s>\n" % h)
            f.write("int main(void){return 0;}\n")
        r = subprocess.run(["gcc", "-aux-info", info, "-c", "-o",
                            os.path.join(tmp, "a.o"), src],
                           capture_output=True)
        if not os.path.exists(info):
            sys.exit("apconst-xcheck: gcc -aux-info produced nothing:\n"
                     + r.stderr.decode()[:400])
        protos = {}
        for line in open(info):
            m = PROTO.match(line.strip())
            if not m:
                continue
            head, args = m.group(1), m.group(2)
            nm = head.split("*")[-1].strip().split()[-1] if head else ""
            nm = nm.strip("*")
            if not re.match(r"^[A-Za-z_][A-Za-z_0-9]*$", nm):
                continue
            ps = params_of(args)
            if ps is None:
                continue
            # A name declared twice (glibc redirects) keeps the first.
            protos.setdefault(nm, ps)
        return protos, missing
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


APEPROTO = re.compile(
    r"^\s*extern\s+(.+?)\s*\(([^)]*)\)\s*;", re.M)


def ape_prototypes():
    protos = {}
    for dirpath, _, names in os.walk(APEINC):
        if os.path.join("ape", "c++") in dirpath:
            continue
        for n in names:
            if not n.endswith(".h"):
                continue
            path = os.path.join(dirpath, n)
            try:
                text = open(path, errors="replace").read()
            except OSError:
                continue
            # Blank comments and literals first: `truefalse-sweep''s
            # lesson, which this tree has now paid for three times --
            # an instrument that reports its own explanatory prose.
            text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
            text = re.sub(r"//[^\n]*", " ", text)
            for m in APEPROTO.finditer(text):
                head, args = m.group(1), m.group(2)
                if "*" in head:
                    nm = head.split("*")[-1].strip()
                else:
                    nm = head.split()[-1] if head.split() else ""
                nm = nm.strip("*").strip()
                if not re.match(r"^[A-Za-z_][A-Za-z_0-9]*$", nm):
                    continue
                ps = params_of(args)
                if ps is None:
                    continue
                rel = os.path.relpath(path, APEINC)
                protos.setdefault(nm, (ps, rel))
    return protos


def main():
    control = "--control" in sys.argv
    glibc, missing = glibc_prototypes()
    ape = ape_prototypes()
    if missing:
        print("note: host lacks %d of the asked headers: %s"
              % (len(missing), " ".join(missing)))
    print("glibc prototypes: %d   APE prototypes: %d" % (len(glibc), len(ape)))

    lost, extra, ncmp, exempt = [], [], 0, []
    for nm, (aps, where) in sorted(ape.items()):
        gps = glibc.get(nm)
        if gps is None:
            continue
        if nm in EXEMPT:
            exempt.append(nm)
            continue
        if len(gps) != len(aps):
            ncmp += 1
            continue
        gc, ac = constness(gps), constness(aps)
        for i, (g, a) in enumerate(zip(gc, ac)):
            if g and not a:
                lost.append((nm, i + 1, where))
            elif a and not g:
                extra.append((nm, i + 1, where))

    print()
    print("APE DROPS a const glibc has (breaks C++ callers): %d" % len(lost))
    for nm, i, where in lost:
        print("    %-24s param %d   %s" % (nm, i, where))
    print()
    print("APE ADDS a const glibc lacks (stricter; usually fine): %d"
          % len(extra))
    for nm, i, where in extra:
        print("    %-24s param %d   %s" % (nm, i, where))
    print()
    print("not comparable (parameter counts differ): %d" % ncmp)
    for nm in exempt:
        print("exempt: %-12s %s" % (nm, EXEMPT[nm]))

    if control:
        # ***THE CONTROL IS EXTERNAL AND HAS TO BE***, like
        # `truefalse-sweep''s: the one finding this was built on is
        # fixed, so the current tree cannot show it.  Re-reading the
        # header with the pre-fix spelling restored is the cheapest
        # form -- no git, no staging, and it cannot leave the tree
        # modified, which a `git show' into the real path can.
        print()
        print("control: re-reading <sys/stat.h> with lstat's pre-fix"
              " spelling")
        path = os.path.join(APEINC, "sys", "stat.h")
        text = open(path, errors="replace").read()
        if "int\tlstat(const char *" not in text and \
           "int lstat(const char *" not in text:
            sys.exit("control: lstat is not declared const -- the"
                     " control cannot distinguish anything")
        ps = params_of("char *, struct stat *")
        gps = glibc.get("lstat")
        if gps is None:
            sys.exit("control: glibc did not declare lstat")
        gc, ac = constness(gps), constness(ps)
        if gc[0] and not ac[0]:
            print("control: FIRES -- pre-fix lstat is reported")
            return 0
        sys.exit("control: did NOT fire; the comparison is not asking"
                 " what it claims")
    return 0


if __name__ == "__main__":
    sys.exit(main())
