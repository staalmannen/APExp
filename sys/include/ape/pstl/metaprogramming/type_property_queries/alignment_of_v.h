// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="alignment_of_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_ALIGNMENT_OF_V_H
#define PSTL_ALIGNMENT_OF_V_H
#include "alignment_of.h"

namespace portable_stl {
/**
 * @brief Provides the member constant value equal to the alignment requirement of the type t_type, as if obtained by an
 * alignof expression.
 * If t_type is an array type, returns the alignment requirements of the element type. If t_type is a reference type,
 * returns the alignment requirements of the type referred to.
 *
 * @tparam t_type Type for property query.
 */
template<class t_type>
constexpr inline ::portable_stl::size_t alignment_of_v = ::portable_stl::alignment_of<t_type>{}();
} // namespace portable_stl
#endif // PSTL_ALIGNMENT_OF_V_H
