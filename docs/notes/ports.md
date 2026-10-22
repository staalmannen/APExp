# The ports

One section per package: what it took to build, what broke, and what the
breakage turned out to be about.  Most of the large finds in this tree
came from a port reaching a path nothing had reached before, so these
read as compiler and library history as much as packaging history.


---

## The 0.6 ports: cfront and bacon, and the first full rebuild

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

## The 0.6 ports: cfront and bacon

**BOTH WERE "BUILDING FINE" AND NEITHER WAS BUILDING ANYTHING, AND THE
TWO FAILURES ARE THE SAME SHAPE FROM OPPOSITE ENDS**: generated C
checked into git, so `mk' never regenerated it and never had to.

**cfront/c++lib: ALL FORTY `.c' WERE COMMITTED AT ZERO BYTES.** So
`mk install' in `cmd/c++lib' compiled forty empty translation units,
`libc++.a' built clean with no symbols in it, and the build reported
success -- *a check that cannot fail*, and one that reads exactly like
a port that has started working. The user's memory of "a crash here
before" was right and the crash had become a silent pass.
**The mechanism is the rule, `> $target'.** Every `%.c:' rule was
`c++ -F ... > $target', and a shell redirection CREATES the file
whatever the command then does. They are `-o $target' now: the
driver's -F arm only `cp's once cfront has returned, so a failure
leaves no target and mk stops where the fault is. The forty files are
`git rm --cached' and `.gitignore'd -- the mkfile's own `CLEANFILES'
says `"*.c"', so they were build output all along.
**cfront CANNOT produce an empty file, which is what makes the empty
files evidence rather than a symptom.** Built on the host with gcc
(`make -C src', first try, no patches) and measured: fed a ZERO-BYTE
input it exits **0 and writes 409 bytes** -- version stamp, `__mptr'
typedef, `__ptbl_vec' declaration; fed a TRUNCATED input it exits
**14** and writes partial output. *There is no input for which cfront
both succeeds and emits nothing.* So an empty result means cfront did
not run, and `c++' now refuses it by name instead of passing it on.
**AND READING THE DRIVER FOUND A SECOND BUG THAT HAS ALWAYS BEEN
THERE: `rc' HAS NO `continue'.** The -F arm ended in `continue', which
rc looked up as an external command, did not find, and fell straight
through into step 4 -- so **every `c++ -F' has also been running `pcc
-c' over its own output.** Worse with `-o': the `obj' chain put
`$outfile' on the object path in -F mode, so the fix to `-o $target'
would have had pcc OVERWRITE the generated C with an object file. Both
halves are fixed, and the `if not' chain became one guarded
assignment. *This is the recorded "rc has no `break'" rule arriving in
its other spelling, in a file written after that rule was written
down.*
**WHICH STAGE IS NOW ONE RUN RATHER THAN ONE ROUND EACH.** The
pipeline is `pcc -E' -> `ns_strip' -> `cfront', and "the output is
empty" says nothing about which of the three went quiet; they fail
differently and need different fixes. `fn stages' prints the byte
count of all three, always on a failure and under `-v' otherwise, with
`-' for a stage not reached. *Not reaching a stage is itself the
answer.* **The host cannot settle it**: a host `pcc -E' dies in
`amd64/include/ape/stddef_arch.h' on `#include "/sys/include/ape/..."',
the same absolute-path wall the `readdir.c' syntax check hit, so the
preprocessing half is only measurable on the VM.

**bacon/BASIC: THE COMMITTED GENERATED C WAS A TRUNCATED CONVERSION,
AND gcc SAYS SO -- 50 ERRORS.** Not a kencc question and not a libap
question: `src/bacon.bac.c' was **276KB against a correct 531KB**, and
the damage is what half a transpilation looks like -- `char*
b2c_loop_result` immediately followed by `long b2c_loop_result`,
`FILE* g_CFILE` three lines above `char* g_CFILE`, `IIF`, `INDEX`,
`LOOP`, `MAX`, `MIN` and `MONTH` each `#define`d twice with different
bodies, and string literals cut open mid-escape. *The one-command
check against gcc is what separated "kencc cannot build this" from
"nothing could build this", and the screenful of `Macro redefinition'
and `external redeclaration' from pcc reads exactly like a kencc
complaint.*
**REGENERATED with the tree's own `bacon.sh' (shell BaCon, bash
5.2.21) from the tree's own `bacon.bac', and the new output is
clean**: `gcc -fsyntax-only` **0 errors, 0 warnings**, 0 in the
classes 6c treats as fatal (`incompatible-pointer-types',
`implicit-function-declaration', `int-conversion'), and **every header
it includes exists under `sys/include/ape' or `amd64/include/ape'** --
nothing missing, including `sys/socket.h', `netdb.h', `arpa/inet.h',
`sys/utsname.h' and `wctype.h'. Four stale per-function headers
(`Get_Var', `Mini_Parser', `Parse_Equation',
`Pre_Tokenize_Functions') are gone; they are inlined now.
**And it is not only a compile**: built on the host it answers
`BaCon version 5.0.3` and converts a `FOR`/`PRINT` program, so the
generated converter runs. *That is the control a syntax check cannot
give.*
**`cmd/basic/mkfile` carried `LIB=.../liblua.a'**, copy-pasted from
`cmd/lua'. In `mkone' `$LIB' is a PREREQUISITE of `$O.out' handed
straight to `$LD', so bacon was linked against Lua's archive and could
not be built until lua had been. Removed; bacon needs only libap.
`HFILES' now lists all 81 generated headers -- `bacon.bac.c' includes
`bacon.bac.h', which includes the other 78, so a regeneration changes
files that appear nowhere in OFILES. *The `tclBinary.c'/`config.h'
rule for the fourth time.*
**TK'S HEADERS ARE INSTALLED NOW -- AND DOING IT FOUND THAT `tcl.h'
HAS NEVER BEEN USABLE.** `sys/include/ape/tcl.h' was installed ALONE,
and its line 2433 is `#include "tclDecls.h"', which was not installed
at all. So `#include <tcl.h>` from anything outside Tcl's own build
has always been a fatal error on the first line -- *the `#pragma lib'
in it has never once been reached*, and the convention bacon's Tk
support was to be modelled on did not work. **The control fires
exactly**: with the old set staged, `tcl.h` alone gives
`fatal error: tclDecls.h: No such file or directory`; with the new
set, 0 errors.
**The closure was MEASURED rather than reasoned**: a `#include <tk.h>`
probe compiled against a staged copy, files added until it was clean,
then `gcc -M` asked which of them were actually reached. Twelve:
`tcl.h`, `tclDecls.h`, `tclPlatDecls.h`, `tk.h`, `tkDecls.h`,
`tkIntXlibDecls.h` and `X11/{X,Xfuncproto,Xlib,Xutil,keysym,keysymdef}.h`.
**Tk bundles its own X11** in `external/tk/xlib/X11` (the stub set it
uses where there is no X server), and `Xlib.h` there ends by including
**`tkIntXlibDecls.h`** -- an *internal* Tk header reached from a public
one, which is upstream's design on a non-X platform and not something
to tidy away. All 15 of the bundled X11 headers are installed, not
just the six: a Tk client that uses an atom or a cursor reaches
`Xatom.h`/`cursorfont.h` directly, and six would make that fail for no
reason. *The six are a measurement; the other nine are a judgement and
are marked as one.*
**`#pragma lib` placement is load-bearing.** `tk.h`'s goes BEFORE its
`#include <tcl.h>`, because a kencc static link resolves archives in
the order recorded and libtk needs libtcl -- tcl.h carries its own
pragma, so putting libtk's first is what makes the order libtk, libtcl
rather than the reverse. **And it names four libraries where the rest
of `sys/include/ape` names one**, which is a deliberate departure:
`cmd/wish/mkfile` links `libtk libtcl libdraw libpng libz libap` in
that order, because Tk's Plan 9 backend draws through libdraw and its
photo reader uses libpng. With `libtk.a` alone a program that includes
the header compiles and then fails to link.
**Verified against the REAL include tree, not a staging guess**:
`Tk_Window` and `Display *` both resolve, 0 errors, with the APE
headers staged and their `"/sys/include/ape/..."` absolute includes
sed'ed out -- the same host wall `readdir.c` hit, and the same way
round it. **The Tcl and Tk builds are untouched**: both mkfiles put
`-I$TCLSRC/generic`/`-I$TKSRC/generic` ahead of `sys/include/ape`, so
each still compiles its own copy.

**THE VM RUN FOUND THE REAL CAUSE OF THE SILENCE, AND IT WAS MINE TO
FIND EARLIER: `$status' IS CLOBBERED BY THE VERY NEXT COMMAND.**
Every failure arm of `rc/bin/ape/c++' read
`if(! ~ $status ''){ cleanup; exit $status }' -- and `cleanup' is
`rm -rf', which SUCCEEDS, so `$status' was the empty string by the
time `exit' evaluated it, and `exit '''` is exit 0. **Seven arms,
every one, since the file was written.** *That is the complete
explanation of the forty zero-byte `.c' files*: mk saw a recipe that
had "succeeded" and went on. It is also why the run with cfront
crashing on thirty files walked through all thirty and only stopped
afterwards at `pcc: Can't open input file abs.c' -- a message about
the consequence, two steps from the cause. `$status' is captured into
a variable first now and `die' exits a fixed one-word token, because
a Plan 9 trap status is several words and `exit' takes one. *I had
named `continue' and the `> $target' redirection as the mechanism and
both were real, but neither was load-bearing: this was.*
**`mk clean' DID NOT CLEAN, for a third reason**: `CLEANFILES= "*.c"'
-- mk gives double quotes no meaning and passes them through, so the
recipe asked rc to remove one file literally named `"*.c"'. So a
stale or empty generation survived every clean and was compiled
again. `cmd/perl/mkfile' has had `CLEANFILES = *.c' right all along.
**THE INSTRUMENT PAID IMMEDIATELY**: every line of the run reads
`c++: <file> bytes: cpp N ns_strip N cfront N', and cfront's column
is 1200-3500 rather than 0 -- so **cfront runs, parses, emits its
preamble and then dies**, which is a completely different problem
from the one the empty files suggested. The crashes group by
DIRECTORY and each group shares one pc exactly: `complex/` 13 files
at `general protection violation pc=0x280db8`, `stream/` 16 files at
`fault write addr=0x480010 pc=0x200ed6`, `in`/`intin` at
`fault read addr=0x0 pc=0x297a82`. *A fixed faulting ADDRESS across
sixteen different inputs is a fixed object, not a wandering pointer.*
Five files already convert cleanly (`_ctor`, `_delete`, `_dtor`,
`_handler`, `pure`), which are the ones with no class member
functions.
**AND THE HOST DOES NOT CRASH AT ALL.** cfront built with gcc and
**AddressSanitizer** (`src/cfront_stubs_asan.c`, which needed one
missing `__cfront_pre_main` added locally) was run over EVERY source
in `lib/`: **0 ASAN findings, no crash, exit 5 or 14 with real C++
diagnostics instead.** So the two runs differ in exactly two things
-- the compiler that built cfront (kencc against gcc) and the
PREPROCESSED INPUT, since the two cpps do not emit the same bytes
(25768 against 26557 for `abs.cpp`). **`c++ -K' keeps the
intermediates** so the VM's own `$pp` can be run through the host's
ASAN cfront: a crash there means the input, no crash means the code
generation. *One file settles a question that reading cfront cannot.*
**The host diagnostics are worth their own round and need no VM**:
`sys/include/ape/c++/iostream.h:224` gives
`ostream::operator <<() cannot be redeclared in class declaration`
four times, `_arr_map.cpp` gives
`operator delete()'s 2nd argument must be a size_t`, `placenew.cpp`
`two definitions of operator new()`, `abs.cpp` `two definitions of
norm()`. Several of these are cfront failing to tell two OVERLOADS
apart, which on a 64-bit target is the shape of a type-signature
comparison that collapses `int` and `long`.
**`<values.h>` DID NOT EXIST and fourteen files include it.** Three
use its macros for real (`perl/pp_sys.c`, `p2c/src/trans.h`,
Devel-PPPort's `limits`), and `cfront-C4/lib/new/_arr_map.cpp` -- in
cmd/c++lib's OFILES -- includes it and uses NOTHING from it, so a
whole object failed over a vestigial line. Written now, and **every
value is DERIVED from `<limits.h>`/`<float.h>` rather than
transcribed**: kencc's `long` is 32-bit where the host's is 64, and
this tree has already spent three rounds on constants that existed
twice and disagreed. One definition, and it is somewhere else. With
it `_arr_map` preprocesses and reaches real diagnostics.
**`TCIFLUSH`, `TCOFLUSH` and `TCIOFLUSH` were missing from
`<termios.h>`** while `tcflush(int, int)' was declared in it -- a
function the header promises whose second argument could not be
named. Of POSIX's four groups it was the only one absent, so the gap
read as nothing at all until bacon's `__b2c__getch' used it and the
build stopped at `name not declared: TCIFLUSH'. 0/1/2, the glibc and
musl assignment; nothing in libap reads the value, since
`termios/tcgetattr.c' casts `queue_selector' to void. **NOTICED, NOT
FIXED**: that no-op is right for the KERNEL and questionable for this
LIBRARY, whose select() copy process does hold unread bytes a
conforming TCIFLUSH would discard. Nothing has measured it.

**THE TERMIOS FIX BROKE EVERY APE BUILD, AND IT WAS A COMMENT.** The
block added beside `TCIFLUSH` named the tcflow group with a glob
rather than spelling the macros out, and that glob contained a star
followed by a slash -- **the two characters that END a C comment**.
It closed itself mid-sentence, everything after became code, and the
apostrophes in the prose then read as character constants: four
`Unterminated string or char const` and a
`syntax error, last name: TC`, *not one of which mentions a comment*.
*A comment containing the close sequence is not a comment*, and a
header is the one file where that breaks every translation unit
rather than one. **I had compile-verified `values.h` in the same
commit and not `termios.h`** -- the check existed and was not applied
to both.

**SO `apehdr-sweep.py` EXISTS NOW, AND IT PAID BEFORE IT WAS
FINISHED.** It compiles a file whose whole content is
`#include <that header>` for each of the 149 in `sys/include/ape`,
with the BUILD's include path in the BUILD's order. **149 headers,
23 known-not-standalone, 0 findings** -- and the control fires:
reintroducing the comment bug reports `termios.h: unknown type name
'TC'` and nothing else.
**Its first version reported 39 failures and 16 of them were ITS
OWN**: it flattened `$objtype/include/ape` and `sys/include/ape` into
one directory, where the two collide, instead of passing them as two
`-I` in order. *An instrument whose include path is not the build's
include path is measuring a different program* -- `apdecl-sweep`
learned that exact lesson the exact same way, and I made the mistake
again in the next sweep I wrote.
**THE OTHER 16 WERE REAL: `Lock` IS DEFINED TWICE.**
`qlock.h` includes `<lock.h>`, which typedefs `Lock`, and then
carries its own copy guarded by **`#ifndef Lock`** -- and `Lock` is a
TYPEDEF, not a macro, so the preprocessor has never heard of it and
that test is always true. The duplicate was always emitted. Textually
identical is not compatible: each `typedef struct { int val; } Lock;`
defines its own ANONYMOUS struct, so they are distinct types sharing
a name, which C forbids. `<pthread.h>` includes both files, so
**sixteen of the 149 headers could not be compiled by a
standards-strict compiler at all**; kencc tolerated it, which is
exactly why it survived. *This is the `PATH_MAX`/`NGROUPS_MAX` rule
-- when a name is wrong, grep for EVERY definition of it -- arriving
for a TYPE, where the cost is a layout rather than a value.*
**And three entries of the sweep's own exemption list were WRONG**,
which it reported rather than hid: `qlock.h`, `tclPlatDecls.h` and
`tkIntXlibDecls.h` were listed as not-standalone and all three
compile. An exemption that starts passing is a finding too, or the
list becomes a set of excuses nobody shortens.

**cfront: THE DRIVER WORKS NOW AND mk STOPS AT THE FAULT.** The run
reads `c++: FAILED at cfront on arg.cpp -- cfront 250970: sys: trap:
general protection violation pc=0x280db8` followed by `cpp 25897
ns_strip 25897 cfront 1265`, and `mk` exits `cxxfail` on the FIRST
file instead of marching through forty. *The `$status` fix is
confirmed where it was found.*
**The crash is ONE LINE: `table.c:1455`, `while ((*__2p))`** --
`table::grow` walking its name array and dereferencing
`np[j]->expr.string`. **One line above it sits a hand-added guard,
`if ((long long)__2s < 0x200000) continue;`** -- so a garbage string
pointer in this table is a phenomenon this fork already knew about
and papered over with a magic number rather than diagnosed.
**TWO MECHANISMS OFFERED BY THE STACK AND BOTH REFUTED BEFORE BEING
BUILT ON.** `acid` showed
`insert__5tableFP4nameUc(__1nn=.., __0this=.., __1k=0x7fff00000000)`,
and `0x7fff00000000` is a 64-bit slot holding the high half of a
stack address with the low half zeroed -- the exact shape of this
tree's 32-bit-`long` invariant. **But the real declaration is
`(__0this, __1nx, __1k)`, `this` FIRST**, and acid printed `__1nn`
first: *its argument order does not match the declaration, so its
value-to-name assignment cannot be trusted here*, and the lead
dissolves. The second was the build-flag difference -- the host
passes `-D__HAVE_SIZE_T` and the mkfile does not: **referenced
nowhere in the sources**, inert. `-D__cfront_have_bool` likewise
changes nothing the host does not already get, since the `enum bool`
it suppresses is already behind `!defined(__GNUC__)`.
**So the decisive experiment is still the one `-K` was built for**,
and it is now one file: the VM's own `$pp` through the host's ASAN
cfront. **And `lstk()` rather than `stk()` is the better command**
-- it prints LOCALS, so `__1j`, `__2s` and `__2p` say directly
whether the index is in range and what the pointer holds, where the
arguments have already proved misleading once.

**AND `lstk()` NAMED IT: A `const char *` HOLDING ITS OWN TEXT.**
`__2s = 0x6f69736963657270` and those eight bytes little-endian are
**"precisio"** -- the first eight characters of the identifier
`precision`. `table.c:1450` is
`__2s = (__1np[__1j])->__O2__4expr.string;` and 1455 dereferences it.
*Third time in this tree a pointer has contained characters*, after
bash's `ifs_value` holding `'.'` and `date`'s `tm_zone` holding
`4865`.
**AND acid HAD TO BE CALIBRATED FIRST, which is what stopped a fourth
false lead.** Every int local looked like garbage -- until the pairs
line up:

```
  __1j = 0x474c200000001a      __1hash = 0x474c20
  __1i = 0x2b2cfb00000003      __1sick = 0x2b2cfb
  __2oerror_count = 0x47552000000000   __1n = 0x475520
```

**In every pair the HIGH half of the "garbage" IS the neighbouring
variable**: acid reads eight bytes for a four-byte `int`, so the low
half is the value and the high half is the next slot. `__1mx` reads
`0xa5` = **165**, and `(g*3)/2` for `g = 0x6e` is 165 exactly. *So
every int in that dump is correct and merely mis-printed, and `__2s`
-- a genuine eight-byte pointer slot -- is the one value that is
really wrong.* Three independent pairs agree on the artefact before
anything was built on the one that did not. This is the `stk()`
lesson again one level down: **acid's own display is a claim like any
other.**
**THE TRANSLATOR WROTE ITS OWN ANSWER INTO THE SOURCE, AND THAT IS AN
ORACLE THIS TREE HAS USED BEFORE.** Every generated struct in
cfront's C carries the size the translator computed --
`struct expr { /* sizeof expr == 40 */`, `name == 144`,
`node == 3` -- **132 of them across the `.c` files**, against tar's
nine. GNU tar's `union block` was 520 here where everything else says
512, because `6c/swt.c`'s `align()` rounds every struct up to 8
(`Asu2`) and aligns a nested struct member to 8 (`Ael1`). *A wrong
field OFFSET is exactly what puts an identifier's text where a
pointer should be*, so the sizes are the cheapest proxy for the
question the crash asks.
**`struct node` is already a guaranteed disagreement**: `TOK` and
`bit` are both `unsigned char` (`typedef.h:19-20`), so it is **3 on
gcc and 8 under kencc**. Whether that matters depends on whether
anything strides over a `node`; field offsets stay right and what
breaks is `sizeof` used as a stride. *The probe reports the fact and
does not decide the consequence.*
**`cfrontsz-probe.py` WAS the instrument and is REMOVED with cfront**
-- its input, cfront's generated `main.c`, is no longer tracked, so it
could not run; the lesson below is why the paragraph stays. It was the
`tarblock-probe` idiom generalised: it extracted `main.c`'s preamble
(the file whose declarations are the largest superset, 47 tagged
types), emits a probe asking `sizeof` for each beside the recorded
number, and **runs the gcc control itself** -- 47 of 47, **0
disagreements**, which is what says the extraction is right. *An
instrument that cannot reproduce the known answer has not earned the
right to report an unknown one*, and a bad extraction would otherwise
produce a probe that compiles and measures nothing. It refuses to
print the VM command unless the control passes. The pcc flags are
cfront's own from `cmd/cfront/mkfile`, for the reason `tarblock-probe`
records: built with different flags it measures a different header.
Each type is asked with the KEYWORD it was declared with, since the
`__Q2_4expr4__C1` family are unions.
**TWO cfront HYPOTHESES REFUTED BEFORE THIS ONE**, both cheaply: the
host passes `-D__HAVE_SIZE_T` and the mkfile does not -- **referenced
nowhere in the sources**, inert; and `-D__cfront_have_bool` suppresses
an `enum bool` that is already behind `!defined(__GNUC__)`, so the
host gets the same thing.

**bacon's REMAINING GAP WAS ASKED ALL AT ONCE RATHER THAN ONE PER
ROUND, and the answer was TWO names.** Preprocessing the whole of
`bacon.bac.c` against the staged APE headers and collecting every
`undeclared` identifier gives exactly `IP_MULTICAST_LOOP` and
`IP_MULTICAST_TTL` -- *a complete answer where `TCIFLUSH` had been a
sample of one*. One command instead of one round each, which is the
rule this file already carries for counting a string in the corpus.
**The IPv6 spellings were all there and the IPv4 ones were not**:
`network/socket.c` already accepts `IPV6_MULTICAST_HOPS`, `_IF` and
`_LOOP` and had no IPv4 counterpart at all, so a program could name
the v6 option and not the v4 one. Added with `IP_MULTICAST_IF`,
`IP_ADD_MEMBERSHIP`, `IP_DROP_MEMBERSHIP` and **`struct ip_mreq`** --
the struct deliberately, because declaring `IP_ADD_MEMBERSHIP`
without the type of its argument is the gap `<termios.h>` had for
`tcflush` one round earlier: an option a program can name and cannot
call.
**The NUMBERS are this file's own and the comment says so.** 1/7/8/9
match neither 4.4BSD nor Linux, so there is no external numbering to
be consistent with and none is needed -- nothing transmits these and
`socket.c` is the only consumer in the tree. Distinctness is the only
requirement.
**AND THE THREE OPTIONS GET THREE DIFFERENT ANSWERS, which is the
whole content of the change.** `IP_MULTICAST_IF`/`_TTL` join the
accept-silently list beside `IP_TTL`. **`IP_MULTICAST_LOOP` is split
by its VALUE**: enabling it asks for the state the socket is already
in, so 0 is true; disabling it asks for something this stack cannot
do, and 0 would say the packets had stopped coming back when they had
not -- ENOPROTOOPT. *A stub that answers "failure" is not the same as
one that answers "nothing to do", and the two halves of this one
option fall on opposite sides of that line.* And
`IP_ADD_MEMBERSHIP`/`IP_DROP_MEMBERSHIP` are deliberately NOT listed,
so they reach the default and refuse: Plan 9 **can** do this
(`/net/udp/N/ctl` takes `addmulti`/`remmulti`), so it is a gap rather
than a limit, and accepting silently would be the worst of the three
-- a program would believe it had joined a group and then receive
nothing, with no error anywhere to say why.

**AND THAT RUN FOUND A SECOND BUG THE PER-HEADER SWEEP CANNOT SEE:
`<stdlib.h>` DECLARED `uname` AND `getrusage`.** It defines neither
`struct utsname` nor `struct rusage` and includes neither header, so
each struct named in those parameter lists was a **new, incomplete
type scoped to the declaration** -- distinct from the real one. Any
translation unit including `<stdlib.h>` and then the right header got
`conflicting types`, and bacon includes both. *This is the `Lock`
bug a second time*: one name declared twice, the two spellings not
compatible, kencc tolerating what the standard forbids. Removed --
POSIX puts them in `<sys/resource.h>` and `<sys/utsname.h>`, both
already declare them correctly beside the struct, and the only caller
in the tree (`plan9/__p9_syscall.c`) includes `<sys/resource.h>`
itself. **bacon's undeclared count is now 0.**

**AND THE SAME QUESTION AT THE LINK STAGE GAVE THE SAME SHAPE OF
ANSWER: `random' AND `srandom' DID NOT EXIST.** With the undeclared
count at 0 bacon compiled and then failed to link --
`Handle_Tree: undefined: random', `main: undefined: srandom in main'.
**Asked all at once rather than one per round**, as the header gap
was: compile `bacon.bac.c` on the host, take `nm -u`, and subtract
every name libap defines. 120 undefined symbols, and after those two
the remainder is **nine glibc artefacts of the host compile**
(`__errno_location`, `__isoc99_sscanf`, `__stack_chk_fail`,
`__xpg_basename`, `_setjmp`) and four VARIABLES my function-shaped
grep could not match (`optind`, `opterr`, `optarg`, `stdin`), all of
which are present. *So the link gap was exactly two names, and that
is a complete answer rather than the first of a series.*
**`rand.c` was NOT reusable, which is the one case in this tree where
reaching for the neighbour would have been wrong.** It is Mitchell &
Reeds with a state of 607 longs -- **2428 bytes** -- and
`initstate()` is handed 8 to 256 bytes and must keep the generator's
whole state INSIDE it. There is no arrangement under which that fits.
*Four times now the library has held a working version of the thing
it could not do; this is the fifth look and the first where the
answer is no.*
**BIT-COMPATIBLE WITH glibc AND 4.4BSD, deliberately.** A seeded
sequence is something programs reproduce across machines, so "a
generator with the right distribution" is not the specification --
the numbers are.
**AND THE DEFAULT STREAM COSTS NO TABLE.** glibc ships 31 magic words
for the unseeded state; 4.3BSD's own comment says that table is the
state `initstate(1, randtbl, 128)` leaves, the rear pointer returning
to 0 because srandom discards exactly `10*deg` values. So `srandom(1)`
on first use reproduces it, and **section 1 of the cross-check
measures that claim rather than assuming it** -- a 31-word table typed
by hand would have been this tree's fourth duplicated constant, and
its failure would arrive as a wrong number rather than a diagnostic.
**`random-xcheck.c` is the instrument** (host program, TWO compiles,
the `strftime-xcheck` rule): 2000 default draws, 400 seeds x 50, all
**five** `initstate` sizes including the state word each writes, a
`setstate` round trip, the previous-state return value and the
under-8-bytes refusal. **0 failures**, and section 4 **found the one
real bug**: `setstate` read word 0 BEFORE saving the old state, so
handing it the state already in use rewound to the last `srandom()`
where glibc continues. Every other section passed. *The ordering is
the whole content of that function and reading alone would have
shipped it backwards.*
**TWO CONTROLS, AND THE FIRST VERSION OF THE SECOND WAS WORTHLESS.**
Section 0 asks the MACHINE whether `random` and `ap_random` are the
same address, since the vacuous-rename trap is what strftime-xcheck
fell into; then it asks whether the comparison can report anything at
all. That second control was first written as `b & 0x7fffffff` for the
"wrong" value -- and `random()` never returns anything above 2^31, so
the mask was a no-op and the broken number was the right one. It
printed a note and passed. *A control whose wrong answer is the right
answer is not a control* -- thirteenth instrument fault, and the only
one so far caught before it shipped. It is two different seeds now,
and it reports 32/32.
**Section 4 had the same defect and the fix found the bug**: restoring
the state already in use is a no-op in glibc, so that version asserted
nothing. Switching away to a second state of a *different size* and
back is what asks the question.

**AND THE PROBE'S OWN ANSWER WAS SEVEN-EIGHTHS NOT ABOUT kencc.**
The VM run said `8 of 47 disagree with the translator', and the
recorded sizes are the **generating machine's**: cfront's C was
produced on Linux, so every system type in it carries glibc's answer.
`__sigset_t` 128 against APE's 64, `_fpstate`/`_libc_fpstate` 512
against 504, `_xsave_hdr` 64 against 32, `__pthread_rwlock_arch_t` 56
against 48 -- *differences APE is not obliged to match and mostly
should not*. Two more are kencc's 32-bit `long` showing through a
`__clock_t` and an `si_band`. **The oracle is an oracle only for the
translator's OWN structs**, and exactly one of those disagrees:
`node`, 3 against 8, the case predicted before the run.
**And `node` cannot be the crash**: `struct name` **inlines** node's
three fields (`base__4node`, `permanent__4node`, `baseclass__4node`)
rather than embedding a `struct node`, because cfront's C flattens
inheritance -- so node's size never enters name's layout.
**BUT THE PROBE WAS ASKING THE WRONG 47 TYPES, AND ITS CONTROL COULD
NOT SEE THAT.** It extracted main.c's PREAMBLE -- everything above
the first function definition -- and cfront's generated C
**interleaves** declarations with definitions, so it got 47 of
main.c's **97**. The gcc control reproduced all 47 and reported 0
disagreements, which was *true*. **Correctness and completeness are
different properties and only one of them was being checked.** Among
the fifty left out were `name`, `expr` and the whole
`__Q2_4expr4__C*` family -- **the exact types the faulting line
dereferences**. *The probe ran, passed its control, and could not
have answered the question it was built for.* Extraction skips
function bodies now, and the missing half of the control is one line:
every tagged type in the file must survive into the probe. 97 of 97.

**AND `-P` WAS ALREADY TAKEN, WHICH THIS FILE'S OWN PLAN DID NOT
NOTICE.** The recorded plan said "`-P` in `sys/src/ape/config`'s
CFLAGS" and justified it with *"the flag costs nothing to parse:
`cc/lex.c`'s ARGBEGIN `default:` arm does `debug[c]++` for any unknown
letter"* -- true, and `P` is not unknown. **Every backend's `peep.c`
uses `debug['P']` for peephole tracing and `reg.c` reads it to
disable register allocation**, so `-P` would have changed CODE
GENERATION while claiming to change layout. *A flag one letter from
another flag is checked, not recalled* -- the rule was already in this
file, and the plan it would have caught was also already in this file.
**It is `-J` now, and a NAMED global `conformalign` rather than a
debug letter**, so the collision cannot recur by someone counting
free letters again. Free uppercase were E, J, O: `E` is `pcc -E`, `O`
reads as an optimisation flag.
**AND pcc HAD TO BE TAUGHT IT EXPLICITLY.** `sys/src/cmd/pcc.c`'s
`ARGBEGIN` has **no `default:`**, so a flag it does not name is
silently dropped -- the build would look exactly right and the layout
would not change. *For a layout flag that is the worst available
failure*, and it would have read as "the compiler change did not
work".
**THE CHANGE IS SMALLER THAN THE SLOGAN.** "kencc aligns everything
to 8" is not what the code does: `Ael1` already answers
`ewidth[etype]` for scalars, which IS their natural alignment on
these targets. The defect is two cases -- `Asu2`'s unconditional
`SZ_VLONG` tail padding, and `Ael1`'s `w <= 0` arm, which catches
struct and union members because `ewidth[TSTRUCT]` is negative. So
`-J` is two lines in each of the ten backends plus one computation in
the shared front end: `sualign()` now records each struct's own
alignment in `Type.talign`, as the max over its members of
`align(1, member, Ael1)` -- *the same identity `__alignof__` already
uses*, rather than a second expression of the same fact that could
drift from it. It follows `packflg` for free, since under
`#pragma pack on` every member aligns to 1.
**IT IS NOT A PER-PACKAGE FLAG, which is the opposite of how it is
natural to reach for it.** -J changes every struct the translation
unit sees, `<stdio.h>`'s and `<sys/stat.h>`'s included, so one package
built with it against a libap built without it disagrees about
`FILE`, `struct stat` and `DIR` -- **silently, with no link error,
because every symbol still resolves.** The safe unit is a whole
self-consistent world: all of APE after a `distclean`, or nothing.
For a few on-disk structs in one package `#pragma pack` is still the
right tool and costs no rebuild. **It is therefore NOT enabled in
`sys/src/ape/config`.**
**`structalign-test.c` is the instrument and it needs THREE runs**:
gcc (0 failures, and the numbers in the file came from that run --
my own arithmetic said 149 where gcc says 150), then `pcc -DPLAN9`
**without** `-J`, which must FAIL about twelve checks, then with it,
which must pass. *The middle run is the whole point*: a test that
passes under `-J` looks identical whether the flag works or the
compiler was always conforming. It checks **offsets as well as
sizes** -- a wrong size breaks a stride, a wrong offset puts one
member's bytes where another is read, which is the shape of a
`const char *` holding the text `precisio`. `-DPLAN9` is not
decoration: section 5's `#pragma pack` is behind it exactly as
tar.h's is.
**One non-conformance `-J` does NOT fix, reported as a PROBE rather
than asserted**: kencc allocates bit fields in whole `tfield` units,
so `struct{unsigned x:3; unsigned y:5; char c;}` is 8 here and 4 on
gcc. Different code, different question; asserting it would make the
test report a failure the flag never promised.
**NOT COMPILED ANYWHERE YET.** kencc's sources need Plan 9's `<u.h>`
and `<libc.h>`, so the gcc sweep this tree uses before shipping
cannot be run on them -- the first build is the VM's. *That is a
weaker position than every other change this round and is worth
saying rather than leaving to be discovered.*

**THE 97-TYPE PROBE RAN, AND `name` -- THE CRASH'S OWN STRUCT -- IS
EIGHT BYTES TOO BIG.** `14 of 97 disagree, 83 agree`, and seven of
the fourteen are cfront's own types rather than glibc's:
`node` 3 -> **8**, **`name` 144 -> 152**, `basic_inst` 168 -> 176,
`funct_inst` 200 -> 208, `state` 88 -> 96, `templ_compilation`
1 -> 8, `templ_inst` 200 -> 208. The other seven are the platform
types already accounted for.
**`name` is the type `table.c:1450` dereferences** --
`__2s = (__1np[__1j])->__O2__4expr.string` -- and `__O2__4expr` is
the SECOND of four unions inside it, so a member that grows ahead of
it moves that union's offset and `.string` reads the wrong eight
bytes. *That is exactly a `const char *` holding the identifier's own
text.* **The padding hypothesis is live again**, and the 47-type run
could not have seen it: `name` was one of the fifty types the
preamble extraction dropped.

**BUT THE TWO INSTRUMENTS DISAGREE ABOUT THE SAME COMPILER, AND THAT
IS THE ROUND'S REAL FINDING.** Minutes apart, same `pcc`:
`cfrontsz-probe` says kencc PADS (`node` 8, `name` 152), and
`structalign-test` says it does NOT -- `struct{char a[3];}` is **3**,
`struct{char a[500];}` is **500**, and **all three runs report 0
failures, including the one without `-J` that was predicted to fail
about twelve checks.** `round()` and `SZ_VLONG` are exactly as read,
so the old rule must answer 8. **Both cannot be true of one
compiler**, so one run is not measuring what its output says -- and
*neither instrument recorded which compiler built its binary*.
**`-J` NOW PREDEFINES `__APEXP_CONFORMALIGN__`**, because `pcc` drops
a flag its ARGBEGIN does not name and `6c` turns an unknown letter
into a debug counter, so **a stale compiler and a working one print
the same thing**. *A null result with two explanations is not a
measurement* -- the `_ttymark`/`_getcwdmark` idiom, for a COMPILER
rather than a library, and the first thing this flag should have had.
`structalign-test` prints it before anything else and gained a
**section 7 PROBE** carrying cfront's own `node` shape -- three
TYPEDEF'd unsigned chars -- beside the char ARRAY section 1 uses, so
one run tells the two instruments apart rather than two rounds.
*The predicted failure did not fire and the prediction was written
down; that is the condition doing its job, not the flag.*

**AND `-J` WAS WORKING THE WHOLE TIME -- 14 of 97 -> 7, EXACTLY THE
PREDICTION.** All seven of cfront's OWN types fall into line under
`pcc -J`: `node` 3, **`name` 144**, `basic_inst` 168, `funct_inst`
200, `state` 88, `templ_compilation` 1, `templ_inst` 200. What is
left is the seven glibc types, which `-J` cannot touch because they
describe the machine that GENERATED the C -- and the two `__Q3_`
entries confirm the reading rather than merely vanishing: `_C4` is
**20** (`__clock_t` four times over at 4 bytes) against Linux's 32,
`_C6` is 8 (`long si_band` + `int si_fd`) against 16. *The 32-bit
`long` invariant showing through, not padding.*
**THE "FLAG NOT PICKED UP" MESSAGE WAS THE MARKER, NOT THE FLAG, AND
IT COST THREE REBUILDS.** `pcc` runs **`/bin/cpp` ITSELF** and pipes
it into `cc` (`pcc.c:299`'s `dopipe`), so the source reaches `cc`
**already preprocessed** -- and neither `dodefine()` in `cc`'s own
symbol table nor `cc`'s `defs[]` can define a macro the source will
ever see. *There are THREE preprocessors in play and only the one
`pcc` spawns actually runs*; the first two attempts configured the
other two. **Name the preprocessor that RUNS, not the one with the
right name** -- the shadowed-`config.h` lesson a third time.
**And the two instruments never disagreed.** `structalign-test` was
compiled **with** `-J` and `cfrontsz-probe` **without** it, and I
read them as the same compile for two rounds. Everything else was
cleared locally first: preprocessing the probe's own translation unit
with cfront's exact flags gives ONE `struct node`, `TOK` and `bit`
both `unsigned char`, and gcc computing 3; `cfront_translated.h`
defines none of the seven; `-B` touches only undeclared-function
diagnostics. *Two compiles differing in one flag is not two compilers
disagreeing, and the flag was in the command line both times.*

**THE OBVIOUS WAY TO TURN `-J` ON TREE-WIDE DOES NOT WORK, and that
is the finding to carry.** `-J` in `sys/src/ape/config`'s CFLAGS
reaches **32 of 137** mkfiles -- the other **105 ASSIGN `CFLAGS=`**
rather than appending `$CFLAGS`, and `cmd/cfront/mkfile:52` is one of
them. `CC` is no better: **59** mkfiles reassign it. *Both of the two
variables a build system offers for exactly this have holes, and
either would have produced the silent ABI split rather than a clean
change* -- 32 packages conforming, 105 not, every symbol still
resolving. **The only mechanism that reaches every APE compile is
`pcc` itself**, since all 59 reassignments still name `pcc`; native
`6c` builds stay on the 9front rule, which is what `cmd2/vts` and
`vtwin` need when they link the host's own `libc.a`.
**`apeabi-probe.c` is what to run BEFORE deciding that**: two
compiles and a diff, `pcc -a` against `pcc -J -a`. `-a` emits acid
definitions carrying every struct's size and every member's offset
(it is `mkone`'s own `%.acid` rule), so the diff is a complete list,
**from the compiler itself**, of everything `-J` moves inside the APE
world. An empty diff would mean the flag is free; a long one is the
cost named struct by struct before a single object is rebuilt. 0
errors against the staged headers on the host.

**AND `-J` WAS ALREADY ON FOR MOST OF THE TREE -- `pcc` ITSELF WAS
PASSING IT, AND HAS BEEN SINCE THE FLAG LANDED.** `pcc.c`'s
`if(!Aflag)` block appended **`-J` to the compiler on every
invocation**, commented *"old/new decl mixture hack"* -- a comment
describing a hack that had stopped existing, because **stock `cc`
names no `-J` at all**: it fell to ARGBEGIN's default, set
`debug['J']`, and **nothing in the whole tree reads `debug['J']`**
(grep: zero hits). A pure no-op for its entire life. Giving the
letter a MEANING therefore turned conforming layout on for every APE
compile that passed neither `-A` nor `-B` -- *the silent ABI split
the flag was built to avoid, created by the flag, live in the tree
for three commits.* **`-P` over again, one level out: I checked `cc`
for a collision and did not check the DRIVER that calls it.**
**It explains both of the round's loose ends with no slack left
over.** `structalign-test` was run as `pcc -DPLAN9` -- no `-A`, no
`-B` -- so the command written down as *the control* was byte for
byte the same compile as the one below it, which is why the twelve
predicted failures did not fire. `cfrontsz-probe` carries cfront's
own flags, which include **`-B`**, so `Aflag` was set, no `-J` was
appended, and it kept the old rule and disagreed on fourteen types
in the same minute. *Two instruments, two layout rules, one `pcc`,
and neither command line said which it was getting.* The earlier
reading -- "one was compiled with `-J` and the other without" -- was
right about the fact and wrong about the cause, and the cause is the
half that needed fixing.
**Removed from the default, so `-J` now means exactly what it says**,
and that makes the tree-wide decision **one line in `pcc.c`** rather
than 137 mkfile edits.
**AND `pcc` NAMED NEITHER `-a` NOR `-Z`, so the probe could not be
taken at all**: `pcc -a apeabi-probe.c` answers `cc: flag -a ignored`
and compiles normally. Both are forwarded now; **`-c` is required
with them** (with `-a` the compiler writes acid to stdout and makes
no object, so pcc would otherwise go on to link one that is not
there). On an older pcc, `pcc -c -W0,-a` passes it by hand. *A driver
that dropped the flag for READING a layout, standing next to one that
dropped the flag for CHANGING it.*
**A run of `apeabi-probe` on a pcc predating this is VOID** -- both
sides would have had `-J` and the diff would come back EMPTY, reading
exactly like a flag that costs nothing.
**Twelve mkfiles said `CC=$APEXPROOT/$objtype/bin/pcc`** where 48
others say plain `pcc`; normalised, since the tree already depends on
`pcc` resolving. *Inconsistent rather than load-bearing* -- and it
does not bear on `-J` either way, since all twelve named the same
program.

**AND THE ACID DIFF IS IN: `-J` MOVES SIXTEEN STRUCTS AND NOT ONE OF
THEM IS IN THE STDIO/STAT CORE.** Two compiles of `apeabi-probe`,
~1400 lines of acid each, and the whole diff is twenty-four hunks
over **two families**:
- **Network addresses**, every one of which becomes the number every
  other system says: `in_addr` 8 -> **4**, `sockaddr_in` 24 -> **16**
  (`sin_addr` 8 -> 4, `sin_zero` 16 -> 8), `sockaddr_in6` 32 -> 28,
  `ip_opts` 48 -> 44, `ip_mreq` 16 -> 8, `sockproto` 8 -> 4,
  `sockaddr`/`sockaddr_storage` 112 -> 110.
- **Locks and pthreads**: `QLock` 32 -> 24, `Rendez` 32 -> 24,
  `pthread_mutex_t` 56 -> **40**, `pthread_cond_t` 56 -> 48,
  `pthread_rwlock_t`'s members, `pthread_once_t` 16 -> 8, and the two
  anonymous lock types `_8_`/`_10_` 8 -> 4. **That is the recorded
  `Lock`-is-one-`int` invariant arriving from the other side** -- the
  very structs the two-stage-bootstrap note said would disagree with
  a native `libc.a`, which is exactly why this stays inside APE.
- Plus `termios` 32 -> 28, on its own.
**WHAT IS ABSENT IS THE RESULT.** `FILE`, `struct stat`, `DIR`,
`jmp_buf`, `sigjmp_buf`, `fd_set`, `tm`, `timeval`, `timespec`,
`dirent`, `passwd`, `group`, `rusage`, `utsname`, `hostent`,
`addrinfo`, `sigaction`, `lconv`, `regex_t`, `mbstate_t`, `sigset_t`
-- **every one unchanged**, and they are the types the flag's own
warning named as the reason it is all-or-nothing. *The feared cost
and the measured cost are different sizes, and only the probe could
have said so.*
**So the blast radius is sockets and threads**, both entirely inside
libap, neither written to disk nor shared with native code.
`/env/_fdinfo` was checked rather than assumed and is **TEXT**, so
there is no cross-`exec` layout hazard there; the one shared BINARY
object is `_buf.c`'s `Muxseg`, between a process and its own copy
process, which `mk distclean` already covers for the reason that
section records.
**SO IT IS ON BY DEFAULT NOW, in `pcc` and nowhere else.** Not CFLAGS
(32 of 137) and not CC (59 reassign it): *both of the two variables a
build system offers for exactly this have holes*, and all 59 still
name `pcc`. **Unconditional, and NOT inside the `if(!Aflag)` block**
-- that block does not run when `-A` or `-B` was given, and
`cmd/cfront` passes `-B`, so putting it there would have missed the
one package the flag was built for. Native `6c` is untouched.
**`pcc -9` is the way BACK**, and it exists for the instruments
rather than for the build: `structalign-test`'s control run and
`apeabi-probe`'s two compiles are both *differences between the two
rules*, and with no way to ask for the old one neither could ever be
taken again. *An irreversible default takes the measurement with it.*
Nothing in the tree passes `-9` and nothing should. `-J` is still
accepted and now does nothing.
**`mk distclean` BEFORE `mk install`**, and the usual reason with an
extra edge: no mkfile lists a system header as a dependency, and
nothing here makes a link fail, so a half-rebuilt tree is silent.
**What to watch, written down before the run**: sockets and threads
are the whole blast radius, so Tcl's `socket.test`/`socket_inet.test`
are the sharpest instruments the tree has for it -- a clean run there
is the confirmation, and a NEW socket failure means something is
computing a length it should not.
**THE TREE BUILDS: `mk distclean` plus `mk install` COMPLETED with
conforming layout everywhere.** *That is the weakest useful result
and is worth saying so plainly*: it confirms nothing fails to compile
or link, and the hazard this flag carries is one that produces
NEITHER. `sockaddr_in` 24 -> 16 and `pthread_mutex_t` 56 -> 40 are
silent by construction -- every symbol resolves either way -- so the
build completing is a precondition for the measurement rather than
the measurement. **The confirmation is behavioural and is still
outstanding.**

**`structalign-test`'s THREE RUNS ARE IN, AND THE MIDDLE ONE FINALLY
FIRED: 14 failures under `pcc -9`, 0 under `pcc`.** That is the first
time the control has produced the predicted failures -- the two
earlier attempts were byte for byte the same compile, because `pcc`
was appending `-J` itself. `struct{char a[3];}` 8 -> 3,
`struct{char a[500];}` 504 -> 500, `offsetof(mixed,n)` 8 -> 1,
`sizeof(struct oldgnu)` 160 -> 150, the packed nested case 10 -> 5,
and section 7's PROBE prints **3** for cfront's own `node` shape. The
`__APEXP_CONFORMALIGN__` banner is what makes the pair readable:
`-J NOT in effect` above the failures, `-J was understood` above the
zero. *A flag, a marker for the flag, and a control run that must
fail -- and only all three together say anything.*
**Section 8 PASSES IN BOTH RUNS, which is correct and is the half
worth checking.** The `sualign` bit-field bug was never gated on
`conformalign`, so a fix that only worked under `-J` would have shown
as section 8 failing under `-9` -- it does not, and `type` survives
every one of the four writes in both runs.

**AND cfront'S CRASH IS GONE -- THE PADDING HYPOTHESIS IS CONFIRMED
BEHAVIOURALLY.** `rm *.c && mk install` in `cmd/c++lib` no longer
reports `general protection violation pc=0x280db8`; cfront exits
**5** with real C++ diagnostics, and its byte column went
**1265 -> 5747**, so it now parses whole headers instead of dying
after its preamble:

```
  iostream.h:224: ostream::operator <<() cannot be redeclared ...
  abs.src.c:40:   two definitions of norm()
  c++: FAILED at cfront on .../complex/abs.cpp -- cfront 62022: 5
  c++: ... bytes: cpp 26553  ns_strip 26553  cfront 5747
```

*That is exactly the prediction written down before the run*:
`name` 144 -> 152 moved the second of its four unions, so
`__O2__4expr.string` read the wrong eight bytes and came back holding
the text `precisio`. `-J` puts `name` back to 144 and the
dereference is of a pointer again.
**AND `pcc -9` SETTLED THE ATTRIBUTION EXACTLY AS ASKED.** cfront
rebuilt with the old layout rule crashes again on the same file at
**`pc=0x280db8`** -- the same address to the digit -- with
`cfront 1265` bytes, byte for byte the pre-`-J` run. **The
`sualign` fix is in BOTH builds**, since that line was never gated on
`conformalign`, so it is excluded and `-J` is the vehicle with
nothing left over. *One flag, one rebuild, two numbers that were
written down before the run* -- and it is the first time this tree
has produced an A/B where the only difference is a layout rule and
the observable is a faulting address.
**THE SEVEN MAGIC GUARDS WERE NEVER WORKING, which is the finding
the pair hands over for free.** `table.c` carries
`if ((long long)...string < 0x200000) continue;` at **1245, 1351,
1451, 1470, 1607, 1671 and 1672** -- this fork papering over a
garbage `const char *` in seven places rather than diagnosing it.
They catch only the case where the misread eight bytes happen to be
a SMALL number, and the one that actually crashed held
`0x6f69736963657270` -- the text `precisio`, far above the
threshold. *A workaround whose own threshold the real case steps
over*, and seven copies of it meant nobody ever asked why.
**REMOVED, and the A/B was confirmed in BOTH directions first**: the
`-J` rebuild was run a second time and gave the same `cfront 5747`
and the same five diagnostics, so neither side of the pair was a
one-off piece of state. Five were a standalone `goto nxt`/`continue`;
`look__6ktable`'s was half of an `&&`; `insert__6ktable`'s was a
two-line `||`. **gcc compiles the file before and after -- which is a
SYNTAX check and not a control**, since both sides pass, and saying
so is the point: the only thing that can confirm this is the VM.
**CONFIRMED: byte-identical.** `cpp 26553  ns_strip 26553
cfront 5747`, the four `iostream.h` redeclarations, `two definitions
of norm()`, exit 5 -- the prediction was written down before the run
and every number in it matched. So none of the seven was
load-bearing, and the garbage pointer they existed for is gone
rather than hidden.
**cfront IS CLOSED AS A QUESTION FOR THIS TREE.** What remains is a
1980s front end that cannot tell two overloads apart on a 64-bit
target, reproduced character for character by the host's own gcc
build -- upstream's, not APExp's. The directory stays, off, for the
three reasons above.
**The diagnostics that remain need no VM and are already recorded**:
the four `iostream.h` redeclarations and `two definitions of norm()`
are character for character what the host ASAN build produced, and
several of them are cfront failing to tell two OVERLOADS apart --
the shape of a type-signature comparison that collapses `int` and
`long` on a 64-bit target.

**AND THE TCL RUN BESIDE THEM IS VOID, FOR A REASON THAT READ EXACTLY
LIKE A RESULT: `mk distclean` DELETED THE TEST INTERPRETER AND
`mk install` DID NOT PUT IT BACK.**

```
  before:  Total 68118  Passed 62138  Skipped  5916  Failed 64
  after:   Total 66970  Passed 55700  Skipped 11233  Failed 37
```

**A failure count that falls by 27 while `Skipped` rises by 5317 is
not an improvement**, and the `Test files exiting with errors:
brodnik.test, mutex.test` line -- absent from every previous run --
is what names the cause. Both files stop on
`package require tcl::test`: mutex.test requires it at the top level,
and **brodnik.test's `try {package require tcl::test}` has no handler
clause, so the error propagates just the same**. Two files aborting
on one line means the package was ABSENT, which means the suite ran
under plain `tclsh`.
**`cmd/tclsh/tcltest` was a `V:` target reachable from nothing while
`CLEANFILES` names it** -- so `clean` removed it and `install` never
rebuilt it. It is a FILE target with `install:V: tcltest` beside it
now (every `V:` rule for a target runs in Plan 9 mk, the idiom
`lib/itcl` already uses), so a distclean plus install leaves the
suite measurable. **`cmd/wish/tktest` had the same asymmetry and the
same fix** -- its `clean:V:` removes it too -- and the degradation
there is milder only because no Tk file aborts: the constrained tests
skip, `Failed` falls, and nothing says why.
**AND BOTH HARNESSES NOW SAY WHICH INTERPRETER THEY ARE.**
`tcl-runall.tcl` REFUSES without `tcl::test`, printing the two
commands to fix it, with `$APEXP_TCL_ANYSHELL=1` as the escape for
the one legitimate case (asking what the *installed* tclsh does);
`tk-runall.tcl` WARNS instead, because there nothing is lost but
comparability. Its marker is `testbitmap`, which `tkTest.c:222`
registers unconditionally -- `testmetrics` and `testmenubar` are
behind platform ifdefs and would report a missing tktest on a
platform that merely has no such command.
*This is the `THIS_SH=../bash` precondition for the fourth time, and
the first time it has been the BUILD SYSTEM rather than a default in
an upstream script.*

**AND THE RE-RUN UNDER `tcltest` IS THE BEHAVIOURAL CONFIRMATION OF
`-J`: EIGHTEEN FIXED, NOTHING BROKEN, NOTHING EVEN MOVED.**

```
  baseline:  Total 68118  Passed 62138  Skipped 5916  Failed 64
  with -J:   Total 68118  Passed 62156  Skipped 5916  Failed 46
```

**`Total` and `Skipped` are IDENTICAL to the digit**, which is what
makes the comparison sound at all: nothing became unrunnable, nothing
newly skipped, no file aborted -- so `Passed` +18 and `Failed` -18 is
one arithmetic statement about the same 68118 executions. The marker
is present, `exit called (code 0)`, and **the `Test files exiting
with errors` section is gone**, so this really is the test
interpreter. *The void run and this one differ in nothing but which
binary ran them, and that is the cleanest control this suite can
give.*
**AND THE SOCKET CONFIRMATION IS WITHDRAWN: THERE IS NO
`socket_inet.test`.** This round recorded *"`socket_inet.test` has
left the failing-file list entirely"* as the behavioural evidence that
`-J` had not broken the socket half of its own blast radius
(`sockaddr_in` 24 -> 16, `in_addr` 8 -> 4). **That file does not exist
and never did**: the suite has one `socket.test`, whose body is
`foreach {af localhost}` with `test socket_$af-1.1 ...`, so every
`socket_inet-*` name is GENERATED with `$af` = `inet`, and a grep for
`socket_inet-5.1` matches no file in the tree. *Its absence from the
list could not have been anything else under any outcome* -- and the
substance fails too: **`socket_inet` has four failures, 2.11, 5.1,
5.3, 7.3**, which is exactly the "`socket_inet` 4" already listed as
unread below. **A name absent from a list is not a measurement until
you have checked the name could ever have appeared there** -- an
absence has two explanations, the thing passed or it was never called
that, and only one is a result.
*The eighteen stand on `Total` and `Skipped` being identical with
`Passed` +18, which is sound. The ATTRIBUTION to sockets does not* --
so with the pthread half already recorded as skipped (`197 thread`,
`12 testmutex`), the behavioural confirmation of `-J` covers neither
family it actually moved.
**THE PTHREAD HALF IS NOT MEASURED HERE, and the skip table says so
rather than leaving it to be assumed**: `197 thread` and `12
testmutex` are SKIPPED, so `pthread_mutex_t` 56 -> 40 and
`pthread_cond_t` 56 -> 48 were barely exercised. *Half the blast
radius is confirmed and half is untouched*, which is a different
statement from "the suite is clean".
**BOTH PER-NAME QUESTIONS ARE NOW ANSWERED, AND A PER-NAME BASELINE
EXISTS AT LAST** -- `docs/notes/tcl-suite.md` carries all 43 names and
the extraction command, because *its absence is what kept this open
for rounds* while every comparison was made by total.
**`Total 68118  Passed 62159  Skipped 5916  Failed 43`**, marker,
exit 0, 167 files, four minutes, `tcl::test 9.0.3 present`.
- **`socket_inet-5.1`/`5.3` were NOT among the eighteen**: both are
  still failing, so the leftover-listener false pass did NOT return.
  That was the stated hazard and this is the good answer.
- **`event.test`/`main.test` were unchanged, not new**: by name they
  are `event-1.1` and `Tcl_Main-5.10`, the two singletons already on
  the list.
**AND 46 -> 43 IS THREE FIXED, NOTHING BROKEN, ALL THREE NAMED**:
`chan-io-41.8`, `expr-old-37.21` and `unixFCmd-2.2.2`, three entries
of the eleven unread singletons. *Three gone and the net is three, so
nothing arrived* -- the only form that confirmation can take, and the
first time this suite's movement has been attributed by name. **None
was predicted or being worked on**, so the vehicle is unidentified and
naming one would be a guess; the baseline makes the next run settle
it. (`io-6.46` and `chan-io-6.46` now both fail, which is the twins
rule working as written; zipfs is **five** `zipfs-password-*` cipher
tests where this file recorded three, one family undercounted from a
prediction rather than a regression.)

**AND THE FIRST REBUILD STOPPED IN bash -- NOT ON `-J`, ON A SHADOWED
HEADER.** `/sys/include/ape/qlock.h:44 syntax error, last name: Lock`,
compiling `general.c`. **`-I$BASHSRC/lib/intl` was on bash's CFLAGS
and that directory holds gettext's own `lock.h`** -- an `-I` is
searched ahead of the system path, so APE's `<pthread.h>`, reaching
its own `#include <lock.h>`, got THAT file, which never typedefs
`Lock`; `<qlock.h>` then hit `Lock lock;` with no such type.
**Nothing in the message says `lock.h`** -- it names the victim's line
in a header bash never mentions, which is why the four-screen command
line was no help. *Name the file that is COMPILED, not the file with
the right name*, for a header a SYSTEM header includes rather than one
the package does.
**AND THE CONFORMANCE FIX IS WHAT MADE IT REACHABLE.** `<qlock.h>`
used to carry its own `Lock` typedef behind an always-true
`#ifndef Lock`, so the shadow cost nothing however the name resolved.
Removing that duplicate was correct -- two anonymous structs sharing a
name is a constraint violation -- and it had been load-bearing.
*A fix that makes a process reach code it never reached before can
expose anything on that path*, this time in a header.
**Removed, and MEASURED rather than hoped**: `ENABLE_NLS` is undef,
the only `<libintl.h>` includes in the compiled set are behind
`#if ENABLE_NLS`, and nothing compiled names any other of that
directory's 29 headers. **`-J` was never in frame** -- the error is a
parse of a type name, and the same file fails the same way under `-9`.
**`sys/lib/tests/ishadow-sweep.py` is the sweep for the class**: which
package `-I` directories hold a header that an APE header includes
with `<>`. **31 (mkfile, directory) pairs, 19 names** -- and it
**gates nothing**, because most are deliberate (Tcl ships `regex.h`
and `tcl.h`, libressl's `include/compat` exists to replace `<stdio.h>`
and friends, zlib owns `zconf.h`). *A sweep that failed on those would
cry wolf*, the rule `apehdr-sweep` already carries. Read a hit as a
question: does the package MEAN to replace that header, or merely
happen to own the name? gettext's `lock.h` was the second kind.
**Its own first version reported 0 of everything and looked healthy**,
because `sys/lib/tests` is THREE levels below the root and it said
two. *A sweep rooted in the wrong tree reports an empty one as a clean
one* -- it now refuses to run unless `sys/include/ape` is under its
root. Fifteenth instrument fault, caught in one run.
**And undoing the control edit with `git checkout <file>` reverted the
FIX in the same file.** *A revert is file-granular and an edit is
not*; the control has to be made and unmade in a copy, or re-applied
deliberately.

**AND THE NEXT STOP WAS `mk: mkfile:96: syntax error; expected one of
:<=` -- IN `cmd/mkfile`, WHICH DOCUMENTS THIS EXACT HAZARD IN ITS OWN
HEADER.** *"Every comment line INSIDE these lists has to end in a
backslash: the list is one continued line, and a comment without it
ends the assignment there."* The block added this round to explain why
`c++lib` and `basic` are off has **four comment lines without one**, so
`_OPTIONAL_APPS` ended at `cfront` and everything from `adeb` to `curl`
became a fresh logical line starting with a bare word. *A rule written
down in a file is not a rule the file obeys* -- and I wrote both.
**THE REPORTED LINE IS WHERE THE RUNAWAY LINE ENDS, NOT WHERE IT
STARTS.** Line 96 is an ordinary `DIRS=\`; the fault is 26 lines
earlier, in a comment. Same shape as the `lock.h` shadow one commit
before -- *the message names the victim* -- and it is why four
hypotheses about the bash mkfile were all wrong: **it was not bash's
mkfile at all**, and every construct in the comment I had suspected
(a lone `#`, `#`+TAB, `<pthread.h>`, an `#include` inside a comment)
has a working precedent elsewhere in the tree. *Checking whether the
suspect construct exists ANYWHERE that already works is one grep and
would have cleared it first.*
**The sweep found it where four readings did not**: every mkfile, every
comment that ends a continuation, reporting only those where the next
logical line is a bare word. `sys/lib/tests/mkcont-sweep.py`, and it
**gates** -- unlike `ishadow-sweep`, each hit is a real break.
**Its discriminator is the whole instrument**: a comment ending a
continuation is usually DELIBERATE (`lib/png/mkfile:42` is the tail of
an OFILES list commented out on purpose), so the naive check is almost
all false positives. 1 finding, 0 after the fix, and the control fires
when one backslash is removed again.
**Watch the first run after this**: ten packages (`adeb`, `dwarfdump`,
`hell`, `pcregrep`, `diff`, `patch`, `mkmk`, `samurai`, `openssl`,
`curl`) re-enter `_OPTIONAL_APPS`. Anything they report is *newly
measured*, not newly broken.

**AND THEN gmake WOULD NOT LINK -- `_convM2D: multiple initialization`
-- AND IT WAS NOT `-J`, IT WAS A REUSED VARIABLE IN `sualign()`.**
`o` is carried ACROSS iterations of the TSTRUCT loop: it holds the
offset of the current BIT-FIELD UNIT, set by the first field of a
group (`l->shift <= 0`) and read back by every later field. The
max-member-alignment loop added for `-J` wrote ITS result into `o`
too -- so **the second and later fields of every bit-field group were
placed at the previous member's ALIGNMENT instead of at the unit's
offset.** `ma` now, in both the TSTRUCT and TUNION arms.
**It was NOT gated on `conformalign`**: that line runs on every
compile, so plain builds were wrong as well, and it has been so since
`81a59a1d`. *A one-line addition to a loop that was already using its
variables for two things.* **No compiler can warn**: both uses are a
`long` holding a small number.
**GNU make's `struct command_switch` is what named it** -- `int c`,
`enum type`, `void *`, then `env:1 toenv:1 no_makefile:1
specified:1` -- so the three later bits moved to offset 4, on top of
`type`, and `6l` answered `multiple initialization` for every array
entry whose two writes to those four bytes were both non-zero. **The
value in the message is the evidence**: `$2` at `+4` with a 56-byte
stride is the bit-field word with `toenv` set, and `string` is also
2, so only entries with both are loud. *The struct's SIZE was 56
either way -- already a multiple of 8 -- so `-J` changed nothing
about it and a size-only check would have passed.*
**`structalign-test.c` SECTION 8 is the regression test**, and it had
to be a new shape rather than a line in section 4: **section 4's
`struct bits` could never have caught this**, because its bit fields
are the FIRST members, so the clobbered `o` was the alignment of
nothing and the offsets came out right anyway. *A bit-field group
needs a member in front of it before a wrong unit offset is visible.*
It also **cannot use `offsetof`** -- C forbids taking a bit field's
address and gcc says so -- so it asserts the COLLISION instead: set
each field of the group in turn and ask whether `type` survived,
which is the question the linker asked. 0 failures on gcc, numbers
measured from that run.
**`cd sys/src/cmd && mk install` BEFORE the tree rebuild**, and this
one matters for every package, not only the ones with `-J` in frame.

**AND `signal()` IS PROTOTYPED NOW -- `void (*signal(int, void
(*)(int)))(int)`, which is what C and POSIX say.** It had been the
UNPROTOTYPED `void (*)()` since the file was written, under a comment
explaining that libap dispatches `void handler(int, char *msg,
Ureg *u)` -- the Plan 9 note string and the trap frame -- and that a
prototype would put the extension out of reach.
**The extension is unchanged and still dispatched**; what went is a
public declaration that turned off argument checking for EVERY caller
in the tree to keep it reachable. *This tree's own invariant is that
a call with no prototype in scope corrupts its arguments under kencc,
and the thing left unchecked here is a FUNCTION POINTER a program
installs and the library later calls.*
**And the header was not even true of libap**: `signal/signal.c`
defined `signal()` with the three-argument type, so the declaration
and the definition have always disagreed and only the empty parameter
list made it legal.
**Nothing in the tree uses it -- swept rather than assumed.** 56
distinct handler names reach `signal()`; exactly two take more than
one argument, and neither is this extension (`diffutils`' own
`signal_handler(int, sighandler)` wrapper, whose `sighandler` is
already `void(*)(int)`, and a `muon` TEST using `SA_SIGINFO`). The
only files outside libap that mention `Ureg` are go1.4's runtime,
which is not built here.
**`SIG_DFL`/`SIG_ERR`/`SIG_IGN` and `sa_handler` MOVE WITH IT** and
could not be left behind: callers compare the return value against
the macros and assign them to `sa_handler`, so a mismatched pair is a
diagnostic in every file that mentions them. `_sighdlr[]` holds the
POSIX type now and **the cast lives at the ONE place that calls a
handler**, `_notetramp` -- not at each assignment, or `_envsetup.c`
and `sigwait.c` would each need one and a cast would stop meaning
"something unusual here". The eleven arch `notetramp.c` are
untouched. `sigaction.c` loses four casts that existed only because
nothing had a type to agree with.
**Measured, with a baseline**: `signal.c`, `sigaction.c`, `sigwait.c`
and `_envsetup.c` syntax-checked on the host against staged headers
in the classes 6c treats as fatal -- **1 error before, 1 after, the
same one** -- and `apehdr-sweep` is 149 headers, 0 findings, with the
together-case holding at its recorded 12.
**That surviving error is a REAL pre-existing find, recorded NOT
fixed**: `lib.h` declares `_notehandler(void *, char *)` and
`signal.c` defines it `(Ureg *, char *)`. *Both sides are right* --
the declaration matches `_NOTIFY`, which is Plan 9's own `void *`,
and the definition matches what the body does -- so narrowing the
declaration only moves the mismatch to the `_NOTIFY` call, which is
exactly what happened when I tried it. Whichever side changes, one
needs a cast. The all-HEAD control is what separates it from this
round: HEAD's `signal.c` gives this one error against HEAD's own
headers.
*(The code for this landed in `6c51444e` by a careless `git add -A`,
whose message describes only the `sualign` fix. Recorded here rather
than rewritten, since that commit was already pushed.)*

**AND THE cfront SIZE PROBE WAS `.gitignore'd, SO THE VM NEVER GOT
IT.** `pcc ... cfrontsz-probe.c` answered `Can't open input file` and
`ls cfront*.c` showed only the two stub files. **git is the only
channel to that machine** -- 9front has no python3 -- so an ignored
generated file is a file the VM cannot see. Both generated files are
committed now. *It is not the shape of the forty zero-byte `c++lib`
files*: those were an INPUT to `mk`, which therefore never regenerated
them, while these two appear in nobody's OFILES and mk never compiles
them. The rule is about what reads the file, not about how it was
made.

**SO `apehdr-sweep.py` GAINED A "TOGETHER" CASE, because compiling
each header ALONE cannot see this class at all** -- each file is fine
by itself and only the COMBINATION conflicts. A pairwise sweep is
149x148/2 compiles; including everything in ONE translation unit is
one, and catches the same class. **Its first run reports 12 errors**,
and they are NOT yet triaged, so it prints them and does **not** gate
the exit status: *failing on an untriaged list makes a sweep cry
wolf, and suppressing the list wastes it.* Some are real
(`uname`/`getrusage` was) and some are design intent -- `<regex.h>`
and `<pcre2posix.h>` both define `regex_t` because they are
ALTERNATIVES and no program includes both.
**TRIAGED NOW, AND TWELVE ERRORS ARE SIX CAUSES** -- which is the
whole reason to triage rather than count, and why the raw list sat
unread for rounds. Only TWO of the six are bugs in this tree:
- **`f2c.h` is FIVE of the twelve, on its own.** `#define min/max/abs`
  collide with `<libv.h>`'s `extern int min(int,int)`, and
  `typedef struct {real r,i;} complex` collides with `<complex.h>`'s
  `#define complex _Complex`. *A transpiler's private runtime header,
  installed PUBLIC, owning four names two C standard headers own.*
  **149 files include it and every one is under `external/f2c`** --
  so it does not belong in `sys/include/ape`. Recommendation, not
  done.
- **`regex.h`/`pcre2posix.h` is THREE, and DESIGN INTENT.** pcre2posix
  spells the `REG_*` codes as an ENUM where `regex.h` `#define`s them,
  so `regex.h:44` turns pcre2posix's enumerator into a numeric
  constant -- the `regex_t`/`regmatch_t` pair is the same collision
  seen twice more. *The "numeric constant" error and the two
  conflicting-struct errors were never three findings.*
- **`Plan9libnet.h` is TWO, and the tree ALREADY FIXED IT ONCE.** It
  declares Plan 9's `accept(int, char*)` and `listen(char*, char*)` --
  different functions wearing POSIX's names -- against
  `<sys/socket.h>`. **`libnet.h` beside it is the same interface with
  `net_` prefixes, and is what all five callers in the tree use;
  NOTHING includes `Plan9libnet.h` at all.** *The library holding a
  working version of the thing it got wrong, for the sixth time, and
  the first time it is a HEADER.* Recommendation: delete it -- a
  header that cannot be combined with `<sys/socket.h>` and that
  nothing includes is only a trap. Not done unasked.
- **`bsd.h:47` is ONE, REAL and OURS**: `getopt(int, char**, char*)`
  where POSIX says `(int, char *const *, const char *)` -- and
  **`<unistd.h>` does not declare `getopt` at all**, so this is the
  tree's only declaration and it is the wrong one. Found
  independently by EDG, which is a stricter compiler than gcc.
- **`features.h:55` is ONE, REAL, OURS, AND IT HAS A VICTIM.**
  `#define hidden` is musl's internal visibility macro **in a public
  header**, reached from `<byteswap.h>`, `<endian.h>`, `<ftw.h>`,
  `<glob.h>`, `<iconv.h>` and more -- and `sqlite3.h:10957` declares
  `unsigned char hidden[48];`, **erased wherever `features.h` came
  first.** *A silent struct-layout change in a public API*, which is
  the `-J` hazard arriving from the preprocessor instead of the
  compiler. `weak_alias` beside it is the same shape with no victim
  found yet.
  **The fix needs care and the care is measurable**: libap's own
  `multibyte/internal.c:25` already carries `#ifndef hidden / #define
  hidden`, so private users can supply their own -- but
  `network/lookup.h:46` relies on the leak, which is the
  `<stdio.h>`-leaked-errno shape. Sweep libap before removing it.
*The sweep PRINTS the triage now rather than the raw lines, and still
does not gate -- three of the six are intent.*

**THE TRIAGE IS WORKED NOW: 12 ERRORS -> 8, AND THE EIGHT THAT REMAIN
ARE THE TWO INTENT CASES.** Each drop was measured by re-running the
sweep rather than argued, and each named its own error.
- **`f2c.h`: RECOMMENDATION WITHDRAWN, and the withdrawal is the
  finding.** The installed copy is byte-identical to the build's own
  `external/f2c/lib/f2c.h` **except for two added lines** --
  `#pragma lib "/$M/lib/ape/libf2c.a"` and a blank. *That is the whole
  reason it exists*: a user compiling `f2c`'s output gets libf2c
  linked, which is the APE convention working as designed. The 149
  includers sit beside their own copy and never see this one, so
  *where the includers live was the wrong question* -- diffing the
  INSTALLED copy against the one next door settles it in one command.
  Its five errors join `regex.h`/`pcre2posix.h` as design intent.
- **`Plan9libnet.h`: DELETED, for a better reason than the one
  recorded.** Nothing includes it, and **it shares the include guard
  `__LIBNET_H` with `libnet.h`**, so the two could never be combined
  anyway. What decides it is that two of its three distinctive
  declarations name functions that DO NOT EXIST: there is no Plan 9
  `accept(int, char*)` or `listen(char*, char*)` in libap, only
  POSIX's.
- **AND `libnet.h` -- the one `<sys/socket.h>` ITSELF INCLUDES -- was
  wrong in both directions.** `net_accept`, `net_listen` and
  `net_reject` were declared here and **defined nowhere and called
  nowhere** (grep: zero hits outside the header), so every program
  including `<sys/socket.h>` carried three promises libap cannot keep
  -- failing at the LINK rather than at the call, which is the later
  and worse of the two places. Removed. *The note said `libnet.h` was
  "the same interface that all five callers use" -- they include it
  and call `announce`/`dial`/`hangup`/`netmkaddr`, never the three
  `net_` names.*
  **AND THE OTHER HALF -- DECLARING `reject` -- BROKE THE BUILD AND
  IS REVERTED.** `plan9/announce.c:139` defines
  `reject(int, char*, char*)` and no header named it, so it looked
  like the "capability present and not declared" shape. flex said
  otherwise on the first compile after it:

  ```
    flexdef.h:366 external redeclaration of: reject
        EXTERN INT reject
        EXTERN FUNC(INT, IND CHAR, IND CHAR) INT   libnet.h:36
  ```

  **flex has `extern int reject;` -- a VARIABLE.** And because this
  header is reached from `<sys/socket.h>`, anything it declares is
  surface for every networked program in the tree: **210 files under
  `external/` use the name**, gnulib spelling two PARAMETERS with it
  (`mbsspn(const char*, const char *reject)`, `u8_strcspn`).
  ***MY SWEEP LOOKED FOR `reject(` AND SO COULD NOT MATCH A
  VARIABLE*** -- which is the mistake this file ALREADY RECORDS, from
  the bacon link round: *"four VARIABLES my function-shaped grep
  could not match (`optind`, `opterr`, `optarg`, `stdin`)"*. Same
  error, two sections apart, in the same session. **Sweep for the
  NAME, not for the shape you expect it to have.**
  **The control fires and is a real one**: a translation unit holding
  `#include <sys/socket.h>` and `extern int reject;` gives 0 errors
  against the fixed header and `redeclared as different kind of
  symbol` with the declaration put back -- gcc's wording for exactly
  what 6c printed.
  **And `apehdr-sweep` could not have caught this, which is a limit
  worth stating**: it compiles APE headers against *each other*, and
  `flexdef.h` is a package's own header. *A public header's real
  blast radius is every package in the tree, and no instrument here
  measures that* -- the cheap guard is to grep `external/` for the
  bare word before adding any name to `sys/include/ape`.
  **CONFIRMED ON THE VM: the revert builds.** `mk distclean` plus
  `mk install` completes, so the tree gets past `lex` and the whole
  order after it was reached for the first time since the header
  changed. *That is the weakest useful result and is worth saying so*
  -- it confirms the collision is gone, and the `net_*` removal
  beside it costs no link, which is all a completed build can say.
- **`getopt`: TWO INSTALLED HEADERS DECLARED IT INCOMPATIBLY, and my
  note said there was only one.** `bsd.h:47` had
  `(int, char**, char*)` while **`getopt.h:8` has had POSIX's
  `(int, char * const [], const char *)` all along**. `bsd.h` and the
  definition in `misc/getopt.c` now match `getopt.h`. Callers are
  unaffected: `char **` converts to `char * const *` because the const
  is at the FIRST level of the pointed-to type (C11 6.5.16.1), which
  is why every program everywhere passes `main`'s `argv` to glibc's
  identically-declared getopt.
- **`features.h`: `hidden` AND `weak_alias` ARE OUT OF THE PUBLIC
  HEADER.** `hidden` had the measured victim -- it expands to nothing
  and `sqlite3.h:10957` declares `unsigned char hidden[48];`, erased
  wherever features.h came first. `weak_alias` had no victim and went
  for a different reason, recorded in its own former comment: gnulib's
  `libc-config.h` defines it with no guard, so the two had to agree
  token for token -- `cpp/macro.c`'s `comparetokens()` compares
  PARAMETER NAMES as well as bodies -- and this file's parameter names
  were chosen to match an external package's. *A public macro that is
  only safe because it was spelled like someone else's is safe by
  coincidence.*
  **Sixteen private files gain the `#ifndef hidden` guard and five
  under `network/` the `weak_alias` one**, which is the idiom
  `include/libm.h` and `multibyte/internal.c` ALREADY used -- copy the
  library's own idiom rather than invent a placement. **Nothing
  outside libap needed either**: every external package using
  `weak_alias` ships its own `libc-config.h`, and bash's `lib/intl`
  (the one exception) is not compiled -- `ENABLE_NLS` is undef and the
  `-I` was removed earlier this session.
**The controls**: `apehdr-sweep` 149 -> 148 headers with **0
standalone findings** throughout, together-case **12 -> 10 -> 9 -> 8**
across the three fixes; `apdecl-sweep` 0. And the twelve touched libap
sources give **3 host errors before and the same 3 after** -- a
pre-existing `FILE *const stdin` qualifier mismatch, unrelated. *The
before-and-after pair is what makes that a control rather than a
syntax check.*
**`sys/include/ape/stdio_impl.h` is the SAME SHAPE and is NOT
touched**: musl's internal stdio header, installed public, reached by
six `stdio/*.c`. No victim has been found for it, so it is recorded
rather than moved.

**AND THE SHARED TRANSPILER RULES CARRIED THE `> $target` BUG THAT
`cmd/c++lib` HAD ALREADY PAID FOR.** `sys/src/cmd/transpilers` is
included by `mkone`/`mkmany`/`mklib` for **every** APE package, and
three of its six rules were wrong.
**NOTHING IN THE TREE TRIGGERS IT, which is why.** There is no `.m`,
`.cpp`, `.p` or `.f` outside `external/`, and everything inside is
built by its own package mkfile -- so these were **traps for the next
person** rather than live bugs. *An untriggered rule gets no
diagnostic from anyone*, and the first `.m` added to a package would
have inherited all three faults at once.
- **The C++ rules were `cfront $stem.cpp > $stem.c`, both halves of
  the c++lib bug.** The redirection creates the target whatever the
  command does; and **cfront is one stage of three** -- handed a
  `.cpp` directly it sees unpreprocessed source. `rc/bin/ape/c++` is
  the driver, takes `.cpp/.cxx/.cc/.C` alike, and `-F` is its
  translate-only mode. `c++ -F -o $target` now.
- **`%.c: %.m` was wrong TWICE, and the driver script says so rather
  than any guess.** `rc/bin/ape/objc` defaults to `link=y` and
  `output="a.out"`, so plain `objc foo.m` compiles **and links**; and
  the `foo.c` it writes on the way is the `.m` with a `#line` on the
  front, listed in its own `junk` and **deleted** -- the translated C
  is `foo.i`. *The rule named a target the command removes.*
  Objective C has no honest `%.c:` rule; it stops at the object.
- **`%.c: %.p` could not run at all.** p2c has no built-in output
  name: `codefnfmt` comes from the `p2crc` file and `trans.c:717`
  exits `Unable to find required system p2crc file` without one.
  `-H $PCHOME` finds `/sys/lib/pascal/p2crc`, whose
  `CodeFileName %Rs.c` is what makes `foo.p` answer `foo.c`.
- `CXXFLAGS` and `FFLAGS` were declared and used by nothing. f2c and
  bacon were already right and are unchanged.
**AND `rc/bin/ape/p2cc` HELD A LIVE BUG FOUND ON THE WAY: it passed
`-H --HOMEDIR--`.** Upstream substitutes that token when it INSTALLS
the script (`src/Makefile:113` is a `sed`); APExp installs it by hand,
and `$homedir`, `$incdir` and `$libdir` were filled in while this one
was not. **The guard is what made it reachable rather than
harmless**: it fires precisely when `$homedir/p2crc` EXISTS, so *the
better configured the tree, the more certainly p2cc added the broken
flag*. `perl -c` passes.

**EDG'S FRONT END IS OPEN SOURCE NOW, AND IT IS THE RIGHT SHAPE OF
TOOL -- investigated, not started.** `github.com/edgcpp/compiler`,
**Apache 2.0 with LLVM exceptions**, so the licence is no obstacle.
The three facts that decide feasibility were measured rather than
assumed, by reading the repository:
- **The `.c` files ARE C++14**, which is the confusing part:
  `BUILD.md` says `g++ -std=c++14 *.c`, and EDG keeps the `.c`
  extension from the decades when the front end really was C. Hosts:
  g++ 5.2, clang 3.4, MSVC 2017.
- **`src/c_gen_be.c` is in the tree** -- the C-generating back end,
  which is the whole reason this is interesting: it emits C SOURCE,
  so kencc decides the layout and the ABI rather than inheriting
  someone else's. *That is exactly the problem EDG's C back end was
  built for -- a target with only a C compiler -- which is APExp.*
- **IT DOES NOT USE THE C++ STANDARD LIBRARY**, and that is the one
  that matters. `basic_hdrs.h` includes only EDG's own headers;
  `host_envir.h`'s only system include is `<locale.h>`. *The thing
  that kills every source-to-source C++ bootstrap is the standard
  library*, because libstdc++ is GCC-specific and libc++ needs C++
  to build -- and EDG sidesteps it by never having used one.
**So the bootstrap has a shape**: build EDG on the host with g++,
run EDG's own `c_gen_be` over EDG's own 150 sources, carry the C to
the VM, build it with pcc. **Two risks worth naming before anyone
starts.** (1) `targ_def.h` has to describe kencc: `int` 4, `long`
**4**, pointer **8** -- and that unusual combination is exactly
LLP64, which EDG must already support because it supports MSVC. (2)
whether EDG's C back end handles the C++ subset EDG itself is
written in, which is the classic self-translation question and is
one host afternoon to answer, with no VM.
**AND `llvm-cbe` IS THE WORSE VERSION OF THE SAME IDEA.** LLVM's own
C backend was **removed in 3.1**; the maintained revival is
out-of-tree and converts **LLVM IR**, not C++ source -- so every C++
semantic has already been lowered against one target's data layout
and calling convention, and you would be recompiling x86-64 SysV
decisions with a compiler whose struct layout this tree has just
spent a round on. It also does not remove the runtime question for
ordinary C++ programs. *EDG's back end works at the SOURCE level,
which is the property that makes the layout kencc's to decide.*
**IT BUILDS AND IT TRANSLATES -- MEASURED ON THE HOST, NOT ARGUED.**
`cmake --preset linux-gcc-release` then `ninja` produces **`cpfe`**
(23 MB), and `cmake/macro-conf/default/cpfe.cmakedef` is literally
`BACK_END_IS_C_GEN_BE=1` / `DO_IL_LOWERING=1` -- **the DEFAULT build
is the C-generating one**, which is better than the README promised.
*(I first read `defines.h`, found `BACK_END_IS_C_GEN_BE` set to 1
nowhere, and reported that the release ships the back end with no
configuration. Wrong: the switch arrives as a cmake `-D`, and the
compile line says `-DBACK_END_IS_C_GEN_BE=1`. **Read the command the
build runs, not the header it might have come from** -- the
`config.h`-that-is-shadowed lesson in a new place.)*
**`eccp -S --g++ --sys_include=...` IS THE TRANSLATOR**: a toy with a
virtual base, an override, a template and `new`/`delete` came out as
86 lines of ordinary C -- templates instantiated, inheritance
flattened to `struct Derived { struct Base __b_4Base; }`, dispatch
through a `__vptr`, Itanium-mangled names -- and **`gcc -c` compiled
it with no errors**. Linking needs EDG's OWN runtime (`lib_src/`:
`new`, `delete`, `vtbl`, `static_init`, `pure_virt`, `rtti`), not
libstdc++, which is the whole reason this is tractable.
**Two obstacles named from the output rather than guessed**: the
generated C carries `__attribute__((__weak__))` and
`((__nothrow__))`, which kencc has not and which will need defining
away or an EDG option; and the host's own runtime build stopped on
`-Wno-error=return-mismatch`, a **gcc 14** flag this box's gcc 13
lacks -- *the driver's flag list, not the translation*.
**EDG is compiled `-fno-exceptions -fno-rtti`**, so the front end
itself needs no unwinder -- the self-translation's runtime surface is
smaller than the general case.

**NOT a reason to stop cfront**, and the reason is this tree's own:
cfront is close (the driver works, mk stops at the fault, five files
convert cleanly) and **its crash is currently flushing out kencc and
libap bugs, which is where every large find here has come from**.
EDG would run on the same libap and want the same bugs fixed.

**THAT REASON HAS NOW EXPIRED, AND SAYING SO IS THE POINT.** The
crash was the last kencc bug cfront had to give, and **the HOST
settles that it is the last**: cfront built with gcc, where `long` is
64-bit and the layout is conforming by construction, produces the
diagnostics that remain **character for character** -- the four
`iostream.h:224/228/266/269` redeclarations, `two definitions of
norm()`, `operator delete()'s 2nd argument must be a size_t`,
`placenew.cpp two definitions of operator new()`. *A fault both
compilers reproduce is upstream's, not this tree's.* So cfront has
stopped being a bug-finder for APExp, and the thing to stop is
**spending rounds on it**, not the directory.
**AND IT IS GONE NOW -- THE USER REMOVED IT, AND EVERY ONE OF THE
THREE REASONS FOR KEEPING IT HAD EXPIRED BY THEN.** The paragraph
here used to argue (1) the `-9`/`-J` pair was the only end-to-end
layout instrument, (2) `cfrontsz-probe.py` read cfront's generated C
for its 97 struct sizes, and (3) the EDG path would want the same
`c++` driver, `ns_strip`, `<values.h>` and c++lib mkfile. *Each was
true when written and none survived the round that followed*:
`structalign-test` now asserts both bit-field rules over nine shapes
plus the two straddles, `edgscope-probe` and `edgtuoff-probe` measure
EDG's own structs, and the EDG driver turned out to want **none** of
cfront's four -- `eccp` is its own pipeline, `ns_strip` has no
counterpart, and `<values.h>` was always needed by perl, p2c and
Devel-PPPort rather than by cfront.
**What went with it, swept rather than recalled**: `cmd/cfront`,
`cmd/c++lib`, the seventeen pre-standard headers in
`sys/include/ape/c++`, `cfrontsz-probe.py` (its input `main.c` is no
longer tracked, so it could not run), and **two committed
x86-64 Linux ELF binaries under `external/cfront-C4`** -- the host
ASAN build, unstripped, in a Plan 9 tree. *Those two were the only
tracked files left in that directory*, so a `git ls-files` is what
found them where a `ls` would have shown forty untracked `.c` and
hidden them.
**And what did NOT go, deliberately: the PROSE.** `pcc.c`,
`cmd/itclsh/mkfile`, `plan9/callmain.c`, `apeabi-probe.c`,
`initzero-test.c` and `structalign-test.c` all still name cfront in
comments, because each is explaining *why the code is as it is* --
`pcc.c`'s is the reason `-J` is unconditional rather than inside the
`if(!Aflag)` block, which is still the reason. *A comment recording
why a decision was made does not become false when its subject is
removed; rewriting it erases the only evidence for the decision.*

**`_OPTIONAL_APPS' AS IT STANDS, re-read rather than recalled**: `go'
and `clisp' are the only two commented out, and `basic', `muon',
`perl' and `edg' are all live -- each of the last two after it had
actually built. **`cfront' and `c++lib' are not commented out, they
are GONE**: no entry, no directory, nothing tracked. *This paragraph
has been stale twice now, both times by naming a state the mkfile had
moved past* -- `grep -n 'optional' sys/src/ape/cmd/mkfile' and reading
the list is the one command that settles it, and line numbers go stale
faster than names, so none are quoted here any more.
*The reason for caution is unchanged and is worth keeping beside the
fact*: one failing entry aborts the whole tree's `mk', so anything
newly enabled is a thing the next full rebuild can stop on, and a port
that has only been built by hand has not been measured in that
position. **The first rebuild after the compound-literal and bit-field
work proved it three times in one run** -- see the section of that name
below.

## The first full rebuild after the compound-literal and bit-field work

**THREE PACKAGES STOPPED IT AND THE DISTCLEAN NEVER FINISHED, which is
one fact about the other two.** `mk clean` and `mk distclean` both hung
**in clisp**, and only then did `mk install` run -- so the tree that
was built was a MIXTURE of objects from before and after a LAYOUT
CHANGE. That is the silent ABI split this file has a rule for, and it
is the reading the next run has to rule out before anything else is
blamed.
- **clisp, FIXED twice over.** `mkfile.rebuild` answered `token '='`
  again with the only `=` left inside a recipe COMMENT -- see the `=`
  rule above and `sys/lib/tests/mkrecipe-probe`. And the hang is its
  own bug: `clean`/`nuke` in `mkfile.runtime` were
  `$BIN/make -C $BUILD clean`, so a tree-wide clean drove a
  300-Makefile autoconf build that can reconfigure, can prompt and can
  wait for ever -- **and mk propagates the failure up through every
  enclosing directory, so one hung package takes the whole tree's clean
  with it.** *That is `cmd2/vts/test` in a new spelling.* Both are
  `rm -rf $BUILD` now: `$BUILD` is build output in full, so removing it
  cannot hang and the cost is a reconfigure.
- **go, FIXED TWICE and still not built**: `CC=pcc -c`, then the
  Makefile backslashes in `-DGOROOT_FINAL`. See the go entry below.
- **AND clisp's `configure` RUNS NOW AND ITS LOG DESCRIPTOR IS GONE.**
  Both mkfile parses are past, `comment5`/`gctrigger`/`varbrace` build,
  all 130-odd `.d` files generate, and `configure` reaches
  `checking whether the C compiler works... no`. **But between those
  lines it printed `configure: line NNNN: 5: Bad file descriptor`
  hundreds of times**, and autoconf keeps `config.log` on **fd 5**
  (`exec 5>>config.log`, then `echo ... >&5` for everything after). So
  the compiler verdict at the end is the verdict of a configure that
  could not write its own log, which is not a statement about pcc.
  *`sh: warning: process exceeds 100/200 file descriptors` sits two
  lines above the first one*, which is bash's `move_to_high_fd` and has
  already been measured harmless once -- so it is a neighbour, not yet
  a cause. **`sys/lib/tests/execfd-test.sh` asks it**, and section 5 is
  `run-redir`'s own `exec 6<>` line, so the recorded unexplained hunk
  and this were one question.
  **MEASURED: 0 FAILURES, ALL EIGHT SECTIONS, ON 9front.** `exec 5>`,
  `exec 5>>`, the reopened number, `exec 200>`, `exec 6<>` and a
  subshell writing the parent's descriptor all work. **So the
  CONSTRUCT is not the bug** -- and `redir.tests:83` is cleared with
  it, which answers the recorded "if it comes back it is flaky" in the
  good direction rather than leaving a third story.
  *That makes the clisp question sharper rather than closing it*, and
  the difference is what the test did NOT reproduce: **every section
  ran in a shell that had just started.** configure's failure arrives
  thousands of lines in, it forks hundreds of children, and -- the
  thing a reading of the construct cannot reach -- **autoconf's own
  first act is `exec $CONFIG_SHELL "$as_myself"`, replacing its own
  process image while `exec 5>>config.log` is meant to stay open
  across it.** `/env/_fdinfo` is the only thing that carries
  per-descriptor state over an APE exec, and *a descriptor has already
  arrived poisoned through exactly that file once in this tree*.
  Sections 8, 9 and 10 ask those three (fork+exec, self re-exec,
  scale) and 10 reports the ITERATION it first fails at, since "it
  broke at 140" and "it never worked" are different findings. Also
  worth noting from the same screen: **the fd warnings fired and every
  section still passed**, which is the third independent confirmation
  that they are noise.
  **AND THE PLAN IS TO STOP RUNNING configure AT ALL**, which is the
  user's call and matches what this tree already does for perl and
  bash: a hand-answered `config.h` plus an mkfile, rather than an
  autoconf run and a 300-Makefile GNU make build driven from inside
  `mk`. *The honest size of that: `lisp.run` is the tractable half and
  a native mkfile for it answers "does kencc build clisp"; the memory
  image is a second half, since CLISP compiles its own Lisp sources
  with the interpreter it has just built.* Not started.
  **AND THE RE-RUN CONFIRMS THE READING WHILE CLEARING THE CONSTRUCT,
  which is what makes this a DEFERRAL rather than an open bug.**
  `configure` now reaches `checking whether the C compiler works...
  no`, with `5: Bad file descriptor` on hundreds of lines around it and
  `configure: error: C compiler cannot create executables` at the end
  -- *the verdict of a configure that could not write its own log, and
  not a statement about `pcc`*. **`execfd-test.sh` is 0 failures across
  all eleven sections on 9front**, sections 8, 9 and 10 included: a
  child that forks AND execs, the shell **re-execing itself** (which is
  autoconf's own first act), and fd 5 held across 300 forks with
  `first bad write: 0`. *So the fd mechanism is cleared and what is
  left is scale inside a 300-Makefile build* -- which makes the
  autoconf route harder to diagnose, not easier, and is the argument
  for the hand-answered `config.h` rather than against it.
  **OUT OF THE DEFAULT BUILD FOR 0.6 and documented in the release
  notes as such**, with go. *The user's call, and the right one: it is
  its own release.*
- **perl, OPEN -- AND THE NEXT RUN NARROWED IT RATHER THAN MOVING IT.** `miniperl` links and then faults running
  `writemain("perlmain.c")`: `suicide: sys: trap: fault write
  addr=0x3000000f0 pc=0x22e50f`. **`0x3000000f0` is high half 3, low
  half 0xf0** -- an eight-byte slot assembled from two four-byte ones,
  which is what a MOVED STRUCT OFFSET looks like from outside, and this
  tree has seen that shape twice before.
  **Two readings, and they need different next steps.** (a) The
  half-cleaned tree: `libperl.a` holds objects from before the
  `sualign()` bit-field change and `miniperl` was linked after it.
  (b) The change itself: **perl's `struct op` is exactly the shape that
  moves** -- `PERL_BITFIELD16 op_type:9` and seven more, then
  `U8 op_flags; U8 op_private;`, which now share the container's tail.
  *`bfmove-sweep` did not report it and the reason is the sweep's, not
  perl's* -- see its UNKNOWN column above.
  **(a) is cheap and must go first**: with clisp's clean fixed, a
  COMPLETE `mk distclean` followed by `mk install` either fixes perl or
  does not, and either answer is worth more than a reading. **If it
  faults again at the same pc**, the bit-field change is implicated and
  `structalign-test`'s three runs and the `apeabi-probe` acid diff --
  both written down before any of this and both still unrun -- are what
  price it.
  *A `sys:` trap leaves the process Broken and readable*, so `acid`
  plus `lstk()` on the faulting miniperl names the member either way.
  Until it builds, `perl` has to stay commented out of
  `_OPTIONAL_APPS` or it aborts the whole tree's `mk` -- the reason
  `edg` and `c++lib` are out.
  **THE SECOND RUN WAS `mk clean; mk install` IN `cmd/perl` ALONE, AND
  THAT IS READING (a) RATHER THAN REFUTING IT.** `libperl.a` is built
  in **`sys/src/ape/lib/perl`**, which that clean never touched, so
  `op.c`, `perl.c` and `universal.c` were recompiled with the new
  bit-field rule and the other fifty-odd objects were not. *Both halves
  of miniperl handle `OP *`.*
  **The arithmetic says how far apart they are.** `BASEOP` is three
  pointers and a `PADOFFSET`, so the bit-field container lands at 28;
  under the old rule `op_flags` is at 32 and `op_private` at 33 with
  `sizeof(OP)` **40**, under the new one they are at 30 and 31 with
  `sizeof(OP)` **32**. perl allocates ops out of its own slabs by that
  size and walks them with it, so one half writing a 40-byte op into a
  32-byte slot at the end of a slab is a write a few bytes past the
  arena -- which is the shape of `fault write addr=0x2ffffff0`, a
  heap-top address rather than a wild pointer. *The first run's
  `0x3000000f0` and this one's `0x2ffffff0` are the same neighbourhood,
  which a random corruption would not be.*
  **So the next run is `cd sys/src/ape/lib/perl && mk clean && mk
  install` BEFORE `cmd/perl`** -- or, now that clisp's clean no longer
  hangs, a complete `mk distclean`. **Predict: miniperl writes
  `perlmain.c` and perl links.** *Refuted if it faults again at the
  same `pc`*, and that would move the bit-field change itself into
  frame, where `structalign-test`'s three runs and the `apeabi-probe`
  acid diff -- both still unrun -- are what price it.
  **CONFIRMED: THE WHOLE TREE BUILT WITHOUT INTERRUPTION AND perl
  WORKS.** With the clean reaching every directory, `miniperl` writes
  `perlmain.c`, perl links and runs. *The prediction was written down
  before the run and the refutation condition did not fire*, so
  reading (a) stands and reading (b) is out: **the `sualign()`
  bit-field change is not implicated**.
  **AND THAT IS THE FIRST BEHAVIOURAL EVIDENCE THE BIT-FIELD CHANGE
  HAS, which is worth more than the absence of a crash.** perl's
  `struct op` is the shape that moves -- `sizeof(OP)` 40 -> 32 -- so a
  perl built entirely under the new rule, running its own module
  loader and generating its own `perlmain.c`, is a program exercising
  the moved struct rather than merely linking against it. *Weak, and
  weak is what a layout change can get from a build*: every symbol
  resolves either way, so this says the tree is SELF-CONSISTENT and
  nothing more. `structalign-test`'s three runs and the `apeabi-probe`
  acid diff still price the change BY NAME and are still unrun -- they
  are no longer blocking anything, and the `-9` count of **21** and
  the `__res_state` numbers (`unused` 368 -> 365, `sort_list` 372 ->
  368, `sizeof` 456 -> 448) are still the written-down predictions
  waiting for a run.
  **`perl` is LIVE in `_OPTIONAL_APPS` again**, which means the next
  tree-wide `mk` is the first that builds it IN THAT POSITION -- the
  recorded caution, since a package built by hand has not been
  measured there.

- **edg, AND IT IS THE ONE GOOD NEWS OF THE ROUND**: `lib/edg` and
  `cmd/edg` both build and `cpfe` runs. **No functional test yet**, so
  read it as "it builds and starts" rather than as a port -- the thing
  that would say anything is a translation whose output `pcc -c`
  accepts, and `--target win64` with the `0x68` fault is where that
  stopped.
  **BUILT TWICE NOW, so it is LIVE**: `edg` in `cmd/mkfile`'s
  transpilers and `edg` in `lib/mkfile`'s `_OPTIONAL_LIBS` -- *lib
  before cmd, because `cmd/edg`'s link line names `libedg.a` and the
  tree walks lib first.* It was out under the "by hand first" rule and
  has now been built by hand twice; that rule is satisfied, not
  waived.
- **AND THE TREE BUILDS WITHOUT INTERRUPTION.** That is the first
  complete run since the compound-literal and bit-field work, and the
  thing it settles is the one a build can settle: nothing in the tree
  fails to compile or link under the new layout rule. **go and clisp
  are the only two still out.**


---

## muon, go, chicken, bacon, the archivers, and what was queued

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

- **muon** -- **IT BUILDS AND IT RUNS. Read the rest of this entry as
  the record of how, not as an open problem.** It crashed before it
  read an argument, the cause was a kencc bug rather than muon's, and
  the fix is `clitzero()` in `cc/dcl.c`; the confirmation is at the
  end.
  **IT CRASHED BEFORE IT READ AN ARGUMENT, AND THE STACK NAMED ONE
  STRUCT MEMBER.** `fault write
  addr=0x7ffffff000` with `lstk()` giving `memset(c=0x0, n=0x29afb0)` <-
  `tstr_clear` <- `path_basename` <- `main.c:1447`. **That memset is
  2,731,952 bytes over a 1024-byte stack buffer**, and `tstr_clear` is
  two statements -- `memset(sb->buf, 0, sb->len)` and `sb->len = 0`. So
  `buf` was RIGHT (the memset reached a real address and walked off the
  top of the stack rather than faulting at once) and exactly one member
  is wrong: **`len`**.
  **AND `len` IS THE ONE MEMBER C REQUIRES TO BE ZEROED.**
  `tstr_init` (`src/lang/string.c:841`) ends `*sb = (struct tstr){
  .flags = flags, .buf = initial_buffer, .cap = initial_buffer_cap };`
  -- **`.len` and `.s` are OMITTED**, and C99 6.7.8p21 says an omitted
  member is initialised as one with static storage duration would be.
  *A compiler that writes only the named members into the destination
  leaves `len` holding whatever was there*, which is the whole symptom
  with nothing left over.
  **`initzero-test.c` is the instrument, and NEITHER EXISTING TEST
  COULD HAVE CAUGHT THIS.** `compound-literal-test` asks whether a
  literal can be addressed, passed and written through -- every check
  names a member it also initialises; `designated-init-test` asks which
  member a DESIGNATOR lands on. **Neither asks about the GAPS, and
  neither assigns a literal THROUGH A POINTER**, which is muon's form.
  *Correctness and completeness again, the 47-of-97 lesson.*
  **Its storage is DIRTIED with 0xAA first and section 0 checks that
  the poison arrived**, because a compiler that writes only the named
  members passes every check here against a zero destination -- and a
  fresh frame usually is one. 0 failures on gcc; the broken behaviour
  replicated beside it gives **3, naming exactly 1a, 1b and 7** and
  printing a length of `0xAAAAAAAA`, the same shape as the VM's
  `0x29afb0`.
  **MEASURED: 6 FAILURES UNDER pcc, 0 UNDER gcc -- muon's crash is
  kencc's, and it is ONE MISSING CALL IN `cc/dcl.c`.**
  `compoundlit()` lowers a literal to a hidden auto (`adecl(CAUTO,...)`)
  and calls `doinit()`, which assigns only the members the list names.
  **`cc.y`'s `adlist` -- an ordinary `T x = {...}` -- is `doinit()`
  FOLLOWED BY `contig()`**, and `contig()` is exactly "zero every byte
  the initialiser did not cover". *`compoundlit()` was the one caller of
  `doinit()` in the compiler that never had the second half*, which is
  why no ordinary C in this tree ever tripped over it.
  **THE PATTERN WAS THE DIAGNOSIS, NOT THE COUNT.** `.len` was garbage
  and `.s` zero through a POINTER, and the other way round into a LOCAL
  -- the same two gaps of the same struct, in one program -- and section
  6b's array literal passed outright. *A compiler that simply never
  zeroed would have failed uniformly; this is an uninitialised slot.*
  And **section 5, a DECLARATION, passed for a real reason** rather than
  by luck: it goes through `adlist`, so it has always had `contig()`.
  *The asymmetry between the two productions is the whole bug.*
  **`contig()` COULD NOT SIMPLY BE CALLED, which is the one subtlety.**
  Its bulk arm emits an **`ODWHILE`** -- a STATEMENT -- and everything
  `compoundlit()` builds has to survive `cgen()` in EXPRESSION context,
  since the literal's value is an operand. `clitzero()` reuses contig's
  front and back trims verbatim and spells the loop out as straight-line
  stores; the cost is one store per uncovered pointer-sized word, which
  is linear and is recorded rather than capped. **It must run BEFORE the
  existing `OLIST`->`OCOMMA` flattening**: `covered1()` descends OLIST
  and OASI and nothing else, so against an OCOMMA tree every member
  would read as uncovered and be zeroed on top of its own initialiser.
  **Zeroing a partially-covered word is correct and deliberate** --
  `initz()` prepends, so every zero store runs before the member stores,
  which is the same ordering `contig()` already relies on.
  **`clitzero-model.py` is the instrument** and extracts the real
  function from `dcl.c` rather than restating it, because the first
  build of any `cc/` change is the VM's. Six layouts by seven FRAME
  OFFSETS -- *`v` is negative, so every `%` in that function is a
  negative modulo and one sign error writes zeros over a neighbouring
  local*. **It has no external oracle** the way `sualign-model` has the
  acid dump, so **its control is a deliberate break**: a copy with the
  tail loop removed must report a gap, and it does. All cases ok, and a
  fully-covered literal costs no stores at all, so `(int){i}` and
  `&(T){...}` keep their `addable` path.
  **CONFIRMED ON THE VM: 6 FAILURES -> 0, every section PASS.** The
  six that moved are exactly the six that failed -- 1a, 2b, 3a, 4a,
  6a and 7 -- while 1b, 2a and 6b, which had passed by luck, still
  pass. *A blanket fix and a correct one look different here*: had
  `clitzero()` zeroed too much it would have broken 1c, 3b and 4b,
  which assert that the NAMED members survive, and they did not move.
  **And that run is also the first build of every pending `cc/`
  change**, `sualign()`'s six lines included -- so the compiler
  compiles and produces a working compiler, which is the weakest
  useful result for a front-end change and the precondition for the
  rest of the order.
  **AND muon RUNS -- the behavioural confirmation, end to end.**
  Rebuilt with the fixed compiler it reaches its own dispatcher and
  prints its own usage: `muon` alone answers `error missing command`,
  `muon -h` lists `analyze devenv fmt install internal options samu
  setup subprojects test version`. *No `fault write addr=0x7ffffff000`
  anywhere* -- the memset that walked off the top of the stack is
  gone, because `tstr_init`'s `.len` is now the zero C always said it
  was. **The chain is measured end to end rather than argued**:
  `lstk()` named the member, `initzero-test` reproduced it, `cc/dcl.c`
  explained why only compound literals had it, and the program that
  crashed now runs.
  **`muon --help` answering `illegal option -- -` is NOT ours**: muon
  has no long options -- its own usage lists `-h` -- and `--help` is
  not the bare `--` that ends an option list, so POSIX getopt parses
  it as the option character `-`. glibc prints the same thing.
  **The `[31m`/`[0m` printed literally is rio**, not a bug: muon
  colours its diagnostics and rio speaks no escape sequences. Under
  `vts` it renders, which is one of the three things vts was for.
  **It is LIVE in `_OPTIONAL_APPS`, not commented out** -- this file
  said otherwise and was stale; so is `basic`, which is live too.
  Off now: **`c++lib`, `go` and `clisp`**. `perl` and `edg` went back
  in once each had built: perl after a COMPLETE clean, edg after two
  by-hand builds.
  **What is NOT measured is muon doing any WORK**: printing a usage
  exercises argument handling and one `tstr`. *A port that builds and
  prints its usage is not a port either* -- `muon setup` on a real
  `meson.build` is the next thing that would say anything.
  *The gcc sweep over the files muon builds was 0 errors in the classes
  6c treats as fatal, and it has no 32-bit-`long` assumptions, so both
  cheap classes were clean and this needed the crash.*
- **go** -- **IT STOPPED ON THE FIRST FILE, AND `bool` IS A KEYWORD
  HERE.** `a.h:5 syntax error, last name: bool` compiling `arm.c`:
  `dist`'s own `typedef int bool;`, against `cc/lex.c:1751`'s
  `"bool", LBOOL, 0` -- **unconditional in `itab`, so `bool` is a
  keyword in every kencc dialect**, native and APE alike. C23 says the
  same, so go1.4 is simply pre-C23 and `gcc -std=c2x` refuses the line
  too. *This is the opposite of the recorded `syntax error, last name:
  bool`, which was stock 9front's `6c` not knowing the word.*
  **THE CLASS IS BOUNDED AND go IS ALONE IN IT.** Five
  `typedef ... bool;` in `external/` and the other four -- bash,
  PDCursesMod, curl, libzip -- are already behind `HAVE_C_BOOL`,
  `__bool_true_false_are_defined`, `HAVE_STDBOOL_H` and `__hpux`.
  go1.4's had no guard at all. *Sizing the class before fixing the
  instance cost one command.*
  **The capability is DECLARED by the build** (`-DHAVE_C_BOOL` in
  `cmd/go/mkfile.bootstrap`, bash's own spelling) rather than sniffed
  from a kencc predefine: keying it on `__APEXP_CONFORMALIGN__` would
  tie `bool` to the struct-layout flag and take the typedef back under
  `pcc -9`. Nothing in dist stores a non-boolean in one -- every
  bool-returning function returns 0, 1 or a comparison, swept first.
  **Host control, in the dialect that reproduces kencc**:
  `gcc -std=c2x -fsyntax-only` over the nine portable files is
  **7 errors before and 0 after**. `plan9.c` needs Plan 9's `u.h` and
  is only measurable on the VM, and what stage two then does is beyond
  the host entirely.
  `go1.4` is still the only thing that mentions `Ureg` outside libap.
  **AND THE NEXT WALL ARRIVED IMMEDIATELY, WHICH IS THE `bool` FIX
  DOING ITS JOB: `CC=pcc` WITH NO `-c`.** With `a.h` compiling, `arm.c`
  answered **`_apemain: undefined: main in _apemain`** -- a LINK error
  on a file that has no `main` and never should. `pcc` without `-c`
  compiles AND LINKS (`pcc.c`'s `if(!cflag)` arm), and `mkone`'s own
  `%.$O: %.c` rule is `$CC $CFLAGS $stem.c` with no `-c` of its own, so
  the flag has to arrive through `CC` or `CFLAGS` and
  `mkfile.bootstrap` had it in neither. **Every other APE package in
  the tree says `CC=pcc -c`** (`cmd/tar/mkfile:79`,
  `cmd/core/mkfile:206`) or puts `-c` first in CFLAGS
  (`cmd/muon/mkfile:165`); this one said plain `pcc`. *The message is
  about the second half of a command whose first half worked*, which is
  why it reads like a missing symbol in libap. One word.
  *A fix that makes a process reach code it never reached before can
  expose anything on that path* -- for the third time, and here the
  thing exposed was one line of the mkfile that had never run.
  **AND THE WALL AFTER THAT WAS THE SAME MKFILE LINE'S OTHER HALF: THE
  BACKSLASHES IN `-DGOROOT_FINAL=\\"...\\"`.** With `-c` in place `arm.c`
  and `buf.c` compiled and `build.c` answered
  **`build.c:21[stdin:207] syntax error, last name: goroot`** -- which
  is `char *goroot = GOROOT_FINAL;`, a C syntax error two files on,
  naming the VARIABLE rather than the flag that broke it. cpp had
  defined the macro as `\"...\"`, backslash and quote, which is not a
  string literal. *Those backslashes are a MAKEFILE idiom.* **mk gives
  double quotes no meaning and passes them through** -- the mechanism
  `cmd/c++lib`'s `CLEANFILES= "*.c"` paid a round for, from the other
  side -- and rc never re-lexes the CONTENTS of an expanded variable,
  which is the same fact that makes every `-DFOO=1` safe through
  `$CFLAGS` and a literal `=` in a recipe fatal. So a plain `"` reaches
  cpp exactly as written and no escape was ever wanted.
  **Three walls in three rounds, each one file further in**, and every
  one of them in this mkfile rather than in go: the `bool` keyword, the
  missing `-c`, the Makefile escaping. *That is what a port that has
  never run looks like from outside.*
  **AND THE FOURTH IS STRUCTURAL RATHER THAN ONE MORE LINE:
  `plan9.c:13 Could not find include file <libc.h>`.** `cmd/dist`
  compiles **all three** portability files and lets `-DPLAN9` pick one,
  so `plan9.c` is live -- 764 lines of native Plan 9 on `<u.h>` and
  `<libc.h>` -- under a compiler that has neither. **The portable arm
  is already written and already satisfied**: `unix.c` is 843 lines of
  POSIX behind `#ifndef WIN32 / #ifndef PLAN9`, and all nine of its
  includes exist in this tree (`unistd.h`, `dirent.h`, `sys/stat.h`,
  `sys/wait.h`, `sys/param.h`, `sys/utsname.h`, `fcntl.h`, `setjmp.h`,
  `signal.h` -- checked, not assumed). *It is simply switched off.*
  **THE MACRO IS DOING TWO UNRELATED JOBS AND ONLY ONE OF THEM IS
  WRONG.** At COMPILE time `-DPLAN9` chooses the portability file; at
  RUN time `build.c` compares `gohostos` against `"plan9"` in six
  places, including `:968` where dist EMITS `-DPLAN9` for the stage-2
  toolchain. *Which C we build dist from* and *which OS dist is
  building for* are different claims, and the port conflates them --
  which is why dropping the flag is not free. `unix.c:670` is a
  **compile-time `#elif` chain** ending in `fatal("unknown operating
  system")` with no plan9 arm, so the change is one `#elif` giving
  `gohostos = "plan9"` plus a new `-D` in place of `-DPLAN9`, declared
  by the build the way `-DHAVE_C_BOOL` already is. *(Keying it on
  `uname()` would not work either: libap answers sysname `Plan9` and
  that chain never reads it.)*
  **Building under `sys/src/cmd` with native `6c` is the other option
  and buys nothing**: it would make stage 1 compile, and dist's whole
  job is to drive stage 2, which is a separate question from where
  dist itself lives. **NOT STARTED, and out of the default build for
  0.6.**

**Ports built but never exercised**, which is a different and cheaper
item -- *a port that builds and has never run is not a port*:
- **chicken** (Scheme) -- **IT CRASHED THE FIRST TIME A SCHEME PROGRAM
  WAS RUN, AND THE CAUSE IS TWO LINES OF `chicken.h`.**
  `chicken compiler-test.scm` answers
  `suicide: sys: trap: fault read addr=0xfffffffffffefa6`.
  `chicken.h:81` sets `C_SIXTY_FOUR` from
  `__LP64__`/`_LP64`/`__MINGW64__`/`_WIN64`; **kencc on amd64 is LLP64**
  and that list names LP64 plus the two WINDOWS LLP64 spellings, and
  kencc predefines only `__STDC__`, `_POSIX_SOURCE` and the two
  `__APEXP_*` markers -- so it was never set. **`C_LLP`, which both
  mkfiles already passed, is read for the word size only INSIDE
  `#ifdef C_SIXTY_FOUR`** (`:515`), so it was inert and the `#else` arm
  ran: **`C_word` was `int`, 32 bits, on a machine with 64-bit
  pointers**, in the type CHICKEN stores pointers in.
  **The state is one upstream cannot produce**: it sets `C_LLP` only
  for `__MINGW64__`/`_WIN64`, both of which are also in the
  `C_SIXTY_FOUR` list, so its LLP64 targets always get both. Passing
  `C_LLP` alone gave a MIXED build -- `C_long` was `long long` and
  `C_strtow` was `strtoll`, both read outside the block, while
  `C_word` stayed 32-bit. *Half the configuration took and half did
  not.*
  **AND `-DC_SIXTY_FOUR` ALONE DOES NOT COMPILE, which the gcc check
  caught before it shipped.** `C_header` is `C_uword` is
  `unsigned C_word`, and under `C_LLP` `C_word` is `C_s64` -- the
  keyword-ish `__int64` only on MinGW. Everywhere else it is the
  TYPEDEF `int64_t`, and `unsigned int64_t` is not C: eight errors
  inside `chicken.h`, the first on `C_SCHEME_BLOCK` at `:755`, **none
  of them naming the cause**. `C_uword` is `C_u64` under
  `C_SIXTY_FOUR && C_LLP` now, which needs no new macro and is the
  same `unsigned __int64` on MinGW. `C_uchar`, `C_uhword` and
  `C_ulong` beside it were checked and are all `unsigned <keyword>`.
  **`chickenword-probe.c` is the instrument and THE HOST RUNS BOTH
  SIDES**, so this cost no VM round: `-U__LP64__ -U_LP64` reproduces
  kencc's configuration exactly. Fixed: `C_word` 8, 0 failures.
  Shipped: `C_SIXTY_FOUR NOT defined`, `C_word` 4, pointer 8, 1
  failure, exit 1.
  **AND THE VM RAN THE CONTROL RATHER THAN THE TEST, which is the
  file's own design working.** Built bare -- without chicken's own
  `-DC_SIXTY_FOUR -DC_LLP` -- it answers `C_SIXTY_FOUR NOT defined`,
  `model LLP64`, `C_word` 4, pointer 8, **1 failure**: exactly the
  shipped configuration the header says must fail. *A probe built
  without the package's flags measures a different header*, which is
  `tarblock-probe`'s rule, and here that is the documented control
  rather than a fault. **Both mkfiles do pass the two flags** (`cmd`
  :75, `lib` :79), so the port itself is fixed; the flagged run is
  what remains.
  Recorded not patched: `chicken.h:813-815` define `C_WORD_MIN`/
  `C_WORD_MAX`/`C_UWORD_MAX` as the LONG limits with no `C_LLP` arm,
  so they would be 32-bit limits for a 64-bit word -- **defined and
  never used, zero uses in the tree**, and upstream carries the same
  latent bug on MinGW64.
  **AND TURNING `C_SIXTY_FOUR` ON EXPOSED A KENCC BUG RATHER THAN A
  CHICKEN ONE: A SINGLE `L` CAPPED A CONSTANT'S WIDTH.** The rebuild
  answered `runtime.c:12525 duplicate cases in switch 0` eight times,
  **and the value in that message is the evidence** -- not a collision
  between two numbers, every label in both of `decode_literal2`'s
  switches had become **0**. `chicken.h` spells its fourteen header
  tags `0x0n00000000000000L`, one `L`, correct on any LP64 system;
  `cc/lex.c`'s widening path was guarded by `(c1 & Numlong) == 0`, so
  it ran only for constants with NO suffix, and `convvtox(vv, TLONG)`
  threw away every significant bit of all fourteen. **C99 6.4.4.1 says
  the opposite**: an `l`/`L` constant takes the first of long,
  unsigned long, long long, unsigned long long *in which its value can
  be represented* -- **`L` is a floor on the type, not a ceiling.**
  Guard removed; the threshold is the same `w` as for an unsuffixed
  constant, since `long` and `int` are both 32 bits here.
  *This is not a chicken fix: it is every LP64 upstream header in the
  tree that writes a 64-bit constant with one L*, which is the normal
  spelling there, and kencc has been truncating all of them with a
  warning nobody reads in a 2000-line header.
  **`longconst-test.c` is the regression test and its SECTION 3 is the
  control**: `0x80000000L` must stay 32 bits, because unsigned long
  can represent it -- a patch that widened on the first `L` passes
  sections 1 and 2 and fails there. 0 failures on gcc, **and the gcc
  run says only that the test is written correctly**: the host's
  `long` is 64 bits, so sections 1 and 2 are true there because
  nothing overflows. Section 0 prints `sizeof(long)` so the two runs
  tell themselves apart. *Not compiled anywhere yet -- kencc needs
  Plan 9's `<u.h>`/`<libc.h>`, so the first build is the VM's.*
  **AND THE REBUILD HALVED IT -- 8 ERRORS -> 4 -- WHICH NAMED A
  SECOND, UNRELATED KENCC BUG UNDERNEATH.** The four that went were
  `runtime.c:12578`, the switch on 64-bit `bits`: that is the
  `L`-suffix fix confirmed exactly where it was predicted. The four
  that REMAIN are `12525`, the switch on a plain `int`, and they were
  never the suffix at all -- *the same four were there before, and
  reading 8 as one cause would have been wrong.* `cc/pswt.c` has two
  defects, and **only the second is audible**:
  - **A 64-bit case TYPE is not a 64-bit case VALUE.** `pgen.c:342`
    sets a case's `isv` from `typev[type]` alone, and `doswit`
    DISCARDED every such case in a switch whose expression is 32 bits,
    under the comment *"can never match"* -- a sentence about a VALUE
    too wide to appear, applied to a small number with a wide type.
    `chicken.h` writes every immediate as
    `((C_word)(C_SPECIAL_BITS | 0x10))` and `C_word` is 64 bits here,
    so **four of `decode_literal2`'s eight labels are 0x0e/0x1e/0x3e/
    0x4e wearing `int64_t`** and would have fallen to `default` at run
    time. *Silent: the file compiles.*
  - **`nc` was counted BEFORE that loop dropped anything, and
    `alloc()` is a hunk bump allocator that does not zero.** So
    `qsort` and the duplicate scan ran over `nc` entries of which the
    last few were never written and compared those against each other
    -- `duplicate cases in switch 0`, **naming a case the program does
    not contain**. Five dropped labels, four reports: *the count in
    the message is the arithmetic of the bug.*
  **C 6.8.4.2p5 decides the fix and gcc confirmed it in one command**:
  a label "is converted to the promoted type of the controlling
  expression", so a wide label is **truncated**, not discarded --
  `case 0x100000001LL:` in a switch on an `int` is reached by **1**,
  and a label that truncates onto another is a real duplicate. The
  `(long)` cast already performed that conversion, so the fix is the
  deletion of the drop plus `nc = q - iq`.
  ***MY FIRST FIX AND MY FIRST TEST WERE BOTH THE OTHER RULE***
  -- "drop only what does not survive truncation" -- and gcc REFUSED
  TO COMPILE the test that asserted it, because `case 0x100000000LL:`
  truncates onto `case 0:`. *Checking against the host first changed
  what the fix should be, not just whether the test was right.*
  **`switchcase-test.c` is the regression test and its SECTION 2 is
  the one that matters**: a compiler with only the loud half fixed
  compiles cleanly and selects the wrong arm, so the error going away
  is not evidence -- only asking which arm ran separates them.
  Section 1 is the loud half, since the file not building is its own
  answer. 0 failures on gcc, where `long` is 64 bits so neither bug
  can arise -- *the host says the test is written correctly and
  nothing more.*
  **Watch the first full rebuild**: a 64-bit-typed label that
  truncates onto another one used to be dropped silently and is now a
  `duplicate cases` ERROR, so a package that relied on the old
  behaviour fails loudly rather than quietly. That is the safe
  direction and is the refutation condition for this change.
  **BOTH CONFIRMED: APExp BUILDS COMPLETELY AGAIN, chicken included.**
  The full rebuild after the two compiler fixes completes, which is
  the weakest useful result and also the only one available for a
  change in the LEXER and the SWITCH TABLE: nothing downstream of
  either produces a link error, so a completed build is a precondition
  rather than a measurement. `longconst-test` and `switchcase-test`
  are what measure them.
  **BOTH ARE IN AND BOTH ARE 0.** `longconst-test` prints `long` 4 and
  `long long` 8 -- so sections 1 and 2 are asking the question they
  exist for rather than passing because nothing overflowed, which is
  what the host run could not do -- and `0x0200000000000000L` survives,
  `0x8000000000000000UL` survives, the switch label decodes to `0xc2`,
  and **section 3's control holds**: `0x80000000L` stays long-sized and
  positive. `switchcase-test` is 0 with **section 2 naming every arm**
  -- the four wide labels 0x0e/0x1e/0x3e/0x4e reach arms 3-6 rather
  than `default`, which is the SILENT half, and 3a's wide label
  truncates to 1 and is selected by 1. *Both compiler fixes are
  measured now rather than inferred from a build that completed.*
- **bacon** (BASIC) -- **IT CONVERTS BASIC TO C ON APExp NOW**, 605
  lines in 0.854s for `bacongui-tk.bac`. What stopped the compile was
  not bacon: **pkg-config has never worked in this tree.**
  `cmd/pkgconf/mkfile` built it with `-DPKG_DEFAULT_PATH="/bin"`, a
  directory with no `.pc` in it, and nothing installed one -- so
  pkgconf is built, is in `_CORE_APPS`, `rc/bin/ape/pkg-config`
  forwards to it, and the whole path resolved nothing. *A capability
  present and not declared, for the sixth time.* `PERSONALITY_PATH`
  beside it already named the right parent; `PKG_DEFAULT_PATH` is
  `/sys/lib/ape/pkgconfig` now and `tcl.pc`/`tk.pc` live there.
  **Their `Cflags` and `Libs` are EMPTY by design**: `/sys/include/ape`
  is already on pcc's path so a `-I` would be noise and anything else
  would shadow the real `tcl.h`; and kencc records archives from
  `#pragma lib`, which both headers carry, while **`6l` resolves `-l`
  against `/$objtype/lib` rather than `/$objtype/lib/ape`
  (`6l/obj.c:405`)** so a `-l` would name a file that does not exist.
  They answer "present, and at what version", which is what `--exists`
  needs. **`DATA_PATH` is not a bacon problem**: upstream's
  `Makefile.in:51` passes `-DDATA_PATH='"$(DATADIR)"'`.
  **`sys/lib/tests/bacon-test.bac` is the first BASIC test, and it had
  to be written because BaCon SHIPS NONE** -- `bacon.bac` plus the
  five GUIs is the whole `.bac` corpus. It is aimed rather than
  general: NUMBER is a C `long`, so sections 1-2 are the 32-bit-`long`
  invariant, and the rest are FLOATING, strings, arrays and a FUNCTION
  return. **Validated on the host first and that caught two bugs IN
  THE TEST** -- a `LOCAL` redeclaring a parameter, and
  `1000000 * 1000000`, which overflows in `int` on gcc too because
  BaCon folds bare literals as `int`. 0 failures on gcc; not yet run
  under pcc.
  **The exit status is NOT the failure count** (BaCon's `END` takes no
  value, its `EXIT` leaves a SUB), so read the `N failures` line.
  **AND THE VM RUN'S TWO FAILURES ARE 1b AND 2a, WHICH ARE THE
  INVARIANT THE FILE EXISTS TO MEASURE RATHER THAN A REGRESSION.**
  BaCon's NUMBER is a C `long` and kencc's is 32 bits, so a value past
  2^31 wraps -- *and NUMBER is the only integer type a BaCon program
  has*, so that is every arithmetic result in every program, not a
  curiosity. They stay as FAILURES rather than becoming a probe:
  demoting the loudest true thing the file measures would hide it.
  The test now PRINTS the diagnosis beside the count.
  **MY FIRST SIZING OF THE FIX WAS WRONG BY TWO ORDERS, and the
  generated output settled it in one second where a grep had not.** I
  counted `"long"` in the GENERATOR -- 232 sites, 175 distinct
  literals -- and called the change large. The generated C contains
  none of them: every NUMBER goes through **one** line,
  `#define NUMBER long`, and the 232 are the generator's own
  bookkeeping. *Counting the thing that emits is not counting the
  thing emitted.*
  **BUT IT IS NOT ONE LINE EITHER, AND THAT IS WHAT `6c` IS FOR.** A
  FUNCTION's return type is written as the bare word `long`
  (`bacon.bac:2322`), not as NUMBER, so widening the define alone is a
  MIXED build -- **chicken's `C_LLP` without `C_SIXTY_FOUR`, exactly**.
  Measured on the host in all three configurations: as generated **0**
  failures; NUMBER and returns both `int` (kencc's shape) **3** --
  1b, 2a, 6c; and the HALF-FIX, NUMBER widened with returns left
  alone, **1 -- 6c alone**. *Without 6c a half-fix and a whole one
  print the same thing.* **So the VM count becomes 3, and the third is
  newly MEASURED rather than newly broken.**
  **CONFIRMED ON THE VM: 3 failures, and they are 1b, 2a and 6c by
  name.** The prediction named the count and all three names before the
  run and every one matched; everything else -- FOR, WHILE, strings,
  arrays, both other FUNCTION returns -- passes. *That is the 32-bit
  `long` invariant measured through a language whose only integer type
  is that `long`*, and the recipe this file records (`-q -c cc`) is
  what ran.
  **AND THE RECIPE THIS FILE RECORDED WAS WRONG IN BOTH HALVES, which
  the first VM run said in one screen.**
  - **`-c cc`, not `-c pcc`.** bacon writes a `Makefile.bacon` naming
    `$stem.o` and links that, so `-c pcc` answers
    `??none??: cannot open file: bacon-test.bac.o` -- `pcc -c` writes
    `.6`. *That is not bacon hardcoding something this tree cannot
    meet*: `pcc.c:75` is
    `objext = (strcmp(prog,"cc")==0) ? "o" : ot->o` and
    `sys/src/ape/9src/cc.c` is the single line
    `#include "../../cmd/pcc.c"` -- **`cc` and `pcc` are one binary
    and the NAME chooses the extension.** The note here called `cc`
    "the APE wrapper rather than pcc" and made naming pcc the point of
    the exercise; `-c cc` is the same compiler under the name that
    answers in the extension every Makefile expects. `-lm` resolves
    too (`pcc.c:498` maps it to `libap.a`).
  - **`BACON_IN_DOCKER=true`, not `</dev/null`.** Both prompt sites
    (`bacon.bac:8306` and `:10489`) are ALREADY guarded by
    `IF GETENVIRON$("BACON_IN_DOCKER") = "true"`, which answers `y`
    without reading -- upstream's own escape for non-interactive use,
    sitting unused while this file prescribed a worse one. **Closing
    stdin does not make the prompt take its default, it makes bacon
    DIE**: the generated `__b2c__input` calls `getdelim`, which
    answers -1 at EOF, and -1 falls into the arm that raises
    `Runtime error: function 'INPUT' ...: Error opening file: No such
    file or directory`. **MEASURED ON glibc** by compiling those four
    lines verbatim with stdin on `/dev/null` -- `total -1 -> RUNTIME
    ERROR arm` -- so it is **BaCon's, on every platform**, and
    `</dev/null` was converting a hang into a different failure rather
    than into an answer. *An errno printed beside a message about
    opening a file, when nothing was opened, is the sticky-errstr
    shape arriving from an upstream runtime instead of from libap.*
    `-q` is worth adding beside it and is not a substitute: it gates
    only the error-report prompt (`IF NOT(g_QUIET)`), and the
    temporary-files one has no such guard.
  **The stronger test is SELF-HOSTING and is not that file**:
  `bacon.bac` is 10,517 lines of BASIC whose output is bacon itself, so
  `bacon -c pcc bacon.bac` converting, compiling and then converting
  again is the end-to-end check -- the same shape as EDG's
  self-translation. Do the small test first, because when self-hosting
  fails it says nothing about which feature broke.
  **`cmd/basic` is LIVE in `_OPTIONAL_APPS` now** -- this line said
  the opposite and was stale -- so the next tree-wide `mk` builds
  bacon, and anything it reports is newly *measured* rather than
  newly broken.
- **the archivers** -- bzip2, xz, unrar, unace, unarj, clzip. See the
  tar section: `-J` retires the padding hunt, so this is now a check
  rather than a hunt, and the way to do it is to run each one on a
  real archive.

**Queued after Tcl/Tk: two more ports, chosen as stress tests.**
**`tkblt` was one of three and is GONE from the tree**: 3.2 is C++, 48
`.C` files with `namespace Blt {` and `#include <cfloat>`, and kencc
has no C++ (`external/cfront-C4` is pre-standard cfront: no
namespaces, no templates, no STL). **tkdesk never needed it** -- it
ships its own BLT subset in **C**, `tkdesk/blt/`, 12 `.c` files and
not one `.C`.
So: **itcl** (4.2.3, 22 `.c` files, an ordinary autoconf extension)
becomes a regular APExp package under `sys/src/ape/lib` and
`sys/src/ape/cmd`, and **tkdesk** gets its mkfile in
**`sys/src/ape/app`** and is **not built by default**, being a
proof-of-concept rather than part of APExp.
**itcl goes first, and the reason is measurability**: it ships its own
test suite, so it is new surface that can be counted, where tkdesk is
an application that either runs or does not and whose failures are
hard to localise. Tcl and Tk have been the most productive bug-finders
here, and every large find in this tree came from new software
reaching an untouched path rather than from grinding a suite already
at its floor.


---

## perl

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

### perl

`sys/src/ape/lib/perl` builds `libperl.a`; `sys/src/ape/cmd/perl` builds
`miniperl`, uses it to generate `perlmain.c`, links `perl`, and installs
the module library into `sys/lib/perl` (config.h's `PRIVLIB`).

Working: the interpreter runs, module loading works, and
`ExtUtils::Miniperl` generates `perlmain.c`.

**No XS extensions.** Plan 9 has no dlopen, so `usedl` is empty,
`dlsrc` is `dl_none.xs`, `xs_init` in `perlmain.c` has an empty body,
and only the pure-perl `dist/` and `cpan/` trees are installed — the
fourteen with a `.xs` are deliberately left out, listed in the mkfile.
A `.pm` that dies in `XSLoader` is worse than one that is absent.
PathTools is the exception: `File::Spec` is pure perl and `Cwd.pm` takes
a pure-perl path when DynaLoader is missing.

**`Config.pm` is hand-maintained**, at `sys/src/ape/cmd/perl/Config.pm`.
APExp does not run `Configure`, so there is no `config.sh` for `configpm`
to read; it is the companion to the hand-answered
`sys/src/external/perl/config.h` and has to be kept in step with it. It
provides `%Config` plus `import`, `myconfig`, `_V` (which `perl -V`
calls, at perl.c:2356), `config_vars`, `config_sh` and `config_re`.

**Getting perl to run at all turned up four bugs, and only one was
perl's.** They are worth reading as a set, because three of them were
silent:

- `bool` was a signed char in kencc, so every conversion to it truncated
  — see `docs/notes/kencc.md`. This is why miniperl compiled programs and
  then executed nothing.
- `setlocale` reported a locale it had not set — see libap, locale/.
- `<stdio.h>` leaked errno, unistd, fcntl and pthread, and libap itself
  relied on the leak.
- perl's `config.h` claimed an 80-bit long double. kencc has none:
  `sub.c`'s `simplet()` maps `BDOUBLE|BLONG` to `types[TDOUBLE]`, so
  `long double` is `double`. `NVTYPE` is `double`, `NVSIZE` 8, the
  `NVef`/`NVff`/`NVgf` formats lose their `L`, `USE_LONG_DOUBLE` is off,
  and the `LONGDBL*` byte patterns and mantissa bit counts follow. A
  format asking printf for a type nothing passes it is how `use 5.006`
  came out as "Invalid version format (non-numeric data)".

---


---

## GNU tar, gnulib's strerror, and the struct padding underneath

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

**GNU tar's messages had NO PROGRAM NAME, and it was every GNU
program in the tree.** `tar xf` on a `.tgz` printed
`: This does not look like a tar archive` where tar anywhere else
says `tar:`. gnulib's `error()` is literally
`#define program_name getprogname ()` (`gnulib/error.c:128`), and
libap's `getprogname()` returned **`argv0`** -- lib9's global, which
lib9 fills from `ARGBEGIN`, **an rc idiom no APE program executes**.
So it was NULL unless the program happened to call `getopt_long`,
which set it as a side effect -- which is why some programs named
themselves and others did not, and why nobody had chased it.
`argv0` is now set in **`plan9/callmain.c`**, the one path every APE
program takes, and its DEFINITION moved there from
`misc/getopt_long.c` for a linking reason: `_callmain` is in every
binary and `getopt_long` is not. `getprogname()` returns the
**basename** -- what BSD, Solaris, glibc and gnulib's own fallback all
return, and what `tar:` rather than `/bin/tar:` depends on -- and
never NULL, since every caller prints it with `%s`.
`progname-test.c` asks all four; its section 3 is what separates a fix
from a half-fix, since returning `argv[0]` whole would pass the rest.
**This is NOT the tar extraction bug** -- it is a second one that was
standing next to it, and the extraction failure is still open. See the
tar entry below.
**CONFIRMED, and by the very next command run**: `tar cf` now prints
``tar: Removing leading `/' from member names`` where the previous
round's run printed `: `. That one prefix certifies the whole chain --
`_callmain` sets `argv0`, `getprogname()` takes the basename, gnulib's
`error()` reaches it -- and `tar:` rather than `/bin/tar:` says the
basename half works too.

**`tar` CANNOT READ A PLAIN TAR FILE, and decompression was never
involved.** The split settled it in one round and eliminated
everything I had been looking at:
- `xd -c` shows `1f 8b 08` -- genuinely gzip;
- `minigzip -d <x.tgz >/tmp/n.tar` exits **status=0**;
- `tar tf /tmp/n.tar` on the ALREADY-DECOMPRESSED file gives the
  **byte-identical** failure, same `A lone zero block at 580`.
Identical output from both runs also says run 1's tar had decompressed
correctly all along, so `Child returned status 1` was minigzip taking
EPIPE when tar gave up -- *a consequence, not a cause*. **Every one of
`GZIP_PROGRAM`, `minigzip` and the exec plumbing is innocent.**
**WHERE IT ACTUALLY FAILS**, read off the source: the message comes
from `buffer.c:451`/`456` in `open_compressed_archive`, and it is
printed when `shortfile` is true -- which is
`*pshort = find_next_block () == 0` in `check_compressed_archive`.
**So tar's FIRST read of the archive yields no block at all.**
That also explains the `.tgz` run's shape exactly: with no bytes to
inspect, the magic test could not fire, so tar fell through to
`set_compression_program_by_suffix` -- it ran minigzip because the
NAME ended in `.tgz`, not because it had seen `1f 8b`.
`O_BINARY` is 0 in all four places that define it, so the `rmtopen
(..., O_RDONLY|O_BINARY)` is not it, and tar's `config.h` makes no
type-size claims.
**NEXT STEP IS `ratrace`, not more source.** It names a failing system
call outright where elimination takes rounds -- it found the `utime()`
bug in one run after six readings chased an errno the failing call
never set. Ask it on the smallest case: whether `tar` can read an
archive **it wrote itself** separates "tar's read path is broken" from
"this archive is unusual", and `ratrace` on that says which call
returns what.
**THE `tar cf` CRASH IS SOLVED, AND IT WAS NEVER TAR'S: gnulib's
`strerror` CALLED ITSELF FOR EVER.** `nohandle=1` named it in one run
and `acid` on the Broken process finished it:

```
tar 2459: suicide: sys: trap: fault write addr=0x7ffffeffefc8 pc=0x247ba3
strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56   (x N)
```

`strerror.c:52` is `msg = strerror (n);` and is *meant* to be the
system's; gnulib arranges that with one macro in its **generated**
`string.h` (`#define strerror rpl_strerror`), so the definition defines
`rpl_strerror` and the `#undef` between declarator and body makes the
inner call reach the real one. **Nothing generates those headers here**
-- `sys/src/external/gnulib` has `string.in.h` and no `string.h` -- so
`<string.h>` was APE's, the function defined the plain name, and line
52 was a call to itself. Legal C, no warning. `n=0x14` is ENOENT.
**And it was every GNU program in the tree**: `strerror.$O` was in
`libgnu.a`, which every GNU package links, and `error(0, errno, ...)`
is how all of them report a failed system call -- so tar, sed, awk,
grep, m4, gettext, diff, patch and bison each died with a stack fault
instead of a message, reading as a different bug every time.
**No link error said so, and the reason is worth keeping**: the
archive's own README rule 1 is *never add a module libap already
provides*, and libap provides `strerror` -- but libap's is an archive
MEMBER THE LINKER NEVER HAD A REASON TO PULL, since gnulib's satisfied
the symbol first. *A module libap already provides is a problem whether
or not `ar` says so.* Fixed by one line out of OFILES; libap's has an
`EPLAN9` arm that returns Plan 9's own `errstr`, so this improves
diagnostics rather than costing anything.
**`nm` for the handler address was the WRONG QUESTION and is closed.**
The faulting address is ~16MB below the stack top: tar had run out of
stack, so the kernel could not push the note frame, which is exactly
what `bad address in notify` means. **A crash whose own message is
about the crash-reporting machinery is reporting the SECOND failure**
-- take the machinery out (`nohandle`) rather than investigate it.
**The sweep matters more than the instance**: the idiom (a definition
of NAME followed by `#undef NAME`) is in **34 places across 24 files**
in the gnulib tree and **exactly one, `strerror.c`, was in OFILES**.
The command is README rule 6 so it can be repeated when OFILES grows --
the next module added could be `fcntl`, `readdir`, `access` or `raise`.
**`strerror-test.c` must be linked against `libgnu.a`** or it passes
against the broken tree and proves nothing; the command is in the file.
**CONFIRMED, all three outcomes.** `tar cf` completes; `strerror-test`
reports **0 failures** linked against `libgnu.a`, section 1 included --
whose only possible failure was to kill the process; **and `tar tf` on
the archive tar had just written FAILED**, which was the third outcome
and the useful one. *The read bug is now proven independent of
`strerror`* -- the question the two rounds before this could not reach,
because tar never finished writing an archive to try.

**THE READ BUG IS OPEN, AND THE SYMPTOM HAS CHANGED -- which retires
part of the old diagnosis.**

```
$ tar tf /tmp/t.tar
tmp/h
tar: Skipping to next header
tar: Exiting with failure status due to previous errors
```

**`tmp/h` is listed correctly**, so the first header parsed AND its
checksum verified -- tar does not print a member name it has not
accepted. And `list.c:294` prints `Skipping to next header` **only when
the previous status was `HEADER_STILL_OK`**, so the failure is on the
**SECOND** `read_header`: a block that is neither a valid header nor
all zeros. **So "tar's FIRST read yields no block" was about the
original archive and does NOT generalise** -- here the first read
plainly yields one. Whether the two failures share a cause is open, and
assuming it would put the next round on the wrong file.
For a one-file archive nothing sits between the member and the zero
blocks, so exactly one of two things is true and they need completely
different fixes: **(a) the archive is malformed** and tar's WRITE path
is broken, or **(b) the archive is fine** and tar's READ path is --
most likely in how far it advances past the data, since landing one
block short would read the file's own contents as a header and give
exactly this.
**`tarhdr-probe.c` SPLIT THEM IN ONE RUN, and it is (a): the archive
is MALFORMED, so it is tar's WRITE path.** The header block is perfect
-- name, size, magic, and the checksum recomputes, so the reader was
right to accept it and right to refuse what came next. But **`hello\n`
sits 8 bytes INTO block 1** where the host reference has it at offset
0, and **blocks 2 and 3 are not zero**.
**The offset of the data is itself a measurement.**
`create.c`'s `dump_regular_file()` does `start_header` (which returns
`record_start`), `finish_header` (which advances to `record_start + 1`)
and then `blocking_read (fd, blk->buffer, ...)` -- so the file offset
of the member's data is exactly **`1 * sizeof(union block)`**. It came
out **520**. Every member of that union is an array of `char` and gcc
makes it 512, so 520 would mean kencc pads one of them: every block
after the first shifted, and a **compiler** question rather than a tar
one. **`tarblock-probe.c` asks it directly**, each member's size beside
the host's answer, and **must be built with tar's own flags** (the
command is in the file) or it measures a different `tar.h`.
**CONFIRMED: `union block` is 520, and SEVEN of the nine sizes
disagree with the host.** It is not tar's bug at all -- it is 6c's
struct layout, and `tarblock-probe`'s whole table is predicted by two
lines of `sys/src/cmd/6c/swt.c`'s `align()`: `Asu2` rounds the end of
**every** struct to `SZ_VLONG` rather than to what its members need,
and `Ael1` aligns a **nested** struct member to 8 as well, because
`ewidth[TSTRUCT]` drops through the same test.

```
  sizeof(union block)      =  520   host says  512   *** DIFFERENT ***
  sizeof(posix_header)     =  504   host says  500   *** DIFFERENT ***
  sizeof(oldgnu_header)    =  504   host says  495   *** DIFFERENT ***
  sizeof(star_in_header)   =  520   host says  512   *** DIFFERENT ***
  sizeof(struct sparse)    =   24   host says   24   same
```

**Two of those numbers need BOTH rules to explain**: `oldgnu_header`
495 -> **504** rather than 496, because its `struct sparse sp[4]` is
pushed from 386 to 392 first; and `star_in_header` 512 -> **520**, the
same push then a tail round -- **and that is the member that set the
union's size.** *`struct sparse` is 24 and agrees, because it is a
multiple of 8 by accident* -- a sample of one struct could have been
that one.
**What breaks is narrow and worth stating narrowly**: field offsets
are still right, which is why tar read its own header back correctly,
checksum and all. **`sizeof` used as a STRIDE or a LENGTH** is what
fails -- tar's entire record walk is `union block *` arithmetic while
every length in the format is a multiple of `BLOCKSIZE`, so 520 put
every block eight bytes late, and the zero-fill (counted in
`BLOCKSIZE`) then missed the gaps, which **is the second symptom**.
Both are one cause after all.
**FIXED with `#pragma pack on`/`off` around tar.h's on-disk structs
only** -- `pragpack()` sets `packflg`, the override both `align()`
cases already read -- guarded by `PLAN9` from `cmd/tar/mkfile`, as
itcl already does. It is spelled `pack on`, not `pack 1`: `pragpack`
does `atoi(s->name+1)` and only matches `on`/`yes` by name. tar's own
`tar_stat_info`/`xheader` are deliberately left unpacked; they hold
real `off_t` and pointers.
**`6c` ITSELF WAS NOT CHANGED, and the way to change it is a FLAG.**
The blast radius is smaller than it looks: `sys/src/cmd/mkfile` has
`BIN=$APEXPROOT/$objtype/bin`, so APExp's compilers install into the
**repo**, and the machine's own `6c` and the `/$objtype/lib/*.a` it
built are untouched. What is exposed is only what this tree links from
the host -- `cmd2/vts` (lib9p, libthread, libc) and `cmd2/vtwin`
(libdraw, libthread, libc).
**Porting those to APE would be a rewrite, not a port**: `ape/lib` has
`draw` but **no `9p` and no `thread`**, and vts *is* a 9P server on
libthread. **And a two-stage bootstrap does not close the gap** --
stage two's compiler would be built with the new rule and still link
the host's `libc.a` built with the old one (`Lock`, one `int`, is 4
naturally and 8 under the current rule, and sits inside `QLock`,
`Ref` and `Rendez`). It would need the whole native world rebuilt from
source, which this tree does not vendor.
**So: `-P` in `sys/src/ape/config`'s CFLAGS.** APE is already a
separate ABI -- own libc, own headers, own include path -- and
everything it links is built in this tree, so it is self-consistent by
construction; native code keeps the 9front ABI; **and the compilers,
being native, are unaffected, so there is no bootstrap question at
all.** The flag costs nothing to parse: `cc/lex.c`'s `ARGBEGIN`
`default:` arm does `debug[c]++` for any unknown letter.
**The work is NOT flipping a constant**: `struct Type` in `cc/cc.h`
has `width`, `offset` and `alignas_req` and **no natural alignment**,
which is exactly why `align()` reaches for `SZ_VLONG`. A conforming
rule means tracking max member alignment in `sualign()` and storing it
on the Type -- the type system, ~40 lines in `cc/` plus one per
backend.
**Measure first with `cc -a`** (acid definitions carry sizes; it is
what `mkone`'s `%.acid` rule uses): diff old against new over the APE
headers and libap, and it names every struct whose layout moves
*inside APE*.
**Order: after the archiver sweep.** If bzip2, xz, unrar, unace,
unarj and clzip come back clean, `#pragma pack` at the two or three
places that model bytes is the whole cost in practice and the flag
buys conformance rather than a bug fix. Detail in `docs/notes/kencc.md`.
**The sweep found six all-char structs in `external/` whose size is
not already a multiple of 8**, two of them tar's; the rest are
`memcpy`-into-a-local and cost nothing. **That is a LOWER BOUND with a
named limit**: the sweep only matches structs whose every member is a
plain `char`, so it misses the three tar structs with a nested
`struct sparse sp[N]` -- *the tool that found the bug's family cannot
find the whole family.*
**CONFIRMED END TO END, AND TAR IS CLOSED.** `tarblock-probe` reports
PASS and 0 disagreements with its `-DPLAN9` marker; all nine sizes
match the host and the block table reads 0/512/1024/1536 with
`record_end` at 10240. Then the same command on the same archive,
across the rebuild:

```
Before rebuild                     After rebuild
$ tar cf /tmp/t2.tar /tmp/h        $ tar cf /tmp/t2.tar /tmp/h
tar: Removing leading `/' ...      tar: Removing leading `/' ...
$ tar tf /tmp/t2.tar               $ tar tf /tmp/t2.tar
tar: This does not look like       tmp/h
     a tar archive                 $
tar: Skipping to next header
tar: Exiting with failure status
```

**And the ORIGINAL archive extracts**: `rm -rf NetHack-5.0.0`,
`tar xf nethack-500-src.tgz`, and the tree is back. **That was the
last open question and it is answered -- BOTH failures were the same
bug.** With `union block` at 520 the *reader* mis-strides exactly as
the writer did, so a correctly-formed foreign archive walked into its
own payload and reported `This does not look like a tar archive` /
`A lone zero block at 580`. **I was right to refuse to assume they
shared a cause, and the measurement is what joined them** -- the
before/after pair is the control, since only the build changed.
*(The before-rebuild run of `tar tf` on tar's OWN archive printed the
foreign archive's message this time, where the earlier run printed
`tmp/h` first: the same bug, differing only in what heap garbage the
mis-strided blocks happened to land on. Another reason not to have
matched them by message.)*
**WORTH A LOOK NEXT, and not urgent**: the archivers -- bzip2, xz,
unrar, unace, unarj, clzip -- are exactly the class of program that
walks on-disk records with struct pointers, which is the one thing the
padding breaks. None has been tested since. The `external/` sweep is a
lower bound by construction (see the note), so *the way to find these
is to run each archiver on a real archive*, not to grep.
Detail in `docs/notes/kencc.md` and `docs/notes/libap.md`.
**AND `-J` LARGELY RETIRES THAT SWEEP, which is a consequence of the
flag worth stating where the to-do was written.** The tar bug was
`Asu2`'s unconditional 8-byte tail round plus `Ael1` aligning a
nested struct member to 8, and **`-J` fixes both for every APE
compile** -- so an all-char on-disk record now gets its natural size
without anyone reaching for `#pragma pack`. *The predicted failure
mode is gone rather than unmeasured.* Running each archiver on a real
archive is still the only way to know, and is still worth one round,
but it is now a check rather than a hunt. tar's own `#pragma pack`
is a no-op under `-J` (both answers are 500 and 495) and **stays**:
it documents the on-disk intent and keeps the file right under `-9`.


---

## bacon: self-hosting, and a fixpoint at generation 2

```
  bash-5.3$ bacon -q -c cc bacon.bac           # gen 1 -> gen 2
  Converting 'bacon.bac'... done, 10518 lines ... in 7.222 seconds.
  cc -o bacon bacon.bac.o  -lm
  -rwxr-xr-x 1 glenda glenda 3048736 Sun 22 18:56 bacon
  2981 -rwxr-xr-x 1 glenda glenda 3052058 Sun 22 18:06 /bin/bacon

  bash-5.3$ ./bacon -q -c cc bacon.bac         # gen 2 -> gen 3
  Converting 'bacon.bac'... done, 10518 lines ... in 6.895 seconds.
  cc -o bacon bacon.bac.o  -lm
  -rwxr-xr-x 1 glenda glenda 3048736 Sun 22 18:58 bacon
```

**BaCon self-hosts on APExp.** Generation 1 converted its own 10518
lines, the C compiled and linked, and **generation 2 then did the same
job** -- which is the half that was missing and the half that matters,
since *a compiler that produces a binary has not been shown to produce a
WORKING one*. That is the gap `miniperl` had when it linked and then
faulted writing `perlmain.c`, and it is closed here by generation 2
doing real work rather than by generation 2 existing.

**And generation 3 is the same size as generation 2: 3048736 both
times.** A converter that has reached a fixpoint produces, from its own
source, a compiler identical to itself; two successive generations
agreeing to the byte count is what that looks like from outside.

### The size comparison was worthless once and is decisive here, and the difference is the whole lesson

One round earlier this file said, of 3048736 against /bin/bacon's
3052058, that **the sizes prove nothing** -- because `/bin/bacon` is
linked by `cmd/basic/mkfile` with APExp's CFLAGS and generation 2 by
bacon's own generated `Makefile.bacon`, so the comparison was measuring
the BUILD and not the translation. *That was right, and it was
incomplete.*

**The gen2-against-gen3 comparison holds the link command constant** --
both come from `Makefile.bacon`, the same `cc -c` and the same
`cc -o ... -lm` -- so the only thing left varying is the C, and the C is
what the question was about all along. **The same measurement that is
meaningless across a build-system boundary becomes decisive once the
boundary is removed.**

*A comparison is not worthless or valuable in itself; it depends on what
else is being held constant* -- which is the control rule arriving as a
property of two file sizes rather than of a test.

### What is still one command short -- and the command is not the obvious one

Equal size is not equal bytes, so the proof is `cmp bacon.bac.c
src/bacon.bac.c`. **But bacon deletes the C it just generated**, so
there is nothing to compare, and the three flags involved do not do what
their names suggest. Read from `bacon.bac` rather than recalled:

- **The `.c` is on the temp list.** `:8294` adds `g_CFILE$` to
  `g_TMP_FILES$`, and `:10509` removes every name on that list unless
  `g_TMP_PRESERVE`. The file lives in the CURRENT directory by default
  (`:8254`, `g_TEMPDIR$` defaults to `"."`), which is why `cc -c
  bacon.bac.c` names it bare.
- **`-p` is the flag**, `:8166`, `CASE 112`. (The options are parsed as
  CHARACTER CODES, so the table reads `CASE 112` rather than `"p"` --
  112 is `p`, 110 is `n`, 113 is `q`, 100 is `d`, 111 is `o`.)
- ***`-n` ALONE THROWS THE CONVERSION AWAY.*** `CASE 110` sets
  `g_NO_COMPILE`, which skips the compile -- and the cleanup at `:10509`
  is OUTSIDE that branch, so the `.c` is generated and then deleted with
  nothing having been built from it. *The obvious flag for "just
  convert" is the one flag that guarantees you keep nothing.*

### And `-p` does not only preserve: it rewrites the file

`:10399` is `IF ISTRUE(g_TMP_PRESERVE)` followed by **`indent`** over
every preserved file. So on a system that HAS `indent`, asking bacon to
keep its output reformats that output, and a `cmp` against the committed
C then differs for a reason that has nothing to do with the translation
-- *a diff full of whitespace, reading exactly like a real
disagreement.* **The instrument would have changed what it measures**,
conditionally, with the condition being whether a program happens to be
installed.

**It is safe here, and bacon says so itself rather than leaving it to be
assumed**: APExp ships no `indent` (`git ls-files` has no such command),
so the run prints

```
	WARNING: 'indent' not found on this system!
```

and leaves the file alone. ***That line is the precondition*** -- if a
run ever prints `Applying indentation... done.` instead, the comparison
below is void. Neither message is gated on `-q`.

### Why `cmp` is the right tool rather than `diff`

Two things had to be true and both were checked rather than hoped:

- **No timestamp in the `.c`.** The only version stamp is
  `COMPILED_BY_WHICH_BACON`, `"BaCon executable " & g_VERSION$`, and
  `:8777` writes it `TO g_GENERIC` -- the `.generic.h`, not the `.c`.
- **No host leaks into the `.c`.** `OS$` is read eleven times in
  `bacon.bac` and **not one of the conditionals separates Linux from
  Plan 9**: they test SunOS, Haiku, BSD, OSF1 and Darwin, so both
  machines take the same branch every time. The twelfth hit is the
  string `"OS$"` inside a runtime error message, not the host.

So the two generators should agree to the byte, and **a difference would
be a real disagreement between shell BaCon and the bacon kencc compiled
rather than a platform artefact** -- which is what makes `cmp` worth
running and its answer worth believing.

```
	./bacon -p -n -q bacon.bac
	cmp bacon.bac.c src/bacon.bac.c
```

`-n` is kept beside `-p` only to skip a compile nobody needs here; it
changes nothing about what is generated.

### The one-word trap, recorded because it was avoided rather than hit

***`./bacon`, NOT `bacon`.*** Plain `bacon` resolves through `$PATH` to
`/bin/bacon`, which is generation **1** -- so the second run would have
re-measured the binary that was already measured and reported a clean,
plausible, meaningless result. *A measurement of a build that does not
contain the change measures nothing*, and nowhere in this tree are two
builds as easy to confuse as here: one word apart, the same name, and
both on the path.
