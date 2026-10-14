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

namespace portable_stl {
/**
 * @brief t_type is an arithmetic type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_arithmetic
  = ::portable_stl::disjunction<::portable_stl::is_integral<t_type>, ::portable_stl::is_floating_point<t_type>>;

} // namespace portable_stl

#endif // PSTL_IS_ARITHMETIC_H
