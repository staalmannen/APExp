// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_other_transformations.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "metaprogramming_type_relations_helper.h"
#include "portable_stl/metaprogramming/helper/integral_constant.h"
#include "portable_stl/metaprogramming/logical_operator/negation.h"
#include "portable_stl/metaprogramming/other_transformations/common_reference.h"
#include "portable_stl/metaprogramming/other_transformations/common_type.h"
#include "portable_stl/metaprogramming/other_transformations/conditional.h"
#include "portable_stl/metaprogramming/other_transformations/enable_if.h"
#include "portable_stl/metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "portable_stl/metaprogramming/other_transformations/invoke_result.h"
#include "portable_stl/metaprogramming/other_transformations/remove_cvref.h"
#include "portable_stl/metaprogramming/other_transformations/type_identity.h"
#include "portable_stl/metaprogramming/other_transformations/underlying_type.h"
#include "portable_stl/metaprogramming/other_transformations/void_t.h"
#include "portable_stl/metaprogramming/other_transformations/is_detected.h"
#include "test_debug_helper.h"

TEST(metaprogramming_other_transformations, conditional) {
  static_cast<void>(test_info_);

  ASSERT_EQ((0U),
            (typename ::portable_stl::conditional<false,
                                                  ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                                  ::portable_stl::integral_constant<std::uint32_t, 0U>>::type{}()));
  ASSERT_EQ((1U),
            (typename ::portable_stl::conditional<true,
                                                  ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                                  ::portable_stl::integral_constant<std::uint32_t, 0U>>::type{}()));

  ASSERT_EQ((0U),
            (::portable_stl::conditional_t<false,
                                           ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                           ::portable_stl::integral_constant<std::uint32_t, 0U>>{}()));
  ASSERT_EQ((1U),
            (::portable_stl::conditional_t<true,
                                           ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                           ::portable_stl::integral_constant<std::uint32_t, 0U>>{}()));

  {
    constexpr ::portable_stl::conditional<false,
                                          ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                          ::portable_stl::integral_constant<std::uint32_t, 0U>>::type
      result_value_type{};
    ASSERT_EQ((0U), (result_value_type()));
    static_cast<void>(result_value_type);
  }
  {
    constexpr ::portable_stl::conditional<true,
                                          ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                          ::portable_stl::integral_constant<std::uint32_t, 0U>>::type
      result_value_type{};
    ASSERT_EQ((1U), (result_value_type()));
    static_cast<void>(result_value_type);
  }
  {
    constexpr ::portable_stl::conditional_t<false,
                                            ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                            ::portable_stl::integral_constant<std::uint32_t, 0U>>
      result_value_type{};
    ASSERT_EQ((0U), (result_value_type()));
    static_cast<void>(result_value_type);
  }
  {
    constexpr ::portable_stl::conditional_t<true,
                                            ::portable_stl::integral_constant<std::uint32_t, 1U>,
                                            ::portable_stl::integral_constant<std::uint32_t, 0U>>
      result_value_type{};
    ASSERT_EQ((1U), (result_value_type()));
    static_cast<void>(result_value_type);
  }
}

namespace metaprogramming_other_transformations_helper {
/**
 * @brief Helper class for check enable_if.
 *
 */
class enable_if_checker final {
public:
  /**
   * @brief Helper function for check enable_if.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<bool t_value, typename ::portable_stl::enable_if<t_value, void *>::type = nullptr>
  constexpr inline static bool check() noexcept {
    return true;
  }
  /**
   * @brief Helper function for check enable_if.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<bool t_value, typename ::portable_stl::enable_if<!t_value, void *>::type = nullptr>
  constexpr inline static bool check() noexcept {
    return false;
  }
};
/**
 * @brief Helper class for check enable_if_t.
 *
 */
class enable_if_t_checker final {
public:
  /**
   * @brief Helper function for check enable_if_t.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */

  template<bool t_value, ::portable_stl::enable_if_t<t_value, void *> = nullptr>
  constexpr inline static bool check() noexcept {
    return true;
  }
  /**
   * @brief Helper function for check enable_if_t.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<bool t_value, ::portable_stl::enable_if_t<!t_value, void *> = nullptr>
  constexpr inline static bool check() noexcept {
    return false;
  }
};
} // namespace metaprogramming_other_transformations_helper

TEST(metaprogramming_other_transformations, enable_if) {
  static_cast<void>(test_info_);
  {
    constexpr typename ::portable_stl::enable_if<true, void const *>::type check_value{nullptr};
    ASSERT_EQ(nullptr, check_value);
    static_cast<void>(check_value);
  }

  {
    constexpr ::portable_stl::enable_if_t<true, void const *> check_value{nullptr};
    ASSERT_EQ(nullptr, check_value);
    static_cast<void>(check_value);
  }
  ASSERT_TRUE((metaprogramming_other_transformations_helper::enable_if_checker::check<true>()));
  ASSERT_FALSE((metaprogramming_other_transformations_helper::enable_if_checker::check<false>()));
  ASSERT_TRUE((metaprogramming_other_transformations_helper::enable_if_t_checker::check<true>()));
  ASSERT_FALSE((metaprogramming_other_transformations_helper::enable_if_t_checker::check<false>()));
}

namespace metaprogramming_other_transformations_helper {
/**
 * @brief Helper class for check enable_if_bool_constant.
 *
 */
class enable_if_bool_constant_checker final {
public:
  /**
   * @brief Helper function for check enable_if_bool_constant.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<class t_value, typename ::portable_stl::enable_if_bool_constant<t_value, void *>::type = nullptr>
  constexpr inline static bool check() noexcept {
    return true;
  }
  /**
   * @brief Helper function for check enable_if_bool_constant.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<class t_value,
           typename ::portable_stl::enable_if_bool_constant<::portable_stl::negation<t_value>, void *>::type = nullptr>
  constexpr inline static bool check() noexcept {
    return false;
  }
};
/**
 * @brief Helper class for check enable_if_bool_constant_t.
 *
 */
class enable_if_bool_constant_t_checker final {
public:
  /**
   * @brief Helper function for check enable_if_bool_constant_t.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */

  template<class t_value, ::portable_stl::enable_if_bool_constant_t<t_value, void *> = nullptr>
  constexpr inline static bool check() noexcept {
    return true;
  }
  /**
   * @brief Helper function for check enable_if_bool_constant_t.
   * Function enabled only if t_value is false.
   * @tparam t_value for select function.
   * @return false
   */
  template<class t_value,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<t_value>, void *> = nullptr>
  constexpr inline static bool check() noexcept {
    return false;
  }
};
} // namespace metaprogramming_other_transformations_helper

TEST(metaprogramming_other_transformations, enable_if_bool_constant) {
  static_cast<void>(test_info_);
  {
    constexpr
      typename ::portable_stl::enable_if_bool_constant<::portable_stl::true_type, void const *>::type check_value{
        nullptr};
    ASSERT_EQ(nullptr, check_value);
    static_cast<void>(check_value);
  }

  {
    constexpr ::portable_stl::enable_if_bool_constant_t<::portable_stl::true_type, void const *> check_value{nullptr};
    ASSERT_EQ(nullptr, check_value);
    static_cast<void>(check_value);
  }
  ASSERT_TRUE((
    metaprogramming_other_transformations_helper::enable_if_bool_constant_checker::check<::portable_stl::true_type>()));
  ASSERT_FALSE((metaprogramming_other_transformations_helper::enable_if_bool_constant_checker::check<
                ::portable_stl::false_type>()));
  ASSERT_TRUE((metaprogramming_other_transformations_helper::enable_if_bool_constant_t_checker::check<
               ::portable_stl::true_type>()));
  ASSERT_FALSE((metaprogramming_other_transformations_helper::enable_if_bool_constant_t_checker::check<
                ::portable_stl::false_type>()));
}

TEST(metaprogramming_other_transformations, type_identity) {
  static_cast<void>(test_info_);

  {
    constexpr typename ::portable_stl::type_identity<std::uint32_t>::type check_type{0U};
    ASSERT_TRUE((std::is_same<std::uint32_t, typename std::remove_cv<decltype(check_type)>::type>{}));
    ASSERT_TRUE((std::is_same<std::uint32_t const, decltype(check_type)>{}));
    ASSERT_EQ(0U, check_type);
    static_cast<void>(check_type);
  }
  {
    constexpr ::portable_stl::type_identity_t<std::uint32_t> check_type{0U};
    ASSERT_TRUE((std::is_same<std::uint32_t, typename std::remove_cv<decltype(check_type)>::type>{}));
    ASSERT_TRUE((std::is_same<std::uint32_t const, decltype(check_type)>{}));
    ASSERT_EQ(0U, check_type);
    static_cast<void>(check_type);
  }
}

TEST(metaprogramming_other_transformations, void_t) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<void, ::portable_stl::void_t<>>{}));
  ASSERT_TRUE((std::is_same<void, ::portable_stl::void_t<std::int32_t>>{}));
}

