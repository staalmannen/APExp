// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_operations.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

// #include "../common/default_only.h"
// #include "../common/move_only.h"
#include "../common/test_allocator.h"
// #include "portable_stl/iterator/move_iterator.h"
#include <algorithm>
#include <random>

#include "portable_stl/list/list.h"
#include "portable_stl/vector/vector.h"

// [merge]

// void merge(list& x);
TEST(list, merge) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::list<std::int32_t> lst2{0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::list<std::int32_t> lst_ref{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    lst1.merge(lst2);

    ASSERT_EQ(lst_ref, lst1);
    ASSERT_TRUE(lst2.empty());
  }

  // rvalue
  {
    ::portable_stl::list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::list<std::int32_t> lst_ref{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    lst1.merge(::portable_stl::list<std::int32_t>{0, 2, 4, 5, 6, 8, 11});

    ASSERT_EQ(lst_ref, lst1);
  }

  // self
  {
    ::portable_stl::list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::list<std::int32_t> lst_ref{1, 3, 7, 9, 10};
    lst1.merge(lst1);

    ASSERT_EQ(lst_ref, lst1);
  }
}

// template <class Compare> void merge(list& x, Compare comp);
TEST(list, merge_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::list<std::int32_t> lst2{11, 8, 6, 5, 4, 2, 0};
    ::portable_stl::list<std::int32_t> lst_ref{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst1.merge(lst2, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
    ASSERT_TRUE(lst2.empty());
  }

  // rvalue
  {
    ::portable_stl::list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::list<std::int32_t> lst_ref{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst1.merge(::portable_stl::list<std::int32_t>{11, 8, 6, 5, 4, 2, 0}, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
  }

  // self
  {
    ::portable_stl::list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::list<std::int32_t> lst_ref{10, 9, 7, 3, 1};
    lst1.merge(lst1, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
  }
}

// [splice]

// void splice(const_iterator pos, list& other);
TEST(list, splice_pos_list) {
  static_cast<void>(test_info_);

  std::int32_t a1[] = {1, 2, 3};
  std::int32_t a2[] = {4, 5, 6};

  // both empty
  {
    ::portable_stl::list<std::int32_t> lst1;
    ::portable_stl::list<std::int32_t> lst2;

    lst1.splice(lst1.begin(), lst2);

    ASSERT_EQ(0U, lst1.size());
    ASSERT_EQ(0, ::portable_stl::distance(lst1.begin(), lst1.end()));
    ASSERT_EQ(0U, lst2.size());
    ASSERT_EQ(0, ::portable_stl::distance(lst2.begin(), lst2.end()));
  }

  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    l1.splice(l1.end(), ::portable_stl::list<std::int32_t>(a2, a2 + 1));
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2;
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2;
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 4);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2);
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 4);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2;
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2;
    l1.splice(::portable_stl::next(l1.begin()), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2;
    l1.splice(::portable_stl::next(l1.begin(), 2), l2);
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(::portable_stl::next(l1.begin()), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(::portable_stl::next(l1.begin(), 2), l2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 4);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(::portable_stl::next(l1.begin()), l2);
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 4);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(::portable_stl::next(l1.begin(), 2), l2);
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 4);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.begin(), l2);
    ASSERT_EQ(l1.size(), 6);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 6);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(::portable_stl::next(l1.begin()), l2);
    ASSERT_EQ(l1.size(), 6);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 6);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(::portable_stl::next(l1.begin(), 2), l2);
    ASSERT_EQ(l1.size(), 6);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 6);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(::portable_stl::next(l1.begin(), 3), l2);
    ASSERT_EQ(l1.size(), 6);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 6);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
    ++i;
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
  }
}

