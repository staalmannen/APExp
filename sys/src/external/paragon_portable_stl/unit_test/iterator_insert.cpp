// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_insert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <vector>

#include "iterator_helper.h"
#include "portable_stl/iterator/back_insert_iterator.h"
#include "portable_stl/iterator/front_insert_iterator.h"
#include "portable_stl/iterator/insert_iterator.h"

namespace index_helpers {
constexpr std::int32_t el_2{2};
constexpr std::int32_t el_3{3};
} // namespace index_helpers

TEST(insert_iterator, back_insert_iterator_ctor) {
  static_cast<void>(test_info_);

  std::vector<std::int32_t> test_vector;
  auto const                bii = ::portable_stl::back_inserter(test_vector);
  static_cast<void>(bii);

  ::portable_stl::back_insert_iterator<std::vector<std::int32_t>> const bii2;
  static_cast<void>(bii2);
}

TEST(insert_iterator, back_insert_iterator_inserts) {
  static_cast<void>(test_info_);

  std::vector<std::int32_t> test_vector;
  auto                      back_ins = ::portable_stl::back_inserter(test_vector);

  std::int32_t insert_value{1};
  back_ins = insert_value;
  back_ins = 0;
  back_ins = 1;

  ASSERT_EQ(index_helpers::el_3, test_vector.size());
  EXPECT_EQ(insert_value, test_vector[0]);
  EXPECT_EQ(0, test_vector[1]);
  EXPECT_EQ(1, test_vector[index_helpers::el_2]);
}

TEST(insert_iterator, back_insert_iterator_deref) {
  static_cast<void>(test_info_);

  std::vector<std::int32_t> test_vector;
  auto                      back_ins = ::portable_stl::back_inserter(test_vector);

  auto &deref = *back_ins;
  EXPECT_EQ(&deref, &back_ins);
}

TEST(insert_iterator, back_insert_iterator_inc) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using back_ins_type = ::portable_stl::back_insert_iterator<std::vector<std::int32_t>>;
  std::vector<std::int32_t> test_vector;
  back_ins_type             back_ins{test_vector};

  back_ins_type  inc{back_ins++};
  back_ins_type &inc2{++inc};

  EXPECT_EQ(&inc, &inc2);

  // check through underlying container
  back_ins = 1;
  inc      = 1;
  inc2     = 1;

  EXPECT_EQ(index_helpers::el_3, test_vector.size());
}

TEST(insert_iterator, front_insert_iterator_ctor) {
  static_cast<void>(test_info_);

  std::deque<std::int32_t> test_deq;
  auto const               fii = ::portable_stl::front_inserter(test_deq);
  static_cast<void>(fii);

  ::portable_stl::front_insert_iterator<std::vector<std::int32_t>> const fii2;
  static_cast<void>(fii2);
}

TEST(insert_iterator, front_insert_iterator_inserts) {
  static_cast<void>(test_info_);

  std::deque<std::int32_t> test_deq;
  auto                     front_ins = ::portable_stl::front_inserter(test_deq);

  std::int32_t insert_value{index_helpers::el_2};
  front_ins = insert_value;
  front_ins = 0;
  front_ins = 1;

  ASSERT_EQ(index_helpers::el_3, test_deq.size());
  EXPECT_EQ(1, test_deq[0]);
  EXPECT_EQ(0, test_deq[1]);
  EXPECT_EQ(insert_value, test_deq[index_helpers::el_2]);
}

TEST(insert_iterator, front_insert_iterator_deref) {
  static_cast<void>(test_info_);

  std::deque<std::int32_t> test_deq;
  auto                     front_ins = ::portable_stl::front_inserter(test_deq);

  auto &deref = *front_ins;
  EXPECT_EQ(&deref, &front_ins);
}

TEST(insert_iterator, front_insert_iterator_inc) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using back_ins_type = ::portable_stl::front_insert_iterator<std::deque<std::int32_t>>;
  std::deque<std::int32_t> test_deq;
  back_ins_type            front_ins{test_deq};

  back_ins_type  inc{front_ins++};
  back_ins_type &inc2{++inc};

  EXPECT_EQ(&inc, &inc2);

  // check through underlying container
  front_ins = 1;
  inc       = 1;
  inc2      = 1;

  EXPECT_EQ(index_helpers::el_3, test_deq.size());
}

TEST(insert_iterator, insert_iterator_ctor) {
  static_cast<void>(test_info_);

  test_iterator_helper::container_with_insert cont;

  auto const ins_iter = ::portable_stl::inserter(cont, cont.begin());
  static_cast<void>(ins_iter);

  ::portable_stl::insert_iterator<test_iterator_helper::container_with_insert> const ins_iter2{cont, cont.begin()};
  static_cast<void>(ins_iter2);
}

TEST(insert_iterator, insert_iterator_inserts) {
  static_cast<void>(test_info_);

  test_iterator_helper::container_with_insert             cont;
  auto                                                    ins_iter = ::portable_stl::inserter(cont, cont.begin());
  test_iterator_helper::container_with_insert::value_type value{0};
  ins_iter = value; // lvalue
  ins_iter = 0;     // rvalue
  ins_iter = 1;

  ASSERT_EQ(index_helpers::el_3, cont.size());

  value    = 1;
  ins_iter = value;
}

TEST(insert_iterator, insert_iterator_deref) {
  static_cast<void>(test_info_);

  test_iterator_helper::container_with_insert cont;
  auto                                        ins_iter = ::portable_stl::inserter(cont, cont.begin());

  auto const &deref = *ins_iter;
  static_cast<void>(deref);
}

TEST(insert_iterator, insert_iterator_inc) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using back_ins_type = ::portable_stl::insert_iterator<test_iterator_helper::container_with_insert>;
  test_iterator_helper::container_with_insert cont;
  auto                                        ins_iter = ::portable_stl::inserter(cont, cont.begin());

  back_ins_type  inc{ins_iter++};
  back_ins_type &inc2{++inc};

  EXPECT_EQ(&inc, &inc2);

  // check through underlying container
  ins_iter = 1;
  inc      = 1;
  inc2     = 1;

  EXPECT_EQ(index_helpers::el_3, cont.size());
}
