// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="derived_from.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DERIVED_FROM_H
#define PSTL_DERIVED_FROM_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/type_relations/is_base_of.h"
#include "../metaprogramming/type_relations/is_convertible.h"

namespace portable_stl {

/**
 * @brief The 'concept' derived_from<derived_type, base_type> is satisfied if and only if base_type is a class type that
 * is either derived_type or a public and unambiguous base of derived_type, ignoring cv-qualifiers. Note that this
 * behavior is different to is_base_of when Base is a private or protected base of derived_type.
 *
 * @tparam derived_type Derived type.
 * @tparam base_type Base type.
 */
template<class derived_type, class base_type>
using derived_from = ::portable_stl::conjunction<
  ::portable_stl::is_base_of<base_type, derived_type>,
  ::portable_stl::is_convertible<derived_type const volatile *, base_type const volatile *>>;

} // namespace portable_stl

#endif /* PSTL_DERIVED_FROM_H */
