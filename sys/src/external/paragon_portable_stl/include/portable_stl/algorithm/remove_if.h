// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_if.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_IF_H
#define PSTL_REMOVE_IF_H

#include "../utility/general/move.h"
#include "find_if.h"

namespace portable_stl {

/**
 * @brief Removes all elements satisfying specific criteria from the range [first, last) and returns a past-the-end
 * iterator for the new end of the range.
 *
 * @tparam t_forward_iterator
 * @tparam t_predicate
 * @param first The range of elements to process.
 * @param last The range of elements to process.
 * @param pred Unary predicate which returns ​true if the element should be removed.
 * @return Past-the-end iterator for the new range of values (if this is not end, then it points to an unspecified
 * value, and so do iterators to any values between this iterator and end).
 */
template<class t_forward_iterator, class t_predicate>
t_forward_iterator remove_if(t_forward_iterator first, t_forward_iterator last, t_predicate pred) {
  first = ::portable_stl::find_if(first, last, pred);
  if (first != last) {
    t_forward_iterator i = first;
    while (++i != last) {
      if (!pred(*i)) {
        *first = ::portable_stl::move(*i);
        ++first;
      }
    }
  }
  return first;
}
} // namespace portable_stl

#endif // PSTL_REMOVE_IF_H
