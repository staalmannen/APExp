/*
 * cxx-striter-test.cpp -- `basic_string''s ITERATOR-PAIR overloads over
 * a range that is not a contiguous block of its own character type.
 *
 * ***THEY TOOK THE ADDRESS OF THE FIRST ELEMENT AND COPIED A BLOCK.***
 * The constructor was
 *
 *     basic_string(::std::to_address(first),
 *                  static_cast<size_type>(::std::distance(first, last)),
 *                  allocator)
 *
 * and `make_string' and `append' said the same thing.  Two faults, and
 * ***THE ONE THAT PRODUCED A DIAGNOSTIC IS THE LUCKY ONE.***
 *
 * (a) It compiles only for an iterator whose `value_type' IS the
 *     string's `value_type'.  unrar's `win32stm.cpp:240' is
 *     `std::string Src(v.begin(), v.end())' over a
 *     `vector<unsigned char>' -- `unsigned char' converts to `char'
 *     perfectly well, and `to_address' hands over an
 *     `unsigned char *' which does not.  The overload SFINAE'd out
 *     and the diagnostic then named `(const char *, size_type,
 *     allocator)', *which is not the constructor anybody wrote*.
 *
 * (b) ***FOR A NON-CONTIGUOUS ITERATOR IT WAS SILENTLY WRONG.***
 *     `to_address' on a `list' iterator answers the address of the
 *     element inside one node, and the copy then read `distance'
 *     elements of whatever followed that node in memory.  The guard
 *     admits `input_iterator_tag', so the implementation promised far
 *     more than it could do -- and nothing in this tree had ever
 *     handed a string a non-contiguous range, so there was no symptom
 *     to notice.  *(b) is the reason this file exists; (a) is the
 *     reason anyone looked.*
 *
 * ---- THE THREE SECTIONS ARE THREE DIFFERENT QUESTIONS -------------
 *
 * 1. **A CONVERTING value_type**, contiguous.  This is unrar's line
 *    and fault (a): before the fix it did not compile, so this section
 *    is mostly answered by the build.
 *
 * 2. **A NON-CONTIGUOUS range** (`std::list`).  Fault (b), and the
 *    only section that could ever have produced a wrong ANSWER rather
 *    than a wrong diagnostic.  The payloads are longer than the
 *    short-string buffer for the same reason `cxx-wstring-test`'s are:
 *    a case that never reallocates exercises less of the path.
 *
 * 3. **A SINGLE-PASS input iterator.**  ***THIS SECTION IS THE ONE
 *    THAT CONSTRAINS THE FIX.*** The obvious implementation calls
 *    `distance(first, last)` to reserve and then loops -- which reads
 *    the range TWICE, and an input iterator cannot be read twice.  So
 *    the reserve is tag-dispatched on
 *    `has_forward_iterator_category`, and without a single-pass case
 *    here that dispatch would be dead code that nothing ever took.
 *    The iterator below is deliberately minimal: a `char const *` and
 *    `input_iterator_tag`, no `operator->` at all, so `to_address`
 *    could not even be called on it.
 *
 * ---- THE REFERENCE ARM -------------------------------------------
 *
 * Every assertion is a standard-library rule ([string.cons],
 * [string.append], [string.assign], [string.insert] all take an
 * InputIterator pair), so libstdc++ answers the same questions:
 *
 *     # against APExp's library (the subject)
 *     g++ -std=c++14 -w -nostdinc++ \
 *         -D__EDG_RUNTIME_USES_NAMESPACES=1 -D__EDG_STD_NAMESPACE=std \
 *         -D__EDG_CONSTEXPR_ENABLED__=1 \
 *         -D__EDG_SIZE_TYPE__='decltype(sizeof(0))' \
 *         -I <shim> -I sys/include/ape/c++ \
 *         cxx-striter-test.cpp <exception-ctor stubs> -o t && ./t
 *
 *     # against libstdc++ (the reference)
 *     g++ -std=c++14 -DREFERENCE cxx-striter-test.cpp -o tref && ./tref
 *
 * ***THE CONTROL IS SPLIT, AND IT HAS TO BE.***  Against the pre-fix
 * headers out of git the whole file **does not compile** -- 19 errors,
 * which is fault (a) and the absent tag dispatch -- so a failure COUNT
 * is not available that way.  Built with `-DCONTROL_SECTION2_ONLY`,
 * which drops the two sections that need the fix in order to compile,
 * it **compiles and reports 3 failures**, and the output is the
 * finding rather than a number:
 *
 *     want "a list is not a block, and this payload is well past ..."
 *     got  "a.......!.......\373";]\360U...#;]\360U.. ......."
 *
 * -- the first element, then 66 bytes of whatever followed that list
 * node, at the right LENGTH.  *That is fault (b) measured instead of
 * read out of the source*, and a control that could only say "it did
 * not build" would have left the silent half of this bug on the
 * strength of a reading.
 *
 * On Plan 9:  eccp -o cxx-striter-test cxx-striter-test.cpp
 *
 * Prints PASS/FAIL per case and exits with the number of failures.
 */

#include <stdio.h>
#include <string.h>

#include <list>
#include <string>
#include <vector>

static int fails = 0;

