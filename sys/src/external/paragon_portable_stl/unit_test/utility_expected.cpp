// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="utility_expected.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <gmock/gmock.h>
#include <list>
#include <portable_stl/language_support/make_initializer_list.h>
#include <portable_stl/utility/expected/bad_expected_access.h>
#include <portable_stl/utility/expected/expected.h>
#include <portable_stl/utility/expected/unexpected.h>

namespace utility_expected_test_helpers {
/**
 * @brief Helper class for error object with exceptions.
 *
 */
class error_check final {
  /**
   * @brief Error value
   *
   */
  std::uint32_t m_value;

public:
  /**
   * @brief Default destructor.
   */
  ~error_check() noexcept = default;
  /**
   * @brief Default constructor.
   */
  error_check() noexcept(false) : error_check(0U) {
  }
  /**
   * @brief Constructor with value.
   *
   * @param local_value
   */
  explicit error_check(std::uint32_t const local_value) noexcept(false) : m_value(local_value) {
  }

  /**
   * @brief Constructor with initializer list.
   *
   * @param il inititalizer_list with argumetns.
   * @param local_value local value
   */
  error_check(::portable_stl::initializer_list<std::uint32_t> const &il,
              std::uint32_t const                                    local_value) noexcept(false)
      : error_check(local_value + static_cast<std::uint32_t>(il.size())) {
  }

  /**
   * @brief Copy constructor.
   *
   * @param source
   */
  error_check(error_check const &source) noexcept(false) : error_check(source.m_value) {
  }
  /**
   * @brief Move constructor.
   *
   * @param source
   */
  error_check(error_check &&source) noexcept(false) : error_check(std::move(source.m_value)) {
  }

  /**
   * @brief Copy assign.
   *
   * @param source
   * @return error_check&
   */
  error_check &operator=(error_check const &source) & noexcept(false);
  /**
   * @brief Move assign.
   *
   * @param source
   * @return
   */
  error_check &operator=(error_check &&source) & noexcept(false);

  /**
   * @brief Stored error value.
   * @return value.
   */
  constexpr std::uint32_t value() const noexcept {
    return m_value;
  }

  /**
   * @brief Swap content.
   * @param other object for swap.
   */
  void local_swap(error_check &other) noexcept {
    std::swap(m_value, other.m_value);
  }
};

/**
 * @brief Swap error containers.
 *
 * @param left error container.
 * @param right error container.
 */
inline static void swap(error_check &left, error_check &right) noexcept {
  left.local_swap(right);
}

/**
 * @brief Copy assign.
 *
 * @param source
 * @return
 */
inline error_check &error_check::operator=(error_check const &source) & noexcept(false) {
  if (this != &source) {
    error_check tmp{source};
    swap(*this, tmp);
  }
  return *this;
}

/**
 * @brief Move assign.
 *
 * @param source
 * @return
 */
inline error_check &error_check::operator=(error_check &&source) & noexcept(false) {
  error_check tmp{std::move(source)};
  swap(*this, tmp);
  return *this;
}

/**
 * @brief Equal compare operator for error object and value.
 *
 * @param left
 * @param right
 * @return
 */
constexpr inline static bool operator==(error_check const &left, error_check const &right) noexcept {
  return left.value() == right.value();
}

/**
 * @brief Equal compare operator for error object and value.
 *
 * @param left
 * @param right
 * @return
 */
constexpr inline static bool operator==(std::uint32_t const left, error_check const &right) noexcept {
  return left == right.value();
}

/**
 * @brief Equal compare operator for error object and value.
 *
 * @param left
 * @param right
 * @return
 */
constexpr inline static bool operator==(error_check const &left, std::uint32_t const right) noexcept {
  return right == left.value();
}

} // namespace utility_expected_test_helpers
TEST(utility_expected, unexpected_construct_inplace_t) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unexpected<std::uint32_t> error{::portable_stl::in_place_t{}, 1U};
    ASSERT_EQ(1U, error.error());
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::unexpected<std::uint32_t>,
                                               ::portable_stl::in_place_t,
                                               std::uint32_t>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{::portable_stl::in_place_t{}, 1U};
    ASSERT_EQ(1U, error.error());
    ASSERT_EQ(error.error(), 1U);
    ASSERT_FALSE((std::is_nothrow_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>,
                                                ::portable_stl::in_place_t,
                                                std::uint32_t>{}));
  }
}

TEST(utility_expected, unexpected_construct_initializer_list) {
  static_cast<void>(test_info_);
  constexpr std::uint32_t result_value{4U};
  {
    utility_expected_test_helpers::error_check test_error{::portable_stl::make_initializer_list({1U, 1U, 1U}), 1U};
    ASSERT_EQ(result_value, test_error.value());
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{
      ::portable_stl::in_place_t{}, ::portable_stl::make_initializer_list({1U, 1U, 1U}), 1U};
    ASSERT_EQ(result_value, error.error());
    ASSERT_FALSE((std::is_nothrow_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>,
                                                ::portable_stl::in_place_t,
                                                ::portable_stl::initializer_list<std::uint32_t>,
                                                std::uint32_t>{}));
  }

  {
    utility_expected_test_helpers::error_check test_error{
      {1U, 1U, 1U},
      1U
    };
    ASSERT_EQ(result_value, test_error.value());
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{
      ::portable_stl::in_place_t{},
      {1U, 1U, 1U},
      1U
    };
    ASSERT_EQ(result_value, error.error());
    ASSERT_FALSE((std::is_nothrow_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>,
                                                ::portable_stl::in_place_t,
                                                ::portable_stl::initializer_list<std::uint32_t>,
                                                std::uint32_t>{}));
  }
}

TEST(utility_expected, unexpected_construct_from_error_value) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::unexpected<std::uint32_t>, std::uint32_t>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{::portable_stl::in_place_t{}, 1U};
    ASSERT_EQ(1U, error.error());
    ASSERT_FALSE((std::is_nothrow_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>,
                                                std::uint32_t>{}));
  }
}

