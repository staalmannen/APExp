// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="exception_masking.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXCEPTION_MASKING_H
#define PSTL_EXCEPTION_MASKING_H

#include "../../../metaprogramming/logical_operator/negation.h"
#include "../../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../../metaprogramming/type_relations/is_same.h"
#include "../../general/forward.h"
#include "../../general/move.h"

namespace portable_stl {
/**
 * @brief Helper class for hide exceptions from destructor.
 * @tparam t_value the inner value type.
 */
template<class t_value> class exception_masking final {
  /**
   * @brief Inner value.
   *
   */
  t_value m_error;

public:
  /**
   * @brief Construct a new expection guard wrapper object
   *
   * @tparam t_current_error type of error value.
   * @param current_error inner value.
   */
  template<class t_current_error = t_value,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::negation<::portable_stl::is_same<t_current_error, exception_masking>>,
             void *>
           = nullptr>
  explicit exception_masking(t_current_error &&current_error) noexcept
      : m_error(::portable_stl::forward<t_current_error>(current_error)) {
  }

  /**
   * @brief Destructor without exceptions.
   */
  ~exception_masking() noexcept = default;

  /**
   * @brief Copy constructor.
   */
  exception_masking(exception_masking const &) noexcept            = default;
  /**
   * @brief Move constructor.
   */
  exception_masking(exception_masking &&) noexcept                 = default;
  /**
   * @brief Copy assign.
   */
  exception_masking &operator=(exception_masking const &) noexcept = default;
  /**
   * @brief Move assign.
   */
  exception_masking &operator=(exception_masking &&) noexcept      = default;

  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  t_value const &error() const & noexcept {
    return m_error;
  }
  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  t_value &&error() && noexcept {
    return ::portable_stl::move(m_error);
  }
  /**
   * @brief Getter for error value.
   *
   * @return error value.
   */
  t_value const &&error() const && noexcept {
    return ::portable_stl::move(m_error);
  }
};

} // namespace portable_stl

#endif // PSTL_EXCEPTION_MASKING_H
