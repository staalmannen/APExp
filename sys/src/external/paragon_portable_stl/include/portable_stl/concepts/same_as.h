// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="same_as.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SAME_AS_H
#define PSTL_SAME_AS_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/type_relations/is_same.h"

namespace portable_stl {

/**
 * @brief The 'concept' same_as<t_type1, t_type2> is satisfied if and only if t_type1 and t_type2 denote the same type.
 * same_as<t_type1, t_type2> subsumes same_as<t_type2, t_type1> and vice versa.
 *
 * @tparam t_type1 Type to test.
 * @tparam t_type2 Type to test.
 */
template<class t_type1, class t_type2>
using same_as
  = ::portable_stl::conjunction<::portable_stl::is_same<t_type1, t_type2>, ::portable_stl::is_same<t_type2, t_type1>>;
} // namespace portable_stl

#endif /* PSTL_SAME_AS_H */
