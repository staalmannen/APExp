// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="destroy_at.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGES_DESTROY_AT_H
#define PSTL_RANGES_DESTROY_AT_H

#include "../memory/destroy_at.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief Destroy the object from location.
   * @tparam t_type the type of object.
   * @param location a pointer to the object to be destroyed.
   */
  template<class t_type>
  inline static void destroy_at(t_type *location) noexcept(::portable_stl::is_nothrow_destructible<t_type>{}()) {
    ::portable_stl::destroy_at(location);
  }
} // namespace ranges
} // namespace portable_stl

#endif // PSTL_RANGES_DESTROY_AT_H
