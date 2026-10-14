// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_initializer_list.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_INITIALIZER_LIST_H
#define PSTL_MAKE_INITIALIZER_LIST_H

#include "initializer_list.h"

namespace portable_stl {
/**
 * @brief Create portable_stl initializer_list from STL initializer_list.
 *
 * @tparam t_type type of initializer objects.
 * @param source source initializer list.
 * @return ::portable_stl::initializer_list.
 */
template<class t_type>
constexpr inline static auto make_initializer_list(std::initializer_list<t_type> const &source) noexcept
  -> ::portable_stl::initializer_list<t_type> {
  return ::portable_stl::initializer_list<t_type>(source);
}

} // namespace portable_stl

#endif // PSTL_MAKE_INITIALIZER_LIST_H