TEST(utility_expected, unexpected_construct_default) {
  static_cast<void>(test_info_);
  {
    utility_expected_test_helpers::error_check check{1U};
    utility_expected_test_helpers::error_check check2{0U};
    utility_expected_test_helpers::error_check check3{check};
    utility_expected_test_helpers::error_check check4{check};
    utility_expected_test_helpers::error_check check5{std::move(check4)};
    ASSERT_EQ(1U, check);
    ASSERT_EQ(0U, check2);
    ASSERT_EQ(1U, check3);
    ASSERT_EQ(1U, check5);
    check3 = check2;
    check2 = std::move(check);
    ASSERT_EQ(0U, check3);
    ASSERT_EQ(1U, check2);
    ASSERT_EQ(1U, check5);
    swap(check3, check5);
    ASSERT_EQ(0U, check5);
    ASSERT_EQ(1U, check2);
    ASSERT_EQ(1U, check3);
  }
  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> error_copy{error};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_constructible<::portable_stl::unexpected<std::uint32_t>>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error_copy{error};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE(
      (std::is_nothrow_copy_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>>{}));
  }
  {
    ::portable_stl::unexpected<std::uint32_t> const error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> const error_copy{error};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_constructible<::portable_stl::unexpected<std::uint32_t> const>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const error_copy{error};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE((std::is_nothrow_copy_constructible<
                  ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const>{}));
  }

  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> error_copy{std::move(error)};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_constructible<::portable_stl::unexpected<std::uint32_t>>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error_copy{std::move(error)};
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE(
      (std::is_nothrow_copy_constructible<::portable_stl::unexpected<utility_expected_test_helpers::error_check>>{}));
  }

  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = error;
    ASSERT_EQ(1U, error.error());
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_assignable<::portable_stl::unexpected<std::uint32_t>>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = error;
    ASSERT_EQ(1U, error.error());
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE(
      (std::is_nothrow_copy_assignable<::portable_stl::unexpected<utility_expected_test_helpers::error_check>>{}));
  }
  {
    ::portable_stl::unexpected<std::uint32_t> const error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = error;
    ASSERT_EQ(1U, error.error());
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_assignable<::portable_stl::unexpected<std::uint32_t>>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = error;
    ASSERT_EQ(1U, error.error());
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE(
      (std::is_nothrow_copy_assignable<::portable_stl::unexpected<utility_expected_test_helpers::error_check>>{}));
  }
  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<std::uint32_t> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = std::move(error);
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_TRUE((std::is_nothrow_copy_assignable<::portable_stl::unexpected<std::uint32_t>>{}));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{1U};
    ASSERT_EQ(1U, error.error());
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error_copy{0U};
    ASSERT_EQ(0U, error_copy.error());
    error_copy = std::move(error);
    ASSERT_EQ(1U, error_copy.error());
    ASSERT_FALSE(
      (std::is_nothrow_copy_assignable<::portable_stl::unexpected<utility_expected_test_helpers::error_check>>{}));
  }
}
TEST(utility_expected, unexpected_error) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unexpected<std::uint32_t> error{1U};
    ASSERT_EQ(1U, error.error());
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error{1U};
    ASSERT_EQ(1U, error.error());
  }
  {
    ::portable_stl::unexpected<std::uint32_t> const error{1U};
    ASSERT_EQ(1U, error.error());
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const error{1U};
    ASSERT_EQ(1U, error.error());
  }
  { ASSERT_EQ(1U, ::portable_stl::unexpected<std::uint32_t>{1U}.error()); }
  { ASSERT_EQ(1U, ::portable_stl::unexpected<utility_expected_test_helpers::error_check>{1U}.error()); }

  {
    ASSERT_EQ(
      1U,
      static_cast<::portable_stl::unexpected<std::uint32_t> const>(::portable_stl::unexpected<std::uint32_t>{1U})
        .error());
  }
  {
    ASSERT_EQ(1U,
              static_cast<::portable_stl::unexpected<utility_expected_test_helpers::error_check> const>(
                ::portable_stl::unexpected<utility_expected_test_helpers::error_check>{1U})
                .error());
  }
}

TEST(utility_expected, unexpected_swap) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error1{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error0{0U};
    ASSERT_EQ(0U, error0.error());
    ASSERT_EQ(1U, error1.error());
    error0.local_swap(error1);
    ASSERT_EQ(0U, error1.error());
    ASSERT_EQ(1U, error0.error());
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error1{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error0{0U};
    ASSERT_EQ(0U, error0.error());
    ASSERT_EQ(1U, error1.error());
    swap(error1, error0);
    ASSERT_EQ(0U, error1.error());
    ASSERT_EQ(1U, error0.error());
  }
  {
    ::portable_stl::unexpected<std::uint32_t> error1{1U};
    ::portable_stl::unexpected<std::uint32_t> error0{0U};
    ASSERT_EQ(0U, error0.error());
    ASSERT_EQ(1U, error1.error());
    error0.local_swap(error1);
    ASSERT_EQ(0U, error1.error());
    ASSERT_EQ(1U, error0.error());
  }
  {
    ::portable_stl::unexpected<std::uint32_t> error1{1U};
    ::portable_stl::unexpected<std::uint32_t> error0{0U};
    ASSERT_EQ(0U, error0.error());
    ASSERT_EQ(1U, error1.error());
    swap(error1, error0);
    ASSERT_EQ(0U, error1.error());
    ASSERT_EQ(1U, error0.error());
  }
}

TEST(utility_expected, unexpected_equal) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unexpected<std::uint32_t> error0{1U};
    ::portable_stl::unexpected<std::uint32_t> error1{1U};
    ::portable_stl::unexpected<std::uint32_t> error2{0U};
    ASSERT_TRUE((error0.is_equal(error1)));
    ASSERT_FALSE((error0.is_equal(error2)));
  }
  {
    ::portable_stl::unexpected<std::uint32_t> error0{1U};
    ::portable_stl::unexpected<std::uint32_t> error1{1U};
    ::portable_stl::unexpected<std::uint32_t> error2{0U};
    ASSERT_EQ(error0, error1);
    ASSERT_NE(error0, error2);
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error0{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error1{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error2{0U};
    ASSERT_TRUE((error0.is_equal(error1)));
    ASSERT_FALSE((error0.is_equal(error2)));
  }
  {
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error0{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error1{1U};
    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> error2{0U};
    ASSERT_EQ(error0, error1);
    ASSERT_NE(error0, error2);
  }
}

TEST(utility_expected, exception_masking) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::exception_masking<std::int32_t>       exception{1};
    ::portable_stl::exception_masking<std::int32_t> const exception_const{1};

    ::portable_stl::exception_masking<std::int32_t> exception_copy{exception_const};
    ::portable_stl::exception_masking<std::int32_t> exception_move{std::move(exception_copy)};

    ASSERT_EQ(1U, exception_move.error());

    exception_copy = exception_const;
    exception_move = std::move(exception_copy);

    ASSERT_EQ(1U, exception_const.error());
    ASSERT_EQ(1U, exception.error());
    ASSERT_EQ(1U, exception_move.error());

    ASSERT_EQ(1U, ::portable_stl::bad_expected_access<std::int32_t>{1}.error());
    ASSERT_EQ(1U,
              static_cast<::portable_stl::bad_expected_access<std::int32_t> const>(
                ::portable_stl::bad_expected_access<std::int32_t>{1})
                .error());
  }
  {
    ::portable_stl::exception_masking<utility_expected_test_helpers::error_check>       exception{1U};
    ::portable_stl::exception_masking<utility_expected_test_helpers::error_check> const exception_const{1U};

    ::portable_stl::exception_masking<utility_expected_test_helpers::error_check> exception_copy{exception_const};
    ::portable_stl::exception_masking<utility_expected_test_helpers::error_check> exception_move{
      std::move(exception_copy)};

    exception_copy = exception_const;
    exception_move = std::move(exception_copy);

    ASSERT_EQ(1U, exception_const.error().value());
    ASSERT_EQ(1U, exception.error().value());
    ASSERT_EQ(1U, exception_move.error().value());

    ASSERT_EQ(1U, ::portable_stl::bad_expected_access<utility_expected_test_helpers::error_check>{1U}.error().value());
    ASSERT_EQ(1U,
              static_cast<::portable_stl::bad_expected_access<utility_expected_test_helpers::error_check> const>(
                ::portable_stl::bad_expected_access<utility_expected_test_helpers::error_check>{1U})
                .error()
                .value());
  }
}

TEST(utility_expected, bad_expected_access) {
  static_cast<void>(test_info_);

  ::portable_stl::bad_expected_access<std::int32_t>       exception{1};
  ::portable_stl::bad_expected_access<std::int32_t> const exception_const{1};

  ASSERT_EQ(1U, exception_const.error());
  ASSERT_EQ(1U, exception.error());

  ASSERT_EQ(1U, ::portable_stl::bad_expected_access<std::int32_t>{1}.error());
  ASSERT_EQ(1U,
            static_cast<::portable_stl::bad_expected_access<std::int32_t> const>(
              ::portable_stl::bad_expected_access<std::int32_t>{1})
              .error());

  ASSERT_NE(nullptr, exception.what());
  ASSERT_STREQ("bad access to portable_stl::expected without expected value", exception.what());
}

