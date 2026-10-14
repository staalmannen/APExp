// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_null_pointer_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NULL_POINTER_V_H
#define PSTL_IS_NULL_POINTER_V_H

#include "is_null_pointer.h"

namespace portable_stl {
/**
 * @brief The t_type is nullptr_t regardless cv modifications.
 *
 * @tparam t_type the type for check.
 */
template<class t_type> constexpr inline bool is_null_pointer_v = ::portable_stl::is_null_pointer<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_NULL_POINTER_V_H
