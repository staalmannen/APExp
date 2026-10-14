// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_assignment.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/type_properties/is_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_copy_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_move_assignable.h"
#include "portable_stl/utility/tuple/tuple.h"
#include "tuple_test_helper.h"

// from https://github.com/llvm-mirror/libcxx/blob/master/test/std/utilities/tuple/tuple.tuple/tuple.assign/

namespace test_tuple_helper {

/**
 * @brief Helper class.
 */
class NonAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return NonAssignable&
   */
  NonAssignable &operator=(NonAssignable const &) = delete;
  /**
   * @brief Assignment operator.
   * @return NonAssignable&
   */
  NonAssignable &operator=(NonAssignable &&)      = delete;
};

/**
 * @brief Helper class.
 */
class CopyAssignable final {
public:
  // clang-format off
  /**
   * @brief Assignment operator.
   * @return CopyAssignable&
   */
  CopyAssignable &operator=(CopyAssignable const &) & = default;
  // clang-format on
  /**
   * @brief Assignment operator.
   * @return CopyAssignable&
   */
  CopyAssignable &operator=(CopyAssignable &&) = delete;
};

static_assert(std::is_copy_assignable<CopyAssignable>::value, "");

/**
 * @brief Helper class.
 */
class MoveAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return MoveAssignable&
   */
  MoveAssignable &operator=(MoveAssignable const &) = delete;
  /**
   * @brief Assignment operator.
   * @return MoveAssignable&
   */
  MoveAssignable &operator=(MoveAssignable &&)    & = default;
};

/**
 * @brief Helper class.
 */
class NothrowCopyAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return NothrowCopyAssignable&
   */
  NothrowCopyAssignable &operator=(NothrowCopyAssignable const &) & noexcept {
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class PotentiallyThrowingCopyAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return PotentiallyThrowingCopyAssignable&
   */
  PotentiallyThrowingCopyAssignable &operator=(PotentiallyThrowingCopyAssignable const &) & {
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class CopyAssignableInt final {
public:
  /**
   * @brief Assignment operator.
   * @return CopyAssignableInt&
   */
  CopyAssignableInt &operator=(std::int32_t &) & {
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class NothrowMoveAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return NothrowMoveAssignable&
   */
  NothrowMoveAssignable &operator=(NothrowMoveAssignable &&) & noexcept {
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class PotentiallyThrowingMoveAssignable final {
public:
  /**
   * @brief Assignment operator.
   * @return PotentiallyThrowingMoveAssignable&
   */
  PotentiallyThrowingMoveAssignable &operator=(PotentiallyThrowingMoveAssignable &&) & {
    return *this;
  }
};

/**
 * @brief Helper class.
 * @tparam t_type
 */
template<class t_type> class AssignableFrom final {
public:
  /**
   * @brief Data.
   */
  t_type m_value;
  /**
   * @brief Construct a new Assignable From object
   */
  AssignableFrom() = default;

  /**
   * @brief Construct a new Assignable From object
   * @tparam t_other_type
   * @param other
   */
  template<class t_other_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_type, t_other_type &&>, void *>
           = nullptr>
  AssignableFrom(t_other_type &&other) : m_value(std::forward<t_other_type>(other)) {
  }

  /**
   * @brief Assignment operator.
   * @tparam T
   * @param other
   * @return AssignableFrom&
   */
  template<class T                                                                                  = t_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_copy_assignable<T>, void *> = nullptr>
  AssignableFrom &operator=(t_type const &other) & {
    m_value = other;
    return *this;
  }

  /**
   * @brief Assignment operator.
   * @tparam T
   * @param other
   * @return AssignableFrom&
   */
  template<class T                                                                                  = t_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_move_assignable<T>, void *> = nullptr>
  AssignableFrom &operator=(t_type &&other) & {
    m_value = std::move(other);
    return *this;
  }

  /**
   * @brief Assignment operator.
   * @tparam T
   * @param other
   * @return AssignableFrom const&
   */
  template<class T = t_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_assignable<T const &, T const &>, void *>
           = nullptr>
  AssignableFrom const &operator=(t_type const &other) const & {
    m_value = other;
    return *this;
  }

  /**
   * @brief Assignment operator.
   * @tparam T
   * @param other
   * @return AssignableFrom const&
   */
  template<class T                                                                                           = t_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_assignable<T const &, T &&>, void *> = nullptr>
  AssignableFrom const &operator=(t_type &&other) const & {
    m_value = std::move(other);
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class CopyAssign final {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Construct a new Copy Assign object
   */
  CopyAssign() = default;
  /**
   * @brief Construct a new Copy Assign object
   * @param value
   */
  CopyAssign(std::int32_t const value) : m_value(value) {
  }
  // clang-format off
  /**
   * @brief Assignment operator.
   * @return CopyAssign&
   */
  CopyAssign            &operator=(CopyAssign const &) & = default;
  // clang-format on
  // CopyAssign const &operator=(CopyAssign const &) const = delete;
  /**
   * @brief Assignment operator.
   * @return CopyAssign&
   */
  CopyAssign            &operator=(CopyAssign &&) = delete;
  // CopyAssign const &operator=(CopyAssign &&) const      = delete;
  /**
   * @brief Get the m_value.
   * @return std::int32_t
   */
  constexpr std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Helper class.
 */
class ConstCopyAssign final {
  /**
   * @brief Data.
   */
  mutable std::int32_t m_value;

public:
  /**
   * @brief Construct a new Const Copy Assign object
   */
  ConstCopyAssign() = default;
  /**
   * @brief Construct a new Const Copy Assign object
   * @param value
   */
  ConstCopyAssign(std::int32_t const value) : m_value(value) {
  }

  /**
   * @brief Assignment operator.
   * @param other
   * @return ConstCopyAssign const&
   */
  ConstCopyAssign const &operator=(ConstCopyAssign const &other) const & {
    if (this != &other) {
      m_value = other.m_value;
    }
    return *this;
  }
  // clang-format off
  /**
   * @brief Assignment operator.
   * @return ConstCopyAssign&
   */
  ConstCopyAssign       &operator=(ConstCopyAssign const &) & = delete;
  // clang-format on
  /**
   * @brief Assignment operator.
   * @return ConstCopyAssign&
   */
  ConstCopyAssign       &operator=(ConstCopyAssign &&)       = delete;
  /**
   * @brief Assignment operator.
   * @return ConstCopyAssign const&
   */
  ConstCopyAssign const &operator=(ConstCopyAssign &&) const = delete;

  /**
   * @brief Get the m_value.
   * @return std::int32_t
   */
  constexpr std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Helper class.
 */
class ConstMoveAssign final {
  /**
   * @brief Data.
   */
  mutable std::int32_t m_value;

public:
  /**
   * @brief Construct a new Const Move Assign object
   */
  ConstMoveAssign() = default;
  /**
   * @brief Construct a new Const Move Assign object
   * @param value
   */
  explicit ConstMoveAssign(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief Copy ctor.
   */
  ConstMoveAssign(ConstMoveAssign const &)  = delete;
  /**
   * @brief Copy ctor.
   */
  ConstMoveAssign(ConstMoveAssign const &&) = delete;
  /**
   * @brief Assignment operator.
   * @param other
   * @return ConstMoveAssign const&
   */
  ConstMoveAssign const &operator=(ConstMoveAssign const &&other) const & noexcept {
    m_value = other.m_value;
    return *this;
  }

  /**
   * @brief Assignment operator.
   * @return ConstMoveAssign&
   */
  ConstMoveAssign       &operator=(ConstMoveAssign const &)       = delete;
  /**
   * @brief Assignment operator.
   * @return ConstMoveAssign const&
   */
  ConstMoveAssign const &operator=(ConstMoveAssign const &) const = delete;
  /**
   * @brief Assignment operator.
   * @return ConstMoveAssign&
   */
  ConstMoveAssign       &operator=(ConstMoveAssign &&)       &noexcept = delete;
  /**
   * @brief Dtor.
   */
  ~ConstMoveAssign()                                              = default;
  /**
   * @brief Get the m_value.
   * @return std::int32_t
   */
  constexpr std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Helper class.
 */
class MoveAssign final {
public:
  /**
   * @brief
   */
  MoveAssign()                                          = default;
  /**
   * @brief Copy ctor.
   */
  MoveAssign(MoveAssign const &)                        = delete;
  /**
   * @brief Move ctor deleted.
   */
  MoveAssign(MoveAssign &&)                             = delete;
  // clang-format off
  /**
   * @brief Assignment operator.
   * @return MoveAssign&
   */
  MoveAssign       &operator=(MoveAssign &&) & = default;
  // clang-format on
  /**
   * @brief Assignment operator.
   * @return MoveAssign&
   */
  MoveAssign       &operator=(MoveAssign const &)       = delete;
  /**
   * @brief Assignment operator.
   * @return MoveAssign const&
   */
  MoveAssign const &operator=(MoveAssign const &) const = delete;
  // MoveAssign const &operator=(MoveAssign &&) const      = delete;
  /**
   * @brief Dtor.
   */
  ~MoveAssign()                                         = default;
};

/**
 * @brief Helper class.
 */
class TracedAssignment final {
  /**
   * @brief
   */
  mutable std::int32_t m_constCopyAssign{0};
  /**
   * @brief
   */
  mutable std::int32_t m_constMoveAssign{0};

public:
  /**
   * @brief Construct a new Traced Assignment object
   */
  constexpr TracedAssignment()                         = default;
  /**
   * @brief Copy ctor.
   */
  constexpr TracedAssignment(TracedAssignment const &) = default;
  /**
   * @brief Move ctor.
   */
  constexpr TracedAssignment(TracedAssignment &&)      = default;
  /**
   * @brief Dtor.
   */
  ~TracedAssignment()                                  = default;
  /**
   * @brief Assignment operator.
   * @return TracedAssignment&
   */
  TracedAssignment &operator=(TracedAssignment const &) & noexcept {
    return *this;
  }
  /**
   * @brief Assignment operator.
   * @param other
   * @return TracedAssignment const&
   */
  TracedAssignment const &operator=(TracedAssignment const &other) const & noexcept {
    if (this != &other) {
      ++m_constCopyAssign;
    }
    return *this;
  }
  /**
   * @brief Assignment operator.
   * @return TracedAssignment&
   */
  TracedAssignment &operator=(TracedAssignment &&) & noexcept {
    return *this;
  }
  /**
   * @brief Assignment operator.
   * @return TracedAssignment const&
   */
  TracedAssignment const &operator=(TracedAssignment &&) const & noexcept {
    ++m_constMoveAssign;
    return *this;
  }
  /**
   * @brief Get the m_constCopyAssign.
   * @return std::int32_t
   */
  constexpr std::int32_t getConstCopyAssign() const noexcept {
    return m_constCopyAssign;
  }
  /**
   * @brief Get the m_constMoveAssign.
   * @return std::int32_t
   */
  constexpr std::int32_t getConstMoveAssign() const noexcept {
    return m_constMoveAssign;
  }
};
} // namespace test_tuple_helper

TEST(tuple, assignment_copy) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<> const tpl0;
    ::portable_stl::tuple<>       tpl;
    tpl = tpl0;
  }
  {
    ::portable_stl::tuple<std::int32_t> const tpl0{1};
    ::portable_stl::tuple<std::int32_t>       tpl;

    tpl = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int8_t> const tpl0{1, 'a'};
    ::portable_stl::tuple<std::int32_t, std::int8_t>       tpl;

    tpl = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ('a', ::portable_stl::get<1>(tpl));
  }

  // test reference assignment.
  {
    std::int32_t x{0};
    std::int32_t y{0};
    std::int32_t x2{1};
    std::int32_t y2{1};

    ::portable_stl::tuple<std::int32_t &, std::int32_t &&>       tpl{x, std::move(y)};
    ::portable_stl::tuple<std::int32_t &, std::int32_t &&> const tpl2{x2, std::move(y2)};
    tpl = tpl2;

    EXPECT_EQ(x2, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(&x, &::portable_stl::get<0>(tpl));
    EXPECT_EQ(y2, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(&y, &::portable_stl::get<1>(tpl));
  }

  // test that the implicitly generated copy assignment operator is properly deleted
  EXPECT_FALSE((std::is_copy_assignable<::portable_stl::tuple<std::unique_ptr<std::int32_t>>>{}));

  EXPECT_FALSE((std::is_copy_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::NonAssignable>>{}));

  EXPECT_TRUE((std::is_copy_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::CopyAssignable>>{}));

  EXPECT_FALSE((std::is_copy_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveAssignable>>{}));

  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type = ::portable_stl::tuple<std::int32_t, std::int32_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using t_pair_type  = ::portable_stl::tuple<std::int32_t, std::int32_t>;

    EXPECT_FALSE((std::is_assignable<t_tuple_type &, t_pair_type>{}));
  }

  // test const requirement
  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type
      = ::portable_stl::tuple<test_tuple_helper::CopyAssignableInt, test_tuple_helper::CopyAssignableInt>;
    /**
     * @brief Test tuple type.
     */
    using t_pair_type = ::portable_stl::tuple<std::int32_t, std::int32_t>;

    EXPECT_FALSE((std::is_assignable<t_tuple_type &, t_pair_type const>{}));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type = ::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveAssignable>;
    /**
     * @brief Test tuple type.
     */
    using t_pair_type  = ::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveAssignable>;

    EXPECT_FALSE((std::is_assignable<t_tuple_type &, t_pair_type &>{}));
  }

  EXPECT_TRUE(
    (std::is_nothrow_copy_assignable<::portable_stl::tuple<test_tuple_helper::NothrowCopyAssignable, std::int32_t>>{}));

  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type = ::portable_stl::tuple<std::int32_t, test_tuple_helper::PotentiallyThrowingCopyAssignable>;

    EXPECT_TRUE(std::is_copy_assignable<t_tuple_type>{});
    EXPECT_FALSE(std::is_nothrow_copy_assignable<t_tuple_type>{});
  }
}

TEST(tuple, assignment_copy_const) {
  static_cast<void>(test_info_);

  {
    test_tuple_helper::TracedAssignment const value1;
    test_tuple_helper::TracedAssignment       value2;
    test_tuple_helper::TracedAssignment       value3;
    value2 = value1;
    value3 = std::move(value1);
    static_cast<void>(value3);
  }

  EXPECT_FALSE(
    (std::is_assignable<::portable_stl::tuple<std::int32_t> const &, ::portable_stl::tuple<std::int32_t> const &>{}));
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<std::int32_t &> const &,
                                  ::portable_stl::tuple<std::int32_t &> const &>{}));
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t &> const &,
                                  ::portable_stl::tuple<std::int32_t &, std::int32_t &> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t> const &,
                                   ::portable_stl::tuple<std::int32_t &, std::int32_t> const &>{}));

  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const &,
                                  ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::CopyAssign> const &,
                                   ::portable_stl::tuple<test_tuple_helper::CopyAssign> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> const &,
                                   ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::MoveAssign> const &,
                                   ::portable_stl::tuple<test_tuple_helper::MoveAssign> const &>{}));

  // reference types
  {
    std::int32_t i1{1};
    std::int32_t i2{0};
    double       d1{1.0};
    double       d2{0.0};

    ::portable_stl::tuple<std::int32_t &, double &> const tpl1{i1, d1};
    ::portable_stl::tuple<std::int32_t &, double &> const tpl2{i2, d2};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
    EXPECT_EQ(1.0, ::portable_stl::get<1>(tpl2));
  }

  // user defined const copy assignment
  {
    ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const tpl2{0};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }

  // make sure the right assignment operator (copy or move) of the type in the tuple is used
  {
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment, test_tuple_helper::TracedAssignment const>       tpl1{};
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment, test_tuple_helper::TracedAssignment const> const tpl2{};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getConstCopyAssign());
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl2).getConstCopyAssign());
  }
}

