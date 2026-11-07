// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="view_interface.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VIEW_INTERFACE_H
#define PSTL_VIEW_INTERFACE_H

#include "../concepts/derived_from.h"
#include "../concepts/same_as.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/primary_type/is_class.h"
#include "concepts/forward_range.h"
#include "concepts/view.h"

// #include "../iterator/concepts/contiguous_iterator.h"
// #include "../metaprogramming/logical_operator/disjunction.h"
// #include "../metaprogramming/type_relations/is_convertible.h"
// #include "iterator_t.h"

namespace std {
namespace ranges {

  template<class derived_type,
           class = ::std::enable_if_bool_constant_t<::std::conjunction<
             ::std::is_class<derived_type>,
             ::std::same_as<derived_type, ::std::remove_cv<derived_type>>>>>
  class view_interface {
    constexpr derived_type &get_derived() noexcept {
      static_assert(sizeof(derived_type)                                          //
                    && ::std::derived_from<derived_type, view_interface> //
                    && ::std::ranges::view<derived_type>);
      return static_cast<derived_type &>(*this);
    }

    constexpr derived_type const &get_derived() const noexcept {
      static_assert(sizeof(derived_type)                                          //
                    && ::std::derived_from<derived_type, view_interface> //
                    && ::std::ranges::view<derived_type>);
      return static_cast<derived_type const &>(*this);
    }

  public:
    template<class t_type = derived_type,
             ::std::enable_if_bool_constant_t<std::ranges::forward_range<t_type>, void *> = nullptr>
    constexpr bool empty() {
      return ::std::ranges::begin(get_derived()) == ::std::ranges::end(get_derived());
    }

    template<class t_type = derived_type,
             ::std::enable_if_bool_constant_t<std::ranges::forward_range<t_type const>, void *>
             = nullptr>
    constexpr bool empty() const {
      return ::std::ranges::begin(get_derived()) == ::std::ranges::end(get_derived());
    }
  };
} // namespace ranges
} // namespace std

#endif /* PSTL_VIEW_INTERFACE_H */
