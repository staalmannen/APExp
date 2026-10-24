// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_end_node.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_END_NODE_H
#define PSTL_TREE_END_NODE_H

namespace portable_stl {

/**
 * @brief RB-tree end node type, represented tree structure.
 *
 * @tparam t_pointer Pointer type.
 */
template<class t_pointer> class tree_end_node {
public:
  /**
   * @brief Pointer type.
   *
   */
  using pointer = t_pointer;

  /**
   * @brief The only one stored pointer.
   *
   */
  pointer m_left;

  /**
   * @brief Default constructor.
   *
   */
  tree_end_node() noexcept : m_left() {
  }
};

} // namespace portable_stl

#endif // PSTL_TREE_END_NODE_H
