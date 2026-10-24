// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_trivially_assignable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRIVIALLY_ASSIGNABLE_H
#define PSTL_IS_TRIVIALLY_ASSIGNABLE_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace type_properties_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   * @tparam t_arg Processed types.
   */
  template<class t_type, class t_arg> class is_trivially_assignable_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__is_trivially_assignable(t_type, t_arg)>;
  };
} // namespace type_properties_helper

/**
 * @brief Check t_type is a Trivially-assignable . ( Can assign with trivial function. )
 * @tparam t_type type for check.
 * @tparam t_arg argument for assign.
 */
template<class t_type, class t_arg>
using is_trivially_assignable = typename type_properties_helper::is_trivially_assignable_wrapper<t_type, t_arg>::type;
} // namespace portable_stl

#endif // PSTL_IS_TRIVIALLY_ASSIGNABLE_H
