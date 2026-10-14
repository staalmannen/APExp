// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_CONSTRUCTIBLE_H
#define PSTL_MOVE_CONSTRUCTIBLE_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "constructible_from.h"
#include "convertible_to.h"

namespace portable_stl {
/**
 * @brief The 'concept' move_constructible is satisfied if t_type is a reference type, or if it is an object type where
 * an object of that type can be constructed from an rvalue of that type in both direct- and copy-initialization
 * contexts, with the usual semantics.
 *
 * @tparam t_type Tested type.
 */
template<class t_type>
using move_constructible = ::portable_stl::conjunction<::portable_stl::constructible_from<t_type, t_type>,
                                                       ::portable_stl::convertible_to<t_type, t_type>>;
} // namespace portable_stl

#endif /* PSTL_MOVE_CONSTRUCTIBLE_H */
