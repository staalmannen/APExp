// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="cpp17_forward_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CPP17_FORWARD_ITERATOR_H
#define PSTL_CPP17_FORWARD_ITERATOR_H

#include "../../common/size_t.h"
#include "../../concepts/constructible_from.h"
#include "../../concepts/convertible_to.h"
#include "../../concepts/same_as.h"
#include "../../metaprogramming/composite_type/is_reference.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../indirectly_readable_traits.h"
#include "../iter_reference_t.h"
#include "cpp17_input_iterator.h"

namespace std {
namespace iterator_helper {
  /**
   * @brief Base LegacyForwardIterator requirement.
   * @tparam t_type Tested iterator type.
   */
  template<class t_iterator> class cpp17_forward_iterator_req1 final {
    /**
     * @brief Test function.
     * @tparam T1
     * @return ::std::true_type
     */
    template<class T1>

    static auto test(::std::size_t) -> decltype(::std::declval<T1 &>()++,
                                                         *::std::declval<T1 &>()++,
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
    using type = decltype(test<t_iterator>(0));
  };

  /**
   * @brief Helper to check common_reference_t requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = void> class cpp17_forward_iterator_req2 final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Helper to check common_reference_t requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class cpp17_forward_iterator_req2<
    t_iterator,
    ::std::void_t<::std::iter_reference_t<t_iterator>,
                           typename ::std::indirectly_readable_traits<t_iterator>::value_type>>
    final {
  public:
    /**
     * @brief Main check and result type.
     */
    using type = ::std::conjunction<
      ::std::cpp17_input_iterator<t_iterator>,
      ::std::constructible_from<t_iterator>,
      ::std::is_reference<::std::iter_reference_t<t_iterator>>,
      ::std::same_as<::std::remove_cvref_t<::std::iter_reference_t<t_iterator>>,
                              typename ::std::indirectly_readable_traits<t_iterator>::value_type>,
      ::std::convertible_to<decltype(::std::declval<t_iterator &>()++), t_iterator const &>,
      ::std::same_as<decltype(*::std::declval<t_iterator &>()++),
                              ::std::iter_reference_t<t_iterator>>>;
  };

  /**
   * @brief Helper to check base (cpp17_forward_iterator_req1) requirements.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = typename cpp17_forward_iterator_req1<t_iterator>::type>
  class cpp17_forward_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename cpp17_forward_iterator_req2<t_iterator>::type;
  };

  /**
   * @brief Helper to check base (cpp17_forward_iterator_req1) requirements.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class cpp17_forward_iterator_impl<t_iterator, ::std::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

} // namespace iterator_helper

/**
 * @brief A LegacyForwardIterator/cpp17_forward_iterator is a LegacyIterator/cpp17_input_iterator that can read data
 * from the pointed-to element.
 *
 * @tparam t_iterator Tested iterator type.
 */
template<class t_iterator>
using cpp17_forward_iterator = typename iterator_helper::cpp17_forward_iterator_impl<t_iterator>::type;

} // namespace std

#endif /* PSTL_CPP17_FORWARD_ITERATOR_H */