namespace metaprogramming_other_transformations_helpers {
/**
 * @brief Helper enum type with std::int16_t underlying type
 *
 */
enum class e1 : std::int16_t {
};
/**
 * @brief Helper enum type with std::uint8_t underlying type
 *
 */
enum class e2 : std::uint8_t {
};
/**
 * @brief Helper enum type with std::uint32_t underlying type
 *
 */
enum class e3 : std::uint32_t {
};
/**
 * @brief Helper enum type with std::int32_t underlying type
 *
 */
enum class e4 : std::int32_t {
};
} // namespace metaprogramming_other_transformations_helpers

TEST(metaprogramming_other_transformations, underlying_type) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type
     */
    using test_type = typename ::portable_stl::underlying_type<metaprogramming_other_transformations_helpers::e1>::type;
    ASSERT_TRUE((std::is_same<std::int16_t, test_type>{}));
    test_type helper{0};
    ASSERT_EQ(0, helper);
  }
  {
    /**
     * @brief Helper type
     */
    using test_type = ::portable_stl::underlying_type_t<metaprogramming_other_transformations_helpers::e1>;
    ASSERT_TRUE((std::is_same<std::int16_t, test_type>{}));
    test_type helper{0};
    ASSERT_EQ(0, helper);
  }

  ASSERT_TRUE((std::is_same<std::int16_t,
                            ::portable_stl::underlying_type_t<metaprogramming_other_transformations_helpers::e1>>{}));
  ASSERT_TRUE((std::is_same<std::uint8_t,
                            ::portable_stl::underlying_type_t<metaprogramming_other_transformations_helpers::e2>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t,
                            ::portable_stl::underlying_type_t<metaprogramming_other_transformations_helpers::e3>>{}));
  ASSERT_TRUE((std::is_same<std::int32_t,
                            ::portable_stl::underlying_type_t<metaprogramming_other_transformations_helpers::e4>>{}));
}

TEST(metaprogramming_other_transformations, remove_cvref) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type.
     */
    using test_remove_cvref = ::portable_stl::remove_cvref<std::int32_t const &&>;
    /**
     * @brief Helper type.
     */
    using test_type         = typename test_remove_cvref::type;
    constexpr test_type value{0};
    ASSERT_TRUE((std::is_same<std::int32_t, test_type>{}));
    ASSERT_EQ(0, value);
  }

  {
    /**
     * @brief Helper type.
     */
    using test_type = ::portable_stl::remove_cvref_t<std::int32_t const &&>;
    constexpr test_type value{0};
    ASSERT_TRUE((std::is_same<std::int32_t, test_type>{}));
    ASSERT_EQ(0, value);
  }

  ASSERT_TRUE((std::is_same<std::int32_t, typename ::portable_stl::remove_cvref<std::int32_t const &&>::type>{}));
  ASSERT_TRUE((std::is_same<std::int32_t, ::portable_stl::remove_cvref_t<std::int32_t const &&>>{}));
}

