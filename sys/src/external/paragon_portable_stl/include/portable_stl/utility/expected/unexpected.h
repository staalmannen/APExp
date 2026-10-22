// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unexpected.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNEXPECTED_H
#define PSTL_UNEXPECTED_H

#include "../../language_support/initializer_list.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/type_properties/is_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_copy_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../../metaprogramming/type_relations/is_same.h"
#include "../general/forward.h"
#include "../general/in_place_t.h"
#include "../general/swap.h"

namespace portable_stl {

/**
 * @brief The class template that represents unexpected objects stored in expected objects.
 *
 * @tparam t_error The type of error object.
 */

template<class t_error> class unexpected final {
  /**
   * @brief Stored error object value.
   */
  t_error m_error;

public:
  /**
   * @brief Destructor.
   *
   */
  ~unexpected() = default;

  /**
   * @brief Default copy constructor.
   * @param source object.
   */
  constexpr unexpected(unexpected const &source) = default;

  /**
   * @brief Default move constructor.
   * @param source object.
   */
  constexpr unexpected(unexpected &&source) = default;

  /**
   * @brief Construct a new unexpected object from value.
   *
   * @tparam t_current_error value error type.
   * @param value error value.
   */
  template<
    class t_current_error = t_error,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_current_error>, unexpected>>,
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_current_error>, ::portable_stl::in_place_t>>,
        ::portable_stl::is_constructible<t_error, t_current_error>>,
      void *>
    = nullptr>
  explicit unexpected(t_current_error &&value) noexcept(
    noexcept(unexpected(::portable_stl::in_place_t{}, ::portable_stl::forward<t_current_error>(value))))
      : unexpected(::portable_stl::in_place_t{}, ::portable_stl::forward<t_current_error>(value)) {
  }

  /**
   * @brief Inplace construct error object.
   * @tparam t_args arguments types for construct error object.
   * @param arguments arguments for construct error object.
   */
  template<class... t_args,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_error, t_args...>, void *>
           = nullptr>
  constexpr explicit unexpected(::portable_stl::in_place_t,
                                t_args &&...arguments) noexcept(noexcept(t_error(::portable_stl::declval<t_args>()...)))
      : m_error(::portable_stl::forward<t_args>(arguments)...) {
  }

  /**
   * @brief Inplace construct error object with initializer_list.
   * @tparam t_list_value the types of initializer_list values.
   * @tparam t_args arguments types for construct error object.
   * @param list_values values in initializer_list.
   * @param arguments arguments for construct error object.
   */
  template<class t_list_value,
           class... t_args,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::is_constructible<t_error, ::portable_stl::initializer_list<t_list_value>, t_args...>,
             void *>
           = nullptr>
  constexpr unexpected(::portable_stl::in_place_t,
                       ::std::initializer_list<t_list_value> const &list_values,
                       t_args &&...arguments) noexcept(noexcept(t_error(::portable_stl::declval<t_args>()...)))
      : m_error(::portable_stl::initializer_list<t_list_value>(list_values),
                ::portable_stl::forward<t_args>(arguments)...) {
  }

  /**
   * @brief Copy assignable operator.
   * @param source source object.
   * @return reference to this object.
   */
  unexpected &operator=(unexpected const &source) & = default;

  /**
   * @brief Move assignable operator.
   * @param source source object.
   * @return reference to this object.
   */
  unexpected &operator=(unexpected &&source) & = default;

  /**
   * @brief Constant value object getter.
   * @return constant lvalue reference.
   */
  constexpr t_error const &error() const & noexcept;

  /**
   * @brief Value object getter.
   * @return lvalue reference..
   */
  t_error &error() & noexcept;

  /**
   * @brief Constant value object getter from temprary object ( rvalue reference ).
   * @return constant rvalue reference..
   */
  constexpr t_error const &&error() const && noexcept;

  /**
   * @brief Value object getter from temprary object ( rvalue reference ).
   * @return rvalue reference..
   */
  t_error &&error() && noexcept;

  /**
   * @brief Swap values with other object.
   *
   * @param other other object.
   */
  void local_swap(unexpected &other) noexcept(::portable_stl::is_nothrow_swappable<t_error>{}());

  /**
   * @brief Compare values with other object.
   * @tparam t_other_error type of other error object.
   * @param other other object.
   * @return result of compare.
   * @retval true if current error object and error object from other object is equal.
   * @retval true if current error object and error object from other object is not equal.
   */
  template<class t_other_error> constexpr bool is_equal(unexpected<t_other_error> const &other) const noexcept;
};

/**
 * @brief Constant value object getter.
 *
 * @tparam t_error type of internal error object.
 * @return constant lvalue reference.
 */
template<class t_error> constexpr inline t_error const &unexpected<t_error>::error() const & noexcept {
  return m_error;
}

/**
 * @brief Value object getter.
 * @return lvalue reference..
 */
template<class t_error> inline t_error &unexpected<t_error>::error() & noexcept {
  return m_error;
}

/**
 * @brief Constant value object getter from temprary object ( rvalue reference ).
 * @return constant rvalue reference..
 */
template<class t_error> constexpr inline t_error const &&unexpected<t_error>::error() const && noexcept {
  return ::portable_stl::move(m_error);
}

/**
 * @brief Value object getter from temprary object ( rvalue reference ).
 * @return rvalue reference..
 */
template<class t_error> inline t_error &&unexpected<t_error>::error() && noexcept {
  return ::portable_stl::move(m_error);
}

/**
 * @brief Swap values with other object.
 *
 * @param other other object.
 */
template<class t_error>
inline void unexpected<t_error>::local_swap(unexpected &other) noexcept(
  ::portable_stl::is_nothrow_swappable<t_error>{}()) {
  ::portable_stl::swap(m_error, other.m_error);
}

/**
 * @brief Compare values with other object.
 * @tparam t_other_error type of other error object.
 * @param other other object.
 * @return result of compare.
 * @retval true if current error object and error object from other object is equal.
 * @retval true if current error object and error object from other object is not equal.
 */
template<class t_error>
template<class t_other_error>
constexpr inline bool unexpected<t_error>::is_equal(unexpected<t_other_error> const &other) const noexcept {
  return m_error == other.m_error;
}

/**
 * @brief Is equal two unexpected objects.
 *
 * @tparam t_error type of internal error for object.
 * @param left one object.
 * @param right other object.
 * @return result of compare.
 * @retval true if internal error value of one object equal other object.
 * @retval false if internal error value of one object not equal other object.
 */
template<class t_error>
constexpr inline static bool operator==(unexpected<t_error> const &left, unexpected<t_error> const &right) noexcept {
  return left.is_equal(right);
}

/**
 * @brief Is not equal two unexpected objects.
 *
 * @tparam t_error type of internal error for object.
 * @param left one object.
 * @param right other object.
 * @return result of compare.
 * @retval true if internal error value of one object not equal other object.
 * @retval false if internal error value of one object equal other object.
 */
template<class t_error>
constexpr inline static bool operator!=(unexpected<t_error> const &left, unexpected<t_error> const &right) noexcept {
  return !left.is_equal(right);
}

/**
 * @brief Swap two unexpected objects.
 *
 * @tparam t_error internal error value type.
 * @param left one object.
 * @param right other object.
 */
template<class t_error>
constexpr inline static void swap(unexpected<t_error> &left,
                                  unexpected<t_error> &right) noexcept(noexcept(left.local_swap(right))) {
  return left.local_swap(right);
}
} // namespace portable_stl

#endif // PSTL_UNEXPECTED_H
