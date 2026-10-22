// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_begin_node.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_BEGIN_NODE_H
#define PSTL_FORWARD_BEGIN_NODE_H

#include "../memory/rebind_pointer.h"

namespace portable_stl {

/**
 * @brief Base type for node of forward list.
 *
 * @tparam t_node_ptr Type of stored pointer.
 */
template<class t_node_ptr> struct forward_begin_node {
  /**
   * @brief Pointer type.
   *
   */
  using pointer = t_node_ptr;

  /**
   * @brief
   *
   */
  using t_begin_node_pointer = ::portable_stl::rebind_pointer_t<t_node_ptr, forward_begin_node>;

  /**
   * @brief Pointer to the next mode.
   *
   */
  pointer m_next;

  forward_begin_node() : m_next(nullptr) {
  }

  /**
   * @brief Constructor
   *
   * @param next Pointer to the next node.
   */
  explicit forward_begin_node(pointer next) : m_next(next) {
  }

  /**
   * @brief Cast m_node to t_begin_node_pointer.
   *
   * @return t_begin_node_pointer Result pointer.
   */
  t_begin_node_pointer next_as_begin() const {
    return static_cast<t_begin_node_pointer>(m_next);
  }
};

} // namespace portable_stl

#endif // PSTL_FORWARD_BEGIN_NODE_H
