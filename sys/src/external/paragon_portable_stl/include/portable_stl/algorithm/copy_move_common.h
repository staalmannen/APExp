// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copy_move_common.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPY_MOVE_COMMON_H
#define PSTL_COPY_MOVE_COMMON_H

#include "../common/size_t.h"
#include "../memory/memmove.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../metaprogramming/type_properties/is_trivially_assignable.h"
#include "../metaprogramming/type_properties/is_volatile.h"
// #include "../metaprogramming/type_traits/datasizeof.h"
#include "../metaprogramming/type_traits/is_always_bitcastable.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_make.h"
#include "unwrap_iter.h"
#include "unwrap_range.h"
#include "element_count.h"

namespace portable_stl {

template<class t_type_from, class t_type_to> class can_lower_copy_assignment_to_memmove final {
public:
  using type = ::portable_stl::conjunction<
    // If the types are always bitcastable, it's valid to do a bitwise copy between them.
    typename ::portable_stl::is_always_bitcastable<t_type_from, t_type_to>::type,
    // Reject conversions that wouldn't be performed by the regular built-in assignment (e.g. between arrays).
    ::portable_stl::is_trivially_assignable<t_type_to &, t_type_from const &>,
    // `memmove` doesn't accept `volatile` pointers, make sure the optimization SFINAEs away in that case.
    ::portable_stl::negation<::portable_stl::is_volatile<t_type_from>>,
    ::portable_stl::negation<::portable_stl::is_volatile<t_type_to>>>;
};

template<class t_type_from, class t_type_to> class can_lower_move_assignment_to_memmove final {
public:
  using type = ::portable_stl::conjunction<typename ::portable_stl::is_always_bitcastable<t_type_from, t_type_to>::type,
                                           ::portable_stl::is_trivially_assignable<t_type_to &, t_type_from &&>,
                                           ::portable_stl::negation<::portable_stl::is_volatile<t_type_from>>,
                                           ::portable_stl::negation<::portable_stl::is_volatile<t_type_to>>>;
};

template<class t_type,
         class t_other_type,
         ::portable_stl::enable_if_bool_constant_t<typename ::portable_stl::is_always_bitcastable<t_other_type, t_type>::type, void *>
         = nullptr>
t_type *constexpr_memmove(t_type *dest, t_other_type *src, element_count num) {
  auto count = static_cast<::portable_stl::size_t>(num);
  //   if (__libcpp_is_constant_evaluated()) {
  //     if (std::__is_pointer_in_range(src, src + count, dest)) {
  //       for (; count > 0; --count) {
  //         std::__assign_trivially_copyable(dest[count - 1], src[count - 1]);
  //       }
  //     } else {
  //       for (::portable_stl::size_t __i{0}; __i != count; ++__i) {
  //         std::__assign_trivially_copyable(dest[__i], src[__i]);
  //       }
  //     }
  //   } else
  if (count > 0) {
    // from last clang
    // ::portable_stl::memmove(dest, src, (count - 1) * sizeof(t_type) + ::portable_stl::datasizeof<t_type>::value);

    // from old ssdk::portable_stl
    ::portable_stl::memmove(dest, src, count * sizeof(t_type));
  }
  return dest;
}

// `memmove` algorithms implementation.

template<class t_input_type, class t_output_type>
::portable_stl::tuple<t_input_type *, t_output_type *> copy_trivial_impl(
  t_input_type *first, t_input_type *last, t_output_type *result) {
  auto const num = static_cast<::portable_stl::size_t>(last - first);

  constexpr_memmove(result, first, ::portable_stl::element_count(num));

  return ::portable_stl::make_tuple(last, result + num);
}

template<class t_input_type, class t_output_type>
::portable_stl::tuple<t_input_type *, t_output_type *> copy_backward_trivial_impl(
  t_input_type *first, t_input_type *last, t_output_type *result) {
  auto const num = static_cast<size_t>(last - first);
  result -= num;

  constexpr_memmove(result, first, ::portable_stl::element_count(num));

  return ::portable_stl::make_tuple(last, result);
}

namespace copy_move_helper {

  template<class t_func1, class t_func2>
  struct overload
      : t_func1
      , t_func2 {
    using t_func1::operator();
    using t_func2::operator();
  };

  template<class t_input_iter, class t_sentinel, class t_output_iter, class = void> class can_rewrap_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_input_iter, class t_sentinel, class t_output_iter>
  class can_rewrap_impl<t_input_iter,
                        t_sentinel,
                        t_output_iter,
                        // Note that sentinels are always copy-constructible.
                        ::portable_stl::enable_if_bool_constant_t<
                          ::portable_stl::conjunction<::portable_stl::is_copy_constructible<t_input_iter>,
                                                      ::portable_stl::is_copy_constructible<t_output_iter>>>>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_input_iter, class t_sentinel, class t_output_iter>
  using can_rewrap = typename can_rewrap_impl<t_input_iter, t_sentinel, t_output_iter>::type;

} // namespace copy_move_helper
// Iterator unwrapping and dispatching to the correct overload.

template<class t_algorithm,
         class t_input_iter,
         class t_sentinel,
         class t_output_iter,
         ::portable_stl::
           enable_if_bool_constant_t<copy_move_helper::can_rewrap<t_input_iter, t_sentinel, t_output_iter>, void *>
         = nullptr>
::portable_stl::tuple<t_input_iter, t_output_iter> unwrap_and_dispatch(
  t_input_iter first, t_sentinel last, t_output_iter out_first) {
  auto range  = ::portable_stl::unwrap_range(first, ::portable_stl::move(last));
  auto result = t_algorithm()(::portable_stl::move(::portable_stl::get<0>(range)),
                              ::portable_stl::move(::portable_stl::get<1>(range)),
                              ::portable_stl::unwrap_iter(out_first));
  return ::portable_stl::make_tuple(
    ::portable_stl::rewrap_range<t_sentinel>(::portable_stl::move(first),
                                             ::portable_stl::move(::portable_stl::get<0>(result))),
    ::portable_stl::rewrap_iter(::portable_stl::move(out_first), ::portable_stl::move(::portable_stl::get<1>(result))));
}

template<class t_algorithm,
         class t_input_iter,
         class t_sentinel,
         class t_output_iter,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::negation<copy_move_helper::can_rewrap<t_input_iter, t_sentinel, t_output_iter>>,
           void *>
         = nullptr>
::portable_stl::tuple<t_input_iter, t_output_iter> unwrap_and_dispatch(
  t_input_iter first, t_sentinel last, t_output_iter out_first) {
  return t_algorithm()(::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(out_first));
}

template<class _AlgPolicy,
         class t_naive_algorithm,
         class t_optimized_algorithm,
         class t_input_iter,
         class t_sentinel,
         class t_output_iter>
::portable_stl::tuple<t_input_iter, t_output_iter> dispatch_copy_or_move(
  t_input_iter first, t_sentinel last, t_output_iter out_first) {
  using t_algorithm = copy_move_helper::overload<t_naive_algorithm, t_optimized_algorithm>;
  return unwrap_and_dispatch<t_algorithm>(
    ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(out_first));
}
} // namespace portable_stl

#endif // PSTL_COPY_MOVE_COMMON_H
