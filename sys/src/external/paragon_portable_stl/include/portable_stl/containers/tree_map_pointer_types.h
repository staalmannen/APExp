// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_map_pointer_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_MAP_POINTER_TYPES_H
#define PSTL_TREE_MAP_POINTER_TYPES_H

#include "../memory/rebind_pointer.h"
#include "tree_key_value_types.h"

namespace portable_stl {

/**
 * @brief Helper to select appropriate types.
 * Primary template.
 *
 * @tparam t_type Given type.
 */
template<class t_type,
         class t_ptr_allocator,
         class t_key_value_type = tree_key_value_types<t_type>,
         bool                   = t_key_value_type::m_is_map>
struct tree_map_pointer_types {};

/**
 * @brief Helper to select appropriate types.
 *
 * @tparam t_type
 * @tparam t_ptr_allocator
 * @tparam t_key_value_type
 */
template<class t_type, class t_ptr_allocator, class t_key_value_type>
struct tree_map_pointer_types<t_type, t_ptr_allocator, t_key_value_type, true> {
  /**
   * @brief
   *
   */
  using t_map_value = typename t_key_value_type::t_map_value_type;

  /**
   * @brief
   *
   */
  using t_map_value_type_pointer = ::portable_stl::rebind_pointer_t<t_ptr_allocator, t_map_value>;

  /**
   * @brief
   *
   */
  using t_const_map_value_type_pointer = ::portable_stl::rebind_pointer_t<t_ptr_allocator, t_map_value const>;
};

} // namespace portable_stl

#endif // PSTL_TREE_MAP_POINTER_TYPES_H
