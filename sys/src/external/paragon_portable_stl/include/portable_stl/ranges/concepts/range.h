// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGE_H
#define PSTL_RANGE_H

#include "../../common/size_t.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../begin.h"
#include "../end.h"

namespace portable_stl {
namespace ranges {
  namespace ranges_helper {
    /**
     * @brief Helper to check if ranges::begin and ranges::end can be calculated for t_type.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_begin_end final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class T1>
      static auto test(
        ::portable_stl::size_t arg) -> decltype(::portable_stl::ranges::begin(::portable_stl::declval<T1 &>()),
                                                ::portable_stl::ranges::end(::portable_stl::declval<T1 &>()),
                                                ::portable_stl::true_type{});

      /**
       * @brief Test function.
       * @tparam T1
       * @return ::portable_stl::false_type
       */
      template<class T1> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(0));
    };
  } // namespace ranges_helper

  /**
   * @brief The range 'concept' defines the requirements of a type that allows iteration over its elements by providing
   * an iterator and sentinel that denote the elements of the range.
   * @tparam t_type
   */
  template<class t_type> using range = typename ranges_helper::has_begin_end<t_type>::type;
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_RANGE_H */
