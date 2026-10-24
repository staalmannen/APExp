// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_TYPES_H
#define PSTL_LIST_TYPES_H

#include "../memory/rebind_pointer.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../metaprogramming/type_traits/has_input_iterator_category.h"

namespace portable_stl {
/**
 * @brief Forward declaration.
 *
 * @tparam t_type Node value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_node;

/**
 * @brief Forward declaration.
 *
 * @tparam t_type Node value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_node_base;

/**
 * @brief List node tratis type.
 *
 * @tparam t_type Node value type.
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr> class list_node_pointer_traits final {
public:
/**
 * @brief Type of node.
 * 
 */
  using t_node_pointer = ::portable_stl::rebind_pointer_t<t_void_ptr, list_node<t_type, t_void_ptr>>;
  /**
   * @brief Type of node base.
   * 
   */
  using t_base_pointer = ::portable_stl::rebind_pointer_t<t_void_ptr, list_node_base<t_type, t_void_ptr>>;

// #if defined(_LIBCPP_ABI_LIST_REMOVE_NODE_POINTER_UB)
  // using t_link_pointer = t_base_pointer;
// #else
  /**
   * @brief 
   * 
   */
  using t_link_pointer = ::portable_stl::
    conditional_bool_constant_t<::portable_stl::is_pointer<t_void_ptr>, t_base_pointer, t_node_pointer>;
// #endif

  /**
   * @brief 
   * 
   */
  using t_non_link_pointer
    = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_same<t_link_pointer, t_node_pointer>,
                                                  t_base_pointer,
                                                  t_node_pointer>;

  /**
   * @brief Cast to type of pointer to node base.
   * 
   * @param ptr 
   * @return t_link_pointer 
   */
  static t_link_pointer unsafe_link_pointer_cast(t_link_pointer ptr) {
    return ptr;
  }

  /**
   * @brief Cast to type of pointer to node base.
   * 
   * @param ptr 
   * @return t_link_pointer 
   */
  static t_link_pointer unsafe_link_pointer_cast(t_non_link_pointer ptr) {
    return static_cast<t_link_pointer>(static_cast<t_void_ptr>(ptr));
  }
};

namespace list_helper {
  /**
   * @brief Helper alias to select functions for input iterators.
   * 
   * @tparam t_iterator 
   */
  template<class t_iterator>
  using enable_for_input_iter
    = ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_iterator>, void *>;

} // namespace list_helper
} // namespace portable_stl

#endif // PSTL_LIST_TYPES_H
