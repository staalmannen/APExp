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

namespace portable_stl {
/**
 * @brief Defines a type of object to be thrown as exception.
 * It reports errors that are a consequence of faulty logic within the program such as violating logical preconditions
 * or class invariants and may be preventable.
 */
template<class = void> class logic_error : public ::portable_stl::exception {
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
  ::portable_stl::exception::message_type what() const noexcept override;
};

/**
 * @brief Get exception message.
 *
 * @return const char pointer to ntbs message.
 */
template<class t_object>
inline ::portable_stl::exception::message_type logic_error<t_object>::what() const noexcept {
  return "logical error from portable_stl.";
}
} // namespace portable_stl

#endif // PSTL_LOGIC_ERROR_H
