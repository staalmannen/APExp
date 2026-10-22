// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="exception_guard.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXCEPTION_GUARD_H
#define PSTL_EXCEPTION_GUARD_H

namespace portable_stl {
/**
 * @brief Class for help rollback changes if exist exception.
 * Implementation with disabled exceptions.
 * @tparam t_fn_rollback type of rolback function.
 */
template<class t_fn_rollback> class exception_guard final {
public:
  /**
   * @brief the type of rolback function.
   */
  using rollback_function_type = t_fn_rollback;

public:
  /**
   * @brief Destructor for call rollback function if operation not commited.
   */
  ~exception_guard() noexcept {
    // Empty function.
  }

  /**
   * @brief Constructor for guard.
   * @param fn_rollback the rollback function.
   */
  constexpr explicit exception_guard(rollback_function_type fn_rollback) noexcept {
    static_cast<void>(fn_rollback);
  }

  /**
   * @brief Move constructor for exception guard.
   * @param source the source for move guard.
   */
  exception_guard(exception_guard &&source) noexcept {
    static_cast<void>(source);
  }
  /**
   * @brief Deleted copy constructor.
   * @param source the source for operation.
   */
  exception_guard(exception_guard const &source)            = delete;
  /**
   * @brief Deleted copy assign.
   * @param source the source for operation.
   */
  exception_guard &operator=(exception_guard const &source) = delete;
  /**
   * @brief Deleted move assign.
   * @param source the source for operation.
   */
  exception_guard &operator=(exception_guard &&source)      = delete;

  /**
   * @brief Commit operation for disable rollback.
   */
  void commit() const noexcept {
    // Empty function.
  }
};
} // namespace portable_stl

#endif // PSTL_EXCEPTION_GUARD_H
