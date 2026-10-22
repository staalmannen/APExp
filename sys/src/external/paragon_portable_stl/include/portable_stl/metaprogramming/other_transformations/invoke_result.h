// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_result.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_RESULT_H
#define PSTL_INVOKE_RESULT_H

#include "../../utility/general/functional/invoke_impl.h"

namespace portable_stl {

/**
 * @brief Deduces the return type of an INVOKE expression at compile time.
 *
 * @tparam t_func_type Callable type.
 * @tparam t_args Argument types.
 */
template<class t_func_type, class... t_args> using invoke_result = ::portable_stl::invoke_of<t_func_type, t_args...>;

template<class t_func_type, class... t_args>
using invoke_result_t = typename invoke_result<t_func_type, t_args...>::type;

} // namespace portable_stl

#endif // PSTL_INVOKE_RESULT_H
