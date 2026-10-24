// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_unique_object_representations_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_V_H
#define PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_V_H
#include "has_unique_object_representations.h"

namespace portable_stl {
/**
 * @brief Check if t_type is TriviallyCopyable and if any two objects of type t_type
 * with the same value have the same object representation.
 *
 * @tparam t_type type for check.
 */
template<class t_type>
constexpr inline bool has_unique_object_representations_v
  = ::portable_stl::has_unique_object_representations<t_type>{}();
} // namespace portable_stl

#endif // PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_V_H
