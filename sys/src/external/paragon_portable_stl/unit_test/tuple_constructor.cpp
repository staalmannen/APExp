// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_constructor.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/utility/tuple/tuple.h"
#include "tuple_test_helper.h"

// from https://github.com/llvm-mirror/libcxx/blob/master/test/std/utilities/tuple/tuple.tuple/tuple.cnstr/

namespace test_tuple_helper {

/**
 * @brief Test class.
 */
class NoDefault final {
public:
  /**
   * @brief Construct a new No Default object
   *
   */
  NoDefault() = delete;
  /**
   * @brief Construct a new No Default object
   */
  constexpr explicit NoDefault(std::int32_t) noexcept {
  }
};

/**
 * @brief Test class.
 */
class NoExceptDefault final {
public:
  /**
   * @brief
   */
  constexpr NoExceptDefault() noexcept = default;
};

/**
 * @brief Test class.
 */
class ThrowingDefault final {
public:
  /**
   * @brief Construct a new Throwing Default object
   */
  constexpr ThrowingDefault() noexcept(false) {
  }
};

/**
 * @brief Test class.
 */
class IllFormedDefault final {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Construct a new Ill Formed Default object
   * @param value
   */
  constexpr IllFormedDefault(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief
   * @tparam Pred
   */
  template<bool Pred = false> constexpr IllFormedDefault() noexcept {
    static_assert(Pred, "The default constructor should not be instantiated");
  }
  /**
   * @brief Get the m_value.
   * for sanitizer only.
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Test class.
 *
 */
class Base_tpl_helper {};
/**
 * @brief Test class.
 */
class Derived_tpl_helper final : public Base_tpl_helper {
protected:
  /**
   * @brief Construct a new Derived_tpl_helper object
   */
  Derived_tpl_helper() = default;
};

} // namespace test_tuple_helper

TEST(tuple, ctor_default) {
  static_cast<void>(test_info_);
  {
    test_tuple_helper::DefaultOnly dctor1;
    test_tuple_helper::DefaultOnly dctor2;
    EXPECT_EQ(dctor1, dctor2);
    EXPECT_FALSE(dctor1 < dctor2);
    EXPECT_FALSE(dctor2 < dctor1);

    test_tuple_helper::HasImplicitCtor implctor1{1};
    test_tuple_helper::HasImplicitCtor implctor2{0};
    EXPECT_FALSE(implctor1 == implctor2);

    test_tuple_helper::HasExplicitCtor explctor1{1};
    test_tuple_helper::HasExplicitCtor explctor2{0};
    EXPECT_FALSE(explctor1 == explctor2);
  }
  {
    portable_stl::tuple<> const tpl;
    static_cast<void>(tpl);
  }
  {
    portable_stl::tuple<std::int32_t> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
  }
  {
    portable_stl::tuple<std::int32_t, std::int8_t *> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
    EXPECT_EQ(nullptr, portable_stl::get<1>(tpl));
  }
  {
    portable_stl::tuple<std::int32_t, std::int8_t *, std::string> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
    EXPECT_EQ(nullptr, portable_stl::get<1>(tpl));
    EXPECT_EQ("", portable_stl::get<2>(tpl));
  }
  {
    portable_stl::tuple<std::int32_t, std::int8_t *, std::string, test_tuple_helper::DefaultOnly> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
    EXPECT_EQ(nullptr, portable_stl::get<1>(tpl));
    EXPECT_EQ("", portable_stl::get<2>(tpl));
    EXPECT_EQ(test_tuple_helper::DefaultOnly(), portable_stl::get<3>(tpl));
  }
  {
    // See bug #21157.
    EXPECT_FALSE((std::is_default_constructible<portable_stl::tuple<test_tuple_helper::NoDefault>>{}));
    EXPECT_FALSE((std::is_default_constructible<
                  portable_stl::tuple<test_tuple_helper::DefaultOnly, test_tuple_helper::NoDefault>>{}));
    EXPECT_FALSE((std::is_default_constructible<portable_stl::tuple<test_tuple_helper::NoDefault,
                                                                    test_tuple_helper::DefaultOnly,
                                                                    test_tuple_helper::NoDefault>>{}));
  }
  {
    EXPECT_TRUE(noexcept(portable_stl::tuple<test_tuple_helper::NoExceptDefault>()));
    EXPECT_TRUE(
      noexcept(portable_stl::tuple<test_tuple_helper::NoExceptDefault, test_tuple_helper::NoExceptDefault>()));

    EXPECT_FALSE(
      noexcept(portable_stl::tuple<test_tuple_helper::ThrowingDefault, test_tuple_helper::NoExceptDefault>()));
    EXPECT_FALSE(
      noexcept(portable_stl::tuple<test_tuple_helper::NoExceptDefault, test_tuple_helper::ThrowingDefault>()));
    EXPECT_FALSE(
      noexcept(portable_stl::tuple<test_tuple_helper::ThrowingDefault, test_tuple_helper::ThrowingDefault>()));
  }
  {
    portable_stl::tuple<> const tpl;
    static_cast<void>(tpl);
  }
  {
    portable_stl::tuple<std::int32_t> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
  }
  {
    portable_stl::tuple<std::int32_t, std::int8_t *> tpl;
    EXPECT_EQ(0, portable_stl::get<0>(tpl));
    EXPECT_EQ(nullptr, portable_stl::get<1>(tpl));
  }
  {
    // Check that the SFINAE on the default constructor is not evaluated when
    // it isn't needed. If the default constructor is evaluated then this test
    // should fail to compile.
    test_tuple_helper::IllFormedDefault                              value{0};
    ::portable_stl::tuple<test_tuple_helper::IllFormedDefault> const tpl{value};
    static_cast<void>(tpl);

    // for sanitizer
    EXPECT_EQ(0, value.getValue());
  }
  {
    EXPECT_FALSE(
      (std::is_default_constructible<portable_stl::tuple<test_tuple_helper::Derived_tpl_helper, std::int32_t>>{}));
  }
}

namespace test_tuple_helper {

/**
 * @brief Test class.
 */
class Empty final {};

} // namespace test_tuple_helper

TEST(tuple, ctor_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<>       tpl0;
    ::portable_stl::tuple<> const tpl1{tpl0};
    static_cast<void>(tpl1);
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int32_t> tpl1{tpl0};
    EXPECT_EQ(1, portable_stl::get<0>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int64_t> tpl0{1, 'a'};
    ::portable_stl::tuple<std::int32_t, std::int64_t> tpl1{tpl0};
    EXPECT_EQ(1, portable_stl::get<0>(tpl1));
    EXPECT_EQ('a', portable_stl::get<1>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int8_t, std::int64_t> const tpl0{1, 'a', 1};
    ::portable_stl::tuple<std::int32_t, std::int8_t, std::int64_t>       tpl1{tpl0};
    EXPECT_EQ(1, portable_stl::get<0>(tpl1));
    EXPECT_EQ('a', portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, portable_stl::get<2>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int32_t> tpl1{tpl0};
    EXPECT_EQ(1, portable_stl::get<0>(tpl1));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::Empty> tpl0;
    ::portable_stl::tuple<test_tuple_helper::Empty> tpl1{tpl0};
    test_tuple_helper::Empty const                  value{::portable_stl::get<0>(tpl1)};
    static_cast<void>(value);
  }
}

namespace test_tuple_helper {

/**
 * @brief Helper class.
 */
class ExplicitTwo final {
public:
  /**
   * @brief Construct a new Explicit Two object
   */
  ExplicitTwo() = default;
  /**
   * @brief Construct a new Explicit Two object
   * @tparam T
   * @tparam std::enable_if<!std::is_same<T, ExplicitTwo>::value>::type
   */
  template<class T, class = typename std::enable_if<!std::is_same<T, ExplicitTwo>::value>::type>
  explicit ExplicitTwo(T) {
  }
  /**
   * @brief Construct a new Explicit Two object
   */
  ExplicitTwo(ExplicitTwo const &)                = default;
  /**
   * @brief Copy.
   * @return ExplicitTwo&
   */
  ExplicitTwo &operator=(ExplicitTwo const &)     = delete;
  /**
   * @brief Construct a new Explicit Two object
   */
  ExplicitTwo(ExplicitTwo &&) noexcept            = default;
  /**
   * @brief Move.
   * @return ExplicitTwo&
   */
  ExplicitTwo &operator=(ExplicitTwo &&) noexcept = delete;
  /**
   * @brief Destroy the Explicit Two object
   */
  ~ExplicitTwo()                                  = default;
};

} // namespace test_tuple_helper

TEST(tuple, ctor_copy_convert) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t>;

    T0 tpl0{1};
    T1 tpl1{tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::HasImplicitCtor>;

    T0 tpl0{1};
    T1 tpl1{tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1).getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::HasExplicitCtor>;

    T0 tpl0{1};
    T1 tpl1{tpl0};

    EXPECT_EQ(test_tuple_helper::HasExplicitCtor(1), ::portable_stl::get<0>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;

    T0 tpl0{1, 'a'};
    T1 tpl1{tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::DerivedExpl_tpl_helper>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::BaseExpl_tpl_helper>;

    T0 tpl0{1, 'a', test_tuple_helper::DerivedExpl_tpl_helper(1)};
    T1 tpl1{tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());
  }
  {
    test_tuple_helper::DerivedExpl_tpl_helper d_val{1};

    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::DerivedExpl_tpl_helper &>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::BaseExpl_tpl_helper &>;

    T0 tpl0{1, 'a', d_val};
    T1 tpl1{tpl0};
    d_val.setValue(::test_tuple_helper::val_2);

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(::test_tuple_helper::val_2, ::portable_stl::get<::test_tuple_helper::val_2>(tpl1).getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::BaseExpl_tpl_helper>;

    T0 tpl0{1, 'a', 1};
    T1 tpl1{tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t> const                 tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasExplicitCtor> tpl2{tpl1};
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t> const                 tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasImplicitCtor> tpl2{tpl1};
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }
  {
    EXPECT_TRUE((std::is_convertible<test_tuple_helper::ExplicitTwo &&, test_tuple_helper::ExplicitTwo>{}));
    EXPECT_TRUE((std::is_convertible<::portable_stl::tuple<test_tuple_helper::ExplicitTwo &&> &&,
                                     ::portable_stl::tuple<test_tuple_helper::ExplicitTwo> const &>{}));

    test_tuple_helper::ExplicitTwo                              value;
    ::portable_stl::tuple<test_tuple_helper::ExplicitTwo> const tpl{
      ::portable_stl::tuple<test_tuple_helper::ExplicitTwo &&>(std::move(value))};
    static_cast<void>(tpl);
  }
}

namespace test_tuple_helper {

/**
 * @brief Move_only type which triggers the empty base optimization
 */
class move_only_ebo final {
public:
  /**
   * @brief Construct a new move only ebo object
   */
  move_only_ebo()                 = default;
  /**
   * @brief Construct a new move only ebo object
   */
  move_only_ebo(move_only_ebo &&) = default;
};

/**
 * @brief A move_only type which does not trigger the empty base optimization
 */
class move_only_large final {
  /**
   * @brief Data.
   *
   */
  std::int32_t m_value{1};

public:
  /**
   * @brief Construct a new move only large object
   */
  move_only_large()                   = default;
  /**
   * @brief Construct a new move only large object
   */
  move_only_large(move_only_large &&) = default;
  /**
   * @brief Get m_value.
   * for sanitizer only
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Test.
 * @tparam t_type
 */
template<class t_type> static void test_sfinae() {
  /**
   * @brief Test tuple type.
   */
  using t_tuple     = ::portable_stl::tuple<t_type>;
  /**
   * @brief Test allocator type.
   */
  using t_allocator = std::allocator<std::int32_t>;
  /**
   * @brief Allocator use tag.
   */
  using t_tag       = ::portable_stl::allocator_arg_t;

  // special members
  {
    EXPECT_TRUE((std::is_default_constructible<t_tuple>{}));
    EXPECT_TRUE((std::is_move_constructible<t_tuple>{}));
    EXPECT_FALSE((std::is_copy_constructible<t_tuple>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_tuple &>{}));
  }
  // args constructors
  {
    EXPECT_TRUE((std::is_constructible<t_tuple, t_type &&>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_type const &>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_type &>{}));
  }
  // uses-allocator special member constructors
  {
    EXPECT_TRUE((std::is_constructible<t_tuple, t_tag, t_allocator>{}));
    EXPECT_TRUE((std::is_constructible<t_tuple, t_tag, t_allocator, t_tuple &&>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_tag, t_allocator, t_tuple const &>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_tag, t_allocator, t_tuple &>{}));
  }
  // uses-allocator args constructors
  {
    EXPECT_TRUE((std::is_constructible<t_tuple, t_tag, t_allocator, t_type &&>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_tag, t_allocator, t_type const &>{}));
    EXPECT_FALSE((std::is_constructible<t_tuple, t_tag, t_allocator, t_type &>{}));
  }
}

} // namespace test_tuple_helper

TEST(tuple, ctor_move) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<>;

    T0       tpl0;
    T0 const tpl1{std::move(tpl0)};

    static_cast<void>(tpl1);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<test_tuple_helper::MoveOnly>;

    T0 tpl0{test_tuple_helper::MoveOnly(0)};
    T0 tpl1{std::move(tpl0)};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly>;

    T0 tpl0{test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};
    T0 tpl1{std::move(tpl0)};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0
      = ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly>;
    T0 tpl0{test_tuple_helper::MoveOnly(1), test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};
    T0 tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1));
  }
  {
    test_tuple_helper::test_sfinae<test_tuple_helper::move_only_ebo>();
    test_tuple_helper::test_sfinae<test_tuple_helper::move_only_large>();
  }
  // for sanitizer only
  {
    test_tuple_helper::move_only_large value;
    EXPECT_EQ(1, value.getValue());
  }
}

namespace test_tuple_helper {

/**
 * @brief Helper class to test convertion.
 */
class BaseExpl_move_tpl_helper {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Ctor.
   * @param value
   */
  explicit BaseExpl_move_tpl_helper(std::int32_t const value) : m_value(value) {
  }
  /**
   * @brief Copy ctor.
   */
  BaseExpl_move_tpl_helper(BaseExpl_move_tpl_helper const &)              = default;
  /**
   * @brief Copy.
   * @return BaseExpl_move_tpl_helper&
   */
  BaseExpl_move_tpl_helper &operator=(BaseExpl_move_tpl_helper const &) & = default;

  /**
   * @brief Construct a new BaseExpl_move_tpl_helper object
   */
  BaseExpl_move_tpl_helper(BaseExpl_move_tpl_helper &&) = delete;

  /**
   * @brief
   */
  BaseExpl_move_tpl_helper &operator=(BaseExpl_move_tpl_helper &&) & = delete;

  /**
   * @brief Destroy the BaseExpl_move_tpl_helper object
   */
  virtual ~BaseExpl_move_tpl_helper() = default;
  /**
   * @brief Get the m_value
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
  /**
   * @brief Set the m_value
   * @param value
   */
  void setValue(std::int32_t const value) noexcept {
    m_value = value;
  }
};

/**
 * @brief Helper class to test convertion.
 */
class DerivedExpl_move_tpl_helper final : public BaseExpl_move_tpl_helper {
public:
  /**
   * @brief Ctor.
   */
  using BaseExpl_move_tpl_helper::BaseExpl_move_tpl_helper;
  /**
   * @brief Copy ctor.
   */
  DerivedExpl_move_tpl_helper(DerivedExpl_move_tpl_helper const &)              = default;
  /**
   * @brief Move ctor.
   */
  DerivedExpl_move_tpl_helper(DerivedExpl_move_tpl_helper &&)                   = delete;
  /**
   * @brief Copy.
   * @return DerivedExpl_move_tpl_helper&
   */
  DerivedExpl_move_tpl_helper &operator=(DerivedExpl_move_tpl_helper const &) & = default;
  /**
   * @brief Move.
   * @return DerivedExpl_move_tpl_helper&
   */
  DerivedExpl_move_tpl_helper &operator=(DerivedExpl_move_tpl_helper &&)      & = delete;
  /**
   * @brief Dtor.
   */
  ~DerivedExpl_move_tpl_helper() final                                          = default;
};

} // namespace test_tuple_helper

TEST(tuple, ctor_move_convert) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int64_t> tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int8_t>  tpl0{1, 'a'};
    ::portable_stl::tuple<std::int64_t, std::int32_t> tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::DerivedExpl_move_tpl_helper>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::BaseExpl_move_tpl_helper>;

    T0 tpl0{1, 'a', test_tuple_helper::DerivedExpl_move_tpl_helper(1)};
    T1 tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::DerivedExpl_move_tpl_helper &>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::BaseExpl_move_tpl_helper &>;

    test_tuple_helper::DerivedExpl_move_tpl_helper value{0};
    T0                                             tpl0{1, 'a', value};
    T1                                             tpl1{std::move(tpl0)};
    value.setValue(1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::
      tuple<std::int32_t, std::int8_t, std::unique_ptr<test_tuple_helper::DerivedExpl_move_tpl_helper>>;
    /**
     * @brief Test tuple type.
     */
    using T1
      = ::portable_stl::tuple<std::int64_t, std::int32_t, std::unique_ptr<test_tuple_helper::BaseExpl_move_tpl_helper>>;

    T0 tpl0{1, 'a', std::make_unique<test_tuple_helper::DerivedExpl_move_tpl_helper>(1)};
    T1 tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1)->getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t>                       tpl0{1};
    ::portable_stl::tuple<test_tuple_helper::HasExplicitCtor> tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1).getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t>                       tpl0{1};
    ::portable_stl::tuple<test_tuple_helper::HasImplicitCtor> tpl1{std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1).getValue());
  }
}

