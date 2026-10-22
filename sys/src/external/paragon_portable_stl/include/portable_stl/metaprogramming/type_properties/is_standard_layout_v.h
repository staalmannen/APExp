// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_standard_layout_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_STANDARD_LAYOUT_V_H
#define PSTL_IS_STANDARD_LAYOUT_V_H

#include "is_standard_layout.h"
namespace portable_stl {
/**
 * @brief t_type is a standard-layout type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> constexpr inline bool is_standard_layout_v = ::portable_stl::is_standard_layout<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_STANDARD_LAYOUT_V_H
