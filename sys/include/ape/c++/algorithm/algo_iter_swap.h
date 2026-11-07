// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="algo_iter_swap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALGO_ITER_SWAP_H
#define PSTL_ALGO_ITER_SWAP_H

#include "../utility/general/declval.h"
#include "../utility/general/swap.h"

namespace std {
/**
 * @brief
 *
 * @tparam t_forward_iterator1
 * @tparam t_forward_iterator2
 * @param lhv
 * @param rhv
 */
template<class t_forward_iterator1, class t_forward_iterator2>
constexpr inline void algo_iter_swap(t_forward_iterator1 lhv, t_forward_iterator2 rhv) noexcept(
  noexcept(swap(*::std::declval<t_forward_iterator1>(), *::std::declval<t_forward_iterator2>()))) {
  swap(*lhv, *rhv);
}
} // namespace std

#endif // PSTL_ALGO_ITER_SWAP_H
