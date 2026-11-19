/*
 * cxx-stdarg-probe.cpp -- which <stdarg.h> does cpfe read, and what
 * does it define?
 *
 * ***A PROBE AND NOT A TEST***: it asserts nothing, because what it
 * asks is what a particular toolchain happens to do.  Report what it
 * prints.  It is a RUNNABLE PROGRAM, for the reason in the next
 * section but one.
 *
 * WHERE IT CAME FROM.  The first `mk install' of
 * `sys/src/ape/c++/unrar' compiled two files and stopped on the third:
 *
 *	strfn.cpp, line 538: error:
 *	    identifier "va_copy" is undefined
 *	  va_copy(argscopy, arglist);
 *
 * **`va_list' on the line ABOVE it is fine, and so are `va_start',
 * `va_arg' and `va_end' elsewhere in the same file.**
 *
 * ---- WHAT THE FIRST RUN ANSWERED, AND WHAT IT LED TO ---------------
 *
 * ***`__STDARG' IS NOT DEFINED***, so **APExp's `stdarg_arch.h' was
 * never read** -- that file is `#ifndef __STDARG' / `#define __STDARG'
 * and it is the only place `va_copy' is defined.  cpfe reported
 * `identifier "__STDARG" is undefined', which is the diagnostic for a
 * name that reached the COMPILER: a macro, even one defined as empty,
 * could not have.
 *
 * **And stock 9front's APE header is ruled out by the same datum**:
 * APExp's own `stdarg.h' comments record that the stock file takes the
 * same `__STDARG' guard -- which is how it once DISABLED APExp's -- so
 * if cpfe had read that one, `__STDARG' would be defined.
 *
 * **But section 2 said `va_start', `va_arg' and `va_end' ARE MACROS**,
 * and that is the datum that named the mechanism: a macro came from
 * somewhere, and with no header read the only candidate left is cpfe.
 * ***IT INTERCEPTS THE INCLUDE.***  `preproc.c:15496':
 *
 *	if (pass_stdarg_references_to_generated_code &&
 *	    (strcmp(name,"stdarg.h")==0 || (C++ && name=="cstdarg")))
 *	  { proc_stdarg_include(is_cstdarg);
 *	    actual_include_was_suppressed = 1; }
 *	else open_file_and_push_input_stack(...);
 *
 * -- `actual_include_was_suppressed', so **no file is opened and the
 * search never happens**.  `proc_stdarg_include' then enters
 * `va_start'/`va_arg'/`va_end' unconditionally and `va_copy' only
 * `if (va_copy_macro_allowed)', which is set in a C-mode path and for
 * `microsoft_version >= 1900' and **nowhere in C++**.  *So the search
 * order, the binds and the header were all innocent*, and the one
 * question this file was built to leave open -- whether `<stdarg.h>'
 * was opened at all -- is answered NO by the source rather than by
 * `-H'.  (`-H' is worth running anyway: it CONFIRMS the absence, and
 * `eccp' had no `-H' either until this round.)
 *
 * ***AND THE REAL FINDING IS NOT `va_copy', IT IS SECTION 3.***
 * `sizeof(va_list)' came back **24** -- cpfe's own, folded into a
 * literal, since with the builtin in force `sys_predef.c:312656' does
 * `#define va_list __gnuc_va_list'.  APExp's `<stdarg.h>' is
 * `typedef char *va_list', which is **8**.  Those cannot both be right
 * for a vararg function DEFINED in C++ and compiled by `pcc'.  Nothing
 * built through `eccp' had ever run one, which is why it had cost
 * nothing -- *and section 4 exists so that it is measured rather than
 * reasoned about.*
 *
 * The fix is `--no_stdarg_builtin' (`cmd_line.c:9769'), now passed by
 * `eccp', which makes cpfe open the real header -- so cpfe and `pcc'
 * agree because they read the SAME FILE.  **Patching
 * `va_copy_macro_allowed' in the corpus would have cleared the error
 * message and left the ABI split standing.**
 *
 * **What this probe must say once the flag is in**: section 1
 * `__STDARG' DEFINED, section 2 all five names macros, section 3
 * `sizeof' **8** and not 24, section 4 unchanged and still right.
 * *Section 4 being right BOTH ways would mean the 24-byte va_list was
 * never actually reached* -- a real result, and the one that would
 * retire this paragraph.
 *
 * ---- IT IS A RUNNABLE PROGRAM, AND THE FIRST VERSION WAS NOT -------
 *
 * ***THE FIRST VERSION DUMPED `PROBE_x [subject]' LINES TO BE READ
 * AFTER THE PREPROCESSOR, AND THAT CANNOT WORK HERE.***  Two faults,
 * and the second is the one worth keeping:
 *
 *   1. Those lines are not valid C++, so they were guarded behind
 *      `-DCXX_STDARG_PROBE_DUMP'.
 *   2. **`eccp -F' IS NOT A PREPROCESS.**  It is cpfe doing a FULL
 *      TRANSLATION that stops before `cc' -- every C++ error in the
 *      file is reported -- so the guarded lines were compiled after
 *      all, and the run reported the probe's own syntax.  *`eccp' had
 *      no `-E' at all*; it has one now (`--preprocess').
 *
 * And a dump has a third weakness this run demonstrated: **the second
 * question was lost to a parse CASCADE.**  Line 115 answered
 * `__STDARG' and line 116's `_APEXP_STDARG_H_' came back only as
 * `expected a ";"', which says nothing.  *A probe that asks several
 * questions in one file must not let the first answer destroy the
 * rest*, which an `#ifdef` cannot do and a stray token can.
 *
 * So every question is an `#ifdef' inside `main' now, each printing
 * its own line, all of them reached in one run.
 *
 * ---- HOW TO RUN IT ------------------------------------------------
 *
 *	eccp -o /tmp/stdargprobe sys/lib/tests/cxx-stdarg-probe.cpp
 *	/tmp/stdargprobe
 *
 * Then, for the file names -- the one thing the program cannot say:
 *
 *	eccp -E -H sys/lib/tests/cxx-stdarg-probe.cpp >/tmp/pp.c
 *
 * `-H' is `--trace_includes'; its list goes to stderr, so it stays on
 * the screen while the preprocessed text goes to the file.  **A line
 * naming `stdarg.h' under `/$objtype/include/ape' or
 * `/sys/include/ape' means APExp's was opened** and the question moves
 * to why its contents did not take; no such line means cpfe never
 * opened one and every name came from its builtins.
 *
 * ***AND RUN THE C SIDE, BECAUSE IT SPLITS THE ANSWER IN HALF***:
 *
 *	cp sys/lib/tests/cxx-stdarg-probe.cpp /tmp/sp.c
 *	pcc -o /tmp/sp /tmp/sp.c && /tmp/sp
 *
 * ***THE COPY IS NOT OPTIONAL AND THE FIRST ATTEMPT DID NOT RUN.***
 * `pcc cxx-stdarg-probe.cpp' answers `cc: no files to compile or
 * load' -- `pcc.c' dispatches on the SUFFIX and `.cpp' is not one it
 * compiles, so the command exits having done nothing, with a message
 * that reads like an empty argument list rather than a refusal.  *A
 * run that compiled nothing and a run that found nothing wrong both
 * print almost nothing*, which is this tree's rule about silence
 * arriving one directory from where it was written down.
 *
 * (The file is C89 but for its `//'-free comments, and `va_list' is
 * the only type it names.)  `pcc' and `eccp' search the same two
 * header roots in the same order, so:
 *
 *   * **C right and C++ wrong** -> the fault is cpfe's, and its
 *     `--sys_include' list in `rc/bin/ape/eccp' is where to look.
 *   * **BOTH wrong** -> the header or the bind, and it has been that
 *     way for every C program all along -- which would be the more
 *     interesting of the two, since nothing in this tree has needed
 *     `va_copy' before.
 *
 * *One command each, and the pair says which half of the toolchain to
 * open.*  A run of only the C++ side cannot tell them apart.
 */

