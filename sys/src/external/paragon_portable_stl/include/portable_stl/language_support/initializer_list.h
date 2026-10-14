// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="initializer_list.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INITIALIZER_LIST_H
#define PSTL_INITIALIZER_LIST_H

#include "../common/size_t.h"

#if !(defined(_LIBCPP_INITIALIZER_LIST) || defined(_INITIALIZER_LIST_) || defined(_INITIALIZER_LIST) \
      || defined(SSDK_STL_INITIALIZER_LIST))
#  include "initializer_list_stl/initializer_list.h"
#endif

namespace portable_stl {

/**
 * @brief list initialization support class.
 * @tparam t_type type of initialization values.
 */
template<class t_type> class initializer_list final {
public:
  /**
   * @brief Type of initialization objects.
   */
  using value_type = t_type;

  /**
   * @brief Reference to objects.
   */
  using reference = value_type const &;

  /**
   * @brief Constant reference to objects.
   */
  using const_reference = value_type const &;

  /**
   * @brief Type for store size of list initialization objects.
   */
  using size_type = ::portable_stl::size_t;

  /**
   * @brief Iterator for access to objects.
   */
  using iterator = value_type const *;

  /**
   * @brief Constant iterator for access to objects.
   */
  using const_iterator = value_type const *;

private:
  /**
   * @brief Iterator to first element.
   */
  const_iterator m_begin;
  /**
   * @brief Number of elements.
   */
  size_type      m_size;

  /**
   * @brief Constructor for create list initialization.
   * @param current_begin fisrt element.
   * @param current_size number of elements.
   */
  constexpr initializer_list(const_iterator current_begin, size_type current_size) noexcept
      : m_begin(current_begin), m_size(current_size) {
  }

public:
  /**
   * @brief Default constructor.
   * First element is nullptr, number of elements is 0.
   */
  constexpr initializer_list() noexcept : initializer_list(nullptr, 0U) {
  }

  /**
   * @brief Constructor for create list initialization from std::initializer_list.
   * @param il list initialization from STL.
   */
  constexpr initializer_list(::std::initializer_list<value_type> const &il) noexcept
      : initializer_list(il.begin(), il.size()) {
  }

  /**
   * @brief Number of elements.
   * @return number of elements.
   */
  constexpr size_type size() const noexcept {
    return m_size;
  }

  /**
   * @brief First element.
   * @return first element.
   */
  constexpr const_iterator begin() const noexcept {
    return m_begin;
  }

  /**
   * @brief One past the last element.
   * @return one past the last element.
   */
  constexpr const_iterator end() const noexcept {
    return &begin()[size()];
  }
};

} // namespace portable_stl

#endif // PSTL_INITIALIZER_LIST_H