namespace test_tuple_helper {

/**
 * @brief 20 items tuple alias.
 *
 * @tparam T
 */
template<class T> using tuple_type = ::portable_stl::tuple<T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T>;

} // namespace test_tuple_helper

TEST(tuple, recursion_depth) {
  // Make sure that we don't blow up the template instantiation recursion depth
  // for tuples of size <= 512 (20 for the sake of msvc).
  static_cast<void>(test_info_);

  /**
   * @brief Test tuple type.
   */
  using tpl_type1 = test_tuple_helper::tuple_type<std::int32_t>;
  /**
   * @brief Test tuple type.
   */
  using tpl_type2 = test_tuple_helper::tuple_type<std::int64_t>;

  tpl_type1 tpl0{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  EXPECT_EQ(1, ::portable_stl::get<0>(tpl0));  // zero element
  EXPECT_EQ(1, ::portable_stl::get<19>(tpl0)); // 20-th element

  tpl_type2 const tpl1{tpl0};                                  // converting copy constructor from &
  tpl_type2 const tpl2{static_cast<tpl_type1 const &>(tpl0)};  // converting copy constructor from const&
  tpl_type2 const tpl3{std::move(tpl0)};                       // converting rvalue constructor
  tpl_type2 const tpl4{static_cast<tpl_type1 const &&>(tpl0)}; // converting const rvalue constructor
  tpl_type2 const tpl5;                                        // default constructor

  static_cast<void>(tpl1);
  static_cast<void>(tpl2);
  static_cast<void>(tpl3);
  static_cast<void>(tpl4);
  static_cast<void>(tpl5);
}
