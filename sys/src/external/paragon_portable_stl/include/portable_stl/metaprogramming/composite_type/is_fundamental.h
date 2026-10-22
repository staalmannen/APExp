// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_fundamental.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_FUNDAMENTAL_H
#define PSTL_IS_FUNDAMENTAL_H

#include "../logical_operator/disjunction.h"
#include "../primary_type/is_null_pointer.h"
#include "../primary_type/is_void.h"
#include "is_arithmetic.h"

namespace portable_stl {
/**
 * @brief t_type is an fundamental type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_fundamental = ::portable_stl::disjunction<::portable_stl::is_arithmetic<t_type>,
                                                   ::portable_stl::is_void<t_type>,
                                                   ::portable_stl::is_null_pointer<t_type>>;

} // namespace portable_stl
#endif // PSTL_IS_FUNDAMENTAL_H
