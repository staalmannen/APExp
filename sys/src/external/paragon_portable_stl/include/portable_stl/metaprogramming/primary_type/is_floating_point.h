// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_floating_point.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_FLOATING_POINT_H
#define PSTL_IS_FLOATING_POINT_H

#include "../cv_modifications/remove_cv.h"
#include "../logical_operator/disjunction.h"
#include "../type_relations/is_same.h"

namespace portable_stl {
/**
 * @brief t_type is a floating-point
 *
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_floating_point
  = ::portable_stl::disjunction<::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, float>,
                                ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, double>,
                                ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, long double>>;

} // namespace portable_stl

#endif // PSTL_IS_FLOATING_POINT_H
