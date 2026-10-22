// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_H
#define PSTL_REMOVE_H

#include "../iterator/iterator_traits.h"
#include "../utility/general/move.h"
#include "find.h"

namespace portable_stl {

/**
 * @brief Removes all elements satisfying specific criteria from the range [first, last) and returns a past-the-end
 * iterator for the new end of the range.
 *
 * @tparam t_forward_iterator
 * @param first The range of elements to process.
 * @param last The range of elements to process.
 * @param value The value of elements to remove.
 * @return Past-the-end iterator for the new range of values (if this is not end, then it points to an unspecified
 * value, and so do iterators to any values between this iterator and end).
 */
template<class t_forward_iterator,
         class t_type = typename ::portable_stl::iterator_traits<t_forward_iterator>::value_type>
t_forward_iterator remove(t_forward_iterator first, t_forward_iterator last, t_type const &value) {
  first = ::portable_stl::find(first, last, value);
  if (first != last) {
    t_forward_iterator i = first;
    while (++i != last) {
      if (!(*i == value)) {
        *first = ::portable_stl::move(*i);
        ++first;
      }
    }
  }
  return first;
}

} // namespace portable_stl

#endif // PSTL_REMOVE_H
