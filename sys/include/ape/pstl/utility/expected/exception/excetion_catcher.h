// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="excetion_catcher.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXCETION_CATCHER_H
#define PSTL_EXCETION_CATCHER_H

#include "../../../metaprogramming/helper/integral_constant.h"
#include "../../../metaprogramming/primary_type/is_void.h"
#include "../../../utility/general/forward.h"
#include "../expected.h"

namespace portable_stl {
/**
 * @brief Helper class for catch exceptions and return result state.
 */
template<class t_error, t_error t_error_value, class t_result_type, class = ::portable_stl::is_void<t_result_type>>
class excetion_catcher final {
public:
  /**
   * @brief Function for catch exceptions.
   * @tparam t_guard_function the type of function with exceptions.
   * @tparam t_args the types of function arguments.
   * @param guard_function the function with exceptions.
   * @param args the function arguments.
   * @return status of calling guard_function.
   * @retval expected with value if the guard_function execute without exceptions.
   * @retval expected with error if the guard_function execute with exceptions.
   */
  template<class t_current_guard_function, class... t_args>
  ::portable_stl::expected<t_result_type, t_error> operator()(t_current_guard_function &&guard_function,
                                                              t_args &&...args) const noexcept {
    try {
      return ::portable_stl::expected<t_result_type, t_error>{
        ::portable_stl::forward<t_current_guard_function>(guard_function)(::portable_stl::forward<t_args>(args)...)};
    } catch (...) {
    }
    return ::portable_stl::expected<t_result_type, t_error>{::portable_stl::unexpect_t{}, t_error_value};
  }
};

/**
 * @brief Helper class for catch exceptions and return result state.
 */
template<class t_error, t_error t_error_value, class t_result_type>
class excetion_catcher<t_error, t_error_value, t_result_type, ::portable_stl::true_type> final {
public:
  /**
   * @brief Function for catch exceptions.
   * @tparam t_guard_function the type of function with exceptions.
   * @tparam t_args the types of function arguments.
   * @param guard_function the function with exceptions.
   * @param args the function arguments.
   * @return status of calling guard_function.
   * @retval expected with value if the guard_function execute without exceptions.
   * @retval expected with error if the guard_function execute with exceptions.
   */
  template<class t_current_guard_function, class... t_args>
  ::portable_stl::expected<t_result_type, t_error> operator()(t_current_guard_function &&guard_function,
                                                              t_args &&...args) const noexcept {
    try {
      ::portable_stl::forward<t_current_guard_function>(guard_function)(::portable_stl::forward<t_args>(args)...);
      return ::portable_stl::expected<t_result_type, t_error>{};
    } catch (...) {
    }
    return ::portable_stl::expected<t_result_type, t_error>{::portable_stl::unexpect_t{}, t_error_value};
  }
};

} // namespace portable_stl

#endif // PSTL_EXCETION_CATCHER_H
