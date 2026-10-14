// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_node_base_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_NODE_BASE_TYPES_H
#define PSTL_TREE_NODE_BASE_TYPES_H

#include "../memory/pointer_traits.h"
#include "../memory/rebind_pointer.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "tree_end_node.h"
// #include "tree_node_base.h"

namespace portable_stl {

template<class t_void_ptr> class tree_node_base;

/**
 * @brief Tree node base types traits.
 *
 * @tparam t_void_ptr Given void pointer type.
 */
template<class t_void_ptr> class tree_node_base_types {
public:
  /**
   * @brief Void pointer type (from allocator).
   */
  using t_void_pointer = t_void_ptr;

  /**
   * @brief Type of an base node in a tree.
   *
   */
  using t_node_base_type    = ::portable_stl::tree_node_base<t_void_pointer>;
  /**
   * @brief Type of a pointer to then base node in a tree.
   *
   */
  using t_node_base_pointer = ::portable_stl::rebind_pointer_t<t_void_ptr, t_node_base_type>;

  /**
   * @brief Type of an end node in a tree.
   *
   */
  using t_end_node_type    = ::portable_stl::tree_end_node<t_node_base_pointer>;
  /**
   * @brief Type of a pointer to then end node in a tree.
   *
   */
  using t_end_node_pointer = ::portable_stl::rebind_pointer_t<t_void_ptr, t_end_node_type>;

  /**
   * @brief Type of the pointer to the parent node.
   *
   */
  using t_parent_pointer = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_pointer<t_end_node_pointer>,
                                                                       t_end_node_pointer,
                                                                       t_node_base_pointer>;

private:
  static_assert(::portable_stl::is_same<typename ::portable_stl::pointer_traits<t_void_ptr>::element_type, void>{}(),
                "t_void_ptr does not point to unqualified void type");
};

} // namespace portable_stl

#endif // PSTL_TREE_NODE_BASE_TYPES_H