namespace metaprogramming_other_transformations_helpers {
/**
 * @brief Helper class for tests
 */
class CallableClass final {
public:
  /**
   * @brief Test function.
   * @param value1 arg1.
   * @param value2 arg2.
   * @return
   */
  constexpr std::int32_t operator()(std::int8_t const value1, std::int32_t const &value2) const noexcept {
    return static_cast<std::int32_t>(value1) + value2;
  }
  /**
   * @brief Test function.
   * @param value arg.
   * @return
   */
  constexpr std::uint32_t operator()(std::uint32_t const value) const noexcept {
    return value;
  }
};

/**
 * @brief Helper class for tests
 */
class ClassWithMemberFunction final {
  /**
   * @brief Private data.
   */
  std::int32_t member_{0};

public:
  /**
   * @brief Test function.
   * @param value arg.
   * @return
   */
  constexpr std::int32_t func(std::int32_t const value) const noexcept {
    return member_ + (0 * value);
  }
};
} // namespace metaprogramming_other_transformations_helpers

TEST(metaprogramming_other_transformations, invoke_result) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type.
     */
    using test_invoke_result
      = ::portable_stl::invoke_result<metaprogramming_other_transformations_helpers::CallableClass, std::uint32_t>;
    /**
     * @brief Helper type.
     */
    using test_type = typename test_invoke_result::type;
    ASSERT_TRUE((std::is_same<std::uint32_t, test_type>{}));
  }
  {
    metaprogramming_other_transformations_helpers::ClassWithMemberFunction const instance{};
    static_cast<void>(instance.func(0));
  }
  {
    constexpr metaprogramming_other_transformations_helpers::CallableClass instance{};
    static_cast<void>(instance(0U));
    static_cast<void>(instance(0, 0));
  }

  ASSERT_TRUE(
    (std::is_same<std::int32_t,
                  ::portable_stl::invoke_result_t<metaprogramming_other_transformations_helpers::CallableClass,
                                                  std::int8_t,
                                                  std::int32_t &>>{}));

  ASSERT_TRUE(
    (std::is_same<
      std::uint32_t,
      ::portable_stl::invoke_result_t<metaprogramming_other_transformations_helpers::CallableClass, std::uint32_t>>{}));

  ASSERT_TRUE((std::is_same<std::int32_t,
                            ::portable_stl::invoke_result_t<
                              decltype(&metaprogramming_other_transformations_helpers::ClassWithMemberFunction::func),
                              metaprogramming_other_transformations_helpers::ClassWithMemberFunction,
                              std::int32_t>>{}));
}

namespace metaprogramming_other_transformations_helpers {} // namespace metaprogramming_other_transformations_helpers

/**
 * @brief Specialization for user classes.
 */
template<>
class portable_stl::common_type<metaprogramming_type_relations_helper::Derived1,
                                metaprogramming_type_relations_helper::Derived4>
  final {
public:
  /**
   * @brief The result common type.
   */
  using type = metaprogramming_type_relations_helper::Base1;
};

namespace metaprogramming_other_transformations_helpers {
/**
 * @brief Medium class checked type.
 * @tparam t_type The tested type.
 */
template<class t_type, class = void> class has_type final {
public:
  /**
   * @brief Result.
   */
  using type = std::false_type;
};

/**
 * @brief Medium class checked type.
 * @tparam t_type The tested type.
 */
template<class t_type> class has_type<t_type, ::portable_stl::void_t<typename t_type::type>> final {
public:
  /**
   * @brief Result.
   */
  using type = std::true_type;
};

/**
 * @brief Helper function to check if t_type has a public typename 'type'.
 *
 * @tparam t_type The tested type.
 */
template<class t_type> constexpr bool has_type_v = has_type<t_type>::type::value;

} // namespace metaprogramming_other_transformations_helpers

