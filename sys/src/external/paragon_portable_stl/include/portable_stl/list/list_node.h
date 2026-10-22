// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_node.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_NODE_H
#define PSTL_LIST_NODE_H

#include "list_node_base.h"

namespace portable_stl {

/**
 * @brief List node type.
 *
 * @tparam t_type Node value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_node : public list_node_base<t_type, t_void_ptr> {
  /**
   * @brief We allow starting the lifetime of nodes without initializing the value held by the node, since that is
   * handled by the list itself in order to be allocator-aware. Constructed in list_impl::create_node().
   */
  union {
    /**
     * @brief Node stored value.
     *
     */
    t_type m_value;
  };

public:
  /**
   * @brief Get the value of the node.
   *
   * @return t_type& node's value.
   */
  t_type &get_value() {
    return m_value;
  }

  /**
   * @brief
   *
   */
  using t_base = ::portable_stl::list_node_base<t_type, t_void_ptr>;
  /**
   * @brief
   *
   */
  using t_link_pointer = typename t_base::t_link_pointer;

  /**
   * @brief Constructor.
   * 
   * @param prev Pointer to the next node.
   * @param next Pointer to the prev node.
   */
  explicit list_node(t_link_pointer prev, t_link_pointer next) : t_base(prev, next) {
  }

  /**
   * @brief Destructor.
   * 
   */
  ~list_node() {
  }

  /**
   * @brief Cast to type of pointer to base node.
   * 
   * @return t_link_pointer Pointer to base node.
   */
  t_link_pointer as_link() {
    return static_cast<t_link_pointer>(t_base::M_self());
  }
};
} // namespace portable_stl

#endif // PSTL_LIST_NODE_H
