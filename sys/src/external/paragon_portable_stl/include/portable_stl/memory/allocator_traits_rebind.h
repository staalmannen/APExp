// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_traits_rebind.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_TRAITS_REBIND_H
#define PSTL_ALLOCATOR_TRAITS_REBIND_H
namespace portable_stl {
namespace allocator_helper {
  /**
   * @brief Helper to check if type has rebind<t_other_type> alias.
   *
   * @tparam t_type
   * @tparam t_other_type
   */
  template<class t_type, class t_other_type, class = void> class has_rebind_other final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

/**
 * @brief Helper to check if type has rebind<t_other_type> alias.
 *
 * @tparam t_type
 * @tparam t_other_type
 */
  template<class t_type, class t_other_type>
  class has_rebind_other<t_type,
                         t_other_type,
                         ::portable_stl::void_t<typename t_type::template rebind<t_other_type>::other>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };
} // namespace allocator_helper

/**
 * @brief Get allocator type for t_other_type.
 * Primary template.
 * @tparam t_type
 * @tparam t_other_type
 * @tparam allocator_helper::has_rebind_other<t_type, t_other_type>::type
 */
template<class t_type,
         class t_other_type,
         class = typename allocator_helper::has_rebind_other<t_type, t_other_type>::type>
class allocator_traits_rebind final {
  static_assert(typename allocator_helper::has_rebind_other<t_type, t_other_type>::type{}(),
                "This allocator has to implement rebind");

public:
  /**
   * @brief Result type.
   */
  using type = typename t_type::template rebind<t_other_type>::other;
};

/**
 * @brief Get allocator type for t_other_type.
 *
 * @tparam t_allocator The type of allocator.
 * @tparam t_type The type of current allocator allocate.
 * @tparam ...t_args The extended types of allocator
 * @tparam t_other_type The desire type for allocate.
 */
template<template<class, class...> class t_allocator, class t_type, class... t_args, class t_other_type>
class allocator_traits_rebind<t_allocator<t_type, t_args...>, t_other_type, ::portable_stl::true_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_allocator<t_type, t_args...>::template rebind<t_other_type>::other;
};

/**
 * @brief Get allocator type for t_other_type.
 *
 * @tparam t_allocator The type of allocator.
 * @tparam t_type The type of current allocator allocate.
 * @tparam ...t_args The extended types of allocator
 * @tparam t_other_type The desire type for allocate.
 */
template<template<class, class...> class t_allocator, class t_type, class... t_args, class t_other_type>
class allocator_traits_rebind<t_allocator<t_type, t_args...>, t_other_type, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = t_allocator<t_other_type, t_args...>;
};

} // namespace portable_stl

#endif // PSTL_ALLOCATOR_TRAITS_REBIND_H
