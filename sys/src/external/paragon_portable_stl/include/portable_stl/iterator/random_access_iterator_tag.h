// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="random_access_iterator_tag.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANDOM_ACCESS_ITERATOR_TAG_H
#define PSTL_RANDOM_ACCESS_ITERATOR_TAG_H

#include "bidirectional_iterator_tag.h"

namespace portable_stl {
/**
 * @brief Type for random_access_iterator.
 */
class random_access_iterator_tag : public bidirectional_iterator_tag {};
} // namespace portable_stl

#endif // PSTL_RANDOM_ACCESS_ITERATOR_TAG_H
