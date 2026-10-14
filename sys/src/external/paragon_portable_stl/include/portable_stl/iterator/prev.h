// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="prev.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PREV_H
#define PSTL_PREV_H
#include "../metaprogramming/type_traits/has_input_iterator_category.h"
#include "../metaprogramming/type_traits/has_bidirectional_iterator_category.h"
#include "advance.h"
#include "iterator_traits.h"

namespace portable_stl {

/**
 * @brief Decrement an iterator.
 * Return the n-th predecessor (or -n-th successor if n is negative) of iterator iter.
 * @tparam t_iterator Iterator type. (Must meet the requirements of LegacyBidirectionalIterator)
 * @param iter An iterator.
 * @param n_value Number of elements iter should be descended.
 * @return An iterator of type t_iterator that holds the nth predecessor (or -nth successor if n is negative) of
 * iterator it.
 */
template<class t_iterator>
inline portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_iterator>,
                                               t_iterator>
  prev(t_iterator iter, typename ::portable_stl::iterator_traits<t_iterator>::difference_type n_value = 1) {
  // if t_iterator has_input_iterator_category, n_value could not be positive.
  ::portable_stl::advance(iter, -n_value);
  return iter;
}
} // namespace portable_stl

#endif // PSTL_PREV_H
