// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="split_buffer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SPLIT_BUFFER_H
#define PSTL_SPLIT_BUFFER_H

#include "../algorithm/max.h"
#include "../error/portable_stl_error.h"
#include "../iterator/distance.h"
#include "../language_support/bad_alloc.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/swap_allocator.h"
#include "../memory/to_address.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../utility/general/forward.h"
#include "../utility/general/make_exception_guard.h"
#include "../utility/general/move.h"
#include "vector_helper.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {
// split_buffer allocates a contiguous chunk of memory and stores objects in the range [m_begin, m_end).
// It has uninitialized memory in the ranges  [m_first, m_begin) and [m_end, m_end_cap.first()). That allows
// it to grow both in the front and back without having to move the data.

template<class t_type, class t_allocator = allocator<t_type>> class split_buffer final {
public:
  using value_type = t_type;

  using allocator_type     = t_allocator;
  using t_alloc_rref       = ::portable_stl::remove_reference_t<allocator_type>;
  using t_allocator_traits = ::portable_stl::allocator_traits<t_alloc_rref>;

  using reference       = value_type &;
  using const_reference = value_type const &;
  using size_type       = typename t_allocator_traits::size_type;
  using difference_type = typename t_allocator_traits::difference_type;
  using pointer         = typename t_allocator_traits::pointer;
  using const_pointer   = typename t_allocator_traits::const_pointer;
  using iterator        = pointer;
  using const_iterator  = const_pointer;

  pointer                                                  m_first;
  pointer                                                  m_begin;
  pointer                                                  m_end;
  ::portable_stl::compressed_pair<pointer, allocator_type> m_end_cap;

  using t_alloc_ref       = ::portable_stl::add_lvalue_reference_t<allocator_type>;
  using t_alloc_const_ref = ::portable_stl::add_lvalue_reference_t<allocator_type>;

  split_buffer(split_buffer const &)            = delete;
  split_buffer &operator=(split_buffer const &) = delete;

  split_buffer() /* noexcept(noexcept(allocator_type{})) */
      : m_first(nullptr), m_begin(nullptr), m_end(nullptr), m_end_cap(nullptr) {
  }

  explicit split_buffer(t_alloc_rref &alloc)
      : m_first(nullptr), m_begin(nullptr), m_end(nullptr), m_end_cap(nullptr, alloc) {
  }

  explicit split_buffer(t_alloc_rref const &alloc)
      : m_first(nullptr), m_begin(nullptr), m_end(nullptr), m_end_cap(nullptr, alloc) {
  }

  split_buffer(size_type capacity, size_type start, t_alloc_rref &alloc);

  split_buffer(split_buffer &&other)
      : m_first(other.m_first)
      , m_begin(other.m_begin)
      , m_end(other.m_end)
      , m_end_cap(::portable_stl::move(other.m_end_cap)) {
    other.m_first = other.m_begin = other.m_end = nullptr;
  }

  ~split_buffer();

  static split_buffer make_split_buffer(size_type capacity, size_type start, t_alloc_rref &alloc) noexcept;

  pointer &end_cap() noexcept {
    return m_end_cap.get_first();
  }
  pointer const &end_cap() const noexcept {
    return m_end_cap.get_first();
  }

  t_alloc_rref &M_alloc() noexcept {
    return m_end_cap.get_second();
  }

  t_alloc_rref const &M_alloc() const noexcept {
    return m_end_cap.get_second();
  }
  void push_front(const_reference value);
  void push_back(const_reference value);
  void push_front(value_type &&value);
  void push_back(value_type &&value);

  template<class... t_args> void emplace_back(t_args &&...args);

  constexpr size_type capacity() const {
    return static_cast<size_type>(end_cap() - m_first);
  }

  void clear() noexcept {
    M_destruct_at_end(m_begin);
  }

  /**
   * Returns a read/write iterator that points to the first element in the vector. Iteration is done in ordinary
   * element order.
   */
  iterator begin() noexcept {
    return iterator(m_begin);
  }

  /**
   * Returns a read-only (constant) iterator that points to the first element in the vector. Iteration is done in
   * ordinary element order.
   */
  const_iterator begin() const noexcept {
    return const_iterator(m_begin);
  }

  /**
   * Returns a read/write iterator that points one past the last element in the vector. Iteration is done in ordinary
   * element order.
   */
  iterator end() noexcept {
    return iterator(m_end);
  }

  /**
   * Returns a read-only (constant) iterator that points one past the last element in the vector. Iteration is done in
   * ordinary element order.
   */
  const_iterator end() const noexcept {
    return const_iterator(m_end);
  }

  /**
   * @brief Returns the number of elements in the vector.
   * @return constexpr size_type
   */
  constexpr size_type size() const noexcept {
    return static_cast<size_type>(m_end - m_begin);
  }

  void M_destruct_at_end(pointer new_last_ptr) noexcept {
    M_destruct_at_end(new_last_ptr, ::portable_stl::false_type{});
  }

  void M_destruct_at_end(pointer new_last_ptr, ::portable_stl::false_type) noexcept;
  void M_destruct_at_end(pointer new_last_ptr, ::portable_stl::true_type) noexcept;

  /**
   * @brief Returns the size() of the largest possible buffer.
   * @param buf given buffer.
   * @return constexpr size_type
   */
  constexpr static size_type max_size(split_buffer const &buf) noexcept;

  void swap(split_buffer &other) noexcept(noexcept(!typename t_allocator_traits::propagate_on_container_swap{}()
                                                   || ::portable_stl::is_nothrow_swappable<t_alloc_rref>{}()));

  void M_construct_at_end(size_type num);

  void M_construct_at_end(size_type num, const_reference value);

  template<class t_input_iterator,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               vector_helper::has_exactly_input_iterator_category<t_input_iterator>,
               ::portable_stl::is_constructible<value_type,
                                                typename ::portable_stl::iterator_traits<t_input_iterator>::reference>>,
             void *>
           = nullptr>
  void M_construct_at_end(t_input_iterator first, t_input_iterator last);

  template<class t_forward_iterator,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::has_forward_iterator_category<t_forward_iterator>,
                                         ::portable_stl::is_constructible<
                                           value_type,
                                           typename ::portable_stl::iterator_traits<t_forward_iterator>::reference>>,
             void *>
           = nullptr>
  void M_construct_at_end(t_forward_iterator first, t_forward_iterator last);

  template<class t_iterator, class t_sentinel> bool M_construct_at_end_with_sentinel(t_iterator first, t_sentinel last);

  template<class t_forward_iterator> void M_construct_at_end_with_size(t_forward_iterator first, size_type num);

private:
  class M_destroy_buffer final {
  public:
    constexpr M_destroy_buffer(split_buffer &buf) : m_buffer(buf) {
    }

    void operator()() {
      if (m_buffer.m_begin != nullptr) {
        m_buffer.M_clear();
        // m_buffer.__annotate_delete();
        t_allocator_traits::deallocate(m_buffer.M_M_alloc(), m_buffer.m_begin, m_buffer.capacity());

        m_buffer.m_begin     = nullptr;
        m_buffer.m_end       = nullptr;
        m_buffer.M_end_cap() = nullptr;
      }
    }

  private:
    split_buffer &m_buffer;
  };

  struct M_ConstructTransaction {
    explicit M_ConstructTransaction(pointer *ptr, size_type num) noexcept
        : m_pos(*ptr), m_end(*ptr + num), m_dest(ptr) {
    }

    ~M_ConstructTransaction() {
      *m_dest = m_pos;
    }

    pointer       m_pos;
    pointer const m_end;

  private:
    pointer *m_dest;
  };
};

