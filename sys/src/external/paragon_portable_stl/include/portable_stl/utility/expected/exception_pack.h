// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="exception_pack.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXCEPTION_PACK_H
#define PSTL_EXCEPTION_PACK_H

#include "expected.h"
#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "exception/excetion_catcher.h"
#else
#  include "noexception/excetion_catcher.h"
#endif

namespace portable_stl {
/**
 * @brief Helper class for convert exception into portable_stl::expected class with error.
 *
 * @tparam t_error type of the error.
 * @tparam t_error_value the value of error.
 */
template<class t_error, t_error t_error_value> class exception_pack final {
public:
  /**
   * @brief Function for convert exception into portable_stl::expected class.
   *
   * @tparam t_guard_function the type of function for exception catch.
   * @tparam ...t_args the function arguments.
   * @param guard_function the function for exception catch.
   * @param args the function arguments.
   * @return portable_stl::expected with error or function result value.
   */
  template<class t_guard_function, class... t_args>
  auto operator()(t_guard_function &&guard_function, t_args &&...args) const noexcept {
    return ::portable_stl::
      excetion_catcher<t_error, t_error_value, decltype(guard_function(::portable_stl::forward<t_args>(args)...))>{}(
        ::portable_stl::forward<t_guard_function>(guard_function), ::portable_stl::forward<t_args>(args)...);
  }
};
} // namespace portable_stl

#endif // PSTL_EXCEPTION_PACK_H
