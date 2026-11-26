// ***************************************************************************
// * APExp addition to portable_stl -- `stack'.
// *
// * Project="APExp C++ library" File="containers/stack.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// An adaptor, so it is short -- and it keeps the LIBRARY's convention
// rather than the standard's: `push' returns `expected<void, std_error>'
// because the underlying `deque::push_back' does, and the alternative is
// to DISCARD that result, which is the silent-failure shape this
// library's whole convention exists to prevent.  See `containers/deque.h'
// for the argument in full.
//
// `top()' on an empty stack is undefined behaviour in the standard and is
// left that way: a `stack' that checked would cost every correct caller
// a branch, and the checked form is `empty()', which callers already
// have.  *An adaptor is not the place to invent a safety the container
// underneath does not offer.*

#ifndef APEXP_STD_CONTAINERS_STACK_H
#define APEXP_STD_CONTAINERS_STACK_H

#include "deque.h"

namespace std {

template<class t_type, class t_container = ::std::deque<t_type>> class stack final {
public:
  using container_type  = t_container;
  using value_type      = typename t_container::value_type;
  using size_type       = typename t_container::size_type;
  using reference       = typename t_container::reference;
  using const_reference = typename t_container::const_reference;

  stack() noexcept = default;
  explicit stack(t_container &&c) noexcept : m_c{::std::move(c)} {
  }
  stack(stack &&)            = default;
  stack &operator=(stack &&) = default;
  stack(stack const &)            = delete;
  stack &operator=(stack const &) = delete;

  bool      empty() const noexcept { return m_c.empty(); }
  size_type size() const noexcept { return m_c.size(); }

  reference       top() { return m_c.back(); }
  const_reference top() const { return m_c.back(); }

  ::std::expected<void, ::std::std_error> push(value_type const &v) {
    return m_c.push_back(v);
  }
  ::std::expected<void, ::std::std_error> push(value_type &&v) {
    return m_c.push_back(::std::move(v));
  }
  void pop() { m_c.pop_back(); }

  void swap(stack &other) noexcept { m_c.swap(other.m_c); }

  t_container const &container() const noexcept { return m_c; }

private:
  t_container m_c;
};

} // namespace std

#endif // APEXP_STD_CONTAINERS_STACK_H
