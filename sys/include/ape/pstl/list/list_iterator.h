// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_ITERATOR_H
#define PSTL_LIST_ITERATOR_H

#include "../iterator/bidirectional_iterator_tag.h"
#include "../memory/pointer_traits.h"
#include "../memory/rebind_pointer.h"
#include "list_types.h"

namespace portable_stl {

/**
 * @brief Iterator for nodes of a list.
 *
 * @tparam t_type Node's value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_iterator {
  /**
   * @brief
   *
   */
  using t_node_traits  = list_node_pointer_traits<t_type, t_void_ptr>;
  /**
   * @brief
   *
   */
  using t_link_pointer = typename t_node_traits::t_link_pointer;

  /**
   * @brief Internally stored pointer.
   *
   */
  t_link_pointer m_ptr;

  /**
   * @brief Constructor from link pointer.
   *
   * @param ptr
   */
  explicit list_iterator(t_link_pointer ptr) noexcept : m_ptr(ptr) {
  }

  template<class, class> friend class list;
  template<class, class> friend class list_impl;
  template<class, class> friend class list_const_iterator;

public:
  /**
   * @brief Iterator category
   *
   */
  using iterator_category = ::portable_stl::bidirectional_iterator_tag;
  /**
   * @brief Value type.
   *
   */
  using value_type        = t_type;
  /**
   * @brief Reference type.
   *
   */
  using reference         = value_type &;
  /**
   * @brief Pointer type.
   *
   */
  using pointer           = ::portable_stl::rebind_pointer_t<t_void_ptr, value_type>;
  /**
   * @brief Difference type.
   *
   */
  using difference_type   = typename ::portable_stl::pointer_traits<pointer>::difference_type;

  /**
   * @brief Default constructor.
   *
   */
  list_iterator() noexcept : m_ptr(nullptr) {
  }

  /**
   * @brief Dereference operator.
   *
   * @return reference Reference to node value.
   */
  reference operator*() const {
    return m_ptr->as_node()->get_value();
  }

  /**
   * @brief Returns pointer to current element.
   *
   * @return pointer Pointer to node element value.
   */
  pointer operator->() const {
    return ::portable_stl::pointer_traits<pointer>::pointer_to(m_ptr->as_node()->get_value());
  }

  /**
   * @brief Pre-increments by one.
   *
   * @return list_iterator& *this.
   */
  list_iterator &operator++() {
    m_ptr = m_ptr->m_next;
    return *this;
  }

  /**
   * @brief Post-increments by one.
   *
   * @return list_iterator A copy of *this that was made before the change.
   */
  list_iterator operator++(int) {
    list_iterator tmp{*this};
    ++(*this);
    return tmp;
  }

  /**
   * @brief Pre-decrements by one.
   *
   * @return list_iterator& *this.
   */
  list_iterator &operator--() {
    m_ptr = m_ptr->m_prev;
    return *this;
  }

  /**
   * @brief Post-decrements by one.
   *
   * @return list_iterator A copy of *this that was made before the change.
   */
  list_iterator operator--(int) {
    list_iterator tmp{*this};
    --(*this);
    return tmp;
  }

  /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying pointers are equal,
   * @return false otherwise
   */
  friend bool operator==(list_iterator const &lhv, list_iterator const &rhv) {
    return lhv.m_ptr == rhv.m_ptr;
  }

  /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying pointers are not equal,
   * @return false otherwise
   */
  friend bool operator!=(list_iterator const &lhv, list_iterator const &rhv) {
    return !(lhv == rhv);
  }
};
} // namespace portable_stl

#endif // PSTL_LIST_ITERATOR_H
