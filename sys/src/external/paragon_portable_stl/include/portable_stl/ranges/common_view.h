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

namespace portable_stl {
namespace ranges {

  template<class t_view,
           class = ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::ranges::common_range<t_view>>,
                                               ::portable_stl::copyable<t_view>>>
  class common_view : public ::portable_stl::ranges::view_interface<common_view<t_view>> {
    t_view m_base{};

  public:
    <::portable_stl::enable_if_bool_constant_t<::portable_stl::default_initializable<t_view>, void *>
     = nullptr> common_view()
      = default;

    template<class t_type>
    using non_const_begin_cond = ::portable_stl::conjunction<::portable_stl::ranges::random_access_range<t_type>,
                                                             ::portable_stl::ranges::sized_range<t_type>>;

    template<portable_stl::enable_if_bool_constant_t<non_const_begin_cond<t_view>, void *> = nullptr>
    constexpr auto begin() {
      return ::portable_stl::ranges::begin(m_base);
    }

    template<portable_stl::enable_if_bool_constant_t<::portable_stl::negation<non_const_begin_cond<t_view>>, void *>
             = nullptr>
    constexpr auto begin() {
      return ::portable_stl::common_iterator<::portable_stl::ranges::iterator_t<t_view>, ::portable_stl::ranges::sentinel_t<t_view>>(
        ranges::begin(m_base));
    }
  };

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_COMMON_VIEW_H */
