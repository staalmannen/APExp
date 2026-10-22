// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_no_deduction_guide.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_NO_DEDUCTION_GUIDE_H
#define PSTL_TUPLE_NO_DEDUCTION_GUIDE_H

#include "gtest/gtest.h"

namespace test_tuple {

/**
 * @brief Additional test for deduction guide
 *
 */
inline void tuple_deduction_guide() {
  ASSERT_TRUE(true);
}

} // namespace test_tuple

#endif // PSTL_TUPLE_NO_DEDUCTION_GUIDE_H
