// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_node_destructor.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_NODE_DESTRUCTOR_H
#define PSTL_TREE_NODE_DESTRUCTOR_H

#include "../memory/allocator_traits.h"
#include "tree_node_types.h"

namespace portable_stl {

/**
 * @brief Used as node destructor in tree and node_handle.
 *
 * @tparam t_allocator Allocator type.
 */
template<class t_allocator> class tree_node_destructor {
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type = t_allocator;

  /**
   * @brief Allocator traits type.
   *
   */
  using t_alloc_traits = ::portable_stl::allocator_traits<allocator_type>;

public:
  /**
   * @brief Pointer type.
   *
   */
  using pointer = typename t_alloc_traits::pointer;

private:
  /**
   * @brief Node type.
   *
   */
  using t_node_types = ::portable_stl::tree_node_types<pointer>;

  /**
   * @brief Stored reference to node allocator.
   *
   */
  allocator_type &m_node_alloc;

public:
  /**
   * @brief Flag.
   *
   */
  bool m_value_constructed;

  /**
   * @brief Copy constructor.
   *
   */
  tree_node_destructor(tree_node_destructor const &) = default;

  /**
   * @brief Deleted copy assignment operator.
   *
   * @return tree_node_destructor& *this.
   */
  tree_node_destructor &operator=(tree_node_destructor const &) = delete;

  /**
   * @brief Constructed.
   *
   * @param node_alloc Given node allocator.
   * @param constrcuted Is node's value constructed.
   */
  explicit tree_node_destructor(allocator_type &node_alloc, bool constrcuted = false) noexcept
      : m_node_alloc(node_alloc), m_value_constructed(constrcuted) {
  }

  /**
   * @brief Functional call operator.
   * Destroy node and object.
   *
   * @param ptr Given pointer to the node.
   * @return ::portable_stl::expected<void, ::portable_stl::int32_t>
   */
  ::portable_stl::expected<void, ::portable_stl::int32_t> operator()(pointer ptr) noexcept {
    if (m_value_constructed) {
      t_alloc_traits::destroy(m_node_alloc, t_node_types::get_ptr(ptr->m_value));
    }
    if (ptr) {
      t_alloc_traits::deallocate(m_node_alloc, ptr, 1);
    }
    return {};
  }

  template<class> friend class map_node_destructor;
};

} // namespace portable_stl

#endif // PSTL_TREE_NODE_DESTRUCTOR_H
