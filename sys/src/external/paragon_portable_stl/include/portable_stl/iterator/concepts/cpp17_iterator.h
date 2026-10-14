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

namespace portable_stl {
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
     * @return ::portable_stl::true_type
     */
    template<class T1>

    static auto test(::portable_stl::size_t) -> decltype(*::portable_stl::declval<T1 &>(),
                                                         ++::portable_stl::declval<T1 &>(),
                                                         *::portable_stl::declval<T1 &>()++,
                                                         ::portable_stl::true_type{});

    /**
     * @brief Test function.
     * @tparam T1
     * @return ::portable_stl::false_type
     */
    template<class T1> static auto test(...) -> ::portable_stl::false_type;

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
    using type = ::portable_stl::conjunction<
      ::portable_stl::is_reference<decltype(*::portable_stl::declval<t_iterator &>())>,
      ::portable_stl::same_as<decltype(++::portable_stl::declval<t_iterator &>()), t_iterator &>,
      ::portable_stl::is_reference<decltype(*::portable_stl::declval<t_iterator &>()++)>,
      ::portable_stl::copyable<t_iterator>>;
  };

  /**
   * @brief LegacyIterator implementation.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class cpp17_iterator_impl<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
}; // namespace iterator_helper

/**
 * @brief The LegacyIterator/cpp17_iterator requirements describe types that can be used to identify and traverse the
 * elements of a container.
 *
 * @tparam t_iterator Tested iterator type.
 */
template<class t_iterator> using cpp17_iterator = typename iterator_helper::cpp17_iterator_impl<t_iterator>::type;

} // namespace portable_stl

#endif /* PSTL_CPP17_ITERATOR_H */
