#!/usr/bin/env python3
# apdecl-sweep -- a HOST sweep, not a test and not a Plan 9 program.
#
#       python3 apdecl-sweep.py        (from sys/lib/tests, or anywhere)
#
# It asks ONE question of every .c under sys/src/ape/lib/ap: does this
# file call a function whose declared return type is NOT `int', without
# any header in its include closure declaring it? Under kencc such a
# call is an implicit `int' return, so a `char *', a `double', a
# `size_t' or a `long long' comes back TRUNCATED or SIGN-EXTENDED, with
# no diagnostic. It is the invariant already in CLAUDE.md, in its
# return-value form rather than its argument form.
#
# ------------------------------------------------------------------
# WHAT IT FOUND, AND WHY IT EXISTS.
#
# `string/strtoumax.c' included <inttypes.h> and <stdint.h> -- neither
# of which reaches a declaration of `strtoull' -- so every value with
# bit 31 set came back sign-extended. bash's `printf "%08X" 2604292517'
# printed `FFFFFFFF9B3A59A5'. One line of a probe named it after four
# mechanisms had been refuted by reading.
#
# A bug like that is never alone, so this sweep followed. It found
# `errno/err.c' and `errno/warn.c' calling `strerror' with no
# <string.h>, handing a truncated `char *' to `%s' -- in the two
# functions a program reaches once something has ALREADY gone wrong.
#
# ------------------------------------------------------------------
# ITS LIMITS, STATED BECAUSE A CLEAN RUN IS NOT A PROOF.
#
# It is a LOWER BOUND by construction, exactly like the all-char struct
# sweep in docs/notes/kencc.md:
#
#   - only functions declared in a curated list of STANDARD headers
#     (STD below). The APE include directory also holds third-party
#     headers -- sqlite3ext.h, chicken.h, zlib.h, libdwarf.h -- whose
#     declarations are irrelevant and were the bulk of the noise;
#   - only non-`int', non-`void' return types, which is the damaging
#     class;
#   - a regex for declarations and calls, so a macro, a K&R-style
#     declaration or a call built by token pasting is invisible.
#
# **Three earlier versions of this file reported 491, then 79, then 2
# hits, and the first two were almost entirely NOISE.** The cuts that
# mattered, in order: strip comments and string literals (the first
# version counted `rendezvous()' named in a COMMENT as a call); limit
# the declaring headers to the standard set; and put
# `sys/src/ape/lib/ap/include' on the search path, which is the
# mkfiles' own `-I../include' -- without it every file under math/ and
# complex/ reads as undeclared, because `libm.h' lives there and is
# what includes <math.h>. *An instrument whose include path is not the
# build\'s include path is measuring a different program.*
#
# 0 hits now. Re-run it after adding files to libap.

import os, re, collections
ROOT="/home/user/APExp"
HDRS=[os.path.join(ROOT,"sys/include/ape"), os.path.join(ROOT,"amd64/include/ape"), os.path.join(ROOT,"sys/src/ape/lib/ap/include")]
SRC=os.path.join(ROOT,"sys/src/ape/lib/ap")
# Only the STANDARD headers. The APE include directory also holds third-party
# headers (sqlite3ext.h, chicken.h, zlib.h, libdwarf.h ...) whose declarations
# are irrelevant here and were the bulk of the first sweep's noise.
STD = set("""stdlib.h string.h strings.h unistd.h stdio.h time.h inttypes.h
 wchar.h ctype.h math.h fcntl.h signal.h locale.h stdint.h libgen.h
 sys/stat.h sys/types.h sys/wait.h sys/time.h sys/socket.h pthread.h
 dirent.h pwd.h grp.h utime.h termios.h""".split())

def strip(t):
    t=re.sub(r'/\*.*?\*/','',t,flags=re.S)
    t=re.sub(r'//[^\n]*','',t)
    t=re.sub(r'"(\\.|[^"\\])*"','""',t)
    return t
def find_header(n,cur):
    for d in [cur]+HDRS:
        p=os.path.join(d,n)
        if os.path.isfile(p): return p
inc_re=re.compile(r'^\s*#\s*include\s*[<"]([^">]+)[">]',re.M)
decl_re=re.compile(r'^\s*(?:extern\s+)?((?:unsigned|signed|const|struct|long|short)\s+)*'
                   r'([A-Za-z_]\w*)\s*(\**)\s*([A-Za-z_]\w*)\s*\([^;{]*\)\s*;',re.M)
INTISH={"int","void"}
KW={"if","while","for","switch","return","sizeof","do","else","case"}
declares={}
for d in HDRS:
    for dp,_,fs in os.walk(d):
        for f in fs:
            if not f.endswith(".h"): continue
            p=os.path.join(dp,f)
            rel=os.path.relpath(p,d)
            if rel not in STD: continue
            t=strip(open(p,errors="ignore").read()); m={}
            for q,rt,star,nm in decl_re.findall(t):
                if nm in KW: continue
                if star or rt not in INTISH: m[nm]=(q or "")+rt+star
            declares[p]=m
def closure(path):
    seen,todo=set(),[path]
    while todo:
        p=todo.pop()
        if p in seen: continue
        seen.add(p)
        try: t=open(p,errors="ignore").read()
        except: continue
        for inc in inc_re.findall(t):
            h=find_header(inc,os.path.dirname(p))
            if h: todo.append(h)
    return seen
call_re=re.compile(r'(?<![\w.>])([a-z_][a-z0-9_]{2,30})\s*\(')
hits=collections.defaultdict(list)
for dp,_,fs in os.walk(SRC):
    for f in fs:
        if not f.endswith(".c"): continue
        p=os.path.join(dp,f); raw=open(p,errors="ignore").read(); t=strip(raw)
        local=set(re.findall(r'^[\w \t\*]*?(?<![\w])([A-Za-z_]\w*)\s*\(',t,re.M))
        local|=set(re.findall(r'(?<![\w])([A-Za-z_]\w*)\s*\([^;{]*\)\s*;',t))
        cl=closure(p); vis={}
        for h in cl: vis.update(declares.get(h,{}))
        for name in sorted(set(call_re.findall(t))):
            if name in local or name in vis or name in KW: continue
            w=[(h,d[name]) for h,d in declares.items() if name in d]
            if w: hits[p].append((name,w[0][1],os.path.basename(w[0][0])))
for p in sorted(hits):
    print(os.path.relpath(p,ROOT))
    for n,rt,h in hits[p]: print("   %-18s returns %-14s <%s>"%(n,rt,h))
print("\n%d files, %d call sites"%(len(hits),sum(len(v) for v in hits.values())))