TEST(utility_expected, expected_default) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t>::unexpected_type error{::portable_stl::in_place_t{}, 1U};
    ASSERT_EQ(1U, error.error());
  }
  {
    ::portable_stl::expected<void, std::uint32_t>::unexpected_type error{::portable_stl::in_place_t{}, 1U};
    ASSERT_EQ(1U, error.error());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t>::rebind<std::int16_t> value{::portable_stl::in_place_t{},
                                                                                      static_cast<std::int16_t>(1)};
    ASSERT_TRUE(value.has_value());
    ASSERT_EQ(1, value.value());
  }
  {
    ::portable_stl::expected<void, std::uint32_t>::rebind<std::int16_t> value{::portable_stl::in_place_t{},
                                                                              static_cast<std::int16_t>(1)};
    ASSERT_TRUE(value.has_value());
    ASSERT_EQ(1, value.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(0, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(0, checker.value());
  }
  {
    ::portable_stl::expected<void, std::uint32_t> checker{};
    ASSERT_TRUE(checker.has_value());
  }
}

TEST(utility_expected, expected_value) {
  static_cast<void>(test_info_);
  constexpr std::int16_t  test_value_short{32};
  constexpr std::int32_t  test_value{test_value_short};
  constexpr std::uint32_t initialize_test_value{30U};

  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{test_value};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    std::int32_t                                          temp_value{test_value};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(temp_value)};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{test_value_short};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    std::int16_t                                          temp_value{test_value_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(temp_value)};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, test_value};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, test_value_short};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> checker{
      ::portable_stl::in_place_t{},
      std::initializer_list<std::uint32_t>{initialize_test_value, initialize_test_value},
      initialize_test_value
    };
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value().value());
  }
  {
    ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> checker{
      ::portable_stl::in_place_t{},
      {initialize_test_value, initialize_test_value},
      initialize_test_value
    };
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value().value());
  }
  {
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>>{}));
    ASSERT_TRUE(
      (std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>, std::int32_t const &>{}));
    ASSERT_TRUE(
      (std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>, std::int32_t &&>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::in_place_t,
                                               std::int32_t>{}));

    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>>{}));

    ASSERT_FALSE((
      std::is_nothrow_constructible<::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                                    utility_expected_test_helpers::error_check const &>{}));
    ASSERT_FALSE((
      std::is_nothrow_constructible<::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                                    utility_expected_test_helpers::error_check &&>{}));
    ASSERT_FALSE((
      std::is_nothrow_constructible<::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                                    ::portable_stl::in_place_t,
                                    utility_expected_test_helpers::error_check>{}));
  }
}

TEST(utility_expected, expected_error) {
  static_cast<void>(test_info_);
  constexpr std::uint16_t test_error_short{42U};
  constexpr std::uint32_t test_error{test_error_short};
  constexpr std::uint32_t initialize_test_value{40U};

  {
    ::portable_stl::unexpected<std::uint32_t> const       unexpected_value{test_error};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{unexpected_value};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::unexpected<std::uint32_t>             unexpected_value{test_error};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(unexpected_value)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, test_error};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check> checker{
      ::portable_stl::unexpect_t{},
      std::initializer_list<std::uint32_t>{initialize_test_value, initialize_test_value},
      initialize_test_value
    };
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error().value());
  }
  {
    ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check> checker{
      ::portable_stl::unexpect_t{},
      {initialize_test_value, initialize_test_value},
      initialize_test_value
    };
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error().value());
  }
  {
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::unexpected<std::uint32_t> const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::unexpected<std::uint32_t> &&>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::unexpect_t,
                                               std::uint32_t>{}));
    ASSERT_FALSE((
      std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                                    ::portable_stl::unexpected<utility_expected_test_helpers::error_check> const &>{}));
    ASSERT_FALSE(
      (std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                                     ::portable_stl::unexpected<utility_expected_test_helpers::error_check> &&>{}));
    ASSERT_FALSE(
      (std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                                     ::portable_stl::unexpect_t,
                                     utility_expected_test_helpers::error_check>{}));
  }
  {
    ::portable_stl::unexpected<std::uint32_t> const error{0U};
    ::portable_stl::expected<void, std::uint32_t>   checker{error};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(0U, checker.error());
  }
  {
    ::portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpected<std::uint32_t>{0U}};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(0U, checker.error());
  }
  {
    ::portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(0U, checker.error());
  }
  {
    ::portable_stl::expected<void, utility_expected_test_helpers::error_check> checker{
      ::portable_stl::unexpect_t{},
      {initialize_test_value, initialize_test_value},
      initialize_test_value
    };
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error().value());
  }
}
TEST(utility_expected, expected_copy_move_simple) {
  static_cast<void>(test_info_);
  constexpr std::int32_t  test_value{32};
  constexpr std::uint32_t test_error{42U};

  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> const source_expected{test_value};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> const source_expected{::portable_stl::unexpect_t{},
                                                                                test_error};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> source_expected{test_value};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint32_t> source_expected{::portable_stl::unexpect_t{}, test_error};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int32_t, std::uint32_t> const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int32_t, std::uint32_t> &&>{}));

    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> const &>{}));
    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> &&>{}));

    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check> const &>{}));
    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check> &&>{}));
  }
}

TEST(utility_expected, expected_copy_move_conversion) {
  static_cast<void>(test_info_);
  constexpr std::int16_t  test_value_short{32};
  constexpr std::int32_t  test_value{test_value_short};
  constexpr std::uint16_t test_error_short{42U};
  constexpr std::uint32_t test_error{test_error_short};
  {
    ::portable_stl::expected<std::int16_t, std::uint32_t> const source_expected{test_value_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int16_t, std::uint16_t> const source_expected{test_value_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint16_t> const source_expected{::portable_stl::unexpect_t{},
                                                                                test_error_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<std::int16_t, std::uint16_t> const source_expected{::portable_stl::unexpect_t{},
                                                                                test_error_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }

  {
    ::portable_stl::expected<std::int16_t, std::uint32_t> source_expected{test_value_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int16_t, std::uint16_t> source_expected{test_value_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_value());
    ASSERT_EQ(test_value, checker.value());
  }
  {
    ::portable_stl::expected<std::int32_t, std::uint16_t> source_expected{::portable_stl::unexpect_t{},
                                                                          test_error_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<std::int16_t, std::uint16_t> source_expected{::portable_stl::unexpect_t{},
                                                                          test_error_short};
    ::portable_stl::expected<std::int32_t, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }

  {
    ASSERT_TRUE((std::is_nothrow_constructible<std::int32_t, std::int32_t const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<std::int32_t, std::int16_t const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<std::uint32_t, std::uint32_t const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<std::uint32_t, std::uint16_t const &>{}));

    ASSERT_TRUE((::portable_stl::is_nothrow_constructible<
                   std::int32_t,
                   ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<std::int32_t>>>{}()
                 && ::portable_stl::is_nothrow_constructible<
                   std::uint32_t,
                   ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<std::uint16_t>>>{}()));

    ASSERT_TRUE((::portable_stl::is_nothrow_constructible<
                   std::int32_t,
                   ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<std::int16_t>>>{}()
                 && ::portable_stl::is_nothrow_constructible<
                   std::uint32_t,
                   ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<std::uint32_t>>>{}()));

    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int16_t, std::uint32_t> const &>{}));

    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int16_t, std::uint32_t> &&>{}));

    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int32_t, std::uint16_t> const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int32_t, std::uint16_t> &&>{}));

    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int16_t, std::uint16_t> const &>{}));
    ASSERT_TRUE((std::is_nothrow_constructible<::portable_stl::expected<std::int32_t, std::uint32_t>,
                                               ::portable_stl::expected<std::int16_t, std::uint16_t> &&>{}));

    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint16_t> const &>{}));
    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t>,
                  ::portable_stl::expected<utility_expected_test_helpers::error_check, std::uint16_t> &&>{}));

    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                  ::portable_stl::expected<std::int16_t, utility_expected_test_helpers::error_check> const &>{}));
    ASSERT_FALSE((std::is_nothrow_constructible<
                  ::portable_stl::expected<std::int32_t, utility_expected_test_helpers::error_check>,
                  ::portable_stl::expected<std::int16_t, utility_expected_test_helpers::error_check> &&>{}));
  }

  {
    ::portable_stl::expected<void, std::uint16_t> const source_expected{::portable_stl::unexpect_t{}, test_error_short};
    ::portable_stl::expected<void, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<void, std::uint32_t> const source_expected{::portable_stl::unexpect_t{}, test_error};
    ::portable_stl::expected<void, std::uint32_t>       checker{source_expected};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<void, std::uint16_t> source_expected{::portable_stl::unexpect_t{}, test_error_short};
    ::portable_stl::expected<void, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
  {
    ::portable_stl::expected<void, std::uint32_t> source_expected{::portable_stl::unexpect_t{}, test_error};
    ::portable_stl::expected<void, std::uint32_t> checker{std::move(source_expected)};
    ASSERT_TRUE(checker.has_error());
    ASSERT_EQ(test_error, checker.error());
  }
}

