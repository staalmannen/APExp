// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_assignable_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_ASSIGNABLE_V_H
#define PSTL_IS_NOTHROW_ASSIGNABLE_V_H

#include "is_nothrow_assignable.h"
namespace portable_stl {
/**
 * @brief Check t_type is an assignable with t_other without exceptions.
 * @tparam t_type type for check.
 * @tparam t_other type for assign.
 */
template<class t_type, class t_other>
constexpr inline bool is_nothrow_assignable_v = ::portable_stl::is_nothrow_assignable<t_type, t_other>{}();
} // namespace portable_stl

#endif // PSTL_IS_NOTHROW_ASSIGNABLE_V_H
