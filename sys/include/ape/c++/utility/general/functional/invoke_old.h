// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_old.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_OLD_H
#define PSTL_INVOKE_OLD_H

#include "requirements/invoke_selector.h"

namespace std {

/**
 * @brief Get result from object, if is function, then call function, if is value, return value.
 *
 * @tparam t_callable_type the type of callable object.
 * @tparam t_arguments the types of arguments.
 * @param callable_object the object for get result(function or member value).
 * @param arguments the arguments for call callable_object if is function.
 * @return getted result.
 */
template<class t_callable_type, class... t_arguments>
constexpr inline static auto invoke(t_callable_type &&callable_object, t_arguments &&...arguments) noexcept(
  noexcept(::std::functional_helper::invoke_selector_helper<t_callable_type, t_arguments...>::get(
    ::std::forward<t_callable_type>(callable_object), ::std::forward<t_arguments>(arguments)...)))
  -> decltype(::std::functional_helper::invoke_selector_helper<t_callable_type, t_arguments...>::get(
    ::std::forward<t_callable_type>(callable_object), ::std::forward<t_arguments>(arguments)...)) {
  return ::std::functional_helper::invoke_selector_helper<t_callable_type, t_arguments...>::get(
    ::std::forward<t_callable_type>(callable_object), ::std::forward<t_arguments>(arguments)...);
}
} // namespace std

#endif // PSTL_INVOKE_OLD_H
