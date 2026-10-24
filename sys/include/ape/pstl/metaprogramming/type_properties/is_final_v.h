// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_final_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_FINAL_V_H
#define PSTL_IS_FINAL_V_H

#include "is_final.h"
namespace portable_stl {
/**
 * @brief t_type is a final class type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> constexpr inline bool is_final_v = ::portable_stl::is_final<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_FINAL_V_H