// void splice(const_iterator pos, list<T,Allocator>& x, iterator i);
TEST(list, splice_pos_list_iter) {
  static_cast<void>(test_info_);

  std::int32_t a1[] = {1, 2, 3};
  std::int32_t a2[] = {4, 5, 6};
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.end(), l2, l2.begin());
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.end(), l2, l2.begin());
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 1);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    i = l2.begin();
    ASSERT_EQ(*i, 5);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.end(), std::move(l2), l2.begin());
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 2);
    l1.splice(l1.end(), l2, ::portable_stl::next(l2.begin()));
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 1);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 5);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2, l2.begin());
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    i = l2.begin();
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2, ::portable_stl::next(l2.begin()));
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 5);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 6);
  }
  {
    ::portable_stl::list<std::int32_t> l1;
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2, ::portable_stl::next(l2.begin(), 2));
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ASSERT_EQ(l2.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 6);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 5);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    l1.splice(l1.begin(), l1, l1.begin());
    ASSERT_EQ(l1.size(), 1);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 1);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(l1.begin(), l2, l2.begin());
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 4);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 1);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 1);
    l1.splice(::portable_stl::next(l1.begin()), l2, l2.begin());
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ASSERT_EQ(l2.size(), 0);
    ASSERT_EQ(::portable_stl::distance(l2.begin(), l2.end()), 0);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    l1.splice(l1.begin(), l1, l1.begin());
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    l1.splice(l1.begin(), l1, ::portable_stl::next(l1.begin()));
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    l1.splice(::portable_stl::next(l1.begin()), l1, l1.begin());
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 2);
    l1.splice(::portable_stl::next(l1.begin()), l1, ::portable_stl::next(l1.begin()));
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 2);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
  }
}

// void splice(const_iterator position, list& x, iterator first, iterator last);
TEST(list, splice_pos_list_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t a1[] = {1, 2, 3};
  std::int32_t a2[] = {4, 5, 6};
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    l1.splice(l1.begin(), l1, ::portable_stl::next(l1.begin()), ::portable_stl::next(l1.begin()));
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    l1.splice(l1.begin(), l1, ::portable_stl::next(l1.begin()), ::portable_stl::next(l1.begin(), 2));
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    auto                               iter2_1 = ::portable_stl::next(l1.begin());
    auto                               iter2_2 = ::portable_stl::next(l1.begin(), 2);
    l1.splice(l1.begin(), std::move(l1), iter2_1, iter2_2);
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 3);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    l1.splice(l1.begin(), l1, ::portable_stl::next(l1.begin()), ::portable_stl::next(l1.begin(), 3));
    ASSERT_EQ(l1.size(), 3);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 3);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
    ++i;
    ASSERT_EQ(*i, 1);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.begin(), l2, ::portable_stl::next(l2.begin()), l2.end());
    ASSERT_EQ(l1.size(), 5);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 5);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
    ASSERT_EQ(l2.size(), 1);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(::portable_stl::next(l1.begin()), l2, ::portable_stl::next(l2.begin()), l2.end());
    ASSERT_EQ(l1.size(), 5);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 5);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
    ASSERT_EQ(l2.size(), 1);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
  }
  {
    ::portable_stl::list<std::int32_t> l1(a1, a1 + 3);
    ::portable_stl::list<std::int32_t> l2(a2, a2 + 3);
    l1.splice(l1.end(), l2, ::portable_stl::next(l2.begin()), l2.end());
    ASSERT_EQ(l1.size(), 5);
    ASSERT_EQ(::portable_stl::distance(l1.begin(), l1.end()), 5);
    ::portable_stl::list<std::int32_t>::const_iterator i = l1.begin();
    ASSERT_EQ(*i, 1);
    ++i;
    ASSERT_EQ(*i, 2);
    ++i;
    ASSERT_EQ(*i, 3);
    ++i;
    ASSERT_EQ(*i, 5);
    ++i;
    ASSERT_EQ(*i, 6);
    ASSERT_EQ(l2.size(), 1);
    i = l2.begin();
    ASSERT_EQ(*i, 4);
  }
}

// [remove]

namespace test_list_helper {
class class_for_remove final {
  std::int32_t *m_int;

public:
  class_for_remove(std::int32_t i) : m_int(std::make_unique<std::int32_t>(i).release()) {
  }

  class_for_remove(class_for_remove const &rhs) : m_int(std::make_unique<std::int32_t>(*rhs.m_int).release()) {
  }

