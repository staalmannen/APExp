// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_virtual_destructor_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_VIRTUAL_DESTRUCTOR_V_H
#define PSTL_HAS_VIRTUAL_DESTRUCTOR_V_H

#include "has_virtual_destructor.h"

namespace portable_stl {
/**
 * @brief Check if t_type has a virtual destructor.
 *
 * @tparam t_type type for check.
 */
template<class t_type>
constexpr inline bool has_virtual_destructor_v = ::portable_stl::has_virtual_destructor<t_type>{}();
} // namespace portable_stl

#endif // PSTL_HAS_VIRTUAL_DESTRUCTOR_V_H
