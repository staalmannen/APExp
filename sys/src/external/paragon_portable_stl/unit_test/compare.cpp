// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="compare.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <type_traits>

#include "portable_stl/compare/compare_functions.h"
#include "portable_stl/compare/compare_t.h"
#include "portable_stl/compare/not_ordered.h"
#include "portable_stl/compare/ordered.h"
#include "portable_stl/compare/partial_ordering.h"
#include "portable_stl/compare/strong_ordering.h"
#include "portable_stl/compare/unspecified.h"
#include "portable_stl/compare/weak_ordering.h"

TEST(compare, compare_helper_compare_t) {
  static_cast<void>(test_info_);
  ASSERT_FALSE((std::is_same<::portable_stl::compare_helper::compare_t, std::uint8_t>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::compare_helper::compare_t, std::int8_t>{}));
}

TEST(compare, compare_helper_not_ordered) {
  static_cast<void>(test_info_);
  constexpr std::int32_t unordered_value{-127};
  ASSERT_EQ(unordered_value, static_cast<std::int32_t>(::portable_stl::compare_helper::not_ordered::unordered));
}

TEST(compare, compare_helper_ordered) {
  static_cast<void>(test_info_);
  ASSERT_EQ(static_cast<std::int32_t>(::portable_stl::compare_helper::ordered::equal), 0);
  ASSERT_EQ(static_cast<std::int32_t>(::portable_stl::compare_helper::ordered::equivalent), 0);
  ASSERT_LT(static_cast<std::int32_t>(::portable_stl::compare_helper::ordered::less), 0);
  ASSERT_GT(static_cast<std::int32_t>(::portable_stl::compare_helper::ordered::greater), 0);
}

TEST(compare, compare_helper_unspecified) {
  static_cast<void>(test_info_);
  // Check working only with 0 'Zero' literal.
  ::portable_stl::compare_helper::unspecified const test_value{0};
  static_cast<void>(test_value);
}