  class_for_remove &operator=(class_for_remove const &rhs) & noexcept {
    *m_int = *rhs.m_int;
    return *this;
  }

  ~class_for_remove() {
    delete m_int;
    m_int = NULL;
  }

  bool operator==(class_for_remove const &rhs) const noexcept {
    return *m_int == *rhs.m_int;
  }

  std::int32_t get() const noexcept {
    return *m_int;
  }
};
} // namespace test_list_helper

// size_type remove(const value_type& value);
TEST(list, remove) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {1, 2, 3, 4};
    std::int32_t a2[] = {1, 2, 4};

    /**
     * @brief Alias.
     */
    using t_list = ::portable_stl::list<std::int32_t>;
    t_list lst(a1, a1 + 4);
    ASSERT_EQ(1, lst.remove(3));
    // ASSERT_TRUE((std::is_same<typename L::size_type, decltype(lst.remove(3))>{}));

    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + 3), lst);
  }
  { // LWG issue #526
    std::int32_t                       a1[] = {1, 2, 1, 3, 5, 8, 11};
    std::int32_t                       a2[] = {2, 3, 5, 8, 11};
    ::portable_stl::list<std::int32_t> lst(a1, a1 + 7);
    lst.remove(lst.front());
    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + 5), lst);
  }
  {
    std::int32_t                                             a1[] = {1, 2, 1, 3, 5, 8, 11, 1};
    std::int32_t                                             a2[] = {2, 3, 5, 8, 11};
    ::portable_stl::list<test_list_helper::class_for_remove> lst;
    for (std::int32_t *ip = a1; ip < a1 + 8; ++ip) {
      lst.push_back(test_list_helper::class_for_remove(*ip));
    }
    ASSERT_EQ(3, lst.remove(lst.front()));

    auto iter = lst.begin();
    for (std::int32_t *ip = a2; ip < a2 + 5; ++ip, ++iter) {
      ASSERT_NE(iter, lst.end());
      ASSERT_EQ(*ip, iter->get());
    }
    ASSERT_EQ(lst.end(), iter);
  }
}

namespace test_list_helper {
static bool even(std::int32_t i) {
  return i % 2 == 0;
}

static bool g(std::int32_t i) {
  return i < 3;
}

static bool g2(std::int32_t lhv, std::int32_t rhv) {
  return lhv == rhv;
}

class PredLWG526 final {
  std::int32_t m_int;

public:
  PredLWG526(std::int32_t i) : m_int(i) {
  }

  PredLWG526(PredLWG526 const &other) = default;

  ~PredLWG526() {
    m_int = -32767;
  }

  bool operator()(PredLWG526 const &p) const noexcept {
    return p.m_int == m_int;
  }

  bool operator()(PredLWG526 const &lhs, PredLWG526 const &rhs) const {
    return lhs.m_int == rhs.m_int;
  }

  bool operator==(std::int32_t i) const noexcept {
    return i == m_int;
  }
};

template<typename t_pred, typename t_arg> class unary_counting_predicate final {
  t_pred              m_pred;
  mutable std::size_t m_count;

public:
  typedef t_arg argument_type;
  typedef bool  result_type;

  unary_counting_predicate(t_pred p) : m_pred(p), m_count(0) {
  }
  unary_counting_predicate(unary_counting_predicate const &)            = default;
  unary_counting_predicate &operator=(unary_counting_predicate const &) = default;
  ~unary_counting_predicate() {
  }

  bool operator()(t_arg const &a) const {
    ++m_count;
    return m_pred(a);
  }
  std::size_t count() const {
    return m_count;
  }
  void reset() {
    m_count = 0;
  }
};

using Predicate = unary_counting_predicate<bool (*)(std::int32_t), std::int32_t>;

} // namespace test_list_helper

