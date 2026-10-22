// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_input_iterator_category.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_INPUT_ITERATOR_CATEGORY_H
#define PSTL_HAS_INPUT_ITERATOR_CATEGORY_H

#include "has_iterator_category_convertible_to.h"
#include "../../iterator/input_iterator_tag.h"
namespace portable_stl {
template<class t_iter>
using has_input_iterator_category =
  typename ::portable_stl::type_traits_helper::has_iterator_category_convertible_to<t_iter, input_iterator_tag>::type;

} // namespace portable_stl

#endif // PSTL_HAS_INPUT_ITERATOR_CATEGORY_H
