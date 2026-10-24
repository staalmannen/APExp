// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_const.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONST_H
#define PSTL_IS_CONST_H

#include "../helper/integral_constant.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief t_type is const-qualified.
   * t_type is not const-qualified implementation.
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_const final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is const-qualified.
   * t_type is const-qualified implementation.
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_const<t_type const> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return true.
     */
    using type = ::portable_stl::true_type;
  };
} // namespace type_properties_helpers

/**
 * @brief t_type is const-qualified.
 * @tparam t_type the type for check.
 */
template<class t_type> using is_const = typename ::portable_stl::type_properties_helpers::is_const<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_CONST_H
