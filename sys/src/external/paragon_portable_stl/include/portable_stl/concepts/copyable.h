// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copyable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPYABLE_H
#define PSTL_COPYABLE_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "assignable_from.h"
#include "copy_constructible.h"
#include "movable.h"

namespace portable_stl {
/**
 * @brief The 'concept' copyable<t_type> specifies that t_type is a movable object type that can also be copied (that
 * is, it supports copy construction and copy assignment).
 * @tparam t_type Given type.
 */
template<class t_type>
using copyable = ::portable_stl::conjunction<::portable_stl::copy_constructible<t_type>,
                                             ::portable_stl::movable<t_type>,
                                             ::portable_stl::assignable_from<t_type &, t_type &>,
                                             ::portable_stl::assignable_from<t_type &, t_type const &>,
                                             ::portable_stl::assignable_from<t_type &, t_type const>>;
} // namespace portable_stl

#endif /* PSTL_COPYABLE_H */
