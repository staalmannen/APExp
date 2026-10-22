// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="array.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/array/array.h>

namespace test_array_helper {
constexpr ::portable_stl::size_t elemets_size{5U};
constexpr ::portable_stl::size_t el_0{0U};
constexpr ::portable_stl::size_t el_1{1U};
constexpr ::portable_stl::size_t el_2{2U};
constexpr ::portable_stl::size_t el_3{3U};
constexpr ::portable_stl::size_t el_4{4U};
} // namespace test_array_helper

TEST(array, ctor) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size>::difference_type checker{0};
    ASSERT_EQ(checker, 0);
  }
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array;
  EXPECT_EQ(test_array_helper::elemets_size, test_array.size());
  EXPECT_EQ(test_array_helper::elemets_size, test_array.max_size());
  EXPECT_FALSE(test_array.empty());

  // make some ref access to local object.
  test_array[0] = 1U;
}

TEST(array, accessors) {
  static_cast<void>(test_info_);
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array{
    {test_array_helper::el_0,
     test_array_helper::el_1,
     test_array_helper::el_2,
     test_array_helper::el_3,
     test_array_helper::el_4}
  };

  EXPECT_EQ(test_array_helper::el_2, test_array[test_array_helper::el_2]);
  EXPECT_EQ(test_array_helper::el_2, test_array.at(test_array_helper::el_2));
  EXPECT_EQ(test_array_helper::el_0, *test_array.data());
  EXPECT_EQ(test_array_helper::el_0, test_array.front());
  EXPECT_EQ(test_array_helper::el_4, test_array.back());
}

TEST(array, accessors_const) {
  static_cast<void>(test_info_);
  constexpr ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array{
    {test_array_helper::el_0,
     test_array_helper::el_1,
     test_array_helper::el_2,
     test_array_helper::el_3,
     test_array_helper::el_4}
  };

  EXPECT_EQ(test_array_helper::el_2, test_array[test_array_helper::el_2]);
  EXPECT_EQ(test_array_helper::el_2, test_array.at(test_array_helper::el_2));
  EXPECT_EQ(test_array_helper::el_0, *test_array.data());
  EXPECT_EQ(test_array_helper::el_0, test_array.front());
  EXPECT_EQ(test_array_helper::el_4, test_array.back());
}

TEST(array, iterators) {
  static_cast<void>(test_info_);
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array{
    {test_array_helper::el_0,
     test_array_helper::el_1,
     test_array_helper::el_2,
     test_array_helper::el_3,
     test_array_helper::el_4}
  };

  {
    auto begin_iter = test_array.begin();
    EXPECT_EQ(test_array_helper::el_3, *(begin_iter + test_array_helper::el_3));
    ++begin_iter;
  }
  {
    auto const begin_iter = test_array.cbegin();
    EXPECT_EQ(test_array_helper::el_3, *(begin_iter + test_array_helper::el_3));
  }
  {
    auto end_iter = test_array.end();
    EXPECT_EQ(test_array_helper::el_2, *(end_iter - test_array_helper::el_3));
    --end_iter;
  }
  {
    auto const end_iter = test_array.cend();
    EXPECT_EQ(test_array_helper::el_2, *(end_iter - test_array_helper::el_3));
  }
  {
    auto rbegin_iter = test_array.rbegin();
    EXPECT_EQ(test_array_helper::el_1, *(rbegin_iter + test_array_helper::el_3));
    static_cast<void>(++rbegin_iter);
  }
  {
    auto const rbegin_iter = test_array.crbegin();
    EXPECT_EQ(test_array_helper::el_1, *(rbegin_iter + test_array_helper::el_3));
  }
  {
    auto rend_iter = test_array.rend();
    EXPECT_EQ(test_array_helper::el_2, *(rend_iter - test_array_helper::el_3));
    static_cast<void>(--rend_iter);
  }
  {
    auto const rend_iter = test_array.crend();
    EXPECT_EQ(test_array_helper::el_2, *(rend_iter - test_array_helper::el_3));
  }
}

TEST(array, iterators_const) {
  static_cast<void>(test_info_);
  constexpr ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array{
    {test_array_helper::el_0,
     test_array_helper::el_1,
     test_array_helper::el_2,
     test_array_helper::el_3,
     test_array_helper::el_4}
  };

  {
    auto begin_iter = test_array.begin();
    ++begin_iter;
    EXPECT_EQ(test_array_helper::el_3, *(begin_iter + test_array_helper::el_2));
  }
  {
    auto const begin_iter = test_array.cbegin();
    EXPECT_EQ(test_array_helper::el_3, *(begin_iter + test_array_helper::el_3));
  }
  {
    auto end_iter = test_array.end();
    --end_iter;
    EXPECT_EQ(test_array_helper::el_2, *(end_iter - test_array_helper::el_2));
  }
  {
    auto const end_iter = test_array.cend();
    EXPECT_EQ(test_array_helper::el_2, *(end_iter - test_array_helper::el_3));
  }
}

TEST(array, fill) {
  static_cast<void>(test_info_);
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::elemets_size> test_array{
    {test_array_helper::el_0,
     test_array_helper::el_1,
     test_array_helper::el_2,
     test_array_helper::el_3,
     test_array_helper::el_4}
  };

  test_array.fill(test_array_helper::el_2);
  EXPECT_EQ(test_array_helper::el_2, test_array.front());
  EXPECT_EQ(test_array_helper::el_2, test_array.back());
}

TEST(array, swap) {
  static_cast<void>(test_info_);
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::el_2> test_array1{
    {test_array_helper::el_1, test_array_helper::el_1}
  };
  ::portable_stl::array<::portable_stl::size_t, test_array_helper::el_2> test_array2{
    {test_array_helper::el_2, test_array_helper::el_2}
  };

  test_array1.swap(test_array2);
  EXPECT_EQ(test_array_helper::el_2, test_array1[1]);
  EXPECT_EQ(test_array_helper::el_1, test_array2[1]);
}
