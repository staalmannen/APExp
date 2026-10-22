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

namespace portable_stl {
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
  = ::portable_stl::conjunction<::portable_stl::equality_comparable<t_type1>,
                                ::portable_stl::equality_comparable<t_type2>,
                                ::portable_stl::comparison_common_type_with<t_type1, t_type2>,
                                ::portable_stl::equality_comparable<::portable_stl::common_reference_t<
                                  ::portable_stl::remove_reference_t<t_type1> const &,
                                  ::portable_stl::remove_reference_t<t_type2> const &>>,
                                ::portable_stl::weakly_equality_comparable_with<t_type1, t_type2>>;

} // namespace portable_stl

#endif /* PSTL_EQUALITY_COMPARABLE_WITH_H */
