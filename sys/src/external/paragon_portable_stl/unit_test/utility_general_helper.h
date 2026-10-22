// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="utility_general_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UTILITY_GENERAL_HELPER_H
#define PSTL_UTILITY_GENERAL_HELPER_H

namespace test_utility_general_helper {
/**
 * @brief Class with Potential exception throwing on move construction.
 */
class throw_on_move_construction final {
public:
  /**
   * @brief Ctor.
   */
  throw_on_move_construction()  = default;
  /**
   * @brief Dtor.
   */
  ~throw_on_move_construction() = default;

  /**
   * @brief Copy ctor.
   */
  throw_on_move_construction(throw_on_move_construction const &) = default;
  /**
   * @brief Move ctor.
   */
  throw_on_move_construction(throw_on_move_construction &&) noexcept(false) {
  }

  /**
   * @brief Copy assignment operator
   * @return _on_move_construction&
   */
  throw_on_move_construction &operator=(throw_on_move_construction const &) & = default;
  /**
   * @brief Move assignment operator
   * @return _on_move_construction&
   */
  throw_on_move_construction &operator=(throw_on_move_construction &&)      & = default;
};

/**
 * @brief Class with Potential exception throwing on move assignment.
 */
class throw_on_move_assignment final {
public:
  /**
   * @brief Ctor.
   */
  throw_on_move_assignment()  = default;
  /**
   * @brief Dtor.
   */
  ~throw_on_move_assignment() = default;

  /**
   * @brief Copy assignment operator
   */
  throw_on_move_assignment(throw_on_move_assignment const &) = default;
  /**
   * @brief Move assignment operator
   */
  throw_on_move_assignment(throw_on_move_assignment &&)      = default;

  /**
   * @brief Copy assignment operator
   * @return _on_move_assignment&
   */
  throw_on_move_assignment &operator=(throw_on_move_assignment const &) & = default;
  /**
   * @brief Move assignment operator
   * @return _on_move_assignment&
   */
  throw_on_move_assignment &operator=(throw_on_move_assignment &&) & noexcept(false) {
    return *this;
  }
};
} // namespace test_utility_general_helper

#endif /* PSTL_UTILITY_GENERAL_HELPER_H */
