// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_null_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NULL_POINTER_H
#define PSTL_IS_NULL_POINTER_H

#include "../../common/nullptr_t.h"
#include "../cv_modifications/remove_cv.h"
#include "../type_relations/is_same.h"

namespace portable_stl {
/**
 * @brief The t_type is nullptr_t regardless cv modifications.
 *
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_null_pointer = ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, ::portable_stl::nullptr_t>;

} // namespace portable_stl

#endif // PSTL_IS_NULL_POINTER_H
