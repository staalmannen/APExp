/*
 * cxx-ehchain-probe.cpp -- what is ON the EH stack when EDG's
 * unwinder gives up.
 *
 *	pcc -c cxx-ehchain-walk.c
 *	eccp -fexceptions -o cxx-ehchain-probe cxx-ehchain-probe.cpp \
 *		cxx-ehchain-walk.$O
 *	./cxx-ehchain-probe
 *
 * and the gcc reference arm, which must print `caught' and must NOT
 * reach the handler:
 *
 *	gcc -DREFERENCE -c -o /tmp/ehwalk.o cxx-ehchain-walk.c
 *	g++ -std=c++14 -DREFERENCE -o /tmp/ehref cxx-ehchain-probe.cpp \
 *		/tmp/ehwalk.o
 *
 * ***THE WALK IS IN A SEPARATE C FILE AND THAT IS A FINDING, NOT A
 * STYLE CHOICE.***  A C++ TU that uses exceptions at all already has
 * cpfe's own `struct __C8 *__curr_eh_stack_entry;' in its generated
 * C, so declaring the name here is a redeclaration with a different
 * type -- `external redeclaration of: __curr_eh_stack_entry', which
 * is what the first version of this probe answered.  The generated
 * tag is per-TU, so no spelling would have agreed.  `cxx-ehchain-
 * walk.c' has the walk and the reasoning; `eccp' already passes
 * `*.o'/`*.[1-9kqv]' to the linker.
 *
 * ---- WHAT THIS IS FOR ------------------------------------------------
 *
 * `unrar' and `cxx-stdexcept-test' both end with
 *
 *	C++ runtime abort: terminate() called by the exception
 *	handling mechanism
 *
 * (`lib_src/eh_util.c:214'), and `cxx-stdexcept-test' aborts on the
 * FIRST throw with the `try' and the `catch' in the same function --
 * so the reproducer is ONE translation unit, the cross-TU reading is
 * dead and `-C' is cleared, it having been a suspect only for the
 * cross-TU case.
 *
 * **The EH code IS emitted**, measured rather than assumed: the
 * generated C of the one-file reproducer has 118 references to
 * `__curr_eh_stack_entry' and 20 `setjmp's, so "cpfe emitted nothing
 * and `--exceptions' must be passed positively" is refuted.
 *
 * **And the kinds pushed are 5, 6 and 1**, from
 * `grep -o 'kind) = ((unsigned char)[0-9]*U)' stdex.c'.  The
 * enumeration is `src/lower_eh.c:6650':
 *
 *	0 ehsek_old_try_block	4 ehsek_vec_new_or_delete
 *	1 ehsek_function	5 ehsek_try_block
 *	2 ehsek_throw_spec	6 ehsek_noexcept
 *	3 ehsek_throw_processing_marker
 *
 * so **try-block entries are pushed, in quantity** -- and a kind 6
 * appears that EDG's own runtime never uses.
 *
 * ---- WHY A PROBE AND NOT MORE READING --------------------------------
 *
 * `throw.c''s search loop reaches `terminate()' by TWO different
 * routes and they are different bugs:
 *
 *   * `:1494' -- `destination_ehsep == 0', i.e. the walk ran off the
 *     end without matching any handler.
 *   * `:1396' -- a kind 6 (`noexcept') entry, which SETS the
 *     destination and stops the search, because a throw escaping a
 *     `noexcept' frame must terminate.  That is the language rule,
 *     so this arm can be CORRECT BEHAVIOUR over a wrong stack.
 *
 * **Both print the same message**, so reading cannot separate them
 * and the chain has to be looked at.  Two candidates were cleared by
 * reading first, which is why they are not in this file:
 * `--no_rtti' is innocent (`lower_eh.c' consults `rtti_enabled'
 * ZERO times; the single use in `lower_il.c' is an assertion, not a
 * gate), and the `:1302' head assertion passes, since its message
 * would have named itself instead.
 *
 * ---- WHY IT NEEDS NO REBUILD OF ANYTHING -----------------------------
 *
 * `std::set_terminate' is in EDG's runtime (`eh_util.c',
 * `exception.stdh:50'), so the handler runs INSIDE the failing
 * process with the chain still standing -- no patch to the generated
 * corpus, no `libedg.a' rebuild, no `acid', and no question about
 * whether `abort()' leaves a broken process in `/proc'.
 *
 * `__curr_eh_stack_entry' is a plain C name in EDG's generated C, so
 * `cxx-ehchain-walk.c' reaches it with an ordinary `extern' and this
 * file calls that one function through `extern "C"'.
 *
 * ---- HOW TO READ IT, STATED BEFORE THE RUN ---------------------------
 *
 *   marker(3) -> try_block(5) ...
 *	The handler WAS reachable and the type match rejected it.
 *	The question moves to the exception-type-specification
 *	tables -- and note `catch (...)' alone should give
 *	`catch_entries == 0', which `throw.c' treats as an
 *	unconditional match, so a `...' that does not catch would
 *	mean the entry was never VISITED rather than not matched.
 *
 *   marker(3) -> noexcept(6) ...
 *	A `noexcept' frame is in the way and `terminate()' is then
 *	CORRECT.  The bug is a push without its pop -- the thrown
 *	object's own constructor is the candidate, portable_stl
 *	marking nearly everything `noexcept' -- and the question
 *	becomes push/pop balance, not the unwinder.
 *
 *   no kind 5 anywhere
 *	The try-block entry is emitted (grep says so) and was not
 *	pushed at run time: a third bug, in the region bookkeeping.
 *
 *   chain is EMPTY, or `__curr_eh_stack_entry' is 0
 *	The global the TU pushes onto is not the global `throw.c'
 *	reads.  That is the link model, and `-C' marking every GLOBL
 *	`DUPOK' is then back in the frame after all -- *a flag that
 *	suppresses a diagnostic can hide the bug the diagnostic
 *	would have named.*
 *
 * **`reached' is load-bearing.**  A handler that never ran and a
 * chain that is empty print the same nothing without it, which is
 * this tree's `edg_dbg_checks' rule.
 *
 * The gcc arm is the control: there the terminate handler must NOT
 * run at all, so a `REFERENCE' build that prints the chain report is
 * the probe's own bug rather than a finding.
 */

