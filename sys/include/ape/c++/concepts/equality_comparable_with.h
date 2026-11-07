// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="equality_comparable_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EQUALITY_COMPARABLE_WITH_H
#define PSTL_EQUALITY_COMPARABLE_WITH_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/common_reference.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "comparison_common_type_with.h"
#include "equality_comparable.h"
#include "weakly_equality_comparable_with.h"

namespace std {
/**
 * @brief The 'concept' specifies that the comparison operators == and != on (possibly mixed) t_type1 and t_type2
 * operands yield results consistent with equality. Comparing mixed operands yields results equivalent to comparing the
 * operands converted to their common type.
 *
 * @tparam t_type1 Tested type.
 * @tparam t_type2 Tested type.
 */
template<class t_type1, class t_type2>
using equality_comparable_with
  = ::std::conjunction<::std::equality_comparable<t_type1>,
                                ::std::equality_comparable<t_type2>,
                                ::std::comparison_common_type_with<t_type1, t_type2>,
                                ::std::equality_comparable<::std::common_reference_t<
                                  ::std::remove_reference_t<t_type1> const &,
                                  ::std::remove_reference_t<t_type2> const &>>,
                                ::std::weakly_equality_comparable_with<t_type1, t_type2>>;

} // namespace std

#endif /* PSTL_EQUALITY_COMPARABLE_WITH_H */
