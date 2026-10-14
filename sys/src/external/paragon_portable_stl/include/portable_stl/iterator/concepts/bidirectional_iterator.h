// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bidirectional_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIDIRECTIONAL_ITERATOR_H
#define PSTL_BIDIRECTIONAL_ITERATOR_H

#include "../../common/size_t.h"
#include "../../concepts/derived_from.h"
#include "../../concepts/same_as.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../../utility/general/forward.h"
#include "../bidirectional_iterator_tag.h"
#include "forward_iterator.h"
#include "iter_concept.h"
namespace portable_stl {
namespace iterator_helper {

  /**
   * @brief Helper to check if pre- and post-increment operators are available.
   *
   * @tparam iterator_t
   */
  template<class iterator_t> class has_minus_ops final {
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @return ::portable_stl::true_type
     */
    template<class T1>
    static auto test(::portable_stl::size_t)
      -> decltype(--::portable_stl::declval<T1 &>(), ::portable_stl::declval<T1 &>()--, ::portable_stl::true_type{});
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
   * @brief bidirectional_iterator 'concept' implementation.
   *
   * @tparam iterator_t Given iterator type to test.
   */
  template<class iterator_t, class = typename has_minus_ops<iterator_t>::type> class bidirectional_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::forward_iterator<iterator_t>,
      ::portable_stl::derived_from<iterator_helper::iter_concept<iterator_t>,
                                   ::portable_stl::bidirectional_iterator_tag>,
      ::portable_stl::same_as<decltype(--::portable_stl::declval<iterator_t &>()), iterator_t &>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<iterator_t &>()--), iterator_t>>;
  };

  /**
   * @brief bidirectional_iterator 'concept' implementation.
   * Negative result.
   * @tparam iterator_t Given iterator type to test.
   */
  template<class iterator_t> class bidirectional_iterator_impl<iterator_t, ::portable_stl::false_type> final {
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
using bidirectional_iterator = typename iterator_helper::bidirectional_iterator_impl<iterator_t>::type;
} // namespace portable_stl

#endif /* PSTL_BIDIRECTIONAL_ITERATOR_H */
