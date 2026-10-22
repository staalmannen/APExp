// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="totally_ordered_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TOTALLY_ORDERED_WITH_H
#define PSTL_TOTALLY_ORDERED_WITH_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/common_reference.h"
#include "equality_comparable_with.h"
#include "partially_ordered_with.h"
#include "totally_ordered.h"

namespace portable_stl {

/**
 * @brief The 'concept' specifies that the comparison operators ==,!=,<,>,<=,>= on (possibly
 * mixed) t_type1 and t_type2 operands yield results consistent with a strict total order. Comparing mixed operands
 * yields results equivalent to comparing the operands converted to their common type.
 *
 * @tparam t_type1
 * @tparam t_type2
 */
template<class t_type1, class t_type2>
using totally_ordered_with
  = ::portable_stl::conjunction<::portable_stl::totally_ordered<t_type1>,
                                ::portable_stl::totally_ordered<t_type2>,
                                ::portable_stl::equality_comparable_with<t_type1, t_type2>,
                                ::portable_stl::totally_ordered<::portable_stl::common_reference_t<
                                  ::portable_stl::remove_reference_t<t_type1> const &,
                                  ::portable_stl::remove_reference_t<t_type2> const &>>,
                                ::portable_stl::partially_ordered_with<t_type1, t_type2>>;
} // namespace portable_stl

#endif /* PSTL_TOTALLY_ORDERED_WITH_H */
