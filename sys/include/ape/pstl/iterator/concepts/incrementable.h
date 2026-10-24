// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="incrementable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INCREMENTABLE_H
#define PSTL_INCREMENTABLE_H

#include "../../concepts/regular.h"
#include "../../concepts/same_as.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "weakly_incrementable.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief incrementable implementation.
   * Primary template.
   */
  template<class, class = void> class incrementable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  // todo(plotitcin): check operator++() && or &
  /**
   * @brief incrementable implementation.
   * @tparam iterator_t Given type.
   */
  template<class iterator_t>
  class incrementable_impl<iterator_t, ::portable_stl::void_t<decltype(::portable_stl::declval<iterator_t &>()++)>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::regular<iterator_t>,
      ::portable_stl::weakly_incrementable<iterator_t>,
      ::portable_stl::same_as<iterator_t, decltype(::portable_stl::declval<iterator_t &>()++)>>;
  };
} // namespace concepts_helper

/**
 * @brief This 'concept' specifies requirements on types that can be incremented with the pre- and post-increment
 * operators, whose increment operations are equality-preserving, and the type is equality_comparable. Unlike with
 * weakly_incrementable, which only support single-pass algorithms, multi-pass one-directional algorithms can be
 * used with types that model incrementable.
 *
 * @tparam iterator_t Given type.
 */
template<class iterator_t> using incrementable = typename concepts_helper::incrementable_impl<iterator_t>::type;

} // namespace portable_stl

#endif /* PSTL_INCREMENTABLE_H */
