// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="comparison_common_type_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMPARISON_COMMON_TYPE_WITH_H
#define PSTL_COMPARISON_COMMON_TYPE_WITH_H

#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "common_reference_with.h"

namespace portable_stl {

/**
 * @brief The exposition-only 'concept' __ComparisonCommonTypeWith specifies that two types share a common type, and a
 * const lvalue or a non-const rvalue(since C++23) of either type is convertible to that common type.
 *
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2>
using comparison_common_type_with
  = ::portable_stl::common_reference_with<::portable_stl::remove_reference_t<t_type1> const &,
                                          ::portable_stl::remove_reference_t<t_type1> const &>;
} // namespace portable_stl

#endif /* PSTL_COMPARISON_COMMON_TYPE_WITH_H */