TEST(tuple, assignment_move) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<> tpl0;
    ::portable_stl::tuple<> tpl;
    tpl = std::move(tpl0);
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly> tpl0{test_tuple_helper::MoveOnly(1)};
    ::portable_stl::tuple<test_tuple_helper::MoveOnly> tpl;

    tpl = std::move(tpl0);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type = ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly>;

    t_tuple_type tpl0{test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};
    t_tuple_type tpl;

    tpl = std::move(tpl0);
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using t_tuple_type
      = ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly>;

    t_tuple_type tpl0{test_tuple_helper::MoveOnly(1), test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};
    t_tuple_type tpl;

    tpl = std::move(tpl0);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl));
  }

  // test reference assignment.
  {
    std::int32_t x{0};
    std::int32_t y{0};
    std::int32_t x2{1};
    std::int32_t y2{1};

    ::portable_stl::tuple<std::int32_t &, std::int32_t &&> tpl{x, std::move(y)};
    ::portable_stl::tuple<std::int32_t &, std::int32_t &&> tpl2{x2, std::move(y2)};
    tpl = std::move(tpl2);

    EXPECT_EQ(x2, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(&x, &::portable_stl::get<0>(tpl));
    EXPECT_EQ(y2, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(&y, &::portable_stl::get<1>(tpl));
  }

  EXPECT_FALSE((std::is_move_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::NonAssignable>>{}));

  EXPECT_TRUE((std::is_move_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveAssignable>>{}));

  EXPECT_TRUE(
    (std::is_nothrow_move_assignable<::portable_stl::tuple<std::int32_t, test_tuple_helper::NothrowMoveAssignable>>{}));

  EXPECT_FALSE((std::is_nothrow_move_assignable<
                ::portable_stl::tuple<test_tuple_helper::PotentiallyThrowingMoveAssignable, std::int32_t>>{}));

  {
    // We assign through the reference and don't move out of the incoming ref,
    // so this doesn't work (but would if the type were CopyAssignable).
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::MoveAssignable &, std::int32_t>;
    EXPECT_FALSE((std::is_move_assignable<T1>{}));

    // ... works if it's CopyAssignable
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<test_tuple_helper::CopyAssignable &, std::int32_t>;
    EXPECT_TRUE((std::is_move_assignable<T2>{}));

    // For rvalue-references, we can move-assign if the type is MoveAssignable
    // or CopyAssignable (since in the worst case the move will decay into a copy).
    /**
     * @brief Test tuple type.
     */
    using T3 = ::portable_stl::tuple<test_tuple_helper::MoveAssignable &&, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T4 = ::portable_stl::tuple<test_tuple_helper::CopyAssignable &&, std::int32_t>;
    EXPECT_TRUE((std::is_move_assignable<T3>{}));
    EXPECT_TRUE((std::is_move_assignable<T4>{}));

    // In all cases, we can't move-assign if the types are not assignable,
    // since we assign through the reference.
    /**
     * @brief Test tuple type.
     */
    using T5 = ::portable_stl::tuple<test_tuple_helper::NonAssignable &, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T6 = ::portable_stl::tuple<test_tuple_helper::NonAssignable &&, std::int32_t>;
    EXPECT_FALSE((std::is_move_assignable<T5>{}));
    EXPECT_FALSE((std::is_move_assignable<T6>{}));
  }
}

TEST(tuple, assignment_move_const) {
  static_cast<void>(test_info_);

  EXPECT_FALSE(
    (std::is_assignable<::portable_stl::tuple<std::int32_t> const &, ::portable_stl::tuple<std::int32_t> &&>{}));
  EXPECT_TRUE(
    (std::is_assignable<::portable_stl::tuple<std::int32_t &> const &, ::portable_stl::tuple<std::int32_t &> &&>{}));
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t &> const &,
                                  ::portable_stl::tuple<std::int32_t &, std::int32_t &> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t> const &,
                                   ::portable_stl::tuple<std::int32_t &, std::int32_t> &&>{}));

  // this is fallback to tuple's const copy assignment
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const &,
                                  ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> &&>{}));

  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::CopyAssign> const &,
                                   ::portable_stl::tuple<test_tuple_helper::CopyAssign> &&>{}));
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> const &,
                                  ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<test_tuple_helper::MoveAssign> const &,
                                   ::portable_stl::tuple<test_tuple_helper::MoveAssign> &&>{}));

  // reference types
  {
    std::int32_t i1{1};
    std::int32_t i2{0};
    double       d1{1.0};
    double       d2{0.0};

    ::portable_stl::tuple<std::int32_t &, double &>       tpl1{i1, d1};
    ::portable_stl::tuple<std::int32_t &, double &> const tpl2{i2, d2};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
    EXPECT_EQ(1.0, ::portable_stl::get<1>(tpl2));
  }

  // user defined const move assignment
  {
    ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign>       tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> const tpl2{0};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getValue());
  }

  // make sure the right assignment operator (copy or move) of the type in the tuple is used
  {
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment, test_tuple_helper::TracedAssignment const>       tpl1{};
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment, test_tuple_helper::TracedAssignment const> const tpl2{};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).getConstMoveAssign());
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl2).getConstCopyAssign());
  }
}

