/*
 * cxx-stdexcept-test.cpp -- the nine classes `<stdexcept>' owes, by
 * their STANDARD NAMES and in their STANDARD HIERARCHY.
 *
 * ***TWO FAULTS, AND THE FIRST ONE HID THE SECOND.***
 *
 * (1) **EDG ships `<stdexcept>' EMPTY.**  `stdexcept.stdh' is
 * `namespace std { }' with nothing between the braces; the EDG
 * runtime supplies `exception', `bad_alloc' and `type_info' and
 * nothing else.  unrar's `os.hpp:16' is literally
 *
 *     #include <stdexcept> // For std::length_error.
 *
 * and it compiled, because `<vector>' drags `length_error.h' in by
 * another route.  *A header that answers an include and declares
 * nothing is the stub-that-says-nothing family, one layer up from a
 * function* -- and the reason it went unnoticed for a whole port is
 * that the name arrived anyway.
 *
 * (2) **portable_stl's four were TEMPLATES.**
 * `template<class = void> class length_error', so
 *
 *     catch (std::length_error &)
 *
 * -- what every real program writes, and `rar.cpp:95' and
 * `dll.cpp:174' -- answered `invalid use of template-name without an
 * argument list', with g++ offering C++17 class template argument
 * deduction as the explanation.  **Upstream's reason is good and is
 * kept**: a template member `what()' needs no `.cpp' and no COMDAT,
 * which is what lets the library stay header-only.  So the fix is a
 * RENAME AND AN ALIAS -- `length_error_impl<>' with
 * `using length_error = length_error_impl<>' -- and not a real class,
 * which would be a question about the link model instead.
 *
 * Six of the nine (`runtime_error', `domain_error',
 * `invalid_argument', `range_error', `overflow_error',
 * `underflow_error') did not exist in any form.
 *
 * ---- SECTION 2 IS THE ONE THAT CONSTRAINS THE DESIGN --------------
 *
 * The cheap way to write ten exception classes is one template and
 * ten aliases of it, which gives ten SIBLINGS -- and then
 * `catch (std::logic_error &)' does not catch a thrown
 * `std::length_error', a guarantee real code leans on
 * ([stdexcept.syn] fixes the derivations).  Section 2 asserts six of
 * those derivations, and *it is the half of this file that would have
 * caught the obvious shortcut.*
 *
 * ---- THIS FILE INCLUDES ONLY `<stdexcept>', ON PURPOSE ------------
 *
 * That is fault (1)'s regression test and it cannot be written as an
 * assertion: if `<stdexcept>' alone does not declare these names, the
 * file does not compile.  Hence `strcmp' rather than `std::string' in
 * section 3 -- *pulling in `<string>' would reintroduce exactly the
 * second route that hid the bug.*
 *
 * `bad_function_call' got the same rename and is NOT here: it belongs
 * to `<functional>', and including that would defeat the paragraph
 * above.
 *
 * ---- THE REFERENCE ARM, AND THE ONE PLACE IT DIFFERS --------------
 *
 *     # against APExp's library (the subject)
 *     g++ -std=c++14 -w -nostdinc++ \
 *         -D__EDG_RUNTIME_USES_NAMESPACES=1 -D__EDG_STD_NAMESPACE=std \
 *         -D__EDG_CONSTEXPR_ENABLED__=1 \
 *         -D__EDG_SIZE_TYPE__='decltype(sizeof(0))' \
 *         -I <shim> -I sys/include/ape/c++ \
 *         cxx-stdexcept-test.cpp <exception-ctor stubs> -o t && ./t
 *
 *     # against libstdc++ (the reference)
 *     g++ -std=c++14 -DREFERENCE cxx-stdexcept-test.cpp -o tref && ./tref
 *
 * ***THE `MK' MACRO IS A RECORDED DEVIATION AND NOT A CONVENIENCE.***
 * The standard gives every one of these a `(string const &)' and a
 * `(char const *)' constructor and NO default constructor;
 * portable_stl's have only a default one.  So the reference arm has
 * to say `T("message")' where the subject says `T()', and the two
 * arms are therefore asking the same question about the HIERARCHY and
 * the NAMES -- which is what this file is for -- and not about
 * construction.  The missing constructors are in 0.6's inventory,
 * with why they were not added here: a `string' overload in these
 * headers is a circular include (`basic_string' throws
 * `length_error'), and storing a bare `char const *' is a silent
 * dangle for any argument without static storage duration, which is
 * worse than the compile error a caller gets now.
 *
 * ---- ITS CONTROL IS A COMPILE FAILURE, WHICH IS WORTH SAYING ------
 *
 * Against the pre-fix headers staged out of git -- the empty
 * `stdexcept.stdh', the four templates, and the six new ones deleted
 * -- this file **does not compile**, 42 errors, the first being
 * `'logic_error' is not a member of 'std'`.  So the control cannot be
 * a failure COUNT, and a run that prints nothing is the expected
 * result rather than a lost measurement.  *That is also why the file
 * is written so that every line of section 1 is a hard error before
 * the fix: a build that reaches `main' has already answered most of
 * the question.*
 *
 * On Plan 9:  eccp -o cxx-stdexcept-test cxx-stdexcept-test.cpp
 *
 * ***AND IT MUST BE BUILT WITHOUT `--no_exceptions'***, which
 * `rc/bin/ape/eccp' passes by default: this file is `throw' and
 * `catch' and nothing else, so a build that drops exceptions measures
 * the driver.  If `eccp' refuses, that refusal IS the result and
 * should be reported rather than worked around.
 *
 * Prints PASS/FAIL per case and exits with the number of failures.
 */

