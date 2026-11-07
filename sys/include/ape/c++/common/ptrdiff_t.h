// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ptrdiff_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PTRDIFF_T_H
#define PSTL_PTRDIFF_T_H

#include "../utility/general/declval.h"
#include "size_t.h"

namespace std {
/**
 * @brief The type is an implementation-defined signed integer type that can
 * hold the difference of two subscripts in an array object.
 */
using ptrdiff_t
  = decltype(::std::declval<::std::size_t *>() - ::std::declval<::std::size_t *>());

} // namespace std

#endif // PSTL_PTRDIFF_T_H
