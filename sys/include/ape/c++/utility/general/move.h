// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_H
#define PSTL_MOVE_H

#include "../../metaprogramming/reference_modifications/remove_reference.h"

namespace std {
/**
 * @brief Use rvalue reference for mark value to moving.
 * @tparam t_type type of value.
 * @param value value for moving.
 * @return rvalue reference to value.
 */
template<class t_type> constexpr inline ::std::remove_reference_t<t_type> &&move(t_type &&value) noexcept {
  return static_cast<::std::remove_reference_t<t_type> &&>(value);
}
} // namespace std

#endif // PSTL_MOVE_H
