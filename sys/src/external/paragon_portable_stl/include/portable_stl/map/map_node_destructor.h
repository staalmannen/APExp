// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_node_destructor.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAP_NODE_DESTRUCTOR_H
#define PSTL_MAP_NODE_DESTRUCTOR_H

#include "../memory/addressof.h"
#include "../memory/allocator_traits.h"

namespace portable_stl {

/**
 * @brief Used as node destructor in map and multimap.
 *
 * @tparam t_allocator Allocator type.
 */
template<class t_allocator> class map_node_destructor {
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type = t_allocator;

  /**
   * @brief Allocator traits type.
   *
   */
  using t_allocator_traits = ::portable_stl::allocator_traits<allocator_type>;

public:
  /**
   * @brief Pointer type.
   *
   */
  using pointer = typename t_allocator_traits::pointer;

private:
  /**
   * @brief Stored reference to node allocator.
   *
   */
  allocator_type &m_node_alloc;

  /**
   * @brief Copy assignmnent operator.
   *
   * @return map_node_destructor& *this.
   */
  map_node_destructor &operator=(map_node_destructor const &);

public:
  /**
   * @brief Flag.
   *
   */
  bool m_first_constructed;

  /**
   * @brief Flag.
   *
   */
  bool m_second_constructed;

  /**
   * @brief Constructor.
   *
   * @param node_alloc Given node allocator.
   */
  explicit map_node_destructor(allocator_type &node_alloc) noexcept
      : m_node_alloc(node_alloc), m_first_constructed(false), m_second_constructed(false) {
  }

  /**
   * @brief Move constructor from tree node destructor.
   *
   * @param other Another tree_node_destructor object.
   */
  map_node_destructor(tree_node_destructor<allocator_type> &&other) noexcept
      : m_node_alloc(other.m_node_alloc)
      , m_first_constructed(other.m_value_constructed)
      , m_second_constructed(other.m_value_constructed) {
    other.m_value_constructed = false;
  }

  /**
   * @brief Functional call operator.
   * Destroy node and objects (key and value).
   *
   * @param ptr Given pointer to the node.
   * @return ::portable_stl::expected<void, ::portable_stl::int32_t>
   */
  void operator()(pointer ptr) noexcept {
    if (m_second_constructed) {
      t_allocator_traits::destroy(m_node_alloc, ::portable_stl::addressof(ptr->m_value.get_value().second));
    }
    if (m_first_constructed) {
      t_allocator_traits::destroy(m_node_alloc, ::portable_stl::addressof(ptr->m_value.get_value().first));
    }
    if (ptr) {
      t_allocator_traits::deallocate(m_node_alloc, ptr, 1);
    }
  }
};

} // namespace portable_stl

#endif // PSTL_MAP_NODE_DESTRUCTOR_H