namespace utility_expected_test_helpers {
/**
 * @brief Operations on object.
 *
 */
enum class operation : uint32_t {
  /**
   * @brief Destroy object
   *
   */
  destruct,
  /**
   * @brief Construct object
   *
   */
  construct,
  /**
   * @brief Copy construct object.
   *
   */
  copy_construct,
  /**
   * @brief Move construct object.
   *
   */
  move_construct,
  /**
   * @brief Copy assign object start.
   *
   */
  copy_assign_begin,
  /**
   * @brief Copy assign object end.
   *
   */
  copy_assign_end,
  /**
   * @brief Move assign object start.
   *
   */
  move_assign_begin,
  /**
   * @brief Move assign object end.
   *
   */
  move_assign_end,
  /**
   * @brief Swap operation.
   *
   */
  swap
};

/**
 * @brief Operations storage.
 *
 */
using t_operations = std::vector<operation>;

/**
 * @brief Helper class for check object lifetime and operations.
 *
 * @tparam t_value_storage inner storage.
 */
template<class t_value_storage> class lifetime_checker final {
public:
private:
  /**
   * @brief Operations storage.
   *
   */
  t_operations   &m_operations;
  /**
   * @brief Data storage.
   *
   */
  t_value_storage m_storage;

public:
  /**
   * @brief Destroy the lifetime checker object
   *
   */
  inline ~lifetime_checker() noexcept {
    try {
      m_operations.push_back(operation::destruct);
    } catch (...) {
    }
  }

  /**
   * @brief Construct a new lifetime checker object
   *
   * @tparam t_args the types for inner storage constructor.
   * @param values operations storage.
   * @param args the arguments for inner storage constructor.
   */
  template<class... t_args>
  inline lifetime_checker(t_operations &values, t_args &&...args) noexcept(
    ::portable_stl::is_nothrow_constructible<t_value_storage, t_args...>{}())
      : m_operations(values), m_storage(std::forward<t_args>(args)...) {
    m_operations.push_back(operation::construct);
  }

  /**
   * @brief Construct a new lifetime checker object
   *
   * @param source the source for copy.
   */
  inline lifetime_checker(lifetime_checker const &source) noexcept(
    ::portable_stl::is_nothrow_copy_constructible<t_value_storage>{}())
      : m_operations(source.m_operations), m_storage(source.m_storage) {
    m_operations.push_back(operation::copy_construct);
  }

  /**
   * @brief Construct a new lifetime checker object
   *
   * @param source the source for move.
   */
  inline lifetime_checker(lifetime_checker &&source) noexcept(
    ::portable_stl::is_nothrow_move_constructible<t_value_storage>{}())
      : m_operations(source.m_operations), m_storage(std::move(source.m_storage)) {
    m_operations.push_back(operation::move_construct);
  }

  /**
   * @brief Assign copy operator.
   *
   * @param source the source for copy.
   * @return this object reference.
   */
  inline lifetime_checker &operator=(lifetime_checker const &source) & noexcept(
    ::portable_stl::is_nothrow_copy_assignable<t_value_storage>{}()) {
    m_operations.push_back(operation::copy_assign_begin);
    if (&source != this) {
      lifetime_checker temp{source};
      temp.swap_internal(*this);
    }
    m_operations.push_back(operation::copy_assign_end);
    return *this;
  }

  /**
   * @brief Assign move operator.
   *
   * @param source the source for move.
   * @return this object reference.
   */
  inline lifetime_checker &operator=(lifetime_checker &&source) & noexcept(
    ::portable_stl::is_nothrow_move_assignable<t_value_storage>{}()) {
    m_operations.push_back(operation::move_assign_begin);
    if (&source != this) {
      lifetime_checker temp{std::move(source)};
      temp.swap_internal(*this);
    }
    m_operations.push_back(operation::move_assign_end);
    return *this;
  }

  /**
   * @brief Inner storage getter.
   *
   * @return inner storage value.
   */
  inline t_value_storage const &value() const & noexcept {
    return m_storage;
  }

  /**
   * @brief Swap this object content with other object.
   *
   * @param other the object for swap.
   */
  inline void swap_internal(lifetime_checker &other) noexcept(
    ::portable_stl::is_nothrow_swappable<t_value_storage>{}()) {
    m_operations.push_back(operation::swap);
    ::portable_stl::swap(m_storage, other.m_storage);
  }
};

/**
 * @brief Swap this lifetime_checker object content with other object.
 *
 * @tparam t_value_storage the lifetime_checker inner storage.
 * @param left  the object for swap.
 * @param right the object for swap.
 */
template<class t_value_storage>
inline static void swap(lifetime_checker<t_value_storage> &left,
                        lifetime_checker<t_value_storage> &right) noexcept(noexcept(left.swap_internal(right))) {
  left.swap_internal(right);
}
} // namespace utility_expected_test_helpers

