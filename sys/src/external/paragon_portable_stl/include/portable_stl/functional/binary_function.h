// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="binary_function.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BINARY_FUNCTION_H
#define PSTL_BINARY_FUNCTION_H

namespace portable_stl {

/**
 * @brief Removed in C++17, but still used in map and function.
 *
 * @tparam t_arg1
 * @tparam t_arg2
 * @tparam t_result
 */
template<class t_arg1, class t_arg2, class t_result> class binary_function_depr {
  public:
  using first_argument_type  = t_arg1;
  using second_argument_type = t_arg2;
  using result_type          = t_result;
};
} // namespace portable_stl

#endif // PSTL_BINARY_FUNCTION_H
