// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_helpers.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_HELPERS_H
#define PSTL_TREE_HELPERS_H

#include "../memory/rebind_pointer.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/remove_cref.h"
#include "tree_node.h"
#include "tree_node_types.h"
#include "value_type_impl.h"

namespace portable_stl {
namespace tree_helper {
  /**
   * @brief Helper to prepare Node types used in tree class.
   *
   * @tparam t_value_type
   * @tparam t_void_ptr Void pointer type.
   */
  template<class t_value_type, class t_void_ptr> struct make_tree_node_types {
  private:
    /**
     * @brief Additional alias for msvc.
     */
    using t_tree_node = ::portable_stl::tree_node<t_value_type, t_void_ptr>;

  public:
    /**
     * @brief
     *
     */
    using t_node_ptr = ::portable_stl::rebind_pointer_t<t_void_ptr, t_tree_node>;

    /**
     * @brief Result type.
     *
     */
    using type = ::portable_stl::tree_node_types<t_node_ptr>;
  };

  template<class t_type> class is_tree_value_type_imp final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_key_type, class t_value_type>
  class is_tree_value_type_imp<::portable_stl::value_type_impl<t_key_type, t_value_type>> final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class... t_args> class is_tree_value_type {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class _One> class is_tree_value_type<_One> {
  public:
    using type = typename is_tree_value_type_imp<::portable_stl::remove_cref_t<_One>>::type;
  };
} // namespace tree_helper
} // namespace portable_stl

#endif // PSTL_TREE_HELPERS_H
