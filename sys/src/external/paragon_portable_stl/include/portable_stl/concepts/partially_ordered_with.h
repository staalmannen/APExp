// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="partially_ordered_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PARTIALLY_ORDERED_WITH_H
#define PSTL_PARTIALLY_ORDERED_WITH_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../utility/general/declval.h"
#include "boolean_testable.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief Helper to check if comparison operations are available.
   *
   * @tparam t_type Given type.
   * @tparam u_type Given type.
   */
  template<class t_type, class u_type> class has_comparison_operations final {
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @return ::portable_stl::true_type
     */
    template<class T1, class T2>
    static auto test(::portable_stl::size_t)
      -> decltype(portable_stl::declval<T1 const &>() < portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T1 const &>() > portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T1 const &>() <= portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T1 const &>() >= portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T2 const &>() < portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T2 const &>() > portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T2 const &>() <= portable_stl::declval<T2 const &>(),
                  portable_stl::declval<T2 const &>() >= portable_stl::declval<T2 const &>(),
                  ::portable_stl::true_type{});
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @return ::portable_stl::false_type
     */
    template<class T1, class T2> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type
      = decltype(test<::portable_stl::remove_reference_t<t_type>, ::portable_stl::remove_reference_t<u_type>>(0U));
  };

  /**
   * @brief partially_ordered_with 'concept' implementation.
   * @tparam t_type Given type.
   * @tparam u_type Given type.
   */
  template<class t_type, class u_type, class = typename has_comparison_operations<t_type, u_type>::type>
  class partially_ordered_with_impl final {
    /**
     * @brief Medium test type.
     */
    using T1 = ::portable_stl::remove_reference_t<t_type>;
    /**
     * @brief Medium test type.
     */
    using T2 = ::portable_stl::remove_reference_t<u_type>;

  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      // clang-format off
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T1 &>() <  ::portable_stl::declval<T2 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T1 &>() >  ::portable_stl::declval<T2 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T1 &>() <= ::portable_stl::declval<T2 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T1 &>() >= ::portable_stl::declval<T2 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T2 &>() <  ::portable_stl::declval<T1 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T2 &>() >  ::portable_stl::declval<T1 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T2 &>() <= ::portable_stl::declval<T1 &>())>,
      ::portable_stl::boolean_testable<decltype(::portable_stl::declval<T2 &>() >= ::portable_stl::declval<T1 &>())>
      // clang-format on
      >;
  };

  /**
   * @brief partially_ordered_with 'concept' implementation.
   * Negative result.
   * @tparam t_type Given type.
   * @tparam u_type Given type.
   */
  template<class t_type, class u_type>
  class partially_ordered_with_impl<t_type, u_type, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace concepts_helper

/**
 * @brief The exposition-only 'concept' partially_ordered_with specifies that a value of type t_type and a value of type
 * u_type can be compared in a partial order with each other (in either order) using <, >, <=, and >=, and the results
 * of the comparisons are consistent.
 *
 * @tparam t_type Given type.
 * @tparam u_type Given type.
 */
template<class t_type, class u_type>
using partially_ordered_with = typename concepts_helper::partially_ordered_with_impl<t_type, u_type>::type;
} // namespace portable_stl

#endif /* PSTL_PARTIALLY_ORDERED_WITH_H */
