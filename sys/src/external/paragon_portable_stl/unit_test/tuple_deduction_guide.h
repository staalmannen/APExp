// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_deduction_guide.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_DEDUCTION_GUIDE_H
#define PSTL_TUPLE_DEDUCTION_GUIDE_H

#include "gtest/gtest.h"

#include "portable_stl/utility/tuple/tuple.h"
#include "portable_stl/utility/tuple/tuple_deduction.h"
#include "tuple_test_helper.h"

namespace test_tuple {

/**
 * @brief Tests for deduction guide
 */
inline void tuple_deduction_guide() {
  std::allocator<std::int32_t> const altor;
  auto const                         altor_tag = ::portable_stl::allocator_arg;

  // tuple(const Types&...) -> tuple<Types...>
  {
    ::portable_stl::tuple tpl1{1};
    EXPECT_TRUE((std::is_same<decltype(tpl1), ::portable_stl::tuple<std::int32_t>>{}));

    std::int32_t          value{1};
    ::portable_stl::tuple tpl2{value, 0.0, nullptr};
    EXPECT_TRUE((std::is_same<decltype(tpl2), ::portable_stl::tuple<std::int32_t, double, decltype(nullptr)>>{}));
  }

  // tuple(AT, A const&, Types const&...) -> tuple<Types...>
  {
    ::portable_stl::tuple tpl1{altor_tag, altor, 1};
    EXPECT_TRUE((std::is_same<decltype(tpl1), ::portable_stl::tuple<std::int32_t>>{}));

    std::int32_t          value{1};
    ::portable_stl::tuple tpl2{altor_tag, altor, 1, 0.0, value};
    EXPECT_TRUE((std::is_same<decltype(tpl2), ::portable_stl::tuple<std::int32_t, double, std::int32_t>>{}));
  }

  // tuple(tuple const& t) -> decltype(t)
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<std::int32_t, decltype(nullptr)>;
    tuple_type const tpl{1, nullptr};

    ::portable_stl::tuple tpl1{tpl};
    EXPECT_TRUE((std::is_same<decltype(tpl1), tuple_type>{}));
  }

  // tuple(tuple&& t) -> decltype(t)
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<void *, std::uint32_t, std::int8_t>;

    ::portable_stl::tuple tpl1{tuple_type(nullptr, 42, 'a')};
    EXPECT_TRUE((std::is_same<decltype(tpl1), tuple_type>{}));
  }

  // tuple(AT, A const&, tuple const& t) -> decltype(t)
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<std::int32_t, decltype(nullptr)>;
    tuple_type const tpl{1, nullptr};

    ::portable_stl::tuple tpl1{altor_tag, altor, tpl};
    EXPECT_TRUE((std::is_same<decltype(tpl1), tuple_type>{}));
  }

  // tuple(AT, A const&, tuple&& t) -> decltype(t)
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<void *, std::uint32_t, std::int8_t>;

    ::portable_stl::tuple tpl1{altor_tag, altor, tuple_type(nullptr, 42, 'a')};
    EXPECT_TRUE((std::is_same<decltype(tpl1), tuple_type>{}));
  }
}

} // namespace test_tuple

#endif /* PSTL_TUPLE_DEDUCTION_GUIDE_H */