namespace test_tuple_helper {

/**
 * @brief Class to test convertion.
 */
class Base_cpy_assign_convert {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Ctor.
   * @param value
   */
  constexpr explicit Base_cpy_assign_convert(std::int32_t const value = 0) noexcept : m_value(value) {
  }
  /**
   * @brief Get the m_value.
   * @return std::int32_t
   */
  constexpr std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Class to test convertion.
 */
class Derived_cpy_assign_convert final : public Base_cpy_assign_convert {
public:
  /**
   * @brief Inherited constructor.
   */
  using Base_cpy_assign_convert::Base_cpy_assign_convert;
};

} // namespace test_tuple_helper

TEST(tuple, assignment_copy_convert) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::tuple<std::int32_t> tpl0{1};
    ::portable_stl::tuple<std::int64_t> tpl1;

    tpl1 = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));

    tpl0 = 0; // prevent making tpl0 const
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int8_t>  tpl0{1, 'a'};
    ::portable_stl::tuple<std::int64_t, std::int32_t> tpl1;

    tpl1 = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));

    tpl0 = {0, 'b'}; // prevent making tpl0 const
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::Derived_cpy_assign_convert> tpl0{
      1, 'a', test_tuple_helper::Derived_cpy_assign_convert{1}};
    ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::Base_cpy_assign_convert> tpl1;

    tpl1 = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());

    tpl0 = {0, 'b', test_tuple_helper::Derived_cpy_assign_convert{1}}; // prevent making tpl0 const
  }
  {
    test_tuple_helper::Derived_cpy_assign_convert d_val1{1};
    test_tuple_helper::Derived_cpy_assign_convert d_val2{0};

    ::portable_stl::tuple<std::int32_t, std::int8_t, test_tuple_helper::Derived_cpy_assign_convert &> tpl0{
      1, 'a', d_val1};
    ::portable_stl::tuple<std::int64_t, std::int32_t, test_tuple_helper::Base_cpy_assign_convert &> tpl1{
      0, 'b', d_val2};

    tpl1 = tpl0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(static_cast<std::int32_t>('a'), ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl1).getValue());

    tpl0 = {1, 'b', d_val2}; // prevent making tpl0 const
  }
  {
    // Test that tuple evaluates correctly applies an lvalue reference
    // before evaluating is_assignable (i.e. 'is_assignable<int&, int&>')
    // instead of evaluating 'is_assignable<int&&, int&>' which is false.
    std::int32_t x{0};
    std::int32_t y{1};

    ::portable_stl::tuple<std::int32_t &&> tpl{std::move(x)};
    ::portable_stl::tuple<std::int32_t &>  tpl2{y};

    tpl = tpl2;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(&x, &::portable_stl::get<0>(tpl));

    tpl2 = x; // prevent making tpl0 const
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<std::int32_t, test_tuple_helper::NonAssignable>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::NonAssignable, std::int32_t>;
    EXPECT_FALSE((std::is_assignable<T0 &, T1 const &>{}));
    EXPECT_FALSE((std::is_assignable<T1 &, T0 const &>{}));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<test_tuple_helper::NothrowCopyAssignable, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::NothrowCopyAssignable, std::int32_t>;
    EXPECT_TRUE((std::is_nothrow_assignable<T0 &, T1 const &>{}));
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T0 = ::portable_stl::tuple<test_tuple_helper::PotentiallyThrowingCopyAssignable, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<test_tuple_helper::PotentiallyThrowingCopyAssignable, std::int32_t>;
    EXPECT_TRUE((std::is_assignable<T0 &, T1 const &>{}));
    EXPECT_FALSE((std::is_nothrow_assignable<T0 &, T1 const &>{}));
  }
}

