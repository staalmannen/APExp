// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_HELPER_H
#define PSTL_TUPLE_HELPER_H

namespace portable_stl {
namespace tuple_helper {

  /**
   * @brief is_specialization implementation.
   * Primary template.
   * @tparam t_type Given type.
   * @tparam t_template Given template class.
   */
  template<class t_type, template<class...> class t_template> class is_specialization_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief is_specialization implementation.
   *
   * @tparam t_template Given template class.
   * @tparam t_types Some types.
   */
  template<template<class...> class t_template, class... t_types>
  class is_specialization_impl<t_template<t_types...>, t_template> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper to check if t_type == t_template<t_types...>
   *
   * @tparam t_type Given type.
   * @tparam t_template Given template class.
   */
  template<class t_type, template<class...> class t_template>
  using is_specialization = typename is_specialization_impl<t_type, t_template>::type;

  /**
   * @brief Helper to check tags.
   * @tparam t_tag_type_expected Expected tag.
   * @tparam t_tag_type Actual tag.
   */
  template<class t_tag_type_expected, class t_tag_type>
  using enable_if_tag_t
    = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_same<t_tag_type, t_tag_type_expected>, void *>;

  /**
   * @brief ignore implementation.
   */
  class ignore_impl final { // struct that ignores assignments
  public:
    constexpr ignore_impl() = default;
    /**
     * @brief Construct a new ignore impl object
     */
    ignore_impl(ignore_impl const &)              = default;
    /**
     * @brief Copy assignment operator.
     * @return ignore_impl&
     */
    ignore_impl &operator=(ignore_impl const &) & = default;

    /**
     * @brief Copy assignment operator.
     *
     * @tparam t_type
     * @return constexpr ignore_impl const&
     */
    template<class t_type> constexpr ignore_impl const &operator=(t_type const &) const & noexcept /* strengthened */ {
      // do nothing
      return *this;
    }
  };

  /**
   * @brief Tag type to disambiguate construction (from one arg per element).
   */
  class exact_args_t final {
  public:
    /**
     * @brief Default ctor.
     */
    explicit exact_args_t() = default;
  };

  /**
   * @brief Tag type to disambiguate construction (from unpacking a tuple/pair).
   */
  class unpack_tuple_t final {
  public:
    /**
     * @brief Default ctor.
     */
    explicit unpack_tuple_t() = default;
  };

  /**
   * @brief Tag type to disambiguate construction (from an allocator and one arg per element).
   */
  class alloc_exact_args_t final {
  public:
    /**
     * @brief Default ctor.
     */
    explicit alloc_exact_args_t() = default;
  };

  /**
   * @brief Tag type to disambiguate construction (from an allocator and unpacking a tuple/pair).
   */
  class alloc_unpack_tuple_t final {
  public:
    /**
     * @brief Default ctor.
     */
    explicit alloc_unpack_tuple_t() = default;
  };

} // namespace tuple_helper

/**
 * @brief Placeholder to skip an element when unpacking a tuple using tie.
 * was inline
 */
constexpr tuple_helper::ignore_impl ignore{};
} // namespace portable_stl

#endif /* PSTL_TUPLE_HELPER_H */
