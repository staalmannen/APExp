// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_volatile_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_VOLATILE_V_H
#define PSTL_IS_VOLATILE_V_H

#include "is_volatile.h"
namespace portable_stl {
/**
 * @brief t_type is volatile-qualified.
 * @tparam t_type the type for check.
 */
template<class t_type> constexpr inline bool is_volatile_v = ::portable_stl::is_volatile<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_VOLATILE_V_H
