// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rank_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_RANK_V_H
#define PSTL_RANK_V_H

#include "rank.h"
namespace portable_stl {
/**
 * @brief If t_type is an array type, provides the member constant value equal to the number of dimensions of the array.
 * For any other type, value is ​0​.
 *
 * @tparam t_type Type for property query.
 */
template<class t_type> constexpr inline ::portable_stl::size_t rank_v = ::portable_stl::rank<t_type>{}();
} // namespace portable_stl

#endif // PSTL_RANK_V_H
