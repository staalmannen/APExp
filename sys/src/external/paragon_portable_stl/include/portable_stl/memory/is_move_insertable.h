// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_move_insertable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_MOVE_INSERTABLE_H
#define PSTL_IS_MOVE_INSERTABLE_H

#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "allocator_traits.h"

namespace portable_stl {

namespace memory_helper {

  template<typename t_allocator,
           typename t_type,
           typename t_value_type = ::portable_stl::remove_cvref_t<typename t_allocator::value_type>,
           typename              = void>
  class is_alloc_insertable_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<typename t_allocator, typename t_type, typename t_value_type>
  class is_alloc_insertable_impl<
    t_allocator,
    t_type,
    t_value_type,
    ::portable_stl::void_t<decltype(::portable_stl::allocator_traits<t_allocator>::construct(
      ::portable_stl::declval<t_allocator &>(),
      ::portable_stl::declval<t_value_type *>(),
      ::portable_stl::declval<t_type>()))>>
    final {
  public:
    using type = ::portable_stl::true_type;
  };
} // namespace memory_helper

// true if t_allocator::value_type is CopyInsertable into containers using t_allocator
// (might be wrong if t_allocator::construct exists but is not constrained,
// i.e. actually trying to use it would still be invalid. Use with caution.)
template<typename t_allocator>
using is_copy_insertable =
  typename memory_helper::is_alloc_insertable_impl<t_allocator, typename t_allocator::value_type const &>::type;

// #if _GLIBCXX_HOSTED
// // std::allocator<t_type> just requires CopyConstructible
// template<typename t_type> class __is_copy_insertable<allocator<t_type>> : is_copy_constructible<t_type> {};
// #endif

// true if t_allocator::value_type is MoveInsertable into containers using t_allocator
// (might be wrong if t_allocator::construct exists but is not constrained,
// i.e. actually trying to use it would still be invalid. Use with caution.)
template<typename t_allocator>
using is_move_insertable =
  typename memory_helper::is_alloc_insertable_impl<t_allocator, typename t_allocator::value_type>::type;

// #if _GLIBCXX_HOSTED
// // std::allocator<t_type> just requires MoveConstructible
// template<typename t_type> struct __is_move_insertable<allocator<t_type>> : is_move_constructible<t_type> {};
// #endif
} // namespace portable_stl

#endif // PSTL_IS_MOVE_INSERTABLE_H
