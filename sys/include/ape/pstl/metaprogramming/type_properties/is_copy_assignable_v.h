// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_copy_assignable_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_COPY_ASSIGNABLE_V_H
#define PSTL_IS_COPY_ASSIGNABLE_V_H

#include "is_copy_assignable.h"
namespace portable_stl {
/**
 * @brief Check t_type is a copy assignable.
 * @tparam t_type type for check.
 */
template<class t_type> constexpr inline bool is_copy_assignable_v = ::portable_stl::is_copy_assignable<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_COPY_ASSIGNABLE_V_H
