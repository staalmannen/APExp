// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_enum.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ENUM_H
#define PSTL_IS_ENUM_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace primary_type_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   */
  template<class t_type> class is_enum_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__is_enum(t_type)>;
  };
} // namespace primary_type_helper

/**
 * @brief t_type is an enumeration struct is_enum type.
 *
 * @tparam t_type the type for check.
 */
template<class t_type> using is_enum = typename primary_type_helper::is_enum_wrapper<t_type>::type;

} // namespace portable_stl

#endif // PSTL_IS_ENUM_H
