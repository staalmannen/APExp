// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="as_const.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_AS_CONST_H
#define PSTL_AS_CONST_H

#include "add_const.h"

namespace portable_stl {

/**
 * @brief Forms lvalue reference to const type of t_type.
 *
 * @tparam t_type Type of given value.
 * @param value Given value.
 * @return lvalue reference to const type of t_type.
 */
template<class t_type> constexpr ::portable_stl::add_const_t<t_type> &as_const(t_type &value) noexcept {
  return value;
}
} // namespace portable_stl

#endif /* PSTL_AS_CONST_H */
