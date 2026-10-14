// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_core_convertible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CORE_CONVERTIBLE_H
#define PSTL_IS_CORE_CONVERTIBLE_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace type_traits_helper {
  /**
   * @brief is_core_convertible implemenation.
   * Primary template.
   *
   * @tparam t_type
   * @tparam t_other_type
   */
  template<class t_type, class t_other_type, class = void> class is_core_convertible_impl final {
  public:
    /**
     * @brief Result type.
     *
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief is_core_convertible implemenation.
   *
   * @tparam t_type
   * @tparam t_other_type
   */
  template<class t_type, class t_other_type>
  class is_core_convertible_impl<t_type,
                                 t_other_type,
                                 decltype(static_cast<void (*)(t_other_type)>(0)(static_cast<t_type (*)()>(0)()))>
    final {
  public:
    /**
     * @brief Result type.
     *
     */
    using type = ::portable_stl::true_type;
  };
} // namespace type_traits_helper

/**
 * @brief [conv.general]/3 says "E can be implicitly converted to a type T" whenever "T t=E;" is well-formed.
 * We can't test for that, but we can test implicit convertibility by passing it to a function. Notice that
 * is_core_convertible<void, void> is false, and is_core_convertible<immovable-type, immovable-type> is true in C++17 and
 * later.
 * @tparam t_type
 * @tparam t_other_type
 */
template<class t_type, class t_other_type>
using is_core_convertible = typename type_traits_helper::is_core_convertible_impl<t_type, t_other_type>::type;

} // namespace portable_stl
#endif // PSTL_IS_CORE_CONVERTIBLE_H
