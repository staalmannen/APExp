// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="negation_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NEGATION_V_H
#define PSTL_NEGATION_V_H

#include "negation.h"

namespace portable_stl {
/**
 * @brief The class template negation forms the logical negation of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class t_bool_constant> constexpr inline bool negation_v = ::portable_stl::negation<t_bool_constant>{}();

} // namespace portable_stl

#endif // PSTL_NEGATION_V_H
