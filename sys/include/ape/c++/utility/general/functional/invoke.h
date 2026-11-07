// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_H
#define PSTL_INVOKE_H

#include "../../../utility/general/forward.h"
#include "invoke_impl.h"
#include "../../../metaprogramming/other_transformations/invoke_result.h"

namespace std {

template<class t_fn_type, class... t_args>
::std::invoke_result_t<t_fn_type, t_args...> invoke(t_fn_type &&fn, t_args &&...args) noexcept(
  noexcept(::std::functional_helper::invoke_impl(
    ::std::forward<t_fn_type>(fn),
    ::std::forward<t_args>(args)...))) /* noexcept(is_nothrow_invocable_v<t_fn_type, t_args...>) */ {
  return ::std::functional_helper::invoke_impl(::std::forward<t_fn_type>(fn),
                                        ::std::forward<t_args>(args)...);
}

} // namespace std

#endif // PSTL_INVOKE_H