template<class t_type, class t_allocator>
split_buffer<t_type, t_allocator>::split_buffer(size_type capacity, size_type start, t_alloc_rref &given_alloc)
    : m_end_cap(nullptr, given_alloc) {
  if (capacity == 0) {
    m_first = nullptr;
  } else {
    m_first = ::portable_stl::allocate_noexcept(M_alloc(), capacity);
    
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_first);
  }
  // vvv change state vvv
  if (!m_first) {
    m_begin = m_end = m_first + start;
    end_cap()       = m_first + capacity;
  } else {
    end_cap() = m_begin = m_end = nullptr;
  }
}

template<class t_type, class t_allocator> split_buffer<t_type, t_allocator>::~split_buffer() {
  clear();
  if (m_first) {
    t_allocator_traits::deallocate(M_alloc(), m_first, capacity());
  }
}

template<class t_type, class t_allocator>
constexpr typename split_buffer<t_type, t_allocator>::size_type split_buffer<t_type, t_allocator>::max_size(
  split_buffer<t_type, t_allocator> const &buf) noexcept {
  return ::portable_stl::min<size_type>(t_allocator_traits::max_size(buf.M_alloc()),
                                        ::portable_stl::numeric_limits<difference_type>::max());
}

// static
template<class t_type, class t_allocator>
split_buffer<t_type, t_allocator> split_buffer<t_type, t_allocator>::make_split_buffer(
  size_type capacity, size_type start, t_alloc_rref &alloc) noexcept {
  split_buffer buf{alloc};

  // if (capacity > max_size(buf)) {
  //   return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
  //     ::portable_stl::portable_stl_error::length_error};
  // }
  buf.m_first = ::portable_stl::allocate_noexcept(buf.M_alloc(), capacity);
  if (buf.m_first) {
    buf.m_begin = buf.m_end = buf.m_first + start;
    buf.end_cap()           = buf.m_first + capacity;
  }
  // return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
  // ::portable_stl::portable_stl_error::allocate_error};

  return buf;
}

