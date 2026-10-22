// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_swappable_with_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_SWAPPABLE_WITH_V_H
#define PSTL_IS_NOTHROW_SWAPPABLE_WITH_V_H

#include "is_nothrow_swappable_with.h"
namespace portable_stl {
/**
 * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
 * and swap(declval<t_other_type>(), declval<t_type>()) is valid without exceptions.
 *
 * @tparam t_type one type for check.
 * @tparam t_other_type other type for check.
 */
template<class t_type, class t_other_type>
constexpr inline bool is_nothrow_swappable_with_v = ::portable_stl::is_nothrow_swappable_with<t_type, t_other_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_NOTHROW_SWAPPABLE_WITH_V_H
