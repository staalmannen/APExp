// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="boolean_testable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BOOLEAN_TESTABLE_H
#define PSTL_BOOLEAN_TESTABLE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "convertible_to.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief Helper check class;
   * @tparam t_type Tested type.
   */
  template<class t_type> using is_bool_type = ::portable_stl::convertible_to<t_type, bool>;

  /**
   * @brief boolean_testable implementation.
   * Primary template.
   */
  template<class, class = void> class boolean_testable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief boolean_testable implementation.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class boolean_testable_impl<t_type, ::portable_stl::void_t<decltype(!declval<t_type>())>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<is_bool_type<t_type>, is_bool_type<decltype(!declval<t_type>())>>;
  };
} // namespace concepts_helper

/**
 * @brief The exposition-only 'concept' boolean-testable specifies the requirements for expressions that are convertible
 * to bool and for which the logical operators have the usual behavior (including short-circuiting), even for two
 * different boolean-testable types.
 *
 * @tparam t_type Tested type.
 */
template<class t_type> using boolean_testable = typename concepts_helper::boolean_testable_impl<t_type>::type;

} // namespace portable_stl

#endif /* PSTL_BOOLEAN_TESTABLE_H */
