// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_trivially_move_assignable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRIVIALLY_MOVE_ASSIGNABLE_H
#define PSTL_IS_TRIVIALLY_MOVE_ASSIGNABLE_H

#include "../reference_modifications/add_lvalue_reference.h"
#include "../reference_modifications/add_rvalue_reference.h"
#include "is_trivially_assignable.h"

namespace portable_stl {

/**
 * @brief Check t_type is a move Trivially-assignable . ( Can assign with trivial function. )
 * @tparam t_type type for check.
 */
template<class t_type>
using is_trivially_move_assignable
  = ::portable_stl::is_trivially_assignable<::portable_stl::add_lvalue_reference_t<t_type>,
                                            ::portable_stl::add_rvalue_reference_t<t_type>>;
} // namespace portable_stl

#endif // PSTL_IS_TRIVIALLY_MOVE_ASSIGNABLE_H
