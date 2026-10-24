// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_const_reference_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_CONST_REFERENCE_T_H
#define PSTL_ITER_CONST_REFERENCE_T_H

#include "../concepts/common_reference_with.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/common_reference.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "concepts/indirectly_readable.h"
#include "iter_reference_t.h"
#include "iter_value_t.h"

namespace portable_stl {
/**
 * @brief Computes the const reference type of t_type.
 *
 * @tparam t_type Given type.
 */
template<class t_type, class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::indirectly_readable<t_type>>>
using iter_const_reference_t = ::portable_stl::common_reference_t<::portable_stl::iter_value_t<t_type> const &&,
                                                                  ::portable_stl::iter_reference_t<t_type>>;

} // namespace portable_stl

#endif /* PSTL_ITER_CONST_REFERENCE_T_H */
