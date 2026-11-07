// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="logic_error.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LOGIC_ERROR_H
#define PSTL_LOGIC_ERROR_H

#include "exception.h"

namespace std {
/**
 * @brief Defines a type of object to be thrown as exception.
 * It reports errors that are a consequence of faulty logic within the program such as violating logical preconditions
 * or class invariants and may be preventable.
 */
template<class = void> class logic_error : public ::std::exception {
public:
  /**
   * @brief Default destructor.
   */
  ~logic_error() noexcept override                                                = default;
  /**
   * @brief Default constructor.
   */
  logic_error() noexcept                                                          = default;
  /**
   * @brief Default copy constructor.
   */
  logic_error(logic_error const &) noexcept                                       = default;
  /**
   * @brief Default move constructor.
   */
  logic_error(logic_error &&) noexcept                                            = default;
  /**
   * @brief Default copy assignment.
   */
  logic_error                            &operator=(logic_error const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  logic_error                            &operator=(logic_error &&) noexcept      = default;
  /**
   * @brief Get exception message.
   *
   * @return const char pointer to ntbs message.
   */
  char const * what() const noexcept override;
};

/**
 * @brief Get exception message.
 *
 * @return const char pointer to ntbs message.
 */
template<class t_object>
inline char const * logic_error<t_object>::what() const noexcept {
  return "logical error from portable_stl.";
}
} // namespace std

#endif // PSTL_LOGIC_ERROR_H
