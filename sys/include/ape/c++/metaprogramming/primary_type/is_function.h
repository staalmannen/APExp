// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_function.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_FUNCTION_H
#define PSTL_IS_FUNCTION_H

#include "../composite_type/is_reference.h"
#include "../logical_operator/disjunction.h"
#include "../logical_operator/negation.h"
#include "../type_properties/is_const.h"

namespace std {
/**
 * @brief t_type is a function type.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_function = ::std::negation<
  ::std::disjunction<::std::is_reference<t_type>, ::std::is_const<t_type const>>>;
} // namespace std

#endif // PSTL_IS_FUNCTION_H
