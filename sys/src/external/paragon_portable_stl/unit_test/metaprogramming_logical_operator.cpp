// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_logical_operator.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/logical_operator/bool_constant_get.h"
#include "portable_stl/metaprogramming/logical_operator/conjunction.h"
#include "portable_stl/metaprogramming/logical_operator/disjunction.h"
#include "portable_stl/metaprogramming/logical_operator/negation.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_logical_operator_inline_variables.h"
#else
#  include "metaprogramming_logical_operator.h"
#endif

TEST(metaprogramming_logical_operator, bool_constant_get) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((::portable_stl::bool_constant_get<std::true_type>{}()));
  ASSERT_FALSE((::portable_stl::bool_constant_get<std::false_type>{}()));

  ASSERT_TRUE((::portable_stl::bool_constant_get<::portable_stl::true_type>{}()));
  ASSERT_FALSE((::portable_stl::bool_constant_get<::portable_stl::false_type>{}()));

  ASSERT_TRUE(
    (static_cast<bool>(std::is_same<::portable_stl::true_type, ::portable_stl::bool_constant_get<std::true_type>>{})));
  ASSERT_TRUE((
    static_cast<bool>(std::is_same<::portable_stl::false_type, ::portable_stl::bool_constant_get<std::false_type>>{})));
  ASSERT_TRUE((static_cast<bool>(
    std::is_same<::portable_stl::true_type, ::portable_stl::bool_constant_get<::portable_stl::true_type>>{})));
  ASSERT_TRUE((static_cast<bool>(
    std::is_same<::portable_stl::false_type, ::portable_stl::bool_constant_get<::portable_stl::false_type>>{})));
}

TEST(metaprogramming_logical_operator, negation) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((::portable_stl::negation<std::false_type>{}()));
  EXPECT_FALSE((::portable_stl::negation<std::true_type>{}()));
  {
    constexpr ::portable_stl::negation<std::false_type> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::negation<std::true_type> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::negation<std::false_type>::type checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::negation<std::true_type>::type checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  test_metaprogramming_logical_operator::metaprogramming_logical_operator_negation_variables();
}

TEST(metaprogramming_logical_operator, conjunction) {
  static_cast<void>(test_info_);

  /**
   * @brief Not full defined class
   *
   */
  class undefined;

  {
    constexpr ::portable_stl::conjunction<> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::conjunction<std::true_type> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::conjunction<std::true_type, std::true_type, std::false_type> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::conjunction<std::true_type, std::true_type, std::false_type, undefined> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr typename ::portable_stl::conjunction<std::true_type>::type checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr typename ::portable_stl::conjunction<std::true_type, std::true_type, std::false_type, undefined>::type
      checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  ASSERT_FALSE((::portable_stl::conjunction<std::false_type, std::true_type, std::true_type, undefined>{}()));
  ASSERT_FALSE((::portable_stl::conjunction<std::true_type, std::false_type, std::true_type, undefined>{}()));
  ASSERT_FALSE((::portable_stl::conjunction<std::true_type, std::true_type, std::false_type, undefined>{}()));
  ASSERT_TRUE((::portable_stl::conjunction<>{}()));
  ASSERT_TRUE((::portable_stl::conjunction<std::true_type>{}()));
  ASSERT_TRUE((::portable_stl::conjunction<std::true_type, std::true_type>{}()));
  ASSERT_TRUE((::portable_stl::conjunction<std::true_type, std::true_type, std::true_type>{}()));

  test_metaprogramming_logical_operator::metaprogramming_logical_operator_conjunction_variables();
}

TEST(metaprogramming_logical_operator, disjunction) {
  static_cast<void>(test_info_);

  /**
   * @brief Not full defined class
   *
   */
  class undefined;

  {
    constexpr ::portable_stl::disjunction<> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::disjunction<std::true_type> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr ::portable_stl::disjunction<std::false_type, std::false_type, std::false_type> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr typename ::portable_stl::disjunction<std::true_type>::type checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  {
    constexpr
      typename ::portable_stl::disjunction<std::false_type, std::false_type, std::false_type>::type checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  ASSERT_FALSE((::portable_stl::disjunction<std::false_type, std::false_type, std::false_type>{}()));
  ASSERT_TRUE((::portable_stl::disjunction<std::false_type, std::true_type, std::false_type>{}()));
  ASSERT_TRUE((::portable_stl::disjunction<std::false_type, std::false_type, std::true_type>{}()));
  ASSERT_TRUE((::portable_stl::disjunction<std::true_type, undefined>{}()));
  ASSERT_TRUE((::portable_stl::disjunction<std::true_type>{}()));
  ASSERT_FALSE((::portable_stl::disjunction<std::false_type>{}()));
  ASSERT_FALSE((::portable_stl::disjunction<>{}()));

  test_metaprogramming_logical_operator::metaprogramming_logical_operator_disjunction_variables();
}
