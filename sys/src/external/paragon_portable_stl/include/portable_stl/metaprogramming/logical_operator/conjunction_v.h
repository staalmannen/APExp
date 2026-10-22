// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="conjunction_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONJUNCTION_V_H
#define PSTL_CONJUNCTION_V_H

#include "conjunction.h"

namespace portable_stl {
/**
 * @brief The class template conjunction forms the logical conjunction of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class... t_bool_constant>
constexpr inline bool conjunction_v = ::portable_stl::conjunction<t_bool_constant...>{}();

} // namespace portable_stl

#endif // PSTL_CONJUNCTION_V_H
