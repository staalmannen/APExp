// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_node.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_LIST_NODE_H
#define PSTL_FORWARD_LIST_NODE_H

#include "../memory/rebind_pointer.h"
#include "forward_begin_node.h"

namespace portable_stl {

/**
 * @brief Forward declaration.
 *
 * @tparam t_type Value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> struct forward_list_node;

template<class t_type, class t_void_ptr>
using t_begin_node_of
  = forward_begin_node<::portable_stl::rebind_pointer_t<t_void_ptr, forward_list_node<t_type, t_void_ptr>>>;

/**
 * @brief Forward list node type.
 *
 * @tparam t_type Value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> struct forward_list_node : public t_begin_node_of<t_type, t_void_ptr> {
  /**
   * @brief Node value type.
   *
   */
  using value_type = t_type;
  /**
   * @brief Base node type.
   *
   */
  using t_base     = t_begin_node_of<t_type, t_void_ptr>;
  /**
   * @brief Node pointer type.
   *
   */
  using t_node_ptr = typename t_base::pointer;

private:
  /**
   * @brief We allow starting the lifetime of nodes without initializing the value held by the node, since that is
   * handled by the list itself in order to be allocator-aware.
   * Constructed in forward_list_impl::create_node().
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
   * @brief Constructor.
   *
   * @param next Pointer to the next node.
   */
  explicit forward_list_node(t_node_ptr next) : t_base(next) {
  }

  /**
   * @brief Destroy the forward list node object.
   *
   */
  ~forward_list_node() {
  }
};

} // namespace portable_stl

#endif // PSTL_FORWARD_LIST_NODE_H
