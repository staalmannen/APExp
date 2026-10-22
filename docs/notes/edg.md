# EDG: the C++ front end

`sys/src/external/edg` holds 133 generated C files, ~2.90M lines: EDG's
own front end translated to C by a `cpfe` built from the same commit
with a kencc target.  This is the whole record of getting there -- the
target description, the link model, the grammar bug, the entry point,
the folded `offsetof`, and the two bit-field rules it flushed out of
kencc on the way.

`sys/src/external/edg/NOTE` is the companion and is the one to read
first if you are about to run `cpfe` by hand: it carries the commands
and the configuration.  This file carries why each of them is what it
is.


---

## EDG: the C++ front end, from investigation to a running cpfe

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

**Ports not started**, in the order their risk was last measured:
- **EDG** -- **BOTH NAMED RISKS ARE CLOSED AND THE SELF-TRANSLATION IS
  IN THE TREE.** `sys/src/external/edg` holds **133 generated C files,
  ~2.90M lines**: all 75 `src/`, 7 `util/` and 51 `lib_src/`, produced
  by a `cpfe` built from the same commit with a kencc target, plus
  EDG's own 17 C++ headers verbatim. `gcc -fsyntax-only` over all 133
  is **0 errors, 0 warnings** -- which is the host's answer and says
  nothing about kencc. Full detail in `sys/src/external/edg/NOTE`;
  only the consequences are here.
  - **Risk 1, the target description: answered by EDG's own `win64`.**
    kencc on amd64 is LLP64 and win64 is EDG's LLP64 configuration, so
    the values were taken from the build's generated
    `cmake_defines.h` rather than invented. Every scalar width
    matches, **including `long double` 8** -- win64 says 8 because
    MSVC has no extended precision and kencc says 8 because
    `cc/sub.c`'s `simplet()` maps `BDOUBLE|BLONG` to `types[TDOUBLE]`,
    which was not predicted. `size_t`/`ssize_t`/`ptrdiff_t` are
    win64's kinds too, read out of `stddef_arch.h`; **`wchar_t` is the
    one place the two differ** (`unsigned int` here, `unsigned short`
    there). `kencc_targ.h`, committed beside the NOTE, is the whole
    configuration -- a **pre-included header**, so nothing in the EDG
    tree is modified.
  - **Risk 2, self-translation: it translates.** One file does not and
    it is the right one -- `util/cfe_daemon_client.c`, the only file
    in the tree needing a real C++ standard library, and a
    unix-domain-socket client is out of scope here twice over.
  - **The target was inferred from the compiler that BUILT cpfe, which
    is the finding of the round.** `targ_def.h:3505` derives
    `GCC_IS_GENERATED_CODE_TARGET` from `defined(__GNUC__)`, and that
    one variable is the sole gate on both `__weak__` emission sites --
    so cpfe built by g++ decided its OUTPUT was for gcc and emitted
    **26,712 `__attribute__((__weak__))`**, which kencc has not. A
    first round also baked in LP64 and glibc's headers. Setting it to
    0 and staging APExp's own headers takes the applied-attribute
    count **38,245 -> 0**; the 11 textual occurrences left are all
    inside string literals, EDG's own emitter text.
  - **THE LINK MODEL IS THE OPEN PROBLEM, and removing `__weak__`
    exposed it rather than solving it.** Those attributes were COMDAT
    emulation for vague linkage. Measured: two trivial TUs sharing one
    header collide on **10 symbols**, and across `src/` there are
    **3,094 COMDAT symbols named in more than one of the 75 files**.
    `--one_instantiation_per_object` is deliberately NOT used -- it
    covers only the template instantiations (3 of the 10) and makes
    the output depend on an `edg_prelink` phase mk cannot naturally
    express. Upstream's answer for a target without COMDAT is the
    **Cfront-like ABI**, and that was attempted and **backed out**:
    `IA64_ABI=0` makes cpfe fail to *compile* on three
    `TARGET_CONFIGURATION`-suffixed macros the Cfront ABI needs, so it
    is reachable by regenerating the macro configuration rather than
    by setting switches, and it changes mangling, the ctor/dtor model
    and vtable layout. Its own round.
  - **THE MKFILES ARE WRITTEN AND NOTHING HAS BEEN THROUGH pcc YET.**
    **It is THREE products, not one**, which `main` settles rather than
    taste: `src`'s 75 files hold exactly one (`cfe.c`) so they are one
    binary, `cpfe`; `util`'s seven hold six, plus `decode.c` with none
    (it is `edg_decode`'s second object); `lib_src`'s 51 hold none, so
    they are a LIBRARY. Hence `sys/src/ape/lib/edg` -> `libedg.a`
    (`mksyslib`) and `sys/src/ape/cmd/edg` -> `cpfe` (`mkone`); `util`
    is six small binaries and blocks nothing.
    **DELIBERATELY NOT IN `cmd/mkfile`'s lists** -- one failing entry
    aborts the whole tree's `mk`, as `basic` and `c++lib` already
    record. By hand first.
    **ORDER IS A DEPENDENCY RATHER THAN A PREFERENCE.** lib/edg first,
    because an archive sidesteps the link model entirely -- `ar` takes
    duplicate members and the clash only arrives at a LINK -- so it
    answers "does pcc compile EDG's generated C" with nothing else in
    frame. Then cmd/edg, where both remaining questions land.
    **AND `mk -k`, NOT `mk`**: Plan 9 mk stops at the first failing
    recipe, so a plain run costs one round per bad file across 75;
    -k names them all at once. *That is the rule bacon's missing
    headers and bacon's missing link symbols both paid for.*
    **AND THE FIRST pcc RUN STOPPED ON THE FOURTH FILE, FOR A KENCC
    GRAMMAR BUG RATHER THAN ANYTHING OF EDG'S: `auto size_t x;` DID
    NOT PARSE.** `autoadlist` began with `xdecor`, which reaches
    `LNAME | LTYPE`, so after `LAUTO` the parser could SHIFT a typedef
    name as the variable being declared -- and **yacc resolves
    shift/reduce in favour of SHIFT**, so the C23 deduction path won
    over `cname: LAUTO`, the storage class. EDG's C writes
    `auto <type> <name>;` for every local: **116,079 of them across
    103 of the 133 files**, so one conflict blocked essentially the
    whole port.
    **`-std=` WOULD NOT HAVE FIXED IT, and that is the finding rather
    than the fix.** The conflict is resolved when yacc BUILDS THE
    TABLE, so no runtime flag has a say -- and there is no dialect
    disagreement to arbitrate, since C23 kept `auto` as a
    storage-class specifier and its type inference applies only where
    `auto` is the SOLE type specifier. *Both standards want the same
    answer here*, and the grammar can reach it alone because `size_t`
    is LTYPE and `x` is LNAME. A new `autoxdecor` roots the first
    declarator at LNAME; `*` still shifts, because `auto *p = &x;` is
    deduction while `auto *p;` would need implicit int.
    **Measured with bison** (kencc's own sources need Plan 9's `<u.h>`
    and `<libc.h>`, so the first build is the VM's -- the weaker
    position `-J` also shipped from): shift/reduce **26 -> 22**,
    reduce/reduce 6 both ways, and the two states that carry it --
    `adecl` 417 and `forexpr` 517 -- each lose their LTYPE and `(`
    shifts, 4 -> 2. *The same production appears in two places, which
    is why a 26 -> 24 prediction was two short.*
    **AND THE WHOLE CORPUS WAS THEN SWEPT AT ONCE, which named three
    bad files and two missing symbols before the VM reached either.**
    *The stripping is the measurement*: with comments, string and
    character literals and `#line` removed first, every C11/C23
    construct kencc lacks counts **zero** -- where a raw grep reports
    `alignof` 2343, `static_assert` 1156, `_Complex` 702 and `typeof`
    425, all of them the word inside EDG's own mangled names and
    diagnostic text. The exceptions were **`lib_src/c99_complex.c`**
    (`_Float16`, `__bf16`, `__float80`, `__float128`) and
    **`thread_dtor.c`/`dtor_list.c`** (`__thread`) -- a feature of the
    HOST compiler rather than of EDG, *which is exactly why `gcc
    -fsyntax-only` reports 0 errors over them*.
    **`mk -k install` ANSWERED: 50 OF 51 COMPILE, AND ONLY
    `c99_complex.c` FAILS** -- predicted by name and by token
    (`syntax error, last name: _Float16`). Commented out of OFILES
    now the measurement is taken; a C++ front end has no use for a
    `_Complex` runtime, and the extended floats drag libgcc's
    soft-float family in behind them.
    **AND THE TWO `__thread` PREDICTIONS WERE WRONG, WHICH IS THE MORE
    USEFUL HALF.** I checked EDG's constructs against C dialects FROM
    MEMORY rather than against the compiler in this repository, where
    `cc/lex.c:1765` has carried `"__thread", LNAME, 0` and a swallow
    at `:1095` all along -- *"Plan 9 has no TLS; silently drop the
    qualifier."* **An instrument whose keyword list is not the
    COMPILER's keyword list is measuring a different compiler**: the
    include-path lesson `apdecl-sweep` and `apehdr-sweep` each paid
    for, one level down, for a lexer. The list to check against is
    `itab` plus that swallow list and both are in the tree -- and
    asking it about the four float types afterwards is what says
    `c99_complex.c` really is the only one.
    **That pass is not a clean bill, either**: `__thread` dropped makes
    `__thread_needed_destruction_head` one process-wide global shared
    by every thread, which is the stub-answering-the-wrong-thing shape.
    Harmless for single-threaded cpfe, a live hazard for anything cpfe
    translates. Recorded, not fixed.
    **And the limits were asked rather than assumed**: longest line
    430 bytes against cpp's `INS` 32768, longest identifier 295
    against `cc`'s `NSYMB` 1500, 7204 `case` in one file where `6c`'s
    `Case` is a linked list, and **`6c`'s `NSYM 50` is a CACHE, not a
    cap** -- `swt.c:229` wraps the slot to 1 and re-emits the ANAME.
    **The libap half of the link is answered and it is TWO NAMES.**
    All 133 compiled with gcc, then nm's defined set subtracted from
    its undefined set: 679 external, 121 of them plain C names, and
    libap defines every one but `_setjmp` and `__cxa_finalize`.
    `_setjmp` is a **missed line in `kencc_targ.h`** rather than a
    libap gap -- EDG's `TARG_SETJMP_FUNC` defaults to `"_setjmp"` and
    **win64, the same configuration every other value came from, says
    `"setjmp"`** -- and adding the name to a public APE header would
    be `reject` again, since `lua/ldo.c:80` uses it under
    `LUA_USE_POSIX`. `__cxa_finalize` is EDG's own runtime's, not
    libap's. *The first version of that sweep reported two dozen
    absent, because its regex required a character before the name and
    a definition starting in column 0 has none -- the function-shaped
    grep in a new spelling.*
    **ALL 75 COMPILE -- `sys_predef.c''s 315,616 lines included -- AND
    THE LINK IS WHERE IT STOPPED.** That was the question with no
    precedent and it is answered.
    **AND MY LINK PREDICTION WAS WRONG, ABOUT ORDERING.** I predicted
    `6l` would report undefined template instantiations; it reports
    **`redefinition:`** until `too many errors`. `6l` catches
    duplicates as it LOADS each object and only reports undefined
    symbols at the end, so it never reached the pass the prediction was
    about. *What it named was a symbol-for-symbol confirmation of the
    host sweep*: `edg::max_val<unsigned long long>` and
    `edg::skip_typerefs`, the two measured at **41 copies each**, and
    `Ptr_map<...>::get_with_hash` at 39.
    **AND THE FIX WAS ALREADY IN THE LINKER WITH NO WAY TO ASK FOR IT
    -- `-C`, COMDAT.** `6l/obj.c:996` is
    `if(p->from.scale & DUPOK){ skip = 1; goto casdef; }` on a
    duplicate ATEXT, and `6l/asm.c:548` uses `sym->dupok` to suppress
    `multiple initialization` for duplicate DATA; `DUPOK` is `(1<<1)`
    in eight `*.out.h`. **The one missing piece was a way for C to set
    the bit**: `gpseudo()` wrote `p->from.scale = (profileflg ? 0 :
    NOPROF)` and nothing ever OR'd into it. *The sixth time this tree
    has found a working implementation of the thing it could not do
    sitting next to the thing that could not do it.*
    **It is blunt and the mkfile says so**: it marks EVERY TEXT and
    GLOBL in the translation unit, not the vague-linkage ones, so two
    genuinely different functions of one name become first-wins
    instead of a diagnostic. Safe for generated C, where every
    duplicate is the same entity by construction, and nothing else in
    the tree passes it. The precise version is `cc` learning
    `__attribute__((__weak__))` -- which EDG already emits, 26,712 of
    them, when its target is gcc -- and that needs a re-translation.
    **x86 AND RISC USE DIFFERENT FIELDS, which one patch would have
    got wrong.** `6c`/`8c` carry TEXT flags in `p->from.scale`;
    `5c`/`7c`/`kc`/`qc`/`vc` carry them in `p->reg`, assigned only for
    ATEXT, so AGLOBL had to be named too. *And `zprog.reg` is `NREG`,
    not 0* -- so every RISC AGLOBL already reaches its linker carrying
    NREG in the flags field, and whether that was accidentally dupok
    was **checked rather than assumed** (16 and 32 against `1<<1`:
    clear).
    **FOUR TARGETS CANNOT HONOUR IT AND NOW SAY SO.** `9l` **declares
    `dupok` in `l.h` and never reads it** -- zero hits in its `.c`
    where every other linker has two -- a pre-existing gap found by
    this change and recorded, not fixed; `1l`/`2l` have no such field
    at all. On those the backend diagnoses once instead of setting a
    bit the linker ignores, *because a flag that silently does nothing
    produces a link failure that looks like a different bug* -- which
    is `pcc`'s missing ARGBEGIN `default:` for the third time.
    **NOT COMPILED ANYWHERE: kencc needs Plan 9's `<u.h>`/`<libc.h>`,
    so the first build is the VM's** -- the same weaker position `-J`
    shipped from.
    **`-C` WORKS AND THE LINK MODEL'S TWO HALVES ARE NOW BOTH
    MEASURED AT THE LINK.** With `-C` every `redefinition:` is gone,
    and what is underneath is `undefined:` on `_ZN3edg...I...E` names
    -- **template instantiations, every one**, with no vtable, no
    typeinfo, no guard variable and no plain C function among them.
    *That is the prediction written down before the run.*
    **And `LIB=` had to go BEFORE the `<mkone` include**, which is
    load-bearing rather than stylistic: `mkone`'s rule is
    `$O.out: $OFILES $LIB` and mk binds a rule's prerequisites when it
    READS the rule, so an assignment after the include expands to
    nothing. It fails in the quietest way available -- the link runs,
    looks right, and reports the archive's symbols as undefined. The
    link line now ends `.../amd64/lib/ape/libedg.a` and `_ZnwyPv` has
    left the undefined list, which is the confirmation; every other
    `cmd` mkfile here (tclsh, wish, itclsh) already did it this way.
    **AND THE LINK MODEL IS TWO HALVES, WHICH READING THEM AS ONE GOT
    WRONG.** 556 of the 558 `_Z` names are **template instantiations
    emitted NOWHERE**, with **zero** vtables, typeinfo, guard
    variables or thunks among them -- so the output is not
    self-contained for templates *independently of
    `--one_instantiation_per_object`*, and the default already needs a
    prelink step for the very entities OIPO was being weighed for. The
    duplicate half is separate and is now measured from OBJECTS rather
    than annotations: **3124 symbols defined in more than one object,
    6410 surplus definitions**, against the 3094 counted from COMDAT
    annotations -- *two routes to the same number, which is better
    evidence than either alone*.
    **`src/sys_predef.c` IS 315,616 LINES IN ONE TRANSLATION UNIT**
    (`ifc_modules_read.c` 130,330, `expr.c` 120,824; 2.9M lines over
    the 133). A `6c` table limit is the likeliest first answer, and it
    would be kencc's rather than the port's -- worth knowing before
    anything is blamed on EDG.
    **`cpfe` HAS NO `LIB=`, AND THAT IS A QUESTION, NOT A CLAIM.**
    cpfe is itself a translated C++ program so it may want EDG's own
    runtime, and *reading cannot settle it*: `src` holds 145,752
    distinct `_Z`-prefixed tokens, nearly all names it defines itself,
    with ordinary identifiers like `_ZERO` among them. Only the link
    says which are undefined. It is not obviously needed -- EDG is
    built `-fno-exceptions -fno-rtti` and `src` references none of
    `_Znwm`/`_Znam`/`_ZdlPv`/`_ZdaPv`, `__memzero` or
    `__abort_execution` -- so the first link is the measurement and
    the fix, if any, is one line naming `libedg.a`.
    **AND THE LINK IS DOWN TO TWO THINGS, ONE A FLAG AND ONE A REAL
    GAP.** With the regenerated corpus the `undefined:` list is a
    SINGLE name and the rest is a `multiple initialization` family:
    - **`-C` WAS ON `cmd/edg` AND NOT ON `lib/edg`, and an archive is
      what hid it.** `ar` takes duplicate members silently, so
      building `libedg.a` without `-C` looked clean; the clash
      arrives only when the LINK pulls two members defining one
      vague-linkage entity. `6l` answered
      `(295) DATA _ZTSv+0(SB)/1,$118` / `multiple initialization` for
      `_ZTSv`, `_ZTIv`, `_ZTSDn` and `_ZTIDn` -- the `void` and
      `decltype(nullptr)` type strings and `type_info` objects --
      **each defined by BOTH `throw.c` and `typeinfo.c`**, counted
      rather than guessed. `asm.c:548` suppresses on `sym->dupok` and
      `obj.c:908` sets that from the AGLOBL's DUPOK bit, which `-C`
      is the only way to ask for; dupok is a property of the SYM, so
      one side carrying it would have sufficed and **neither did**.
      One line. *(The symbol name in that message --
      `__tourite_needs_stdio_exit:` -- is stale `diag` context and
      names nothing; read the DATA line above it.)*
    - **`__cxa_finalize` IS A GAP EDG LEAVES OPEN, not one this tree
      opened.** `include_c++/cxxabi.h:184` DECLARES the finalization
      pair and `lib_src` defines neither, because on every platform
      EDG targets the C++ runtime supplies them. There is none here.
      `sys/src/ape/lib/edg/cxa_atexit.c` and `dso_handle.c` are the
      two hand-written files in that directory, **not in libap**: a
      C++ ABI name in a library every program links is `reject`
      again, and in `libedg.a` they are members nothing pulls until
      something asks.
      **The ABI is the specification and that matters most where the
      behaviour is easy to approximate.** Itanium 3.3.5.3 wants the
      entry REMOVED BEFORE it is called and the list RE-SCANNED
      afterwards, since a destructor may register more. A plain
      descending `for` loop passes the ordering test and fails both,
      observably -- `switchcase`-style, the naive version replicated
      beside it gives **4 failures naming sections 3, 4a, 4b and 5b**
      while the real one gives 0.
      **`__dso_handle` IS ITS OWN FILE BECAUSE THE HOST ALREADY HAS
      ONE**: glibc's `crtbeginS.o` defines it, so with the two in one
      object the cross-check does not link at all. *That collision is
      the measurement* -- the handle belongs to the C startup and the
      finalizers to the C++ runtime, and the host says so by owning
      exactly one of the two. cpfe references neither: `__dso_handle`
      appears in `src/lower_init.c` only as a STRING LITERAL, because
      cpfe EMITS references to it in the C it generates.
      `cxaatexit-test.c` is the instrument and runs on both machines
      unchanged, 0 failures on gcc.
      **CONFIRMED ON 9front: 0 failures, every section** -- including
      4a/4b (the entry removed BEFORE it is called, re-entry seeing an
      empty list) and 5a/5b (per-`__dso_handle` matching), which are
      the two the ABI specifies and which a plain descending `for` loop
      fails. `__dso_handle` non-null says both sources linked.
      **The FIRST run of it did not link**, and both halves were real:
      the command omitted the extra source AND the file's own 9front
      line omitted `dso_handle.c`, having been copied from the gcc line
      and inherited its single source. *The asymmetry is the file's own
      finding and the header now says so.*
  - **AND THEN cpfe LINKED AND CRASHED ON EVERY RUN -- `fault read
    addr=0x2 pc=0x2` -- AND THE FAULTING ADDRESS IS `argc`.**
    `lib_src/main.c` defines `void _main(void)`, EDG's static-init
    helper, and **`_main` is `6l`'s DEFAULT ENTRY POINT**
    (`6l/obj.c:305` is `INITENTRY = "_main"`;
    `arch/amd64/main9.s:3` is `TEXT _main(SB), 1, $0`). `6l` makes
    that name an SXREF at startup and takes it from the **first
    archive on the link line** that defines it -- and `cmd/edg`
    names `libedg.a` ahead of libap. So the entry became EDG's
    helper: it ran `_Z12__call_ctorsv`, which returns at once
    (`vars.c:49` has `__head` null and `munch_ctors.c` defines
    `_ctors[1] = {0}`), and then executed a plain `RET`. **`main9.s`
    reads the kernel's argument block at `0(SP)`, so `0(SP)` at entry
    holds argc** -- which is what that `RET` popped and jumped to.
    `cpfe --help` is **argc 2**. *A faulting pc equal to the argument
    count could not have arisen any other way*, and it is falsifiable
    with no rebuild: `cpfe` alone must have given `pc=0x1`,
    `cpfe a b c` `pc=0x4`.
    **`-C` IS NOT IMPLICATED, checked rather than assumed of the
    blunt flag standing next to it.** There was no duplicate for
    `dupokall` to silence: `main9.$O` is pulled only to satisfy the
    entry symbol, its other global `_tos` being referenced from
    `profile.c` alone, so with `libedg.a` answering first that member
    never reached the link. *First-archive-wins, and no linker has a
    diagnostic for it.*
    **RENAMED, NOT DROPPED FROM OFILES** -- one file compiled with
    `-D_main=__edg_main`. Nothing anywhere references `_main`, so
    removing the member would link equally well and would throw away
    the only entry point into EDG's static-initialisation machinery.
    **THE STATIC-INIT GAP IS REAL AND RECORDED, NOT FIXED**: nothing
    now calls `_Z12__call_ctorsv`, so a C++ program cpfe translates
    would not run its static constructors. cpfe itself does not need
    it, and does not emit a call to `_main` either -- the name occurs
    in the 133-file corpus exactly twice, both in `lib_src/main.c`,
    with no string literal of it in the emitter. Upstream's
    convention is a crt that calls it; this target's crt
    (`main9.s` -> `_callmain` -> `_apemain` -> `main`) does not.
    **AND ONE `nm` SAYS `_main` IS ALONE, where reading 51 files
    costs a round**: all of `lib_src` through gcc, then
    `nm --defined-only -g`, gives exactly FOUR external definitions
    that are neither `_Z`-mangled nor `__`-prefixed -- `_ctors`,
    `_dtors`, `_main`, `_new_handler` -- and the other three collide
    with nothing. ***`cmd/edg/mkfile` ASSERTED THAT EVERY DEFINITION
    UNDER `lib_src` IS `_Z`-MANGLED OR `__`-PREFIXED, AND THAT
    SENTENCE IS THE ONE THAT WOULD HAVE FOUND THIS.*** It was a
    reading presented as a check; *an almost-true claim is worse than
    none, because it reads as having been verified.* Corrected there.
    **AND THE FIRST BUILD OF THAT FIX DID NOT RUN, FOR THE RECORDED
    rc RULE**: mk hands a recipe to `rc`, where `=` is a SYNTAX
    CHARACTER, so a bare `-D_main=__edg_main` answers
    `/rc/lib/rcmain:24 *eval*:1: token '=': syntax error` -- *a
    message naming rcmain and a token, with nothing in it about this
    mkfile*. Quoted. **Every other `-D` in the tree arrives through
    an expanded `$CFLAGS`**, where mk substitutes after rc has
    parsed, so this is the tree's first LITERAL one and had no
    working precedent in the directory to copy. *The rule was already
    written down here, in its `awk -v name=$name` spelling, and a
    rule recorded for one program's arguments did not transfer to a
    compiler's.
    **CONFIRMED: cpfe RUNS.** It reaches its own command-line parser
    and answers with its own diagnostics -- `invalid option: --help`,
    and `-V` giving `missing source file name`. *That is the
    entry-point diagnosis confirmed behaviourally*, and **both
    messages are cpfe working rather than refusing**: `--help` and
    `-V` are **`eccp` DRIVER** options, cpfe's own table has no
    `help` entry at all and spells the other `--version`, and `-V`
    reaching "missing source file name" means it was ACCEPTED with
    only the operand absent. **`--no_standard_includes` is the
    driver's too** and must not go in a hand-written command: cpfe
    has no standard include path of its own, so there is nothing to
    suppress. The first translation command is in the NOTE; the half
    that matters is **`pcc -c` on the generated C**, since cpfe
    emitting C says the front end runs while pcc accepting it says
    `kencc_targ.h` describes this machine. Use a toy with **no `new`
    and no static constructors** -- those are the two places the
    runtime is reached and the static-init gap above is open.*
  - **AND cpfe'S TARGET IS NOT kencc'S -- `kencc_targ.h` NEVER REACHED
    `target.c`.** The first translation attempt answered
    `check_target_config: must use SoftFloat library`, which is cpfe
    refusing **its own configuration**: `target.c:10642` fires when
    `targ_ldbl_mant_dig == 64`, an 80-bit long double it cannot fold
    without a SoftFloat library it was not built with. **cpfe is
    MULTI-TARGET** -- `target.c:6525` holds EIGHT configurations,
    `fe_init.c:49180` defaults the index to **0**, and entry 0
    (labelled `linux_x86_64`) is `set_legacy_target_config`, built
    from the UNSUFFIXED `TARG_*` macros `kencc_targ.h` overrides.
    **It carries the HOST's values**: `long 8`, `long double 16`,
    `mant_dig 64`. *The `__weak__` suppression (38,245 -> 0) is a
    property of the cpfe BUILD; the `TARG_*` widths are read when
    `target.c` is TRANSLATED, and only the second bakes into the
    committed C.* **Two different macro environments, treated as
    one.** Which mechanism -- absent from the translation command, or
    overridden by `cmake_defines.h` after it -- is NOT settled.
    **AND `--target win64` IS kencc's MODEL EXACTLY, with the cost
    enumerated rather than feared.** Both configurations are in the
    generated source, so their diff is COMPLETE (the `apeabi-probe`
    idiom): **126 `targ_*` assignments, 36 differ.** win64 gets
    right what legacy got wrong -- `long 4`, `long double 8`/53,
    `size_t`/`ssize_t`/`ptrdiff_t` as `long long`, and
    **`targ_setjmp_func "setjmp"`**, which is the exact undefined
    symbol the link reported and the NOTE called "a missed line in
    `kencc_targ.h`". *A diff reproducing, from a different
    direction, a bug found at the LINK is what says it measures the
    right thing.* The windows baggage is **four families and one
    stray**: `wchar_t`/`wint_t` unsigned SHORT (APE says unsigned
    int); five FIELD-ALIGNMENT variables (`double_field_alignment` 4
    against kencc's 8 under `-J` -- *the one most likely to bite,
    unmeasured*); three bit-field rules; pointer-to-member 4 bytes
    with a `short` delta; and `packing_applies_to_base_classes`.
    **Both `targ_microsoft_*` switches are 0 and the config sets no
    mode flags at all** -- `--microsoft` is a separate option that
    `--target win64` does not imply. Watch `jmp_buf` (39 ints
    against legacy's 25 longs, APE's being neither), which matters
    here because **EDG's EH is setjmp-based**.
    **AND THE PREDEFINED MACRO FILE IS WHERE THE REST OF THE
    WINDOWS-NESS LIVES**: with the target set, cpfe next wants
    `lib_win64/predefined_macros.txt`, which we ship for no target.
    **`--clear_flag=use_predefined_macro_file` is not a workaround**
    -- that file is where a win64 build's `_WIN32` and `_MSC_VER`
    come from, so suppressing it is precisely *LLP64 without the
    Windows macros*, and it is the flag this tree's own translation
    recipe already uses. **`--target win64` is a BRIDGE**; the end
    state is entry 0 carrying kencc's values, and *every item on the
    divergence list is a symptom of the same miss*. Command and full
    diff in the NOTE.
  - **AND WITH THAT FLAG cpfe FAULTS -- `fault read addr=0x68
    pc=0x7e2d88` -- WHICH IS NOT A CONFIGURATION PROBLEM.** Option
    parsing and target selection are both past (the same cpfe gave a
    clean `catastrophic error` one flag earlier), so it dies in real
    work. **The HOST cpfe, same commit, same flags, same four
    `--sys_include` directories, exits 0 and writes the expected C** --
    so this is the kencc/libap side, the cfront partition again.
    **The static-init gap is NOT it, and that is measured rather than
    assumed**: the whole 133-file corpus holds exactly ONE
    `__sti__` routine (`fe_init.c:55031`) and its body assigns **0** to
    sixteen members of `diagnostic_counters` -- values a BSS global
    already has. *The gap is real for what cpfe TRANSLATES and inert
    for cpfe itself; two different claims.* A `sys:` trap leaves the
    process **Broken and readable**, so the next step is `acid <pid>`
    and **`lstk()`** (locals, not `stk()`'s arguments -- twice burnt),
    then whether `/tmp/t.c` exists and whether an EMPTY input faults at
    the same `pc`.
  - **AND `lstk()` NAMED IT: EDG FOLDS `offsetof` INTO THE GENERATED C,
    SO THE C CARRIES A STRUCT OFFSET AS AN INTEGER LITERAL.** The stack
    is `predeclare_entities` -> `make_global_operator_new_or_delete_symbol`
    -> `void_type` -> `f_add_orphaned_file_scope_il_entry`, and
    `il.c:26113` is `&tup->orphaned_file_scope_il_entries[entry_kind]
    .last_entry` with `entry_kind` 6 in the frame. The list element is
    **16** bytes (1616/101, from the registration's own arguments), so
    `6*16 + 8` is **104 = 0x68 exactly** -- *the faulting address is
    that subscript of a NULL array, and an address the arithmetic
    reproduces to the digit is a measurement rather than a
    resemblance.* (`argc` printed as `0x360000000d`: the LOW half is
    13, the real count -- **calibrate acid before believing a value**,
    for the second time.)
    **`trans_unit.h`'s `register_trans_unit_variable_with_field` is
    `offsetof(a_translation_unit, field)` and cpfe FOLDS it.** The whole
    corpus holds exactly TWO non-zero ones against 359 zeros -- 400 for
    `orphaned_file_scope_il_entries`, 416 for `module_id_ptr`. If the
    compiler BUILDING the C disagrees, the registration files the
    pointer under the wrong member, the real one stays null, and the
    first read faults far downstream with every type right and every
    symbol resolved.
    ***THE NOTE ALREADY SAID "EDG BAKES IN NO STRUCT SIZES", AND THAT
    WAS TRUE OF THE WRONG QUESTION***: it was measured by grepping for
    cfront's `sizeof X == N` markers, and **a folded `offsetof` has no
    marker** -- indistinguishable from any other integer literal. *The
    sweep that cleared cfront's whole class could not see this one, and
    the sentence read as though the class had been cleared.*
    **`sys/lib/tests/edgtuoff-probe.c` is the instrument, and it is a
    REDUCTION rather than an extraction** -- pointers to `void *`,
    scalars as written, twenty lines, no part of EDG. **The gcc control
    is what licenses that**: the host must print 424/440, the numbers
    `gdb` reads from the DWARF of a real `gcc -g -c mem_manage.c`, and
    it does. *A reduction that reproduces the known answer is
    layout-faithful; one that does not is measuring a different struct.*
    **Predicted for pcc, before the run: 408 and 416+8, a uniform
    8-byte shift.** `unsigned long` 8 -> **4** makes `an_il_header`
    208 -> 184, which is exactly the 24 of 424-400 -- *so the fold
    already used kencc's `long` and the corpus is right about scalar
    widths.* What moves is `a_scope_pointers_block`'s
    `unsigned int x:1; char __dummy[7];` -- EDG's own explicit padding,
    sized for a bit field packed with the `char` -- against **kencc
    allocating a bit field in a whole `tfield` unit**, the one
    non-conformance `-J` does NOT fix and which this file already
    records. 160 -> **168**, everything after it up 8.
    **Refuted if pcc prints 400/416**, which would send the next round
    to `trans_unit.c`'s registration machinery instead of the compiler
    -- *a probe whose two outcomes name two different files is worth
    more than one that can only confirm.* **The fix is a
    re-translation, not a patch**: a hand-edited constant is put back
    by the next regeneration, and the second `offsetof` is the evidence
    for that, since it is shifted by the same 8.
  - **CONFIRMED ON THE VM TO THE DIGIT: 408 and 424, `long` 4,
    `an_il_header` 184, `a_scope_pointers_block` 168.** Every number
    was written down before the run and every one matched, and the two
    halves were independent: 208 -> 184 is the five `unsigned long`,
    which is exactly the 24 of 424-400, *so the fold did use kencc's
    `long`*; 160 -> 168 is the bit-field container. **408 is where the
    array was filed and 400 is `exported_template_file`, so the
    registration wrote over a different live member** -- the `0x68`
    fault is the second consequence and the first has not been looked
    for.
    **AND THE KNOB IS `TARG_MICROSOFT_BIT_FIELD_ALLOCATION`, which
    reverses nothing but completes a plan that had no mechanism in
    it.** `kencc_targ.h` sets no bit-field variable at all.
    `targ_bit_field_container_size` is NOT it -- upstream's comment
    says -1 is already "the base type", a four-byte container, and EDG
    still shared its tail, so *the container governs alignment, not
    sharing*, and stopping at that variable's name would have cost a
    round. The sharing one is a **`TARG_` macro rather than a
    command-line flag**, which is exactly what a pre-include can set,
    and **one of the eight shipped configurations already uses it**.
    **The scope is the corpus, not the struct**: EDG emits explicit
    padding after EVERY bit-field group -- 33 of 33 in `src/il.c`, 958
    `__dummy[N]` across 74 files -- so one rule decides all of them.
    **Section 2 of the probe decides it and is not yet run**: the
    identification *"kencc's rule is MSVC's"* is recalled rather than
    measured, and a 2.9M-line regeneration is too much to rest on a
    recollection, so it asks pcc for `struct{unsigned x:1; char c;}`.
    **4 and 8 means the knob is the fix; 1 and 4 is gcc's shared
    container (the host control, which fires); anything else means the
    knob is not the fix** and the remaining option is kencc's own
    allocation under `-J` -- the recorded non-conformance, five public
    APE headers wide, with `apeabi-probe` already built to price it.
    *What cpfe would EMIT under the knob is deliberately not in the
    probe*: only a rebuilt cpfe can say, so asserting it would measure
    a guess.
  - **MEASURED 4 AND 8 -- kencc IS MSVC's RULE -- AND THE KNOB IS
    STILL NOT THE FIX, WHICH A HOST REBUILD SAID BEFORE ANY
    REGENERATION.** With `TARG_MICROSOFT_BIT_FIELD_ALLOCATION 1` a
    rebuilt cpfe answers `offsetof 4 / sizeof 8` and `sizeof 160` for
    the real shape -- kencc's numbers exactly -- **and the emitted
    padding does not move**: a regenerated `mem_manage.c` still says
    `char __dummy[7]`, character for character.
    **`c_gen_be.c:3132`'s `offset_after_field` names a DIFFERENT
    variable**: its bit-field arm is gated on
    `msvc_is_generated_code_target`, and the other arm gives
    `offset + ceil(bits/8)` = 153, so padding is 160-153 = 7.
    ***`targ_microsoft_bit_field_allocation` is the FRONT END's layout;
    `msvc_is_generated_code_target` is what the C BACK END assumes
    about the compiler that will build its output. Two axes, and I
    conflated them*** -- which is the *"`__weak__` is the BUILD, the
    `TARG_*` widths are the TRANSLATION"* mistake **a third time**,
    and the first time it cost a prediction that had been written
    down. **And the second axis is unavailable**: it gates **18 sites
    in `c_gen_be.c`** plus four more files -- `__cdecl`, `__declspec`,
    the inline model -- and the padding is one of the eighteen.
    **REVERTED**, and not merely as useless: with the real fix it
    would be actively wrong.
    **What is left is kencc's own allocation, and it needs NO
    REGENERATION** -- *the 2.9M lines are already correct for a
    compiler that shares the container* (EDG 160, gcc 160, constants
    400/416 right, all 958 paddings sized for it), so one compiler
    change makes the committed corpus correct as it stands. It is the
    conforming direction too: C11 6.7.2.1p11 leaves the unit to the
    implementation, so kencc is not illegal, but it is alone against
    gcc, clang, EDG and every source-to-source tool's output, and `-J`
    exists to put APE on the model everything else uses.
    **Run `apeabi-probe` FIRST** -- the recorded rule for exactly this
    -- two compiles and an acid diff naming every struct that moves,
    from the compiler itself, before an object is rebuilt.
  - **AND THE PROBE COULD NOT SEE THE CHANGE IT WAS BEING REACHED FOR:
    ITS THIRTY-ONE HEADERS CONTAIN NOT ONE BIT FIELD.** The diff would
    have come back EMPTY and an empty diff there reads exactly like a
    change that costs nothing -- *the void-measurement shape this very
    file records for the `pcc` that appended `-J` to both sides.* Four
    headers added and a four-shape CONTROL beside them, so one dump
    says which allocation rule the compiler in front of it follows.
    **And the axis is two COMPILERS, not `-J` against `-9`**: the
    bit-field line was never gated on `conformalign`, so after the
    rebuild no flag asks for the old rule and the `before` dump must be
    taken first or it is gone.
  - **FOUR public APE headers hold a bit field, swept rather than
    recalled, and only TWO move.** `resolv.h` (`ndots:4, nsort:4` then
    `unsigned char unused[3]`) and `curl.h` (`includeSubDomains:1` then
    `char expire[18]`) -- *both written expecting the shared container;
    `__res_state` is glibc's own layout.* `fenv_arch.h` does NOT move
    (an `int` cannot share a container with only 2 bytes left) and
    `obstack.h` does not (the group is last). `iostream.h` was a false
    hit of a looser grep. **The public headers are a LOWER BOUND**: the
    change reaches every APE compile, and no acid dump of one
    translation unit sees libap's own sources or `external/`.
    *But "looks small" is what the probe is for, and `-J`'s own
    history is that the feared cost and the measured cost were
    different sizes.*
  - **THE BASELINE IS TAKEN AND EVERY NUMBER WAS WRITTEN DOWN FIRST**
    (`tmp/abi-bf-before.acid`, 1751 lines). All four controls answered
    as predicted -- `shares` 4/8, `aligned` 4/8, `trailing` 16 -- and
    **the two that matter are the two that already AGREE with gcc**:
    `aligned` and `trailing` must be IDENTICAL in the after-dump, or
    the patch changed more than the sharing rule, which a shares-only
    check could not have told apart. `split` was left unknown and is
    now answered: **kencc closes the container across base types too**,
    where gcc shares -- a third rule, reported not asserted.
    `__res_state` is the **only** mover in the public surface
    (`unused[3]` at 368 against gcc's 365, so `sort_list` and the size
    move by 4); `fenv_t` and `obstack` are identical under both rules,
    exactly as called. **And the acid dump swept ITSELF** -- every
    `aggr` scanned for two members at one offset, acid's signature for
    a bit-field group -- finding those same three and nothing else, the
    rest being unions. *Two routes to one answer, as with EDG's
    duplicate count.*
  - **AND THE PART NO ACID DUMP CAN SEE IS MEASURED:
    `sys/lib/tests/bfmove-sweep.py`.** `lib/ap` 3 groups / 1 mover;
    `external/` 43093 groups / **268** movers -- and **266 of the 268
    are EDG**, which is the change's purpose arriving as its own cost
    line, since the 958 `__dummy[N]` paddings ARE this shape. The other
    two are `sqlite3.c`'s `struct Column` and curl's
    `curl_hstsentry`, each internal to one package. **The one `lib/ap`
    hit is a LATENT BUG rather than a cost**: `include/meta.h` is
    musl's mallocng header, whose `pad[UNIT - sizeof(ptr) - 1]` is
    sized so the struct is exactly UNIT *only if the bit field shares*
    -- wrong under kencc by construction, costing nothing because
    **nothing includes it**, and the change would FIX it.
    *The sweep's first version allowed `\**` and reported perl's
    `char *subbeg` -- a POINTER, which can never share a 4-byte tail;
    **a regex that matches the type NAME is not one that matches the
    TYPE**, and that was the whole 284 -> 268.*
  - **So the price is paid and it is small**: one public struct, two
    package-internal ones, one dead header, and EDG. *`-J`'s history
    was that the feared and measured costs were different sizes; this
    time they are the same size, and the measurement says so rather

    than the expectation.*
  - **AND `sualign()` IS PATCHED -- SIX LINES, gated on
    `conformalign`.** Under `-J` a bit-field group no longer reserves
    the whole `tfield` unit: `w` advances by `ceil((shift+nbits)/8)`
    from the container's offset, so the next ordinary member sits in
    what is left of it at its own alignment. Gated because native `6c`
    links the host's own `libc.a`, which is the reason `-J` exists.
  - **The sharing opens a hazard the old rule could not have, and it
    is guarded**: `sub.c`'s `makedot` types a bit-field reference as
    `tfield` itself, so every read and write of one is a whole 4-byte
    access at the container -- and with the tail shared, `w` can stop
    at `o+1`. **Under `#pragma pack on` that is a three-byte
    over-WRITE past the end of the object**, since setting a bit field
    is a read-modify-write. One line makes the width cover the last
    container, and *the arithmetic rather than a measurement says it
    is free elsewhere*: any struct with a bit field has `talign >= 4`,
    `o` is a multiple of 4 and `w >= o+1`, so `Asu2` already rounds to
    at least `o+4`. It can only bite where `packflg` took `talign` to 1.
  - **AND THE MODEL REFUTED THE PATCH'S OWN COMMENT BEFORE THE VM SAW
    IT.** I wrote that the `nw > w` guard was load-bearing because
    kencc does not restart the container when an ordinary member sits
    BETWEEN two bit fields -- and **`cc.y`'s `edecor: xdecor` arm does
    `lastbit = 0; firstbit = 1;` for every ordinary declarator**, so
    it does restart and the guard cannot fire today. *An almost-true
    claim presented as verified is worse than none* -- the
    `cmd/edg/mkfile` lesson, caught this time before the build rather
    than after. The guard stays, marked DEFENSIVE: the invariant it
    protects lives two files away.
  - **Predicted, from the model, before the run**: `__res_state`
    `unused` 368 -> **365**, `sort_list` 372 -> **368**, `sizeof`
    456 -> **448** -- a drop of 8, not the 4 I first wrote, because
    `dnsrch` is `char *[]` so `talign` is 8. `structalign-test` under
    `-9` must fail **21** rather than 14. **Refutation conditions**:
    `bf_aligned` or `bf_trailing` moving, any fourth name in the acid
    diff, or a `-9` count that is not 21.
  - **BOTH RUNS ARE IN: 0 under `pcc`, 22 under `pcc -9`** -- and the
    count is not 21, so that condition fired. **It is fully
    attributed**: 40 checks, failing 4/3/4/3/2/1 in sections 1-6, 0 in
    section 8 and **5 in section 9**, which is 22 exactly.
    ***THE COUNT WAS A PREDICTION ABOUT THE INSTRUMENT RATHER THAN
    ABOUT THE COMPILER.*** 14 was measured against a version of
    `structalign-test.c` that has since gained section 8, gained
    section 9 and had section 4 "GROW UP", so sections 1-6 alone now
    answer 17 where they once answered 14; I added my guess at section
    9's movers to a stale base and was wrong in both terms at once.
    *Predict the NAMES, not the total* -- which is this file's own
    "compare per name, never by total" arriving for a prediction
    instead of for a suite diff, and the per-name condition is the one
    that mattered.
  - **AND THE SUBSTANTIVE REFUTATION DID NOT FIRE, which is the
    result.** `bf_aligned` is 8 with `c` at 4 and `bf_trailing` is 16
    **under BOTH rules** -- the two shapes that already agree with gcc
    are untouched, so the patch changed the sharing rule and nothing
    else. `bf_shares` 8 -> **4** with `c` at 1, `bf_split` 8 -> **4**
    with `c` at 1 (so the container is shared across base types now
    too, where kencc used to close it), `bf_overflow` 16 -> **12**
    with `c` at 8 unmoved. Section 8 passes in both runs, as recorded.
  - **A SECOND RULE IS STILL OPEN AND THE PROBE LINES SAY SO.** Under
    `-J`, `struct{char; unsigned:1; char;}` is off(d) 5 / size 8 where
    gcc says **2 and 4**, and `struct{unsigned:1; char; unsigned:1;
    char;}` is off(y) 5 / size 8 where gcc says **3 and 4**. (Under
    `-9` the same two are 8/16 and 12/16, so the change moved both
    toward gcc without reaching it.) *Reported as a PROBE rather than
    asserted*, because it is a different rule from the one the patch
    promised: a bit field FOLLOWING an ordinary member opens a fresh
    container here. Nothing has measured what it costs.
  - **THE AFTER-DUMP IS IN AND THE PREDICTION HELD TO THE DIGIT, WITH
    NOTHING LEFT OVER.** `__res_state` `unused` 368 -> **365**,
    `sort_list` 372 -> **368**, `sizeof` 456 -> **448**;
    `_abi_bf_shares` 8 -> **4** with `c` 4 -> 1; `_abi_bf_split` 8 ->
    **4** with `C` 4 -> 1. **Five names, and the refutation condition
    was "any name beyond those"** -- `_abi_bf_aligned` and
    `_abi_bf_trailing` are ABSENT from the diff, i.e. identical under
    both compilers, which is the half a shares-only check could not
    have told apart. *Every number was written down before the run.*
    The public surface's whole cost is one struct.
  - **AND cpfe GETS MUCH FURTHER: `0x68` IS GONE.** With the rebuilt
    compiler the same `--target win64` command faults at
    **`addr=0x10 pc=0x861d21`** -- a different address AND a different
    pc -- and the stack says how much further: `finish_function_body_`
    `processing` -> `prune_needed_flag_il_walk` ->
    `walk_tree_and_set_needed` -> `mark_as_needed_basic` ->
    `set_routine_definition_needed`. The old fault was in
    `predeclare_entities`, **before the source was read at all**; this
    one is at the end of a function body, in IL pruning. *So cpfe
    parsed the whole translation unit and built IL for it* -- which is
    the `offsetof` fix confirmed behaviourally, and the thing a
    completed build could not say.
  - **`lstk()` CALIBRATED ITSELF, which is the half to read first.**
    The dump prints the SAME value at several widths: `0x1d6d010`
    beside `0x1d6d01000`, `0x1c82ec0` beside `0x1c82ec000`,
    `0x7ffffffde200` beside `0x7ffffffde20000` beside
    `0x1007ffffffde200`. **Three spellings of one value is the
    artefact, not three values** -- acid reading eight bytes for a
    narrower slot, the `cfront` lesson for the third time. *So the
    `__T101...` temporaries are unreadable here and the ARGUMENTS are
    the readable part*, which is the opposite of the cfront round and
    is true for a locatable reason: these are named parameters whose
    mangled names match the declaration.
  - **THE RECURSION IS SOUND FOR SEVEN FRAMES AND THEN IS NOT.**
    `prune_needed_flag_il_walk(entry_ptr=0x1c7efa8, entry_kind=0xb)`
    -> ... -> `walk_tree_and_set_needed(entry_ptr=0x1d7eb80,
    entry_kind=0x19)`, every pointer a real heap address -- and that
    frame then calls ITSELF with **`(entry_ptr=0x8,
    entry_kind=0x45)`**. A child pointer and kind read out of the node
    came back as 8 and 69.
    ***I CALLED 0x45 GARBAGE AND IT IS NOT: IT IS `iek_ms_attribute`,
    AND THE CALL IS CORRECT.*** I counted commas in a 100-line window
    of the generated enum, got "about 61", and concluded 69 was
    outside it. **`an_il_entry_kind` has 114 enumerators**, and worse,
    *the count was the wrong question*: the enum has `#if`-guarded
    members (`MICROSOFT_EXTENSIONS_ALLOWED` and more), so **its
    numbering depends on the macro configuration** -- decode against
    `src/il_def.h` and you get a different answer from the corpus that
    actually runs. Against `src/il.c`'s own config-resolved enum:
    0x0b is `iek_routine`, 0x19 is `iek_scope`, 0x45 is
    **`iek_ms_attribute`**, and the first two match their frames
    exactly. *A WINDOW onto an enum is not the enum, and a header's enum is
    not the generated one.*
    **AND THE SECOND WRONG STEP WAS READING THE LINE NUMBERS IN THE
    WRONG FILE.** `walk_tree_and_set_needed` is **40 lines** in
    `src/il_walk.c` (527-567), so `:2678` and `:3034` are not in it --
    its body is `src/walk_entry.h`, **4457 lines**, included with the
    routine name as a macro. *The `#line` directives follow the
    INCLUDED body, not the file that names the function.*
    **SO THE CALL IS EXACTLY RIGHT AND THE VALUE IS NOT.**
    `walk_entry.h:3032`, inside `case iek_scope:`, is literally
    `walk_list(eptr->ms_attributes, an_ms_attribute_ptr,
    iek_ms_attribute)` -- so the walker was reading `a_scope`'s LAST
    member, and the kind it passed is that line's own constant.
    **`eptr->ms_attributes` answered 8.**
  - **AND `a_scope` IS THE SHAPE OF THE SECOND, STILL-OPEN RULE.**
    `il.c:13799` gives its prefix as three pointers, an `int32_t`
    `number`, an **`unsigned char kind`**, and THEN seven
    `unsigned int :1` -- *a bit-field group FOLLOWING ordinary
    members*, which is the case `structalign-test` section 9 reports
    as a probe and says of: "nothing has measured what it costs".
    **`sys/lib/tests/edgscope-probe.c` measures it**, in EDG's real
    prefix rather than a toy, and its **section 2 is the control**:
    the same shape with the `unsigned char` removed, so the bit field
    is first -- the case `edgtuoff-probe` already measured as agreeing
    once the container is shared. *If the control disagrees too, the
    finding is not about the following rule at all.* gcc: 0
    disagreements, so the reduction reproduces the known answer.
    **WHAT IT WILL AND WILL NOT SHOW, written down before the run.**
    A disagreement says every member of `a_scope` after the bit-field
    group sits where EDG, gcc and the generated C do not expect.
    **It does NOT on its own prove that is the fault** -- kencc
    computes every offset from the same declaration, so a
    different-but-consistent layout costs nothing until something
    BAKES an offset in. *That mechanism is the one already measured
    here*, the folded `offsetof`, and the next question is whether any
    folded constant names a scope member. Predicted: `after` at 40 and
    `sizeof` 48 against the host's 32 and 40.
  - **MEASURED ON THE VM, EXACTLY AS PREDICTED: 40 and 48 against 32
    and 40, and THE CONTROL IS WHAT MAKES IT READABLE.** Section 2 --
    the same prefix with the `unsigned char` removed, so the bit field
    is first -- **PASSES at 32 and 40**, so the disagreement is the
    FOLLOWING rule specifically and not bit fields in general. Section
    3 reproduces `structalign-test`'s two probe shapes to the digit
    (5/8 against 2/4, 5/8 against 3/4). 6 disagreements, 0 on gcc.
  - ***AND THE "NOTHING HAS MEASURED WHAT IT COSTS" LINE IS NOW FALSE,
    WHICH IS THE ROUND'S REAL FINDING: THE CORPUS BAKES THAT OFFSET AS
    A `memcpy` LENGTH.*** Grepping EDG's own sources for `offsetof`
    gives nine sites, and `src/exprutil.h:577` is
    `memcpy((char*)this, (char*)src, offsetof(an_operand, variant))`.
    In the generated C that is **`expr.c:64388`,
    `memcpy(..., 152ULL)`** -- *a folded `offsetof` used as a LENGTH,
    baked as a literal.*
    **AND `an_operand` IS THE SAME SHAPE AS `a_scope`**: two
    `unsigned char` (`kind`, `state`) and then **23 bit fields**
    (`il.c:17826`).
  - ***AND THAT LAST STEP WAS WRONG AND IS WITHDRAWN: 152 IS 152 UNDER
    EVERY RULE.*** I read the shape, saw `a_scope`'s shape, and
    concluded kencc's `offsetof(an_operand, variant)` could not be 152
    -- **without computing it.** The member after the 23 bit fields is
    `a_name_reference name_reference`, and its alignment is **8**, so
    `round(w, 8)` is **24** under HEAD's rule, under the sharing rule
    and under the following rule alike; every member after it, `variant`
    at 152 included, is therefore at gcc's offset in all three. It is
    the `an_operand` row of `sualign-model.py` now -- three columns and
    one answer -- and the host oracle agrees (`gcc` says
    `name_reference` 24, `variant` **152**, `sizeof` 360, read out of a
    compiled object rather than from a guess).
    ***A struct with the broken shape is not a struct with a broken
    offset***: an 8-aligned member after the group absorbs the whole
    1-3 byte difference. *Almost-true-claim trap, for the second time
    in this one function's history, and the first time it cost a
    diagnosis rather than a comment.*
  - **SO THE SECOND RULE IS CONFORMANCE WORK, NOT cpfe's FAULT, AND THE
    WHOLE CORPUS SAYS SO IN ONE COMMAND.** EDG's sources hold exactly
    **two** folded `offsetof` sites -- `trans_unit.h`'s pair, which the
    sharing rule already put back to 400/416, and this one, which never
    moved. Every other number EDG bakes is a real `sizeof` expression.
    **And a consistent-but-different layout costs nothing on its own**:
    pcc lays `a_scope` out and pcc reads it back. So
    `ms_attributes` answering 8 is still unexplained and the `0x10`
    fault needs a different line of attack.
  - **IT IS WORTH FIXING ANYWAY, AND libap IS WHAT NAMES THE PRICE:
    `fenv_t` DISAGREES WITH THE ASSEMBLY THAT FILLS IT.**
    `amd64/include/ape/fenv_arch.h` puts `__opcode:11, __unused4:5`
    after `unsigned short __cs_selector`, which leaves `w` at 18 --
    the `follow` shape exactly. gcc answers `__data_offset` 20 and
    `__mxcsr` **28**; under the sharing rule alone kencc answered 24
    and **32**. **And 28 is not gcc's choice**: `arch/amd64/fenv.s` is
    literally `FSTENV (DI)` then `STMXCSR 28(DI)`, with `fesetenv`
    reading `LDMXCSR 27(DI)` after its `INCQ` -- *the assembly
    hardcodes the x87 FSTENV image, which the struct is a
    transcription of.* **Latent rather than live**: nothing in the tree
    reads a member by name (grep: zero hits outside the header) and
    36 >= 32, so the 32 bytes the assembly writes still fit. It bites
    the first time any C reads `env.__mxcsr` or builds a `fenv_t` by
    hand. *A layout rule found through a C++ front end, paid for by the
    floating-point environment.*
    And it matters more than one struct: **cross-compiling to the other
    ten architectures is the next release's first item**, and a layout
    rule that is wrong is wrong on every backend at once.
  - **PATCHED, in the `sualign()` arm the sharing rule already uses and
    gated on `conformalign` for the same reason.** `gbit` is the whole
    mechanism: `cc.y`'s OBIT arm counts `lastbit` from the GROUP's
    start, so `l->shift` is relative and only `sualign` knows the base.
    **And the crossing test had to be redone here**, which reading the
    grammar does not give you: `cc.y` already splits a group whose bits
    pass `tfield->width*8`, but it tests against a container starting
    at bit 0 of the group, and with the head shared the first container
    has fewer bits left -- so `struct{char c[3]; unsigned a:16;}`, one
    field of one group to the grammar, crosses the 32-bit boundary and
    must begin at the next unit. `o` is bumped and `gbit` carried with
    it, the carry being for the group's LATER fields since the ones
    already placed are already right.
  - **The model is clean before the VM sees it: 0 disagreements with
    gcc over twelve shapes**, with `__res_state` under HEAD's rule
    still reproducing `tmp/abi-bf-before.acid` as the control.
    `structalign-test` section 9 is nine shapes now, the four
    `follow` ones turned from PROBE into assertions -- *a probe is a
    question whose answer nothing promised; once something promises
    it, the probe is the regression test* -- and **`bf_straddle` and
    `bf_straddle2` are the valuable half**: a patch that shares the
    head and forgets the crossing passes `bf_after` and `bf_between`
    and fails exactly those two. 0 failures on gcc, 47 checks.
  - **Predictions, written down before the run.** `pcc` 0 failures and
    `pcc -9` **30** rather than 22 (eight added, two each for
    `bf_after`, `bf_between`, `bf_straddle`, `bf_straddle2`) -- *but
    predict the NAMES, since the last count prediction was 21 against
    a measured 22 and the whole error was in a stale instrument base.*
    `edgscope-probe` 6 -> **0** with its section 2 control still
    clean. `edgtuoff-probe` **unchanged at 408/424**: every bit-field
    group in that chain is preceded by a pointer, so `w` is already
    aligned and `follow` cannot move it. `__res_state` **unchanged**
    at `unused` 365 / `sort_list` 368 / `sizeof` 448, for the same
    reason -- `pfcode` is an `int`. **Refuted if any of those three
    moves**, which would mean the patch reaches structs whose group
    starts on a boundary and therefore does more than share the head.
  - **NOT COMPILED ANYWHERE: kencc needs Plan 9's `<u.h>`/`<libc.h>`,
    so the first build is the VM's** -- and `cd sys/src/cmd && mk
    install` comes before the tree rebuild, as the `sualign` bit-field
    fix already records.
  - **AND THE REBUILD STOPPED IN gmake AGAIN -- SAME MESSAGE, DIFFERENT
    BUG, AND IT IS THE STATIC INITIALISER RATHER THAN THE LAYOUT.**
    `_convM2D: multiple initialization` eighty-odd times, each preceded
    by `DATA function_table_init<8>+16(SB)/4,$16777216`, stride 24.
    **Every number reads out**: `gmake/src/function.c:31`'s
    `struct function_table_entry` is a union, a `const char *`, then
    `len`/`minimum_args`/`maximum_args` as three `unsigned char`, then
    `expand_args:1, alloc_fn:1, adds_command:1` -- the `follow` shape.
    The ordinary members end at byte 19, so the container is the
    aligned unit at **16**, `expand_args` is at shift **24** and
    0x01000000 is 16777216, and the struct is 24 bytes. *An address,
    a width, a value and a stride that the arithmetic reproduces to
    the digit is a measurement rather than a resemblance* -- for the
    third time in this file.
  - ***THE CONTAINER IS NOT THE GROUP, and `init1` was emitting the
    CONTAINER.*** One DATA of `bitaggt->width` -- `tfield`'s four
    bytes -- at the container's offset. Bytes 16, 17 and 18 are the
    three `unsigned char` and have their own one-byte DATA records, so
    the same four bytes really were written twice and **`6l` was
    right**. `cc/dcl.c`'s new `gbitagg()` emits the group's OWN bytes,
    **one at a time**, zeros skipped.
  - **ONE BYTE AT A TIME BECAUSE THE LINKER DECIDES IT**, not for
    taste: `6l/asm.c`'s `datblk` switches `p->from.scale` with
    `case 1, 2, 4, 8` and a `diag("bad nuxi")` default, and a group can
    span **three** bytes (17 bits after a `char`). There is no width to
    ask for, one-byte records always exist, and it needs no
    per-architecture table across the eleven linkers.
  - **AND THE GROUP-BOUNDARY TEST WAS WRONG TOO, which the head rule
    turned from indirect into incorrect.** It compared the container
    OFFSET, and with the container rounded DOWN two groups can share
    one: `struct{unsigned a:1; char c; unsigned b:1;}` puts both at
    container 0, so the two would merge and `c`'s byte would be
    emitted from the bit-field value. It is a gap in the BITS now --
    within a group `cc.y`'s `lastbit` makes the fields contiguous, and
    a boundary always leaves one.
  - ***AND THE TAIL RULE HAD THE SAME DEFECT AND NOTHING EVER FIRED
    IT***, which is the half worth keeping: `struct{unsigned a:1;
    char c;} x = {1,'z'};` puts `c` inside the same container, so the
    four-byte DATA at 0 clobbers it. That rule shipped three commits
    earlier. *A bug that needs two features at once to become
    reachable is still one bug*, and this is the fix for both rather
    than a cost of the second.
  - **MODELLED AGAINST gcc's OWN OBJECT BYTES BEFORE THE VM SEES IT,
    because the last round of this cost a full `distclean` plus
    `install`.** `sys/lib/tests/bitinit-model.py` lays each shape out
    with `sualign-model`, runs `init1`'s accumulation and `gbitagg`'s
    byte loop, and compares with the bytes `gcc` actually puts in the
    object: **7 shapes, 0 problems**, `ftab`'s one live byte at 19
    exactly where the old code wrote four at 16.
    **It tracks a WRITTEN-MASK and reports OVERLAP**, which is the
    half that matters -- it reproduces the LINKER's complaint rather
    than only the final bytes, and *a model that compared only the
    finished image would have scored the old code as correct*, since
    its four-byte write leaves the right bits where the one-byte
    writes had already put them.
    **`--old` is the control and it fires**: the replaced code reports
    **6 of 7** shapes, `ftab` overlapping at **16, 17, 18** -- the
    bytes the real linker named -- with `plain`, the no-bit-field
    shape, staying clean in both modes.
  - **`sys/lib/tests/bitinit-test.c` is the regression test** and
    reads back **every member, ordinary ones included**: a compiler
    with the old emission does not LINK, one with too narrow a span
    gives a wrong bit field, one that writes over a neighbour gives a
    wrong `char`. **Section 0 is the control** -- a struct with no bit
    fields at all -- so a change that breaks `init1` in general says
    so rather than reading as a bit-field span problem. 0 failures on
    gcc, and section 1 is GNU make's shape as an ARRAY, since the real
    failure was one record per entry.
  - **THERE IS A DRIVER NOW: `rc/bin/ape/eccp`, AND `c++` IS A
    ONE-LINE FORWARDER TO IT.** With cfront removed the name is free,
    so `CXX=c++` works for autoconf, for GNU make's default and for
    `sys/src/cmd/transpilers` -- **whose rules did not have to change
    at all**, which is the whole value of having gone through a driver:
    `$CXX -F $CXXFLAGS -o $target` means the same to both front ends,
    and `eccp -F` removes the target on a failure for the same reason
    cfront's arm did. *A rule written against a driver survives the
    front end being replaced; one written against `cfront` would not
    have.* The body lives in `eccp` because that is upstream's name and
    what every document here cites, and because two names with one
    implementation is the only arrangement that cannot drift -- which
    also **retires the recorded `--help`/`-V` trap**: those were always
    DRIVER options and there was no driver.
    It carries `--target win64`, the
    `--clear_flag=use_predefined_macro_file`, the four `--sys_include`
    in order, and the `$status` and `--gen_c_file_name` disciplines
    `cmd/c++lib` paid for; `-F` stops after the translation, for an
    mkfile rule. **`cc` rather than `pcc`, deliberately**: one binary,
    and the NAME chooses the object extension (`pcc.c:75`), so under
    `cc` it is `.o` on all eleven architectures and the driver needs no
    objtype table -- bacon's recipe paid a round for exactly that.
    **NOT PARSE-CHECKED: there is no rc on the build host**, so the
    first run is the VM's.
  - **AND THE NOTE'S OWN COMMAND PARAGRAPH WAS WRONG ABOUT rc, in the
    paragraph that tells the next person how to type it.** It said the
    `=` needs quoting "only in an mkfile recipe". **`=` is a syntax
    character in rc wherever it is not a leading assignment or inside
    quotes** -- the recipe is merely where this tree met it first. A
    bare `--sys_include=/sys/include/ape` is `token '=': syntax error`
    in an rc script and at an rc prompt too; it needs no quoting only
    in **bash**, which is what the recorded run used. Corrected there,
    and `eccp` builds every one by concatenation.
  - **AND EDG'S HEADERS ARE IN `sys/include/ape/c++` NOW, which is the
    directory cfront vacated -- but ONE OF MY THREE OBJECTIONS TO IT
    WAS SIMPLY WRONG.** I wrote that `apehdr-sweep` "compiles every
    header there STANDALONE AS C, so this would turn a gating
    instrument into a column of findings". **It does not look in
    subdirectories at all**: the sweep is `os.listdir` over
    `sys/include/ape` and its 149 is exactly
    `ls sys/include/ape/*.h | wc -l`, so `c++/` has always been outside
    it -- as it must have been, since cfront's seventeen headers sat
    there while the sweep reported 0 findings. *One command on the
    instrument settles what a reading of the directory cannot*, and the
    evidence was in the number the sweep had been printing all along.
    The other two objections were about cfront owning the directory
    (gone) and about nothing including them (the point of
    `--sys_include`).
  - **The collision was real, though, and `git status` printed it.**
    Staging EDG's set over cfront's shows `new.h` and `stdexcept.h` as
    **M** rather than A/D -- the same two names, different content --
    and cfront's `new.h` DECLARED `operator new` with `#pragma lib`
    where EDG's is a shim doing `#include <new>`, **both under the
    guard `__NEW_H`**. *The `Lock` shape and the `reject` shape in one
    file*, and the reason the two sets could never have shared a
    directory.
  - **COMMITTED COPIES, not an install rule, and that is the tree's own
    precedent rather than a new arrangement.** `sys/include/ape/X11` is
    fifteen committed copies of `external/tk/xlib/X11`, and `tcl.h`,
    `tk.h` and `f2c.h` are the same shape; `mount-include` binds
    `sys/include`, so a committed header reaches the VM **through git
    alone** -- which matters because git is the only channel to it and
    `cmd/edg` is deliberately out of the tree's app lists. The install
    rule and the gitignored copy I added one round earlier are both
    gone. **The drift hazard is the `PATH_MAX` class and is named
    rather than left**: `sys/include/ape/c++/README` carries
    `diff -rq -x README` against the original, **empty output being the
    pass** -- `-q` because a bare `diff -r` prints seventy lines of
    content, and the exclusion because ours replaces upstream's.
  - **`include_c99` IS NOT MIRRORED AND NEEDS NO MIRROR**, which is the
    neat half: its one file is `iso646.h`, `sys/include/ape/iso646.h`
    is ours now and is already on `eccp`'s path -- **and ours is the
    better of the two**, since it is guarded `#ifndef __cplusplus`
    where EDG's defines the eleven macros unconditionally. Correct in
    both languages from one file.
  - **THE STL STAYS WHERE IT IS, and the reason is an API rather than a
    namespace.** `paragon_portable_stl` is 720 headers with zero system
    includes, which makes it the best C++ corpus this tree has -- and
    `vector::push_back` returns
    `expected<void, portable_stl_error>` where C++ says `void`, so no
    aliasing or rename recovers it. Installing it as if it were the
    standard library would put something called one where
    `#include <vector>` does not find one: *the
    capability-present-and-not-declared bug with the sign reversed.*
    `eccp`'s `$STLINCL` reaches it, and if it is ever installed it
    wants `sys/include/ape/c++/portable_stl/`, which the one
    `--sys_include` already covers.
  - **AND `include_c99` WAS A ONE-HEADER GAP THAT WAS REAL:
    `iso646.h` DID NOT EXIST IN APExp AT ALL.** That directory holds
    exactly one file, so "what does it have that our headers do not"
    answered in one command -- all of it. Written now, guarded
    `#ifndef __cplusplus` because in C++ all eleven are KEYWORDS.
    **The directory's NAME is the misleading half**: these are C95
    (Normative Addendum 1), not C99, so *"which C99 features does EDG
    need" has the answer none -- it needs a C95 header*, and cpfe never
    reaches ours either way since `edg/include_c99` is searched first.
    **A sweep of all 31 headers the C standards require named four more
    absentees** -- `stdalign.h`, `threads.h` (C11), `stdbit.h`,
    `stdckdint.h` (C23) -- in the 0.6 inventory rather than written
    blind. `apehdr-sweep` 149 headers, 0 standalone findings,
    together-case holding at 8.
  - **AND THE HOST CONTROL IS CLEAN, so the partition holds.** The
    same `/tmp/t.cpp` through the host `cpfe` built from the same
    commit, with the same `--target win64
    --clear_flag=use_predefined_macro_file` and four `--sys_include`:
    **exit 0, 3793 bytes of correct C** -- vtables, Itanium mangling,
    `struct D { struct B __b_1B; }`. So the toy is innocent and EDG is
    innocent, and this is the kencc/libap side -- *the cfront
    partition for the third time.* *(The VM command carried three
    `--sys_include`, not four: `/sys/include/ape` was missing. Inert
    for a toy that includes no headers, and not inert for anything
    else.)*

  - **THERE IS NO C++ STANDARD LIBRARY HERE AND EDG SHIPS NONE, and
    the EXCEPTION MODEL decides what could fill the gap.** `lib_src`
    is the **libsupc++/libc++abi layer** -- new/delete, vtables, RTTI,
    static init, pure-virtual -- and `include_c++`'s eleven headers
    are the LANGUAGE-SUPPORT set, its own README saying *"only those
    headers that require specific magic"*. A grep for
    `basic_string|vector|iostream` across all of them is **empty**.
    **What works with no library at all is the subset EDG ITSELF is
    written in** -- classes, templates, virtual dispatch, RAII,
    `new`/`delete`, plus `bad_alloc`/`type_info`/`initializer_list` --
    which is why the self-translation worked.
    **AND THE LAYERING LOOKS STANDARD WHILE THE EH MODEL IS NOT.**
    EDG's exceptions are **setjmp/longjmp with its own regions**
    (`__eh_curr_region` 138, `an_eh_stack_entry` 99, `setjmp` 19) and
    there are **ZERO `_Unwind_` references in all 51 files**. *Good*:
    no libgcc, no libunwind, no `.eh_frame`, no personality routine --
    the only model that could work on a target with none of those, and
    the reason EDG's C back end exists. *Bad*: **libc++'s EH assumes
    the ITANIUM ABI**, so this is not the usual drop-libc++-onto-a-
    conforming-ABI arrangement the libsupc++ shape suggests. Only the
    grep says so. The type-trait builtins a modern STL needs ARE in
    cpfe's table, checked (`__is_trivially_copyable`,
    `__is_constructible`, `__is_base_of`, `__underlying_type`, ...).
    **AND THE AXIS THAT DECIDES A CANDIDATE IS THE NAMESPACE, NOT
    MAINTENANCE**: APExp exists to build existing software with
    minimal modification, and code written against `std::vector` does
    not compile against `etl::` or `eastl::` however good they are.
    *A renamed STL serves NEW code; only a `std::` one serves a PORT.*
    STLport fits this compiler best and died in 2008; ETL is
    maintained but embedded and fixed-capacity; EASTL is more
    complete; **uClibc++ is the one reported to be `std::` with
    iostreams**, and is inactive at 0.2.5. Ordering, candidates and
    **a provenance paragraph saying which lines are measured and
    which are only recalled or searched** are in the NOTE. *Nothing
    started; none of it blocks anything already working.*
    **AND A FIFTH CANDIDATE WAS MEASURED RATHER THAN RECALLED --
    Paragon's `paragon_portable_stl`, MIT, header-only.** It is the
    first one whose properties were read out of the source instead of
    from memory, and on the technical axes it is better than anything
    on the list above:
    - **ZERO `#include <...>` in all 720 headers.** No host C++
      standard library, no C library headers -- the property that
      disqualifies libc++ and uClibc++ here, satisfied by
      construction rather than by porting.
    - **C++14** (`CMakeLists.txt`'s `CXX_STANDARD 14`), well inside
      what EDG's own self-translation already exercises.
    - **Exception-free is a real mode, not a flag that stops
      throwing**: parallel `exception/` and `noexception/` trees and
      an `expected<T, portable_stl_error>` error channel. *That
      matters more here than anywhere else*, since EDG's EH is
      setjmp-based with its own regions and `lib_src`'s EH has never
      been exercised.
    - **Every `__builtin_*` sits behind `__has_builtin` with a pure
      C++ `generic/` fallback** -- 19 builtins, every one guarded --
      so a compiler with none of them still compiles.
    - The type-trait intrinsics it uses unguarded
      (`__is_trivially_copyable`, `__is_constructible`,
      `__underlying_type`, `__is_class`, `__is_polymorphic`,
      `__is_aggregate`, ...) are **the ones already checked present
      in cpfe's table** in the paragraph above. *Two directions, one
      answer.*
    **AND IT IS STILL DISQUALIFIED FOR THE JOB, ON THE AXIS THIS
    FILE ALREADY NAMES, TWICE OVER.** `namespace portable_stl`, 1283
    occurrences, not `std` -- *a renamed STL serves NEW code; only a
    `std::` one serves a PORT.* **And a rename would not even be
    enough**, which is the stronger half and is the measurement
    rather than the rule: `vector::push_back` returns
    `::portable_stl::expected<void, ::portable_stl::portable_stl_error>`
    where C++ says `void`, so the API differs from the standard's and
    no aliasing recovers it. Coverage is partial too -- string,
    string_view, vector, list, forward_list, map, set, array,
    variant, tuple, function, memory, ranges, algorithm, and **no
    iostreams, locale, regex, threads, deque or unordered
    containers**.
    **SO IT IS THE WRONG ANSWER TO THAT QUESTION AND A GOOD ANSWER TO
    A DIFFERENT ONE: a CONFORMANCE CORPUS for cpfe.** 720 headers of
    heavy template metaprogramming that need no C++ library, no
    exceptions and no runtime support, translated by cpfe and
    compiled by pcc, is a far better measurement of "does this port
    work on real C++" than the toy the NOTE prescribes -- and it
    costs a translation run rather than a port. **And the corpus has
    NO libap SURFACE AT ALL** -- zero system includes -- so a failure
    is cpfe's or kencc's and cannot be libap's. *That partition is
    worth as much as the coverage*: every earlier C++ question here
    has had both halves live at once.
    **THE SUITE IS BIGGER THAN "a number of tests", AND ITS SHAPE IS
    MEASURED**: 110 `.cpp`, **1253 `TEST(`** plus 16 `TEST_F`, and
    **15,897 assertions** -- almost entirely `ASSERT_EQ/TRUE/FALSE`
    and `EXPECT_EQ/TRUE/FALSE` (14,606 of the 15,897), with a short
    tail of `GT/LT/LE/GE/NE`. **What is NOT a plain comparison is
    small and nameable**: 18 `ASSERT_THAT` (gmock matchers), 16
    `TEST_F` fixtures, 22 throw-related, and **19 of the 110 files
    pull the host's `<vector>`/`<list>`/`<algorithm>`** and have to
    be left out. So a gtest SHIM of about ten macros reaches ~92% of
    it -- a behavioural C++ suite this target has never had. *As
    shipped it is not free*: 131 files include `<gtest/gtest.h>`, and
    gtest itself wants a real `std::`, which is the thing that does
    not exist here.
    **AND THE 22 THROW ASSERTIONS ARE THE VALUABLE TAIL RATHER THAN
    THE AWKWARD ONE**: `ASSERT_THROW`/`ASSERT_NO_THROW`/
    `ASSERT_ANY_THROW` are the only exercise of EDG's setjmp-based EH
    this tree could get, and `lib_src`'s EH has never been run.
    ***THE SHIM MUST NOT REGISTER TESTS WITH STATIC CONSTRUCTORS, and
    naming that now is worth a round***: gtest's `TEST()` builds its
    registry from static initialisers, and **nothing calls
    `_Z12__call_ctorsv`** -- the static-init gap recorded above, open
    and unfixed. A suite registered that way would report zero tests
    and read exactly like a translation bug. Generate an explicit
    table of test functions from the `TEST(` names instead, or fix
    static init first and let the suite be what confirms it.
    **AND THE 720 HEADERS DO NOT BELONG IN `sys/include/ape`** -- the
    import under `sys/src/external` is the whole of it, reached with an
    `-I` from whatever translates it, exactly as Tcl's own build reaches
    `-I$TCLSRC/generic`. Three reasons, each already a rule here: a
    public APE header's blast radius is **every package in the tree**
    (`reject` cost a build over one name); `apehdr-sweep` compiles every
    header in that directory **standalone as C**, so 720 C++-only files
    would turn a gating instrument into 720 findings; and **nothing in
    the tree includes them**, which is the test `Plan9libnet.h` was
    deleted for failing. *Install a header when a program needs to say
    `#include <...>` and not before* -- and if a C++ program here ever
    does, it wants its own subdirectory, not the top level.
  - **AND THE RUNTIME ADDS NOTHING libap ALREADY PROVIDES, checked
    rather than assumed.** `lib_src` holds `exit.c`, `main.c`,
    `error.c` and `memzero.c`, which is the shape that cost this tree
    the gnulib `strerror` round -- but **every DEFINITION there is
    `_Z`-mangled or `__`-prefixed**: `exit.c` defines `_Z4exiti`,
    `memzero.c` defines `__memzero`. The plain C names (`memset`,
    `memcpy`, `malloc`, `free`, `abort`, `exit`) appear only as
    DECLARATIONS and resolve to libap rather than replacing it.
    *The filenames read alarmingly and the definitions do not* --
    the declaration/definition distinction the `reject` round cost a
    build over, asked the right way round this time.
    **And EDG bakes in NO struct sizes**, which is the other thing
    cfront's C did and the reason its oracle existed: zero
    `sizeof X == N` markers against cfront's 132, because EDG emits
    real `sizeof` expressions. *kencc computes every layout here*, so
    conforming `-J` is exactly what the generated code wants and
    `cfrontsz-probe`'s whole class of problem does not recur.
    **Both OFILES lists are sound AND complete** -- 51 and 75, no
    name missing a file and no file missing from a list, which are
    different properties and only one of them was checked the time
    the 47-of-97 probe passed its control and measured the wrong
    types. `mkcont-sweep` 0.
  - **Its staging list doubled as a to-do list for our own headers.**
    Eight APE headers could not be included from C++; **four were
    fixed on their own evidence** later in the same session
    (`signal()`'s prototype, the `SIG_*` casts, `features.h`'s
    `hidden`, `bsd.h`'s `getopt`) and a re-translation need not repeat
    them. **The other four are fixed now too, so the staging list is
    closed**: `stdlib.h`'s unguarded `_Noreturn`, its parameter named
    `template`, `unistd.h`'s parameter named `new`, and `signal.h`'s
    `restrict` read as a duplicate parameter name -- every one a
    parameter name or a keyword, so invisible to a C caller.
    *EDG is a stricter compiler than gcc, and that is what it bought.*
  - **AND THE OBVIOUS FIX FOR TWO OF THEM WAS THE ONE THAT HAD JUST
    BROKEN THE BUILD.** `#define _Noreturn` or `#define restrict`
    under `__cplusplus` would put an UNRESERVED name in a public APE
    header that external packages define themselves -- gnulib ships a
    whole `_Noreturn.h`, and a dozen `config.h` here define
    `restrict` -- which is `reject` again, one round later. **The
    bare-word sweep was run FIRST this time**, and it is what chose
    the spellings: everything used is in the reserved
    double-underscore space, which nothing outside an implementation
    may define.
    **Three of the four need no macro at all.** `restrict` becomes
    `__restrict`, which costs nothing because *kencc lexes all three
    spellings to the same `LRESTRICT`* (`cc/lex.c:1652,1678-1679`) --
    and where a package's own `cdefs.h` defines `__restrict` (twelve
    do) it expands to the qualifier or to nothing, correct either way.
    The two parameters are renamed, which no caller can see.
    `__ape_template` was not invented here: **EDG's generated C
    already carries it**, so the staged edit had used this convention
    and the tree now matches its own output.
  - **The control is a before-and-after pair on IDENTICAL staging, and
    it found a FIFTH item.** A C++ translation unit including
    `<stdlib.h>`, `<unistd.h>` and `<signal.h>` gives **12 errors
    before and 1 after** -- and the survivor is `stddef.h:50`
    typedef'ing **`wchar_t`, which is a built-in type in C++**,
    present in BOTH runs and named nowhere in the NOTE's list of
    eight. *Recorded, not fixed.* The half that could have cost the
    tree is the other one: the same unit compiled as **C is 0
    errors**. `apehdr-sweep` 148 headers / 0 findings with the
    together-case holding at its recorded 8; `apdecl-sweep` 0.
    *The first staging recipe differed slightly between the two runs
    and the after-count was re-taken with the before's exact
    commands* -- two compiles differing in anything but the change
    are not a control, which this file records from the `-J` round.


---

## The driver's first end-to-end run, and the template that would not link

`c++ -v -K /tmp/t.cpp` on the VM:

```
  cpfe --c++14 --no_exceptions --no_rtti --target win64
       --clear_flag=use_predefined_macro_file
       --sys_include=/sys/include/ape/c++
       --sys_include=/amd64/include/ape
       --sys_include=/sys/include/ape
       --gen_c_file_name=/tmp/t.eccp.c /tmp/t.cpp
  cc -c /tmp/t.eccp.c
  cc -o a.out t.eccp.o /amd64/lib/ape/libedg.a
  main: undefined: _Z5twiceIiET_S0_ in main
  eccp: FAILED at link on a.out -- cc 70925: 6l: 6l 70926: error
```

**Read the first three lines before the fourth.** cpfe ran with every
flag the NOTE prescribes, emitted C, and `cc -c` compiled that C without
a word — *which is the first time this port has been measured end to end
through the driver rather than by hand*, and it clears the translation,
the target description, the three `--sys_include` and the rc quoting all
at once. The failure is at the LINK and nowhere else.

**`_Z5twiceIiET_S0_` demangles to `int twice<int>(int)`** — a function
template instantiation, which is exactly the half of the link model this
file already measured from the other direction: of the 558 undefined
`_Z` names in cpfe's OWN first link, **556 were template instantiations
emitted nowhere**, with no vtable, typeinfo, guard variable or thunk
among them. *That measurement predicted this one and nobody connected
the two until a three-line toy did it.*

### Why the default can never work here

Under EDG's default instantiation mode an instantiation is emitted by
**no** translation unit; a separate `edg_prelink` pass reads the objects,
decides which one shall carry each instantiation, and re-runs the front
end on it. **We have no prelinker and `mk` cannot naturally express
one** — which is the same objection that kept
`--one_instantiation_per_object` off the table, and the note recording
that already said the default *"needs a prelink step for the very
entities OIPO was being weighed for"*. So this was never a bug to find;
it was a configuration this tree had not chosen yet.

### `--instantiate local`, and what it costs

`cmd_line.c:20611` maps the string `"local"` to `tim_local`, so the mode
is present in the committed corpus rather than only in upstream's
documentation — and `cmd_line.c:2019` shows the long-option parser takes
its value either inline after `=` or as the next argv word, so
`--instantiate local` is two plain words and needs **no rc quoting**,
unlike every other `--opt=value` in the driver.

`local` emits every instantiation a translation unit needs **inside
that unit, with internal linkage**. Nothing is left undefined and nothing
can collide, so it settles both halves of the link model at once — the
half `-C` exists for and the half `-C` could not touch. It is upstream's
answer for a target with neither a prelinker nor COMDAT, which is this
one exactly.

***THE COST IS REAL AND IT IS NOT CODE SIZE.*** Internal linkage means
each object gets its own copy, so a template's static data member, or a
static local inside a template function, stops being one object shared
across the program and becomes one per translation unit. A program whose
correctness rests on that identity — a counter, a registry, a guard — is
**silently wrong rather than loudly broken**. Nothing here has measured
it, and a single translation unit, which is every use so far, cannot
show it. `--instantiate used` is one word away for anyone who wants the
default back and has a prelink step to go with it.

**`-C` stays**, and the reason is that the two flags cover different
entities: `local` governs what the FRONT END emits for templates, while
the `_ZTSv`/`_ZTIv`/`_ZTSDn`/`_ZTIDn` duplicates that `-C` suppresses are
`throw.c` and `typeinfo.c` both defining the `void` and
`decltype(nullptr)` type strings — vague linkage in the hand-written
runtime, which no instantiation mode touches.

**NOT MEASURED. The prediction, written before the run**: the same
command links and `a.out` runs. **Refuted if `_Z5twiceIiET_S0_` is still
undefined**, which would mean the C back end ignores the mode and the
remaining route is a prelink phase after all. A second, cheaper
observable: with `-K` the generated C is kept, so `grep twice
/tmp/t.eccp.c` says whether the instantiation is now IN the file
regardless of what the link does — *and that separates "the flag did
nothing" from "the flag worked and something else is undefined"*, which
the link's own message cannot.

### CONFIRMED: it links

```
  bash-5.3$ c++ -v -K /tmp/t.cpp
  cpfe --c++14 --no_exceptions --no_rtti --target win64
       --clear_flag=use_predefined_macro_file --instantiate local
       --sys_include=... --gen_c_file_name=/tmp/t.eccp.c /tmp/t.cpp
  cc -c /tmp/t.eccp.c
  cc -o a.out t.eccp.o /amd64/lib/ape/libedg.a
  bash-5.3$ ./a.out
  bash-5.3$
```

**The prediction and its refutation condition were both written down
before the run, and the condition did not fire.** `_Z5twiceIiET_S0_` is
gone from the link; the C back end does honour `--instantiate local`,
which reading the option table could establish was *accepted* and never
that it was *acted on*. So the link model is closed on both halves at
last: `local` for the templates, `-C` for the runtime's vague-linkage
typeinfo.

**That makes C++-with-templates a working pipeline here** -- the first
thing in this port that is a capability rather than a stage.

***AND THE RUN PRINTED NOTHING, WHICH IS A SEPARATE QUESTION AND IS NOT
ANSWERED.*** `./a.out` returned to the prompt with no output. There are
two readings and they are a `cat` apart:

  - `/tmp/t.cpp` never printed anything, being a link exercise -- in
    which case silence is correct and there is nothing here;
  - it was meant to print, and did not -- in which case the **static
    constructor gap is the first suspect**, since nothing calls
    `_Z12__call_ctorsv` and a program whose output depends on a static
    initialiser running would be silent in exactly this way.

*A program that links and runs is not a program that works*, and the
difference between those two sentences is the whole of what this round
measured and did not measure. `cat /tmp/t.cpp` and `echo $status` settle
it; **and if it is the second reading, that is a better reproducer for
the static-init gap than anything written down for it so far**, which
has only ever been reasoned about from the corpus.
