// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_object.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_OBJECT_H
#define PSTL_IS_OBJECT_H

#include "../logical_operator/disjunction.h"
#include "../primary_type/is_array.h"
#include "../primary_type/is_class.h"
#include "../primary_type/is_union.h"
#include "is_scalar.h"

namespace portable_stl {
/**
 * @brief t_type is an object type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_object = ::portable_stl::disjunction<::portable_stl::is_scalar<t_type>,
                                              ::portable_stl::is_array<t_type>,
                                              ::portable_stl::is_union<t_type>,
                                              ::portable_stl::is_class<t_type>>;

} // namespace portable_stl

#endif // PSTL_IS_OBJECT_H
