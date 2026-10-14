// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_iterators.cpp"
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
#include "portable_stl/vector/vector.h"

// [iterators]

TEST(vector, begin_end) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias for vector of int.
   */
  using t_vector = ::portable_stl::vector<std::int32_t>;

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
  {
    std::int32_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_vector     vec(::portable_stl::ranges::begin(arr), ::portable_stl::ranges::end(arr));

    t_vector::iterator b = vec.begin();
    ASSERT_EQ(0, *b);

    ++b;
    ASSERT_EQ(1, *b);

    *b = 10;
    ASSERT_EQ(10, *b);

    ASSERT_EQ(10, ::portable_stl::distance(vec.begin(), vec.end()));
  }
}

TEST(vector, rbegin_rend) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias for vector of int.
   */
  using t_vector = ::portable_stl::vector<std::int32_t>;
  {
    t_vector vec;
    assert(vec.rbegin() == vec.rend());
    assert(vec.crbegin() == vec.crend());
  }
  {
    std::int32_t const n{10};
    t_vector           vec;
    t_vector const    &cvec{vec};
    vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    {
      std::int32_t iterations{0};

      for (t_vector::const_reverse_iterator it{vec.crbegin()}; it != vec.crend(); ++it) {
        EXPECT_EQ(n - iterations - 1, *it);
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

      for (typename t_vector::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        EXPECT_EQ(n - iterations - 1, *it);
        *it = 40;
        EXPECT_EQ(40, *it);
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
