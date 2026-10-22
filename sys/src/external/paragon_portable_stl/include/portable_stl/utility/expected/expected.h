// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="expected.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXPECTED_H
#define PSTL_EXPECTED_H

#include "../../algorithm/max.h"
#include "../../array/array.h"
#include "../../common/uchar_t.h"
#include "../../language_support/initializer_list.h"
#include "../../memory/addressof.h"
#include "../../memory/construct_at.h"
#include "../../memory/destroy_at.h"
#include "../../memory/storage_for.h"
#include "../../metaprogramming/other_transformations/invoke_result.h"
#include "../../metaprogramming/primary_type/is_void.h"
#include "../../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_destructible.h"
#include "../../utility/general/functional/invoke.h"
#include "../general/make_exception_guard.h"
#include "bad_expected_access.h"
#include "expected_swap_helper.h"
#include "unexpect_t.h"
#include "unexpected.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../../language_support/exception/throw_on_true.h"
#else
#  include "../../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief The class template expected provides a way to store either of two values.
 * An object of expected at any given time either holds an expected value of type t_type, or an unexpected value of type
 * t_error. expected is never valueless.
 *
 * @tparam t_type the type of the expected value. The type must either be (possibly cv-qualified) void, or meet the
 * Destructible requirements (in particular, array and reference types are not allowed).
 * @tparam t_error the type of the unexpected value. The type must meet the Destructible requirements, and must be a
 * valid template argument for unexpected (in particular, arrays, non-object types, and cv-qualified types are not
 * allowed).
 */
