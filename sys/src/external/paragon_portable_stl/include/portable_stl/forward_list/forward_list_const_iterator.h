// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_const_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_LIST_CONST_ITERATOR_H
#define PSTL_FORWARD_LIST_CONST_ITERATOR_H

#include "../iterator/forward_iterator_tag.h"
#include "../memory/rebind_pointer.h"
#include "../metaprogramming/type_properties/is_const.h"
#include "forward_list_iterator.h"
#include "forward_list_types.h"

namespace portable_stl {

/**
 * @brief Constant iterator for nodes of a forward list.
 *
 * @tparam t_node_const_ptr
 */
template<class t_node_const_ptr> class forward_list_const_iterator {
  static_assert(!is_const<typename pointer_traits<t_node_const_ptr>::element_type>{}(), "");
  /**
   * @brief
   *
   */
  using t_node_ptr = t_node_const_ptr;

  /**
   * @brief
   *
   */
  using t_traits = ::portable_stl::forward_node_traits<t_node_ptr>;

  /**
   * @brief
   *
   */
  using t_node_type = typename t_traits::t_node_type;

  /**
   * @brief
   *
   */
  using t_node_pointer = typename t_traits::t_node_pointer;

  /**
   * @brief
   *
   */
  using t_begin_node_pointer = typename t_traits::t_begin_node_pointer;

  /**
   * @brief
   *
   */
  using t_iter_node_pointer = typename t_traits::t_iter_node_pointer;

  /**
   * @brief
   *
   */
  using t_void_pointer = typename t_traits::t_void_pointer;

  /**
   * @brief Internally stored pointer.
   *
   */
  t_iter_node_pointer m_ptr;

  /**
   * @brief Cast to t_begin_node_pointer type.
   *
   * @return t_begin_node_pointer Result pointer.
   */
  t_begin_node_pointer get_begin() const {
    return static_cast<t_begin_node_pointer>(static_cast<t_void_pointer>(m_ptr));
  }

  /**
   * @brief Cast to t_node_pointer type.
   *
   * @return t_node_pointer Result pointer.
   */
  t_node_pointer get_unsafe_node_pointer() const {
    return static_cast<t_node_pointer>(static_cast<t_void_pointer>(m_ptr));
  }

  /**
   * @brief Constructor.
   *
   */
  explicit forward_list_const_iterator(nullptr_t) noexcept : m_ptr(nullptr) {
  }

  /**
   * @brief Constructor.
   *
   * @param ptr Given pointer.
   */
  explicit forward_list_const_iterator(t_begin_node_pointer ptr) noexcept : m_ptr(t_traits::as_iter_node(ptr)) {
  }

  /**
   * @brief Constructor
   *
   * @param ptr Given pointer.
   */
  explicit forward_list_const_iterator(t_node_pointer ptr) noexcept : m_ptr(t_traits::as_iter_node(ptr)) {
  }

  template<class, class> friend class forward_list;

public:
  /**
   * @brief Iterator category.
   *
   */
  using iterator_category = ::portable_stl::forward_iterator_tag;
  /**
   * @brief Value type.
   *
   */
  using value_type        = typename t_traits::t_node_value_type;
  /**
   * @brief Reference type.
   *
   */
  using reference         = value_type const &;
  /**
   * @brief Difference type.
   *
   */
  using difference_type   = typename pointer_traits<t_node_pointer>::difference_type;
  /**
   * @brief Pointer type.
   *
   */
  using pointer           = ::portable_stl::rebind_pointer_t<t_node_pointer, value_type const>;

  /**
   * @brief Default constructor.
   */
  forward_list_const_iterator() noexcept : m_ptr(nullptr) {
  }

  /**
   * @brief Constructor from non constant iterator.
   *
   * @param iter Non constant iterator.
   */
  forward_list_const_iterator(forward_list_iterator<t_node_pointer> iter) noexcept : m_ptr(iter.m_ptr) {
  }

  /**
   * @brief Dereference operator.
   *
   * @return reference Reference to node value.
   */
  reference operator*() const {
    return get_unsafe_node_pointer()->get_value();
  }

  /**
   * @brief Returns pointer to current element.
   *
   * @return Pointer to node element value.
   */
  pointer operator->() const {
    return pointer_traits<pointer>::pointer_to(get_unsafe_node_pointer()->get_value());
  }

  /**
   * @brief Pre-increments by one.
   *
   * @return forward_list_const_iterator& *this.
   */
  forward_list_const_iterator &operator++() {
    m_ptr = t_traits::as_iter_node(m_ptr->m_next);
    return *this;
  }

  /**
   * @brief Post-increments by one
   *
   * @return forward_list_const_iterator
   */
  forward_list_const_iterator operator++(int) {
    forward_list_const_iterator tmp(*this);
    ++(*this);
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
  friend bool operator==(forward_list_const_iterator const &lhv, forward_list_const_iterator const &rhv) {
    return lhv.m_ptr == rhv.m_ptr;
  }

  /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying pointers are not equal,
   * @return false otherwise.
   */
  friend bool operator!=(forward_list_const_iterator const &lhv, forward_list_const_iterator const &rhv) {
    return !(lhv == rhv);
  }
};

} // namespace portable_stl

#endif // PSTL_FORWARD_LIST_CONST_ITERATOR_H
