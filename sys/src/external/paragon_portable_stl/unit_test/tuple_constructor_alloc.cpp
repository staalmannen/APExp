// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_constructor_alloc.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/array/array.h"
#include "portable_stl/utility/tuple/tuple.h"
#include "tuple_test_helper.h"

namespace test_tuple_helper {

/**
 * @brief Static member.
 */
bool alloc_first::allocator_constructed{false};

/**
 * @brief Static member.
 */
bool alloc_last::allocator_constructed{false};

/**
 * @brief Test class.
 * @tparam T
 */
template<class T = void> class NonDefaultConstructible final {
public:
  /**
   * @brief Constructor.
   */
  constexpr NonDefaultConstructible() {
    static_assert(!std::is_same<T, T>::value, "Default Ctor instantiated");
  }
  /**
   * @brief Constructor.
   */
  explicit constexpr NonDefaultConstructible(std::int32_t) {
  }
};

} // namespace test_tuple_helper

TEST(tuple, alloc_ctor_default) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<> const tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>()};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>()};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::DefaultOnly> tpl{::portable_stl::allocator_arg,
                                                              test_tuple_helper::A1<std::int32_t>()};
    EXPECT_EQ(test_tuple_helper::DefaultOnly(), ::portable_stl::get<0>(tpl));
  }
  // tuple_val constructor conditions
  {
    /**
     * @brief Test value type.
     */
    using t_type           = test_tuple_helper::alloc_first;
    /**
     * @brief Test allcoator type.
     */
    using t_allocator_type = test_tuple_helper::A1<std::int32_t>;
    EXPECT_TRUE((::portable_stl::uses_allocator<t_type, t_allocator_type>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_constructible<t_type, ::portable_stl::allocator_arg_t, t_allocator_type const &>{}()));
  }
  {
    EXPECT_FALSE(test_tuple_helper::alloc_first::allocator_constructed);

    ::portable_stl::tuple<test_tuple_helper::alloc_first> tpl{::portable_stl::allocator_arg,
                                                              test_tuple_helper::A1<std::int32_t>(5)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(), ::portable_stl::get<0>(tpl));
  }
  {
    EXPECT_FALSE(test_tuple_helper::alloc_last::allocator_constructed);

    ::portable_stl::tuple<test_tuple_helper::alloc_last> tpl{::portable_stl::allocator_arg,
                                                             test_tuple_helper::A1<std::int32_t>(5)};

    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(), ::portable_stl::get<0>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;

    ::portable_stl::tuple<test_tuple_helper::DefaultOnly, test_tuple_helper::alloc_first> tpl{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5)};

    EXPECT_EQ(test_tuple_helper::DefaultOnly(), ::portable_stl::get<0>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(), ::portable_stl::get<1>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    ::portable_stl::tuple<test_tuple_helper::DefaultOnly, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>
      tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5)};

    EXPECT_EQ(test_tuple_helper::DefaultOnly(), ::portable_stl::get<0>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(), ::portable_stl::get<1>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(), ::portable_stl::get<2>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    ::portable_stl::tuple<test_tuple_helper::DefaultOnly, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>
      tpl{::portable_stl::allocator_arg, test_tuple_helper::A2<std::int32_t>(5)};

    EXPECT_EQ(test_tuple_helper::DefaultOnly(), ::portable_stl::get<0>(tpl));
    ASSERT_FALSE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(), ::portable_stl::get<1>(tpl));
    ASSERT_FALSE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(), ::portable_stl::get<2>(tpl));
  }

  // Test that we can use a tag derived from allocator_arg_t
  {
    test_tuple_helper::DerivedFromAllocatorArgT             derived;
    ::portable_stl::tuple<> const                           tpl1{derived, test_tuple_helper::A1<std::int32_t>()};
    ::portable_stl::tuple<std::int32_t> const               tpl2{derived, test_tuple_helper::A1<std::int32_t>()};
    ::portable_stl::tuple<std::int32_t, std::int32_t> const tpl3{derived, test_tuple_helper::A1<std::int32_t>()};

    static_cast<void>(tpl1);
    static_cast<void>(tpl2);
    static_cast<void>(tpl3);
  }

  // Test that the uses-allocator default constructor does not evaluate
  // its SFINAE when it otherwise shouldn't be selected. Do this by
  // using 'NonDefaultConstructible' which will cause a compile error
  // if std::is_default_constructible is evaluated on it.
  {
    /**
     * @brief Test value type.
     */
    using test_type = test_tuple_helper::NonDefaultConstructible<>;

    test_type                                         value{1};
    ::portable_stl::tuple<test_type, test_type> const tpl{value, value};
    static_cast<void>(tpl);
    ::portable_stl::tuple<test_type, test_type> const tpl2{1, 1};
    static_cast<void>(tpl2);
  }
}

