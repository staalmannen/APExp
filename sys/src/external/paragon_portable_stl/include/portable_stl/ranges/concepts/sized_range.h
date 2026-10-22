// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="sized_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SIZED_RANGE_H
#define PSTL_SIZED_RANGE_H

#include "../../common/size_t.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/disjunction.h"
#include "../../utility/general/declval.h"
#include "../size.h"
#include "range.h"

namespace portable_stl {
namespace ranges {
  namespace ranges_helper {
    /**
     * @brief Helper to check if ranges::size can be calculated for t_type.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_size final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class T1>
      static auto test(
        ::portable_stl::size_t arg) -> decltype(::portable_stl::ranges::size(::portable_stl::declval<T1 &>()),
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
   * @brief The sized_range 'concept' specifies the requirements of a range type that knows its size in constant time
   * with the size function.
   *
   * @tparam range_type Tested range type.
   */
  template<class range_type>
  using sized_range = ::portable_stl::conjunction<::portable_stl::ranges::range<t_type>,
                                                  typename ranges_helper::has_size<t_type>::type>;

} // namespace ranges
} // namespace portable_stl

/*

template< class T >
concept sized_range = ranges::range<T> &&
    requires(T& t) {
        ranges::size(t);
    };

*/

#endif /* PSTL_SIZED_RANGE_H */
