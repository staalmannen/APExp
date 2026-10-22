// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="out_of_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_OUT_OF_RANGE_H
#define PSTL_OUT_OF_RANGE_H

#include "logic_error.h"

namespace portable_stl {
/**
 * @brief Defines a type of object to be thrown as exception.
 * It reports errors that are consequence of attempt to access elements out of defined range.
 */
template<class = void>
class out_of_range : public ::portable_stl::logic_error<> {
public:
  /**
   * @brief Default destructor.
   */
  ~out_of_range() noexcept override                                                = default;
  /**
   * @brief Default constructor.
   */
  out_of_range() noexcept                                                          = default;
  /**
   * @brief Default copy constructor.
   */
  out_of_range(out_of_range const &) noexcept                                      = default;
  /**
   * @brief Default move constructor.
   */
  out_of_range(out_of_range &&) noexcept                                           = default;
  /**
   * @brief Default copy assignment.
   */
  out_of_range                           &operator=(out_of_range const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  out_of_range                           &operator=(out_of_range &&) noexcept      = default;
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
inline ::portable_stl::exception::message_type out_of_range<t_object>::what() const noexcept {
  return "out of range error from portable_stl.";
}

} // namespace portable_stl

#endif // PSTL_OUT_OF_RANGE_H
