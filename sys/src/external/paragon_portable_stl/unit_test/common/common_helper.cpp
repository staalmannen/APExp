// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_helper.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include "default_only.h"
#include "counter.h"

namespace test_common_helper {

std::int32_t DefaultOnly::count = 0;

std::int32_t Counter_base::gConstructed = 0;

} // namespace test_common_helper
