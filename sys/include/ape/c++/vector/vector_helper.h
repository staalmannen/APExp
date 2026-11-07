// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VECTOR_HELPER_H
#define PSTL_VECTOR_HELPER_H

#include "../iterator/concepts/iter_concept.h"
#include "../iterator/input_iterator_tag.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../metaprogramming/type_traits/has_forward_iterator_category.h"

namespace std {
namespace vector_helper {

  template<class t_iter, class t_checked_tag, class = iterator_helper::has_iterator_category_type<t_iter>>
  class has_exactly_iterator_category_impl final {
  public:
    using type
      = ::std::is_same<typename ::std::iterator_traits<t_iter>::iterator_category, t_checked_tag>;
  };

  template<class t_iter, class t_checked_tag>
  class has_exactly_iterator_category_impl<t_iter, t_checked_tag, ::std::false_type> final {
  public:
    using type = ::std::false_type;
  };

  template<class t_iter>
  using has_exactly_input_iterator_category =
    typename has_exactly_iterator_category_impl<t_iter, input_iterator_tag>::type;

  /**
   * @brief Helper alias to select functions for input iterators.
   */
  template<class t_iterator, class t_value_type>
  using enable_for_input_iter = ::std::enable_if_bool_constant_t<
    ::std::conjunction<
      vector_helper::has_exactly_input_iterator_category<t_iterator>,
      ::std::is_constructible<t_value_type, typename ::std::iterator_traits<t_iterator>::reference>>,
    void *>;

  /**
   * @brief Helper alias to select functions for forwarder and upper iterators.
   */
  template<class t_iterator, class t_value_type>
  using enable_for_forward_iter = ::std::enable_if_bool_constant_t<
    ::std::conjunction<
      ::std::has_forward_iterator_category<t_iterator>,
      ::std::is_constructible<t_value_type, typename ::std::iterator_traits<t_iterator>::reference>>,
    void *>;

  /**
   * @brief Helper alias to select functions for input iterators.
   */
  template<class t_iterator>
  using enable_for_input_iter_bool
    = ::std::enable_if_bool_constant_t<vector_helper::has_exactly_input_iterator_category<t_iterator>, void *>;

  /**
   * @brief Helper alias to select functions for forwarder and upper iterators.
   */
  template<class t_iterator>
  using enable_for_forward_iter_bool
    = ::std::enable_if_bool_constant_t<::std::has_forward_iterator_category<t_iterator>, void *>;
} // namespace vector_helper
} // namespace std

#endif // PSTL_VECTOR_HELPER_H
