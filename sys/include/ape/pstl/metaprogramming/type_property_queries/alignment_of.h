// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="alignment_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALIGNMENT_OF_H
#define PSTL_ALIGNMENT_OF_H
#include "../../common/size_t.h"
#include "../helper/integral_constant.h"
#include "../reference_modifications/remove_reference.h"

namespace portable_stl {
/**
 * @brief Provides the member constant value equal to the alignment requirement of the type t_type, as if obtained by an
 * alignof expression.
 * If t_type is an array type, returns the alignment requirements of the element type. If t_type is a reference type,
 * returns the alignment requirements of the type referred to.
 *
 * @tparam t_type type for property query.
 */
template<class t_type>
using alignment_of
  = ::portable_stl::integral_constant<::portable_stl::size_t, alignof(::portable_stl::remove_reference_t<t_type>)>;
} // namespace portable_stl
#endif // PSTL_ALIGNMENT_OF_H
