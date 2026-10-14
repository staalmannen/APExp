// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="test_debug_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEST_DEBUG_HELPER_H
#define PSTL_TEST_DEBUG_HELPER_H

#include <iostream>
#include <typeinfo>
// #include <type_traits>

template<class type> void print_type_info() {
  std::cout << "'" << typeid(type).name() << "'(" << sizeof(type) << ")"
            << "\n";
}

#endif /* PSTL_TEST_DEBUG_HELPER_H */
