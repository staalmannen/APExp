// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_movable_storable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_MOVABLE_STORABLE_H
#define PSTL_INDIRECTLY_MOVABLE_STORABLE_H

#include "../../concepts/assignable_from.h"
#include "../../concepts/constructible_from.h"
#include "../../concepts/movable.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iter_rvalue_reference_t.h"
#include "../iter_value_t.h"
#include "indirectly_movable.h"
#include "indirectly_writable.h"

namespace std {

/**
 * @brief The indirectly_movable_storable 'concept' specifies the relationship between an indirectly_readable type and
 * an indirectly_writable type. In addition to indirectly_movable, this 'concept' specifies that the move from the
 * indirectly_readable type can be performed via an intermediate object.
 *
 * @tparam in_type Given type.
 * @tparam out_type Given type.
 */
template<class in_type, class out_type>
using indirectly_movable_storable
  = ::std::conjunction<::std::indirectly_movable<in_type, out_type>,
                                ::std::indirectly_writable<out_type, ::std::iter_value_t<in_type>>,
                                ::std::movable<::std::iter_value_t<in_type>>,
                                ::std::constructible_from<::std::iter_value_t<in_type>,
                                                                   ::std::iter_rvalue_reference_t<in_type>>,
                                ::std::assignable_from<::std::iter_value_t<in_type> &,
                                                                ::std::iter_rvalue_reference_t<in_type>>>;
} // namespace std

#endif /* PSTL_INDIRECTLY_MOVABLE_STORABLE_H */
