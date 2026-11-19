/*
 * cxx-ehchain-probe.cpp -- what is ON the EH stack when EDG's
 * unwinder gives up.
 *
 *	eccp -fexceptions -o cxx-ehchain-probe cxx-ehchain-probe.cpp
 *	./cxx-ehchain-probe
 *
 * and the gcc reference arm, which must print `caught' and must NOT
 * reach the handler:
 *
 *	g++ -std=c++14 -DREFERENCE -o /tmp/ehref cxx-ehchain-probe.cpp
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
 * `extern "C"' reaches it.  **Only `next' and `kind' are declared
 * here**, at offsets 0 and 8, and nothing is ever allocated through
 * this declaration -- a prefix is enough to WALK a list and getting
 * the union wrong cannot matter.  (`an_eh_stack_entry' is
 * `{ next; kind; variant; }' in `throw.c' and `struct __C7' is the
 * same three in a client TU -- checked, so the two sides agree about
 * where `kind' is.)
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

#ifndef REFERENCE

/*
 * The walk only ever reads these two members; see the header for why
 * a prefix declaration is sound and the union is not needed.
 */
struct eh_entry {
  struct eh_entry *next;
  unsigned char kind;
};

extern "C" struct eh_entry *__curr_eh_stack_entry;

static char const *kindname(unsigned char k) {
  switch (k) {
  case 0: return "old_try_block";
  case 1: return "function";
  case 2: return "throw_spec";
  case 3: return "throw_processing_marker";
  case 4: return "vec_new_or_delete";
  case 5: return "TRY_BLOCK";
  case 6: return "NOEXCEPT";
  }
  return "???";
}

static void dumpchain(char const *when) {
  struct eh_entry *e;
  int n;

  printf("  chain at %s: head = %p\n", when, (void *)__curr_eh_stack_entry);
  n = 0;
  for (e = __curr_eh_stack_entry; e != 0 && n < 64; e = e->next, n++)
    printf("    [%2d] %p kind %u %s\n", n, (void *)e,
           (unsigned)e->kind, kindname(e->kind));
  printf("  chain at %s: %d entr%s\n", when, n, n == 1 ? "y" : "ies");
}

#else

static void dumpchain(char const *when) {
  printf("  chain at %s: not available on the reference arm\n", when);
}

#endif

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

int main(void) {
  setvbuf(stdout, 0, _IOLBF, 0);
  printf("cxx-ehchain-probe: starting\n");

  std::set_terminate(on_terminate);

  printf("section 1: chain before any try\n");
  dumpchain("entry");

  printf("section 2: throw and catch by type, same function\n");
  try {
    printf("  inside try, about to throw\n");
    dumpchain("inside try");
    throw Boom(7);
  } catch (Boom &b) {
    printf("  caught Boom, v = %d\n", b.v);
  } catch (...) {
    printf("  caught by ellipsis -- the type match failed\n");
  }

  printf("section 3: throw and catch by ellipsis only\n");
  try {
    throw Boom(9);
  } catch (...) {
    printf("  caught by ellipsis\n");
  }

  printf("\ncxx-ehchain-probe: terminate handler reached = %d\n", reached);
  printf("cxx-ehchain-probe: %s\n",
         reached ? "FAIL (unwinder gave up)" : "PASS (exceptions work)");
  return reached;
}
