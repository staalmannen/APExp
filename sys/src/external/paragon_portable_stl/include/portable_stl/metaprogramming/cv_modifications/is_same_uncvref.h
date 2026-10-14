// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_same_uncvref.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SAME_UNCVREF_H
#define PSTL_IS_SAME_UNCVREF_H

#include "../other_transformations/remove_cvref.h"
#include "../type_relations/is_same.h"

namespace portable_stl {

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_other_type
 */
template<class t_type, class t_other_type>
using is_same_uncvref
  = ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_type>, ::portable_stl::remove_cvref_t<t_other_type>>;
} // namespace portable_stl

#endif // PSTL_IS_SAME_UNCVREF_H
