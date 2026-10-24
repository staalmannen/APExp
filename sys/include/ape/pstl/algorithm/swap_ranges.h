// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swap_ranges.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAP_RANGES_H
#define PSTL_SWAP_RANGES_H

#include "../utility/general/move.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "iterator_operations.h"

namespace portable_stl {
namespace algorithm_helper {

  // 2+2 iterators: the shorter size will be used.
  template<class t_alg_policy,
           class t_forward_iterator1,
           class t_sentinel1,
           class t_forward_iterator2,
           class t_sentinel2>
  ::portable_stl::tuple<t_forward_iterator1, t_forward_iterator2> swap_ranges_impl(
    t_forward_iterator1 first1, t_sentinel1 last1, t_forward_iterator2 first2, t_sentinel2 last2) {
    while ((first1 != last1) && (first2 != last2)) {
      ::portable_stl::iterator_operations<t_alg_policy>::iter_swap(first1, first2);
      static_cast<void>(++first1);
      static_cast<void>(++first2);
    }

    return ::portable_stl::tuple<t_forward_iterator1, t_forward_iterator2>(::portable_stl::move(first1),
                                                                           ::portable_stl::move(first2));
  }

  // 2+1 iterators: size2 >= size1.
  template<class t_alg_policy, class t_forward_iterator1, class t_sentinel1, class t_forward_iterator2>
  ::portable_stl::tuple<t_forward_iterator1, t_forward_iterator2> swap_ranges_impl(
    t_forward_iterator1 first1, t_sentinel1 last1, t_forward_iterator2 first2) {
    while (first1 != last1) {
      ::portable_stl::iterator_operations<t_alg_policy>::iter_swap(first1, first2);
      static_cast<void>(++first1);
      static_cast<void>(++first2);
    }

    return ::portable_stl::tuple<t_forward_iterator1, t_forward_iterator2>(::portable_stl::move(first1),
                                                                           ::portable_stl::move(first2));
  }
} // namespace algorithm_helper

/**
 * @brief Swaps two ranges of elements.
 *
 * @tparam t_forward_iterator1 Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2 Must meet the requirements of LegacyForwardIterator.
 * @param first1 The first range of elements to swap.
 * @param last1 The first range of elements to swap.
 * @param first2 Beginning of the second range of elements to swap.
 * @return Iterator to the element past the last element exchanged in the range beginning with first2.
 */
template<class t_forward_iterator1, class t_forward_iterator2>
inline t_forward_iterator2 swap_ranges(
  t_forward_iterator1 first1, t_forward_iterator1 last1, t_forward_iterator2 first2) {
  return ::portable_stl::get<1>(algorithm_helper::swap_ranges_impl<::portable_stl::classic_alg_policy>(
    ::portable_stl::move(first1), ::portable_stl::move(last1), ::portable_stl::move(first2)));
}
} // namespace portable_stl
#endif // PSTL_SWAP_RANGES_H