TEST(utility_expected, expected_lifetime_check) {
  static_cast<void>(test_info_);

  {
    utility_expected_test_helpers::t_operations values{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, values, 0};
      ASSERT_TRUE(left.has_value());
    }
    ASSERT_THAT(values,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations values{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>> const left{
        portable_stl::in_place_t{}, values, 0};
      ASSERT_TRUE(left.has_value());
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{left};
      ASSERT_TRUE(right.has_value());
    }
    ASSERT_THAT(values,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations values{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, values, 0};
      ASSERT_TRUE(left.has_value());
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{std::move(left)};
      ASSERT_TRUE(right.has_value());
    }
    ASSERT_THAT(values,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations errors{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::unexpect_t{}, errors, 0U};
      ASSERT_TRUE(left.has_error());
    }
    ASSERT_THAT(errors,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations errors{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>> const left{
        portable_stl::unexpect_t{}, errors, 0U};
      ASSERT_TRUE(left.has_error());
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{left};
      ASSERT_TRUE(right.has_error());
    }
    ASSERT_THAT(errors,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations errors{};
    {
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::unexpect_t{}, errors, 0U};
      ASSERT_TRUE(left.has_error());
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{std::move(left)};
      ASSERT_TRUE(right.has_error());
    }
    ASSERT_THAT(errors,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }
}

TEST(utility_expected, expected_swap_no_exceptions) {
  static_cast<void>(test_info_);
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      utility_expected_test_helpers::lifetime_checker<std::int32_t> left{operations, 0};
      utility_expected_test_helpers::lifetime_checker<std::int32_t> right{operations, 0};
      swap(left, right);
      utility_expected_test_helpers::lifetime_checker<std::int32_t>       copy_object{right};
      utility_expected_test_helpers::lifetime_checker<std::int32_t> const move_object{std::move(copy_object)};
      static_cast<void>(move_object);
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      utility_expected_test_helpers::lifetime_checker<std::int32_t> object{operations, 0};
      utility_expected_test_helpers::lifetime_checker<std::int32_t> copy_object{operations, 0};
      utility_expected_test_helpers::lifetime_checker<std::int32_t> move_object{operations, 0};
      copy_object = object;
      move_object = std::move(object);
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::copy_assign_begin,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::copy_assign_end,
                                       utility_expected_test_helpers::operation::move_assign_begin,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::move_assign_end,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t value_left{1};
      constexpr std::int32_t value_right{2};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::in_place_t{}, operations, value_right};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());

      left.swap_internal(right);

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_right, left.value().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_left, right.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::uint32_t value_left{1U};
      constexpr std::uint32_t value_right{2U};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::unexpect_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::unexpect_t{}, operations, value_right};

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_left, left.error().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_right, right.error().value());

      swap(left, right);

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_right, left.error().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_left, right.error().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t  value_left{-1};
      constexpr std::uint32_t value_right{2U};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::unexpect_t{}, operations, value_right};

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_right, right.error().value());

      swap(left, right);

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_right, left.error().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_left, right.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct, // temprary value.
                                       utility_expected_test_helpers::operation::destruct,       // old value.
                                       utility_expected_test_helpers::operation::move_construct, // error value.
                                       utility_expected_test_helpers::operation::destruct,       // old error.
                                       utility_expected_test_helpers::operation::move_construct, // value from temprary.
                                       utility_expected_test_helpers::operation::destruct,       // temprary value.
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::uint32_t value_left{2U};
      constexpr std::int32_t  value_right{-1};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::unexpect_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::in_place_t{}, operations, value_right};

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_left, left.error().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());

      swap(left, right);

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_right, left.value().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_left, right.error().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct, // temprary value.
                                       utility_expected_test_helpers::operation::destruct,       // old value.
                                       utility_expected_test_helpers::operation::move_construct, // error value.
                                       utility_expected_test_helpers::operation::destruct,       // old error.
                                       utility_expected_test_helpers::operation::move_construct, // value from temprary.
                                       utility_expected_test_helpers::operation::destruct,       // temprary value.
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    constexpr std::int32_t  value_left{-1};
    constexpr std::uint32_t value_right{2U};

    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    portable_stl::expected<std::int32_t, std::uint32_t> right{portable_stl::unexpect_t{}, value_right};

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_right, right.error());

    swap(left, right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_right, left.error());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_left, right.value());
  }

  {
    constexpr std::int32_t  value_right{-1};
    constexpr std::uint32_t value_left{2U};

    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    portable_stl::expected<std::int32_t, std::uint32_t> right{portable_stl::in_place_t{}, value_right};

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value());

    swap(left, right);

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_right, left.value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_left, right.error());
  }

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::uint32_t                                                                      value_error{2U};
      portable_stl::expected<void, utility_expected_test_helpers::lifetime_checker<std::uint32_t>> left{
        portable_stl::unexpect_t{}, operations, value_error};

      portable_stl::expected<void, utility_expected_test_helpers::lifetime_checker<std::uint32_t>> right{};

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_error, left.error().value());
      ASSERT_TRUE(right.has_value());

      swap(left, right);

      ASSERT_TRUE(left.has_value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_error, right.error().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::uint32_t                                                                      value_error{2U};
      portable_stl::expected<void, utility_expected_test_helpers::lifetime_checker<std::uint32_t>> right{
        portable_stl::unexpect_t{}, operations, value_error};

      portable_stl::expected<void, utility_expected_test_helpers::lifetime_checker<std::uint32_t>> left{};

      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_error, right.error().value());
      ASSERT_TRUE(left.has_value());

      swap(left, right);

      ASSERT_TRUE(right.has_value());
      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_error, left.error().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    portable_stl::expected<void, std::uint32_t> left{};
    portable_stl::expected<void, std::uint32_t> right{};

    ASSERT_TRUE(left.has_value());
    ASSERT_TRUE(right.has_value());

    swap(left, right);

    ASSERT_TRUE(left.has_value());
    ASSERT_TRUE(right.has_value());
  }
  {
    constexpr std::uint32_t value_error{2U};

    portable_stl::expected<void, std::uint32_t> left{};
    portable_stl::expected<void, std::uint32_t> right{portable_stl::unexpect_t{}, value_error};

    ASSERT_TRUE(left.has_value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error, right.error());

    swap(left, right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error, left.error());
    ASSERT_TRUE(right.has_value());
  }
  {
    constexpr std::uint32_t value_error{2U};

    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_error};
    portable_stl::expected<void, std::uint32_t> right{};

    ASSERT_TRUE(right.has_value());
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error, left.error());

    swap(left, right);

    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error, right.error());
    ASSERT_TRUE(left.has_value());
  }
  {
    constexpr std::uint32_t value_error_left{42U};
    constexpr std::uint32_t value_error_right{24U};

    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_error_left};
    portable_stl::expected<void, std::uint32_t> right{portable_stl::unexpect_t{}, value_error_right};

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error_left, left.error());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error_right, right.error());

    swap(left, right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error_right, left.error());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error_left, right.error());
  }
}

namespace utility_expected_test_helpers {

/**
 * @brief Helper class for check work with exceptions.
 *
 */
template<class t_inner_type> class exception_checker final {
  /**
   * @brief Counter for exceptio trigger.
   *
   */
  std::int32_t &m_counter;
  /**
   * @brief Inner storage for value.
   *
   */
  t_inner_type  m_inner_type;

  /**
   * @brief Helper function for check counter and throw exception.
   *
   */
  inline void check_throw() {
    --m_counter;
    if (m_counter == 0) {
      throw std::bad_exception{};
    }
  }

public:
  /**
   * @brief Destroy the exception checker object
   *
   */
  ~exception_checker() noexcept(false) {
    check_throw();
  }

  /**
   * @brief Constructor of object.
   * @param counter the trigger counter.
   * @param inner_type the inner value.
   */
  exception_checker(std::int32_t &counter, t_inner_type inner_type) : m_counter(counter), m_inner_type(inner_type) {
    check_throw();
  }

  /**
   * @brief Construct a new exception checker object
   *
   * @param other the source object.
   */
  exception_checker(exception_checker const &other) : m_counter(other.m_counter), m_inner_type(other.m_inner_type) {
    check_throw();
  }

  /**
   * @brief Construct a new exception checker object
   *
   * @param other the source object.
   */
  exception_checker(exception_checker &&other) : m_counter(other.m_counter), m_inner_type(other.m_inner_type) {
    check_throw();
  }

  /**
   * @brief Assign a new exception checker object by copy other.
   *
   * @param other the source object.
   * @return refetence to this object.
   */
  exception_checker &operator=(exception_checker const &other) & {
    if (&other != this) {
      check_throw();
      exception_checker tmp{other};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Assign a new exception checker object by move other.
   *
   * @param other the source object.
   * @return refetence to this object.
   */
  exception_checker &operator=(exception_checker &&other) & {
    if (&other != this) {
      check_throw();
      exception_checker tmp{std::move(other)};
      tmp.swap_internal(*this);
    }
    return *this;
  }

  /**
   * @brief Swap content from this and other objects.
   *
   * @param other the source object.
   */
  void swap_internal(exception_checker &other) {
    check_throw();
    std::swap(m_inner_type, other.m_inner_type);
  }

  /**
   * @brief Getter for inner value.
   *
   * @return value
   */
  t_inner_type const &value() const & noexcept {
    return m_inner_type;
  }
};

/**
 * @brief Swap content from left and right objects.
 *
 * @tparam t_inner_type the inner type of exception_checker.
 * @param left  the for swap object.
 * @param right the for swap object.
 */
template<class t_inner_type>
inline static void swap(exception_checker<t_inner_type> &left, exception_checker<t_inner_type> &right) {
  left.swap_internal(right);
}

} // namespace utility_expected_test_helpers

TEST(utility_expected, expected_swap_with_exceptions) {
  static_cast<void>(test_info_);

  {
    std::int32_t                                                         counter{0};
    utility_expected_test_helpers::exception_checker<std::int32_t> const object{counter, 0};
    utility_expected_test_helpers::exception_checker<std::int32_t>       object_copy{counter, 0};
    utility_expected_test_helpers::exception_checker<std::int32_t>       object_move{counter, 0};
    object_copy = object;
    object_move = std::move(object_copy);
    static_cast<void>(object_move);
  }

  {
    std::int32_t           counter{3};
    constexpr std::int32_t value_left{1};
    constexpr std::int32_t value_right{2};
    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      left{portable_stl::in_place_t{}, counter, value_left};

    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      right{portable_stl::in_place_t{}, counter, value_right};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());

    ASSERT_ANY_THROW(left.swap_internal(right));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());
  }

