// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bidirectional_iterator_tag.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIDIRECTIONAL_ITERATOR_TAG_H
#define PSTL_BIDIRECTIONAL_ITERATOR_TAG_H

#include "forward_iterator_tag.h"

namespace portable_stl {
/**
 * @brief Type for bidirectional_iterator.
 */
class bidirectional_iterator_tag : public forward_iterator_tag {};
} // namespace portable_stl

#endif // PSTL_BIDIRECTIONAL_ITERATOR_TAG_H
