// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_const_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_CONST_ITERATOR_H
#define PSTL_TREE_CONST_ITERATOR_H

#include "../iterator/bidirectional_iterator_tag.h"
#include "../memory/pointer_traits.h"
#include "tree_iterator.h"
#include "tree_node_types.h"

namespace portable_stl {

/**
 * @brief Constant iterator for nodes of a RB-tree.
 *
 * @tparam t_type Node's value type.
 * @tparam t_node_ptr
 * @tparam t_diff_type
 */
template<class t_type, class t_node_ptr, class t_diff_type> class tree_const_iterator {
  /**
   * @brief Node type.
   *
   */
  using t_node_types        = portable_stl::tree_node_types<t_node_ptr>;
  /**
   * @brief Node pointer type.
   *
   */
  using t_node_pointer      = typename t_node_types::t_node_pointer;
  /**
   * @brief Node base pointer type.
   *
   */
  using t_node_base_pointer = typename t_node_types::t_node_base_pointer;
  /**
   * @brief End node pointer type.
   *
   */
  using t_end_node_pointer  = typename t_node_types::t_end_node_pointer;
  /**
   * @brief Used by iterator pointer type.
   *
   */
  using t_iter_pointer      = typename t_node_types::t_iter_pointer;
  /**
   * @brief Node pointer traits type.
   *
   */
  using t_pointer_traits    = ::portable_stl::pointer_traits<t_node_pointer>;

  /**
   * @brief Internally stored pointer.
   *
   */
  t_iter_pointer m_ptr;

public:
  /**
   * @brief Iterator category.
   *
   */
  using iterator_category = ::portable_stl::bidirectional_iterator_tag;
  /**
   * @brief Node's value type.
   *
   */
  using value_type        = t_type;
  /**
   * @brief Differenc type.
   *
   */
  using difference_type   = t_diff_type;
  /**
   * @brief Reference type.
   *
   */
  using reference         = value_type const &;
  /**
   * @brief Pointer to node's value type.
   *
   */
  using pointer           = typename t_node_types::t_const_node_value_type_pointer;

  /**
   * @brief Default constructor.
   *
   */
  tree_const_iterator() noexcept : m_ptr(nullptr) {
  }

private:
  /**
   * @brief
   *
   */
  using t_non_const_iterator = ::portable_stl::tree_iterator<value_type, t_node_pointer, difference_type>;

public:
  /**
   * @brief Constructor from non constant iterator.
   *
   * @param ptr
   */
  tree_const_iterator(t_non_const_iterator iter) noexcept : m_ptr(iter.m_ptr) {
  }

  /**
   * @brief Dereference operator.
   *
   * @return reference Reference to value.
   */
  reference operator*() const {
    return get_node_pointer()->m_value;
  }

  /**
   * @brief Returns pointer to current element.
   *
   * @return pointer Pointer to node element value.
   */
  pointer operator->() const {
    return ::portable_stl::pointer_traits<pointer>::pointer_to(get_node_pointer()->m_value);
  }

  /**
   * @brief Pre-increments by one.
   *
   * @return tree_const_iterator& *this.
   */
  tree_const_iterator &operator++() {
    m_ptr = static_cast<t_iter_pointer>(
      tree_ns::tree_next_iter<t_end_node_pointer>(static_cast<t_node_base_pointer>(m_ptr)));
    return *this;
  }

  /**
   * @brief Post-increments by one.
   *
   * @return tree_const_iterator A copy of *this that was made before the change.
   */
  tree_const_iterator operator++(int) {
    tree_const_iterator iter(*this);
    ++(*this);
    return iter;
  }

  /**
   * @brief Pre-decrements by one.
   *
   * @return tree_const_iterator& *this.
   */
  tree_const_iterator &operator--() {
    m_ptr = static_cast<t_iter_pointer>(
      tree_ns::tree_prev_iter<t_node_base_pointer>(static_cast<t_end_node_pointer>(m_ptr)));
    return *this;
  }

  /**
   * @brief Post-decrements by one.
   *
   * @return tree_const_iterator A copy of *this that was made before the change.
   */
  tree_const_iterator operator--(int) {
    tree_const_iterator iter(*this);
    --(*this);
    return iter;
  }

  /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying pointers are equal,
   * @return false otherwise
   */
  friend bool operator==(tree_const_iterator const &lhv, tree_const_iterator const &rhv) {
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
  friend bool operator!=(tree_const_iterator const &lhv, tree_const_iterator const &rhv) {
    return !(lhv == rhv);
  }

private:
  /**
   * @brief Constructor.
   *
   * @param ptr
   */
  explicit tree_const_iterator(t_node_pointer ptr) noexcept : m_ptr(ptr) {
  }

  /**
   * @brief Constructor.
   *
   * @param ptr
   */
  explicit tree_const_iterator(t_end_node_pointer ptr) noexcept : m_ptr(ptr) {
  }

  /**
   * @brief Casts to node pointer type.
   *
   * @return t_node_pointer node pointer.
   */
  t_node_pointer get_node_pointer() const {
    return static_cast<t_node_pointer>(m_ptr);
  }

  template<class, class, class> friend class tree;
  template<class, class, class, class> friend class map;
  template<class, class, class, class> friend class multimap;
  template<class, class, class> friend class set;
  template<class, class, class> friend class multiset;
  template<class> friend class map_const_iterator;
};

} // namespace portable_stl

#endif // PSTL_TREE_CONST_ITERATOR_H
