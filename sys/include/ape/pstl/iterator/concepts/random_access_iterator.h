// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="random_access_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANDOM_ACCESS_ITERATOR_H
#define PSTL_RANDOM_ACCESS_ITERATOR_H

#include "../../common/size_t.h"
#include "../../concepts/derived_from.h"
#include "../../concepts/same_as.h"
#include "../../concepts/totally_ordered.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/is_detected.h"
#include "../../utility/general/declval.h"
#include "../../utility/general/forward.h"
#include "../incrementable_traits.h"
#include "../iter_reference_t.h"
#include "../random_access_iterator_tag.h"
#include "bidirectional_iterator.h"
#include "iter_concept.h"
#include "sized_sentinel_for.h"

namespace portable_stl {

namespace iterator_helper {
  /**
   * @brief Test 'predicate' to check if iter_difference_t can be inferenced for iterator_t.
   * Used with is_detected<>.
   * @tparam t_type Tested type.
   */
  template<class t_type> using has_iter_difference_type_pred = ::portable_stl::iter_difference_t<t_type>;

  /**
   * @brief Helper to check if random access operators are available.
   * Primary template.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t, class = ::portable_stl::is_detected<has_iter_difference_type_pred, iterator_t>>
  class has_random_ops final {
    /**
     * @brief Test function.
     * @tparam T1 
     * @return ::portable_stl::true_type
     */
    template<class T1, class diff_type = ::portable_stl::iter_difference_t<T1>>
    static auto test(::portable_stl::size_t)
      -> decltype(::portable_stl::declval<T1 &>() += ::portable_stl::declval<diff_type const &>(),
                  ::portable_stl::declval<T1 const &>() + ::portable_stl::declval<diff_type const &>(),
                  ::portable_stl::declval<diff_type const &>() + ::portable_stl::declval<T1 const &>(),
                  ::portable_stl::declval<T1 &>() -= ::portable_stl::declval<diff_type const &>(),
                  ::portable_stl::declval<T1 const &>() - ::portable_stl::declval<diff_type const &>(),
                  ::portable_stl::declval<T1 const &>()[::portable_stl::declval<diff_type const &>()],
                  ::portable_stl::true_type{});
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @return ::portable_stl::false_type
     */
    template<class T1> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<iterator_t>(0U));
  };

  /**
   * @brief Helper to check if random access operators are available.
   * False branch wihtout has_iter_difference_t<>.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t> class has_random_ops<iterator_t, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief bidirectional_iterator 'concept' implementation.
   *
   * @tparam iterator_t Given iterator type to test.
   */
  template<class iterator_t, class = typename has_random_ops<iterator_t>::type>
  class random_access_iterator_impl final {
    /**
     * @brief Difference type.
     */
    using diff_type = ::portable_stl::iter_difference_t<iterator_t>;
    /**
     * @brief Difference type.
     */
    using ref_type  = ::portable_stl::iter_reference_t<iterator_t>;

  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::bidirectional_iterator<iterator_t>,
      ::portable_stl::derived_from<iterator_helper::iter_concept<iterator_t>,
                                   ::portable_stl::random_access_iterator_tag>,
      ::portable_stl::totally_ordered<iterator_t>,
      ::portable_stl::sized_sentinel_for<iterator_t, iterator_t>,
      // clang-format off
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t &>()       += ::portable_stl::declval<diff_type const &>()), iterator_t &>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t const &>() +  ::portable_stl::declval<diff_type const &>()), iterator_t>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<diff_type const &>()  +  ::portable_stl::declval<iterator_t &>()),      iterator_t>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t &>()       -= ::portable_stl::declval<diff_type const &>()), iterator_t &>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t const &>() -  ::portable_stl::declval<diff_type const &>()), iterator_t>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t const &>()[::portable_stl::declval<diff_type const &>()]),   ref_type>
      // clang-format on
      >;
  };

  /**
   * @brief bidirectional_iterator 'concept' implementation.
   * Negative result.
   * @tparam iterator_t Given iterator type to test.
   */
  template<class iterator_t> class random_access_iterator_impl<iterator_t, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace iterator_helper

/**
 * @brief The 'concept' bidirectional_iterator refines forward_iterator by adding the ability to move an iterator
 * backward.
 *
 * @tparam iterator_t Given iterator type to test.
 */
template<class iterator_t>
using random_access_iterator = typename iterator_helper::random_access_iterator_impl<iterator_t>::type;

} // namespace portable_stl

#endif /* PSTL_RANDOM_ACCESS_ITERATOR_H */
