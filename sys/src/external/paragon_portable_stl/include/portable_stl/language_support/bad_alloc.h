// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bad_alloc.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BAD_ALLOC_H
#define PSTL_BAD_ALLOC_H

#include "exception.h"

namespace portable_stl {
/**
 * @brief bad_alloc is the type of the object thrown as exceptions by the allocation functions to report failure to
 * allocate storage.
 */
template<class = void> class bad_alloc : public ::portable_stl::exception {
public:
  /**
   * @brief Default destructor.
   */
  ~bad_alloc() noexcept override                                                = default;
  /**
   * @brief Default constructor.
   */
  bad_alloc() noexcept                                                          = default;
  /**
   * @brief Default copy constructor.
   */
  bad_alloc(bad_alloc const &) noexcept                                         = default;
  /**
   * @brief Default move constructor.
   */
  bad_alloc(bad_alloc &&) noexcept                                              = default;
  /**
   * @brief Default copy assignment.
   */
  bad_alloc                              &operator=(bad_alloc const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  bad_alloc                              &operator=(bad_alloc &&) noexcept      = default;
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
template<class t_object> inline ::portable_stl::exception::message_type bad_alloc<t_object>::what() const noexcept {
  return "bad_alloc error from portable_stl.";
}
} // namespace portable_stl

#endif // PSTL_BAD_ALLOC_H
