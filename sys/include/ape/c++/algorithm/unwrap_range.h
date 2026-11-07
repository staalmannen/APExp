// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unwrap_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNWRAP_RANGE_H
#define PSTL_UNWRAP_RANGE_H

#include "../utility/general/declval.h"
#include "../utility/general/move.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_make.h"
#include "unwrap_iter.h"

namespace std {
template<class t_iter, class t_unwrapped = decltype(::std::unwrap_iter(::std::declval<t_iter>()))>
std::tuple<t_unwrapped, t_unwrapped> unwrap_range(t_iter first, t_iter last) {
  return ::std::make_tuple(::std::unwrap_iter(::std::move(first)),
                        ::std::unwrap_iter(::std::move(last)));
}

template<class t_iter, class t_unwrapped> t_iter rewrap_range(t_iter orig_iter, t_unwrapped iter) {
  return ::std::rewrap_iter(::std::move(orig_iter), ::std::move(iter));
}
} // namespace std

#endif // PSTL_UNWRAP_RANGE_H
