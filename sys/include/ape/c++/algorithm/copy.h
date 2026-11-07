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

namespace std {

template<class, class t_input_iterator, class t_sentinel, class t_output_iterator>
inline ::std::tuple<t_input_iterator, t_output_iterator> copy_impl(
  t_input_iterator, t_sentinel, t_output_iterator);

template<class t_alg_policy> struct copy_loop {
  template<class t_input_iterator, class t_sentinel, class t_output_iterator>
  ::std::tuple<t_input_iterator, t_output_iterator> operator()(
    t_input_iterator first, t_sentinel last, t_output_iterator result) const {
    while (first != last) {
      *result = *first;
      ++first;
      ++result;
    }

    return ::std::make_tuple(::std::move(first), ::std::move(result));
  }

  // == RELATED TO SEGMENTED ITERATORS

  // template<class t_input_iterator, class t_output_iterator> struct _CopySegment {
  //   using _Traits = __segmented_iterator_traits<t_input_iterator>;

  //   t_output_iterator &result_;

  //   constexpr explicit _CopySegment(t_output_iterator &result) : result_(result) {
  //   }

  //   void operator()(typename _Traits::__local_iterator __lfirst, typename _Traits::__local_iterator __llast) {
  //     result_ = ::std::copy_impl<t_alg_policy>(__lfirst, __llast, ::std::move(result_)).second;
  //   }
  // };

  // template<class t_input_iterator,
  //          class t_output_iterator,
  //          __enable_if_t<__is_segmented_iterator<t_input_iterator>::value, int> = 0>
  // ::std::tuple<t_input_iterator, t_output_iterator> operator()(t_input_iterator first, t_input_iterator
  // last, t_output_iterator result) const {
  //   ::std::__for_each_segment(first, last, _CopySegment<t_input_iterator, t_output_iterator>(result));
  //   return ::std::make_tuple(last, ::std::move(result));
  // }

  // template<
  //   class t_input_iterator,
  //   class t_output_iterator,
  //   __enable_if_t<__has_random_access_iterator_category<t_input_iterator>::value
  //                   && !__is_segmented_iterator<t_input_iterator>::value &&
  //                   __is_segmented_iterator<t_output_iterator>::value,
  //                 int>
  //   = 0>
  // ::std::tuple<t_input_iterator, t_output_iterator> operator()(t_input_iterator first, t_input_iterator
  // last, t_output_iterator result) const {
  //   using _Traits = __segmented_iterator_traits<t_output_iterator>;
  //   using _DiffT  = typename common_type<__iter_diff_t<t_input_iterator>, __iter_diff_t<t_output_iterator>>::type;

  //   if (first == last) {
  //     return ::std::make_tuple(::std::move(first), ::std::move(result));
  //   }

  //   auto __local_first      = _Traits::__local(result);
  //   auto __segment_iterator = _Traits::__segment(result);
  //   while (true) {
  //     auto __local_last = _Traits::__end(__segment_iterator);
  //     auto __size       = ::std::min<_DiffT>(__local_last - __local_first, last - first);
  //     auto __iters      = ::std::copy_impl<t_alg_policy>(first, first + __size, __local_first);
  //     first             = ::std::move(__iters.first);

  //     if (first == last) {
  //       return ::std::make_tuple(::std::move(first), _Traits::__compose(__segment_iterator,
  //       ::std::move(__iters.second)));
  //     }

  //     __local_first = _Traits::__begin(++__segment_iterator);
  //   }
  // }
};

struct copy_trivial {
  // At this point, the iterators have been unwrapped so any `contiguous_iterator` has been unwrapped to a pointer.
  template<class t_input_type,
           class t_output_type,
           ::std::enable_if_bool_constant_t<
             typename ::std::can_lower_copy_assignment_to_memmove<t_input_type, t_output_type>::type,
             void *>
           = nullptr>
  ::std::tuple<t_input_type *, t_output_type *> operator()(
    t_input_type *first, t_input_type *last, t_output_type *result) const {
    return ::std::copy_trivial_impl(first, last, result);
  }
};

template<class t_alg_policy, class t_input_iterator, class t_sentinel, class t_output_iterator>
inline ::std::tuple<t_input_iterator, t_output_iterator> copy_impl(
  t_input_iterator first, t_sentinel last, t_output_iterator result) {
  return ::std::dispatch_copy_or_move<t_alg_policy, copy_loop<t_alg_policy>, copy_trivial>(
    ::std::move(first), ::std::move(last), ::std::move(result));
}

template<class t_input_iterator, class t_output_iterator>
inline t_output_iterator copy(t_input_iterator first, t_input_iterator last, t_output_iterator result) {
  return ::std::get<1>(copy_impl<::std::classic_alg_policy>(first, last, result));
}
} // namespace std

#endif // PSTL_COPY_H
