// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_polymorphic.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_POLYMORPHIC_H
#define PSTL_IS_POLYMORPHIC_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace type_properties_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   */
  template<class t_type> class is_polymorphic_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__is_polymorphic(t_type)>;
  };
} // namespace type_properties_helper

/**
 * @brief t_type is a polymorphic class type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> using is_polymorphic = typename type_properties_helper::is_polymorphic_wrapper<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_POLYMORPHIC_H