TEST(metaprogramming_other_transformations, common_type) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type.
     */
    using test_common_type_result = ::portable_stl::common_type<std::uint32_t, std::uint32_t>;
    ASSERT_TRUE(metaprogramming_other_transformations_helpers::has_type_v<test_common_type_result>);

    /**
     * @brief Helper type.
     */
    using test_type = typename test_common_type_result::type;
    ASSERT_TRUE((std::is_same<std::uint32_t, test_type>{}));
  }
  {
    /**
     * @brief Helper type.
     */
    using test_common_type_result = ::portable_stl::common_type<metaprogramming_type_relations_helper::Base1, double>;
    ASSERT_FALSE(metaprogramming_other_transformations_helpers::has_type_v<test_common_type_result>);
  }

  EXPECT_TRUE((std::is_same<std::uint32_t, typename ::portable_stl::common_type<std::uint32_t>::type>{}));

  EXPECT_TRUE((std::is_same<std::common_type_t<void>, ::portable_stl::common_type_t<void>>{}()));
  EXPECT_TRUE((std::is_same<std::common_type_t<void const>, ::portable_stl::common_type_t<void const>>{}()));
  EXPECT_TRUE(
    (std::is_same<std::common_type_t<void const volatile>, ::portable_stl::common_type_t<void const volatile>>{}()));

  EXPECT_TRUE((std::is_same<std::common_type_t<std::uint32_t, std::uint32_t const &>,
                            ::portable_stl::common_type_t<std::uint32_t, std::uint32_t const &>>{}()));

  EXPECT_TRUE((std::is_same<std::common_type_t<std::int8_t, std::int16_t, std::int32_t>,
                            ::portable_stl::common_type_t<std::int8_t, std::int16_t, std::int32_t>>{}()));

  EXPECT_TRUE(
    (std::is_same<
      std::uint32_t,
      ::portable_stl::
        common_type_t<std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, std::int32_t, std::uint32_t>>{}()));

  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::int8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::uint8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::int16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::uint16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::int32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::uint32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::int32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::uint32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::int64_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::common_type_t<std::uint64_t, std::uint64_t>>{}()));

  EXPECT_TRUE((std::is_same<metaprogramming_type_relations_helper::Base1,
                            ::portable_stl::common_type_t<metaprogramming_type_relations_helper::Derived1,
                                                          metaprogramming_type_relations_helper::Derived4>>{}()));
}

TEST(metaprogramming_other_transformations, common_reference_msvc) {
  static_cast<void>(test_info_);
  /**
   * @brief Test base class.
   */
  using B = metaprogramming_type_relations_helper::Base1;
  /**
   * @brief Test derived class.
   */
  using D = metaprogramming_type_relations_helper::Derived1;
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D &>, B &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &&, D &&>, B &&>{}));
}

