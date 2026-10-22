// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_const_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAP_CONST_ITERATOR_H
#define PSTL_MAP_CONST_ITERATOR_H

#include "../iterator/bidirectional_iterator_tag.h"
#include "map_iterator.h"
#include "../memory/pointer_traits.h"

namespace portable_stl {

/**
 * @brief Constant iterator for nodes of a map.
 * 
 * @tparam t_tree_iterator Type of map's base tree.
 */
template<class t_tree_iterator> class map_const_iterator {
  /**
   * @brief 
   * 
   */
  using t_node_types     = typename t_tree_iterator::t_node_types;
  /**
   * @brief 
   * 
   */
  using t_pointer_traits = typename t_tree_iterator::t_pointer_traits;

/**
 * @brief Internally stored tree iterator.
 * 
 */
  t_tree_iterator m_iter;

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
  using value_type        = typename t_node_types::t_map_value_type;
  
  /**
   * @brief Reference type.
   *
   */
  using reference         = value_type const &;
  
  /**
   * @brief Pointer type.
   *
   */
  using pointer           = typename t_node_types::t_const_map_value_type_pointer;
  
  /**
   * @brief Difference type.
   *
   */
  using difference_type   = typename t_tree_iterator::difference_type;


/**
 * @brief Default constructor.
 * 
 */
  map_const_iterator() noexcept {
  }

/**
 * @brief Constructor from tree iterator.
 * 
 * @param iter 
 */
  map_const_iterator(t_tree_iterator iter) noexcept : m_iter(iter) {
  }

/**
 * @brief Constructor from non constant iterator.
 * 
 * @param iter 
 */
  map_const_iterator(::portable_stl::map_iterator<typename t_tree_iterator::t_non_const_iterator> iter) noexcept : m_iter(iter.m_iter) {
  }

  /**
   * @brief Dereference operator.
   *
   * @return reference Reference to node value.
   */
  reference operator*() const {
    return m_iter->get_value();
  }

/**
   * @brief Returns pointer to current element.
   *
   * @return pointer Pointer to node element value.
   */
  pointer operator->() const {
    return ::portable_stl::pointer_traits<pointer>::pointer_to(m_iter->get_value());
  }

  /**
   * @brief Pre-increments by one.
   *
   * @return map_const_iterator& *this.
   */
  map_const_iterator &operator++() {
    ++m_iter;
    return *this;
  }

  /**
   * @brief Post-increments by one.
   *
   * @return map_const_iterator A copy of *this that was made before the change.
   */
  map_const_iterator operator++(int) {
    map_const_iterator tmp{*this};
    ++(*this);
    return tmp;
  }

  /**
   * @brief Pre-decrements by one.
   *
   * @return map_const_iterator& *this.
   */
  map_const_iterator &operator--() {
    --m_iter;
    return *this;
  }

  /**
   * @brief Post-decrements by one.
   *
   * @return map_const_iterator A copy of *this that was made before the change.
   */
  map_const_iterator operator--(int) {
    map_const_iterator tmp{*this};
    --(*this);
    return tmp;
  }

  /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying iterator are equal,
   * @return false false otherwise
   */
  friend bool operator==(map_const_iterator const &lhv, map_const_iterator const &rhv) {
    return lhv.m_iter == rhv.m_iter;
  }

    /**
   * @brief Compares the iterators.
   *
   * @param lhv Iterator to compare.
   * @param rhv Iterator to compare.
   * @return true If underlying iterator are not equal,
   * @return false false otherwise
   */
  friend bool operator!=(map_const_iterator const &lhv, map_const_iterator const &rhv) {
    return lhv.m_iter != rhv.m_iter;
  }

  template<class, class, class, class> friend class map;
  template<class, class, class, class> friend class multimap;
  template<class, class, class> friend class tree_const_iterator;
};

}

#endif // PSTL_MAP_CONST_ITERATOR_H
