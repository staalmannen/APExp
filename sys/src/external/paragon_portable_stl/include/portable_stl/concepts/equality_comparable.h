// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="equality_comparable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EQUALITY_COMPARABLE_H
#define PSTL_EQUALITY_COMPARABLE_H

#include "weakly_equality_comparable_with.h"

namespace portable_stl {
/**
 * @brief The 'concept' equality_comparable specifies that the comparison operators == and != on T reflects equality:
 * == yields true if and only if the operands are equal.
 *
 * @tparam t_type Tested type.
 */
template<class t_type> using equality_comparable = ::portable_stl::weakly_equality_comparable_with<t_type, t_type>;
} // namespace portable_stl

#endif /* PSTL_EQUALITY_COMPARABLE_H */
