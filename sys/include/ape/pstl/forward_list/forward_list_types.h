// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_LIST_TYPES_H
#define PSTL_FORWARD_LIST_TYPES_H

#include "../memory/pointer_traits.h"
#include "../memory/rebind_pointer.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "forward_begin_node.h"
#include "forward_list_node.h"

namespace portable_stl {

/**
 * @brief Helper to select value type of forward list's node.
 * Primary template.
 */
template<class> class forward_list_node_value_type;

/**
 * @brief Helper to select value type of forward list's node.
 *
 * @tparam t_type
 * @tparam t_void_ptr
 */
template<class t_type, class t_void_ptr>
class forward_list_node_value_type<forward_list_node<t_type, t_void_ptr>> final {
public:
  /**
   * @brief Value type.
   *
   */
  using type = t_type;
};

/**
 * @brief Forward list's node traits.
 *
 * @tparam t_node_ptr
 */
template<class t_node_ptr> struct forward_node_traits {
  /**
   * @brief
   *
   */
  using t_node_type = ::portable_stl::remove_cv_t<typename ::portable_stl::pointer_traits<t_node_ptr>::element_type>;
  /**
   * @brief
   *
   */
  using t_node_value_type    = typename forward_list_node_value_type<t_node_type>::type;
  /**
   * @brief
   *
   */
  using t_node_pointer       = t_node_ptr;
  /**
   * @brief
   *
   */
  using t_begin_node         = forward_begin_node<t_node_ptr>;
  /**
   * @brief
   *
   */
  using t_begin_node_pointer = ::portable_stl::rebind_pointer_t<t_node_ptr, t_begin_node>;
  /**
   * @brief
   *
   */
  using t_void_pointer       = ::portable_stl::rebind_pointer_t<t_node_ptr, void>;

  // #if defined(_LIBCPP_ABI_FORWARD_LIST_REMOVE_NODE_POINTER_UB)
  //   using t_iter_node_pointer = t_begin_node_pointer;
  // #else
  /**
   * @brief
   *
   */
  using t_iter_node_pointer = ::portable_stl::
    conditional_bool_constant_t<::portable_stl::is_pointer<t_void_pointer>, t_begin_node_pointer, t_node_pointer>;
  // #endif

  /**
   * @brief
   *
   */
  using t_non_iter_node_pointer
    = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_same<t_iter_node_pointer, t_node_pointer>,
                                                  t_begin_node_pointer,
                                                  t_node_pointer>;

  /**
   * @brief
   *
   * @param ptr
   * @return t_iter_node_pointer
   */
  static t_iter_node_pointer as_iter_node(t_iter_node_pointer ptr) {
    return ptr;
  }

  /**
   * @brief
   *
   * @param ptr
   * @return
   */
  static t_iter_node_pointer as_iter_node(t_non_iter_node_pointer ptr) {
    return static_cast<t_iter_node_pointer>(static_cast<t_void_pointer>(ptr));
  }
};

} // namespace portable_stl

#endif // PSTL_FORWARD_LIST_TYPES_H