TEST(tuple, assignment_move_convert) {
  static_cast<void>(test_info_);
  // test constraints

  // sizeof...(Types) equals sizeof...(UTypes)
  EXPECT_TRUE(
    (std::is_assignable<::portable_stl::tuple<std::int32_t &> const &, ::portable_stl::tuple<std::int64_t &> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &, std::int64_t &> &&>{}));

  // // (is_assignable<const Types&, UTypes&&> && ...) is true
  EXPECT_TRUE((std::is_assignable<
               ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>> const &,
               ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> &&>{}));
  EXPECT_TRUE((std::is_assignable<
               ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>,
                                     test_tuple_helper::ConstMoveAssign> const &,
               ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign, test_tuple_helper::ConstMoveAssign> &&>{}));
  EXPECT_FALSE((
    std::is_assignable<::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>,
                                             test_tuple_helper::AssignableFrom<test_tuple_helper::MoveAssign>> const &,
                       ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign, test_tuple_helper::MoveAssign> &&>{}));

  {
    std::int32_t i1{1};
    std::int32_t i2{1};
    std::int64_t j1{0};
    std::int64_t j2{0};

    ::portable_stl::tuple<std::int32_t &, std::int32_t &>       tpl1{i1, i2};
    ::portable_stl::tuple<std::int64_t &, std::int64_t &> const tpl2{j1, j2};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl2));
  }

  // user defined const copy assignment
  {
    ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign>                                          tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>> const tpl2{0};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getValue());
  }

  // make sure the right assignment operator of the type in the tuple is used
  {
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment>                                          tpl1{};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::TracedAssignment>> const tpl2{};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getConstMoveAssign());
  }
}

