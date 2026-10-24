// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="disjunction_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DISJUNCTION_V_H
#define PSTL_DISJUNCTION_V_H

#include "disjunction.h"

namespace portable_stl {
/**
 * @brief The class template disjunction forms the logical disjunction of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class... t_bool_constant>
constexpr inline bool disjunction_v = ::portable_stl::disjunction<t_bool_constant...>{}();

} // namespace portable_stl

#endif // PSTL_DISJUNCTION_V_H
