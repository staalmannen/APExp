// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="totally_ordered.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TOTALLY_ORDERED_H
#define PSTL_TOTALLY_ORDERED_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "equality_comparable.h"
#include "partially_ordered_with.h"

namespace portable_stl {

/**
 * @brief The 'concept' totally_ordered specifies that the comparison operators ==,!=,<,>,<=,>= on a type yield results
 * consistent with a strict total order on the type.
 *
 * @tparam t_type Given type.
 */
template<class t_type>
using totally_ordered = ::portable_stl::conjunction<::portable_stl::equality_comparable<t_type>,
                                                    ::portable_stl::partially_ordered_with<t_type, t_type>>;
} // namespace portable_stl

#endif /* PSTL_TOTALLY_ORDERED_H */
