// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="cpp17_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CPP17_ITERATOR_H
#define PSTL_CPP17_ITERATOR_H

#include "../../common/size_t.h"
#include "../../concepts/copyable.h"
#include "../../concepts/same_as.h"
#include "../../metaprogramming/composite_type/is_reference.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"

namespace std {
namespace iterator_helper {
  /**
   * @brief Base LegacyIterator requirement.
   *
   * @tparam t_type Tested iterator type.
   */
  template<class t_type> class cpp17_iterator_req final {
    /**
     * @brief Test function.
     * @tparam T1
     * @return ::std::true_type
     */
    template<class T1>

    static auto test(::std::size_t) -> decltype(*::std::declval<T1 &>(),
                                                         ++::std::declval<T1 &>(),
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
    using type = decltype(test<t_type>(0));
  };

  /**
   * @brief LegacyIterator implementation.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = typename cpp17_iterator_req<t_iterator>::type> class cpp17_iterator_impl final {
  public:
    /**
     * @brief Main checks result type.
     */
    using type = ::std::conjunction<
      ::std::is_reference<decltype(*::std::declval<t_iterator &>())>,
      ::std::same_as<decltype(++::std::declval<t_iterator &>()), t_iterator &>,
      ::std::is_reference<decltype(*::std::declval<t_iterator &>()++)>,
      ::std::copyable<t_iterator>>;
  };

  /**
   * @brief LegacyIterator implementation.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class cpp17_iterator_impl<t_iterator, ::std::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };
}; // namespace iterator_helper

/**
 * @brief The LegacyIterator/cpp17_iterator requirements describe types that can be used to identify and traverse the
 * elements of a container.
 *
 * @tparam t_iterator Tested iterator type.
 */
template<class t_iterator> using cpp17_iterator = typename iterator_helper::cpp17_iterator_impl<t_iterator>::type;

} // namespace std

#endif /* PSTL_CPP17_ITERATOR_H */