#include <stdarg.h>

#include <stdio.h>

/*
 * The one case that must NOT be compiled unless asked for: if
 * `va_copy' is absent this is unrar's error in six lines rather than
 * in a 49-file build.  Behind a `-D' because the whole point of the
 * rest of the file is to REPORT that absence rather than die of it.
 *
 *	eccp -c -DCXX_STDARG_PROBE_USE sys/lib/tests/cxx-stdarg-probe.cpp
 */
#ifdef CXX_STDARG_PROBE_USE
static void probe_use(char const *fmt, ...) {
  va_list a;
  va_list b;
  va_start(a, fmt);
  va_copy(b, a);
  va_end(b);
  va_end(a);
}
#endif

/*
 * SECTION 4's SUBJECTS: vararg functions DEFINED HERE, which is the
 * only shape that can show the va_list disagreement.
 *
 * ***A CALL TO `printf' CANNOT***, and that is why these exist.  The
 * CALLER's side of a vararg call is the target's calling convention,
 * which cpfe takes from `target.c' and which the whole program
 * already depends on -- every `printf' above works, so it is right.
 * The CALLEE's side is `va_list' itself, and it is in force only
 * where the `...' function is COMPILED THROUGH `eccp'.  libap's
 * `printf' is `pcc''s, so it uses APExp's `va_list' whatever cpfe
 * thinks; these do not.
 *
 * `probe_mix' takes an `int' and a `double' because the two travel
 * differently on amd64 and a `va_arg' that walks the wrong structure
 * is far likelier to get the second wrong than the first.
 */
