// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_destructible_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_DESTRUCTIBLE_V_H
#define PSTL_IS_NOTHROW_DESTRUCTIBLE_V_H

#include "is_nothrow_destructible.h"
namespace portable_stl {
/**
 * @brief t_type can be destroyed without exceptions.
 *
 * @tparam t_type type for check.
 */
template<class t_type>
constexpr inline bool is_nothrow_destructible_v = ::portable_stl::is_nothrow_destructible<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_NOTHROW_DESTRUCTIBLE_V_H
