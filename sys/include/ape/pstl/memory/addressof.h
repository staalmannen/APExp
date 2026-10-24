// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="addressof.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADDRESSOF_H
#define PSTL_ADDRESSOF_H
namespace portable_stl {

/**
 * @brief The actual address of the object or function referenced by value, even in the presence of an overloaded
 * operator&.
 *
 * @tparam t_type the type of value.
 * @param value value for get address.
 * @return actual address of the object.
 */
template<class t_type> constexpr t_type *addressof(t_type &value) noexcept {
  static_cast<void>(value);
  return __builtin_addressof(value);
}

} // namespace portable_stl

#endif // PSTL_ADDRESSOF_H
