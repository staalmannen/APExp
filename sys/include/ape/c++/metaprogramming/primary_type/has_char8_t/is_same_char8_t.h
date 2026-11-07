// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_same_char8_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SAME_CHAR8_T_H
#define PSTL_IS_SAME_CHAR8_T_H

#include "../../helper/integral_constant.h"

namespace std {
namespace metaprogramming_helper {
  /**
   * @brief Helper checker for char8_t type.
   *
   * @tparam t_type The parameter for check.
   */
  template<class t_type> using is_same_char8_t = ::std::is_same<t_type, char8_t>;
} // namespace metaprogramming_helper
} // namespace std

#endif // PSTL_IS_SAME_CHAR8_T_H