TEST(metaprogramming_other_transformations, common_reference) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type.
     */
    using test_common_ref_result = ::portable_stl::common_reference<std::add_lvalue_reference_t<std::uint32_t>,
                                                                    std::add_lvalue_reference_t<std::uint32_t> &>;
    EXPECT_TRUE(metaprogramming_other_transformations_helpers::has_type_v<test_common_ref_result>);

    /**
     * @brief Helper type.
     */
    using test_type = typename test_common_ref_result::type;
    EXPECT_TRUE((std::is_same<std::uint32_t &, test_type>{}));
  }
  {
    /**
     * @brief Helper type.
     */
    using test_common_ref_result
      = ::portable_stl::common_reference<metaprogramming_type_relations_helper::Base1, double>;
    EXPECT_FALSE(metaprogramming_other_transformations_helpers::has_type_v<test_common_ref_result>);
  }

  // If sizeof...(T) is zero, there shall be no member type.
  {
    /**
     * @brief Helper type.
     */
    using test_common_ref_result = ::portable_stl::common_reference<>;
    EXPECT_FALSE(metaprogramming_other_transformations_helpers::has_type_v<test_common_ref_result>);
  }

  {
    /**
     * @brief Helper type.
     */
    using test_common_ref_result
      = ::portable_stl::common_reference<std::int32_t, std::int16_t, std::int32_t, std::int8_t *>;
    EXPECT_FALSE(metaprogramming_other_transformations_helpers::has_type_v<test_common_ref_result>);
  }

  EXPECT_TRUE((std::is_same<std::int32_t &,
                            ::portable_stl::common_reference_t<std::add_lvalue_reference_t<std::int32_t>,
                                                               std::add_lvalue_reference_t<std::int32_t>,
                                                               std::add_lvalue_reference_t<std::int32_t>>>{}));

  EXPECT_TRUE((std::is_same<std::int32_t &,
                            ::portable_stl::common_reference_t<std::add_lvalue_reference_t<std::int32_t>,
                                                               std::add_lvalue_reference_t<std::int32_t>,
                                                               std::add_lvalue_reference_t<std::int32_t>,
                                                               std::add_lvalue_reference_t<std::int32_t>>>{}));
  EXPECT_TRUE((std::is_same<std::int64_t,
                            ::portable_stl::common_reference_t<std::add_lvalue_reference_t<std::int8_t>,
                                                               std::add_lvalue_reference_t<std::int16_t> &,
                                                               std::add_lvalue_reference_t<std::int32_t> &&,
                                                               std::add_lvalue_reference_t<std::int64_t> &,
                                                               std::add_lvalue_reference_t<std::uint8_t> &,
                                                               std::add_lvalue_reference_t<std::uint16_t> &&>>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t, std::int32_t, std::int32_t>, std::int32_t>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t &&, std::int32_t const &, std::int32_t volatile &>,
                  std::int32_t const volatile &>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t &&, std::int32_t const &, float &>, float>{}));

  // Otherwise, if sizeof...(T) is one, let T0 denote the sole type in the pack T. The member typedef type shall denote
  // the same type as T0.
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<void>, void>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t>, std::int32_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t &>, std::int32_t &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t &&>, std::int32_t &&>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t const>, std::int32_t const>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t const &>, std::int32_t const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t const &&>, std::int32_t const &&>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t volatile[]>, std::int32_t volatile[]>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t volatile(&)[]>, std::int32_t volatile(&)[]>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t volatile(&&)[]>, std::int32_t volatile(&&)[]>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<void (&)()>, void (&)()>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<void (&&)()>, void (&&)()>{}));

  /**
   * @brief Test base class.
   */
  using B = metaprogramming_type_relations_helper::Base1;

  /**
   * @brief Test derived class.
   */
  using D = metaprogramming_type_relations_helper::Derived1;

  // If T1 and T2 are reference types and COMMON_REF(T1, T2) is well-formed, then the member typedef type denotes that
  // type.
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D &>, B &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B const &, D &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D const &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D const &, D &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D &, B &, D &>, B &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &&, D &&>, B &&>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B const &&, D &&>, B const &&>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &&, D const &&>, B const &&>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D &&>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &, D const &&>, B const &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B const &, D &&>, B const &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &&, D &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<D &, B &&>, B const &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B &&, D const &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<D const &, B &&>, B const &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<B const &&, D &>, B const &>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<D &, B const &&>, B const &>{}));

  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t const &, std::int32_t volatile &>,
                            std::int32_t const volatile &>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t const volatile &&, std::int32_t volatile &&>,
                  std::int32_t const volatile &&>{}));

  // Otherwise, if COND_RES(T1, T2) is well-formed, then the member typedef type denotes that type.
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<void, void>, void>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t, std::int16_t>, std::int32_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t, std::int16_t &>, std::int32_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t &, std::int16_t &>, std::int32_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t &, std::int16_t>, std::int32_t>{}));

  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t(&)[10], std::int32_t(&)[11]>, std::int32_t *>{}));
}

TEST(metaprogramming_other_transformations, DISABLED_common_reference_tricky_cases) {
  static_cast<void>(test_info_);

  // array
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t(&)[10], std::int32_t(&&)[10]>,
                            std::int32_t const(&)[10]>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::common_reference_t<std::int32_t const(&)[10], std::int32_t volatile(&)[10]>,
                            std::int32_t const volatile(&)[10]>{}));

  // tricky volatile reference case
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t &&, std::int32_t volatile &>, std::int32_t>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::common_reference_t<std::int32_t volatile &, std::int32_t &&>, std::int32_t>{}));
}
