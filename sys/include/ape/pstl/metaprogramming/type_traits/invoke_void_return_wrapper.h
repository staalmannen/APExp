// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_void_return_wrapper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_VOID_RETURN_WRAPPER_H
#define PSTL_INVOKE_VOID_RETURN_WRAPPER_H

#include "../../utility/general/forward.h"
#include "../../utility/general/functional/invoke_impl.h"
#include "../primary_type/is_void.h"
#include "../helper/integral_constant.h"

namespace portable_stl {
template<class t_return_type, class = ::portable_stl::is_void<t_return_type>> class invoke_void_return_wrapper final {
    public:
  template<class... t_args> static t_return_type call(t_args &&...args) {
    return ::portable_stl::functional_helper::invoke_impl(::portable_stl::forward<t_args>(args)...);
  }
};

template<class t_return_type> class invoke_void_return_wrapper<t_return_type, ::portable_stl::true_type> final {
    public:
  template<class... t_args> static void call(t_args &&...args) {
    ::portable_stl::functional_helper::invoke_impl(::portable_stl::forward<t_args>(args)...);
  }
};
} // namespace portable_stl

#endif // PSTL_INVOKE_VOID_RETURN_WRAPPER_H
