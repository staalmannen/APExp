// ***************************************************************************
// * APExp addition to portable_stl -- `queue'.
// *
// * Project="APExp C++ library" File="containers/queue.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// The other adaptor; see `containers/stack.h' for why `push' returns
// `expected' and `front()' does not check.
//
// **`priority_queue' is NOT here.**  It needs `make_heap`/`push_heap`/
// `pop_heap`, and shipping a `queue' header that declares a
// `priority_queue' it cannot implement is the empty-`<stdexcept>' shape
// this port has already paid for once.

#ifndef APEXP_STD_CONTAINERS_QUEUE_H
#define APEXP_STD_CONTAINERS_QUEUE_H

#include "deque.h"

namespace std {

template<class t_type, class t_container = ::std::deque<t_type>> class queue final {
public:
  using container_type  = t_container;
  using value_type      = typename t_container::value_type;
  using size_type       = typename t_container::size_type;
  using reference       = typename t_container::reference;
  using const_reference = typename t_container::const_reference;

  queue() noexcept = default;
  explicit queue(t_container &&c) noexcept : m_c{::std::move(c)} {
  }
  queue(queue &&)            = default;
  queue &operator=(queue &&) = default;
  queue(queue const &)            = delete;
  queue &operator=(queue const &) = delete;

  bool      empty() const noexcept { return m_c.empty(); }
  size_type size() const noexcept { return m_c.size(); }

  reference       front() { return m_c.front(); }
  const_reference front() const { return m_c.front(); }
  reference       back() { return m_c.back(); }
  const_reference back() const { return m_c.back(); }

  ::std::expected<void, ::std::std_error> push(value_type const &v) {
    return m_c.push_back(v);
  }
  ::std::expected<void, ::std::std_error> push(value_type &&v) {
    return m_c.push_back(::std::move(v));
  }
  void pop() { m_c.pop_front(); }

  void swap(queue &other) noexcept { m_c.swap(other.m_c); }

  t_container const &container() const noexcept { return m_c; }

private:
  t_container m_c;
};

} // namespace std

#endif // APEXP_STD_CONTAINERS_QUEUE_H
