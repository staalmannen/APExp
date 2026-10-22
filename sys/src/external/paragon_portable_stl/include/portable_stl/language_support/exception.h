// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="exception.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXCEPTION_H
#define PSTL_EXCEPTION_H

#include "../common/char_t.h"

namespace portable_stl {

/**
 * @brief The class exception defines the base class for the types of objects thrown as exceptions by C++ standard
 * library components, and certain expressions, to report errors detected during program execution.
 */
class exception {
protected:
  /**
   * @brief Default constructor.
   */
  exception() noexcept = default;

  /**
   * @brief Default copy constructor.
   *
   * @param source source object.
   */
  exception(exception const &source) noexcept = default;

  /**
   * @brief Default move constructor.
   *
   * @param source source object.
   */
  exception(exception &&source) noexcept = default;

  /**
   * @brief Default copy assigment operator.
   *
   * @param source source object.
   * @return reference to this.
   */
  exception &operator=(exception const &source) & noexcept = default;

  /**
   * @brief Default move assigment operator.
   *
   * @param source source object.
   * @return reference to this.
   */
  exception &operator=(exception &&source) & noexcept = default;

public:
  /**
   * @brief Message type for ntbs.
   *
   */
  using message_type            = ::portable_stl::char_t const *;
  /**
   * @brief Default destructor.
   */
  virtual ~exception() noexcept = default;

  /**
   * @brief Get exception message.
   *
   * @return const char pointer to ntbs message.
   */
  virtual message_type what() const noexcept = 0;
};

} // namespace portable_stl

#endif // PSTL_EXCEPTION_H
