// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="extent_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_EXTENT_V_H
#define PSTL_EXTENT_V_H

#include "extent.h"
namespace std {
/**
 * @brief If t_type is an array type, provides value equal to the number of elements along the Nth dimension of the
 * array, if N is in [​0​, rank<T>::value). For any other type, or if t_type is an array of unknown bound along its
 * first dimension and N is ​0​, value is ​0​.
 *
 * @tparam t_type type for property query.
 */
template<class t_type, ::std::size_t N = 0U>
constexpr inline ::std::size_t extent_v = ::std::extent<t_type, N>{}();

} // namespace std

#endif // PSTL_EXTENT_V_H
