// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_unsigned_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_UNSIGNED_V_H
#define PSTL_IS_UNSIGNED_V_H

#include "is_unsigned.h"
namespace portable_stl {
/**
 * @brief t_type is a unsigned type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> constexpr inline bool is_unsigned_v = ::portable_stl::is_unsigned<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_UNSIGNED_V_H