template<class t_type, class t_allocator>
inline void split_buffer<t_type, t_allocator>::push_back(const_reference value) {
  if (m_end == end_cap()) {
    if (m_begin > m_first) {
      difference_type diff{m_begin - m_first};
      diff  = (diff + 1) / 2;
      m_end = ::portable_stl::move(m_begin, m_end, m_begin - diff);
      m_begin -= diff;
    } else {
      auto cap = ::portable_stl::max<size_type>(2 * static_cast<size_t>(end_cap() - m_first), 1);
      split_buffer<value_type, t_alloc_rref &> tmp(cap, cap / 4, M_alloc());
      tmp.M_construct_at_end(move_iterator<pointer>(m_begin), move_iterator<pointer>(m_end));
      ::portable_stl::swap(m_first, tmp.m_first);
      ::portable_stl::swap(m_begin, tmp.m_begin);
      ::portable_stl::swap(m_end, tmp.m_end);
      ::portable_stl::swap(end_cap(), tmp.end_cap());
    }
  }
  t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(m_end), value);
  ++m_end;
}

template<class t_type, class t_allocator> void split_buffer<t_type, t_allocator>::push_back(value_type &&value) {
  if (m_end == end_cap()) {
    if (m_begin > m_first) {
      difference_type diff{m_begin - m_first};
      diff  = (diff + 1) / 2;
      m_end = ::portable_stl::move(m_begin, m_end, m_begin - diff);
      m_begin -= diff;
    } else {
      auto cap = ::portable_stl::max<size_type>(2 * static_cast<size_t>(end_cap() - m_first), 1);
      split_buffer<value_type, t_alloc_rref &> tmp(cap, cap / 4, M_alloc());
      tmp.M_construct_at_end(move_iterator<pointer>(m_begin), move_iterator<pointer>(m_end));
      ::portable_stl::swap(m_first, tmp.m_first);
      ::portable_stl::swap(m_begin, tmp.m_begin);
      ::portable_stl::swap(m_end, tmp.m_end);
      ::portable_stl::swap(end_cap(), tmp.end_cap());
    }
  }
  t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(m_end), ::portable_stl::move(value));
  ++m_end;
}

template<class t_type, class t_allocator>
template<class... t_args>
void split_buffer<t_type, t_allocator>::emplace_back(t_args &&...args) {
  if (m_end == end_cap()) {
    if (m_begin > m_first) {
      difference_type diff{m_begin - m_first};
      diff  = (diff + 1) / 2;
      m_end = ::portable_stl::move(m_begin, m_end, m_begin - diff);
      m_begin -= diff;
    } else {
      auto cap = ::portable_stl::max<size_type>(2 * static_cast<size_t>(end_cap() - m_first), 1);
      split_buffer<value_type, t_alloc_rref &> tmp(cap, cap / 4, M_alloc());
      tmp.M_construct_at_end(move_iterator<pointer>(m_begin), move_iterator<pointer>(m_end));
      ::portable_stl::swap(m_first, tmp.m_first);
      ::portable_stl::swap(m_begin, tmp.m_begin);
      ::portable_stl::swap(m_end, tmp.m_end);
      ::portable_stl::swap(end_cap(), tmp.end_cap());
    }
  }
  t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(m_end), ::portable_stl::forward<t_args>(args)...);
  ++m_end;
}

