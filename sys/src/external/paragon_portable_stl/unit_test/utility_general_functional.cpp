// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="utility_general_functional.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <list>
#include <vector>

#include "portable_stl/utility/general/functional/invoke.h"
#include "portable_stl/utility/general/functional/reference_wrapper.h"

TEST(reference_wrapper, reference_wrapper) {
  constexpr std::int32_t const user_value_1{1};
  constexpr std::int32_t const user_value_2{2};
  constexpr std::int32_t const user_value_3{3};
  constexpr std::int32_t const user_value_4{4};
  static_cast<void>(test_info_);
  std::list<std::int32_t> list{user_value_1, user_value_2, user_value_3, user_value_4};
  std::vector<::portable_stl::reference_wrapper<std::int32_t>> vec_of_refs{list.begin(), list.end()};
  EXPECT_EQ(user_value_3, vec_of_refs[user_value_2]);
  EXPECT_EQ(user_value_4, vec_of_refs[user_value_3]);

  constexpr std::uint32_t const position_of_vector{3U};

  // 'random access []' to list via vector of ref wrappers
  std::swap(vec_of_refs[0U].get(), vec_of_refs[position_of_vector].get());

  EXPECT_EQ(user_value_4, list.front());
  EXPECT_EQ(user_value_1, list.back());

  // creating ref ( )
  {
    auto test_r = ::portable_stl::ref(list.front());
    test_r--;
    EXPECT_EQ(user_value_3, test_r);

    auto test_r2 = ::portable_stl::ref(test_r);
    test_r2--;
    EXPECT_EQ(user_value_2, test_r);
    EXPECT_EQ(user_value_2, test_r2);
  }

  // creating cref ( )
  {
    std::list<std::int32_t> const list_const{user_value_1, user_value_2, user_value_3, user_value_4};

    auto test_r = ::portable_stl::cref(list_const.back());
    EXPECT_EQ(user_value_4, test_r);

    auto test_r2 = ::portable_stl::cref(test_r);
    EXPECT_EQ(user_value_4, test_r);
    EXPECT_EQ(test_r, test_r2);
  }

  EXPECT_TRUE((std::is_same<std::int32_t, typename ::portable_stl::reference_wrapper<std::int32_t>::type>()));

  {
    ::portable_stl::is_reference_wrapper<typename ::portable_stl::reference_wrapper<std::int32_t>> checker{};
    EXPECT_TRUE((checker()));
  }
  {
    ::portable_stl::is_reference_wrapper<std::int32_t> checker{};
    EXPECT_FALSE((checker()));
  }
  {
    ::portable_stl::is_reference_wrapper<typename ::portable_stl::reference_wrapper<std::int32_t>>::type checker{};
    EXPECT_TRUE((checker()));
  }
  {
    ::portable_stl::is_reference_wrapper<std::int32_t>::type checker{};
    EXPECT_FALSE((checker()));
  }
}

namespace utility_general_functional_helper {
constexpr std::int32_t value_ten{10};
/**
 * @brief Test class.
 */
class invoke_checker   final {
public:
  /**
   * @brief Simple operator() implemantation.
   *
   * @param value
   * @return value_ten * value.
   */
  constexpr std::int32_t operator()(std::int32_t const value) const noexcept {
    return value_ten * value;
  }
  /**
   * @brief Simple function.
   *
   * @param value
   * @return value_ten * value.
   */
  constexpr std::int32_t func(std::int32_t const value) const noexcept {
    return value_public - value;
  }

  /**
   * @brief Member data.
   */
  std::int32_t value_public{value_ten + 1};
};

/**
 * @brief Simple function.
 *
 * @param value
 * @return value_ten * value.
 */
constexpr inline static std::int32_t int_function(double const value) noexcept {
  return value_ten * static_cast<std::int32_t>(value);
}
} // namespace utility_general_functional_helper

TEST(utility_general_functional, invoke) {
  static_cast<void>(test_info_);

  // function
  {
    EXPECT_EQ(utility_general_functional_helper::value_ten,
              ::portable_stl::invoke(utility_general_functional_helper::int_function, 1));
  }
  // // function
  // {
  //   /**
  //    * @brief Helper type for check invoke.
  //    *
  //    */
  //   using cheker = ::portable_stl::functional_helper::
  //     invoke_selector_helper<decltype(&utility_general_functional_helper::int_function), decltype(1)>;
  //   EXPECT_EQ(utility_general_functional_helper::value_ten,
  //             (cheker::get(utility_general_functional_helper::int_function, 1)));

  //   EXPECT_EQ(utility_general_functional_helper::value_ten,
  //             (cheker{}.get(utility_general_functional_helper::int_function, 1)));
  // }
  // member function
  {
    utility_general_functional_helper::invoke_checker Obj1{};
    EXPECT_EQ(utility_general_functional_helper::value_ten,
              ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::func, Obj1, 1));
  }
  // member function pointer
  {
    auto Obj1(std::make_unique<utility_general_functional_helper::invoke_checker>());
    EXPECT_EQ(utility_general_functional_helper::value_ten,
              ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::func, Obj1, 1));
  }
  // member function reference wrapper
  {
    utility_general_functional_helper::invoke_checker Obj1{};
    EXPECT_EQ(
      utility_general_functional_helper::value_ten,
      ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::func, ::portable_stl::ref(Obj1), 1));
  }

  // data member
  {
    utility_general_functional_helper::invoke_checker Obj1{};
    EXPECT_EQ((utility_general_functional_helper::value_ten + 1),
              ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::value_public, Obj1));
  }
  // data member pointer
  {
    auto Obj1(std::make_unique<utility_general_functional_helper::invoke_checker>());
    EXPECT_EQ((utility_general_functional_helper::value_ten + 1),
              ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::value_public, Obj1));
  }
  // data member reference wrapper
  {
    utility_general_functional_helper::invoke_checker Obj1{};

    EXPECT_EQ((utility_general_functional_helper::value_ten + 1),
              ::portable_stl::invoke(&utility_general_functional_helper::invoke_checker::value_public,
                                     ::portable_stl::ref(Obj1)));
  }

  // functional object
  {
    utility_general_functional_helper::invoke_checker Obj1{};
    EXPECT_EQ(utility_general_functional_helper::value_ten,
              ::portable_stl::invoke(utility_general_functional_helper::invoke_checker(), 1));
    EXPECT_EQ(utility_general_functional_helper::value_ten, ::portable_stl::invoke(Obj1, 1));
  }

  // functional object

  {
    auto func([](auto value) noexcept -> std::int32_t {
      return utility_general_functional_helper::value_ten * value;
    });
    EXPECT_EQ(utility_general_functional_helper::value_ten, func(1));
    EXPECT_EQ(utility_general_functional_helper::value_ten, ::portable_stl::invoke(func, 1));
  }
}
