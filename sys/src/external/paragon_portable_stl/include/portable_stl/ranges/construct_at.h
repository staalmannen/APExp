// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="construct_at.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGES_CONSTRUCT_AT_H
#define PSTL_RANGES_CONSTRUCT_AT_H

#include "../memory/construct_at.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief Construct the t_type object at the location memory.
   *
   * @tparam t_type the type of object.
   * @tparam t_args the types of arguments.
   * @param location the pointer to memory for construct object.
   * @param args arguments for contruction.
   * @return pointer to the constructed object.
   */
  template<class t_type, class... t_args>
  constexpr inline static t_type *construct_at(t_type *location, t_args &&...args) noexcept(
    ::portable_stl::is_nothrow_constructible<t_type>{}()) {
    return ::portable_stl::construct_at<t_type, t_args...>(location, ::portable_stl::forward<t_args>(args)...);
  }
} // namespace ranges
} // namespace portable_stl

#endif // PSTL_RANGES_CONSTRUCT_AT_H
