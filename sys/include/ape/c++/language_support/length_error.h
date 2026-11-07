// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="length_error.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_LENGTH_ERROR_H
#define PSTL_LENGTH_ERROR_H

#include "logic_error.h"

namespace std {
/**
 * @brief Defines a type of object to be thrown as exception. It reports errors that result from attempts to exceed
 * implementation defined length limits for some object.
 */
template<class = void> class length_error : public ::std::logic_error<> {
public:
  /**
   * @brief Default destructor.
   */
  ~length_error() noexcept override                                                = default;
  /**
   * @brief Default constructor.
   */
  length_error() noexcept                                                          = default;
  /**
   * @brief Default copy constructor.
   */
  length_error(length_error const &) noexcept                                      = default;
  /**
   * @brief Default move constructor.
   */
  length_error(length_error &&) noexcept                                           = default;
  /**
   * @brief Default copy assignment.
   */
  length_error                           &operator=(length_error const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  length_error                           &operator=(length_error &&) noexcept      = default;
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
template<class t_object> inline char const * length_error<t_object>::what() const noexcept {
  return "length error from portable_stl.";
}

} // namespace std

#endif // PSTL_LENGTH_ERROR_H
