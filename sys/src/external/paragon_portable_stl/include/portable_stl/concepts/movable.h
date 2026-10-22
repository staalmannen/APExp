// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="movable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVABLE_H
#define PSTL_MOVABLE_H

#include "../metaprogramming/composite_type/is_object.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "assignable_from.h"
#include "move_constructible.h"
#include "swappable.h"

namespace portable_stl {
/**
 * @brief The 'concept' movable<t_type> specifies that t_type is an object type that can be moved (that is, it can be
 * move constructed, move assigned, and lvalues of type t_type can be swapped).
 *
 * @tparam t_type Tested type.
 */
template<class t_type>
using movable = ::portable_stl::conjunction<::portable_stl::is_object<t_type>,
                                            ::portable_stl::move_constructible<t_type>,
                                            ::portable_stl::assignable_from<t_type &, t_type>,
                                            ::portable_stl::swappable<t_type>>;
} // namespace portable_stl

#endif /* PSTL_MOVABLE_H */
