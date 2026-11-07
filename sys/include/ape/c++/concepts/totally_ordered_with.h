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

namespace std {

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
  = ::std::conjunction<::std::totally_ordered<t_type1>,
                                ::std::totally_ordered<t_type2>,
                                ::std::equality_comparable_with<t_type1, t_type2>,
                                ::std::totally_ordered<::std::common_reference_t<
                                  ::std::remove_reference_t<t_type1> const &,
                                  ::std::remove_reference_t<t_type2> const &>>,
                                ::std::partially_ordered_with<t_type1, t_type2>>;
} // namespace std

#endif /* PSTL_TOTALLY_ORDERED_WITH_H */