template<class t_type, class t_allocator> void split_buffer<t_type, t_allocator>::M_construct_at_end(size_type num) {
  M_ConstructTransaction trans(&this->m_end, num);
  for (; trans.m_pos != trans.m_end; ++trans.m_pos) {
    t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(trans.m_pos));
  }
}

template<class t_type, class t_allocator>
void split_buffer<t_type, t_allocator>::M_construct_at_end(size_type num, const_reference value) {
  M_ConstructTransaction trans(&this->m_end, num);
  for (; trans.m_pos != trans.m_end; ++trans.m_pos) {
    t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(trans.m_pos), value);
  }
}

template<class t_type, class t_allocator>
template<class t_input_iterator,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<
             vector_helper::has_exactly_input_iterator_category<t_input_iterator>,
             ::portable_stl::is_constructible<typename split_buffer<t_type, t_allocator>::value_type,
                                              typename ::portable_stl::iterator_traits<t_input_iterator>::reference>>,
           void *>>
void split_buffer<t_type, t_allocator>::M_construct_at_end(t_input_iterator first, t_input_iterator last) {
  M_construct_at_end_with_sentinel(first, last);
}

template<class t_type, class t_allocator>
template<class t_forward_iterator,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<
             ::portable_stl::has_forward_iterator_category<t_forward_iterator>,
             ::portable_stl::is_constructible<typename split_buffer<t_type, t_allocator>::value_type,
                                              typename ::portable_stl::iterator_traits<t_forward_iterator>::reference>>,
           void *>>
void split_buffer<t_type, t_allocator>::M_construct_at_end(t_forward_iterator first, t_forward_iterator last) {
  M_construct_at_end_with_size(first, static_cast<size_type>(::portable_stl::distance(first, last)));
}

template<class t_type, class t_allocator>
template<class t_forward_iterator>
void split_buffer<t_type, t_allocator>::M_construct_at_end_with_size(t_forward_iterator first, size_type num) {
  M_ConstructTransaction trans(&this->m_end, num);
  for (; trans.m_pos != trans.m_end; ++trans.m_pos, (void)++first) {
    t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(trans.m_pos), *first);
  }
}

template<class t_type, class t_allocator>
void split_buffer<t_type, t_allocator>::swap(split_buffer &other) noexcept(
  noexcept(!typename t_allocator_traits::propagate_on_container_swap{}()
           || ::portable_stl::is_nothrow_swappable<t_alloc_rref>{}())) {
  ::portable_stl::swap(m_first, other.m_first);
  ::portable_stl::swap(m_begin, other.m_begin);
  ::portable_stl::swap(m_end, other.m_end);
  ::portable_stl::swap(end_cap(), other.end_cap());
  ::portable_stl::swap_allocator(M_alloc(), other.M_alloc());
}

template<class t_type, class t_allocator>
template<class t_iterator, class t_sentinel>
bool split_buffer<t_type, t_allocator>::M_construct_at_end_with_sentinel(t_iterator first, t_sentinel last) {
  t_alloc_rref &alloc = M_alloc();
  for (; first != last; ++first) {
    if (m_end == end_cap()) {
      size_type old_cap = static_cast<size_type>(end_cap() - m_first);
      auto      new_cap = ::portable_stl::max<size_type>(2 * old_cap, 8);
      auto      buf     = split_buffer::make_split_buffer(new_cap, 0, alloc);
      if (!buf.m_first) {
        return false;
      }
      for (pointer ptr = m_begin; ptr != m_end; ++ptr, (void)++buf.m_end) {
        t_allocator_traits::construct(buf.M_alloc(), ::portable_stl::to_address(buf.m_end), ::portable_stl::move(*ptr));
      }
      swap(buf);
    }
    t_allocator_traits::construct(alloc, ::portable_stl::to_address(this->m_end), *first);
    ++this->m_end;
  }
  return true;
}

template<class t_type, class t_allocator>
inline void split_buffer<t_type, t_allocator>::M_destruct_at_end(pointer new_last_ptr,
                                                                 ::portable_stl::false_type) noexcept {
  while (new_last_ptr != m_end) {
    t_allocator_traits::destroy(M_alloc(), ::portable_stl::to_address(--m_end));
  }
}

template<class t_type, class t_allocator>
inline void split_buffer<t_type, t_allocator>::M_destruct_at_end(pointer new_last_ptr,
                                                                 ::portable_stl::true_type) noexcept {
  m_end = new_last_ptr;
}
} // namespace portable_stl

#endif // PSTL_SPLIT_BUFFER_H
