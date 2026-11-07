// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_swappable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_SWAPPABLE_H
#define PSTL_IS_NOTHROW_SWAPPABLE_H

#include "../reference_modifications/add_lvalue_reference.h"
#include "is_nothrow_swappable_with.h"

namespace std {

/**
 * @brief Check object with type t_type can swap with other object with this type without exceptions.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_nothrow_swappable = ::std::is_nothrow_swappable_with<::std::add_lvalue_reference_t<t_type>,
                                                                       ::std::add_lvalue_reference_t<t_type>>;
} // namespace std

#endif /* PSTL_IS_NOTHROW_SWAPPABLE_H */
