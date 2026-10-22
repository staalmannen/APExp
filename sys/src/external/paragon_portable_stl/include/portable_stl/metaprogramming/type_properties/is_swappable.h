// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_swappable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SWAPPABLE_H
#define PSTL_IS_SWAPPABLE_H

#include "../reference_modifications/add_lvalue_reference.h"
#include "is_swappable_with.h"

namespace portable_stl {
/**
 * @brief Check object with type t_type can swap with other object with this type.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_swappable = ::portable_stl::is_swappable_with<::portable_stl::add_lvalue_reference_t<t_type>,
                                                       ::portable_stl::add_lvalue_reference_t<t_type>>;
} // namespace portable_stl

#endif /* PSTL_IS_SWAPPABLE_H */
