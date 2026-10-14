// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_node_base.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_NODE_BASE_H
#define PSTL_LIST_NODE_BASE_H

#include "list_types.h"

namespace portable_stl {

/**
 * @brief List base node type, represented list structure.
 *
 * @tparam t_type Node value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_node_base {
public:
  /**
   * @brief
   *
   */
  using t_node_traits  = ::portable_stl::list_node_pointer_traits<t_type, t_void_ptr>;
  /**
   * @brief
   *
   */
  using t_node_pointer = typename t_node_traits::t_node_pointer;
  /**
   * @brief
   *
   */
  using t_base_pointer = typename t_node_traits::t_base_pointer;
  /**
   * @brief
   *
   */
  using t_link_pointer = typename t_node_traits::t_link_pointer;

  /**
   * @brief Pointer to the next node.
   *
   */
  t_link_pointer m_prev;

  /**
   * @brief Pointer to the prev node.
   *
   */
  t_link_pointer m_next;

  /**
   * @brief Default constructor.
   *
   */
  list_node_base()
      : m_prev(t_node_traits::unsafe_link_pointer_cast(M_self()))
      , m_next(t_node_traits::unsafe_link_pointer_cast(M_self())) {
  }

  /**
   * @brief Constructor.
   *
   * @param prev Pointer to the next node.
   * @param next Pointer to the prev node.
   */
  explicit list_node_base(t_link_pointer prev, t_link_pointer next) : m_prev(prev), m_next(next) {
  }

  /**
   * @brief Cast to type of pointer to base node.
   *
   * @return t_base_pointer Pointer to base node.
   */
  t_base_pointer M_self() {
    return pointer_traits<t_base_pointer>::pointer_to(*this);
  }

  /**
   * @brief Cast to type of pointer to node.
   *
   * @return t_node_pointer Pointer to node.
   */
  t_node_pointer as_node() {
    return static_cast<t_node_pointer>(M_self());
  }
};
} // namespace portable_stl

#endif // PSTL_LIST_NODE_BASE_H
