/*
 * cxx-stdarg-probe.cpp -- WHICH <stdarg.h> does cpfe read, and does it
 * define `va_copy'?
 *
 * ***A PROBE AND NOT A TEST***: it asserts nothing, because what it
 * asks is what a particular toolchain happens to do.  Report what it
 * prints.
 *
 * WHERE IT CAME FROM.  The first `mk install' of
 * `sys/src/ape/c++/unrar' compiled `rar.cpp' and `strlist.cpp' and
 * stopped on the third file:
 *
 *	strfn.cpp, line 538: error:
 *	    identifier "va_copy" is undefined
 *	  va_copy(argscopy, arglist);
 *
 * **`va_list' on the line ABOVE it is fine, and so are `va_start',
 * `va_arg' and `va_end' elsewhere in the same file.**  So a
 * `<stdarg.h>' was found and read -- cpfe would otherwise have said
 * `cannot open source file' -- and the one it read defines everything
 * except `va_copy'.
 *
 * ***AND READING THE TREE CANNOT SAY WHICH FILE THAT IS.***
 * `amd64/include/ape/stdarg_arch.h' DOES define `va_copy';
 * `amd64/include/ape/stdarg.h' and `sys/include/ape/stdarg.h' both
 * chain to it; `mount-include' binds all of them into place and
 * `apexp-sh' runs `mount-include'; nothing in `sys/include/ape',
 * `sys/include/ape/c++' or EDG's `include_c++' defines `__STDARG' or
 * ships a second `stdarg.h'.  *Every reading says it should work*,
 * which is exactly the point at which this tree's own rule says to
 * stop reading and ask the machine.
 *
 * TWO CANDIDATE MECHANISMS, and the probe separates them:
 *
 *   (a) **cpfe read somebody else's `stdarg.h'** -- stock 9front's,
 *       which keeps it in the architecture directory and has no
 *       `va_copy' (APExp's own header comments record that stock file
 *       taking the same `__STDARG' guard, which is how it once
 *       DISABLED APExp's).  Then `__STDARG' is defined and `va_copy'
 *       is not.
 *   (b) **cpfe read no `stdarg.h' at all** and `va_list'/`va_start'/
 *       `va_arg'/`va_end' came from its own builtins, which EDG front
 *       ends have -- with `va_copy' absent or gated by mode.  Then
 *       `__STDARG' is NOT defined.
 *
 * ---- HOW TO RUN IT ------------------------------------------------
 *
 * ***START WITH `--trace_includes', WHICH NAMES THE FILE OUTRIGHT***
 * and so settles (a) against (b) in one command.  cpfe has it
 * (`src/cmd_line.c'), and `eccp' passes any `--option' through:
 *
 *	eccp -F -o /tmp/stdarg.c --trace_includes \
 *	     sys/lib/tests/cxx-stdarg-probe.cpp
 *
 * The line naming `stdarg.h' is the whole answer: a path under
 * `/amd64/include/ape' or `/sys/include/ape' is APExp's and should
 * have `va_copy'; no such line at all is (b).  **`--list_macros' is
 * the second half** -- it dumps every macro cpfe holds, so
 * `grep va_ ' over its output says what is defined rather than what
 * ought to be.
 *
 * Then the preprocessed output, which answers the rest at once.
 * ***`-F' AND NOT A COMPILE***: `#error' stops at the first one and
 * would cost a run per question.
 *
 *	eccp -F -o /tmp/stdarg.c sys/lib/tests/cxx-stdarg-probe.cpp
 *	tail -20 /tmp/stdarg.c
 *
 * Every line below beginning `PROBE_' comes out with its macros
 * expanded, and each subject is in BRACKETS so that expanded and
 * unexpanded cannot be confused:
 *
 *	PROBE_vacopy [va_copy(dst, src)]   -> VERBATIM: not a macro
 *	PROBE_vacopy [((dst) = (src))]     -> expanded: it is defined
 *	PROBE_guard  [__STDARG]            -> VERBATIM: not defined, so
 *	                                      APExp's header was not read
 *
 * **A preprocessor may split an expansion across lines**, so read the
 * last thirty rather than grepping for whole lines -- gcc does exactly
 * that with glibc's `__builtin_va_copy', which is how this file's own
 * output was checked on the build host before it shipped.
 *
 * ***AND RUN THE C SIDE TOO, BECAUSE IT SPLITS THE ANSWER IN HALF***:
 *
 *	pcc -E sys/lib/tests/cxx-stdarg-probe.cpp >/tmp/stdarg-c.c
 *	tail -20 /tmp/stdarg-c.c
 *
 * `pcc' and `cpfe' search the same two header roots in the same order
 * (`/$objtype/include/ape' then `/sys/include/ape'), so:
 *
 *   * **C is right and C++ is wrong** -> the fault is cpfe's: either
 *     its include search or its builtins, and `eccp''s `--sys_include'
 *     list is where to look.
 *   * **BOTH are wrong** -> the fault is the header or the bind, and
 *     it has been there all along for every C program too -- which
 *     would be the more interesting of the two, since nothing has
 *     needed `va_copy' before.
 *
 * *One command each, and the pair says which half of the toolchain to
 * open.*  A run of only the C++ side cannot tell them apart.
 */

#include <stdarg.h>

/*
 * ***THE DUMP LINES ARE NOT VALID C++ AND ARE GUARDED FOR THAT
 * REASON.***  They exist to be looked at after the preprocessor, so a
 * plain compile of this file must not see them -- otherwise the one
 * run that reproduces unrar's error reports six errors of this probe's
 * own making instead.  *A probe whose own syntax is the first thing to
 * fail cannot report anything about its subject.*  Caught on the build
 * host with `g++ -fsyntax-only' before this file shipped.
 */
#ifdef CXX_STDARG_PROBE_DUMP
PROBE_guard [__STDARG]
PROBE_apexp_arch [_APEXP_STDARG_H_]
PROBE_valist [va_list]
PROBE_vastart [va_start(ap, x)]
PROBE_vaend [va_end(ap)]
PROBE_vacopy [va_copy(dst, src)]
#endif

/*
 * And the real thing, so that a compile (rather than `-F') reproduces
 * unrar's failure in six lines instead of in a 49-file build:
 *
 *	eccp -c -fexceptions sys/lib/tests/cxx-stdarg-probe.cpp
 *
 * If that compiles, `va_copy' is fine here and unrar's `strfn.cpp'
 * reaches it by some route this file does not -- which would be a
 * third mechanism and worth knowing.
 */
static void probe_use(const char *fmt, ...) {
  va_list a;
  va_list b;
  va_start(a, fmt);
  va_copy(b, a);
  va_end(b);
  va_end(a);
}

int main(void) {
  probe_use("");
  return 0;
}