#include <stdio.h>
#include <stdlib.h>
#include <exception>

static int reached = 0;

/*
 * The whole of the walk is in `cxx-ehchain-walk.c'; see the header
 * for why it cannot live in this file.  `char *' and not
 * `char const *', to match a C file compiled by pcc without arguing
 * about a prototype across two languages.
 */
extern "C" void eh_dump(char *when);

static void dumpchain(char const *when) { eh_dump((char *)when); }

static void on_terminate(void) {
  reached = 1;
  printf("\n*** terminate handler REACHED ***\n");
  dumpchain("terminate");
  fflush(stdout);
  /*
   * _exit and not abort: abort re-enters the runtime, and a second
   * failure on the way out would overwrite the one finding this
   * probe exists to print.
   */
  exit(3);
}

struct Boom {
  int v;
  Boom(int x) : v(x) {}
};

/*
 * ---- WHY THIS TAKES A CASE NUMBER ------------------------------------
 *
 * ***ONE TERMINATE HIDES EVERY CASE AFTER IT.***  The first version
 * ran all the throws in one process, and the handler `exit's -- so
 * the ellipsis-only case never ran, and its silence looked like
 * nothing rather than like a case that was never reached.  That is
 * this tree's rule about a section that can kill the process, which
 * `mmaptrim-probe' already takes an argument for.
 *
 * **The cases are chosen to separate four things the single case
 * could not**, because the data now says the impossible: the
 * type-specification table is CORRECT -- `ets[1] flags 0x30', bit 16
 * set with bits 1 and 128 clear, which is the ellipsis -- so
 * `check_exception_type_specifications' must return non-zero and the
 * destination must be set.  `__eh_curr_region' going 65535 -> 0 says
 * independently that it was not: the cleanup loop at `throw.c:1426'
 * is `while (ehsep != destination_ehsep)', so a null destination
 * walks the WHOLE chain and takes `saved_region_number' (0) from the
 * function entry.  Two readings of the same run agreeing on
 * something the source forbids is why these cases exist.
 *
 *   0  no throw at all.  The control, and it must PASS -- a matrix
 *      where every case fails cannot tell a broken throw from a
 *      broken probe.
 *   1  `throw 42' caught by `...'.  No constructor, no destructor, a
 *      fundamental type_info: the shortest path through the runtime
 *      there is.
 *   2  `throw 42' caught by `catch (int)'.  Same object, but now the
 *      match is a real type comparison -- `throw.c:892' is pointer
 *      identity on the type_info OR on its NAME STRING, never
 *      `strcmp', so 1 passing and 2 failing would name duplicate
 *      type_info and put `-C' back in the frame.
 *   3  `throw Boom(7)' caught by `...'.  Adds a CONSTRUCTOR, which
 *      is what makes `__throw' read `object_evaluation_complete' and
 *      decide whether to call `__exception_started' itself
 *      (`throw.c:1082').  1 passing and 3 failing puts the fault in
 *      the object-construction path and not in the unwinder.
 *   4  `throw Boom(7)' caught by `catch (Boom &)', with an ellipsis
 *      fallback: the original failing case, kept last.
 *
 * Exit status is the finding: 0 caught as intended, 3 terminate
 * reached, 4 caught by the WRONG handler -- which is a different bug
 * from both and would otherwise print as a pass.
 */