// size_type remove_if(Pred pred);
TEST(list, remove_pred) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief
     *
     */
    using t_list = ::portable_stl::list<std::int32_t>;

    std::int32_t a1[] = {1, 2, 3, 4};
    std::int32_t a2[] = {3, 4};

    t_list                      lst(a1, a1 + 4);
    test_list_helper::Predicate cout_pred(test_list_helper::g);
    ASSERT_TRUE((std::is_same<t_list::size_type, decltype(lst.remove_if(std::ref(cout_pred)))>{}));
    ASSERT_EQ(2, lst.remove_if(std::ref(cout_pred)));

    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + 2), lst);
    ASSERT_EQ(4, cout_pred.count());
  }

  {
    std::int32_t a1[] = {1, 2, 3, 4};
    std::int32_t a2[] = {1, 3};

    ::portable_stl::list<std::int32_t> lst(a1, a1 + 4);

    test_list_helper::Predicate cout_pred(test_list_helper::even);

    ASSERT_EQ(2, lst.remove_if(std::ref(cout_pred)));
    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + 2), lst);

    ASSERT_EQ(4, cout_pred.count());
  }

  { // LWG issue #526
    std::int32_t a1[] = {1, 2, 1, 3, 5, 8, 11};
    std::int32_t a2[] = {2, 3, 5, 8, 11};

    ::portable_stl::list<test_list_helper::PredLWG526> lst(a1, a1 + 7);

    lst.remove_if(lst.front());
    ASSERT_EQ(5U, lst.size());
    for (std::size_t i{0U}; i < lst.size(); ++i) {
      ASSERT_EQ(lst.front(), a2[i]); // do not change order
      lst.pop_front();
    }
  }
}

// [reverse]

// void reverse() noexcept;
TEST(list, reverse) {
  static_cast<void>(test_info_);

  // one element
  {
    ::portable_stl::list<std::int32_t> lst{9};

    lst.reverse();

    ASSERT_EQ((::portable_stl::list<std::int32_t>{9}), lst);
  }

  {
    ::portable_stl::list<std::int32_t> lst{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst.reverse();
    ASSERT_EQ((::portable_stl::list<std::int32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}), lst);
  }
}

// [unique]

// size_type unique();
TEST(list, unique) {
  static_cast<void>(test_info_);

  std::int32_t a1[] = {2, 1, 1, 4, 4, 4, 4, 3, 3};
  std::int32_t a2[] = {2, 1, 4, 3};
  using t_list      = ::portable_stl::list<std::int32_t>;

  t_list lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));

  ASSERT_TRUE((std::is_same<t_list::size_type, decltype(lst.unique())>{}));
  ASSERT_EQ(5, lst.unique());

  ASSERT_EQ(t_list(a2, a2 + 4), lst);
}

// template <class BinaryPred> size_type unique(BinaryPred pred);
TEST(list, unique_pred) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {2, 1, 1, 4, 4, 4, 4, 3, 3};
    std::int32_t a2[] = {2, 1, 4, 3};
    using t_list      = ::portable_stl::list<std::int32_t>;
    t_list lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ASSERT_TRUE((std::is_same<t_list::size_type, decltype(lst.unique(test_list_helper::g2))>{}));
    ASSERT_EQ(5, lst.unique(test_list_helper::g2));
    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + 4), lst);
  }

  { // LWG issue #526
    std::int32_t                                         a1[] = {1, 1, 1, 2, 3, 5, 5, 2, 11};
    std::int32_t                                         a2[] = {1, 2, 3, 5, 2, 11};
    ::portable_stl::list<::test_list_helper::PredLWG526> lst(a1, a1 + 9);
    ASSERT_EQ(3, lst.unique(std::ref(lst.front())));

    ASSERT_EQ(6, lst.size());
    for (std::size_t i{0U}; i < lst.size(); ++i) {
      ASSERT_EQ(lst.front(), a2[i]); // do not change order
      lst.pop_front();
    }
  }
}

// [sort]

namespace test_list_helper {
class SortPayload final {
  std::int32_t m_val;

public:
  SortPayload(std::int32_t v) : m_val(v), m_side(0) {
  }

  SortPayload(std::int32_t v, std::int32_t s) : m_val(v), m_side(s) {
  }

  bool operator<(SortPayload const &rhs) const {
    return m_val < rhs.m_val;
  }

