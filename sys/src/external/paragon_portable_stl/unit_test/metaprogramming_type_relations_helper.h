// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_relations_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_RELATIONS_HELPER_H
#define PSTL_METAPROGRAMMING_TYPE_RELATIONS_HELPER_H

namespace metaprogramming_type_relations_helper {
/**
 * @brief Test class.
 */
class Base1 {};
/**
 * @brief Test class.
 */
class Derived1 : public Base1 {};
/**
 * @brief Test class.
 */
class Derived2 final : private Derived1 {};
/**
 * @brief Test class.
 */
class Derived4 final : public Base1 {};

/**
 * @brief Test class.
 */
class Base2 {};
/**
 * @brief Test class.
 */
class Derived3 final : public Base2 {};
} // namespace metaprogramming_type_relations_helper

#endif // PSTL_METAPROGRAMMING_TYPE_RELATIONS_HELPER_H
