// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="cpp17_random_access_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CPP17_RANDOM_ACCESS_ITERATOR_H
#define PSTL_CPP17_RANDOM_ACCESS_ITERATOR_H

#include "../../common/size_t.h"
#include "../../concepts/convertible_to.h"
#include "../../concepts/same_as.h"
#include "../../concepts/totally_ordered.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../incrementable_traits.h"
#include "../iter_reference_t.h"
#include "cpp17_bidirectional_iterator.h"

namespace std {
namespace iterator_helper {
  /**
   * @brief Base requirement.
   * @tparam t_type Tested iterator type.
   */
  template<class t_iterator> class cpp17_random_access_iterator_req1 final {
    /**
     * @brief Test function.
     * @tparam T1
     * @tparam T1
     * @return ::std::true_type
     */
    template<class T1, class T2>

    static auto test(
      ::std::size_t) -> decltype(::std::declval<T1 &>() += ::std::declval<T2 &>(),
                                          ::std::declval<T1 &>() -= ::std::declval<T2 &>(),
                                          ::std::declval<T1 &>() + ::std::declval<T2 &>(),
                                          ::std::declval<T2 &>() + ::std::declval<T1 &>(),
                                          ::std::declval<T1 &>() - ::std::declval<T2 &>(),
                                          ::std::declval<T1 &>() - ::std::declval<T1 &>(),
                                          ::std::declval<T1 &>()[::std::declval<T2 &>()],
                                          ::std::true_type{});

    /**
     * @brief Test function.
     * @return ::std::false_type
     */
    template<class, class> static auto test(...) -> ::std::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type
      = decltype(test<t_iterator, typename ::std::incrementable_traits<t_iterator>::difference_type>(0));
  };

  /**
   * @brief Helper to check main requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = typename cpp17_random_access_iterator_req1<t_iterator>::type>
  class cpp17_random_access_iterator_req2 final {
    /**
     * @brief Difference type.
     */
    using t_diff = typename ::std::incrementable_traits<t_iterator>::difference_type;

  public:
    // clang-format off
    /**
     * @brief Main check and result type.
     */
    using type = ::std::conjunction<
      ::std::cpp17_bidirectional_iterator<t_iterator>,
      ::std::totally_ordered<t_iterator>,
      ::std::same_as<decltype(::std::declval<t_iterator &>() += ::std::declval<t_diff &>()), t_iterator &>,
      ::std::same_as<decltype(::std::declval<t_iterator &>() -= ::std::declval<t_diff &>()), t_iterator &>,
      ::std::same_as<decltype(::std::declval<t_iterator &>() + ::std::declval<t_diff &>()), t_iterator >,
      ::std::same_as<decltype(::std::declval<t_diff &>() + ::std::declval<t_iterator &>()), t_iterator >,
      ::std::same_as<decltype(::std::declval<t_iterator &>() - ::std::declval<t_diff &>()), t_iterator >,
      ::std::same_as<decltype(::std::declval<t_iterator &>() - ::std::declval<t_iterator &>()), t_diff >,
      ::std::convertible_to<
                                    decltype(::std::declval<t_iterator &>()[::std::declval<t_diff &>()]),
                                    ::std::iter_reference_t<t_iterator>
                                    >
      >;
    // clang-format on
  };

  /**
   * @brief Helper to check main requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class cpp17_random_access_iterator_req2<t_iterator, ::std::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Helper to check typenames requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = void> class cpp17_random_access_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Helper to check typenames requirements.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class cpp17_random_access_iterator_impl<
    t_iterator,
    ::std::void_t<typename ::std::incrementable_traits<t_iterator>::difference_type,
                           ::std::iter_reference_t<t_iterator>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename cpp17_random_access_iterator_req2<t_iterator>::type;
  };

} // namespace iterator_helper

/**
 * @brief A LegacyBidirectionalIterator/cpp17_random_access_iterator is a LegacyForwardIterator/cpp17_forward_iterator
 * that can be moved in both directions (i.e. incremented and decremented).
 *
 * @tparam t_iterator Tested iterator type.
 */
template<class t_iterator>
using cpp17_random_access_iterator = typename iterator_helper::cpp17_random_access_iterator_impl<t_iterator>::type;

} // namespace std

#endif /* PSTL_CPP17_RANDOM_ACCESS_ITERATOR_H */
