// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="inplace_vector_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INPLACE_VECTOR_IMPL_H
#define PSTL_INPLACE_VECTOR_IMPL_H

#include "../iterator/reverse_iterator.h"
#include "../common/size_t.h"
#include "../common/ptrdiff_t.h"

namespace portable_stl {

template<class t_type> class inplace_vector_impl/*  : private __iv_detail::__storage::_t<t_type, __N> */ {
private:
  // static_assert(is_nothrow_destructible_v<t_type>, "T must be nothrow destructible");
  // using __base_t = __iv_detail::__storage::_t<t_type, __N>;
  // using __self   = inplace_vector<t_type, __N>;
  // using __base_t::__data;
  // using __base_t::__size;
  // using __base_t::__unsafe_set_size;

public:
  using value_type             = t_type;
  using pointer                = t_type *;
  using const_pointer          = const t_type *;
  using reference              = value_type &;
  using const_reference        = value_type const &;
  using size_type              = ::portable_stl::size_t;
  using difference_type        = ::portable_stl::ptrdiff_t;
  using iterator               = pointer;
  using const_iterator         = const_pointer;
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;

  constexpr inplace_vector() noexcept { __unsafe_set_size(0); }
};
} // namespace portable_stl

#endif // PSTL_INPLACE_VECTOR_IMPL_H

