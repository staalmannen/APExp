// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="sized_sentinel_for.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SIZED_SENTINEL_FOR_H
#define PSTL_SIZED_SENTINEL_FOR_H

#include "../../concepts/same_as.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../utility/general/declval.h"
#include "../incrementable_traits.h"
#include "sentinel_for.h"

namespace std {

/**
 * @brief Customization place.
 * @tparam sentinel_t
 * @tparam iterator_t
 */
template<class sentinel_t, class iterator_t> class disable_sized_sentinel_for_impl final {
public:
  /**
   * @brief Result type.
   */
  using type = ::std::false_type;
};

/**
 * @brief Customization place.
 * Instead of: template < class S, class I > inline constexpr bool disable_sized_sentinel_for = false;
 * @tparam sentinel_t
 * @tparam iterator_t
 */
template<class sentinel_t, class iterator_t>
using disable_sized_sentinel_for = typename disable_sized_sentinel_for_impl<sentinel_t, iterator_t>::type;

namespace iterator_helper {
  /**
   * @brief Check if types can be subtracted.
   * @tparam sentinel_t Sentinel type.
   * @tparam iterator_t Iterator type.
   */
  template<class sentinel_t, class iterator_t> class subtracted final {
  public:
    /**
     * @brief Positive test function
     * @tparam T1
     * @tparam T2
     * @param arg1
     * @return ::std::true_type
     */
    template<class T1, class T2>
    static auto test(::std::size_t arg1)
      -> decltype(::std::declval<T1 const &>() - ::std::declval<T2 const &>(),
                  ::std::declval<T2 const &>() - ::std::declval<T1 const &>(),
                  ::std::true_type{});

    /**
     * @brief Negative test function
     * @tparam T1
     * @tparam T2
     * @return ::std::true_type
     */
    template<class T1, class T2> static auto test(...) -> ::std::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<sentinel_t, iterator_t>(0));
  };

  /**
   * @brief sized_sentinel_for 'concept' inlpementatoin.
   * Types can be subtracted.
   * @tparam sentinel_t Sentinel type.
   * @tparam iterator_t Iterator type.
   */
  template<class sentinel_t, class iterator_t, class = typename subtracted<sentinel_t, iterator_t>::type>
  class sized_sentinel_for_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::conjunction<
      ::std::sentinel_for<sentinel_t, iterator_t>,
      ::std::negation<::std::disable_sized_sentinel_for<::std::remove_cvref_t<sentinel_t>,
                                                                          ::std::remove_cvref_t<iterator_t>>>,
      ::std::same_as<decltype(declval<sentinel_t const &>() - declval<iterator_t const &>()),
                              ::std::iter_difference_t<iterator_t>>,
      ::std::same_as<decltype(declval<iterator_t const &>() - declval<sentinel_t const &>()),
                              ::std::iter_difference_t<iterator_t>>>;
  };

  /**
   * @brief sized_sentinel_for 'concept' inlpementatoin.
   * Types can not be subtracted.
   * @tparam sentinel_t Sentinel type.
   * @tparam iterator_t Iterator type.
   */
  template<class sentinel_t, class iterator_t>
  class sized_sentinel_for_impl<sentinel_t, iterator_t, ::std::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };
} // namespace iterator_helper

/**
 * @brief The sized_sentinel_for 'concept' specifies that an object of the iterator type iterator_t and an object of the
 * sentinel type sentinel_t can be subtracted to compute the distance between them in constant time.
 *
 * @tparam sentinel_t Sentinel type.
 * @tparam iterator_t Iterator type.
 */
template<class sentinel_t, class iterator_t>
using sized_sentinel_for = typename iterator_helper::sized_sentinel_for_impl<sentinel_t, iterator_t>::type;

} // namespace std

#endif /* PSTL_SIZED_SENTINEL_FOR_H */
