/*
 * cxx-wstring-test.cpp -- basic_string's mutators on a character type
 * WIDER THAN ONE BYTE.
 *
 * ***SIX SITES IN THE C++ LIBRARY PASSED AN ELEMENT COUNT WHERE
 * `memcpy'/`memmove'/`memset' WANT BYTES, AND EVERY ONE OF THEM IS
 * CORRECT FOR `char'.***  `sizeof(char)' is 1, so nothing reachable
 * through `std::string' can show it -- which is why the whole
 * library, `cxx-library-test' and `cxxlib-host.sh --instantiate'
 * were green while `std::wstring' silently corrupted itself on
 * insert, erase, append and replace.
 *
 * It came out of `std::to_wstring', which unrar uses ten times:
 *
 *     std::wstring(L" -md=") + std::to_wstring(3)
 *       ->  0020 002D 0000 0000 0000 0033      (" -\0\0\0" "3")
 *
 * Five elements were asked for and five BYTES were copied: one
 * element and a quarter, the rest left as the zero fill.  The sites:
 *
 *   basic_string.h   insert(index, sv)        memcpy, count unscaled
 *                    erase(index, count)      memmove, count unscaled
 *                    append(sv)               memcpy, count unscaled
 *                    replace(pos, n, sv)      memcpy, count unscaled
 *                    replace(pos, n, n2, ch)  memset -- see below
 *   short_object_    replace(...)             memmove, count unscaled
 *     optimization.h                          (the PRIMARY template)
 *
 * **The `memset' one is a type bug and not an arithmetic one.**
 * `memset' writes one byte per unit whatever the count, so filling a
 * `wstring' with `L'Q'' gave `0x00515151' in the first element and
 * nothing in the rest.  Scaling its count would not have fixed it;
 * `traits_type::assign(ptr, count, ch)' is the per-element fill.
 *
 * ---- TWO MORE THAT LOOK LIKE THE SAME BUG AND ARE NOT -------------
 *
 * `short_object_optimization.h' holds TWO classes: a primary template
 * and a `sizeof(value_type) == 1' specialisation.  The specialisation
 * carries the same `replace' line, and its copy constructor wrote
 * `memset(&temp.get()[size() * sizeof(value_type)], 0, 1)' -- an
 * index that is scaled and a width that is not, which reads exactly
 * like the bug above.  ***BOTH ARE CORRECT BY CONSTRUCTION THERE***,
 * because that class only ever serves a one-byte type.  They were
 * changed to match the primary template so the two read the same, and
 * they are NOT findings.  *The first draft of this header counted
 * eight bugs; the specialisation condition is one line above the
 * class and says so.*
 *
 * The consequence for this file: a case that goes through the
 * specialisation can never fail, so section 1 is not merely a
 * control by intent -- it is one by construction.
 *
 * ---- THE CONTROL IS gcc's OWN LIBRARY, AND IT IS ONE FLAG ---------
 *
 * Every assertion here is a standard-library rule, so this file is
 * correct against libstdc++ as written.  **Build it BOTH ways**: the
 * second is a reference implementation answering the same questions,
 * which is the strongest control available for this and costs one
 * flag.
 *
 *     # against APExp's library (the subject)
 *     g++ -std=c++14 -w -nostdinc++ \
 *         -D__EDG_RUNTIME_USES_NAMESPACES=1 -D__EDG_STD_NAMESPACE=std \
 *         -D__EDG_CONSTEXPR_ENABLED__=1 \
 *         -D__EDG_SIZE_TYPE__='decltype(sizeof(0))' \
 *         -I <shim> -I sys/include/ape/c++ \
 *         cxx-wstring-test.cpp <exception-ctor stubs> -o t && ./t
 *
 *     # against libstdc++ (the reference)
 *     g++ -std=c++14 -DREFERENCE cxx-wstring-test.cpp -o tref && ./tref
 *
 * `<shim>' is the extensionless-forwarder directory
 * `cxxlib-host.sh'/`cxxapp-host.sh' stage, and the stubs are one TU
 * defining `std::bad_alloc::bad_alloc()' and
 * `std::exception::exception()': this library is header-only and
 * mangles those names the same as libstdc++, which defines them for
 * ITS classes.  *That is a harness limit, not a finding.*
 *
 * On Plan 9:  eccp -o cxx-wstring-test cxx-wstring-test.cpp
 *
 * ---- WHY char IS IN HERE AT ALL ------------------------------------
 *
 * Section 1 is `char' and is expected to pass against a BROKEN
 * library.  It is here so that a run which fails everything is
 * distinguishable from one that fails the wide types: *a test whose
 * every section fails says the harness broke, and without a section
 * that must pass there is no way to tell.*
 *
 * Prints PASS/FAIL per case and exits with the number of failures.
 */

