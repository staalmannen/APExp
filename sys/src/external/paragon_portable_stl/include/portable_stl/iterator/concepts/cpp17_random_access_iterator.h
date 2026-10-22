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

namespace portable_stl {
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
     * @return ::portable_stl::true_type
     */
    template<class T1, class T2>

    static auto test(
      ::portable_stl::size_t) -> decltype(::portable_stl::declval<T1 &>() += ::portable_stl::declval<T2 &>(),
                                          ::portable_stl::declval<T1 &>() -= ::portable_stl::declval<T2 &>(),
                                          ::portable_stl::declval<T1 &>() + ::portable_stl::declval<T2 &>(),
                                          ::portable_stl::declval<T2 &>() + ::portable_stl::declval<T1 &>(),
                                          ::portable_stl::declval<T1 &>() - ::portable_stl::declval<T2 &>(),
                                          ::portable_stl::declval<T1 &>() - ::portable_stl::declval<T1 &>(),
                                          ::portable_stl::declval<T1 &>()[::portable_stl::declval<T2 &>()],
                                          ::portable_stl::true_type{});

    /**
     * @brief Test function.
     * @return ::portable_stl::false_type
     */
    template<class, class> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type
      = decltype(test<t_iterator, typename ::portable_stl::incrementable_traits<t_iterator>::difference_type>(0));
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
    using t_diff = typename ::portable_stl::incrementable_traits<t_iterator>::difference_type;

  public:
    // clang-format off
    /**
     * @brief Main check and result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::cpp17_bidirectional_iterator<t_iterator>,
      ::portable_stl::totally_ordered<t_iterator>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_iterator &>() += ::portable_stl::declval<t_diff &>()), t_iterator &>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_iterator &>() -= ::portable_stl::declval<t_diff &>()), t_iterator &>,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_iterator &>() + ::portable_stl::declval<t_diff &>()), t_iterator >,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_diff &>() + ::portable_stl::declval<t_iterator &>()), t_iterator >,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_iterator &>() - ::portable_stl::declval<t_diff &>()), t_iterator >,
      ::portable_stl::same_as<decltype(::portable_stl::declval<t_iterator &>() - ::portable_stl::declval<t_iterator &>()), t_diff >,
      ::portable_stl::convertible_to<
                                    decltype(::portable_stl::declval<t_iterator &>()[::portable_stl::declval<t_diff &>()]),
                                    ::portable_stl::iter_reference_t<t_iterator>
                                    >
      >;
    // clang-format on
  };

  /**
   * @brief Helper to check main requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class cpp17_random_access_iterator_req2<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
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
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper to check typenames requirements.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class cpp17_random_access_iterator_impl<
    t_iterator,
    ::portable_stl::void_t<typename ::portable_stl::incrementable_traits<t_iterator>::difference_type,
                           ::portable_stl::iter_reference_t<t_iterator>>>
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

} // namespace portable_stl

#endif /* PSTL_CPP17_RANDOM_ACCESS_ITERATOR_H */
