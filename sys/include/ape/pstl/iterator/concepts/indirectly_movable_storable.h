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

namespace portable_stl {

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
  = ::portable_stl::conjunction<::portable_stl::indirectly_movable<in_type, out_type>,
                                ::portable_stl::indirectly_writable<out_type, ::portable_stl::iter_value_t<in_type>>,
                                ::portable_stl::movable<::portable_stl::iter_value_t<in_type>>,
                                ::portable_stl::constructible_from<::portable_stl::iter_value_t<in_type>,
                                                                   ::portable_stl::iter_rvalue_reference_t<in_type>>,
                                ::portable_stl::assignable_from<::portable_stl::iter_value_t<in_type> &,
                                                                ::portable_stl::iter_rvalue_reference_t<in_type>>>;
} // namespace portable_stl

#endif /* PSTL_INDIRECTLY_MOVABLE_STORABLE_H */
