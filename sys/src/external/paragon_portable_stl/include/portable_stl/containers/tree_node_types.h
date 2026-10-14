// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_node_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_NODE_TYPES_H
#define PSTL_TREE_NODE_TYPES_H

#include "../memory/pointer_traits.h"
#include "../memory/rebind_pointer.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "tree_key_value_types.h"
#include "tree_map_pointer_types.h"
#include "tree_node.h"
#include "tree_node_base_types.h"

namespace portable_stl {

template<class t_node_ptr, class t_node_type = typename ::portable_stl::pointer_traits<t_node_ptr>::element_type>
struct tree_node_types;

template<class t_node_ptr, class t_type, class t_void_ptr>
struct tree_node_types<t_node_ptr, ::portable_stl::tree_node<t_type, t_void_ptr>>
    : public tree_node_base_types<t_void_ptr>
    , tree_key_value_types<t_type>
    , tree_map_pointer_types<t_type, t_void_ptr> {
  /**
   * @brief Tree's base node types.
   *
   */
  using t_base             = ::portable_stl::tree_node_base_types<t_void_ptr>;
  /**
   * @brief Tree's node keys types.
   *
   */
  using t_key_base         = ::portable_stl::tree_key_value_types<t_type>;
  /**
   * @brief
   *
   */
  using t_map_pointer_base = ::portable_stl::tree_map_pointer_types<t_type, t_void_ptr>;

public:
  /**
   * @brief Node type.
   *
   */
  using t_node_type    = typename ::portable_stl::pointer_traits<t_node_ptr>::element_type;
  /**
   * @brief Node pointer type.
   *
   */
  using t_node_pointer = t_node_ptr;

  /**
   * @brief Node's value type.
   *
   */
  using t_node_value_type               = t_type;
  /**
   * @brief  Node's value pointer type.
   *
   */
  using t_node_value_type_pointer       = ::portable_stl::rebind_pointer_t<t_void_ptr, t_node_value_type>;
  /**
   * @brief  Node's value constant pointer type.
   *
   */
  using t_const_node_value_type_pointer = ::portable_stl::rebind_pointer_t<t_void_ptr, t_node_value_type const>;
  /**
   * @brief Type of pointer stored by node iterator.
   *
   */
  using t_iter_pointer = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_pointer<t_node_pointer>,
                                                                     typename t_base::t_end_node_pointer,
                                                                     t_node_pointer>;

private:
  static_assert(!::portable_stl::is_const<t_node_type>{}(), "t_node_ptr should never be a pointer to const");
  static_assert((::portable_stl::is_same<::portable_stl::rebind_pointer_t<t_void_ptr, t_node_type>, t_node_ptr>{}()),
                "t_void_ptr does not rebind to t_node_ptr.");
};

} // namespace portable_stl

#endif // PSTL_TREE_NODE_TYPES_H