template<class t_type, class t_error, class = ::portable_stl::is_void<t_type>> class expected final {
public:
  /**
   * @brief the type of the expected value.
   */
  using value_type = t_type;

  /**
   * @brief the type of the unexpected value.
   */
  using error_type = t_error;

  /**
   * @brief the type of the unexpected object.
   */
  using unexpected_type = ::portable_stl::unexpected<error_type>;

  /**
   * @brief Create type for other type of the expected value and current type of the unexpected value.
   *
   * @tparam t_other_type the other type of the expected value.
   */
  template<class t_other_type> using rebind = expected<t_other_type, error_type>;

private:
  /**
   * @brief Helper concept for check construct from other expected class.
   *
   * @tparam t_other_value the other value type.
   * @tparam t_other_error the other error type.
   */
  template<class t_other_value, class t_other_error>
  using can_construct_from_expected = ::portable_stl::conjunction<
    ::portable_stl::negation<::portable_stl::is_same<::portable_stl::expected<t_other_value, t_other_error>, expected>>,
    ::portable_stl::is_constructible<value_type, t_other_value>,
    ::portable_stl::is_constructible<error_type, t_other_error>,
    ::portable_stl::disjunction<
      ::portable_stl::is_same<::portable_stl::remove_cv_t<value_type>, bool>,
      ::portable_stl::negation<::portable_stl::disjunction<
        ::portable_stl::is_constructible<value_type, ::portable_stl::expected<t_other_value, t_other_error> &>,
        ::portable_stl::is_constructible<value_type, ::portable_stl::expected<t_other_value, t_other_error>>,
        ::portable_stl::is_constructible<value_type, ::portable_stl::expected<t_other_value, t_other_error> const &>,
        ::portable_stl::is_constructible<value_type, ::portable_stl::expected<t_other_value, t_other_error> const>,
        ::portable_stl::is_convertible<::portable_stl::expected<t_other_value, t_other_error> &, value_type>,
        ::portable_stl::is_convertible<::portable_stl::expected<t_other_value, t_other_error>, value_type>,
        ::portable_stl::is_convertible<::portable_stl::expected<t_other_value, t_other_error> const &, value_type>,
        ::portable_stl::is_convertible<::portable_stl::expected<t_other_value, t_other_error> const, value_type>>>>,
    ::portable_stl::negation<::portable_stl::disjunction<
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error> &>,
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error>>,
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error> const &>,
      ::portable_stl::is_constructible<unexpected_type,
                                       ::portable_stl::expected<t_other_value, t_other_error> const>>>>;

  /**
   * @brief Type for describe current storage value.
   */
  enum class storage_state : ::portable_stl::uchar_t {
    /**
     * @brief Storage have value.
     */
    value,
    /**
     * @brief Storage have error.
     */
    error
  };

  /**
   * @brief the storage for save value or error.
   */
  alignas(::portable_stl::max(alignof(value_type), alignof(error_type)))
    portable_stl::array<::portable_stl::uchar_t, ::portable_stl::max(sizeof(value_type), sizeof(error_type))> m_storage;

  /**
   * @brief the variable described storage content.
   */
  storage_state m_storage_type;

public:
  /**
   * @brief Destructor for expected object.
   */
  ~expected() noexcept(::portable_stl::is_nothrow_destructible<value_type>{}()
                       && ::portable_stl::is_nothrow_destructible<error_type>{}()) {
    if (m_storage_type == storage_state::value) {
      ::portable_stl::destroy_at(&::portable_stl::storage_for<value_type>(m_storage));
    } else {
      ::portable_stl::destroy_at(&::portable_stl::storage_for<error_type>(m_storage));
    }
  }

  /**
   * @brief Default constructor for expected object with the expected default value.
   */
  expected() noexcept(::portable_stl::is_nothrow_default_constructible<value_type>{}())
      : m_storage_type(storage_state::value) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage)));
  }

  /**
   * @brief Initialize class with valid value.
   * @tparam t_value_type type of value.
   * @param current_value the value for initialize.
   */
  template<
    class t_value_type = value_type,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_value_type>, ::portable_stl::in_place_t>>,
        ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_value_type>, expected>>,
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_value_type>, unexpected_type>>,
        ::portable_stl::is_constructible<value_type, t_value_type>>,
      void *>
    = nullptr>
  explicit expected(t_value_type &&current_value) noexcept(
    ::portable_stl::is_nothrow_constructible<value_type, t_value_type>{}())
      : m_storage_type(storage_state::value) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                                   ::portable_stl::forward<t_value_type>(current_value)));
  }
  /**
   * @brief Inplace value constructor.
   *
   * @tparam t_args arguments for construct value.
   * @param args value constructor arguments.
   */
  template<class... t_args>
  expected(::portable_stl::in_place_t,
           t_args &&...args) noexcept(::portable_stl::is_nothrow_constructible<value_type, t_args...>{}())
      : m_storage_type(storage_state::value) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                                   ::portable_stl::forward<t_args>(args)...));
  }

  /**
   * @brief Inplace value constructor with initializer_list.
   *
   * @tparam t_list_value the types of initializer_list values.
   * @tparam t_args types of arguments.
   * @param
   * @param list_values values in initializer_list.
   * @param args value constructor arguments.
   */
  template<class t_list_value, class... t_args>
  expected(::portable_stl::in_place_t, ::std::initializer_list<t_list_value> list_values, t_args &&...args) noexcept(
    ::portable_stl::is_nothrow_constructible<value_type, ::portable_stl::initializer_list<t_list_value>, t_args...>{}())
      : m_storage_type(storage_state::value) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                                   ::portable_stl::initializer_list<t_list_value>{list_values},
                                                   ::portable_stl::forward<t_args>(args)...));
  }
  /**
   * @brief Initialize class with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  expected(::portable_stl::unexpected<t_other_error> const &error_value) noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(
      ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage), error_value.error()));
  }

  /**
   * @brief Initialize class with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  expected(::portable_stl::unexpected<t_other_error> &&error_value) noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::move(error_value.error())));
  }

  /**
   * @brief Inplace error constructor.
   *
   * @tparam t_args the arguments for error value construct.
   * @param args value constructor arguments.
   */
  template<class... t_args>
  expected(::portable_stl::unexpect_t,
           t_args &&...args) noexcept(::portable_stl::is_nothrow_constructible<error_type, t_args...>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::forward<t_args>(args)...));
  }
  /**
   * @brief Inplace error constructor with initializer_list.
   *
   * @tparam t_list_value the types of initializer_list values.
   * @tparam t_args types of arguments.
   * @param
   * @param list_values values in initializer_list.
   * @param args value constructor arguments.
   */
  template<class t_list_value, class... t_args>
  explicit expected(
    ::portable_stl::unexpect_t,
    ::std::initializer_list<t_list_value> list_values,
    t_args &&...args) noexcept(::portable_stl::is_nothrow_constructible<error_type,
                                                                        ::portable_stl::initializer_list<t_list_value>,
                                                                        t_args...>{}())

      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::initializer_list<t_list_value>{list_values},
                                                   ::portable_stl::forward<t_args>(args)...));
  }

  /**
   * @brief Copy constructor expected object from the source expected object.
   * @param source the object for copy.
   */
  expected(expected const &source) noexcept(::portable_stl::is_nothrow_copy_constructible<value_type>{}()
                                            && ::portable_stl::is_nothrow_copy_constructible<error_type>{}())
      : m_storage_type(source.m_storage_type) {
    if (m_storage_type == storage_state::value) {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                                     ::portable_stl::storage_for<value_type const>(source.m_storage)));
    } else if (m_storage_type == storage_state::error) {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                     ::portable_stl::storage_for<error_type const>(source.m_storage)));
    } else {
      // Storage not have any value.
    }
  }

  /**
   * @brief Move constructor expected object from the source expected object.
   * @param source the object for move.
   */
  expected(expected &&source) noexcept(::portable_stl::is_nothrow_move_constructible<value_type>{}()
                                       && ::portable_stl::is_nothrow_move_constructible<error_type>{}())
      : m_storage_type(source.m_storage_type) {
    if (m_storage_type == storage_state::value) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                     ::portable_stl::move(::portable_stl::storage_for<value_type>(source.m_storage))));
    } else if (m_storage_type == storage_state::error) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                     ::portable_stl::move(::portable_stl::storage_for<error_type>(source.m_storage))));
    } else {
      // Storage not have any value.
    }
  }

  /**
   * @brief Copy constructor expected object from the source expected object.
   * @tparam t_other_value the other expected object value parameter type.
   * @tparam t_other_error the other expected object error parameter type.
   * @param source the object for copy.
   */
  template<class t_other_value,
           class t_other_error,
           ::portable_stl::enable_if_bool_constant_t<can_construct_from_expected<t_other_value, t_other_error>, void *>
           = nullptr>
  expected(::portable_stl::expected<t_other_value, t_other_error> const &source) noexcept(
    (::portable_stl::is_nothrow_constructible<
       value_type,
       ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<t_other_value>>>{}()
     && ::portable_stl::is_nothrow_constructible<
       error_type,
       ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<t_other_error>>>{}()))
      : m_storage_type(source.has_value() ? storage_state::value : storage_state::error) {
    if (m_storage_type == storage_state::value) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage), source.value()));
    } else {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage), source.error()));
    }
  }

  /**
   * @brief Move constructor expected object from the source expected object.
   * @tparam t_other_value the other expected object value parameter type.
   * @tparam t_other_error the other expected object error parameter type.
   * @param source the object for move.
   */
  template<class t_other_value,
           class t_other_error,
           ::portable_stl::enable_if_bool_constant_t<can_construct_from_expected<t_other_value, t_other_error>, void *>
           = nullptr>
  expected(::portable_stl::expected<t_other_value, t_other_error> &&source) noexcept((
    ::portable_stl::is_nothrow_constructible<value_type, ::portable_stl::add_rvalue_reference_t<t_other_value>>{}()
    && ::portable_stl::is_nothrow_constructible<error_type, ::portable_stl::add_rvalue_reference_t<t_other_error>>{}()))
      : m_storage_type(source.has_value() ? storage_state::value : storage_state::error) {
    if (m_storage_type == storage_state::value) {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<value_type>(m_storage),
                                                     ::portable_stl::move(source.value())));
    } else {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                     ::portable_stl::move(source.error())));
    }
  }

  /**
   * @brief Swap this object and source object.
   * @param source the object for swap.
   */
  void swap_internal(expected &source) noexcept(::portable_stl::is_nothrow_move_constructible<value_type>{}()
                                                && ::portable_stl::is_nothrow_swappable<value_type>{}()
                                                && ::portable_stl::is_nothrow_move_constructible<error_type>{}()
                                                && ::portable_stl::is_nothrow_swappable<error_type>{}()) {
    if ((m_storage_type == storage_state::value) && (source.m_storage_type == storage_state::value)) {
      swap(::portable_stl::storage_for<value_type>(m_storage),
           ::portable_stl::storage_for<value_type>(source.m_storage));
    } else if ((m_storage_type == storage_state::error) && (source.m_storage_type == storage_state::error)) {
      swap(::portable_stl::storage_for<error_type>(m_storage),
           ::portable_stl::storage_for<error_type>(source.m_storage));
    } else if (m_storage_type == storage_state::error) {
      ::portable_stl::utility_expected_helper::expected_swap_helper<value_type, error_type>::use(source.m_storage,
                                                                                                 m_storage);
      swap(m_storage_type, source.m_storage_type);
    } else {
      ::portable_stl::utility_expected_helper::expected_swap_helper<value_type, error_type>::use(m_storage,
                                                                                                 source.m_storage);
      swap(m_storage_type, source.m_storage_type);
    }
  }

  /**
   * @brief Copy assignment operator.
   *
   * @param source the source object.
   * @return reference to this object.
   */
  expected &operator=(expected const &source) & noexcept(::portable_stl::is_nothrow_copy_constructible<expected>{}()
                                                         && ::portable_stl::is_nothrow_swappable<expected>{}()) { //
    if (this != &source) {
      expected tmp{source};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Move assignment operator.
   *
   * @param source the source object.
   * @return reference to this object.
   */
  expected &operator=(expected &&source) & noexcept(
    ::portable_stl::is_nothrow_copy_constructible<expected>{}() && noexcept(this->swap_internal(*this))) {
    if (this != &source) {
      expected tmp{::portable_stl::move(source)};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Assignment valid value.
   * @tparam t_value_type type of value.
   * @param current_value the value for assignment.
   */
  template<
    class t_value_type = value_type,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_value_type>, expected>>,
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_value_type>, unexpected_type>>,
        ::portable_stl::is_constructible<value_type, t_value_type>,
        ::portable_stl::is_assignable<::portable_stl::add_lvalue_reference_t<value_type>, t_value_type>>,
      void *>
    = nullptr>
  inline expected &operator=(t_value_type &&current_value) & noexcept(
    ::portable_stl::is_nothrow_constructible<value_type, t_value_type>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{::portable_stl::forward<t_value_type>(current_value)};
    tmp.swap_internal(*this);
    return *this;
  }

  /**
   * @brief Assignment object with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  inline expected &operator=(::portable_stl::unexpected<t_other_error> const &error_value) & noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{error_value};
    tmp.swap_internal(*this);
    return *this;
  }

  /**
   * @brief Assignment object with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  inline expected &operator=(unexpected<t_other_error> &&error_value) & noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{::portable_stl::move(error_value)};
    tmp.swap_internal(*this);
    return *this;
  }

  /**
   * @brief Assignment in place value.
   *
   * @tparam t_args arguments for assignment value.
   * @param arguments value constructor arguments.
   * @return reference to value.
   */
  template<class... t_args>
  inline value_type &emplace(t_args &&...arguments) noexcept(
    ::portable_stl::is_nothrow_constructible<value_type, t_args...>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{::portable_stl::forward<t_args>(arguments)...};
    tmp.swap_internal(*this);
    return value();
  }

  /**
   * @brief Assignment in place value constructed with initializer_list.
   *
   * @tparam t_list_value the types of initializer_list values.
   * @tparam t_args types of arguments.
   * @param list_values values in initializer_list.
   * @param args value constructor arguments.
   * @return reference to value.
   */
  template<class t_list_value, class... t_args>
  inline value_type &emplace(::std::initializer_list<t_list_value> list_values, t_args &&...args) noexcept(
    ::portable_stl::is_nothrow_constructible<value_type, ::portable_stl::initializer_list<t_list_value>, t_args...>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{::portable_stl::in_place_t{},
                 ::portable_stl::initializer_list<t_list_value>{list_values},
                 ::portable_stl::forward<t_args>(args)...};
    tmp.swap_internal(*this);
    return value();
  }

  /**
   * @brief Get address of the expected constant value.
   *
   * @return the address of expected constant value.
   * @warning if has_value is false then behavior is undefined.
   */
  constexpr value_type const *operator->() const noexcept {
    return &::portable_stl::storage_for<value_type const>(m_storage);
  }

  /**
   * @brief Get address of the expected value.
   *
   * @return the address of expected value.
   * @warning if has_value is false then behavior is undefined.
   */
  value_type *operator->() noexcept {
    return &::portable_stl::storage_for<value_type>(m_storage);
  }
  /**
   * @brief Get lvalue reference to the expected constant value.
   *
   * @return the lvalue reference to the expected constant value.
   * @warning if has_value is false then behavior is undefined.
   */
  constexpr value_type const &operator*() const & noexcept {
    return ::portable_stl::storage_for<value_type const>(m_storage);
  }
  /**
   * @brief Get lvalue reference to the expected value.
   *
   * @return the lvalue reference to the expected value.
   * @warning if has_value is false then behavior is undefined.
   */
  value_type &operator*() & noexcept {
    return ::portable_stl::storage_for<value_type>(m_storage);
  }

  /**
   * @brief Get rvalue reference to the expected constant value.
   *
   * @return the rvalue reference to the expected constant value.
   * @warning if has_value is false then behavior is undefined.
   */
  constexpr value_type const &&operator*() const && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<value_type const>(m_storage));
  }
  /**
   * @brief Get rvalue reference to the expected value.
   *
   * @return the rvalue reference to the expected value.
   * @warning if has_value is false then behavior is undefined.
   */
  value_type &&operator*() && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<value_type>(m_storage));
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the expected value.
   * @retval false is stored the unexpected value.
   */
  constexpr explicit operator bool() const noexcept {
    return has_value();
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the expected value.
   * @retval false is stored the unexpected value or undefined.
   */
  constexpr bool has_value() const noexcept {
    return (m_storage_type == storage_state::value);
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the unexpected value.
   * @retval false is stored the expected value or undefined.
   */
  constexpr bool has_error() const noexcept {
    return (m_storage_type == storage_state::error);
  }

  /**
   * @brief Get the expected value.
   *
   * @return the expected value.
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  constexpr value_type const &value() const & noexcept(
    noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type const>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type const>(m_storage));
    return ::portable_stl::storage_for<value_type const>(m_storage);
  }

  /**
   * @brief Get the expected value.
   *
   * @return the expected value.
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  value_type &value() & noexcept(
    noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type>(m_storage));
    return ::portable_stl::storage_for<value_type>(m_storage);
  }

  /**
   * @brief Get the expected value.
   *
   * @return the expected value.
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  constexpr value_type const &&value() const && noexcept(
    noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type const>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type const>(m_storage));
    return ::portable_stl::move(::portable_stl::storage_for<value_type const>(m_storage));
  }

  /**
   * @brief Get the expected value.
   *
   * @return the expected value.
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  value_type &&value() && noexcept(
    noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type>(m_storage));
    return ::portable_stl::move(::portable_stl::storage_for<value_type>(m_storage));
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  constexpr error_type const &error() const & noexcept {
    return ::portable_stl::storage_for<error_type const>(m_storage);
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  error_type &error() & noexcept {
    return ::portable_stl::storage_for<error_type>(m_storage);
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  constexpr error_type const &&error() const && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<error_type const>(m_storage));
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  error_type &&error() && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<error_type>(m_storage));
  }

  /**
   * @brief Get value or other if value not exist.
   *
   * @tparam t_value_type type of other value.
   * @param other the other value if value not exist.
   * @return value or other.
   * @retval value if object has value.
   * @retval other if object has error.
   */
  template<class t_value_type>
  value_type value_or(t_value_type &&other) const & noexcept(
    ::portable_stl::is_nothrow_move_constructible<value_type>{}()
    && ::portable_stl::is_nothrow_constructible<value_type, decltype(other)>{}()) {
    return (has_value() ? **this : static_cast<value_type>(::portable_stl::forward<t_value_type>(other)));
  }

  /**
   * @brief Get value or other if value not exist.
   *
   * @tparam t_value_type type of other value.
   * @param other the other value if value not exist.
   * @return value or other.
   * @retval value if object has value.
   * @retval other if object has error.
   */
  template<class t_value_type>
  value_type value_or(t_value_type &&other) && noexcept(
    ::portable_stl::is_nothrow_move_constructible<value_type>{}()
    && ::portable_stl::is_nothrow_constructible<value_type, decltype(other)>{}()) {
    return (has_value() ? **this : static_cast<value_type>(::portable_stl::forward<t_value_type>(other)));
  }

  /**
   * @brief Get error or other
   *
   * @tparam t_other_error the type of other error.
   * @param other the other error.
   * @return error or other.
   * @retval error if object has error.
   * @retval other if object has value.
   */
  template<class t_other_error = error_type> error_type error_or(t_other_error &&other) const & noexcept{
    return (has_error() ? error() : static_cast<error_type>(::portable_stl::forward<t_other_error>(other)));
  }

  /**
   * @brief Get error or other
   *
   * @tparam t_other_error the type of other error.
   * @param other the other error.
   * @return error or other.
   * @retval error if object has error.
   * @retval other if object has value.
   */
  template<class t_other_error = error_type> error_type error_or(t_other_error &&other) && {
    return (has_error() ? error() : static_cast<error_type>(::portable_stl::forward<t_other_error>(other)));
  }

  /**
   * @brief Check equality this and other expected object.
   *
   * @tparam t_other_value type of other value.
   * @tparam t_other_error the type of other error.
   *
   * @param other the object for check equality.
   *
   * @return result of the checking.
   *
   * @retval true if objects is eqaul.
   * @retval false if objects is not eqaul.
   */
  template<class t_other_value, class t_other_error>
  bool is_equal(expected<t_other_value, t_other_error> const &other) const noexcept {
    if (has_value()) {
      return (other.has_value() && (operator*() == (other.operator*())));
    } else {
      return (other.has_error() && (error() == other.error()));
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, value_type>>>
  t_result and_then(t_functor &&functor) & noexcept(
    noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())) && noexcept(
      t_result{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*());
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, value_type>>>
  t_result and_then(t_functor &&functor) && noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()))) && noexcept(t_result{
    ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()));
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, value_type>>>
  t_result and_then(t_functor &&functor) const & noexcept(
    noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())) && noexcept(
      t_result{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*());
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, value_type>>>
  t_result and_then(t_functor &&functor) const && noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()))) && noexcept(t_result{
    ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()));
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) & noexcept(
    noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())) && noexcept(
      t_result{::portable_stl::in_place_t{}, operator*()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, operator*()};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error());
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) && noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))) && noexcept(t_result{
    ::portable_stl::in_place_t{}, ::portable_stl::move(operator*())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, ::portable_stl::move(operator*())};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()));
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) const & noexcept(
    noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())) && noexcept(
      t_result{::portable_stl::in_place_t{}, operator*()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, operator*()};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error());
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) const && noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))) && noexcept(t_result{
    ::portable_stl::in_place_t{}, ::portable_stl::move(operator*())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, ::portable_stl::move(operator*())};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()));
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, value_type>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) & noexcept(noexcept(
    t_result{::portable_stl::in_place_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())}) && noexcept(t_result{
    ::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())};
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, value_type>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) && noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(operator*()))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return t_result{
        ::portable_stl::in_place_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, value_type>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) const & noexcept(noexcept(
    t_result{::portable_stl::in_place_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())}) && noexcept(t_result{
    ::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), operator*())};
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, value_type>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) const && noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(operator*()))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return t_result{
        ::portable_stl::in_place_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(operator*()))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns an expected containing without value ( void on success ); otherwise, returns the expected
   * itself. Value map to void.
   *
   * @return the transformed expected value or itself on contain error.
   *
   */
  ::portable_stl::expected<void, error_type> transform_void() const
    noexcept(noexcept(::portable_stl::expected<void, error_type>{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::expected<void, error_type>{};
    } else {
      return ::portable_stl::expected<void, error_type>{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<value_type, t_result_value>>
  t_result transform_error(t_functor &&functor) & noexcept(noexcept(
    t_result{::portable_stl::unexpect_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())}) && noexcept(t_result{
    ::portable_stl::in_place_t{}, operator*()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, operator*()};
    } else {
      return t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<value_type, t_result_value>>
  t_result transform_error(t_functor &&functor) && noexcept(
    noexcept(t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(error()))}) && noexcept(t_result{
      ::portable_stl::in_place_t{}, ::portable_stl::move(operator*())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, ::portable_stl::move(operator*())};
    } else {
      return t_result{
        ::portable_stl::unexpect_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<value_type, t_result_value>>
  t_result transform_error(t_functor &&functor) const & noexcept(noexcept(
    t_result{::portable_stl::unexpect_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())}) && noexcept(t_result{
    ::portable_stl::in_place_t{}, operator*()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, operator*()};
    } else {
      return t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<value_type, t_result_value>>
  t_result transform_error(t_functor &&functor) const && noexcept(
    noexcept(t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(error()))}) && noexcept(t_result{
      ::portable_stl::in_place_t{}, ::portable_stl::move(operator*())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}, ::portable_stl::move(operator*())};
    } else {
      return t_result{
        ::portable_stl::unexpect_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))};
    }
  }
};

/**
 * @brief Swap this object and source object.
 *
 * @tparam t_type the type of the expected value. The type must either be (possibly cv-qualified) void, or meet the
 * Destructible requirements (in particular, array and reference types are not allowed).
 * @tparam t_error the type of the unexpected value. The type must meet the Destructible requirements, and must be a
 * valid template argument for unexpected (in particular, arrays, non-object types, and cv-qualified types are not
 * allowed).
 * @param left  the object for swap.
 * @param right the object for swap.
 */
template<class t_value, class t_error>
inline static void swap(
  ::portable_stl::expected<t_value, t_error> &left,
  ::portable_stl::expected<t_value, t_error> &right) noexcept(noexcept(left.swap_internal(right))) {
  left.swap_internal(right);
}

/**
 * @brief Check equality this and other expected object.
 *
 * @tparam t_value type of value.
 * @tparam t_error the type of error.
 * @tparam t_other_value type of other value.
 * @tparam t_other_error the type of other error.
 *
 * @param value the object for check equality.
 * @param other the object for check equality.
 *
 * @return result of the checking.
 *
 * @retval true if objects is eqaul.
 * @retval false if objects is not eqaul.
 */
template<class t_value, class t_error, class t_other_value, class t_other_error>
inline static bool operator==(::portable_stl::expected<t_value, t_error> const             &value,
                              ::portable_stl::expected<t_other_value, t_other_error> const &other) noexcept {
  return (value.is_equal(other));
}

/**
 * @brief Check equality this and other expected object.
 *
 * @tparam t_value type of value.
 * @tparam t_error the type of error.
 * @tparam t_other_value type of other value.
 *
 * @param value the object for check equality.
 * @param other the value for check equality.
 *
 * @return result of the checking.
 *
 * @retval true if objects is eqaul.
 * @retval false if objects is not eqaul.
 */
template<class t_value,
         class t_error,
         class t_other_value,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<
             ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_other_value>,
                                                              ::portable_stl::expected<t_value, t_error>>>,
             ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_other_value>,
                                                              ::portable_stl::unexpected<t_error>>>,
             ::portable_stl::is_constructible<t_value, t_other_value>,
             ::portable_stl::is_assignable<::portable_stl::add_lvalue_reference_t<t_value>, t_other_value>>,
           void *>
         = nullptr>
inline static bool operator==(
  ::portable_stl::expected<t_value, t_error> const &value,
  t_other_value const &other) noexcept(noexcept(::portable_stl::expected<t_value, t_error>{other})) {
  return (value.is_equal(::portable_stl::expected<t_value, t_error>{other}));
}

/**
 * @brief Check equality this and other expected object.
 *
 * @tparam t_value type of value.
 * @tparam t_error the type of error.
 * @tparam t_other_error the type of other error.
 *
 * @param value the object for check equality.
 * @param other the unexpected object for check equality.
 *
 * @return result of the checking.
 *
 * @retval true if objects is eqaul.
 * @retval false if objects is not eqaul.
 */
template<class t_value, class t_error, class t_other_error>
inline static bool operator==(
  ::portable_stl::expected<t_value, t_error> const &value,
  ::portable_stl::unexpected<t_other_error> const  &other) noexcept(noexcept(::portable_stl::expected<t_value, t_error>{
  other})) {
  return (value.is_equal(::portable_stl::expected<t_value, t_error>{other}));
}

/**
 * @brief The class template expected provides a way to store either of two values.
 * An object of expected at any given time either holds an expected value of type t_type, or an unexpected value of type
 * t_error. expected is never valueless.
 * Specification for work without value only error.
 *
 * @tparam t_error the type of the unexpected value. The type must meet the Destructible requirements, and must be a
 * valid template argument for unexpected (in particular, arrays, non-object types, and cv-qualified types are not
 * allowed).
 */
template<class t_value, class t_error> class expected<t_value, t_error, ::portable_stl::true_type> final {
public:
  /**
   * @brief the type of the expected value.
   */
  using value_type = void;

  /**
   * @brief the type of the unexpected value.
   */
  using error_type = t_error;

  /**
   * @brief the type of the unexpected object.
   */
  using unexpected_type = ::portable_stl::unexpected<error_type>;

  /**
   * @brief Create type for other type of the expected value and current type of the unexpected value.
   *
   * @tparam t_other_type the other type of the expected value.
   */
  template<class t_other_type> using rebind = expected<t_other_type, error_type>;

private:
  /**
   * @brief Helper concept for check construct from other expected class.
   *
   * @tparam t_other_value the other value type.
   * @tparam t_other_error the other error type.
   */
  template<class t_other_value, class t_other_error>
  using can_construct_from_expected = ::portable_stl::conjunction<
    ::portable_stl::negation<::portable_stl::is_same<::portable_stl::expected<t_other_value, t_other_error>, expected>>,
    ::portable_stl::is_void<t_other_value>,
    ::portable_stl::is_constructible<error_type, t_other_error>,
    ::portable_stl::negation<::portable_stl::disjunction<
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error> &>,
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error>>,
      ::portable_stl::is_constructible<unexpected_type, ::portable_stl::expected<t_other_value, t_other_error> const &>,
      ::portable_stl::is_constructible<unexpected_type,
                                       ::portable_stl::expected<t_other_value, t_other_error> const>>>>;

  /**
   * @brief Type for describe current storage value.
   */
  enum class storage_state : ::portable_stl::uchar_t {
    /**
     * @brief Storage have value.
     */
    value,
    /**
     * @brief Storage have error.
     */
    error
  };

  /**
   * @brief the storage for save error.
   */
  alignas(alignof(error_type)) portable_stl::array<::portable_stl::uchar_t, sizeof(error_type)> m_storage;

  /**
   * @brief the variable described storage content.
   */
  storage_state m_storage_type;

public:
  /**
   * @brief Destructor for expected object.
   */
  ~expected() noexcept(::portable_stl::is_nothrow_destructible<error_type>{}()) {
    if (m_storage_type == storage_state::error) {
      ::portable_stl::destroy_at(&::portable_stl::storage_for<error_type>(m_storage));
    }
  }

  /**
   * @brief Default constructor for expected object with the expected default value.
   */
  constexpr expected() noexcept : m_storage_type(storage_state::value) {
  }

  /**
   * @brief Initialize class with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  expected(::portable_stl::unexpected<t_other_error> const &error_value) noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(
      ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage), error_value.error()));
  }

  /**
   * @brief Initialize class with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  expected(::portable_stl::unexpected<t_other_error> &&error_value) noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::move(error_value.error())));
  }

  /**
   * @brief Inplace error constructor.
   *
   * @tparam t_args the arguments for error value construct.
   * @param args value constructor arguments.
   */
  template<class... t_args>
  expected(::portable_stl::unexpect_t,
           t_args &&...args) noexcept(::portable_stl::is_nothrow_constructible<error_type, t_args...>{}())
      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::forward<t_args>(args)...));
  }
  /**
   * @brief Inplace error constructor with initializer_list.
   *
   * @tparam t_list_value the types of initializer_list values.
   * @tparam t_args types of arguments.
   * @param
   * @param list_values values in initializer_list.
   * @param args value constructor arguments.
   */
  template<class t_list_value, class... t_args>
  explicit expected(
    ::portable_stl::unexpect_t,
    ::std::initializer_list<t_list_value> list_values,
    t_args &&...args) noexcept(::portable_stl::is_nothrow_constructible<error_type,
                                                                        ::portable_stl::initializer_list<t_list_value>,
                                                                        t_args...>{}())

      : m_storage_type(storage_state::error) {
    static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                   ::portable_stl::initializer_list<t_list_value>{list_values},
                                                   ::portable_stl::forward<t_args>(args)...));
  }

  /**
   * @brief Copy constructor expected object from the source expected object.
   * @param source the object for copy.
   */
  expected(expected const &source) noexcept(::portable_stl::is_nothrow_copy_constructible<error_type>{}())
      : m_storage_type(source.m_storage_type) {
    if (m_storage_type == storage_state::error) {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                     ::portable_stl::storage_for<error_type const>(source.m_storage)));
    }
  }

  /**
   * @brief Move constructor expected object from the source expected object.
   * @param source the object for move.
   */
  expected(expected &&source) noexcept(::portable_stl::is_nothrow_move_constructible<error_type>{}())
      : m_storage_type(source.m_storage_type) {
    if (m_storage_type == storage_state::error) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                     ::portable_stl::move(::portable_stl::storage_for<error_type>(source.m_storage))));
    }
  }

  /**
   * @brief Copy constructor expected object from the source expected object.
   * @tparam t_other_value the other expected object value parameter type.
   * @tparam t_other_error the other expected object error parameter type.
   * @param source the object for copy.
   */
  template<class t_other_value,
           class t_other_error,
           ::portable_stl::enable_if_bool_constant_t<can_construct_from_expected<t_other_value, t_other_error>, void *>
           = nullptr>
  expected(::portable_stl::expected<t_other_value, t_other_error> const &source) noexcept(
    (::portable_stl::is_nothrow_constructible<
      error_type,
      ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<t_other_error>>>{}()))
      : m_storage_type(source.has_value() ? storage_state::value : storage_state::error) {
    if (m_storage_type == storage_state::error) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage), source.error()));
    }
  }

  /**
   * @brief Move constructor expected object from the source expected object.
   * @tparam t_other_value the other expected object value parameter type.
   * @tparam t_other_error the other expected object error parameter type.
   * @param source the object for move.
   */
  template<class t_other_value,
           class t_other_error,
           ::portable_stl::enable_if_bool_constant_t<can_construct_from_expected<t_other_value, t_other_error>, void *>
           = nullptr>
  expected(::portable_stl::expected<t_other_value, t_other_error> &&source) noexcept(
    (::portable_stl::is_nothrow_constructible<error_type, ::portable_stl::add_rvalue_reference_t<t_other_error>>{}()))
      : m_storage_type(source.has_value() ? storage_state::value : storage_state::error) {
    if (m_storage_type == storage_state::error) {
      static_cast<void>(::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                                     ::portable_stl::move(source.error())));
    }
  }

  /**
   * @brief Swap this object and source object.
   * @param source the object for swap.
   */
  void swap_internal(expected &source) noexcept(::portable_stl::is_nothrow_move_constructible<error_type>{}()
                                                && ::portable_stl::is_nothrow_swappable<error_type>{}()) {
    if ((m_storage_type == storage_state::error) && (source.m_storage_type == storage_state::error)) {
      swap(::portable_stl::storage_for<error_type>(m_storage),
           ::portable_stl::storage_for<error_type>(source.m_storage));
    } else if (m_storage_type == storage_state::error) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(source.m_storage),
                                     ::portable_stl::move(::portable_stl::storage_for<error_type>(m_storage))));
      ::portable_stl::destroy_at(&::portable_stl::storage_for<error_type>(m_storage));
      swap(m_storage_type, source.m_storage_type);
    } else if (source.m_storage_type == storage_state::error) {
      static_cast<void>(
        ::portable_stl::construct_at(&::portable_stl::storage_for<error_type>(m_storage),
                                     ::portable_stl::move(::portable_stl::storage_for<error_type>(source.m_storage))));
      ::portable_stl::destroy_at(&::portable_stl::storage_for<error_type>(source.m_storage));
      swap(m_storage_type, source.m_storage_type);
    } else {
      // Nothing for two values.
    }
  }

  /**
   * @brief Copy assignment operator.
   *
   * @param source the source object.
   * @return reference to this object.
   */
  expected &operator=(expected const &source) & noexcept(::portable_stl::is_nothrow_copy_constructible<expected>{}()
                                                         && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    if (this != &source) {
      expected tmp{source};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Move assignment operator.
   *
   * @param source the source object.
   * @return reference to this object.
   */
  expected &operator=(expected &&source) & noexcept(
    ::portable_stl::is_nothrow_copy_constructible<expected>{}() && noexcept(this->swap_internal(*this))) {
    if (this != &source) {
      expected tmp{::portable_stl::move(source)};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Assignment object with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  inline expected &operator=(::portable_stl::unexpected<t_other_error> const &error_value) & noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{error_value};
    tmp.swap_internal(*this);
    return *this;
  }

  /**
   * @brief Assignment object with error value.
   *
   * @tparam t_other_error the type of error.
   * @param error_value object with error value.
   */
  template<class t_other_error>
  inline expected &operator=(::portable_stl::unexpected<t_other_error> &&error_value) & noexcept(
    ::portable_stl::is_nothrow_constructible<error_type, t_other_error &&>{}()
    && ::portable_stl::is_nothrow_swappable<expected>{}()) {
    expected tmp{::portable_stl::move(error_value)};
    tmp.swap_internal(*this);
    return *this;
  }

  /**
   * @brief Assignment in place value.
   */
  inline void emplace() noexcept(::portable_stl::is_nothrow_destructible<error_type>{}()) {
    if (m_storage_type == storage_state::error) {
      ::portable_stl::destroy_at(&::portable_stl::storage_for<error_type>(m_storage));
    }
    m_storage_type = storage_state::value;
  }

  /**
   * @brief Do nothing for void value.
   *
   */
  constexpr inline void operator*() const noexcept {
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the expected value.
   * @retval false is stored the unexpected value.
   */
  constexpr explicit operator bool() const noexcept {
    return has_value();
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the expected value.
   * @retval false is stored the unexpected value or undefined.
   */
  constexpr bool has_value() const noexcept {
    return (m_storage_type == storage_state::value);
  }

  /**
   * @brief get the flag what value is stored expected or unexpected.
   * @return the flag what value is stored expected or unexpected.
   * @retval true is stored the unexpected value.
   * @retval false is stored the expected value or undefined.
   */
  constexpr bool has_error() const noexcept {
    return (m_storage_type == storage_state::error);
  }

  /**
   * @brief Try get the expected value.
   *
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  void value() const & noexcept(noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
    !has_value(), ::portable_stl::storage_for<error_type const>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::storage_for<error_type const>(m_storage));
  }

  /**
   * @brief Try get the expected value.
   *
   * @throw bad_expected_access<error_type> if has_value is false.
   * @warning if exceptions disabled and has_value is false then behavior is undefined.
   */
  void value() && noexcept(noexcept(::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
    !has_value(), ::portable_stl::storage_for<error_type>(m_storage)))) {
    ::portable_stl::throw_on_true<::portable_stl::bad_expected_access<error_type>>(
      !has_value(), ::portable_stl::move(::portable_stl::storage_for<error_type>(m_storage)));
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  constexpr error_type const &error() const & noexcept {
    return ::portable_stl::storage_for<error_type const>(m_storage);
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  error_type &error() & noexcept {
    return ::portable_stl::storage_for<error_type>(m_storage);
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  constexpr error_type const &&error() const && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<error_type const>(m_storage));
  }

  /**
   * @brief Get the unexpected value.
   *
   * @return the unexpected value.
   * @warning if has_value is true then behavior is undefined.
   */
  error_type &&error() && noexcept {
    return ::portable_stl::move(::portable_stl::storage_for<error_type>(m_storage));
  }

  /**
   * @brief Get error or other
   *
   * @tparam t_other_error the type of other error.
   * @param other the other error.
   * @return error or other.
   * @retval error if object has error.
   * @retval other if object has value.
   */
  template<class t_other_error = error_type> error_type error_or(t_other_error &&other) const & {
    return (has_error() ? error() : static_cast<error_type>(::portable_stl::forward<t_other_error>(other)));
  }

  /**
   * @brief Get error or other
   *
   * @tparam t_other_error the type of other error.
   * @param other the other error.
   * @return error or other.
   * @retval error if object has error.
   * @retval other if object has value.
   */
  template<class t_other_error = error_type> error_type error_or(t_other_error &&other) && {
    return (has_error() ? error() : static_cast<error_type>(::portable_stl::forward<t_other_error>(other)));
  }

  /**
   * @brief Check equality this and other expected object.
   *
   * @tparam t_other_value type of other value.
   * @tparam t_other_error the type of other error.
   *
   * @param other the object for check equality.
   *
   * @return result of the checking.
   *
   * @retval true if objects is eqaul.
   * @retval false if objects is not eqaul.
   */
  template<class t_other_value, class t_other_error>
  bool is_equal(expected<t_other_value, t_other_error> const &other) const noexcept {
    if (has_value()) {
      return (other.has_value());
    } else {
      return (other.has_error() && (error() == other.error()));
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor, class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor>>>
  t_result and_then(t_functor &&functor) & noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor))) && noexcept(t_result{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor));
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor, class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor>>>
  t_result and_then(t_functor &&functor) && noexcept(noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(
    functor))) && noexcept(t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor));
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor, class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor>>>
  t_result and_then(t_functor &&functor) const & noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor))) && noexcept(t_result{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor));
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the result of the given function on the expected value if it exists; otherwise, returns the expected
   * itself. Run on value.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has value.
   * @return result of call functor or error if object has error.
   */
  template<class t_functor, class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor>>>
  t_result and_then(t_functor &&functor) const && noexcept(
    noexcept(::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))) && noexcept(
      t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor));
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) & noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), error())) && noexcept(t_result{::portable_stl::in_place_t{}})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error());
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) && noexcept(noexcept(
    ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                           ::portable_stl::move(error()))) && noexcept(t_result{::portable_stl::in_place_t{}})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()));
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) const & noexcept(noexcept(::portable_stl::invoke(
    ::portable_stl::forward<t_functor>(functor), error())) && noexcept(t_result{::portable_stl::in_place_t{}})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error());
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns the result of the given
   * function on the unexpected value. Run on error.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return result of call functor or value if object has value.
   */
  template<class t_functor,
           class t_result = ::portable_stl::remove_cvref_t<::portable_stl::invoke_result_t<t_functor, error_type>>>
  t_result or_else(t_functor &&functor) const && noexcept(noexcept(
    ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                           ::portable_stl::move(error()))) && noexcept(t_result{::portable_stl::in_place_t{}})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{}};
    } else {
      return ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()));
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) & noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) && noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) const & noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns an expected containing the transformed expected value if it exists; otherwise, returns the expected
   * itself. Value map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor>>,
           class t_result       = expected<t_result_value, error_type>>
  t_result transform(t_functor &&functor) const && noexcept(
    noexcept(t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))}) && noexcept(t_result{
      ::portable_stl::unexpect_t{}, ::portable_stl::move(error())})) {
    if (has_value()) {
      return t_result{::portable_stl::in_place_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor))};
    } else {
      return t_result{::portable_stl::unexpect_t{}, ::portable_stl::move(error())};
    }
  }

  /**
   * @brief returns an expected containing without value ( void on success ); otherwise, returns the expected
   * itself. Value map to void.
   *
   * @return the transformed expected value or itself on contain error.
   *
   */
  ::portable_stl::expected<void, error_type> transform_void() const
    noexcept(noexcept(::portable_stl::expected<void, error_type>{::portable_stl::unexpect_t{}, error()})) {
    if (has_value()) {
      return ::portable_stl::expected<void, error_type>{};
    } else {
      return ::portable_stl::expected<void, error_type>{::portable_stl::unexpect_t{}, error()};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<void, t_result_value>>
  t_result transform_error(t_functor &&functor) & noexcept(noexcept(
    t_result{::portable_stl::unexpect_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())}) && noexcept(t_result{})) {
    if (has_value()) {
      return t_result{};
    } else {
      return t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<void, t_result_value>>
  t_result transform_error(t_functor &&functor) && noexcept(
    noexcept(t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(error()))}) && noexcept(t_result{})) {
    if (has_value()) {
      return t_result{};
    } else {
      return t_result{
        ::portable_stl::unexpect_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<void, t_result_value>>
  t_result transform_error(t_functor &&functor) const & noexcept(noexcept(
    t_result{::portable_stl::unexpect_t{},
             ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())}) && noexcept(t_result{})) {
    if (has_value()) {
      return t_result{};
    } else {
      return t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), error())};
    }
  }

  /**
   * @brief returns the expected itself if it contains an expected value; otherwise, returns an expected containing the
   * transformed unexpected value. Error map.
   *
   * @tparam t_functor the type of functor.
   * @param functor the functor for call if object has error.
   * @return the transformed expected value or itsel on contain error.
   */
  template<class t_functor,
           class t_result_value = ::portable_stl::remove_cv_t<::portable_stl::invoke_result_t<t_functor, error_type>>,
           class t_result       = expected<void, t_result_value>>
  t_result transform_error(t_functor &&functor) const && noexcept(
    noexcept(t_result{::portable_stl::unexpect_t{},
                      ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor),
                                             ::portable_stl::move(error()))}) && noexcept(t_result{})) {
    if (has_value()) {
      return t_result{};
    } else {
      return t_result{
        ::portable_stl::unexpect_t{},
        ::portable_stl::invoke(::portable_stl::forward<t_functor>(functor), ::portable_stl::move(error()))};
    }
  }
};
} // namespace portable_stl

#endif // PSTL_EXPECTED_H