static int run_case(int c) {
  switch (c) {
  case 0:
    printf("  case 0: no throw (control)\n");
    return 0;

  case 1:
    printf("  case 1: throw 42, catch (...)\n");
    try {
      dumpchain("inside try");
      throw 42;
    } catch (...) {
      printf("  caught by ellipsis\n");
      return 0;
    }
    return 4;

  case 2:
    printf("  case 2: throw 42, catch (int)\n");
    try {
      dumpchain("inside try");
      throw 42;
    } catch (int v) {
      printf("  caught int, v = %d\n", v);
      return 0;
    } catch (...) {
      printf("  caught by ELLIPSIS -- the int match failed\n");
      return 4;
    }

  case 3:
    printf("  case 3: throw Boom(7), catch (...)\n");
    try {
      dumpchain("inside try");
      throw Boom(7);
    } catch (...) {
      printf("  caught by ellipsis\n");
      return 0;
    }
    return 4;

  case 4:
    printf("  case 4: throw Boom(7), catch (Boom &)\n");
    try {
      dumpchain("inside try");
      throw Boom(7);
    } catch (Boom &b) {
      printf("  caught Boom, v = %d\n", b.v);
      return 0;
    } catch (...) {
      printf("  caught by ELLIPSIS -- the Boom match failed\n");
      return 4;
    }
  }
  printf("  no such case %d\n", c);
  return 2;
}

int main(int argc, char **argv) {
  int c, rc;

  setvbuf(stdout, 0, _IOLBF, 0);
  c = argc > 1 ? atoi(argv[1]) : 0;
  printf("cxx-ehchain-probe: starting, case %d\n", c);

  std::set_terminate(on_terminate);

  printf("chain before any try\n");
  dumpchain("entry");

  rc = run_case(c);
  if (rc != 0)
    return rc;

  printf("\ncxx-ehchain-probe: terminate handler reached = %d\n", reached);
  printf("cxx-ehchain-probe: %s\n",
         reached ? "FAIL (unwinder gave up)" : "PASS (exceptions work)");
  return reached;
}