  {
    std::int32_t            counter{3};
    constexpr std::uint32_t value_left{1U};
    constexpr std::uint32_t value_right{2U};
    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      left{portable_stl::unexpect_t{}, counter, value_left};

    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      right{portable_stl::unexpect_t{}, counter, value_right};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error().value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_right, right.error().value());

    ASSERT_ANY_THROW(left.swap_internal(right));

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error().value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_right, right.error().value());
  }

  {
    constexpr std::int32_t max_operations_in_swap{8};
    for (std::int32_t counter_value{3}; counter_value < max_operations_in_swap; ++counter_value) {
      std::int32_t            counter{counter_value};
      constexpr std::int32_t  value_left{1};
      constexpr std::uint32_t value_right{2U};
      portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                             utility_expected_test_helpers::exception_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, counter, value_left};

      portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                             utility_expected_test_helpers::exception_checker<std::uint32_t>>
        right{portable_stl::unexpect_t{}, counter, value_right};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_right, right.error().value());

      ASSERT_ANY_THROW(left.swap_internal(right));

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_error());
      ASSERT_EQ(value_right, right.error().value());
    }
  }

  {
    constexpr std::int32_t max_operations_in_swap{8};
    for (std::int32_t counter_value{3}; counter_value < max_operations_in_swap; ++counter_value) {
      std::int32_t            counter{counter_value};
      constexpr std::uint32_t value_left{1U};
      constexpr std::int32_t  value_right{2};
      portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                             utility_expected_test_helpers::exception_checker<std::uint32_t>>
        left{portable_stl::unexpect_t{}, counter, value_left};

      portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                             utility_expected_test_helpers::exception_checker<std::uint32_t>>
        right{portable_stl::in_place_t{}, counter, value_right};
      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_left, left.error().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());

      ASSERT_ANY_THROW(left.swap_internal(right));

      ASSERT_TRUE(left.has_error());
      ASSERT_EQ(value_left, left.error().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());
    }
  }
}

TEST(utility_expected, expected_assignment) {
  static_cast<void>(test_info_);

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t value_left{1};
      constexpr std::int32_t value_right{2};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::in_place_t{}, operations, value_right};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());

      left = right;

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_right, left.value().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t value_left{1};
      constexpr std::int32_t value_right{2};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        right{portable_stl::in_place_t{}, operations, value_right};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      ASSERT_TRUE(right.has_value());
      ASSERT_EQ(value_right, right.value().value());

      left = std::move(right);

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_right, left.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    std::int32_t           counter{4};
    constexpr std::int32_t value_left{1};
    constexpr std::int32_t value_right{2};
    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      left{portable_stl::in_place_t{}, counter, value_left};

    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      right{portable_stl::in_place_t{}, counter, value_right};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());

    ASSERT_ANY_THROW(left.operator=(right));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());
  }

  {
    std::int32_t           counter{4};
    constexpr std::int32_t value_left{1};
    constexpr std::int32_t value_right{2};
    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      left{portable_stl::in_place_t{}, counter, value_left};

    portable_stl::expected<utility_expected_test_helpers::exception_checker<std::int32_t>,
                           utility_expected_test_helpers::exception_checker<std::uint32_t>>
      right{portable_stl::in_place_t{}, counter, value_right};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());

    ASSERT_ANY_THROW(left.operator=(std::move(right)));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());
    ASSERT_TRUE(right.has_value());
    ASSERT_EQ(value_right, right.value().value());
  }
}

TEST(utility_expected, expected_assignment_expected) {
  static_cast<void>(test_info_);

  constexpr std::int16_t test_value_short{32};
  constexpr std::int32_t test_value{test_value_short};
  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t value_left{1};

      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      utility_expected_test_helpers::lifetime_checker<std::int32_t> const check{operations, test_value};

      left = check;

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(test_value, left.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::copy_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    utility_expected_test_helpers::t_operations operations{};
    {
      constexpr std::int32_t value_left{1};
      portable_stl::expected<utility_expected_test_helpers::lifetime_checker<std::int32_t>,
                             utility_expected_test_helpers::lifetime_checker<std::uint32_t>>
        left{portable_stl::in_place_t{}, operations, value_left};
      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(value_left, left.value().value());
      utility_expected_test_helpers::lifetime_checker<std::int32_t> check{operations, test_value};

      left = std::move(check);

      ASSERT_TRUE(left.has_value());
      ASSERT_EQ(test_value, left.value().value());
    }
    ASSERT_THAT(operations,
                ::testing::ElementsAre(utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::construct,
                                       utility_expected_test_helpers::operation::move_construct,
                                       utility_expected_test_helpers::operation::swap,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct,
                                       utility_expected_test_helpers::operation::destruct));
  }

  {
    constexpr std::uint32_t                           value_error{1U};
    portable_stl::expected<void, std::uint32_t>       left{};
    portable_stl::expected<void, std::uint32_t> const right{portable_stl::unexpect_t{}, value_error};
    ASSERT_TRUE(left.has_value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error, right.error());

    left = right;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error, left.error());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error, right.error());
  }

  {
    constexpr std::uint32_t                     value_error{1U};
    portable_stl::expected<void, std::uint32_t> left{};
    portable_stl::expected<void, std::uint32_t> right{portable_stl::unexpect_t{}, value_error};
    ASSERT_TRUE(left.has_value());
    ASSERT_TRUE(right.has_error());
    ASSERT_EQ(value_error, right.error());

    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_error, left.error());
  }

  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    left = test_value;

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(test_value, left.value());
  }

  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    std::int32_t value{test_value};

    left = std::move(value);

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(test_value, left.value());
  }

  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    left = test_value_short;

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(test_value, left.value());
  }

  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    std::int16_t value{test_value_short};

    left = std::move(value);

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(test_value, left.value());
  }
}

TEST(utility_expected, expected_assignment_unexpected) {
  static_cast<void>(test_info_);
  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    portable_stl::unexpected<std::uint32_t> const value{0U};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                     value_left{1U};
    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    portable_stl::unexpected<std::uint32_t> const value{0U};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    portable_stl::unexpected<std::uint32_t> right{0U};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                     value_left{1U};
    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    portable_stl::unexpected<std::uint32_t> right{0U};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    portable_stl::unexpected<std::uint16_t> const value{static_cast<std::uint16_t>(0U)};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                     value_left{1U};
    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    portable_stl::unexpected<std::uint16_t> const value{static_cast<std::uint16_t>(0U)};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    portable_stl::unexpected<std::uint16_t> right{static_cast<std::uint16_t>(0U)};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                     value_left{1U};
    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    portable_stl::unexpected<std::uint16_t> right{static_cast<std::uint16_t>(0U)};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }
}

