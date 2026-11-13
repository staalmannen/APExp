/*
 * cxx-niterbase-probe -- does a SELF-REFERENTIAL trailing return type
 * kill cpfe?
 *
 *	c++ -F cxx-niterbase-probe.cpp
 *
 * ***A PROBE, NOT A TEST.***  It asserts nothing and prints nothing.
 * The result is whether cpfe SURVIVES it:
 *
 *	ok ......... the shape below is NOT the bug; read the minimal
 *	             reproducer `cxx-vecsplit' phase C produces instead
 *	CRASH ...... the whole bug is these twenty lines, and the 2.9M
 *	             line corpus and the C++ library are both out of it
 *	error ...... the probe is wrong, not cpfe -- it compiles under
 *	             g++ -std=c++14, so a diagnostic here is a
 *	             disagreement worth reading on its own
 *
 * WHERE IT COMES FROM.  `cxx-vecsplit' bisected `<vector>' to one
 * line: `vector.h:28', `#include "../iterator/niter_base.h"'.  Line
 * 27 is ok and line 28 CRASHES.  But `cxx-vecnarrow' phase 1 compiled
 * that header ALONE and it was fine, so the crash is a COMBINATION
 * and the boundary names only its last member.
 *
 * The one thing in that header that is unusual is below.  Two of its
 * four `niter_base' overloads are declared with a TRAILING RETURN
 * TYPE THAT CALLS `niter_base':
 *
 *	template<typename t_iterator>
 *	constexpr auto niter_base(::std::reverse_iterator<t_iterator> it)
 *	  -> decltype(::std::make_reverse_iterator(niter_base(it.base())))
 *
 * The name is in scope from its own declarator onwards, so the
 * overload set the `decltype' resolves against INCLUDES THE FUNCTION
 * BEING DECLARED, whose return type is the thing being computed.  It
 * terminates because `it.base()' is one level less wrapped, and g++
 * accepts it -- but it is the shape a front end is most likely to
 * recurse on, and it is worth one command to find out.
 *
 * ***IT IS A GUESS AND IT IS LABELLED ONE.***  This tree's honest
 * tally for mechanisms guessed from code alone is about one in eight;
 * the automated minimiser is the measurement and this is the cheap
 * shot taken while it runs.  If it answers `ok' that is a real
 * result -- it rules the shape out.
 *
 * Checked under g++ -std=c++14 -fsyntax-only before shipping.
 */

/* Deliberately NO library headers: if this crashes, nothing about
   `sys/include/ape/c++' or EDG's corpus is implicated. */

template<class t_iterator> struct wrap_iter {
  t_iterator m_i;
  constexpr t_iterator base() const {
    return m_i;
  }
};

template<class t_iterator> struct rev_iter {
  t_iterator m_i;
  constexpr t_iterator base() const {
    return m_i;
  }
};

template<class t_iterator> struct mov_iter {
  t_iterator m_i;
  constexpr t_iterator base() const {
    return m_i;
  }
};

template<class t_iterator> constexpr rev_iter<t_iterator> make_rev(t_iterator i) {
  return rev_iter<t_iterator>{i};
}

template<class t_iterator> constexpr mov_iter<t_iterator> make_mov(t_iterator i) {
  return mov_iter<t_iterator>{i};
}

/* 1: the fallback, which is what terminates the recursion. */
template<class t_iterator> constexpr t_iterator nbase(t_iterator i) {
  return i;
}

/* 2: an ordinary unwrapping overload, no trailing return type. */
template<class t_iterator> constexpr t_iterator nbase(wrap_iter<t_iterator> i) {
  return i.base();
}

/* 3: THE SHAPE -- `nbase' named inside its own trailing return type. */
template<class t_iterator>
constexpr auto nbase(rev_iter<t_iterator> i) -> decltype(make_rev(nbase(i.base()))) {
  return make_rev(nbase(i.base()));
}

/* 4: the same again, with overload 3 now in the set it resolves
      against -- which is the case that can make a front end walk the
      two of them against each other. */
template<class t_iterator>
constexpr auto nbase(mov_iter<t_iterator> i) -> decltype(make_mov(nbase(i.base()))) {
  return make_mov(nbase(i.base()));
}

/*
 * Nothing below instantiates any of it, because `<vector>' does not
 * either: the translation unit that crashes cpfe is an `#include' and
 * an empty `main'.  **If this probe needed an instantiation to crash,
 * it would not be reproducing what was measured.**
 */
int main(void) {
  return 0;
}
