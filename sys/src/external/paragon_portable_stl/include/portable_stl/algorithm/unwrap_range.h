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

namespace portable_stl {
template<class t_iter, class t_unwrapped = decltype(::portable_stl::unwrap_iter(::portable_stl::declval<t_iter>()))>
portable_stl::tuple<t_unwrapped, t_unwrapped> unwrap_range(t_iter first, t_iter last) {
  return ::portable_stl::make_tuple(::portable_stl::unwrap_iter(::portable_stl::move(first)),
                        ::portable_stl::unwrap_iter(::portable_stl::move(last)));
}

template<class t_iter, class t_unwrapped> t_iter rewrap_range(t_iter orig_iter, t_unwrapped iter) {
  return ::portable_stl::rewrap_iter(::portable_stl::move(orig_iter), ::portable_stl::move(iter));
}
} // namespace portable_stl

#endif // PSTL_UNWRAP_RANGE_H