TEST(tuple, assignment_copy_const_convert) {
  static_cast<void>(test_info_);

  // test constraints

  // sizeof...(Types) equals sizeof...(UTypes)
  EXPECT_TRUE((std::is_assignable<::portable_stl::tuple<std::int32_t &> const &,
                                  ::portable_stl::tuple<std::int64_t &> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &> const &>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &, std::int64_t &> const &>{}));

  // (is_assignable<const Types&, const UTypes&> && ...) is true
  EXPECT_TRUE((std::is_assignable<
               ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstCopyAssign>> const &,
               ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const &>{}));

  EXPECT_TRUE(
    (std::is_assignable<
      ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstCopyAssign>,
                            test_tuple_helper::ConstCopyAssign> const &,
      ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign, test_tuple_helper::ConstCopyAssign> const &>{}));

  EXPECT_FALSE((std::is_assignable<
                ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstCopyAssign>,
                                      test_tuple_helper::CopyAssign> const &,
                ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign, test_tuple_helper::CopyAssign> const &>{}));

  // reference types
  {
    std::int32_t i1{1};
    std::int32_t i2{1};
    std::int64_t j1{0};
    std::int64_t j2{0};

    ::portable_stl::tuple<std::int32_t &, std::int32_t &> const tpl1{i1, i2};
    ::portable_stl::tuple<std::int64_t &, std::int64_t &> const tpl2{j1, j2};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl2));
  }

  // user defined const copy assignment
  {
    ::portable_stl::tuple<test_tuple_helper::ConstCopyAssign> const                                    tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstCopyAssign>> const tpl2{0};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getValue());
  }

  // make sure the right assignment operator of the type in the tuple is used
  {
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment> const                                    tpl1{};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::TracedAssignment>> const tpl2{};

    tpl2 = tpl1;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getConstCopyAssign());
  }
}

