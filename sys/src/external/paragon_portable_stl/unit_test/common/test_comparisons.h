// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="test_comparisons.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEST_COMPARISONS_H
#define PSTL_TEST_COMPARISONS_H

namespace test_common_helper {

class LessAndEqComp final {
  int m_value;
  public:

  LessAndEqComp(int v) : m_value(v) {}

  friend bool operator<(const LessAndEqComp& lhs, const LessAndEqComp& rhs) {
    return lhs.m_value < rhs.m_value;
  }

  friend bool operator==(const LessAndEqComp& lhs, const LessAndEqComp& rhs) {
    return lhs.m_value == rhs.m_value;
  }
};

// Test the consistency of the six basic comparison operators for values that are ordered or unordered.
template<class t_type, class t_other_type = t_type>
bool testComparisonsComplete(t_type const &t1, t_other_type const &t2, bool isEqual, bool isLess, bool isGreater) {
  assert(((isEqual ? 1 : 0) + (isLess ? 1 : 0) + (isGreater ? 1 : 0) <= 1)
         && "at most one of isEqual, isLess, and isGreater can be true");
  // clang-format off
    if (isEqual) {
        if (!(t1 == t2)) return false;
        if (!(t2 == t1)) return false;
        if ( (t1 != t2)) return false;
        if ( (t2 != t1)) return false;
        if ( (t1  < t2)) return false;
        if ( (t2  < t1)) return false;
        if (!(t1 <= t2)) return false;
        if (!(t2 <= t1)) return false;
        if ( (t1  > t2)) return false;
        if ( (t2  > t1)) return false;
        if (!(t1 >= t2)) return false;
        if (!(t2 >= t1)) return false;
    } else if (isLess) {
        if ( (t1 == t2)) return false;
        if ( (t2 == t1)) return false;
        if (!(t1 != t2)) return false;
        if (!(t2 != t1)) return false;
        if (!(t1  < t2)) return false;
        if ( (t2  < t1)) return false;
        if (!(t1 <= t2)) return false;
        if ( (t2 <= t1)) return false;
        if ( (t1  > t2)) return false;
        if (!(t2  > t1)) return false;
        if ( (t1 >= t2)) return false;
        if (!(t2 >= t1)) return false;
    } else if (isGreater) {
        if ( (t1 == t2)) return false;
        if ( (t2 == t1)) return false;
        if (!(t1 != t2)) return false;
        if (!(t2 != t1)) return false;
        if ( (t1  < t2)) return false;
        if (!(t2  < t1)) return false;
        if ( (t1 <= t2)) return false;
        if (!(t2 <= t1)) return false;
        if (!(t1  > t2)) return false;
        if ( (t2  > t1)) return false;
        if (!(t1 >= t2)) return false;
        if ( (t2 >= t1)) return false;
    } else { // unordered
        if ( (t1 == t2)) return false;
        if ( (t2 == t1)) return false;
        if (!(t1 != t2)) return false;
        if (!(t2 != t1)) return false;
        if ( (t1  < t2)) return false;
        if ( (t2  < t1)) return false;
        if ( (t1 <= t2)) return false;
        if ( (t2 <= t1)) return false;
        if ( (t1  > t2)) return false;
        if ( (t2  > t1)) return false;
        if ( (t1 >= t2)) return false;
        if ( (t2 >= t1)) return false;
    }
  // clang-format on

  return true;
}

// Test the six basic comparison operators for ordered values.
template<class t_type, class t_other_type = t_type>
bool testComparisons(t_type const &t1, t_other_type const &t2, bool isEqual, bool isLess) {
  assert(!(isEqual && isLess) && "isEqual and isLess cannot be both true");
  bool isGreater = !isEqual && !isLess;
  return testComparisonsComplete(t1, t2, isEqual, isLess, isGreater);
}
} // namespace test_common_helper

#endif // PSTL_TEST_COMPARISONS_H