TEST(compare, partial_ordering) {
  static_cast<void>(test_info_);
  ASSERT_FALSE(
    (::portable_stl::partial_ordering::unordered().operator==(::portable_stl::partial_ordering::equivalent())));
  ASSERT_TRUE(
    (::portable_stl::partial_ordering::unordered().operator==(::portable_stl::partial_ordering::unordered())));

  ASSERT_TRUE(
    (::portable_stl::partial_ordering::unordered().operator!=(::portable_stl::partial_ordering::equivalent())));
  ASSERT_FALSE(
    (::portable_stl::partial_ordering::unordered().operator!=(::portable_stl::partial_ordering::unordered())));

  ASSERT_FALSE((::portable_stl::partial_ordering::unordered().operator==(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::unordered().operator!=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered().operator<(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered().operator<=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered().operator>(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered().operator>=(0)));

  ASSERT_FALSE(
    (::portable_stl::partial_ordering::equivalent().operator==(::portable_stl::partial_ordering::unordered())));
  ASSERT_TRUE(
    (::portable_stl::partial_ordering::equivalent().operator==(::portable_stl::partial_ordering::equivalent())));

  ASSERT_TRUE(
    (::portable_stl::partial_ordering::equivalent().operator!=(::portable_stl::partial_ordering::unordered())));
  ASSERT_FALSE(
    (::portable_stl::partial_ordering::equivalent().operator!=(::portable_stl::partial_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent().operator==(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent().operator!=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent().operator<(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent().operator<=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent().operator>(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent().operator>=(0)));

  ASSERT_FALSE((::portable_stl::partial_ordering::less().operator==(::portable_stl::partial_ordering::unordered())));
  ASSERT_TRUE((::portable_stl::partial_ordering::less().operator==(::portable_stl::partial_ordering::less())));
  ASSERT_TRUE((::portable_stl::partial_ordering::less().operator!=(::portable_stl::partial_ordering::unordered())));
  ASSERT_FALSE((::portable_stl::partial_ordering::less().operator!=(::portable_stl::partial_ordering::less())));

  ASSERT_FALSE((::portable_stl::partial_ordering::less().operator==(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::less().operator!=(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::less().operator<(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::less().operator<=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::less().operator>(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::less().operator>=(0)));

  ASSERT_TRUE((::portable_stl::partial_ordering::greater().operator==(::portable_stl::partial_ordering::greater())));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater().operator==(::portable_stl::partial_ordering::unordered())));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater().operator!=(::portable_stl::partial_ordering::greater())));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater().operator!=(::portable_stl::partial_ordering::unordered())));

  ASSERT_FALSE((::portable_stl::partial_ordering::greater().operator==(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater().operator!=(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater().operator<(0)));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater().operator<=(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater().operator>(0)));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater().operator>=(0)));

  ASSERT_NE(::portable_stl::partial_ordering::unordered(), ::portable_stl::partial_ordering::equivalent());
  ASSERT_EQ(::portable_stl::partial_ordering::equivalent(), ::portable_stl::partial_ordering::equivalent());

  ASSERT_FALSE((::portable_stl::partial_ordering::unordered() == 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::unordered() != 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered() < 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered() > 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered() <= 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::unordered() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::partial_ordering::unordered()));
  ASSERT_TRUE((0 != ::portable_stl::partial_ordering::unordered()));
  ASSERT_FALSE((0 < ::portable_stl::partial_ordering::unordered()));
  ASSERT_FALSE((0 > ::portable_stl::partial_ordering::unordered()));
  ASSERT_FALSE((0 <= ::portable_stl::partial_ordering::unordered()));
  ASSERT_FALSE((0 >= ::portable_stl::partial_ordering::unordered()));

  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent() == 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent() != 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent() < 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::equivalent() > 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent() <= 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::equivalent() >= 0));

  ASSERT_TRUE((0 == ::portable_stl::partial_ordering::equivalent()));
  ASSERT_FALSE((0 != ::portable_stl::partial_ordering::equivalent()));
  ASSERT_FALSE((0 < ::portable_stl::partial_ordering::equivalent()));
  ASSERT_FALSE((0 > ::portable_stl::partial_ordering::equivalent()));
  ASSERT_TRUE((0 <= ::portable_stl::partial_ordering::equivalent()));
  ASSERT_TRUE((0 >= ::portable_stl::partial_ordering::equivalent()));

  ASSERT_FALSE((::portable_stl::partial_ordering::less() == 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::less() != 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::less() < 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::less() > 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::less() <= 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::less() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::partial_ordering::less()));
  ASSERT_TRUE((0 != ::portable_stl::partial_ordering::less()));
  ASSERT_FALSE((0 < ::portable_stl::partial_ordering::less()));
  ASSERT_TRUE((0 > ::portable_stl::partial_ordering::less()));
  ASSERT_FALSE((0 <= ::portable_stl::partial_ordering::less()));
  ASSERT_TRUE((0 >= ::portable_stl::partial_ordering::less()));

  ASSERT_FALSE((::portable_stl::partial_ordering::greater() == 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater() != 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater() < 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater() > 0));
  ASSERT_FALSE((::portable_stl::partial_ordering::greater() <= 0));
  ASSERT_TRUE((::portable_stl::partial_ordering::greater() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::partial_ordering::greater()));
  ASSERT_TRUE((0 != ::portable_stl::partial_ordering::greater()));
  ASSERT_TRUE((0 < ::portable_stl::partial_ordering::greater()));
  ASSERT_FALSE((0 > ::portable_stl::partial_ordering::greater()));
  ASSERT_TRUE((0 <= ::portable_stl::partial_ordering::greater()));
  ASSERT_FALSE((0 >= ::portable_stl::partial_ordering::greater()));
}

TEST(compare, weak_ordering) {
  static_cast<void>(test_info_);

  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent().operator==(::portable_stl::weak_ordering::less())));
  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent().operator==(::portable_stl::weak_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent().operator!=(::portable_stl::weak_ordering::less())));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent().operator!=(::portable_stl::weak_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent().operator==(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent().operator!=(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent().operator<(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent().operator<=(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent().operator>(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent().operator>=(0)));

  ASSERT_FALSE((::portable_stl::weak_ordering::less().operator==(::portable_stl::weak_ordering::equivalent())));
  ASSERT_TRUE((::portable_stl::weak_ordering::less().operator==(::portable_stl::weak_ordering::less())));
  ASSERT_TRUE((::portable_stl::weak_ordering::less().operator!=(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::weak_ordering::less().operator!=(::portable_stl::weak_ordering::less())));

  ASSERT_FALSE((::portable_stl::weak_ordering::less().operator==(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::less().operator!=(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::less().operator<(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::less().operator<=(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::less().operator>(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::less().operator>=(0)));

  ASSERT_TRUE((::portable_stl::weak_ordering::greater().operator==(::portable_stl::weak_ordering::greater())));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater().operator==(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater().operator!=(::portable_stl::weak_ordering::greater())));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater().operator!=(::portable_stl::weak_ordering::equivalent())));

  ASSERT_FALSE((::portable_stl::weak_ordering::greater().operator==(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater().operator!=(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater().operator<(0)));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater().operator<=(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater().operator>(0)));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater().operator>=(0)));

  ASSERT_NE(::portable_stl::weak_ordering::greater(), ::portable_stl::weak_ordering::equivalent());
  ASSERT_EQ(::portable_stl::weak_ordering::equivalent(), ::portable_stl::weak_ordering::equivalent());

  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent() == 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent() != 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent() < 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::equivalent() > 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent() <= 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::equivalent() >= 0));

  ASSERT_TRUE((0 == ::portable_stl::weak_ordering::equivalent()));
  ASSERT_FALSE((0 != ::portable_stl::weak_ordering::equivalent()));
  ASSERT_FALSE((0 < ::portable_stl::weak_ordering::equivalent()));
  ASSERT_FALSE((0 > ::portable_stl::weak_ordering::equivalent()));
  ASSERT_TRUE((0 <= ::portable_stl::weak_ordering::equivalent()));
  ASSERT_TRUE((0 >= ::portable_stl::weak_ordering::equivalent()));

  ASSERT_FALSE((::portable_stl::weak_ordering::less() == 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::less() != 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::less() < 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::less() > 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::less() <= 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::less() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::weak_ordering::less()));
  ASSERT_TRUE((0 != ::portable_stl::weak_ordering::less()));
  ASSERT_FALSE((0 < ::portable_stl::weak_ordering::less()));
  ASSERT_TRUE((0 > ::portable_stl::weak_ordering::less()));
  ASSERT_FALSE((0 <= ::portable_stl::weak_ordering::less()));
  ASSERT_TRUE((0 >= ::portable_stl::weak_ordering::less()));

  ASSERT_FALSE((::portable_stl::weak_ordering::greater() == 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater() != 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater() < 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater() > 0));
  ASSERT_FALSE((::portable_stl::weak_ordering::greater() <= 0));
  ASSERT_TRUE((::portable_stl::weak_ordering::greater() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::weak_ordering::greater()));
  ASSERT_TRUE((0 != ::portable_stl::weak_ordering::greater()));
  ASSERT_TRUE((0 < ::portable_stl::weak_ordering::greater()));
  ASSERT_FALSE((0 > ::portable_stl::weak_ordering::greater()));
  ASSERT_TRUE((0 <= ::portable_stl::weak_ordering::greater()));
  ASSERT_FALSE((0 >= ::portable_stl::weak_ordering::greater()));
}

TEST(compare, strong_ordering) {
  static_cast<void>(test_info_);

  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent().operator==(::portable_stl::strong_ordering::less())));
  ASSERT_TRUE(
    (::portable_stl::strong_ordering::equivalent().operator==(::portable_stl::strong_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent().operator!=(::portable_stl::strong_ordering::less())));
  ASSERT_FALSE(
    (::portable_stl::strong_ordering::equivalent().operator!=(::portable_stl::strong_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent().operator==(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent().operator!=(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent().operator<(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent().operator<=(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent().operator>(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent().operator>=(0)));

  ASSERT_FALSE((::portable_stl::strong_ordering::less().operator==(::portable_stl::strong_ordering::equivalent())));
  ASSERT_TRUE((::portable_stl::strong_ordering::less().operator==(::portable_stl::strong_ordering::less())));
  ASSERT_TRUE((::portable_stl::strong_ordering::less().operator!=(::portable_stl::strong_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::strong_ordering::less().operator!=(::portable_stl::strong_ordering::less())));

  ASSERT_FALSE((::portable_stl::strong_ordering::less().operator==(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::less().operator!=(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::less().operator<(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::less().operator<=(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::less().operator>(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::less().operator>=(0)));

  ASSERT_TRUE((::portable_stl::strong_ordering::greater().operator==(::portable_stl::strong_ordering::greater())));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater().operator==(::portable_stl::strong_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater().operator!=(::portable_stl::strong_ordering::greater())));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater().operator!=(::portable_stl::strong_ordering::equivalent())));

  ASSERT_FALSE((::portable_stl::strong_ordering::greater().operator==(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater().operator!=(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater().operator<(0)));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater().operator<=(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater().operator>(0)));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater().operator>=(0)));

  ASSERT_NE(::portable_stl::strong_ordering::greater(), ::portable_stl::strong_ordering::equivalent());
  ASSERT_EQ(::portable_stl::strong_ordering::equivalent(), ::portable_stl::strong_ordering::equivalent());

  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent() == 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent() != 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent() < 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::equivalent() > 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent() <= 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::equivalent() >= 0));

  ASSERT_TRUE((0 == ::portable_stl::strong_ordering::equivalent()));
  ASSERT_FALSE((0 != ::portable_stl::strong_ordering::equivalent()));
  ASSERT_FALSE((0 < ::portable_stl::strong_ordering::equivalent()));
  ASSERT_FALSE((0 > ::portable_stl::strong_ordering::equivalent()));
  ASSERT_TRUE((0 <= ::portable_stl::strong_ordering::equivalent()));
  ASSERT_TRUE((0 >= ::portable_stl::strong_ordering::equivalent()));

  ASSERT_FALSE((::portable_stl::strong_ordering::less() == 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::less() != 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::less() < 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::less() > 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::less() <= 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::less() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::strong_ordering::less()));
  ASSERT_TRUE((0 != ::portable_stl::strong_ordering::less()));
  ASSERT_FALSE((0 < ::portable_stl::strong_ordering::less()));
  ASSERT_TRUE((0 > ::portable_stl::strong_ordering::less()));
  ASSERT_FALSE((0 <= ::portable_stl::strong_ordering::less()));
  ASSERT_TRUE((0 >= ::portable_stl::strong_ordering::less()));

  ASSERT_FALSE((::portable_stl::strong_ordering::greater() == 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater() != 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater() < 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater() > 0));
  ASSERT_FALSE((::portable_stl::strong_ordering::greater() <= 0));
  ASSERT_TRUE((::portable_stl::strong_ordering::greater() >= 0));

  ASSERT_FALSE((0 == ::portable_stl::strong_ordering::greater()));
  ASSERT_TRUE((0 != ::portable_stl::strong_ordering::greater()));
  ASSERT_TRUE((0 < ::portable_stl::strong_ordering::greater()));
  ASSERT_FALSE((0 > ::portable_stl::strong_ordering::greater()));
  ASSERT_TRUE((0 <= ::portable_stl::strong_ordering::greater()));
  ASSERT_FALSE((0 >= ::portable_stl::strong_ordering::greater()));
}

TEST(compare, ordering_conversions) {
  static_cast<void>(test_info_);
  ASSERT_EQ(::portable_stl::weak_ordering::equivalent(), ::portable_stl::strong_ordering::equal());
  ASSERT_EQ(::portable_stl::weak_ordering::equivalent(), ::portable_stl::strong_ordering::equivalent());
  ASSERT_EQ(::portable_stl::partial_ordering::equivalent(), ::portable_stl::strong_ordering::equal());
  ASSERT_EQ(::portable_stl::partial_ordering::equivalent(), ::portable_stl::strong_ordering::equivalent());
  ASSERT_EQ(::portable_stl::weak_ordering::less(), ::portable_stl::strong_ordering::less());
  ASSERT_EQ(::portable_stl::weak_ordering::greater(), ::portable_stl::strong_ordering::greater());
  ASSERT_EQ(::portable_stl::partial_ordering::less(), ::portable_stl::strong_ordering::less());
  ASSERT_EQ(::portable_stl::partial_ordering::greater(), ::portable_stl::strong_ordering::greater());

  ASSERT_EQ(::portable_stl::partial_ordering::equivalent(), ::portable_stl::weak_ordering::equivalent());
  ASSERT_EQ(::portable_stl::partial_ordering::less(), ::portable_stl::weak_ordering::less());
  ASSERT_EQ(::portable_stl::partial_ordering::greater(), ::portable_stl::weak_ordering::greater());
}

TEST(compare, conversion_functions) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((::portable_stl::is_eq(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::is_eq(::portable_stl::weak_ordering::greater())));

  ASSERT_TRUE((::portable_stl::is_neq(::portable_stl::weak_ordering::greater())));
  ASSERT_FALSE((::portable_stl::is_neq(::portable_stl::weak_ordering::equivalent())));

  ASSERT_TRUE((::portable_stl::is_lt(::portable_stl::weak_ordering::less())));
  ASSERT_FALSE((::portable_stl::is_lt(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::is_lt(::portable_stl::weak_ordering::greater())));

  ASSERT_TRUE((::portable_stl::is_lteq(::portable_stl::weak_ordering::less())));
  ASSERT_TRUE((::portable_stl::is_lteq(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::is_lteq(::portable_stl::weak_ordering::greater())));

  ASSERT_TRUE((::portable_stl::is_gt(::portable_stl::weak_ordering::greater())));
  ASSERT_FALSE((::portable_stl::is_gt(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::is_gt(::portable_stl::weak_ordering::less())));

  ASSERT_TRUE((::portable_stl::is_gteq(::portable_stl::weak_ordering::greater())));
  ASSERT_TRUE((::portable_stl::is_gteq(::portable_stl::weak_ordering::equivalent())));
  ASSERT_FALSE((::portable_stl::is_gteq(::portable_stl::weak_ordering::less())));
}
