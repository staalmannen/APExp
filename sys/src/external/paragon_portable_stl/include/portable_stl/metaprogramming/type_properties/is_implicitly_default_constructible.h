// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_implicitly_default_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_IMPLICITLY_DEFAULT_CONSTRUCTIBLE_H
#define PSTL_IS_IMPLICITLY_DEFAULT_CONSTRUCTIBLE_H

#include "../helper/integral_constant.h"
#include "is_default_constructible.h"

namespace portable_stl {
namespace type_properties_helper {
  /**
   * @brief First of all, we can't implement this check in C++03 mode because the {} default initialization syntax isn't
   * valid. Second, we implement the trait in a funny manner with two defaulted template arguments to workaround Clang's
   * PR43454.
   *
   * @tparam t_type Given type.
   */
  template<class t_type> void test_implicit_default_constructible(t_type);

  /**
   * @brief is_implicitly_default_constructible implementation.
   * Primary template.
   * @tparam t_type Given type.
   */
  template<class t_type, class = void, class = typename is_default_constructible<t_type>::type>
  class is_implicitly_default_constructible_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief is_implicitly_default_constructible implementation.
   *
   * @tparam t_type Given type.
   */
  template<class t_type>
  class is_implicitly_default_constructible_impl<t_type,
                                                 decltype(test_implicit_default_constructible<t_type const &>({})),
                                                 ::portable_stl::true_type>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief is_implicitly_default_constructible implementation.
   *
   * @tparam t_type Given type.
   */
  template<class t_type>
  class is_implicitly_default_constructible_impl<t_type,
                                                 decltype(test_implicit_default_constructible<t_type const &>({})),
                                                 ::portable_stl::false_type>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace type_properties_helper

/**
 * @brief Check t_type is a implicitly constructible without argumetns.
 *
 * @tparam t_type Given type.
 */
template<class t_type>
using is_implicitly_default_constructible =
  typename type_properties_helper::is_implicitly_default_constructible_impl<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_IS_IMPLICITLY_DEFAULT_CONSTRUCTIBLE_H */
