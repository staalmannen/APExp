// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_test_helper.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include "tuple_test_helper.h"

namespace test_tuple_helper {

/**
 * @brief Comparison opeartor.
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool operator==(DefaultOnly const &x, DefaultOnly const &y) noexcept {
  return x.getData() == y.getData();
}

/**
 * @brief Comparison opeartor.
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool operator<(DefaultOnly const &x, DefaultOnly const &y) noexcept {
  return x.getData() < y.getData();
}

/**
 * @brief Comparison opeartor.
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool operator==(HasImplicitCtor const &x, HasImplicitCtor const &y) noexcept {
  return x.getValue() == y.getValue();
}

/**
 * @brief Comparison opeartor.
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool operator==(HasExplicitCtor const &x, HasExplicitCtor const &y) noexcept {
  return x.getValue() == y.getValue();
}

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(alloc_last const &x, alloc_last const &y) noexcept {
  return x.getData() == y.getData();
}

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator<(alloc_last const &x, alloc_last const &y) noexcept {
  return x.getData() < y.getData();
}

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(alloc_first const &x, alloc_first const &y) noexcept {
  return x.getData() == y.getData();
}

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator<(alloc_first const &x, alloc_first const &y) noexcept {
  return x.getData() < y.getData();
}

} // namespace test_tuple_helper
