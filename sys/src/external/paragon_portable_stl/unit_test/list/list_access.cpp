// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_access.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

// #include "../common/move_only.h"
#include "../common/test_allocator.h"
// #include "portable_stl/iterator/move_iterator.h"
#include "portable_stl/list/list.h"

// [element access]

// reference/const_reference front()
TEST(list, front) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst{1, 2, 3};

    auto &front_ref = lst.front();
    ASSERT_EQ(1, front_ref);

    front_ref = 4;
    ASSERT_EQ(4, *lst.begin());
  }

  // constant
  {
    ::portable_stl::list<std::int32_t> const lst{1, 2, 3};

    auto &front_ref = lst.front();
    ASSERT_EQ(1, front_ref);

    ASSERT_TRUE((std::is_same<::portable_stl::list<std::int32_t>::const_reference, decltype(front_ref)>{}));
  }
}

// reference/const_reference back()
TEST(list, back) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst{1, 2, 3};

    auto &back_ref = lst.back();
    ASSERT_EQ(3, back_ref);

    back_ref = 4;
    ASSERT_EQ(4, *::portable_stl::prev(lst.end()));
  }

  // constant
  {
    ::portable_stl::list<std::int32_t> const lst{1, 2, 3};

    auto &back_ref = lst.back();
    ASSERT_EQ(3, back_ref);

    ASSERT_TRUE((std::is_same<::portable_stl::list<std::int32_t>::const_reference, decltype(back_ref)>{}));
  }
}

// iterator       begin();
// iterator       end();
// const_iterator begin()  const;
// const_iterator end()    const;
// const_iterator cbegin() const;
// const_iterator cend()   const;
TEST(list, iterators) {
  static_cast<void>(test_info_);

  {
    using t_type = std::int32_t;
    using t_list = ::portable_stl::list<t_type>;
    t_list           lst;
    t_list::iterator i = lst.begin();
    t_list::iterator j = lst.end();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
  }
  {
    using t_type = std::int32_t;
    using t_list = ::portable_stl::list<t_type>;
    t_list const           lst;
    t_list::const_iterator i = lst.begin();
    t_list::const_iterator j = lst.end();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
  }
  {
    using t_type = std::int32_t;
    using t_list = ::portable_stl::list<t_type>;
    t_list                 lst;
    t_list::const_iterator i = lst.cbegin();
    t_list::const_iterator j = lst.cend();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
    ASSERT_EQ(i, lst.end());
  }
  {
    using t_type         = std::int32_t;
    using t_list         = ::portable_stl::list<t_type>;
    t_type const     t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_list           lst(std::begin(t), std::end(t));
    t_list::iterator i = lst.begin();
    ASSERT_EQ(*i, 0);
    ++i;
    ASSERT_EQ(*i, 1);
    *i = 10;
    ASSERT_EQ(*i, 10);
    ASSERT_EQ(::portable_stl::distance(lst.begin(), lst.end()), 10);
  }
  {
    ::portable_stl::list<std::int32_t>::iterator       ii1{}, ii2{};
    ::portable_stl::list<std::int32_t>::iterator       ii4 = ii1;
    ::portable_stl::list<std::int32_t>::const_iterator cii{};
    ASSERT_TRUE(ii1 == ii2);
    ASSERT_TRUE(ii1 == ii4);

    ASSERT_FALSE(ii1 != ii2);

    ASSERT_TRUE(ii1 == cii);
    ASSERT_TRUE(cii == ii1);
    ASSERT_FALSE(ii1 != cii);
    ASSERT_FALSE(cii != ii1);
  }
}

// reverse_iterator       rbegin();
// reverse_iterator       rend();
// const_reverse_iterator rbegin()  const;
// const_reverse_iterator rend()    const;
// const_reverse_iterator crbegin() const;
// const_reverse_iterator crend()   const;
TEST(list, rbegin_rend) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias for vector of int.
   */
  using t_list = ::portable_stl::list<std::int32_t>;
  {
    t_list lst;
    ASSERT_EQ(lst.rbegin(), lst.rend());
    ASSERT_EQ(lst.crbegin(), lst.crend());
  }
  {
    std::int32_t const n{10};
    t_list             lst;
    t_list const      &clst{lst};
    lst.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    {
      std::int32_t iterations{0};

      for (t_list::const_reverse_iterator it{lst.crbegin()}; it != lst.crend(); ++it) {
        EXPECT_EQ(n - iterations - 1, *it);
        ++iterations;
      }
      EXPECT_EQ(n, iterations);
    }
    {
      EXPECT_EQ(clst.rbegin(), lst.crbegin());
      EXPECT_EQ(clst.rend(), lst.crend());
    }
    {
      std::int32_t iterations{0};

      for (typename t_list::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it) {
        EXPECT_EQ(n - iterations - 1, *it);
        *it = 40;
        EXPECT_EQ(40, *it);
        ++iterations;
      }
      EXPECT_EQ(n, iterations);
    }

    EXPECT_EQ(n, ::portable_stl::distance(lst.rbegin(), lst.rend()));
    EXPECT_EQ(n, ::portable_stl::distance(clst.rbegin(), clst.rend()));
    EXPECT_EQ(n, ::portable_stl::distance(lst.crbegin(), lst.crend()));
    EXPECT_EQ(n, ::portable_stl::distance(clst.crbegin(), clst.crend()));
  }
}

// [capacity]

// bool empty() const noexcept;
TEST(list, empty) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst;

  ASSERT_NO_THROW(lst.empty());
  ASSERT_TRUE(lst.empty());

  lst.push_back(1);
  ASSERT_FALSE(lst.empty());

  lst.clear();
  ASSERT_TRUE(lst.empty());
}

TEST(list, size) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst;
  ASSERT_NO_THROW(lst.size());
  ASSERT_EQ(lst.size(), 0U);

  lst.push_back(2);
  ASSERT_EQ(lst.size(), 1);

  lst.push_back(1);
  ASSERT_EQ(lst.size(), 2);

  lst.push_back(3);
  ASSERT_EQ(lst.size(), 3);

  lst.erase(lst.begin());
  ASSERT_EQ(lst.size(), 2);

  lst.erase(lst.begin());
  ASSERT_EQ(lst.size(), 1);

  lst.erase(lst.begin());
  ASSERT_EQ(lst.size(), 0);
}

// size_type max_size() const noexcept
TEST(list, max_size) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator with limitations.
   */
  using t_allocator      = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
  /**
   * @brief Node allocator alias.
   */
  using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;

  t_node_allocator::m_max_size = 6;

  ::portable_stl::list<std::int32_t, t_allocator> lst;

  ASSERT_EQ(6, lst.max_size());

  t_node_allocator::m_max_size = 10000;
}
