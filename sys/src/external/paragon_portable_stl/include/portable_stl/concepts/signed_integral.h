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

namespace portable_stl {
/**
 * @brief The 'concept' signed_integral<t_Type> is satisfied if and only if t_Type is an integral type and
 * is_signed<t_Type> is true_type.
 *
 * @tparam t_Type Tested type.
 */
template<class t_type>
using signed_integral
  = ::portable_stl::conjunction<::portable_stl::integral<t_type>, ::portable_stl::is_signed<t_type>>;
} // namespace portable_stl

#endif /* PSTL_SIGNED_INTEGRAL_H */
