// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bad_function_call.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BAD_FUNCTION_CALL_H
#define PSTL_BAD_FUNCTION_CALL_H

#include "exception.h"

namespace portable_stl {
/**
 * @brief bad_function_call is the type of the exception thrown by function::operator() if the function wrapper has no
 * target.
 */
template<class = void> class bad_function_call : public ::portable_stl::exception {
public:
  /**
   * @brief Default destructor.
   */
  ~bad_function_call() noexcept override                                                = default;
  /**
   * @brief Default constructor.
   */
  bad_function_call() noexcept                                                          = default;
  /**
   * @brief Default copy constructor.
   */
  bad_function_call(bad_function_call const &) noexcept                                 = default;
  /**
   * @brief Default move constructor.
   */
  bad_function_call(bad_function_call &&) noexcept                                      = default;
  /**
   * @brief Default copy assignment.
   */
  bad_function_call                      &operator=(bad_function_call const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  bad_function_call                      &operator=(bad_function_call &&) noexcept      = default;
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
inline ::portable_stl::exception::message_type bad_function_call<t_object>::what() const noexcept {
  return "bad_function_call error from portable_stl.";
}
} // namespace portable_stl

#endif // PSTL_BAD_FUNCTION_CALL_H
