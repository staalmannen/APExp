// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="constexpr_memcmp_equal.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTEXPR_MEMCMP_EQUAL_H
#define PSTL_CONSTEXPR_MEMCMP_EQUAL_H

#include "../memory/memcmp.h"
#include "../metaprogramming/constant_evaluation/is_constant_evaluated.h"
#include "../concepts/is_equality_comparable.h"
#include "element_count.h"

namespace std {

// Because of is_trivially_equality_comparable we know that comparing the object representations is equivalent
// to a ::memcmp(...) == 0. Since we have multiple objects contiguously in memory, we can call memcmp once instead
// of invoking it on every object individually.
template<class t_type, class t_other_type>
bool constexpr_memcmp_equal(t_type const *left, t_other_type const *right, ::std::element_count num) {
  static_assert(typename ::std::is_trivially_equality_comparable<t_type, t_other_type>::type{}(),
                "t_type and t_other_type have to be trivially equality comparable");

  auto count = static_cast<size_t>(num);

  if (::std::is_constant_evaluated()) {
    while (count != 0) {
      if (*left != *right) {
        return false;
      }
      --count;
      ++left;
      ++right;
    }
    return true;
  } else {
    return ::std::memcmp(left, right, count * sizeof(t_type)) == 0;
  }
}
} // namespace std

#endif // PSTL_CONSTEXPR_MEMCMP_EQUAL_H
