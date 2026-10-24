// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_rvalue_referenceable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_RVALUE_REFERENCEABLE_H
#define PSTL_IS_RVALUE_REFERENCEABLE_H

#include "../../common/size_t.h"
#include "../helper/integral_constant.h"
#include "../other_transformations/void_t.h"

namespace portable_stl {
namespace metaprogramming_type_properties_helper {
  /**
   * @brief Check type is rvalue referenceable
   * Non-referenceable type implementation.
   */
  template<class t_type, class = void> class is_rvalue_referenceable final {
  public:
    /**
     * @brief Value getter.
     *
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Check type is rvalue referenceable
   * Referenceable type implementation.
   */
  template<class t_type> class is_rvalue_referenceable<t_type, ::portable_stl::void_t<t_type &&>> final {
  public:
    /**
     * @brief Value getter.
     *
     */
    using type = ::portable_stl::true_type;
  };
} // namespace metaprogramming_type_properties_helper

/**
 * @brief Check type is rvalue referenceable
 *
 * @tparam t_type type for check.
 */
template<class t_type>
using is_rvalue_referenceable = typename metaprogramming_type_properties_helper::is_rvalue_referenceable<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_RVALUE_REFERENCEABLE_H
