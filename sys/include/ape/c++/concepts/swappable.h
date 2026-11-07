// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swappable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAPPABLE_H
#define PSTL_SWAPPABLE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "ranges_swap.h"

namespace std {
namespace concepts_helper {
  /**
   * @brief swappable implementation.
   * Primary template.
   */
  template<class, class = void> class swappable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief swappable implementation.
   * @tparam t_type Given type.
   */
  template<class t_type>
  class swappable_impl<t_type,
                       ::std::void_t<decltype(::std::ranges::swap2(
                         ::std::declval<t_type &>(), ::std::declval<t_type &>()))>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::true_type;
  };
} // namespace concepts_helper

/**
 * @brief The 'concept' swappable<t_type> specifies that lvalues of type t_type are swappable.
 * @tparam t_type Tested type.
 */
template<class t_type> using swappable = typename ::std::concepts_helper::swappable_impl<t_type>::type;
} // namespace std

#endif /* PSTL_SWAPPABLE_H */
