// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_arithmetic.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ARITHMETIC_H
#define PSTL_IS_ARITHMETIC_H

#include "../logical_operator/disjunction.h"
#include "../primary_type/is_floating_point.h"
#include "../primary_type/is_integral.h"

namespace std {
/**
 * @brief t_type is an arithmetic type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_arithmetic
  = ::std::disjunction<::std::is_integral<t_type>, ::std::is_floating_point<t_type>>;

} // namespace std

#endif // PSTL_IS_ARITHMETIC_H
