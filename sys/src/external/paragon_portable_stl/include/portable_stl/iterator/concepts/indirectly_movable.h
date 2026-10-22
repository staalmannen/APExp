// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_movable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_MOVABLE_H
#define PSTL_INDIRECTLY_MOVABLE_H

#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iter_rvalue_reference_t.h"
#include "indirectly_readable.h"
#include "indirectly_writable.h"

namespace portable_stl {
/**
 * @brief The indirectly_movable 'concept' specifies the relationship between an indirectly_readable type and a type
 * that is indirectly_writable. The indirectly_writable type must be able to directly move the object that the
 * indirectly_readable type references.
 *
 * @tparam in_type Given type.
 * @tparam out_type Given type.
 */
template<class in_type, class out_type>
using indirectly_movable = ::portable_stl::conjunction<
  ::portable_stl::indirectly_readable<in_type>,
  ::portable_stl::indirectly_writable<out_type, ::portable_stl::iter_rvalue_reference_t<in_type>>>;
} // namespace portable_stl

#endif /* PSTL_INDIRECTLY_MOVABLE_H */
