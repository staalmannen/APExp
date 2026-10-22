// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="throw_on_true.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_THROW_ON_TRUE_H
#define PSTL_THROW_ON_TRUE_H

#include "../../utility/general/forward.h"

namespace portable_stl {

/**
 * @brief Throw exception if condition true
 *
 * @tparam t_exception the type of exception.
 * @tparam t_args the types of arguments for create exception.
 * @param condition the conditions for check before create exception.
 * @param args the arguments for create exception.
 */
template<class t_exception, class... t_args> inline static void throw_on_true(bool const condition, t_args &&...args) {
  if (condition) {
    throw t_exception(::portable_stl::forward<t_args>(args)...);
  }
}
} // namespace portable_stl

#endif // PSTL_THROW_ON_TRUE_H
