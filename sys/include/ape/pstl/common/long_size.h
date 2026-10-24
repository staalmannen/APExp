// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="long_size.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LONG_SIZE_H
#define PSTL_LONG_SIZE_H

namespace portable_stl {
namespace common_helper {

  /**
   * @brief Helper to determine 64-bit types size.
   * Primary template.
   */
  template<unsigned = sizeof(long)> struct long_size {};

  /**
   * @brief case unsigned int == long
   */
  template<> struct long_size<sizeof(unsigned int)> {
    using int64_t   = signed long long int;
    using uint64_t  = unsigned long long int;
    using intmax_t  = int64_t;
    using uintmax_t = uint64_t;
  };
  
  /**
   * @brief case unsigned long long = long
   */
  template<> struct long_size<sizeof(unsigned long long)> {
    using int64_t   = signed long int;
    using uint64_t  = unsigned long int;
    using intmax_t  = int64_t;
    using uintmax_t = uint64_t;
  };
} // namespace common_helper
} // namespace portable_stl

#endif /* PSTL_LONG_SIZE_H */