TEST(utility_expected, expected_assignment_cross) {
  static_cast<void>(test_info_);
  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());
    portable_stl::unexpected<std::uint32_t> const value{0U};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    portable_stl::expected<void, std::uint32_t> left{};
    ASSERT_TRUE(left.has_value());
    portable_stl::unexpected<std::uint32_t> const value{0U};
    left = value;

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    portable_stl::unexpected<std::uint32_t> right{0U};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    portable_stl::expected<void, std::uint32_t> left{};
    ASSERT_TRUE(left.has_value());

    portable_stl::unexpected<std::uint32_t> right{0U};
    left = std::move(right);

    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(0, left.error());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());
    constexpr std::int32_t value{0};
    left = value;

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(0, left.value());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    left = 0;

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(0, left.value());
  }
}

TEST(utility_expected, expected_emplace) {
  static_cast<void>(test_info_);
  {
    constexpr std::int32_t                              value_left{1};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::in_place_t{}, value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value());

    ASSERT_EQ(0, left.emplace(0));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(0, left.value());
  }

  {
    portable_stl::expected<void, std::uint32_t> left{};
    ASSERT_TRUE(left.has_value());

    left.emplace();

    ASSERT_TRUE(left.has_value());
  }

  {
    constexpr std::uint32_t                                                           result_value{4U};
    constexpr std::uint32_t                                                           value_left{1U};
    portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> left{portable_stl::in_place_t{},
                                                                                           value_left};
    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(value_left, left.value().value());

    ASSERT_EQ(result_value, left.emplace({1U, 1U, 1U}, 1U));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(result_value, left.value().value());
  }

  {
    constexpr std::uint32_t                             value_left{1U};
    portable_stl::expected<std::int32_t, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    ASSERT_EQ(0, left.emplace(0));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(0, left.value());
  }

  {
    constexpr std::uint32_t                     value_left{1U};
    portable_stl::expected<void, std::uint32_t> left{portable_stl::unexpect_t{}, value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    left.emplace();

    ASSERT_TRUE(left.has_value());
  }

  {
    constexpr std::uint32_t                                                           result_value{4U};
    constexpr std::uint32_t                                                           value_left{1U};
    portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> left{portable_stl::unexpect_t{},
                                                                                           value_left};
    ASSERT_TRUE(left.has_error());
    ASSERT_EQ(value_left, left.error());

    ASSERT_EQ(result_value, left.emplace({1U, 1U, 1U}, 1U));

    ASSERT_TRUE(left.has_value());
    ASSERT_EQ(result_value, left.value());
  }
}

TEST(utility_expected, expected_observers) {
  static_cast<void>(test_info_);
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE(static_cast<bool>(checker));
    ASSERT_EQ(0, checker.value());
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
    ASSERT_EQ(0, checker.value());
    ASSERT_TRUE(static_cast<bool>(checker));
    checker = 1;
    ASSERT_EQ(1, checker.value());
    checker.value() = 0;
    ASSERT_EQ(0, checker.value());
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_EQ(0, *checker);
    ASSERT_TRUE(static_cast<bool>(checker));
  }

  {
    portable_stl::expected<void, std::uint32_t> const checker{};
    *checker;
    ASSERT_TRUE(static_cast<bool>(checker));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
    ASSERT_EQ(0, *checker);
    ASSERT_TRUE(static_cast<bool>(checker));
    *checker = 1;
    ASSERT_EQ(1, checker.value());
  }
  {
    ASSERT_EQ(0,
              (*(static_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::in_place_t{}, 0}))));
    ASSERT_EQ(0, (*(portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::in_place_t{}, 0})));
  }

  {
    portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> checker{
      ::portable_stl::in_place_t{}, 0U};
    ASSERT_EQ(0, checker->value());
  }
  {
    portable_stl::expected<utility_expected_test_helpers::error_check, std::uint32_t> const checker{
      ::portable_stl::in_place_t{}, 0U};
    ASSERT_EQ(0, checker->value());
  }
  {
    ASSERT_EQ(0,
              (static_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                 portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::in_place_t{}, 0})
                 .value()));
    ASSERT_EQ(0, (portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::in_place_t{}, 0}).value());
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_THROW(checker.value(), ::portable_stl::bad_expected_access<std::uint32_t>);
  }

  {
    portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    *checker;
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_THROW(checker.value(), ::portable_stl::bad_expected_access<std::uint32_t>);
  }

  {
    portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_THROW(checker.value(), ::portable_stl::bad_expected_access<std::uint32_t>);
  }

  {
    ASSERT_THROW((portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}.value()),
                 ::portable_stl::bad_expected_access<std::uint32_t>);
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_EQ(0U, checker.error());
    ASSERT_FALSE(static_cast<bool>(checker));
  }
  {
    portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_EQ(0U, checker.error());
    ASSERT_FALSE(static_cast<bool>(checker));
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_EQ(0U, checker.error());
    ASSERT_FALSE(static_cast<bool>(checker));
    checker.error() = 1U;
    ASSERT_EQ(1U, checker.error());
  }
  {
    portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_EQ(0U, checker.error());
    ASSERT_FALSE(static_cast<bool>(checker));
    checker.error() = 1U;
    ASSERT_EQ(1U, checker.error());
  }
  {
    ASSERT_EQ(0U,
              ((static_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                  portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::unexpect_t{}, 0U}))
                 .error()));
    ASSERT_EQ(0U, ((portable_stl::expected<std::int32_t, std::uint32_t>{portable_stl::unexpect_t{}, 0U}).error()));
  }

  {
    ASSERT_EQ(0U,
              ((static_cast<portable_stl::expected<void, std::uint32_t> const &&>(
                  portable_stl::expected<void, std::uint32_t>{portable_stl::unexpect_t{}, 0U}))
                 .error()));
    ASSERT_EQ(0U, ((portable_stl::expected<void, std::uint32_t>{portable_stl::unexpect_t{}, 0U}).error()));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE(static_cast<bool>(checker));
    ASSERT_EQ(0, checker.value_or(-1));
    ASSERT_EQ(0, (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}).value_or(-1));
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_EQ(-1, checker.value_or(-1));
    ASSERT_EQ(-1, (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}).value_or(-1));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_EQ(0, checker.error_or(1U));
    ASSERT_EQ(0, (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}).error_or(1U));
  }
  {
    portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_FALSE(static_cast<bool>(checker));
    ASSERT_EQ(0, checker.error_or(1U));
    ASSERT_EQ(0, (portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}).error_or(1U));
  }
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE(static_cast<bool>(checker));
    ASSERT_EQ(1, checker.error_or(1U));
    ASSERT_EQ(1, (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}).error_or(1U));
  }
  {
    portable_stl::expected<void, std::uint32_t> const checker{};
    ASSERT_TRUE(static_cast<bool>(checker));
    ASSERT_EQ(1, checker.error_or(1U));
    ASSERT_EQ(1, (portable_stl::expected<void, std::uint32_t>{}).error_or(1U));
  }
}

TEST(utility_expected, expected_equality) {
  static_cast<void>(test_info_);
  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE(checker.is_equal(portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}));
  }
  {
    portable_stl::expected<void, std::uint32_t> const checker{};
    ASSERT_TRUE(checker.is_equal(portable_stl::expected<void, std::uint32_t>{}));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE((checker == portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}));
  }

  {
    portable_stl::expected<void, std::uint32_t> const checker{};
    ASSERT_TRUE((checker == portable_stl::expected<void, std::uint32_t>{}));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
    ASSERT_TRUE((checker == 0));
  }

  {
    portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_TRUE((checker == ::portable_stl::unexpected<std::uint32_t>{0U}));
  }
  {
    portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
    ASSERT_TRUE((checker == ::portable_stl::unexpected<std::uint32_t>{0U}));
  }
}

