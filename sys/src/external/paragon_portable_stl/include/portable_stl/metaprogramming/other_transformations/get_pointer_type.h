// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_pointer_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_POINTER_TYPE_H
#define PSTL_GET_POINTER_TYPE_H

#include "../pointer_modifications/add_pointer.h"
#include "void_t.h"

namespace portable_stl {
/**
 * @brief Get the type of pointer from t_class_type or t_type.
 * @tparam t_type the type for get pointer.
 * @tparam t_class_type the class with type named pointer.
 *
 * Version t_class_type not contain type named pointer.
 */
template<class t_type, class t_class_type, class = void> class get_pointer_type final {
public:
  /**
   * @brief Result type.
   */
  using type = ::portable_stl::add_pointer_t<t_type>;
};

/**
 * @brief Get the type of pointer from t_class_type or t_type.
 * @tparam t_type the type for get pointer.
 * @tparam t_class_type the class with type named pointer.
 *
 * Version t_class_type contain type named pointer.
 */
template<class t_type, class t_class_type>
class get_pointer_type<t_type, t_class_type, ::portable_stl::void_t<typename t_class_type::pointer>> final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_class_type::pointer;
};

/**
 * @brief Get the type of pointer from t_class_type or t_type.
 * @tparam t_type the type for get pointer.
 * @tparam t_class_type the class with type named pointer.
 *
 * Result type is t_class_type::pointer or t_type*.
 */
template<class t_type, class t_class_type>
using get_pointer_type_t = typename get_pointer_type<t_type, t_class_type>::type;
} // namespace portable_stl

#endif // PSTL_GET_POINTER_TYPE_H
