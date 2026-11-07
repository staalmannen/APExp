// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_forward_iterator_category.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_FORWARD_ITERATOR_CATEGORY_H
#define PSTL_HAS_FORWARD_ITERATOR_CATEGORY_H

#include "../../iterator/forward_iterator_tag.h"
#include "has_iterator_category_convertible_to.h"
namespace std {
template<class t_iter>
using has_forward_iterator_category = typename ::std::type_traits_helper::has_iterator_category_convertible_to<t_iter, forward_iterator_tag>::type;
} // namespace std

#endif // PSTL_HAS_FORWARD_ITERATOR_CATEGORY_H
