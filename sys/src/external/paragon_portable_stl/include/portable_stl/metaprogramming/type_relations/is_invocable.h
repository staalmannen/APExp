// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_invocable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_INVOCABLE_H
#define PSTL_IS_INVOCABLE_H

#include "../../utility/general/functional/invoke_impl.h"

namespace portable_stl {

/**
 * @brief Determines whether INVOKE(declval<t_func_type>(), declval<t_args>()...) is well formed when treated as an
 * unevaluated operand.
 * If t_func_type or any type in the parameter pack t_args is not a complete type, (possibly cv-qualified) void, or an
 * array of unknown bound, the behavior is undefined.
 *
 * @tparam t_func_type
 * @tparam ...t_args
 */
template<class t_func_type, class... t_args>
using is_invocable = typename ::portable_stl::functional_helper::invokable<t_func_type, t_args...>::type;

} // namespace portable_stl

#endif // PSTL_IS_INVOCABLE_H
