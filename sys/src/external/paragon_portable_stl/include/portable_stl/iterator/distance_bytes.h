// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="distance_bytes.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef DISTANCE_BYTES_H
#define DISTANCE_BYTES_H

#include "distance.h"
#include "iterator_traits.h"

namespace portable_stl {
/**
 * @brief Returns the number of bytes from first to last.
 *
 * @tparam iterator_t Iterator type.
 * @param first iterator pointing to the first element.
 * @param last iterator pointing to the end of the range.
 * @return The number of bytes first to last.
 */
template<class iterator_t>
inline auto distance_bytes(iterator_t first, iterator_t last) -> typename iterator_traits<iterator_t>::difference_type {
  return (::portable_stl::distance(first, last, typename iterator_traits<iterator_t>::iterator_category())
          * sizeof(typename iterator_traits<iterator_t>::value_type));
}
} // namespace portable_stl

#endif // DISTANCE_BYTES_H
