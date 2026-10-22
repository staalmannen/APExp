// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_node_base.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_NODE_BASE_H
#define PSTL_TREE_NODE_BASE_H

#include "tree_node_base_types.h"

namespace portable_stl {

/**
 * @brief RB-tree base node type, represented tree structure.
 *
 * @tparam t_void_ptr
 */
template<class t_void_ptr> class tree_node_base : public tree_node_base_types<t_void_ptr>::t_end_node_type {
  using t_node_base_type = tree_node_base_types<t_void_ptr>;

public:
  /**
   * @brief Type of a pointer to the other nodes.
   *
   */
  using pointer          = typename t_node_base_type::t_node_base_pointer;
  /**
   * @brief Type of a pointer to the parent node.
   *
   */
  using t_parent_pointer = typename t_node_base_type::t_parent_pointer;

  /**
   * @brief Right sub-tree.
   *
   */
  pointer m_right;

  /**
   * @brief Parent node.
   *
   */
  t_parent_pointer m_parent;

  /**
   * @brief Node Color.
   *
   */
  bool m_is_black;

  /**
   * @brief Cast parent to pointer type.
   *
   * @return pointer
   */
  pointer parent_unsafe() const {
    return static_cast<pointer>(m_parent);
  }

  /**
   * @brief Parent object setter.
   *
   * @param new_parent
   */
  void set_parent(pointer new_parent) {
    m_parent = static_cast<t_parent_pointer>(new_parent);
  }

  /**
   * @brief Deleted constructor.
   *
   */
  ~tree_node_base() = delete;

  /**
   * @brief Deleted copy constructor.
   *
   */
  tree_node_base(tree_node_base const &) = delete;

  /**
   * @brief Deleted copy assignment operator.
   *
   */
  tree_node_base &operator=(tree_node_base const &) = delete;
};

} // namespace portable_stl

#endif // PSTL_TREE_NODE_BASE_H