  std::int32_t getVal() const noexcept {
    return m_val;
  }

  std::int32_t m_side;
  //     bool operator==(const SortPayload &rhs) const { return val == rhs.val;}
};

static bool greater(SortPayload const &lhs, SortPayload const &rhs) {
  return lhs.getVal() > rhs.getVal();
}

static void test_stable(std::int32_t num) {
  std::mt19937 randomness;

  using t_type       = SortPayload;
  using t_list       = ::portable_stl::list<t_type>;
  using t_vector     = ::portable_stl::vector<t_type>;
  using t_vector_std = std::vector<t_type>;

  t_vector_std vec_std;
  for (std::int32_t i{0}; i < num; ++i) {
    vec_std.push_back(SortPayload(i / 2));
  }

  std::shuffle(vec_std.begin(), vec_std.end(), randomness);
  t_vector vec;
  for (auto &i : vec_std) {
    vec.push_back(i);
  }

  for (std::int32_t i{0}; i < num; ++i) {
    vec[static_cast<::portable_stl::size_t>(i)].m_side = i;
  }

  t_list lst(vec.begin(), vec.end());
  lst.sort();
  ASSERT_EQ(num, ::portable_stl::distance(lst.begin(), lst.end()));

  //  Are we sorted?
  typename t_list::const_iterator j = lst.begin();
  for (std::int32_t i{0}; i < num; ++i, ++j) {
    ASSERT_EQ((i / 2), j->getVal());
  }

  //  Are we stable?
  for (t_list::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    t_list::const_iterator next = ::portable_stl::next(it);
    if ((next != lst.end()) && (it->getVal() == next->getVal())) {
      ASSERT_TRUE(it->m_side < next->m_side);
    }
  }
}

static void test_stable2(std::int32_t num) {
  std::mt19937 randomness;

  using t_type       = SortPayload;
  using t_list       = ::portable_stl::list<t_type>;
  using t_vector     = ::portable_stl::vector<t_type>;
  using t_vector_std = std::vector<t_type>;

  t_vector_std vec_std;
  for (std::int32_t i{0}; i < num; ++i) {
    vec_std.push_back(SortPayload(i / 2));
  }

  std::shuffle(vec_std.begin(), vec_std.end(), randomness);
  t_vector vec;
  for (auto &i : vec_std) {
    vec.push_back(i);
  }

  for (std::int32_t i{0}; i < num; ++i) {
    vec[static_cast<::portable_stl::size_t>(i)].m_side = i;
  }

  t_list lst(vec.begin(), vec.end());
  lst.sort(greater);
  ASSERT_EQ(num, ::portable_stl::distance(lst.begin(), lst.end()));

  //  Are we sorted?
  typename t_list::const_iterator j = lst.begin();
  for (std::int32_t i{0}; i < num; ++i, ++j) {
    ASSERT_EQ(j->getVal(), (num - 1 - i) / 2);
  }

  //  Are we stable?
  for (t_list::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    t_list::const_iterator next = ::portable_stl::next(it);
    if ((next != lst.end()) && (it->getVal() == next->getVal())) {
      ASSERT_TRUE(it->m_side < next->m_side);
    }
  }
}
} // namespace test_list_helper

// void sort();
TEST(list, sort) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {4, 8, 1, 0, 5, 7, 2, 3, 6, 11, 10, 9};
    std::int32_t a2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    ::portable_stl::list<std::int32_t> lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    lst.sort();
    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), lst);
  }

  {
    for (int i{0}; i < 40; ++i) {
      test_list_helper::test_stable(i);
    }
  }
}

// template <class Compare> sort(Compare comp);
TEST(list, sort_comp) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {4, 8, 1, 0, 5, 7, 2, 3, 6, 11, 10, 9};
    std::int32_t a2[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    ::portable_stl::list<std::int32_t> lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    lst.sort(std::greater<int>());
    ASSERT_EQ(::portable_stl::list<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), lst);
  }

  {
    for (int i{0}; i < 40; ++i) {
      test_list_helper::test_stable2(i);
    }
  }
}
