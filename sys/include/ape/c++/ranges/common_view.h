// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_view.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_VIEW_H
#define PSTL_COMMON_VIEW_H

#include "../concepts/copyable.h"
#include "...iterator/c
#include "../concepts/default_initializable.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "concepts/common_range.h"
#include "concepts/random_access_range.h"
#include "concepts/sized_range.h"
#include "view_interface.h"
#include "iterator_t.h"
#include "sentinel_t.h"

namespace std {
namespace ranges {

  template<class t_view,
           class = ::std::conjunction<::std::negation<::std::ranges::common_range<t_view>>,
                                               ::std::copyable<t_view>>>
  class common_view : public ::std::ranges::view_interface<common_view<t_view>> {
    t_view m_base{};

  public:
    <::std::enable_if_bool_constant_t<::std::default_initializable<t_view>, void *>
     = nullptr> common_view()
      = default;

    template<class t_type>
    using non_const_begin_cond = ::std::conjunction<::std::ranges::random_access_range<t_type>,
                                                             ::std::ranges::sized_range<t_type>>;

    template<std::enable_if_bool_constant_t<non_const_begin_cond<t_view>, void *> = nullptr>
    constexpr auto begin() {
      return ::std::ranges::begin(m_base);
    }

    template<std::enable_if_bool_constant_t<::std::negation<non_const_begin_cond<t_view>>, void *>
             = nullptr>
    constexpr auto begin() {
      return ::std::common_iterator<::std::ranges::iterator_t<t_view>, ::std::ranges::sentinel_t<t_view>>(
        ranges::begin(m_base));
    }
  };

} // namespace ranges
} // namespace std

#endif /* PSTL_COMMON_VIEW_H */
