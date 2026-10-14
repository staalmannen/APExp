// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_swappable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_SWAPPABLE_H
#define PSTL_INDIRECTLY_SWAPPABLE_H

#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../iter_swap.h"
#include "indirectly_readable.h"

namespace portable_stl {

namespace iterator_helper {
  /**
   * @brief indirectly_swappable 'concept' implementation.
   *
   * @tparam t_iterator1 Given iterator type.
   * @tparam t_iterator2 Given iterator type.
   */
  template<class t_iterator1, class t_iterator2> class indirectly_swappable_impl final {
    /**
     * @brief Helper class to check if adl iter_swap function could be called.
     * @tparam I1 Given iterator type.
     * @tparam I2 Given iterator type.
     * @param iter1
     * @param iter2
     * @return ::portable_stl::true_type
     */
    template<class I1, class I2>
    static auto test(I1 const iter1, I2 const iter2)
      -> decltype(::portable_stl::ranges::iter_swap2(iter1, iter2), ::portable_stl::true_type{});

    /**
     * @brief
     * @tparam I1 Given iterator type.
     * @tparam I2 Given iterator type.
     * @return ::portable_stl::false_type
     */
    template<class I1, class I2> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type
      = ::portable_stl::conjunction<::portable_stl::indirectly_readable<t_iterator1>,
                                    ::portable_stl::indirectly_readable<t_iterator2>,
                                    decltype(test<t_iterator1, t_iterator1>(::portable_stl::declval<t_iterator1>(),
                                                                            ::portable_stl::declval<t_iterator1>())),
                                    decltype(test<t_iterator1, t_iterator2>(::portable_stl::declval<t_iterator1>(),
                                                                            ::portable_stl::declval<t_iterator2>())),
                                    decltype(test<t_iterator2, t_iterator1>(::portable_stl::declval<t_iterator2>(),
                                                                            ::portable_stl::declval<t_iterator1>())),
                                    decltype(test<t_iterator2, t_iterator2>(::portable_stl::declval<t_iterator2>(),
                                                                            ::portable_stl::declval<t_iterator2>()))>;
  };
} // namespace iterator_helper

/**
 * @brief The 'concept' indirectly_swappable specifies a relationship between two types respectively modelling
 * indirectly_readable, where their referenced types can be swapped.
 *
 * @tparam t_iterator1 Given iterator type.
 * @tparam t_iterator2 Given iterator type.
 */
template<class t_iterator1, class t_iterator2 = t_iterator1>
using indirectly_swappable =
  typename ::portable_stl::iterator_helper::indirectly_swappable_impl<t_iterator1, t_iterator2>::type;
} // namespace portable_stl

#endif /* PSTL_INDIRECTLY_SWAPPABLE_H */
