// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="contiguous_iterator_tag.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONTIGUOUS_ITERATOR_TAG_H
#define PSTL_CONTIGUOUS_ITERATOR_TAG_H

#include "random_access_iterator_tag.h"

namespace portable_stl {
/**
 * @brief Type for contiguous_iterator.
 */
class contiguous_iterator_tag : public random_access_iterator_tag {};
} // namespace portable_stl

#endif // PSTL_CONTIGUOUS_ITERATOR_TAG_H
