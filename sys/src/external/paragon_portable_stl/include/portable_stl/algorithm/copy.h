// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copy.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPY_H
#define PSTL_COPY_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "copy_move_common.h"
#include "iterator_operations.h"

namespace portable_stl {

template<class, class t_input_iterator, class t_sentinel, class t_output_iterator>
inline ::portable_stl::tuple<t_input_iterator, t_output_iterator> copy_impl(
  t_input_iterator, t_sentinel, t_output_iterator);

template<class t_alg_policy> struct copy_loop {
  template<class t_input_iterator, class t_sentinel, class t_output_iterator>
  ::portable_stl::tuple<t_input_iterator, t_output_iterator> operator()(
    t_input_iterator first, t_sentinel last, t_output_iterator result) const {
    while (first != last) {
      *result = *first;
      ++first;
      ++result;
    }

    return ::portable_stl::make_tuple(::portable_stl::move(first), ::portable_stl::move(result));
  }

  // == RELATED TO SEGMENTED ITERATORS

  // template<class t_input_iterator, class t_output_iterator> struct _CopySegment {
  //   using _Traits = __segmented_iterator_traits<t_input_iterator>;

  //   t_output_iterator &result_;

  //   constexpr explicit _CopySegment(t_output_iterator &result) : result_(result) {
  //   }

  //   void operator()(typename _Traits::__local_iterator __lfirst, typename _Traits::__local_iterator __llast) {
  //     result_ = ::portable_stl::copy_impl<t_alg_policy>(__lfirst, __llast, ::portable_stl::move(result_)).second;
  //   }
  // };

  // template<class t_input_iterator,
  //          class t_output_iterator,
  //          __enable_if_t<__is_segmented_iterator<t_input_iterator>::value, int> = 0>
  // ::portable_stl::tuple<t_input_iterator, t_output_iterator> operator()(t_input_iterator first, t_input_iterator
  // last, t_output_iterator result) const {
  //   ::portable_stl::__for_each_segment(first, last, _CopySegment<t_input_iterator, t_output_iterator>(result));
  //   return ::portable_stl::make_tuple(last, ::portable_stl::move(result));
  // }

  // template<
  //   class t_input_iterator,
  //   class t_output_iterator,
  //   __enable_if_t<__has_random_access_iterator_category<t_input_iterator>::value
  //                   && !__is_segmented_iterator<t_input_iterator>::value &&
  //                   __is_segmented_iterator<t_output_iterator>::value,
  //                 int>
  //   = 0>
  // ::portable_stl::tuple<t_input_iterator, t_output_iterator> operator()(t_input_iterator first, t_input_iterator
  // last, t_output_iterator result) const {
  //   using _Traits = __segmented_iterator_traits<t_output_iterator>;
  //   using _DiffT  = typename common_type<__iter_diff_t<t_input_iterator>, __iter_diff_t<t_output_iterator>>::type;

  //   if (first == last) {
  //     return ::portable_stl::make_tuple(::portable_stl::move(first), ::portable_stl::move(result));
  //   }

  //   auto __local_first      = _Traits::__local(result);
  //   auto __segment_iterator = _Traits::__segment(result);
  //   while (true) {
  //     auto __local_last = _Traits::__end(__segment_iterator);
  //     auto __size       = ::portable_stl::min<_DiffT>(__local_last - __local_first, last - first);
  //     auto __iters      = ::portable_stl::copy_impl<t_alg_policy>(first, first + __size, __local_first);
  //     first             = ::portable_stl::move(__iters.first);

  //     if (first == last) {
  //       return ::portable_stl::make_tuple(::portable_stl::move(first), _Traits::__compose(__segment_iterator,
  //       ::portable_stl::move(__iters.second)));
  //     }

  //     __local_first = _Traits::__begin(++__segment_iterator);
  //   }
  // }
};

struct copy_trivial {
  // At this point, the iterators have been unwrapped so any `contiguous_iterator` has been unwrapped to a pointer.
  template<class t_input_type,
           class t_output_type,
           ::portable_stl::enable_if_bool_constant_t<
             typename ::portable_stl::can_lower_copy_assignment_to_memmove<t_input_type, t_output_type>::type,
             void *>
           = nullptr>
  ::portable_stl::tuple<t_input_type *, t_output_type *> operator()(
    t_input_type *first, t_input_type *last, t_output_type *result) const {
    return ::portable_stl::copy_trivial_impl(first, last, result);
  }
};

template<class t_alg_policy, class t_input_iterator, class t_sentinel, class t_output_iterator>
inline ::portable_stl::tuple<t_input_iterator, t_output_iterator> copy_impl(
  t_input_iterator first, t_sentinel last, t_output_iterator result) {
  return ::portable_stl::dispatch_copy_or_move<t_alg_policy, copy_loop<t_alg_policy>, copy_trivial>(
    ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(result));
}

template<class t_input_iterator, class t_output_iterator>
inline t_output_iterator copy(t_input_iterator first, t_input_iterator last, t_output_iterator result) {
  return ::portable_stl::get<1>(copy_impl<::portable_stl::classic_alg_policy>(first, last, result));
}
} // namespace portable_stl

#endif // PSTL_COPY_H
