// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_lvalue_reference_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_LVALUE_REFERENCE_V_H
#define PSTL_IS_LVALUE_REFERENCE_V_H

#include "is_lvalue_reference.h"

namespace portable_stl {
/**
 * @brief t_type is an lvalue reference type.
 * @tparam t_type the type for check.
 */
template<class t_type> constexpr inline bool is_lvalue_reference_v = ::portable_stl::is_lvalue_reference<t_type>{}();
} // namespace portable_stl

#endif /* PSTL_IS_LVALUE_REFERENCE_V_H */
