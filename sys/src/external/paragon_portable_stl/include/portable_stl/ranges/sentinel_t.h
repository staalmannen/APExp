// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="sentinel_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SENTINEL_T_H
#define PSTL_SENTINEL_T_H

#include "../utility/general/declval.h"
#include "end.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief Used to obtain the associated sentinel type of a range_type.
   * @tparam range_type Given type.
   */
  template<class range_type>
  using sentinel_t = decltype(::portable_stl::ranges::end(::portable_stl::declval<range_type &>()));

  namespace ranges_helper {
    /**
     * @brief Helper to check if ranges::sentinel_t can be inferenced for t_type.
     * Primary template.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = void> class has_sentinel_t_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class T1>
      static auto test(::portable_stl::size_t arg) -> decltype(::portable_stl::ranges::sentinel_t<T1>(),
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

    /**
     * @brief Helper to check if sentinel_t could be inferenced.
     * To safe use (msvc) in classes that use sentinel_t<>.
     * @tparam t_type Given type.
     */
    template<class t_type> using has_sentinel_t = typename has_sentinel_t_impl<t_type>::type;
  } // namespace ranges_helper
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_SENTINEL_T_H */