TEST(tuple, assignment_move_const_convert) {
  static_cast<void>(test_info_);

  // test constraints

  // sizeof...(Types) equals sizeof...(UTypes)
  EXPECT_TRUE(
    (std::is_assignable<::portable_stl::tuple<std::int32_t &> const &, ::portable_stl::tuple<std::int64_t &> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &, std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &> &&>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::tuple<std::int32_t &> const &,
                                   ::portable_stl::tuple<std::int64_t &, std::int64_t &> &&>{}));

  // (is_assignable<const Types&, UTypes&&> && ...) is true
  EXPECT_TRUE((std::is_assignable<
               ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>> const &,
               ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign> &&>{}));

  EXPECT_TRUE((std::is_assignable<
               ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>,
                                     test_tuple_helper::ConstMoveAssign> const &,
               ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign, test_tuple_helper::ConstMoveAssign> &&>{}));

  EXPECT_FALSE((
    std::is_assignable<::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>,
                                             test_tuple_helper::AssignableFrom<test_tuple_helper::MoveAssign>> const &,
                       ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign, test_tuple_helper::MoveAssign> &&>{}));

  // reference types
  {
    std::int32_t i1{1};
    std::int32_t i2{1};
    std::int64_t j1{0};
    std::int64_t j2{0};

    ::portable_stl::tuple<std::int32_t &, std::int32_t &>       tpl1{i1, i2};
    ::portable_stl::tuple<std::int64_t &, std::int64_t &> const tpl2{j1, j2};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl2));
  }

  // user defined const copy assignment
  {
    ::portable_stl::tuple<test_tuple_helper::ConstMoveAssign>                                          tpl1{1};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::ConstMoveAssign>> const tpl2{0};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getValue());
  }

  // make sure the right assignment operator of the type in the tuple is used
  {
    ::portable_stl::tuple<test_tuple_helper::TracedAssignment>                                          tpl1{};
    ::portable_stl::tuple<test_tuple_helper::AssignableFrom<test_tuple_helper::TracedAssignment>> const tpl2{};

    tpl2 = std::move(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value.getConstMoveAssign());
  }
}