#include <stdio.h>
#include <string>

static int fails = 0;

template<class t_string> static void chk(char const *tag, t_string const &got,
                                         typename t_string::value_type const *want) {
  ::std::size_t n = 0;
  while (want[n] != typename t_string::value_type()) {
    ++n;
  }
  bool ok = (got.size() == n);
  for (::std::size_t j = 0; ok && j < n; ++j) {
    ok = (got[j] == want[j]);
  }
  if (ok) {
    printf("PASS %s\n", tag);
    return;
  }
  ++fails;
  printf("FAIL %s\n     got  size=%d :", tag, (int)got.size());
  for (::std::size_t j = 0; j < got.size(); ++j) {
    printf(" %08lX", (unsigned long)(got[j]));
  }
  printf("\n     want size=%d :", (int)n);
  for (::std::size_t j = 0; j < n; ++j) {
    printf(" %08lX", (unsigned long)(want[j]));
  }
  printf("\n");
}

/*
 * The eight mutator cases, once per character type.  `L' is the
 * literal prefix as a template argument cannot be, so each case names
 * its own literals and the SET is what is shared.
 *
 * ***EVERY CASE MUST CROSS THE SHORT-STRING BOUNDARY FOR AT LEAST ONE
 * TYPE, OR IT PASSES AGAINST THE BROKEN LIBRARY.***  The SSO buffer
 * is 23 BYTES, so it holds 23 `char' and only 5 `wchar_t': a case
 * built to look reasonable for `char' never reallocates, and the
 * first draft of `append' passed for exactly that reason while
 * `+=' on the same data failed.  The sizes below are chosen against
 * the wide capacity, and both an in-place case and a growing one are
 * kept wherever the two take different paths.
 */
