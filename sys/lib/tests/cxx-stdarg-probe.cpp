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
 * ---- WHAT THE FIRST RUN ANSWERED ----------------------------------
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
 * ***SO WHERE DO THE OTHER FOUR NAMES COME FROM?  cpfe ITSELF.***
 * `symbol_tbl.c:33309' is
 * `full_enter_symbol("va_list", 7, sk_type, ...)' -- cpfe enters
 * `va_list' as a TYPE of its own -- and `lexical.c' carries
 * `__builtin_va_start', `__builtin_va_end' and `__builtin_va_copy' as
 * builtins.  `sys_predef.c:313963' predefines the typedef
 * `__builtin_va_list'.  *`va_copy' is the one name in that family that
 * is not predefined as a MACRO*, which is exactly the shape of the
 * failure.
 *
 * What is NOT yet settled is whether `<stdarg.h>' was opened at all.
 * `--trace_includes' (cpfe's `-H', `cmd_line.c:8837') names every file
 * it opens and answers that outright.
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
 *	pcc -o /tmp/stdargprobe-c sys/lib/tests/cxx-stdarg-probe.cpp
 *
 * (`pcc' compiles this file as C: it is C89 but for the `//'-free
 * comments, and `va_list' is the only type it names.)  `pcc' and
 * `eccp' search the same two header roots in the same order, so:
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
  printf("  _APEXP_STDARG_H_  DEFINED     (APExp's <stdarg.h> wrapper WAS\n");
  printf("                                 read -- so the wrapper ran and\n");
  printf("                                 <stdarg_arch.h> did not)\n");
#else
  printf("  _APEXP_STDARG_H_  not defined (APExp's wrapper was not read)\n");
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
  }

  printf("\ncxx-stdarg-probe: done\n");
  return 0;
}
