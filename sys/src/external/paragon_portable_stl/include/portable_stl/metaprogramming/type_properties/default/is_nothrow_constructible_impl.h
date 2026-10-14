// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_constructible_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H
#define PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H

#include "../../helper/integral_constant.h"

namespace portable_stl {
namespace type_properties_helper {

  template<class t_type, class... t_args> class is_nothrow_constructible_wrapper final {
  public:
    using type = ::portable_stl::bool_constant<__is_nothrow_constructible(t_type, t_args...)>;
  };

  template<class t_type, class... t_args>
  using is_nothrow_constructible_impl = typename is_nothrow_constructible_wrapper<t_type, t_args...>::type;
} // namespace type_properties_helper
} // namespace portable_stl

#endif /* PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H */
