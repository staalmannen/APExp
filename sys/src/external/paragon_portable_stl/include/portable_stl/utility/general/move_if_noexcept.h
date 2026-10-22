// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_if_noexcept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_IF_NOEXCEPT_H
#define PSTL_MOVE_IF_NOEXCEPT_H

#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../../metaprogramming/reference_modifications/remove_reference.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../../metaprogramming/type_properties/is_copy_constructible.h"
#include "move.h"

namespace portable_stl {
namespace general_helper {
  template<class t_type>
  using move_if_noexcept_result_t = ::portable_stl::conditional_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_nothrow_move_constructible<t_type>>,
                                ::portable_stl::is_copy_constructible<t_type>>,
    t_type const &,
    t_type &&>;
} // namespace general_helper

template<class t_type>
constexpr inline general_helper::move_if_noexcept_result_t<t_type> move_if_noexcept(t_type &value) noexcept {
  return portable_stl::move(value);
}

} // namespace portable_stl

#endif // PSTL_MOVE_IF_NOEXCEPT_H
