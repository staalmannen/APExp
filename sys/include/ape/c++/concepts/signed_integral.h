// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="signed_integral.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SIGNED_INTEGRAL_H
#define PSTL_SIGNED_INTEGRAL_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/type_properties/is_signed.h"
#include "integral.h"

namespace std {
/**
 * @brief The 'concept' signed_integral<t_Type> is satisfied if and only if t_Type is an integral type and
 * is_signed<t_Type> is true_type.
 *
 * @tparam t_Type Tested type.
 */
template<class t_type>
using signed_integral
  = ::std::conjunction<::std::integral<t_type>, ::std::is_signed<t_type>>;
} // namespace std

#endif /* PSTL_SIGNED_INTEGRAL_H */
