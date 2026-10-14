// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_exception_guard.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_EXCEPTION_GUARD_H
#define PSTL_MAKE_EXCEPTION_GUARD_H

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "exception/exception_guard.h"
#else
#  include "no_exception/exception_guard.h"
#endif
namespace portable_stl {
/**
 * @brief Helper function for create object exception_guard
 *
 * @tparam t_fn_rollback the type of rollback function.
 * @param fn_rollback rollback function.
 * @return exception_guard object.
 */
template<class t_fn_rollback>
inline static exception_guard<t_fn_rollback> make_exception_guard(t_fn_rollback &&fn_rollback) noexcept(
  noexcept(exception_guard<t_fn_rollback>(portable_stl::forward<t_fn_rollback>(fn_rollback)))) {
  return exception_guard<t_fn_rollback>{portable_stl::forward<t_fn_rollback>(fn_rollback)};
}
} // namespace portable_stl

#endif // PSTL_MAKE_EXCEPTION_GUARD_H
