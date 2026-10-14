// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unary_function.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNARY_FUNCTION_H
#define PSTL_UNARY_FUNCTION_H

namespace portable_stl {
template<class t_arg1, class t_result> class unary_function_depr {
public:
  using argument_type = t_arg1;
  using result_type   = t_result;
};
} // namespace portable_stl

#endif // PSTL_UNARY_FUNCTION_H
