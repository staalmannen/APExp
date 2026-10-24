// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_H
#define PSTL_FORWARD_H

#include "../../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../../metaprogramming/reference_modifications/remove_reference.h"

namespace portable_stl {
/**
 * @brief Perfect forward arguments to other function.
 *
 * @tparam t_type for argument.
 * @param value argument for forward.
 * @return result value.
 */
template<class t_type> constexpr t_type &&forward(::portable_stl::remove_reference_t<t_type> &value) noexcept {
  return static_cast<t_type &&>(value);
}

/**
 * @brief Perfect forward arguments to other function.
 *
 * @tparam t_type for argument.
 * @param value argument for forward.
 * @return result value.
 */
template<class t_type> constexpr t_type &&forward(::portable_stl::remove_reference_t<t_type> &&value) noexcept {
  return static_cast<t_type &&>(value);
}

} // namespace portable_stl

#endif /* PSTL_FORWARD_H */
