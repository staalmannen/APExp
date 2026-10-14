// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_swappable_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_SWAPPABLE_WITH_H
#define PSTL_IS_NOTHROW_SWAPPABLE_WITH_H

#include "../helper/integral_constant.h"
#include "is_swappable_with.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
   * and swap(declval<t_other_type>(), declval<t_type>()) is valid without exceptions.
   * Swap function exist.
   *
   * @tparam t_type one type for check.
   * @tparam t_other_type other type for check.
   */
  template<class t_type, class t_other_type, class = ::portable_stl::is_swappable_with<t_type, t_other_type>>
  class is_nothrow_swappable_with final {
  public:
    /**
     * @brief Result value.
     */
    constexpr static bool const value{
      noexcept(swap(::portable_stl::declval<t_type>(), ::portable_stl::declval<t_other_type>())) && noexcept(
        swap(::portable_stl::declval<t_other_type>(), ::portable_stl::declval<t_type>()))};
  };

  /**
   * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
   * and swap(declval<t_other_type>(), declval<t_type>()) is valid without exceptions.
   * Swap function not exist.
   *
   * @tparam t_type one type for check.
   * @tparam t_other_type other type for check.
   */
  template<class t_type, class t_other_type>
  class is_nothrow_swappable_with<t_type, t_other_type, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result value.
     *
     */
    constexpr static bool const value{false};
  };

} // namespace type_properties_helpers

/**
 * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
 * and swap(declval<t_other_type>(), declval<t_type>()) is valid without exceptions.
 *
 * @tparam t_type one type for check.
 * @tparam t_other_type other type for check.
 */
template<class t_type, class t_other_type>
using is_nothrow_swappable_with = ::portable_stl::bool_constant<
  ::portable_stl::type_properties_helpers::is_nothrow_swappable_with<t_type, t_other_type>::value>;

} // namespace portable_stl

#endif /* PSTL_IS_NOTHROW_SWAPPABLE_WITH_H */
