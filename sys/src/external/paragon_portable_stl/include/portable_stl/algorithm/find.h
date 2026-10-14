// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="find.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FIND_H
#define PSTL_FIND_H

namespace portable_stl {

/**
 * @brief Returns an iterator to the first element in the range [first, last) that satisfies specific criteria (or last
 * if there is no such iterator).
 *
 * @tparam t_input_iterator
 * @tparam t_type
 * @param first The range of elements to examine.
 * @param last The range of elements to examine.
 * @param value Value to compare the elements to.
 * @return The first iterator it in the range [first, last) satisfying condition or last if there is no such iterator.
 */
template<class t_input_iterator, class t_type>
inline t_input_iterator find(t_input_iterator first, t_input_iterator last, t_type const &value) {
  for (; first != last; ++first) {
    if (*first == value) {
      break;
    }
  }
  return first;
}

} // namespace portable_stl

#endif // PSTL_FIND_H
