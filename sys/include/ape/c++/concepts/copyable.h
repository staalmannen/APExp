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

namespace std {
/**
 * @brief The 'concept' copyable<t_type> specifies that t_type is a movable object type that can also be copied (that
 * is, it supports copy construction and copy assignment).
 * @tparam t_type Given type.
 */
template<class t_type>
using copyable = ::std::conjunction<::std::copy_constructible<t_type>,
                                             ::std::movable<t_type>,
                                             ::std::assignable_from<t_type &, t_type &>,
                                             ::std::assignable_from<t_type &, t_type const &>,
                                             ::std::assignable_from<t_type &, t_type const>>;
} // namespace std

#endif /* PSTL_COPYABLE_H */