static int probe_sum(int n, ...) {
  va_list ap;
  int i;
  int s = 0;
  va_start(ap, n);
  for (i = 0; i < n; i++) { s += va_arg(ap, int); }
  va_end(ap);
  return s;
}

static double probe_mix(int n, ...) {
  va_list ap;
  int i;
  double d;
  double s = 0.0;
  va_start(ap, n);
  for (i = 0; i < n; i++) {
    s += (double)va_arg(ap, int);
    d = va_arg(ap, double);
    s += d;
  }
  va_end(ap);
  return s;
}

#ifdef va_copy
/*
 * Only compiled when `va_copy' exists, so this file builds either
 * way -- the whole point of the rest of it being to REPORT the
 * absence rather than die of it.  It walks the list twice through a
 * copy, so a `va_copy' that aliases rather than copies gives a
 * readably wrong answer instead of the right one.
 */
static int probe_twice(int n, ...) {
  va_list ap;
  va_list bp;
  int i;
  int s = 0;
  va_start(ap, n);
  va_copy(bp, ap);
  for (i = 0; i < n; i++) { s += va_arg(ap, int); }
  for (i = 0; i < n; i++) { s += va_arg(bp, int); }
  va_end(bp);
  va_end(ap);
  return s;
}
#endif

int main(void) {
  setvbuf(stdout, (char *)0, _IOLBF, 0);
  printf("cxx-stdarg-probe: starting\n");

  /*
   * 1.  WHICH HEADER WAS READ, asked through the guards each one
   * defines.  `__STDARG' is `stdarg_arch.h''s and ALSO stock 9front's,
   * so it does not by itself say whose -- but its ABSENCE rules out
   * both at once, which is the answer that matters here.
   */
  printf("\n-- 1. which <stdarg.h> was read --\n");
#ifdef __STDARG
  printf("  __STDARG          DEFINED     (a stdarg_arch.h was read:\n");
  printf("                                 APExp's or stock 9front's)\n");
#else
  printf("  __STDARG          not defined (NEITHER APExp's stdarg_arch.h\n");
  printf("                                 NOR stock 9front's was read)\n");
#endif
#ifdef _APEXP_STDARG_H_
  printf("  _APEXP_STDARG_H_  DEFINED     (APExp's <stdarg.h> wrapper was read)\n");
#else
  printf("  _APEXP_STDARG_H_  not defined (APExp's wrapper was not read)\n");
#endif
  /*
   * ***THE VERDICT IS THE PAIR, NOT EITHER GUARD.***  This block used
   * to hang a conclusion off `_APEXP_STDARG_H_' alone -- "so the
   * wrapper ran and <stdarg_arch.h> did not" -- which was written for
   * the case where the wrapper is found and the arch header is not,
   * and silently assumed the two were MUTUALLY EXCLUSIVE.  They are
   * not: the healthy state has BOTH defined, and the first run after
   * `--no_stdarg_builtin' printed that sentence beside a defined
   * `__STDARG', contradicting itself in its own output.
   *
   * *A conclusion attached to one of two conditions is wrong in every
   * case the other one changes*, which is this file's own rule about
   * reporting rather than concluding, broken inside the report.
   */
  printf("  -> ");
#if defined(__STDARG) && defined(_APEXP_STDARG_H_)
  printf("wrapper AND arch header both read: the expected state\n");
#elif defined(_APEXP_STDARG_H_)
  printf("wrapper read, arch header NOT: the include of\n");
  printf("     <stdarg_arch.h> missed -- a bind or search-order fault\n");
#elif defined(__STDARG)
  printf("arch header read WITHOUT the wrapper: reached directly\n");
#else
  printf("NEITHER was read -- cpfe suppressed the include\n");
  printf("     (preproc.c:15496; pass --no_stdarg_builtin)\n");
#endif

  /*
   * 2.  WHICH NAMES ARE MACROS.  A name that is a macro came from a
   * header; one that is not and still works is cpfe's own.  *That
   * distinction is the whole finding*: `va_list' is a predefined TYPE
   * in cpfe (`symbol_tbl.c'), and `va_start'/`va_arg'/`va_end' are
   * builtins, so a build can get all four with no header at all.
   */
  printf("\n-- 2. which names are macros --\n");
#ifdef va_start
  printf("  va_start          is a macro\n");
#else
  printf("  va_start          NOT a macro (cpfe builtin)\n");
#endif
#ifdef va_arg
  printf("  va_arg            is a macro\n");
#else
  printf("  va_arg            NOT a macro (cpfe builtin)\n");
#endif
#ifdef va_end
  printf("  va_end            is a macro\n");
#else
  printf("  va_end            NOT a macro (cpfe builtin)\n");
#endif
#ifdef va_copy
  printf("  va_copy           is a macro\n");
#else
  printf("  va_copy           NOT a macro   <-- unrar's stop\n");
#endif
#ifdef __va_copy
  printf("  __va_copy         is a macro   (the pre-C99 spelling)\n");
#else
  printf("  __va_copy         NOT a macro\n");
#endif
#ifdef __builtin_va_copy
  printf("  __builtin_va_copy is a macro\n");
#else
  printf("  __builtin_va_copy NOT a macro (it is a cpfe BUILTIN, which\n");
  printf("                                 an #ifdef cannot see)\n");
#endif

  /*
   * 3.  `va_list' names a type whatever the answers above, or this
   * file would not have compiled.  Printed anyway, because *a reader
   * who sees only section 1's "not defined" should be able to tell
   * that the program still built* -- the whole puzzle is that four of
   * the five names work with no header.
   */
  printf("\n-- 3. va_list --\n");
  {
    va_list a;
    (void)a;
    printf("  va_list           names a type (sizeof %d)\n", (int)sizeof(va_list));
    printf("                    (8 = APExp's `char *'; 24 = cpfe's own\n");
    printf("                     __gnuc_va_list, i.e. the builtin path)\n");
  }

  /*
   * 4.  DOES A VARARG FUNCTION COMPILED THROUGH THIS TOOLCHAIN WORK?
   * The one question section 3's number raises and cannot answer.
   * Reported and not asserted, like everything else here -- but the
   * wanted value is printed beside each, so a wrong answer is
   * readable without knowing the arithmetic.
   */
  printf("\n-- 4. a vararg function DEFINED here and CALLED --\n");
  {
    int s = probe_sum(5, 1, 2, 3, 4, 5);
    printf("  probe_sum(1..5)   = %d\t(want 15)%s\n",
           s, (s == 15) ? "" : "   <-- WRONG");
  }
  {
    double d = probe_mix(2, 10, 0.5, 20, 0.25);
    printf("  probe_mix         = %.3f\t(want 30.750)%s\n",
           d, (d > 30.74 && d < 30.76) ? "" : "   <-- WRONG");
  }
#ifdef va_copy
  {
    int s = probe_twice(3, 10, 20, 30);
    printf("  probe_twice       = %d\t(want 120)%s\n",
           s, (s == 120) ? "" : "   <-- WRONG");
  }
#else
  printf("  probe_twice         skipped -- va_copy is not available\n");
#endif

  printf("\ncxx-stdarg-probe: done\n");
  return 0;
}
