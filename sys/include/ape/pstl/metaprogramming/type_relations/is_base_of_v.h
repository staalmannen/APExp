// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_base_of_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_BASE_OF_V_H
#define PSTL_IS_BASE_OF_V_H

#include "is_base_of.h"

namespace portable_stl {
/**
 * @brief Checks if a type is derived from the other type.
 *
 * @tparam base_type The base type to check.
 * @tparam derived_type The derived type to check.
 */
template<class base_type, class derived_type>
constexpr inline bool is_base_of_v = ::portable_stl::is_base_of<base_type, derived_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_BASE_OF_V_H
