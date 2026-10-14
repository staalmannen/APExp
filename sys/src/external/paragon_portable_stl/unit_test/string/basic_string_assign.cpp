// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_assign.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "basic_string_test_helper.h"
#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"
#include "portable_stl/string/basic_string.h"
#include "portable_stl/string/char_traits.h"

// [operator=]

// (1)
TEST(basic_string, assign_operator_copy) {
  static_cast<void>(test_info_);

  TString s0{test_string_helper::test_string1};

  {
    TString s;
    s = s0;

    ASSERT_EQ(s0.size(), s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    s = s0;

    ASSERT_EQ(s0.size(), s.size());
    EXPECT_TRUE(s0 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  TString s1{test_string_helper::test_string2};
  {
    TString s;
    s = s1;

    ASSERT_EQ(s1.size(), s.size());
    EXPECT_TRUE(s1 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};
    try {
      s = s1;
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = s1;
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (2)
TEST(basic_string, assign_operator_move) {
  static_cast<void>(test_info_);

  {
    TString s0{test_string_helper::test_string1};
    TString s;
    s = std::move(s0);

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TString s0{test_string_helper::test_string1};
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    s = std::move(s0);

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s1{test_string_helper::test_string2};
    TString s;
    s = std::move(s1);

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // reuse old (moved) storage
  {
    TString s1{test_string_helper::test_string2};
    TString s{"abc"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = std::move(s1);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // reuse old (moved) storage
  {
    TString s1{test_string_helper::test_string2};
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = std::move(s1);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // reuse (moved) old small storage
  {
    TString s1{"abc"};
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = std::move(s1);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (3)
TEST(basic_string, assign_operator_pointer) {
  static_cast<void>(test_info_);

  {
    TString s;
    s = test_string_helper::test_string1;

    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    s = test_string_helper::test_string1;

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    s = test_string_helper::test_string2;

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};
    try {
      s = test_string_helper::test_string2;
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = test_string_helper::test_string2;
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (4)
TEST(basic_string, assign_operator_char) {
  static_cast<void>(test_info_);

  {
    TString s;
    s = 'g';

    ASSERT_EQ(1, s.size());
    ASSERT_TRUE("g" == s);
  }
  {
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    s = 'g';

    ASSERT_EQ(1, s.size());
    EXPECT_TRUE("g" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    s = 'g';

    ASSERT_EQ(1, s.size());
    EXPECT_TRUE("g" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (5)
TEST(basic_string, assign_operator_initializer_list) {
  static_cast<void>(test_info_);

  {
    TString s;
    s = {'1', '2', '3', '4', '5', '6'};

    ASSERT_EQ(6, s.size());
    ASSERT_TRUE("123456" == s);
  }
  {
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    s = {'1', '2', '3', '4', '5', '6'};

    ASSERT_EQ(6, s.size());
    ASSERT_TRUE("123456" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    s = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
         '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'};

    ASSERT_EQ(25, s.size());
    EXPECT_TRUE(s == "1234567890123456789012345");
  }

  // new storage allocation failure.
  {
    TString s{"abc"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
           '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'};
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
           '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'};
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (6)
TEST(basic_string, assign_operator_string_view) {
  static_cast<void>(test_info_);

  // Alias for string view type.
  using TStringView2 = typename TString::view_type;

  {
    TString s;
    s = TStringView2(test_string_helper::test_string1);

    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    s = TStringView2(test_string_helper::test_string1);

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    s = TStringView2(test_string_helper::test_string2);

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};
    try {
      s = TStringView2(test_string_helper::test_string2);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s = TStringView2(test_string_helper::test_string2);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

// [assign]

TEST(basic_string, assign_count_char) {
  static_cast<void>(test_info_);

  {
    TString s;
    auto    result = s.assign(0, 'g');

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.size());
    EXPECT_TRUE("" == result.value().get());
    ASSERT_TRUE("" == s);
  }
  {
    TString s;
    auto    result = s.assign(1, 'g');

    ASSERT_TRUE(result);
    ASSERT_EQ(1, s.size());
    EXPECT_TRUE("g" == result.value().get());
    ASSERT_TRUE("g" == s);
  }
  {
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(5, 'g');

    ASSERT_TRUE(result);
    ASSERT_EQ(5, s.size());
    EXPECT_TRUE("ggggg" == result.value().get());
    ASSERT_TRUE("ggggg" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
  {
    TString s;

    auto result = s.assign(test_string_helper::chars_in_SSO, 'a');

    ASSERT_TRUE(result);
    ASSERT_EQ(test_string_helper::chars_in_SSO, s.size());
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == result.value().get());
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(25, 'g');
    EXPECT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"abc"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(25, 'g');
    EXPECT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_string) {
  static_cast<void>(test_info_);

  TString s0{test_string_helper::test_string1};

  {
    TString s;
    auto    result = s.assign(s0);

    ASSERT_TRUE(result);
    ASSERT_EQ(s0.size(), s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(s0);

    ASSERT_TRUE(result);
    ASSERT_EQ(s0.size(), s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  TString s1{test_string_helper::test_string2};
  {
    TString s;
    auto    result = s.assign(s1);

    ASSERT_TRUE(result);
    ASSERT_EQ(s1.size(), s.size());
    EXPECT_TRUE(s1 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(s1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(s1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_string_pos_count) {
  static_cast<void>(test_info_);

  TString s0{test_string_helper::test_string1};

  TMManager::m_counter_ok_allocation = 0;
  {
    TString s;
    auto    result = s.assign(s0, 0, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.size());
    ASSERT_TRUE("" == s);
  }
  {
    TString s;
    auto    result = s.assign(s0, 0, 10);

    ASSERT_TRUE(result);
    ASSERT_EQ(s0.size(), s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TString s;
    auto    result = s.assign(s0, 1, 10);

    ASSERT_TRUE(result);
    ASSERT_EQ(5, s.size());
    ASSERT_TRUE("bcdef" == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(s0, 0, 10);

    ASSERT_TRUE(result);
    ASSERT_EQ(s0.size(), s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);
  }

  TMManager::m_counter_ok_allocation = 100;
  TString s1{test_string_helper::test_string2};
  {
    TString s;
    auto    result = s.assign(s1, 0, 50);

    ASSERT_TRUE(result);
    ASSERT_EQ(s1.size(), s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(s1, 0, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // out of range
  {
    TString s{"abc"};

    auto result = s.assign(s1, 60, 1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(s1, 0, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // out of range before new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(s1, 60, 1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_move) {
  static_cast<void>(test_info_);

  {
    TString s0{test_string_helper::test_string1};
    TString s;
    s.assign(std::move(s0));

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TString s0{test_string_helper::test_string1};
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    s.assign(std::move(s0));

    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s1{test_string_helper::test_string2};
    TString s;
    s.assign(std::move(s1));

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // reuse old (moved) storage
  {
    TString s1{test_string_helper::test_string2};
    TString s{"abc"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s.assign(std::move(s1));
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // reuse old (moved) storage
  {
    TString s1{test_string_helper::test_string2};
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s.assign(std::move(s1));
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // reuse (moved) old small storage
  {
    TString s1{"abc"};
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    try {
      s.assign(std::move(s1));
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }

    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_pointer_count) {
  static_cast<void>(test_info_);

  {
    TString s;
    auto    result = s.assign(test_string_helper::test_string1, 6);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(test_string_helper::test_string1, 6);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign(test_string_helper::test_string2, 50);

    ASSERT_TRUE(result);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(test_string_helper::test_string2, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(test_string_helper::test_string2, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_pointer) {
  static_cast<void>(test_info_);

  {
    TString s;
    auto    result = s.assign(test_string_helper::test_string1);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(test_string_helper::test_string1);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign(test_string_helper::test_string2);

    ASSERT_TRUE(result);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(test_string_helper::test_string2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(test_string_helper::test_string2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_two_iter) {
  static_cast<void>(test_info_);

  {
    TString s;
    auto    result = s.assign(&test_string_helper::test_string1[0], &test_string_helper::test_string1[6]);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(&test_string_helper::test_string1[0], &test_string_helper::test_string1[6]);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign(&test_string_helper::test_string2[0], &test_string_helper::test_string2[50]);

    ASSERT_TRUE(result);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(&test_string_helper::test_string2[0], &test_string_helper::test_string2[50]);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(&test_string_helper::test_string2[0], &test_string_helper::test_string2[50]);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_initializer_list) {
  static_cast<void>(test_info_);

  {
    TString s;
    auto    result = s.assign({'1', '2', '3', '4', '5', '6'});

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE("123456" == s);
  }
  {
    TString s;
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign({'1', '2', '3', '4', '5', '6'});

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE("123456" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign({'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                               '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'});

    ASSERT_TRUE(result);
    ASSERT_EQ(25, s.size());
    EXPECT_TRUE(s == "1234567890123456789012345");
  }

  // new storage allocation failure.
  {
    TString s{"abc"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign({'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                            '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'});
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign({'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                            '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'});
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_string_view) {
  static_cast<void>(test_info_);

  // Alias for string view type.
  using TStringView2 = typename TString::view_type;

  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1));

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1));

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string2));

    ASSERT_TRUE(result);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(TStringView2(test_string_helper::test_string2));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(TStringView2(test_string_helper::test_string2));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, assign_string_view_pos_count) {
  static_cast<void>(test_info_);

  // Alias for string view type.
  using TStringView2 = typename TString::view_type;

  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1), 0, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.size());
    ASSERT_TRUE("" == s);
  }
  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1), 1, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, s.size());
    ASSERT_TRUE("b" == s);
  }
  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1), 0, 6);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    ASSERT_TRUE(test_string_helper::test_string1 == s);
  }
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string1), 0, 6);

    ASSERT_TRUE(result);
    ASSERT_EQ(6, s.size());
    EXPECT_TRUE(test_string_helper::test_string1 == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  {
    TString s;
    auto    result = s.assign(TStringView2(test_string_helper::test_string2), 0, 50);

    ASSERT_TRUE(result);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
  }

  // out of range
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(TStringView2(test_string_helper::test_string2), 60, 1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TMManager::m_counter_ok_allocation = 0;

    TString s{"abc"};

    auto result = s.assign(TStringView2(test_string_helper::test_string2), 0, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);

    TMManager::m_counter_ok_allocation = 100;
  }

  // new storage allocation failure.
  {
    TString s{"123456789012345678901234567890"};
    TMManager::m_counter_ok_allocation = 0;

    auto result = s.assign(TStringView2(test_string_helper::test_string2), 0, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // same as before unsuccess assignment.
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);

    TMManager::m_counter_ok_allocation = 100;
  }
}