namespace utility_expected_test_helpers {
/**
 * @brief Helper value for check result.
 *
 */
constexpr std::int32_t                                              monadic_result_value{-1};
/**
 * @brief Helper value for check result.
 *
 */
constexpr std::uint32_t                                             monadic_result_error{1U};
/**
 * @brief Helper function for check monadic operations
 *
 * @param value for check
 * @return ::portable_stl::expected<std::int32_t, std::uint32_t>
 */
inline static ::portable_stl::expected<std::int32_t, std::uint32_t> value_functor(std::int32_t const value) noexcept {
  return {::portable_stl::in_place_t{}, value + monadic_result_value};
}

/**
 * @brief Helper function for check monadic operations
 *
 * @return ::portable_stl::expected<std::int32_t, std::uint32_t>
 */
inline static ::portable_stl::expected<std::int32_t, std::uint32_t> value_functor_void() noexcept {
  return {::portable_stl::in_place_t{}, monadic_result_value};
}

/**
 * @brief Helper function for check monadic operations
 *
 * @param value for check
 * @return ::portable_stl::expected<std::int32_t, std::uint32_t>
 */
inline static ::portable_stl::expected<std::int32_t, std::uint32_t> error_functor(std::uint32_t const value) noexcept {
  return {::portable_stl::unexpect_t{}, value + monadic_result_error};
}

/**
 * @brief Helper function for check monadic operations
 *
 * @param value for check
 * @return std::int32_t
 */
constexpr inline static std::int32_t value_map_functor(std::int32_t const value) noexcept {
  return (value + monadic_result_value);
}

/**
 * @brief Helper function for check monadic operations
 *
 * @return std::int32_t
 */
constexpr inline static std::int32_t value_map_functor_void() noexcept {
  return (monadic_result_value);
}

/**
 * @brief Helper function for check monadic operations
 *
 * @param value for check
 * @return std::uint32_t
 */
constexpr inline static std::uint32_t error_map_functor(std::uint32_t const value) noexcept {
  return (value + monadic_result_error);
}
} // namespace utility_expected_test_helpers

TEST(utility_expected, expected_monadic) {
  static_cast<void>(test_info_);

  {
    { ASSERT_TRUE(utility_expected_test_helpers::value_functor(0).has_value()); }

    { ASSERT_TRUE(utility_expected_test_helpers::value_functor_void().has_value()); }

    { ASSERT_TRUE(utility_expected_test_helpers::error_functor(0U).has_error()); }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                utility_expected_test_helpers::value_map_functor(0));
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                utility_expected_test_helpers::error_map_functor(0U));
    }
  }

  {
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.and_then(utility_expected_test_helpers::value_functor).value());
    }

    {
      portable_stl::expected<void, std::uint32_t> checker{};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.and_then(utility_expected_test_helpers::value_functor_void).value());
    }

    {
      portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.and_then(utility_expected_test_helpers::value_functor).value());
    }

    {
      portable_stl::expected<void, std::uint32_t> const checker{};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.and_then(utility_expected_test_helpers::value_functor_void).value());
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}
                   .and_then(utility_expected_test_helpers::value_functor)
                   .value()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (portable_stl::expected<void, std::uint32_t>{}
                   .and_then(utility_expected_test_helpers::value_functor_void)
                   .value()));
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (const_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                   portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0})
                   .and_then(utility_expected_test_helpers::value_functor)
                   .value()));
    }
    {
      ASSERT_EQ(
        utility_expected_test_helpers::monadic_result_value,
        (const_cast<portable_stl::expected<void, std::uint32_t> const &&>(portable_stl::expected<void, std::uint32_t>{})
           .and_then(utility_expected_test_helpers::value_functor_void)
           .value()));
    }

    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(0U, (checker.and_then(utility_expected_test_helpers::value_functor).error()));
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(0U, (checker.and_then(utility_expected_test_helpers::value_functor_void).error()));
    }
  }

  {
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.or_else(utility_expected_test_helpers::error_functor).error());
    }

    {
      portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.or_else(utility_expected_test_helpers::error_functor).error());
    }

    {
      portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.or_else(utility_expected_test_helpers::error_functor).error());
    }

    {
      portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.or_else(utility_expected_test_helpers::error_functor).error());
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}
                   .or_else(utility_expected_test_helpers::error_functor)
                   .error()));
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}
                   .or_else(utility_expected_test_helpers::error_functor)
                   .error()));
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (const_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                   portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U})
                   .or_else(utility_expected_test_helpers::error_functor)
                   .error()));
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (const_cast<portable_stl::expected<void, std::uint32_t> const &&>(
                   portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U})
                   .or_else(utility_expected_test_helpers::error_functor)
                   .error()));
    }
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(0U, (checker.or_else(utility_expected_test_helpers::error_functor).value()));
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{};
      ASSERT_TRUE((checker.or_else(utility_expected_test_helpers::error_functor).has_value()));
    }
  }
  {
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.transform(utility_expected_test_helpers::value_map_functor).value());
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.transform(utility_expected_test_helpers::value_map_functor_void).value());
    }

    {
      portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.transform(utility_expected_test_helpers::value_map_functor).value());
    }
    {
      portable_stl::expected<void, std::uint32_t> const checker{};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                checker.transform(utility_expected_test_helpers::value_map_functor_void).value());
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0}
                   .transform(utility_expected_test_helpers::value_map_functor)
                   .value()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (portable_stl::expected<void, std::uint32_t>{}
                   .transform(utility_expected_test_helpers::value_map_functor_void)
                   .value()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_value,
                (const_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                   portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::in_place_t{}, 0})
                   .transform(utility_expected_test_helpers::value_map_functor)
                   .value()));
    }
    {
      ASSERT_EQ(
        utility_expected_test_helpers::monadic_result_value,
        (const_cast<portable_stl::expected<void, std::uint32_t> const &&>(portable_stl::expected<void, std::uint32_t>{})
           .transform(utility_expected_test_helpers::value_map_functor_void)
           .value()));
    }
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(0U, (checker.transform(utility_expected_test_helpers::value_map_functor).error()));
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(0U, (checker.transform(utility_expected_test_helpers::value_map_functor_void).error()));
    }
  }
  {
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.transform_error(utility_expected_test_helpers::error_map_functor).error());
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.transform_error(utility_expected_test_helpers::error_map_functor).error());
    }

    {
      portable_stl::expected<std::int32_t, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.transform_error(utility_expected_test_helpers::error_map_functor).error());
    }
    {
      portable_stl::expected<void, std::uint32_t> const checker{::portable_stl::unexpect_t{}, 0U};
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                checker.transform_error(utility_expected_test_helpers::error_map_functor).error());
    }

    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}
                   .transform_error(utility_expected_test_helpers::error_map_functor)
                   .error()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U}
                   .transform_error(utility_expected_test_helpers::error_map_functor)
                   .error()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (const_cast<portable_stl::expected<std::int32_t, std::uint32_t> const &&>(
                   portable_stl::expected<std::int32_t, std::uint32_t>{::portable_stl::unexpect_t{}, 0U})
                   .transform_error(utility_expected_test_helpers::error_map_functor)
                   .error()));
    }
    {
      ASSERT_EQ(utility_expected_test_helpers::monadic_result_error,
                (const_cast<portable_stl::expected<void, std::uint32_t> const &&>(
                   portable_stl::expected<void, std::uint32_t>{::portable_stl::unexpect_t{}, 0U})
                   .transform_error(utility_expected_test_helpers::error_map_functor)
                   .error()));
    }
    {
      portable_stl::expected<std::int32_t, std::uint32_t> checker{::portable_stl::in_place_t{}, 0};
      ASSERT_EQ(0, (checker.transform_error(utility_expected_test_helpers::error_map_functor).value()));
    }
    {
      portable_stl::expected<void, std::uint32_t> checker{};
      ASSERT_TRUE((checker.transform_error(utility_expected_test_helpers::error_map_functor).has_value()));
    }
  }
}
