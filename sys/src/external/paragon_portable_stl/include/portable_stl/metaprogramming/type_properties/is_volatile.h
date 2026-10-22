// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_volatile.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_VOLATILE_H
#define PSTL_IS_VOLATILE_H

#include "../helper/integral_constant.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief t_type is volatile-qualified.
   * t_type is not volatile-qualified implementation.
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_volatile final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is volatile-qualified.
   * t_type is volatile-qualified implementation.
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_volatile<t_type volatile> final {
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
 * @brief t_type is volatile-qualified.
 * @tparam t_type the type for check.
 */
template<class t_type> using is_volatile = typename ::portable_stl::type_properties_helpers::is_volatile<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_VOLATILE_H
