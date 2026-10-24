// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_scalar.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SCALAR_H
#define PSTL_IS_SCALAR_H

#include "../logical_operator/disjunction.h"
#include "../primary_type/is_enum.h"
#include "../primary_type/is_null_pointer.h"
#include "../primary_type/is_pointer.h"
#include "is_arithmetic.h"
#include "is_member_pointer.h"

namespace portable_stl {
/**
 * @brief t_type is an scalar type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_scalar = ::portable_stl::disjunction<::portable_stl::is_arithmetic<t_type>,
                                              ::portable_stl::is_enum<t_type>,
                                              ::portable_stl::is_pointer<t_type>,
                                              ::portable_stl::is_member_pointer<t_type>,
                                              ::portable_stl::is_null_pointer<t_type>>;

} // namespace portable_stl

#endif // PSTL_IS_SCALAR_H
