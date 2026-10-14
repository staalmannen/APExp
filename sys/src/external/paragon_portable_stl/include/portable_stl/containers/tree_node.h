// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_node.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_NODE_H
#define PSTL_TREE_NODE_H

#include "tree_node_base.h"

namespace portable_stl {

/**
 * @brief RB-tree node type.
 *
 * @tparam t_type Stored value type.
 * @tparam t_void_ptr Void pointer type.
 */
template<class t_type, class t_void_ptr> class tree_node : public tree_node_base<t_void_ptr> {
public:
  /**
   * @brief Node's value type.
   *
   */
  using t_node_value_type = t_type;

  /**
   * @brief Stored value.
   *
   */
  t_node_value_type m_value;

  /**
   * @brief Value getter.
   *
   * @return t_type&
   */
  t_type &get_value() {
    return m_value;
  }

  /**
   * @brief Deleted constructor.
   *
   */
  ~tree_node() = delete;

  /**
   * @brief Deleted copy constructor.
   *
   */
  tree_node(tree_node const &) = delete;

  /**
   * @brief Deleted copy assignment operator.
   *
   */
  tree_node &operator=(tree_node const &) = delete;
};

} // namespace portable_stl

#endif // PSTL_TREE_NODE_H
