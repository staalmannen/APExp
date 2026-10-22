// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bad_expected_access.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BAD_EXPECTED_ACCESS_H
#define PSTL_BAD_EXPECTED_ACCESS_H

#include "../../language_support/exception.h"
#include "../../metaprogramming/primary_type/is_void.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../general/forward.h"
#include "../general/move.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "exception/exception_masking.h"
#else
#  include "noexception/exception_masking.h"
#endif

namespace portable_stl {
/**
 * @brief The class template bad_expected_access defines the type of objects thrown as exceptions to report the
 * situation where an attempt is made to access the value of an expected<t_type, t_error> object for which has_value()
 * is false.
 *
 * @tparam t_error type of error object.
 */
template<class t_error, class = ::portable_stl::is_void<t_error>> class bad_expected_access;

/**
 * @brief The class template bad_expected_access defines the type of objects thrown as exceptions to report the
 * situation where an attempt is made to access the value of an expected<t_type, t_error> object for which has_value()
 * is false.
 *
 * t_error is void.
 *
 * @tparam t_error type of error object.
 */
template<class t_error>
class bad_expected_access<t_error, ::portable_stl::true_type> : public ::portable_stl::exception {
protected:
  /**
   * @brief Default constructor.
   */
  bad_expected_access() noexcept                                         = default;
  /**
   * @brief Default copy constructor.
   */
  bad_expected_access(bad_expected_access const &) noexcept              = default;
  /**
   * @brief Default move constructor.
   */
  bad_expected_access(bad_expected_access &&) noexcept                   = default;
  /**
   * @brief Default copy assignment.
   */
  bad_expected_access &operator=(bad_expected_access const &) & noexcept = default;
  /**
   * @brief Default move assignment.
   */
  bad_expected_access &operator=(bad_expected_access &&) & noexcept      = default;

public:
  /**
   * @brief Default destructor.
   */
  ~bad_expected_access() noexcept override = default;

  /**
   * @brief Get exception message.
   *
   * @return const char pointer to ntbs message.
   */
  ::portable_stl::exception::message_type what() const noexcept override;
};

/**
 * @brief Get exception message.
 * @tparam t_error type of error object.
 *
 * @return const char pointer to ntbs message.
 */
template<class t_error>
inline ::portable_stl::exception::message_type
  bad_expected_access<t_error, ::portable_stl::true_type>::what() const noexcept {
  return "bad access to portable_stl::expected without expected value";
}

/**
 * @brief The class template bad_expected_access defines the type of objects thrown as exceptions to report the
 * situation where an attempt is made to access the value of an expected<t_type, t_error> object for which has_value()
 * is false.
 * Non void error object type.
 * @tparam t_error type of error object.
 */
template<class t_error, class> class bad_expected_access : public bad_expected_access<void, ::portable_stl::true_type> {
  /**
   * @brief Error value object.
   *
   */
  ::portable_stl::exception_masking<t_error> m_error;

public:
  /**
   * @brief Error type.
   */
  using error_type = t_error;

  /**
   * @brief Default destructor.
   */
  ~bad_expected_access() noexcept override = default;

  /**
   * @brief Construct a new bad_expected_access object.
   *
   * @param current_error error value.
   */
  template<class t_current_error = t_error,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::negation<::portable_stl::is_same<t_current_error, bad_expected_access>>,
             void *>
           = nullptr>
  explicit bad_expected_access(t_current_error &&current_error) noexcept(
    ::portable_stl::is_nothrow_move_constructible<t_current_error>{}())
      : bad_expected_access<void, ::portable_stl::true_type>()
      , m_error(::portable_stl::forward<t_current_error>(current_error)) {
  }
  /**
   * @brief Default constructor.
   */
  bad_expected_access() noexcept                                         = default;
  /**
   * @brief Default copy constructor.
   */
  bad_expected_access(bad_expected_access const &) noexcept              = default;
  /**
   * @brief Default move constructor.
   */
  bad_expected_access(bad_expected_access &&) noexcept                   = default;
  /**
   * @brief Default copy assignment.
   */
  bad_expected_access &operator=(bad_expected_access const &) & noexcept = default;
  /**
   * @brief Default move assignment.
   */
  bad_expected_access &operator=(bad_expected_access &&) & noexcept      = default;
  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  error_type const    &error() const    &noexcept {
    return m_error.error();
  }
  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  error_type &&error() && noexcept {
    return ::portable_stl::move(::portable_stl::move(m_error).error());
  }
  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  error_type const &&error() const && noexcept {
    return ::portable_stl::move(::portable_stl::move(m_error).error());
  }
};

} // namespace portable_stl

#endif // PSTL_BAD_EXPECTED_ACCESS_H
