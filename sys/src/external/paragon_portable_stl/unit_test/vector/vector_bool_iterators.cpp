// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool_iterators.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/ranges/begin.h"
#include "portable_stl/ranges/end.h"
#include "portable_stl/vector/vector_bool.h"

// [iterators]

TEST(vector_bool, begin_end) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias for vector of int.
   */
  using t_vector = ::portable_stl::vector<bool>;

  {
    t_vector           vec;
    t_vector::iterator b = vec.begin();
    t_vector::iterator e = vec.end();
    ASSERT_EQ(0, ::portable_stl::distance(b, e));
    ASSERT_EQ(b, e);
  }
  {
    t_vector const           vec;
    t_vector::const_iterator b = vec.begin();
    t_vector::const_iterator e = vec.end();
    ASSERT_EQ(0, ::portable_stl::distance(b, e));
    ASSERT_EQ(b, e);
  }
  {
    t_vector                 vec;
    t_vector::const_iterator b = vec.cbegin();
    t_vector::const_iterator e = vec.cend();
    ASSERT_EQ(0, ::portable_stl::distance(b, e));
    ASSERT_EQ(b, e);
    ASSERT_EQ(b, vec.end());
  }
}

TEST(vector_bool, rbegin_rend) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias for vector of int.
   */
  using t_vector = ::portable_stl::vector<bool>;
  {
    t_vector vec;
    assert(vec.rbegin() == vec.rend());
    assert(vec.crbegin() == vec.crend());
  }
  {
    std::int32_t const n{5};
    t_vector           vec;
    t_vector const    &cvec{vec};
    vec.assign({true, false, true, false, true});
    {
      std::int32_t iterations{0};

      for (t_vector::const_reverse_iterator it{vec.crbegin()}; it != vec.crend(); ++it) {
        EXPECT_EQ((n - iterations) % 2, *it);
        ++iterations;
      }
      EXPECT_EQ(n, iterations);
    }
    {
      EXPECT_EQ(cvec.rbegin(), vec.crbegin());
      EXPECT_EQ(cvec.rend(), vec.crend());
    }
    {
      std::int32_t iterations{0};

      for (typename t_vector::reverse_iterator it{vec.rbegin()}; it != vec.rend(); ++it) {
        EXPECT_EQ((n - iterations) % 2, *it);
        *it = true;
        EXPECT_EQ(true, *it);
        ++iterations;
      }
      EXPECT_EQ(n, iterations);
    }

    EXPECT_EQ(n, ::portable_stl::distance(vec.rbegin(), vec.rend()));
    EXPECT_EQ(n, ::portable_stl::distance(cvec.rbegin(), cvec.rend()));
    EXPECT_EQ(n, ::portable_stl::distance(vec.crbegin(), vec.crend()));
    EXPECT_EQ(n, ::portable_stl::distance(cvec.crbegin(), cvec.crend()));
  }
}
