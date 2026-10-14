// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_trivially_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRIVIALLY_CONSTRUCTIBLE_H
#define PSTL_IS_TRIVIALLY_CONSTRUCTIBLE_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace type_properties_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   * @tparam t_args Processed types.
   */
  template<class t_type, class... t_args> class is_trivially_constructible_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__is_trivially_constructible(t_type, t_args...)>;
  };
} // namespace type_properties_helper

/**
 * @brief Check t_type is a Trivially-constructible . ( Can construct with trivial function. )
 * @tparam t_type type for check.
 * @tparam ...t_args arguments for constructor.
 */
template<class t_type, class... t_args>
using is_trivially_constructible =
  typename type_properties_helper::is_trivially_constructible_wrapper<t_type, t_args...>::type;
} // namespace portable_stl

#endif // PSTL_IS_TRIVIALLY_CONSTRUCTIBLE_H