TEST(tuple, alloc_ctor_copy) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<>       tpl0;
    ::portable_stl::tuple<> const tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), tpl0};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int32_t> tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::alloc_first>;

    test_tuple_helper::alloc_first::allocator_constructed = false;

    tuple_type tpl0{1};
    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::alloc_last>;

    test_tuple_helper::alloc_last::allocator_constructed = false;

    tuple_type tpl0{1};
    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>;

    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type tpl0{1, 0};
    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type
      = ::portable_stl::tuple<std::int32_t, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>;
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type tpl0{1, 0, 1};
    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl));
  }
  // Test that we can use a tag derived from allocator_arg_t
  {
    test_tuple_helper::DerivedFromAllocatorArgT derived;
    ::portable_stl::tuple<std::int32_t>         from{1};
    ::portable_stl::tuple<std::int32_t> const   tpl0{derived, test_tuple_helper::A1<std::int32_t>(), from};
    static_cast<void>(tpl0);
  }
}

TEST(tuple, alloc_ctor_move) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<>       tpl0;
    ::portable_stl::tuple<> const tpl{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), std::move(tpl0)};
    static_cast<void>(tpl);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::MoveOnly>;
    tuple_type tpl0{test_tuple_helper::MoveOnly(1)};

    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::alloc_first>;
    tuple_type tpl0{1};
    test_tuple_helper::alloc_first::allocator_constructed = false;

    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::alloc_last>;
    tuple_type tpl0{1};
    test_tuple_helper::alloc_last::allocator_constructed = false;

    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::alloc_first>;
    tuple_type tpl0{0, 1};
    test_tuple_helper::alloc_first::allocator_constructed = false;

    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type = ::portable_stl::
      tuple<test_tuple_helper::MoveOnly, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>;
    tuple_type tpl0{1, 0, 1};
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl));
  }
  {
    // Test that we can use a tag derived from allocator_arg_t
    test_tuple_helper::DerivedFromAllocatorArgT derived;
    ::portable_stl::tuple<std::int32_t>         from{1};
    ::portable_stl::tuple<std::int32_t> const   tpl0{derived, test_tuple_helper::A1<std::int32_t>(), std::move(from)};
    static_cast<void>(tpl0);
  }
}

TEST(tuple, alloc_ctor_copy_convert) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int64_t> tpl1{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), tpl0};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    test_tuple_helper::alloc_first::allocator_constructed = false;

    ::portable_stl::tuple<test_tuple_helper::alloc_first> tpl1{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type0 = ::portable_stl::tuple<std::int32_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using tuple_type1 = ::portable_stl::tuple<test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>;

    tuple_type0 tpl0{1, 0};
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type1 tpl1{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    assert(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type0 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using tuple_type1
      = ::portable_stl::tuple<std::int64_t, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last>;

    tuple_type0 tpl0{1, 0, 1};
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type1 tpl1{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), tpl0};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1));
  }
  {
    ::portable_stl::tuple<std::int32_t> const                 tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasExplicitCtor> tpl2{
      ::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, tpl1};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t> const                 tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasImplicitCtor> tpl2{
      ::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, tpl1};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
  }

  // Test that we can use a tag derived from allocator_arg_t
  {
    test_tuple_helper::DerivedFromAllocatorArgT derived;
    ::portable_stl::tuple<std::int32_t>         from{1};
    ::portable_stl::tuple<std::int64_t> const   tpl0{derived, test_tuple_helper::A1<std::int32_t>(), from};
    static_cast<void>(tpl0);
  }
}

