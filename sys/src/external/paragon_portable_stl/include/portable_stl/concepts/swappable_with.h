// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swappable_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAPPABLE_WITH_H
#define PSTL_SWAPPABLE_WITH_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "common_reference_with.h"
#include "ranges_swap.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief swappable_with 'concept' implementation.
   *
   * @tparam t_type Tested type.
   * @tparam u_type Tested type.
   */
  template<class t_type, class u_type> class swappable_with_impl final {
    /**
     * @brief Test to call ranges::swap2.
     * @param t1_value
     * @param t2_value
     * @return true_type
     */
    template<class T1, class T2>
    static auto test(T1 &&t1_value, T2 &&t2_value)
      -> decltype(::portable_stl::ranges::swap2(::portable_stl::forward<T1>(t1_value),
                                                ::portable_stl::forward<T2>(t2_value)),
                  ::portable_stl::true_type{});

    /**
     * @brief
     * @tparam T1
     * @tparam T2
     * @return false_type
     */
    template<class T1, class T2> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::common_reference_with<t_type, u_type>,
      decltype(test<t_type, t_type>(::portable_stl::declval<t_type>(), ::portable_stl::declval<t_type>())),
      decltype(test<u_type, u_type>(::portable_stl::declval<u_type>(), ::portable_stl::declval<u_type>())),
      decltype(test<t_type, u_type>(::portable_stl::declval<t_type>(), ::portable_stl::declval<u_type>())),
      decltype(test<u_type, t_type>(::portable_stl::declval<u_type>(), ::portable_stl::declval<t_type>()))>;
  };
} // namespace concepts_helper

/**
 * @brief The 'concept' swappable_with<T, U> specifies that expressions of the type and value category encoded by T and
 * U are swappable with each other.
 * @tparam t_type Tested type.
 * @tparam u_type Tested type.
 */
template<class t_type, class u_type>
using swappable_with = typename concepts_helper::swappable_with_impl<t_type, u_type>::type;
} // namespace portable_stl

#endif /* PSTL_SWAPPABLE_WITH_H */