static void chk(char const *tag, ::std::string const &got, char const *want) {
  bool ok = (got.size() == strlen(want));
  for (::std::size_t j = 0; ok && j < got.size(); ++j) {
    ok = (got[j] == want[j]);
  }
  if (ok) {
    printf("PASS %s\n", tag);
    return;
  }
  ++fails;
  printf("FAIL %s\n     want \"%s\" (%d)\n     got  \"", tag, want, (int)strlen(want));
  for (::std::size_t j = 0; j < got.size(); ++j) {
    printf("%c", got[j] ? got[j] : '.');
  }
  printf("\" (%d)\n", (int)got.size());
}

/*
 * A SINGLE-PASS input iterator, as small as the concept allows.  No
 * `operator->' and no `operator-', so neither `to_address' nor a
 * random-access `distance' can be applied to it -- which is the point:
 * an implementation that measures the range before copying it cannot
 * compile against this, and one that measures it twice cannot be
 * correct with it.
 */
class single_pass final {
  char const *m_p;

public:
  typedef ::std::input_iterator_tag iterator_category;
  typedef char                      value_type;
  typedef ::std::ptrdiff_t          difference_type;
  typedef char const               *pointer;
  typedef char const               &reference;

  explicit single_pass(char const *p) noexcept : m_p(p) {
  }
  char const  &operator*() const noexcept {
    return *m_p;
  }
  single_pass &operator++() noexcept {
    ++m_p;
    return *this;
  }
  single_pass operator++(int) noexcept {
    single_pass tmp(*this);
    ++m_p;
    return tmp;
  }
  bool operator==(single_pass const &other) const noexcept {
    return m_p == other.m_p;
  }
  bool operator!=(single_pass const &other) const noexcept {
    return m_p != other.m_p;
  }
};

int main(void) {
  setvbuf(stdout, (char *)0, _IOLBF, 0);
  printf("cxx-striter-test: starting\n");
  printf("short-string capacity in elements: %d\n", (int)::std::string().capacity());

  /*
   * 1. A CONVERTING value_type, contiguous.  unrar's own line.
   * ***MOSTLY ANSWERED BY THE BUILD***: before the fix not one of
   * these compiled.
   */
#ifndef CONTROL_SECTION2_ONLY
  printf("\n-- 1. unsigned char iterators into a string<char> --\n");
  {
    char const *src = "a converting value_type, long enough to leave the SSO buffer";
    ::std::vector<unsigned char> v;
    for (char const *p = src; *p; ++p) {
      v.push_back((unsigned char)*p);
    }
    chk("string(v.begin(), v.end())", ::std::string(v.begin(), v.end()), src);
    {
      ::std::string s("head: ");
      s.append(v.begin(), v.end());
      chk("append(v.begin(), v.end())", s,
          "head: a converting value_type, long enough to leave the SSO buffer");
    }
    {
      ::std::string s("replaced");
      s.assign(v.begin(), v.end());
      chk("assign(v.begin(), v.end())", s, src);
    }
    {
      ::std::string s("<>");
      s.insert(s.cbegin() + 1, v.begin(), v.end());
      chk("insert(cbegin()+1, v.begin(), v.end())", s,
          "<a converting value_type, long enough to leave the SSO buffer>");
    }
  }
#endif

  /*
   * 2. A NON-CONTIGUOUS range.  ***THE ONLY SECTION THAT COULD GIVE A
   * WRONG ANSWER RATHER THAN A WRONG DIAGNOSTIC***, and so the only
   * one the pre-fix headers can be made to run at all.
   */
  printf("\n-- 2. list<char> iterators: the silent half --\n");
  {
    char const *src = "a list is not a block, and this payload is well past the SSO buffer";
    ::std::list<char> l;
    for (char const *p = src; *p; ++p) {
      l.push_back(*p);
    }
    chk("string(l.begin(), l.end())", ::std::string(l.begin(), l.end()), src);
    {
      ::std::string s;
      s.append(l.begin(), l.end());
      chk("append(l.begin(), l.end()) onto empty", s, src);
    }
    {
      ::std::list<char> three;
      three.push_back('X');
      three.push_back('Y');
      three.push_back('Z');
      ::std::string s("ab");
      s.insert(s.cbegin() + 1, three.begin(), three.end());
      chk("insert(cbegin()+1, 3 list elements)", s, "aXYZb");
    }
  }

  /*
   * 3. A SINGLE-PASS input iterator.  See the header: this is what
   * forbids measuring the range before copying it, and without it the
   * tag dispatch in `M_reserve_for_range' would be dead code.
   */
#ifndef CONTROL_SECTION2_ONLY
  printf("\n-- 3. a single-pass input iterator --\n");
  {
    char const *src = "single pass, no operator-> and no subtraction, past the SSO buffer";
    chk("string(single_pass, single_pass)",
        ::std::string(single_pass(src), single_pass(src + strlen(src))), src);
    {
      ::std::string s("x");
      s.append(single_pass(src), single_pass(src + strlen(src)));
      ::std::string want("x");
      want.append(src);
      chk("append(single_pass, single_pass)", s, want.c_str());
    }
    /* the empty range: first == last on the first comparison, so
     * nothing may be read through the iterator at all */
    chk("string(single_pass empty range)",
        ::std::string(single_pass(src), single_pass(src)), "");
  }
#endif

  printf("\ncxx-striter-test: %d failure(s)\n", fails);
  return fails;
}