#define MUTATORS(T, S, P, NAME)                                                     \
  do {                                                                              \
    typedef ::std::basic_string<T> S;                                                \
    { S s(P##"xy"); s.insert(0U, S(P##"ABCD"));                                      \
      chk<S>(NAME ": insert(0,\"ABCD\") on \"xy\" [grows]", s, P##"ABCDxy"); }       \
    { S s(P##"xy"); s.insert(0U, S(P##"A"));                                         \
      chk<S>(NAME ": insert(0,\"A\") on \"xy\" [in place]", s, P##"Axy"); }          \
    { S s(P##"xy"); s.insert(1U, S(P##"ABCD"));                                      \
      chk<S>(NAME ": insert(1,\"ABCD\") on \"xy\"", s, P##"xABCDy"); }               \
    { S s(P##"abcd"); s.append(S(P##"xy"));                                          \
      chk<S>(NAME ": append(\"xy\") on \"abcd\"", s, P##"abcdxy"); }                 \
    { S s(P##"ab"); s += P##"cdefgh";                                                \
      chk<S>(NAME ": += \"cdefgh\" on \"ab\"", s, P##"abcdefgh"); }                  \
    { S s(P##"abcdefgh"); s.erase(2U, 3U);                                           \
      chk<S>(NAME ": erase(2,3) on \"abcdefgh\"", s, P##"abfgh"); }                  \
    { S s(P##"abcdefgh"); s.replace(1U, 2U, S(P##"XYZ"));                            \
      chk<S>(NAME ": replace(1,2,\"XYZ\") on \"abcdefgh\"", s, P##"aXYZdefgh"); }    \
    { S s(P##"abcdefgh"); s.replace(1U, 2U, 3U, P##'Q');                             \
      chk<S>(NAME ": replace(1,2,3,'Q') on \"abcdefgh\"", s, P##"aQQQdefgh"); }      \
    { S s(P##"abcdefghijklmnop"); S c(s); c.insert(0U, S(P##"Z"));                   \
      chk<S>(NAME ": copy of a heap string, then insert", s, P##"abcdefghijklmnop"); \
      chk<S>(NAME ": the copy itself", c, P##"Zabcdefghijklmnop"); }                 \
  } while (0)

int main(void) {
  setvbuf(stdout, (char *)0, _IOLBF, 0);
  printf("cxx-wstring-test: starting\n");
  printf("sizeof: char %d, wchar_t %d, char16_t %d, char32_t %d\n",
         (int)sizeof(char), (int)sizeof(wchar_t), (int)sizeof(char16_t), (int)sizeof(char32_t));
  printf("short-string capacity in ELEMENTS: string %d, wstring %d\n",
         (int)::std::string().capacity(), (int)::std::wstring().capacity());

  /*
   * 1. `char'.  ***MUST PASS AGAINST A BROKEN LIBRARY.***  See the
   * header: without it, "everything failed" and "the wide types
   * failed" print the same thing.
   */
  printf("\n-- 1. char (the control: passes either way) --\n");
  MUTATORS(char, Sc, , "char");

  /* 2. `wchar_t'.  APE's is 4 bytes; win64's is 2.  Either shows it. */
  printf("\n-- 2. wchar_t --\n");
  MUTATORS(wchar_t, Sw, L, "wchar_t");

  /* 3. and 4.  The same bug by the same arithmetic, two more widths. */
  printf("\n-- 3. char16_t --\n");
  MUTATORS(char16_t, S16, u, "char16_t");

  printf("\n-- 4. char32_t --\n");
  MUTATORS(char32_t, S32, U, "char32_t");

  /*
   * 5. `to_wstring'.  SIX OVERLOADS AND NO FLOAT, deliberately: see
   * `sys/include/ape/c++/string/to_wstring.h'.  `size_t' is
   * `unsigned long long' under kencc and `unsigned long' on an LP64
   * host, so the `unsigned long' and `unsigned long long' cases are
   * each load-bearing on one of the two.
   */
  printf("\n-- 5. to_wstring --\n");
  chk< ::std::wstring>("to_wstring(0)", ::std::to_wstring(0), L"0");
  chk< ::std::wstring>("to_wstring(42)", ::std::to_wstring(42), L"42");
  chk< ::std::wstring>("to_wstring(-42)", ::std::to_wstring(-42), L"-42");
  chk< ::std::wstring>("to_wstring(7u)", ::std::to_wstring(7u), L"7");
  chk< ::std::wstring>("to_wstring(-1L)", ::std::to_wstring(-1L), L"-1");
  chk< ::std::wstring>("to_wstring(4000000000UL)", ::std::to_wstring(4000000000UL), L"4000000000");
  chk< ::std::wstring>("to_wstring(-9000000000LL)", ::std::to_wstring(-9000000000LL),
                       L"-9000000000");
  chk< ::std::wstring>("to_wstring(12345678901ULL)", ::std::to_wstring(12345678901ULL),
                       L"12345678901");
  {
    ::std::size_t z = 99U;
    chk< ::std::wstring>("to_wstring(size_t 99)", ::std::to_wstring(z), L"99");
  }

  /*
   * 6. unrar's own four spellings.  ***THE POINT IS THE OPERAND KINDS,
   * NOT THE VALUES.***  Each picks a different `operator+': a
   * temporary string on the left, a bare pointer on the left, a bare
   * CHARACTER on the left, and a chain.  The pointer and character
   * forms both go through `insert(0, ...)' on the right-hand
   * temporary, which is the site section 2 exercises directly -- so
   * these are the shapes a caller writes, kept because a library rule
   * can be right while the overload a program reaches is not.
   */
  printf("\n-- 6. the shapes unrar writes --\n");
  chk< ::std::wstring>("wstring(L\"rtmp\") + to_wstring(7)",
                       ::std::wstring(L"rtmp") + ::std::to_wstring(7), L"rtmp7");
  chk< ::std::wstring>("L\"h\" + to_wstring(1234u)",
                       L"h" + ::std::to_wstring(1234u), L"h1234");
  chk< ::std::wstring>("L\" -md=\" + to_wstring(3) + L\"g\"",
                       L" -md=" + ::std::to_wstring(3) + L"g", L" -md=3g");
  {
    ::std::wstring name(L"file");
    name += L';' + ::std::to_wstring(-5L);
    chk< ::std::wstring>("name += L';' + to_wstring(-5L)", name, L"file;-5");
  }

  printf("\ncxx-wstring-test: %d failure(s)\n", fails);
  return fails;
}
