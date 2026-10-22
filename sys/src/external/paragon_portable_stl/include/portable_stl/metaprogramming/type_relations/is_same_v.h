// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_same_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SAME_V_H
#define PSTL_IS_SAME_V_H

#include "is_same.h"

namespace portable_stl {
/**
 * @brief t_type and t_other_type name the same with the same cv-qualifications.
 *
 * @tparam t_type The type for compare.
 * @tparam t_other_type The other type for compare.
 */
template<class t_type, class t_other_type>
constexpr inline bool is_same_v = ::portable_stl::is_same<t_type, t_other_type>{}();

} // namespace portable_stl

#endif // PSTL_IS_SAME_V_H