#include <stdexcept>

#include <stdio.h>
#include <string.h>

#ifdef REFERENCE
/* libstdc++'s have the standard's constructors and no default one. */
#define MK(T) T("message")
#else
#define MK(T) T()
#endif

static int fails = 0;

static void chk(char const *tag, bool ok) {
  if (ok) {
    printf("PASS %s\n", tag);
    return;
  }
  ++fails;
  printf("FAIL %s\n", tag);
}

/*
 * A case is `throw X, catch Y' and the ASSERTION IS THAT THE HANDLER
 * RAN.  `caught' starts false and only the handler sets it, so a
 * `catch (...)' fallback after it distinguishes "the wrong handler
 * ran" from "nothing was thrown" -- and without the fallback an
 * escaping exception would `terminate' and the run would end with no
 * count at all, which is the one failure mode this file could not
 * otherwise report.
 */
#define CASE(TAG, THROWN, CAUGHT)                                  \
  do {                                                             \
    bool caught = false;                                           \
    bool other  = false;                                           \
    try {                                                          \
      throw MK(::std::THROWN);                                     \
    } catch (::std::CAUGHT &) {                                    \
      caught = true;                                               \
    } catch (...) {                                                \
      other = true;                                                \
    }                                                              \
    if (other) {                                                   \
      printf("     (a different handler ran)\n");                   \
    }                                                              \
    chk(TAG, caught);                                              \
  } while (0)

int main(void) {
  setvbuf(stdout, (char *)0, _IOLBF, 0);
  printf("cxx-stdexcept-test: starting\n");

  /*
   * 1. Each of the nine by its OWN name.  ***THIS SECTION IS THE
   * COMPILE AND NOT THE RUN***: before the rename every line of it
   * was a hard error, so a build that gets this far has already
   * answered most of the question.
   */
  printf("\n-- 1. the nine, each by its own name --\n");
  CASE("logic_error", logic_error, logic_error);
  CASE("runtime_error", runtime_error, runtime_error);
  CASE("domain_error", domain_error, domain_error);
  CASE("invalid_argument", invalid_argument, invalid_argument);
  CASE("length_error", length_error, length_error);
  CASE("out_of_range", out_of_range, out_of_range);
  CASE("range_error", range_error, range_error);
  CASE("overflow_error", overflow_error, overflow_error);
  CASE("underflow_error", underflow_error, underflow_error);

  /*
   * 2. The hierarchy.  See the header: one template plus nine aliases
   * would pass section 1 completely and fail every line of this.
   */
  printf("\n-- 2. the derivations [stdexcept.syn] fixes --\n");
  CASE("length_error is a logic_error", length_error, logic_error);
  CASE("out_of_range is a logic_error", out_of_range, logic_error);
  CASE("domain_error is a logic_error", domain_error, logic_error);
  CASE("invalid_argument is a logic_error", invalid_argument, logic_error);
  CASE("range_error is a runtime_error", range_error, runtime_error);
  CASE("overflow_error is a runtime_error", overflow_error, runtime_error);
  CASE("underflow_error is a runtime_error", underflow_error, runtime_error);
  CASE("logic_error is an exception", logic_error, exception);
  CASE("runtime_error is an exception", runtime_error, exception);

  /*
   * 3. `what()'.  Not the TEXT -- that is implementation-defined and
   * the two arms would differ by construction -- but that it answers
   * at all and that a derived class does not inherit its base's
   * answer, which is what a `using' alias to the WRONG template would
   * produce while passing everything above.
   */
  printf("\n-- 3. what() --\n");
  {
    ::std::length_error e = MK(::std::length_error);
    ::std::logic_error  b = MK(::std::logic_error);
    chk("length_error::what() is not null", e.what() != (char const *)0);
    chk("logic_error::what() is not null", b.what() != (char const *)0);
#ifdef REFERENCE
    printf("     (the reference arm's two carry the same message by\n");
    printf("      construction, so the next case is subject-only)\n");
#else
    chk("the derived answer is its own", strcmp(e.what(), b.what()) != 0);
#endif
  }

  printf("\ncxx-stdexcept-test: %d failure(s)\n", fails);
  return fails;
}
