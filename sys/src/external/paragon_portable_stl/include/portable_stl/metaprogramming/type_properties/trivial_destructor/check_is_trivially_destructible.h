// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="check_is_trivially_destructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CHECK_IS_TRIVIALLY_DESTRUCTIBLE_H
#define PSTL_CHECK_IS_TRIVIALLY_DESTRUCTIBLE_H

#include "../../helper/integral_constant.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   */
  template<class t_type> class is_trivially_destructible_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__has_trivial_destructor(t_type)>;
  };

  /**
   * @brief Check t_type is a Trivially-destructible . ( Can destroy by free like functions. )
   * @tparam t_type type for check.
   */
  template<class t_type>
  using check_is_trivially_destructible = typename is_trivially_destructible_wrapper<t_type>::type;

} // namespace type_properties_helpers

} // namespace portable_stl

#endif // PSTL_CHECK_IS_TRIVIALLY_DESTRUCTIBLE_H
