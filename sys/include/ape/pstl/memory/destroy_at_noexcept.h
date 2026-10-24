// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="destroy_at_noexcept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DESTROY_AT_NOEXCEPT_H
#define PSTL_DESTROY_AT_NOEXCEPT_H

#include "../metaprogramming/type_properties/is_nothrow_destructible.h"

namespace portable_stl {
/**
 * @brief Destroy the object from location.
 * Suppress all exceptions.
 * @tparam t_type the type of object.
 * @param location the location of object in memory.
 */
template<class t_type> inline static void destroy_at_noexcept(t_type *location) noexcept {
  try {
    location->~t_type();
  } catch (...) {
    static_cast<void>();
  }
}
} // namespace portable_stl

#endif // PSTL_DESTROY_AT_NOEXCEPT_H
