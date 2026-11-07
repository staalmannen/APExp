// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITERATOR_T_H
#define PSTL_ITERATOR_T_H

#include "../utility/general/declval.h"
#include "begin.h"

namespace std {
namespace ranges {
  /**
   * @brief Used to obtain the associated iterator type of a t_type.
   * @tparam t_type Given type.
   */
  template<class t_type>
  using iterator_t = decltype(::std::ranges::begin(::std::declval<t_type &>()));

  namespace ranges_helper {
    /**
     * @brief Helper to check if ranges::iterator_t can be inferenced for t_type.
     * Primary template.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = void> class has_iterator_t_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param arg
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(::std::size_t arg) -> decltype(::std::ranges::iterator_t<T1>(),
                                                               ::std::true_type{});

      /**
       * @brief Test function.
       * @tparam T1
       * @return ::std::false_type
       */
      template<class T1> static auto test(...) -> ::std::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(0));
    };

    /**
     * @brief Helper to check if iterator_t could be inferenced.
     * To safe use (msvc) in classes that use iterator_t<>.
     * @tparam t_type Given type.
     */
    template<class t_type> using has_iterator_t = typename has_iterator_t_impl<t_type>::type;
  } // namespace ranges_helper
} // namespace ranges
} // namespace std

#endif /* PSTL_ITERATOR_T_H */
