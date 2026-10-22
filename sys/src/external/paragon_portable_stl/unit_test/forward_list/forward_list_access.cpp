// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_access.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../common/test_allocator.h"
#include "portable_stl/forward_list/forward_list.h"

// [element access]

// reference/const_reference front()
TEST(forward_list, front) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto &front_ref = lst.front();
    ASSERT_EQ(0, front_ref);

    front_ref = 10;
    ASSERT_EQ(10, lst.front());
    ASSERT_EQ(10, *lst.begin());
  }

  // constant
  {
    ::portable_stl::forward_list<std::int32_t> const lst{1, 2, 3};

    auto &front_ref = lst.front();
    ASSERT_EQ(1, front_ref);

    ASSERT_TRUE((std::is_same<::portable_stl::forward_list<std::int32_t>::const_reference, decltype(front_ref)>{}));
  }
}

// iterator       begin();
// iterator       end();
// const_iterator begin()  const;
// const_iterator end()    const;
// const_iterator cbegin() const;
// const_iterator cend()   const;
TEST(forward_list, iterators) {
  static_cast<void>(test_info_);

  {
    using t_type         = std::int32_t;
    using t_forward_list = ::portable_stl::forward_list<t_type>;
    t_forward_list           lst;
    t_forward_list::iterator i = lst.begin();
    t_forward_list::iterator j = lst.end();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
  }
  {
    using t_type         = std::int32_t;
    using t_forward_list = ::portable_stl::forward_list<t_type>;
    t_forward_list const           lst;
    t_forward_list::const_iterator i = lst.begin();
    t_forward_list::const_iterator j = lst.end();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
  }
  {
    using t_type         = std::int32_t;
    using t_forward_list = ::portable_stl::forward_list<t_type>;
    t_forward_list                 lst;
    t_forward_list::const_iterator i = lst.cbegin();
    t_forward_list::const_iterator j = lst.cend();
    ASSERT_EQ(::portable_stl::distance(i, j), 0);
    ASSERT_EQ(i, j);
    ASSERT_EQ(i, lst.end());
  }
  {
    using t_type                 = std::int32_t;
    using t_forward_list         = ::portable_stl::forward_list<t_type>;
    t_type const             t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_forward_list           lst(std::begin(t), std::end(t));
    t_forward_list::iterator i = lst.begin();
    ASSERT_EQ(*i, 0);
    ++i;
    ASSERT_EQ(*i, 1);
    *i = 10;
    ASSERT_EQ(*i, 10);
    ASSERT_EQ(::portable_stl::distance(lst.begin(), lst.end()), 10);
  }
  {
    ::portable_stl::forward_list<std::int32_t>::iterator       ii1{}, ii2{};
    ::portable_stl::forward_list<std::int32_t>::iterator       ii4 = ii1;
    ::portable_stl::forward_list<std::int32_t>::const_iterator cii{};
    ASSERT_TRUE(ii1 == ii2);
    ASSERT_TRUE(ii1 == ii4);

    ASSERT_FALSE(ii1 != ii2);

    ASSERT_TRUE(ii1 == cii);
    ASSERT_TRUE(cii == ii1);
    ASSERT_FALSE(ii1 != cii);
    ASSERT_FALSE(cii != ii1);
  }
}

// iterator       before_begin();
// const_iterator before_begin() const;
// const_iterator cbefore_begin() const;
TEST(forward_list, before_begin) {
  static_cast<void>(test_info_);

  /**
   * @brief List alias.
   */
  using t_flist = ::portable_stl::forward_list<std::int32_t>;

  {
    t_flist lst;

    t_flist::iterator iter = lst.before_begin();
    ASSERT_EQ(1, ::portable_stl::distance(iter, lst.end()));
  }
  {
    t_flist const           lst;
    t_flist::const_iterator iter = lst.before_begin();
    ASSERT_EQ(1, ::portable_stl::distance(iter, lst.end()));
  }
  {
    t_flist const           lst;
    t_flist::const_iterator iter = lst.cbefore_begin();
    ASSERT_EQ(1, ::portable_stl::distance(iter, lst.end()));
    ASSERT_EQ(lst.cbefore_begin(), lst.before_begin());
  }

  std::int32_t const arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  {
    t_flist           lst(std::begin(arr), std::end(arr));
    t_flist::iterator iter = lst.before_begin();
    ASSERT_EQ(11, ::portable_stl::distance(iter, lst.end()));
    ASSERT_EQ(::portable_stl::next(lst.before_begin()), lst.begin());
  }
  {
    t_flist const           lst(std::begin(arr), std::end(arr));
    t_flist::const_iterator iter = lst.before_begin();
    ASSERT_EQ(11, ::portable_stl::distance(iter, lst.end()));
  }
}

// [capacity]

// bool empty() const noexcept;
TEST(forward_list, empty) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst;

  ASSERT_NO_THROW(lst.empty());
  ASSERT_TRUE(lst.empty());

  lst.push_front(1);
  ASSERT_FALSE(lst.empty());

  lst.clear();
  ASSERT_TRUE(lst.empty());
}

// size_type max_size() const noexcept
TEST(forward_list, max_size) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator with limitations.
   */
  using t_allocator      = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
  /**
   * @brief Node allocator alias.
   */
  using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t,
  void *>>;

  t_node_allocator::m_max_size = 6;

  ::portable_stl::forward_list<std::int32_t, t_allocator> lst;

  ASSERT_EQ(6, lst.max_size());

  t_node_allocator::m_max_size = 10000;
}
