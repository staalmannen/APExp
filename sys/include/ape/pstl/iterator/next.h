// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="next.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NEXT_H
#define PSTL_NEXT_H
#include "advance.h"
#include "concepts/cpp17_input_iterator.h"
#include "iterator_traits.h"
#include "concepts/iter_concept.h"

namespace portable_stl {

namespace next_helper {

  template<class t_iter, class t_checked_tag, class = iterator_helper::has_iterator_category_type<t_iter>>
  class has_exactly_iterator_category_impl final {
  public:
    using type
      = ::portable_stl::is_same<typename ::portable_stl::iterator_traits<t_iter>::iterator_category, t_checked_tag>;
  };

  template<class t_iter, class t_checked_tag>
  class has_exactly_iterator_category_impl<t_iter, t_checked_tag, ::portable_stl::false_type> final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_iter>
  using has_exactly_input_iterator_category =
    typename has_exactly_iterator_category_impl<t_iter, input_iterator_tag>::type;

  template<class t_iter, class t_checked_tag, class = iterator_helper::has_iterator_category_type<t_iter>>
  class has_iterator_category_convertible_to final {
  public:
    using type = ::portable_stl::is_convertible<typename ::portable_stl::iterator_traits<t_iter>::iterator_category,
                                                t_checked_tag>;
  };

  template<class t_iter, class t_checked_tag>
  class has_iterator_category_convertible_to<t_iter, t_checked_tag, ::portable_stl::false_type> final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_iter>
  using has_input_iterator_category = typename has_iterator_category_convertible_to<t_iter, input_iterator_tag>::type;

} // namespace next_helper

/**
 * @brief Increment an iterator.
 * Return the n-th successor (or -n-th predecessor if n is negative) of iterator iter.
 * @tparam t_iterator Iterator type. (Must meet the requirements of LegacyInputIterator)
 * @param iter An iterator.
 * @param n_value Number of elements to advance.
 * @return An iterator of type t_iterator that holds the n-th successor (or -n-th predecessor if n is negative) of
 * iterator iter.
 */
template<class t_iterator>
inline portable_stl::enable_if_bool_constant_t<next_helper::has_input_iterator_category<t_iterator>, t_iterator> next(
  t_iterator iter, typename ::portable_stl::iterator_traits<t_iterator>::difference_type n_value = 1) {
  ::portable_stl::advance(iter, n_value);
  return iter;
}
} // namespace portable_stl

#endif // PSTL_NEXT_H
