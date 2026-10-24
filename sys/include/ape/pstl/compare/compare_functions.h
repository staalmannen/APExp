// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="compare_functions.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMPARE_FUNCTIONS_H
#define PSTL_COMPARE_FUNCTIONS_H

#include "partial_ordering.h"

namespace portable_stl {
/**
 * @brief Check the comparsion result status is equal.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is partial_ordering::equal
 * @retval false if cmp is not partial_ordering::equal
 */
constexpr inline static bool is_eq(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator==(::portable_stl::partial_ordering::equivalent());
}

/**
 * @brief Check the comparsion result status is not equal.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is not partial_ordering::equal
 * @retval false if cmp is partial_ordering::equal
 */
constexpr inline static bool is_neq(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator!=(::portable_stl::partial_ordering::equivalent());
}

/**
 * @brief Check the comparsion result status is less.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is partial_ordering::less
 * @retval false if cmp is not partial_ordering::less
 */
constexpr inline static bool is_lt(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator==(::portable_stl::partial_ordering::less());
}

/**
 * @brief Check the comparsion result status is less or equal.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is partial_ordering::equal or if cmp is partial_ordering::less
 * @retval false if cmp is partial_ordering::greater
 */
constexpr inline static bool is_lteq(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator!=(::portable_stl::partial_ordering::greater());
}

/**
 * @brief Check the comparsion result status is greater.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is partial_ordering::greater
 * @retval false if cmp is partial_ordering::less or if cmp is partial_ordering::equal
 */
constexpr inline static bool is_gt(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator==(::portable_stl::partial_ordering::greater());
}

/**
 * @brief Check the comparsion result status is greater or equal.
 *
 * @param cmp the comparsion result status.
 *
 * @return result status.
 * @retval true if cmp is partial_ordering::equal or if cmp is partial_ordering::greater
 * @retval false if cmp is partial_ordering::less
 */
constexpr inline static bool is_gteq(::portable_stl::partial_ordering const cmp) noexcept {
  return cmp.operator!=(::portable_stl::partial_ordering::less());
}
} // namespace portable_stl

#endif /* PSTL_COMPARE_FUNCTIONS_H */
