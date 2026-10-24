// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="distance.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DISTANCE_H
#define PSTL_DISTANCE_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_relations/is_derived_from.h"
#include "iterator_traits.h"
#include "random_access_iterator_tag.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief Returns the number of hops from first to last.
   * Implementation for iterator with input access.
   * @tparam iterator_t Iterator type.
   * @param first iterator pointing to the first element.
   * @param last iterator pointing to the end of the range.
   * @param
   * @return The number of increments needed to go from first to last.
   */
  template<class iterator_t>
  inline auto distance(iterator_t first, iterator_t last, ::portable_stl::input_iterator_tag) ->
    typename iterator_traits<iterator_t>::difference_type {
    typename portable_stl::iterator_traits<iterator_t>::difference_type result{0};
    while (first != last) {
      ++first;
      ++result;
    }
    return result;
  }

  /**
   * @brief Returns the number of hops from first to last.
   * Implementation for iterator with random access.
   * @tparam iterator_t Iterator type.
   * @param first iterator pointing to the first element.
   * @param last iterator pointing to the end of the range.
   * @param
   * @return The number of increments needed to go from first to last.
   */
  template<class iterator_t>
  inline auto distance(iterator_t first, iterator_t last, ::portable_stl::random_access_iterator_tag) ->
    typename iterator_traits<iterator_t>::difference_type {
    return last - first;
  }
} // namespace iterator_helper

/**
 * @brief Returns the number of hops from first to last.
 *
 * @tparam iterator_t Iterator type.
 * @param first iterator pointing to the first element.
 * @param last iterator pointing to the end of the range.
 * @return The number of increments needed to go from first to last.
 */
template<class iterator_t>
inline auto distance(iterator_t first, iterator_t last) -> typename iterator_traits<iterator_t>::difference_type {
  return iterator_helper::distance(first, last, typename iterator_traits<iterator_t>::iterator_category());
}
} // namespace portable_stl

#endif /* PSTL_DISTANCE_H */
