// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_arg.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_ARG_H
#define PSTL_ALLOCATOR_ARG_H

namespace portable_stl {
/**
 * @brief allocator_arg_t is an empty class type used to disambiguate the overloads of constructors and member
 * functions of allocator-aware objects, including tuple, function, packaged_task, (until C++17) and promise.
 */
class allocator_arg_t {
public:
  /**
   * @brief Construct a new allocator arg t object
   */
  explicit allocator_arg_t() = default;
};

// was _INLINE_VAR
/**
 * @brief Constant of allocator_arg_t.
 */
constexpr allocator_arg_t allocator_arg{};
} // namespace portable_stl

#endif /* PSTL_ALLOCATOR_ARG_H */
