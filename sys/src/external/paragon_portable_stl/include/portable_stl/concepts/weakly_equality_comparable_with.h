// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="weakly_equality_comparable_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_WEAKLY_EQUALITY_COMPARABLE_WITH_H
#define PSTL_WEAKLY_EQUALITY_COMPARABLE_WITH_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "boolean_testable.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief weakly_equality_comparable_with implementation.
   * Primary template.
   */
  template<class, class, class = void> class weakly_equality_comparable_with_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief weakly_equality_comparable_with implementation.
   * explicitly convert (decay_t<>) possible array and function type to pointer.
   *
   * @tparam t_type Tested type.
   * @tparam u_type Tested type.
   */
  template<class t_type, class u_type>
  class weakly_equality_comparable_with_impl<
    t_type,
    u_type,
    void_t<decltype(::portable_stl::declval<::portable_stl::decay_t<t_type &>>()
                    == ::portable_stl::declval<::portable_stl::decay_t<u_type &>>()),
           decltype(::portable_stl::declval<::portable_stl::decay_t<t_type &>>()
                    != ::portable_stl::declval<::portable_stl::decay_t<u_type &>>()),
           decltype(::portable_stl::declval<::portable_stl::decay_t<u_type &>>()
                    == ::portable_stl::declval<::portable_stl::decay_t<t_type &>>()),
           decltype(::portable_stl::declval<::portable_stl::decay_t<u_type &>>()
                    != ::portable_stl::declval<::portable_stl::decay_t<t_type &>>())>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<::portable_stl::decay_t<t_type &>>()
                                                == ::portable_stl::declval<::portable_stl::decay_t<u_type &>>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<::portable_stl::decay_t<t_type &>>()
                                                != ::portable_stl::declval<::portable_stl::decay_t<u_type &>>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<::portable_stl::decay_t<u_type &>>()
                                                == ::portable_stl::declval<::portable_stl::decay_t<t_type &>>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<::portable_stl::decay_t<u_type &>>()
                                                != ::portable_stl::declval<::portable_stl::decay_t<t_type &>>())>>;
  };
} // namespace concepts_helper

/**
 * @brief The exposition-only 'concept' __WeaklyEqualityComparableWith specifies that an object of type t_type and an
 * object of type u_type can be compared for equality with each other (in either order) using both == and !=, and the
 * results of the comparisons are consistent.
 *
 * @tparam t_type Tested type.
 * @tparam u_type Tested type.
 */
template<class t_type, class u_type>
using weakly_equality_comparable_with =
  typename concepts_helper::weakly_equality_comparable_with_impl<t_type, u_type>::type;
} // namespace portable_stl

#endif // PSTL_WEAKLY_EQUALITY_COMPARABLE_WITH_H