TEST(tuple, alloc_ctor_move_convert) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    test_tuple_helper::alloc_first::allocator_constructed = false;

    ::portable_stl::tuple<test_tuple_helper::alloc_first> tpl1{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type0 = ::portable_stl::tuple<std::unique_ptr<test_tuple_helper::DerivedExpl_tpl_helper>>;
    /**
     * @brief Test tuple type.
     */
    using tuple_type1 = ::portable_stl::tuple<std::unique_ptr<test_tuple_helper::BaseExpl_tpl_helper>>;

    tuple_type0 tpl0{std::make_unique<test_tuple_helper::DerivedExpl_tpl_helper>(1)};
    tuple_type1 tpl1{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1)->getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type0 = ::portable_stl::tuple<std::int32_t, std::unique_ptr<test_tuple_helper::DerivedExpl_tpl_helper>>;
    /**
     * @brief Test tuple type.
     */
    using tuple_type1
      = ::portable_stl::tuple<test_tuple_helper::alloc_first, std::unique_ptr<test_tuple_helper::BaseExpl_tpl_helper>>;

    tuple_type0 tpl0{1, std::make_unique<test_tuple_helper::DerivedExpl_tpl_helper>(1)};
    test_tuple_helper::alloc_first::allocator_constructed = false;

    tuple_type1 tpl1{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl1)->getValue());
  }
  {
    /**
     * @brief Test tuple type.
     */
    using tuple_type0
      = ::portable_stl::tuple<std::int32_t, std::int32_t, std::unique_ptr<test_tuple_helper::DerivedExpl_tpl_helper>>;
    /**
     * @brief Test tuple type.
     */
    using tuple_type1 = ::portable_stl::tuple<test_tuple_helper::alloc_last,
                                              test_tuple_helper::alloc_first,
                                              std::unique_ptr<test_tuple_helper::BaseExpl_tpl_helper>>;

    tuple_type0 tpl0{1, 0, std::make_unique<test_tuple_helper::DerivedExpl_tpl_helper>(1)};
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;

    tuple_type1 tpl1{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), std::move(tpl0)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1)->getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t>                       tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasExplicitCtor> tpl2{
      ::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, std::move(tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }
  {
    ::portable_stl::tuple<std::int32_t>                       tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::HasImplicitCtor> tpl2{
      ::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, std::move(tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }

  // Test that we can use a tag derived from allocator_arg_t
  {
    test_tuple_helper::DerivedFromAllocatorArgT derived;
    ::portable_stl::tuple<std::int32_t>         from{1};
    ::portable_stl::tuple<std::int64_t> const   tpl0{derived, test_tuple_helper::A1<std::int32_t>(), std::move(from)};
    static_cast<void>(tpl0);
  }
}

namespace test_tuple_helper {

/**
 * @brief Test class.
 */
class ImplicitCopy final {
public:
  /**
   * @brief Ctor.
   */
  explicit ImplicitCopy(std::int32_t) noexcept {
  }
  /**
   * @brief Ctor copy.
   */
  ImplicitCopy(ImplicitCopy const &)              = default;
  /**
   * @brief Copy.
   * @return ImplicitCopy
   */
  ImplicitCopy &operator=(ImplicitCopy const &) & = delete;
  /**
   * @brief Ctor move.
   */
  ImplicitCopy(ImplicitCopy &&)                   = delete;
  /**
   * @brief Move.
   * @return ImplicitCopy
   */
  ImplicitCopy &operator=(ImplicitCopy &&)        = delete;
  /**
   * @brief Dtor.
   */
  ~ImplicitCopy()                                 = default;
};

/**
 * @brief Test that tuple(::portable_stl::allocator_arg, Alloc, Types const&...) allows implicit
 * copy conversions in return value expressions.
 * @return ::portable_stl::tuple<ImplicitCopy>
 */
static ::portable_stl::tuple<ImplicitCopy> testImplicitCopy1() {
  ImplicitCopy value{1};
  return {::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, value};
}

} // namespace test_tuple_helper

TEST(tuple, alloc_ctor_from_const) {
  static_cast<void>(test_info_);
  {
    static_cast<void>(test_tuple_helper::testImplicitCopy1());
  }
  {
    // check that the literal '0' can implicitly initialize a stored pointer.
    ::portable_stl::tuple<std::int32_t *> const tpl{::portable_stl::allocator_arg, std::allocator<std::int32_t>{}, 0};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl{::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(), 1};
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    ::portable_stl::tuple<test_tuple_helper::alloc_first> tpl{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), test_tuple_helper::alloc_first(1)};

    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(1), ::portable_stl::get<0>(tpl));
  }
  {
    test_tuple_helper::alloc_last::allocator_constructed = false;
    ::portable_stl::tuple<test_tuple_helper::alloc_last> tpl{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), test_tuple_helper::alloc_last(1)};

    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(1), ::portable_stl::get<0>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    ::portable_stl::tuple<std::int32_t, test_tuple_helper::alloc_first> tpl{
      ::portable_stl::allocator_arg, test_tuple_helper::A1<std::int32_t>(5), 1, test_tuple_helper::alloc_first(1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(1), ::portable_stl::get<1>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;
    ::portable_stl::tuple<std::int32_t, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last> tpl{
      ::portable_stl::allocator_arg,
      test_tuple_helper::A1<std::int32_t>(5),
      1,
      test_tuple_helper::alloc_first(1),
      test_tuple_helper::alloc_last(1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(1), ::portable_stl::get<1>(tpl));
    ASSERT_TRUE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(1), ::portable_stl::get<2>(tpl));
  }
  {
    test_tuple_helper::alloc_first::allocator_constructed = false;
    test_tuple_helper::alloc_last::allocator_constructed  = false;
    ::portable_stl::tuple<std::int32_t, test_tuple_helper::alloc_first, test_tuple_helper::alloc_last> tpl{
      ::portable_stl::allocator_arg,
      test_tuple_helper::A2<std::int32_t>(5),
      1,
      test_tuple_helper::alloc_first(1),
      test_tuple_helper::alloc_last(1)};
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    ASSERT_FALSE(test_tuple_helper::alloc_first::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_first(1), ::portable_stl::get<1>(tpl));
    ASSERT_FALSE(test_tuple_helper::alloc_last::allocator_constructed);
    EXPECT_EQ(test_tuple_helper::alloc_last(1), ::portable_stl::get<2>(tpl));
  }
  {
    // Test that we can use a tag derived from allocator_arg_t
    test_tuple_helper::DerivedFromAllocatorArgT             derived;
    ::portable_stl::tuple<> const                           tpl1{derived, test_tuple_helper::A1<std::int32_t>()};
    ::portable_stl::tuple<std::int32_t> const               tpl2{derived, test_tuple_helper::A1<std::int32_t>(), 1};
    ::portable_stl::tuple<std::int32_t, std::int32_t> const tpl3{derived, test_tuple_helper::A1<std::int32_t>(), 1, 1};
    static_cast<void>(tpl1);
    static_cast<void>(tpl2);
    static_cast<void>(tpl3);
  }
}
