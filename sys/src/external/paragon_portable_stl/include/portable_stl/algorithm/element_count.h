// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="element_count.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ELEMENT_COUNT_H
#define PSTL_ELEMENT_COUNT_H

#include "../common/size_t.h"

namespace portable_stl {
/**
 * @brief Type used to encode that a function takes an integer that represents a number of elements as opposed to a
 * number of bytes.
 */
enum class element_count : ::portable_stl::size_t {
};

} // namespace portable_stl

#endif // PSTL_ELEMENT_COUNT_H
