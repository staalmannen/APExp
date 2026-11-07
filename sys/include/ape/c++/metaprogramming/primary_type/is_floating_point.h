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

namespace std {
/**
 * @brief t_type is a floating-point
 *
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_floating_point
  = ::std::disjunction<::std::is_same<::std::remove_cv_t<t_type>, float>,
                                ::std::is_same<::std::remove_cv_t<t_type>, double>,
                                ::std::is_same<::std::remove_cv_t<t_type>, long double>>;

} // namespace std

#endif // PSTL_IS_FLOATING_POINT_H
