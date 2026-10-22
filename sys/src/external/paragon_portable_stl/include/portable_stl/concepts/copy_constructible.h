// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copy_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPY_CONSTRUCTIBLE_H
#define PSTL_COPY_CONSTRUCTIBLE_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "constructible_from.h"
#include "convertible_to.h"
#include "move_constructible.h"

namespace portable_stl {
/**
 * @brief The 'concept' copy_constructible is satisfied if t_type is an lvalue reference type, or if it is a
 * move_constructible object type where an object of that type can constructed from a (possibly const) lvalue or const
 * rvalue of that type in both direct- and copy-initialization contexts with the usual semantics (a copy is constructed
 * with the source unchanged).
 *
 * @tparam t_type Given type.
 */
template<class t_type>
using copy_constructible = ::portable_stl::conjunction<::portable_stl::move_constructible<t_type>,
                                                       ::portable_stl::constructible_from<t_type, t_type &>,
                                                       ::portable_stl::convertible_to<t_type &, t_type>,
                                                       ::portable_stl::constructible_from<t_type, t_type const &>,
                                                       ::portable_stl::convertible_to<t_type const &, t_type>,
                                                       ::portable_stl::constructible_from<t_type, t_type const>,
                                                       ::portable_stl::convertible_to<t_type const, t_type>>;
} // namespace portable_stl

#endif /* PSTL_COPY_CONSTRUCTIBLE_H */
